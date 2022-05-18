#include "common.h"
#include "hud_element.h"

HudScript HudScript_HandPointDownLoop = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_SetTexelOffset(0, -1),
		he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
		he_SetTexelOffset(0, -1),
		he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
		he_SetTexelOffset(0, -1),
		he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
		he_SetTexelOffset(0, -1),
		he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
		he_SetTexelOffset(2, -1),
		he_SetImage(1, 0x0002C900, 0x0002CA20),
		he_SetTexelOffset(2, -1),
		he_SetImage(1, 0x0002CA40, 0x0002CB60),
		he_SetTexelOffset(2, -1),
		he_SetImage(4, 0x0002CB80, 0x0002CCA0),
		he_SetTexelOffset(2, 4),
		he_SetImage(1, 0x0002C900, 0x0002CA20),
		he_SetTexelOffset(0, 3),
		he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
		he_SetTexelOffset(0, -1),
		he_SetImage(14, 0x0002CCC0, 0x0002CDE0),
	he_Restart,
	he_End
};

HudScript HudScript_HandPointDown = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_SetTexelOffset(0, -1),
	he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
	he_SetTexelOffset(2, -1),
	he_SetImage(1, 0x0002C900, 0x0002CA20),
	he_SetTexelOffset(2, -1),
	he_SetImage(1, 0x0002CA40, 0x0002CB60),
	he_SetTexelOffset(2, -1),
	he_SetImage(4, 0x0002CB80, 0x0002CCA0),
	he_SetTexelOffset(2, 4),
	he_SetImage(1, 0x0002C900, 0x0002CA20),
	he_SetTexelOffset(0, 3),
	he_SetImage(1, 0x0002C7C0, 0x0002C8E0),
	he_SetTexelOffset(0, -1),
	he_SetImage(2, 0x0002CCC0, 0x0002CDE0),
	he_SetTexelOffset(0, 3),
	he_Loop,
		he_SetImage(60, 0x0002C7C0, 0x0002C8E0),
	he_Restart,
	he_End
};

HudScript HudScript_HandPointDownHeld = {
    he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
	    he_SetImage(60, 0x0002C7C0, 0x0002C8E0),
	he_Restart,
	he_End
};

HudScript HudScript_HandPointLeftLoop = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_SetTexelOffset(0, 0),
		he_SetImage(1, 0x0002CE00, 0x0002CF20),
		he_SetTexelOffset(0, 0),
		he_SetImage(1, 0x0002CE00, 0x0002CF20),
		he_SetTexelOffset(0, 0),
		he_SetImage(1, 0x0002CE00, 0x0002CF20),
		he_SetTexelOffset(0, 0),
		he_SetImage(1, 0x0002CE00, 0x0002CF20),
		he_SetTexelOffset(0, -1),
		he_SetImage(1, 0x0002CF40, 0x0002D060),
		he_SetTexelOffset(0, -1),
		he_SetImage(1, 0x0002D080, 0x0002D1A0),
		he_SetTexelOffset(1, -3),
		he_SetImage(4, 0x0002D1C0, 0x0002D2E0),
		he_SetTexelOffset(0, 4),
		he_SetImage(1, 0x0002CF40, 0x0002D060),
		he_SetTexelOffset(0, 4),
		he_SetImage(1, 0x0002CE00, 0x0002CF20),
		he_SetTexelOffset(0, 1),
		he_SetImage(14, 0x0002D300, 0x0002D420),
	he_Restart,
	he_End
};

HudScript HudScript_HandPointLeft = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_SetTexelOffset(0, 0),
	he_SetImage(1, 0x0002CE00, 0x0002CF20),
	he_SetTexelOffset(0, -1),
	he_SetImage(1, 0x0002CF40, 0x0002D060),
	he_SetTexelOffset(0, -1),
	he_SetImage(1, 0x0002D080, 0x0002D1A0),
	he_SetTexelOffset(1, -3),
	he_SetImage(4, 0x0002D1C0, 0x0002D2E0),
	he_SetTexelOffset(0, 4),
	he_SetImage(1, 0x0002CF40, 0x0002D060),
	he_SetTexelOffset(0, 4),
	he_SetImage(1, 0x0002CE00, 0x0002CF20),
	he_SetTexelOffset(0, 1),
	he_SetImage(2, 0x0002D300, 0x0002D420),
	he_SetTexelOffset(0, 4),
	he_Loop,
		he_SetImage(60, 0x0002CE00, 0x0002CF20),
	he_Restart,
	he_End
};

HudScript HudScript_HandPointLeftHeld = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_SetImage(60, 0x0002CE00, 0x0002CF20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Present = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000000, 0x00000200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeDone = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000220, 0x00000420),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeBaked = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000440, 0x00000640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakePan = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000660, 0x00000860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeBatter = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000880, 0x00000A80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeBowl = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000AA0, 0x00000CA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeMixed = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000CC0, 0x00000EC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeIcing = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00000EE0, 0x000010E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeBerries = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001100, 0x00001300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Hammer1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002D940, 0x0002DB40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Hammer2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002DB80, 0x0002DD80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Hammer3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002DDC0, 0x0002DFC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Boots1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002E000, 0x0002E200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Boots2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002E240, 0x0002E440),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Boots3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002E480, 0x0002E680),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Items = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002E6C0, 0x0002E8C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HeartPiece = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_SetImage(60, 0x00030CE0, 0x00030E00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Heart = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_SetImage(10, 0x00030A60, 0x00030B80),
		he_SetImage(6, 0x00030BA0, 0x00030CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Coin = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_op_15(00000000),
		he_SetImage(3, 0x0002F5C0, 0x0002F6E0),
		he_SetImage(3, 0x0002F700, 0x0002F820),
		he_SetImage(3, 0x0002FAC0, 0x0002FBE0),
		he_SetImage(3, 0x0002FC00, 0x0002FD20),
		he_SetImage(3, 0x0002FD40, 0x0002FE60),
		he_SetImage(3, 0x0002FE80, 0x0002FFA0),
		he_SetImage(3, 0x0002FFC0, 0x000300E0),
		he_SetImage(3, 0x00030100, 0x00030220),
		he_RandomRestart(100, 70),
		he_op_15(00000001),
		he_SetImage(3, 0x0002F5C0, 0x0002F6E0),
		he_SetImage(2, 0x0002F700, 0x0002F820),
		he_SetImage(1, 0x0002F840, 0x0002F960),
		he_SetImage(1, 0x0002F980, 0x0002FAA0),
		he_SetImage(2, 0x0002FAC0, 0x0002FBE0),
		he_SetImage(3, 0x0002FC00, 0x0002FD20),
		he_SetImage(3, 0x0002FD40, 0x0002FE60),
		he_SetImage(3, 0x0002FE80, 0x0002FFA0),
		he_SetImage(3, 0x0002FFC0, 0x000300E0),
		he_SetImage(3, 0x00030100, 0x00030220),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CoinSparkleA = {
	he_SetTexelOffset(-8, 0),
	he_SetImage(1, 0x00030240, 0x00030260),
	he_SetImage(1, 0x00030280, 0x000302A0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(2, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(1, 0x00030300, 0x00030320),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030340, 0x00030360),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030380, 0x000303A0),
	he_SetImage(16, 0x000303C0, 0x000303E0),
	he_End
};

HudScript HudScript_Item_CoinSparkleB = {
	he_SetTexelOffset(8, 8),
	he_SetImage(1, 0x00030240, 0x00030260),
	he_SetImage(1, 0x00030280, 0x000302A0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(2, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(1, 0x00030300, 0x00030320),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030340, 0x00030360),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030380, 0x000303A0),
	he_SetImage(16, 0x000303C0, 0x000303E0),
	he_End
};

HudScript HudScript_Item_CoinSparkleC = {
	he_SetTexelOffset(-4, 8),
	he_SetImage(1, 0x00030240, 0x00030260),
	he_SetImage(1, 0x00030280, 0x000302A0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(2, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(1, 0x00030300, 0x00030320),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030340, 0x00030360),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030380, 0x000303A0),
	he_SetImage(16, 0x000303C0, 0x000303E0),
	he_End
};

HudScript HudScript_Item_CoinSparkleD = {
	he_SetTexelOffset(6, -6),
	he_SetImage(1, 0x00030240, 0x00030260),
	he_SetImage(1, 0x00030280, 0x000302A0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(2, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(1, 0x00030300, 0x00030320),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030340, 0x00030360),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030380, 0x000303A0),
	he_SetImage(16, 0x000303C0, 0x000303E0),
	he_End
};

HudScript HudScript_Item_CoinSparkleE = {
	he_SetTexelOffset(1, -8),
	he_SetImage(1, 0x00030240, 0x00030260),
	he_SetImage(1, 0x00030280, 0x000302A0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(2, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x000302C0, 0x000302E0),
	he_SetImage(1, 0x00030300, 0x00030320),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030340, 0x00030360),
	he_SetImage(1, 0x000303C0, 0x000303E0),
	he_SetImage(1, 0x00030380, 0x000303A0),
	he_SetImage(16, 0x000303C0, 0x000303E0),
	he_End
};

//TODO unclear how to use he_RandomBranch
HudScript HudScript_Item_CoinSparkleRandom = {
0x00000008, 0x00000005, 0x00000000, 0x00000017, 0x00000005, (s32)HudScript_Item_CoinSparkleA, (s32)HudScript_Item_CoinSparkleB, (s32)HudScript_Item_CoinSparkleC, (s32)HudScript_Item_CoinSparkleD, (s32)HudScript_Item_CoinSparkleE, 0x00000000
};

/*
HudScript HudScript_Item_CoinSparkleRandom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_8x8),
	he_RandomBranch(HudScript_Item_CoinSparkleA, HudScript_Item_CoinSparkleB, HudScript_Item_CoinSparkleC, HudScript_Item_CoinSparkleD, HudScript_Item_CoinSparkleE),
	he_End
};
*/

HudScript HudScript_Item_StarPoint = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_24x24),
	he_Loop,
		he_SetImage(2, 0x00030E20, 0x00030F40),
		he_SetImage(2, 0x00030F60, 0x00031080),
		he_SetImage(2, 0x000310A0, 0x000311C0),
		he_SetImage(2, 0x000311E0, 0x00031300),
		he_SetImage(2, 0x00031320, 0x00031440),
		he_SetImage(2, 0x00031460, 0x00031580),
		he_SetImage(2, 0x000315A0, 0x000316C0),
		he_SetImage(2, 0x000316E0, 0x00031800),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SmallStarPoint = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_8x8),
	he_Loop,
		he_SetImage(2, 0x00031CA0, 0x00031CC0),
		he_SetImage(2, 0x00031CE0, 0x00031D00),
		he_SetImage(2, 0x00031D20, 0x00031D40),
		he_SetImage(2, 0x00031D60, 0x00031D80),
		he_SetImage(2, 0x00031DA0, 0x00031DC0),
		he_SetImage(2, 0x00031DE0, 0x00031E00),
		he_SetImage(2, 0x00031E20, 0x00031E40),
		he_SetImage(2, 0x00031E60, 0x00031E80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HeartPoint = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(8, 0x0002E900, 0x0002EB00),
		he_SetImage(5, 0x0002EB20, 0x0002ED20),
		he_SetImage(8, 0x0002ED40, 0x0002EF40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerPoint = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(8, 0x0002EF60, 0x0002F160),
		he_SetImage(5, 0x0002F180, 0x0002F380),
		he_SetImage(8, 0x0002F3A0, 0x0002F5A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StarPiece = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(12, 0x00030400, 0x00030600),
		he_SetImage(4, 0x00030620, 0x00030820),
		he_SetImage(12, 0x00030840, 0x00030A40),
		he_SetImage(4, 0x00030620, 0x00030820),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GearBoots1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001320, 0x00001520),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GearBoots2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001540, 0x00001740),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GearBoots3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001760, 0x00001960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GearHammer1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001980, 0x00001B80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GearHammer2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001BA0, 0x00001DA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GearHammer3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001DC0, 0x00001FC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LuckyStar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00001FE0, 0x000021E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Map = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002200, 0x00002400),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KoopaFortressKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009020, 0x00009220),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RuinsKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009240, 0x00009440),
	he_Restart,
	he_End
};

HudScript HudScript_Item_TubbaCastleKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009460, 0x00009660),
	he_Restart,
	he_End
};

HudScript HudScript_Item_IcePalaceKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009680, 0x00009880),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BowserCastleKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000098A0, 0x00009AA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Dolly = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009AC0, 0x00009CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KooperShell = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009CE0, 0x00009EE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PulseStone = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00009F00, 0x0000A100),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Artifact = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000A120, 0x0000A320),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AncientVase = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000A340, 0x0000A540),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RuinsStonePyramid = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000A560, 0x0000A760),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RuinsStoneStar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000A780, 0x0000A980),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RuinsStoneMoon = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000A9A0, 0x0000ABA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ForestPass = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000ABC0, 0x0000ADC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BooRecordOutline = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000ADE0, 0x0000AFE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BooRecord = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000B000, 0x0000B200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BooWeight = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000B220, 0x0000B420),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BooPortrait = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000B440, 0x0000B640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MysticKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000B660, 0x0000B860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StoreroomKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000B880, 0x0000BA80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ToyboxTrain = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000BAA0, 0x0000BCA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FryingPan = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000BCC0, 0x0000BEC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Dictionary = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000BEE0, 0x0000C0E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MysteryNote = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000C100, 0x0000C300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuspiciousNote = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000C320, 0x0000C520),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Seed1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000C540, 0x0000C740),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Seed2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000C760, 0x0000C960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Seed3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000C980, 0x0000CB80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Seed4 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000CBA0, 0x0000CDA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CrystalBerry = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000CDC0, 0x0000CFC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_WaterStone = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000CFE0, 0x0000D1E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MagicBean = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000D200, 0x0000D400),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FertileSoil = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000D420, 0x0000D620),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MiracleWater = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000D640, 0x0000D840),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UltraStone = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000D860, 0x0000DA60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ToadDoll = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000DAA0, 0x0000DCA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Calculator = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000DCC0, 0x0000DEC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Screwdriver = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000DEE0, 0x0000E0E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CookBook = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000E100, 0x0000E300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JadeRaven = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000E320, 0x0000E520),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SnowmanBucket = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000E540, 0x0000E740),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SnowmanScarf = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000E760, 0x0000E960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RedKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000E980, 0x0000EB80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BlueKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000EBC0, 0x0000EDC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootPackage = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000EDE0, 0x0000EFE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootRedJar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000F000, 0x0000F200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Melody = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000F220, 0x0000F420),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Lyrics = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000F440, 0x0000F640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mailbag = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000F660, 0x0000F860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StarStone = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000F880, 0x0000FA80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SneakyParasol = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000FAA0, 0x0000FCA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PeachKey = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000FCE0, 0x0000FEE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UNK_1DC210 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0000FF00, 0x00010100),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UNK_1DC430 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00010120, 0x00010320),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UNK_1DC650 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00010340, 0x00010540),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UNK_1DC870 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00010560, 0x00010760),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DojoCard1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00010780, 0x00010980),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DojoCard2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000109A0, 0x00010BA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DojoCard3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00010BC0, 0x00010DC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DojoCard4 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00010E00, 0x00011000),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DojoCard5 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011020, 0x00011220),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CrystalBall = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011240, 0x00011440),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GoldCard = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011460, 0x00011660),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SilverCard = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011680, 0x00011880),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootBook = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000118A0, 0x00011AA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootTheTape = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011AC0, 0x00011CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootMerluvleeAutograph = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011CE0, 0x00011EE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootEmptyWallet = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00011F20, 0x00012120),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootLuigiAutograph = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012140, 0x00012340),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootShell = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012360, 0x00012560),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootPhoto = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012580, 0x00012780),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KootGlasses = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000127A0, 0x000129A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Letter = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000129C0, 0x00012BC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Letter_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000129C0, 0x00012BE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_089 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012C00, 0x00012E00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_089_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012C00, 0x00012E20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08A = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012E40, 0x00013040),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08A_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00012E40, 0x00013060),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08B = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013080, 0x00013280),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08B_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013080, 0x000132A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08C = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000132C0, 0x000134C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08C_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000132C0, 0x000134E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08D = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013500, 0x00013700),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08D_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013500, 0x00013720),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08E = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013740, 0x00013940),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08E_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013740, 0x00013960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08F = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013980, 0x00013B80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_08F_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013980, 0x00013BA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PleaseComeBack = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013BC0, 0x00013DC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PleaseComeBack_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013BC0, 0x00013DE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_139 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013E00, 0x00014000),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_139_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00013E00, 0x00014020),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FrightJar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014040, 0x00014240),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FrightJar_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014040, 0x00014260),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mystery = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014280, 0x00014480),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mystery_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014280, 0x000144A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RepelGel = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000144C0, 0x000146C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RepelGel_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000144C0, 0x000146E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_InsecticideHerb = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014700, 0x00014900),
	he_Restart,
	he_End
};

HudScript HudScript_Item_InsecticideHerb_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014700, 0x00014920),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_13E = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014940, 0x00014B40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_13E_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014940, 0x00014B60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_13F = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014B80, 0x00014D80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_13F_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014B80, 0x00014DA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpicySoup = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002420, 0x00002620),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpicySoup_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002420, 0x00002640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ApplePie = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002660, 0x00002860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ApplePie_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002660, 0x00002880),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneyUltra = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000028A0, 0x00002AA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneyUltra_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000028A0, 0x00002AC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleUltra = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002AE0, 0x00002CE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleUltra_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002AE0, 0x00002D00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellyUltra = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002D20, 0x00002F20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellyUltra_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002D20, 0x00002F40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Koopasta = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002F60, 0x00003160),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Koopasta_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00002F60, 0x00003180),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FriedShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000031A0, 0x000033A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FriedShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000031A0, 0x000033C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShroomCake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000033E0, 0x000035E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShroomCake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000033E0, 0x00003600),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShroomSteak = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003620, 0x00003820),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShroomSteak_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003620, 0x00003840),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HotShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003860, 0x00003A60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HotShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003860, 0x00003A80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SweetShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003AA0, 0x00003CA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SweetShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003AA0, 0x00003CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HealthyJuice = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003CE0, 0x00003EE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HealthyJuice_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003CE0, 0x00003F00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BlandMeal = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003F20, 0x00004120),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BlandMeal_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00003F20, 0x00004140),
	he_Restart,
	he_End
};

HudScript HudScript_Item_YummyMeal = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004160, 0x00004360),
	he_Restart,
	he_End
};

HudScript HudScript_Item_YummyMeal_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004160, 0x00004380),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DeluxeFeast = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000043A0, 0x000045A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DeluxeFeast_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000043A0, 0x000045C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpecialShake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000045E0, 0x000047E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpecialShake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000045E0, 0x00004800),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BigCookie = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004820, 0x00004A20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BigCookie_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004820, 0x00004A40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Cake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004A60, 0x00004C60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Cake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004A60, 0x00004C80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mistake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004CA0, 0x00004EA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mistake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004CA0, 0x00004EC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KoopaTea = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004EE0, 0x000050E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KoopaTea_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00004EE0, 0x00005100),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneySuper = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005120, 0x00005320),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneySuper_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005120, 0x00005340),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleSuper = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005360, 0x00005560),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleSuper_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005360, 0x00005580),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellySuper = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000055A0, 0x000057A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellySuper_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000055A0, 0x000057C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Spaghetti = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000057E0, 0x000059E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Spaghetti_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000057E0, 0x00005A00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_EggMissile = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005A20, 0x00005C20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_EggMissile_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005A20, 0x00005C40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FriedEgg = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005C60, 0x00005E60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FriedEgg_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005C60, 0x00005E80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneyShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005EA0, 0x000060A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneyShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00005EA0, 0x000060C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneyCandy = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000060E0, 0x000062E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneyCandy_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000060E0, 0x00006300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ElectroPop = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006320, 0x00006520),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ElectroPop_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006320, 0x00006540),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FirePop = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006560, 0x00006760),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FirePop_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006560, 0x00006780),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LimeCandy = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000067A0, 0x000069A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LimeCandy_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000067A0, 0x000069C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CocoPop = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000069E0, 0x00006BE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CocoPop_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000069E0, 0x00006C00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LemonCandy = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006C20, 0x00006E20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LemonCandy_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006C20, 0x00006E40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellyPop = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006E60, 0x00007060),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellyPop_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00006E60, 0x00007080),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StrangeCake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000070A0, 0x000072A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StrangeCake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000070A0, 0x000072C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KookyCookie = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000072E0, 0x000074E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KookyCookie_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000072E0, 0x00007500),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FrozenFries = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007520, 0x00007720),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FrozenFries_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007520, 0x00007740),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PotatoSalad = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007760, 0x00007960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PotatoSalad_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007760, 0x00007980),
	he_Restart,
	he_End
};

HudScript HudScript_Item_NuttyCake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000079A0, 0x00007BA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_NuttyCake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000079A0, 0x00007BC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007BE0, 0x00007DE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007BE0, 0x00007E00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BoiledEgg = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007E20, 0x00008020),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BoiledEgg_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00007E20, 0x00008040),
	he_Restart,
	he_End
};

HudScript HudScript_Item_YoshiCookie = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008060, 0x00008260),
	he_Restart,
	he_End
};

HudScript HudScript_Item_YoshiCookie_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008060, 0x00008280),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellyShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000082A0, 0x000084A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JellyShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000082A0, 0x000084C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02C = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000084E0, 0x000086E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02C_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000084E0, 0x00008700),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02D = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008720, 0x00008920),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02D_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008720, 0x00008940),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02E = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008960, 0x00008B60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02E_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008960, 0x00008B80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02F = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008BA0, 0x00008DA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_02F_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008BA0, 0x00008DC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_030 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008DE0, 0x00008FE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_030_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00008DE0, 0x00009000),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpinSmash = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014DC0, 0x00014FC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpinSmash_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00014DC0, 0x00014FE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Multibounce = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015000, 0x00015200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Multibounce_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015000, 0x00015220),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerPlus = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015240, 0x00015440),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerPlus_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015240, 0x00015460),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DodgeMaster = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015480, 0x00015680),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DodgeMaster_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015480, 0x000156A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerBounce = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000156C0, 0x000158C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerBounce_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000156C0, 0x000158E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpikeShield = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015900, 0x00015B00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpikeShield_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015900, 0x00015B20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FirstAttack = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015B40, 0x00015D40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FirstAttack_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015B40, 0x00015D60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HPPlus = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015D80, 0x00015F80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HPPlus_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015D80, 0x00015FA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_QuakeHammer = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015FC0, 0x000161C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_QuakeHammer_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00015FC0, 0x000161E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DoubleDip = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016200, 0x00016400),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DoubleDip_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016200, 0x00016420),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerQuake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016440, 0x00016640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerQuake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016440, 0x00016660),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaQuake = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016680, 0x00016880),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaQuake_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016680, 0x000168A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SleepStomp = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000168C0, 0x00016AC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SleepStomp_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000168C0, 0x00016AE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SmashCharge = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016B00, 0x00016D00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SmashCharge_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016B00, 0x00016D20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SSmashChg = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016D40, 0x00016F40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SSmashChg_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016D40, 0x00016F60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AutoSmash = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016F80, 0x00017180),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AutoSmash_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00016F80, 0x000171A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FireShield = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000171C0, 0x000173C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FireShield_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000171C0, 0x000173E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JumpCharge = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017400, 0x00017600),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JumpCharge_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017400, 0x00017620),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SJumpChg = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017640, 0x00017840),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SJumpChg_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017640, 0x00017860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AutoJump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017880, 0x00017A80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AutoJump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017880, 0x00017AA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DDownPound = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017AC0, 0x00017CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DDownPound_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017AC0, 0x00017CE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AutoMultibounce = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017D00, 0x00017F00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AutoMultibounce_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017D00, 0x00017F20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DizzyStomp = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017F40, 0x00018140),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DizzyStomp_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00017F40, 0x00018160),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HammerThrow = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018180, 0x00018380),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HammerThrow_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018180, 0x000183A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SmashCharge0 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000183C0, 0x000185C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SmashCharge0_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000183C0, 0x000185E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PrettyLucky = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018600, 0x00018800),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PrettyLucky_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018600, 0x00018820),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FeelingFine = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018840, 0x00018A40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FeelingFine_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018840, 0x00018A60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXA = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018A80, 0x00018C80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXA_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018A80, 0x00018CA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AllorNothing = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018CC0, 0x00018EC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AllorNothing_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018CC0, 0x00018EE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HPDrain = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018F00, 0x00019100),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HPDrain_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00018F00, 0x00019120),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JumpCharge0 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019140, 0x00019340),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JumpCharge0_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019140, 0x00019360),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SlowGo = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019380, 0x00019580),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SlowGo_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019380, 0x000195A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FPPlus = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000195C0, 0x000197C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FPPlus_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000195C0, 0x000197E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaRush = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019800, 0x00019A00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaRush_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019800, 0x00019A20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_IcePower = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019A40, 0x00019C40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_IcePower_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019A40, 0x00019C60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DefendPlus = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019C80, 0x00019E80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DefendPlus_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019C80, 0x00019EA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PayOff = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019EC0, 0x0001A0C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PayOff_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00019EC0, 0x0001A0E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MoneyMoney = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A100, 0x0001A300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MoneyMoney_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A100, 0x0001A320),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ChillOut = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A340, 0x0001A540),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ChillOut_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A340, 0x0001A560),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HappyHeart = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A580, 0x0001A780),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HappyHeart_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A580, 0x0001A7A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ZapTap = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A7C0, 0x0001A9C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ZapTap_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001A7C0, 0x0001A9E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Berserker = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001AA00, 0x0001AC00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Berserker_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001AA00, 0x0001AC20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RightOn = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001AC40, 0x0001AE40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RightOn_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001AC40, 0x0001AE60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RunawayPay = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001AE80, 0x0001B080),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RunawayPay_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001AE80, 0x0001B0A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Refund = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B0C0, 0x0001B2C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Refund_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B0C0, 0x0001B2E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerSaver = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B300, 0x0001B500),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerSaver_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B300, 0x0001B520),
	he_Restart,
	he_End
};

HudScript HudScript_Item_TripleDip = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B540, 0x0001B740),
	he_Restart,
	he_End
};

HudScript HudScript_Item_TripleDip_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B540, 0x0001B760),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerFanatic = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B780, 0x0001B980),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerFanatic_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B780, 0x0001B9A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerJump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B9C0, 0x0001BBC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerJump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001B9C0, 0x0001BBE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperJump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001BC00, 0x0001BE00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperJump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001BC00, 0x0001BE20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaJump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001BE40, 0x0001C040),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaJump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001BE40, 0x0001C060),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerSmash1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C080, 0x0001C280),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerSmash1_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C080, 0x0001C2A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperSmash = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C2C0, 0x0001C4C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperSmash_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C2C0, 0x0001C4E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaSmash = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C500, 0x0001C700),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaSmash_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C500, 0x0001C720),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LuckyDay = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C740, 0x0001C940),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LuckyDay_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C740, 0x0001C960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaHPDrain = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C980, 0x0001CB80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MegaHPDrain_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001C980, 0x0001CBA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BumpAttack = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001CBC0, 0x0001CDC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BumpAttack_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001CBC0, 0x0001CDE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PUpDDown = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001CE00, 0x0001D000),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PUpDDown_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001CE00, 0x0001D020),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PDownDUp = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D040, 0x0001D240),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PDownDUp_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D040, 0x0001D260),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HeartFinder = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D280, 0x0001D480),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HeartFinder_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D280, 0x0001D4A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerFinder = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D4C0, 0x0001D6C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FlowerFinder_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D4C0, 0x0001D6E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DizzyAttack = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D700, 0x0001D900),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DizzyAttack_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D700, 0x0001D920),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpeedySpin = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D940, 0x0001DB40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpeedySpin_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001D940, 0x0001DB60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpinAttack = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001DB80, 0x0001DD80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SpinAttack_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001DB80, 0x0001DDA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ISpy = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001DDC0, 0x0001DFC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ISpy_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001DDC0, 0x0001DFE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerRush = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E000, 0x0001E200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerRush_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E000, 0x0001E220),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LastStand = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E240, 0x0001E440),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LastStand_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E240, 0x0001E460),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CloseCall = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E480, 0x0001E680),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CloseCall_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E480, 0x0001E6A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CrazyHeart = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E6C0, 0x0001E8C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CrazyHeart_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E6C0, 0x0001E8E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0D5 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E900, 0x0001EB00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0D5_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001E900, 0x0001EB20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0D6 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001EB40, 0x0001ED40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0D6_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001EB40, 0x0001ED60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0D7 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001ED80, 0x0001EF80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0D7_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001ED80, 0x0001EFA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShrinkSmash = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001EFC0, 0x0001F1C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShrinkSmash_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001EFC0, 0x0001F1E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShrinkStomp = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F200, 0x0001F400),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShrinkStomp_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F200, 0x0001F420),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DDownJump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F440, 0x0001F640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DDownJump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F440, 0x0001F660),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DamageDodge = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F680, 0x0001F880),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DamageDodge_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F680, 0x0001F8A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_EarthquakeJump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F8C0, 0x0001FAC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_EarthquakeJump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001F8C0, 0x0001FAE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HappyFlower = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001FB00, 0x0001FD00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HappyFlower_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001FB00, 0x0001FD20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0DE = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001FD40, 0x0001FF40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0DE_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001FD40, 0x0001FF60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0DF = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001FF80, 0x00020180),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0DF_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0001FF80, 0x000201A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DeepFocus3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000201C0, 0x000203C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DeepFocus3_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000201C0, 0x000203E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperFocus = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020400, 0x00020600),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperFocus_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020400, 0x00020620),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Kaiden = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020640, 0x00020840),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Kaiden_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020640, 0x00020860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_QuickChange = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020880, 0x00020A80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_QuickChange_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020880, 0x00020AA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E4 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020AC0, 0x00020CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E4_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020AC0, 0x00020CE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E5 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020D00, 0x00020F00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E5_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020D00, 0x00020F20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E6 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020F40, 0x00021140),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E6_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00020F40, 0x00021160),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E7 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021180, 0x00021380),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0E7_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021180, 0x000213A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Peekaboo = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000213C0, 0x000215C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Peekaboo_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000213C0, 0x000215E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GroupFocus = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021600, 0x00021800),
	he_Restart,
	he_End
};

HudScript HudScript_Item_GroupFocus_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021600, 0x00021820),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXD = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021840, 0x00021A40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXD_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021840, 0x00021A60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXB = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021A80, 0x00021C80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXB_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021A80, 0x00021CA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXE = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021CC0, 0x00021EC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXE_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021CC0, 0x00021EE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXC = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021F00, 0x00022100),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXC_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00021F00, 0x00022120),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXF = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022140, 0x00022340),
	he_Restart,
	he_End
};

HudScript HudScript_Item_AttackFXF_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022140, 0x00022360),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0EF = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022380, 0x00022580),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0EF_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022380, 0x000225A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HealthyHealthy = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000225C0, 0x000227C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HealthyHealthy_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000225C0, 0x000227E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F1 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022800, 0x00022A00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F1_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022800, 0x00022A20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F2 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022A40, 0x00022C40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F2_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022A40, 0x00022C60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F3 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022C80, 0x00022E80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F3_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022C80, 0x00022EA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F4 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022EC0, 0x000230C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F4_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00022EC0, 0x000230E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F5 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023100, 0x00023300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F5_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023100, 0x00023320),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F6 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023340, 0x00023540),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F6_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023340, 0x00023560),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F7 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023580, 0x00023780),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_0F7_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023580, 0x000237A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FireFlower = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A3C0, 0x0002A5C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_FireFlower_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A3C0, 0x0002A5E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SnowmanDoll = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A600, 0x0002A800),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SnowmanDoll_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A600, 0x0002A820),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ThunderRage = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A840, 0x0002AA40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ThunderRage_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A840, 0x0002AA60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ThunderBolt = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002AA80, 0x0002AC80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ThunderBolt_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002AA80, 0x0002ACA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShootingStar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002ACC0, 0x0002AEC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ShootingStar_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002ACC0, 0x0002AEE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DustyHammer = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002AF00, 0x0002B100),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DustyHammer_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002AF00, 0x0002B120),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Pebble = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B140, 0x0002B340),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Pebble_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B140, 0x0002B360),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_127 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B380, 0x0002B580),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_127_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B380, 0x0002B5A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StoneCap = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B5C0, 0x0002B7C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StoneCap_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B5C0, 0x0002B7E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_VoltShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B800, 0x0002BA00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_VoltShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002B800, 0x0002BA20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerStar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002BA40, 0x0002BC40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_PowerStar_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002BA40, 0x0002BC60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Parasol = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002BC80, 0x0002BE80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Parasol_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002BC80, 0x0002BEA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MagicMirror = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002BEC0, 0x0002C0C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MagicMirror_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002BEC0, 0x0002C0E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_12D = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002C100, 0x0002C300),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_12D_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002C100, 0x0002C320),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_12E = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002C340, 0x0002C540),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_12E_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002C340, 0x0002C560),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_12F = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002C580, 0x0002C780),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_12F_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002C580, 0x0002C7A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mushroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000237C0, 0x000239C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Mushroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000237C0, 0x000239E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023A00, 0x00023C00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023A00, 0x00023C20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UltraShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023C40, 0x00023E40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_UltraShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023C40, 0x00023E60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LifeShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023E80, 0x00024080),
	he_Restart,
	he_End
};

HudScript HudScript_Item_LifeShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00023E80, 0x000240A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DriedShroom = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000240C0, 0x000242C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DriedShroom_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000240C0, 0x000242E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_TastyTonic = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024300, 0x00024500),
	he_Restart,
	he_End
};

HudScript HudScript_Item_TastyTonic_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024300, 0x00024520),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperSoda = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024540, 0x00024740),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SuperSoda_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024540, 0x00024760),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BlueBerry = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024780, 0x00024980),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BlueBerry_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024780, 0x000249A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RedBerry = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000249C0, 0x00024BC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_RedBerry_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000249C0, 0x00024BE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_YellowBerry = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024C00, 0x00024E00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_YellowBerry_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024C00, 0x00024E20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BubbleBerry = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024E40, 0x00025040),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BubbleBerry_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00024E40, 0x00025060),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Goomnut = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025080, 0x00025280),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Goomnut_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025080, 0x000252A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KoopaLeaf = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000252C0, 0x000254C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_KoopaLeaf_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000252C0, 0x000254E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DriedPasta = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025500, 0x00025700),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DriedPasta_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025500, 0x00025720),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Lime = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025740, 0x00025940),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Lime_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025740, 0x00025960),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Lemon = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025980, 0x00025B80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Lemon_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025980, 0x00025BA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DriedFruit = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025BC0, 0x00025DC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DriedFruit_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025BC0, 0x00025DE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StrangeLeaf = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025E00, 0x00026000),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StrangeLeaf_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00025E00, 0x00026020),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeMix = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026040, 0x00026240),
	he_Restart,
	he_End
};

HudScript HudScript_Item_CakeMix_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026040, 0x00026260),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Egg = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026280, 0x00026480),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Egg_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026280, 0x000264A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Coconut = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000264C0, 0x000266C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Coconut_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000264C0, 0x000266E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Melon = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026700, 0x00026900),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Melon_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026700, 0x00026920),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StinkyHerb = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026940, 0x00026B40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StinkyHerb_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026940, 0x00026B60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_IcedPotato = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026B80, 0x00026D80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_IcedPotato_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026B80, 0x00026DA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneySyrup = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026DC0, 0x00026FC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HoneySyrup_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00026DC0, 0x00026FE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleSyrup = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027000, 0x00027200),
	he_Restart,
	he_End
};

HudScript HudScript_Item_MapleSyrup_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027000, 0x00027220),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JamminJelly = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027240, 0x00027440),
	he_Restart,
	he_End
};

HudScript HudScript_Item_JamminJelly_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027240, 0x00027460),
	he_Restart,
	he_End
};

HudScript HudScript_Item_WhackasBump = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027480, 0x00027680),
	he_Restart,
	he_End
};

HudScript HudScript_Item_WhackasBump_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027480, 0x000276A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Apple = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000276C0, 0x000278C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_Apple_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000276C0, 0x000278E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingSalt = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027900, 0x00027B00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingSalt_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027900, 0x00027B20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingSugar = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027B40, 0x00027D40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingSugar_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027B40, 0x00027D60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingEgg = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027D80, 0x00027F80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingEgg_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027D80, 0x00027FA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingCream = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027FC0, 0x000281C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingCream_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00027FC0, 0x000281E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingStrawberry = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028200, 0x00028400),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingStrawberry_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028200, 0x00028420),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingButter = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028440, 0x00028640),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingButter_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028440, 0x00028660),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingCleanser = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028680, 0x00028880),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingCleanser_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028680, 0x000288A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingWater = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000288C0, 0x00028AC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingWater_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000288C0, 0x00028AE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingFlour = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028B00, 0x00028D00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingFlour_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028B00, 0x00028D20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingMilk = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028D40, 0x00028F40),
	he_Restart,
	he_End
};

HudScript HudScript_Item_BakingMilk_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028D40, 0x00028F60),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_11F = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028F80, 0x00029180),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_11F_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00028F80, 0x000291A0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SleepySheep = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000291C0, 0x000293C0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_SleepySheep_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x000291C0, 0x000293E0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_XBandage = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029400, 0x00029600),
	he_Restart,
	he_End
};

HudScript HudScript_Item_XBandage_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029400, 0x00029620),
	he_Restart,
	he_End
};

HudScript HudScript_Item_POWBlock = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029640, 0x00029840),
	he_Restart,
	he_End
};

HudScript HudScript_Item_POWBlock_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029640, 0x00029860),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HustleDrink = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029880, 0x00029A80),
	he_Restart,
	he_End
};

HudScript HudScript_Item_HustleDrink_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029880, 0x00029AA0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StopWatch = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029AC0, 0x00029CC0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_StopWatch_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029AC0, 0x00029CE0),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DizzyDial = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029D00, 0x00029F00),
	he_Restart,
	he_End
};

HudScript HudScript_Item_DizzyDial_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029D00, 0x00029F20),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_136 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029F40, 0x0002A140),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_136_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x00029F40, 0x0002A160),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_137 = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A180, 0x0002A380),
	he_Restart,
	he_End
};

HudScript HudScript_Item_ITEM_137_disabled = {
	he_SetVisible,
	he_SetTileSize(HUD_ELEMENT_SIZE_32x32),
	he_Loop,
		he_SetImage(60, 0x0002A180, 0x0002A3A0),
	he_Restart,
	he_End
};

//TODO padding
s32 pad_after_item_hudscripts[] = {
    0x00000000, 0x00000000
};

ItemData gItemTable[] = {
{	// item 0: Nothing
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x140,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1: Jump
	.nameMsg = MESSAGE_ID(0x26, 0x0A0),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x38,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2: SpinJump
	.nameMsg = MESSAGE_ID(0x26, 0x0A1),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x39,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3: TornadoJump
	.nameMsg = MESSAGE_ID(0x26, 0x0A2),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x3A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4: Hammer
	.nameMsg = MESSAGE_ID(0x26, 0x0A3),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x3B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5: SuperHammer
	.nameMsg = MESSAGE_ID(0x26, 0x0A4),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x3C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6: UltraHammer
	.nameMsg = MESSAGE_ID(0x26, 0x0A5),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x3D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7: LuckyStar
	.nameMsg = MESSAGE_ID(0x26, 0x0A6),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0A6),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A6),
	.sellValue = -1,
	.hudElemID = 0x3E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 8: Map
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x140,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 9: BigMap
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x140,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_GEAR | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item A: FirstDegreeCard
	.nameMsg = MESSAGE_ID(0x26, 0x0E2),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E2),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E2),
	.sellValue = -1,
	.hudElemID = 0x78,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item B: SecondDegreeCard
	.nameMsg = MESSAGE_ID(0x26, 0x0E3),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E3),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E3),
	.sellValue = -1,
	.hudElemID = 0x79,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item C: ThirdDegreeCard
	.nameMsg = MESSAGE_ID(0x26, 0x0E4),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E4),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E4),
	.sellValue = -1,
	.hudElemID = 0x7A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item D: FourthDegreeCard
	.nameMsg = MESSAGE_ID(0x26, 0x0E5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E5),
	.sellValue = -1,
	.hudElemID = 0x7B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E: Diploma
	.nameMsg = MESSAGE_ID(0x26, 0x0E6),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E6),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E6),
	.sellValue = -1,
	.hudElemID = 0x7C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F: UltraStone
	.nameMsg = MESSAGE_ID(0x26, 0x0E7),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E7),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E7),
	.sellValue = -1,
	.hudElemID = 0x62,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2,
	.typeFlags = ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10: KoopaFortressKey
	.nameMsg = MESSAGE_ID(0x26, 0x0A7),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0A7),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A7),
	.sellValue = -1,
	.hudElemID = 0x40,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11: RuinsKey
	.nameMsg = MESSAGE_ID(0x26, 0x0A8),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0A8),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A8),
	.sellValue = -1,
	.hudElemID = 0x41,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12: PulseStone
	.nameMsg = MESSAGE_ID(0x26, 0x0B0),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B0),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B0),
	.sellValue = -1,
	.hudElemID = 0x47,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13: TubbaCastleKey
	.nameMsg = MESSAGE_ID(0x26, 0x0A9),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0A9),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A9),
	.sellValue = -1,
	.hudElemID = 0x42,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14: CrystalPalaceKey
	.nameMsg = MESSAGE_ID(0x26, 0x0AA),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AA),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AA),
	.sellValue = -1,
	.hudElemID = 0x43,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15: LunarStone
	.nameMsg = MESSAGE_ID(0x26, 0x0B3),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B3),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B3),
	.sellValue = -1,
	.hudElemID = 0x4C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 16: PyramidStone
	.nameMsg = MESSAGE_ID(0x26, 0x0B4),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B4),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B4),
	.sellValue = -1,
	.hudElemID = 0x4A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 17: DiamondStone
	.nameMsg = MESSAGE_ID(0x26, 0x0B5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B5),
	.sellValue = -1,
	.hudElemID = 0x4B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 18: VolcanoVase
	.nameMsg = MESSAGE_ID(0x26, 0x0B2),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B2),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B2),
	.sellValue = -1,
	.hudElemID = 0x49,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 19: KooperShell
	.nameMsg = MESSAGE_ID(0x26, 0x0AF),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AF),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AF),
	.sellValue = -1,
	.hudElemID = 0x46,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1A: BowserCastleKey
	.nameMsg = MESSAGE_ID(0x26, 0x0AB),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AB),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AB),
	.sellValue = -1,
	.hudElemID = 0x44,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1B: ForestPass
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x4D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1C: BooWeight
	.nameMsg = MESSAGE_ID(0x26, 0x0B7),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B7),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B7),
	.sellValue = -1,
	.hudElemID = 0x50,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1D: BooPortrait
	.nameMsg = MESSAGE_ID(0x26, 0x0B8),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B8),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B8),
	.sellValue = -1,
	.hudElemID = 0x51,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1E: CrystalBerry
	.nameMsg = MESSAGE_ID(0x26, 0x0C4),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C4),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C4),
	.sellValue = -1,
	.hudElemID = 0x5D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 1F: MysticalKey
	.nameMsg = MESSAGE_ID(0x26, 0x0B9),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B9),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B9),
	.sellValue = -1,
	.hudElemID = 0x52,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 20: StoreroomKey
	.nameMsg = MESSAGE_ID(0x26, 0x0BA),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0BA),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0BA),
	.sellValue = -1,
	.hudElemID = 0x53,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 21: ToyTrain
	.nameMsg = MESSAGE_ID(0x26, 0x0BB),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0BB),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0BB),
	.sellValue = -1,
	.hudElemID = 0x54,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 22: BooRecord
	.nameMsg = MESSAGE_ID(0x26, 0x0B6),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B6),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B6),
	.sellValue = -1,
	.hudElemID = 0x4F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 23: FryingPan
	.nameMsg = MESSAGE_ID(0x26, 0x0BC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0BC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0BC),
	.sellValue = -1,
	.hudElemID = 0x55,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 24: Dictionary
	.nameMsg = MESSAGE_ID(0x26, 0x0BD),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0BD),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0BD),
	.sellValue = -1,
	.hudElemID = 0x56,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 25: MysteryNote
	.nameMsg = MESSAGE_ID(0x26, 0x0BE),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0BE),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0BE),
	.sellValue = -1,
	.hudElemID = 0x57,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 26: SuspiciousNote
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x58,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 27: CrystalBall
	.nameMsg = MESSAGE_ID(0x26, 0x0C9),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C9),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C9),
	.sellValue = -1,
	.hudElemID = 0x7D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 28: Screwdriver
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x65,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 29: Cookbook
	.nameMsg = MESSAGE_ID(0x26, 0x0CB),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0CB),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0CB),
	.sellValue = -1,
	.hudElemID = 0x66,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2A: JadeRaven
	.nameMsg = MESSAGE_ID(0x26, 0x0CC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0CC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0CC),
	.sellValue = -1,
	.hudElemID = 0x67,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2B: MagicalSeed1
	.nameMsg = MESSAGE_ID(0x26, 0x0C0),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C0),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C0),
	.sellValue = -1,
	.hudElemID = 0x59,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2C: MagicalSeed2
	.nameMsg = MESSAGE_ID(0x26, 0x0C1),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C1),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C1),
	.sellValue = -1,
	.hudElemID = 0x5A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2D: MagicalSeed3
	.nameMsg = MESSAGE_ID(0x26, 0x0C2),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C2),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C2),
	.sellValue = -1,
	.hudElemID = 0x5B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2E: MagicalSeed4
	.nameMsg = MESSAGE_ID(0x26, 0x0C3),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C3),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C3),
	.sellValue = -1,
	.hudElemID = 0x5C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 2F: ToadDoll
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x63,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 30: Calculator
	.nameMsg = MESSAGE_ID(0x26, 0x0CA),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0CA),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0CA),
	.sellValue = -1,
	.hudElemID = 0x64,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 31: SnowmanBucket
	.nameMsg = MESSAGE_ID(0x26, 0x0CF),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0CF),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0CF),
	.sellValue = -1,
	.hudElemID = 0x68,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 32: SnowmanScarf
	.nameMsg = MESSAGE_ID(0x26, 0x0D0),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D0),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D0),
	.sellValue = -1,
	.hudElemID = 0x69,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 33: RedKey
	.nameMsg = MESSAGE_ID(0x26, 0x0D2),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D2),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D2),
	.sellValue = -1,
	.hudElemID = 0x6A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 34: BlueKey
	.nameMsg = MESSAGE_ID(0x26, 0x0D3),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D3),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D3),
	.sellValue = -1,
	.hudElemID = 0x6B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 35: UnusedLetter01
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 36: Letter01
	.nameMsg = MESSAGE_ID(0x26, 0x0EB),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0EB),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0EB),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 37: Letter02
	.nameMsg = MESSAGE_ID(0x26, 0x0EC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0EC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0EC),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 38: Letter03
	.nameMsg = MESSAGE_ID(0x26, 0x0ED),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0ED),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0ED),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 39: Letter04
	.nameMsg = MESSAGE_ID(0x26, 0x0EE),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0EE),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0EE),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3A: Letter05
	.nameMsg = MESSAGE_ID(0x26, 0x0EF),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0EF),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0EF),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3B: Letter06
	.nameMsg = MESSAGE_ID(0x26, 0x0F0),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F0),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F0),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3C: Letter07
	.nameMsg = MESSAGE_ID(0x26, 0x0F1),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F1),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F1),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3D: Letter08
	.nameMsg = MESSAGE_ID(0x26, 0x0F2),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F2),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F2),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3E: Letter09
	.nameMsg = MESSAGE_ID(0x26, 0x0F3),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F3),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F3),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 3F: UnusedLetter02
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 40: Letter10
	.nameMsg = MESSAGE_ID(0x26, 0x0F4),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F4),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F4),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 41: Letter11
	.nameMsg = MESSAGE_ID(0x26, 0x0F5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F5),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 42: UnusedLetter03
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 43: UnusedLetter04
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 44: UnusedLetter05
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 45: Letter12
	.nameMsg = MESSAGE_ID(0x26, 0x0F6),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F6),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F6),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 46: Letter13
	.nameMsg = MESSAGE_ID(0x26, 0x0F7),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F7),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F7),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 47: Letter14
	.nameMsg = MESSAGE_ID(0x26, 0x0F8),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F8),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F8),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 48: Letter15
	.nameMsg = MESSAGE_ID(0x26, 0x0F9),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0F9),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0F9),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 49: Letter16
	.nameMsg = MESSAGE_ID(0x26, 0x0FA),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0FA),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0FA),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4A: Letter17
	.nameMsg = MESSAGE_ID(0x26, 0x0FB),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0FB),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0FB),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4B: Letter18
	.nameMsg = MESSAGE_ID(0x26, 0x0FC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0FC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0FC),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4C: Letter19
	.nameMsg = MESSAGE_ID(0x26, 0x0FD),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0FD),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0FD),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4D: UnusedLetter06
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4E: Letter20
	.nameMsg = MESSAGE_ID(0x26, 0x0FE),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0FE),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0FE),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 4F: Letter21
	.nameMsg = MESSAGE_ID(0x26, 0x0FF),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0FF),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0FF),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 50: Letter22
	.nameMsg = MESSAGE_ID(0x26, 0x100),
	.fullDescMsg = MESSAGE_ID(0x25, 0x100),
	.shortDescMsg = MESSAGE_ID(0x23, 0x100),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 51: Letter23
	.nameMsg = MESSAGE_ID(0x26, 0x101),
	.fullDescMsg = MESSAGE_ID(0x25, 0x101),
	.shortDescMsg = MESSAGE_ID(0x23, 0x101),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 52: Letter24
	.nameMsg = MESSAGE_ID(0x26, 0x102),
	.fullDescMsg = MESSAGE_ID(0x25, 0x102),
	.shortDescMsg = MESSAGE_ID(0x23, 0x102),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 53: Artifact
	.nameMsg = MESSAGE_ID(0x26, 0x0B1),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0B1),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0B1),
	.sellValue = -1,
	.hudElemID = 0x48,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 54: Letter25
	.nameMsg = MESSAGE_ID(0x26, 0x0EA),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0EA),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0EA),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 55: UnusedLetter07
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x88,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 56: Dolly
	.nameMsg = MESSAGE_ID(0x26, 0x0AE),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AE),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AE),
	.sellValue = -1,
	.hudElemID = 0x45,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 57: WaterStone
	.nameMsg = MESSAGE_ID(0x26, 0x0C5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C5),
	.sellValue = -1,
	.hudElemID = 0x5E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 58: MagicalBean
	.nameMsg = MESSAGE_ID(0x26, 0x0C6),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C6),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C6),
	.sellValue = -1,
	.hudElemID = 0x5F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 59: FertileSoil
	.nameMsg = MESSAGE_ID(0x26, 0x0C7),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C7),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C7),
	.sellValue = -1,
	.hudElemID = 0x60,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5A: MiracleWater
	.nameMsg = MESSAGE_ID(0x26, 0x0C8),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0C8),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0C8),
	.sellValue = -1,
	.hudElemID = 0x61,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5B: VolcanoVase
	.nameMsg = MESSAGE_ID(0x26, 0x0CD),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0CD),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0CD),
	.sellValue = -1,
	.hudElemID = 0x49,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5C: KootTheTape
	.nameMsg = MESSAGE_ID(0x26, 0x104),
	.fullDescMsg = MESSAGE_ID(0x25, 0x104),
	.shortDescMsg = MESSAGE_ID(0x23, 0x104),
	.sellValue = -1,
	.hudElemID = 0x81,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5D: BakingSugar
	.nameMsg = MESSAGE_ID(0x26, 0x0D8),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D8),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D8),
	.sellValue = -1,
	.hudElemID = 0x116,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5E: BakingSalt
	.nameMsg = MESSAGE_ID(0x26, 0x0D9),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D9),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D9),
	.sellValue = -1,
	.hudElemID = 0x115,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 5F: BakingEgg
	.nameMsg = MESSAGE_ID(0x26, 0x0DA),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0DA),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0DA),
	.sellValue = -1,
	.hudElemID = 0x117,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 60: BakingCream
	.nameMsg = MESSAGE_ID(0x26, 0x0DB),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0DB),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0DB),
	.sellValue = -1,
	.hudElemID = 0x118,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 61: BakingStrawberry
	.nameMsg = MESSAGE_ID(0x26, 0x0DC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0DC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0DC),
	.sellValue = -1,
	.hudElemID = 0x119,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 62: BakingButter
	.nameMsg = MESSAGE_ID(0x26, 0x0DD),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0DD),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0DD),
	.sellValue = -1,
	.hudElemID = 0x11A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 63: BakingCleanser
	.nameMsg = MESSAGE_ID(0x26, 0x0DE),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0DE),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0DE),
	.sellValue = -1,
	.hudElemID = 0x11B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 64: BakingWater
	.nameMsg = MESSAGE_ID(0x26, 0x0DF),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0DF),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0DF),
	.sellValue = -1,
	.hudElemID = 0x11C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 65: BakingFlour
	.nameMsg = MESSAGE_ID(0x26, 0x0E0),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E0),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E0),
	.sellValue = -1,
	.hudElemID = 0x11D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 66: BakingMilk
	.nameMsg = MESSAGE_ID(0x26, 0x0E1),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E1),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E1),
	.sellValue = -1,
	.hudElemID = 0x11E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 67: Lyrics
	.nameMsg = MESSAGE_ID(0x26, 0x0D6),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D6),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D6),
	.sellValue = -1,
	.hudElemID = 0x6F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 68: Melody
	.nameMsg = MESSAGE_ID(0x26, 0x0D7),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D7),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D7),
	.sellValue = -1,
	.hudElemID = 0x6E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 69: Mailbag
	.nameMsg = MESSAGE_ID(0x26, 0x0BF),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0BF),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0BF),
	.sellValue = -1,
	.hudElemID = 0x70,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6A: PeachKey1
	.nameMsg = MESSAGE_ID(0x26, 0x0AC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AC),
	.sellValue = -1,
	.hudElemID = 0x73,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6B: OddKey
	.nameMsg = MESSAGE_ID(0x26, 0x0AD),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AD),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AD),
	.sellValue = -1,
	.hudElemID = 0x53,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6C: StarStone
	.nameMsg = MESSAGE_ID(0x26, 0x0D1),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D1),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D1),
	.sellValue = -1,
	.hudElemID = 0x71,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6D: SneakyParasol
	.nameMsg = MESSAGE_ID(0x26, 0x0D4),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D4),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D4),
	.sellValue = -1,
	.hudElemID = 0x72,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6E: KootKoopaLegends
	.nameMsg = MESSAGE_ID(0x26, 0x103),
	.fullDescMsg = MESSAGE_ID(0x25, 0x103),
	.shortDescMsg = MESSAGE_ID(0x23, 0x103),
	.sellValue = -1,
	.hudElemID = 0x80,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 6F: KootLuigiAutograph
	.nameMsg = MESSAGE_ID(0x26, 0x105),
	.fullDescMsg = MESSAGE_ID(0x25, 0x105),
	.shortDescMsg = MESSAGE_ID(0x23, 0x105),
	.sellValue = -1,
	.hudElemID = 0x82,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 70: KootEmptyWallet
	.nameMsg = MESSAGE_ID(0x26, 0x106),
	.fullDescMsg = MESSAGE_ID(0x25, 0x106),
	.shortDescMsg = MESSAGE_ID(0x23, 0x106),
	.sellValue = -1,
	.hudElemID = 0x83,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 71: KootMerluvleeAutograph
	.nameMsg = MESSAGE_ID(0x26, 0x107),
	.fullDescMsg = MESSAGE_ID(0x25, 0x107),
	.shortDescMsg = MESSAGE_ID(0x23, 0x107),
	.sellValue = -1,
	.hudElemID = 0x84,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 72: KootShell
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x85,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 73: KootOldPhoto
	.nameMsg = MESSAGE_ID(0x26, 0x108),
	.fullDescMsg = MESSAGE_ID(0x25, 0x108),
	.shortDescMsg = MESSAGE_ID(0x23, 0x108),
	.sellValue = -1,
	.hudElemID = 0x86,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 74: KootGlasses
	.nameMsg = MESSAGE_ID(0x26, 0x109),
	.fullDescMsg = MESSAGE_ID(0x25, 0x109),
	.shortDescMsg = MESSAGE_ID(0x23, 0x109),
	.sellValue = -1,
	.hudElemID = 0x87,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 75: KootAltPhoto
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x86,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 76: KootPackage
	.nameMsg = MESSAGE_ID(0x26, 0x10A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x10A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x10A),
	.sellValue = -1,
	.hudElemID = 0x6C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 77: KootRedJar
	.nameMsg = MESSAGE_ID(0x26, 0x10B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x10B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x10B),
	.sellValue = -1,
	.hudElemID = 0x6D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 78: PeachKey2
	.nameMsg = MESSAGE_ID(0x26, 0x0AC),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0AC),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0AC),
	.sellValue = -1,
	.hudElemID = 0x73,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 79: WarehouseKey
	.nameMsg = MESSAGE_ID(0x26, 0x0CE),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0CE),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0CE),
	.sellValue = -1,
	.hudElemID = 0x53,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7A: PrisonKey1
	.nameMsg = MESSAGE_ID(0x26, 0x0D5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D5),
	.sellValue = -1,
	.hudElemID = 0x53,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7B: SilverCredit
	.nameMsg = MESSAGE_ID(0x26, 0x0E8),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E8),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E8),
	.sellValue = -1,
	.hudElemID = 0x7F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7C: GoldCredit
	.nameMsg = MESSAGE_ID(0x26, 0x0E9),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0E9),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0E9),
	.sellValue = -1,
	.hudElemID = 0x7E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7D: PrisonKey2
	.nameMsg = MESSAGE_ID(0x26, 0x0D5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D5),
	.sellValue = -1,
	.hudElemID = 0x73,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7E: PrisonKey3
	.nameMsg = MESSAGE_ID(0x26, 0x0D5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D5),
	.sellValue = -1,
	.hudElemID = 0x73,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 7F: PrisonKey4
	.nameMsg = MESSAGE_ID(0x26, 0x0D5),
	.fullDescMsg = MESSAGE_ID(0x25, 0x0D5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0D5),
	.sellValue = -1,
	.hudElemID = 0x73,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_KEY | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 80: FireFlower
	.nameMsg = MESSAGE_ID(0x26, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x000),
	.shortDescMsg = MESSAGE_ID(0x23, 0x000),
	.sellValue = 4,
	.hudElemID = 0x120,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 0
},
{	// item 81: SnowmanDoll
	.nameMsg = MESSAGE_ID(0x26, 0x001),
	.fullDescMsg = MESSAGE_ID(0x25, 0x001),
	.shortDescMsg = MESSAGE_ID(0x23, 0x001),
	.sellValue = 6,
	.hudElemID = 0x121,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 4,
	.potencyB = 0
},
{	// item 82: ThunderRage
	.nameMsg = MESSAGE_ID(0x26, 0x002),
	.fullDescMsg = MESSAGE_ID(0x25, 0x002),
	.shortDescMsg = MESSAGE_ID(0x23, 0x002),
	.sellValue = 8,
	.hudElemID = 0x122,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item 83: ShootingStar
	.nameMsg = MESSAGE_ID(0x26, 0x004),
	.fullDescMsg = MESSAGE_ID(0x25, 0x004),
	.shortDescMsg = MESSAGE_ID(0x23, 0x004),
	.sellValue = 15,
	.hudElemID = 0x124,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 6,
	.potencyB = 0
},
{	// item 84: ThunderBolt
	.nameMsg = MESSAGE_ID(0x26, 0x003),
	.fullDescMsg = MESSAGE_ID(0x25, 0x003),
	.shortDescMsg = MESSAGE_ID(0x23, 0x003),
	.sellValue = 4,
	.hudElemID = 0x123,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item 85: Pebble
	.nameMsg = MESSAGE_ID(0x26, 0x006),
	.fullDescMsg = MESSAGE_ID(0x25, 0x006),
	.shortDescMsg = MESSAGE_ID(0x23, 0x006),
	.sellValue = 1,
	.hudElemID = 0x126,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 1,
	.potencyB = 0
},
{	// item 86: DustyHammer
	.nameMsg = MESSAGE_ID(0x26, 0x005),
	.fullDescMsg = MESSAGE_ID(0x25, 0x005),
	.shortDescMsg = MESSAGE_ID(0x23, 0x005),
	.sellValue = 1,
	.hudElemID = 0x125,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 1,
	.potencyB = 0
},
{	// item 87: InsecticideHerb
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 1,
	.hudElemID = 0x13D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 88: StoneCap
	.nameMsg = MESSAGE_ID(0x26, 0x007),
	.fullDescMsg = MESSAGE_ID(0x25, 0x007),
	.shortDescMsg = MESSAGE_ID(0x23, 0x007),
	.sellValue = 15,
	.hudElemID = 0x128,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 0
},
{	// item 89: TastyTonic
	.nameMsg = MESSAGE_ID(0x26, 0x00E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x00E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x00E),
	.sellValue = 1,
	.hudElemID = 0xFD,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 8A: Mushroom
	.nameMsg = MESSAGE_ID(0x26, 0x009),
	.fullDescMsg = MESSAGE_ID(0x25, 0x009),
	.shortDescMsg = MESSAGE_ID(0x23, 0x009),
	.sellValue = 2,
	.hudElemID = 0xF8,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item 8B: VoltShroom
	.nameMsg = MESSAGE_ID(0x26, 0x008),
	.fullDescMsg = MESSAGE_ID(0x25, 0x008),
	.shortDescMsg = MESSAGE_ID(0x23, 0x008),
	.sellValue = 7,
	.hudElemID = 0x129,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 4,
	.potencyB = 0
},
{	// item 8C: SuperShroom
	.nameMsg = MESSAGE_ID(0x26, 0x00A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x00A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x00A),
	.sellValue = 7,
	.hudElemID = 0xF9,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 0
},
{	// item 8D: DriedShroom
	.nameMsg = MESSAGE_ID(0x26, 0x00D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x00D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x00D),
	.sellValue = 1,
	.hudElemID = 0xFC,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 1,
	.potencyB = 0
},
{	// item 8E: UltraShroom
	.nameMsg = MESSAGE_ID(0x26, 0x00B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x00B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x00B),
	.sellValue = 50,
	.hudElemID = 0xFA,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 50,
	.potencyB = 0
},
{	// item 8F: SleepySheep
	.nameMsg = MESSAGE_ID(0x26, 0x026),
	.fullDescMsg = MESSAGE_ID(0x25, 0x026),
	.shortDescMsg = MESSAGE_ID(0x23, 0x026),
	.sellValue = 4,
	.hudElemID = 0x130,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 0
},
{	// item 90: POWBlock
	.nameMsg = MESSAGE_ID(0x26, 0x027),
	.fullDescMsg = MESSAGE_ID(0x25, 0x027),
	.shortDescMsg = MESSAGE_ID(0x23, 0x027),
	.sellValue = 3,
	.hudElemID = 0x132,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 2,
	.potencyB = 0
},
{	// item 91: HustleDrink
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 10,
	.hudElemID = 0x133,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 2,
	.potencyB = 0
},
{	// item 92: StopWatch
	.nameMsg = MESSAGE_ID(0x26, 0x028),
	.fullDescMsg = MESSAGE_ID(0x25, 0x028),
	.shortDescMsg = MESSAGE_ID(0x23, 0x028),
	.sellValue = 10,
	.hudElemID = 0x134,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 4,
	.potencyB = 0
},
{	// item 93: WhackasBump
	.nameMsg = MESSAGE_ID(0x26, 0x019),
	.fullDescMsg = MESSAGE_ID(0x25, 0x019),
	.shortDescMsg = MESSAGE_ID(0x23, 0x019),
	.sellValue = 30,
	.hudElemID = 0x113,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 25,
	.potencyB = 25
},
{	// item 94: Apple
	.nameMsg = MESSAGE_ID(0x26, 0x01A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x01A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x01A),
	.sellValue = 2,
	.hudElemID = 0x114,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item 95: LifeShroom
	.nameMsg = MESSAGE_ID(0x26, 0x00C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x00C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x00C),
	.sellValue = 20,
	.hudElemID = 0xFB,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 0
},
{	// item 96: Mystery
	.nameMsg = MESSAGE_ID(0x26, 0x02B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x02B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x02B),
	.sellValue = 1,
	.hudElemID = 0x13B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 97: RepelGel
	.nameMsg = MESSAGE_ID(0x26, 0x02C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x02C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x02C),
	.sellValue = 15,
	.hudElemID = 0x13C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 2,
	.potencyB = 0
},
{	// item 98: FrightJar
	.nameMsg = MESSAGE_ID(0x26, 0x02A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x02A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x02A),
	.sellValue = 3,
	.hudElemID = 0x13A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 99: PleaseComeBack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 5,
	.hudElemID = 0x138,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 9A: DizzyDial
	.nameMsg = MESSAGE_ID(0x26, 0x029),
	.fullDescMsg = MESSAGE_ID(0x25, 0x029),
	.shortDescMsg = MESSAGE_ID(0x23, 0x029),
	.sellValue = 6,
	.hudElemID = 0x135,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 0
},
{	// item 9B: SuperSoda
	.nameMsg = MESSAGE_ID(0x26, 0x00F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x00F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x00F),
	.sellValue = 3,
	.hudElemID = 0xFE,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 5
},
{	// item 9C: Lemon
	.nameMsg = MESSAGE_ID(0x26, 0x015),
	.fullDescMsg = MESSAGE_ID(0x25, 0x015),
	.shortDescMsg = MESSAGE_ID(0x23, 0x015),
	.sellValue = 1,
	.hudElemID = 0x107,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 1,
	.potencyB = 2
},
{	// item 9D: Lime
	.nameMsg = MESSAGE_ID(0x26, 0x014),
	.fullDescMsg = MESSAGE_ID(0x25, 0x014),
	.shortDescMsg = MESSAGE_ID(0x23, 0x014),
	.sellValue = 1,
	.hudElemID = 0x106,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 3
},
{	// item 9E: BlueBerry
	.nameMsg = MESSAGE_ID(0x26, 0x010),
	.fullDescMsg = MESSAGE_ID(0x25, 0x010),
	.shortDescMsg = MESSAGE_ID(0x23, 0x010),
	.sellValue = 2,
	.hudElemID = 0xFF,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 5
},
{	// item 9F: RedBerry
	.nameMsg = MESSAGE_ID(0x26, 0x011),
	.fullDescMsg = MESSAGE_ID(0x25, 0x011),
	.shortDescMsg = MESSAGE_ID(0x23, 0x011),
	.sellValue = 2,
	.hudElemID = 0x100,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item A0: YellowBerry
	.nameMsg = MESSAGE_ID(0x26, 0x012),
	.fullDescMsg = MESSAGE_ID(0x25, 0x012),
	.shortDescMsg = MESSAGE_ID(0x23, 0x012),
	.sellValue = 2,
	.hudElemID = 0x101,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 3
},
{	// item A1: BubbleBerry
	.nameMsg = MESSAGE_ID(0x26, 0x013),
	.fullDescMsg = MESSAGE_ID(0x25, 0x013),
	.shortDescMsg = MESSAGE_ID(0x23, 0x013),
	.sellValue = 3,
	.hudElemID = 0x102,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item A2: JamminJelly
	.nameMsg = MESSAGE_ID(0x26, 0x018),
	.fullDescMsg = MESSAGE_ID(0x25, 0x018),
	.shortDescMsg = MESSAGE_ID(0x23, 0x018),
	.sellValue = 50,
	.hudElemID = 0x112,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 50
},
{	// item A3: MapleSyrup
	.nameMsg = MESSAGE_ID(0x26, 0x017),
	.fullDescMsg = MESSAGE_ID(0x25, 0x017),
	.shortDescMsg = MESSAGE_ID(0x23, 0x017),
	.sellValue = 10,
	.hudElemID = 0x111,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 10
},
{	// item A4: HoneySyrup
	.nameMsg = MESSAGE_ID(0x26, 0x016),
	.fullDescMsg = MESSAGE_ID(0x25, 0x016),
	.shortDescMsg = MESSAGE_ID(0x23, 0x016),
	.sellValue = 3,
	.hudElemID = 0x110,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 5
},
{	// item A5: Goomnut
	.nameMsg = MESSAGE_ID(0x26, 0x01B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x01B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x01B),
	.sellValue = 2,
	.hudElemID = 0x103,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 3
},
{	// item A6: KoopaLeaf
	.nameMsg = MESSAGE_ID(0x26, 0x01C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x01C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x01C),
	.sellValue = 1,
	.hudElemID = 0x104,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 3
},
{	// item A7: DriedPasta
	.nameMsg = MESSAGE_ID(0x26, 0x01D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x01D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x01D),
	.sellValue = 4,
	.hudElemID = 0x105,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 2
},
{	// item A8: DriedFruit
	.nameMsg = MESSAGE_ID(0x26, 0x01E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x01E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x01E),
	.sellValue = 5,
	.hudElemID = 0x108,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 15,
	.potencyB = 0
},
{	// item A9: StrangeLeaf
	.nameMsg = MESSAGE_ID(0x26, 0x01F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x01F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x01F),
	.sellValue = 2,
	.hudElemID = 0x109,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 5
},
{	// item AA: CakeMix
	.nameMsg = MESSAGE_ID(0x26, 0x020),
	.fullDescMsg = MESSAGE_ID(0x25, 0x020),
	.shortDescMsg = MESSAGE_ID(0x23, 0x020),
	.sellValue = 3,
	.hudElemID = 0x10A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 1
},
{	// item AB: Egg
	.nameMsg = MESSAGE_ID(0x26, 0x021),
	.fullDescMsg = MESSAGE_ID(0x25, 0x021),
	.shortDescMsg = MESSAGE_ID(0x23, 0x021),
	.sellValue = 2,
	.hudElemID = 0x10B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item AC: Coconut
	.nameMsg = MESSAGE_ID(0x26, 0x022),
	.fullDescMsg = MESSAGE_ID(0x25, 0x022),
	.shortDescMsg = MESSAGE_ID(0x23, 0x022),
	.sellValue = 1,
	.hudElemID = 0x10C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 0
},
{	// item AD: Melon
	.nameMsg = MESSAGE_ID(0x26, 0x023),
	.fullDescMsg = MESSAGE_ID(0x25, 0x023),
	.shortDescMsg = MESSAGE_ID(0x23, 0x023),
	.sellValue = 7,
	.hudElemID = 0x10D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 15,
	.potencyB = 0
},
{	// item AE: StinkyHerb
	.nameMsg = MESSAGE_ID(0x26, 0x024),
	.fullDescMsg = MESSAGE_ID(0x25, 0x024),
	.shortDescMsg = MESSAGE_ID(0x23, 0x024),
	.sellValue = 1,
	.hudElemID = 0x10E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 5
},
{	// item AF: IcedPotato
	.nameMsg = MESSAGE_ID(0x26, 0x025),
	.fullDescMsg = MESSAGE_ID(0x25, 0x025),
	.shortDescMsg = MESSAGE_ID(0x23, 0x025),
	.sellValue = 3,
	.hudElemID = 0x10F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 0
},
{	// item B0: SpicySoup
	.nameMsg = MESSAGE_ID(0x26, 0x02D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x02D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x02D),
	.sellValue = 10,
	.hudElemID = 0x1,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 4,
	.potencyB = 4
},
{	// item B1: ApplePie
	.nameMsg = MESSAGE_ID(0x26, 0x02E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x02E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x02E),
	.sellValue = 10,
	.hudElemID = 0x2,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 15
},
{	// item B2: HoneyUltra
	.nameMsg = MESSAGE_ID(0x26, 0x035),
	.fullDescMsg = MESSAGE_ID(0x25, 0x035),
	.shortDescMsg = MESSAGE_ID(0x23, 0x035),
	.sellValue = 75,
	.hudElemID = 0x3,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 50,
	.potencyB = 5
},
{	// item B3: MapleUltra
	.nameMsg = MESSAGE_ID(0x26, 0x036),
	.fullDescMsg = MESSAGE_ID(0x25, 0x036),
	.shortDescMsg = MESSAGE_ID(0x23, 0x036),
	.sellValue = 100,
	.hudElemID = 0x4,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 50,
	.potencyB = 10
},
{	// item B4: JellyUltra
	.nameMsg = MESSAGE_ID(0x26, 0x037),
	.fullDescMsg = MESSAGE_ID(0x25, 0x037),
	.shortDescMsg = MESSAGE_ID(0x23, 0x037),
	.sellValue = 150,
	.hudElemID = 0x5,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 50,
	.potencyB = 50
},
{	// item B5: Koopasta
	.nameMsg = MESSAGE_ID(0x26, 0x038),
	.fullDescMsg = MESSAGE_ID(0x25, 0x038),
	.shortDescMsg = MESSAGE_ID(0x23, 0x038),
	.sellValue = 10,
	.hudElemID = 0x6,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 7,
	.potencyB = 7
},
{	// item B6: FriedShroom
	.nameMsg = MESSAGE_ID(0x26, 0x039),
	.fullDescMsg = MESSAGE_ID(0x25, 0x039),
	.shortDescMsg = MESSAGE_ID(0x23, 0x039),
	.sellValue = 5,
	.hudElemID = 0x7,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 6,
	.potencyB = 2
},
{	// item B7: ShroomCake
	.nameMsg = MESSAGE_ID(0x26, 0x03C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x03C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x03C),
	.sellValue = 20,
	.hudElemID = 0x8,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 10
},
{	// item B8: ShroomSteak
	.nameMsg = MESSAGE_ID(0x26, 0x03B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x03B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x03B),
	.sellValue = 45,
	.hudElemID = 0x9,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 30,
	.potencyB = 10
},
{	// item B9: HotShroom
	.nameMsg = MESSAGE_ID(0x26, 0x03A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x03A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x03A),
	.sellValue = 15,
	.hudElemID = 0xA,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 15,
	.potencyB = 5
},
{	// item BA: SweetShroom
	.nameMsg = MESSAGE_ID(0x26, 0x03D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x03D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x03D),
	.sellValue = 50,
	.hudElemID = 0xB,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 30,
	.potencyB = 20
},
{	// item BB: YummyMeal
	.nameMsg = MESSAGE_ID(0x26, 0x03F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x03F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x03F),
	.sellValue = 15,
	.hudElemID = 0xE,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 20,
	.potencyB = 20
},
{	// item BC: HealthyJuice
	.nameMsg = MESSAGE_ID(0x26, 0x042),
	.fullDescMsg = MESSAGE_ID(0x25, 0x042),
	.shortDescMsg = MESSAGE_ID(0x23, 0x042),
	.sellValue = 25,
	.hudElemID = 0xC,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 40
},
{	// item BD: BlandMeal
	.nameMsg = MESSAGE_ID(0x26, 0x03E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x03E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x03E),
	.sellValue = 10,
	.hudElemID = 0xD,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 10
},
{	// item BE: DeluxeFeast
	.nameMsg = MESSAGE_ID(0x26, 0x040),
	.fullDescMsg = MESSAGE_ID(0x25, 0x040),
	.shortDescMsg = MESSAGE_ID(0x23, 0x040),
	.sellValue = 60,
	.hudElemID = 0xF,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 40,
	.potencyB = 40
},
{	// item BF: SpecialShake
	.nameMsg = MESSAGE_ID(0x26, 0x041),
	.fullDescMsg = MESSAGE_ID(0x25, 0x041),
	.shortDescMsg = MESSAGE_ID(0x23, 0x041),
	.sellValue = 10,
	.hudElemID = 0x10,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 20
},
{	// item C0: BigCookie
	.nameMsg = MESSAGE_ID(0x26, 0x043),
	.fullDescMsg = MESSAGE_ID(0x25, 0x043),
	.shortDescMsg = MESSAGE_ID(0x23, 0x043),
	.sellValue = 10,
	.hudElemID = 0x11,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 20
},
{	// item C1: Cake
	.nameMsg = MESSAGE_ID(0x26, 0x044),
	.fullDescMsg = MESSAGE_ID(0x25, 0x044),
	.shortDescMsg = MESSAGE_ID(0x23, 0x044),
	.sellValue = 10,
	.hudElemID = 0x12,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 15
},
{	// item C2: Mistake
	.nameMsg = MESSAGE_ID(0x26, 0x045),
	.fullDescMsg = MESSAGE_ID(0x25, 0x045),
	.shortDescMsg = MESSAGE_ID(0x23, 0x045),
	.sellValue = 1,
	.hudElemID = 0x13,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 1,
	.potencyB = 1
},
{	// item C3: KoopaTea
	.nameMsg = MESSAGE_ID(0x26, 0x046),
	.fullDescMsg = MESSAGE_ID(0x25, 0x046),
	.shortDescMsg = MESSAGE_ID(0x23, 0x046),
	.sellValue = 3,
	.hudElemID = 0x14,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_USE_DRINK_ANIMATION | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 7
},
{	// item C4: HoneySuper
	.nameMsg = MESSAGE_ID(0x26, 0x032),
	.fullDescMsg = MESSAGE_ID(0x25, 0x032),
	.shortDescMsg = MESSAGE_ID(0x23, 0x032),
	.sellValue = 20,
	.hudElemID = 0x15,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 5
},
{	// item C5: MapleSuper
	.nameMsg = MESSAGE_ID(0x26, 0x033),
	.fullDescMsg = MESSAGE_ID(0x25, 0x033),
	.shortDescMsg = MESSAGE_ID(0x23, 0x033),
	.sellValue = 35,
	.hudElemID = 0x16,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 10
},
{	// item C6: JellySuper
	.nameMsg = MESSAGE_ID(0x26, 0x034),
	.fullDescMsg = MESSAGE_ID(0x25, 0x034),
	.shortDescMsg = MESSAGE_ID(0x23, 0x034),
	.sellValue = 100,
	.hudElemID = 0x17,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 50
},
{	// item C7: Spaghetti
	.nameMsg = MESSAGE_ID(0x26, 0x047),
	.fullDescMsg = MESSAGE_ID(0x25, 0x047),
	.shortDescMsg = MESSAGE_ID(0x23, 0x047),
	.sellValue = 7,
	.hudElemID = 0x18,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 6,
	.potencyB = 4
},
{	// item C8: EggMissile
	.nameMsg = MESSAGE_ID(0x26, 0x048),
	.fullDescMsg = MESSAGE_ID(0x25, 0x048),
	.shortDescMsg = MESSAGE_ID(0x23, 0x048),
	.sellValue = 10,
	.hudElemID = 0x19,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_2 | ITEM_TARGET_FLAG_8000,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 6,
	.potencyB = 0
},
{	// item C9: FriedEgg
	.nameMsg = MESSAGE_ID(0x26, 0x049),
	.fullDescMsg = MESSAGE_ID(0x25, 0x049),
	.shortDescMsg = MESSAGE_ID(0x23, 0x049),
	.sellValue = 7,
	.hudElemID = 0x1A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 0
},
{	// item CA: HoneyShroom
	.nameMsg = MESSAGE_ID(0x26, 0x02F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x02F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x02F),
	.sellValue = 10,
	.hudElemID = 0x1B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 5
},
{	// item CB: HoneyCandy
	.nameMsg = MESSAGE_ID(0x26, 0x04A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x04A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x04A),
	.sellValue = 15,
	.hudElemID = 0x1C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 20
},
{	// item CC: ElectroPop
	.nameMsg = MESSAGE_ID(0x26, 0x04B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x04B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x04B),
	.sellValue = 25,
	.hudElemID = 0x1D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 15
},
{	// item CD: FirePop
	.nameMsg = MESSAGE_ID(0x26, 0x04C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x04C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x04C),
	.sellValue = 20,
	.hudElemID = 0x1E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = -1,
	.potencyB = 20
},
{	// item CE: LimeCandy
	.nameMsg = MESSAGE_ID(0x26, 0x04D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x04D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x04D),
	.sellValue = 15,
	.hudElemID = 0x1F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 20
},
{	// item CF: CocoPop
	.nameMsg = MESSAGE_ID(0x26, 0x04E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x04E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x04E),
	.sellValue = 12,
	.hudElemID = 0x20,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 3,
	.potencyB = 15
},
{	// item D0: LemonCandy
	.nameMsg = MESSAGE_ID(0x26, 0x04F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x04F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x04F),
	.sellValue = 15,
	.hudElemID = 0x21,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 15
},
{	// item D1: JellyPop
	.nameMsg = MESSAGE_ID(0x26, 0x050),
	.fullDescMsg = MESSAGE_ID(0x25, 0x050),
	.shortDescMsg = MESSAGE_ID(0x23, 0x050),
	.sellValue = 100,
	.hudElemID = 0x22,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 64
},
{	// item D2: StrangeCake
	.nameMsg = MESSAGE_ID(0x26, 0x051),
	.fullDescMsg = MESSAGE_ID(0x25, 0x051),
	.shortDescMsg = MESSAGE_ID(0x23, 0x051),
	.sellValue = 10,
	.hudElemID = 0x23,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item D3: KookyCookie
	.nameMsg = MESSAGE_ID(0x26, 0x052),
	.fullDescMsg = MESSAGE_ID(0x25, 0x052),
	.shortDescMsg = MESSAGE_ID(0x23, 0x052),
	.sellValue = 12,
	.hudElemID = 0x24,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 15
},
{	// item D4: FrozenFries
	.nameMsg = MESSAGE_ID(0x26, 0x053),
	.fullDescMsg = MESSAGE_ID(0x25, 0x053),
	.shortDescMsg = MESSAGE_ID(0x23, 0x053),
	.sellValue = 15,
	.hudElemID = 0x25,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 15,
	.potencyB = 0
},
{	// item D5: PotatoSalad
	.nameMsg = MESSAGE_ID(0x26, 0x054),
	.fullDescMsg = MESSAGE_ID(0x25, 0x054),
	.shortDescMsg = MESSAGE_ID(0x23, 0x054),
	.sellValue = 6,
	.hudElemID = 0x26,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 10,
	.potencyB = 0
},
{	// item D6: NuttyCake
	.nameMsg = MESSAGE_ID(0x26, 0x055),
	.fullDescMsg = MESSAGE_ID(0x25, 0x055),
	.shortDescMsg = MESSAGE_ID(0x23, 0x055),
	.sellValue = 6,
	.hudElemID = 0x27,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 10
},
{	// item D7: MapleShroom
	.nameMsg = MESSAGE_ID(0x26, 0x030),
	.fullDescMsg = MESSAGE_ID(0x25, 0x030),
	.shortDescMsg = MESSAGE_ID(0x23, 0x030),
	.sellValue = 25,
	.hudElemID = 0x28,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 10
},
{	// item D8: BoiledEgg
	.nameMsg = MESSAGE_ID(0x26, 0x056),
	.fullDescMsg = MESSAGE_ID(0x25, 0x056),
	.shortDescMsg = MESSAGE_ID(0x23, 0x056),
	.sellValue = 10,
	.hudElemID = 0x29,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 8,
	.potencyB = 8
},
{	// item D9: YoshiCookie
	.nameMsg = MESSAGE_ID(0x26, 0x057),
	.fullDescMsg = MESSAGE_ID(0x25, 0x057),
	.shortDescMsg = MESSAGE_ID(0x23, 0x057),
	.sellValue = 20,
	.hudElemID = 0x2A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 15,
	.potencyB = 15
},
{	// item DA: JellyShroom1
	.nameMsg = MESSAGE_ID(0x26, 0x031),
	.fullDescMsg = MESSAGE_ID(0x25, 0x031),
	.shortDescMsg = MESSAGE_ID(0x23, 0x031),
	.sellValue = 75,
	.hudElemID = 0x2B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 50
},
{	// item DB: JellyShroom2
	.nameMsg = MESSAGE_ID(0x26, 0x031),
	.fullDescMsg = MESSAGE_ID(0x25, 0x031),
	.shortDescMsg = MESSAGE_ID(0x23, 0x031),
	.sellValue = 75,
	.hudElemID = 0x2B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 50
},
{	// item DC: JellyShroom3
	.nameMsg = MESSAGE_ID(0x26, 0x031),
	.fullDescMsg = MESSAGE_ID(0x25, 0x031),
	.shortDescMsg = MESSAGE_ID(0x23, 0x031),
	.sellValue = 75,
	.hudElemID = 0x2B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 50
},
{	// item DD: JellyShroom4
	.nameMsg = MESSAGE_ID(0x26, 0x031),
	.fullDescMsg = MESSAGE_ID(0x25, 0x031),
	.shortDescMsg = MESSAGE_ID(0x23, 0x031),
	.sellValue = 75,
	.hudElemID = 0x2B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 50
},
{	// item DE: JellyShroom5
	.nameMsg = MESSAGE_ID(0x26, 0x031),
	.fullDescMsg = MESSAGE_ID(0x25, 0x031),
	.shortDescMsg = MESSAGE_ID(0x23, 0x031),
	.sellValue = 75,
	.hudElemID = 0x2B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 50
},
{	// item DF: JellyShroom6
	.nameMsg = MESSAGE_ID(0x26, 0x031),
	.fullDescMsg = MESSAGE_ID(0x25, 0x031),
	.shortDescMsg = MESSAGE_ID(0x23, 0x031),
	.sellValue = 75,
	.hudElemID = 0x2B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_ENEMY | ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_WORLD_USABLE | ITEM_TYPE_FLAG_BATTLE_USABLE | ITEM_TYPE_FLAG_CONSUMABLE | ITEM_TYPE_FLAG_FOOD_OR_DRINK | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 5,
	.potencyB = 50
},
{	// item E0: SpinSmash
	.nameMsg = MESSAGE_ID(0x26, 0x068),
	.fullDescMsg = MESSAGE_ID(0x25, 0x068),
	.shortDescMsg = MESSAGE_ID(0x23, 0x068),
	.sellValue = 75,
	.hudElemID = 0x90,
	.sortValue = 23,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SPIN_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E1: Multibounce
	.nameMsg = MESSAGE_ID(0x26, 0x05E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05E),
	.sellValue = 75,
	.hudElemID = 0x91,
	.sortValue = 4,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MULTIBOUNCE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E2: PowerPlusA
	.nameMsg = MESSAGE_ID(0x26, 0x073),
	.fullDescMsg = MESSAGE_ID(0x25, 0x073),
	.shortDescMsg = MESSAGE_ID(0x23, 0x073),
	.sellValue = 250,
	.hudElemID = 0x92,
	.sortValue = 67,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E3: DodgeMaster
	.nameMsg = MESSAGE_ID(0x26, 0x080),
	.fullDescMsg = MESSAGE_ID(0x25, 0x080),
	.shortDescMsg = MESSAGE_ID(0x23, 0x080),
	.sellValue = 100,
	.hudElemID = 0x93,
	.sortValue = 40,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DODGE_MASTER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E4: PowerBounce
	.nameMsg = MESSAGE_ID(0x26, 0x061),
	.fullDescMsg = MESSAGE_ID(0x25, 0x061),
	.shortDescMsg = MESSAGE_ID(0x23, 0x061),
	.sellValue = 100,
	.hudElemID = 0x94,
	.sortValue = 13,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_BOUNCE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E5: SpikeShield
	.nameMsg = MESSAGE_ID(0x26, 0x07F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07F),
	.sellValue = 100,
	.hudElemID = 0x95,
	.sortValue = 92,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SPIKE_SHIELD,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E6: FirstAttack
	.nameMsg = MESSAGE_ID(0x26, 0x087),
	.fullDescMsg = MESSAGE_ID(0x25, 0x087),
	.shortDescMsg = MESSAGE_ID(0x23, 0x087),
	.sellValue = 100,
	.hudElemID = 0x96,
	.sortValue = 109,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FIRST_ATTACK,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E7: HPPlusA
	.nameMsg = MESSAGE_ID(0x26, 0x071),
	.fullDescMsg = MESSAGE_ID(0x25, 0x071),
	.shortDescMsg = MESSAGE_ID(0x23, 0x071),
	.sellValue = 150,
	.hudElemID = 0x97,
	.sortValue = 53,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E8: QuakeHammer
	.nameMsg = MESSAGE_ID(0x26, 0x06A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06A),
	.sellValue = 100,
	.hudElemID = 0x98,
	.sortValue = 24,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_QUAKE_HAMMER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item E9: DoubleDip
	.nameMsg = MESSAGE_ID(0x26, 0x06D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06D),
	.sellValue = 100,
	.hudElemID = 0x99,
	.sortValue = 33,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DOUBLE_DIP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item EA: MysteryScroll
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0x140,
	.sortValue = 0,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MYSTERY_SCROLL,
	.potencyA = 0,
	.potencyB = 0
},
{	// item EB: SleepStomp
	.nameMsg = MESSAGE_ID(0x26, 0x05C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05C),
	.sellValue = 75,
	.hudElemID = 0x9C,
	.sortValue = 9,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SLEEP_STOMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item EC: FireShield
	.nameMsg = MESSAGE_ID(0x26, 0x097),
	.fullDescMsg = MESSAGE_ID(0x25, 0x097),
	.shortDescMsg = MESSAGE_ID(0x23, 0x097),
	.sellValue = 75,
	.hudElemID = 0xA0,
	.sortValue = 91,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FIRE_SHIELD,
	.potencyA = 0,
	.potencyB = 0
},
{	// item ED: QuickChange
	.nameMsg = MESSAGE_ID(0x26, 0x070),
	.fullDescMsg = MESSAGE_ID(0x25, 0x070),
	.shortDescMsg = MESSAGE_ID(0x23, 0x070),
	.sellValue = 200,
	.hudElemID = 0xE3,
	.sortValue = 36,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_QUICK_CHANGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item EE: DDownPound
	.nameMsg = MESSAGE_ID(0x26, 0x069),
	.fullDescMsg = MESSAGE_ID(0x25, 0x069),
	.shortDescMsg = MESSAGE_ID(0x23, 0x069),
	.sellValue = 75,
	.hudElemID = 0xA4,
	.sortValue = 29,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_D_DOWN_POUND,
	.potencyA = 0,
	.potencyB = 0
},
{	// item EF: DizzyStomp
	.nameMsg = MESSAGE_ID(0x26, 0x05D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05D),
	.sellValue = 75,
	.hudElemID = 0xA6,
	.sortValue = 10,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DIZZY_STOMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F0: SmashCharge0
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 30,
	.hudElemID = 0xA8,
	.sortValue = 20,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SMASH_CHARGE0,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F1: PrettyLucky
	.nameMsg = MESSAGE_ID(0x26, 0x081),
	.fullDescMsg = MESSAGE_ID(0x25, 0x081),
	.shortDescMsg = MESSAGE_ID(0x23, 0x081),
	.sellValue = 100,
	.hudElemID = 0xA9,
	.sortValue = 85,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_PRETTY_LUCKY,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F2: FeelingFine
	.nameMsg = MESSAGE_ID(0x26, 0x08C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08C),
	.sellValue = 100,
	.hudElemID = 0xAA,
	.sortValue = 94,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FEELING_FINE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F3: AttackFXA
	.nameMsg = MESSAGE_ID(0x26, 0x08D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08D),
	.sellValue = 30,
	.hudElemID = 0xAB,
	.sortValue = 112,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_A,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F4: AllorNothing
	.nameMsg = MESSAGE_ID(0x26, 0x093),
	.fullDescMsg = MESSAGE_ID(0x25, 0x093),
	.shortDescMsg = MESSAGE_ID(0x23, 0x093),
	.sellValue = 100,
	.hudElemID = 0xAC,
	.sortValue = 80,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ALLOR_NOTHING,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F5: HPDrain
	.nameMsg = MESSAGE_ID(0x26, 0x078),
	.fullDescMsg = MESSAGE_ID(0x25, 0x078),
	.shortDescMsg = MESSAGE_ID(0x23, 0x078),
	.sellValue = 50,
	.hudElemID = 0xAD,
	.sortValue = 79,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HP_DRAIN,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F6: JumpCharge0
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 30,
	.hudElemID = 0xAE,
	.sortValue = 4,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_JUMP_CHARGE0,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F7: SlowGo
	.nameMsg = MESSAGE_ID(0x26, 0x094),
	.fullDescMsg = MESSAGE_ID(0x25, 0x094),
	.shortDescMsg = MESSAGE_ID(0x23, 0x094),
	.sellValue = 10,
	.hudElemID = 0xAF,
	.sortValue = 111,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SLOW_GO,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F8: FPPlusA
	.nameMsg = MESSAGE_ID(0x26, 0x072),
	.fullDescMsg = MESSAGE_ID(0x25, 0x072),
	.shortDescMsg = MESSAGE_ID(0x23, 0x072),
	.sellValue = 150,
	.hudElemID = 0xB0,
	.sortValue = 58,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item F9: MegaRush
	.nameMsg = MESSAGE_ID(0x26, 0x086),
	.fullDescMsg = MESSAGE_ID(0x25, 0x086),
	.shortDescMsg = MESSAGE_ID(0x23, 0x086),
	.sellValue = 50,
	.hudElemID = 0xB1,
	.sortValue = 81,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_RUSH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item FA: IcePower
	.nameMsg = MESSAGE_ID(0x26, 0x095),
	.fullDescMsg = MESSAGE_ID(0x25, 0x095),
	.shortDescMsg = MESSAGE_ID(0x23, 0x095),
	.sellValue = 75,
	.hudElemID = 0xB2,
	.sortValue = 90,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ICE_POWER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item FB: DefendPlusA
	.nameMsg = MESSAGE_ID(0x26, 0x074),
	.fullDescMsg = MESSAGE_ID(0x25, 0x074),
	.shortDescMsg = MESSAGE_ID(0x23, 0x074),
	.sellValue = 250,
	.hudElemID = 0xB3,
	.sortValue = 70,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DEFEND_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item FC: PayOff
	.nameMsg = MESSAGE_ID(0x26, 0x096),
	.fullDescMsg = MESSAGE_ID(0x25, 0x096),
	.shortDescMsg = MESSAGE_ID(0x23, 0x096),
	.sellValue = 50,
	.hudElemID = 0xB4,
	.sortValue = 101,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_PAY_OFF,
	.potencyA = 0,
	.potencyB = 0
},
{	// item FD: MoneyMoney
	.nameMsg = MESSAGE_ID(0x26, 0x09A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09A),
	.sellValue = 200,
	.hudElemID = 0xB5,
	.sortValue = 101,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MONEY_MONEY,
	.potencyA = 0,
	.potencyB = 0
},
{	// item FE: ChillOut
	.nameMsg = MESSAGE_ID(0x26, 0x098),
	.fullDescMsg = MESSAGE_ID(0x25, 0x098),
	.shortDescMsg = MESSAGE_ID(0x23, 0x098),
	.sellValue = 50,
	.hudElemID = 0xB6,
	.sortValue = 105,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_CHILL_OUT_BADGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item FF: HappyHeartA
	.nameMsg = MESSAGE_ID(0x26, 0x079),
	.fullDescMsg = MESSAGE_ID(0x25, 0x079),
	.shortDescMsg = MESSAGE_ID(0x23, 0x079),
	.sellValue = 100,
	.hudElemID = 0xB7,
	.sortValue = 42,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAPPY_HEART,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 100: ZapTap
	.nameMsg = MESSAGE_ID(0x26, 0x099),
	.fullDescMsg = MESSAGE_ID(0x25, 0x099),
	.shortDescMsg = MESSAGE_ID(0x23, 0x099),
	.sellValue = 100,
	.hudElemID = 0xB8,
	.sortValue = 95,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ZAP_TAP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 101: Berserker
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 300,
	.hudElemID = 0xB9,
	.sortValue = 88,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_BERSERKER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 102: RightOn
	.nameMsg = MESSAGE_ID(0x26, 0x09B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09B),
	.sellValue = 300,
	.hudElemID = 0xBA,
	.sortValue = 41,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_RIGHT_ON,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 103: RunawayPay
	.nameMsg = MESSAGE_ID(0x26, 0x09C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09C),
	.sellValue = 50,
	.hudElemID = 0xBB,
	.sortValue = 99,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_RUNAWAY_PAY,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 104: Refund
	.nameMsg = MESSAGE_ID(0x26, 0x09D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09D),
	.sellValue = 50,
	.hudElemID = 0xBC,
	.sortValue = 100,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_REFUND,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 105: FlowerSaverA
	.nameMsg = MESSAGE_ID(0x26, 0x07B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07B),
	.sellValue = 250,
	.hudElemID = 0xBD,
	.sortValue = 63,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FLOWER_SAVER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 106: TripleDip
	.nameMsg = MESSAGE_ID(0x26, 0x06E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06E),
	.sellValue = 200,
	.hudElemID = 0xBE,
	.sortValue = 34,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_TRIPLE_DIP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 107: HammerThrow
	.nameMsg = MESSAGE_ID(0x26, 0x066),
	.fullDescMsg = MESSAGE_ID(0x25, 0x066),
	.shortDescMsg = MESSAGE_ID(0x23, 0x066),
	.sellValue = 75,
	.hudElemID = 0xA7,
	.sortValue = 28,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAMMER_THROW,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 108: MegaQuake
	.nameMsg = MESSAGE_ID(0x26, 0x06C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06C),
	.sellValue = 200,
	.hudElemID = 0x9B,
	.sortValue = 26,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_QUAKE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 109: SmashCharge
	.nameMsg = MESSAGE_ID(0x26, 0x064),
	.fullDescMsg = MESSAGE_ID(0x25, 0x064),
	.shortDescMsg = MESSAGE_ID(0x23, 0x064),
	.sellValue = 50,
	.hudElemID = 0x9D,
	.sortValue = 21,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SMASH_CHARGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10A: JumpCharge
	.nameMsg = MESSAGE_ID(0x26, 0x05A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05A),
	.sellValue = 50,
	.hudElemID = 0xA1,
	.sortValue = 5,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_JUMP_CHARGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10B: SSmashChg
	.nameMsg = MESSAGE_ID(0x26, 0x065),
	.fullDescMsg = MESSAGE_ID(0x25, 0x065),
	.shortDescMsg = MESSAGE_ID(0x23, 0x065),
	.sellValue = 100,
	.hudElemID = 0x9E,
	.sortValue = 22,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SUPER_SMASH_CHARGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10C: SJumpChg
	.nameMsg = MESSAGE_ID(0x26, 0x05B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05B),
	.sellValue = 100,
	.hudElemID = 0xA2,
	.sortValue = 6,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SUPER_JUMP_CHARGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10D: PowerRush
	.nameMsg = MESSAGE_ID(0x26, 0x084),
	.fullDescMsg = MESSAGE_ID(0x25, 0x084),
	.shortDescMsg = MESSAGE_ID(0x23, 0x084),
	.sellValue = 50,
	.hudElemID = 0xD1,
	.sortValue = 83,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_RUSH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10E: AutoJump
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 50,
	.hudElemID = 0xA3,
	.sortValue = 15,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_AUTO_JUMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 10F: AutoSmash
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 50,
	.hudElemID = 0x9F,
	.sortValue = 31,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_AUTO_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 110: CrazyHeart
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 300,
	.hudElemID = 0xD4,
	.sortValue = 45,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_CRAZY_HEART,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 111: LastStand
	.nameMsg = MESSAGE_ID(0x26, 0x085),
	.fullDescMsg = MESSAGE_ID(0x25, 0x085),
	.shortDescMsg = MESSAGE_ID(0x23, 0x085),
	.sellValue = 50,
	.hudElemID = 0xD2,
	.sortValue = 82,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_LAST_STAND,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 112: CloseCall
	.nameMsg = MESSAGE_ID(0x26, 0x083),
	.fullDescMsg = MESSAGE_ID(0x25, 0x083),
	.shortDescMsg = MESSAGE_ID(0x23, 0x083),
	.sellValue = 50,
	.hudElemID = 0xD3,
	.sortValue = 84,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_CLOSE_CALL,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 113: PUpDDown
	.nameMsg = MESSAGE_ID(0x26, 0x076),
	.fullDescMsg = MESSAGE_ID(0x25, 0x076),
	.shortDescMsg = MESSAGE_ID(0x23, 0x076),
	.sellValue = 100,
	.hudElemID = 0xC9,
	.sortValue = 78,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_P_UP_D_DOWN,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 114: LuckyDay
	.nameMsg = MESSAGE_ID(0x26, 0x082),
	.fullDescMsg = MESSAGE_ID(0x25, 0x082),
	.shortDescMsg = MESSAGE_ID(0x23, 0x082),
	.sellValue = 300,
	.hudElemID = 0xC6,
	.sortValue = 86,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_LUCKY_DAY,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 115: MegaHPDrain
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0xC7,
	.sortValue = 87,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_HP_DRAIN,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 116: PDownDUp
	.nameMsg = MESSAGE_ID(0x26, 0x077),
	.fullDescMsg = MESSAGE_ID(0x25, 0x077),
	.shortDescMsg = MESSAGE_ID(0x23, 0x077),
	.sellValue = 100,
	.hudElemID = 0xCA,
	.sortValue = 77,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_P_DOWN_D_UP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 117: PowerQuake
	.nameMsg = MESSAGE_ID(0x26, 0x06B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06B),
	.sellValue = 150,
	.hudElemID = 0x9A,
	.sortValue = 25,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_QUAKE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 118: AutoMultibounce
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 75,
	.hudElemID = 0xA5,
	.sortValue = 14,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_AUTO_MULTIBOUNCE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 119: FlowerFanatic
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 300,
	.hudElemID = 0xBF,
	.sortValue = 66,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FLOWER_FANATIC,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11A: HeartFinder
	.nameMsg = MESSAGE_ID(0x26, 0x07C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07C),
	.sellValue = 75,
	.hudElemID = 0xCB,
	.sortValue = 97,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HEART_FINDER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11B: FlowerFinder
	.nameMsg = MESSAGE_ID(0x26, 0x07D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07D),
	.sellValue = 75,
	.hudElemID = 0xCC,
	.sortValue = 98,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FLOWER_FINDER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11C: SpinAttack
	.nameMsg = MESSAGE_ID(0x26, 0x089),
	.fullDescMsg = MESSAGE_ID(0x25, 0x089),
	.shortDescMsg = MESSAGE_ID(0x23, 0x089),
	.sellValue = 150,
	.hudElemID = 0xCF,
	.sortValue = 108,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SPIN_ATTACK,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11D: DizzyAttack
	.nameMsg = MESSAGE_ID(0x26, 0x08A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08A),
	.sellValue = 100,
	.hudElemID = 0xCD,
	.sortValue = 107,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DIZZY_ATTACK,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11E: ISpy
	.nameMsg = MESSAGE_ID(0x26, 0x09E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09E),
	.sellValue = 200,
	.hudElemID = 0xD0,
	.sortValue = 104,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_I_SPY,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 11F: SpeedySpin
	.nameMsg = MESSAGE_ID(0x26, 0x08B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08B),
	.sellValue = 50,
	.hudElemID = 0xCE,
	.sortValue = 106,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SPEEDY_SPIN,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 120: BumpAttack
	.nameMsg = MESSAGE_ID(0x26, 0x088),
	.fullDescMsg = MESSAGE_ID(0x25, 0x088),
	.shortDescMsg = MESSAGE_ID(0x23, 0x088),
	.sellValue = 200,
	.hudElemID = 0xC8,
	.sortValue = 110,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_BUMP_ATTACK,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 121: PowerJump
	.nameMsg = MESSAGE_ID(0x26, 0x058),
	.fullDescMsg = MESSAGE_ID(0x25, 0x058),
	.shortDescMsg = MESSAGE_ID(0x23, 0x058),
	.sellValue = 50,
	.hudElemID = 0xC0,
	.sortValue = 1,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_JUMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 122: SuperJump
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0xC1,
	.sortValue = 2,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SUPER_JUMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 123: MegaJump
	.nameMsg = MESSAGE_ID(0x26, 0x059),
	.fullDescMsg = MESSAGE_ID(0x25, 0x059),
	.shortDescMsg = MESSAGE_ID(0x23, 0x059),
	.sellValue = 200,
	.hudElemID = 0xC2,
	.sortValue = 3,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_JUMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 124: PowerSmash1
	.nameMsg = MESSAGE_ID(0x26, 0x062),
	.fullDescMsg = MESSAGE_ID(0x25, 0x062),
	.shortDescMsg = MESSAGE_ID(0x23, 0x062),
	.sellValue = 50,
	.hudElemID = 0xC3,
	.sortValue = 17,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 125: SuperSmash
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0xC4,
	.sortValue = 18,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SUPER_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 126: MegaSmash
	.nameMsg = MESSAGE_ID(0x26, 0x063),
	.fullDescMsg = MESSAGE_ID(0x25, 0x063),
	.shortDescMsg = MESSAGE_ID(0x23, 0x063),
	.sellValue = 200,
	.hudElemID = 0xC5,
	.sortValue = 19,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 127: PowerSmash2
	.nameMsg = MESSAGE_ID(0x26, 0x062),
	.fullDescMsg = MESSAGE_ID(0x25, 0x062),
	.shortDescMsg = MESSAGE_ID(0x23, 0x062),
	.sellValue = 50,
	.hudElemID = 0x140,
	.sortValue = 17,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 128: PowerSmash3
	.nameMsg = MESSAGE_ID(0x26, 0x062),
	.fullDescMsg = MESSAGE_ID(0x25, 0x062),
	.shortDescMsg = MESSAGE_ID(0x23, 0x062),
	.sellValue = 50,
	.hudElemID = 0x140,
	.sortValue = 17,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_MEGA_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 129: DeepFocus1
	.nameMsg = MESSAGE_ID(0x26, 0x07E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07E),
	.sellValue = 50,
	.hudElemID = 0xE0,
	.sortValue = 49,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DEEP_FOCUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12A: SuperFocus
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0xE1,
	.sortValue = 52,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SUPER_FOCUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12B: ShrinkSmash
	.nameMsg = MESSAGE_ID(0x26, 0x067),
	.fullDescMsg = MESSAGE_ID(0x25, 0x067),
	.shortDescMsg = MESSAGE_ID(0x23, 0x067),
	.sellValue = 75,
	.hudElemID = 0xD8,
	.sortValue = 27,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SHRINK_SMASH,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12C: ShellCrack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0x140,
	.sortValue = 30,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SHELL_CRACK,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12D: Kaiden
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 300,
	.hudElemID = 0xE2,
	.sortValue = 39,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_KAIDEN,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12E: DDownJump
	.nameMsg = MESSAGE_ID(0x26, 0x060),
	.fullDescMsg = MESSAGE_ID(0x25, 0x060),
	.shortDescMsg = MESSAGE_ID(0x23, 0x060),
	.sellValue = 100,
	.hudElemID = 0xDA,
	.sortValue = 12,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_D_DOWN_JUMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 12F: ShrinkStomp
	.nameMsg = MESSAGE_ID(0x26, 0x05F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05F),
	.sellValue = 75,
	.hudElemID = 0xD9,
	.sortValue = 8,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_SHRINK_STOMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 130: DamageDodgeA
	.nameMsg = MESSAGE_ID(0x26, 0x075),
	.fullDescMsg = MESSAGE_ID(0x25, 0x075),
	.shortDescMsg = MESSAGE_ID(0x23, 0x075),
	.sellValue = 150,
	.hudElemID = 0xDB,
	.sortValue = 73,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DAMAGE_DODGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 131: EarthquakeJump
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0xDC,
	.sortValue = 11,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_EARTHQUAKE_JUMP,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 132: DeepFocus2
	.nameMsg = MESSAGE_ID(0x26, 0x07E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07E),
	.sellValue = 50,
	.hudElemID = 0xE0,
	.sortValue = 49,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DEEP_FOCUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 133: DeepFocus3
	.nameMsg = MESSAGE_ID(0x26, 0x07E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07E),
	.sellValue = 50,
	.hudElemID = 0xE0,
	.sortValue = 49,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DEEP_FOCUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 134: HPPlusB
	.nameMsg = MESSAGE_ID(0x26, 0x071),
	.fullDescMsg = MESSAGE_ID(0x25, 0x071),
	.shortDescMsg = MESSAGE_ID(0x23, 0x071),
	.sellValue = 150,
	.hudElemID = 0x97,
	.sortValue = 53,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 135: FPPlusB
	.nameMsg = MESSAGE_ID(0x26, 0x072),
	.fullDescMsg = MESSAGE_ID(0x25, 0x072),
	.shortDescMsg = MESSAGE_ID(0x23, 0x072),
	.sellValue = 150,
	.hudElemID = 0xB0,
	.sortValue = 58,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 136: HappyHeartB
	.nameMsg = MESSAGE_ID(0x26, 0x079),
	.fullDescMsg = MESSAGE_ID(0x25, 0x079),
	.shortDescMsg = MESSAGE_ID(0x23, 0x079),
	.sellValue = 100,
	.hudElemID = 0xB7,
	.sortValue = 42,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAPPY_HEART,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 137: HappyHeartX
	.nameMsg = MESSAGE_ID(0x26, 0x079),
	.fullDescMsg = MESSAGE_ID(0x25, 0x079),
	.shortDescMsg = MESSAGE_ID(0x23, 0x079),
	.sellValue = 100,
	.hudElemID = 0xB7,
	.sortValue = 42,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAPPY_HEART,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 138: FlowerSaverB
	.nameMsg = MESSAGE_ID(0x26, 0x07B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07B),
	.sellValue = 250,
	.hudElemID = 0xBD,
	.sortValue = 63,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FLOWER_SAVER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 139: FlowerSaverX
	.nameMsg = MESSAGE_ID(0x26, 0x07B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07B),
	.sellValue = 250,
	.hudElemID = 0xBD,
	.sortValue = 63,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FLOWER_SAVER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13A: DamageDodgeB
	.nameMsg = MESSAGE_ID(0x26, 0x075),
	.fullDescMsg = MESSAGE_ID(0x25, 0x075),
	.shortDescMsg = MESSAGE_ID(0x23, 0x075),
	.sellValue = 150,
	.hudElemID = 0xDB,
	.sortValue = 73,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DAMAGE_DODGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13B: DamageDodgeX
	.nameMsg = MESSAGE_ID(0x26, 0x075),
	.fullDescMsg = MESSAGE_ID(0x25, 0x075),
	.shortDescMsg = MESSAGE_ID(0x23, 0x075),
	.sellValue = 150,
	.hudElemID = 0xDB,
	.sortValue = 73,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DAMAGE_DODGE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13C: PowerPlusB
	.nameMsg = MESSAGE_ID(0x26, 0x073),
	.fullDescMsg = MESSAGE_ID(0x25, 0x073),
	.shortDescMsg = MESSAGE_ID(0x23, 0x073),
	.sellValue = 250,
	.hudElemID = 0x92,
	.sortValue = 67,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13D: PowerPlusX
	.nameMsg = MESSAGE_ID(0x26, 0x073),
	.fullDescMsg = MESSAGE_ID(0x25, 0x073),
	.shortDescMsg = MESSAGE_ID(0x23, 0x073),
	.sellValue = 250,
	.hudElemID = 0x92,
	.sortValue = 67,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_POWER_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13E: DefendPlusX
	.nameMsg = MESSAGE_ID(0x26, 0x074),
	.fullDescMsg = MESSAGE_ID(0x25, 0x074),
	.shortDescMsg = MESSAGE_ID(0x23, 0x074),
	.sellValue = 250,
	.hudElemID = 0xB3,
	.sortValue = 70,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DEFEND_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 13F: DefendPlusY
	.nameMsg = MESSAGE_ID(0x26, 0x074),
	.fullDescMsg = MESSAGE_ID(0x25, 0x074),
	.shortDescMsg = MESSAGE_ID(0x23, 0x074),
	.sellValue = 250,
	.hudElemID = 0xB3,
	.sortValue = 70,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_DEFEND_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 140: HappyFlowerA
	.nameMsg = MESSAGE_ID(0x26, 0x07A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07A),
	.sellValue = 100,
	.hudElemID = 0xDD,
	.sortValue = 46,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAPPY_FLOWER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 141: HappyFlowerB
	.nameMsg = MESSAGE_ID(0x26, 0x07A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07A),
	.sellValue = 100,
	.hudElemID = 0xDD,
	.sortValue = 46,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAPPY_FLOWER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 142: HappyFlowerX
	.nameMsg = MESSAGE_ID(0x26, 0x07A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07A),
	.sellValue = 100,
	.hudElemID = 0xDD,
	.sortValue = 46,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HAPPY_FLOWER,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 143: GroupFocus
	.nameMsg = MESSAGE_ID(0x26, 0x06F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06F),
	.sellValue = 100,
	.hudElemID = 0xE9,
	.sortValue = 35,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_GROUP_FOCUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 144: Peekaboo
	.nameMsg = MESSAGE_ID(0x26, 0x09F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09F),
	.sellValue = 100,
	.hudElemID = 0xE8,
	.sortValue = 37,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_PEEKABOO,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 145: AttackFXD
	.nameMsg = MESSAGE_ID(0x26, 0x08E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08E),
	.sellValue = 30,
	.hudElemID = 0xEA,
	.sortValue = 115,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_D,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 146: AttackFXB
	.nameMsg = MESSAGE_ID(0x26, 0x08F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08F),
	.sellValue = 30,
	.hudElemID = 0xEB,
	.sortValue = 113,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_B,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 147: AttackFXE
	.nameMsg = MESSAGE_ID(0x26, 0x090),
	.fullDescMsg = MESSAGE_ID(0x25, 0x090),
	.shortDescMsg = MESSAGE_ID(0x23, 0x090),
	.sellValue = 30,
	.hudElemID = 0xEC,
	.sortValue = 116,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_E,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 148: AttackFXC
	.nameMsg = MESSAGE_ID(0x26, 0x091),
	.fullDescMsg = MESSAGE_ID(0x25, 0x091),
	.shortDescMsg = MESSAGE_ID(0x23, 0x091),
	.sellValue = 30,
	.hudElemID = 0xED,
	.sortValue = 114,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_C,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 149: AttackFXF
	.nameMsg = MESSAGE_ID(0x26, 0x092),
	.fullDescMsg = MESSAGE_ID(0x25, 0x092),
	.shortDescMsg = MESSAGE_ID(0x23, 0x092),
	.sellValue = 30,
	.hudElemID = 0xEE,
	.sortValue = 117,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_F,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14A: HPPlusC
	.nameMsg = MESSAGE_ID(0x26, 0x071),
	.fullDescMsg = MESSAGE_ID(0x25, 0x071),
	.shortDescMsg = MESSAGE_ID(0x23, 0x071),
	.sellValue = 150,
	.hudElemID = 0x97,
	.sortValue = 53,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14B: HPPlusX
	.nameMsg = MESSAGE_ID(0x26, 0x071),
	.fullDescMsg = MESSAGE_ID(0x25, 0x071),
	.shortDescMsg = MESSAGE_ID(0x23, 0x071),
	.sellValue = 150,
	.hudElemID = 0x97,
	.sortValue = 53,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14C: HPPlusY
	.nameMsg = MESSAGE_ID(0x26, 0x071),
	.fullDescMsg = MESSAGE_ID(0x25, 0x071),
	.shortDescMsg = MESSAGE_ID(0x23, 0x071),
	.sellValue = 150,
	.hudElemID = 0x97,
	.sortValue = 53,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14D: FPPlusC
	.nameMsg = MESSAGE_ID(0x26, 0x072),
	.fullDescMsg = MESSAGE_ID(0x25, 0x072),
	.shortDescMsg = MESSAGE_ID(0x23, 0x072),
	.sellValue = 150,
	.hudElemID = 0xB0,
	.sortValue = 58,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14E: FPPlusX
	.nameMsg = MESSAGE_ID(0x26, 0x072),
	.fullDescMsg = MESSAGE_ID(0x25, 0x072),
	.shortDescMsg = MESSAGE_ID(0x23, 0x072),
	.sellValue = 150,
	.hudElemID = 0xB0,
	.sortValue = 58,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 14F: FPPlusY
	.nameMsg = MESSAGE_ID(0x26, 0x072),
	.fullDescMsg = MESSAGE_ID(0x25, 0x072),
	.shortDescMsg = MESSAGE_ID(0x23, 0x072),
	.sellValue = 150,
	.hudElemID = 0xB0,
	.sortValue = 58,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_FP_PLUS,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 150: HealthyHealthy
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 100,
	.hudElemID = 0xF0,
	.sortValue = 93,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_HEALTHY_HEALTHY,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 151: AttackFXF2
	.nameMsg = MESSAGE_ID(0x26, 0x092),
	.fullDescMsg = MESSAGE_ID(0x25, 0x092),
	.shortDescMsg = MESSAGE_ID(0x23, 0x092),
	.sellValue = 30,
	.hudElemID = 0xEE,
	.sortValue = 117,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_F,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 152: AttackFXF3
	.nameMsg = MESSAGE_ID(0x26, 0x092),
	.fullDescMsg = MESSAGE_ID(0x25, 0x092),
	.shortDescMsg = MESSAGE_ID(0x23, 0x092),
	.sellValue = 30,
	.hudElemID = 0xEE,
	.sortValue = 117,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_F,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 153: AttackFXF4
	.nameMsg = MESSAGE_ID(0x26, 0x092),
	.fullDescMsg = MESSAGE_ID(0x25, 0x092),
	.shortDescMsg = MESSAGE_ID(0x23, 0x092),
	.sellValue = 30,
	.hudElemID = 0xEE,
	.sortValue = 117,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_F,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 154: AttackFXF5
	.nameMsg = MESSAGE_ID(0x26, 0x092),
	.fullDescMsg = MESSAGE_ID(0x25, 0x092),
	.shortDescMsg = MESSAGE_ID(0x23, 0x092),
	.sellValue = 30,
	.hudElemID = 0xEE,
	.sortValue = 117,
	.targetFlags = 0,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_ATTACK_FX_F,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 155: PartnerAttack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 1,
	.hudElemID = 0x149,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_BADGE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 156: Heart
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x31,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = 0,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 157: Coin
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 1,
	.hudElemID = 0x32,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_COLLECTIBLE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 158: HeartPiece
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x33,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_COLLECTIBLE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 159: StarPoint
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x34,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_COLLECTIBLE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15A: HeartPoint
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = -1,
	.hudElemID = 0x35,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_COLLECTIBLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15B: FlowerPoint
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 1,
	.hudElemID = 0x36,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_COLLECTIBLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15C: StarPiece
	.nameMsg = MESSAGE_ID(0x26, 0x10C),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 1,
	.hudElemID = 0x37,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_COLLECTIBLE | ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15D: Present
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x140,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15E: CakeDone
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x141,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 15F: CakeBare
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x142,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 160: CakePan
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x143,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 161: CakeBatter
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x144,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 162: CakeBowl
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x145,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 163: CakeMixed
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x146,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 164: CakeWithIcing
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x147,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 165: CakeWithBerries
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x148,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 166: Hammer1Icon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x14A,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 167: Hammer2Icon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x14B,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 168: Hammer3Icon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x14C,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 169: Boots1Icon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x14D,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 16A: Boots2Icon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x14E,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 16B: Boots3Icon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x14F,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
},
{	// item 16C: ItemsIcon
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.sellValue = 0,
	.hudElemID = 0x150,
	.sortValue = 0,
	.targetFlags = ITEM_TARGET_FLAG_PLAYER,
	.typeFlags = ITEM_TYPE_FLAG_ENTITY_FULLSIZE,
	.moveID = MOVE_NONE,
	.potencyA = 0,
	.potencyB = 0
}
};

IconHudScriptPair gItemHudScripts[] = {
{ .enabled = NULL, .disabled = NULL },
{ .enabled = &HudScript_Item_SpicySoup, .disabled = &HudScript_Item_SpicySoup_disabled },
{ .enabled = &HudScript_Item_ApplePie, .disabled = &HudScript_Item_ApplePie_disabled },
{ .enabled = &HudScript_Item_HoneyUltra, .disabled = &HudScript_Item_HoneyUltra_disabled },
{ .enabled = &HudScript_Item_MapleUltra, .disabled = &HudScript_Item_MapleUltra_disabled },
{ .enabled = &HudScript_Item_JellyUltra, .disabled = &HudScript_Item_JellyUltra_disabled },
{ .enabled = &HudScript_Item_Koopasta, .disabled = &HudScript_Item_Koopasta_disabled },
{ .enabled = &HudScript_Item_FriedShroom, .disabled = &HudScript_Item_FriedShroom_disabled },
{ .enabled = &HudScript_Item_ShroomCake, .disabled = &HudScript_Item_ShroomCake_disabled },
{ .enabled = &HudScript_Item_ShroomSteak, .disabled = &HudScript_Item_ShroomSteak_disabled },
{ .enabled = &HudScript_Item_HotShroom, .disabled = &HudScript_Item_HotShroom_disabled },
{ .enabled = &HudScript_Item_SweetShroom, .disabled = &HudScript_Item_SweetShroom_disabled },
{ .enabled = &HudScript_Item_HealthyJuice, .disabled = &HudScript_Item_HealthyJuice_disabled },
{ .enabled = &HudScript_Item_BlandMeal, .disabled = &HudScript_Item_BlandMeal_disabled },
{ .enabled = &HudScript_Item_YummyMeal, .disabled = &HudScript_Item_YummyMeal_disabled },
{ .enabled = &HudScript_Item_DeluxeFeast, .disabled = &HudScript_Item_DeluxeFeast_disabled },
{ .enabled = &HudScript_Item_SpecialShake, .disabled = &HudScript_Item_SpecialShake_disabled },
{ .enabled = &HudScript_Item_BigCookie, .disabled = &HudScript_Item_BigCookie_disabled },
{ .enabled = &HudScript_Item_Cake, .disabled = &HudScript_Item_Cake_disabled },
{ .enabled = &HudScript_Item_Mistake, .disabled = &HudScript_Item_Mistake_disabled },
{ .enabled = &HudScript_Item_KoopaTea, .disabled = &HudScript_Item_KoopaTea_disabled },
{ .enabled = &HudScript_Item_HoneySuper, .disabled = &HudScript_Item_HoneySuper_disabled },
{ .enabled = &HudScript_Item_MapleSuper, .disabled = &HudScript_Item_MapleSuper_disabled },
{ .enabled = &HudScript_Item_JellySuper, .disabled = &HudScript_Item_JellySuper_disabled },
{ .enabled = &HudScript_Item_Spaghetti, .disabled = &HudScript_Item_Spaghetti_disabled },
{ .enabled = &HudScript_Item_EggMissile, .disabled = &HudScript_Item_EggMissile_disabled },
{ .enabled = &HudScript_Item_FriedEgg, .disabled = &HudScript_Item_FriedEgg_disabled },
{ .enabled = &HudScript_Item_HoneyShroom, .disabled = &HudScript_Item_HoneyShroom_disabled },
{ .enabled = &HudScript_Item_HoneyCandy, .disabled = &HudScript_Item_HoneyCandy_disabled },
{ .enabled = &HudScript_Item_ElectroPop, .disabled = &HudScript_Item_ElectroPop_disabled },
{ .enabled = &HudScript_Item_FirePop, .disabled = &HudScript_Item_FirePop_disabled },
{ .enabled = &HudScript_Item_LimeCandy, .disabled = &HudScript_Item_LimeCandy_disabled },
{ .enabled = &HudScript_Item_CocoPop, .disabled = &HudScript_Item_CocoPop_disabled },
{ .enabled = &HudScript_Item_LemonCandy, .disabled = &HudScript_Item_LemonCandy_disabled },
{ .enabled = &HudScript_Item_JellyPop, .disabled = &HudScript_Item_JellyPop_disabled },
{ .enabled = &HudScript_Item_StrangeCake, .disabled = &HudScript_Item_StrangeCake_disabled },
{ .enabled = &HudScript_Item_KookyCookie, .disabled = &HudScript_Item_KookyCookie_disabled },
{ .enabled = &HudScript_Item_FrozenFries, .disabled = &HudScript_Item_FrozenFries_disabled },
{ .enabled = &HudScript_Item_PotatoSalad, .disabled = &HudScript_Item_PotatoSalad_disabled },
{ .enabled = &HudScript_Item_NuttyCake, .disabled = &HudScript_Item_NuttyCake_disabled },
{ .enabled = &HudScript_Item_MapleShroom, .disabled = &HudScript_Item_MapleShroom_disabled },
{ .enabled = &HudScript_Item_BoiledEgg, .disabled = &HudScript_Item_BoiledEgg_disabled },
{ .enabled = &HudScript_Item_YoshiCookie, .disabled = &HudScript_Item_YoshiCookie_disabled },
{ .enabled = &HudScript_Item_JellyShroom, .disabled = &HudScript_Item_JellyShroom_disabled },
{ .enabled = &HudScript_Item_ITEM_02C, .disabled = &HudScript_Item_ITEM_02C_disabled },
{ .enabled = &HudScript_Item_ITEM_02D, .disabled = &HudScript_Item_ITEM_02D_disabled },
{ .enabled = &HudScript_Item_ITEM_02E, .disabled = &HudScript_Item_ITEM_02E_disabled },
{ .enabled = &HudScript_Item_ITEM_02F, .disabled = &HudScript_Item_ITEM_02F_disabled },
{ .enabled = &HudScript_Item_ITEM_030, .disabled = &HudScript_Item_ITEM_030_disabled },
{ .enabled = &HudScript_Item_Heart, .disabled = &HudScript_Item_Heart },
{ .enabled = &HudScript_Item_Coin, .disabled = &HudScript_Item_Coin },
{ .enabled = &HudScript_Item_HeartPiece, .disabled = &HudScript_Item_HeartPiece },
{ .enabled = &HudScript_Item_StarPoint, .disabled = &HudScript_Item_StarPoint },
{ .enabled = &HudScript_Item_HeartPoint, .disabled = &HudScript_Item_HeartPoint },
{ .enabled = &HudScript_Item_FlowerPoint, .disabled = &HudScript_Item_FlowerPoint },
{ .enabled = &HudScript_Item_StarPiece, .disabled = &HudScript_Item_StarPiece },
{ .enabled = &HudScript_Item_GearBoots1, .disabled = &HudScript_Item_GearBoots1 },
{ .enabled = &HudScript_Item_GearBoots2, .disabled = &HudScript_Item_GearBoots2 },
{ .enabled = &HudScript_Item_GearBoots3, .disabled = &HudScript_Item_GearBoots3 },
{ .enabled = &HudScript_Item_GearHammer1, .disabled = &HudScript_Item_GearHammer1 },
{ .enabled = &HudScript_Item_GearHammer2, .disabled = &HudScript_Item_GearHammer2 },
{ .enabled = &HudScript_Item_GearHammer3, .disabled = &HudScript_Item_GearHammer3 },
{ .enabled = &HudScript_Item_LuckyStar, .disabled = &HudScript_Item_LuckyStar },
{ .enabled = &HudScript_Item_Map, .disabled = &HudScript_Item_Map },
{ .enabled = &HudScript_Item_KoopaFortressKey, .disabled = &HudScript_Item_KoopaFortressKey },
{ .enabled = &HudScript_Item_RuinsKey, .disabled = &HudScript_Item_RuinsKey },
{ .enabled = &HudScript_Item_TubbaCastleKey, .disabled = &HudScript_Item_TubbaCastleKey },
{ .enabled = &HudScript_Item_IcePalaceKey, .disabled = &HudScript_Item_IcePalaceKey },
{ .enabled = &HudScript_Item_BowserCastleKey, .disabled = &HudScript_Item_BowserCastleKey },
{ .enabled = &HudScript_Item_Dolly, .disabled = &HudScript_Item_Dolly },
{ .enabled = &HudScript_Item_KooperShell, .disabled = &HudScript_Item_KooperShell },
{ .enabled = &HudScript_Item_PulseStone, .disabled = &HudScript_Item_PulseStone },
{ .enabled = &HudScript_Item_Artifact, .disabled = &HudScript_Item_Artifact },
{ .enabled = &HudScript_Item_AncientVase, .disabled = &HudScript_Item_AncientVase },
{ .enabled = &HudScript_Item_RuinsStonePyramid, .disabled = &HudScript_Item_RuinsStonePyramid },
{ .enabled = &HudScript_Item_RuinsStoneStar, .disabled = &HudScript_Item_RuinsStoneStar },
{ .enabled = &HudScript_Item_RuinsStoneMoon, .disabled = &HudScript_Item_RuinsStoneMoon },
{ .enabled = &HudScript_Item_ForestPass, .disabled = &HudScript_Item_ForestPass },
{ .enabled = &HudScript_Item_BooRecordOutline, .disabled = &HudScript_Item_BooRecordOutline },
{ .enabled = &HudScript_Item_BooRecord, .disabled = &HudScript_Item_BooRecord },
{ .enabled = &HudScript_Item_BooWeight, .disabled = &HudScript_Item_BooWeight },
{ .enabled = &HudScript_Item_BooPortrait, .disabled = &HudScript_Item_BooPortrait },
{ .enabled = &HudScript_Item_MysticKey, .disabled = &HudScript_Item_MysticKey },
{ .enabled = &HudScript_Item_StoreroomKey, .disabled = &HudScript_Item_StoreroomKey },
{ .enabled = &HudScript_Item_ToyboxTrain, .disabled = &HudScript_Item_ToyboxTrain },
{ .enabled = &HudScript_Item_FryingPan, .disabled = &HudScript_Item_FryingPan },
{ .enabled = &HudScript_Item_Dictionary, .disabled = &HudScript_Item_Dictionary },
{ .enabled = &HudScript_Item_MysteryNote, .disabled = &HudScript_Item_MysteryNote },
{ .enabled = &HudScript_Item_SuspiciousNote, .disabled = &HudScript_Item_SuspiciousNote },
{ .enabled = &HudScript_Item_Seed1, .disabled = &HudScript_Item_Seed1 },
{ .enabled = &HudScript_Item_Seed2, .disabled = &HudScript_Item_Seed2 },
{ .enabled = &HudScript_Item_Seed3, .disabled = &HudScript_Item_Seed3 },
{ .enabled = &HudScript_Item_Seed4, .disabled = &HudScript_Item_Seed4 },
{ .enabled = &HudScript_Item_CrystalBerry, .disabled = &HudScript_Item_CrystalBerry },
{ .enabled = &HudScript_Item_WaterStone, .disabled = &HudScript_Item_WaterStone },
{ .enabled = &HudScript_Item_MagicBean, .disabled = &HudScript_Item_MagicBean },
{ .enabled = &HudScript_Item_FertileSoil, .disabled = &HudScript_Item_FertileSoil },
{ .enabled = &HudScript_Item_MiracleWater, .disabled = &HudScript_Item_MiracleWater },
{ .enabled = &HudScript_Item_UltraStone, .disabled = &HudScript_Item_UltraStone },
{ .enabled = &HudScript_Item_ToadDoll, .disabled = &HudScript_Item_ToadDoll },
{ .enabled = &HudScript_Item_Calculator, .disabled = &HudScript_Item_Calculator },
{ .enabled = &HudScript_Item_Screwdriver, .disabled = &HudScript_Item_Screwdriver },
{ .enabled = &HudScript_Item_CookBook, .disabled = &HudScript_Item_CookBook },
{ .enabled = &HudScript_Item_JadeRaven, .disabled = &HudScript_Item_JadeRaven },
{ .enabled = &HudScript_Item_SnowmanBucket, .disabled = &HudScript_Item_SnowmanBucket },
{ .enabled = &HudScript_Item_SnowmanScarf, .disabled = &HudScript_Item_SnowmanScarf },
{ .enabled = &HudScript_Item_RedKey, .disabled = &HudScript_Item_RedKey },
{ .enabled = &HudScript_Item_BlueKey, .disabled = &HudScript_Item_BlueKey },
{ .enabled = &HudScript_Item_KootPackage, .disabled = &HudScript_Item_KootPackage },
{ .enabled = &HudScript_Item_KootRedJar, .disabled = &HudScript_Item_KootRedJar },
{ .enabled = &HudScript_Item_Melody, .disabled = &HudScript_Item_Melody },
{ .enabled = &HudScript_Item_Lyrics, .disabled = &HudScript_Item_Lyrics },
{ .enabled = &HudScript_Item_Mailbag, .disabled = &HudScript_Item_Mailbag },
{ .enabled = &HudScript_Item_StarStone, .disabled = &HudScript_Item_StarStone },
{ .enabled = &HudScript_Item_SneakyParasol, .disabled = &HudScript_Item_SneakyParasol },
{ .enabled = &HudScript_Item_PeachKey, .disabled = &HudScript_Item_PeachKey },
{ .enabled = &HudScript_Item_UNK_1DC210, .disabled = &HudScript_Item_UNK_1DC210 },
{ .enabled = &HudScript_Item_UNK_1DC430, .disabled = &HudScript_Item_UNK_1DC430 },
{ .enabled = &HudScript_Item_UNK_1DC650, .disabled = &HudScript_Item_UNK_1DC650 },
{ .enabled = &HudScript_Item_UNK_1DC870, .disabled = &HudScript_Item_UNK_1DC870 },
{ .enabled = &HudScript_Item_DojoCard1, .disabled = &HudScript_Item_DojoCard1 },
{ .enabled = &HudScript_Item_DojoCard2, .disabled = &HudScript_Item_DojoCard2 },
{ .enabled = &HudScript_Item_DojoCard3, .disabled = &HudScript_Item_DojoCard3 },
{ .enabled = &HudScript_Item_DojoCard4, .disabled = &HudScript_Item_DojoCard4 },
{ .enabled = &HudScript_Item_DojoCard5, .disabled = &HudScript_Item_DojoCard5 },
{ .enabled = &HudScript_Item_CrystalBall, .disabled = &HudScript_Item_CrystalBall },
{ .enabled = &HudScript_Item_GoldCard, .disabled = &HudScript_Item_GoldCard },
{ .enabled = &HudScript_Item_SilverCard, .disabled = &HudScript_Item_SilverCard },
{ .enabled = &HudScript_Item_KootBook, .disabled = &HudScript_Item_KootBook },
{ .enabled = &HudScript_Item_KootTheTape, .disabled = &HudScript_Item_KootTheTape },
{ .enabled = &HudScript_Item_KootMerluvleeAutograph, .disabled = &HudScript_Item_KootMerluvleeAutograph },
{ .enabled = &HudScript_Item_KootEmptyWallet, .disabled = &HudScript_Item_KootEmptyWallet },
{ .enabled = &HudScript_Item_KootLuigiAutograph, .disabled = &HudScript_Item_KootLuigiAutograph },
{ .enabled = &HudScript_Item_KootShell, .disabled = &HudScript_Item_KootShell },
{ .enabled = &HudScript_Item_KootPhoto, .disabled = &HudScript_Item_KootPhoto },
{ .enabled = &HudScript_Item_KootGlasses, .disabled = &HudScript_Item_KootGlasses },
{ .enabled = &HudScript_Item_Letter, .disabled = &HudScript_Item_Letter_disabled },
{ .enabled = &HudScript_Item_ITEM_089, .disabled = &HudScript_Item_ITEM_089_disabled },
{ .enabled = &HudScript_Item_ITEM_08A, .disabled = &HudScript_Item_ITEM_08A_disabled },
{ .enabled = &HudScript_Item_ITEM_08B, .disabled = &HudScript_Item_ITEM_08B_disabled },
{ .enabled = &HudScript_Item_ITEM_08C, .disabled = &HudScript_Item_ITEM_08C_disabled },
{ .enabled = &HudScript_Item_ITEM_08D, .disabled = &HudScript_Item_ITEM_08D_disabled },
{ .enabled = &HudScript_Item_ITEM_08E, .disabled = &HudScript_Item_ITEM_08E_disabled },
{ .enabled = &HudScript_Item_ITEM_08F, .disabled = &HudScript_Item_ITEM_08F_disabled },
{ .enabled = &HudScript_Item_SpinSmash, .disabled = &HudScript_Item_SpinSmash_disabled },
{ .enabled = &HudScript_Item_Multibounce, .disabled = &HudScript_Item_Multibounce_disabled },
{ .enabled = &HudScript_Item_PowerPlus, .disabled = &HudScript_Item_PowerPlus_disabled },
{ .enabled = &HudScript_Item_DodgeMaster, .disabled = &HudScript_Item_DodgeMaster_disabled },
{ .enabled = &HudScript_Item_PowerBounce, .disabled = &HudScript_Item_PowerBounce_disabled },
{ .enabled = &HudScript_Item_SpikeShield, .disabled = &HudScript_Item_SpikeShield_disabled },
{ .enabled = &HudScript_Item_FirstAttack, .disabled = &HudScript_Item_FirstAttack_disabled },
{ .enabled = &HudScript_Item_HPPlus, .disabled = &HudScript_Item_HPPlus_disabled },
{ .enabled = &HudScript_Item_QuakeHammer, .disabled = &HudScript_Item_QuakeHammer_disabled },
{ .enabled = &HudScript_Item_DoubleDip, .disabled = &HudScript_Item_DoubleDip_disabled },
{ .enabled = &HudScript_Item_PowerQuake, .disabled = &HudScript_Item_PowerQuake_disabled },
{ .enabled = &HudScript_Item_MegaQuake, .disabled = &HudScript_Item_MegaQuake_disabled },
{ .enabled = &HudScript_Item_SleepStomp, .disabled = &HudScript_Item_SleepStomp_disabled },
{ .enabled = &HudScript_Item_SmashCharge, .disabled = &HudScript_Item_SmashCharge_disabled },
{ .enabled = &HudScript_Item_SSmashChg, .disabled = &HudScript_Item_SSmashChg_disabled },
{ .enabled = &HudScript_Item_AutoSmash, .disabled = &HudScript_Item_AutoSmash_disabled },
{ .enabled = &HudScript_Item_FireShield, .disabled = &HudScript_Item_FireShield_disabled },
{ .enabled = &HudScript_Item_JumpCharge, .disabled = &HudScript_Item_JumpCharge_disabled },
{ .enabled = &HudScript_Item_SJumpChg, .disabled = &HudScript_Item_SJumpChg_disabled },
{ .enabled = &HudScript_Item_AutoJump, .disabled = &HudScript_Item_AutoJump_disabled },
{ .enabled = &HudScript_Item_DDownPound, .disabled = &HudScript_Item_DDownPound_disabled },
{ .enabled = &HudScript_Item_AutoMultibounce, .disabled = &HudScript_Item_AutoMultibounce_disabled },
{ .enabled = &HudScript_Item_DizzyStomp, .disabled = &HudScript_Item_DizzyStomp_disabled },
{ .enabled = &HudScript_Item_HammerThrow, .disabled = &HudScript_Item_HammerThrow_disabled },
{ .enabled = &HudScript_Item_SmashCharge0, .disabled = &HudScript_Item_SmashCharge0_disabled },
{ .enabled = &HudScript_Item_PrettyLucky, .disabled = &HudScript_Item_PrettyLucky_disabled },
{ .enabled = &HudScript_Item_FeelingFine, .disabled = &HudScript_Item_FeelingFine_disabled },
{ .enabled = &HudScript_Item_AttackFXA, .disabled = &HudScript_Item_AttackFXA_disabled },
{ .enabled = &HudScript_Item_AllorNothing, .disabled = &HudScript_Item_AllorNothing_disabled },
{ .enabled = &HudScript_Item_HPDrain, .disabled = &HudScript_Item_HPDrain_disabled },
{ .enabled = &HudScript_Item_JumpCharge0, .disabled = &HudScript_Item_JumpCharge0_disabled },
{ .enabled = &HudScript_Item_SlowGo, .disabled = &HudScript_Item_SlowGo_disabled },
{ .enabled = &HudScript_Item_FPPlus, .disabled = &HudScript_Item_FPPlus_disabled },
{ .enabled = &HudScript_Item_MegaRush, .disabled = &HudScript_Item_MegaRush_disabled },
{ .enabled = &HudScript_Item_IcePower, .disabled = &HudScript_Item_IcePower_disabled },
{ .enabled = &HudScript_Item_DefendPlus, .disabled = &HudScript_Item_DefendPlus_disabled },
{ .enabled = &HudScript_Item_PayOff, .disabled = &HudScript_Item_PayOff_disabled },
{ .enabled = &HudScript_Item_MoneyMoney, .disabled = &HudScript_Item_MoneyMoney_disabled },
{ .enabled = &HudScript_Item_ChillOut, .disabled = &HudScript_Item_ChillOut_disabled },
{ .enabled = &HudScript_Item_HappyHeart, .disabled = &HudScript_Item_HappyHeart_disabled },
{ .enabled = &HudScript_Item_ZapTap, .disabled = &HudScript_Item_ZapTap_disabled },
{ .enabled = &HudScript_Item_Berserker, .disabled = &HudScript_Item_Berserker_disabled },
{ .enabled = &HudScript_Item_RightOn, .disabled = &HudScript_Item_RightOn_disabled },
{ .enabled = &HudScript_Item_RunawayPay, .disabled = &HudScript_Item_RunawayPay_disabled },
{ .enabled = &HudScript_Item_Refund, .disabled = &HudScript_Item_Refund_disabled },
{ .enabled = &HudScript_Item_FlowerSaver, .disabled = &HudScript_Item_FlowerSaver_disabled },
{ .enabled = &HudScript_Item_TripleDip, .disabled = &HudScript_Item_TripleDip_disabled },
{ .enabled = &HudScript_Item_FlowerFanatic, .disabled = &HudScript_Item_FlowerFanatic_disabled },
{ .enabled = &HudScript_Item_PowerJump, .disabled = &HudScript_Item_PowerJump_disabled },
{ .enabled = &HudScript_Item_SuperJump, .disabled = &HudScript_Item_SuperJump_disabled },
{ .enabled = &HudScript_Item_MegaJump, .disabled = &HudScript_Item_MegaJump_disabled },
{ .enabled = &HudScript_Item_PowerSmash1, .disabled = &HudScript_Item_PowerSmash1_disabled },
{ .enabled = &HudScript_Item_SuperSmash, .disabled = &HudScript_Item_SuperSmash_disabled },
{ .enabled = &HudScript_Item_MegaSmash, .disabled = &HudScript_Item_MegaSmash_disabled },
{ .enabled = &HudScript_Item_LuckyDay, .disabled = &HudScript_Item_LuckyDay_disabled },
{ .enabled = &HudScript_Item_MegaHPDrain, .disabled = &HudScript_Item_MegaHPDrain_disabled },
{ .enabled = &HudScript_Item_BumpAttack, .disabled = &HudScript_Item_BumpAttack_disabled },
{ .enabled = &HudScript_Item_PUpDDown, .disabled = &HudScript_Item_PUpDDown_disabled },
{ .enabled = &HudScript_Item_PDownDUp, .disabled = &HudScript_Item_PDownDUp_disabled },
{ .enabled = &HudScript_Item_HeartFinder, .disabled = &HudScript_Item_HeartFinder_disabled },
{ .enabled = &HudScript_Item_FlowerFinder, .disabled = &HudScript_Item_FlowerFinder_disabled },
{ .enabled = &HudScript_Item_DizzyAttack, .disabled = &HudScript_Item_DizzyAttack_disabled },
{ .enabled = &HudScript_Item_SpeedySpin, .disabled = &HudScript_Item_SpeedySpin_disabled },
{ .enabled = &HudScript_Item_SpinAttack, .disabled = &HudScript_Item_SpinAttack_disabled },
{ .enabled = &HudScript_Item_ISpy, .disabled = &HudScript_Item_ISpy_disabled },
{ .enabled = &HudScript_Item_PowerRush, .disabled = &HudScript_Item_PowerRush_disabled },
{ .enabled = &HudScript_Item_LastStand, .disabled = &HudScript_Item_LastStand_disabled },
{ .enabled = &HudScript_Item_CloseCall, .disabled = &HudScript_Item_CloseCall_disabled },
{ .enabled = &HudScript_Item_CrazyHeart, .disabled = &HudScript_Item_CrazyHeart_disabled },
{ .enabled = &HudScript_Item_ITEM_0D5, .disabled = &HudScript_Item_ITEM_0D5_disabled },
{ .enabled = &HudScript_Item_ITEM_0D6, .disabled = &HudScript_Item_ITEM_0D6_disabled },
{ .enabled = &HudScript_Item_ITEM_0D7, .disabled = &HudScript_Item_ITEM_0D7_disabled },
{ .enabled = &HudScript_Item_ShrinkSmash, .disabled = &HudScript_Item_ShrinkSmash_disabled },
{ .enabled = &HudScript_Item_ShrinkStomp, .disabled = &HudScript_Item_ShrinkStomp_disabled },
{ .enabled = &HudScript_Item_DDownJump, .disabled = &HudScript_Item_DDownJump_disabled },
{ .enabled = &HudScript_Item_DamageDodge, .disabled = &HudScript_Item_DamageDodge_disabled },
{ .enabled = &HudScript_Item_EarthquakeJump, .disabled = &HudScript_Item_EarthquakeJump_disabled },
{ .enabled = &HudScript_Item_HappyFlower, .disabled = &HudScript_Item_HappyFlower_disabled },
{ .enabled = &HudScript_Item_ITEM_0DE, .disabled = &HudScript_Item_ITEM_0DE_disabled },
{ .enabled = &HudScript_Item_ITEM_0DF, .disabled = &HudScript_Item_ITEM_0DF_disabled },
{ .enabled = &HudScript_Item_DeepFocus3, .disabled = &HudScript_Item_DeepFocus3_disabled },
{ .enabled = &HudScript_Item_SuperFocus, .disabled = &HudScript_Item_SuperFocus_disabled },
{ .enabled = &HudScript_Item_Kaiden, .disabled = &HudScript_Item_Kaiden_disabled },
{ .enabled = &HudScript_Item_QuickChange, .disabled = &HudScript_Item_QuickChange_disabled },
{ .enabled = &HudScript_Item_ITEM_0E4, .disabled = &HudScript_Item_ITEM_0E4_disabled },
{ .enabled = &HudScript_Item_ITEM_0E5, .disabled = &HudScript_Item_ITEM_0E5_disabled },
{ .enabled = &HudScript_Item_ITEM_0E6, .disabled = &HudScript_Item_ITEM_0E6_disabled },
{ .enabled = &HudScript_Item_ITEM_0E7, .disabled = &HudScript_Item_ITEM_0E7_disabled },
{ .enabled = &HudScript_Item_Peekaboo, .disabled = &HudScript_Item_Peekaboo_disabled },
{ .enabled = &HudScript_Item_GroupFocus, .disabled = &HudScript_Item_GroupFocus_disabled },
{ .enabled = &HudScript_Item_AttackFXD, .disabled = &HudScript_Item_AttackFXD_disabled },
{ .enabled = &HudScript_Item_AttackFXB, .disabled = &HudScript_Item_AttackFXB_disabled },
{ .enabled = &HudScript_Item_AttackFXE, .disabled = &HudScript_Item_AttackFXE_disabled },
{ .enabled = &HudScript_Item_AttackFXC, .disabled = &HudScript_Item_AttackFXC_disabled },
{ .enabled = &HudScript_Item_AttackFXF, .disabled = &HudScript_Item_AttackFXF_disabled },
{ .enabled = &HudScript_Item_ITEM_0EF, .disabled = &HudScript_Item_ITEM_0EF_disabled },
{ .enabled = &HudScript_Item_HealthyHealthy, .disabled = &HudScript_Item_HealthyHealthy_disabled },
{ .enabled = &HudScript_Item_ITEM_0F1, .disabled = &HudScript_Item_ITEM_0F1_disabled },
{ .enabled = &HudScript_Item_ITEM_0F2, .disabled = &HudScript_Item_ITEM_0F2_disabled },
{ .enabled = &HudScript_Item_ITEM_0F3, .disabled = &HudScript_Item_ITEM_0F3_disabled },
{ .enabled = &HudScript_Item_ITEM_0F4, .disabled = &HudScript_Item_ITEM_0F4_disabled },
{ .enabled = &HudScript_Item_ITEM_0F5, .disabled = &HudScript_Item_ITEM_0F5_disabled },
{ .enabled = &HudScript_Item_ITEM_0F6, .disabled = &HudScript_Item_ITEM_0F6_disabled },
{ .enabled = &HudScript_Item_ITEM_0F7, .disabled = &HudScript_Item_ITEM_0F7_disabled },
{ .enabled = &HudScript_Item_Mushroom, .disabled = &HudScript_Item_Mushroom_disabled },
{ .enabled = &HudScript_Item_SuperShroom, .disabled = &HudScript_Item_SuperShroom_disabled },
{ .enabled = &HudScript_Item_UltraShroom, .disabled = &HudScript_Item_UltraShroom_disabled },
{ .enabled = &HudScript_Item_LifeShroom, .disabled = &HudScript_Item_LifeShroom_disabled },
{ .enabled = &HudScript_Item_DriedShroom, .disabled = &HudScript_Item_DriedShroom_disabled },
{ .enabled = &HudScript_Item_TastyTonic, .disabled = &HudScript_Item_TastyTonic_disabled },
{ .enabled = &HudScript_Item_SuperSoda, .disabled = &HudScript_Item_SuperSoda_disabled },
{ .enabled = &HudScript_Item_BlueBerry, .disabled = &HudScript_Item_BlueBerry_disabled },
{ .enabled = &HudScript_Item_RedBerry, .disabled = &HudScript_Item_RedBerry_disabled },
{ .enabled = &HudScript_Item_YellowBerry, .disabled = &HudScript_Item_YellowBerry_disabled },
{ .enabled = &HudScript_Item_BubbleBerry, .disabled = &HudScript_Item_BubbleBerry_disabled },
{ .enabled = &HudScript_Item_Goomnut, .disabled = &HudScript_Item_Goomnut_disabled },
{ .enabled = &HudScript_Item_KoopaLeaf, .disabled = &HudScript_Item_KoopaLeaf_disabled },
{ .enabled = &HudScript_Item_DriedPasta, .disabled = &HudScript_Item_DriedPasta_disabled },
{ .enabled = &HudScript_Item_Lime, .disabled = &HudScript_Item_Lime_disabled },
{ .enabled = &HudScript_Item_Lemon, .disabled = &HudScript_Item_Lemon_disabled },
{ .enabled = &HudScript_Item_DriedFruit, .disabled = &HudScript_Item_DriedFruit_disabled },
{ .enabled = &HudScript_Item_StrangeLeaf, .disabled = &HudScript_Item_StrangeLeaf_disabled },
{ .enabled = &HudScript_Item_CakeMix, .disabled = &HudScript_Item_CakeMix_disabled },
{ .enabled = &HudScript_Item_Egg, .disabled = &HudScript_Item_Egg_disabled },
{ .enabled = &HudScript_Item_Coconut, .disabled = &HudScript_Item_Coconut_disabled },
{ .enabled = &HudScript_Item_Melon, .disabled = &HudScript_Item_Melon_disabled },
{ .enabled = &HudScript_Item_StinkyHerb, .disabled = &HudScript_Item_StinkyHerb_disabled },
{ .enabled = &HudScript_Item_IcedPotato, .disabled = &HudScript_Item_IcedPotato_disabled },
{ .enabled = &HudScript_Item_HoneySyrup, .disabled = &HudScript_Item_HoneySyrup_disabled },
{ .enabled = &HudScript_Item_MapleSyrup, .disabled = &HudScript_Item_MapleSyrup_disabled },
{ .enabled = &HudScript_Item_JamminJelly, .disabled = &HudScript_Item_JamminJelly_disabled },
{ .enabled = &HudScript_Item_WhackasBump, .disabled = &HudScript_Item_WhackasBump_disabled },
{ .enabled = &HudScript_Item_Apple, .disabled = &HudScript_Item_Apple_disabled },
{ .enabled = &HudScript_Item_BakingSalt, .disabled = &HudScript_Item_BakingSalt_disabled },
{ .enabled = &HudScript_Item_BakingSugar, .disabled = &HudScript_Item_BakingSugar_disabled },
{ .enabled = &HudScript_Item_BakingEgg, .disabled = &HudScript_Item_BakingEgg_disabled },
{ .enabled = &HudScript_Item_BakingCream, .disabled = &HudScript_Item_BakingCream_disabled },
{ .enabled = &HudScript_Item_BakingStrawberry, .disabled = &HudScript_Item_BakingStrawberry_disabled },
{ .enabled = &HudScript_Item_BakingButter, .disabled = &HudScript_Item_BakingButter_disabled },
{ .enabled = &HudScript_Item_BakingCleanser, .disabled = &HudScript_Item_BakingCleanser_disabled },
{ .enabled = &HudScript_Item_BakingWater, .disabled = &HudScript_Item_BakingWater_disabled },
{ .enabled = &HudScript_Item_BakingFlour, .disabled = &HudScript_Item_BakingFlour_disabled },
{ .enabled = &HudScript_Item_BakingMilk, .disabled = &HudScript_Item_BakingMilk_disabled },
{ .enabled = &HudScript_Item_ITEM_11F, .disabled = &HudScript_Item_ITEM_11F_disabled },
{ .enabled = &HudScript_Item_FireFlower, .disabled = &HudScript_Item_FireFlower_disabled },
{ .enabled = &HudScript_Item_SnowmanDoll, .disabled = &HudScript_Item_SnowmanDoll_disabled },
{ .enabled = &HudScript_Item_ThunderRage, .disabled = &HudScript_Item_ThunderRage_disabled },
{ .enabled = &HudScript_Item_ThunderBolt, .disabled = &HudScript_Item_ThunderBolt_disabled },
{ .enabled = &HudScript_Item_ShootingStar, .disabled = &HudScript_Item_ShootingStar_disabled },
{ .enabled = &HudScript_Item_DustyHammer, .disabled = &HudScript_Item_DustyHammer_disabled },
{ .enabled = &HudScript_Item_Pebble, .disabled = &HudScript_Item_Pebble_disabled },
{ .enabled = &HudScript_Item_ITEM_127, .disabled = &HudScript_Item_ITEM_127_disabled },
{ .enabled = &HudScript_Item_StoneCap, .disabled = &HudScript_Item_StoneCap_disabled },
{ .enabled = &HudScript_Item_VoltShroom, .disabled = &HudScript_Item_VoltShroom_disabled },
{ .enabled = &HudScript_Item_PowerStar, .disabled = &HudScript_Item_PowerStar_disabled },
{ .enabled = &HudScript_Item_Parasol, .disabled = &HudScript_Item_Parasol_disabled },
{ .enabled = &HudScript_Item_MagicMirror, .disabled = &HudScript_Item_MagicMirror_disabled },
{ .enabled = &HudScript_Item_ITEM_12D, .disabled = &HudScript_Item_ITEM_12D_disabled },
{ .enabled = &HudScript_Item_ITEM_12E, .disabled = &HudScript_Item_ITEM_12E_disabled },
{ .enabled = &HudScript_Item_ITEM_12F, .disabled = &HudScript_Item_ITEM_12F_disabled },
{ .enabled = &HudScript_Item_SleepySheep, .disabled = &HudScript_Item_SleepySheep_disabled },
{ .enabled = &HudScript_Item_XBandage, .disabled = &HudScript_Item_XBandage_disabled },
{ .enabled = &HudScript_Item_POWBlock, .disabled = &HudScript_Item_POWBlock_disabled },
{ .enabled = &HudScript_Item_HustleDrink, .disabled = &HudScript_Item_HustleDrink_disabled },
{ .enabled = &HudScript_Item_StopWatch, .disabled = &HudScript_Item_StopWatch_disabled },
{ .enabled = &HudScript_Item_DizzyDial, .disabled = &HudScript_Item_DizzyDial_disabled },
{ .enabled = &HudScript_Item_ITEM_136, .disabled = &HudScript_Item_ITEM_136_disabled },
{ .enabled = &HudScript_Item_ITEM_137, .disabled = &HudScript_Item_ITEM_137_disabled },
{ .enabled = &HudScript_Item_PleaseComeBack, .disabled = &HudScript_Item_PleaseComeBack_disabled },
{ .enabled = &HudScript_Item_ITEM_139, .disabled = &HudScript_Item_ITEM_139_disabled },
{ .enabled = &HudScript_Item_FrightJar, .disabled = &HudScript_Item_FrightJar_disabled },
{ .enabled = &HudScript_Item_Mystery, .disabled = &HudScript_Item_Mystery_disabled },
{ .enabled = &HudScript_Item_RepelGel, .disabled = &HudScript_Item_RepelGel_disabled },
{ .enabled = &HudScript_Item_InsecticideHerb, .disabled = &HudScript_Item_InsecticideHerb_disabled },
{ .enabled = &HudScript_Item_ITEM_13E, .disabled = &HudScript_Item_ITEM_13E_disabled },
{ .enabled = &HudScript_Item_ITEM_13F, .disabled = &HudScript_Item_ITEM_13F_disabled },
{ .enabled = &HudScript_Item_Present, .disabled = &HudScript_Item_Present },
{ .enabled = &HudScript_Item_CakeDone, .disabled = &HudScript_Item_CakeDone },
{ .enabled = &HudScript_Item_CakeBaked, .disabled = &HudScript_Item_CakeBaked },
{ .enabled = &HudScript_Item_CakePan, .disabled = &HudScript_Item_CakePan },
{ .enabled = &HudScript_Item_CakeBatter, .disabled = &HudScript_Item_CakeBatter },
{ .enabled = &HudScript_Item_CakeBowl, .disabled = &HudScript_Item_CakeBowl },
{ .enabled = &HudScript_Item_CakeMixed, .disabled = &HudScript_Item_CakeMixed },
{ .enabled = &HudScript_Item_CakeIcing, .disabled = &HudScript_Item_CakeIcing },
{ .enabled = &HudScript_Item_CakeBerries, .disabled = &HudScript_Item_CakeBerries },
{ .enabled = (HudScript*)0x80109338, .disabled = (HudScript*)0x801093D8 },
{ .enabled = &HudScript_Item_Hammer1, .disabled = &HudScript_Item_Hammer1 },
{ .enabled = &HudScript_Item_Hammer2, .disabled = &HudScript_Item_Hammer2 },
{ .enabled = &HudScript_Item_Hammer3, .disabled = &HudScript_Item_Hammer3 },
{ .enabled = &HudScript_Item_Boots1, .disabled = &HudScript_Item_Boots1 },
{ .enabled = &HudScript_Item_Boots2, .disabled = &HudScript_Item_Boots2 },
{ .enabled = &HudScript_Item_Boots3, .disabled = &HudScript_Item_Boots3 },
{ .enabled = &HudScript_Item_Items, .disabled = &HudScript_Item_Items }
};

s32 ItemScript_Jump[] = {
0x00000001, 0x000000FF, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CompleteCake[] = {
0x00000001, 0x000000FF, 0x00000000, 0x00000200, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeDone[] = {
0x00000001, 0x000000FF, 0x00000220, 0x00000420, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeBaked[] = {
0x00000001, 0x000000FF, 0x00000440, 0x00000640, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakePan[] = {
0x00000001, 0x000000FF, 0x00000660, 0x00000860, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeBatter[] = {
0x00000001, 0x000000FF, 0x00000880, 0x00000A80, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeBowl[] = {
0x00000001, 0x000000FF, 0x00000AA0, 0x00000CA0, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeMixed[] = {
0x00000001, 0x000000FF, 0x00000CC0, 0x00000EC0, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeIcing[] = {
0x00000001, 0x000000FF, 0x00000EE0, 0x000010E0, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_CakeBerries[] = {
0x00000001, 0x000000FF, 0x00001100, 0x00001300, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Hammer1[] = {
0x00000001, 0x000000FF, 0x0002D940, 0x0002DB40, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Hammer2[] = {
0x00000001, 0x000000FF, 0x0002DB80, 0x0002DD80, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Hammer3[] = {
0x00000001, 0x000000FF, 0x0002DDC0, 0x0002DFC0, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Boots1[] = {
0x00000001, 0x000000FF, 0x0002E000, 0x0002E200, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Boots2[] = {
0x00000001, 0x000000FF, 0x0002E240, 0x0002E440, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Boots3[] = {
0x00000001, 0x000000FF, 0x0002E480, 0x0002E680, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_Items[] = {
0x00000001, 0x000000FF, 0x0002E6C0, 0x0002E8C0, 0x00000000, 0x00000000, 0x00000000
};

s32 ItemScript_PleaseComeBack[] = {
0x00000001, 0x0000003C, 0x00013BC0, 0x00013DC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_139[] = {
0x00000001, 0x0000003C, 0x00013E00, 0x00014000, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FrightJar[] = {
0x00000001, 0x0000003C, 0x00014040, 0x00014240, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Mystery[] = {
0x00000001, 0x0000003C, 0x00014280, 0x00014480, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RepelGel[] = {
0x00000001, 0x0000003C, 0x000144C0, 0x000146C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_InsecticideHerb[] = {
0x00000001, 0x0000003C, 0x00014700, 0x00014900, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_13E[] = {
0x00000001, 0x0000003C, 0x00014940, 0x00014B40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_13F[] = {
0x00000001, 0x0000003C, 0x00014B80, 0x00014D80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GearBoots1[] = {
0x00000001, 0x0000003C, 0x00001320, 0x00001520, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GearBoots2[] = {
0x00000001, 0x0000003C, 0x00001540, 0x00001740, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GearBoots3[] = {
0x00000001, 0x0000003C, 0x00001760, 0x00001960, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GearHammer1[] = {
0x00000001, 0x0000003C, 0x00001980, 0x00001B80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GearHammer2[] = {
0x00000001, 0x0000003C, 0x00001BA0, 0x00001DA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GearHammer3[] = {
0x00000001, 0x0000003C, 0x00001DC0, 0x00001FC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_LuckyStar[] = {
0x00000001, 0x0000003C, 0x00001FE0, 0x000021E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Map[] = {
0x00000001, 0x0000003C, 0x00002200, 0x00002400, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KoopaFortressKey[] = {
0x00000001, 0x0000003C, 0x00009020, 0x00009220, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RuinsKey[] = {
0x00000001, 0x0000003C, 0x00009240, 0x00009440, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_TubbaCastleKey[] = {
0x00000001, 0x0000003C, 0x00009460, 0x00009660, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_IcePalaceKey[] = {
0x00000001, 0x0000003C, 0x00009680, 0x00009880, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BowserCastleKey[] = {
0x00000001, 0x0000003C, 0x000098A0, 0x00009AA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Dolly[] = {
0x00000001, 0x0000003C, 0x00009AC0, 0x00009CC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KooperShell[] = {
0x00000001, 0x0000003C, 0x00009CE0, 0x00009EE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PulseStone[] = {
0x00000001, 0x0000003C, 0x00009F00, 0x0000A100, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Artifact[] = {
0x00000001, 0x0000003C, 0x0000A120, 0x0000A320, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AncientVase[] = {
0x00000001, 0x0000003C, 0x0000A340, 0x0000A540, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RuinsStonePyramid[] = {
0x00000001, 0x0000003C, 0x0000A560, 0x0000A760, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RuinsStoneStar[] = {
0x00000001, 0x0000003C, 0x0000A780, 0x0000A980, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RuinsStoneMoon[] = {
0x00000001, 0x0000003C, 0x0000A9A0, 0x0000ABA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ForestPass[] = {
0x00000001, 0x0000003C, 0x0000ABC0, 0x0000ADC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BooRecordOutline[] = {
0x00000001, 0x0000003C, 0x0000ADE0, 0x0000AFE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BooRecord[] = {
0x00000001, 0x0000003C, 0x0000B000, 0x0000B200, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BooWeight[] = {
0x00000001, 0x0000003C, 0x0000B220, 0x0000B420, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BoosPortrait[] = {
0x00000001, 0x0000003C, 0x0000B440, 0x0000B640, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MysticKey[] = {
0x00000001, 0x0000003C, 0x0000B660, 0x0000B860, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StoreroomKey[] = {
0x00000001, 0x0000003C, 0x0000B880, 0x0000BA80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ToyTrain[] = {
0x00000001, 0x0000003C, 0x0000BAA0, 0x0000BCA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FryingPan[] = {
0x00000001, 0x0000003C, 0x0000BCC0, 0x0000BEC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Dictionary[] = {
0x00000001, 0x0000003C, 0x0000BEE0, 0x0000C0E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MysteryNote[] = {
0x00000001, 0x0000003C, 0x0000C100, 0x0000C300, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SuspiciousNote[] = {
0x00000001, 0x0000003C, 0x0000C320, 0x0000C520, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MagicalSeed1[] = {
0x00000001, 0x0000003C, 0x0000C540, 0x0000C740, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MagicalSeed2[] = {
0x00000001, 0x0000003C, 0x0000C760, 0x0000C960, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MagicalSeed3[] = {
0x00000001, 0x0000003C, 0x0000C980, 0x0000CB80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MagicalSeed4[] = {
0x00000001, 0x0000003C, 0x0000CBA0, 0x0000CDA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_CrystalBerry[] = {
0x00000001, 0x0000003C, 0x0000CDC0, 0x0000CFC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_WaterStone[] = {
0x00000001, 0x0000003C, 0x0000CFE0, 0x0000D1E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MagicalBean[] = {
0x00000001, 0x0000003C, 0x0000D200, 0x0000D400, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FertileSoil[] = {
0x00000001, 0x0000003C, 0x0000D420, 0x0000D620, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MiracleWater[] = {
0x00000001, 0x0000003C, 0x0000D640, 0x0000D840, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_UltraStone[] = {
0x00000001, 0x0000003C, 0x0000D860, 0x0000DA60, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ToadDoll[] = {
0x00000001, 0x0000003C, 0x0000DAA0, 0x0000DCA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Calculator[] = {
0x00000001, 0x0000003C, 0x0000DCC0, 0x0000DEC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Screwdriver[] = {
0x00000001, 0x0000003C, 0x0000DEE0, 0x0000E0E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Cookbook[] = {
0x00000001, 0x0000003C, 0x0000E100, 0x0000E300, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JadeRaven[] = {
0x00000001, 0x0000003C, 0x0000E320, 0x0000E520, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SnowmanBucket[] = {
0x00000001, 0x0000003C, 0x0000E540, 0x0000E740, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SnowmanScarf[] = {
0x00000001, 0x0000003C, 0x0000E760, 0x0000E960, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RedKey[] = {
0x00000001, 0x0000003C, 0x0000E980, 0x0000EB80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BlueKey[] = {
0x00000001, 0x0000003C, 0x0000EBC0, 0x0000EDC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootPackage[] = {
0x00000001, 0x0000003C, 0x0000EDE0, 0x0000EFE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootRedJar[] = {
0x00000001, 0x0000003C, 0x0000F000, 0x0000F200, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Melody[] = {
0x00000001, 0x0000003C, 0x0000F220, 0x0000F420, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Lyrics[] = {
0x00000001, 0x0000003C, 0x0000F440, 0x0000F640, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Mailbag[] = {
0x00000001, 0x0000003C, 0x0000F660, 0x0000F860, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StarStone[] = {
0x00000001, 0x0000003C, 0x0000F880, 0x0000FA80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SneakyParasol[] = {
0x00000001, 0x0000003C, 0x0000FAA0, 0x0000FCA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PeachKey[] = {
0x00000001, 0x0000003C, 0x0000FCE0, 0x0000FEE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_1DC210[] = {
0x00000001, 0x0000003C, 0x0000FF00, 0x00010100, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_1DC430[] = {
0x00000001, 0x0000003C, 0x00010120, 0x00010320, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_1DC650[] = {
0x00000001, 0x0000003C, 0x00010340, 0x00010540, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_1DC870[] = {
0x00000001, 0x0000003C, 0x00010560, 0x00010760, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DojoCard1[] = {
0x00000001, 0x0000003C, 0x00010780, 0x00010980, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DojoCard2[] = {
0x00000001, 0x0000003C, 0x000109A0, 0x00010BA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DojoCard3[] = {
0x00000001, 0x0000003C, 0x00010BC0, 0x00010DC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DojoCard4[] = {
0x00000001, 0x0000003C, 0x00010E00, 0x00011000, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DojoCard5[] = {
0x00000001, 0x0000003C, 0x00011020, 0x00011220, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_CrystalBall[] = {
0x00000001, 0x0000003C, 0x00011240, 0x00011440, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GoldCard[] = {
0x00000001, 0x0000003C, 0x00011460, 0x00011660, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SilverCard[] = {
0x00000001, 0x0000003C, 0x00011680, 0x00011880, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootBook[] = {
0x00000001, 0x0000003C, 0x000118A0, 0x00011AA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootTheTape[] = {
0x00000001, 0x0000003C, 0x00011AC0, 0x00011CC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootAutographMerluvlee[] = {
0x00000001, 0x0000003C, 0x00011CE0, 0x00011EE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootEmptyWallet[] = {
0x00000001, 0x0000003C, 0x00011F20, 0x00012120, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootAutographLuigi[] = {
0x00000001, 0x0000003C, 0x00012140, 0x00012340, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootKoopaShell[] = {
0x00000001, 0x0000003C, 0x00012360, 0x00012560, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootOldPhoto[] = {
0x00000001, 0x0000003C, 0x00012580, 0x00012780, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KootGlasses[] = {
0x00000001, 0x0000003C, 0x000127A0, 0x000129A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Letter[] = {
0x00000001, 0x0000003C, 0x000129C0, 0x00012BC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_089[] = {
0x00000001, 0x0000003C, 0x00012C00, 0x00012E00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_08A[] = {
0x00000001, 0x0000003C, 0x00012E40, 0x00013040, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_08B[] = {
0x00000001, 0x0000003C, 0x00013080, 0x00013280, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_08C[] = {
0x00000001, 0x0000003C, 0x000132C0, 0x000134C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_08D[] = {
0x00000001, 0x0000003C, 0x00013500, 0x00013700, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_08E[] = {
0x00000001, 0x0000003C, 0x00013740, 0x00013940, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_08F[] = {
0x00000001, 0x0000003C, 0x00013980, 0x00013B80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SpinSmash[] = {
0x00000001, 0x0000003C, 0x00014DC0, 0x00014FC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Multibounce[] = {
0x00000001, 0x0000003C, 0x00015000, 0x00015200, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerPlus[] = {
0x00000001, 0x0000003C, 0x00015240, 0x00015440, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DodgeMaster[] = {
0x00000001, 0x0000003C, 0x00015480, 0x00015680, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerBounce[] = {
0x00000001, 0x0000003C, 0x000156C0, 0x000158C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SpikeShield[] = {
0x00000001, 0x0000003C, 0x00015900, 0x00015B00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FirstAttack[] = {
0x00000001, 0x0000003C, 0x00015B40, 0x00015D40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HPPlus[] = {
0x00000001, 0x0000003C, 0x00015D80, 0x00015F80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_QuakeHammer[] = {
0x00000001, 0x0000003C, 0x00015FC0, 0x000161C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DoubleDip[] = {
0x00000001, 0x0000003C, 0x00016200, 0x00016400, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerQuake[] = {
0x00000001, 0x0000003C, 0x00016440, 0x00016640, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MegaQuake[] = {
0x00000001, 0x0000003C, 0x00016680, 0x00016880, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SleepStomp[] = {
0x00000001, 0x0000003C, 0x000168C0, 0x00016AC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SmashCharge[] = {
0x00000001, 0x0000003C, 0x00016B00, 0x00016D00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SSmashChg[] = {
0x00000001, 0x0000003C, 0x00016D40, 0x00016F40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AutoSmash[] = {
0x00000001, 0x0000003C, 0x00016F80, 0x00017180, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FireShield[] = {
0x00000001, 0x0000003C, 0x000171C0, 0x000173C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JumpCharge[] = {
0x00000001, 0x0000003C, 0x00017400, 0x00017600, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SJumpChg[] = {
0x00000001, 0x0000003C, 0x00017640, 0x00017840, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AutoJump[] = {
0x00000001, 0x0000003C, 0x00017880, 0x00017A80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DDownPound[] = {
0x00000001, 0x0000003C, 0x00017AC0, 0x00017CC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AutoMultibounce[] = {
0x00000001, 0x0000003C, 0x00017D00, 0x00017F00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DizzyStomp[] = {
0x00000001, 0x0000003C, 0x00017F40, 0x00018140, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HammerThrow[] = {
0x00000001, 0x0000003C, 0x00018180, 0x00018380, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SmashCharge0[] = {
0x00000001, 0x0000003C, 0x000183C0, 0x000185C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PrettyLucky[] = {
0x00000001, 0x0000003C, 0x00018600, 0x00018800, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FeelingFine[] = {
0x00000001, 0x0000003C, 0x00018840, 0x00018A40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AttackFXA[] = {
0x00000001, 0x0000003C, 0x00018A80, 0x00018C80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AllorNothing[] = {
0x00000001, 0x0000003C, 0x00018CC0, 0x00018EC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HPDrain[] = {
0x00000001, 0x0000003C, 0x00018F00, 0x00019100, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JumpCharge0[] = {
0x00000001, 0x0000003C, 0x00019140, 0x00019340, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SlowGo[] = {
0x00000001, 0x0000003C, 0x00019380, 0x00019580, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FPPlus[] = {
0x00000001, 0x0000003C, 0x000195C0, 0x000197C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MegaRush[] = {
0x00000001, 0x0000003C, 0x00019800, 0x00019A00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_IcePower[] = {
0x00000001, 0x0000003C, 0x00019A40, 0x00019C40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DefendPlus[] = {
0x00000001, 0x0000003C, 0x00019C80, 0x00019E80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PayOff[] = {
0x00000001, 0x0000003C, 0x00019EC0, 0x0001A0C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MoneyMoney[] = {
0x00000001, 0x0000003C, 0x0001A100, 0x0001A300, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ChillOut[] = {
0x00000001, 0x0000003C, 0x0001A340, 0x0001A540, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HappyHeart[] = {
0x00000001, 0x0000003C, 0x0001A580, 0x0001A780, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ZapTap[] = {
0x00000001, 0x0000003C, 0x0001A7C0, 0x0001A9C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Berserker[] = {
0x00000001, 0x0000003C, 0x0001AA00, 0x0001AC00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RightOn[] = {
0x00000001, 0x0000003C, 0x0001AC40, 0x0001AE40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RunawayPay[] = {
0x00000001, 0x0000003C, 0x0001AE80, 0x0001B080, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Refund[] = {
0x00000001, 0x0000003C, 0x0001B0C0, 0x0001B2C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FlowerSaver[] = {
0x00000001, 0x0000003C, 0x0001B300, 0x0001B500, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_TripleDip[] = {
0x00000001, 0x0000003C, 0x0001B540, 0x0001B740, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FlowerFanatic[] = {
0x00000001, 0x0000003C, 0x0001B780, 0x0001B980, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerJump[] = {
0x00000001, 0x0000003C, 0x0001B9C0, 0x0001BBC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SuperJump[] = {
0x00000001, 0x0000003C, 0x0001BC00, 0x0001BE00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MegaJump[] = {
0x00000001, 0x0000003C, 0x0001BE40, 0x0001C040, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerSmash[] = {
0x00000001, 0x0000003C, 0x0001C080, 0x0001C280, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SuperSmash[] = {
0x00000001, 0x0000003C, 0x0001C2C0, 0x0001C4C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MegaSmash[] = {
0x00000001, 0x0000003C, 0x0001C500, 0x0001C700, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_LuckyDay[] = {
0x00000001, 0x0000003C, 0x0001C740, 0x0001C940, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MegaHPDrain[] = {
0x00000001, 0x0000003C, 0x0001C980, 0x0001CB80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BumpAttack[] = {
0x00000001, 0x0000003C, 0x0001CBC0, 0x0001CDC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PUpDDown[] = {
0x00000001, 0x0000003C, 0x0001CE00, 0x0001D000, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PDownDUp[] = {
0x00000001, 0x0000003C, 0x0001D040, 0x0001D240, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HeartFinder[] = {
0x00000001, 0x0000003C, 0x0001D280, 0x0001D480, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FlowerFinder[] = {
0x00000001, 0x0000003C, 0x0001D4C0, 0x0001D6C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DizzyAttack[] = {
0x00000001, 0x0000003C, 0x0001D700, 0x0001D900, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SpeedySpin[] = {
0x00000001, 0x0000003C, 0x0001D940, 0x0001DB40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SpinAttack[] = {
0x00000001, 0x0000003C, 0x0001DB80, 0x0001DD80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ISpy[] = {
0x00000001, 0x0000003C, 0x0001DDC0, 0x0001DFC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerRush[] = {
0x00000001, 0x0000003C, 0x0001E000, 0x0001E200, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_LastStand[] = {
0x00000001, 0x0000003C, 0x0001E240, 0x0001E440, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_CloseCall[] = {
0x00000001, 0x0000003C, 0x0001E480, 0x0001E680, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_CrazyHeart[] = {
0x00000001, 0x0000003C, 0x0001E6C0, 0x0001E8C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0D5[] = {
0x00000001, 0x0000003C, 0x0001E900, 0x0001EB00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0D6[] = {
0x00000001, 0x0000003C, 0x0001EB40, 0x0001ED40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0D7[] = {
0x00000001, 0x0000003C, 0x0001ED80, 0x0001EF80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ShrinkSmash[] = {
0x00000001, 0x0000003C, 0x0001EFC0, 0x0001F1C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ShrinkStomp[] = {
0x00000001, 0x0000003C, 0x0001F200, 0x0001F400, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DDownJump[] = {
0x00000001, 0x0000003C, 0x0001F440, 0x0001F640, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DamageDodge[] = {
0x00000001, 0x0000003C, 0x0001F680, 0x0001F880, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_EarthquakeJump[] = {
0x00000001, 0x0000003C, 0x0001F8C0, 0x0001FAC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HappyFlower[] = {
0x00000001, 0x0000003C, 0x0001FB00, 0x0001FD00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HappyCoin[] = {
0x00000001, 0x0000003C, 0x0001FD40, 0x0001FF40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0DF[] = {
0x00000001, 0x0000003C, 0x0001FF80, 0x00020180, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DeepFocus[] = {
0x00000001, 0x0000003C, 0x000201C0, 0x000203C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SuperFocus[] = {
0x00000001, 0x0000003C, 0x00020400, 0x00020600, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Kaiden[] = {
0x00000001, 0x0000003C, 0x00020640, 0x00020840, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_QuickChange[] = {
0x00000001, 0x0000003C, 0x00020880, 0x00020A80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0E4[] = {
0x00000001, 0x0000003C, 0x00020AC0, 0x00020CC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0E5[] = {
0x00000001, 0x0000003C, 0x00020D00, 0x00020F00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0E6[] = {
0x00000001, 0x0000003C, 0x00020F40, 0x00021140, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0E7[] = {
0x00000001, 0x0000003C, 0x00021180, 0x00021380, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Peekaboo[] = {
0x00000001, 0x0000003C, 0x000213C0, 0x000215C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_GroupFocus[] = {
0x00000001, 0x0000003C, 0x00021600, 0x00021800, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AttackFXD[] = {
0x00000001, 0x0000003C, 0x00021840, 0x00021A40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AttackFXB[] = {
0x00000001, 0x0000003C, 0x00021A80, 0x00021C80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AttackFXE[] = {
0x00000001, 0x0000003C, 0x00021CC0, 0x00021EC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AttackFXC[] = {
0x00000001, 0x0000003C, 0x00021F00, 0x00022100, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_AttackFXF[] = {
0x00000001, 0x0000003C, 0x00022140, 0x00022340, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0EF[] = {
0x00000001, 0x0000003C, 0x00022380, 0x00022580, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HealthyHealthy[] = {
0x00000001, 0x0000003C, 0x000225C0, 0x000227C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F1[] = {
0x00000001, 0x0000003C, 0x00022800, 0x00022A00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F2[] = {
0x00000001, 0x0000003C, 0x00022A40, 0x00022C40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F3[] = {
0x00000001, 0x0000003C, 0x00022C80, 0x00022E80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F4[] = {
0x00000001, 0x0000003C, 0x00022EC0, 0x000230C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F5[] = {
0x00000001, 0x0000003C, 0x00023100, 0x00023300, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F6[] = {
0x00000001, 0x0000003C, 0x00023340, 0x00023540, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_0F7[] = {
0x00000001, 0x0000003C, 0x00023580, 0x00023780, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Heart[] = {
0x00000001, 0x0000000A, 0x00030A60, 0x00030B80, 0x00000000, 0x00000000, 0x00000001, 0x00000006, 0x00030BA0, 0x00030CC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Coin[] = {
0x00000003, 0x00000001, 0x00000003, 0x0002F5C0, 0x0002F6E0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002F700, 0x0002F820, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FAC0, 0x0002FBE0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FC00, 0x0002FD20, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FD40, 0x0002FE60, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FE80, 0x0002FFA0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FFC0, 0x000300E0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x00030100, 0x00030220, 0x00000000, 0x00000000, 0x00000004, 0x00000064, 0x00000032, 0x00000001, 0x00000003, 0x0002F5C0, 0x0002F6E0, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x0002F700, 0x0002F820, 0x00000000, 0x00000000, 0x00000001, 0x00000001, 0x0002F840, 0x0002F960, 0x00000000, 0x00000000, 0x00000001, 0x00000001, 0x0002F980, 0x0002FAA0, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x0002FAC0, 0x0002FBE0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FC00, 0x0002FD20, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FD40, 0x0002FE60, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FE80, 0x0002FFA0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x0002FFC0, 0x000300E0, 0x00000000, 0x00000000, 0x00000001, 0x00000003, 0x00030100, 0x00030220, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HeartPiece[] = {
0x00000001, 0x0000003C, 0x00030CE0, 0x00030E00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StarPoint[] = {
0x00000001, 0x00000002, 0x00030E20, 0x00030F40, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x00030F60, 0x00031080, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x000310A0, 0x000311C0, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x000311E0, 0x00031300, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x00031320, 0x00031440, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x00031460, 0x00031580, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x000315A0, 0x000316C0, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x000316E0, 0x00031800, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HeartPoint[] = {
0x00000001, 0x00000008, 0x0002E900, 0x0002EB00, 0x00000000, 0x00000000, 0x00000001, 0x00000005, 0x0002EB20, 0x0002ED20, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x0002ED40, 0x0002EF40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FlowerPoint[] = {
0x00000001, 0x00000008, 0x0002EF60, 0x0002F160, 0x00000000, 0x00000000, 0x00000001, 0x00000005, 0x0002F180, 0x0002F380, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x0002F3A0, 0x0002F5A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StarPiece[] = {
0x00000001, 0x0000000C, 0x00030400, 0x00030600, 0x00000000, 0x00000000, 0x00000001, 0x00000004, 0x00030620, 0x00030820, 0x00000000, 0x00000000, 0x00000001, 0x0000000C, 0x00030840, 0x00030A40, 0x00000000, 0x00000000, 0x00000001, 0x00000004, 0x00030620, 0x00030820, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SpicySoup[] = {
0x00000001, 0x0000003C, 0x00002420, 0x00002620, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ApplePie[] = {
0x00000001, 0x0000003C, 0x00002660, 0x00002860, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HoneyUltra[] = {
0x00000001, 0x0000003C, 0x000028A0, 0x00002AA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MapleUltra[] = {
0x00000001, 0x0000003C, 0x00002AE0, 0x00002CE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JellyUltra[] = {
0x00000001, 0x0000003C, 0x00002D20, 0x00002F20, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Koopasta[] = {
0x00000001, 0x0000003C, 0x00002F60, 0x00003160, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FriedShroom[] = {
0x00000001, 0x0000003C, 0x000031A0, 0x000033A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ShroomCake[] = {
0x00000001, 0x0000003C, 0x000033E0, 0x000035E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ShroomSteak[] = {
0x00000001, 0x0000003C, 0x00003620, 0x00003820, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HotShroom[] = {
0x00000001, 0x0000003C, 0x00003860, 0x00003A60, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SweetShroom[] = {
0x00000001, 0x0000003C, 0x00003AA0, 0x00003CA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HealthyJuice[] = {
0x00000001, 0x0000003C, 0x00003CE0, 0x00003EE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BlandMeal[] = {
0x00000001, 0x0000003C, 0x00003F20, 0x00004120, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_YummyMeal[] = {
0x00000001, 0x0000003C, 0x00004160, 0x00004360, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DeluxeFeast[] = {
0x00000001, 0x0000003C, 0x000043A0, 0x000045A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SpecialShake[] = {
0x00000001, 0x0000003C, 0x000045E0, 0x000047E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BigCookie[] = {
0x00000001, 0x0000003C, 0x00004820, 0x00004A20, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Cake[] = {
0x00000001, 0x0000003C, 0x00004A60, 0x00004C60, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Mistake[] = {
0x00000001, 0x0000003C, 0x00004CA0, 0x00004EA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KoopaTea[] = {
0x00000001, 0x0000003C, 0x00004EE0, 0x000050E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HoneySuper[] = {
0x00000001, 0x0000003C, 0x00005120, 0x00005320, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MapleSuper[] = {
0x00000001, 0x0000003C, 0x00005360, 0x00005560, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JellySuper[] = {
0x00000001, 0x0000003C, 0x000055A0, 0x000057A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Spaghetti[] = {
0x00000001, 0x0000003C, 0x000057E0, 0x000059E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_EggMissile[] = {
0x00000001, 0x0000003C, 0x00005A20, 0x00005C20, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FriedEgg[] = {
0x00000001, 0x0000003C, 0x00005C60, 0x00005E60, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HoneyShroom[] = {
0x00000001, 0x0000003C, 0x00005EA0, 0x000060A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HoneyCandy[] = {
0x00000001, 0x0000003C, 0x000060E0, 0x000062E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ElectroPop[] = {
0x00000001, 0x0000003C, 0x00006320, 0x00006520, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FirePop[] = {
0x00000001, 0x0000003C, 0x00006560, 0x00006760, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_LimeCandy[] = {
0x00000001, 0x0000003C, 0x000067A0, 0x000069A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_CocoPop[] = {
0x00000001, 0x0000003C, 0x000069E0, 0x00006BE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_LemonCandy[] = {
0x00000001, 0x0000003C, 0x00006C20, 0x00006E20, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JellyPop[] = {
0x00000001, 0x0000003C, 0x00006E60, 0x00007060, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StrangeCake[] = {
0x00000001, 0x0000003C, 0x000070A0, 0x000072A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KookyCookie[] = {
0x00000001, 0x0000003C, 0x000072E0, 0x000074E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FrozenFries[] = {
0x00000001, 0x0000003C, 0x00007520, 0x00007720, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PotatoSalad[] = {
0x00000001, 0x0000003C, 0x00007760, 0x00007960, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_NuttyCake[] = {
0x00000001, 0x0000003C, 0x000079A0, 0x00007BA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MapleShroom[] = {
0x00000001, 0x0000003C, 0x00007BE0, 0x00007DE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BoiledEgg[] = {
0x00000001, 0x0000003C, 0x00007E20, 0x00008020, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_YoshiCookie[] = {
0x00000001, 0x0000003C, 0x00008060, 0x00008260, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JellyShroom[] = {
0x00000001, 0x0000003C, 0x000082A0, 0x000084A0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_02C[] = {
0x00000001, 0x0000003C, 0x000084E0, 0x000086E0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_02D[] = {
0x00000001, 0x0000003C, 0x00008720, 0x00008920, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_02E[] = {
0x00000001, 0x0000003C, 0x00008960, 0x00008B60, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_02F[] = {
0x00000001, 0x0000003C, 0x00008BA0, 0x00008DA0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_030[] = {
0x00000001, 0x0000003C, 0x00008DE0, 0x00008FE0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_FireFlower[] = {
0x00000001, 0x0000003C, 0x0002A3C0, 0x0002A5C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SnowmanDoll[] = {
0x00000001, 0x0000003C, 0x0002A600, 0x0002A800, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ThunderRage[] = {
0x00000001, 0x0000003C, 0x0002A840, 0x0002AA40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ThunderBolt[] = {
0x00000001, 0x0000003C, 0x0002AA80, 0x0002AC80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ShootingStar[] = {
0x00000001, 0x0000003C, 0x0002ACC0, 0x0002AEC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DustyHammer[] = {
0x00000001, 0x0000003C, 0x0002AF00, 0x0002B100, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Pebble[] = {
0x00000001, 0x0000003C, 0x0002B140, 0x0002B340, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_127[] = {
0x00000001, 0x0000003C, 0x0002B380, 0x0002B580, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StoneCap[] = {
0x00000001, 0x0000003C, 0x0002B5C0, 0x0002B7C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_VoltShroom[] = {
0x00000001, 0x0000003C, 0x0002B800, 0x0002BA00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_PowerStar[] = {
0x00000001, 0x0000003C, 0x0002BA40, 0x0002BC40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Parasol[] = {
0x00000001, 0x0000003C, 0x0002BC80, 0x0002BE80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MagicMirror[] = {
0x00000001, 0x0000003C, 0x0002BEC0, 0x0002C0C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_12D[] = {
0x00000001, 0x0000003C, 0x0002C100, 0x0002C300, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_12E[] = {
0x00000001, 0x0000003C, 0x0002C340, 0x0002C540, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_12F[] = {
0x00000001, 0x0000003C, 0x0002C580, 0x0002C780, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Mushroom[] = {
0x00000001, 0x0000003C, 0x000237C0, 0x000239C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SuperShroom[] = {
0x00000001, 0x0000003C, 0x00023A00, 0x00023C00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_UltraShroom[] = {
0x00000001, 0x0000003C, 0x00023C40, 0x00023E40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_LifeShroom[] = {
0x00000001, 0x0000003C, 0x00023E80, 0x00024080, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DriedShroom[] = {
0x00000001, 0x0000003C, 0x000240C0, 0x000242C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_TastyTonic[] = {
0x00000001, 0x0000003C, 0x00024300, 0x00024500, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SuperSoda[] = {
0x00000001, 0x0000003C, 0x00024540, 0x00024740, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BlueBerry[] = {
0x00000001, 0x0000003C, 0x00024780, 0x00024980, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_RedBerry[] = {
0x00000001, 0x0000003C, 0x000249C0, 0x00024BC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_YellowBerry[] = {
0x00000001, 0x0000003C, 0x00024C00, 0x00024E00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BubbleBerry[] = {
0x00000001, 0x0000003C, 0x00024E40, 0x00025040, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Goomnut[] = {
0x00000001, 0x0000003C, 0x00025080, 0x00025280, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_KoopaLeaf[] = {
0x00000001, 0x0000003C, 0x000252C0, 0x000254C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DriedPasta[] = {
0x00000001, 0x0000003C, 0x00025500, 0x00025700, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Lime[] = {
0x00000001, 0x0000003C, 0x00025740, 0x00025940, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Lemon[] = {
0x00000001, 0x0000003C, 0x00025980, 0x00025B80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DriedFruit[] = {
0x00000001, 0x0000003C, 0x00025BC0, 0x00025DC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StrangeLeaf[] = {
0x00000001, 0x0000003C, 0x00025E00, 0x00026000, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_CakeMix[] = {
0x00000001, 0x0000003C, 0x00026040, 0x00026240, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Egg[] = {
0x00000001, 0x0000003C, 0x00026280, 0x00026480, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Coconut[] = {
0x00000001, 0x0000003C, 0x000264C0, 0x000266C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Melon[] = {
0x00000001, 0x0000003C, 0x00026700, 0x00026900, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StinkyHerb[] = {
0x00000001, 0x0000003C, 0x00026940, 0x00026B40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_IcedPotato[] = {
0x00000001, 0x0000003C, 0x00026B80, 0x00026D80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HoneySyrup[] = {
0x00000001, 0x0000003C, 0x00026DC0, 0x00026FC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_MapleSyrup[] = {
0x00000001, 0x0000003C, 0x00027000, 0x00027200, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_JamminJelly[] = {
0x00000001, 0x0000003C, 0x00027240, 0x00027440, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_WhackasBump[] = {
0x00000001, 0x0000003C, 0x00027480, 0x00027680, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_Apple[] = {
0x00000001, 0x0000003C, 0x000276C0, 0x000278C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingSalt[] = {
0x00000001, 0x0000003C, 0x00027900, 0x00027B00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingSugar[] = {
0x00000001, 0x0000003C, 0x00027B40, 0x00027D40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingEgg[] = {
0x00000001, 0x0000003C, 0x00027D80, 0x00027F80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingCream[] = {
0x00000001, 0x0000003C, 0x00027FC0, 0x000281C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingStrawberry[] = {
0x00000001, 0x0000003C, 0x00028200, 0x00028400, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingButter[] = {
0x00000001, 0x0000003C, 0x00028440, 0x00028640, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingCleanser[] = {
0x00000001, 0x0000003C, 0x00028680, 0x00028880, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingWater[] = {
0x00000001, 0x0000003C, 0x000288C0, 0x00028AC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingFlour[] = {
0x00000001, 0x0000003C, 0x00028B00, 0x00028D00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_BakingMilk[] = {
0x00000001, 0x0000003C, 0x00028D40, 0x00028F40, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_118[] = {
0x00000001, 0x0000003C, 0x00028F80, 0x00029180, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_SleepySheep[] = {
0x00000001, 0x0000003C, 0x000291C0, 0x000293C0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_XBandage[] = {
0x00000001, 0x0000003C, 0x00029400, 0x00029600, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_POWBlock[] = {
0x00000001, 0x0000003C, 0x00029640, 0x00029840, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_HustleDrink[] = {
0x00000001, 0x0000003C, 0x00029880, 0x00029A80, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_StopWatch[] = {
0x00000001, 0x0000003C, 0x00029AC0, 0x00029CC0, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_DizzyDial[] = {
0x00000001, 0x0000003C, 0x00029D00, 0x00029F00, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_136[] = {
0x00000001, 0x0000003C, 0x00029F40, 0x0002A140, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32 ItemScript_ITEM_137[] = {
0x00000001, 0x0000003C, 0x0002A180, 0x0002A380, 0x00000000, 0x00000000, 0x00000002, 0x00000000
};

s32* gItemEntityScripts[] = {
ItemScript_Jump, ItemScript_GearBoots1, ItemScript_GearBoots2, ItemScript_GearBoots3, ItemScript_GearHammer1, ItemScript_GearHammer2, ItemScript_GearHammer3, ItemScript_LuckyStar, ItemScript_Jump, ItemScript_Jump, ItemScript_DojoCard1, ItemScript_DojoCard2, ItemScript_DojoCard3, ItemScript_DojoCard4, ItemScript_DojoCard5, ItemScript_UltraStone, ItemScript_KoopaFortressKey, ItemScript_RuinsKey, ItemScript_PulseStone, ItemScript_TubbaCastleKey, ItemScript_IcePalaceKey, ItemScript_RuinsStoneMoon, ItemScript_RuinsStonePyramid, ItemScript_RuinsStoneStar, ItemScript_AncientVase, ItemScript_KooperShell, ItemScript_BowserCastleKey, ItemScript_ForestPass, ItemScript_BooWeight, ItemScript_BoosPortrait, ItemScript_CrystalBerry, ItemScript_MysticKey, ItemScript_StoreroomKey, ItemScript_ToyTrain, ItemScript_BooRecord, ItemScript_FryingPan, ItemScript_Dictionary, ItemScript_MysteryNote, ItemScript_SuspiciousNote, ItemScript_CrystalBall, ItemScript_Screwdriver, ItemScript_Cookbook, ItemScript_JadeRaven, ItemScript_MagicalSeed1, ItemScript_MagicalSeed2, ItemScript_MagicalSeed3, ItemScript_MagicalSeed4, ItemScript_ToadDoll, ItemScript_Calculator, ItemScript_SnowmanBucket, ItemScript_SnowmanScarf, ItemScript_RedKey, ItemScript_BlueKey, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Letter, ItemScript_Artifact, ItemScript_Letter, ItemScript_Letter, ItemScript_Dolly, ItemScript_WaterStone, ItemScript_MagicalBean, ItemScript_FertileSoil, ItemScript_MiracleWater, ItemScript_AncientVase, ItemScript_KootTheTape, ItemScript_BakingSugar, ItemScript_BakingSalt, ItemScript_BakingEgg, ItemScript_BakingCream, ItemScript_BakingStrawberry, ItemScript_BakingButter, ItemScript_BakingCleanser, ItemScript_BakingWater, ItemScript_BakingFlour, ItemScript_BakingMilk, ItemScript_Lyrics, ItemScript_Melody, ItemScript_Mailbag, ItemScript_PeachKey, ItemScript_StoreroomKey, ItemScript_StarStone, ItemScript_SneakyParasol, ItemScript_KootBook, ItemScript_KootAutographMerluvlee, ItemScript_KootEmptyWallet, ItemScript_KootAutographLuigi, ItemScript_KootKoopaShell, ItemScript_KootOldPhoto, ItemScript_KootGlasses, ItemScript_KootOldPhoto, ItemScript_KootPackage, ItemScript_KootRedJar, ItemScript_PeachKey, ItemScript_StoreroomKey, ItemScript_StoreroomKey, ItemScript_SilverCard, ItemScript_GoldCard, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_FireFlower, ItemScript_SnowmanDoll, ItemScript_ThunderRage, ItemScript_ShootingStar, ItemScript_ThunderBolt, ItemScript_Pebble, ItemScript_DustyHammer, ItemScript_InsecticideHerb, ItemScript_StoneCap, ItemScript_TastyTonic, ItemScript_Mushroom, ItemScript_VoltShroom, ItemScript_SuperShroom, ItemScript_DriedShroom, ItemScript_UltraShroom, ItemScript_SleepySheep, ItemScript_POWBlock, ItemScript_HustleDrink, ItemScript_StopWatch, ItemScript_WhackasBump, ItemScript_Apple, ItemScript_LifeShroom, ItemScript_Mystery, ItemScript_RepelGel, ItemScript_FrightJar, ItemScript_PleaseComeBack, ItemScript_DizzyDial, ItemScript_SuperSoda, ItemScript_Lemon, ItemScript_Lime, ItemScript_BlueBerry, ItemScript_RedBerry, ItemScript_YellowBerry, ItemScript_BubbleBerry, ItemScript_JamminJelly, ItemScript_MapleSyrup, ItemScript_HoneySyrup, ItemScript_Goomnut, ItemScript_KoopaLeaf, ItemScript_DriedPasta, ItemScript_DriedFruit, ItemScript_StrangeLeaf, ItemScript_CakeMix, ItemScript_Egg, ItemScript_Coconut, ItemScript_Melon, ItemScript_StinkyHerb, ItemScript_IcedPotato, ItemScript_SpicySoup, ItemScript_ApplePie, ItemScript_HoneyUltra, ItemScript_MapleUltra, ItemScript_JellyUltra, ItemScript_Koopasta, ItemScript_FriedShroom, ItemScript_ShroomCake, ItemScript_ShroomSteak, ItemScript_HotShroom, ItemScript_SweetShroom, ItemScript_YummyMeal, ItemScript_HealthyJuice, ItemScript_BlandMeal, ItemScript_DeluxeFeast, ItemScript_SpecialShake, ItemScript_BigCookie, ItemScript_Cake, ItemScript_Mistake, ItemScript_KoopaTea, ItemScript_HoneySuper, ItemScript_MapleSuper, ItemScript_JellySuper, ItemScript_Spaghetti, ItemScript_EggMissile, ItemScript_FriedEgg, ItemScript_HoneyShroom, ItemScript_HoneyCandy, ItemScript_ElectroPop, ItemScript_FirePop, ItemScript_LimeCandy, ItemScript_CocoPop, ItemScript_LemonCandy, ItemScript_JellyPop, ItemScript_StrangeCake, ItemScript_KookyCookie, ItemScript_FrozenFries, ItemScript_PotatoSalad, ItemScript_NuttyCake, ItemScript_MapleShroom, ItemScript_BoiledEgg, ItemScript_YoshiCookie, ItemScript_JellyShroom, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_SpinSmash, ItemScript_Multibounce, ItemScript_PowerPlus, ItemScript_DodgeMaster, ItemScript_PowerBounce, ItemScript_SpikeShield, ItemScript_FirstAttack, ItemScript_HPPlus, ItemScript_QuakeHammer, ItemScript_DoubleDip, ItemScript_Jump, ItemScript_SleepStomp, ItemScript_FireShield, ItemScript_QuickChange, ItemScript_DDownPound, ItemScript_DizzyStomp, ItemScript_SmashCharge0, ItemScript_PrettyLucky, ItemScript_FeelingFine, ItemScript_AttackFXA, ItemScript_AllorNothing, ItemScript_HPDrain, ItemScript_JumpCharge0, ItemScript_SlowGo, ItemScript_FPPlus, ItemScript_MegaRush, ItemScript_IcePower, ItemScript_DefendPlus, ItemScript_PayOff, ItemScript_MoneyMoney, ItemScript_ChillOut, ItemScript_HappyHeart, ItemScript_ZapTap, ItemScript_Berserker, ItemScript_RightOn, ItemScript_RunawayPay, ItemScript_Refund, ItemScript_FlowerSaver, ItemScript_TripleDip, ItemScript_HammerThrow, ItemScript_MegaQuake, ItemScript_SmashCharge, ItemScript_JumpCharge, ItemScript_SSmashChg, ItemScript_SJumpChg, ItemScript_PowerRush, ItemScript_AutoJump, ItemScript_AutoSmash, ItemScript_CrazyHeart, ItemScript_LastStand, ItemScript_CloseCall, ItemScript_PUpDDown, ItemScript_LuckyDay, ItemScript_MegaHPDrain, ItemScript_PDownDUp, ItemScript_PowerQuake, ItemScript_AutoMultibounce, ItemScript_FlowerFanatic, ItemScript_HeartFinder, ItemScript_FlowerFinder, ItemScript_SpinAttack, ItemScript_DizzyAttack, ItemScript_ISpy, ItemScript_SpeedySpin, ItemScript_BumpAttack, ItemScript_PowerJump, ItemScript_SuperJump, ItemScript_MegaJump, ItemScript_PowerSmash, ItemScript_SuperSmash, ItemScript_MegaSmash, ItemScript_Jump, ItemScript_Jump, ItemScript_DeepFocus, ItemScript_SuperFocus, ItemScript_ShrinkSmash, ItemScript_Jump, ItemScript_Kaiden, ItemScript_DDownJump, ItemScript_ShrinkStomp, ItemScript_DamageDodge, ItemScript_EarthquakeJump, ItemScript_DeepFocus, ItemScript_SuperFocus, ItemScript_HPPlus, ItemScript_FPPlus, ItemScript_HappyHeart, ItemScript_HappyHeart, ItemScript_FlowerSaver, ItemScript_FlowerSaver, ItemScript_DamageDodge, ItemScript_DamageDodge, ItemScript_PowerPlus, ItemScript_PowerPlus, ItemScript_DefendPlus, ItemScript_DefendPlus, ItemScript_HappyFlower, ItemScript_HappyFlower, ItemScript_HappyFlower, ItemScript_GroupFocus, ItemScript_Peekaboo, ItemScript_AttackFXD, ItemScript_AttackFXB, ItemScript_AttackFXE, ItemScript_AttackFXC, ItemScript_AttackFXF, ItemScript_HPPlus, ItemScript_HPPlus, ItemScript_HPPlus, ItemScript_FPPlus, ItemScript_FPPlus, ItemScript_FPPlus, ItemScript_HealthyHealthy, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Heart, ItemScript_Coin, ItemScript_HeartPiece, ItemScript_StarPoint, ItemScript_HeartPoint, ItemScript_FlowerPoint, ItemScript_StarPiece, ItemScript_CompleteCake, ItemScript_CakeDone, ItemScript_CakeBaked, ItemScript_CakePan, ItemScript_CakeBatter, ItemScript_CakeBowl, ItemScript_CakeMixed, ItemScript_CakeIcing, ItemScript_CakeBerries, ItemScript_Hammer1, ItemScript_Hammer2, ItemScript_Hammer3, ItemScript_Boots1, ItemScript_Boots2, ItemScript_Boots3, ItemScript_Items, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump, ItemScript_Jump
};

s32 gItemIconRasterOffsets[] = {
0x00000000, 0x00001320, 0x00001540, 0x00001760, 0x00001980, 0x00001BA0, 0x00001DC0, 0x00001FE0, 0x00000000, 0x00000000, 0x00010780, 0x000109A0, 0x00010BC0, 0x00010E00, 0x00011020, 0x0000D860, 0x00009020, 0x00009240, 0x00009F00, 0x00009460, 0x00009680, 0x0000A9A0, 0x0000A560, 0x0000A780, 0x0000A340, 0x00009CE0, 0x000098A0, 0x0000ABC0, 0x0000B220, 0x0000B440, 0x0000CDC0, 0x0000B660, 0x0000B880, 0x0000BAA0, 0x0000B000, 0x0000BCC0, 0x0000BEE0, 0x0000C100, 0x0000C320, 0x00011240, 0x0000DEE0, 0x0000E100, 0x0000E320, 0x0000C540, 0x0000C760, 0x0000C980, 0x0000CBA0, 0x0000DAA0, 0x0000DCC0, 0x0000E540, 0x0000E760, 0x0000E980, 0x0000EBC0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x000129C0, 0x0000A120, 0x000129C0, 0x000129C0, 0x00009AC0, 0x0000CFE0, 0x0000D200, 0x0000D420, 0x0000D640, 0x0000A340, 0x00011AC0, 0x00027B40, 0x00027900, 0x00027D80, 0x00027FC0, 0x00028200, 0x00028440, 0x00028680, 0x000288C0, 0x00028B00, 0x00028D40, 0x0000F440, 0x0000F220, 0x0000F660, 0x0000FCE0, 0x0000B880, 0x0000F880, 0x0000FAA0, 0x000118A0, 0x00011CE0, 0x00011F20, 0x00012140, 0x00012360, 0x00012580, 0x000127A0, 0x00012580, 0x0000EDE0, 0x0000F000, 0x0000FCE0, 0x0000B880, 0x0000B880, 0x00011680, 0x00011460, 0x00000000, 0x00000000, 0x00000000, 0x0002A3C0, 0x0002A600, 0x0002A840, 0x0002ACC0, 0x0002AA80, 0x0002B140, 0x0002AF00, 0x00014700, 0x0002B5C0, 0x00024300, 0x000237C0, 0x0002B800, 0x00023A00, 0x000240C0, 0x00023C40, 0x000291C0, 0x00029640, 0x00029880, 0x00029AC0, 0x00027480, 0x000276C0, 0x00023E80, 0x00014280, 0x000144C0, 0x00014040, 0x00013BC0, 0x00029D00, 0x00024540, 0x00025980, 0x00025740, 0x00024780, 0x000249C0, 0x00024C00, 0x00024E40, 0x00027240, 0x00027000, 0x00026DC0, 0x00025080, 0x000252C0, 0x00025500, 0x00025BC0, 0x00025E00, 0x00026040, 0x00026280, 0x000264C0, 0x00026700, 0x00026940, 0x00026B80, 0x00002420, 0x00002660, 0x000028A0, 0x00002AE0, 0x00002D20, 0x00002F60, 0x000031A0, 0x000033E0, 0x00003620, 0x00003860, 0x00003AA0, 0x00004160, 0x00003CE0, 0x00003F20, 0x000043A0, 0x000045E0, 0x00004820, 0x00004A60, 0x00004CA0, 0x00004EE0, 0x00005120, 0x00005360, 0x000055A0, 0x000057E0, 0x00005A20, 0x00005C60, 0x00005EA0, 0x000060E0, 0x00006320, 0x00006560, 0x000067A0, 0x000069E0, 0x00006C20, 0x00006E60, 0x000070A0, 0x000072E0, 0x00007520, 0x00007760, 0x000079A0, 0x00007BE0, 0x00007E20, 0x00008060, 0x000082A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00014DC0, 0x00015000, 0x00015240, 0x00015480, 0x000156C0, 0x00015900, 0x00015B40, 0x00015D80, 0x00015FC0, 0x00016200, 0x00000000, 0x000168C0, 0x000171C0, 0x00020880, 0x00017AC0, 0x00017F40, 0x000183C0, 0x00018600, 0x00018840, 0x00018A80, 0x00018CC0, 0x00018F00, 0x00019140, 0x00019380, 0x000195C0, 0x00019800, 0x00019A40, 0x00019C80, 0x00019EC0, 0x0001A100, 0x0001A340, 0x0001A580, 0x0001A7C0, 0x0001AA00, 0x0001AC40, 0x0001AE80, 0x0001B0C0, 0x0001B300, 0x0001B540, 0x00018180, 0x00016680, 0x00016B00, 0x00017400, 0x00016D40, 0x00017640, 0x0001E000, 0x00017880, 0x00016F80, 0x0001E6C0, 0x0001E240, 0x0001E480, 0x0001CE00, 0x0001C740, 0x0001C980, 0x0001D040, 0x00016440, 0x00017D00, 0x0001B780, 0x0001D280, 0x0001D4C0, 0x0001DB80, 0x0001D700, 0x0001DDC0, 0x0001D940, 0x0001CBC0, 0x0001B9C0, 0x0001BC00, 0x0001BE40, 0x0001C080, 0x0001C2C0, 0x0001C500, 0x00000000, 0x00000000, 0x000201C0, 0x00020400, 0x0001EFC0, 0x00000000, 0x00020640, 0x0001F440, 0x0001F200, 0x0001F680, 0x0001F8C0, 0x000201C0, 0x00020400, 0x00015D80, 0x000195C0, 0x0001A580, 0x0001A580, 0x0001B300, 0x0001B300, 0x0001F680, 0x0001F680, 0x00015240, 0x00015240, 0x00019C80, 0x00019C80, 0x0001FB00, 0x0001FB00, 0x0001FB00, 0x00021600, 0x000213C0, 0x00021840, 0x00021A80, 0x00021CC0, 0x00021F00, 0x00022140, 0x00015D80, 0x00015D80, 0x00015D80, 0x000195C0, 0x000195C0, 0x000195C0, 0x000225C0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030A60, 0x0002F5C0, 0x00030CE0, 0x00030E20, 0x0002E900, 0x0002EF60, 0x00030400
};

s32 gItemIconPaletteOffsets[] = {
0x00000200, 0x00001520, 0x00001740, 0x00001960, 0x00001B80, 0x00001DA0, 0x00001FC0, 0x000021E0, 0x00000200, 0x00000200, 0x00010980, 0x00010BA0, 0x00010DC0, 0x00011000, 0x00011220, 0x0000DA60, 0x00009220, 0x00009440, 0x0000A100, 0x00009660, 0x00009880, 0x0000ABA0, 0x0000A760, 0x0000A980, 0x0000A540, 0x00009EE0, 0x00009AA0, 0x0000ADC0, 0x0000B420, 0x0000B640, 0x0000CFC0, 0x0000B860, 0x0000BA80, 0x0000BCA0, 0x0000B200, 0x0000BEC0, 0x0000C0E0, 0x0000C300, 0x0000C520, 0x00011440, 0x0000E0E0, 0x0000E300, 0x0000E520, 0x0000C740, 0x0000C960, 0x0000CB80, 0x0000CDA0, 0x0000DCA0, 0x0000DEC0, 0x0000E740, 0x0000E960, 0x0000EB80, 0x0000EDC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x00012BC0, 0x0000A320, 0x00012BC0, 0x00012BC0, 0x00009CC0, 0x0000D1E0, 0x0000D400, 0x0000D620, 0x0000D840, 0x0000A540, 0x00011CC0, 0x00027D40, 0x00027B00, 0x00027F80, 0x000281C0, 0x00028400, 0x00028640, 0x00028880, 0x00028AC0, 0x00028D00, 0x00028F40, 0x0000F640, 0x0000F420, 0x0000F860, 0x0000FEE0, 0x0000BA80, 0x0000FA80, 0x0000FCA0, 0x00011AA0, 0x00011EE0, 0x00012120, 0x00012340, 0x00012560, 0x00012780, 0x000129A0, 0x00012780, 0x0000EFE0, 0x0000F200, 0x0000FEE0, 0x0000BA80, 0x0000BA80, 0x00011880, 0x00011660, 0x00000200, 0x00000200, 0x00000200, 0x0002A5C0, 0x0002A800, 0x0002AA40, 0x0002AEC0, 0x0002AC80, 0x0002B340, 0x0002B100, 0x00014900, 0x0002B7C0, 0x00024500, 0x000239C0, 0x0002BA00, 0x00023C00, 0x000242C0, 0x00023E40, 0x000293C0, 0x00029840, 0x00029A80, 0x00029CC0, 0x00027680, 0x000278C0, 0x00024080, 0x00014480, 0x000146C0, 0x00014240, 0x00013DC0, 0x00029F00, 0x00024740, 0x00025B80, 0x00025940, 0x00024980, 0x00024BC0, 0x00024E00, 0x00025040, 0x00027440, 0x00027200, 0x00026FC0, 0x00025280, 0x000254C0, 0x00025700, 0x00025DC0, 0x00026000, 0x00026240, 0x00026480, 0x000266C0, 0x00026900, 0x00026B40, 0x00026D80, 0x00002620, 0x00002860, 0x00002AA0, 0x00002CE0, 0x00002F20, 0x00003160, 0x000033A0, 0x000035E0, 0x00003820, 0x00003A60, 0x00003CA0, 0x00004360, 0x00003EE0, 0x00004120, 0x000045A0, 0x000047E0, 0x00004A20, 0x00004C60, 0x00004EA0, 0x000050E0, 0x00005320, 0x00005560, 0x000057A0, 0x000059E0, 0x00005C20, 0x00005E60, 0x000060A0, 0x000062E0, 0x00006520, 0x00006760, 0x000069A0, 0x00006BE0, 0x00006E20, 0x00007060, 0x000072A0, 0x000074E0, 0x00007720, 0x00007960, 0x00007BA0, 0x00007DE0, 0x00008020, 0x00008260, 0x000084A0, 0x00000200, 0x00000200, 0x00000200, 0x00000200, 0x00000200, 0x00014FC0, 0x00015200, 0x00015440, 0x00015680, 0x000158C0, 0x00015B00, 0x00015D40, 0x00015F80, 0x000161C0, 0x00016400, 0x00000200, 0x00016AC0, 0x000173C0, 0x00020A80, 0x00017CC0, 0x00018140, 0x000185C0, 0x00018800, 0x00018A40, 0x00018C80, 0x00018EC0, 0x00019100, 0x00019340, 0x00019580, 0x000197C0, 0x00019A00, 0x00019C40, 0x00019E80, 0x0001A0C0, 0x0001A300, 0x0001A540, 0x0001A780, 0x0001A9C0, 0x0001AC00, 0x0001AE40, 0x0001B080, 0x0001B2C0, 0x0001B500, 0x0001B740, 0x00018380, 0x00016880, 0x00016D00, 0x00017600, 0x00016F40, 0x00017840, 0x0001E200, 0x00017A80, 0x00017180, 0x0001E8C0, 0x0001E440, 0x0001E680, 0x0001D000, 0x0001C940, 0x0001CB80, 0x0001D240, 0x00016640, 0x00017F00, 0x0001B980, 0x0001D480, 0x0001D6C0, 0x0001DD80, 0x0001D900, 0x0001DFC0, 0x0001DB40, 0x0001CDC0, 0x0001BBC0, 0x0001BE00, 0x0001C040, 0x0001C280, 0x0001C4C0, 0x0001C700, 0x00000200, 0x00000200, 0x000203C0, 0x00020600, 0x0001F1C0, 0x00000200, 0x00020840, 0x0001F640, 0x0001F400, 0x0001F880, 0x0001FAC0, 0x000203C0, 0x00020600, 0x00015F80, 0x000197C0, 0x0001A780, 0x0001A780, 0x0001B500, 0x0001B500, 0x0001F880, 0x0001F880, 0x00015440, 0x00015440, 0x00019E80, 0x00019E80, 0x0001FD00, 0x0001FD00, 0x0001FD00, 0x00021800, 0x000215C0, 0x00021A40, 0x00021C80, 0x00021EC0, 0x00022100, 0x00022340, 0x00015F80, 0x00015F80, 0x00015F80, 0x000197C0, 0x000197C0, 0x000197C0, 0x000227C0, 0x00000200, 0x00000200, 0x00000200, 0x00000200, 0x00000200, 0x00030B80, 0x0002F6E0, 0x00030E00, 0x00030F40, 0x0002EB00, 0x0002F160, 0x00030600
};

s32 D_8008EEC0[] = {
0, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000009, 0x00000006, 0x00000007, 0x00000008, 0x00000005, 0x0000000A, 0x0000000B
};

s32 D_8008EEF0[] = {
0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000000, 0x00000006, 0x00000007, 0x00000008, 0x00000005, 0x00000000, 0x00000000
};

s32 gPartnerPopupProperties[][4] = {
    {0x800989A0, 0x00000000, 0x00000000, 0x00000000},
    {0x001D0007, 0x00000002, 0x00280000, 0x00280001},
    {0x001D0008, 0x00000003, 0x0028000D, 0x0028000E},
    {0x001D0009, 0x00000004, 0x0028001A, 0x0028001B},
    {0x001D000A, 0x00000005, 0x00280027, 0x00280028},
    {0x001D000B, 0x00000001, 0x00000000, 0x00000000},
    {0x001D000C, 0x00000007, 0x00280041, 0x00280042},
    {0x001D000D, 0x00000008, 0x0028004E, 0x0028004F},
    {0x001D000E, 0x00000009, 0x0028005B, 0x0028005C},
    {0x001D000F, 0x00000006, 0x00280034, 0x00280035},
    {0x001D0010, 0x00000001, 0x00000000, 0x00000000},
    {0x001D0011, 0x00000001, 0x00000000, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000}
};

//TODO padding
s32 pad8[] = {
    0x00000000, 0x00000000
};

extern HudScript HudScript_Partner0;
extern HudScript HudScript_Goombario;
extern HudScript HudScript_Kooper;
extern HudScript HudScript_Bombette;
extern HudScript HudScript_Parakarry;
extern HudScript HudScript_Watt;
extern HudScript HudScript_Sushie;
extern HudScript HudScript_Lakilester;
extern HudScript HudScript_Bow;
extern HudScript HudScript_PartnerA;
extern HudScript HudScript_Partner0Disabled;
extern HudScript HudScript_GoombarioDisabled;
extern HudScript HudScript_KooperDisabled;
extern HudScript HudScript_BombetteDisabled;
extern HudScript HudScript_ParakarryDisabled;
extern HudScript HudScript_WattDisabled;
extern HudScript HudScript_SushieDisabled;
extern HudScript HudScript_LakilesterDisabled;
extern HudScript HudScript_BowDisabled;
extern HudScript HudScript_PartnerADisabled;

IconHudScriptPair gPartnerIconHudScripts[] = {
    { .enabled = &HudScript_Partner0, .disabled = &HudScript_Partner0Disabled, },
    { .enabled = &HudScript_Goombario, .disabled = &HudScript_GoombarioDisabled, },
    { .enabled = &HudScript_Kooper, .disabled = &HudScript_KooperDisabled, },
    { .enabled = &HudScript_Bombette, .disabled = &HudScript_BombetteDisabled, },
    { .enabled = &HudScript_Parakarry, .disabled = &HudScript_ParakarryDisabled, },
    { .enabled = &HudScript_Bow, .disabled = &HudScript_BowDisabled, },
    { .enabled = &HudScript_Watt, .disabled = &HudScript_WattDisabled, },
    { .enabled = &HudScript_Sushie, .disabled = &HudScript_SushieDisabled, },
    { .enabled = &HudScript_Lakilester, .disabled = &HudScript_LakilesterDisabled, },
    { .enabled = (HudScript*)0x80107F78, .disabled = (HudScript*)0x80107FA0, },
    { .enabled = &HudScript_PartnerA, .disabled = &HudScript_PartnerADisabled, },
    { .enabled = (HudScript*)0x80108018, .disabled = (HudScript*)0x80108040, },
    { .enabled = (HudScript*)0x80108018, .disabled = (HudScript*)0x80108040 },
};

MoveData gMoveTable[] = {
{	// move 0: Nothing
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = 0,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 1: Unused_01
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 2: Unused_02
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 3: Hammer1
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A3),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 4: Hammer2
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x23, 0x0A4),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A4),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 5: Hammer3
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x23, 0x0A5),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A5),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 6: Unused_Hammer4
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 7: Unused_Hammer5
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 8: SpinSmash
	.nameMsg = MESSAGE_ID(0x2A, 0x010),
	.fullDescMsg = MESSAGE_ID(0x25, 0x068),
	.shortDescMsg = MESSAGE_ID(0x23, 0x068),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 2,
	.costBP = 1
},
{	// move 9: QuakeHammer
	.nameMsg = MESSAGE_ID(0x2A, 0x012),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06A),
	.flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 2,
	.costBP = 1
},
{	// move A: DDownPound
	.nameMsg = MESSAGE_ID(0x2A, 0x011),
	.fullDescMsg = MESSAGE_ID(0x25, 0x069),
	.shortDescMsg = MESSAGE_ID(0x23, 0x069),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 2,
	.costBP = 2
},
{	// move B: SmashCharge0
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 1
},
{	// move C: Unused_Hammer_0C
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move D: HammerThrow
	.nameMsg = MESSAGE_ID(0x2A, 0x00E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x066),
	.shortDescMsg = MESSAGE_ID(0x23, 0x066),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 2,
	.costBP = 2
},
{	// move E: MegaQuake
	.nameMsg = MESSAGE_ID(0x2A, 0x014),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06C),
	.flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 7,
	.costBP = 3
},
{	// move F: SmashCharge
	.nameMsg = MESSAGE_ID(0x2A, 0x00C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x064),
	.shortDescMsg = MESSAGE_ID(0x23, 0x064),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 1
},
{	// move 10: Unused_Hammer_10
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x25, 0x064),
	.shortDescMsg = MESSAGE_ID(0x23, 0x064),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 11: SuperSmashCharge
	.nameMsg = MESSAGE_ID(0x2A, 0x00D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x065),
	.shortDescMsg = MESSAGE_ID(0x23, 0x065),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 4,
	.costBP = 2
},
{	// move 12: Unused_Hammer_12
	.nameMsg = MESSAGE_ID(0x1D, 0x038),
	.fullDescMsg = MESSAGE_ID(0x25, 0x065),
	.shortDescMsg = MESSAGE_ID(0x23, 0x065),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 13: AutoSmash
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 1
},
{	// move 14: PowerQuake
	.nameMsg = MESSAGE_ID(0x2A, 0x013),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06B),
	.flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 4,
	.costBP = 2
},
{	// move 15: PowerSmash
	.nameMsg = MESSAGE_ID(0x2A, 0x00A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x062),
	.shortDescMsg = MESSAGE_ID(0x23, 0x062),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 2,
	.costBP = 1
},
{	// move 16: SuperSmash
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 4,
	.costBP = 2
},
{	// move 17: MegaSmash
	.nameMsg = MESSAGE_ID(0x2A, 0x00B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x063),
	.shortDescMsg = MESSAGE_ID(0x23, 0x063),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 6,
	.costBP = 3
},
{	// move 18: ShrinkSmash
	.nameMsg = MESSAGE_ID(0x2A, 0x00F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x067),
	.shortDescMsg = MESSAGE_ID(0x23, 0x067),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 2,
	.costBP = 1
},
{	// move 19: ShellCrack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_1000 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_HAMMER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 6,
	.costBP = 3
},
{	// move 1A: Jump1
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x23, 0x0A0),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A0),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 1B: Jump2
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x23, 0x0A1),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A1),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 1C: Jump3
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x23, 0x0A2),
	.shortDescMsg = MESSAGE_ID(0x23, 0x0A2),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 1D: Unused_Jump4
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 1E: Unused_Jump5
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 1F: Multibounce
	.nameMsg = MESSAGE_ID(0x2A, 0x006),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05E),
	.flags = MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 2,
	.costBP = 1
},
{	// move 20: PowerBounce
	.nameMsg = MESSAGE_ID(0x2A, 0x009),
	.fullDescMsg = MESSAGE_ID(0x25, 0x061),
	.shortDescMsg = MESSAGE_ID(0x23, 0x061),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 3,
	.costBP = 2
},
{	// move 21: SleepStomp
	.nameMsg = MESSAGE_ID(0x2A, 0x004),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05C),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 2,
	.costBP = 1
},
{	// move 22: DizzyStomp
	.nameMsg = MESSAGE_ID(0x2A, 0x005),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05D),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 2,
	.costBP = 1
},
{	// move 23: JumpCharge0
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 1
},
{	// move 24: Unused_24
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 1,
	.costBP = 1
},
{	// move 25: JumpCharge
	.nameMsg = MESSAGE_ID(0x2A, 0x002),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05A),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 1
},
{	// move 26: Unused_26
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05A),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 27: SuperJumpCharge
	.nameMsg = MESSAGE_ID(0x2A, 0x003),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05B),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER | MOVE_DATA_FLAG_800,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 4,
	.costBP = 2
},
{	// move 28: Unused_28
	.nameMsg = MESSAGE_ID(0x1D, 0x039),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05B),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 29: AutoJump
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 1
},
{	// move 2A: AutoMultibounce
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 5,
	.costBP = 2
},
{	// move 2B: PowerJump
	.nameMsg = MESSAGE_ID(0x2A, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x058),
	.shortDescMsg = MESSAGE_ID(0x23, 0x058),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 2,
	.costBP = 1
},
{	// move 2C: SuperJump
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 4,
	.costBP = 2
},
{	// move 2D: MegaJump
	.nameMsg = MESSAGE_ID(0x2A, 0x001),
	.fullDescMsg = MESSAGE_ID(0x25, 0x059),
	.shortDescMsg = MESSAGE_ID(0x23, 0x059),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 6,
	.costBP = 3
},
{	// move 2E: DDownJump
	.nameMsg = MESSAGE_ID(0x2A, 0x008),
	.fullDescMsg = MESSAGE_ID(0x25, 0x060),
	.shortDescMsg = MESSAGE_ID(0x23, 0x060),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 2,
	.costBP = 2
},
{	// move 2F: ShrinkStomp
	.nameMsg = MESSAGE_ID(0x2A, 0x007),
	.fullDescMsg = MESSAGE_ID(0x25, 0x05F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x05F),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 2,
	.costBP = 1
},
{	// move 30: EarthquakeJump
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_20 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_JUMP,
	.actionTip = MOVE_ACTION_TIP_20,
	.costFP = 2,
	.costBP = 2
},
{	// move 31: Unused_DefendPlus
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x074),
	.shortDescMsg = MESSAGE_ID(0x23, 0x074),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_3,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 6
},
{	// move 32: Unused_32
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_3,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 8
},
{	// move 33: DamageDodge
	.nameMsg = MESSAGE_ID(0x26, 0x075),
	.fullDescMsg = MESSAGE_ID(0x25, 0x075),
	.shortDescMsg = MESSAGE_ID(0x23, 0x075),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_3,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 34: Items
	.nameMsg = MESSAGE_ID(0x1D, 0x03F),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x0A4),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_ITEMS,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 35: DoubleDip
	.nameMsg = MESSAGE_ID(0x2A, 0x015),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06D),
	.flags = 0,
	.category = MOVE_TYPE_ITEMS,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 3,
	.costBP = 1
},
{	// move 36: TripleDip
	.nameMsg = MESSAGE_ID(0x2A, 0x016),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06E),
	.flags = 0,
	.category = MOVE_TYPE_ITEMS,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 6,
	.costBP = 3
},
{	// move 37: Unused_37
	.nameMsg = 0x80098A04,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = 0,
	.category = MOVE_TYPE_TACTICS,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 38: QuickChange
	.nameMsg = MESSAGE_ID(0x2A, 0x018),
	.fullDescMsg = MESSAGE_ID(0x25, 0x070),
	.shortDescMsg = MESSAGE_ID(0x23, 0x070),
	.flags = 0,
	.category = MOVE_TYPE_TACTICS,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 4
},
{	// move 39: Unused_39
	.nameMsg = 0x80098A04,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_6,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 3A: Unused_3A
	.nameMsg = 0x80098A04,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = 0,
	.category = MOVE_TYPE_ATTACK_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 3B: PowerPlus
	.nameMsg = MESSAGE_ID(0x26, 0x073),
	.fullDescMsg = MESSAGE_ID(0x25, 0x073),
	.shortDescMsg = MESSAGE_ID(0x23, 0x073),
	.flags = 0,
	.category = MOVE_TYPE_ATTACK_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 6
},
{	// move 3C: AllorNothing
	.nameMsg = MESSAGE_ID(0x26, 0x093),
	.fullDescMsg = MESSAGE_ID(0x25, 0x093),
	.shortDescMsg = MESSAGE_ID(0x23, 0x093),
	.flags = 0,
	.category = MOVE_TYPE_ATTACK_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 4
},
{	// move 3D: IcePower
	.nameMsg = MESSAGE_ID(0x26, 0x095),
	.fullDescMsg = MESSAGE_ID(0x25, 0x095),
	.shortDescMsg = MESSAGE_ID(0x23, 0x095),
	.flags = 0,
	.category = MOVE_TYPE_ATTACK_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 3E: PUpDDown
	.nameMsg = MESSAGE_ID(0x2A, 0x019),
	.fullDescMsg = MESSAGE_ID(0x25, 0x076),
	.shortDescMsg = MESSAGE_ID(0x23, 0x076),
	.flags = 0,
	.category = MOVE_TYPE_ATTACK_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 3F: Unused_3F
	.nameMsg = 0x80098A04,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 40: SpikeShield
	.nameMsg = MESSAGE_ID(0x26, 0x07F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07F),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 41: FireShield
	.nameMsg = MESSAGE_ID(0x26, 0x097),
	.fullDescMsg = MESSAGE_ID(0x25, 0x097),
	.shortDescMsg = MESSAGE_ID(0x23, 0x097),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 42: PrettyLucky
	.nameMsg = MESSAGE_ID(0x26, 0x081),
	.fullDescMsg = MESSAGE_ID(0x25, 0x081),
	.shortDescMsg = MESSAGE_ID(0x23, 0x081),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 43: FeelingFine
	.nameMsg = MESSAGE_ID(0x26, 0x08C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08C),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 44: ZapTap
	.nameMsg = MESSAGE_ID(0x26, 0x099),
	.fullDescMsg = MESSAGE_ID(0x25, 0x099),
	.shortDescMsg = MESSAGE_ID(0x23, 0x099),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 4
},
{	// move 45: DefendPlus
	.nameMsg = MESSAGE_ID(0x26, 0x074),
	.fullDescMsg = MESSAGE_ID(0x25, 0x074),
	.shortDescMsg = MESSAGE_ID(0x23, 0x074),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 6
},
{	// move 46: LastStand
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x085),
	.shortDescMsg = MESSAGE_ID(0x23, 0x085),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 47: CloseCall
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x083),
	.shortDescMsg = MESSAGE_ID(0x23, 0x083),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 48: LuckyDay
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x082),
	.shortDescMsg = MESSAGE_ID(0x23, 0x082),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 7
},
{	// move 49: PDownDUp
	.nameMsg = MESSAGE_ID(0x2A, 0x01A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x077),
	.shortDescMsg = MESSAGE_ID(0x23, 0x077),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 4A: HealthyHealthy
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = 0,
	.category = MOVE_TYPE_DEFENSE_UP,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 4B: Unused_4B
	.nameMsg = 0x80098A04,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = 0,
	.category = MOVE_TYPE_9,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 4C: DodgeMaster
	.nameMsg = MESSAGE_ID(0x26, 0x080),
	.fullDescMsg = MESSAGE_ID(0x25, 0x080),
	.shortDescMsg = MESSAGE_ID(0x23, 0x080),
	.flags = 0,
	.category = MOVE_TYPE_9,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 4D: FirstAttack
	.nameMsg = MESSAGE_ID(0x26, 0x087),
	.fullDescMsg = MESSAGE_ID(0x25, 0x087),
	.shortDescMsg = MESSAGE_ID(0x23, 0x087),
	.flags = 0,
	.category = MOVE_TYPE_9,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 4E: SlowGo
	.nameMsg = MESSAGE_ID(0x26, 0x094),
	.fullDescMsg = MESSAGE_ID(0x25, 0x094),
	.shortDescMsg = MESSAGE_ID(0x23, 0x094),
	.flags = 0,
	.category = MOVE_TYPE_9,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 4F: RightOn
	.nameMsg = MESSAGE_ID(0x26, 0x09B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09B),
	.flags = 0,
	.category = MOVE_TYPE_9,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 8
},
{	// move 50: BumpAttack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x088),
	.shortDescMsg = MESSAGE_ID(0x23, 0x088),
	.flags = 0,
	.category = MOVE_TYPE_9,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 5
},
{	// move 51: Unused_51
	.nameMsg = 0x80098A04,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 52: HPPlus
	.nameMsg = MESSAGE_ID(0x26, 0x071),
	.fullDescMsg = MESSAGE_ID(0x25, 0x071),
	.shortDescMsg = MESSAGE_ID(0x23, 0x071),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 53: MysteryScroll
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 54: AttackFXA
	.nameMsg = MESSAGE_ID(0x26, 0x08D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08D),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 55: AttackFXD
	.nameMsg = MESSAGE_ID(0x26, 0x08E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08E),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 56: AttackFXB
	.nameMsg = MESSAGE_ID(0x26, 0x08F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08F),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 57: AttackFXE
	.nameMsg = MESSAGE_ID(0x26, 0x090),
	.fullDescMsg = MESSAGE_ID(0x25, 0x090),
	.shortDescMsg = MESSAGE_ID(0x23, 0x090),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 58: AttackFXC
	.nameMsg = MESSAGE_ID(0x26, 0x091),
	.fullDescMsg = MESSAGE_ID(0x25, 0x091),
	.shortDescMsg = MESSAGE_ID(0x23, 0x091),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 59: AttackFXF
	.nameMsg = MESSAGE_ID(0x26, 0x092),
	.fullDescMsg = MESSAGE_ID(0x25, 0x092),
	.shortDescMsg = MESSAGE_ID(0x23, 0x092),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 5A: HPDrain
	.nameMsg = MESSAGE_ID(0x26, 0x078),
	.fullDescMsg = MESSAGE_ID(0x25, 0x078),
	.shortDescMsg = MESSAGE_ID(0x23, 0x078),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 5B: FPPlus
	.nameMsg = MESSAGE_ID(0x26, 0x072),
	.fullDescMsg = MESSAGE_ID(0x25, 0x072),
	.shortDescMsg = MESSAGE_ID(0x23, 0x072),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 5C: MoneyMoney
	.nameMsg = MESSAGE_ID(0x26, 0x09A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09A),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 7
},
{	// move 5D: ChillOutBadge
	.nameMsg = MESSAGE_ID(0x26, 0x098),
	.fullDescMsg = MESSAGE_ID(0x25, 0x098),
	.shortDescMsg = MESSAGE_ID(0x23, 0x098),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 5E: HappyHeart
	.nameMsg = MESSAGE_ID(0x26, 0x079),
	.fullDescMsg = MESSAGE_ID(0x25, 0x079),
	.shortDescMsg = MESSAGE_ID(0x23, 0x079),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 5F: MegaRush
	.nameMsg = MESSAGE_ID(0x26, 0x086),
	.fullDescMsg = MESSAGE_ID(0x25, 0x086),
	.shortDescMsg = MESSAGE_ID(0x23, 0x086),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 60: Berserker
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 8
},
{	// move 61: RunawayPay
	.nameMsg = MESSAGE_ID(0x26, 0x09C),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09C),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 62: FlowerSaver
	.nameMsg = MESSAGE_ID(0x26, 0x07B),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07B),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 6
},
{	// move 63: PayOff
	.nameMsg = MESSAGE_ID(0x26, 0x096),
	.fullDescMsg = MESSAGE_ID(0x25, 0x096),
	.shortDescMsg = MESSAGE_ID(0x23, 0x096),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 64: PowerRush
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x084),
	.shortDescMsg = MESSAGE_ID(0x23, 0x084),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 65: CrazyHeart
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 10
},
{	// move 66: MegaHPDrain
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 10
},
{	// move 67: FlowerFanatic
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 10
},
{	// move 68: HeartFinder
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07C),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07C),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 69: FlowerFinder
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07D),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 6A: SpinAttack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x089),
	.shortDescMsg = MESSAGE_ID(0x23, 0x089),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 6B: DizzyAttack
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08A),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 6C: ISpy
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09E),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 6D: SpeedySpin
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x25, 0x08B),
	.shortDescMsg = MESSAGE_ID(0x23, 0x08B),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 6E: Refund
	.nameMsg = MESSAGE_ID(0x26, 0x09D),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09D),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09D),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 6F: Unused_FinalGoompa
	.nameMsg = 0x800989F0,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 70: Unused_FinalBombomb
	.nameMsg = 0x800989DC,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 71: DeepFocus
	.nameMsg = MESSAGE_ID(0x26, 0x07E),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07E),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07E),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 1
},
{	// move 72: SuperFocus
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 5
},
{	// move 73: Kaiden
	.nameMsg = MESSAGE_ID(0x00, 0x000),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_80000000,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 74: HappyFlower
	.nameMsg = MESSAGE_ID(0x26, 0x07A),
	.fullDescMsg = MESSAGE_ID(0x25, 0x07A),
	.shortDescMsg = MESSAGE_ID(0x23, 0x07A),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 75: GroupFocus
	.nameMsg = MESSAGE_ID(0x26, 0x06F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x06F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x06F),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 2
},
{	// move 76: Peekaboo
	.nameMsg = MESSAGE_ID(0x26, 0x09F),
	.fullDescMsg = MESSAGE_ID(0x25, 0x09F),
	.shortDescMsg = MESSAGE_ID(0x23, 0x09F),
	.flags = MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_NONE,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 3
},
{	// move 77: Focus
	.nameMsg = MESSAGE_ID(0x1D, 0x014),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x020),
	.flags = MOVE_DATA_FLAG_80000000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 78: Refresh
	.nameMsg = MESSAGE_ID(0x1D, 0x015),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x021),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 1
},
{	// move 79: Lullaby
	.nameMsg = MESSAGE_ID(0x1D, 0x016),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x022),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 1
},
{	// move 7A: StarStorm
	.nameMsg = MESSAGE_ID(0x1D, 0x017),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x023),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 2
},
{	// move 7B: ChillOutMove
	.nameMsg = MESSAGE_ID(0x1D, 0x018),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x024),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 2
},
{	// move 7C: Smooch
	.nameMsg = MESSAGE_ID(0x1D, 0x019),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x025),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 3,
	.costBP = 3
},
{	// move 7D: TimeOut
	.nameMsg = MESSAGE_ID(0x1D, 0x01A),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x026),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 2
},
{	// move 7E: UpAndAway
	.nameMsg = MESSAGE_ID(0x1D, 0x01B),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x027),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 2
},
{	// move 7F: StarBeam
	.nameMsg = MESSAGE_ID(0x1D, 0x01C),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x028),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 80: PeachBeam
	.nameMsg = MESSAGE_ID(0x1D, 0x01D),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x029),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 81: PeachFocus
	.nameMsg = MESSAGE_ID(0x1D, 0x01E),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x020),
	.flags = MOVE_DATA_FLAG_100,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 82: TwinkDash
	.nameMsg = MESSAGE_ID(0x1D, 0x01F),
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x1D, 0x020),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_STAR_POWER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 83: Headbonk1
	.nameMsg = MESSAGE_ID(0x2B, 0x000),
	.fullDescMsg = MESSAGE_ID(0x28, 0x007),
	.shortDescMsg = MESSAGE_ID(0x28, 0x002),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_2,
	.costFP = 0,
	.costBP = 0
},
{	// move 84: Headbonk2
	.nameMsg = MESSAGE_ID(0x2B, 0x000),
	.fullDescMsg = MESSAGE_ID(0x28, 0x008),
	.shortDescMsg = MESSAGE_ID(0x28, 0x002),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_2,
	.costFP = 0,
	.costBP = 0
},
{	// move 85: Headbonk3
	.nameMsg = MESSAGE_ID(0x2B, 0x000),
	.fullDescMsg = MESSAGE_ID(0x28, 0x009),
	.shortDescMsg = MESSAGE_ID(0x28, 0x002),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_2,
	.costFP = 0,
	.costBP = 0
},
{	// move 86: Tattle
	.nameMsg = MESSAGE_ID(0x2B, 0x001),
	.fullDescMsg = MESSAGE_ID(0x28, 0x00A),
	.shortDescMsg = MESSAGE_ID(0x28, 0x003),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_20000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 0,
	.costBP = 0
},
{	// move 87: Charge
	.nameMsg = MESSAGE_ID(0x2B, 0x002),
	.fullDescMsg = MESSAGE_ID(0x28, 0x00B),
	.shortDescMsg = MESSAGE_ID(0x28, 0x004),
	.flags = MOVE_DATA_FLAG_100,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 1,
	.costBP = 0
},
{	// move 88: Multibonk
	.nameMsg = MESSAGE_ID(0x2B, 0x003),
	.fullDescMsg = MESSAGE_ID(0x28, 0x00C),
	.shortDescMsg = MESSAGE_ID(0x28, 0x005),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_2,
	.costFP = 3,
	.costBP = 0
},
{	// move 89: ShellToss1
	.nameMsg = MESSAGE_ID(0x2B, 0x004),
	.fullDescMsg = MESSAGE_ID(0x28, 0x014),
	.shortDescMsg = MESSAGE_ID(0x28, 0x00F),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 8A: ShellToss2
	.nameMsg = MESSAGE_ID(0x2B, 0x004),
	.fullDescMsg = MESSAGE_ID(0x28, 0x015),
	.shortDescMsg = MESSAGE_ID(0x28, 0x00F),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 8B: ShellToss3
	.nameMsg = MESSAGE_ID(0x2B, 0x004),
	.fullDescMsg = MESSAGE_ID(0x28, 0x016),
	.shortDescMsg = MESSAGE_ID(0x28, 0x00F),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move 8C: PowerShell
	.nameMsg = MESSAGE_ID(0x2B, 0x005),
	.fullDescMsg = MESSAGE_ID(0x28, 0x017),
	.shortDescMsg = MESSAGE_ID(0x28, 0x010),
	.flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 3,
	.costBP = 0
},
{	// move 8D: DizzyShell
	.nameMsg = MESSAGE_ID(0x2B, 0x006),
	.fullDescMsg = MESSAGE_ID(0x28, 0x018),
	.shortDescMsg = MESSAGE_ID(0x28, 0x011),
	.flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_3,
	.costFP = 4,
	.costBP = 0
},
{	// move 8E: FireShell
	.nameMsg = MESSAGE_ID(0x2B, 0x007),
	.fullDescMsg = MESSAGE_ID(0x28, 0x019),
	.shortDescMsg = MESSAGE_ID(0x28, 0x012),
	.flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 5,
	.costBP = 0
},
{	// move 8F: BodySlam1
	.nameMsg = MESSAGE_ID(0x2B, 0x008),
	.fullDescMsg = MESSAGE_ID(0x28, 0x021),
	.shortDescMsg = MESSAGE_ID(0x28, 0x01C),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_15,
	.costFP = 0,
	.costBP = 0
},
{	// move 90: BodySlam2
	.nameMsg = MESSAGE_ID(0x2B, 0x008),
	.fullDescMsg = MESSAGE_ID(0x28, 0x022),
	.shortDescMsg = MESSAGE_ID(0x28, 0x01C),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_15,
	.costFP = 0,
	.costBP = 0
},
{	// move 91: BodySlam3
	.nameMsg = MESSAGE_ID(0x2B, 0x008),
	.fullDescMsg = MESSAGE_ID(0x28, 0x023),
	.shortDescMsg = MESSAGE_ID(0x28, 0x01C),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_15,
	.costFP = 0,
	.costBP = 0
},
{	// move 92: Bomb
	.nameMsg = MESSAGE_ID(0x2B, 0x009),
	.fullDescMsg = MESSAGE_ID(0x28, 0x024),
	.shortDescMsg = MESSAGE_ID(0x28, 0x01D),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_2000 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_3,
	.costFP = 3,
	.costBP = 0
},
{	// move 93: PowerBomb
	.nameMsg = MESSAGE_ID(0x2B, 0x00A),
	.fullDescMsg = MESSAGE_ID(0x28, 0x025),
	.shortDescMsg = MESSAGE_ID(0x28, 0x01E),
	.flags = MOVE_DATA_FLAG_4 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_3,
	.costFP = 6,
	.costBP = 0
},
{	// move 94: MegaBomb
	.nameMsg = MESSAGE_ID(0x2B, 0x00B),
	.fullDescMsg = MESSAGE_ID(0x28, 0x026),
	.shortDescMsg = MESSAGE_ID(0x28, 0x01F),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_3,
	.costFP = 8,
	.costBP = 0
},
{	// move 95: SkyDive1
	.nameMsg = MESSAGE_ID(0x2B, 0x00C),
	.fullDescMsg = MESSAGE_ID(0x28, 0x02E),
	.shortDescMsg = MESSAGE_ID(0x28, 0x029),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 96: SkyDive2
	.nameMsg = MESSAGE_ID(0x2B, 0x00C),
	.fullDescMsg = MESSAGE_ID(0x28, 0x02F),
	.shortDescMsg = MESSAGE_ID(0x28, 0x029),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 97: SkyDive3
	.nameMsg = MESSAGE_ID(0x2B, 0x00C),
	.fullDescMsg = MESSAGE_ID(0x28, 0x030),
	.shortDescMsg = MESSAGE_ID(0x28, 0x029),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 98: ShellShot
	.nameMsg = MESSAGE_ID(0x2B, 0x00D),
	.fullDescMsg = MESSAGE_ID(0x28, 0x031),
	.shortDescMsg = MESSAGE_ID(0x28, 0x02A),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_10000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_5,
	.costFP = 3,
	.costBP = 0
},
{	// move 99: AirLift
	.nameMsg = MESSAGE_ID(0x2B, 0x00E),
	.fullDescMsg = MESSAGE_ID(0x28, 0x032),
	.shortDescMsg = MESSAGE_ID(0x28, 0x02B),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_400 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_3,
	.costFP = 3,
	.costBP = 0
},
{	// move 9A: AirRaid
	.nameMsg = MESSAGE_ID(0x2B, 0x00F),
	.fullDescMsg = MESSAGE_ID(0x28, 0x033),
	.shortDescMsg = MESSAGE_ID(0x28, 0x02C),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 6,
	.costBP = 0
},
{	// move 9B: Unused_LoneFool1
	.nameMsg = 0x800989D0,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 9C: Unused_LoneFool2
	.nameMsg = 0x800989D0,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 9D: Unused_LoneFool3
	.nameMsg = 0x800989D0,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 9E: Unused_Mumble
	.nameMsg = 0x800989C0,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_4,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move 9F: Unused_Preach
	.nameMsg = 0x800989B4,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move A0: Unused_Awakening
	.nameMsg = 0x800989A8,
	.fullDescMsg = MESSAGE_ID(0x00, 0x000),
	.shortDescMsg = MESSAGE_ID(0x00, 0x000),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_0,
	.costFP = 0,
	.costBP = 0
},
{	// move A1: ElectroDash1
	.nameMsg = MESSAGE_ID(0x2B, 0x014),
	.fullDescMsg = MESSAGE_ID(0x28, 0x048),
	.shortDescMsg = MESSAGE_ID(0x28, 0x043),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_15,
	.costFP = 0,
	.costBP = 0
},
{	// move A2: ElectroDash2
	.nameMsg = MESSAGE_ID(0x2B, 0x014),
	.fullDescMsg = MESSAGE_ID(0x28, 0x049),
	.shortDescMsg = MESSAGE_ID(0x28, 0x043),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_15,
	.costFP = 0,
	.costBP = 0
},
{	// move A3: ElectroDash3
	.nameMsg = MESSAGE_ID(0x2B, 0x014),
	.fullDescMsg = MESSAGE_ID(0x28, 0x04A),
	.shortDescMsg = MESSAGE_ID(0x28, 0x043),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_15,
	.costFP = 0,
	.costBP = 0
},
{	// move A4: PowerShock
	.nameMsg = MESSAGE_ID(0x2B, 0x015),
	.fullDescMsg = MESSAGE_ID(0x28, 0x04B),
	.shortDescMsg = MESSAGE_ID(0x28, 0x044),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_3,
	.costFP = 2,
	.costBP = 0
},
{	// move A5: TurboCharge
	.nameMsg = MESSAGE_ID(0x2B, 0x016),
	.fullDescMsg = MESSAGE_ID(0x28, 0x04C),
	.shortDescMsg = MESSAGE_ID(0x28, 0x045),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_10,
	.costFP = 3,
	.costBP = 0
},
{	// move A6: MegaShock
	.nameMsg = MESSAGE_ID(0x2B, 0x017),
	.fullDescMsg = MESSAGE_ID(0x28, 0x04D),
	.shortDescMsg = MESSAGE_ID(0x28, 0x046),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_12,
	.costFP = 5,
	.costBP = 0
},
{	// move A7: BellyFlop1
	.nameMsg = MESSAGE_ID(0x2B, 0x018),
	.fullDescMsg = MESSAGE_ID(0x28, 0x055),
	.shortDescMsg = MESSAGE_ID(0x28, 0x050),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move A8: BellyFlop2
	.nameMsg = MESSAGE_ID(0x2B, 0x018),
	.fullDescMsg = MESSAGE_ID(0x28, 0x056),
	.shortDescMsg = MESSAGE_ID(0x28, 0x050),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move A9: BellyFlop3
	.nameMsg = MESSAGE_ID(0x2B, 0x018),
	.fullDescMsg = MESSAGE_ID(0x28, 0x057),
	.shortDescMsg = MESSAGE_ID(0x28, 0x050),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_80 | MOVE_DATA_FLAG_800 | MOVE_DATA_FLAG_4000 | MOVE_DATA_FLAG_10000 | MOVE_DATA_FLAG_40000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_1,
	.costFP = 0,
	.costBP = 0
},
{	// move AA: Squirt
	.nameMsg = MESSAGE_ID(0x2B, 0x019),
	.fullDescMsg = MESSAGE_ID(0x28, 0x058),
	.shortDescMsg = MESSAGE_ID(0x28, 0x051),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_14,
	.costFP = 3,
	.costBP = 0
},
{	// move AB: WaterBlock
	.nameMsg = MESSAGE_ID(0x2B, 0x01A),
	.fullDescMsg = MESSAGE_ID(0x28, 0x059),
	.shortDescMsg = MESSAGE_ID(0x28, 0x052),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_10,
	.costFP = 3,
	.costBP = 0
},
{	// move AC: TidalWave
	.nameMsg = MESSAGE_ID(0x2B, 0x01B),
	.fullDescMsg = MESSAGE_ID(0x28, 0x05A),
	.shortDescMsg = MESSAGE_ID(0x28, 0x053),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_8,
	.costFP = 6,
	.costBP = 0
},
{	// move AD: SpinyFlip1
	.nameMsg = MESSAGE_ID(0x2B, 0x01C),
	.fullDescMsg = MESSAGE_ID(0x28, 0x062),
	.shortDescMsg = MESSAGE_ID(0x28, 0x05D),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_16,
	.costFP = 0,
	.costBP = 0
},
{	// move AE: SpinyFlip2
	.nameMsg = MESSAGE_ID(0x2B, 0x01C),
	.fullDescMsg = MESSAGE_ID(0x28, 0x063),
	.shortDescMsg = MESSAGE_ID(0x28, 0x05D),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_16,
	.costFP = 0,
	.costBP = 0
},
{	// move AF: SpinyFlip3
	.nameMsg = MESSAGE_ID(0x2B, 0x01C),
	.fullDescMsg = MESSAGE_ID(0x28, 0x064),
	.shortDescMsg = MESSAGE_ID(0x28, 0x05D),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_16,
	.costFP = 0,
	.costBP = 0
},
{	// move B0: SpinySurge
	.nameMsg = MESSAGE_ID(0x2B, 0x01D),
	.fullDescMsg = MESSAGE_ID(0x28, 0x065),
	.shortDescMsg = MESSAGE_ID(0x28, 0x05E),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 4,
	.costBP = 0
},
{	// move B1: CloudNine
	.nameMsg = MESSAGE_ID(0x2B, 0x01E),
	.fullDescMsg = MESSAGE_ID(0x28, 0x066),
	.shortDescMsg = MESSAGE_ID(0x28, 0x05F),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_10,
	.costFP = 4,
	.costBP = 0
},
{	// move B2: Hurricane
	.nameMsg = MESSAGE_ID(0x2B, 0x01F),
	.fullDescMsg = MESSAGE_ID(0x28, 0x067),
	.shortDescMsg = MESSAGE_ID(0x28, 0x060),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_12,
	.costFP = 5,
	.costBP = 0
},
{	// move B3: Smack1
	.nameMsg = MESSAGE_ID(0x2B, 0x010),
	.fullDescMsg = MESSAGE_ID(0x28, 0x03B),
	.shortDescMsg = MESSAGE_ID(0x28, 0x036),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 0,
	.costBP = 0
},
{	// move B4: Smack2
	.nameMsg = MESSAGE_ID(0x2B, 0x010),
	.fullDescMsg = MESSAGE_ID(0x28, 0x03C),
	.shortDescMsg = MESSAGE_ID(0x28, 0x036),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 0,
	.costBP = 0
},
{	// move B5: Smack3
	.nameMsg = MESSAGE_ID(0x2B, 0x010),
	.fullDescMsg = MESSAGE_ID(0x28, 0x03D),
	.shortDescMsg = MESSAGE_ID(0x28, 0x036),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 0,
	.costBP = 0
},
{	// move B6: OuttaSight
	.nameMsg = MESSAGE_ID(0x2B, 0x011),
	.fullDescMsg = MESSAGE_ID(0x28, 0x03E),
	.shortDescMsg = MESSAGE_ID(0x28, 0x037),
	.flags = MOVE_DATA_FLAG_TARGET_PLAYER,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_NONE,
	.costFP = 2,
	.costBP = 0
},
{	// move B7: Spook
	.nameMsg = MESSAGE_ID(0x2B, 0x012),
	.fullDescMsg = MESSAGE_ID(0x28, 0x03F),
	.shortDescMsg = MESSAGE_ID(0x28, 0x038),
	.flags = MOVE_DATA_FLAG_2 | MOVE_DATA_FLAG_8000,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 3,
	.costBP = 0
},
{	// move B8: FanSmack
	.nameMsg = MESSAGE_ID(0x2B, 0x013),
	.fullDescMsg = MESSAGE_ID(0x28, 0x040),
	.shortDescMsg = MESSAGE_ID(0x28, 0x039),
	.flags = MOVE_DATA_FLAG_SINGLE_TARGET | MOVE_DATA_FLAG_2,
	.category = MOVE_TYPE_PARTNER,
	.actionTip = MOVE_ACTION_TIP_4,
	.costFP = 5,
	.costBP = 0
},
};

//TODO padding
s32 pad_after_move_table[] = {
    0x00000000, 0x00000000, 0x00000000
};

s32 gMessageBoxFrameParts[] = {
0x802EBFF0, 0x802EC010, 0x802EC030, 0x802EC050, 0x802EC070, 0x802EC090, 0x802EC0B0, 0x802EC0D0, 0x802EC0F0, 0x802EC110, 0x802EC130, 0x802EC150, 0x802EC170, 0x802EC190, 0x802EC1B0, 0x802EC1D0, 0x802EC1F0, 0x802EC210, 0x802EC230, 0x802EC250, 0x802EC270, 0x802EC290, 0x802EC2B0, 0x802EC2D0, 0x802EC2F0, 0x802EC310, 0x802EC330, 0x802EC350, 0x802EC370, 0x802EC390, 0x802EC3B0, 0x802EC3D0
};
