#include "Warlock.hpp"

Warlock::Warlock(){}

Warlock::Warlock(Warlock const &other)
{
    *this = other;
}

Warlock &Warlock::operator=(Warlock const &other)
{
    this->name = other.getName();
    this->title = other.getTitle();
    return(*this);
}

Warlock::Warlock (std::string name, std::string title) : name(name), title(title)
{
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
    std::map <std::string, ASpell *> :: iterator it;
    for (it = spells.begin(); it != spells.end(); ++it)
    {
        delete it->second;
    }
    spells.clear();
}

std::string const &Warlock::getName() const
{
    return(this->name);
}

std::string const &Warlock::getTitle() const
{
    return(this->title);
}

void Warlock::setTitle (std::string const &title)
{
    this->title =  title;   
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}


void Warlock::learnSpell (ASpell *spell)
{
    if (spell)
        if (!spells.count(spell->getName()))
            spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string const &spell)
{
    if (spells.count(spell))
    {
        delete spells[spell];
        spells.erase(spell);
    }
}
void Warlock::launchSpell(std::string const &spell, ATarget &target)
{
    if (spells.count(spell))
        spells[spell]->launch(target);
}
