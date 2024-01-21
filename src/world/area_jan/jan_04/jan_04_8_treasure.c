#include "jan_04.h"
#include "entity.h"
#include "effects.h"

#include "world/common/todo/SetEntityPositionF.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

API_CALLABLE(N(AnimateFlyingChestRotScale)) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rot.y = (1.0f - cos_rad(entity->scale.y * PI)) * 990.0 * 0.25f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AnimateFallingChestRot)) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = -30;
    }
    entity->rot.x = script->functionTemp[0];
    entity->rot.z = script->functionTemp[0];
    script->functionTemp[0]++;

    if (script->functionTemp[0] == 1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

Vec3f N(ChestFlightArc)[] = {
    {  -40.0,   330.0, -900.0 },
    { -117.0,   420.0, -600.0 },
    { -195.0,   465.0, -300.0 },
    { -272.0,   465.0,    0.0 },
    { -350.0,   325.0,  300.0 },
    { -350.0,   250.0,  300.0 },
};

Vec3f N(ChestFallPath)[] = {
    {   10.0,   130.0,  -20.0 },
    {    5.0,    75.0,  -20.0 },
    {    0.0,     0.0,  -20.0 },
};

Vec3f N(ChestBouncePath)[] = {
    {    0.0,     0.0,  -20.0 },
    {    0.0,    30.0,   -8.0 },
    {    0.0,     0.0,    0.0 },
};

EvtScript N(EVS_Scene_TreasureChest) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_04_ENTRY_1)
        Call(PlaySound, SOUND_FALL_LONG)
        Call(UseSettingsFrom, CAM_DEFAULT, -350, 300, 0)
        Call(SetPanTarget, CAM_DEFAULT, -350, 300, 0)
        Call(SetCamPitch, CAM_DEFAULT, 10, Float(-7.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(MakeEntity, Ref(Entity_Chest), 0, 2650, 0, 148, MAKE_ENTITY_END)
        Set(LVarA, LVar0)
        Thread
            Call(N(AnimateFlyingChestRotScale))
        EndThread
        Thread
            Set(LVar9, LVarA)
            Call(LoadPath, 70, Ref(N(ChestFlightArc)), ARRAY_COUNT(N(ChestFlightArc)), EASING_QUADRATIC_OUT)
            Loop(0)
                Call(GetNextPathPos)
                Call(N(SetEntityPositionF), LVar9, LVar1, LVar2, LVar3)
                Wait(1)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        Wait(50)
        Call(GotoMap, Ref("jan_04"), jan_04_ENTRY_2)
        Wait(100)
    Else
        Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, 0, 170, 0)
        Call(SetCamDistance, CAM_DEFAULT, 350)
        Call(SetCamPitch, CAM_DEFAULT, 16, Float(-6.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(20)
        Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.2))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(MakeEntity, Ref(Entity_Chest), 0, 2650, 0, 0, MAKE_ENTITY_END)
        Set(LVarA, LVar0)
        Thread
            Call(N(AnimateFallingChestRot))
        EndThread
        Set(LVar9, LVarA)
        Call(LoadPath, 12, Ref(N(ChestFallPath)), ARRAY_COUNT(N(ChestFallPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(N(SetEntityPositionF), LVar9, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAt, SOUND_JAN_CHEST_IMPACT, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
        Thread
            PlayEffect(EFFECT_WALKING_DUST, 2, -15, 0, 0, 10, 10)
            PlayEffect(EFFECT_WALKING_DUST, 2, 0, 0, 0, 0, 0)
            PlayEffect(EFFECT_WALKING_DUST, 2, 15, 0, 0, 350, 350)
            Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.0))
        EndThread
        Call(LoadPath, 10, Ref(N(ChestBouncePath)), ARRAY_COUNT(N(ChestBouncePath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(N(SetEntityPositionF), LVar9, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAt, SOUND_JAN_CHEST_IMPACT, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
        PlayEffect(EFFECT_WALKING_DUST, 2, -10, 0, 15, 0, 0)
        PlayEffect(EFFECT_WALKING_DUST, 2, -10, 0, 15, 0, 0)
        Wait(60)
        Exec(N(EVS_GotoMap_kmr_24_0))
    EndIf
    Return
    End
};
