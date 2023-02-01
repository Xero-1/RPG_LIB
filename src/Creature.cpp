#include "Creature.h"

//////////CREATURE SIMPLE//////////
Creature_simple::Creature_simple(): Entity()
{
	this->_AC=0;
}
Creature_simple::~Creature_simple(){};
void Creature_simple::useItem(Item& item)
{
	unsigned short int type=item.getType();
	if(type==POTION)
	{
		Potion* i=dynamic_cast<Potion*>(item.Clone());
		alteredState(_state,i->getEffects());
	}
}
void Creature_simple::castSpell(Creature_simple& obj,Spell& spell)
{
	unsigned short int type=spell.getType();
	if(type==MAGIC_ATTACK)
	{
		Magic_attack* s=dynamic_cast<Magic_attack*>(spell.Clone());
		s->Cast(obj.getHP(),obj.getState());
	}else if(type==CHARM)
	{
		Charm* s=dynamic_cast<Charm*>(spell.Clone());
		s->Cast(obj.getState());
	}
}
bool Creature_simple::castFromSpellBook(Creature_simple& obj,unsigned int index)
{
	if(_MANA._current - _spellBook[index].getCost()>=0)
	{
		castSpell(obj,_spellBook[index]);
		_MANA._current-=_spellBook[index].getCost();
		return true;
	}else
		return false;
}
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
	unsigned short int type=item.getType();
    if(type==WEAPON)
    {
        Weapon* w=dynamic_cast<Weapon*>(item.Clone());
		setWeapon(*w);
        delete w;
    }else if(type==ARMOR)
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
	unsigned int size=getState().size();
	for(int i=0;i<size;i++)
	{
		switch(getState()[i].getType())
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
		if(getState()[i].getTime()<=0)
			deleteEffect(getState(),i);
		else
			getState()[i].setTime(getState()[i].getTime()-1);			
	}
}
