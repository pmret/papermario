#include "arn_09.h"
#include "entity.h"
#include "sprite/npc/tubbas_heart.h"

extern s16 Entity_ScriptSpring_AnimLaunch[];

EvtScript N(80240140) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 5)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar4, 1)
    EVT_SET(LVar3, 1)
    EVT_EXEC(0x80285DFC)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_10"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(802401F4) = {
    EVT_BIND_TRIGGER(N(80240140), TRIGGER_WALL_PRESS_A, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240220) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 0)
            EVT_SET(LVar4, 1)
            EVT_SET(LVar3, 1)
            EVT_EXEC_WAIT(0x80285E24)
            EVT_EXEC(N(802401F4))
        EVT_CASE_EQ(1)
            EVT_EXEC(N(802401F4))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 35)
    EVT_CALL(SetSpriteShading, 524288)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80240974)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80240220))
    EVT_EXEC(N(802404D0))
    EVT_EXEC(N(802400A0))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_398)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(802403A0) = {
    EVT_IF_EQ(AreaFlag(1), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AreaFlag(1), 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 0, 200, 0, 30)
    EVT_CALL(GotoMap, EVT_PTR("arn_08"), 1)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(802403A0)))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4CC)[] = {
    0x00000000,
};

EvtScript N(802404D0) = {
    EVT_IF_EQ(AreaFlag(1), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AreaFlag(1), 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, 8)
    EVT_CALL(func_802D2484)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.5))
    EVT_CALL(PlayerJump, 50, 0, 0, 16)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_SET(AreaFlag(1), 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_5A8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(802405B0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(802405C0) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802405D0) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(802405B0),
    .onDefeat = &N(802405C0),
    .level = 13,
};

EvtScript N(idle_802405FC) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 0, 25, -10, 6)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x2086, 0)
    EVT_CALL(N(func_80240000_BF6060))
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 0, 200, 0, 15)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_SET(GB_StoryProgress, -18)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80240730) = {
    EVT_IF_NE(GB_StoryProgress, -19)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_802405FC)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80240784) = {
    .id = 0,
    .settings = &N(npcSettings_802405D0),
    .pos = { 0.0f, 25.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80240730),
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
};

NpcGroupList N(npcGroupList_80240974) = {
    NPC_GROUP(N(npcGroup_80240784)),
    {},
};

ApiStatus N(func_80240000_BF6060)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);
    return ApiStatus_DONE2;
}
