#include "arn_09.h"
#include "sprite/npc/tubbas_heart.h"

extern s32 D_000001E4;

EvtSource N(80240140) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 5)
    EVT_SET(EVT_VAR(2), 0)
    EVT_SET(EVT_VAR(4), 1)
    EVT_SET(EVT_VAR(3), 1)
    EVT_EXEC(0x80285DFC)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_10"), 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(802401F4) = {
    EVT_BIND_TRIGGER(N(80240140), TRIGGER_WALL_PRESS_A, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80240220) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_SET(EVT_VAR(2), 0)
            EVT_SET(EVT_VAR(4), 1)
            EVT_SET(EVT_VAR(3), 1)
            EVT_EXEC_WAIT(0x80285E24)
            EVT_EXEC(N(802401F4))
        EVT_CASE_EQ(1)
            EVT_EXEC(N(802401F4))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 35)
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

EvtSource N(802403A0) = {
    EVT_IF_EQ(EVT_AREA_FLAG(1), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_AREA_FLAG(1), 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetPlayerJumpscale, EVT_FIXED(1.0))
    EVT_CALL(PlayerJump, 0, 200, 0, 30)
    EVT_CALL(GotoMap, EVT_PTR("arn_08"), 1)
    EVT_WAIT_FRAMES(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EAA30, 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(802403A0)))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4CC)[] = {
    0x00000000,
};

EvtSource N(802404D0) = {
    EVT_IF_EQ(EVT_AREA_FLAG(1), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_AREA_FLAG(1), 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, 8)
    EVT_CALL(func_802D2484)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_CALL(SetPlayerJumpscale, EVT_FIXED(1.5))
    EVT_CALL(PlayerJump, 50, 0, 0, 16)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_SET(EVT_AREA_FLAG(1), 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_5A8)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(802405B0) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(802405C0) = {
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

EvtSource N(idle_802405FC) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 0, 25, -10, 6)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x2086, 0)
    EVT_CALL(N(func_80240000_BF6060))
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_tubbas_heart_Palette_00_Anim_13)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(2.5))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x20C8, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 0, 200, 0, 15)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_SET(EVT_SAVE_VAR(0), -18)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80240730) = {
    EVT_IF_NE(EVT_SAVE_VAR(0), -19)
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80240730),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
    NPC_GROUP(N(npcGroup_80240784), BATTLE_ID(0, 0, 0, 0)),
    {},
};

ApiStatus N(func_80240000_BF6060)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(0);

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, &D_000001E4);
    return ApiStatus_DONE2;
}
