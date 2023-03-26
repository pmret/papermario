#include "common.h"
#include "message_ids.h"
#include "effects.h"
#include "model.h"
#include "sprite/npc/ChuckQuizmo.h"

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
        clamp_angle(-camera->currentYaw);
    }
}

API_CALLABLE(N(Quizmo_HideWorld)) {
    if (isInitialCall) {
        s32 i;

        mdl_set_all_fog_mode(FOG_MODE_1);
        *gBackgroundFogModePtr = FOG_MODE_1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != CHUCK_QUIZMO_NPC_ID) {
                npc->flags |= NPC_FLAG_HIDING;
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = get_item_entity(i);

            if (itemEntity != NULL && itemEntity->flags & ITEM_ENTITY_FLAG_10) {
                itemEntity->flags |= ITEM_ENTITY_FLAG_8000000;
            }
        }

        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 8;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);

    if (script->functionTemp[0] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(Quizmo_FadeInWorld)) {
    s32 i;

    if (isInitialCall) {
        set_background_color_blend(0, 0, 0, 255);
        script->functionTemp[0] = 255;
        script->functionTemp[1] = 0;
    }

    script->functionTemp[0] -= 8;
    if (script->functionTemp[0] < 0) {
        script->functionTemp[0] = 0;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    if (script->functionTemp[0] == 0 && script->functionTemp[1] == 0) {
        script->functionTemp[1] = 1;
    } else if (script->functionTemp[1] == 1) {
        mdl_set_all_fog_mode(FOG_MODE_0);
        *gBackgroundFogModePtr = FOG_MODE_0;

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
                entity->flags &= ~ITEM_ENTITY_FLAG_8000000;
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
        N(Quizmo_AudienceEffect)->flags |= EFFECT_INSTANCE_FLAG_10;
        N(Quizmo_VannaTEffect)->flags |= EFFECT_INSTANCE_FLAG_10;
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

    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(gCameras[cameraID].vfov));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Quizmo_AddViewRelativeOffset)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    Bytecode ourVarX = *args++;
    Bytecode outVarZ = *args++;

    s32 cameraYaw = gCameras[gCurrentCameraID].currentYaw;
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
    EVT_CALL(N(Quizmo_ShouldQuizmoLeave))
    EVT_IF_LE(LVar0, 1)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 300)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ChuckQuizmo_Vanish)
        EVT_WAIT(40)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetQuizCamera) = {
    EVT_CALL(N(Quizmo_GetCamVfov), 0, QUIZ_ARRAY_SAVED_FOV)
    EVT_CALL(N(Quizmo_SetCamVfov), 0, 25) //TODO
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetCamType, 0, LVar1, LVar2)
    EVT_CALL(SetCamType, 0, LVar1, 0)
    EVT_CALL(GetCamDistance, 0, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, 370)
    EVT_ELSE
        EVT_SETF(LVar0, -370)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, LVar0)
    EVT_CALL(GetCamPitch, 0, LVar0, LVar1)
    EVT_SETF(LVar0, EVT_FLOAT(13.0))
    EVT_SETF(LVar1, EVT_FLOAT(-10.0))
    EVT_CALL(SetCamPitch, 0, LVar0, LVar1)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_OtherCamScript) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetCamDistance, 0, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, 17)
    EVT_ELSE
        EVT_SETF(LVar0, -17)
    EVT_END_IF
    EVT_CALL(SetCamDistance, 0, LVar0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ResetCamera) = {
    EVT_CALL(N(Quizmo_SetCamVfov), 0, QUIZ_ARRAY_SAVED_FOV)
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePlayerToPodium) = {
    EVT_WAIT(20)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 83, LVar0, LVar1)
    EVT_THREAD
        EVT_SETF(LVar2, 0)
        EVT_LOOP(60)
            EVT_SETF(LVar3, LVar0)
            EVT_SETF(LVar4, LVar1)
            EVT_MULF(LVar3, LVar2)
            EVT_MULF(LVar4, LVar2)
            EVT_DIVF(LVar3, 60)
            EVT_DIVF(LVar4, 60)
            EVT_ADDF(LVar3, QUIZ_ARRAY_ORIGIN_X)
            EVT_ADDF(LVar4, QUIZ_ARRAY_ORIGIN_Z)
            EVT_CALL(SetPlayerPos, LVar3, QUIZ_ARRAY_ORIGIN_Y, LVar4)
            EVT_ADDF(LVar2, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SETF(LVar3, LVar0)
        EVT_SETF(LVar4, LVar1)
        EVT_ADDF(LVar3, QUIZ_ARRAY_ORIGIN_X)
        EVT_ADDF(LVar4, QUIZ_ARRAY_ORIGIN_Z)
        EVT_CALL(SetPlayerPos, LVar3, QUIZ_ARRAY_ORIGIN_Y, LVar4)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPlayer))
    EVT_CALL(FacePlayerTowardPoint, QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MovePartnerToPodium) = {
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVarA, LVarB, LVarC)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), LVarA, LVarC, 108, LVar0, LVar1)
    EVT_SETF(LVar5, QUIZ_ARRAY_ORIGIN_Y)
    EVT_SUBF(LVar5, LVarB)
    EVT_THREAD
        EVT_CALL(N(Quizmo_UpdatePartnerPosition))
        EVT_SETF(LVar3, LVar0)
        EVT_SETF(LVar4, LVar1)
        EVT_SETF(LVar6, LVar5)
        EVT_ADDF(LVar3, LVarA)
        EVT_ADDF(LVar4, LVarC)
        EVT_ADDF(LVar6, LVarB)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar3, LVar6, LVar4)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SpinPartner))
    EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_MoveQuizmoToMicrophone) = {
    EVT_CALL(GetNpcPos, CHUCK_QUIZMO_NPC_ID, LVarA, LVarB, LVarC)
    EVT_CALL(N(Quizmo_AddViewRelativeOffset), LVarA, LVarC, -70, LVar0, LVar1)
    EVT_THREAD
        EVT_SETF(LVar2, 0)
        EVT_LOOP(60)
            EVT_SETF(LVar3, LVar0)
            EVT_SETF(LVar4, LVar1)
            EVT_MULF(LVar3, LVar2)
            EVT_MULF(LVar4, LVar2)
            EVT_DIVF(LVar3, 60)
            EVT_DIVF(LVar4, 60)
            EVT_ADDF(LVar3, LVarA)
            EVT_ADDF(LVar4, LVarC)
            EVT_CALL(SetNpcPos, CHUCK_QUIZMO_NPC_ID, LVar3, QUIZ_ARRAY_ORIGIN_Y, LVar4)
            EVT_ADDF(LVar2, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(NpcFacePlayer, CHUCK_QUIZMO_NPC_ID, 0)
    EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_SetCharacterPositons) = {
    EVT_EXEC(N(EVS_Quizmo_MovePlayerToPodium))
    EVT_EXEC(N(EVS_Quizmo_MovePartnerToPodium))
    EVT_EXEC_WAIT(N(EVS_Quizmo_MoveQuizmoToMicrophone))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerThinking) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Question)
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerHitBuzzer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Throw)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_RightAnswer) = {
    EVT_LOOP(0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fall)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Land)
        EVT_WAIT(2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fall)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Land)
        EVT_WAIT(2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fall)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, 0)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -2)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar1, -3)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Land)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerPos, LVar0, QUIZ_ARRAY_ORIGIN_Y, LVar2)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_PlayerReaction_WrongAnswer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_VacantStare)
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_ReturnPlayerToOriginalPos) = {
    EVT_THREAD
        EVT_CALL(N(Quizmo_AddViewRelativeOffset), QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 25, LVar0, LVar1)
        EVT_SETF(LVar2, QUIZ_ARRAY_ORIGIN_X)
        EVT_ADDF(LVar2, LVar0)
        EVT_SETF(LVar3, QUIZ_ARRAY_ORIGIN_Z)
        EVT_ADDF(LVar3, LVar1)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar2, LVar3, 40)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Z, 40)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_RightAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_RightAnswer), LVar1)
    EVT_WAIT(60)
    EVT_KILL_THREAD(LVar1)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_WrongAnswer) = {
    EVT_EXEC_GET_TID(N(EVS_Quizmo_PlayerReaction_WrongAnswer), LVar1)
    EVT_WAIT(60)
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, -1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_KILL_THREAD(LVar1)
    EVT_EXEC_WAIT(N(EVS_Quizmo_ReturnPlayerToOriginalPos))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_QuizMain) = {
    EVT_IF_GT(GB_CompletedQuizzes, 63)
        EVT_SET(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, QUIZ_ARRAY_ORIGIN_X, QUIZ_ARRAY_ORIGIN_Y, QUIZ_ARRAY_ORIGIN_Z)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 16)
    EVT_IF_EQ(GB_CompletedQuizzes, 63)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000A)
    EVT_ELSE
        EVT_IF_EQ(GF_Met_ChuckQuizmo, 1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_0009)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_0008)
            EVT_SET(GF_Met_ChuckQuizmo, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, -1, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000C)
        EVT_EXEC_WAIT(N(EVS_Quizmo_Exit))
        EVT_SET(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_Quizmo_TakingQuiz, 1)
    EVT_CALL(N(Quizmo_HideEntities))
    EVT_CALL(N(Quizmo_HideWorld))
    EVT_EXEC(N(EVS_Quizmo_SetQuizCamera))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, CHUCK_QUIZMO_NPC_ID, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_EXEC_GET_TID(N(EVS_Quizmo_SetCharacterPositons), LVar1)
    EVT_CALL(ContinueSpeech, -1, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000B)
    EVT_CALL(PlaySound, 137)
    EVT_LOOP(0)
        EVT_IS_THREAD_RUNNING(LVar1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(Quizmo_CreateStage))
    EVT_LOOP(5)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_SET(LVar0, MSG_QuizQuestion_01)
    EVT_ADD(LVar0, GB_CompletedQuizzes)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_OpenHat, ANIM_ChuckQuizmo_CloseHat, 0, LVar0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Question)
    EVT_SET(LVar0, MSG_QuizChoice_01)
    EVT_ADD(LVar0, GB_CompletedQuizzes)
    EVT_CALL(PlaySound, 142)
    EVT_CALL(ShowChoice, LVar0)
    EVT_KILL_THREAD(LVar1)
    EVT_CALL(StopSound, 142)
    EVT_EXEC(N(EVS_Quizmo_PlayerHitBuzzer))
    EVT_WAIT(15)
    EVT_CALL(PlaySound, 141)
    EVT_CALL(N(Quizmo_UnkStageEffectMode), LVar0)
    EVT_SET(QUIZ_ARRAY_ANSWER_RESULT, 0)
    EVT_CALL(N(Quizmo_CreateWorker))
    EVT_WAIT(40)
    EVT_CALL(N(Quizmo_UpdateRecords))
    EVT_THREAD
        EVT_WAIT(110)
        EVT_CALL(CloseChoice)
        EVT_SET(QUIZ_ARRAY_ANSWER_RESULT, 0)
    EVT_END_THREAD
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenCorrect)
        EVT_SET(QUIZ_ARRAY_ANSWER_RESULT, 1)
        EVT_THREAD
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 1)
            EVT_WAIT(6)
            EVT_WAIT(6)
            EVT_WAIT(6)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 2)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT(6)
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT(6)
            EVT_CALL(PlaySound, SOUND_21C)
            EVT_WAIT(6)
            EVT_CALL(PlaySound, SOUND_21C)
        EVT_END_THREAD
        EVT_CALL(PlaySound, SOUND_8A)
        EVT_CALL(N(Quizmo_SetVannaAnim_Clap))
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 50)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 83, LVar0, LVar2)
            EVT_CALL(PlayEffect, 0x7, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, LVar0, LVar1, LVar2, 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_ADD(LVar1, -3)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 58, LVar0, LVar2)
            EVT_CALL(PlayEffect, 0x7, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, LVar0, LVar1, LVar2, 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
            EVT_ADD(LVar1, 30)
            EVT_CALL(N(Quizmo_AddViewRelativeOffset), 0, 0, 93, LVar0, LVar2)
            EVT_CALL(PlayEffect, 0x7, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, 0x44, 4, LVar0, LVar1, LVar2, 1, 60, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(15)
        EVT_END_THREAD
        EVT_WAIT(20)
        EVT_EXEC_GET_TID(N(EVS_Quizmo_RightAnswer), LVar1)
        EVT_ADD(GB_CompletedQuizzes, 1)
        EVT_IF_GT(GB_CompletedQuizzes, 63)
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_0010)
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_CloseHat)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(LVar1, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenHat)
            EVT_SET(LVar0, ITEM_STAR_PIECE)
            EVT_SET(LVar1, 3)
            EVT_EXEC_WAIT(N(GiveItemReward))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 15)
            EVT_CALL(N(Quizmo_SetVannaAnim_Idle))
            EVT_CALL(SetMessageValue, GB_CompletedQuizzes, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_0011)
        EVT_ELSE
            EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_000E)
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_CloseHat)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(LVar1, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenHat)
            EVT_SET(LVar0, ITEM_STAR_PIECE)
            EVT_SET(LVar1, 1)
            EVT_EXEC_WAIT(N(GiveItemReward))
            EVT_CALL(AddStarPieces, 1)
            EVT_CALL(N(Quizmo_SetStageLightsDelay), 15)
            EVT_CALL(N(Quizmo_SetVannaAnim_Idle))
            EVT_CALL(SetMessageValue, GB_CompletedQuizzes, 0)
            EVT_IF_EQ(GB_CompletedQuizzes, 1)
                EVT_CALL(SetMessageText, EVT_PTR(MessageSingular), 1)
            EVT_ELSE
#if VERSION_PAL
                EVT_CALL(GetLanguage, LVar0)
                EVT_IF_EQ(LVar0, LANGUAGE_DE)
                    EVT_CALL(SetMessageText, EVT_PTR(MessagePlural_de), 1)
                EVT_ELSE
                    EVT_CALL(SetMessageText, EVT_PTR(MessagePlural), 1)
                EVT_END_IF
#else
                EVT_CALL(SetMessageText, EVT_PTR(MessagePlural), 1)
#endif
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ChuckQuizmo_Talk, ANIM_ChuckQuizmo_Idle, 0, MSG_MGM_000F)
        EVT_END_IF
        EVT_SET(LVar0, 1)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_OpenWrong)
        EVT_SET(QUIZ_ARRAY_ANSWER_RESULT, 2)
        EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_CALL(PlaySound, SOUND_8B)
        EVT_EXEC_GET_TID(N(EVS_Quizmo_WrongAnswer), LVar1)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(PlayEffect, 0x2B, 0, LVar2, LVar3, LVar4, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(ContinueSpeech, -1, -1, -1, 0, MSG_MGM_000D)
        EVT_CALL(SetNpcAnimation, CHUCK_QUIZMO_NPC_ID, ANIM_ChuckQuizmo_CloseWrong)
        EVT_LOOP(0)
            EVT_IS_THREAD_RUNNING(LVar1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_CALL(N(Quizmo_UnkStageEffectMode), -1)
    EVT_CALL(EnablePartnerAI)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(PlaySound, SOUND_8F)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(45)
        EVT_CALL(StopSound, SOUND_89)
    EVT_END_THREAD
    EVT_CALL(N(Quizmo_SetVannaAnim_Wave))
    EVT_CALL(N(Quizmo_DestroyEffects))
    EVT_EXEC_WAIT(N(EVS_Quizmo_Exit))
    EVT_EXEC(N(EVS_Quizmo_ResetCamera))
    EVT_CALL(N(Quizmo_FadeInWorld))
    EVT_CALL(N(Quizmo_ShowEntities))
    EVT_SET(GF_Quizmo_TakingQuiz, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_OtherAI) = {
    EVT_CALL(N(Quizmo_ShouldAppear))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_NO_SPRITE, FALSE)
    EVT_CALL(SetNpcSprite, -1, ANIM_ChuckQuizmo_Idle)
    EVT_CALL(N(Quizmo_RenderInit))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_Interact) = {
    EVT_USE_ARRAY(EVT_PTR(N(Quizmo_ScriptArray)))
    EVT_SET(GF_Quizmo_ChangedLocation, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_MOVEMENT_LOCKED, 1)
    EVT_EXEC_WAIT(N(EVS_Quizmo_QuizMain))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_MOVEMENT_LOCKED, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Quizmo_NPC_Aux) = {
    EVT_CALL(N(Quizmo_NPC_Aux_Impl))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(Quizmo_MobileAISettings) = {
    .moveSpeed = 0.7f,
    .moveTime = 30,
    .waitTime = 20,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_Quizmo_Npc_AI) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(Quizmo_MobileAISettings)))
    EVT_RETURN
    EVT_END
};

// primary quizmo NpcSettings
NpcSettings N(NpcSettings_ChuckQuizmo) = {
    .defaultAnim = ANIM_ChuckQuizmo_Idle,
    .height = 35,
    .radius = 28,
    .otherAI = &N(EVS_Quizmo_NPC_OtherAI),
    .onInteract = &N(EVS_Quizmo_NPC_Interact),
    .aux = &N(EVS_Quizmo_NPC_Aux),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .level = 99,
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .level = 99,
    .actionFlags = 16,
};
