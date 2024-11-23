/*
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
    Character(std::string name, std::string surname,  std::string department, std::string charSpecialTrick, std::string SpecialTrickUses);
    ~Character();
    bool move(unsigned int distance);
    bool attack(void);
    bool mock(void);
    bool makeSpecialTrick(void);
protected:
    bool down_;
    unsigned char strength_;
    unsigned char dextrerity_;
    unsigned char reaction_;
    unsigned int rage_;
    int morale_;
    std::string department_;
    std::string specialTrick_;
    std::string speialTricksLeft_;
};

#endif // CHARACTER_H
*/
