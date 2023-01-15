#include "Magic.h"

Spell::Spell(): Entity(), Level()
{
    this->cost=0;
    this->type=NULL;
    this->school=NULL;
    this->nrEffects=0;
}
Spell::~Spell()
{}
