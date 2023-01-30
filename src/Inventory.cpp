#include "Inventory.h"

Inventory::Inventory()
{
    this->_capacity=5;
	this->_expandable=false;
}
Inventory::~Inventory()
{
	unsigned int size=_items.size();
    for(int i=0;i<size;i++)
      	_items.pop_back();
}
bool Inventory::addItem(Item& newItem)
{
    if(_items.size()<_capacity || _expandable)
	{
		_items.push_back(newItem.Clone());
		if(_items.size()>=_capacity)
			this->_capacity+=5;
		return true;
	}else
		return false;
}
bool Inventory::hasItem(std::string s,unsigned short int itemCant)
{
    unsigned int cant=0,size=_items.size();
    for(int i=0;i<size;i++)
    {
        if(s==_items[i]->getName())
        	cant++;
	}
	if(cant>=itemCant)
		return true;
	else
		return false;
}
