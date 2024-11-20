// #ifndef SPECIALTRICK_H
// #define SPECIALTRICK_H

// #include <string>
// #include <vector>


// #define TRICK_PASSIVE false
// #define TRICK_ACTIVE true

// class SpecialTrick;
// class Character;
// class Department;

// class SpecialTrick
// {
// public:
//     SpecialTrick(bool passiveTrick, unsigned int numberOfUses);
//     virtual bool makeSpecialTrick(void) = 0;

//     virtual ~SpecialTrick();
// protected:
//     const bool POA_Trick_; //Passive Or Active Trick
//     unsigned int numOfUsesLeft;
//     bool condition; //Для активного трюка всегда ложно. Для пассивного трюка - активен после включения
// };

// class SHF_SpecialTrick : public SpecialTrick {
// public:
//     SHF_SpecialTrick(bool poa, unsigned int numberOfUses);
//     virtual bool makeSpecialTrick(void);
//     ~SHF_SpecialTrick();
// };

// class SPD_SpecialTrick : public SpecialTrick{
// public:
//     SPD_SpecialTrick(bool poa, unsigned int numberOfUses);
//     virtual bool makeSpecialTrick(void);
//     ~SPD_SpecialTrick();
// };

// class somedep_SpecialTrick : public SpecialTrick{
// public:
//     somedep_SpecialTrick(bool poa, unsigned int numberOfUses);
//     virtual bool makeSpecialTrick(void);
//     ~somedep_SpecialTrick();
// };

// class tradeDep_SpecialTrick : public SpecialTrick{
// public:
//     tradeDep_SpecialTrick(bool poa, unsigned int numberOfUses);
//     virtual bool makeSpecialTrick(void);
//     ~tradeDep_SpecialTrick();
// };



// #endif // SPECIALTRICK_H
