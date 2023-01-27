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
        this->name="NONE";
        this->description="NONE";
    }
    inline std::string getName(){return this->name;}
    inline std::string getDescription(){return this->description;}
    inline void setName(std::string s){this->name=s;}
    inline void setDescription(std::string s){this->description=s;}
};
//////////COUNTER//////////
struct Counter
{
    float _max;
    float _current;
};
//////////LEVEL//////////
class Level
{
private:
    unsigned int _level;
    unsigned int _expNext;
    unsigned int _expCurrent;
public:
    inline Level()
    {
        _level=0;
        _expNext=0;
        _expCurrent=0;
    }
    inline unsigned int getLevel(){return this->_level;}
    inline unsigned int getExpNext(){return this->_expNext;}
    inline unsigned int getExpCurrent(){return this->_expCurrent;}
    inline void setLevel(unsigned int i){this->_level=i;}
    inline void setExpNext(unsigned int i){this->_expNext=i;}
    inline void setExpCurrent(unsigned int i){this->_expCurrent=i;}
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
    Effect();
    ~Effect();
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
        this->D[0]=0;//FACES
        this->D[1]=0;//ROLLS
        this->D[2]=0;//MOD
    }
    ~Dice();
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
