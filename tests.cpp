#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Hybrid-Vehicle-Virtual.cpp"

TEST_CASE("Testing Vehicle Operations") {
    Vehicle v("Test Vehicle");
    SUBCASE("Start and Stop Functions") {
        v.Start();
        v.Stop();
    }
}

TEST_CASE("Testing Gasoline Vehicle Efficiency") {
    Gasoline g("Gasoline");
    CHECK(g.gasolineMilesPerDollar() == 20.0);
}

TEST_CASE("Testing Electric Vehicle Efficiency") {
    Electric e("Electric");
    CHECK(e.electricMilesPerDollar() == 40.0);
}

TEST_CASE("Testing Hybrid Vehicle") {
    Hybrid h("Hybrid");
    h.PercentGas(0.5);
    CHECK(h.fuelEfficiencyPerDollar() == doctest::Approx(30.0));
    SUBCASE("Start and Stop Functions") {
        h.Start();
        h.Stop();
    }
}
