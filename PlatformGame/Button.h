#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "p2Animation.h"
#include "p2Point.h"
#include "UI_Element.h"
#include "p2SString.h"
#include "PugiXml\src\pugixml.hpp"

class Button : public UI_Element {
public:

	Button(int x, int y, int weight, int height, int type);
	virtual ~Button();
	bool Update(float dt);
	void Draw(float dt);
	bool CleanUp();
	bool IsMouseOn();

public:
	
	SDL_Rect NoPressedNoMouseOn;
	SDL_Rect MouseOn;
	SDL_Rect Pressed;
	bool repeataudio = true;

};

#endif