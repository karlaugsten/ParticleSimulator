//
//  ParticleTests.cpp
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "ParticleCalculator.h"
#include "ParticleGenerator.h"
#include "Vortex.h"
#include <iostream>
#include <time.h>

void runPerformanceTest(int numParticles, int numVortex)
{
    ParticleGenerator* generator = new ParticleGenerator();
    ParticleCalculator* calculator = new ParticleCalculator();
    
    // Generate and load particles into the calculator
    calculator->loadParticles(generator->generate(numParticles/2.0, numParticles/2.0, 0.0, 0.0, 300.0, 300.0, 0.0, 0.0, 10.0, 10.0), numParticles);
    
    // Add in vortices
    for(int i = 0; i < numVortex; i++)
    {
        calculator->addVortex(new Vortex(100.0, 100.0, 100, 3));
    }
    
    // time operation
    clock_t start, finish;
    start = clock();
    // move a bunch of times
    for(int i = 0; i < 60; i++)
    {
        calculator->move();
    }
    finish = clock();
    float elapsed = (double(finish-start)/CLOCKS_PER_SEC);
    printf("Tests took: %f time to run\n",elapsed);
    
}

int main()
{
    printf("NOW RUNNING PERFORMANCE TESTS\n");
    runPerformanceTest(10000, 10);
    
    
}


