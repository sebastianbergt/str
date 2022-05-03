#pragma once

#include <string>

namespace str {

namespace in_place {
  /// \brief transform string to all upper case without creating a copy
  /// \param[in, out] s string to be transformed
  void upper(std::string &s);
}// namespace in_place

namespace copy {
  /// \brief creates a copy of the string and transforms the new string to all upper case
  /// \param[in] s string to be transformed
  /// \return copy of the string put in, in all upper case
  std::string upper(const std::string &s);
}// namespace copy

}// namespace str