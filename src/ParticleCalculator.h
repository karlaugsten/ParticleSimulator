//
//  ParticleCalculator.h
//  ParticleTest
//
//  ParticleCalculator is a class to calculate the movement
//  And position of particles based on vortices.
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//


#include <list>

#include "Vortex.h"
#include "Particle.h"

class ParticleCalculator {
    /* Array of particles we will allocate */
    Particle** particles;
    float timeStep;
    // Should this be a list?
    std::list<Vortex*> vortices;
    int numParticles;
    
public:
    ParticleCalculator();
    void move(void);
    void setStepValue(float);
    void loadParticles(Particle**, int);
    void addVortex(Vortex*);
    Particle** getParticles(void);
    std::list<Vortex*> getVortices(void);
};
