#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory
{
private:
	std::vector<Item*> _items;
    unsigned int _capacity;
    bool _expandable;
public:
    Inventory();
    ~Inventory();
    inline unsigned int getCapacity(){return this->_capacity;}
	inline bool getExpandable(){return this->_expandable;}
	inline unsigned int getSize(){return this->_items.size();}
	inline void setCapacity(unsigned int i){this->_capacity=i;}
	inline void setExpandable(bool b){this->_expandable=b;}
	inline Item& operator[](unsigned int index){return *this->_items[index];}
    bool addItem(Item& newItem);
    inline void removeItem(unsigned int index){_items.erase(_items.begin()+index);}
    bool hasItem(std::string s,unsigned short int itemCant=1);
};

#endif
