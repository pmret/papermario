#include "common.h"
#include "hud_element.h"
#include "item_entity.h"
#include "world/world.h"

#if !VERSION_JP
#define MSG_FullDesc_32 0
#define MSG_ItemFullDesc_AutoJump 0
#define MSG_ItemFullDesc_AutoMultibounce 0
#define MSG_ItemFullDesc_AutoSmash 0
#define MSG_ItemFullDesc_Berserker 0
#define MSG_ItemFullDesc_CrazyHeart 0
#define MSG_ItemFullDesc_EarthquakeJump 0
#define MSG_ItemFullDesc_FlowerFanatic 0
#define MSG_ItemFullDesc_ForestPass 0
#define MSG_ItemFullDesc_HealthyHealthy 0
#define MSG_ItemFullDesc_HustleDrink 0
#define MSG_ItemFullDesc_InsecticideHerb 0
#define MSG_ItemFullDesc_JumpCharge0 0
#define MSG_ItemFullDesc_Kaiden 0
#define MSG_ItemFullDesc_KootAltPhoto 0
#define MSG_ItemFullDesc_KootShell 0
#define MSG_ItemFullDesc_MegaHPDrain 0
#define MSG_ItemFullDesc_MysteryScroll 0
#define MSG_ItemFullDesc_PleaseComeBack 0
#define MSG_ItemFullDesc_Screwdriver 0
#define MSG_ItemFullDesc_ShellCrack 0
#define MSG_ItemFullDesc_SmashCharge0 0
#define MSG_ItemFullDesc_SuperFocus 0
#define MSG_ItemFullDesc_SuperJump 0
#define MSG_ItemFullDesc_SuperSmash 0
#define MSG_ItemFullDesc_SuspiciousNote 0
#define MSG_ItemFullDesc_ToadDoll 0
#define MSG_ItemFullDesc_UnusedLetter 0
#define MSG_ItemFullDesc_UnusedLetter02 0
#define MSG_ItemFullDesc_UnusedLetter03 0
#define MSG_ItemFullDesc_UnusedLetter04 0
#define MSG_ItemFullDesc_UnusedLetter05 0
#define MSG_ItemFullDesc_UnusedLetter06 0
#define MSG_ItemName_Heart 0
#define MSG_ItemName_Coin 0
#define MSG_ItemName_HeartPiece 0
#define MSG_ItemName_StarPoint 0
#define MSG_ItemName_HeartPoint 0
#define MSG_ItemName_FlowerPoint 0
#define MSG_ItemName_Map 0
#define MSG_ItemName_BigMap 0
#define MSG_ItemName_AutoJump 0
#define MSG_ItemName_AutoMultibounce 0
#define MSG_ItemName_AutoSmash 0
#define MSG_ItemName_Berserker 0
#define MSG_ItemName_CrazyHeart 0
#define MSG_ItemName_EarthquakeJump 0
#define MSG_ItemName_FlowerFanatic 0
#define MSG_ItemName_ForestPass 0
#define MSG_ItemName_HealthyHealthy 0
#define MSG_ItemName_HustleDrink 0
#define MSG_ItemName_InsecticideHerb 0
#define MSG_ItemName_JumpCharge0 0
#define MSG_ItemName_Kaiden 0
#define MSG_ItemName_KootAltPhoto 0
#define MSG_ItemName_KootShell 0
#define MSG_ItemName_MegaHPDrain 0
#define MSG_ItemName_MysteryScroll 0
#define MSG_ItemName_PleaseComeBack 0
#define MSG_ItemName_Screwdriver 0
#define MSG_ItemName_ShellCrack 0
#define MSG_ItemName_SmashCharge0 0
#define MSG_ItemName_SuperFocus 0
#define MSG_ItemName_SuperJump 0
#define MSG_ItemName_SuperSmash 0
#define MSG_ItemName_SuspiciousNote 0
#define MSG_ItemName_ToadDoll 0
#define MSG_ItemName_UnusedLetter 0
#define MSG_ItemName_UnusedLetter02 0
#define MSG_ItemName_UnusedLetter03 0
#define MSG_ItemName_UnusedLetter04 0
#define MSG_ItemName_UnusedLetter05 0
#define MSG_ItemName_UnusedLetter06 0
#define MSG_ItemShortDesc_AutoJump 0
#define MSG_ItemShortDesc_AutoMultibounce 0
#define MSG_ItemShortDesc_AutoSmash 0
#define MSG_ItemShortDesc_Berserker 0
#define MSG_ItemShortDesc_CrazyHeart 0
#define MSG_ItemShortDesc_EarthquakeJump 0
#define MSG_ItemShortDesc_FlowerFanatic 0
#define MSG_ItemShortDesc_ForestPass 0
#define MSG_ItemShortDesc_HealthyHealthy 0
#define MSG_ItemShortDesc_HustleDrink 0
#define MSG_ItemShortDesc_InsecticideHerb 0
#define MSG_ItemShortDesc_JumpCharge0 0
#define MSG_ItemShortDesc_Kaiden 0
#define MSG_ItemShortDesc_KootAltPhoto 0
#define MSG_ItemShortDesc_KootShell 0
#define MSG_ItemShortDesc_MegaHPDrain 0
#define MSG_ItemShortDesc_MysteryScroll 0
#define MSG_ItemShortDesc_PleaseComeBack 0
#define MSG_ItemShortDesc_Screwdriver 0
#define MSG_ItemShortDesc_ShellCrack 0
#define MSG_ItemShortDesc_SmashCharge0 0
#define MSG_ItemShortDesc_SuperFocus 0
#define MSG_ItemShortDesc_SuperJump 0
#define MSG_ItemShortDesc_SuperSmash 0
#define MSG_ItemShortDesc_SuspiciousNote 0
#define MSG_ItemShortDesc_ToadDoll 0
#define MSG_ItemShortDesc_UnusedLetter 0
#define MSG_ItemShortDesc_UnusedLetter02 0
#define MSG_ItemShortDesc_UnusedLetter03 0
#define MSG_ItemShortDesc_UnusedLetter04 0
#define MSG_ItemShortDesc_UnusedLetter05 0
#define MSG_ItemShortDesc_UnusedLetter06 0
#define MSG_MoveName_32 0
#define MSG_MoveName_AutoJump 0
#define MSG_MoveName_AutoMultibounce 0
#define MSG_MoveName_AutoSmash 0
#define MSG_MoveName_Berserker 0
#define MSG_MoveName_BumpAttack 0
#define MSG_MoveName_CloseCall 0
#define MSG_MoveName_CrazyHeart 0
#define MSG_MoveName_DefendPlus 0
#define MSG_MoveName_DizzyAttack 0
#define MSG_MoveName_EarthquakeJump 0
#define MSG_MoveName_FlowerFanatic 0
#define MSG_MoveName_FlowerFinder 0
#define MSG_MoveName_HealthyHealthy 0
#define MSG_MoveName_HeartFinder 0
#define MSG_MoveName_ISpy 0
#define MSG_MoveName_JumpCharge0 0
#define MSG_MoveName_LastStand 0
#define MSG_MoveName_LuckyDay 0
#define MSG_MoveName_MegaHPDrain 0
#define MSG_MoveName_PowerRush 0
#define MSG_MoveName_SmashCharge0 0
#define MSG_MoveName_SpeedySpin 0
#define MSG_MoveName_SpinAttack 0
#define MSG_MoveName_SuperJump 0
#define MSG_MoveName_SuperSmash 0
#define MSG_PartnerDesc_Goombaria_Battle 0
#define MSG_PartnerDesc_Goombaria_World 0
#define MSG_PartnerDesc_Goompa_Battle 0
#define MSG_PartnerDesc_Goompa_World 0
#define MSG_PartnerDesc_Twink_Battle 0
#define MSG_PartnerDesc_Twink_World 0
#define MSG_ShortDesc_32 0

// Use generic names for the different levels of partner moves
#define MSG_PartnerMoveName_BellyFlop1 MSG_PartnerMoveName_BellyFlop
#define MSG_PartnerMoveName_BellyFlop2 MSG_PartnerMoveName_BellyFlop
#define MSG_PartnerMoveName_BellyFlop3 MSG_PartnerMoveName_BellyFlop
#define MSG_PartnerMoveName_BodySlam1 MSG_PartnerMoveName_BodySlam
#define MSG_PartnerMoveName_BodySlam2 MSG_PartnerMoveName_BodySlam
#define MSG_PartnerMoveName_BodySlam3 MSG_PartnerMoveName_BodySlam
#define MSG_PartnerMoveName_ElectroDash1 MSG_PartnerMoveName_ElectroDash
#define MSG_PartnerMoveName_ElectroDash2 MSG_PartnerMoveName_ElectroDash
#define MSG_PartnerMoveName_ElectroDash3 MSG_PartnerMoveName_ElectroDash
#define MSG_PartnerMoveName_Headbonk1 MSG_PartnerMoveName_Headbonk
#define MSG_PartnerMoveName_Headbonk2 MSG_PartnerMoveName_Headbonk
#define MSG_PartnerMoveName_Headbonk3 MSG_PartnerMoveName_Headbonk
#define MSG_PartnerMoveName_ShellToss1 MSG_PartnerMoveName_ShellToss
#define MSG_PartnerMoveName_ShellToss2 MSG_PartnerMoveName_ShellToss
#define MSG_PartnerMoveName_ShellToss3 MSG_PartnerMoveName_ShellToss
#define MSG_PartnerMoveName_SkyDive1 MSG_PartnerMoveName_SkyDive
#define MSG_PartnerMoveName_SkyDive2 MSG_PartnerMoveName_SkyDive
#define MSG_PartnerMoveName_SkyDive3 MSG_PartnerMoveName_SkyDive
#define MSG_PartnerMoveName_Smack1 MSG_PartnerMoveName_Smack
#define MSG_PartnerMoveName_Smack2 MSG_PartnerMoveName_Smack
#define MSG_PartnerMoveName_Smack3 MSG_PartnerMoveName_Smack
#define MSG_PartnerMoveName_SpinyFlip1 MSG_PartnerMoveName_SpinyFlip
#define MSG_PartnerMoveName_SpinyFlip2 MSG_PartnerMoveName_SpinyFlip
#define MSG_PartnerMoveName_SpinyFlip3 MSG_PartnerMoveName_SpinyFlip
#endif

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

#include "item_data.inc.c"

//TODO split for partner popup menu data?

// "change partner" menu position -> partnerID
s32 PartnerIDFromMenuIndex[] = {
    PARTNER_NONE,
    PARTNER_GOOMBARIO,
    PARTNER_KOOPER,
    PARTNER_BOMBETTE,
    PARTNER_PARAKARRY,
    PARTNER_BOW,
    PARTNER_WATT,
    PARTNER_SUSHIE,
    PARTNER_LAKILESTER,
    PARTNER_GOOMPA,
    PARTNER_GOOMBARIA,
    PARTNER_TWINK
};

// partnerID -> "change partner" menu position
s32 MenuIndexFromPartnerID[] = {
    [PARTNER_NONE]          0,
    [PARTNER_GOOMBARIO]     1,
    [PARTNER_KOOPER]        2,
    [PARTNER_BOMBETTE]      3,
    [PARTNER_PARAKARRY]     4,
    [PARTNER_GOOMPA]        0,
    [PARTNER_WATT]          6,
    [PARTNER_SUSHIE]        7,
    [PARTNER_LAKILESTER]    8,
    [PARTNER_BOW]           5,
    [PARTNER_GOOMBARIA]     0,
    [PARTNER_TWINK]         0,
};

PartnerPopupProperties gPartnerPopupProperties[] = {
    [PARTNER_NONE] {
        (s32) "なし",
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
        MSG_PartnerDesc_Goompa_World,
        MSG_PartnerDesc_Goompa_Battle,
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
        MSG_PartnerDesc_Goombaria_World,
        MSG_PartnerDesc_Goombaria_Battle,
    },
    [PARTNER_TWINK] {
        MSG_Menus_Party_Twink,
        0x00000001,
        MSG_PartnerDesc_Twink_World,
        MSG_PartnerDesc_Twink_Battle,
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
    { .enabled = &HES_Partner0, .disabled = &HES_Partner0Disabled },
    { .enabled = &HES_Goombario, .disabled = &HES_GoombarioDisabled },
    { .enabled = &HES_Kooper, .disabled = &HES_KooperDisabled },
    { .enabled = &HES_Bombette, .disabled = &HES_BombetteDisabled },
    { .enabled = &HES_Parakarry, .disabled = &HES_ParakarryDisabled },
    { .enabled = &HES_Bow, .disabled = &HES_BowDisabled },
    { .enabled = &HES_Watt, .disabled = &HES_WattDisabled },
    { .enabled = &HES_Sushie, .disabled = &HES_SushieDisabled },
    { .enabled = &HES_Lakilester, .disabled = &HES_LakilesterDisabled },
    { .enabled = &HES_Partner9, .disabled = &HES_Partner9Disabled },
    { .enabled = &HES_PartnerA, .disabled = &HES_PartnerADisabled },
    { .enabled = &HES_PartnerB, .disabled = &HES_PartnerBDisabled },
    { .enabled = &HES_PartnerB, .disabled = &HES_PartnerBDisabled },
};

#include "move_data.inc.c"

//TODO padding
s32 pad_after_move_table[] = {
    0x00000000, 0x00000000, 0x00000000
};

extern IMG_BIN ui_msg_frame_a_1_1_png[];
extern IMG_BIN ui_msg_frame_a_1_2_png[];
extern IMG_BIN ui_msg_frame_a_1_3_png[];
extern IMG_BIN ui_msg_frame_a_1_4_png[];
extern IMG_BIN ui_msg_frame_a_1_5_png[];
extern IMG_BIN ui_msg_frame_a_2_1_png[];
extern IMG_BIN ui_msg_frame_a_2_5_png[];
extern IMG_BIN ui_msg_frame_a_3_1_png[];
extern IMG_BIN ui_msg_frame_a_3_5_png[];
extern IMG_BIN ui_msg_frame_a_4_1_png[];
extern IMG_BIN ui_msg_frame_a_4_5_png[];
extern IMG_BIN ui_msg_frame_a_5_1_png[];
extern IMG_BIN ui_msg_frame_a_5_2_png[];
extern IMG_BIN ui_msg_frame_a_5_3_png[];
extern IMG_BIN ui_msg_frame_a_5_4_png[];
extern IMG_BIN ui_msg_frame_a_5_5_png[];
extern IMG_BIN ui_msg_frame_b_1_1_png[];
extern IMG_BIN ui_msg_frame_b_1_2_png[];
extern IMG_BIN ui_msg_frame_b_1_3_png[];
extern IMG_BIN ui_msg_frame_b_1_4_png[];
extern IMG_BIN ui_msg_frame_b_1_5_png[];
extern IMG_BIN ui_msg_frame_b_2_1_png[];
extern IMG_BIN ui_msg_frame_b_2_5_png[];
extern IMG_BIN ui_msg_frame_b_3_1_png[];
extern IMG_BIN ui_msg_frame_b_3_5_png[];
extern IMG_BIN ui_msg_frame_b_4_1_png[];
extern IMG_BIN ui_msg_frame_b_4_5_png[];
extern IMG_BIN ui_msg_frame_b_5_1_png[];
extern IMG_BIN ui_msg_frame_b_5_2_png[];
extern IMG_BIN ui_msg_frame_b_5_3_png[];
extern IMG_BIN ui_msg_frame_b_5_4_png[];
extern IMG_BIN ui_msg_frame_b_5_5_png[];

IMG_BIN* gMessageBoxFrameParts[2][16] = {
    {
        ui_msg_frame_a_1_1_png, ui_msg_frame_a_1_2_png, ui_msg_frame_a_1_3_png, ui_msg_frame_a_1_4_png,
        ui_msg_frame_a_1_5_png, ui_msg_frame_a_2_1_png, ui_msg_frame_a_2_5_png, ui_msg_frame_a_3_1_png,
        ui_msg_frame_a_3_5_png, ui_msg_frame_a_4_1_png, ui_msg_frame_a_4_5_png, ui_msg_frame_a_5_1_png,
        ui_msg_frame_a_5_2_png, ui_msg_frame_a_5_3_png, ui_msg_frame_a_5_4_png, ui_msg_frame_a_5_5_png,
    },
    {
        ui_msg_frame_b_1_1_png, ui_msg_frame_b_1_2_png, ui_msg_frame_b_1_3_png, ui_msg_frame_b_1_4_png,
        ui_msg_frame_b_1_5_png, ui_msg_frame_b_2_1_png, ui_msg_frame_b_2_5_png, ui_msg_frame_b_3_1_png,
        ui_msg_frame_b_3_5_png, ui_msg_frame_b_4_1_png, ui_msg_frame_b_4_5_png, ui_msg_frame_b_5_1_png,
        ui_msg_frame_b_5_2_png, ui_msg_frame_b_5_3_png, ui_msg_frame_b_5_4_png, ui_msg_frame_b_5_5_png,
    }
};
