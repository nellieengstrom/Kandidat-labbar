//
//  emitter.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-14.
//

#include "emitter.h"

Emitter::Emitter(vec2 inPosition, float inSize, Color inColor){
    //emitterType = "uniform";
    position = inPosition;
    size = inSize;
    color = inColor;
};

/*void Emitter::changeEmitterType(std::string type) {
    emitterType = type;
};*/

rendering::EmitterInfo Emitter::toEmitterInfo(){
    rendering::EmitterInfo emitterInfo;
    emitterInfo.position = position;
    emitterInfo.size = size;
    emitterInfo.color = color;
    return emitterInfo;
};
