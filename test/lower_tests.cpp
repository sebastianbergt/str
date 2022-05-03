#include <catch2/catch.hpp>
#include <str/lower.hpp>

#include <tuple>

using record = std::tuple<std::string, std::string>;

record lowerTestData()
{
  return GENERATE(table<std::string, std::string>({ record{ "SAMPLE", "sample" },
    record{ "I\\$f`(*E", "i\\$f`(*e" },
    record{ "hp*Yh+$]", "hp*yh+$]" },
    record{ ")E0Sp=aJ", ")e0sp=aj" },
    record{ "%\\7ba`IJ", "%\\7ba`ij" },
    record{ "=^oZ:cb_", "=^oz:cb_" },
    record{ "P!oWgOtU", "p!owgotu" },
    record{ "+!r+=oSY", "+!r+=osy" },
    record{ "*Z\\2E!/q", "*z\\2e!/q" },
    record{ "\"weW\'}9T", "\"wew\'}9t" },
    record{ "|A<w@;cY", "|a<w@;cy" },
    record{ ".L[P^&+|", ".l[p^&+|" },
    record{ "EHyb2F{[", "ehyb2f{[" } }));
}


SCENARIO("str::in_place::lower")
{
  auto extent = lowerTestData();

  GIVEN("a string")
  {
    auto input = std::get<0>(extent);
    const auto expected_output = std::get<1>(extent);

    WHEN("in place lower is called")
    {
      str::in_place::lower(input);
      THEN("the input is lower case") { CHECK(input == expected_output); }
    }
  }
}

SCENARIO("str::copy::lower")
{
  auto extent = lowerTestData();

  GIVEN("a string")
  {
    auto input = std::get<0>(extent);
    const auto expected_output = std::get<1>(extent);

    WHEN("copy lower is called")
    {
      const auto result = str::copy::lower(input);
      THEN("the result is lower case") { CHECK(result == expected_output); }
    }
  }
}
