#ifndef __JPLAYER_H_
#define __JPLAYER_H_

#include "j1Module.h"
#include "p2Animation.h"
#include "p2Point.h"
#include "j1Collision.h"
struct SDL_Texture;
struct SDL_Rect;



class jPlayer : public j1Module
{
public:
	jPlayer();

	//Destructor
	virtual ~jPlayer();

	//Called before player is aviable
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	//// Called each loop iteration
	bool PreUpdate();
	
	//// Called each loop iteration
	bool PostUpdate();


	//Called every loop iteration
	bool Update(float dt);

	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);
	void Die();
	void Fall();
	void Spawn();
	void LoadPushbacks(); 
	void ChangePlayer(int playernumber);
	void GoJump();
	void GoSwim();
	void GoClimb();
	void Move_Left_Right();
	void Camera();
	void SetPositionRect();

public:
	
	SDL_Rect rect;

	Animation* current_animation = nullptr;
	Animation idle[3];
	Animation idle2[3];
	Animation GoLeft[3];
	Animation GoRight[3];
	Animation jumpR[3];
	Animation jumpL[3];
	Animation SwimRight[3];
	Animation SwimLeft[3];
	Animation Climb[3];
	Animation ClimbIdle[3];
	Animation Death[3];

	SDL_Texture* texture; 


	p2SString sprites_name[3];
	p2SString	JumpFx;
	p2SString	WaterFx;
	p2SString DeathFx;
	p2SString DeathFx2;
	p2SString LadderFx;

	Collider* coll = nullptr;

	fPoint position;
	iPoint initialmap1;
	iPoint initialmap2;

	bool WalkLeft = false;
	bool WalkRight = false;
	bool GoUp = false;
	bool GoDown = false;
	bool Idle = false;
	bool Jump = false;
	bool IsJumping = false;
	bool CanJump = true;
	bool CanClimb = false;
	bool CanSwim = false;
	bool death = false;
	bool fall = false;
	bool God = false;
	bool NextMap = false;
	bool NoInput = false;

	float gravity = 0.0f;
	float JumpSpeed = 0.0f;
	float SpeedWalk = 0.0f;
	float SpeedClimb = 0.0f;
	float SpeedSwimUp = 0.0f;
	float SpeedSwimDown = 0.0f;
	float SpeedSwimLeftRight = 0.0f;

	int startmap2 = 0;
	int maxYcam = 0;
	int minYcam = 0;
	int lowcam = 0;
	int positionWinMap1 = 0;
	int startpointcameramap2 = 0;
	int JumpTime = 0;
	int playerwidth = 0;
	int playerHeight = 0;
	int playerheight = 0;
	int finalmapplayer = 0;
	int finalmap = 0;
	int NumPlayer = 900;

	unsigned int jumpfx;
	unsigned int waterfx;
	unsigned int deathfx;
	unsigned int deathfx2;
	unsigned int ladderfx;
	uint Time = 0;
	

};


#endif