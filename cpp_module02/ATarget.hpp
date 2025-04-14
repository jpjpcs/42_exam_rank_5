#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string type;

	public:
		ATarget();
		ATarget(ATarget const &other);
		ATarget(std::string const &type);
		ATarget &operator=(ATarget const &other);
		virtual ~ATarget();

		std::string const getType() const;
		virtual ATarget	*clone() const = 0;
		void	getHitBySpell(ASpell const &spell) const;
};
