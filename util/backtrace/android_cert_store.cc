#include "android_cert_store.h"

#if !BUILDFLAG(IS_ANDROID)
#error "This file is only for Android"
#endif // !BUILDFLAG(IS_ANDROID)

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

namespace crashpad {
namespace backtrace {
namespace android_cert_store {

#include "certs_pem.h"

namespace {

bool file_exists(const base::FilePath& path) {
  return access(path.value().c_str(), F_OK) != -1;
}

size_t file_size(const base::FilePath& path) {
  struct stat st;
  if (stat(path.value().c_str(), &st) == -1)
    return 0;
  return st.st_size;
}

} // anonymous namespace

create_result create(const base::FilePath& database) {

  auto certs_file = database.Append("/backtrace-cacert.pem");

  if (file_exists(certs_file) && file_size(certs_file) == certs_pem_len)
    return create_result::already_exists;

  int file_handle = open(certs_file.value().c_str(),
    O_CREAT | O_TRUNC | O_WRONLY, 0644);

  if (file_handle == -1)
    return create_result::failure;

  auto written = write(file_handle, certs_pem, certs_pem_len);
  if (written != certs_pem_len){
      close(file_handle);
      return create_result::failure;
  }

  close(file_handle);
  return create_result::success;
}

} // android_cert_store
} // backtrace
} // crashpad
