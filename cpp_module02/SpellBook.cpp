#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook &SpellBook::operator=(SpellBook const &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

SpellBook::SpellBook(SpellBook const &other)
{
	*this = other;
}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *> :: iterator it;
	for (it = spells.begin(); it != spells.end(); ++it)
	{
		delete it->second;
	}
	spells.clear();
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		if (!spells.count(spell->getName()))
			spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &spell)
{
	if (spells.count(spell))
	{
		delete spells[spell]; 
		spells.erase(spell); 
	}
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	if (spells.count(spell))
		return (spells[spell]->clone());
	return (NULL);
}
/*

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell;
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell->clone();
}
			
void	SpellBook::forgetSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		spells.erase(spell);
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
	{
		delete speels[spells];
		spells.erase(spell);
	}
}

ASpell	*SpellBook::createSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		return (spells[spell]);
	return (NULL);
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	if (spells.find(spell) != spells.end())
		return (spells[spell]->clone());
	return (NULL);
}
*/
