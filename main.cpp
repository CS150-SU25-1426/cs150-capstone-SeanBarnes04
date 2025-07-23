#include "RodStock.h"

int main() {
    RodStock testBar(5.5, 50, "Chinesium", "METRIC");
    cout << testBar << "\n";

    testBar.setMat("1022 Low Carbon Steel");
    testBar.operator--();
    cout << testBar << "\n";
    
    testBar.setCut(4.5);
    testBar.operator--();
    cout << testBar << "\n\n";

    RodStock muricaBar("1/2", 24, "6061 Aluminum", "WTF is a kilometer");
    cout << muricaBar << "\n";
    muricaBar.setUnits("IMPERIAL");
    cout << muricaBar << "\n\n";

    RodStock deciBar(50.01, 123.456, "Oak Wood", "METRIC");
    cout << deciBar << "\n";
    deciBar.setDia(100326.002011098732005);
    cout << deciBar << "\n";
    deciBar.setDia(100326.00201198732005);
    cout << deciBar << "\n\n";

    cout << testBar << "\n";
    cout << muricaBar << "\n";
    cout << deciBar << "\n";


    return 0;
}