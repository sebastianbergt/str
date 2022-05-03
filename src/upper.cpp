#include <algorithm>
#include <cctype>
#include <string>

#include <str/upper.hpp>

namespace str {

namespace in_place {
  void upper(std::string &s) { std::transform(s.begin(), s.end(), s.begin(), ::toupper); }
}// namespace in_place

namespace copy {
  std::string upper(const std::string &s)
  {
    std::string result{ s };
    in_place::upper(result);
    return result;
  }
}// namespace copy

}// namespace str