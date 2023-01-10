#include "android_cert_store.h"

#if !BUILDFLAG(IS_ANDROID)
#error "This file is only for Android"
#endif // !BUILDFLAG(IS_ANDROID)

#include <fcntl.h>
#include <unistd.h>

#include "util/stream/file_output_stream.h"
#include "util/stream/zlib_output_stream.h"

namespace crashpad {
namespace backtrace {
namespace android_cert_store {

#include "certs_pem_gz.h"

namespace {

bool file_exists(const base::FilePath& path) {
  return access(path.value().c_str(), F_OK) != -1;
}

} // anonymous namespace

create_result create(const base::FilePath& database) {

  auto certs_file = database.Append("/backtrace-cacert.pem");

  if (file_exists(certs_file))
    return create_result::already_exists;

  FileHandle file_handle = open(certs_file.value().c_str(),
    O_CREAT | O_TRUNC | O_WRONLY, 0644);

  if (file_handle == -1)
    return create_result::failure;

  auto out = std::make_unique<FileOutputStream>(file_handle);
  ZlibOutputStream ungzip(ZlibOutputStream::Mode::kDecompress, std::move(out));

  if (!ungzip.Write(certs_pem_gz, certs_pem_gz_len) || !ungzip.Flush()) {
    close(file_handle);
    return create_result::failure;
  }

  return create_result::success;
}

} // android_cert_store
} // backtrace
} // crashpad
