#include "Basics.h"

//////////STATE//////////
Effect::Effect()
{
    this->type=NORMAL;
    this->time=0;
}
Effect::~Effect(){}
void addEffect(std::vector<Effect>& obj,Effect newEffect)
{
	bool b=false;
	unsigned int size=obj.size();
	for(int i=0;i<size;i++)
		if(obj[i].getType()==newEffect.getType())
		{
			obj[i].setTime(obj[i].getTime()+newEffect.getTime()/2);
			b=true;
			i=size;
		}
	if(!b)
		obj.push_back(newEffect);
}
void deleteEffect(std::vector<Effect>& obj,unsigned int index)
{
	obj.erase(obj.begin()+index);
}
void alteredState(std::vector<Effect>& obj,std::vector<Effect> effects)
{
	unsigned int effectsCount=effects.size();
	for(int i=0;i<effectsCount;i++)
	{
		addEffect(obj,effects[i]);
	}
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
void rollDamage(Counter& objHP,Dice dAttack)
{
	objHP._current-=dAttack.Roll();
}
