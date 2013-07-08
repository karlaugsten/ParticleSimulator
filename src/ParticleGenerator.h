//
//  ParticleGenerator.h
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "Particle.h"

/**
* A class to generate particles. 
* This class will be usedfor the generation of particles.
* You can tell it to generate a certain amount of particles/antiparticles
* with a given range of position and velocity values.
*/
class ParticleGenerator {
    
public:
    ParticleGenerator();
    Particle** generate(int, int, float, float, float, float, float, float, float, float);
    
};
