#pragma once

#include<string>
#include<iostream>
#include "ATarget.hpp"

class ATarget;

class Polymorph : public ASpell
{
    public:
        Polymorph();
        virtual ~Polymorph();
        virtual Polymorph *clone() const;
};
