#include "particlesystem.h"

#include "Tracy.hpp"
#include <cmath>
#include <random>
#include "uniform.hpp"
#include "directional.hpp"
#include "gravityWell.hpp"
#include "wind.hpp"
#include <iostream>

namespace {
    constexpr float Pi = 3.141592654f;
    const float Tau = 2.f * Pi;
    
} // namespace

ParticleSystem::ParticleSystem() {
    forces = {};
    emitters = {};
    particles = {};
}

void ParticleSystem::update([[maybe_unused]] float dt, float numberOfSpawnDirections, float angle) {
    // @TODO: Update the state of the particle system, move particles forwards, spawn new
    // particles, destroy old particles, and apply effects
    
    //Ta bort döda partiklar
    int it = 0;
    for(Particle p: particles){
        if(p.getLifeTime() <= 0.0f){
            particles.erase(particles.begin()+it);
        }
        else{
            it++;
        }
    }
    
    //Spawn new particles
    for(Emitter* e: emitters){
        //Använda iteratorer för att lägga till med insert
        std::vector<Particle> newParticles = e -> createParticles(numberOfSpawnDirections, angle);
        particles.insert(particles.end(), newParticles.begin(), newParticles.end()); //lägg till de skapade particlarna i particles
    }
    
    //Skapa krafter som vektorer
    //Loopa igenom alla partiklar och beräkna hur den påverkas av systemets forces
    for(Particle& p: particles){
        vec2 sumOfForces = {0.0f, 0.0f};
        for(Force* f: forces){
            sumOfForces += f -> computeForce(p.getPosition());
        }
        p.updateSingleParticle(dt, sumOfForces);

    }
        
}

void ParticleSystem::render() {
    // @TODO: Render the particles, emitters and what not contained within the system
    std::vector<rendering::ParticleInfo> particleInfo;
    std::vector<rendering::EmitterInfo> emitterInfo;
    std::vector<rendering::ForceInfo> forceInfo;
    
    for(Particle& p: particles){
        particleInfo.push_back(p.toParticleInfo());
        
        /*std::cout << "At render time: Position: (" << p.getPosition().x << ", " << p.getPosition().y << ")"
                  << " Lifetime: " << p.getLifeTime() << std::endl;*/
        
    }
    for(Emitter* e: emitters){
        emitterInfo.push_back(e->toEmitterInfo());
    }
    for(Force* f: forces){
        forceInfo.push_back(f->toForceInfo());
    }
    
    rendering::renderParticles(particleInfo);
    rendering::renderEmitters(emitterInfo);
    rendering::renderForces(forceInfo);
    
}

void ParticleSystem::addUniform(vec2 inPosition){
    Color colorEmitter = {0.2f, 1.0f, 0.8f};
    Emitter* newUniform = new Uniform(inPosition, 8.0f, colorEmitter);
    emitters.push_back(newUniform);
}

void ParticleSystem::addDirectional(vec2 inPosition){
    Color colorEmitter = {0.8f, 1.0f, 0.2f};
    Emitter* newDirectional = new Directional(inPosition, 8.0f, colorEmitter, Pi/2);
    emitters.push_back(newDirectional);
}

void ParticleSystem::addGravityWell(vec2 inPosition){
    Color colorForce = {0.2f, 0.5f, 0.9f};
    Force* newGravityWell = new GravityWell(inPosition, 6.0f, colorForce);
    forces.push_back(newGravityWell);
}

void ParticleSystem::addWind(vec2 inPosition){
    Color colorForce = {0.9f, 0.5f, 0.2f};
    Force* newWind = new Wind(inPosition, 6.0f, colorForce, Pi/4);
    forces.push_back(newWind);
}

std::vector<Particle> ParticleSystem::getParticles() {
    return particles;
}


/*void ParticleSystem::removeLatestEmitter(){
    emitters.erase(emitters.end());
}*/
