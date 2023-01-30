#ifndef ITEM_H
#define ITEM_H

#include "Basics.h"
#include "Magic.h"

enum
{
    WEAPON=1,
    ARMOR,
    POTION
} Item_Types;
enum
{
    HEAD=0,
    CHEST,
    ARM,
    HAND,
    LEG,
    FOOT,
    COUNT_BODY_PARTS
} Body_Parts;
//////////ITEM//////////
class Item: public Entity
{
private:
    unsigned short int _type;
    unsigned short int _rarity;
    unsigned int _valueSell;
    unsigned int _valueBuy;
public:
    Item();
    ~Item();
    inline unsigned short int getType(){return this->_type;}
    inline unsigned short int getRarity(){return this->_rarity;}
    inline unsigned int getValueSell(){return this->_valueSell;}
    inline unsigned int getValueBuy(){return this->_valueBuy;}
	inline void setType(unsigned short int i){this->_type=i;}
    inline void setRarity(unsigned short int i){this->_rarity=i;}
    inline void setValueSell(unsigned int i){this->_valueSell=i;}
    inline void setValueBuy(unsigned int i){this->_valueBuy=i;}

    virtual Item*Clone()const=0;
};
//////////WEAPON//////////
class Weapon: public Item
{
private:
    Dice _dAttack;
public:
    Weapon();
    virtual ~Weapon();
    inline Dice& getDiceAttack(){return this->_dAttack;}

    Weapon* Clone()const;
};
//////////ARMOR//////////
class Armor: public Item
{
private:
    unsigned int _defence;
    unsigned short int _partCover;
public:
    Armor();
    virtual ~Armor();
    inline unsigned int getDefence(){return this->_defence;}
    inline unsigned short int getPartCover(){return this->_partCover;}
    inline void setDefence(unsigned int i){this->_defence=i;}
    inline void setPartCover(unsigned short int i){this->_partCover=i;}

    Armor* Clone()const;
};
//////////POTION//////////
class Potion: public Item
{
private:
	std::vector<Effect> _effects;
public:
    Potion();
    virtual ~Potion();
	inline std::vector<Effect>& getEffects(){return this->_effects;}

    Potion* Clone()const;
};

#endif
