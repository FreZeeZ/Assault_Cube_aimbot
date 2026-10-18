#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "hooks/hooks.h"

DWORD WINAPI Cube(LPVOID module)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	hooks::Setup();

	while (!(GetAsyncKeyState(VK_END) & 1))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}

	hooks::Release();
	Sleep(3000);

	fclose(f);
	FreeConsole();
	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(module), 0);
	return 0;
}

BOOL __stdcall DllMain(HMODULE hModule, DWORD reson, LPVOID lp)
{
	if (reson == DLL_PROCESS_ATTACH)
	{
		CreateThread(nullptr, NULL, Cube, hModule, NULL, nullptr);
	}
	return TRUE;

}