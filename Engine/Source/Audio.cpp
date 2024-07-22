#include "Audio.h"
#include <iostream>

bool Audio::Initialize()
{
	FMOD::System_Create(&m_audio);

	void* extradriverdata = nullptr;
	m_audio->init(32, FMOD_INIT_NORMAL, extradriverdata);
	return true;
}
void Audio::Shutdown()
{
	m_audio->close();
}

void Audio::Update()
{
	m_audio->update();
}

bool Audio::Addsound(const std::string& name)
{
	FMOD::Sound* sound = nullptr;
	m_audio->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);
	if (sound == nullptr)
	{
		std::cerr << "Could not load Sound: " << name << std::endl;
		return false;
	}

	m_sounds[name] = sound;
	return true;
}

bool Audio::Playsound(const std::string& name)
{

	if (m_sounds.find(name) == m_sounds.end())
	{
		if (!Addsound(name)) return false;

	}

	m_audio->playSound(m_sounds[name], 0, false, nullptr);
	return true;
}
