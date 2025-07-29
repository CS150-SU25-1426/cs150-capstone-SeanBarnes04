#ifndef RODSTOCK_h
#define RODSTOCK_h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class RodStock {
private:
    double length;
    string diameter; // allows diameter to be written as 1/4 or 0.25, not used for math
    string material;
    string units; // inches (IMPERIAL) or mm (METRIC) for purposes of this project
    double toCut;

public:
    RodStock(string diameter, double length, string material, string units);
    RodStock(double diameter, double length, string material, string units);
    RodStock(const RodStock& other);
    ~RodStock();

    string getDia(RodStock rodstock);
    double getLen(RodStock rodstock);
    string getMat(RodStock rodstock);
    string getUnits(RodStock rodstock);

    void setDia(string diameter);
    void setLen(double length);
    void setMat(string material);
    void setUnits(string units);
    void setDia(double diameter);

    void setCut(double cutLength);
    double getCut(RodStock rodstock);
    RodStock operator--();

    friend ostream& operator<<(ostream& os, const RodStock& r);

};

#endif