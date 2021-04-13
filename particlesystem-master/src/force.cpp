//
//  force.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-14.
//

#include "force.h"

//namespace {
//} // namespace

Force::Force(vec2 inPosition, float inSize, Color inColor){
    position = inPosition;
    size = inSize;
    color = inColor;
}

/*void Force::changeForceType(std::string type) {
    forceType = type;
}*/

rendering::ForceInfo Force::toForceInfo(){
    rendering::ForceInfo forceInfo;
    forceInfo.position = position;
    forceInfo.size = size;
    forceInfo.color = color;
    return forceInfo;
};


