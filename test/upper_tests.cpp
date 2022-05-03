#include <catch2/catch.hpp>
#include <str/upper.hpp>

#include <tuple>

using record = std::tuple<std::string, std::string>;

record upperTestData()
{
  return GENERATE(table<std::string, std::string>({ record{ "sample", "SAMPLE" },
    record{ "I\\$f`(*E", "I\\$F`(*E" },
    record{ "hp*Yh+$]", "HP*YH+$]" },
    record{ ")E0Sp=aJ", ")E0SP=AJ" },
    record{ "%\\7ba`IJ", "%\\7BA`IJ" },
    record{ "=^oZ:cb_", "=^OZ:CB_" },
    record{ "P!oWgOtU", "P!OWGOTU" },
    record{ "+!r+=oSY", "+!R+=OSY" },
    record{ "*Z\\2E!/q", "*Z\\2E!/Q" },
    record{ "\"weW\'}9T", "\"WEW\'}9T" },
    record{ "|A<w@;cY", "|A<W@;CY" },
    record{ ".L[P^&+|", ".L[P^&+|" },
    record{ "EHyb2F{[", "EHYB2F{[" } }));
}


SCENARIO("str::in_place::upper")
{
  auto extent = upperTestData();

  GIVEN("a string")
  {
    auto input = std::get<0>(extent);
    const auto expected_output = std::get<1>(extent);

    WHEN("in place upper is called")
    {
      str::in_place::upper(input);
      THEN("the input is upper case") { CHECK(input == expected_output); }
    }
  }
}

SCENARIO("str::copy::upper")
{
  auto extent = upperTestData();

  GIVEN("a string")
  {
    auto input = std::get<0>(extent);
    const auto expected_output = std::get<1>(extent);

    WHEN("copy upper is called")
    {
      const auto result = str::copy::upper(input);
      THEN("the result is upper case") { CHECK(result == expected_output); }
    }
  }
}
