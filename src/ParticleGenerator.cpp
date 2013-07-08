//
//  ParticleGenerator.cpp
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "ParticleGenerator.h"
#include <stdlib.h>

/** 
* A generic constructor. Creates an empty generator.
*/
ParticleGenerator::ParticleGenerator() 
{
    /* initialize random seed: */
    srand (time(NULL));
}

/** 
* This will generate an array of particles according to the input specifications.
* @param numParticles The number of particles with charge 1 to create.
* @param numAntiParticles The number of particles with charge -1 to create.
* @param minPositionX The minimum x position a particle will be placed at.
* @param minPositionY The minimum y position a particle will be placed at.
* @param maxPositionX The maximum x position a particle will be placed at.
* @param maxPositionY The maximum y position a particle will be placed at.
* @param minVelocityX The minimum x velocity a particle will be given.
* @param minVelocityY The minimum y velocity a particle will be given.
* @param maxVelocityX The maximum x velocity a particle will be given.
* @param maxVelocityY The maximum y velocity a particle will be given.
* @return a pointer to an array of the generated particles.
*/
Particle** ParticleGenerator::generate(int numParticles,
                    int numAntiParticles,
                    float minPositionX,
                    float minPositionY,
                    float maxPositionX,
                    float maxPositionY,
                    float minVelocityX,
                    float minVelocityY,
                    float maxVelocityX,
                    float maxVelocityY)
{
    // Allocate the particles
    Particle** newParticles = new Particle*[numParticles+numAntiParticles];
    
    float posX, posY, velX, velY;
    
    for(int index = 0; index < numParticles; index++)
    {
        posX = (rand()/float(RAND_MAX))*(maxPositionX - minPositionX) + minPositionX;
        posY = (rand()/float(RAND_MAX))*(maxPositionY - minPositionY) + minPositionY;
        velX = (rand()/float(RAND_MAX))*(maxVelocityX - minVelocityX) + minVelocityX;
        velY = (rand()/float(RAND_MAX))*(maxVelocityY - minVelocityY) + minVelocityY;
        newParticles[index] = new Particle(1, posX, posY, velX, velY);   
    }
    
    // Generate antiparticles
    for(int index = numParticles; index < numParticles + numAntiParticles; index++)
    {
        posX = (rand()/float(RAND_MAX))*(maxPositionX - minPositionX) + minPositionX;
        posY = (rand()/float(RAND_MAX))*(maxPositionY - minPositionY) + minPositionY;
        velX = (rand()/float(RAND_MAX))*(maxVelocityX - minVelocityX) + minVelocityX;
        velY = (rand()/float(RAND_MAX))*(maxVelocityY - minVelocityY) + minVelocityY;
        newParticles[index] = new Particle(-1, posX, posY, velX, velY);   
    }
    return newParticles;
}
