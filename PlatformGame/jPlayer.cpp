#include "p2Defs.h"
#include "p2Log.h"
#include "p2Point.h"
#include "j1App.h"
#include "jPlayer.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1input.h"

jPlayer::jPlayer() : j1Module()
{
	name.create("player");

	
	

}


jPlayer::~jPlayer()
{
}


bool jPlayer::Awake(pugi::xml_node& config)
{
	LOG("Init SDL player");
	//config = config.child("player");
	tryy = config.child("sprites").attribute("name").as_string();
	
	texture = App->tex->Load(tryy);

	bool ret = true;


	return ret;
}

bool jPlayer::Start()
{
	
	position.x = 30;
	position.y = 60;
	bool ret = true;
	LoadPushbacks();

	return ret;
}

bool jPlayer::PreUpdate()
{

	
	return true;
}

bool jPlayer::Update(float dt)
{
	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame()));
	return true;
}

bool jPlayer::CleanUp()
{
	App->tex->UnLoad(texture);
	return true;
}

bool jPlayer::LoadPushbacks()
{


	idle.PushBack({ 147,0,65,82 });
	current_animation = &idle;
	return true;
}



