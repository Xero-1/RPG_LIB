#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H

#include "Magic.h"

class Spell_book
{
private:
	std::vector<Spell*> _spells;
public:
	Spell_book();
	~Spell_book();
	inline Spell& operator[](unsigned int index){return *this->_spells[index];}
	inline void addSpell(Spell& newSpell){_spells.push_back(newSpell.Clone());}
	inline void removeSpell(unsigned int index){_spells.erase(_spells.begin()+index);}
};

#endif
