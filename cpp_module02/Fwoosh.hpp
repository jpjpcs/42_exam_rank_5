#pragma once

#include<string>
#include<iostream>
#include "ATarget.hpp"

class ATarget;

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        virtual ~Fwoosh();
        virtual Fwoosh *clone() const;
};
