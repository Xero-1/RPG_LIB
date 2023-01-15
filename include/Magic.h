#ifndef MAGIC_H
#define MAGIC_H

#include "Basics.h"

enum
{
    ATTACK=1,
    MEDICAL,
    BUFF,
    DEBUFF
} Magic_Types;
class Spell: public Entity, public Level
{
private:
    unsigned int cost;
    unsigned short int type;
    unsigned short int school;
    unsigned short int nrEffects;
    State effects[PARALYZED];
    Dice dAttack;
public:
    Spell();
    ~Spell();
    inline unsigned int getCost(){return this->cost;}
    inline unsigned short int getType(){return this->type;}
    inline unsigned short int getSchool(){return this->school;}
    inline unsigned short int getNrEffects(){return this->nrEffects;}
    inline void setCost(unsigned int i){this->cost=i;}
    inline void setType(unsigned short int i){this->type=i;}
    inline void setSchool(unsigned short int i){this->school=i;}
    inline void setNrEffects(unsigned short int i){this->nrEffects=i;}
    inline State* getEffects(){return this->effects;}
    inline Dice& getDiceAttack(){return this->dAttack;}
    inline void causeEffects(State* obj){causeAlteredStates(nrEffects,effects,obj);}
};

#endif
