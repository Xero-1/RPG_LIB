#include "Item.h"

//////////ITEM//////////
Item::Item(): Entity()
{
    this->type=NULL;
    this->rarity=NULL;
    this->valueSell=0;
    this->valueBuy=0;
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
    this->DEF=0;
    this->partCover=NULL;
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
	this->spell=nullptr;
	this->charges=0;
}
Wand::~Wand(){}
void Wand::setSpell(Spell* s)
{
	delete this->spell;
	this->spell=s;
}

Wand* Wand::Clone()const
{
	return new Wand(*this);
}
