#include "character.h"

Character::Character(std::string name, Department* department, SpecialTrick* charSpecialTrick)
{

}

bool Character::makeSpecialTrick(SpecialTrick* charSpecialTrick){
    if(!charSpecialTrick)return false;

    return true;
}

Department::Department(std::string name, SpecialTrick* depSpecTrick) : name_{name}, depSpecTrick_{depSpecTrick},
    passiveSpecTrick_{(depSpecTrick == nullptr) ? true : false}{}


bool Department::makeSpecialTrick(SpecialTrick* depSpecTrick){
    if(!depSpecTrick_)return false;

    return true;
}
