#include <algorithm>
#include <cstddef>
#include <iterator>
#include <str/strip.hpp>
#include <string>
namespace str {

namespace in_place {

  namespace detail {
    void strip_left(std::string &s, const std::string &characters_to_remove)
    {
      auto it = s.begin();
      for (; it < s.end(); it = std::next(it)) {
        if (characters_to_remove.find(*it) == std::string::npos) { break; }
      }
      s.erase(s.begin(), it);
    }

    void strip_right(std::string &s, const std::string &characters_to_remove)
    {
      auto it = s.rbegin();
      for (; it < s.rend(); it = std::next(it)) {
        if (characters_to_remove.find(*it) == std::string::npos) { break; }
      }
      s.erase(it.base(), s.end());
    }
  }// namespace detail

  void strip(std::string &s, const std::string &characters_to_remove)
  {
    detail::strip_left(s, characters_to_remove);
    detail::strip_right(s, characters_to_remove);
  }
}// namespace in_place

namespace copy {
  namespace detail {
    std::string::const_iterator strip_find_begin(const std::string &s, const std::string &characters_to_remove)
    {
      auto begin = s.begin();
      for (; begin < s.end(); begin = std::next(begin)) {
        if (characters_to_remove.find(*begin) == std::string::npos) { break; }
      }
      return begin;
    }

    std::string::const_iterator strip_find_end(const std::string &s, const std::string &characters_to_remove)
    {
      auto end = std::prev(s.end());
      for (; end >= s.begin(); end = std::prev(end)) {
        if (characters_to_remove.find(*end) == std::string::npos) { break; }
      }
      return end;
    }
  }// namespace detail

  std::string strip(const std::string &s, const std::string &characters_to_remove)
  {
    const auto begin = detail::strip_find_begin(s, characters_to_remove);
    const auto end = detail::strip_find_end(s, characters_to_remove);
    const auto pos = static_cast<std::size_t>(begin - s.begin());
    const auto str_size = static_cast<std::size_t>(end - begin) + 1;
    // static_cast<std::size_t>(std::distance(begin, end));

    return s.substr(pos, str_size);
  }
}// namespace copy
}// namespace str
