//
//  force.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-14.
//

#ifndef force_h
#define force_h

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include <vector>
#include <string>
#include <cmath>

#include <stdio.h>

class Force {
public:
    Force(vec2 inPosition, float inSize, Color inColor);
    virtual ~Force() = default;

    //void changeForceType(std::string type);
    rendering::ForceInfo toForceInfo();
    virtual vec2 computeForce(vec2 particlePosition) = 0;
protected:
    vec2 position;
private:
    float size;
    Color color;
};

#endif /* force_h */
