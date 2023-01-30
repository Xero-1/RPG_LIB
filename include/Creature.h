#ifndef CREATURE_H
#define CREATURE_H

#include "Inventory.h"
#include "SpellBook.h"

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
class Creature_simple: public Entity
{
private:
	Counter _HP;
	Counter _MANA;
	unsigned int _AC;
	Weapon _weapon;
	Spell_book _spellBook;
public:
	Creature_simple();
	~Creature_simple();
	inline Counter& getHP(){return this->_HP;}
	inline Counter& getMANA(){return this->_MANA;}
	inline unsigned int getAC(){return this->_AC;}
	inline Weapon& getWeapon(){return this->_weapon;}
	inline void setAC(unsigned int i){this->_AC=i;}
	inline void setWeapon(Weapon w){this->_weapon=w;}
	inline Spell_book& getSpellBook(){return this->_spellBook;}
};

class Creature_complex: public Creature_simple, public Level
{
private:
    Inventory _inv;
    Armor _armorSet[COUNT_BODY_PARTS];
    unsigned short int _stats[COUNT_STATS];
    short int _statMods[COUNT_STATS];
	std::vector<Effect> _state;
public:
    Creature_complex();
    ~Creature_complex();
    inline Inventory& getInv(){return this->_inv;}
    inline unsigned short int* getStats(){return this->_stats;}
    inline short int* getStatMods(){return this->_statMods;}
	inline std::vector<Effect>& getState(){return this->_state;}
    //////////EQUIPMENT//////////
    inline Armor& getArmorPiece(unsigned int piece){return this->_armorSet[piece];}
    void setArmorPiece(Armor a);
    void equipItem(Item& item);
    void equipItemFromInv(unsigned int index);
    void useItem(Item& item);
    void useItemFromInv(unsigned int index);
    //////////GAME LOOP//////////
    void update();
	void updateState();
};

#endif
