// Copyright 2022 Sauce Labs. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <cstdint>
#include <optional>
#include <vector>

#include "base/files/file_path.h"
#include "util/misc/uuid.h"

namespace crashpad {
namespace backtrace {
namespace crash_history {

struct RunEntry
{
    UUID uuid;
    bool crashed;
    time_t start_time;
    std::optional<time_t> crash_time;
};

static constexpr int default_max_entries = 10;

bool Append(const base::FilePath& database,
            UUID uuid,
            int max_entries = default_max_entries);

bool SetCrashed(const base::FilePath& database, UUID uuid);

int ConsecutiveCrashesCount(const base::FilePath& database);

} // crash_history
} // backtrace
} // crashpad
