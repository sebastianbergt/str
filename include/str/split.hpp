#pragma once

#include <cstddef>
#include <memory>// for std::allocator
#include <string>


namespace str {

/// \brief split a string into an STL Container of your choice
/// \tparam Container e.g std::vector, std::list
/// \tparam Value default is std::string
/// \tparam Allocator default is std::allocator<Value>
/// \param[in] s input string to be split
/// \param[in] delimiter string to be used for cutting the input string into pieces
/// \return a collection of the parts
template<template<typename, typename> class Container,
  typename Value = std::string,
  typename Allocator = std::allocator<Value>>
Container<Value, Allocator> split(const std::string &s, const std::string &delimiter)
{
  Container<Value, Allocator> result{};
  std::size_t last_pos = 0;
  std::size_t pos = 0;
  while ((pos = s.find(delimiter, last_pos)) != std::string::npos) {
    result.push_back(s.substr(last_pos, pos - last_pos));
    last_pos = pos + delimiter.size();
  }
  const auto tail = s.substr(last_pos);
  if (!tail.empty()) { result.push_back(tail); }

  return result;
}

}// namespace str
