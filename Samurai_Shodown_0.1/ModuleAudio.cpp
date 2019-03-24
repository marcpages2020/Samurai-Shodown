#include "ModuleAudio.h"
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
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024)==-1)
	{
		LOG("Mix_OpenAudio: %s\n", Mix_GetError());
	}
	App->audio->PlaySong("Wan-Fu.ogg");
	App->audio->PlayFX("Ippon.wav");
	return true;
}

void ModuleAudio::PlaySong(const char* path) {
	Mix_Music* song;
	song = Mix_LoadMUS(path);
	if (!song)
	{
		LOG("Mix_LoadMUS(\"%s\"): %s\n",path, Mix_GetError());
	}	
	if (Mix_PlayMusic(song, -1) == -1)
	{
		LOG("Mix_PlayMusic: %s\n", Mix_GetError());
	}
	for (int i = 0; i < MAX_SONGS; i++)
	{
		if (songs[i]==nullptr)
		{
			songs[i] = song;
			break;
		}
	}
}

void ModuleAudio::PlayFX(const char* path) {
	Mix_Chunk* fx;
	fx = Mix_LoadWAV(path);
	if (!fx)
	{
		LOG("Mix_LoadWAV: %s\n", Mix_GetError());
	}
	if (Mix_PlayChannel(-1,fx,0)==-1)
	{
		LOG("Mix_PlayChannel: %s\n", Mix_GetError());
	}
	for (int i = 0; i < MAX_FX; i++)
	{
		if (fxs[i]==nullptr)
		{
			fxs[i] = fx;
			break;
		}
	}
}

bool ModuleAudio::CleanUp() {
	
	LOG("Freeing muisc");

	for (int i = 0; i < MAX_SONGS; i++)
	{
		if (songs[i]!=nullptr)
		{
			Mix_FreeMusic(songs[i]);
			songs[i] = nullptr;
		}
	}
	for (int i = 0; i <MAX_FX; i++)
	{
		if (fxs[i]!=nullptr)
		{
			Mix_FreeChunk(fxs[i]);
			fxs[i] = nullptr;
		}
	}


	Mix_Quit();
	return true;
}