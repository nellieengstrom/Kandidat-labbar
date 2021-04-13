//
//  particle.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-14.
//

#ifndef particle_h
#define particle_h

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include <vector>

#include <stdio.h>

class Particle {
public:
    Particle(vec2 inPosition, float inRadius, Color inColor, float inMass, vec2 inVelocity);

    float lifetime;
    vec2 position;
    
    void updateSingleParticle(float dt, vec2 inputForce);
    float getLifeTime();
    rendering::ParticleInfo toParticleInfo();
    vec2 getPosition();
    
private:
    
    float radius;
    Color color;
    float mass;
    vec2 velocity;
};


#endif /* particle_h */

