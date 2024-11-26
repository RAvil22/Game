#include "character.h"

using namespace unitCharacter;

Character::Character(CharacterProperties properties)
{
    this->name_ = properties.name;
    this->surname_ = properties.surname;
    this->department_ = properties.department;
    this->specialTrick_= properties.charSpecialTrick;
    this->specialTricksLeft_= properties.specialTrickUses;
    this->strength_ = properties.strength;
    this->dextrerity_ = properties.dextrerity;
    this->reaction_ = properties.reaction;
    this->rage_ = properties.initialRage;
    this->health_ = properties.initialHealth;
    this->tiredness_ = properties.initialTiredness;
    this->morale_ = properties.initialMorale;
}

Character::~Character()
{

}

bool Character::move(unsigned int distance)
{
    auto tire{countTiredness(ACTION_MOVE, distance)};
    if(tire < -0.01)return false;
    this->tiredness_ = tire;
    return true;
}

bool Character::attack(void)
{
    auto tire{countTiredness(ACTION_MOVE, 0)};
    if(tire < -0.01)return false;
    this->tiredness_ = tire;
    return true;
}

bool Character::defend(void)
{
    auto tire{countTiredness(ACTION_DEFEND, 0)};
    if(tire < -0.01)return false;
    this->tiredness_ = tire;
    return true;
}

bool Character::mock()
{
    if(this->morale_ > 25)return true;
    else return false;
}

void Character::rest(void)
{
    if(this->tiredness_ < 0.01 && health_ < 100)health_ += 1;
    countTiredness(ACTION_REST, 0);
    countMorale();
}

bool Character::makeSpecialTrick()
{
    if(!specialTricksLeft_)return false;
    return specialTricksLeft_--;
}

float Character::countTiredness(Action action, unsigned int parameter)
{
    switch (action) {
    case ACTION_MOVE:
        if((parameter*0.025 + this->tiredness_)*(1 + float(this->rage_)/100) > 100)return -1;
        return (parameter*0.025 + this->tiredness_)*(1 + float(this->rage_)/100);
    case ACTION_ATTACK:
    case ACTION_DEFEND:
        if((tiredness_ + 1)*(1 + float(this->rage_)/100) > 100)return -1;
        return (tiredness_ + 1)*(1 + float(this->rage_)/100);
    case ACTION_MOCK:
        return this->tiredness_;
    case ACTION_SPECIALTRICK:
        return this->tiredness_;
    case ACTION_REST:
        if(tiredness_ - 2 < 0)return 0;
        return tiredness_ - 2;
    default:
        return -1;
    }
    return -1;
}

bool Character::countMorale(void)
{
    this->morale_ = 100*(this->health_/100)*(1 - this->tiredness_/100);
    return true;
}
