#include "Spider.h"
#include "p2SString.h"
#include "j1Textures.h"
#include "j1App.h"
#include "j1Render.h"
#include "PugiXml\src\pugixml.hpp"

Spider::Spider(int x, int y) : Entity(x,y)
{
	position.x = x;
	position.y = y;
}

Spider::~Spider()
{
}

bool Spider::Awake(pugi::xml_node & config)
{
	pugi::xml_node spider = config.child("enemies").child("Spider");

	sprites = spider.child("sprite").text().as_string();
	GoLeft = LoadPushbacks(spider, "GoLeft");
	GoRight = LoadPushbacks(spider, "GoRight");
	IdleLeft = LoadPushbacks(spider, "IdleLeft");
	IdleRight = LoadPushbacks(spider, "IdleRight");
	DieLeft = LoadPushbacks(spider, "DieLeft");
	DieRight = LoadPushbacks(spider, "DieRight");
	HitLeft = LoadPushbacks(spider, "HitLeft");
	HitRight = LoadPushbacks(spider, "HitRight");

	return true;
}

bool Spider::Start()
{

	texture = App->tex->Load(sprites.GetString());
	current_animation = &IdleLeft;
	return true;
}

bool Spider::PreUpdate()
{
	return true;
}

bool Spider::PostUpdate()
{
	return true;
}

bool Spider::Update(float dt)
{
	return true;
}

bool Spider::Load(pugi::xml_node & spider)
{
	return true;
}

bool Spider::Save(pugi::xml_node & spider) const
{
	return true;
}

void Spider::Draw(float dt)
{

	App->render->Blit(texture, position.x, position.y, &(current_animation->GetCurrentFrame(dt)));

}

bool Spider::CleanUp()
{
	return true;
}

void Spider::OnCollision(Collider * c2)
{


}

Animation Spider::LoadPushbacks(pugi::xml_node &config, p2SString NameAnim) const
{
	p2SString XML_Name_Player_Anims;
	SDL_Rect rect;
	Animation anim;
	XML_Name_Player_Anims = "AnimationsSpider";

	for (pugi::xml_node frames = config.child(XML_Name_Player_Anims.GetString()).child(NameAnim.GetString()).child("frame"); frames; frames = frames.next_sibling("frame")) {
		rect.x = frames.attribute("x").as_int();
		rect.y = frames.attribute("y").as_int();
		rect.w = frames.attribute("w").as_int();
		rect.h = frames.attribute("h").as_int();
		anim.PushBack({ rect.x,rect.y,rect.w,rect.h });
	}
	anim.speed = config.child(XML_Name_Player_Anims.GetString()).child(NameAnim.GetString()).attribute("speed").as_float();
	anim.loop = config.child(XML_Name_Player_Anims.GetString()).child(NameAnim.GetString()).attribute("loop").as_bool();

	return anim;
}