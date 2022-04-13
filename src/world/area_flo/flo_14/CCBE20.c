#include "flo_14.h"
#include "sprite/npc/bubulb.h"
#include "sprite/npc/bzzap.h"

enum {
    NPC_BUBULB,
    NPC_BZZAP,
};

BSS s32 N(ItemChoiceList)[91];

f32 N(sixFloats)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_802444D8) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 2,
    .chaseSpeed = 4.5f,
    .unk_1C = { .s = 6 },
    .unk_20 = 1,
    .chaseRadius = 90.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

EvtScript N(npcAI_80244508) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(UnkNpcAIMainFunc9), EVT_PTR(N(npcAISettings_802444D8)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80244578) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80244508),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 19,
};

NpcSettings N(npcSettings_802445A4) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcSettings N(npcSettings_802445D0) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

s32 N(D_802445FC_CCF90C) = {
    0x00000000,
};

s32 N(D_80244600_CCF910) = {
    0x00000000,
};

EvtScript N(80244604) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(1))
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveItemAt, EVT_VAR(1))
            EVT_CALL(GetPlayerPos, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(N(AddPlayerHandsOffset), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
            EVT_CALL(MakeItemEntity, EVT_VAR(0), EVT_VAR(3), EVT_VAR(4), EVT_VAR(5), 1, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_60005)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(SetPlayerAnimation, ANIM_10002)
            EVT_CALL(RemoveItemEntity, EVT_VAR(0))
    EVT_END_SWITCH
    EVT_CALL(N(func_80242288_CCD598), EVT_VAR(10))
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80244738) = {
    EVT_CALL(N(BuildItemChoiceList), EVT_VAR(0))
    EVT_BIND_PADLOCK(N(80244604), 0x10, 0, EVT_PTR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(func_80242234_CCD544), EVT_VAR(0))
    EVT_RETURN
    EVT_END
};


s32 N(D_80244788_CCFA98)[] = {
    ITEM_BUBBLE_BERRY, ITEM_NONE
};

EvtScript N(interact_80244790) = {
    EVT_IF_EQ(EVT_AREA_FLAG(37), 1)
        EVT_SET(EVT_AREA_FLAG(35), 1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0063))
        EVT_SET(EVT_AREA_FLAG(35), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_AREA_FLAG(35), 1)
    EVT_IF_EQ(EVT_SAVE_FLAG(1412), 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x005F))
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0060))
    EVT_END_IF
    EVT_CALL(FindItem, 161, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_SET(EVT_VAR(0), EVT_PTR(N(D_80244788_CCFA98)))
        EVT_SET(EVT_VAR(1), 0)
        EVT_EXEC_WAIT(N(80244738))
        EVT_IF_EQ(EVT_VAR(0), -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0064))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0061))
            EVT_SET(EVT_AREA_FLAG(36), 1)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(PlayerMoveTo, 555, 110, 20)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(func_802CF56C, 2)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(AdjustCam, 0, EVT_FIXED(1.0), 0, 350, EVT_FIXED(17.0), EVT_FIXED(-6.0))
            EVT_EXEC(N(80243870))
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0062))
            EVT_THREAD
                EVT_WAIT_FRAMES(40)
                EVT_CALL(InterpPlayerYaw, 315, 0)
            EVT_END_THREAD
            EVT_LABEL(10)
            EVT_IF_EQ(EVT_AREA_FLAG(37), 0)
                EVT_WAIT_FRAMES(1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(ResetCam, 0, EVT_FIXED(4.0))
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 5, MESSAGE_ID(0x11, 0x0063))
            EVT_SET(EVT_SAVE_FLAG(1412), 1)
            EVT_BIND_TRIGGER(N(8024352C), TRIGGER_FLOOR_PRESS_A, 30, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(EVT_AREA_FLAG(35), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80244ADC) = {
    EVT_SET(EVT_AREA_FLAG(36), 0)
    EVT_SET(EVT_AREA_FLAG(37), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80244790)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80244B20) = {
    .id = NPC_BUBULB,
    .settings = &N(npcSettings_802445A4),
    .pos = { 617.0f, 0.0f, 108.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_4000,
    .init = &N(init_80244ADC),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_E,
        NPC_ANIM_bubulb_Palette_00_Anim_E,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00E3),
};

StaticNpc N(npcGroup_80244D10) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80244578),
    .pos = { -175.0f, 55.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { -175, 55, 15, 30, 0, -32767, 0, -175, 55, 15, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_4,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80244F00) = {
    NPC_GROUP(N(npcGroup_80244B20), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80244D10), BATTLE_ID(24, 25, 0, 1)),
    {},
};

static s32 N(pad_4F24)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80244F30) = {
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 675, 60, -100, 17, EVT_SAVE_FLAG(1387))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4F64)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80244F70) = {
    EVT_LOOP(0)
        EVT_CALL(N(func_80242360_CCD670), EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), EVT_VAR(4))
            EVT_CALL(GetPlayerActionState, EVT_VAR(0))
            EVT_IF_NE(EVT_VAR(0), 23)
                EVT_IF_EQ(EVT_VAR(8), 0)
                    EVT_THREAD
                        EVT_CALL(GetModelCenter, EVT_VAR(5))
                        EVT_CALL(PlaySoundAt, 0x1DB, 4194304, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                    EVT_END_THREAD
                EVT_END_IF
                EVT_IF_LT(EVT_VAR(7), 90)
                    EVT_IF_EQ(EVT_VAR(7), 0)
                        EVT_WAIT_FRAMES(5)
                        EVT_SET(EVT_VAR(8), 6)
                        EVT_CALL(ModifyColliderFlags, 0, EVT_VAR(9), 0x7FFFFE00)
                    EVT_END_IF
                    EVT_ADD(EVT_VAR(8), 1)
                    EVT_ADD(EVT_VAR(7), EVT_VAR(8))
                EVT_END_IF
                EVT_GOTO(50)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_NE(EVT_VAR(7), 0)
            EVT_SUB(EVT_VAR(8), 1)
            EVT_ADD(EVT_VAR(7), EVT_VAR(8))
            EVT_IF_LE(EVT_VAR(7), 0)
                EVT_SET(EVT_VAR(8), 0)
                EVT_SET(EVT_VAR(7), 0)
                EVT_THREAD
                    EVT_CALL(GetModelCenter, EVT_VAR(5))
                    EVT_CALL(PlaySoundAt, 0x1DC, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
                EVT_END_THREAD
                EVT_CALL(ModifyColliderFlags, 1, EVT_VAR(9), 0x7FFFFE00)
            EVT_END_IF
        EVT_END_IF
        EVT_LABEL(50)
        EVT_IF_GE(EVT_VAR(7), 90)
            EVT_SET(EVT_VAR(8), -1)
            EVT_SET(EVT_VAR(7), 90)
        EVT_END_IF
        EVT_CALL(RotateModel, EVT_VAR(5), EVT_VAR(7), -1, 0, 0)
        EVT_CALL(RotateModel, EVT_VAR(6), EVT_VAR(7), -1, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80245224) = {
    EVT_SET(EVT_VAR(4), 21)
    EVT_SET(EVT_VAR(5), 21)
    EVT_SET(EVT_VAR(6), 20)
    EVT_SET(EVT_VAR(7), EVT_MAP_VAR(10))
    EVT_SET(EVT_VAR(8), EVT_MAP_VAR(11))
    EVT_SET(EVT_VAR(9), 22)
    EVT_EXEC(N(80244F70))
    EVT_SET(EVT_VAR(4), 17)
    EVT_SET(EVT_VAR(5), 26)
    EVT_SET(EVT_VAR(6), 25)
    EVT_SET(EVT_VAR(7), EVT_MAP_VAR(12))
    EVT_SET(EVT_VAR(8), EVT_MAP_VAR(13))
    EVT_SET(EVT_VAR(9), 18)
    EVT_EXEC(N(80244F70))
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/enemy/UnkAI_9.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80242234_CCD544)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802445FC_CCF90C) = FALSE;
    }

    if (N(D_802445FC_CCF90C)) {
        N(D_802445FC_CCF90C) = FALSE;
        evt_set_variable(script, *args, N(D_80244600_CCF910));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242288_CCD598)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80244600_CCF910) = evt_get_variable(script, *args);
    N(D_802445FC_CCF90C) = TRUE;
    return ApiStatus_DONE2;
}

#include "world/common/atomic/MakeConsumableChoice.inc.c"
