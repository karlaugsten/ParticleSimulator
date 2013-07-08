//
//  Vortex.cpp
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "Vortex.h"

/*
* Constructor with some basic default values
*/
Vortex::Vortex()
{
    forceType = 3;
    strength = 300;   
}

/*
* Constructor specifying custom values
*/
Vortex::Vortex(float startx, float starty, int startStrength, float startType)
{
    forceType = startType;
    strength = startStrength;
    position.x = startx;
    position.y = starty;
}

/*
* Will return an integer specifying which type of force this vortex has.
* 1 is a directional force
* 2 is a linear force
* 3 is a quadratic force
*/
int Vortex::getType()
{
    return forceType;   
}

/*
* returns: A float representing the strength of this vortex
*/
float Vortex::getStrength()
{
    return strength;   
}

/*
* returns: Vortex position
*/ 
Coordinate Vortex::getPosition()
{
    return position;   
}
