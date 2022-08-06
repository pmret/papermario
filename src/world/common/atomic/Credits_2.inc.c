#include "common.h"

// split from Credits_1 due to small differences in credits_update_line

void N(credits_worker_render)(void) {
    Mtx* projMtx = &N(CreditsProjMatrices)[gCurrentDisplayContextIndex];
    CreditsData* data = N(CreditsDataPtr);
    s32 i;

    gSPViewport(gMasterGfxPos++, &N(CreditsViewport));
    guOrtho(projMtx, 0.0f, 320.0f, -240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    gSPMatrix(gMasterGfxPos++, OS_PHYSICAL_TO_K0(projMtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPPipeSync(gMasterGfxPos++);
    gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterGfxPos++, G_SHADE | G_SHADING_SMOOTH);

    for (i = 0; i < ARRAY_COUNT(data->lines); i++) {
        if (data->lines[i].flags & CREDITS_LINE_FLAG_1) {
            N(credits_update_line)(&data->lines[i]);
        }
    }
}

void N(credits_load_message)(CreditsEntry* entry) {
    CreditsLine* line;
    s32 maxLineChars;
    s32 unkMsgProperty;
    s32 i = 0;
    
    while (TRUE) {
        if (!(N(CreditsDataPtr)->lines[i].flags & CREDITS_LINE_FLAG_1)) {
            break;
        }
        if (++i == ARRAY_COUNT(N(CreditsDataPtr)->lines)) {
            return;
        }
    }
    
    line = &N(CreditsDataPtr)->lines[i];
    if (entry->msgID != NULL) {
        if (entry->msgID >= 0) {
            dma_load_msg(entry->msgID, N(CreditsMessageBuffers)[N(CreditsBufferIndex)]);
            line->message = N(CreditsMessageBuffers)[N(CreditsBufferIndex)];
            N(CreditsBufferIndex)++;
            if (N(CreditsBufferIndex) >= ARRAY_COUNT(N(CreditsMessageBuffers))) {
                N(CreditsBufferIndex) = 0;
            }
        } else {
            line->message = (u8*) entry->msgID;
        }
        get_msg_properties((s32) line->message, NULL, NULL, &maxLineChars, NULL, NULL, &unkMsgProperty, 0);
        line->posX            = entry->posX;
        line->posY            = entry->posY;
        line->palette         = entry->palette;
        line->appearMode      = entry->appearMode;
        line->appearTime      = entry->appearTime;
        line->holdMode        = entry->holdMode;
        line->holdTime        = entry->holdTime;
        if (entry->perCharDelayIn != 0) {
            line->holdTime = entry->holdTime - ((maxLineChars - 1) - unkMsgProperty) * entry->perCharDelayIn;
            if (line->holdTime < 0) {
                line->holdTime = 0;
            }
        }
        line->vanishMode      = entry->vanishMode;
        line->vanishTime      = entry->vanishTime;
        line->perCharDelayIn  = entry->perCharDelayIn;
        line->perCharDelayOut = entry->perCharDelayOut;
        line->flags           = entry->flags | CREDITS_LINE_FLAG_1 | CREDITS_LINE_FLAG_2;
    }
}

void N(init_credits)(void) {
    s32 i;

    N(CreditsDataPtr) = &N(CreditsData);
    N(CreditsData).workerID = create_generic_entity_frontUI(NULL, N(credits_worker_render));

    for (i = 0; i < ARRAY_COUNT(N(CreditsData).lines); i++) {
        N(CreditsData).lines[i].flags = 0;
    }
}

ApiStatus N(InitCredits)(Evt* script, s32 isInitialCall) {
    N(init_credits)();
    load_font(1);
    return ApiStatus_DONE2;
}

ApiStatus N(ShowCreditList)(Evt* script, s32 isInitialCall) {
    CreditsEntry* creditList = (CreditsEntry*) evt_get_variable(script, *script->ptrReadPos);
    
    if (isInitialCall) {
        script->varTable[0] = 0;
        script->varTable[1] = -1;
        script->varTable[2] = 0;
    }
    
    switch (script->varTable[0]) {
        case 0:
            while (TRUE) {
                if (creditList[script->varTable[2]].msgID != 0) {
                    N(credits_load_message)(&creditList[script->varTable[2]]);
                }
                script->varTable[1] = creditList[script->varTable[2]].next;
                script->varTable[2]++;
                if (script->varTable[1] > 0) {
                    break;
                }
                if (script->varTable[1] == -1) {
                    return ApiStatus_DONE2;
                }
            }
            script->varTable[0] = 1;
            // fall through
        case 1:
            script->varTable[1]--;
            if (script->varTable[1] <= 0) {
                script->varTable[0] = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}
