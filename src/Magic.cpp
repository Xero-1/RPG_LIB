#include "Magic.h"

//////////SPELL//////////
Spell::Spell(): Entity(), Level()
{
    this->cost=0;
    this->type=NULL;
}
Spell::~Spell(){}
//////////MAGIC_ATTACK//////////
Magic_attack::Magic_attack(): Spell()
{
	setType(MAGIC_ATTACK);
}
Magic_attack::~Magic_attack(){}

Magic_attack* Magic_attack::Clone()const
{
	return new Magic_attack(*this);
}
//////////CHARM//////////
Charm::Charm(): Spell()
{
	setType(CHARM);
}
Charm::~Charm(){}

Charm* Charm::Clone()const
{
	return new Charm(*this);
}
