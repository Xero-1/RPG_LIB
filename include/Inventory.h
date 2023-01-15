#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory
{
private:
    Item** items;
    unsigned int capacity;
    unsigned int nrItems;

    Counter weight;
public:
    Inventory();
    ~Inventory();
    //inline unsigned int getNrItems(){return sizeof(this->items)/sizeof(this->items[0]);}
    inline unsigned int getNrItems(){return this->nrItems;}
    inline unsigned int getCapacity(){return this->capacity;}
    inline void setCapacity(unsigned int i){this->capacity=i;}
    inline void setNrItems(unsigned int i){this->nrItems=i;}
    inline Counter& getWeight(){return this->weight;}
    inline Item& operator[](unsigned int index){return *this->items[index];}
    void addItem(Item& newItem);
    void removeItem(unsigned int index);
    void expand(unsigned int extraSpace=20);
};

#endif
