#include "catch2.h"
#include "particlesystem.h"

TEST_CASE("If the particles are deleted correctly", "ParticleSystem") {

	{
		ParticleSystem testSystem;
		constexpr float Pi = 3.141592654f;

		float dt = 60;
		float numberOfSpawnDirections = 1;
		float angle = Pi / 4;

		vec2 inPosition = { 0.5f, -0.5f };
		testSystem.addUniform(inPosition);
		testSystem.update(dt, numberOfSpawnDirections, angle);
		REQUIRE(testSystem.getParticles[0].getLifeTime() == 60.0f);
		testSystem.update(dt, numberOfSpawnDirections, angle);
		REQUIRE(testSystem.getParticles[0].getLifeTime() == 0.0f);
	}
}

