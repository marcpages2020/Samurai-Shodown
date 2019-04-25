#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision()
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_WALL_LEFT][COLLIDER_WALL_LEFT] = false;
	matrix[COLLIDER_WALL_RIGHT][COLLIDER_WALL_RIGHT] = false;

	matrix[COLLIDER_WALL_RIGHT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL_RIGHT][COLLIDER_PLAYER_PARTICLES] = false;
	matrix[COLLIDER_WALL_LEFT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL_LEFT][COLLIDER_PLAYER_PARTICLES] = false;

	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_WALL_RIGHT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_WALL_LEFT] = true;

	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_PARTICLES] = false;
	matrix[COLLIDER_PLAYER_PARTICLES][COLLIDER_PLAYER] = false;

	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER] = true;

	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_2_ATTACK] = true;
	matrix[COLLIDER_PLAYER_2_ATTACK][COLLIDER_PLAYER] = true;

	matrix[COLLIDER_PLAYER_2][COLLIDER_WALL_RIGHT] = true;
	matrix[COLLIDER_WALL_RIGHT][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_WALL_LEFT] = true;
	matrix[COLLIDER_WALL_LEFT][COLLIDER_PLAYER_2] = true;

	matrix[COLLIDER_PLAYER_1_ATTACK][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER_1_ATTACK] = true;

	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_1_ATTACK] = false;
	matrix[COLLIDER_PLAYER_1_ATTACK][COLLIDER_PLAYER] = false;

	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER_2_ATTACK] = false;
	matrix[COLLIDER_PLAYER_2_ATTACK][COLLIDER_PLAYER_2] = false;

	matrix[COLLIDER_PLAYER_PARTICLES][COLLIDER_WALL_RIGHT] = false;
	matrix[COLLIDER_PLAYER_PARTICLES][COLLIDER_WALL_LEFT] = false;

	matrix[COLLIDER_PLAYER_2_PARTICLES][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER_2_PARTICLES] = false;
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	// Calculate collisions
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->callback)
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if (debug == false)
		return;

	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_WALL_RIGHT: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_WALL_LEFT: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER_2: //orange
			App->render->DrawQuad(colliders[i]->rect, 255, 165, 0, alpha);
			break;
		case COLLIDER_PLAYER_PARTICLES: //yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER_1_ATTACK: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_PLAYER_2_ATTACK: //purple
			App->render->DrawQuad(colliders[i]->rect, 180, 150, 190, alpha);
			break;
		case COLLIDER_PLAYER_2_PARTICLES:
			App->render->DrawQuad(colliders[i]->rect, 205, 130, 60, alpha);
			break;
		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}
	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
			rect.x + rect.w > r.x &&
			rect.y < r.y + r.h &&
			rect.h + rect.y > r.y);
}