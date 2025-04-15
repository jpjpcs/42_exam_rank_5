#pragma once

#include<string>
#include<iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
    private:
        std::map <std::string, ASpell *> spells;
        
        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);

    public:
        SpellBook();
        ~SpellBook();
        void learnSpell (ASpell *spell);
        void forgetSpell(std::string const &spell);
        ASpell* createSpell(std::string const &spell);
};