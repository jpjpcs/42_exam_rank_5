#pragma once

#include<string>
#include<iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private: 
        std::string name;
        std::string title;
        std::map <std::string, ASpell *> spells;
        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);

    public:
        Warlock (std::string name, std::string title);
        ~Warlock();
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle (std::string const &title);
        void introduce() const;

        void learnSpell (ASpell *spell);
        void forgetSpell(std::string const &spell);
        void launchSpell(std::string const &spell, ATarget &target);
};
