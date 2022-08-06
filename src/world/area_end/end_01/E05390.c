#include "end_01.h"

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern ParadeNpcInfo N(ParadeNpcsTable)[];

extern CreditsUnkBeta N(Font4Patterns)[16];
extern CreditsUnkBeta N(Font3Patterns)[16];
extern Vp N(CreditsViewport);
extern s32 N(CreditsBufferIndex);

// start of BSS:
extern CreditsData N(CreditsData);
extern CreditsData* N(CreditsDataPtr);
extern u8 N(CreditsMessageBuffers)[23][256];
extern Mtx N(CreditsProjMatrices)[2];

s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);
void dma_load_msg(u32 msgID, void* dest);

#include "world/common/atomic/Credits.inc.c"

#ifdef NON_MATCHING
void func_80241B44_E06EA4(CreditsLine* line) {
    CreditsChar creditsChar;
    CreditsChar* curChar = &creditsChar;
    CreditsUnkBeta* curPattern;
    s32 msgHeight, msgWidth, msgMaxLineChars;
    s32 doneCurrentState;
    s32 readPos;
    u8 curMsgChar;
    u16 nextMsgChar1, nextMsgChar2;
    u16 doneCalcLoop, doneDrawLoop;
    s32 drawCount;
    s32 posX;
    s32 i;

    doneCurrentState = FALSE;
    if (line->flags & CREDITS_LINE_FLAG_2) {
        line->flags &= ~CREDITS_LINE_FLAG_2;
        line->time = 0;
        line->state = 0;
    }
    
    get_msg_properties(line->message, &msgHeight, &msgWidth, &msgMaxLineChars, NULL, NULL, NULL, 0);
    
    curChar->font = 0;
    curChar->variation = 0;

    // calculate message width
    msgWidth = 1;
    readPos = 0;
    do {
        curMsgChar = line->message[readPos++];
        nextMsgChar1 = line->message[readPos];
        doneCalcLoop = FALSE;
        
        switch (curMsgChar) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
                curChar->variation = curMsgChar - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_ENDL:
            case MSG_CHAR_READ_END:
                doneCalcLoop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                // only support function for selecting font
                if (line->message[readPos++] == MSG_READ_FUNC_FONT) {
                    curChar->font = line->message[readPos++];
                }
                break;
            default:
                msgWidth += msg_get_print_char_width(curMsgChar, curChar->font, curChar->variation, 1.0f, 0, 1) - 1;
                if (curChar->font == MSG_FONT_TITLE || curChar->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font3Patterns);
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font4Patterns);
                    }
    
                    i = 0;
    
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        if (curMsgChar == MSG_CHAR_LPAREN || nextMsgChar1 == MSG_CHAR_LPAREN) {
                            msgWidth++;
                        }
                    }
                    
                    do {
                        if (curMsgChar == curPattern[i].unk_00 && nextMsgChar1 == curPattern[i].unk_01) {
                            msgWidth += curPattern[i].size;
                        }
                        i++;
                    } while (curPattern[i].size != 0);
                }
                break;
        }
    } while (!doneCalcLoop);

    line->msgWidth = msgWidth;
    if (line->flags & CREDITS_LINE_FLAG_1) {
        posX = line->posX - (((f32) msgWidth * 0.5) + 0.0);
    } else {
        posX = line->posX;
    }

    curChar->font = 0;
    curChar->variation = 0;
    curChar->palette = line->palette;
    
    drawCount = 0;
    readPos = 0;
    do {
        curMsgChar = line->message[readPos++];
        nextMsgChar2 = line->message[readPos];
        doneDrawLoop = FALSE;
        
        switch (curMsgChar) {
            case MSG_CHAR_READ_VARIANT0:
            case MSG_CHAR_READ_VARIANT1:
            case MSG_CHAR_READ_VARIANT2:
                curChar->variation = curMsgChar - MSG_CHAR_READ_VARIANT0;
                break;
            case MSG_CHAR_READ_ENDL:
            case MSG_CHAR_READ_END:
                doneDrawLoop = TRUE;
                break;
            case MSG_CHAR_READ_FUNCTION:
                if (line->message[readPos++] == 0) {
                    curChar->font = line->message[readPos++];
                }
                break;
            default:
                if (curMsgChar < MSG_CHAR_READ_ENDL) {
                    curChar->charIndex = curMsgChar;
                    curChar->posX = posX;
                    curChar->posY = line->posY;
                    
                    switch (line->state) {
                        case CREDITS_LINE_APPEARING:
                            curChar->fadeInTime = line->time - (line->perCharDelayIn * drawCount);
                            if (curChar->fadeInTime >= 0) {
                                if (line->appearTime < curChar->fadeInTime) {
                                    curChar->fadeInTime = line->appearTime;
                                }
                                if ((nextMsgChar2 == MSG_CHAR_READ_END) && (curChar->fadeInTime == line->appearTime)) {
                                    doneCurrentState = TRUE;
                                }
                                switch (line->appearMode) {
                                    case 0:
                                        N(CharAnim_FadeIn_5)(line, curChar);
                                        break;
                                    case 1:
                                        N(CharAnim_FadeIn_1)(line, curChar);
                                        break;
                                    case 2:
                                        N(CharAnim_FadeIn_2)(line, curChar);
                                        break;
                                    case 3:
                                        N(CharAnim_FadeIn_3)(line, curChar);
                                        break;
                                    case 4:
                                        N(CharAnim_FadeIn_4)(line, curChar);
                                        break;
                                    case 5:
                                        N(CharAnim_FadeIn_5)(line, curChar);
                                        break;
                                }
                            }
                            break;
                        
                        case CREDITS_LINE_HOLDING:
                            if (nextMsgChar2 == MSG_CHAR_READ_END) {
                                if (line->time == line->holdTime) {
                                    doneCurrentState = TRUE;
                                }
                            }
                            N(CharAnim_Hold)(line, curChar);
                            break;

                        case CREDITS_LINE_VANISHING:
                            curChar->fadeInTime = line->time - (line->perCharDelayOut * drawCount);
                            if (curChar->fadeInTime < 0) {
                                curChar->fadeInTime = 0;
                            }
                            if (curChar->fadeInTime > line->vanishTime) {
                                curChar->fadeInTime = line->vanishTime;
                            }
                            if (nextMsgChar2 == MSG_CHAR_READ_END && curChar->fadeInTime == line->vanishTime) {
                                doneCurrentState = TRUE;
                            }

                            switch (line->vanishMode) {
                                case 0:
                                    N(CharAnim_FadeOut_3)(line, curChar);
                                    break;
                                case 1:
                                    N(CharAnim_FadeOut_1)(line, curChar);
                                    break;
                                case 2:
                                    N(CharAnim_FadeOut_2)(line, curChar);
                                    break;
                                case 3:
                                    N(CharAnim_FadeOut_3)(line, curChar);
                                    break;
                            }
                            break;
                    }
                    drawCount++;
                }

                posX += msg_get_print_char_width(curMsgChar, curChar->font, curChar->variation, 1.0f, 0, 1) - 1;
                if (curChar->font == MSG_FONT_TITLE || curChar->font == MSG_FONT_SUBTITLE) {
                    curPattern = N(Font3Patterns);
                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        curPattern = N(Font4Patterns);
                    }

                    i = 0;

                    if (curChar->font == MSG_FONT_SUBTITLE) {
                        if (curMsgChar == MSG_CHAR_LPAREN || nextMsgChar2 == MSG_CHAR_LPAREN) {
                            posX++;
                        }
                    }
                    do {
                        if (curMsgChar == curPattern[i].unk_00 && nextMsgChar2 == curPattern[i].unk_01) {
                            posX += curPattern[i].size;
                        }
                        i++;
                    } while (curPattern[i].size != 0);
                }
                break;
        }
    } while (!doneDrawLoop);
    
    if ((line->state == CREDITS_LINE_APPEARING) && doneCurrentState) {
        s32 temp = 0;
        get_msg_properties(line->message, NULL, NULL, &temp, NULL, NULL, NULL, 0);
        line->time = 0;
        line->state++;
        if (line->holdTime <= 0) {
            line->state++;
        }
    } else if ((line->state == CREDITS_LINE_HOLDING) && doneCurrentState) {
        line->time = 0;
        line->state++;
    } else if ((line->state == CREDITS_LINE_VANISHING) && doneCurrentState) {
        line->flags &= ~CREDITS_LINE_FLAG_1;
    }
    line->time++;
}
#else
INCLUDE_ASM(s32, "world/area_end/end_01/E05390", func_80241B44_E06EA4);
#endif

void func_802421E8_E07548(void) {
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
        if (data->lines[i].flags & 1) {
            func_80241B44_E06EA4(&data->lines[i]);
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

void func_80242510_E07870(void) {
    s32 i;

    N(CreditsDataPtr) = &N(CreditsData);
    N(CreditsData).workerID = create_generic_entity_frontUI(NULL, func_802421E8_E07548);

    for (i = 0; i < ARRAY_COUNT(N(CreditsData).lines); i++) {
        N(CreditsData).lines[i].flags = 0;
    }
}

ApiStatus func_80242568_E078C8(Evt* script, s32 isInitialCall) {
    func_80242510_E07870();
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

ApiStatus func_80242690_E079F0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    ParadeNpcInfo* npcInfo = &N(ParadeNpcsTable)[npcID];
    NpcBlueprint bp;
    Npc* npc;

    bp.flags = NPC_FLAG_100;
    bp.initialAnim = npcInfo->initialAnim;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    spr_allocateBtlComponentsOnWorldHeap = TRUE;

    npc = get_npc_by_index(_create_npc_standard(&bp, npcInfo->animList));
    npc->npcID = npcID;
    npc->flags &= ~NPC_FLAG_PARTICLE;
    npc->pos.x = npcInfo->pos.x;
    npc->pos.y = npcInfo->pos.y;
    npc->pos.z = npcInfo->pos.z;
    set_npc_yaw(npc, npcInfo->yaw);
    return ApiStatus_DONE2;
}

ApiStatus func_80242754_E07AB4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 heapSize = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, _heap_malloc(&gSpriteHeapPtr, heapSize));
    return ApiStatus_DONE2;
}

ApiStatus func_802427B4_E07B14(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 pointer = *args++;

    _heap_free(&gSpriteHeapPtr, evt_get_variable(script, pointer));
    return ApiStatus_DONE2;
}

ApiStatus func_802427E8_E07B48(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->unk_506 = 1;
    camera->movePos.x += 0.6666667f;
    return ApiStatus_DONE2;
}

ApiStatus func_80242840_E07BA0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc** npc = (Npc**)&script->functionTempPtr[1];

    if (isInitialCall) {
        *npc = get_npc_unsafe(evt_get_variable(script, *args++));
    }

    (*npc)->pos.x += 0.6666667f;

    return ApiStatus_BLOCK;
}

ApiStatus func_8024289C_E07BFC(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_START)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

static char* N(exit_str_0) = "kmr_30";
