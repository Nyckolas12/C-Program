#pragma once
#include <fmod.h>
#include <fmod.hpp>
#include <map>
#include <string>
class Audio
{
public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void Shutdown();
	void Update();
	bool Addsound(const std::string& name);
	bool Playsound(const std::string& name);

private:
	FMOD::System* m_audio{ nullptr };
	std::map<std::string, FMOD::Sound*> m_sounds;
};