#include "backtrace.hpp"

#include <iostream>

#include <client/crash_report_database.h>
#include <client/settings.h>
#include <client/crashpad_client.h>
#include <client/crashpad_info.h>

namespace backtrace
{
std::unique_ptr<crashpad::CrashReportDatabase> database;

bool initialize_crashpad(std::string_view url)
{
    using namespace crashpad;

    std::map<std::string, std::string> annotations;
    std::vector<std::string> arguments;
    bool rc;

    /*
     * ENSURE THIS VALUE IS CORRECT.
     *
     * This is the directory you will use to store and
     * queue crash data.
     */
    std::wstring db_path(L".");

    /*
     * ENSURE THIS VALUE IS CORRECT.
     *
     * Crashpad has the ability to support crashes both in-process
     * and out-of-process. The out-of-process handler is
     * significantly more robust than traditional in-process crash
     * handlers. This path may be relative.
     */
    std::wstring handler_path(L"C:/code/backtrace/crashpad-cmake/build-win/handler/Debug/handler.exe");

    /*
     * THE FOLLOWING ANNOTATIONS MUST BE SET.
     *
     * Backtrace supports many file formats. Set format to minidump
     * so it knows how to process the incoming dump.
     */
    annotations["format"] = "minidump";

    /*
     * REMOVE THIS FOR ACTUAL BUILD.
     *
     * We disable crashpad rate limiting for this example.
     */
    arguments.push_back("--no-rate-limit");

    base::FilePath db(db_path);
    base::FilePath handler(handler_path);

    database = crashpad::CrashReportDatabase::Initialize(db);

    std::cerr << __LINE__ << '\n';

    if (database == nullptr || database->GetSettings() == NULL)
        return false;

    std::cerr << __LINE__ << '\n';
    std::cerr << __LINE__ << std::string{url} << '\n';

    /* Enable automated uploads. */
    database->GetSettings()->SetUploadsEnabled(true);

    return CrashpadClient{}.StartHandler(
        handler, db, db, std::string{url}, annotations, arguments, false, false, {}
    );
}

void crash_memset()
{
    memset((void*)(intptr_t)4, 123, 1);
}

}
