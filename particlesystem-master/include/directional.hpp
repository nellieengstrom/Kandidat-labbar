//
//  directional.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#ifndef directional_hpp
#define directional_hpp

#include <stdio.h>
#include "emitter.h"

class Directional: public Emitter{
public:
    Directional(vec2 inPosition, float inSize, Color inColor, float inAngle): Emitter(inPosition, inSize, inColor){angle = inAngle;};
    std::vector<Particle> createParticles(float numberOfSpawnDirections, float inAngle);
    
private:
    float angle;
};
#endif /* directional_hpp */
