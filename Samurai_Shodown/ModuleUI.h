#ifndef _MODULE_UI
#define _MODULE_UI
#include "Module.h"

class ModuleUI : public Module 
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

};

#endif // !_MODULE_UI

