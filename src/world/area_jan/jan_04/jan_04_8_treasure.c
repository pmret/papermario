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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_04_ENTRY_1)
        EVT_CALL(PlaySound, SOUND_FALL_LONG)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -350, 300, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -350, 300, 0)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 10, EVT_FLOAT(-7.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 0, 2650, 0, 148, MAKE_ENTITY_END)
        EVT_SET(LVarA, LVar0)
        EVT_THREAD
            EVT_CALL(N(AnimateFlyingChestRotScale))
        EVT_END_THREAD
        EVT_THREAD
            EVT_SET(LVar9, LVarA)
            EVT_CALL(LoadPath, 70, EVT_PTR(N(ChestFlightArc)), ARRAY_COUNT(N(ChestFlightArc)), EASING_QUADRATIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(GetNextPathPos)
                EVT_CALL(N(SetEntityPositionF), LVar9, LVar1, LVar2, LVar3)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_WAIT(50)
        EVT_CALL(GotoMap, EVT_PTR("jan_04"), jan_04_ENTRY_2)
        EVT_WAIT(100)
    EVT_ELSE
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 170, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 16, EVT_FLOAT(-6.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.2))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 0, 2650, 0, 0, MAKE_ENTITY_END)
        EVT_SET(LVarA, LVar0)
        EVT_THREAD
            EVT_CALL(N(AnimateFallingChestRot))
        EVT_END_THREAD
        EVT_SET(LVar9, LVarA)
        EVT_CALL(LoadPath, 12, EVT_PTR(N(ChestFallPath)), ARRAY_COUNT(N(ChestFallPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(N(SetEntityPositionF), LVar9, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAt, SOUND_JAN_CHEST_IMPACT, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
        EVT_THREAD
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -15, 0, 0, 10, 10)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, 0, 0, 0, 0, 0)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, 15, 0, 0, 350, 350)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(LoadPath, 10, EVT_PTR(N(ChestBouncePath)), ARRAY_COUNT(N(ChestBouncePath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(N(SetEntityPositionF), LVar9, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAt, SOUND_JAN_CHEST_IMPACT, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -10, 0, 15, 0, 0)
        EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, -10, 0, 15, 0, 0)
        EVT_WAIT(60)
        EVT_EXEC(N(EVS_GotoMap_kmr_24_0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
