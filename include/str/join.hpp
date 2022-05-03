#pragma once

#include <memory>// for std::allocator
#include <string>


namespace str {

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
