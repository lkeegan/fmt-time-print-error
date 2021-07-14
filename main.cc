#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/chrono.h>

#include <ctime>
#include <chrono>

int main() {
    std::time_t startup_time = std::chrono::system_clock::to_time_t(
                           std::chrono::system_clock::now());
    std::tm local_time;
#ifdef HAVE_LOCALTIME_R
    localtime_r(&startup_time,&local_time);
#else
    std::tm* tm = std::localtime(&startup_time);
    std::memcpy(&local_time,tm,sizeof(std::tm));
#endif

  auto time_string = fmt::format("{:%a %F %T %Z}",local_time);
  fmt::print(time_string);
}
