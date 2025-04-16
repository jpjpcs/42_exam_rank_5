#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::TargetGenerator(TargetGenerator const &other)
{
    *this = other;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other)
{
    if (this == &other)
        return(*this);
    return(*this);
}

TargetGenerator::~TargetGenerator()
{
    std::map <std::string, ATarget *> :: iterator it;
    for (it = targets.begin(); it != targets.end(); ++it)
    {
        delete it->second;
    }
    targets.clear();
}

void TargetGenerator::learnTargetType (ATarget *target)
{
    if (target)
        if (!targets.count(target->getType()))
            targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
    if (targets.count(target))
    {
        delete targets[target];
        targets.erase(target);
    }
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
    if(targets.count(target))
        return(targets[target]->clone());
    return(NULL);
}
