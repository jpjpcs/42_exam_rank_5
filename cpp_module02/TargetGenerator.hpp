#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *> targets;

		TargetGenerator &operator=(TargetGenerator const &other);
		TargetGenerator(TargetGenerator const &other);

	public:
		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget *target);
		void	forgetTargetType(std::string const &target);
		ATarget	*createTarget(std::string const &target);
};
