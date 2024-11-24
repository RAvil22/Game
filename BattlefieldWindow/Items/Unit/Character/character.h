#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <cstdint>

namespace unitCharacter {
    struct CharacterProperties{
        std::string name;
        std::string surname;
        std::string department;
        std::string charSpecialTrick;
        uint32_t specialTrickUses;
        unsigned int strength;
        unsigned int dextrerity;
        unsigned int reaction;
        float initialRage;
        unsigned int initialHealth;
        float initialMorale;
        float initialTiredness;
    };

    enum Action{ACTION_MOVE, ACTION_ATTACK, ACTION_DEFEND, ACTION_MOCK, ACTION_SPECIALTRICK, ACTION_REST};

    class Character
    {
    public:
        Character(CharacterProperties properties);
        ~Character();
        bool move(unsigned int distance);
        bool attack(void);
        bool defend(void);
        bool mock(void);
        void rest(void);
        bool makeSpecialTrick(void);
        float countTiredness(Action, unsigned int parameter);
    protected:
        bool down_;
        unsigned int strength_;
        unsigned int dextrerity_;
        unsigned int reaction_;
        float rage_;
        unsigned int health_;
        float morale_;
        float tiredness_;
        bool frigthen{false};
        std::string name_;
        std::string surname_;
        std::string department_;
        std::string specialTrick_;
        uint32_t specialTricksLeft_;
    private:
        bool countMorale(void);
    };
}



#endif // CHARACTER_H
