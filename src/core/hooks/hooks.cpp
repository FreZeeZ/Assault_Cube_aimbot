#include "hooks.h"
#include "../console/console.h"
#include "../../../ext/minhook/MinHook.h"
#include <iostream>

bool hooks::Setup()
{
	if (MH_Initialize() != MH_OK)
	{
		return false;
	}

	MH_EnableHook(MH_ALL_HOOKS);
	std::cout << "[HOOKS] Setup is successful!\n";

	console::activate();

	return true;
}

void hooks::Release()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();
	std::cout << "[HOOKS] Release successful!\n";
}