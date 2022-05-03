#pragma once

#include <string>

namespace str {

namespace in_place {
  void strip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
}// namespace in_place

namespace copy {
  std::string strip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
}// namespace copy
}// namespace str
