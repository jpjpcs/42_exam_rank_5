#pragma once

#include<string>
#include<iostream>
#include "ATarget.hpp"

class ATarget;

class BrickWall : public ATarget
{
    public:
        BrickWall();
        virtual ~BrickWall();
        virtual BrickWall *clone() const;
};
