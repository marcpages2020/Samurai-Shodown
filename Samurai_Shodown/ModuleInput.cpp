#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
	for (uint i = 0; i < MAX_BUTTONS; ++i) {
		for (int j = 0; j < 2; ++j) {
			game_pad[i][j] = KEY_IDLE;
		}
	}
		
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	SDL_Init(SDL_INIT_GAMECONTROLLER);
	if (controller_player_1 == nullptr) {
		controller_player_1 = SDL_GameControllerOpen(0);
	}
	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	for (int i = 0; i < MAX_BUTTONS; ++i) {
		for (int j = 0; j < 2; ++j) {
			game_pad[i][j] = SDL_GameControllerGetButton(controller_player_1, (SDL_GameControllerButton)i);
		}
	}

	for (int i = 0; i < MAX_BUTTONS; ++i) {

		for (int j = 0; j < 2; ++j) {
			if (game_pad[i][j] == KEY_IDLE) {
				game_pad[i][j] == KEY_DOWN;
				break;
			}
			else {
				game_pad[i][j] == KEY_REPEAT;
				break;
			}

			if (game_pad[i][j] == KEY_REPEAT || game_pad[i][j] == KEY_DOWN) {
				game_pad[i][j] == KEY_UP;
				break;
			}
			else {
				game_pad[i][j] == KEY_IDLE;
				break;
			}
		}

	}
	while (SDL_PollEvent(&Events) == 1) {

		switch (Events.type) {
		case SDL_CONTROLLERDEVICEADDED:
			SDL_Init(SDL_INIT_GAMECONTROLLER);
			if (controller_player_1 == nullptr) {
				controller_player_1 = SDL_GameControllerOpen(0);
				controller_1_index = Events.cdevice.which;
			}
			break;
		case SDL_CONTROLLERDEVICEREMOVED:
			if (Events.cdevice.which == controller_1_index) {
				SDL_GameControllerClose(controller_player_1);
				controller_player_1 = nullptr;
				controller_1_index = 0;
			}
			break;
		}
	}

	if (keyboard[SDL_SCANCODE_ESCAPE] || Events.type == SDL_QUIT)
		return update_status::UPDATE_STOP;


	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}