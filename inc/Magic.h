#ifndef MAGIC_H
#define MAGIC_H

#include "Basics.h"

enum
{
	MAGIC_ATTACK=1,
	CHARM
} Magic_Types;
//////////SPELL//////////
class Spell: public Entity, public Level
{
private:
    unsigned int cost;
    unsigned short int type;
	std::vector<Effect> effects;
public:
    Spell();
    ~Spell();
    inline unsigned int getCost(){return this->cost;}
    inline unsigned short int getType(){return this->type;}
	inline std::vector<Effect>& getEffects(){return this->effects;}
    inline void setCost(unsigned int i){this->cost=i;}
    inline void setType(unsigned short int i){this->type=i;}

	virtual Spell*Clone()const=0;
};
//////////MAGIC_ATTACK//////////
class Magic_attack: public Spell
{
private:
	Dice dAttack;
public:
	Magic_attack();
	~Magic_attack();
	inline Dice& getDiceAttack(){return this->dAttack;}
	void Cast(Counter& objHP,std::vector<Effect>& objState);

	Magic_attack* Clone()const;
};
//////////CHARM//////////
class Charm: public Spell
{
private:
public:
	Charm();
	~Charm();
	void Cast(std::vector<Effect>& objState);

	Charm* Clone()const;
};

//////////SPELL BOOK//////////
class Spell_book
{
private:
	std::vector<Spell*> spells;
public:
	Spell_book();
	~Spell_book();
	inline unsigned int getSize(){return this->spells.size();}
	inline Spell& operator[](unsigned int index){return *this->spells[index];}
	inline void addSpell(Spell& newSpell){spells.push_back(newSpell.Clone());}
	inline void removeSpell(unsigned int index){spells.erase(spells.begin()+index);}
};
#endif
