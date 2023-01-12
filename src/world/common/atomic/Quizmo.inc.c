#include "common.h"
#include "effects.h"
#include "model.h"

// TODO, can we remove this once all data disasm'ed?
extern QuizRequirement N(Quizmo_Requirements)[];
extern u8 N(Quizmo_Answers)[64];
extern s32** N(varStash);

void N(Quizmo_NPC_OnRender)(Npc* npc);

ApiStatus N(StashVars)(Evt* script, s32 isInitialCall) {
    //static s32** varTable = NULL;
    s32 i;

    if (N(varStash) == NULL) {
        N(varStash) = heap_malloc(sizeof(script->varTable));

        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            N(varStash)[i] = script->varTablePtr[i];
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
            script->varTablePtr[i] = N(varStash)[i];
        }

        heap_free(N(varStash));
        N(varStash) = NULL;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(GetItemName)(Evt* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;
    s32 itemID = evt_get_variable(script, args);

    evt_set_variable(script, args, LOOKUP_ITEM(itemID).nameMsg);
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_HideEntities)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_ShowEntities)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_ShouldAppear)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_RenderInit)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->onRender = N(Quizmo_NPC_OnRender);
    npc->blur.quizmo = heap_malloc(sizeof(*npc->blur.quizmo));
    npc->blur.quizmo->flags = 0;

    return ApiStatus_DONE1;
}

ApiStatus N(Quizmo_NPC_Aux_Impl)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_HideWorld)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        s32 i;

        mdl_set_all_fog_mode(1);
        *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != CHUCK_QUIZMO_NPC_ID) {
                npc->flags |= NPC_FLAG_NO_DROPS; // odd
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

ApiStatus N(Quizmo_FadeInWorld)(Evt* script, s32 isInitialCall) {
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
        mdl_set_all_fog_mode(0);
        *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_0;

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != NULL && npc->flags != 0) {
                if (npc->npcID != NPC_PARTNER && npc->npcID != CHUCK_QUIZMO_NPC_ID) {
                    npc->flags &= ~NPC_FLAG_NO_DROPS;
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

ApiStatus N(Quizmo_UpdateRecords)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_CreateStage)(Evt* script, s32 isInitialCall) {
    QuizmoStageFXData* stageData;

    if (isInitialCall) {
        N(Quizmo_StageEffect) = fx_quizmo_stage(0,
            evt_get_variable(script, ArrayVar(1)),
            evt_get_variable(script, ArrayVar(2)),
            evt_get_variable(script, ArrayVar(3)));
        N(Quizmo_AudienceEffect) = fx_quizmo_audience(0,
            evt_get_variable(script, ArrayVar(1)),
            evt_get_variable(script, ArrayVar(2)),
            evt_get_variable(script, ArrayVar(3)));
        N(Quizmo_VannaTEffect) = fx_quizmo_assistant(0,
            evt_get_variable(script, ArrayVar(1)),
            evt_get_variable(script, ArrayVar(2)),
            evt_get_variable(script, ArrayVar(3)),
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

ApiStatus N(Quizmo_DestroyEffects)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_SetStageLightsDelay)(Evt* script, s32 isInitialCall) {
    N(Quizmo_StageEffect)->data.quizmoStage->lightScrollDelay = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_UnkStageEffectMode)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_SetVannaAnim_Idle)(Evt* script, s32 isInitialCall) {
    N(Quizmo_VannaTEffect)->data.quizmoAssistant->anim = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_SetVannaAnim_Clap)(Evt* script, s32 isInitialCall) {
    N(Quizmo_VannaTEffect)->data.quizmoAssistant->anim = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_SetVannaAnim_Wave)(Evt* script, s32 isInitialCall) {
    N(Quizmo_VannaTEffect)->data.quizmoAssistant->anim = 2;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_ShouldQuizmoLeave)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, LVar0, gGameStatusPtr->debugQuizmo);
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_SetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_GetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, EVT_FLOAT_TO_FIXED(gCameras[cameraID].vfov));
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_AddViewRelativeOffset)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    Bytecode ourVarX = *args++;
    Bytecode outVarZ = *args++;

    s32 cameraYaw = gCameras[gCurrentCameraID].currentYaw;
    s32 outX = evt_get_variable(script, ArrayVar(1)) - (z * cos_deg(cameraYaw));
    s32 outZ = evt_get_variable(script, ArrayVar(3)) - (z * sin_deg(cameraYaw));

    outX -= x;
    outZ -= y;

    evt_set_variable(script, ourVarX, outX);
    evt_set_variable(script, outVarZ, outZ);

    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_SpinPlayer)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_SpinPartner)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(Quizmo_UpdatePartnerPosition)(Evt* script, s32 isInitialCall) {
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
    s32 result = evt_get_variable(NULL, N(Quizmo_AnswerResult));

    if (result == 1) {
        fx_quizmo_answer(0, 0, 0, 0);
    } else if (result == 2) {
        fx_quizmo_answer(1, 0, 0, 0);
    }
}

ApiStatus N(Quizmo_CreateWorker)(Evt* script, s32 isInitialCall) {
    N(Quizmo_Worker) = create_worker_frontUI(NULL, N(Quizmo_CreateReactionEffect));
    return ApiStatus_DONE2;
}
