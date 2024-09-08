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
#if VERSION_JP
    SetGroup(EVT_GROUP_00)
#else
    SetGroup(EVT_GROUP_0B)
#endif
    Set(LV_Time, 0)
    Set(LV_SoundDelay, 0)
    Label(0)
        // no shooting stars if player x < -50
        Call(GetPlayerPos, LV_PosX, LV_PosY, LV_PosZ)
        IfLt(LV_PosX, -50)
            Wait(1)
            Goto(0)
        EndIf
        // choose delay from ~100 to 20 as a function of player x position
        Set(LV_Delay, 1000)
        Sub(LV_Delay, LV_PosX)
        Div(LV_Delay, 10)
        IfLt(LV_Delay, 20)
            Set(LV_Delay, 20)
        EndIf
        // choose a random spawn position within 400 units of the player in x and z
        Call(GetPlayerPos, LV_PosX, LV_PosY, LV_PosZ)
        Call(RandInt, 400, LV_Dx)
        Set(LV_Dy, 200)
        Call(RandInt, 400, LV_Dz)
        Sub(LV_Dz, 200)
        Add(LV_PosX, LV_Dx)
        Add(LV_PosY, LV_Dy)
        Add(LV_PosZ, LV_Dz)
        // choose a final position relative to the spawn position, with y = 0 and a random x offset
        Set(LV_EndX, LV_PosX)
        Call(RandInt, 100, LV_Dx)
        Add(LV_Dx, 50)
        Sub(LV_EndX, LV_Dx)
        Set(LV_EndY, 0)
        Set(LV_EndZ, LV_PosZ)
        // choose random speed
        Call(RandInt, 4, LV_Speed)
        Add(LV_Speed, 10)
        // choose random star type
        Switch(LV_PosZ)
            CaseLt(-290)
                Set(LV_Type, FX_STAR_BACKGROUND)
            CaseLt(40)
                Set(LV_Type, FX_STAR_LARGE_BOUNCING)
            CaseGe(40)
                Set(LV_Type, FX_STAR_FOREGROUND)
        EndSwitch
        // play sound (subject to minimum delay)
        IfLt(LV_SoundDelay, 2)
            Call(PlaySoundAt, SOUND_SEQ_SHOOTING_STAR_FALL, SOUND_SPACE_DEFAULT, LV_PosX, LV_PosY, LV_PosZ)
            Add(LV_SoundDelay, 1)
        EndIf
        Add(LV_Time, LV_Delay)
        IfGt(LV_Time, 30)
            Set(LV_Time, 0)
            Set(LV_SoundDelay, 0)
        EndIf
        // spawn the effect
        Call(N(SpawnDirectedShootingStarFX), LV_Type, LV_PosX, LV_PosY, LV_PosZ, LV_EndX, LV_EndY, LV_EndZ, LV_Speed)
        Wait(LV_Delay)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Starfall_Random) = {
    SetGroup(EVT_GROUP_0B)
    Thread
        Label(0)
            Call(RandInt, 50, LVar0)
            Add(LVar0, 10)
            Call(N(SpawnRandomBackgroundShootingStarFX))
            Wait(LVar0)
            Goto(0)
    EndThread
    Thread
        Label(1)
            Call(RandInt, 50, LVar0)
            Add(LVar0, 20)
            Call(N(SpawnRandomForegroundShootingStarFX))
            Wait(LVar0)
            Goto(1)
    EndThread
    Thread
        Label(2)
            Call(RandInt, 50, LVar0)
            Add(LVar0, 20)
            Call(N(SpawnRandomBouncingShootingStarFX))
            Call(PlaySoundAt, SOUND_SEQ_SHOOTING_STAR_FALL, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
            Wait(LVar0)
            Goto(2)
    EndThread
    Return
    End
};
