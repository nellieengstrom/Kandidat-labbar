//
//  wind.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#include "wind.hpp"


Wind::Wind(vec2 inPosition, float inSize, Color inColor, float inAngle): Force(inPosition, inSize, inColor){
    angle = inAngle;
    windPower = 0.01f; //Maximal vindstyrka, i Newton
};

vec2 Wind::computeForce(vec2 particlePosition){
    float windMagnitude = 0.0f;
    
    //Kolla om partikeln är inom vinkel
    vec2 dist = particlePosition-position;
    float particleAngle = atan(dist.x/dist.y);
    if(abs(particleAngle-angle) <= 0.7f){
        //Beräkna vindstyrka med hjälp av avståndet till partikeln
        windMagnitude = -1*windPower/(sqrtf(dist.x*dist.x + dist.y*dist.y));
    };
    
    //Gör om till x- och y-komponenter med hjälp av vinkeln (till partikeln) och vindstyrkan
    vec2 force = {windMagnitude*cos(particleAngle), windMagnitude*sin(particleAngle)};
    
    return force;
}

/*void Wind::changeAngle(float newAngle) {
    angle = newAngle;
}*/
