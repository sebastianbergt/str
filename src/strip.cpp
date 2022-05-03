#include <algorithm>
#include <cstddef>
#include <iterator>
#include <str/strip.hpp>
#include <string>
namespace str {

namespace detail {
  std::string::const_iterator strip_find_begin(const std::string &s, const std::string &characters_to_remove)
  {
    auto begin = s.begin();
    for (; begin < s.end(); begin = std::next(begin)) {
      if (characters_to_remove.find(*begin) == std::string::npos) { return begin; }
    }
    return s.begin();
  }

  std::string::const_iterator strip_find_end(const std::string &s, const std::string &characters_to_remove)
  {
    auto end = std::prev(s.end());
    for (; end >= s.begin(); end = std::prev(end)) {
      if (characters_to_remove.find(*end) == std::string::npos) { return std::next(end); }
    }
    return s.end();
  }
}// namespace detail

namespace in_place {
  void lstrip(std::string &s, const std::string &characters_to_remove)
  {
    const auto begin = detail::strip_find_begin(s, characters_to_remove);
    s.erase(s.begin(), begin);
  }

  void rstrip(std::string &s, const std::string &characters_to_remove)
  {
    const auto end = detail::strip_find_end(s, characters_to_remove);
    s.erase(end, s.end());
  }

  void strip(std::string &s, const std::string &characters_to_remove)
  {
    lstrip(s, characters_to_remove);
    rstrip(s, characters_to_remove);
  }
}// namespace in_place

namespace copy {
  std::string lstrip(const std::string &s, const std::string &characters_to_remove)
  {
    const auto begin = detail::strip_find_begin(s, characters_to_remove);
    const auto pos = static_cast<std::size_t>(begin - s.begin());
    const auto str_size = static_cast<std::size_t>(s.end() - begin);
    return s.substr(pos, str_size);
  }

  std::string rstrip(const std::string &s, const std::string &characters_to_remove)
  {
    const auto end = detail::strip_find_end(s, characters_to_remove);
    const auto str_size = static_cast<std::size_t>(end - s.begin());
    return s.substr(0, str_size);
  }

  std::string strip(const std::string &s, const std::string &characters_to_remove)
  {
    const auto begin = detail::strip_find_begin(s, characters_to_remove);
    const auto end = detail::strip_find_end(s, characters_to_remove);
    const auto pos = static_cast<std::size_t>(begin - s.begin());
    const auto str_size = static_cast<std::size_t>(end - begin);
    return s.substr(pos, str_size);
  }
}// namespace copy
}// namespace str
