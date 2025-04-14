#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

TargetGenerator::TargetGenerator(TargetGenerator const &other)
{
	*this = other;
}
TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *> :: iterator it;
	for(it = targets.begin(); it != targets.end(); ++it)
	{
		delete it->second;
	}
	targets.clear();
}
void	TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		if (targets.find(target->getType()) == targets.end())
			targets[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	if (targets.find(target) != targets.end())
	{
		delete targets[target];
		targets.erase(target);
	}
}

ATarget	*TargetGenerator::createTarget(std::string const &target)
{
	if (targets.find(target) != targets.end())
		return (targets[target]->clone());
	return (NULL);
}
