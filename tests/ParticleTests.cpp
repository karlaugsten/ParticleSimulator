//
//  ParticleTests.cpp
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "ParticleCalculator.h"
#include "ParticleGenerator.h"

int main()
{
    printf("NOW RUNNING PERFORMANCE TESTS\n");
    runPerformanceTest(10000, 10);
    
    
}

void runPerformanceTest(int numParticles, int numVortex)
{
    ParticleGenerator* generator = new ParticleGenerator();
    ParticleCalculator* calculator = new ParticleCalculator();
    
    // Generate and load particles into the calculator
    calculator->loadParticles(generator->generate(numParticles/2.0, numParticles/2.0, 0.0, 0.0, 300.0, 300.0, 0.0, 0.0, 10.0, 10.0));
    
    // move a bunch of times
    for(int i = 0; i < 10000; i++)
    {
        calculator->move();
    }
    
}
