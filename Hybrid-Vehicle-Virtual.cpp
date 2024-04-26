#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
protected:
    double weight;
    string name;

public:
    Vehicle() { cout << "Constructor(): Vehicle" << endl; }
    Vehicle(string name) : name(name) { cout << "Constructor(string name): Vehicle" << endl; }
    
    virtual ~Vehicle() {
        cout << "Destructor: Vehicle" << endl;
    }

    virtual void Start() { cout << "Vehicle START" << endl; }
    virtual void Stop() { cout << "Vehicle STOP" << endl; }
};

class Gasoline : public virtual Vehicle {
public:
    Gasoline(string name) : Vehicle(name) {
        cout << "Constructor: Gasoline" << endl;
    }
    ~Gasoline() {
        cout << "Destructor: Gasoline" << endl;
    }

    double gasolineMilesPerDollar() {
        cout << "Calculating Gasoline Efficiency" << endl;
        return 20.0;
    }
};

class Electric : public virtual Vehicle {
public:
    Electric(string name) : Vehicle(name) {
        cout << "Constructor: Electric" << endl;
    }
    ~Electric() {
        cout << "Destructor: Electric" << endl;
    }

    double electricMilesPerDollar() {
        cout << "Calculating Electric Efficiency" << endl;
        return 40.0;
    }
};

class Hybrid : public Electric, public Gasoline {
private:
    double _percentGas;

public:
    Hybrid(string name) : Vehicle(name), Electric(name), Gasoline(name) {
        cout << "Constructor: Hybrid" << endl;
    }
    ~Hybrid() {
        cout << "Destructor: Hybrid" << endl;
    }

    double fuelEfficiencyPerDollar() {
        cout << "Calculating Hybrid Efficiency" << endl;
        double percentElectric = 1 - _percentGas;
        return (electricMilesPerDollar() * percentElectric) + (gasolineMilesPerDollar() * _percentGas);
    }

    double PercentGas() {
        return _percentGas;
    }

    void PercentGas(double pg) {
        _percentGas = pg;
    }

    void Start() override { cout << "Hybrid START" << endl; }
    void Stop() override { cout << "Hybrid STOP" << endl; }
};
