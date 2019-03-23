#include "ModuleAudio.h"

/*bool ModuleAudio::Init() {
	int flags = MIX_INIT_OGG;
	int innited = Mix_Init(flags);
	if (innited&flags != flags)
	{
		LOG("Mix_Init: %s\n", Mix_GetError());
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024)==-1)
	{
		LOG("Mix_OpenAudio: %s\n", Mix_GetError());
	}

	return true;
}
Mix_Music* const ModuleAudio::Load(const char* path) {
	song[0] = Mix_LoadMUS(path);
	if (!song)
	{
		LOG("Mix_LoadMUS(\"%s\"): %s\n",path, Mix_GetError());
	}
	if (Mix_PlayMusic(song[0], -1) == -1)
	{

	}
	return song[0];
}

bool ModuleAudio::CleanUp() {
	Mix_FreeMusic(song[0]);
	Mix_Quit();
	return true;
}*/