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
void Magic_attack::Cast(Counter& objHP,std::vector<Effect>& objState)
{
	rollDamage(objHP,dAttack);
	alteredState(objState,getEffects());
}

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
void Charm::Cast(std::vector<Effect>& objState)
{
	alteredState(objState,getEffects());
}

Charm* Charm::Clone()const
{
	return new Charm(*this);
}
