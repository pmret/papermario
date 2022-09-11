#include "arn_13.h"
#include "entity.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/tubbas_heart.h"

EvtScript N(exitSingleDoor_80240100) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 2)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_12"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_802401A4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 7)
    EVT_SET(LVar2, 2)
    EVT_SET(LVar3, 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_11"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240248) = {
    EVT_BIND_TRIGGER(N(exitSingleDoor_80240100), TRIGGER_WALL_PRESS_A, 2, 1, 0)
    EVT_BIND_TRIGGER(N(exitSingleDoor_802401A4), TRIGGER_WALL_PRESS_A, 7, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80240290) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, -1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(80240248))
        EVT_CASE_EQ(1)
            EVT_SET(LVar2, 2)
            EVT_SET(LVar3, 1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_EXEC(N(80240248))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 35)
    EVT_CALL(SetSpriteShading, 524292)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80240BCC)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80240060))
    EVT_EXEC(N(enterSingleDoor_80240290))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_424)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80240430) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80240440) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80240450) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80240430),
    .onDefeat = &N(80240440),
    .level = 13,
};

MobileAISettings N(npcAISettings_8024047C) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 15,
    .alertRadius = 150.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.3f,
    .chaseTurnRate= 70,
    .chaseUpdateInterval = 1,
    .chaseRadius = 180.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_802404AC) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(npcAISettings_8024047C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802404CC) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_802404AC),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

EvtScript N(idle_802404F8) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_14)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_SUB(LVar0, 80)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 12)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_14)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_SUB(LVar0, 80)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 12)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_SET(GB_StoryProgress, -19)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_802406F4) = {
    EVT_SET(GF_ARN13_Defeated_Goomba, 1)
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80240720) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_802404F8)))
    EVT_IF_NE(GB_StoryProgress, -22)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024076C) = {
    EVT_IF_LT(GB_StoryProgress, -12)
        EVT_IF_EQ(GF_ARN13_Defeated_Goomba, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802406F4)))
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802406F4)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802407EC)[] = {
    {
        .id = 0,
        .settings = &N(npcSettings_80240450),
        .pos = { 80.0f, 50.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(init_80240720),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
	.animations = {
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        },
    }
};

StaticNpc N(npcGroup_802409DC) = {
    .id = 1,
    .settings = &N(npcSettings_802404CC),
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_8024076C),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { 0, 0, 0, 20, 0, -32767, 0, 0, 0, 0, 150, 0, 0, 1 }},
    .animations = {
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_walk,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_idle,
        NPC_ANIM_goomba_hyper_pain,
        NPC_ANIM_goomba_hyper_pain,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
        NPC_ANIM_goomba_hyper_run,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(npcGroupList_80240BCC) = {
    NPC_GROUP(N(npcGroup_802407EC)),
    NPC_GROUP(N(npcGroup_802409DC), BTL_ARN_FORMATION_02, BTL_ARN_STAGE_04),
    {},
};

EvtScript N(80240BF0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0184, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), 200, 0, -40, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(80240BF0)))
    EVT_RETURN
    EVT_END
};
