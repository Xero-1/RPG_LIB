#ifndef BASICS_H
#define BASICS_H

#include <cstdlib>
#include <string>
#include <vector>

//////////ENTITY//////////
class Entity
{
private:
    std::string name;
    std::string description;
public:
    inline Entity()
    {
        name="NONE";
        description="NONE";
    }
    inline std::string getName(){return this->name;}
    inline std::string getDescription(){return this->description;}
    inline void setName(std::string s){this->name=s;}
    inline void setDescription(std::string s){this->description=s;}
};
//////////COUNTER//////////
struct Counter
{
    float MAX;
    float CURRENT;
};
//////////LEVEL//////////
class Level
{
private:
    unsigned int level;
    unsigned int expNext;
    unsigned int expCurrent;
public:
    inline Level()
    {
        level=0;
        expNext=0;
        expCurrent=0;
    }
    inline unsigned int getLevel(){return this->level;}
    inline unsigned int getExpNext(){return this->expNext;}
    inline unsigned int getExpCurrent(){return this->expCurrent;}
    inline void setLevel(unsigned int i){this->level=i;}
    inline void setExpNext(unsigned int i){this->expNext=i;}
    inline void setExpCurrent(unsigned int i){this->expCurrent=i;}
};
//////////STATE//////////
enum
{
    HEALING=0,
    POISONED,
    BURNING,
    STUNNED,
    PARALYZED,
    COUNT_STATES
} Effect_Types;
class Effect
{
private:
    unsigned short int type;
    unsigned int time;
public:
    inline Effect()
	{
		type=0;
		time=0;
	}
    inline unsigned short int getType(){return this->type;}
    inline unsigned int getTime(){return this->time;}
    inline void setType(unsigned short int i){this->type=i;}
    inline void setTime(unsigned int i){this->time=i;}
};
void addEffect(std::vector<Effect>& obj,Effect newEffect);
void deleteEffect(std::vector<Effect>& obj,unsigned int index);
void alteredState(std::vector<Effect>& obj,std::vector<Effect> effects);
//////////DICE//////////
class Dice
{
private:
    int D[3];
public:
    inline Dice()
    {
        D[0]=0;//FACES
        D[1]=0;//ROLLS
        D[2]=0;//MOD
    }
    inline void setValues(unsigned int faces,unsigned rolls,int mod)
    {
        this->D[0]=faces;
        this->D[1]=rolls;
        this->D[2]=mod;
    }
    unsigned int Roll();
    std::string getDescription();
};
//////////FUNCTIONS//////////
unsigned int diceRoll(const int faces,const int rolls,const int mod=0);
bool diceCheck(const int check,const int faces,const int mod=0);
void rollDamage(Counter& objHP,Dice dAttack);

#endif
