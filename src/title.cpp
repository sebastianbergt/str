#include <algorithm>
#include <cctype>
#include <iterator>
#include <str/title.hpp>
#include <string>

namespace str {


namespace in_place {
  static inline bool isLetter(const char c) { return static_cast<bool>(std::isalpha(c)); }
  static inline char toUpper(const char c) { return static_cast<char>(::toupper(c)); }

  void title(std::string &s) noexcept
  {
    if (isLetter(*s.begin())) { *s.begin() = toUpper(*s.begin()); }

    for (auto it = std::next(s.begin()); it < s.end(); it = std::next(it)) {
      auto previous = std::prev(it);
      if (*previous == ' ' && isLetter(*it)) { *it = toUpper(*it); }
    }
  }
}// namespace in_place

namespace copy {
  std::string title(const std::string &s) noexcept
  {
    std::string result{ s };
    in_place::title(result);
    return result;
  }
}// namespace copy

}// namespace str