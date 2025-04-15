#pragma once

#include<string>
#include<iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map <std::string, ATarget *> targets;
        
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);

    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType (ATarget *target);
        void forgetTargetType(std::string const &target);
        ATarget* createTarget(std::string const &target);
};