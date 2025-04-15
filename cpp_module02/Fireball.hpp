#pragma once

#include<string>
#include<iostream>
#include "ATarget.hpp"

class ATarget;

class Fireball : public ASpell
{
    public:
        Fireball();
        virtual ~Fireball();
        virtual Fireball *clone() const;
};
