#include "common.h"
#include "effects.h"

ApiStatus N(UnkEffect0FFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 type = evt_get_float_variable(script, *args++); // @bug? s32 accessed as a float
    f32 startX = evt_get_float_variable(script, *args++);
    f32 startY = evt_get_float_variable(script, *args++);
    f32 startZ = evt_get_float_variable(script, *args++);
    f32 endX = evt_get_float_variable(script, *args++);
    f32 endY = evt_get_float_variable(script, *args++);
    f32 endZ = evt_get_float_variable(script, *args++);
    f32 speed = evt_get_float_variable(script, *args++);

    fx_star(type, startX, startY, startZ, endX, endY, endZ, speed);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkEffect0FFunc1)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 temp_f30;
    f32 startX;
    f32 startY;
    f32 rand1 = rand_int(500) - 250;
    f32 rand2 = rand_int(500) - 250;
    f32 rand3 = rand_int(100) + 600;
    f32 startZ;
    f32 endX;
    f32 endY;
    f32 endZ;

    temp_f30 = playerStatus->pos.x + (rand3 * sin_rad(yaw));
    startX = temp_f30 + (rand1 * sin_rad(yawPlus));
    startY = playerStatus->pos.y + 200.0f;
    startZ = playerStatus->pos.z - (rand3 * cos_rad(yaw));
    startZ -= (rand1 * cos_rad(yawPlus));
    endX = playerStatus->pos.x + (rand3 * sin_rad(yaw));
    endX += (rand2 * sin_rad(yawMinus));
    endY = playerStatus->pos.y;
    endZ = playerStatus->pos.z - (rand3 * cos_rad(yaw));
    endZ -= (rand2 * cos_rad(yawMinus));
    fx_star(FX_STAR_0, startX, startY, startZ, endX, endY, endZ, rand_int(10) + 10);
    return ApiStatus_DONE2;
}


ApiStatus N(UnkEffect0FFunc3)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 temp_f30;
    f32 startX;
    f32 startY;
    f32 rand1 = rand_int(300) - 150;
    f32 rand2 = rand_int(300) - 150;
    f32 rand3 = rand_int(100) + 50;
    f32 startZ;
    f32 var4;
    f32 var5;
    f32 var6;

    if ((playerStatus->pos.y >= 250.0f)) {
        return ApiStatus_DONE2;
    }

    temp_f30 = playerStatus->pos.x - (rand3 * sin_rad(yaw));
    startX = temp_f30 + (rand1 * sin_rad(yawPlus));
    startY = playerStatus->pos.y + 200.0f;
    startZ = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    startZ = startZ - (rand1 * cos_rad(yawPlus));
    var4 = playerStatus->pos.x - (rand3 * sin_rad(yaw));
    var4 = var4 + (rand2 * sin_rad(yawMinus));
    var5 = playerStatus->pos.y;
    var6 = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    var6 = var6 - (rand2 * cos_rad(yawMinus));
    fx_star(FX_STAR_1, startX, startY, startZ, var4, var5, var6, rand_int(10) + 10);
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
    var4 += rand2 * sin_rad(yawMinus);
    var5 = playerStatus->pos.y;
    var6 = playerStatus->pos.z + (rand3 * cos_rad(yaw));
    var6 -= rand2 * cos_rad(yawMinus);
    fx_star(FX_STAR_2, var1, var2, var3, var4, var5, var6, rand_int(4) + 10);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Starfall_Directed) = {
    #define LV_Type LVar0
    #define LV_PosX LVar1
    #define LV_PosY LVar2
    #define LV_PosZ LVar3
    #define LV_EndX LVar4
    #define LV_EndY LVar5
    #define LV_EndZ LVar6
    #define LV_Speed LVar7
    #define LV_Delay LVar8
    #define LV_Dx LVarA
    #define LV_Dy LVarB
    #define LV_Dz LVarC
    #define LV_Time LVarD
    #define LV_SoundDelay LVarE
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LV_Time, 0)
    EVT_SET(LV_SoundDelay, 0)
    EVT_LABEL(0)
        // no shooting stars if player x < -50
        EVT_CALL(GetPlayerPos, LV_PosX, LV_PosY, LV_PosZ)
        EVT_IF_LT(LV_PosX, -50)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        // choose delay from ~100 to 20 as a function of player x position
        EVT_SET(LV_Delay, 1000)
        EVT_SUB(LV_Delay, LV_PosX)
        EVT_DIV(LV_Delay, 10)
        EVT_IF_LT(LV_Delay, 20)
            EVT_SET(LV_Delay, 20)
        EVT_END_IF
        // choose a random spawn position within 400 units of the player in x and z
        EVT_CALL(GetPlayerPos, LV_PosX, LV_PosY, LV_PosZ)
        EVT_CALL(RandInt, 400, LV_Dx)
        EVT_SET(LV_Dy, 200)
        EVT_CALL(RandInt, 400, LV_Dz)
        EVT_SUB(LV_Dz, 200)
        EVT_ADD(LV_PosX, LV_Dx)
        EVT_ADD(LV_PosY, LV_Dy)
        EVT_ADD(LV_PosZ, LV_Dz)
        // choose a final position relative to the spawn position, with y = 0 and a random x offset
        EVT_SET(LV_EndX, LV_PosX)
        EVT_CALL(RandInt, 100, LV_Dx)
        EVT_ADD(LV_Dx, 50)
        EVT_SUB(LV_EndX, LV_Dx)
        EVT_SET(LV_EndY, 0)
        EVT_SET(LV_EndZ, LV_PosZ)
        // choose random speed
        EVT_CALL(RandInt, 4, LV_Speed)
        EVT_ADD(LV_Speed, 10)
        // choose random star type
        EVT_SWITCH(LV_PosZ)
            EVT_CASE_LT(-290)
                EVT_SET(LV_Type, FX_STAR_0)
            EVT_CASE_LT(40)
                EVT_SET(LV_Type, FX_STAR_2)
            EVT_CASE_GE(40)
                EVT_SET(LV_Type, FX_STAR_1)
        EVT_END_SWITCH
        // play sound (subject to minimum delay)
        EVT_IF_LT(LV_SoundDelay, 2)
            EVT_CALL(PlaySoundAt, SOUND_SEQ_15, 0, LV_PosX, LV_PosY, LV_PosZ)
            EVT_ADD(LV_SoundDelay, 1)
        EVT_END_IF
        EVT_ADD(LV_Time, LV_Delay)
        EVT_IF_GT(LV_Time, 30)
            EVT_SET(LV_Time, 0)
            EVT_SET(LV_SoundDelay, 0)
        EVT_END_IF
        // spawn the effect
        EVT_CALL(N(UnkEffect0FFunc2), LV_Type, LV_PosX, LV_PosY, LV_PosZ, LV_EndX, LV_EndY, LV_EndZ, LV_Speed)
        EVT_WAIT(LV_Delay)
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
            EVT_CALL(N(UnkEffect0FFunc1))
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
            EVT_CALL(PlaySoundAt, SOUND_SEQ_15, 0, LVar1, LVar2, LVar3)
            EVT_WAIT(LVar0)
            EVT_GOTO(2)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
