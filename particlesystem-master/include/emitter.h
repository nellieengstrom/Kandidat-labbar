//
//  emitter.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-14.
//

#ifndef emitter_h
#define emitter_h
#define _USE_MATH_DEFINES

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include "particle.h"
#include <vector>
#include <string>
#include <cmath>

#include <stdio.h>

class Emitter {
public:
    Emitter(vec2 inPosition, float inSize, Color inColor);

    virtual std::vector<Particle> createParticles(float numberOfSpawnDirections, float inAngle) = 0;
    rendering::EmitterInfo toEmitterInfo();
    
protected:
    vec2 position;
    Color color;
    
private:
    float size;
};

#endif /* emitter_h */
