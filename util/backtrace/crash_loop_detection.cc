#include "crash_loop_detection.h"

#include <ctime>

#include <deque>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#include "build/build_config.h"
#include "util/string/split_string.h"

namespace crashpad {
namespace backtrace {
namespace crash_loop_detection {

static auto CsvFileName(const base::FilePath& database)
{
#if BUILDFLAG(IS_WIN)
  return database.value() + L"/crash_loop_detection.csv";
#else
  return database.value() + "/crash_loop_detection.csv";
#endif
}

using CrashData = std::deque<std::vector<std::string>>;

static CrashData LoadCrashData(const base::FilePath& database,
                               int max_entries = std::numeric_limits<int>::max())
{
  CrashData lines;
  auto csv_file = CsvFileName(database);
  std::ifstream f(csv_file);

  for (std::string line; std::getline(f, line);) {
    if (line.size() && line.back() == '\n')
      line.pop_back();
    lines.push_back(SplitString(line, ','));
    if (lines.size() > max_entries)
      lines.pop_front();
  }
  return lines;
}

static bool WriteCrashData(const base::FilePath& database,
                           const CrashData& data)
{
  std::deque<std::string> lines;
  std::ofstream f(CsvFileName(database), std::ios::trunc);

  if (!f)
    return false;

  for (const auto& vec : data) {
    std::stringstream str;
    for (const auto& el : vec)
      str << el << ',';
    auto line = str.str();
    if (line.size()) {
      if (&vec == &data.back())
        line.pop_back();
      else
        line.back() = '\n';
    }
    f << line;
  }

  return true;
}

bool CrashLoopDetectionAppend(const base::FilePath& database,
                              UUID uuid,
                              int max_entries)
{
  auto lines = LoadCrashData(database, max_entries - 1);

  time_t current_time = time(nullptr);
  std::vector<std::string> new_line = {
      std::to_string(current_time), uuid.ToString(), "0"};
  lines.push_back(std::move(new_line));

  return WriteCrashData(database, lines);
}

bool CrashLoopDetectionSetCrashed(const base::FilePath& database, UUID uuid)
{
  auto lines = LoadCrashData(database);
  bool success{};
  std::string uuid_str = uuid.ToString();

  for (auto& line : lines) {
    if (line.size() < 3)
      continue;
    if (line[1] == uuid_str) {
      success = true;
      line[2] = "1";
      if (line.size() > 3)
        line[3] = std::to_string(time(nullptr));
      else
        line.push_back(std::to_string(time(nullptr)));
    }
  }

  return success && WriteCrashData(database, lines);
}

int ConsecutiveCrashesCount(const base::FilePath& database)
{
  auto lines = LoadCrashData(database);

  auto is_crashing = [](const auto& line) {
    if (line.size() >= 3 && line[2] != "0")
      return false;
    return true;
  };

  auto it = std::find_if(lines.rbegin(), lines.rend(), is_crashing);
  return std::distance(lines.rbegin(), it);
}

}  // namespace crash_loop_detection
}  // namespace backtrace
}  // namespace crashpad
