#include <catch2/catch.hpp>
#include <str/title.hpp>

#include <tuple>

using record = std::tuple<std::string, std::string>;

record titleTestData()
{
  return GENERATE(table<std::string, std::string>(
    { record{ "hello sample", "Hello Sample" }, record{ "# very funny", "# Very Funny" }, record{ "", "" } }));
}


SCENARIO("str::in_place::title")
{
  auto extent = titleTestData();

  GIVEN("a string")
  {
    auto input = std::get<0>(extent);
    const auto expected_output = std::get<1>(extent);

    WHEN("in place title is called")
    {
      str::in_place::title(input);
      THEN("the input is title case") { CHECK(input == expected_output); }
    }
  }
}

SCENARIO("str::copy::title")
{
  auto extent = titleTestData();

  GIVEN("a string")
  {
    auto input = std::get<0>(extent);
    const auto expected_output = std::get<1>(extent);

    WHEN("copy title is called")
    {
      const auto result = str::copy::title(input);
      THEN("the result is title case") { CHECK(result == expected_output); }
    }
  }
}
