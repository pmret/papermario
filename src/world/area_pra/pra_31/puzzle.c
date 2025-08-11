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

    incorrect = false;
    for (i = 0; i < GRID_SIZE_Z; i++) {
        for (j = 0; j < GRID_SIZE_X; j++) {
            if (puzzle->cells[i][j] > CELL_EMPTY) {
                puzzle->cells[i][j]--;
            }

            if (puzzle->cells[i][j] != N(PuzzleSolution)[i][j]) {
                incorrect = true;
            }
        }
    }

    if (!incorrect) {
        evt_set_variable(script, MV_PuzzleSolved, true);
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
            script->varTable[0] = true;
        }
    }

    // is the cell out of bounds?
    if (ci < 0) {
        script->varTable[0] = true;
    }
    if (ci >= GRID_SIZE_X) {
        script->varTable[0] = true;
    }
    if (cj < 0) {
        script->varTable[0] = true;
    }
    if (cj >= GRID_SIZE_Z) {
        script->varTable[0] = true;
    }

    // cancel the push if the cell is invalid
    if (script->varTable[0] == true && gPlayerStatusPtr->actionState == ACTION_STATE_PUSHING_BLOCK) {
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
    Loop(0)
        IfEq(MV_PuzzleSolved, true)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, true)
    Loop(0)
        IfEq(MV_PushingStatue, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
    Wait(40)
    Call(UseSettingsFrom, CAM_DEFAULT, 325, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 325, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(323.3), Float(-66.5))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(296.8))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Wait(45)
        Call(SetGroupVisibility, MODEL_g255, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_g262, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_g264, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_g265, MODEL_GROUP_VISIBLE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1071, COLLIDER_FLAGS_UPPER_MASK)
    EndThread
    Thread
        Wait(50)
        Call(PlaySoundAtModel, MODEL_k1, SOUND_PRA_UNFOLD_EXIT, 0)
        Wait(25)
        Call(PlaySoundAtModel, MODEL_k2, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
        Wait(5)
        Call(PlaySoundAtModel, MODEL_k3, SOUND_PRA_UNFOLD_STEP, 0)
    EndThread
    Thread
        Wait(50)
        Call(EnableModel, MODEL_n1, false)
        Call(EnableModel, MODEL_k1, true)
        Wait(10)
        Call(EnableModel, MODEL_n2, false)
        Call(EnableModel, MODEL_k2, true)
        Wait(30)
        Call(EnableModel, MODEL_n3, false)
        Call(EnableModel, MODEL_k3, true)
        Wait(22)
        Call(EnableModel, MODEL_n4, false)
        Call(EnableModel, MODEL_k4, true)
        Wait(18)
        Call(EnableModel, MODEL_n5, false)
        Call(EnableModel, MODEL_k5, true)
    EndThread
    Call(PlayModelAnimation, MDL_ANIMATOR_0, Ref(N(AS_Stairs_Unfold)))
    Wait(200)
    Set(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_UpdateStatuePositions) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(N(GetDinoStatuePosRot), NPC_AlbinoDino_01)
    Set(MV_StatueYaw_01, LVar2)
    Call(N(GetDinoStatuePosRot), NPC_AlbinoDino_02)
    Set(MV_StatueYaw_02, LVar2)
    Call(N(GetDinoStatuePosRot), NPC_AlbinoDino_03)
    Set(MV_StatueYaw_03, LVar2)
    Loop(0)
        Call(N(GetDinoStatuePosRot), NPC_AlbinoDino_01)
        Call(TranslateGroup, MODEL_s01, LVar0, 0, LVar1)
        Call(RotateGroup, MODEL_g292, MV_StatueYaw_01, 0, 1, 0)
        Call(N(GetDinoStatuePosRot), NPC_AlbinoDino_02)
        Call(TranslateGroup, MODEL_s02, LVar0, 0, LVar1)
        Call(RotateGroup, MODEL_g298, MV_StatueYaw_02, 0, 1, 0)
        Call(N(GetDinoStatuePosRot), NPC_AlbinoDino_03)
        Call(TranslateGroup, MODEL_s03, LVar0, 0, LVar1)
        Call(RotateGroup, MODEL_g299, MV_StatueYaw_03, 0, 1, 0)
        Call(N(GetDinoNpcPosRot), NPC_AlbinoDino_01)
        Call(SetNpcPos, NPC_AlbinoDino_01, LVar0, -10, LVar1)
        Call(N(GetDinoNpcPosRot), NPC_AlbinoDino_02)
        Call(SetNpcPos, NPC_AlbinoDino_02, LVar0, -10, LVar1)
        Call(N(GetDinoNpcPosRot), NPC_AlbinoDino_03)
        Call(SetNpcPos, NPC_AlbinoDino_03, LVar0, -10, LVar1)
        Call(UpdateColliderTransform, COLLIDER_s01n)
        Call(UpdateColliderTransform, COLLIDER_s01e)
        Call(UpdateColliderTransform, COLLIDER_s01s)
        Call(UpdateColliderTransform, COLLIDER_s01w)
        Call(UpdateColliderTransform, COLLIDER_s02n)
        Call(UpdateColliderTransform, COLLIDER_s02e)
        Call(UpdateColliderTransform, COLLIDER_s02s)
        Call(UpdateColliderTransform, COLLIDER_s02w)
        Call(UpdateColliderTransform, COLLIDER_s03n)
        Call(UpdateColliderTransform, COLLIDER_s03e)
        Call(UpdateColliderTransform, COLLIDER_s03s)
        Call(UpdateColliderTransform, COLLIDER_s03w)
        Wait(1)
    EndLoop
    Return
    End
};

#include "world/common/todo/UnkFunc11.inc.c"

EvtScript N(EVS_PushStatue_Impl) = {
    Call(N(GetPlayerPushDirection), LVarA)
    Call(InterpPlayerYaw, LVar0, 0)
    Loop(20)
        Call(N(UnkFunc11), LVar9)
        IfEq(LVar0, 0)
            Return
        Else
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, true)
    Thread
        Call(N(GetPlayerPushLerpValues), LVarA)
        Call(MakeLerp, LVar3, LVar4, PUSH_TIME, EASING_LINEAR)
        Loop(0)
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
            Call(UpdateLerp)
            Call(N(UnkFunc12))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, PUSH_TIME, Float(0.3))
    EndThread
    Set(MV_PushingStatue, true)
    Call(PlaySoundAtCollider, LVar9, SOUND_PRA_PUSH_STATUE, 0)
    Call(N(BeginPushingStatue), LVarA)
    Wait(PUSH_TIME)
    Set(MV_PushingStatue, false)
    Call(N(EndBlockPushingState))
    Thread
        Call(DisablePlayerInput, false)
        Wait(2)
        Call(N(UnkFunc11), LVar9)
        IfEq(LVar0, 0)
            Wait(2)
            Call(N(UnkFunc11), LVar9)
            IfEq(LVar0, 0)
                Call(SetPlayerActionState, ACTION_STATE_IDLE)
            EndIf
        EndIf
    EndThread
    Return
    End
};

EvtScript N(EVS_PushStatue_01) = {
#if !VERSION_JP
    IfGe(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        Return
    EndIf
#endif
    Call(N(IsDestCellUnavailable), NPC_AlbinoDino_01)
    IfEq(LVar0, true)
        Return
    EndIf
    Set(LVarA, NPC_AlbinoDino_01)
    Set(LVar9, COLLIDER_s01e)
    ExecWait(N(EVS_PushStatue_Impl))
    Return
    End
};

EvtScript N(EVS_PushStatue_02) = {
#if !VERSION_JP
    IfGe(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        Return
    EndIf
#endif
    Call(N(IsDestCellUnavailable), NPC_AlbinoDino_02)
    IfEq(LVar0, true)
        Return
    EndIf
    Set(LVarA, NPC_AlbinoDino_02)
    Set(LVar9, COLLIDER_s02e)
    ExecWait(N(EVS_PushStatue_Impl))
    Return
    End
};

EvtScript N(EVS_PushStatue_03) = {
#if !VERSION_JP
    IfGe(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        Return
    EndIf
#endif
    Call(N(IsDestCellUnavailable), NPC_AlbinoDino_03)
    IfEq(LVar0, true)
        Return
    EndIf
    Set(LVarA, NPC_AlbinoDino_03)
    Set(LVar9, COLLIDER_s03e)
    ExecWait(N(EVS_PushStatue_Impl))
    Return
    End
};

EvtScript N(EVS_SetupPuzzle) = {
    Call(InitAnimatedModels)
    Call(LoadAnimatedModel, MDL_ANIMATOR_0, Ref(N(AS_Stairs_Skeleton)))
    Call(SetAnimatedModelRootPosition, MDL_ANIMATOR_0, 0, 0, 0)
    Call(SetAnimatedModelRenderMode, MDL_ANIMATOR_0, RENDER_MODE_SURFACE_OPA)
    Thread
        Call(N(EVS_ManagePuzzle))
    EndThread
    Wait(1)
    Call(ParentColliderToModel, COLLIDER_s01n, MODEL_o1032)
    Call(ParentColliderToModel, COLLIDER_s01e, MODEL_o1032)
    Call(ParentColliderToModel, COLLIDER_s01s, MODEL_o1032)
    Call(ParentColliderToModel, COLLIDER_s01w, MODEL_o1032)
    Call(ParentColliderToModel, COLLIDER_s02n, MODEL_o1040)
    Call(ParentColliderToModel, COLLIDER_s02e, MODEL_o1040)
    Call(ParentColliderToModel, COLLIDER_s02s, MODEL_o1040)
    Call(ParentColliderToModel, COLLIDER_s02w, MODEL_o1040)
    Call(ParentColliderToModel, COLLIDER_s03n, MODEL_o1044)
    Call(ParentColliderToModel, COLLIDER_s03e, MODEL_o1044)
    Call(ParentColliderToModel, COLLIDER_s03s, MODEL_o1044)
    Call(ParentColliderToModel, COLLIDER_s03w, MODEL_o1044)
    Set(MV_PuzzleSolved, false)
    Exec(N(EVS_UpdateStatuePositions))
    BindTrigger(Ref(N(EVS_PushStatue_01)), TRIGGER_WALL_PUSH, COLLIDER_s01e, 1, 0)
    BindTrigger(Ref(N(EVS_PushStatue_02)), TRIGGER_WALL_PUSH, COLLIDER_s02e, 1, 0)
    BindTrigger(Ref(N(EVS_PushStatue_03)), TRIGGER_WALL_PUSH, COLLIDER_s03e, 1, 0)
    IfGe(GB_StoryProgress, STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
        Call(PlayModelAnimation, MDL_ANIMATOR_0, Ref(N(AS_Stairs_InitializeAfter)))
        Call(SetGroupVisibility, MODEL_no, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_kage_yuka, MODEL_GROUP_VISIBLE)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1071, COLLIDER_FLAGS_UPPER_MASK)
        Call(PlayModelAnimation, MDL_ANIMATOR_0, Ref(N(AS_Stairs_InitializeBefore)))
        Call(SetGroupVisibility, MODEL_g255, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g262, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g264, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g265, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_no, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_kage_yuka, MODEL_GROUP_HIDDEN)
        Exec(N(EVS_Scene_PuzzleSolved))
    EndIf
    Return
    End
};
