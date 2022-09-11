#include "arn_08.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/yakkey.h"
#include "world/partners.h"
#include "entity.h"

enum {
    NPC_TUBBAS_HEART,
    NPC_YAKKEY,
};

EvtScript N(802403B0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ClearDefeatedEnemies)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 6)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar4, 1)
    EVT_SET(LVar3, -1)
    EVT_EXEC(0x80285DFC)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_07"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240470) = {
    EVT_BIND_TRIGGER(N(802403B0), TRIGGER_WALL_PRESS_A, 6, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024049C) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(80240470))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar4, 1)
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, -1)
            EVT_EXEC_WAIT(0x80285E24)
            EVT_SET(AreaFlag(1), 0)
            EVT_EXEC(N(80240470))
        EVT_CASE_EQ(1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_IF_EQ(GB_StoryProgress, -18)
                EVT_CALL(SetPlayerPos, 1000, 1000, 0)
                EVT_CALL(SetNpcPos, NPC_PARTNER, 1000, 1000, 0)
                EVT_CALL(RotateModel, 0, 80, 0, -1, 0)
                EVT_CALL(RotateModel, 1, 80, 0, -1, 0)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_6)
                EVT_CALL(SetNpcJumpscale, 0, EVT_FLOAT(2.5))
                EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
                EVT_CALL(NpcJump0, 0, -50, 0, 50, 10)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_7)
                EVT_WAIT(1)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_6)
                EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
                EVT_CALL(NpcJump0, 0, -110, 0, 110, 10)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_7)
                EVT_WAIT(1)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_6)
                EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
                EVT_CALL(NpcJump0, 0, -180, 0, 180, 10)
                EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_7)
                EVT_WAIT(1)
                EVT_CALL(MakeLerp, 80, 0, 10, 0)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, 0, LVar0, 0, -1, 0)
                    EVT_CALL(RotateModel, 1, LVar0, 0, -1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtCollider, 6, 450, 0)
                EVT_WAIT(20)
                EVT_CALL(SetPlayerPos, 0, 0, 0)
                EVT_CALL(SetNpcPos, NPC_PARTNER, 0, 0, 0)
                EVT_SET(GB_StoryProgress, -17)
            EVT_END_IF
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
            EVT_CALL(PlayerJump, -10, 0, 75, 18)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_EXEC(N(80240470))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 35)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(GF_MAP_WindyMill, 1)
    EVT_IF_GE(GB_StoryProgress, -12)
        EVT_SET(GF_ARN10_Defeated_Goomba, 0)
        EVT_SET(GF_ARN12_Defeated_Goomba, 0)
        EVT_SET(GF_ARN13_Defeated_Goomba, 0)
    EVT_END_IF
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80241828)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(80240BA0))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_EXEC_WAIT(N(8024118C))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(8024049C))
    EVT_EXEC(N(80240B50))
    EVT_EXEC(N(80240300))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_A6C) = {
    0x00000000,
};

EvtScript N(80240A70) = {
    EVT_LOOP(0)
        EVT_IF_NE(GB_StoryProgress, -18)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(func_8024008C_BF482C))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(func_80240000_BF47A0))
    EVT_SET(AreaFlag(1), 1)
    EVT_IF_LT(GB_StoryProgress, -23)
        EVT_SET(GB_StoryProgress, -23)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("arn_09"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240B50) = {
    EVT_CALL(SetCamProperties, 0, EVT_FLOAT(90.0), 0, 0, 0, EVT_FLOAT(470.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_EXEC(N(80240A70))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_B98)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(80240BA0) = {
    EVT_CALL(PlaySound, 0x8000004B)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(10)
        EVT_CALL(RotateModel, 9, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 15, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 11, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, 13, LVar0, 0, 0, -1)
        EVT_CALL(RotateModel, 17, LVar0, 0, 0, -1)
        EVT_ADD(LVar0, 1)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

static s32 N(pad_CB4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80240CC0) = {
    EVT_CALL(N(func_802400C0_BF4860))
    EVT_CALL(DemoJoystickXY, 2, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 12, 4)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 28, 11)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 47, 22)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 68, 38)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, 48)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, 59)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 64, 62)
    EVT_WAIT(4)
    EVT_CALL(DemoSetButtons, 32768)
    EVT_WAIT(10)
    EVT_CALL(DemoJoystickXY, 64, 58)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 70, 34)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 77, -2)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 74, -23)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 71, -36)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 69, -44)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 67, -49)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 30, -30)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, -1)
    EVT_WAIT(8)
    EVT_CALL(DemoSetButtons, 32768)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 0, -2)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 0, -1)
    EVT_WAIT(2)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 1, 0)
    EVT_WAIT(1)
    EVT_CALL(DemoJoystickXY, 0, 0)
    EVT_CALL(N(func_802400D4_BF4874))
    EVT_CALL(DemoSetButtons, 32768)
    EVT_WAIT(12)
    EVT_CALL(DemoSetButtons, 0)
    EVT_WAIT(20)
    EVT_IF_EQ(GF_DemoSceneDone, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, 1)
    EVT_CALL(GotoMapSpecial, EVT_PTR("arn_08"), 2, 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(802410AC) = {
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_CALL(GetDemoState, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_EQ(GF_DemoSceneDone, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_DemoSceneDone, 1)
    EVT_CALL(GotoMapSpecial, EVT_PTR("arn_08"), 2, 3)
    EVT_WAIT(35)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024116C) = {
    EVT_CALL(N(func_802400F4_BF4894))
    EVT_RETURN
    EVT_END
};

s32 N(D_80241188_BF5928) = {
    0x00000000,
};

EvtScript N(8024118C) = {
    EVT_CALL(SetCamProperties, 0, EVT_FLOAT(90.0), 0, 0, 0, EVT_FLOAT(470.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(N(func_8024019C_BF493C))
    EVT_SET(GF_DemoSceneDone, 0)
    EVT_EXEC(N(802410AC))
    EVT_EXEC(N(80240CC0))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_11FC) = {
    0x00000000,
};

EvtScript N(80241200) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80241210) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80241220) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80241200),
    .onDefeat = &N(80241210),
    .level = 13,
};

NpcSettings N(npcSettings_8024124C) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

EvtScript N(idle_80241278) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241288) = {
    EVT_IF_NE(GB_StoryProgress, -18)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_ELSE
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80241278)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802412E8) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(8)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MSG_CH3_00BA)
        EVT_CASE_LT(42)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MSG_CH3_00BB)
        EVT_CASE_LT(61)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MSG_CH3_00BC)
        EVT_CASE_LT(90)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MSG_CH3_00BD)
        EVT_CASE_GE(90)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_yakkey_Palette_00_Anim_2, NPC_ANIM_yakkey_Palette_00_Anim_1, 0, MSG_CH3_00BE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802413E8) = {
    EVT_IF_LT(GB_StoryProgress, -12)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_ELSE
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802412E8)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80241448) = {
    .id = NPC_TUBBAS_HEART,
    .settings = &N(npcSettings_80241220),
    .pos = { -23.0f, 75.0f, 31.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80241288),
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

StaticNpc N(npcGroup_80241638) = {
    .id = NPC_YAKKEY,
    .settings = &N(npcSettings_8024124C),
    .pos = { 38.0f, 0.0f, 97.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING,
    .init = &N(init_802413E8),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
        NPC_ANIM_yakkey_Palette_00_Anim_1,
    },
    .tattle = MSG_NpcTattle_Yakkey,
};

NpcGroupList N(npcGroupList_80241828) = {
    NPC_GROUP(N(npcGroup_80241448)),
    NPC_GROUP(N(npcGroup_80241638)),
    {},
};

static s32 N(pad_184C) = {
    0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_IF_LT(GB_StoryProgress, -23)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 0, 30, 0, 0, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

ApiStatus N(func_802400C0_BF4860)(Evt* script, s32 isInitialCall) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802400D4_BF4874)(Evt* script, s32 isInitialCall) {
    func_800EF300();
    return ApiStatus_DONE2;
}

ApiStatus N(func_802400F4_BF4894)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (!(playerStatus->position.y > -10.0f)) {
        f32 temp_f20 = func_800E34D8();
        s32 colliderID;

        playerStatus->position.y = player_check_collision_below(temp_f20, &colliderID);
        script->functionTemp[0] += fabsf(temp_f20);

        return (script->functionTemp[0] > 50) * ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_8024019C_BF493C)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32* dataPtr = &N(D_80241188_BF5928);

    switch (*dataPtr) {
        case 0:
            *dataPtr = 1;
            break;
        case 1:
        case 2:
            (*dataPtr)++;
            break;
        case 3: {
            partner_clear_player_tracking(wPartnerNpc);
            partner_set_goal_pos(playerStatus->position.x, playerStatus->position.z);
            func_800EF3D4(0);
            set_npc_yaw(wPartnerNpc, 90.0f);
            playerStatus->targetYaw = 90.0f;
            playerStatus->currentYaw = 90.0f;
            playerStatus->spriteFacingAngle = 0.0f;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}
