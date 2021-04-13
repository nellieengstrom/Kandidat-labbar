//
//  uniform.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#include "uniform.hpp"
//#include

std::vector<Particle> Uniform::createParticles(float numberOfSpawnDirections, float inAngle){
    float nOfSpawnDirections = numberOfSpawnDirections;
    std::vector<Particle> createdParticles;
    float radius = 3.0f; //Ev flytta ut, så att access finns utifrån
    float mass = 0.05f;
    
    float m = 0.3f; //storleken på starthasigheten
    float x,y;
    
    //for(int i = 0; i < numberOfParticles; i++){
        theta = (float)(theta + 2.0f*M_PI/nOfSpawnDirections);
        x = m*cos(theta);
        y = m*sin(theta);
        //Skapa en partikel
        Particle newParticle = Particle(position, radius, color, mass, {x,y});
        
        //Lägga till partikel till createdParticles
        createdParticles.push_back(newParticle); //bäst att använda push_back eller back_inserter?
        
    //}
    
    return createdParticles;
};
