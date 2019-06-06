#ifndef _MODULECHARACTERSELECTION_H
#define _MODULECHARACTERSELECTION_H
#include "Module.h"
#include "ModuleTextures.h"
#include "Animation.h"
#include "ModuleAudio.h"

class ModuleCharacterSelection :public Module {
public:
	ModuleCharacterSelection();
	~ModuleCharacterSelection();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* background;
	SDL_Texture* character;
	SDL_Texture* player1;
	SDL_Texture* player2;
	Mix_Music* music;
	Mix_Chunk* character_selected;
	Animation p1;
	Animation p2;
	Animation idle;
	bool ring_played = false;

};
#endif // !_MODULECHARACTERSELECTION_H

