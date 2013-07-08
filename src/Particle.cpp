//
//  Particle.cpp
//  ParticleTest
//
//  Created by Karl Augsten on 13-07-03.
//  Copyright (c) 2013 Karl Augsten. All rights reserved.
//

#include "Particle.h"

/**
* A generic constructor.
*/
Particle::Particle()
{
       
}

/**
* Constructor to set the particles charge
*/
Particle::Particle(int charge, float x, float y, float velx, float vely)
{
    this->charge = charge;
    this->position.x = x;
    this->position.y = y;
    this->velocity.x = velx;
    this->velocity.y = vely;
}

Coordinate Particle::getPosition()
{
    return position;   
}

Coordinate Particle::getVelocity()
{
    return velocity;   
}

void Particle::setPosition(Coordinate newPosition)
{
    this->position = newPosition;   
}

void Particle::setVelocity(Coordinate newVelocity)
{
    this->velocity = newVelocity;   
}

/**
* @return Either 1 or -1 represnting the particles charge.
*/
int Particle::getCharge()
{
    return charge;   
}

