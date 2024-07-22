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
#include <fmod.h>
#include <SDL.h>

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


private:
	bool quit{ false };
	Renderer* m_renderer{ nullptr };
	Input* m_input{ nullptr };
	Audio* m_audio{ nullptr };
	Time* m_time{ nullptr };
};

extern Engine g_engine;