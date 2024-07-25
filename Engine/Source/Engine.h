#pragma once

#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "Audio.h"
#include "MathUtils.h"
#include "Model.h"
#include "Transform.h"
#include "Vector2.h"
#include "Renderer.h"
#include "ParticleSystem.h"
#include <fmod.h>
#include <SDL.h>
#include <memory>

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime() { return *m_time; }
	bool IsQuit() { return quit; }

	ParticleSystem& GetPS() { return *m_particleSystem; }


private:
	bool quit{ false };
	std::unique_ptr<Renderer> m_renderer{ nullptr };
	std::unique_ptr<Input> m_input{ nullptr };
	std::unique_ptr<Audio> m_audio{ nullptr };
	std::unique_ptr<Time> m_time{ nullptr };
	std::unique_ptr<ParticleSystem> m_particleSystem;
};

extern Engine g_engine;