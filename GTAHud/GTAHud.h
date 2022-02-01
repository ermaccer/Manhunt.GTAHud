#pragma once
#include "ColorSchemes.h"

struct GTAHudSettings {
	bool UseVCAmmoPos = false;
	bool FixMHIcons = true;
	int  ColorScheme = 0;
	int  HudAlpha = 255;
	float HudOffsetX = -0.03f;
	float HudOffsetY = 0.025f;
};

class GTAHud {
public:
	static int m_totalAmmo;
	static int m_curAmmo;

	static int m_healthTexture;
	static int m_staminaTexture;
	
	static GTAHudSettings settings;

	static void LoadSettings();
	static void LoadResources();

	static void Draw();
	static void StoreLoadedAmmoCount(char*, char*, int count);
	static void StoreTotalAmmoCount(char*, char*, int count);

	static bool IsPlayerHoldingAFirearm();
};