#include "comp_pickup.h"
#include "../EntityComponentStore.h"
#include "../extern.h"
#include "../tools/ConsoleModule.h"


void Pickup::update(float dt) {
	
	if (!picked) {
		 
		Camera& camera = ECS.getComponentInArray<Camera>(1); // PlayerCamera
		Transform& transformPlayer = ECS.getComponentFromEntity<Transform>(camera.owner);
		Transform& transformPickup = ECS.getComponentFromEntity<Transform>(owner);
		lm::vec3 playerPosition = transformPlayer.position();
		lm::vec3 pickupPosition = transformPickup.position();
		//std::cout << pickupPosition.distance(playerPosition) << std::endl;
		if (pickupPosition.distance(playerPosition) < 5.0f) {
			// pickup 
			transformPickup.scale(0.0f, 0.0f, 0.0f);
			picked = true;
		}
	}
}

// Render debug the tag.
void Pickup::debugRender() {

	static char elevenBytes[11] = {};
	ImGui::AddSpace(0, 5);
	if (ImGui::TreeNode("Pickup")) {
		ImGui::Text("It's a Pickup");
		ImGui::TreePop();
	}

	// Adds a cool line at the end.
	ImDrawList*   draw_list = ImGui::GetWindowDrawList();
	ImVec2 p = ImGui::GetCursorScreenPos();
	draw_list->AddLine(ImVec2(p.x - 9999, p.y), ImVec2(p.x + 9999, p.y), ImGui::GetColorU32(ImGuiCol_Border));
}