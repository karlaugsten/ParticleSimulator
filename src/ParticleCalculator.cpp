//
//  ParticleCalculator.cpp
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "ParticleCalculator.h"
#include <cmath>

ParticleCalculator::ParticleCalculator()
{
    // Do initialization in here
    timeStep = 0.3;   
}

/**
* Moves the particles one more time step.
*/
void ParticleCalculator::move()
{
    // Move particles according to their velocity 
    // Possibly use an algorithm/behaviour class to do it
    
    for (int index = 0; index < numParticles; index++)
    {
        Particle * particle = particles[index];
        //adjust velocity of particles due to vortices
        Coordinate position = particle->getPosition();
        Coordinate velocity = particle->getVelocity(); 
        
        // TODO: Could possibly move this loop into the outer loop; Possible performance gain??
        for (std::list<Vortex*>::iterator it = vortices.begin(); it != vortices.end(); ++it)
        {   
            Vortex* vortex = *it;
            double distanceX = position.x - vortex->getPosition().x;
            double distanceY = position.y - vortex->getPosition().y;
            
            double distance = sqrt(distanceX*distanceX + distanceY*distanceY);
            
            // Force is dependent on distance^type where type is 1|2|3
            for (int i = 1; i<vortex->getType()-1; i++)
            {
                distance *= distance;
            }
            velocity.x = velocity.x+(vortex->getStrength()*particle->getCharge()*timeStep*(distanceX/distance));
            velocity.y = velocity.y+(vortex->getStrength()*particle->getCharge()*timeStep*(distanceY/distance));
            
        }
        
        position.x = position.x + velocity.x*timeStep;
        position.y = position.y + velocity.y*timeStep;
        particle->setPosition(position);
        particle->setVelocity(velocity);
    }
}

/**
* Sets the time step value which controls how fast the particles move.
*/
void ParticleCalculator::setStepValue(float newStep)
{
    timeStep = newStep;   
}

/**
* Loads a new array of particles into the particle calculator
*/
void ParticleCalculator::loadParticles(Particle** newParticles, int numParticles)
{
    particles = newParticles;
    this->numParticles = numParticles;
}

/**
* Adds a vortex onto the list of vortices.
*/
void ParticleCalculator::addVortex(Vortex* newVortex)
{
    vortices.push_back(newVortex);
}

/**
* @return A pointer to the array of particles
*/
Particle** ParticleCalculator::getParticles()
{
    return particles;   
}

/**
* @return A pointer to the array of vortices
*/
std::list<Vortex*> ParticleCalculator::getVortices()
{
    return vortices;
}
