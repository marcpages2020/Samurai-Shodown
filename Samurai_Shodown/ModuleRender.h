#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"
#include "SDL\include\SDL_rect.h"
#include "SDL/include/SDL.h"
#include <limits.h>

struct SDL_Renderer;
struct SDL_Texture;
struct Collider;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status Update();
	update_status PreUpdate();
	bool CleanUp();
	
	bool Blit(SDL_Texture* texture, int x, int y, const SDL_Rect* section = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, float speed = 1.0f, bool use_camera = true, double angle = 0, int pivot_x = INT_MAX, int pivot_y = INT_MAX) const;
	bool VericalTransition();
	bool HorizontalTransition();
	bool DrawQuad(const SDL_Rect & rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);

	void MoveCamera();
	void SetCamera();
private:
	Collider* left = nullptr;
	Collider* right = nullptr;
public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	SDL_Rect up_black_rect{0 ,0,SCREEN_WIDTH,0 };
	SDL_Rect down_black_rect{ 0,SCREEN_HEIGHT,SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
	SDL_Rect left_black_rect{ 0 ,0,SCREEN_WIDTH/2,SCREEN_HEIGHT};
	SDL_Rect right_black_rect{ SCREEN_WIDTH/2 ,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT };
};

#endif //__ModuleRenderer_H__