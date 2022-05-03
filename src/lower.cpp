#include <algorithm>
#include <cctype>
#include <string>

#include <str/lower.hpp>

namespace str {

namespace in_place {
  void lower(std::string &s) noexcept { std::transform(s.begin(), s.end(), s.begin(), ::tolower); }
}// namespace in_place

namespace copy {
  std::string lower(const std::string &s) noexcept
  {
    std::string result{ s };
    in_place::lower(result);
    return result;
  }
}// namespace copy

}// namespace str