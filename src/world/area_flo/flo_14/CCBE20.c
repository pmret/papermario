#include "flo_14.h"
#include "sprite/npc/bubulb.h"
#include "sprite/npc/bzzap.h"

enum {
    NPC_BUBULB,
    NPC_BZZAP,
};

BSS s32 N(ItemChoiceList)[91];

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

MobileAISettings N(npcAISettings_802444D8) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 4.5f,
    .chaseTurnRate= 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 90.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80244508) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(npcAISettings_802444D8)))
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

s32 N(ItemChoice_HasSelectedItem) = {
    0x00000000,
};

s32 N(ItemChoice_SelectedItemID) = {
    0x00000000,
};

EvtScript N(80244604) = {
    EVT_SET(LVar9, LVar1)
    EVT_CALL(ShowConsumableChoicePopup)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveItemAt, LVar1)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_CALL(N(AddPlayerHandsOffset), LVar3, LVar4, LVar5)
            EVT_CALL(MakeItemEntity, LVar0, LVar3, LVar4, LVar5, 1, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
            EVT_WAIT(30)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_SWITCH
    EVT_CALL(N(ItemChoice_SaveSelected), LVarA)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80244738) = {
    EVT_CALL(N(BuildItemChoiceList), LVar0)
    EVT_BIND_PADLOCK(N(80244604), 0x10, 0, EVT_PTR(N(ItemChoiceList)), 0, 1)
    EVT_CALL(N(ItemChoice_WaitForSelection), LVar0)
    EVT_RETURN
    EVT_END
};


s32 N(D_80244788_CCFA98)[] = {
    ITEM_BUBBLE_BERRY, ITEM_NONE
};

EvtScript N(interact_80244790) = {
    EVT_IF_EQ(AreaFlag(37), 1)
        EVT_SET(AreaFlag(35), 1)
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0063)
        EVT_SET(AreaFlag(35), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AreaFlag(35), 1)
    EVT_IF_EQ(GF_FLO14_GaveBerryToBubblePlant, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_005F)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0060)
    EVT_END_IF
    EVT_CALL(FindItem, 161, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_SET(LVar0, EVT_PTR(N(D_80244788_CCFA98)))
        EVT_SET(LVar1, 0)
        EVT_EXEC_WAIT(N(80244738))
        EVT_IF_EQ(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0064)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0061)
            EVT_SET(AreaFlag(36), 1)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
            EVT_CALL(PlayerMoveTo, 555, 110, 20)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), FALSE)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(func_802CF56C, 2)
            EVT_WAIT(5)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(1.0), 0, 350, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
            EVT_EXEC(N(80243870))
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0062)
            EVT_THREAD
                EVT_WAIT(40)
                EVT_CALL(InterpPlayerYaw, 315, 0)
            EVT_END_THREAD
            EVT_LABEL(10)
            EVT_IF_EQ(AreaFlag(37), 0)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH6_0063)
            EVT_SET(GF_FLO14_GaveBerryToBubblePlant, 1)
            EVT_BIND_TRIGGER(N(8024352C), TRIGGER_FLOOR_PRESS_A, 30, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AreaFlag(35), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80244ADC) = {
    EVT_SET(AreaFlag(36), 0)
    EVT_SET(AreaFlag(37), 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80244790)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80244B20) = {
    .id = NPC_BUBULB,
    .settings = &N(npcSettings_802445A4),
    .pos = { 617.0f, 0.0f, 108.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_4000,
    .init = &N(init_80244ADC),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
    .tattle = MSG_NpcTattle_BubblePlant,
};

StaticNpc N(npcGroup_80244D10) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80244578),
    .pos = { -175.0f, 55.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .yaw = 90,
    .drops = {
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
    },
	.territory = { .temp = { -175, 55, 15, 30, 0, -32767, 0, -175, 55, 15, 200, 0, 0, 1 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(npcGroupList_80244F00) = {
    NPC_GROUP(N(npcGroup_80244B20)),
    NPC_GROUP(N(npcGroup_80244D10), 0x1819, 0x00),
    {},
};

static s32 N(pad_4F24)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80244F30) = {
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 675, 60, -100, 17, GF_FLO14_Item_StarPiece)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4F64)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80244F70) = {
    EVT_LOOP(0)
        EVT_CALL(N(func_80242360_CCD670), LVar0)
        EVT_IF_EQ(LVar0, LVar4)
            EVT_CALL(GetPlayerActionState, LVar0)
            EVT_IF_NE(LVar0, 23)
                EVT_IF_EQ(LVar8, 0)
                    EVT_THREAD
                        EVT_CALL(GetModelCenter, LVar5)
                        EVT_CALL(PlaySoundAt, 0x1DB, 4194304, LVar0, LVar1, LVar2)
                    EVT_END_THREAD
                EVT_END_IF
                EVT_IF_LT(LVar7, 90)
                    EVT_IF_EQ(LVar7, 0)
                        EVT_WAIT(5)
                        EVT_SET(LVar8, 6)
                        EVT_CALL(ModifyColliderFlags, 0, LVar9, 0x7FFFFE00)
                    EVT_END_IF
                    EVT_ADD(LVar8, 1)
                    EVT_ADD(LVar7, LVar8)
                EVT_END_IF
                EVT_GOTO(50)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_NE(LVar7, 0)
            EVT_SUB(LVar8, 1)
            EVT_ADD(LVar7, LVar8)
            EVT_IF_LE(LVar7, 0)
                EVT_SET(LVar8, 0)
                EVT_SET(LVar7, 0)
                EVT_THREAD
                    EVT_CALL(GetModelCenter, LVar5)
                    EVT_CALL(PlaySoundAt, 0x1DC, 0, LVar0, LVar1, LVar2)
                EVT_END_THREAD
                EVT_CALL(ModifyColliderFlags, 1, LVar9, 0x7FFFFE00)
            EVT_END_IF
        EVT_END_IF
        EVT_LABEL(50)
        EVT_IF_GE(LVar7, 90)
            EVT_SET(LVar8, -1)
            EVT_SET(LVar7, 90)
        EVT_END_IF
        EVT_CALL(RotateModel, LVar5, LVar7, -1, 0, 0)
        EVT_CALL(RotateModel, LVar6, LVar7, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80245224) = {
    EVT_SET(LVar4, 21)
    EVT_SET(LVar5, 21)
    EVT_SET(LVar6, 20)
    EVT_SET(LVar7, MapVar(10))
    EVT_SET(LVar8, MapVar(11))
    EVT_SET(LVar9, 22)
    EVT_EXEC(N(80244F70))
    EVT_SET(LVar4, 17)
    EVT_SET(LVar5, 26)
    EVT_SET(LVar6, 25)
    EVT_SET(LVar7, MapVar(12))
    EVT_SET(LVar8, MapVar(13))
    EVT_SET(LVar9, 18)
    EVT_EXEC(N(80244F70))
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/atomic/MakeConsumableChoice.inc.c"
