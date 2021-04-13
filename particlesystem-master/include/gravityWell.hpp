//
//  gravityWell.hpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#ifndef gravityWell_hpp
#define gravityWell_hpp

#include <stdio.h>
#include "force.h"

class GravityWell: public Force {
    public:
        GravityWell(vec2 inPosition, float inSize, Color inColor);
        vec2 computeForce(vec2 particlePosition);
    private:
};

#endif /* gravityWell_hpp */
