#include "common.h"
#include "message_ids.h"
#include "effects.h"
#include "model.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/player.h"

#ifndef CHUCK_QUIZMO_NPC_ID
    #error CHUCK_QUIZMO_NPC_ID must be defined for Quizmo.inc.c
#endif

#define QUIZMO_ANIMS \
{ \
    ANIM_ChuckQuizmo_Idle, \
    ANIM_ChuckQuizmo_Walk, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Idle, \
    ANIM_ChuckQuizmo_Idle, \
    ANIM_ChuckQuizmo_Still, \
    ANIM_ChuckQuizmo_Still, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
    ANIM_ChuckQuizmo_Run, \
}

extern s16 MessagePlural;
extern s16 MessageSingular;

#if VERSION_PAL
extern u8 MessagePlural_de[];
#endif

BSS s32 N(Quizmo_Worker);
// needed for kmr_02
#ifndef QUIZMO_PRE_STATIC_PAD
MAP_STATIC_PAD(1,quizmo_pre_array);
#endif
BSS s32 N(Quizmo_ScriptArray)[5];
MAP_STATIC_PAD(1,quizmo_post_array);
BSS EffectInstance* N(Quizmo_StageEffect);
BSS EffectInstance* N(Quizmo_AudienceEffect);
BSS EffectInstance* N(Quizmo_VannaTEffect);

enum {
    QUIZ_ARRAY_SAVED_FOV        = ArrayVar(0),
    QUIZ_ARRAY_ORIGIN_X         = ArrayVar(1),
    QUIZ_ARRAY_ORIGIN_Y         = ArrayVar(2),
    QUIZ_ARRAY_ORIGIN_Z         = ArrayVar(3),
    QUIZ_ARRAY_ANSWER_RESULT    = ArrayVar(4),
};

enum {
    QUIZ_ARRAY_INDEX_SAVED_FOV      = 0,
    QUIZ_ARRAY_INDEX_ORIGIN_X       = 1,
    QUIZ_ARRAY_INDEX_ORIGIN_Y       = 2,
    QUIZ_ARRAY_INDEX_ORIGIN_Z       = 3,
    QUIZ_ARRAY_INDEX_ANSWER_RESULT  = 4,
};

#include "world/common/complete/GiveReward.inc.c"

// values for Quizmo npc init vars
enum {
    QUIZ_AREA_KMR       = 0,
    QUIZ_AREA_MAC       = 1,
    QUIZ_AREA_NOK       = 2,
    QUIZ_AREA_DRO       = 3,
    QUIZ_AREA_JAN       = 4,
    QUIZ_AREA_SAM       = 5,
    QUIZ_AREA_HOS       = 6,
};

enum {
    // area_kmr
    QUIZ_MAP_KMR_02     = 0,
    QUIZ_COUNT_KMR      = 1,
    // area_mac
    QUIZ_MAP_MAC_00     = 0,
    QUIZ_MAP_MAC_01     = 1,
    QUIZ_MAP_MAC_02     = 2, // unused
    QUIZ_MAP_MAC_03     = 3, // unused
    QUIZ_MAP_MAC_04     = 4,
    QUIZ_MAP_MAC_05     = 5,
    QUIZ_COUNT_MAC      = 6,
    // area_nok
    QUIZ_MAP_NOK_01     = 0,
    QUIZ_MAP_NOK_02     = 1,
    QUIZ_COUNT_NOK      = 2,
    // area_dro
    QUIZ_MAP_DRO_01     = 0,
    QUIZ_MAP_DRO_02     = 1,
    QUIZ_COUNT_DRO      = 2,
    // area_jan
    QUIZ_MAP_JAN_02     = 0,
    QUIZ_MAP_JAN_03     = 1,
    QUIZ_COUNT_JAN      = 2,
    // area_sam
    QUIZ_MAP_SAM_01     = 0,
    QUIZ_MAP_SAM_02     = 1,
    QUIZ_MAP_SAM_11     = 2,
    QUIZ_COUNT_SAM      = 3,
    // area_hos
    QUIZ_MAP_HOS_03     = 0,
    QUIZ_COUNT_HOS      = 1,
};

u8 N(Quizmo_Answers)[64] = {
    2, 1, 1, 2, 2, 0, 2, 0,
    2, 1, 0, 2, 1, 1, 0, 2,
    0, 2, 1, 0, 0, 2, 1, 0,
    2, 1, 1, 2, 2, 1, 1, 1,
    0, 2, 2, 2, 2, 0, 1, 1,
    2, 1, 2, 1, 2, 0, 0, 1,
    1, 0, 1, 2, 1, 0, 2, 2,
    1, 2, 0, 2, 2, 1, 1, 1,
};

QuizRequirement N(Quizmo_Requirements)[] = {
    { STORY_CH0_KAMMY_RETURNED_TO_BOWSER, 0 },
    { STORY_CH1_BEGAN_PEACH_MISSION, 10 },
    { STORY_CH2_BEGAN_PEACH_MISSION, 20 },
    { STORY_CH3_BEGAN_PEACH_MISSION, 30 },
    { STORY_CH4_BEGAN_PEACH_MISSION, 37 },
    { STORY_CH5_STAR_SPRIT_DEPARTED, 44 },
    { STORY_CH6_BEGAN_PEACH_MISSION, 52 },
    { STORY_CH7_BEGAN_PEACH_MISSION, 60 },
    { STORY_EPILOGUE, 64 },
    { 0, 64 }, // end of list
};

API_CALLABLE(N(Quizmo_HideEntities)) {
    gEntityHideMode = ENTITY_HIDE_MODE_1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_ShowEntities)) {
    gEntityHideMode = ENTITY_HIDE_MODE_0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_ShouldAppear)) {
    Enemy* enemy = script->owner1.enemy;
    u16 hasLocation = evt_get_variable(script, GF_Quizmo_HasLocation);
    u16 changedLocation = evt_get_variable(script, GF_Quizmo_ChangedLocation);
    u16 locTown = evt_get_variable(script, GB_ChuckQuizmo_Town);
    u16 locMap = evt_get_variable(script, GB_ChuckQuizmo_Map);
    s32 var;
    s32 i;

    s32 test2;
    u16 curTown1 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 curTown2 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 numMaps = (enemy->varTable[0] & 0xFF00) >> 8;
    u16 curMap = (enemy->varTable[0] & 0xFF) >> 0;
    s32 progress;
    s32 numAnswered;

    if (curTown1 != locTown) {
        changedLocation = FALSE;
        hasLocation = FALSE;
    }

    if (!hasLocation) {
        if (rand_int(100) < 30) {
            locMap = rand_int(numMaps - 1);
            locTown = curTown1;
            evt_set_variable(script, GB_ChuckQuizmo_Town, locTown);
            evt_set_variable(script, GB_ChuckQuizmo_Map, locMap);
            hasLocation = TRUE;
        }
    }

    evt_set_variable(script, GF_Quizmo_HasLocation, hasLocation);
    evt_set_variable(script, GF_Quizmo_ChangedLocation, changedLocation);
    numAnswered = evt_get_variable(NULL, GB_CompletedQuizzes);
    progress = evt_get_variable(NULL, GB_StoryProgress);

    // vanilla bug? never checks the final requirement in the list
    for (i = 0; i < 8; i++) {
        if (progress < N(Quizmo_Requirements)[i].requiredStoryProgress) {
            break;
        }
    }

    //TODO clean this up
    progress = numAnswered < N(Quizmo_Requirements)[i].numQuestionsUnlocked;
    test2 = var = progress;

    if ((((curTown2 == locTown) && (curMap == locMap) && (changedLocation == 0) && test2)) ||
        (gGameStatusPtr->debugQuizmo && var)) {
        script->varTable[0] = TRUE;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = FALSE;
    }

    return ApiStatus_DONE2;
}

void N(Quizmo_NPC_OnRender)(Npc* npc);

API_CALLABLE(N(Quizmo_RenderInit)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->onRender = N(Quizmo_NPC_OnRender);
    npc->blur.quizmo = heap_malloc(sizeof(*npc->blur.quizmo));
    npc->blur.quizmo->flags = 0;

    return ApiStatus_DONE1;
}

API_CALLABLE(N(Quizmo_NPC_Aux_Impl)) {
    // does nothing, probably a default/template function for NPCs
    get_npc_unsafe(script->owner2.npcID);
    return ApiStatus_BLOCK;
}

void N(Quizmo_NPC_OnRender)(Npc* npc) {
    Camera* camera = &gCameras[gCurrentCamID];

    if (npc->blur.quizmo->flags & 1) {
        clamp_angle(-camera->curYaw);
    }
}

API_CALLABLE(N(Quizmo_HideWorld)) {
    if (isInitialCall) {
        s32 i;

        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != NULL && npc->flags != 0) {
                if (npc->npcID != NPC_PARTNER && npc->npcID != CHUCK_QUIZMO_NPC_ID) {
                    npc->flags |= NPC_FLAG_HIDING;
                }
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = get_item_entity(i);
            if (itemEntity != NULL && itemEntity->flags & ITEM_ENTITY_FLAG_10) {
                itemEntity->flags |= ITEM_ENTITY_FLAG_HIDING;
            }
        }

        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 8;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);

    if (script->functionTemp[0] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(Quizmo_FadeInWorld)) {
    s32 i;

    if (isInitialCall) {
        mdl_set_shroud_tint_params(0, 0, 0, 255);
        script->functionTemp[0] = 255;
        script->functionTemp[1] = 0;
    }

    script->functionTemp[0] -= 8;
    if (script->functionTemp[0] < 0) {
        script->functionTemp[0] = 0;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);
    if (script->functionTemp[0] == 0 && script->functionTemp[1] == 0) {
        script->functionTemp[1] = 1;
    } else if (script->functionTemp[1] == 1) {
        mdl_set_all_tint_type(ENV_TINT_NONE);
        *gBackgroundTintModePtr = ENV_TINT_NONE;

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != NULL && npc->flags != 0) {
                if (npc->npcID != NPC_PARTNER && npc->npcID != CHUCK_QUIZMO_NPC_ID) {
                    npc->flags &= ~NPC_FLAG_HIDING;
                }
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* entity = get_item_entity(i);
            if (entity != NULL && entity->flags & ITEM_ENTITY_FLAG_10) {
                entity->flags &= ~ITEM_ENTITY_FLAG_HIDING;
            }
        }

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(Quizmo_UpdateRecords)) {
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 999) {
        gPlayerData.quizzesAnswered++;
    }

    if (script->varTable[0] == N(Quizmo_Answers)[evt_get_variable(NULL, GB_CompletedQuizzes)]) {
        script->varTable[0] = 1;
        gPlayerData.quizzesCorrect++;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_CreateStage)) {
    QuizmoStageFXData* stageData;

    if (isInitialCall) {
        N(Quizmo_StageEffect) = fx_quizmo_stage(0,
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_X),
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Y),
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Z));
        N(Quizmo_AudienceEffect) = fx_quizmo_audience(0,
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_X),
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Y),
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Z));
        N(Quizmo_VannaTEffect) = fx_quizmo_assistant(0,
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_X),
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Y),
            evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Z),
            1.0f, 0);

        stageData = N(Quizmo_StageEffect)->data.quizmoStage;
        stageData->microphoneRaiseAmt = 0;
        stageData->leftWallRaiseAmt = 0;
        stageData->rightWallRaiseAmt = 0;
        stageData->podiumRaiseAmt = 0;
        stageData->rearWallRaiseAmt = 0;
    }

    stageData = N(Quizmo_StageEffect)->data.quizmoStage;

    stageData->leftWallRaiseAmt += 10;
    stageData->podiumRaiseAmt += 10;
    stageData->rightWallRaiseAmt += 10;
    stageData->microphoneRaiseAmt += 10;
    stageData->rearWallRaiseAmt += 10;
    if (stageData->microphoneRaiseAmt >= 255) {
        stageData->microphoneRaiseAmt = 255;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(Quizmo_DestroyEffects)) {
    QuizmoStageFXData* stageData;

    if (isInitialCall) {
        N(Quizmo_AudienceEffect)->flags |= FX_INSTANCE_FLAG_DISMISS;
        N(Quizmo_VannaTEffect)->flags |= FX_INSTANCE_FLAG_DISMISS;
    }

    stageData = N(Quizmo_StageEffect)->data.quizmoStage;
    stageData->microphoneRaiseAmt -= 10;
    stageData->leftWallRaiseAmt -= 10;
    stageData->rightWallRaiseAmt -= 10;
    stageData->podiumRaiseAmt -= 10;
    stageData->rearWallRaiseAmt -= 10;

    if (stageData->microphoneRaiseAmt <= 0) {
        stageData->microphoneRaiseAmt = 0;
        remove_effect(N(Quizmo_StageEffect));
        free_worker(N(Quizmo_Worker));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(Quizmo_SetStageLightsDelay)) {
    N(Quizmo_StageEffect)->data.quizmoStage->lightScrollDelay = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_UnkStageEffectMode)) {
    s32 var = evt_get_variable(script, *script->ptrReadPos);
    QuizmoStageFXData* stageData = N(Quizmo_StageEffect)->data.quizmoStage;

    switch (var) {
        case 0:
            stageData->unkEffectMode = 0xC0;
            break;
        case 1:
            stageData->unkEffectMode = 0x80;
            break;
        case 2:
            stageData->unkEffectMode = 0x40;
            break;
        default:
            stageData->unkEffectMode = 0;
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_SetVannaAnim_Idle)) {
    N(Quizmo_VannaTEffect)->data.quizmoAssistant->anim = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_SetVannaAnim_Clap)) {
    N(Quizmo_VannaTEffect)->data.quizmoAssistant->anim = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_SetVannaAnim_Wave)) {
    N(Quizmo_VannaTEffect)->data.quizmoAssistant->anim = 2;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_ShouldQuizmoLeave)) {
    evt_set_variable(script, LVar0, gGameStatusPtr->debugQuizmo);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_SetCamVfov)) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_GetCamVfov)) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, Float_TO_FIXED(gCameras[cameraID].vfov));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_AddViewRelativeOffset)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    Bytecode ourVarX = *args++;
    Bytecode outVarZ = *args++;

    s32 cameraYaw = gCameras[gCurrentCameraID].curYaw;
    s32 outX = evt_get_variable(script, QUIZ_ARRAY_ORIGIN_X) - (z * cos_deg(cameraYaw));
    s32 outZ = evt_get_variable(script, QUIZ_ARRAY_ORIGIN_Z) - (z * sin_deg(cameraYaw));

    outX -= x;
    outZ -= y;

    evt_set_variable(script, ourVarX, outX);
    evt_set_variable(script, outVarZ, outZ);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_SpinPlayer)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 60;
    }

    playerStatus->targetYaw += 30.0f;
    if (playerStatus->targetYaw >= 360.0f) {
        playerStatus->targetYaw -= 360.0f;
    }

    script->functionTemp[0]--;

    if (script->functionTemp[0] < 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(Quizmo_SpinPartner)) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);

    if (isInitialCall) {
        script->functionTemp[0] = 60;
    }

    partner->yaw += 30.0f;
    if (partner->yaw >= 360.0f) {
        partner->yaw -= 360.0f;
    }

    script->functionTemp[0]--;

    if (script->functionTemp[0] < 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(Quizmo_UpdatePartnerPosition)) {
    Npc* npc = get_npc_unsafe(NPC_PARTNER);
    f32* x = (f32*) &script->functionTemp[1];
    f32* y = (f32*) &script->functionTemp[2];
    f32* z = (f32*) &script->functionTemp[3];

    if (isInitialCall) {
        *x = evt_get_float_variable(script, LVar0) / 60.0f;
        *y = evt_get_float_variable(script, LVar5) / 60.0f;
        *z = evt_get_float_variable(script, LVar1) / 60.0f;
        script->functionTemp[0] = 60;
    }

    npc->pos.x += *x;
    npc->pos.y += *y;
    npc->pos.z += *z;
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

void N(Quizmo_CreateReactionEffect)(void) {
    s32 result = evt_get_variable(NULL, N(Quizmo_ScriptArray[QUIZ_ARRAY_INDEX_ANSWER_RESULT]));

    if (result == 1) {
        fx_quizmo_answer(0, 0, 0, 0);
    } else if (result == 2) {
        fx_quizmo_answer(1, 0, 0, 0);
    }
}

API_CALLABLE(N(Quizmo_CreateWorker)) {
    N(Quizmo_Worker) = create_worker_frontUI(NULL, N(Quizmo_CreateReactionEffect));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Quizmo_Exit) = {
    Call(N(Quizmo_ShouldQuizmoLeave))
    IfLe(LVar0, 1)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 300)
        Call(SetNpcJumpscale, NPC_SELF, 1)
        Call(SetNpcAnimation, NPC_SELF, ANIM_ChuckQuizmo_Vanish)
        Wait(40)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_Quizmo_SetQuizCamera) = {
    Call(N(Quizmo_GetCamVfov), 0, QUIZ_ARRAY_SAVED_FOV)
    Call(N(Quizmo_SetCamVfov), 0, 25) //TODO
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, 0, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    Call(GetCamType, 0, LVar1, LVar2)
    Call(SetCamType, 0, LVar1, 0)
    Call(GetCamDistance, 0, LVar0)
    IfGt(LVar0, 0)
        SetF(LVar0, 370)
    Else
        SetF(LVar0, -370)
    EndIf
    Call(SetCamDistance, 0, LVar0)
    Call(GetCamPitch, 0, LVar0, LVar1)
    SetF(LVar0, Float(13.0))
    SetF(LVar1, Float(-10.0))
    Call(SetCamPitch, 0, LVar0, LVar1)
    Call(PanToTarget, 0, 0, 1)
    Call(SetCamLeadPlayer, 0, 0)
    Return
    End
};

EvtScript N(EVS_Quizmo_OtherCamScript) = {
    Call(GetNpcPos, CHUCK_QUIZMO_NPC_ID, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    Call(SetPanTarget, 0, LVar0, LVar1, LVar2)
    Call(GetCamDistance, 0, LVar0)
    IfGt(LVar0, 0)
        SetF(LVar0, 17)
    Else
        SetF(LVar0, -17)
    EndIf
    Call(SetCamDistance, 0, LVar0)
    Call(SetCamSpeed, 0, Float(90.0))
    Call(WaitForCam, 0, Float(1.0))
    Call(SetCamSpeed, 0, 1)
    Return
    End
};

EvtScript N(EVS_Quizmo_ResetCamera) = {
    Call(N(Quizmo_SetCamVfov), 0, QUIZ_ARRAY_SAVED_FOV)
    Call(PanToTarget, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_Quizmo_MovePlayerToPodium) = {
    Wait(20)
    Call(N(Quizmo_AddViewRelativeOffset), QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 83, LVar0, LVar1)
    Thread
        SetF(LVar2, 0)
        Loop(60)
            SetF(LVar3, LVar0)
            SetF(LVar4, LVar1)
            MulF(LVar3, LVar2)
            MulF(LVar4, LVar2)
            DivF(LVar3, 60)
            DivF(LVar4, 60)
            AddF(LVar3, QUIZ_ARRAY_ORIGIN_X)
            AddF(LVar4, QUIZ_ARRAY_ORIGIN_Z)
            Call(SetPlayerPos, LVar3, QUIZ_ARRAY_ORIGIN_Y, LVar4)
            AddF(LVar2, 1)
            Wait(1)
        EndLoop
        SetF(LVar3, LVar0)
        SetF(LVar4, LVar1)
        AddF(LVar3, QUIZ_ARRAY_ORIGIN_X)
        AddF(LVar4, QUIZ_ARRAY_ORIGIN_Z)
        Call(SetPlayerPos, LVar3, QUIZ_ARRAY_ORIGIN_Y, LVar4)
    EndThread
    Call(N(Quizmo_SpinPlayer))
    Call(FacePlayerTowardPoint, QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_Quizmo_MovePartnerToPodium) = {
    Call(GetNpcPos, NPC_PARTNER, LVarA, LVarB, LVarC)
    Call(N(Quizmo_AddViewRelativeOffset), LVarA, LVarC, 108, LVar0, LVar1)
    SetF(LVar5, QUIZ_ARRAY_ORIGIN_Y)
    SubF(LVar5, LVarB)
    Thread
        Call(N(Quizmo_UpdatePartnerPosition))
        SetF(LVar3, LVar0)
        SetF(LVar4, LVar1)
        SetF(LVar6, LVar5)
        AddF(LVar3, LVarA)
        AddF(LVar4, LVarC)
        AddF(LVar6, LVarB)
        Call(SetNpcPos, NPC_PARTNER, LVar3, LVar6, LVar4)
    EndThread
    Call(N(Quizmo_SpinPartner))
    Call(NpcFacePlayer, NPC_PARTNER, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Return
    End
};

EvtScript N(EVS_Quizmo_MoveQuizmoToMicrophone) = {
    Call(GetNpcPos, CHUCK_QUIZMO_NPC_ID, LVarA, LVarB, LVarC)
    Call(N(Quizmo_AddViewRelativeOffset), LVarA, LVarC, -70, LVar0, LVar1)
    Thread
        SetF(LVar2, 0)
        Loop(60)
            SetF(LVar3, LVar0)
            SetF(LVar4, LVar1)
            MulF(LVar3, LVar2)
            MulF(LVar4, LVar2)
            DivF(LVar3, 60)
            DivF(LVar4, 60)
            AddF(LVar3, LVarA)
            AddF(LVar4, LVarC)
            Call(SetNpcPos, CHUCK_QUIZMO_NPC_ID, LVar3, QUIZ_ARRAY_ORIGIN_Y, LVar4)
            AddF(LVar2, 1)
            Wait(1)
        EndLoop
    EndThread
    Wait(60)
    Call(NpcFacePlayer, CHUCK_QUIZMO_NPC_ID, 0)
    Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_Idle)
    Return
    End
};

EvtScript N(EVS_Quizmo_SetCharacterPositons) = {
    Exec(N(EVS_Quizmo_MovePlayerToPodium))
    Exec(N(EVS_Quizmo_MovePartnerToPodium))
    ExecWait(N(EVS_Quizmo_MoveQuizmoToMicrophone))
    Return
    End
};

EvtScript N(EVS_Quizmo_PlayerThinking) = {
    Loop(0)
        Call(SetPlayerAnimation, ANIM_Mario1_Question)
        Wait(20)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Quizmo_PlayerHitBuzzer) = {
    Call(SetPlayerAnimation, ANIM_Mario1_Throw)
    Wait(15)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_Quizmo_PlayerReaction_RightAnswer) = {
    Loop(0)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
        Wait(2)
        Call(SetPlayerAnimation, ANIM_Mario1_Jump)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 3)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Fall)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -3)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Land)
        Wait(2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
        Wait(2)
        Call(SetPlayerAnimation, ANIM_Mario1_Jump)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 3)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Fall)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -3)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Land)
        Wait(2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
        Wait(2)
        Call(SetPlayerAnimation, ANIM_Mario1_Jump)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 3)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Fall)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, 0)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Add(LVar1, -3)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_Land)
        Wait(2)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerPos, LVar0, QUIZ_ARRAY_ORIGIN_Y, LVar2)
    Wait(1)
    Return
    End
};

EvtScript N(EVS_Quizmo_PlayerReaction_WrongAnswer) = {
    Call(SetPlayerAnimation, ANIM_Mario1_VacantStare)
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Quizmo_ReturnPlayerToOriginalPos) = {
    Thread
        Call(N(Quizmo_AddViewRelativeOffset), QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 25, LVar0, LVar1)
        SetF(LVar2, QUIZ_ARRAY_ORIGIN_X)
        AddF(LVar2, LVar0)
        SetF(LVar3, QUIZ_ARRAY_ORIGIN_Z)
        AddF(LVar3, LVar1)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(NpcMoveTo, NPC_PARTNER, LVar2, LVar3, 40)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EndThread
    Call(PlayerMoveTo, QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 40)
    Return
    End
};

EvtScript N(EVS_Quizmo_RightAnswer) = {
    ExecGetTID(N(EVS_Quizmo_PlayerReaction_RightAnswer), LVar1)
    Wait(60)
    KillThread(LVar1)
    Loop(5)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(2)
    EndLoop
    Wait(20)
    ExecWait(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    Return
    End
};

EvtScript N(EVS_Quizmo_WrongAnswer) = {
    ExecGetTID(N(EVS_Quizmo_PlayerReaction_WrongAnswer), LVar1)
    Wait(60)
    Loop(5)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, -1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(2)
    EndLoop
    Wait(20)
    KillThread(LVar1)
    ExecWait(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    Return
    End
};

EvtScript N(EVS_Quizmo_QuizMain) = {
    IfGt(GB_CompletedQuizzes, 63)
        Set(LVar0, 0)
        Return
    EndIf
    Call(GetPlayerPos, QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Y, QUIZ_ARRAY_ORIGIN_Z)
    Call(NpcFacePlayer, NPC_SELF, 16)
    IfEq(GB_CompletedQuizzes, 63)
        Call(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000A)
    Else
        IfEq(GF_Met_ChuckQuizmo, 1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_0009)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_0008)
            Set(GF_Met_ChuckQuizmo, 1)
        EndIf
    EndIf
    Call(ShowChoice, MSG_Choice_000D)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, -1, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000C)
        ExecWait(N(EVS_Quizmo_Exit))
        Set(LVar0, 0)
        Return
    EndIf
    Set(GF_Quizmo_TakingQuiz, 1)
    Call(N(Quizmo_HideEntities))
    Call(N(Quizmo_HideWorld))
    Exec(N(EVS_Quizmo_SetQuizCamera))
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    ExecGetTID(N(EVS_Quizmo_SetCharacterPositons), LVar1)
    Call(ContinueSpeech, -1, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000B)
    Call(PlaySound, SOUND_LRAW_AUDIENCE_MURMUR)
    Loop(0)
        IsThreadRunning(LVar1, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(N(Quizmo_CreateStage))
    Loop(5)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(2)
    EndLoop
    Set(LVar0, MSG_QuizQuestion_01)
    Add(LVar0, GB_CompletedQuizzes)
    Call(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_OpenHat, ANIM_ChuckQuizmo_CloseHat, 0, LVar0)
    Call(SetPlayerAnimation, ANIM_Mario1_Question)
    Set(LVar0, MSG_QuizChoice_01)
    Add(LVar0, GB_CompletedQuizzes)
    Call(PlaySound, SOUND_LRAW_QUIZ_TICKING)
    Call(ShowChoice, LVar0)
    KillThread(LVar1)
    Call(StopSound, SOUND_LRAW_QUIZ_TICKING)
    Exec(N(EVS_Quizmo_PlayerHitBuzzer))
    Wait(15)
    Call(PlaySound, SOUND_QUIZ_BUZZER)
    Call(N(Quizmo_UnkStageEffectMode), LVar0)
    Set(QUIZ_ARRAY_ANSWER_RESULT, 0)
    Call(N(Quizmo_CreateWorker))
    Wait(40)
    Call(N(Quizmo_UpdateRecords))
    Thread
        Wait(110)
        Call(CloseChoice)
        Set(QUIZ_ARRAY_ANSWER_RESULT, 0)
    EndThread
    IfEq(LVar0, 1)
        Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenCorrect)
        Set(QUIZ_ARRAY_ANSWER_RESULT, 1)
        Thread
            Call(N(Quizmo_SetStageLightsDelay), 1)
            Wait(6)
            Wait(6)
            Wait(6)
            Call(N(Quizmo_SetStageLightsDelay), 2)
        EndThread
        Thread
            Call(PlaySound, SOUND_APPROVE)
            Wait(6)
            Call(PlaySound, SOUND_APPROVE)
            Wait(6)
            Call(PlaySound, SOUND_APPROVE)
            Wait(6)
            Call(PlaySound, SOUND_APPROVE)
        EndThread
        Call(PlaySound, SOUND_AUDIENCE_CHEER)
        Call(N(Quizmo_SetVannaAnim_Clap))
        Thread
            Wait(15)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 50)
            Call(N(Quizmo_AddViewRelativeOffset), 0, 0, 83, LVar0, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_CONFETTI, 4, LVar0, LVar1, LVar2, 1, 60)
            Wait(15)
            Add(LVar1, -3)
            Call(N(Quizmo_AddViewRelativeOffset), 0, 0, 58, LVar0, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_CONFETTI, 4, LVar0, LVar1, LVar2, 1, 60)
            Wait(15)
            Add(LVar1, 30)
            Call(N(Quizmo_AddViewRelativeOffset), 0, 0, 93, LVar0, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_CONFETTI, 4, LVar0, LVar1, LVar2, 1, 60)
            Wait(15)
        EndThread
        Wait(20)
        ExecGetTID(N(EVS_Quizmo_RightAnswer), LVar1)
        Add(GB_CompletedQuizzes, 1)
        IfGt(GB_CompletedQuizzes, 63)
            Call(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_0010)
            Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_CloseHat)
            Loop(0)
                IsThreadRunning(LVar1, LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenHat)
            Set(LVar0, ITEM_STAR_PIECE)
            Set(LVar1, 3)
            ExecWait(N(GiveItemReward))
            Call(AddStarPieces, 1)
            Call(N(Quizmo_SetStageLightsDelay), 15)
            Call(N(Quizmo_SetVannaAnim_Idle))
            Call(SetMessageValue, GB_CompletedQuizzes, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_0011)
        Else
            Call(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_000E)
            Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_CloseHat)
            Loop(0)
                IsThreadRunning(LVar1, LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenHat)
            Set(LVar0, ITEM_STAR_PIECE)
            Set(LVar1, 1)
            ExecWait(N(GiveItemReward))
            Call(AddStarPieces, 1)
            Call(N(Quizmo_SetStageLightsDelay), 15)
            Call(N(Quizmo_SetVannaAnim_Idle))
            Call(SetMessageValue, GB_CompletedQuizzes, 0)
            IfEq(GB_CompletedQuizzes, 1)
                Call(SetMessageText, Ref(MessageSingular), 1)
            Else
#if VERSION_PAL
                Call(GetLanguage, LVar0)
                IfEq(LVar0, LANGUAGE_DE)
                    Call(SetMessageText, Ref(MessagePlural_de), 1)
                Else
                    Call(SetMessageText, Ref(MessagePlural), 1)
                EndIf
#else
                Call(SetMessageText, Ref(MessagePlural), 1)
#endif
            EndIf
            Call(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000F)
        EndIf
        Set(LVar0, 1)
    Else
        Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenWrong)
        Set(QUIZ_ARRAY_ANSWER_RESULT, 2)
        Call(PlaySound, SOUND_MENU_ERROR)
        Call(PlaySound, SOUND_AUDIENCE_BOO)
        ExecGetTID(N(EVS_Quizmo_WrongAnswer), LVar1)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        PlayEffect(EFFECT_WINDY_LEAVES, 0, LVar2, LVar3, LVar4)
        Call(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_000D)
        Call(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_CloseWrong)
        Loop(0)
            IsThreadRunning(LVar1, LVar0)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Set(LVar0, 0)
    EndIf
    Call(N(Quizmo_UnkStageEffectMode), -1)
    Call(EnablePartnerAI)
    Thread
        Wait(30)
        Call(PlaySound, SOUND_QUIZMO_VANISH)
    EndThread
    Thread
        Wait(45)
        Call(StopSound, SOUND_LRAW_AUDIENCE_MURMUR)
    EndThread
    Call(N(Quizmo_SetVannaAnim_Wave))
    Call(N(Quizmo_DestroyEffects))
    ExecWait(N(EVS_Quizmo_Exit))
    Exec(N(EVS_Quizmo_ResetCamera))
    Call(N(Quizmo_FadeInWorld))
    Call(N(Quizmo_ShowEntities))
    Set(GF_Quizmo_TakingQuiz, 0)
    Return
    End
};

EvtScript N(EVS_Quizmo_NPC_OtherAI) = {
    Call(N(Quizmo_ShouldAppear))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_NO_SPRITE, FALSE)
    Call(SetNpcSprite, -1, ANIM_ChuckQuizmo_Idle)
    Call(N(Quizmo_RenderInit))
    Return
    End
};

EvtScript N(EVS_Quizmo_NPC_Interact) = {
    UseArray(Ref(N(Quizmo_ScriptArray)))
    Set(GF_Quizmo_ChangedLocation, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerFlagBits, PS_FLAG_MOVEMENT_LOCKED, 1)
    ExecWait(N(EVS_Quizmo_QuizMain))
    Call(DisablePlayerPhysics, FALSE)
    Call(SetPlayerFlagBits, PS_FLAG_MOVEMENT_LOCKED, 0)
    Return
    End
};

EvtScript N(EVS_Quizmo_NPC_Aux) = {
    Call(N(Quizmo_NPC_Aux_Impl))
    Return
    End
};

MobileAISettings N(Quizmo_MobileAISettings) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_Quizmo_Npc_AI) = {
    Call(BasicAI_Main, Ref(N(Quizmo_MobileAISettings)))
    Return
    End
};

// primary quizmo NpcSettings
NpcSettings N(NpcSettings_ChuckQuizmo) = {
    .defaultAnim = ANIM_ChuckQuizmo_Idle,
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .level = ACTOR_LEVEL_NONE,
};

// alternate (unused?) variant of quizmo with AI and ENEMY_FLAG_IGNORE_WORLD_COLLISION unset
NpcSettings N(Quizmo_AltNpcSettings) = {
    .defaultAnim = ANIM_ChuckQuizmo_Idle,
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .ai = &N(EVS_Quizmo_Npc_AI),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = 16,
};
