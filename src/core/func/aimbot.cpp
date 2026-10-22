#include "aimbot.h"
#include <Windows.h>
#include "../../sdk/mem/memory.h"
#include "../../sdk/mem/offsets.h"
#include <iostream>

void aim::AimBot()
{
	aim::GetClossestEntity();

}

void aim::GetClossestEntity()
{
	uintptr_t Base = Mem::GetModuleBase("ac_client.exe");
	if (!Base) return;

	uintptr_t EntityAdrr = *reinterpret_cast<uintptr_t*>(Base + offs::EntityList);
	if (!EntityAdrr) return;

	uintptr_t PlayerAdress = *reinterpret_cast<uintptr_t*>(Base + offs::LocalPlayer);
	if (!PlayerAdress) return;

	int NumPlayers = *reinterpret_cast<int*>(Base + offs::NumOfPlayers);

	for (int i = 0; i < NumPlayers; i++)
	{
		uintptr_t enemy = *(uintptr_t*)(EntityAdrr + (i * 0x4));
		if (!enemy) continue;

		if (enemy == PlayerAdress) continue;

		Vector3 pos = *reinterpret_cast<Vector3*>(enemy + offs::Pos);
		std::cout << "[+] Enemy [" << i << "] Pos: X=" << pos.x << " Y=" << pos.y << " Z=" << pos.z << std::endl;
	}

}