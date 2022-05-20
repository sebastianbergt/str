#include <catch2/catch.hpp>
#include <str/split.hpp>

#include <deque>
#include <list>
#include <string>
#include <vector>

struct TestFixture
{
  std::string STR1{ "abcd" };
  std::string STR2{ "efgh" };
  std::string STR3{ "ijkl" };
  std::string DELIMITER{ "hckp" };
};

// NOLINTNEXTLINE
SCENARIO_METHOD(TestFixture, "str::split basic usage")
{
  GIVEN("a string with delimiters")
  {
    std::string input{};
    if (GENERATE(true, false)) {
      input = STR1 + DELIMITER + STR2 + DELIMITER + STR3;
    } else {
      input = STR1 + DELIMITER + STR2 + DELIMITER + STR3 + DELIMITER;
    }

    WHEN("split is called with std::vector as the result type")
    {
      const std::vector<std::string> result = str::split<std::vector>(input, DELIMITER);
      THEN("the result is the split string")
      {
        REQUIRE(result.size() == 3);
        CHECK(result.at(0) == STR1);
        CHECK(result.at(1) == STR2);
        CHECK(result.at(2) == STR3);
      }
    }

    WHEN("split is called with std::list as the result type")
    {
      std::list<std::string> result = str::split<std::list>(input, DELIMITER);
      THEN("the result is the split string")
      {
        REQUIRE(result.size() == 3);
        CHECK(result.front() == STR1);
        result.pop_front();
        CHECK(result.front() == STR2);
        result.pop_front();
        CHECK(result.front() == STR3);
      }
    }

    WHEN("split is called with std::deque as the result type")
    {
      std::deque<std::string> result = str::split<std::deque>(input, DELIMITER);
      THEN("the result is the split string")
      {
        REQUIRE(result.size() == 3);
        CHECK(result.front() == STR1);
        result.pop_front();
        CHECK(result.front() == STR2);
        result.pop_front();
        CHECK(result.front() == STR3);
      }
    }
  }
}
