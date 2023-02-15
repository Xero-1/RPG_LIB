#ifndef ITEM_H
#define ITEM_H

#include "Basics.h"
#include "Magic.h"

enum
{
    WEAPON=1,
    ARMOR,
    POTION,
	WAND
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
    unsigned int DEF;
    unsigned short int partCover;
public:
    Armor();
    virtual ~Armor();
    inline unsigned int getDEF(){return this->DEF;}
    inline unsigned short int getPartCover(){return this->partCover;}
    inline void setDEF(unsigned int i){this->DEF=i;}
    inline void setPartCover(unsigned short int i){this->partCover=i;}

    Armor* Clone()const;
};
//////////POTION//////////
class Potion: public Item
{
private:
	std::vector<Effect> effects;
public:
    Potion();
    virtual ~Potion();
	inline std::vector<Effect>& getEffects(){return this->effects;}

    Potion* Clone()const;
};
//////////WAND//////////
class Wand: public Item
{
private:
	Spell* spell;
	unsigned short int charges;
public:
	Wand();
	~Wand();
	inline Spell& getSpell(){return *this->spell;}
	inline unsigned short int getCharges(){return this->charges;}
	void setSpell(Spell* s);
	inline void setCharges(unsigned short int i){this->charges=i;}

	Wand* Clone()const;
};

#endif
