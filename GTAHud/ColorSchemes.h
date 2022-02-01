#pragma once


struct Color {
	int R, G, B;
};


struct ColorScheme {
	Color MoneyColor;
	Color HealthColor;
	Color ArmorColor;
	Color TimeColor;
	Color AmmoColor;
	Color WantedColor;
};

extern ColorScheme ColorsVC;
extern ColorScheme ColorsMH;
extern ColorScheme Colors3;
extern ColorScheme ColorsLCS;
// to do
extern ColorScheme ColorsCustom;