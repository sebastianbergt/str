#include <catch2/catch.hpp>
#include <str/join.hpp>

#include <forward_list>
#include <list>
#include <string>
#include <vector>

SCENARIO("str::join basic usage")
{
  std::string STR1{ "abcd" };
  std::string STR2{ "efgh" };
  std::string STR3{ "ijkl" };
  GIVEN("a vector of strings")
  {
    std::vector<std::string> vector_of_strings{ STR1, STR2, STR3 };

    WHEN("join is called")
    {
      const auto result = str::join(vector_of_strings);
      THEN("the result is the joined string") { CHECK(result == std::string{ STR1 + STR2 + STR3 }); }
    }
  }
}

// NOLINTNEXTLINE
TEMPLATE_TEST_CASE("str::join",
  "[test][template]",
  std::vector<std::string>,
  std::forward_list<std::string>,
  std::list<std::string>)
{
  std::string STR1{ "abcd" };
  std::string STR2{ "efgh" };
  std::string STR3{ "ijkl" };
  GIVEN("a vector of strings")
  {
    TestType container_of_strings{ STR1, STR2, STR3 };

    WHEN("join is called")
    {
      const auto result = str::join(container_of_strings);
      THEN("the result is the joined string") { CHECK(result == std::string{ STR1 + STR2 + STR3 }); }
    }
  }
}