#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/chrono.h>

#include <ctime>
#include <chrono>

int main() {
    std::time_t startup_time = std::chrono::system_clock::to_time_t(
                           std::chrono::system_clock::now());
    std::tm local_time = *std::localtime(&startup_time);

  auto time_string = fmt::format("{:%a %F %T %Z}",local_time);
  fmt::print(time_string);
}
