//
//  particle.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-14.
//

#include "particle.h"
#include <iostream>

Particle::Particle(vec2 inPosition, float inRadius, Color inColor, float inMass, vec2 inVelocity){
    position = inPosition;
    radius = inRadius;
    color = inColor;
    lifetime = 60.0f;
    mass = inMass;
    velocity = inVelocity;
}

void Particle::updateSingleParticle(float dt, vec2 inputForce){
    vec2 acceleration = inputForce/mass;
    velocity = velocity + acceleration*dt;
    position = position + velocity*dt;
    
    lifetime -= dt;
}

float Particle::getLifeTime(){
    return lifetime;
}

vec2 Particle::getPosition(){
    return position;
}

rendering::ParticleInfo Particle::toParticleInfo(){
    rendering::ParticleInfo particleInfo;
    particleInfo.position = position;
    particleInfo.radius = radius;
    particleInfo.color = color;
    particleInfo.lifetime = lifetime;
    return particleInfo;
};


