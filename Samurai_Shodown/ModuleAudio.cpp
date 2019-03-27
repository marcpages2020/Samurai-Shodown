#include "ModuleAudio.h"
#include "Application.h"
#include "SDL/include/SDL.h"
#pragma comment(lib,"SDL_mixer/libx86/SDL2_mixer.lib")

ModuleAudio::ModuleAudio() :Module()
{}
ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init() {
	int flags = MIX_INIT_OGG;
	Mix_Init(SDL_INIT_AUDIO);

	int innited = Mix_Init(flags);
	if (innited&flags != flags)
	{
		LOG("Mix_Init: %s\n", Mix_GetError());
		return false;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024)==-1)
	{
		LOG("Mix_OpenAudio: %s\n", Mix_GetError());
		return true;
	}



	return true;
}

Mix_Music* ModuleAudio::LoadMusic(const char* path) {
	Mix_Music* song;
	song = Mix_LoadMUS(path);
	if (!song)
	{
		LOG("Mix_LoadMUS(\"%s\"): %s\n",path, Mix_GetError());
	}	
	for (int i = 0; i < MAX_SONGS; i++)
	{
		if (songs[i]==nullptr)
		{
			songs[i] = song;
			break;
		}
	}
	return song;
}

Mix_Chunk* ModuleAudio::LoadFX(const char* path) {
	Mix_Chunk* fx;
	fx = Mix_LoadWAV(path);
	if (!fx)
	{
		LOG("Mix_LoadWAV: %s\n", Mix_GetError());
	}
	for (int i = 0; i < MAX_FX; i++)
	{
		if (fxs[i]==nullptr)
		{
			fxs[i] = fx;
			break;
		}
	}
	return fx;
}

bool ModuleAudio::PlayMusic(Mix_Music* song) {
	if (Mix_PlayMusic(song, -1) == -1)
	{
		LOG("Mix_PlayMusic: %s\n", Mix_GetError());
		return false;
	}
	return true;
}

bool ModuleAudio::PlayFX(Mix_Chunk* fx) {
	if (Mix_PlayChannel(-1, fx, 0) == -1)
	{
		LOG("Mix_PlayChannel: %s\n", Mix_GetError());
		return false;
	}
	return true;
}

bool ModuleAudio::CleanUp() {
	
	LOG("Freeing music");

	for (int i = 0; i < MAX_SONGS; i++)
	{
		if (songs[i]!=nullptr)
		{
			songs[i] = nullptr;
		}
	}
	for (int i = 0; i <MAX_FX; i++)
	{
		if (fxs[i]!=nullptr)
		{
			fxs[i] = nullptr;
		}
	}


	Mix_CloseAudio();
	Mix_Quit();
	return true;
}