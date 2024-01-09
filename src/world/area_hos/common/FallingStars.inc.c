#include "common.h"
#include "effects.h"

API_CALLABLE(N(SpawnDirectedShootingStarFX)) {
    Bytecode* args = script->ptrReadPos;
    f32 type = evt_get_float_variable(script, *args++); /// @bug? s32 accessed as a float
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

API_CALLABLE(N(SpawnRandomBackgroundShootingStarFX)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 startX, startY, startZ;
    f32 endX, endY, endZ;
    f32 startOffset = rand_int(500) - 250;
    f32 endOffset = rand_int(500) - 250;
    f32 fwdOffset = rand_int(100) + 600;
    f32 temp_f30;

    temp_f30 = playerStatus->pos.x + (fwdOffset * sin_rad(yaw));
    startX = temp_f30 + (startOffset * sin_rad(yawPlus));
    startY = playerStatus->pos.y + 200.0f;
    startZ = playerStatus->pos.z - (fwdOffset * cos_rad(yaw));
    startZ -= startOffset * cos_rad(yawPlus);

    endX = playerStatus->pos.x + (fwdOffset * sin_rad(yaw));
    endX += endOffset * sin_rad(yawMinus);
    endY = playerStatus->pos.y;
    endZ = playerStatus->pos.z - (fwdOffset * cos_rad(yaw));
    endZ -= endOffset * cos_rad(yawMinus);

    fx_star(FX_STAR_BACKGROUND, startX, startY, startZ, endX, endY, endZ, rand_int(10) + 10);
    return ApiStatus_DONE2;
}


API_CALLABLE(N(SpawnRandomForegroundShootingStarFX)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 startOffset = rand_int(300) - 150;
    f32 endOffset = rand_int(300) - 150;
    f32 fwdOffset = rand_int(100) + 50;
    f32 startX, startY, startZ;
    f32 endX, endY, endZ;

    if ((playerStatus->pos.y >= 250.0f)) {
        return ApiStatus_DONE2;
    }

    startX = playerStatus->pos.x - (fwdOffset * sin_rad(yaw));
    startX += (startOffset * sin_rad(yawPlus));
    startY = playerStatus->pos.y + 200.0f;
    startZ = playerStatus->pos.z + (fwdOffset * cos_rad(yaw));
    startZ -= startOffset * cos_rad(yawPlus);

    endX = playerStatus->pos.x - (fwdOffset * sin_rad(yaw));
    endX += endOffset * sin_rad(yawMinus);
    endY = playerStatus->pos.y;
    endZ = playerStatus->pos.z + (fwdOffset * cos_rad(yaw));
    endZ -= endOffset * cos_rad(yawMinus);

    fx_star(FX_STAR_FOREGROUND, startX, startY, startZ, endX, endY, endZ, rand_int(10) + 10);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnRandomBouncingShootingStarFX)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw = gCameras[CAM_DEFAULT].curYaw / 180.0f * PI;
    f32 yawPlus = yaw + (PI_D / 2);
    f32 yawMinus = yaw - (PI_D / 2);
    f32 startOffset = rand_int(150);
    f32 endOffset = rand_int(150);
    f32 fwdOffset = rand_int(100) - 50;
    f32 startX, startY, startZ;
    f32 endX, endY, endZ;

    if ((playerStatus->pos.z < 200.0f)) {
        return ApiStatus_DONE2;
    }

    startX = playerStatus->pos.x - (fwdOffset * sin_rad(yaw));
    startX += (startOffset * sin_rad(yawPlus));
    startY = playerStatus->pos.y + 200.0f;
    startZ = playerStatus->pos.z + (fwdOffset * cos_rad(yaw));
    startZ -= startOffset * cos_rad(yawPlus);

    script->varTable[1] = startX;
    script->varTable[2] = startY;
    script->varTable[3] = startZ;

    endX = playerStatus->pos.x - (fwdOffset * sin_rad(yaw));
    endX += endOffset * sin_rad(yawMinus);
    endY = playerStatus->pos.y;
    endZ = playerStatus->pos.z + (fwdOffset * cos_rad(yaw));
    endZ -= endOffset * cos_rad(yawMinus);

    fx_star(FX_STAR_LARGE_BOUNCING, startX, startY, startZ, endX, endY, endZ, rand_int(4) + 10);
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
                EVT_SET(LV_Type, FX_STAR_BACKGROUND)
            EVT_CASE_LT(40)
                EVT_SET(LV_Type, FX_STAR_LARGE_BOUNCING)
            EVT_CASE_GE(40)
                EVT_SET(LV_Type, FX_STAR_FOREGROUND)
        EVT_END_SWITCH
        // play sound (subject to minimum delay)
        EVT_IF_LT(LV_SoundDelay, 2)
            EVT_CALL(PlaySoundAt, SOUND_SEQ_SHOOTING_STAR_FALL, SOUND_SPACE_DEFAULT, LV_PosX, LV_PosY, LV_PosZ)
            EVT_ADD(LV_SoundDelay, 1)
        EVT_END_IF
        EVT_ADD(LV_Time, LV_Delay)
        EVT_IF_GT(LV_Time, 30)
            EVT_SET(LV_Time, 0)
            EVT_SET(LV_SoundDelay, 0)
        EVT_END_IF
        // spawn the effect
        EVT_CALL(N(SpawnDirectedShootingStarFX), LV_Type, LV_PosX, LV_PosY, LV_PosZ, LV_EndX, LV_EndY, LV_EndZ, LV_Speed)
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
            EVT_CALL(N(SpawnRandomBackgroundShootingStarFX))
            EVT_WAIT(LVar0)
            EVT_GOTO(0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(1)
            EVT_CALL(RandInt, 50, LVar0)
            EVT_ADD(LVar0, 20)
            EVT_CALL(N(SpawnRandomForegroundShootingStarFX))
            EVT_WAIT(LVar0)
            EVT_GOTO(1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LABEL(2)
            EVT_CALL(RandInt, 50, LVar0)
            EVT_ADD(LVar0, 20)
            EVT_CALL(N(SpawnRandomBouncingShootingStarFX))
            EVT_CALL(PlaySoundAt, SOUND_SEQ_SHOOTING_STAR_FALL, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
            EVT_WAIT(LVar0)
            EVT_GOTO(2)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
