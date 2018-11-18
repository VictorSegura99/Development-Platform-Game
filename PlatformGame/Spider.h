#ifndef __SPIDER_H__
#define __SPIDER_H__

#include "p2Animation.h"
#include "p2Point.h"
#include "Entity.h"
#include "p2SString.h"
#include "PugiXml\src\pugixml.hpp"

class Spider : public Entity {
public:
	Spider(int x, int y);
	virtual ~Spider();
	bool PreUpdate();
	bool PostUpdate();
	bool Update(float dt);
	bool Radar();
	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;
	void Draw(float dt);
	bool CleanUp();
	void OnCollision(Collider* c2);
	void AnimationLogic();


	Animation LoadPushbacks(pugi::xml_node&, p2SString NameAnim) const;

public:
	
	Animation GoLeft;
	Animation GoRight;
	Animation IdleLeft;
	Animation IdleRight;
	Animation HitLeft;
	Animation HitRight;
	Animation DieLeft;
	Animation DieRight;
	p2SString sprites;
	fPoint speed;
	iPoint spider_pos;
	iPoint player_pos;
	iPoint original_pos;
	iPoint path_to_follow;
	iPoint velocity;
	float GRAVITY = 433.33f;
	uint range = 8;
};






#endif
