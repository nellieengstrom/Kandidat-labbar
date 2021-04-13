//
//  directional.cpp
//  ParticleSystem
//
//  Created by Jenny Rudemo on 2021-02-23.
//

#include "directional.hpp"

std::vector<Particle> Directional::createParticles(float numberOfSpawnDirections, float inAngle){
    std::vector<Particle> createdParticles;
    float radius = 3.0f; //Ev flytta ut, så att access finns utifrån
    float mass = 0.15f;
    angle = inAngle;
    
    //float theta = M_PI/4; //Vinkel som partiklarna skickas ut med
    float magnitude = 10.0f; //Starthastighet? Eller något annat?
    float x,y;
    x = magnitude*cos(angle);
    y = magnitude*sin(angle);
    //Skapa en partikel
    Particle newParticle = Particle(position, radius, color, mass, {x,y});
    
    //Lägga till partikel till createdParticles
    createdParticles.push_back(newParticle); //bäst att använda push_back eller back_inserter?
    
    return createdParticles;
};
