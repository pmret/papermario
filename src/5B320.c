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

s32 D_8008EEC0[] = { 0, 1, 2, 3, 4, 9, 6, 7, 8, 5, 10, 11 };

s32 D_8008EEF0[] = { 0, 1, 2, 3, 4, 0, 6, 7, 8, 5, 0, 0 };

PartnerPopupProperties gPartnerPopupProperties[] = {
    [PARTNER_NONE] {
        "なし",
        0x00000000,
        0x00000000,
        0x00000000,
    },
    [PARTNER_GOOMBARIO] {
        MSG_Menus_Party_Goombario,
        0x00000002,
        MSG_PartnerDesc_Goombario_World,
        MSG_PartnerDesc_Goombario_Battle,
    },
    [PARTNER_KOOPER] {
        MSG_Menus_Party_Kooper,
        0x00000003,
        MSG_PartnerDesc_Kooper_World,
        MSG_PartnerDesc_Kooper_Battle,
    },
    [PARTNER_BOMBETTE] {
        MSG_Menus_Party_Bombette,
        0x00000004,
        MSG_PartnerDesc_Bombette_World,
        MSG_PartnerDesc_Bombette_Battle,
    },
    [PARTNER_PARAKARRY] {
        MSG_Menus_Party_Parakarry,
        0x00000005,
        MSG_PartnerDesc_Parakarry_World,
        MSG_PartnerDesc_Parakarry_Battle,
    },
    [PARTNER_GOOMPA] {
        MSG_Menus_Party_Goompa,
        0x00000001,
        0x00000000,
        0x00000000,
    },
    [PARTNER_WATT] {
        MSG_Menus_Party_Watt,
        0x00000007,
        MSG_PartnerDesc_Watt_World,
        MSG_PartnerDesc_Watt_Battle,
    },
    [PARTNER_SUSHIE] {
        MSG_Menus_Party_Sushie,
        0x00000008,
        MSG_PartnerDesc_Sushie_World,
        MSG_PartnerDesc_Sushie_Battle,
    },
    [PARTNER_LAKILESTER] {
        MSG_Menus_Party_Lakilester,
        0x00000009,
        MSG_PartnerDesc_Lakilester_World,
        MSG_PartnerDesc_Lakilester_Battle,
    },
    [PARTNER_BOW] {
        MSG_Menus_Party_Bow,
        0x00000006,
        MSG_PartnerDesc_Bow_World,
        MSG_PartnerDesc_Bow_Battle,
    },
    [PARTNER_GOOMBARIA] {
        MSG_Menus_Party_Goombaria,
        0x00000001,
        0x00000000,
        0x00000000,
    },
    [PARTNER_TWINK] {
        MSG_Menus_Party_Twink,
        0x00000001,
        0x00000000,
        0x00000000,
    }
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
