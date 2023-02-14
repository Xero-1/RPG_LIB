#include "Creature.h"

//////////CREATURE SIMPLE//////////
Creature::Creature(): Entity()
{
	this->HP.MAX=0;
	this->HP.CURRENT=0;
	this->MP.MAX=0;
	this->MP.CURRENT=0;
	this->AC=0;
}
void Creature::useItem(Item& item)
{
	unsigned short int type=item.getType();
	if(type==POTION)
	{
		Potion* i=dynamic_cast<Potion*>(item.Clone());
		alteredState(state,i->getEffects());
	}
}
void Creature::castSpell(Creature& obj,Spell& spell)
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
bool Creature::castFromSpellBook(Creature& obj,unsigned int index)
{
	if(MP.CURRENT-spellBook[index].getCost()>=0)
	{
		castSpell(obj,spellBook[index]);
		MP.CURRENT-=spellBook[index].getCost();
		return true;
	}else
		return false;
}
//////////CREATURE COMPLEX//////////
Creature_complex::Creature_complex(): Creature(), Level()
{
    Armor a;
    for(int i=0;i<FOOT;i++)
    {
        a.setPartCover(i+1);
        armorSet[i]=a;
    }
}
Creature_complex::~Creature_complex(){}
//////////EQUIPMENT//////////
void Creature_complex::setArmorPiece(Armor a)
{
	setAC(getAC()-armorSet[a.getPartCover()].getDEF());//Deacrease defence of previous piece
    this->armorSet[a.getPartCover()]=a;//Set piece
	setAC(getAC()+armorSet[a.getPartCover()].getDEF());//Add defence of new piece
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
    equipItem(inv[index]);
    inv.removeItem(index);
}
void Creature_complex::useItemFromInv(unsigned int index)
{
    useItem(inv[index]);
    inv.removeItem(index);
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
