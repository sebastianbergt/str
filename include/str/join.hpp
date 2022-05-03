#pragma once

#include <memory>// for std::allocator
#include <string>


namespace str {

/// \brief join STL Container of std::string together into a single string
/// \tparam Container e.g std::vector, std::list
/// \tparam Value default is std::string
/// \tparam Allocator default is std::allocator<Value>
/// \param[in] collection collection to be joined
/// \return a new string of all the strings in the collection joined together
template<template<typename, typename> class Container,
  typename Value = std::string,
  typename Allocator = std::allocator<Value>>
std::string join(const Container<Value, Allocator> &collection)
{
  std::string result{};
  for (const auto &element : collection) { result.append(element); }
  return result;
}

}// namespace str
