#include "kkj_14.h"
#include "effects.h"
#include "sprite/player.h"

Vec3f N(PeachTossPath)[] = {
    { -307.0,    30.0,  -30.0 },
    { -290.0,    35.0,  -30.0 },
    { -250.0,     0.0,  -30.0 },
};

Vec3f N(TwinkFollowPath)[] = {
    { -480.0,    30.0,  -30.0 },
    { -360.0,    60.0,  -30.0 },
    { -340.0,   120.0,  -70.0 },
    { -380.0,    40.0, -100.0 },
};

Vec3f N(TwinkApproachPath)[] = {
    { -380.0,    40.0, -100.0 },
    { -360.0,    45.0,  -82.0 },
    { -340.0,    40.0,  -65.0 },
    { -320.0,    32.0,  -52.0 },
    { -290.0,    25.0,  -30.0 },
};

EvtScript N(EVS_Scene_TossedBackInRoom) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_CAUGHT, 0, 8)
    EVT_CALL(SetPlayerPos, -480, 30, -30)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Carried)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -480, 30, -30)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_Guard_01, -492, 0, -30)
    EVT_CALL(SetNpcPos, NPC_Koopatrol_Guard_02, -460, 0, -30)
    EVT_CALL(SetNpcYaw, NPC_Koopatrol_Guard_01, 90)
    EVT_CALL(SetNpcYaw, NPC_Koopatrol_Guard_02, 90)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -300, 0, -30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -300, 0, -30)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o112, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(LoadPath, 50 * DT, EVT_PTR(N(TwinkFollowPath)), ARRAY_COUNT(N(TwinkFollowPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcVar, NPC_Koopatrol_Guard_01, 0, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_Guard_01, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_Guard_01, -316, -32, 0)
        EVT_CALL(SetNpcVar, NPC_Koopatrol_Guard_01, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim14)
        EVT_CALL(SetNpcSpeed, NPC_Koopatrol_Guard_02, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_Guard_02, -284, -28, 0)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Koopatrol_Guard_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetPlayerPos, LVar0, 30, LVar2)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_Koopatrol_Guard_01, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim12)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim12)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Thrown)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim15)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim15)
    EVT_CALL(LoadPath, 15 * DT, EVT_PTR(N(PeachTossPath)), ARRAY_COUNT(N(PeachTossPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Land)
    EVT_THREAD
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar1, LVar2, LVar3, 0)
        EVT_WAIT(47)
        EVT_ADD(LVar1, -5)
        EVT_ADD(LVar2, 10)
        EVT_ADD(LVar3, 5)
        EVT_LOOP(4)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 1, LVar1, LVar2, LVar3, 0, 0)
            EVT_WAIT(10 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_Guard_01, -462, -30, 0)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_Guard_01, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol_Guard_02, -430, -30, 0)
        EVT_CALL(SetNpcPos, NPC_Koopatrol_Guard_02, NPC_DISPOSE_LOCATION)
        EVT_CALL(MakeLerp, 120, 0, 8, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o112, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_CALL(LoadPath, 50 * DT, EVT_PTR(N(TwinkApproachPath)), ARRAY_COUNT(N(TwinkApproachPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach1_Idle)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0159)
        EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_015A)
        EVT_IF_LT(GB_KKJ_CaughtCount, 3)
            EVT_IF_EQ(AF_KKJ_13, FALSE)
                EVT_SET(LVar0, MSG_Peach_015B)
            EVT_ELSE
                EVT_SET(LVar0, MSG_Peach_015D)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar0, MSG_Peach_015C)
        EVT_END_IF
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, LVar0)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0176)
        EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0177)
        EVT_IF_LT(GB_KKJ_CaughtCount, 3)
            EVT_IF_EQ(AF_KKJ_13, FALSE)
                EVT_SET(LVar0, MSG_Peach_0178)
            EVT_ELSE
                EVT_SET(LVar0, MSG_Peach_017A)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar0, MSG_Peach_0179)
        EVT_END_IF
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, LVar0)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/Koopatrol_Stationary.inc.c"

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_WorldKoopatrol_Anim15,
    ANIM_LIST_END
};

NpcData N(NpcData_Guards)[] = {
    {
        .id = NPC_Koopatrol_Guard_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_Guard_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
};

NpcGroupList N(TossBackNPCs) = {
    NPC_GROUP(N(NpcData_Guards)),
    {}
};
