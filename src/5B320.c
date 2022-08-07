#include "common.h"
#include "hud_element.h"
#include "item_entity.h"
#include "world/world.h"

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

HudScript HES_HandPointDownLoop = {
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

HudScript HES_HandPointDown = {
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

HudScript HES_HandPointDownHeld = {
    hs_SetVisible
    hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
    hs_Loop
        hs_SetIcon(60, anim_hand_0)
    hs_Restart
    hs_End
};

HudScript HES_HandPointLeftLoop = {
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

HudScript HES_HandPointLeft = {
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

HudScript HES_HandPointLeftHeld = {
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

extern HudScript HES_Partner0;
extern HudScript HES_Goombario;
extern HudScript HES_Kooper;
extern HudScript HES_Bombette;
extern HudScript HES_Parakarry;
extern HudScript HES_Watt;
extern HudScript HES_Sushie;
extern HudScript HES_Lakilester;
extern HudScript HES_Partner9;
extern HudScript HES_Bow;
extern HudScript HES_PartnerA;
extern HudScript HES_PartnerB;
extern HudScript HES_Partner0Disabled;
extern HudScript HES_GoombarioDisabled;
extern HudScript HES_KooperDisabled;
extern HudScript HES_BombetteDisabled;
extern HudScript HES_ParakarryDisabled;
extern HudScript HES_WattDisabled;
extern HudScript HES_SushieDisabled;
extern HudScript HES_LakilesterDisabled;
extern HudScript HES_Partner9Disabled;
extern HudScript HES_BowDisabled;
extern HudScript HES_PartnerADisabled;
extern HudScript HES_PartnerBDisabled;

IconHudScriptPair gPartnerIconHudScripts[] = {
    { .enabled = &HES_Partner0, .disabled = &HES_Partner0Disabled, },
    { .enabled = &HES_Goombario, .disabled = &HES_GoombarioDisabled, },
    { .enabled = &HES_Kooper, .disabled = &HES_KooperDisabled, },
    { .enabled = &HES_Bombette, .disabled = &HES_BombetteDisabled, },
    { .enabled = &HES_Parakarry, .disabled = &HES_ParakarryDisabled, },
    { .enabled = &HES_Bow, .disabled = &HES_BowDisabled, },
    { .enabled = &HES_Watt, .disabled = &HES_WattDisabled, },
    { .enabled = &HES_Sushie, .disabled = &HES_SushieDisabled, },
    { .enabled = &HES_Lakilester, .disabled = &HES_LakilesterDisabled, },
    { .enabled = &HES_Partner9, .disabled = &HES_Partner9Disabled, },
    { .enabled = &HES_PartnerA, .disabled = &HES_PartnerADisabled, },
    { .enabled = &HES_PartnerB, .disabled = &HES_PartnerBDisabled, },
    { .enabled = &HES_PartnerB, .disabled = &HES_PartnerBDisabled },
};

#include "move_table.inc.c"

//TODO padding
s32 pad_after_move_table[] = {
    0x00000000, 0x00000000, 0x00000000
};

s32* gMessageBoxFrameParts[] = {
    D_802EBFF0, D_802EC010, D_802EC030, D_802EC050,
    D_802EC070, D_802EC090, D_802EC0B0, D_802EC0D0,
    D_802EC0F0, D_802EC110, D_802EC130, D_802EC150,
    D_802EC170, D_802EC190, D_802EC1B0, D_802EC1D0,
    D_802EC1F0, D_802EC210, D_802EC230, D_802EC250,
    D_802EC270, D_802EC290, D_802EC2B0, D_802EC2D0,
    D_802EC2F0, D_802EC310, D_802EC330, D_802EC350,
    D_802EC370, D_802EC390, D_802EC3B0, D_802EC3D0
};
