#include "SpellBook.h"

Spell_book::Spell_book(){}
Spell_book::~Spell_book()
{
	unsigned int size=_spells.size();
	for(int i=0;i<size;i++)
		_spells.pop_back();
}

