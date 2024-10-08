#include "kzn_23.h"
#include "entity.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(SetChestPosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIndex = evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIndex);

    entity->pos.x = x;
    entity->pos.y = y;
    entity->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetChestPosition)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    evt_set_variable(script, *args++, entity->pos.x);
    evt_set_variable(script, *args++, entity->pos.y);
    evt_set_variable(script, *args++, entity->pos.z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetPyroclastPos)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    EffectInstance* effect = script->varTablePtr[0xE];

    effect->data.unk_65->pos.x = x;
    effect->data.unk_65->pos.y = y;
    effect->data.unk_65->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AllowCameraInterpY)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    camera->moveFlags &= ~CAMERA_MOVE_IGNORE_PLAYER_Y;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AnimateChestSize)) {
    Entity* entity = get_entity_by_index(script->varTable[0xA]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = script->functionTemp[1] / 60.0f;
    entity->scale.y = script->functionTemp[1] / 60.0f;
    entity->scale.z = script->functionTemp[1] / 60.0f;

    entity->rot.y = (1.0f - cos_rad(entity->scale.y * PI)) * 990.0 / 2.0;

    script->functionTemp[1]--;
    if (~script->functionTemp[1] == 0) { //TODO remove ~ optimization
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Wait(30)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Panic, 5, MSG_CH5_0117)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Call(InterpNpcYaw, NPC_SELF, 90, 1)
    Wait(1)
    Call(SetNpcRotationPivot, NPC_SELF, 10)
    Call(SetNpcRotation, NPC_SELF, 0, 0, 180)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
    Return
    End
};

EvtScript N(EVS_CameraFollowMisstar) = {
    Label(0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
        Add(LVar1, 60)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfLt(LVar1, 2740)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

Vec3f N(PyroclastPathA)[] = {
    {  50.0, 2650.0, -20.0 },
    { 150.0, 2850.0, -45.0 },
    { 235.0, 2950.0, -60.0 },
    { 335.0, 3000.0, -75.0 },
};

Vec3f N(PyroclastPathB)[] = {
    {  -20.0, 2650.0, -20.0 },
    { -120.0, 2850.0, -40.0 },
    { -220.0, 3000.0, -40.0 },
};

Vec3f N(PyroclastPathC)[] = {
    { 10.0, 2650.00,  -20.0 },
    { 20.0, 2800.00,  -60.0 },
    { 30.0, 2880.00, -100.0 },
    { 40.0, 2920.00, -150.0 },
    { 50.0, 2940.00, -220.0 },
};

Vec3f N(PyroclastPathD)[] = {
    {  -35.0, 2650.0, -20.0 },
    {  -65.0, 2780.0, -30.0 },
    {  -95.0, 2850.0, -40.0 },
    { -125.0, 2880.0, -50.0 },
    { -155.0, 2900.0, -60.0 },
    { -185.0, 2915.0, -70.0 },
};

s32 N(SoundXPositions)[] = {
    130, -150, 130, -150,
};

EvtScript N(EVS_PlayPyroclastSounds) = {
    Add(LVar0, 1)
    UseBuf(N(SoundXPositions))
    Loop(LVar0)
        BufRead1(LVar1)
    EndLoop
    IfEq(AF_KZN23_UseAlternateSound, FALSE)
        Call(PlaySoundAt, SOUND_FLYING_PYROCLAST_1, SOUND_SPACE_DEFAULT, LVar1, 2800, 0)
        Set(AF_KZN23_UseAlternateSound, TRUE)
    Else
        Call(PlaySoundAt, SOUND_FLYING_PYROCLAST_2, SOUND_SPACE_DEFAULT, LVar1, 2800, 0)
        Set(AF_KZN23_UseAlternateSound, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_SpawnPyroclasts) = {
    Loop(0)
        Thread
            Call(RandInt, 3, LVar0)
            Exec(N(EVS_PlayPyroclastSounds))
            Switch(LVar0)
                CaseEq(0)
                    PlayEffect(EFFECT_65, 2, 50, 2650, -20, 1, 0)
                    Set(LVarE, LVarF)
                    Call(LoadPath, 15, Ref(N(PyroclastPathA)), ARRAY_COUNT(N(PyroclastPathA)), EASING_QUADRATIC_OUT)
                CaseEq(1)
                    PlayEffect(EFFECT_65, 2, -20, 2650, -20, 1, 0)
                    Set(LVarE, LVarF)
                    Call(LoadPath, 10, Ref(N(PyroclastPathB)), ARRAY_COUNT(N(PyroclastPathB)), EASING_QUADRATIC_OUT)
                CaseEq(2)
                    PlayEffect(EFFECT_65, 2, 10, 2650, -20, 1, 0)
                    Set(LVarE, LVarF)
                    Call(LoadPath, 15, Ref(N(PyroclastPathC)), ARRAY_COUNT(N(PyroclastPathC)), EASING_QUADRATIC_OUT)
                CaseEq(3)
                    PlayEffect(EFFECT_65, 2, -50, 2650, -20, 1, 0)
                    Set(LVarE, LVarF)
                    Call(LoadPath, 20, Ref(N(PyroclastPathD)), ARRAY_COUNT(N(PyroclastPathD)), EASING_QUADRATIC_OUT)
            EndSwitch
            Call(RandInt, 1, LVar4)
            IfEq(LVar4, 0)
                Set(LVar4, -1)
            EndIf
            Loop(0)
                Call(GetNextPathPos)
                Mul(LVar1, LVar4)
                Call(N(SetPyroclastPos), LVar1, LVar2, LVar3)
                Wait(1)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(DismissEffect, LVarE)
        EndThread
        Wait(8)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_Misstar) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(N(AllowCameraInterpY))
    Exec(N(EVS_CameraFollowMisstar))
    Call(SetSelfVar, 0, 0)
    Thread
        Wait(1)
        Call(SetPlayerAnimation, ANIM_MarioW2_Carried)
    EndThread
    // fly out of the volcano shaft
    Thread
        Call(MakeLerp, 0, 3090, 160, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Sub(LVar0, 100)
            Call(SetNpcPos, NPC_SELF, 0, LVar0, 0)
            Call(SetNpcPos, NPC_Kolorado, 10, LVar0, -5)
            Call(SetPlayerPos, -10, LVar0, 5)
            Add(LVar0, 20)
            Call(SetNpcPos, NPC_PARTNER, -10, LVar0, 0)
            IfGt(LVar0, 2840)
                Call(SetSelfVar, 0, 1)
            EndIf
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    // wait for escape
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(0)
        EndIf
    // make the pyroclasts + sounds
    Exec(N(EVS_SpawnPyroclasts))
    Wait(35)
    // make the chest thrown from the volcano
    Call(MakeEntity, Ref(Entity_Chest), 0, 2650, 0, 148, MAKE_ENTITY_END)
    Set(LVarA, LVar0)
    Thread
        Call(N(AnimateChestSize))
    EndThread
    Set(LVar9, LVarA)
    Call(N(GetChestPosition), LVar9, LVar2, LVar3, LVar4)
    Call(MakeLerp, LVar3, 3000, 10, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetChestPosition), LVar9, LVar2, LVar0, LVar4)
        Add(LVar2, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    // end scene
    Wait(45)
    Call(GotoMap, Ref("jan_04"), jan_04_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    Call(SetNpcPos, NPC_SELF, 0, -100, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_Misstar)))
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_RAYCAST_TO_INTERACT | ENEMY_FLAG_SKIP_BATTLE,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Misstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
