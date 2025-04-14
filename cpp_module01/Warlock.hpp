#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell *> spells;

		Warlock();
		Warlock &operator=(Warlock const &other);
		Warlock(Warlock const &other);

	public:
		Warlock(std::string const name, std::string const title);
		~Warlock();
		std::string const getName() const;
		std::string const getTitle() const;
		void	setTitle(std::string const &title);
		void	introduce() const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spell);
		void	launchSpell(std::string const &spell, ATarget &target);
};
