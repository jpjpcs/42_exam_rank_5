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
	targets.clear();
}
void	TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		if (targets.find(target->getType()) == targets.end())
			targets[target->getType()] = target;
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	if (targets.find(target) != targets.end())
		targets.erase(target);
}

ATarget	*TargetGenerator::createTarget(std::string const &target)
{
	if (targets.find(target) != targets.end())
		return (targets[target]);
	return (NULL);
}
