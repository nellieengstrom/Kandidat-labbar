//
//  gravityWell.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#include "gravityWell.hpp"

GravityWell::GravityWell(vec2 inPosition, float inSize, Color inColor): Force(inPosition, inSize, inColor){};

vec2 GravityWell::computeForce(vec2 particlePosition){
 
    vec2 dist = position-particlePosition;
    //vec2 dist = particlePosition-position; //Blir repeller istället
    
    //Beräkna rikting m.h.a. normalized()
    vec2 norm = dist.normalized();
    //float particleAngle = atan(dist.x/dist.y); //Använd hellre vektorer genomgående
    
    //Beräkna windPower(styrkan på gravitationen)
    float C = 1.0f; //gravitationskonstant, värdet kan sättas fritt
    float gravityMagnitude = C/(dist.length()*dist.length()); //double kan ha 15 decimaler, float kan ha 7 decimaler
    
    //vec2 force = {gravityMagnitude*cos(particleAngle), gravityMagnitude*sin(particleAngle)};
    vec2 force = norm*gravityMagnitude;
    
    return force;
}
