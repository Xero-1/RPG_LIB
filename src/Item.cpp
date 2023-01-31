#include "Item.h"

//////////ITEM//////////
Item::Item(): Entity()
{
    this->_type=NULL;
    this->_rarity=NULL;
    this->_valueSell=0;
    this->_valueBuy=0;
}
Item::~Item(){}
//////////WEAPON//////////
Weapon::Weapon(): Item()
{
    setType(WEAPON);
}
Weapon::~Weapon(){}
Weapon* Weapon::Clone()const
{
	return new Weapon(*this);
}
//////////ARMOR//////////
Armor::Armor(): Item()
{
    setType(ARMOR);
    this->_defence=0;
    this->_partCover=NULL;
}
Armor::~Armor(){}
Armor* Armor::Clone()const
{
    return new Armor(*this);
}
//////////POTION//////////
Potion::Potion()
{
    setType(POTION);
}
Potion::~Potion(){}

Potion* Potion::Clone()const
{
    return new Potion(*this);
}
//////////WAND//////////
Wand::Wand(): Item()
{
	setType(WAND);
	this->_spell=nullptr;
	this->_charges=0;
}
Wand::~Wand(){}
void Wand::setSpell(Spell* s)
{
	delete this->_spell;
	this->_spell=s;
}

Wand* Wand::Clone()const
{
	return new Wand(*this);
}
