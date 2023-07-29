#include "common.h"
#include "effects.h"

ApiStatus N(UnkEffect0FFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 var0 = evt_get_float_variable(script, *args++);
    f32 var1 = evt_get_float_variable(script, *args++);
    f32 var2 = evt_get_float_variable(script, *args++);
    f32 var3 = evt_get_float_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);
    f32 var5 = evt_get_float_variable(script, *args++);
    f32 var6 = evt_get_float_variable(script, *args++);
    f32 var7 = evt_get_float_variable(script, *args++);

    fx_star(var0, var1, var2, var3, var4, var5, var6, var7);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkEffect0FFunc)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 temp_f30;
    f32 var1;
    f32 var2;
    f32 rand1 = rand_int(500) - 250;
    f32 rand2 = rand_int(500) - 250;
    f32 rand3 = rand_int(100) + 600;
    f32 var3;
    f32 var4;
    f32 var5;
    f32 var6;

    temp_f30 = playerStatus->pos.x + (rand3 * sin_rad(yaw));
    var1 = temp_f30 + (rand1 * sin_rad(yawPlus));
    var2 = playerStatus->pos.y + 200.0f;
    var3 = playerStatus->pos.z - (rand3 * cos_rad(yaw));
    var3 = var3 - (rand1 * cos_rad(yawPlus));
    var4 = playerStatus->pos.x + (rand3 * sin_rad(yaw));
    var4 = var4 + (rand2 * sin_rad(yawMinus));
    var5 = playerStatus->pos.y;
    var6 = playerStatus->pos.z - (rand3 * cos_rad(yaw));
    var6 = var6 - (rand2 * cos_rad(yawMinus));
    fx_star(0, var1, var2, var3, var4, var5, var6, rand_int(10) + 10);
    return ApiStatus_DONE2;
}


ApiStatus N(UnkEffect0FFunc3)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 temp_f30;
    f32 var1;
    f32 var2;
    f32 rand1 = rand_int(300) - 150;
    f32 rand2 = rand_int(300) - 150;
    f32 rand3 = rand_int(100) + 50;
    f32 var3;
    f32 var4;
    f32 var5;
    f32 var6;

    if ((playerStatus->pos.y >= 250.0f)) {
        return ApiStatus_DONE2;
    }

    temp_f30 = playerStatus->pos.x - (rand3 * sin_rad(yaw));
    var1 = temp_f30 + (rand1 * sin_rad(yawPlus));
    var2 = playerStatus->pos.y + 200.0f;
    var3 = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    var3 = var3 - (rand1 * cos_rad(yawPlus));
    var4 = playerStatus->pos.x - (rand3 * sin_rad(yaw));
    var4 = var4 + (rand2 * sin_rad(yawMinus));
    var5 = playerStatus->pos.y;
    var6 = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    var6 = var6 - (rand2 * cos_rad(yawMinus));
    fx_star(1, var1, var2, var3, var4, var5, var6, rand_int(10) + 10);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkEffect0FFunc4)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 temp_f30;
    f32 var1;
    f32 var2;
    f32 rand1 = rand_int(150);
    f32 rand2 = rand_int(150);
    f32 rand3 = rand_int(100) - 50;
    f32 var3;
    f32 var4;
    f32 var5;
    f32 var6;

    if ((playerStatus->pos.z < 200.0f)) {
        return ApiStatus_DONE2;
    }

    temp_f30 = playerStatus->pos.x - (rand3 * sin_rad(yaw));
    var1 = temp_f30 + (rand1 * sin_rad(yawPlus));
    var2 = playerStatus->pos.y + 200.0f;
    var3 = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    var3 = var3 - (rand1 * cos_rad(yawPlus));
    script->varTable[1] = var1;
    script->varTable[2] = var2;
    script->varTable[3] = var3;
    var4 = playerStatus->pos.x - (rand3 * sin_rad(yaw));
    var4 = var4 + (rand2 * sin_rad(yawMinus));
    var5 = playerStatus->pos.y;
    var6 = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    var6 = var6 - (rand2 * cos_rad(yawMinus));
    fx_star(2, var1, var2, var3, var4, var5, var6, rand_int(4) + 10);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Starfall_Directed) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarE, 0)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_LT(LVar1, -50)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_SET(LVar8, 1000)
        EVT_SUB(LVar8, LVar1)
        EVT_DIV(LVar8, 10)
        EVT_IF_LT(LVar8, 20)
            EVT_SET(LVar8, 20)
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_CALL(RandInt, 400, LVarA)
        EVT_SET(LVarB, 200)
        EVT_CALL(RandInt, 400, LVarC)
        EVT_SUB(LVarC, 200)
        EVT_ADD(LVar1, LVarA)
        EVT_ADD(LVar2, LVarB)
        EVT_ADD(LVar3, LVarC)
        EVT_SET(LVar4, LVar1)
        EVT_CALL(RandInt, 100, LVarA)
        EVT_ADD(LVarA, 50)
        EVT_SUB(LVar4, LVarA)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, LVar3)
        EVT_CALL(RandInt, 4, LVar7)
        EVT_ADD(LVar7, 10)
        EVT_SWITCH(LVar3)
            EVT_CASE_LT(-290)
                EVT_SET(LVar0, 0)
            EVT_CASE_LT(40)
                EVT_SET(LVar0, 2)
            EVT_CASE_GE(40)
                EVT_SET(LVar0, 1)
        EVT_END_SWITCH
        EVT_IF_LT(LVarE, 2)
            EVT_CALL(PlaySoundAt, SOUND_B0000015, 0, LVar1, LVar2, LVar3)
            EVT_ADD(LVarE, 1)
        EVT_END_IF
        EVT_ADD(LVarD, LVar8)
        EVT_IF_GT(LVarD, 30)
            EVT_SET(LVarD, 0)
            EVT_SET(LVarE, 0)
        EVT_END_IF
        EVT_CALL(N(UnkEffect0FFunc2), LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, LVar6, LVar7)
        EVT_WAIT(LVar8)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Starfall_Random) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_THREAD
        EVT_LABEL(0)
            EVT_CALL(RandInt, 50, LVar0)
            EVT_ADD(LVar0, 10)
            EVT_CALL(N(UnkEffect0FFunc))
            EVT_WAIT(LVar0)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(1)
            EVT_CALL(RandInt, 50, LVar0)
            EVT_ADD(LVar0, 20)
            EVT_CALL(N(UnkEffect0FFunc3))
            EVT_WAIT(LVar0)
            EVT_GOTO(1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(2)
            EVT_CALL(RandInt, 50, LVar0)
            EVT_ADD(LVar0, 20)
            EVT_CALL(N(UnkEffect0FFunc4))
            EVT_CALL(PlaySoundAt, SOUND_B0000015, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(LVar0)
            EVT_GOTO(2)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
