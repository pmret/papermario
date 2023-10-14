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
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Panic, 5, MSG_CH5_0117)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcRotationPivot, NPC_SELF, 10)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 180)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CameraFollowMisstar) = {
    EVT_LABEL(0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, 2740)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_ADD(LVar0, 1)
    EVT_USE_BUF(N(SoundXPositions))
    EVT_LOOP(LVar0)
        EVT_BUF_READ1(LVar1)
    EVT_END_LOOP
    EVT_IF_EQ(AF_KZN23_UseAlternateSound, FALSE)
        EVT_CALL(PlaySoundAt, SOUND_FLYING_PYROCLAST_1, SOUND_SPACE_DEFAULT, LVar1, 2800, 0)
        EVT_SET(AF_KZN23_UseAlternateSound, TRUE)
    EVT_ELSE
        EVT_CALL(PlaySoundAt, SOUND_FLYING_PYROCLAST_2, SOUND_SPACE_DEFAULT, LVar1, 2800, 0)
        EVT_SET(AF_KZN23_UseAlternateSound, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpawnPyroclasts) = {
    EVT_LOOP(0)
        EVT_THREAD
            EVT_CALL(RandInt, 3, LVar0)
            EVT_EXEC(N(EVS_PlayPyroclastSounds))
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_PLAY_EFFECT(EFFECT_65, 2, 50, 2650, -20, 1, 0)
                    EVT_SET(LVarE, LVarF)
                    EVT_CALL(LoadPath, 15, EVT_PTR(N(PyroclastPathA)), ARRAY_COUNT(N(PyroclastPathA)), EASING_QUADRATIC_OUT)
                EVT_CASE_EQ(1)
                    EVT_PLAY_EFFECT(EFFECT_65, 2, -20, 2650, -20, 1, 0)
                    EVT_SET(LVarE, LVarF)
                    EVT_CALL(LoadPath, 10, EVT_PTR(N(PyroclastPathB)), ARRAY_COUNT(N(PyroclastPathB)), EASING_QUADRATIC_OUT)
                EVT_CASE_EQ(2)
                    EVT_PLAY_EFFECT(EFFECT_65, 2, 10, 2650, -20, 1, 0)
                    EVT_SET(LVarE, LVarF)
                    EVT_CALL(LoadPath, 15, EVT_PTR(N(PyroclastPathC)), ARRAY_COUNT(N(PyroclastPathC)), EASING_QUADRATIC_OUT)
                EVT_CASE_EQ(3)
                    EVT_PLAY_EFFECT(EFFECT_65, 2, -50, 2650, -20, 1, 0)
                    EVT_SET(LVarE, LVarF)
                    EVT_CALL(LoadPath, 20, EVT_PTR(N(PyroclastPathD)), ARRAY_COUNT(N(PyroclastPathD)), EASING_QUADRATIC_OUT)
            EVT_END_SWITCH
            EVT_CALL(RandInt, 1, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_SET(LVar4, -1)
            EVT_END_IF
            EVT_LOOP(0)
                EVT_CALL(GetNextPathPos)
                EVT_MUL(LVar1, LVar4)
                EVT_CALL(N(SetPyroclastPos), LVar1, LVar2, LVar3)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(DismissEffect, LVarE)
        EVT_END_THREAD
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Misstar) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(N(AllowCameraInterpY))
    EVT_EXEC(N(EVS_CameraFollowMisstar))
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Carried)
    EVT_END_THREAD
    // fly out of the volcano shaft
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 3090, 160, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, LVar0, 0)
            EVT_CALL(SetNpcPos, NPC_Kolorado, 10, LVar0, -5)
            EVT_CALL(SetPlayerPos, -10, LVar0, 5)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetNpcPos, NPC_PARTNER, -10, LVar0, 0)
            EVT_IF_GT(LVar0, 2840)
                EVT_CALL(SetSelfVar, 0, 1)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    // wait for escape
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    // make the pyroclasts + sounds
    EVT_EXEC(N(EVS_SpawnPyroclasts))
    EVT_WAIT(35)
    // make the chest thrown from the volcano
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 0, 2650, 0, 148, MAKE_ENTITY_END)
    EVT_SET(LVarA, LVar0)
    EVT_THREAD
        EVT_CALL(N(AnimateChestSize))
    EVT_END_THREAD
    EVT_SET(LVar9, LVarA)
    EVT_CALL(N(GetChestPosition), LVar9, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar3, 3000, 10, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetChestPosition), LVar9, LVar2, LVar0, LVar4)
        EVT_ADD(LVar2, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    // end scene
    EVT_WAIT(45)
    EVT_CALL(GotoMap, EVT_PTR("jan_04"), jan_04_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -100, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_Misstar)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
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
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
