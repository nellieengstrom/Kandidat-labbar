//
//  uniform.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#ifndef uniform_hpp
#define uniform_hpp

#include <stdio.h>
#include "emitter.h"

class Uniform: public Emitter{
public:
    Uniform(vec2 inPosition, float inSize, Color inColor): Emitter(inPosition, inSize, inColor){};
    std::vector<Particle> createParticles(float numberOfSpawnDirections, float inAngle);
    
private:
    float theta = 0.0f;
};

#endif /* uniform_hpp */
