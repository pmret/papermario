#include "pra_31.h"

#define DINO_CELL_SIZE 50
#define PUSH_TIME  40
#define GRID_SIZE_X 9
#define GRID_SIZE_Z 3
#define DINO_COUNT  3

typedef struct DinoData {
    /* 0x00 */ s16 ci; // cell i index
    /* 0x02 */ s16 cj; // cell j index
    /* 0x04 */ f32 corPosX;
    /* 0x08 */ f32 curPosZ;
    /* 0x0C */ f32 goalPosX;
    /* 0x10 */ f32 goalPosZ;
    /* 0x14 */ f32 angle;
} DinoData; // size = 0x18

typedef struct DinoPuzzleData {
    /* 0x00 */ DinoData dinos[DINO_COUNT];
    /* 0x48 */ s16 cells[GRID_SIZE_Z][GRID_SIZE_X];
    /* 0x7E */ char unk_7E[0x2];
} DinoPuzzleData; // size = 0x80

enum {
    CELL_EMPTY     = 0,
    CELL_DINO      = -1,
};

s32 N(InitialConfigurationBefore)[DINO_COUNT][3] = {
    { 2, 0, 270 },
    { 3, 2, 270 },
    { 5, 1, 270 },
};

s32 N(InitialConfigurationAfter)[DINO_COUNT][3]= {
    { 1, 1, 270 },
    { 4, 1, 270 },
    { 7, 1, 270 },
};

s16 N(PuzzleSolution)[GRID_SIZE_Z][GRID_SIZE_X] = {
    {  CELL_EMPTY, CELL_EMPTY,  CELL_EMPTY,  CELL_EMPTY, CELL_EMPTY,  CELL_EMPTY,  CELL_EMPTY, CELL_EMPTY,  CELL_EMPTY },
    {  CELL_EMPTY, CELL_DINO,   CELL_EMPTY,  CELL_EMPTY, CELL_DINO,   CELL_EMPTY,  CELL_EMPTY, CELL_DINO,   CELL_EMPTY },
    {  CELL_EMPTY, CELL_EMPTY,  CELL_EMPTY,  CELL_EMPTY, CELL_EMPTY,  CELL_EMPTY,  CELL_EMPTY, CELL_EMPTY,  CELL_EMPTY },
};

API_CALLABLE(N(EVS_ManagePuzzle)) {
    DinoPuzzleData* puzzle;
    DinoData* dino;
    s32 storyProgress;
    s32 incorrect;
    s32 i, j;

    if (isInitialCall) {
        puzzle = heap_malloc(sizeof(*puzzle));
        evt_set_variable(script, MV_PuzzleDataPtr, (s32) puzzle);
        storyProgress = evt_get_variable(script, GB_StoryProgress);

        for (i = 0; i < GRID_SIZE_Z; i++) {
            for (j = 0; j < GRID_SIZE_X; j++) {
                puzzle->cells[i][j] = CELL_EMPTY;
            }
        }

        for (j = 0, dino = &puzzle->dinos[0]; j < DINO_COUNT; j++, dino++) {
            if (storyProgress < STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE) {
                dino->ci = N(InitialConfigurationBefore)[j][0];
                dino->cj = N(InitialConfigurationBefore)[j][1];
                dino->angle = N(InitialConfigurationBefore)[j][2];
            } else {
                dino->ci = N(InitialConfigurationAfter)[j][0];
                dino->cj = N(InitialConfigurationAfter)[j][1];
                dino->angle = N(InitialConfigurationAfter)[j][2];
            }
            dino->corPosX = dino->goalPosX = (dino->ci * DINO_CELL_SIZE) + DINO_CELL_SIZE;
            dino->curPosZ = dino->goalPosZ = (dino->cj * DINO_CELL_SIZE) + DINO_CELL_SIZE + DINO_CELL_SIZE / 2;
            puzzle->cells[dino->cj][dino->ci] = CELL_DINO;
        }
        evt_set_variable(script, MV_DinoYaw_01, 270);
        evt_set_variable(script, MV_DinoYaw_02, 270);
        evt_set_variable(script, MV_DinoYaw_03, 270);
    }

    puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    dino = &puzzle->dinos[0];
    for (j = 0; j < DINO_COUNT; j++, dino++) {
        if (dino->corPosX < dino->goalPosX) {
            dino->corPosX += (f32) DINO_CELL_SIZE / PUSH_TIME;
        }
        if (dino->corPosX > dino->goalPosX) {
            dino->corPosX -= (f32) DINO_CELL_SIZE / PUSH_TIME;
        }
        if (dino->curPosZ < dino->goalPosZ) {
            dino->curPosZ += (f32) DINO_CELL_SIZE / PUSH_TIME;
        }
        if (dino->curPosZ > dino->goalPosZ) {
            dino->curPosZ -= (f32) DINO_CELL_SIZE / PUSH_TIME;
        }
    }

    incorrect = FALSE;
    for (i = 0; i < GRID_SIZE_Z; i++) {
        for (j = 0; j < GRID_SIZE_X; j++) {
            if (puzzle->cells[i][j] > CELL_EMPTY) {
                puzzle->cells[i][j]--;
            }

            if (puzzle->cells[i][j] != N(PuzzleSolution)[i][j]) {
                incorrect = TRUE;
            }
        }
    }

    if (!incorrect) {
        evt_set_variable(script, MV_PuzzleSolved, TRUE);
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SetDinoAngle)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    f32 angle = evt_get_float_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];

    dino->angle = angle;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IsDestCellUnavailable)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];
    s32 ci;
    s32 cj;
    s32 i;

    script->varTable[0] = 0;

    // determine the cell we want to push into
    switch ((s32) dino->angle) {
        case 0:
            ci = dino->ci;
            cj = dino->cj - 1;
            break;
        case 90:
            cj = dino->cj;
            ci = dino->ci + 1;
            break;
        case 180:
            ci = dino->ci;
            cj = dino->cj + 1;
            break;
        case 270:
            cj = dino->cj;
            ci = dino->ci - 1;
            break;
    }

    // does another dino exist at the proposed grid cell?
    for (i = 0; i < DINO_COUNT; i++) {
        if (i != idx && ci == puzzle->dinos[i].ci && cj == puzzle->dinos[i].cj) {
            script->varTable[0] = TRUE;
        }
    }

    // is the cell out of bounds?
    if (ci < 0) {
        script->varTable[0] = TRUE;
    }
    if (ci >= GRID_SIZE_X) {
        script->varTable[0] = TRUE;
    }
    if (cj < 0) {
        script->varTable[0] = TRUE;
    }
    if (cj >= GRID_SIZE_Z) {
        script->varTable[0] = TRUE;
    }

    // cancel the push if the cell is invalid
    if (script->varTable[0] == TRUE && gPlayerStatusPtr->actionState == ACTION_STATE_PUSHING_BLOCK) {
        set_action_state(ACTION_STATE_IDLE);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(BeginPushingStatue)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];

    puzzle->cells[dino->cj][dino->ci] = PUSH_TIME / 2;

    switch ((s32) dino->angle) {
        case 0:
            dino->cj--;
            break;
        case 90:
            dino->ci++;
            break;
        case 180:
            dino->cj++;
            break;
        case 270:
            dino->ci--;
    }

    puzzle->cells[dino->cj][dino->ci] = CELL_DINO;
    dino->goalPosX = ((dino->ci * DINO_CELL_SIZE) + DINO_CELL_SIZE);
    dino->goalPosZ = ((dino->cj * DINO_CELL_SIZE) + DINO_CELL_SIZE + DINO_CELL_SIZE / 2);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPlayerPushDirection)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];

    switch ((s32)dino->angle) {
        case 0:
            script->varTable[0] = 180;
            break;
        case 180:
            script->varTable[0] = 0;
            break;
        case 90:
            script->varTable[0] = 90;
            break;
        case 270:
            script->varTable[0] = 270;
            break;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPlayerPushLerpValues)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];

    switch ((s32)dino->angle) {
        case 0:
            script->varTable[3] = playerStatus->pos.z;
            script->varTable[4] = playerStatus->pos.z + DINO_CELL_SIZE;
            script->varTable[5] = 1;
            break;
        case 90:
            script->varTable[3] = playerStatus->pos.x;
            script->varTable[4] = playerStatus->pos.x + DINO_CELL_SIZE;
            script->varTable[5] = 0;
            break;
        case 180:
            script->varTable[3] = playerStatus->pos.z;
            script->varTable[4] = playerStatus->pos.z - DINO_CELL_SIZE;
            script->varTable[5] = 1;
            break;
        case 270:
            script->varTable[3] = playerStatus->pos.x;
            script->varTable[4] = playerStatus->pos.x - DINO_CELL_SIZE;
            script->varTable[5] = 0;
            break;
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc12.inc.c"

API_CALLABLE(N(GetDinoStatuePosRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];

    evt_set_float_variable(script, LVar0, dino->corPosX);
    evt_set_float_variable(script, LVar1, -dino->curPosZ);
    evt_set_float_variable(script, LVar2, clamp_angle(dino->angle + 90.0));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetDinoNpcPosRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    DinoPuzzleData* puzzle = (DinoPuzzleData*) evt_get_variable(script, MV_PuzzleDataPtr);
    DinoData* dino = &puzzle->dinos[idx];

    evt_set_float_variable(script, LVar0, dino->corPosX);
    evt_set_float_variable(script, LVar1, dino->curPosZ);
    evt_set_float_variable(script, LVar2, clamp_angle(dino->angle));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EndBlockPushingState)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= PA_FLAG_ABORT_PUSHING_BLOCK;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_PuzzleSolved) = {
    EVT_LOOP(0)
        EVT_IF_EQ(MV_PuzzleSolved, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_IF_EQ(MV_PushingStatue, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
    EVT_WAIT(40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 325, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 325, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(323.3), EVT_FLOAT(-66.5))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(296.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(45)
        EVT_CALL(SetGroupVisibility, MODEL_g255, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_g262, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_g264, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_g265, MODEL_GROUP_VISIBLE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1071, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(50)
        EVT_CALL(PlaySoundAtModel, MODEL_k1, SOUND_PRA_UNFOLD_EXIT, 0)
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtModel, MODEL_k2, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(50)
        EVT_CALL(EnableModel, MODEL_n1, FALSE)
        EVT_CALL(EnableModel, MODEL_k1, TRUE)
        EVT_WAIT(10)
        EVT_CALL(EnableModel, MODEL_n2, FALSE)
        EVT_CALL(EnableModel, MODEL_k2, TRUE)
        EVT_WAIT(30)
        EVT_CALL(EnableModel, MODEL_n3, FALSE)
        EVT_CALL(EnableModel, MODEL_k3, TRUE)
        EVT_WAIT(22)
        EVT_CALL(EnableModel, MODEL_n4, FALSE)
        EVT_CALL(EnableModel, MODEL_k4, TRUE)
        EVT_WAIT(18)
        EVT_CALL(EnableModel, MODEL_n5, FALSE)
        EVT_CALL(EnableModel, MODEL_k5, TRUE)
    EVT_END_THREAD
    EVT_CALL(PlayModelAnimation, MDL_ANIMATOR_0, EVT_PTR(N(AS_Stairs_Unfold)))
    EVT_WAIT(200)
    EVT_SET(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateStatuePositions) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(N(GetDinoStatuePosRot), NPC_AlbinoDino_01)
    EVT_SET(MV_StatueYaw_01, LVar2)
    EVT_CALL(N(GetDinoStatuePosRot), NPC_AlbinoDino_02)
    EVT_SET(MV_StatueYaw_02, LVar2)
    EVT_CALL(N(GetDinoStatuePosRot), NPC_AlbinoDino_03)
    EVT_SET(MV_StatueYaw_03, LVar2)
    EVT_LOOP(0)
        EVT_CALL(N(GetDinoStatuePosRot), NPC_AlbinoDino_01)
        EVT_CALL(TranslateGroup, MODEL_s01, LVar0, 0, LVar1)
        EVT_CALL(RotateGroup, MODEL_g292, MV_StatueYaw_01, 0, 1, 0)
        EVT_CALL(N(GetDinoStatuePosRot), NPC_AlbinoDino_02)
        EVT_CALL(TranslateGroup, MODEL_s02, LVar0, 0, LVar1)
        EVT_CALL(RotateGroup, MODEL_g298, MV_StatueYaw_02, 0, 1, 0)
        EVT_CALL(N(GetDinoStatuePosRot), NPC_AlbinoDino_03)
        EVT_CALL(TranslateGroup, MODEL_s03, LVar0, 0, LVar1)
        EVT_CALL(RotateGroup, MODEL_g299, MV_StatueYaw_03, 0, 1, 0)
        EVT_CALL(N(GetDinoNpcPosRot), NPC_AlbinoDino_01)
        EVT_CALL(SetNpcPos, NPC_AlbinoDino_01, LVar0, -10, LVar1)
        EVT_CALL(N(GetDinoNpcPosRot), NPC_AlbinoDino_02)
        EVT_CALL(SetNpcPos, NPC_AlbinoDino_02, LVar0, -10, LVar1)
        EVT_CALL(N(GetDinoNpcPosRot), NPC_AlbinoDino_03)
        EVT_CALL(SetNpcPos, NPC_AlbinoDino_03, LVar0, -10, LVar1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s01n)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s01e)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s01s)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s01w)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s02n)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s02e)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s02s)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s02w)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s03n)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s03e)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s03s)
        EVT_CALL(UpdateColliderTransform, COLLIDER_s03w)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc11.inc.c"

EvtScript N(EVS_PushStatue_Impl) = {
    EVT_CALL(N(GetPlayerPushDirection), LVarA)
    EVT_CALL(InterpPlayerYaw, LVar0, 0)
    EVT_LOOP(20)
        EVT_CALL(N(UnkFunc11), LVar9)
        EVT_IF_EQ(LVar0, 0)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(N(GetPlayerPushLerpValues), LVarA)
        EVT_CALL(MakeLerp, LVar3, LVar4, PUSH_TIME, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(UnkFunc12))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, PUSH_TIME, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_SET(MV_PushingStatue, TRUE)
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_PRA_PUSH_STATUE, 0)
    EVT_CALL(N(BeginPushingStatue), LVarA)
    EVT_WAIT(PUSH_TIME)
    EVT_SET(MV_PushingStatue, FALSE)
    EVT_CALL(N(EndBlockPushingState))
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_WAIT(2)
        EVT_CALL(N(UnkFunc11), LVar9)
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(2)
            EVT_CALL(N(UnkFunc11), LVar9)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushStatue_01) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(IsDestCellUnavailable), NPC_AlbinoDino_01)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, NPC_AlbinoDino_01)
    EVT_SET(LVar9, COLLIDER_s01e)
    EVT_EXEC_WAIT(N(EVS_PushStatue_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushStatue_02) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(IsDestCellUnavailable), NPC_AlbinoDino_02)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, NPC_AlbinoDino_02)
    EVT_SET(LVar9, COLLIDER_s02e)
    EVT_EXEC_WAIT(N(EVS_PushStatue_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushStatue_03) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(IsDestCellUnavailable), NPC_AlbinoDino_03)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, NPC_AlbinoDino_03)
    EVT_SET(LVar9, COLLIDER_s03e)
    EVT_EXEC_WAIT(N(EVS_PushStatue_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPuzzle) = {
    EVT_CALL(InitAnimatedModels)
    EVT_CALL(LoadAnimatedModel, MDL_ANIMATOR_0, EVT_PTR(N(AS_Stairs_Skeleton)))
    EVT_CALL(SetAnimatedModelRootPosition, MDL_ANIMATOR_0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, MDL_ANIMATOR_0, RENDER_MODE_SURFACE_OPA)
    EVT_THREAD
        EVT_CALL(N(EVS_ManagePuzzle))
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(ParentColliderToModel, COLLIDER_s01n, MODEL_o1032)
    EVT_CALL(ParentColliderToModel, COLLIDER_s01e, MODEL_o1032)
    EVT_CALL(ParentColliderToModel, COLLIDER_s01s, MODEL_o1032)
    EVT_CALL(ParentColliderToModel, COLLIDER_s01w, MODEL_o1032)
    EVT_CALL(ParentColliderToModel, COLLIDER_s02n, MODEL_o1040)
    EVT_CALL(ParentColliderToModel, COLLIDER_s02e, MODEL_o1040)
    EVT_CALL(ParentColliderToModel, COLLIDER_s02s, MODEL_o1040)
    EVT_CALL(ParentColliderToModel, COLLIDER_s02w, MODEL_o1040)
    EVT_CALL(ParentColliderToModel, COLLIDER_s03n, MODEL_o1044)
    EVT_CALL(ParentColliderToModel, COLLIDER_s03e, MODEL_o1044)
    EVT_CALL(ParentColliderToModel, COLLIDER_s03s, MODEL_o1044)
    EVT_CALL(ParentColliderToModel, COLLIDER_s03w, MODEL_o1044)
    EVT_SET(MV_PuzzleSolved, FALSE)
    EVT_EXEC(N(EVS_UpdateStatuePositions))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushStatue_01)), TRIGGER_WALL_PUSH, COLLIDER_s01e, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushStatue_02)), TRIGGER_WALL_PUSH, COLLIDER_s02e, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushStatue_03)), TRIGGER_WALL_PUSH, COLLIDER_s03e, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        EVT_CALL(PlayModelAnimation, MDL_ANIMATOR_0, EVT_PTR(N(AS_Stairs_InitializeAfter)))
        EVT_CALL(SetGroupVisibility, MODEL_no, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_kage_yuka, MODEL_GROUP_VISIBLE)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1071, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(PlayModelAnimation, MDL_ANIMATOR_0, EVT_PTR(N(AS_Stairs_InitializeBefore)))
        EVT_CALL(SetGroupVisibility, MODEL_g255, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g262, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g264, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g265, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_no, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_kage_yuka, MODEL_GROUP_HIDDEN)
        EVT_EXEC(N(EVS_Scene_PuzzleSolved))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
