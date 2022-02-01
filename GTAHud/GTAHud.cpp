#include "pch.h"
#include "GTAHud.h"
#include "IniReader.h"

#include "manhunt/Frontend.h"
#include "manhunt/Scene.h"
#include "manhunt/Player.h"
#include "manhunt/Time.h"
#include "manhunt/Renderer.h"
#include "manhunt/Collectable.h"
#include "manhunt/TypeData.h"
#include "manhunt/Inventory.h"
#include "manhunt/core.h"

#include "ColorSchemes.h"

#include <iostream>

int GTAHud::m_totalAmmo = 0;
int GTAHud::m_curAmmo = 0;
int GTAHud::m_healthTexture = 0;
int GTAHud::m_staminaTexture = 0;

GTAHudSettings GTAHud::settings;

ColorScheme Colors3 = {
	{89, 115, 150}, // money
	{186, 101, 50}, // health
	{124, 140, 95}, // armor
	{194, 165, 120},// time
	{0,0,0},// ammo
	{255,255,255},// wanted
};

ColorScheme ColorsVC = {
	{0, 207, 133}, // money
	{255, 150, 225}, // health
	{185, 185, 185}, // armor
	{97, 194, 247},// time
	{255, 150, 225},// ammo
	{97, 194, 247},// wanted
};

ColorScheme ColorsLCS = {
	{0, 128, 64}, // money
	{142,0,0}, // health
	{42,120, 190}, // armor
	{0, 128, 64},// time
	{255, 255, 255},// ammo
	{192, 155, 54},// wanted
};

ColorScheme ColorsMH = {
	{150,150, 150}, // money
	{112, 145, 69}, // health
	{167, 158, 89}, // armor
	{150,150, 150},// time
	{255, 255, 255},// ammo
	{192, 155, 54},// wanted
};




void GTAHud::LoadSettings()
{
	CIniReader ini("");

	settings.UseVCAmmoPos = ini.ReadBoolean("Settings", "UseVCAmmoPos", false);
	settings.FixMHIcons = ini.ReadBoolean("Settings", "FixMHIcons", false);
	settings.ColorScheme = ini.ReadInteger("Settings", "ColorScheme", 0);
	settings.HudAlpha = ini.ReadInteger("Settings", "HudAlpha", 255);
	settings.HudOffsetX = ini.ReadFloat("Settings", "HudOffsetX", -0.03f);
	settings.HudOffsetY = ini.ReadFloat("Settings", "HudOffsetY", 0.025f);
}

void GTAHud::LoadResources()
{
	int txd = CallAndReturn<int, 0x5EA510, const char*>("pictures\\gta_hud.txd");

	if (!txd)
		MessageBoxA(0, "Failed to load mp_hud.txd!", 0, MB_ICONERROR);

	if (txd)
	{
		m_healthTexture = CFrontend::GetTextureFromTXD(txd, "heart");
		m_staminaTexture = CFrontend::GetTextureFromTXD(txd, "stamina");
	}

	// CFrontend::InitTextures
	Call<0x5EA540>();

}

void GTAHud::Draw()
{
	static char buff[128] = {};
	CPlayer* plr = (CPlayer*)CScene::FindPlayer();

	// disable pickup names
	Patch<int>(0x7C9C80, 1);

	ColorScheme scheme = ColorsMH;

	switch (settings.ColorScheme)
	{
	case 0:
		scheme = ColorsMH;
		break;
	case 1:
		scheme = Colors3;
		break;
	case 2:
		scheme = ColorsVC;
		break;
	case 3:
		scheme = ColorsLCS;
		break;
	default:
		break;
	}



	// weapon icon
	{
		// this includes fist when switching;
		//CCollectableTypeData* item;
		//item = (CCollectableTypeData*)plr->m_pInventory->m_inventory[plr->m_nCurrentSlot]->m_pTypeData;
		//int icon = CallAndReturn<int, 0x5DF9A0, int, int>(item->m_nCollectableType, 0);
		
		int icon = CallAndReturn<int, 0x5DF9A0, int, int>(CGameInventory::GetCurrentItem(), 0);

		if (settings.FixMHIcons)
		{
			CRenderer::PushRenderStateBlend();
			CRenderer::RenderStateSetBlend(rwBLENDONE, rwBLENDONE);
		}

		CRenderer::DrawQuad2d(0.915f + settings.HudOffsetX, 0.0625f + settings.HudOffsetY, 0.08f, 0.1375f, 255, 255, 255, settings.HudAlpha, *(int*)icon);

		if (settings.FixMHIcons)
			CRenderer::PopRenderStateBlend();
	}


	// Health
	if (plr->m_fHealth < 25 && CGameTime::ms_currGameTime & 8 || plr->m_fHealth > 25)
	{
		int health = plr->m_fHealth;
		if (health < 0)
			health = 0;
		sprintf(buff, "  %03d", health);
		CRenderer::DrawQuad2d(0.845f + settings.HudOffsetX, 0.16f + settings.HudOffsetY, 0.024f, 0.045f, 0, 0, 0, settings.HudAlpha, *(int*)m_healthTexture);
		CRenderer::DrawQuad2d(0.842f + settings.HudOffsetX, 0.156f + settings.HudOffsetY, 0.024f, 0.045f, scheme.HealthColor.R, scheme.HealthColor.G, scheme.HealthColor.B, settings.HudAlpha, *(int*)m_healthTexture);

		CFrontend::SetDrawRGBA(0, 0, 0, settings.HudAlpha);
		CFrontend::Print8(buff, 0.852f + settings.HudOffsetX, 0.155f + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
		CFrontend::SetDrawRGBA(scheme.HealthColor.R, scheme.HealthColor.G, scheme.HealthColor.B, settings.HudAlpha);
		CFrontend::Print8(buff, 0.85f + settings.HudOffsetX, 0.15 + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);

	}

	// Stamina
	float normalizedStamina = plr->m_fStamina * 100.0f;
	if (normalizedStamina < 25 && CGameTime::ms_currGameTime & 8 || normalizedStamina  > 25)
	{
		sprintf(buff, "  %03d", (int)(normalizedStamina));
		CRenderer::DrawQuad2d(0.773f + settings.HudOffsetX, 0.16f + settings.HudOffsetY, 0.024f, 0.045f, 0, 0, 0, settings.HudAlpha, *(int*)m_staminaTexture);
		CRenderer::DrawQuad2d(0.770f + settings.HudOffsetX, 0.156f + settings.HudOffsetY, 0.024f, 0.045f, scheme.ArmorColor.R, scheme.ArmorColor.G, scheme.ArmorColor.B, settings.HudAlpha, *(int*)m_staminaTexture);

		CFrontend::SetDrawRGBA(0, 0, 0, settings.HudAlpha);
		CFrontend::Print8(buff, 0.78f + settings.HudOffsetX, 0.155f + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
		CFrontend::SetDrawRGBA(scheme.ArmorColor.R, scheme.ArmorColor.G, scheme.ArmorColor.B, settings.HudAlpha);
		CFrontend::Print8(buff, 0.778f + settings.HudOffsetX, 0.15 + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
	}

	// Money (kills)
	{
		int kills = *(int*)0x7B7D84 + *(int*)0x7B7DA0;
		sprintf(buff, "$%09d", kills);
		CFrontend::SetDrawRGBA(0, 0, 0, settings.HudAlpha);
		CFrontend::Print8(buff, 0.782f + settings.HudOffsetX, 0.105f + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
		CFrontend::SetDrawRGBA(scheme.MoneyColor.R, scheme.MoneyColor.G, scheme.MoneyColor.B, settings.HudAlpha);
		CFrontend::Print8(buff, 0.78f + settings.HudOffsetX, 0.10 + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
	}

	// Time
	{
		int minutes = (CGameTime::ms_currGameTimePaused / 1000 / 60) % 60;
		int seconds = (CGameTime::ms_currGameTimePaused / 1000 % 60);


		sprintf(buff, "   %02d:%02d", minutes, seconds);
		CFrontend::SetDrawRGBA(0, 0, 0, settings.HudAlpha);
		CFrontend::Print8(buff, 0.826f + settings.HudOffsetX, 0.055f + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
		CFrontend::SetDrawRGBA(scheme.TimeColor.R, scheme.TimeColor.G, scheme.TimeColor.B, settings.HudAlpha);
		CFrontend::Print8(buff, 0.825f + settings.HudOffsetX, 0.05f + settings.HudOffsetY, 1.0f, 1.0f, 0.0, FONT_TYPE_DEFAULT);
	}

	// Ammo
	{
		if (IsPlayerHoldingAFirearm())
		{
			// center hack
			float startingPos = 0.927;

			if (m_totalAmmo > 9 && m_totalAmmo < 100)
				startingPos = 0.927 + 0.005;

			if (m_totalAmmo >= 0 && m_totalAmmo < 10)
				startingPos = 0.927 + 0.010;

			float vcOffset = 0.0;

			if (settings.UseVCAmmoPos)
				vcOffset = 0.055f;

			sprintf(buff, "%d-%d", m_totalAmmo, m_curAmmo);
			if (!(scheme.AmmoColor.R == 0 && scheme.AmmoColor.G == 0 && scheme.AmmoColor.B == 0))
			{
				CFrontend::SetDrawRGBA(0, 0, 0, settings.HudAlpha);
				CFrontend::Print8(buff, startingPos + 0.002 + settings.HudOffsetX, 0.160f + settings.HudOffsetY + vcOffset, 0.65f, 0.65f, 0.0, FONT_TYPE_DEFAULT);
			}
			CFrontend::SetDrawRGBA(scheme.AmmoColor.R, scheme.AmmoColor.G, scheme.AmmoColor.B, settings.HudAlpha);
			CFrontend::Print8(buff, startingPos + settings.HudOffsetX, 0.155 + settings.HudOffsetY + vcOffset, 0.65f, 0.65f, 0.0, FONT_TYPE_DEFAULT);
		}
		
	}
}

void GTAHud::StoreLoadedAmmoCount(char*, char*, int count)
{
	m_curAmmo = count;
}

void GTAHud::StoreTotalAmmoCount(char*, char*, int count)
{
	m_totalAmmo = count;
}

bool GTAHud::IsPlayerHoldingAFirearm()
{
	switch (CGameInventory::GetCurrentItem())
	{
	case CT_GLOCK:
	case CT_DESERT_EAGLE:
	case CT_6SHOOTER:
	case CT_TRANQ_RIFLE:
	case CT_SHOTGUN:
	case CT_NAILGUN:
	case CT_SHOTGUN_TORCH:
	case CT_SAWNOFF:
	case CT_UZI:
	case CT_COLT_COMMANDO:
	case CT_SNIPER_RIFLE:
	case CT_GLOCK_SILENCED:
	case CT_GLOCK_TORCH:
		return true;
	}

	return false;
}
