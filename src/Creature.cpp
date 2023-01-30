#include "Creature.h"

//////////CREATURE SIMPLE//////////
Creature_simple::Creature_simple(): Entity()
{
	this->_AC=0;
}
Creature_simple::~Creature_simple(){};
//////////CREATURE COMPLEX//////////
Creature_complex::Creature_complex(): Creature_simple(), Level()
{
    Armor a;
    for(int i=0;i<FOOT;i++)
    {
        a.setPartCover(i+1);
        _armorSet[i]=a;
    }
}
Creature_complex::~Creature_complex(){}
//////////EQUIPMENT//////////
void Creature_complex::setArmorPiece(Armor a)
{
	setAC(getAC() - _armorSet[a.getPartCover()].getDefence());//Deacrease defence of previous piece
    this->_armorSet[a.getPartCover()]=a;//Set piece
	setAC(getAC() + _armorSet[a.getPartCover()].getDefence());//Add defence of new piece
}
void Creature_complex::equipItem(Item& item)
{
    if(item.getType()==WEAPON)
    {
        Weapon* w=dynamic_cast<Weapon*>(item.Clone());
		setWeapon(*w);
        delete w;
    }else if(item.getType()==ARMOR)
    {
        Armor *a=dynamic_cast<Armor*>(item.Clone());
        setArmorPiece(*a);
        delete a;
    }
}
void Creature_complex::equipItemFromInv(unsigned int index)
{
    equipItem(_inv[index]);
    _inv.removeItem(index);
}
void Creature_complex::useItem(Item& item)
{
	unsigned short int type=item.getType();
	if(type==POTION)
	{
		Potion* p=dynamic_cast<Potion*>(item.Clone());
		alteredState(_state,p->getEffects());
	}
}
void Creature_complex::useItemFromInv(unsigned int index)
{
    useItem(_inv[index]);
    _inv.removeItem(index);
}
//////////GAME LOOP//////////
void Creature_complex::update()
{
	updateState();
}
void Creature_complex::updateState()
{
	unsigned int size=_state.size();
	for(int i=0;i<size;i++)
	{
		switch(_state[i].getType())
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
		if(_state[i].getTime()<=0)
			deleteEffect(_state,i);
		else
			_state[i].setTime(_state[i].getTime()-1);			
	}
}
