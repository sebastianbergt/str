#pragma once

#include <string>

namespace str {

namespace in_place {
  void upper(std::string &s);
}

namespace copy {
  std::string upper(const std::string &s);
}

}// namespace str