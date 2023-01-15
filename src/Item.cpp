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
    this->defence=0;
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
    this->nrEffects=0;
}
Potion::~Potion(){}

Potion* Potion::Clone()const
{
    return new Potion(*this);
}
