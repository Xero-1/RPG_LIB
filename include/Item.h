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
    unsigned short int type;
    unsigned short int rarity;
    unsigned int valueSell;
    unsigned int valueBuy;
	bool magic;
	Charm enchantment;
public:
    Item();
    ~Item();
    inline unsigned short int getType(){return this->type;}
    inline unsigned short int getRarity(){return this->rarity;}
    inline unsigned int getValueSell(){return this->valueSell;}
    inline unsigned int getValueBuy(){return this->valueBuy;}
    inline bool getMagic(){return this->magic;}
	inline Charm& getEnchantment(){return this->enchantment;}
	inline void setType(unsigned short int i){this->type=i;}
    inline void setRarity(unsigned short int i){this->rarity=i;}
    inline void setValueSell(unsigned int i){this->valueSell=i;}
    inline void setValueBuy(unsigned int i){this->valueBuy=i;}
	inline void setMagic(bool b){magic=b;}

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
	std::vector<Effect> effects;
public:
    Potion();
    virtual ~Potion();
	inline std::vector<Effect>& getEffects(){return this->effects;}

    Potion* Clone()const;
};

#endif
