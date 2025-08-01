#include <iomanip>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
#include "Cake.h"

Cake::Cake(string flavor, string icingFlavor, string message, string filling, string decor, int size, int count) 
    : flavor(flavor), icingFlavor(icingFlavor), message(message), filling(filling), decor(decor), size(size), count(count) {}

Cake::Cake() : flavor(""), icingFlavor(""), message(""), filling(""), decor(""), size(0), count(0) {}
    

bool Cake::operator==(const Cake& other) const {
    return (flavor == other.flavor &&
            icingFlavor == other.icingFlavor &&
            message == other.message &&
            filling == other.filling &&
            decor == other.decor &&
            size == other.size &&
            count == other.count &&
            price == other.price);
}

double Cake::getPrice() const{
    double basePrice = size*5.0;
    if (filling != "") {
        basePrice += 5.0; 
    }
    basePrice *= count; 
    double finalPrice = basePrice * (1.0925);
    return finalPrice;
}

ostream& operator<<(ostream& os, const Cake& cake) {
    os << "\n************************************************************************\n";
    os << setw(10) << left << "Flavor: " << setw(20) << left << cake.flavor << setw(8) << left << "Icing: " << setw(15) << left << cake.icingFlavor << "\n";
    os << setw(10) << left << "Filling: " << setw(20) << left << cake.filling << setw(8) << left << "Decor: " << setw(15) << left << cake.decor << "\n";
    os << setw(10) << left << "Size: " << setw(20) << left << cake.size << setw(8) << left << "Count: " << setw(15) << left << cake.count << "\n";
    os << setw(10) << left << "Message: \"" << cake.message << "\"\n";
    os << setw(10) << left << "Price: " << "$" << fixed << setprecision(2) << cake.getPrice() << "\n";
    os << "************************************************************************\n";

    return os;
}