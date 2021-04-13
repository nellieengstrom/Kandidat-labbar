//
//  wind.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#ifndef wind_hpp
#define wind_hpp

#include <stdio.h>
#include "force.h"
#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include <vector>
#include <string>

class Wind: public Force {
    public:
        Wind(vec2 inPosition, float inSize, Color inColor, float inAngle);
        vec2 computeForce(vec2 particlePosition);
        //void changeAngle(float newAngle);
    private:
    float angle;
    float windPower;
};

#endif /* wind_hpp */
