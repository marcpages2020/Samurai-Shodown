#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#include <math.h>
#define MAX_FRAMES 25

struct Frame {

	SDL_Rect rect;
	float speed;
};

class Animation
{
public:
	bool loop = true;
	Frame frames[MAX_FRAMES];
	float current_frame;
private:
	int loops;
	int last_frame = -1;

public:

	void PushBack(const SDL_Rect& rect, float speed = 1.0f)
	{
		int i = ++last_frame;
		frames[i].rect = rect;
		frames[i].speed = speed;
	}

	SDL_Rect& GetCurrentFrame()
	{
		current_frame += frames[(int)current_frame].speed;
		if (current_frame >= last_frame) {
			current_frame = (loop) ? 0.0f : last_frame - 1;
			loops++;
		}


		return frames[(int)current_frame].rect;
	}
	bool Finished() const
	{
		return loops > 0;
	}

	void Reset()
	{
		current_frame = 0;
	}
	int SeeCurrentFrame() {
		return (int)current_frame;
	}
};

#endif