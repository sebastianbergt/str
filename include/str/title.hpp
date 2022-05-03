#pragma once

#include <string>

namespace str {

namespace in_place {
  /// \brief transform string to title case without creating a copy
  /// \param[in, out] s string to be transformed
  void title(std::string &s) noexcept;
}// namespace in_place

namespace copy {
  /// \brief creates a copy of the string and transforms the new string to title case
  /// \param[in] s string to be transformed
  /// \return copy of the string put in, in title case
  std::string title(const std::string &s) noexcept;
}// namespace copy

}// namespace str