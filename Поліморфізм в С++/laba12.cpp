#include <iostream>
#include <vector>
using namespace std;

class Property {
protected:
    double worth;
public:
    virtual ~Property() {
        cout << "Destructor of Property called\n";
    }

    Property(double w) : worth(w) {
        cout << "Constructor of Property called with worth: " << worth << "\n";
    }

    virtual double calculateTax() const = 0;
};


class Appartment : public Property {
public:
    Appartment(double w) : Property(w) {
        cout << "Constructor of Appartment called\n";
    }

    ~Appartment() {
        cout << "Destructor of Appartment called\n";
    }

    double calculateTax() const override {
        return worth / 1000;
    }
};

class Car : public Property {
public:
    Car(double w) : Property(w) {
        cout << "Constructor of Car called\n";
    }

    ~Car() {
        cout << "Destructor of Car called\n";
    }

    double calculateTax() const override {
        return worth / 200;
    }
};

class CountryHouse : public Property {
public:
    CountryHouse(double w) : Property(w) {
        cout << "Constructor of CountryHouse called\n";
    }

    ~CountryHouse() {
        cout << "Destructor of CountryHouse called\n";
    }

    double calculateTax() const override {
        return worth / 500;
    }
};

int main() {
    vector<Property*> properties;

    properties.push_back(new Appartment(100000));
    properties.push_back(new Appartment(150000));
    properties.push_back(new Appartment(200000));

    properties.push_back(new Car(30000));
    properties.push_back(new Car(25000));

    properties.push_back(new CountryHouse(50000));
    properties.push_back(new CountryHouse(100000));

    for (auto prop : properties) {
        cout << "Tax: " << prop->calculateTax() << endl;
    }

    for (auto prop : properties) {
        delete prop;
    }
    return 0;
}
