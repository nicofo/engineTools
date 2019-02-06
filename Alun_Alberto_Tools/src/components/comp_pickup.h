#pragma once
#include "../includes.h"
#include "../Components.h"


// Pickup logic
struct Pickup : public Component {

	bool picked = false;

	void update(float dt);
	void Save(rapidjson::Document& json, rapidjson::Value & entity) {}
	void Load(rapidjson::Value & entity, int ent_id) {}
	void debugRender();
};
