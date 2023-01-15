#ifndef CREATURE_H
#define CREATURE_H

#include "Inventory.h"

enum
{
    STRENGTH=1,
    DEXTERITY,
    CONSTITUTION,
    INTELLIGENCE,
    WISDOM,
    CHARISMA
} Stats;
class Creature: public Entity, public Level
{
private:
    Counter HP;
    Counter MANA;
    State state[PARALYZED];
    Inventory inv;
    unsigned int AC;
    Weapon _weapon;
    Armor _armorSet[FOOT];
    unsigned short int stats[CHARISMA];
    short int statMods[CHARISMA];
public:
    Creature();
    ~Creature();
    inline Counter& getHP(){return this->HP;}
    inline Counter& getMANA(){return this->MANA;}
    inline State* getState(){return this->state;}
    inline Inventory& getInv(){return this->inv;}
    inline unsigned int getAC(){return this->AC;}
    inline void setAC(unsigned int i){this->AC=i;}
    inline unsigned short int* getStats(){return this->stats;}
    inline short int* getStatMods(){return this->statMods;}
    //////////EQUIPMENT//////////
    inline Weapon& getWeapon(){return this->_weapon;}
    inline void setWeapon(Weapon w){this->_weapon=w;}
    inline Armor& getArmorPiece(unsigned int piece){return this->_armorSet[piece-1];}
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
