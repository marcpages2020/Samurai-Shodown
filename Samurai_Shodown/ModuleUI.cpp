#include "ModuleUI.h"

ModuleUI::ModuleUI() {}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {
	LOG("Loading UI\n");
	return true;
}

bool ModuleUI::CleanUp() {
	LOG("UI Unloaded\n");
	return true;
}

update_status ModuleUI::Update() {
	return UPDATE_CONTINUE;
}
