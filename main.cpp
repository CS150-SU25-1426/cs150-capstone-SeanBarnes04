#include "RodStock.h"
#include "ListMaker.h"

int main() {
    
    ListMaker rodList;

    bool endProgram = false;
    int option = 0;
    do {
        cout << "****************************************\n"
             << "*      ROD STOCK INVENTORY MANAGER     *\n"
             << "****************************************\n"
             << "*        SELECT AN OPTION BELOW        *\n"
             << "****************************************\n"
             << "* 1. View Rod Stock List               *\n"
             << "* 2. Add Rod Stock                     *\n"
             << "* 3. Cut Down Rod Stock (broken)       *\n"
             << "* 4. Modify Existing Stock Data        *\n"
             << "* 5. Remove Rod Stock                  *\n"
             << "* 6. Exit Manager                      *\n"
             << "****************************************\n"
             << ">> ";
        cin >> option;
        switch(option) {
            case 1: {
                cout << "List of available rod stock:\n"; 
                cout << rodList << "\n";
            break;
            }
            case 2: {
                string newDia = "" ;
                double newLen  = 0;
                string newMat  = "";
                string newUnits  = "";
                
                cout << "Enter a diameter (string):\n";
                getline(cin, newDia);
                getline(cin, newDia); // needs a double getline for some reason, using cin.clear and cin.ignore both caused infinite loops
                
                cout << "Enter a material (string):\n";
                getline(cin, newMat);

                cout << "Enter units (string):\n";
                getline(cin, newUnits);

                cout << "Enter a length (double):\n";
                cin >> newLen;

                RodStock newRod(newDia, newLen, newMat, newUnits);
                rodList.addRod(newRod);
                cout << endl;
            break; 
            }
            case 3: { // See comments below
                int index = 0;
                cout << "Enter the index # of the rod you wish to cut (enter -1 to cancel): ";
                cin >> index;
                if (index >= 0) {
                    double cutLength;
                    cout << "Enter length of the cut: ";
                    cin >> cutLength;
                    rodList.getRod(rodList, index).setCut(cutLength); // rodList is modified to add cutLength
                    rodList.getRod(rodList, index).operator--(); // operator-- runs, but does not modify existing entry as it would outside the ListMaker list
                }
                
            break; 
            }
            case 4: {
                int index = 0;
                cout << "Enter the index # of the rod you wish to modify (enter -1 to cancel): ";
                cin >> index;

                cin.ignore();
                if (index >= 0) {
                    rodList.modRod(rodList.getRod(rodList, index), index); 
                }
                break;
            }
            case 5: {
                int destroyedRod = -1;
                cout << "Enter the index value for the stock you want to remove: "; 
                cin >> destroyedRod;
                rodList.deleteRod(destroyedRod);
            break;
            }
            case 6: cout << "Program Exited\n\n"; endProgram = true; break;
            default: cout << "Invalid Input\n"; break;
        }
    } while (endProgram == false);
    
    return 0;
}