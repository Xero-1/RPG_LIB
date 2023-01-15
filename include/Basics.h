#ifndef BASICS_H
#define BASICS_H

#include <cstdlib>
#include <string>

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
class Counter
{
private:
    float _Max;
    float _Current;
public:
    inline Counter()
    {
        this->_Max=0;
        this->_Current=0;
    }
    inline float Max(){return this->_Max;}
    inline float Current(){return this->_Current;}
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
    NORMAL=1,
    HEALING,
    POISONED,
    BURNING,
    STUNNED,
    PARALYZED
} States_Types;
class State
{
private:
    unsigned short int type;
    unsigned int time;
public:
    State();
    ~State();
    inline unsigned short int getType(){return this->type;}
    inline unsigned int getTime(){return this->time;}
    inline void setType(unsigned short int i){this->type=i;}
    inline void setTime(unsigned int i){this->time=i;}
    void changeState(State& obj);
};
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
void causeAlteredStates(unsigned short int nrEffects,State* effects,State* obj);

#endif
