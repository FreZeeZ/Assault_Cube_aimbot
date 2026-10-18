#include "console.h"
#include "../func/aimbot.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>

using namespace std;
void console::activate()
{
	cout << "/=/=/=/=/=/=/=/=/=/\n"
		 << "made by FreeZee_S\n"
		 << "/=/=/=/=/=/=/=/=/=/\n" << endl;

	cout << "Insert - print control panel\n"
		 << "press END for disable console control\n";

	while (!(GetAsyncKeyState(VK_END) & 1))
	{
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			cout << "Insert - print control panel\n"
				 << "press END for disable console control\n";
		}

		this_thread::sleep_for(chrono::milliseconds(15));
	}
}
