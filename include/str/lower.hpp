#pragma once

#include <string>

namespace str {

namespace in_place {
  /// \brief transform string to all lower case without creating a copy
  /// \param[in, out] s string to be transformed
  void lower(std::string &s) noexcept;
}// namespace in_place

namespace copy {
  /// \brief creates a copy of the string and transforms the new string to all lower case
  /// \param[in] s string to be transformed
  /// \return copy of the string put in, in all lower case
  std::string lower(const std::string &s) noexcept;
}// namespace copy

}// namespace str