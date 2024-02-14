#include "crash_history.h"

#include <ctime>

#include <iostream>
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
namespace crash_history {

static auto CsvFileName(const base::FilePath& database)
{
#if BUILDFLAG(IS_WIN)
  return database.value() + L"/crash_history.csv";
#else
  return database.value() + "/crash_history.csv";
#endif
}

static std::vector<RunEntry>
LoadCrashData(const base::FilePath& database, int max_entries = std::numeric_limits<int>::max())
{
  std::vector<RunEntry> entries;
  auto csv_file = CsvFileName(database);
  std::ifstream f(csv_file);

  for (std::string line; std::getline(f, line);) {
    if (line.size() && line.back() == '\n')
      line.pop_back();
    auto split = SplitString(line, ',');
    if (split.size() < 3)
      continue;
    RunEntry entry;
    if (!entry.uuid.InitializeFromString(split[0]))
      continue;
    entry.crashed = split[1] == "1";
    try {
      entry.start_time = std::stoll(split[2]);
      if (split.size() > 3) {
        entry.crash_time = std::stoll(split[3]);
      }
    } catch (const std::invalid_argument& arg) {
      continue;
    }
    entries.push_back(std::move(entry));
  }

  if (entries.size() > max_entries)
    entries.erase(entries.begin(), entries.end() - max_entries);
  return entries;
}

static bool WriteCrashData(const base::FilePath& database,
                           const std::vector<RunEntry>& data)
{
  std::deque<std::string> lines;
  std::ofstream f(CsvFileName(database), std::ios::trunc);

  if (!f)
    return false;

  for (const auto& entry : data) {
    std::stringstream str;
    str << entry.uuid.ToString() << ','
        << (entry.crashed ? "1" : "0") << ','
        << entry.start_time;
    if (entry.crash_time)
      str << ',' << entry.crash_time.value();
    str << '\n';

    auto line = str.str();
    if (line.size()) {
      if (&entry == &data.back())
        line.pop_back();
    }
    f << line;
  }

  return true;
}

bool Append(const base::FilePath& database, UUID uuid, int max_entries)
{
  auto entries = LoadCrashData(database, max_entries - 1);

  time_t current_time = time(nullptr);
  RunEntry entry = {uuid, false, current_time, std::nullopt};
  entries.push_back(std::move(entry));

  return WriteCrashData(database, entries);
}

bool SetCrashed(const base::FilePath& database, UUID uuid)
{
  auto entries = LoadCrashData(database);
  bool success{};
  std::string uuid_str = uuid.ToString();

  for (auto& entry : entries) {
    if (entry.uuid == uuid) {
      success = true;
      entry.crashed = true;
      entry.crash_time = time(nullptr);
      break;
    }
  }

  return success && WriteCrashData(database, entries);
}

int ConsecutiveCrashesCount(const base::FilePath& database)
{
  auto entries = LoadCrashData(database);

  auto is_crashing = [](const auto& entry) {
    return !entry.crashed;
  };

  auto it = std::find_if(entries.rbegin(), entries.rend(), is_crashing);
  return std::distance(entries.rbegin(), it);
}

}  // namespace crash_history
}  // namespace backtrace
}  // namespace crashpad
