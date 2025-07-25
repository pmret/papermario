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
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetMusic, 0, SONG_PEACH_CAUGHT, 0, VOL_LEVEL_FULL)
    Call(SetPlayerPos, -480, 30, -30)
    Call(SetPlayerAnimation, ANIM_Peach2_Carried)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, -480, 30, -30)
    Call(SetNpcPos, NPC_Koopatrol_Guard_01, -492, 0, -30)
    Call(SetNpcPos, NPC_Koopatrol_Guard_02, -460, 0, -30)
    Call(SetNpcYaw, NPC_Koopatrol_Guard_01, 90)
    Call(SetNpcYaw, NPC_Koopatrol_Guard_02, 90)
    Call(UseSettingsFrom, CAM_DEFAULT, -300, 0, -30)
    Call(SetPanTarget, CAM_DEFAULT, -300, 0, -30)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o112, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Wait(10 * DT)
        Call(LoadPath, 50 * DT, Ref(N(TwinkFollowPath)), ARRAY_COUNT(N(TwinkFollowPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    Call(SetNpcVar, NPC_Koopatrol_Guard_01, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_Guard_01, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_Guard_01, -316, -32, 0)
        Call(SetNpcVar, NPC_Koopatrol_Guard_01, 0, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Koopatrol_Guard_02, Float(5.0))
        Call(NpcMoveTo, NPC_Koopatrol_Guard_02, -284, -28, 0)
    EndThread
    Loop(0)
        Call(GetNpcPos, NPC_Koopatrol_Guard_01, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Add(LVar2, 2)
        Call(SetPlayerPos, LVar0, 30, LVar2)
        Wait(1)
        Call(GetNpcVar, NPC_Koopatrol_Guard_01, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim12)
    Call(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim12)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_Thrown)
    Call(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim15)
    Call(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim15)
    Call(LoadPath, 15 * DT, Ref(N(PeachTossPath)), ARRAY_COUNT(N(PeachTossPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_Peach2_Land)
    Thread
        Add(LVar1, 10)
        PlayEffect(EFFECT_LANDING_DUST, 1, LVar1, LVar2, LVar3, 0)
        Wait(47)
        Add(LVar1, -5)
        Add(LVar2, 10)
        Add(LVar3, 5)
        Loop(4)
            PlayEffect(EFFECT_WALKING_DUST, 1, LVar1, LVar2, LVar3, 0, 0)
            Wait(10 * DT)
        EndLoop
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim01)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Koopatrol_Guard_01, ANIM_WorldKoopatrol_Anim06)
        Call(NpcMoveTo, NPC_Koopatrol_Guard_01, -462, -30, 0)
        Call(SetNpcPos, NPC_Koopatrol_Guard_01, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim01)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Koopatrol_Guard_02, ANIM_WorldKoopatrol_Anim06)
        Call(NpcMoveTo, NPC_Koopatrol_Guard_02, -430, -30, 0)
        Call(SetNpcPos, NPC_Koopatrol_Guard_02, NPC_DISPOSE_LOCATION)
        Call(MakeLerp, 120, 0, 8, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o112, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttw, COLLIDER_FLAGS_UPPER_MASK)
        Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, 0)
    EndThread
    Wait(60 * DT)
    Call(LoadPath, 50 * DT, Ref(N(TwinkApproachPath)), ARRAY_COUNT(N(TwinkApproachPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0159)
        Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_015A)
        IfLt(GB_KKJ_CaughtCount, 3)
            IfEq(AF_KKJ_13, false)
                Set(LVar0, MSG_Peach_015B)
            Else
                Set(LVar0, MSG_Peach_015D)
            EndIf
        Else
            Set(LVar0, MSG_Peach_015C)
        EndIf
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, LVar0)
    Else
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0176)
        Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0177)
        IfLt(GB_KKJ_CaughtCount, 3)
            IfEq(AF_KKJ_13, false)
                Set(LVar0, MSG_Peach_0178)
            Else
                Set(LVar0, MSG_Peach_017A)
            EndIf
        Else
            Set(LVar0, MSG_Peach_0179)
        EndIf
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, LVar0)
    EndIf
    Exec(N(EVS_SetupMusic))
    Call(ResetCam, CAM_DEFAULT, Float(1.0 / DT))
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_Guard_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
};

NpcGroupList N(TossBackNPCs) = {
    NPC_GROUP(N(NpcData_Guards)),
    {}
};
