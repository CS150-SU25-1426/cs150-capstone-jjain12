#include <iostream>

#ifndef CAKE_H
#define CAKE_H

using namespace std;

class Cake {
private: 

string flavor;
string icingFlavor;
string message;
string filling;
string decor; 

int size, count; 
double price; 

public:

Cake(string flavor, string icingFlavor, string message, string filling, string decor, int size, int count);
Cake();

string getFlavor() const {return flavor;}
string getIcingFlavor() const {return icingFlavor;}
string getMessage() const {return message;}
string getFilling() const {return filling;}
string getDecor() const {return decor;}
int getSize() const {return size;}
int getCount() const {return count;}
double getPrice() const;

void setFlavor(string f) {flavor = f;}
void setIcingFlavor(string i) {icingFlavor = i;}
void setMessage(string m) {message = m;}
void setFilling(string f) {filling = f;}
void setDecor(string d) {decor = d;}
void setSize(int s) {size = s;}
void setPrice(double p) {price = p;}
void setCount(int c) {count = c;}

bool operator==(const Cake& other) const;

friend ostream& operator << (ostream& os, const Cake& cake);

};

#endif



