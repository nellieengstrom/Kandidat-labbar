#ifndef __PARTICLESYSTEM_H__
#define __PARTICLESYSTEM_H__

#include "util/color.h"
#include "util/rendering.h"
#include "util/vec2.h"
#include "force.h"
#include "emitter.h"
#include "particle.h"
#include <vector>

class ParticleSystem {
public:
    ParticleSystem();

    void update(float dt, float numberOfSpawnDirections, float angle);
    void render();
    void addUniform(vec2 inPosition);
    void addDirectional(vec2 inPosition);
    void addGravityWell(vec2 inPosition);
    void addWind(vec2 inPosition);
    std::vector<Particle> ParticleSystem::getParticles();
    //void removeLatestEmitter();
    
private:
    std::vector<Force*> forces;
    std::vector<Emitter*> emitters;
    std::vector<Particle> particles;
};

#endif // __PARTICLESYSTEM_H__
