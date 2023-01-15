#include "Basics.h"

//////////STATE//////////
State::State()
{
    this->type=NORMAL;
    this->time=0;
}
State::~State(){}
void State::changeState(State& obj)
{
    obj.setType(type);
    obj.setTime(time);
}
//////////DICE//////////
Dice::~Dice(){}
unsigned int Dice::Roll()
{
    return diceRoll(D[0],D[1],D[2]);
}
std::string Dice::getDescription()
{
    std::string s;
    s="<"+std::to_string(D[1])+"D"+std::to_string(D[0]);
    s+=D[2]>=0?" +":" ";
    s+=std::to_string(D[2])+">";
    return s;
}
//////////FUNCTIONS//////////
unsigned int diceRoll(const int faces,const int rolls,const int mod)
{
    int result=mod;
    for(int i=0;i<rolls;i++)
        result+=rand()%faces+1;
    if(result<0)
        result=0;
    return result;
}
bool diceCheck(const int check,const int faces,const int mod)
{
    if(diceRoll(faces,1,mod)>=check)
        return true;
    else
        return false;
}
void causeAlteredStates(unsigned short int nrEffects,State* effects,State* obj)
{
    for(int i=0;i<nrEffects;i++)
    {
        if(obj[i].getType()==NORMAL)
            effects[i].changeState(obj[i]);
        else if(obj[i].getType()==effects[i].getType())
            obj[i].setTime(obj[i].getTime()+(effects[i].getTime()/2));
    }
}
