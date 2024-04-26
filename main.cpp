#include "Hybrid-Vehicle-Virtual.cpp"

int main() {
    string whichVehicle = "Super Vehicle";
    Hybrid hybrid(whichVehicle);
    hybrid.PercentGas(0.5);

    hybrid.Start();
    cout << "Fuel efficiency per dollar: " << hybrid.fuelEfficiencyPerDollar() << endl;

    return 0;
}