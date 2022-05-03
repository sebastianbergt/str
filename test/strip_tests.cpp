#include <catch2/catch.hpp>
#include <str/strip.hpp>

#include <tuple>

using record = std::tuple<std::string, std::string, std::string>;

record stripTestData()
{
  return GENERATE(table<std::string, std::string, std::string>({
    record{ "  APPLES and ORANGES  ", " ", "APPLES and ORANGES" },
    record{ "  ..APPLES.and ORANGES++  ", " .+", "APPLES.and ORANGES" },
  }));
}


SCENARIO("str::in_place::strip")
{
  auto test_data = stripTestData();

  GIVEN("a input string and characters to remove")
  {
    auto input = std::get<0>(test_data);
    auto characters_to_remove = std::get<1>(test_data);
    const auto expected_output = std::get<2>(test_data);

    WHEN("in place strip is called")
    {
      str::in_place::strip(input, characters_to_remove);
      THEN("the input is stripped") { CHECK(input == expected_output); }
    }
  }
}

SCENARIO("str::copy::strip")
{
  auto test_data = stripTestData();

  GIVEN("a input string and characters to remove")
  {
    const auto input = std::get<0>(test_data);
    const auto characters_to_remove = std::get<1>(test_data);
    const auto expected_output = std::get<2>(test_data);

    WHEN("copy strip is called")
    {
      const auto result = str::copy::strip(input, characters_to_remove);
      THEN("the result is stripped") { CHECK(result == expected_output); }
    }
  }
}
