#include "Creature.h"

Creature::Creature(): Entity(), Level()
{
    this->AC=0;
    Armor a;
    for(int i=0;i<FOOT;i++)
    {
        a.setPartCover(i+1);
        _armorSet[i]=a;
    }
}
Creature::~Creature(){}
//////////EQUIPMENT//////////
void Creature::setArmorPiece(Armor a)
{
    this->AC-=_armorSet[a.getPartCover()-1].getDefence();//Deacrease defence of previous piece
    this->_armorSet[a.getPartCover()-1]=a;//Set piece
    this->AC+=_armorSet[a.getPartCover()-1].getDefence();//Add defence of new piece
}
void Creature::equipItem(Item& item)
{
    if(item.getType()==WEAPON)
    {
        Weapon* w=dynamic_cast<Weapon*>(item.Clone());
        this->_weapon=*w;
        delete w;
    }else if(item.getType()==ARMOR)
    {
        Armor *a=dynamic_cast<Armor*>(item.Clone());
        setArmorPiece(*a);
        delete a;
    }
}
void Creature::equipItemFromInv(unsigned int index)
{
    equipItem(inv[index]);
    inv.removeItem(index);
}
void Creature::useItem(Item& item)
{
	unsigned short int type=item.getType();
	if(type==POTION)
	{
		Potion* p=dynamic_cast<Potion*>(item.Clone());
		alteredState(state,p->getEffects());
	}
}
void Creature::useItemFromInv(unsigned int index)
{
    useItem(inv[index]);
    inv.removeItem(index);
}
//////////GAME LOOP//////////
void Creature::update()
{
	updateState();
}
void Creature::updateState()
{
	unsigned int size=state.size();
	for(int i=0;i<size;i++)
	{
		switch(state[i].getType())
		{
			case HEALING:
				break;
			case POISONED:
				break;
			case BURNING:
				break;
			case STUNNED:
				break;
			case PARALYZED:
				break;
		}
		if(state[i].getTime()<=0)
			deleteEffect(state,i);
		else
			state[i].setTime(state[i].getTime()-1);			
	}
}
