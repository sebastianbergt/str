#pragma once

#include <string>

namespace str {

namespace in_place {

  /// \brief Removes given characters from the begin of the input string without creating a copy
  /// \param[in, out] s string to be transformed
  /// \param[in] characters_to_remove string with characters that will be removed
  void lstrip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });

  /// \brief Removes given characters from the end of the input string without creating a copy
  /// \param[in, out] s string to be transformed
  /// \param[in] characters_to_remove string with characters that will be removed
  void rstrip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });

  /// \brief Removes given characters from the begin and the end of the input string without creating a copy
  /// \param[in, out] s string to be transformed
  /// \param[in] characters_to_remove string with characters that will be removed
  void strip(std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
}// namespace in_place

namespace copy {
  /// \brief Creates a copy of the input and removes given characters from the begin of the input string
  /// \param[in, out] s string to be transformed
  /// \param[in] characters_to_remove string with characters that will be removed, default value is a space
  /// \return copy of the string put in, but left trimmed
  std::string lstrip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });

  /// \brief Creates a copy of the input and removes given characters from the end of the input string
  /// \param[in, out] s string to be transformed
  /// \param[in] characters_to_remove string with characters that will be removed, default value is a space
  /// \return copy of the string put in, but right trimmed
  std::string rstrip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });

  /// \brief Creates a copy of the input and removes given characters from the beginning and the end of the input string
  /// \param[in, out] s string to be transformed
  /// \param[in] characters_to_remove string with characters that will be removed, default value is a space
  /// \return copy of the string put in, but trimmed
  std::string strip(const std::string &s, const std::string &characters_to_remove = std::string{ ' ' });
}// namespace copy
}// namespace str
