#pragma once

#include <string>

namespace str {

namespace in_place {
  void lstrip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
  void rstrip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
  void strip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
}// namespace in_place

namespace copy {

  std::string lstrip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
  std::string rstrip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
  std::string strip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
}// namespace copy
}// namespace str
