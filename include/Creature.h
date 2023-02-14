#ifndef CREATURE_H
#define CREATURE_H

#include "Inventory.h"

enum
{
    STRENGTH=0,
    DEXTERITY,
    CONSTITUTION,
    INTELLIGENCE,
    WISDOM,
    CHARISMA,
    COUNT_STATS
} Stats;
class Creature: public Entity
{
private:
	Counter HP;
	Counter MP;
	unsigned int AC;
	Weapon weapon;
	std::vector<Effect> state;
	Spell_book spellBook;
public:
	Creature();
	inline Counter& getHP(){return this->HP;}
	inline Counter& getMP(){return this->MP;}
	inline unsigned int getAC(){return this->AC;}
	inline Weapon& getWeapon(){return this->weapon;}
	inline std::vector<Effect>& getState(){return this->state;}
	inline void setAC(unsigned int i){this->AC=i;}
	inline void setWeapon(Weapon w){this->weapon=w;}
	inline Spell_book& getSpellBook(){return this->spellBook;}
	void useItem(Item& item);
	void castSpell(Creature& obj,Spell& spell);
	bool castFromSpellBook(Creature& obj,unsigned int index);
};

class Creature_complex: public Creature, public Level
{
private:
    Inventory inv;
    Armor armorSet[COUNT_BODY_PARTS];
    unsigned short int stats[COUNT_STATS];
    short int statMods[COUNT_STATS];
public:
    Creature_complex();
    ~Creature_complex();
    inline Inventory& getInv(){return this->inv;}
    inline unsigned short int* getStats(){return this->stats;}
    inline short int* getStatMods(){return this->statMods;}
    //////////EQUIPMENT//////////
    inline Armor& getArmorPiece(unsigned int piece){return this->armorSet[piece];}
    void setArmorPiece(Armor a);
    void equipItem(Item& item);
    void equipItemFromInv(unsigned int index);
    void useItemFromInv(unsigned int index);
    //////////GAME LOOP//////////
    void update();
	void updateState();
};

#endif
