#include "Inventory.h"

Inventory::Inventory()
{
    this->capacity=5;
	this->expandable=false;
}
Inventory::~Inventory()
{
	unsigned int size=items.size();
    for(int i=0;i<size;i++)
      	items.pop_back();
}
bool Inventory::addItem(Item& newItem)
{
    if(items.size()<capacity || expandable)
	{
		items.push_back(newItem.Clone());
		if(items.size()>=capacity)
			this->capacity+=5;
		return true;
	}else
		return false;
}
bool Inventory::hasItem(std::string s,unsigned short int itemCant)
{
    unsigned int cant=0,size=items.size();
    for(int i=0;i<size;i++)
    {
        if(s==items[i]->getName())
        	cant++;
	}
	if(cant>=itemCant)
		return true;
	else
		return false;
}
