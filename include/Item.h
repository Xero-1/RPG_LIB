#ifndef ITEM_H
#define ITEM_H

#include "Basics.h"

enum
{
    WEAPON=1,
    ARMOR,
    POTION
} Item_Types;
enum
{
    HEAD=1,
    CHEST,
    ARM,
    HAND,
    LEG,
    FOOT
} Body_Parts;
//////////ITEM//////////
class Item: public Entity
{
private:
    unsigned short int type;
    unsigned short int rarity;
    unsigned int valueSell;
    unsigned int valueBuy;
public:
    Item();
    ~Item();
    inline unsigned short int getType(){return this->type;}
    inline unsigned short int getRarity(){return this->rarity;}
    inline unsigned int getValueSell(){return this->valueSell;}
    inline unsigned int getValueBuy(){return this->valueBuy;}
    inline void setType(unsigned short int i){this->type=i;}
    inline void setRarity(unsigned short int i){this->rarity=i;}
    inline void setValueSell(unsigned int i){this->valueSell=i;}
    inline void setValueBuy(unsigned int i){this->valueBuy=i;}

    virtual Item*Clone()const=0;
};
//////////WEAPON//////////
class Weapon: public Item
{
private:
    Dice dAttack;
public:
    Weapon();
    virtual ~Weapon();
    inline Dice& getDiceAttack(){return this->dAttack;}

    Weapon* Clone()const;
};
//////////ARMOR//////////
class Armor: public Item
{
private:
    unsigned int defence;
    unsigned short int partCover;
public:
    Armor();
    virtual ~Armor();
    inline unsigned int getDefence(){return this->defence;}
    inline unsigned short int getPartCover(){return this->partCover;}
    inline void setDefence(unsigned int i){this->defence=i;}
    inline void setPartCover(unsigned short int i){this->partCover=i;}

    Armor* Clone()const;
};
//////////POTION//////////
class Potion: public Item
{
private:
    unsigned short int nrEffects;
    State effects[PARALYZED];
public:
    Potion();
    virtual ~Potion();
    inline unsigned short int getNrEffects(){return this->nrEffects;}
    inline void setNrEffects(unsigned short int i){this->nrEffects=i;}
    inline State* getEffects(){return this->effects;}
    inline void causeEffects(State* obj){causeAlteredStates(nrEffects,effects,obj);}

    Potion* Clone()const;
};

#endif
