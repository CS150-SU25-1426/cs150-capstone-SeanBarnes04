#include "RodStock.h"


RodStock::RodStock(string diameter, double length, string material, string units) {
    this->diameter = diameter;
    this->length = length;
    this->material = material;
    this->toCut = 0;
    if (units == "METRIC") {
        this->units = " mm";
    } else if (units == "IMPERIAL") {
        this->units = "\"";
    } else {
        this->units = " units"; // generic units as default value
    }
}
RodStock::RodStock(double diameter, double length, string material, string units) { // automatic conversion of number input to string
    string temp = to_string(diameter);
    int numLength = temp.length();
    bool startCount = false;
    string numToString = "";
    string leadingZero = "";
    for (int i = 0; i < numLength; i++) {
        char c = temp[i];
        if (isdigit(c) && startCount == false) {
            numToString += c;
        }
        if (c == '.') {
            startCount = true;
            numToString += c;
        }
        if (startCount == true && isdigit(c)) {
            if (c != '0') {
                numToString += leadingZero;
                leadingZero = "";
                numToString += c;
            } else {
                leadingZero += c;
            }
        }
    }
    this->diameter = numToString;
    this->length = length;
    this->material = material;
    this->toCut = 0;
    if (units == "METRIC") {
        this->units = " mm";
    } else if (units == "IMPERIAL") {
        this->units = "\"";
    } else {
        this->units = " units"; // generic units as default value
    }
}

RodStock::RodStock(const RodStock& other) {
    this->diameter = other.diameter;
    this->length = other.length;
    this->material = other.material;
    this->units = other.units;
}

RodStock::~RodStock() {}

string RodStock::getDia(RodStock rodstock) { return rodstock.diameter; }
double RodStock::getLen(RodStock rodstock) { return rodstock.length; }
string RodStock::getMat(RodStock rodstock) { return rodstock.material; }
string RodStock::getUnits(RodStock rodstock) { return rodstock.units; }

void RodStock::setDia(string diameter) { this->diameter = diameter; }
void RodStock::setLen(double length) { this->length = length; }
void RodStock::setMat(string material) { this->material = material; }
void RodStock::setUnits(string units) { 
    if (units == "METRIC") {
        this->units = " mm";
    } else if (units == "IMPERIAL") {
        this->units = "\"";
    } else {
        this->units = " units"; // generic units as default value
    } 
}

void RodStock::setDia(double diameter) {
    string temp = to_string(diameter);
    int numLength = temp.length();
    bool startCount = false;
    string numToString = "";
    string leadingZero = "";
    for (int i = 0; i < numLength; i++) {
        char c = temp[i];
        if (isdigit(c) && startCount == false) {
            numToString += c;
        }
        if (c == '.') {
            startCount = true;
            numToString += c;
        }
        if (startCount == true && isdigit(c)) {
            if (c != '0') {
                numToString += leadingZero;
                leadingZero = "";
                numToString += c;
            } else {
                leadingZero += c;
            }
        }
    }
    this->diameter = numToString;
}

void RodStock::setCut(double cutLength) { this->toCut = cutLength; }
RodStock RodStock::operator--() { // cutLength must be called first, otherwise this function does nothing
    length -= toCut;
    return *this;
}

ostream& operator<<(ostream& os, const RodStock& r) {
        os << r.material << " Rod Stock [" << r.diameter << r.units << " diameter, " << r.length << r.units << " long]";
        return os;
    }
