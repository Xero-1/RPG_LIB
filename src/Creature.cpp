#include "Creature.h"

Creature::Creature(): Entity(), Level()
{
    this->AC=0;
    Armor a;
    for(int i=0;i<FOOT;i++)
    {
        a.setPartCover(i+1);
        _armorSet[i]=a;
    }
}
Creature::~Creature()
{}
//////////EQUIPMENT//////////
void Creature::setArmorPiece(Armor a)
{
    this->AC-=_armorSet[a.getPartCover()-1].getDefence();//Deacrease defence of previous piece
    this->_armorSet[a.getPartCover()-1]=a;//Set piece
    this->AC+=_armorSet[a.getPartCover()-1].getDefence();//Add defence of new piece
}
void Creature::equipItem(Item& item)
{
    if(item.getType()==WEAPON)
    {
        Weapon* w=dynamic_cast<Weapon*>(item.Clone());
        this->_weapon=*w;
        delete w;
    }else if(item.getType()==ARMOR)
    {
        Armor *a=dynamic_cast<Armor*>(item.Clone());
        setArmorPiece(*a);
        delete a;
    }
}
void Creature::equipItemFromInv(unsigned int index)
{
    equipItem(inv[index]);
    inv.removeItem(index);
}
void Creature::useItem(Item& item)
{
    if(item.getType()==POTION)
    {
        Potion *p=dynamic_cast<Potion*>(item.Clone());
        p->causeEffects(state);
        delete p;
    }
}
void Creature::useItemFromInv(unsigned int index)
{
    useItem(inv[index]);
    inv.removeItem(index);
}
//////////GAME LOOP//////////
void Creature::update()
{
    updateState();
}
void Creature::updateState()
{
    for(int i=0;i<PARALYZED;i++)
    {
        if(state[i].getType()!=NORMAL || state[i].getTime()<=0)
            state[i].setType(NORMAL);
        else
            state[i].setTime(state[i].getTime()-1);
    }
}
