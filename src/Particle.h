//
//  Particle.h
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#ifndef __ParticleTest__Particle__
#define __ParticleTest__Particle__

#include <iostream>
#include "Common.h"


class Particle
{
    Coordinate position;
    Coordinate velocity;
    int charge;
    
public:
    Particle();
    Particle(int, float, float, float, float);
    
    Coordinate getPosition(void);
    Coordinate getVelocity(void);
    void setPosition(Coordinate);
    void setVelocity(Coordinate);
    int getCharge(void);
    
};

#endif /* defined(__ParticleTest__Vortex__) */
