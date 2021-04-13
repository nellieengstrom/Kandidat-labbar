#include "Tracy.hpp"
#include "particlesystem.h"
#include "util/rendering.h"

#include <algorithm>
#include <iterator>
#include <random>
#include <iostream>

// A function strictly used to exemplify the
// render[Particles/Emitters/Forces] functions.
// Note: This function should be removed in your final implementation.
void particleRenderingExample();

namespace {
    constexpr float Pi = 3.141592654f;
    const float Tau = 2.f * Pi;
    
}

int main(int, char**) {
    rendering::createWindow();

    ParticleSystem particleSystem;

    float speed = 1.0f;
    bool isRunning = true;
    float numberOfSpawnDirections = 6.0f;
    float angle = Pi/4;
    //float angleForce = Pi/4;
    vec2 position = {0.0f,0.0f};
    while (isRunning) {
        const float dt = rendering::beginFrame();

        {

            std::cout << "IM HERE" << std::endl;
             //printf("%s\n", (__LINE__));

            ui::GuiScope ui;  // Initiates and finalizes UI rendering upon
                              // construction/destruction
            // @TODO: Add UI calls
            
            // @TODO: Replace this example code with your own UI elements
            
            ui::beginGroup("Lägg till emitters");
                ui::sliderVec2("Position", position, -1.0f, 1.0f);
                if(ui::button("Add uniform emitter")){
                    particleSystem.addUniform(position); //Lägga till uniform emitter
                }
                if(ui::button("Add directional emitter")){
                    particleSystem.addDirectional(position); //Lägga till directional emitter
                }
            ui::endGroup();
            /*if(ui::button("Remove latest emitter")){
                particleSystem.removeLatestEmitter();
            }*/
            
            ui::beginGroup("Lägg till forces");
                if(ui::button("Add gravity well")){
                    particleSystem.addGravityWell(position); //Lägga till gravity well
                }
                if(ui::button("Add wind")){
                    particleSystem.addWind(position); //Lägga till wind
                }
            ui::endGroup();
            
            
            ui::beginGroup("Inställningar");
                ui::sliderFloat("Antal strålar för uniform emitter", numberOfSpawnDirections, 1.0f, 360.0f);
                ui::sliderFloat("Vinkel för directional emitter", angle, 0.0f, 2*Pi);
                //ui::sliderFloat("Vinkel för wind", angleForce, 0.0f, 2 * Pi);
            ui::endGroup();
            
            
            ui::sliderFloat("Simulation speed", speed, 0.001f, 10.0f);
            if (ui::button("Close application")) {
                isRunning = false;
            }
        }

        particleSystem.update(dt * speed, numberOfSpawnDirections, angle);
        particleSystem.render();


        isRunning &= rendering::endFrame();
    }

    rendering::destroyWindow();

    return EXIT_SUCCESS;
}

