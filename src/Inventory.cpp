#include "Inventory.h"

Inventory::Inventory()
{
    this->capacity=5;
    this->nrItems=0;
    items=new Item*[capacity];
    for(int i=0;i<capacity;i++)
        items[i]=nullptr;
}
Inventory::~Inventory()
{
    for(int i=0;i<nrItems;i++)
        delete items[i];
    delete[] items;
}
void Inventory::addItem(Item& newItem)
{
    if(nrItems<capacity)
        items[nrItems++]=newItem.Clone();
}
void Inventory::removeItem(unsigned int index)
{
    Item** temp=new Item*[capacity];
    unsigned int itemCount=0;
    for(int i=0;i<nrItems;i++)
    {
        if(i!=index)
            temp[itemCount++]=items[i]->Clone();
        delete items[i];
        items[i]=nullptr;
    }
    for(int i=nrItems;i<capacity;i++)
        temp[i]=nullptr;
    items=temp;
    this->nrItems--;
}
void Inventory::expand(unsigned int extraSpace)
{
    this->capacity+=extraSpace;
    Item** temp=new Item*[capacity];
    for(int i=0;i<nrItems;i++)
    {
        temp[i]=items[i]->Clone();
        delete items[i];
        items[i]=nullptr;
    }
    for(int i=nrItems;i<capacity;i++)
    	temp[i]=nullptr;
    items=temp;
}
bool Inventory::hasItem(std::string s,unsigned short int itemCant)
{
    unsigned int cant=0;
    for(int i=0;i<nrItems;i++)
    {
        if(s==items[i]->getName())
        	cant++;
	}
	if(cant>=itemCant)
		return true;
	else
		return false;
}
