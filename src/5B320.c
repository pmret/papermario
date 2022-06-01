#include "common.h"
#include "hud_element.h"
#include "item_entity.h"

#define STANDARD_ITEM_SCRIPT(icon) \
    { \
        is_SetIcon(60, icon) \
		is_Restart \
		is_End \
    }

#define STANDARD_ITEM_HUD_SCRIPT(icon) \
    { \
		hs_SetVisible \
		hs_SetTileSize(HUD_ELEMENT_SIZE_32x32) \
		hs_Loop \
			hs_SetIcon(60, icon) \
		hs_Restart \
		hs_End \
    }

HudScript HudScript_HandPointDownLoop = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(1, anim_hand_0)
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(1, anim_hand_0)
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(1, anim_hand_0)
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(1, anim_hand_0)
		hs_SetTexelOffset(2, -1)
		hs_SetIcon(1, anim_hand_1)
		hs_SetTexelOffset(2, -1)
		hs_SetIcon(1, anim_hand_2)
		hs_SetTexelOffset(2, -1)
		hs_SetIcon(4, anim_hand_3)
		hs_SetTexelOffset(2, 4)
		hs_SetIcon(1, anim_hand_1)
		hs_SetTexelOffset(0, 3)
		hs_SetIcon(1, anim_hand_0)
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(14, anim_hand_4)
	hs_Restart
	hs_End
};

HudScript HudScript_HandPointDown = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_SetTexelOffset(0, -1)
	hs_SetIcon(1, anim_hand_0)
	hs_SetTexelOffset(2, -1)
	hs_SetIcon(1, anim_hand_1)
	hs_SetTexelOffset(2, -1)
	hs_SetIcon(1, anim_hand_2)
	hs_SetTexelOffset(2, -1)
	hs_SetIcon(4, anim_hand_3)
	hs_SetTexelOffset(2, 4)
	hs_SetIcon(1, anim_hand_1)
	hs_SetTexelOffset(0, 3)
	hs_SetIcon(1, anim_hand_0)
	hs_SetTexelOffset(0, -1)
	hs_SetIcon(2, anim_hand_4)
	hs_SetTexelOffset(0, 3)
	hs_Loop
		hs_SetIcon(60, anim_hand_0)
	hs_Restart
	hs_End
};

HudScript HudScript_HandPointDownHeld = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetIcon(60, anim_hand_0)
	hs_Restart
	hs_End
};

HudScript HudScript_HandPointLeftLoop = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetTexelOffset(0, 0)
		hs_SetIcon(1, anim_hand_5)
		hs_SetTexelOffset(0, 0)
		hs_SetIcon(1, anim_hand_5)
		hs_SetTexelOffset(0, 0)
		hs_SetIcon(1, anim_hand_5)
		hs_SetTexelOffset(0, 0)
		hs_SetIcon(1, anim_hand_5)
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(1, anim_hand_6)
		hs_SetTexelOffset(0, -1)
		hs_SetIcon(1, anim_hand_7)
		hs_SetTexelOffset(1, -3)
		hs_SetIcon(4, anim_hand_8)
		hs_SetTexelOffset(0, 4)
		hs_SetIcon(1, anim_hand_6)
		hs_SetTexelOffset(0, 4)
		hs_SetIcon(1, anim_hand_5)
		hs_SetTexelOffset(0, 1)
		hs_SetIcon(14, anim_hand_9)
	hs_Restart
	hs_End
};

HudScript HudScript_HandPointLeft = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_SetTexelOffset(0, 0)
	hs_SetIcon(1, anim_hand_5)
	hs_SetTexelOffset(0, -1)
	hs_SetIcon(1, anim_hand_6)
	hs_SetTexelOffset(0, -1)
	hs_SetIcon(1, anim_hand_7)
	hs_SetTexelOffset(1, -3)
	hs_SetIcon(4, anim_hand_8)
	hs_SetTexelOffset(0, 4)
	hs_SetIcon(1, anim_hand_6)
	hs_SetTexelOffset(0, 4)
	hs_SetIcon(1, anim_hand_5)
	hs_SetTexelOffset(0, 1)
	hs_SetIcon(2, anim_hand_9)
	hs_SetTexelOffset(0, 4)
	hs_Loop
		hs_SetIcon(60, anim_hand_5)
	hs_Restart
	hs_End
};

HudScript HudScript_HandPointLeftHeld = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetIcon(60, anim_hand_5)
	hs_Restart
	hs_End
};

#include "item_hud_scripts.inc.c"

//TODO padding
s32 pad_after_item_hudscripts[] = {
    0x00000000, 0x00000000
};

#include "item_table.inc.c"

#include "item_hud_script_table.inc.c"

#include "item_entity_scripts.inc.c"

s32 D_8008EEC0[] = {
0, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000009, 0x00000006, 0x00000007, 0x00000008, 0x00000005, 0x0000000A, 0x0000000B
};

s32 D_8008EEF0[] = {
0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000000, 0x00000006, 0x00000007, 0x00000008, 0x00000005, 0x00000000, 0x00000000
};

const char D_800989A0[] = "なし";

s32 gPartnerPopupProperties[][4] = {
    {&D_800989A0, 0x00000000, 0x00000000, 0x00000000},
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
extern HudScript HudScript_Partner9;
extern HudScript HudScript_Bow;
extern HudScript HudScript_PartnerA;
extern HudScript HudScript_PartnerB;
extern HudScript HudScript_Partner0Disabled;
extern HudScript HudScript_GoombarioDisabled;
extern HudScript HudScript_KooperDisabled;
extern HudScript HudScript_BombetteDisabled;
extern HudScript HudScript_ParakarryDisabled;
extern HudScript HudScript_WattDisabled;
extern HudScript HudScript_SushieDisabled;
extern HudScript HudScript_LakilesterDisabled;
extern HudScript HudScript_Partner9Disabled;
extern HudScript HudScript_BowDisabled;
extern HudScript HudScript_PartnerADisabled;
extern HudScript HudScript_PartnerBDisabled;

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
    { .enabled = &HudScript_Partner9, .disabled = &HudScript_Partner9Disabled, },
    { .enabled = &HudScript_PartnerA, .disabled = &HudScript_PartnerADisabled, },
    { .enabled = &HudScript_PartnerB, .disabled = &HudScript_PartnerBDisabled, },
    { .enabled = &HudScript_PartnerB, .disabled = &HudScript_PartnerBDisabled },
};

#include "move_table.inc.c"

//TODO padding
s32 pad_after_move_table[] = {
    0x00000000, 0x00000000, 0x00000000
};

s32 gMessageBoxFrameParts[] = {
	0x802EBFF0, 0x802EC010, 0x802EC030, 0x802EC050, 0x802EC070, 0x802EC090, 0x802EC0B0, 0x802EC0D0, 0x802EC0F0, 0x802EC110, 0x802EC130, 0x802EC150, 0x802EC170, 0x802EC190, 0x802EC1B0, 0x802EC1D0, 0x802EC1F0, 0x802EC210, 0x802EC230, 0x802EC250, 0x802EC270, 0x802EC290, 0x802EC2B0, 0x802EC2D0, 0x802EC2F0, 0x802EC310, 0x802EC330, 0x802EC350, 0x802EC370, 0x802EC390, 0x802EC3B0, 0x802EC3D0
};
