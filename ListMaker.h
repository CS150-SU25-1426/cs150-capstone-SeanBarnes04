#include "RodStock.h"
#include <vector>

#ifndef LISTMAKER_h
#define LISTMAKER_h

class ListMaker {
private:
    vector<RodStock> rodList;
    int counter;
public:
    ListMaker(RodStock entry);
    ListMaker();
    ListMaker(const ListMaker& other);
    ~ListMaker();

    void addRod(RodStock entry);
    RodStock getRod(ListMaker list, int index);
    int getCounter(ListMaker list);

    void modRod(RodStock entry, int index);
    void replaceRod(RodStock entry, int index);
    void deleteRod(int index);

    friend ostream& operator<<(ostream& os, const ListMaker& r);
    bool operator==(const ListMaker& other) const;

};

#endif // LISTMAKER_h
