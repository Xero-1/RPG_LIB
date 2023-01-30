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
