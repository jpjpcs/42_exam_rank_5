#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell *> spells;

		SpellBook &operator=(SpellBook const &other);
		SpellBook(SpellBook const &other);

	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spell);
		ASpell	*createSpell(std::string const &spell);
};
