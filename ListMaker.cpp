#include "ListMaker.h"

    ListMaker::ListMaker(RodStock entry) {
        this->rodList.push_back(entry);
        this->counter = 1;
    }
    ListMaker::ListMaker() { this->counter = 0; }
    ListMaker::ListMaker(const ListMaker& other) {
        this->rodList = other.rodList;
        this->counter = other.counter;
    }
    ListMaker::~ListMaker() {
        while (!rodList.empty()) {
            rodList.pop_back();
        }
    }

    void ListMaker::addRod(RodStock entry) {
        this->rodList.push_back(entry);
        this->counter++;
    }

    RodStock ListMaker::getRod(ListMaker list, int index) { return rodList[index]; }
    int ListMaker::getCounter(ListMaker list) { return list.counter;}


    void ListMaker::modRod(RodStock entry, int index) {
        string tempDia = "";
        double tempLen = 0;
        string tempMat = "";
        string tempUnits = "";
        cout << "Rod Stock modifier:\n"
             << "Enter an input for each entry.\n"
             << "Press enter to leave string unchanged.\n"
             << "Enter 0 to leave double unchanged.\n";
        cout << "Enter a diameter (string) (Current dia: " << entry.getDia(entry) << ")\n";
        getline(cin, tempDia);
        cout << "Enter a material (string) (Current material: " << entry.getMat(entry) << ")\n";
        getline(cin, tempMat);
        cout << "Enter units (string) (Current units: " << entry.getUnits(entry) << ")\n";
        getline(cin, tempUnits);
        cout << "Enter a length (double) (Current length: " << entry.getLen(entry) << ")\n";
        cin >> tempLen;

        if (tempDia != "") {
            entry.setDia(tempDia);
        }
        if (tempLen != 0) {
            entry.setLen(tempLen);
        }
        if (tempMat != "") {
            entry.setMat(tempMat);
        }
        if (tempUnits != "") {
            entry.setUnits(tempUnits);
        }
        rodList[index] = entry;

    }
    void ListMaker::replaceRod(RodStock entry, int index) {
        rodList[index] = entry;
    }
    void ListMaker::deleteRod(int index) {
        rodList.erase(rodList.begin() + index);
        counter--;
    }

    ostream& operator<<(ostream& os, const ListMaker& l) {
        for (int i = 0; i < l.counter; i++) {
            os << "Index #" << i << ":  " << l.rodList[i] << "\n";
        }
        return os;
    }

    bool ListMaker::operator==(const ListMaker& other) const {
        return counter == other.counter;
    }