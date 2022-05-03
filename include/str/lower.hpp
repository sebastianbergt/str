#pragma once

#include <string>

namespace str {

namespace in_place {
  void lower(std::string &s) noexcept;
}

namespace copy {
  std::string lower(const std::string &s) noexcept;
}

}// namespace str