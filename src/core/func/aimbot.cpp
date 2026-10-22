#include "aimbot.h"
#include <Windows.h>
#include "../../sdk/mem/memory.h"
#include "../../sdk/mem/offsets.h"
#include <iostream>


void aim::AimBot()
{
	GetClossestEntity();
}

void aim::GetClossestEntity()
{
    uintptr_t Base = Mem::GetModuleBase("ac_client.exe");
    if (!Base) return;

    uintptr_t EntityAdrr = *reinterpret_cast<uintptr_t*>(Base + offs::EntityList);
    if (!EntityAdrr) return;

    uintptr_t PlayerAdress = *reinterpret_cast<uintptr_t*>(Base + offs::LocalPlayer);
    if (!PlayerAdress) return;

    Vector3 localPlayerPos = *(Vector3*)(PlayerAdress + offs::Pos);
    float MinDist = 999999.0f;
    Vector3 closestPos;
    bool found = false;

    int NumPlayers = *reinterpret_cast<int*>(Base + offs::NumOfPlayers);

    for (int i = 1; i < NumPlayers; i++)
    {
        uintptr_t enemy = *reinterpret_cast<uintptr_t*>(EntityAdrr + (i * 0x4));
        if (!enemy) continue;

        int isDead = *reinterpret_cast<int*>(enemy + offs::IsDead);
        if (isDead != 0) continue;

        Vector3 Player_pos = *reinterpret_cast<Vector3*>(enemy + offs::Pos);
        float dist = localPlayerPos.Distance(Player_pos);
        if (dist < MinDist)
        {
            MinDist = dist;
            closestPos = Player_pos;
            found = true;
        }
    }

    if (found)
    {
        float dx = closestPos.x - localPlayerPos.x;
        float dy = closestPos.y - localPlayerPos.y;
        float dz = closestPos.z - localPlayerPos.z;

        float dist2D = std::sqrt(dx * dx + dy * dy);

        float yaw = std::atan2(dy, dx) * (180.0f / 3.14159265f) + 90.0f;
        float pitch = std::atan2(dz, dist2D) * (180.0f / 3.14159265f);

        Vector2* playerAngles = reinterpret_cast<Vector2*>(PlayerAdress + offs::ViewAng);
        playerAngles->x = yaw;
        playerAngles->y = pitch;
    }
}