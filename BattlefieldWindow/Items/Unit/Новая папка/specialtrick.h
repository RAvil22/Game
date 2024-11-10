#ifndef SPECIALTRICK_H
#define SPECIALTRICK_H

#include "core.h"

class SHF_SpecialTrick : public SpecialTrick {
public:
    SHF_SpecialTrick(bool poa, unsigned int numberOfUses);
    virtual bool makeSpecialTrick(void);
    ~SHF_SpecialTrick();
};

class SPD_SpecialTrick : public SpecialTrick{
public:
    SPD_SpecialTrick(bool poa, unsigned int numberOfUses);
    virtual bool makeSpecialTrick(void);
    ~SPD_SpecialTrick();
};

class somedep_SpecialTrick : public SpecialTrick{
public:
    somedep_SpecialTrick(bool poa, unsigned int numberOfUses);
    virtual bool makeSpecialTrick(void);
    ~somedep_SpecialTrick();
};

class tradeDep_SpecialTrick : public SpecialTrick{
public:
    tradeDep_SpecialTrick(bool poa, unsigned int numberOfUses);
    virtual bool makeSpecialTrick(void);
    ~tradeDep_SpecialTrick();
};



#endif // SPECIALTRICK_H
