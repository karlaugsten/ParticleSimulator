//
//  Vortex.h
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#ifndef __ParticleTest__Vortex__
#define __ParticleTest__Vortex__

#include <iostream>
#include "VortexState.h"
#import "Common.h"

class Vortex {
    // TODO: encapsulate these elements into a state class
    int forceType;
    float strength;
    Coordinate position;
public:
    Vortex(void);
    Vortex(float, float, int, float);
    int getType(void);
    float getStrength(void);
    Coordinate getPosition(void);
};

#endif /* defined(__ParticleTest__Vortex__) */
