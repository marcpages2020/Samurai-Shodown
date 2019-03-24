#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

#include "ModuleScene.h"

ModuleInput::ModuleInput() : Module()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{

	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	
	return ret;
}

// Called every draw update
update_status ModuleInput::Update()
{
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);

	// TODO 1: find out how to detect if the ESC key was pressed
	// and quit the game

	if (keyboard[SDL_SCANCODE_ESCAPE])
	{
		SDL_Quit();
		return update_status::UPDATE_STOP;
	}
	else if (keyboard[SDL_SCANCODE_LEFT])
	{
		if (App->scene->x<-10)
		{
			App->scene->x += 10;
		}

	}
	else if (keyboard[SDL_SCANCODE_RIGHT])
	{
		if (App->scene->x>-180)
		{
			App->scene->x -= 10;
		}


		
	}
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}