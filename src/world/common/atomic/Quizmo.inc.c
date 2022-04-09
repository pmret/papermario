
#include "common.h"
#include "effects.h"

// TODO, can we remove this once all data disasm'ed?
extern Quizmo_Requirements N(Quizmo_Requirements)[];

extern u8 N(Quizmo_Answers)[64];

ApiStatus N(Set80151310_1)(Evt* script, s32 isInitialCall) {
    D_80151310 = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall) {
    D_80151310 = 0;
    return ApiStatus_DONE2;
}


ApiStatus N(UnkQuizFunc)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    u16 phi_s0 = evt_get_variable(script, EVT_SAVE_FLAG(1768));
    u16 phi_s7 = evt_get_variable(script, EVT_SAVE_FLAG(1769));
    u16 temp_s6 = evt_get_variable(script, EVT_SAVE_VAR(350));
    u16 phi_s5 = evt_get_variable(script, EVT_SAVE_VAR(351));
    s32 var;
    s32 i;

    s32 test2;
    u16 temp_s3 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 sp_10 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 temp_s2 = (enemy->varTable[0] & 0xFF00) >> 8;
    u16 sp_1e = (enemy->varTable[0] & 0xFF) >> 0;
    s32 temp_v0;
    s32 temp_s0_2;

    if (temp_s3 != temp_s6) {
        phi_s7 = 0;
        phi_s0 = 0;
    }

    if (phi_s0 == 0) {
        if (rand_int(100) < 30) {
            phi_s5 = rand_int(temp_s2 - 1);
            temp_s6 = temp_s3;
            evt_set_variable(script, EVT_SAVE_VAR(350), temp_s6);
            evt_set_variable(script, EVT_SAVE_VAR(351), phi_s5);
            phi_s0 = 1;
        }
    }

    evt_set_variable(script, EVT_SAVE_FLAG(1768), phi_s0);
    evt_set_variable(script, EVT_SAVE_FLAG(1769), phi_s7);
    temp_s0_2 = evt_get_variable(NULL, EVT_SAVE_VAR(352));
    temp_v0 = evt_get_variable(NULL, EVT_STORY_PROGRESS);

    for (i = 0; i < 8; i++) {
        if (temp_v0 < (*(N(Quizmo_Requirements) + i)).unk_00) {
            break;
        }
    }

    temp_v0 = temp_s0_2 < (*(N(Quizmo_Requirements) + i)).unk_04;
    test2 = var = temp_v0;

    if ((((sp_10 == temp_s6) && (sp_1e == phi_s5) && (phi_s7 == 0) && test2)) ||
        ((gGameStatusPtr->debugQuizmo != 0) && var)) {
        script->varTable[0] = 1;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

void N(UnkFunc28)(Npc* npc);

ApiStatus N(UnkFunc31)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->onRender = N(UnkFunc28);
    npc->blurBuf = heap_malloc(8);
    *((s32*)npc->blurBuf) = 0;

    return ApiStatus_DONE1;
}

ApiStatus N(GetNpcUnsafeOwner2)(Evt* script, s32 isInitialCall) {
    get_npc_unsafe(script->owner2.npcID);
    return ApiStatus_BLOCK;
}

void N(UnkFunc28)(Npc* npc) {
    Camera* camera = &gCameras[gCurrentCamID];

    if (*((s32*)npc->blurBuf) & 1) {
        clamp_angle(-camera->currentYaw);
    }
}

ApiStatus N(UnkAlphaFunc)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        s32 i;

        mdl_set_all_fog_mode(1);
        D_801512F0[0] = 1;
        set_background_color_blend(0, 0, 0, 0);

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);

            if (npc != NULL && npc->flags != 0 && npc->npcID != NPC_PARTNER && npc->npcID != UNK_ALPHA_FUNC_NPC) {
                npc->flags |= 0x800000;
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* itemEntity = get_item_entity(i);

            if (itemEntity != NULL && itemEntity->flags & ENTITY_FLAGS_SKIP_UPDATE_TRANSFORM_MATRIX) {
                itemEntity->flags |= ENTITY_FLAGS_8000000;
            }
        }

        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 8;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    return (script->functionTemp[0] == 255) * ApiStatus_DONE2;
}

ApiStatus N(UnkFunc29)(Evt* script, s32 isInitialCall) {
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
        *D_801512F0 = 0;

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = get_npc_by_index(i);
            if (npc != NULL && npc->flags != 0) {
                if (npc->npcID != NPC_PARTNER && npc->npcID != UNK_ALPHA_FUNC_NPC) {
                    npc->flags &= ~0x00800000;
                }
            }
        }

        for (i = 0; i < MAX_ITEM_ENTITIES; i++) {
            ItemEntity* entity = get_item_entity(i);
            if (entity != NULL && entity->flags & 0x10) {
                entity->flags &= ~0x8000000;
            }
        }

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(Quizmo_UnkA)(Evt* script, s32 isInitialCall) {
    u16 quizzesAnswered = gPlayerData.quizzesAnswered;

    if (quizzesAnswered < 999) {
        gPlayerData.quizzesAnswered++;
    }

    if (script->varTable[0] == N(Quizmo_Answers)[evt_get_variable(NULL, EVT_SAVE_VAR(352))]) {
        script->varTable[0] = 1;
        gPlayerData.quizzesCorrect++;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_UnkB)(Evt* script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(Quizmo_StageEffect) = fx_quizmo_stage(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)));
        N(Quizmo_AudienceEffect) = fx_quizmo_audience(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)));
        N(Quizmo_VannaTEffect) = fx_quizmo_assistant(0, evt_get_variable(script, EVT_ARRAY(1)), evt_get_variable(script, EVT_ARRAY(2)),
                                      evt_get_variable(script, EVT_ARRAY(3)), 1.0f, 0);

        effectPtr = N(Quizmo_StageEffect)->data;
        effectPtr->unk_18 = 0;
        effectPtr->unk_20 = 0;
        effectPtr->unk_24.s = 0;
        effectPtr->unk_28 = 0;
        effectPtr->unk_1C = 0;
    }

    effectPtr = N(Quizmo_StageEffect)->data;

    effectPtr->unk_20 += 10;
    effectPtr->unk_28 += 10;
    effectPtr->unk_24.s += 10;
    effectPtr->unk_18 += 10;
    effectPtr->unk_1C += 10;
    if (effectPtr->unk_18 >= 255) {
        effectPtr->unk_18 = 255;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(Quizmo_UnkC)(Evt* script, s32 isInitialCall) {
    EffectInstanceDataThing* effectPtr;

    if (isInitialCall) {
        N(Quizmo_AudienceEffect)->flags |= 0x10;
        N(Quizmo_VannaTEffect)->flags |= 0x10;
    }

    effectPtr = N(Quizmo_StageEffect)->data;
    effectPtr->unk_18 -= 10;
    effectPtr->unk_20 -= 10;
    effectPtr->unk_24.s -= 10;
    effectPtr->unk_28 -= 10;
    effectPtr->unk_1C -= 10;

    if (effectPtr->unk_18 <= 0) {
        effectPtr->unk_18 = 0;
        remove_effect(N(Quizmo_StageEffect));
        free_generic_entity(N(Quizmo_Worker));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(Quizmo_UnkD)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_StageEffect)->data)->unk_34 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_UnkE)(Evt* script, s32 isInitialCall) {
    s32 var = evt_get_variable(script, *script->ptrReadPos);
    EffectInstanceDataThing* effectPtr = N(Quizmo_StageEffect)->data;

    switch (var) {
        case 0:
            effectPtr->unk_38 = 0xC0;
            break;
        case 1:
            effectPtr->unk_38 = 0x80;
            break;
        case 2:
            effectPtr->unk_38 = 0x40;
            break;
        default:
            effectPtr->unk_38 = 0;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_UnkF)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_VannaTEffect)->data)->unk_1C = 0;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_UnkG)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_VannaTEffect)->data)->unk_1C = 1;
    return ApiStatus_DONE2;
}

ApiStatus N(Quizmo_UnkH)(Evt* script, s32 isInitialCall) {
    ((EffectInstanceDataThing*)N(Quizmo_VannaTEffect)->data)->unk_1C = 2;
    return ApiStatus_DONE2;
}

ApiStatus N(GetGameStatus75)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, EVT_VAR(0), gGameStatusPtr->debugQuizmo);
    return ApiStatus_DONE2;
}

ApiStatus N(SetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    gCameras[cameraID].vfov = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(GetCamVfov)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 cameraID = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, EVT_FIXED(gCameras[cameraID].vfov));
    return ApiStatus_DONE2;
}

ApiStatus N(UnkCameraFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    Bytecode out1 = *args++;
    Bytecode out2 = *args++;
    s32 cameraYaw = gCameras[gCurrentCameraID].currentYaw;
    s32 outVal1 = evt_get_variable(script, EVT_ARRAY(1)) - (var2 * cos_deg(cameraYaw));
    s32 outVal2 = evt_get_variable(script, EVT_ARRAY(3)) - (var2 * sin_deg(cameraYaw));

    outVal1 -= var0;
    outVal2 -= var1;

    evt_set_variable(script, out1, outVal1);
    evt_set_variable(script, out2, outVal2);

    return ApiStatus_DONE2;
}

ApiStatus N(UnkRotatePlayer)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 60;
    }

    playerStatus->targetYaw += 30.0f;
    if (playerStatus->targetYaw >= 360.0f) {
        playerStatus->targetYaw -= 360.0f;
    }

    script->functionTemp[0]--;

    return (script->functionTemp[0] >> 0x1F) & ApiStatus_DONE2;
}

ApiStatus N(UnkRotatePartner)(Evt* script, s32 isInitialCall) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);

    if (isInitialCall) {
        script->functionTemp[0] = 60;
    }

    partner->yaw += 30.0f;
    if (partner->yaw >= 360.0f) {
        partner->yaw -= 360.0f;
    }

    script->functionTemp[0]--;

    return (script->functionTemp[0] >> 0x1F) & ApiStatus_DONE2;
}

ApiStatus N(UnkMovePartner)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_PARTNER);
    f32* x = (f32*) &script->functionTemp[1];
    f32* y = (f32*) &script->functionTemp[2];
    f32* z = (f32*) &script->functionTemp[3];

    if (isInitialCall) {
        *x = evt_get_float_variable(script, EVT_VAR(0)) / 60.0f;
        *y = evt_get_float_variable(script, EVT_VAR(5)) / 60.0f;
        *z = evt_get_float_variable(script, EVT_VAR(1)) / 60.0f;
        script->functionTemp[0] = 60;
    }

    npc->pos.x += *x;
    npc->pos.y += *y;
    npc->pos.z += *z;
    script->functionTemp[0]--;

    return (script->functionTemp[0] == 0) * ApiStatus_DONE2;
}

void N(Quizmo_UnkI)(void) {
    s32 var = evt_get_variable(NULL, N(Quizmo_WasCorrect));

    if (var == 1) {
        fx_quizmo_answer(0, 0, 0, 0);
    } else if (var == 2) {
        fx_quizmo_answer(1, 0, 0, 0);
    }
}

ApiStatus N(Quizmo_UnkJ)(Evt* script, s32 isInitialCall) {
    N(Quizmo_Worker) = create_generic_entity_frontUI(NULL, N(Quizmo_UnkI));
    return ApiStatus_DONE2;
}
