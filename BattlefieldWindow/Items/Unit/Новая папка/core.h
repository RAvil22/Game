#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>


#define TRICK_PASSIVE false
#define TRICK_ACTIVE true

class SpecialTrick;
class Character;
class Department;

class SpecialTrick
{
public:
    SpecialTrick(bool passiveTrick, unsigned int numberOfUses);
    virtual bool makeSpecialTrick(void) = 0;

    virtual ~SpecialTrick();
protected:
    const bool POA_Trick_; //Passive Or Active Trick
    unsigned int numOfUsesLeft;
    bool condition; //Для активного трюка всегда ложно. Для пассивного трюка - активен после включения
};

class Department
{
public:
    Department(std::string name, SpecialTrick* depSpecTrick);
    bool makeSpecialTrick(SpecialTrick* depSpecTrick);
    bool isSpecTrickPassive(void);
protected:
    const bool passiveSpecTrick_;
    std::string name_;
    SpecialTrick* depSpecTrick_;
    std::vector<Character*> characters_;
};

class Character
{
public:
    Character(std::string name, Department* department, SpecialTrick* charSpecialTrick);
    ~Character();
    bool move(unsigned int distance);
    bool attack(Character* opponent);
    bool mock(Character* oppponent);
    bool makeSpecialTrick(SpecialTrick* specTrick);
protected:
    bool down_;
    unsigned char strength_;
    unsigned char dextrerity_;
    unsigned char reaction_;
    unsigned int rage_;
    int morale_;
    Department* department_;
    std::vector<SpecialTrick*> specialTricks_;
};

#endif // CORE_H
