#pragma once

#include<string>
#include<iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private: 
        std::string type;

    public:
        ATarget();
        ATarget(ATarget const &other);
        ATarget &operator=(ATarget const &other);
        ATarget (std::string type);
        virtual ~ATarget();
        std::string const &getType() const;
        virtual ATarget *clone() const = 0;

        void getHitBySpell (ASpell const &spell) const;
};
