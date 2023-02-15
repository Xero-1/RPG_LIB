#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory
{
private:
	std::vector<Item*> items;
    unsigned int capacity;
    bool expandable;
public:
    Inventory();
    ~Inventory();
    inline unsigned int getCapacity(){return this->capacity;}
	inline bool getExpandable(){return this->expandable;}
	inline unsigned int getSize(){return this->items.size();}
	inline void setCapacity(unsigned int i){this->capacity=i;}
	inline void setExpandable(bool b){this->expandable=b;}
	inline Item& operator[](unsigned int index){return *this->items[index];}
    bool addItem(Item& newItem);
    inline void removeItem(unsigned int index){items.erase(items.begin()+index);}
    bool hasItem(std::string s,unsigned short int itemCant=1);
};

#endif
