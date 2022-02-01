// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"
#include "GTAHud.h"

using namespace Memory::VP;

void Init()
{
	// disable bars
	Nop(0x5F0F7A, 5);
	Nop(0x5F1463, 5);
	Nop(0x5F15D0, 5);
	Nop(0x5F0F05, 5);

	// disable weapon swaps
	Nop(0x5DEB57, 5);
	Nop(0x5DEBD7, 5);
	Nop(0x5DEC18, 5);
	Nop(0x5DF007, 5);
	Nop(0x5DEC18, 5);
	Nop(0x5DEC5D, 5);

	// ammo count
	Nop(0x5DF27B, 5);
	Nop(0x5DF735, 5);
	Nop(0x5DF8C3, 5);
	Nop(0x5DF27B, 5);
	Nop(0x5DF540, 5);
	Nop(0x5DF61B, 5);

	// weapon bar
	Nop(0x5DEFBE, 5);


	// ally name
	Patch<float>(0x7CD248, -1);

	GTAHud::LoadSettings();

	InjectHook(0x5EE344, GTAHud::LoadResources, PATCH_CALL);
	InjectHook(0x5DEFBE, GTAHud::Draw, PATCH_CALL);
	InjectHook(0x5DF636, GTAHud::StoreLoadedAmmoCount, PATCH_CALL);
	InjectHook(0x5DF12C, GTAHud::StoreTotalAmmoCount, PATCH_CALL);
}


extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		if (*(int*)0x63BC93 != 0x24448B66)
		{
			MessageBoxA(0, "Invalid executable!", "GTAHud", 0);
		}
		else Init();
	}
}