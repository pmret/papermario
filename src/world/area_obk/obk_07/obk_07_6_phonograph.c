#include "obk_07.h"
#include "hud_element.h"
#include "battle/action_cmd.h"
#include "sprite/player.h"

extern HudScript HES_SlowlyMashAButton;

extern EvtScript N(EVS_UpdateGuardBoo);
extern EvtScript N(EVS_DummyUpdateGuardBoo);
extern EvtScript N(EVS_GuardBoo_ReturnToPost);
extern EvtScript N(EVS_NpcAI_GuardBoo_Wary);

s32 N(ItemList_Records)[] = {
    ITEM_BOO_RECORD,
    ITEM_NONE
};

s32 N(SongList)[] = {
    SONG_PHONOGRAPH_MUSIC,
    SONG_TOAD_TOWN,
};

typedef struct PhonographData {
    /* 0x000 */ s32 mashMeterSmoothDivisor;
    /* 0x004 */ s32 fillValue;
    /* 0x008 */ s32 barFillWidth;
    /* 0x00C */ s32 songName;
    /* 0x010 */ s32 mashMeterDividers[6];
    /* 0x028 */ s32 mashMeterIntervals;
    /* 0x02C */ s32 hudWorker;
    /* 0x030 */ s32 state;
    /* 0x034 */ s32 hudBaseX;
    /* 0x038 */ s32 hudBaseY;
    /* 0x03C */ s32 hudElemAButton;
    /* 0x040 */ s32 hudElemBlueMeter;
    /* 0x044 */ s32 hudElemOK;
    /* 0x048 */ char unk_48[0x4];
    /* 0x04C */ s32 updateScaleScriptID;
    /* 0x050 */ s32 updateCrankScriptID;
    /* 0x054 */ s32 updateRecordScriptID;
    /* 0x058 */ s32 inputBuffer[90];
    /* 0x1C0 */ s32 inputBufferPos;
    /* 0x1C4 */ f32 timeScale;
    /* 0x1C8 */ f32 crankRotation;
    /* 0x1CC */ f32 recordRotation;
    /* 0x1D0 */ f32 modelScale;
    /* 0x1D4 */ s32 meterFillAmount;
    /* 0x1D8 */ s32 unk_1D8;
    /* 0x1DC */ s8 unk_1DC;
    /* 0x1DD */ char unk_1DD[0x3];
} PhonographData; // size = 0x1E0

enum {
    PHONOGRAPH_HUD_STATE_DESTROYED  = -1,
    PHONOGRAPH_HUD_STATE_INIT       = 0,
    PHONOGRAPH_HUD_STATE_APPEAR     = 1,    // hud slides in from left side of screen
    PHONOGRAPH_HUD_STATE_MASHING    = 10,   // 'A' button icon begins mashing animation
    PHONOGRAPH_HUD_STATE_FINAL      = 11,   // final state used during minigame
};

API_CALLABLE(N(CreatePhonographData)) {
    evt_set_variable(script, MV_PhonographDataPtr, (s32) heap_malloc(sizeof(PhonographData)));
    return ApiStatus_DONE2;
}

PhonographData* N(GetPhonographData)(void) {
    return (PhonographData*) evt_get_variable(NULL, MV_PhonographDataPtr);
}

u8 N(mashMeter_bgColors)[] = {
     33,  33, 117,
     29,  35, 163,
     70,  12, 180,
    107,   0, 120,
    115,  13,  19,
};

u8 N(mashMeter_fillColors)[] = {
      0, 228, 134,
     46, 180, 242,
    117, 112, 255,
    243,   4, 188,
    247,  13,   5,
};

u8 N(mashMeter_cutOffColors)[] = {
     45,  56, 210,
     84,  40, 209,
    125,  44, 181,
    161,  27,  85,
    255, 255, 255,
};

// similar to draw_mash_meter
void N(DrawMashMeter)(s32 posX, s32 posY, s32 fillValue) {
    PhonographData* data = N(GetPhonographData)();
    s32 maxCutoff;
    s32 width;
    s32 i;
    s32 cutOff;
    s32 offsetX;
    s32 s2;
    s32 filledWidth;
    s32 r, g, b;

    posX -= 28;
    posY -= 4;

    maxCutoff = data->mashMeterDividers[data->mashMeterIntervals];

    if (fillValue < 0) {
        fillValue = 0;
    }

    width = 0;
    for (i = 0; i < data->mashMeterIntervals; i++) {
        cutOff = data->mashMeterDividers[i + 1];
        if (cutOff > fillValue) {
            cutOff = fillValue;
        }
        width = cutOff * 60 / maxCutoff * 100;
        if (fillValue == cutOff) {
            break;
        }
    }

    offsetX = 0;
    data->barFillWidth += (width - data->barFillWidth) / data->mashMeterSmoothDivisor;

    for (i = 0; i < data->mashMeterIntervals; i++) {
        cutOff = data->mashMeterDividers[i + 1];
        width = cutOff * 60 / maxCutoff - offsetX;
        r = N(mashMeter_bgColors)[i * 3 + 0];
        g = N(mashMeter_bgColors)[i * 3 + 1];
        b = N(mashMeter_bgColors)[i * 3 + 2];
        startup_draw_prim_rect_COPY(posX + offsetX, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
        if (i >= data->mashMeterIntervals - 1) {
            break;
        }
        r = N(mashMeter_cutOffColors)[i * 3 + 0];
        g = N(mashMeter_cutOffColors)[i * 3 + 1];
        b = N(mashMeter_cutOffColors)[i * 3 + 2];
        startup_draw_prim_rect_COPY(posX + offsetX + width, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
        offsetX += width;
    }
    offsetX = 0;
    for (i = 0; i < data->mashMeterIntervals; i++) {
        r = N(mashMeter_fillColors)[i * 3 + 0];
        g = N(mashMeter_fillColors)[i * 3 + 1];
        b = N(mashMeter_fillColors)[i * 3 + 2];

        cutOff = data->mashMeterDividers[i + 1];
        if (cutOff > fillValue) {
            cutOff = fillValue;
        }

        width = data->barFillWidth / 100 - offsetX;
        filledWidth = cutOff * 60 / maxCutoff - offsetX;
        if (width < 0) {
            break;
        }

        if (filledWidth == 0) {
            filledWidth = width;
        } else if (cutOff == fillValue) {
            filledWidth = width;
        } else if (filledWidth < width) {
            width = filledWidth;
        }

        startup_draw_prim_rect_COPY(posX + offsetX, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
        if (i >= data->mashMeterIntervals - 1) {
            break;
        }

        r = N(mashMeter_cutOffColors)[i * 3 + 0];
        g = N(mashMeter_cutOffColors)[i * 3 + 1];
        b = N(mashMeter_cutOffColors)[i * 3 + 2];
        startup_draw_prim_rect_COPY(posX + offsetX + width, posY, posX + offsetX + width, posY + 5, r, g, b, 255);
        offsetX += filledWidth;
    }
}

void N(DrawMashMeterWithDivisor)(s32 baseX, s32 baseY, s32 fillValue, s32 smoothDivisor) {
    N(GetPhonographData)()->mashMeterSmoothDivisor = smoothDivisor;
    N(DrawMashMeter)(baseX, baseY, fillValue);
}

void N(worker_update_phonograph_hud)(void) {
    PhonographData* data = N(GetPhonographData)();
    s32 id;
    s32 temp;
    s32 mashInputsCount;
    s32 arrCount;
    s32 idx;
    s32 i;

    data->inputBuffer[data->inputBufferPos] = gGameStatusPtr->pressedButtons[0] & BUTTON_A;
    data->inputBufferPos++;
    if (data->inputBufferPos >= ARRAY_COUNT(data->inputBuffer)) {
        data->inputBufferPos = 0;
    }

    switch (data->state) {
        case PHONOGRAPH_HUD_STATE_INIT:
            id = data->hudElemAButton;
            hud_element_set_alpha(id, 255);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            id = data->hudElemBlueMeter;
            hud_element_set_alpha(id, 255);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            id = data->hudElemOK;
            hud_element_set_alpha(id, 255);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            data->state = PHONOGRAPH_HUD_STATE_APPEAR;
            break;
        case PHONOGRAPH_HUD_STATE_APPEAR:
            data->hudBaseX += 20;
            if (data->hudBaseX > 50) {
                data->hudBaseX = 50;
            }
            hud_element_set_render_pos(data->hudElemAButton, data->hudBaseX, data->hudBaseY);
            hud_element_set_render_pos(data->hudElemBlueMeter, data->hudBaseX, data->hudBaseY + 28);
            hud_element_set_render_pos(data->hudElemOK, data->hudBaseX + 2, data->hudBaseY + 14);
            break;
        case PHONOGRAPH_HUD_STATE_MASHING:
            hud_element_set_script(data->hudElemAButton, &HES_SlowlyMashAButton);
            data->state = PHONOGRAPH_HUD_STATE_FINAL;
            // fallthrough
        case PHONOGRAPH_HUD_STATE_FINAL:
            arrCount = ARRAY_COUNT(data->inputBuffer);
            idx = data->inputBufferPos;
            idx -= arrCount;
            data->fillValue = 0;
            if (idx < 0) {
                idx += arrCount;
            }

            mashInputsCount = 0;
            for (i = 0; i < arrCount; i++, idx++) {
                if (idx >= ARRAY_COUNT(data->inputBuffer)) {
                    idx -= ARRAY_COUNT(data->inputBuffer);
                }
                if (data->inputBuffer[idx] != 0) {
                    mashInputsCount++;
                }
            }
            evt_set_variable(NULL, MV_MashInputsAmount, mashInputsCount * 1000);
            data->fillValue = (mashInputsCount * 100) / 22;
            if (data->fillValue < 0) {
                data->fillValue = 0;
            }
            if (data->fillValue > 100) {
                data->fillValue = 100;
            }

            id = data->barFillWidth / 60; // TODO use of id required to match - weird
            if (id <= 50) {
                temp = 50.0f;
                temp *= sin_rad(DEG_TO_RAD((id * 90) / 50));
            } else {
                temp = ((1.0 - sin_rad(DEG_TO_RAD((((id - 50) * 90) / 50) + 90))) * 50.0) + 50.0;
            }
            data->timeScale = (((100 - temp) * 0.25) / 100.0) + ((2.0 * temp) / 100.0);
            snd_song_set_playback_rate(data->songName, data->timeScale);
            set_script_timescale(get_script_by_id(data->updateScaleScriptID), data->timeScale * 3.0f);
            set_script_timescale(get_script_by_id(data->updateCrankScriptID), data->timeScale * 5.0f);
            set_script_timescale(get_script_by_id(data->updateRecordScriptID), data->timeScale * 5.0f);
            break;
    }
}

API_CALLABLE(N(func_80240EF8_BCFAE8)) {
    PhonographData* data = N(GetPhonographData)();
    s32 temp_f6 = script->varTable[0] / 1000;

    temp_f6 = sin_rad(DEG_TO_RAD((temp_f6 * 90) / 50)) * 50.0f;
    data->timeScale = (((100 - temp_f6) * 0.25) / 100.0) + ((2.0 * temp_f6) / 100.0);
    snd_song_set_playback_rate(data->songName, data->timeScale);

    //@bug? these set the timescale for *this* script, not the three update scripts
    get_script_by_id(data->updateScaleScriptID);
    set_script_timescale(script, data->timeScale * 3.0f);
    get_script_by_id(data->updateCrankScriptID);
    set_script_timescale(script, data->timeScale * 5.0f);
    get_script_by_id(data->updateRecordScriptID);
    set_script_timescale(script, data->timeScale * 5.0f);
    return ApiStatus_DONE2;
}

void N(worker_draw_phonograph_hud)(void) {
    PhonographData* data = N(GetPhonographData)();
    s32 hudElemIndex;
    s32 x, y;

    hudElemIndex = data->hudElemAButton;
    hud_element_draw_clipped(hudElemIndex);

    hudElemIndex = data->hudElemBlueMeter;
    hud_element_draw_clipped(hudElemIndex);
    hud_element_get_render_pos(hudElemIndex, &x, &y);
    N(DrawMashMeterWithDivisor)(x, y, data->fillValue, 2);

    hudElemIndex = data->hudElemOK;
    hud_element_draw_clipped(hudElemIndex);
}

API_CALLABLE(N(GetSelectedRecordIndex)) {
    s32 outVal = 0;
    s32* record = N(ItemList_Records);

    while (TRUE) {
        if (*record == 0) {
            outVal = -1;
        } else if (*record++ != script->varTable[0]) {
            outVal++;
            continue;
        }
        break;
    }
    script->varTable[0] = outVal;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreatePhonographHudData)) {
    PhonographData* data = N(GetPhonographData)();
    s32 id;
    s32 i;

    gOverrideFlags |= GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
    data->hudWorker = create_worker_frontUI(N(worker_update_phonograph_hud), N(worker_draw_phonograph_hud));
    data->state = PHONOGRAPH_HUD_STATE_INIT;
    data->fillValue = 0;
    data->barFillWidth = 0;
    data->mashMeterDividers[0] = 0;
    data->mashMeterDividers[1] = 20;
    data->mashMeterDividers[2] = 40;
    data->mashMeterDividers[3] = 60;
    data->mashMeterDividers[4] = 80;
    data->mashMeterDividers[5] = 100;
    data->mashMeterIntervals = ARRAY_COUNT(data->mashMeterDividers) - 1;

    for (i = 0; i < ARRAY_COUNT(data->inputBuffer); i++) {
        data->inputBuffer[i] = 0;
    }
    data->inputBufferPos = 0;

    data->crankRotation = 0;
    data->recordRotation = 0;
    data->hudBaseX = -48;
    data->hudBaseY = 64;
    data->timeScale = 1.0f;
    data->modelScale = 1.0f;

    data->hudElemAButton = id = hud_element_create(&HES_AButton);
    hud_element_set_render_pos(id, data->hudBaseX, data->hudBaseY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    data->hudElemBlueMeter = id = hud_element_create(&HES_BlueMeter);
    hud_element_set_render_pos(id, data->hudBaseX, data->hudBaseY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    data->hudElemOK = id = hud_element_create(&HES_RunAwayOK);
    hud_element_set_render_pos(id, data->hudBaseX, data->hudBaseY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayRecordSong)) {
    bgm_set_song(0, N(SongList)[evt_get_variable(script, GB_OBK07_SelectedRecord)], 0, 500, 8);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SavePhonographUpdateScriptIDs)) {
    PhonographData* data = N(GetPhonographData)();

    data->state = PHONOGRAPH_HUD_STATE_MASHING;
    data->updateScaleScriptID = evt_get_variable(NULL, MV_UpdateScaleScript);
    data->updateCrankScriptID = evt_get_variable(NULL, MV_UpdateCrankScript);
    data->updateRecordScriptID = evt_get_variable(NULL, MV_UpdateRecordScript);
    data->songName = gMusicSettings->songName;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyPhonographHudData)) {
    PhonographData* data = N(GetPhonographData)();

    data->state = PHONOGRAPH_HUD_STATE_DESTROYED;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
    hud_element_free(data->hudElemAButton);
    hud_element_free(data->hudElemBlueMeter);
    hud_element_free(data->hudElemOK);
    free_worker(data->hudWorker);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPhonographScaleDivisor)) {
    N(GetPhonographData)();
    script->varTable[3] = 150;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetPhonographScale)) {
    PhonographData* data = N(GetPhonographData)();

    data->modelScale = evt_get_float_variable(script, LVar2);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetCrankRotation)) {
    PhonographData* data = N(GetPhonographData)();

    data->crankRotation = clamp_angle(evt_get_float_variable(script, LVar0));
    evt_set_float_variable(script, LVar0, data->crankRotation);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetRecordRotation)) {
    PhonographData* temp_s1 = N(GetPhonographData)();

    temp_s1->recordRotation = clamp_angle(evt_get_float_variable(script, LVar0));
    evt_set_float_variable(script, LVar0, temp_s1->recordRotation);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPhonographScale)) {
    evt_set_float_variable(script, LVar0, N(GetPhonographData)()->modelScale);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetCrankRotation)) {
    evt_set_float_variable(script, LVar0, N(GetPhonographData)()->crankRotation);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetRecordRotation)) {
    evt_set_float_variable(script, LVar0, N(GetPhonographData)()->recordRotation);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SaveLastUpdateValue)) {
    f32 value = evt_get_float_variable(script, LVar0);
    evt_set_float_variable(script, LVar1, value);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckScaleNearUnity)) {
    f32 curScale = evt_get_float_variable(script, LVar0);
    f32 prevScale = evt_get_float_variable(script, LVar1);

    if (prevScale <= 1.0f && curScale >= 1.0f) {
        script->varTable[2] = 1;
    } else {
        script->varTable[2] = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckAngleNearZero)) {
    f32 curAngle = evt_get_float_variable(script, LVar0);
    f32 prevAngle = evt_get_float_variable(script, LVar1);

    if (prevAngle <= 360.0f && curAngle <= 100.0f) {
        script->varTable[2] = 1;
    } else {
        script->varTable[2] = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GuardBooDoNothing)) {
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80241790_BD0380)) {
    PhonographData* data = N(GetPhonographData)();
    s32 distFromCenter = abs(data->fillValue - 50);
    s32 v1, v0;

    while (TRUE) {
        if (distFromCenter < 10) {
            v1 = 10;
            v1 -= distFromCenter;
            v0 = v1 * 24;
        } else {
            v1 = -distFromCenter;
            v0 = v1 * 4;
        }
        break;
    }

    distFromCenter = (v0 + v1) * 2;
    data->meterFillAmount += distFromCenter;

    if (data->fillValue != 0) {
        data->unk_1DC = 1;
    }
    if (data->unk_1DC == 1) {
        if (data->fillValue <= 0) {
            data->unk_1D8++;
        } else {
            data->unk_1D8 = 0;
        }
    }

    if (data->meterFillAmount > 10000) {
        data->meterFillAmount = 10000;
    }
    if (data->meterFillAmount < 0) {
        data->meterFillAmount = 0;
    }

    script->varTable[0] = 0;
    if (data->unk_1D8 >= 46 || (gGameStatusPtr->pressedButtons[0] & BUTTON_B)) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitPhonographHud)) {
    PhonographData* data = N(GetPhonographData)();

    data->meterFillAmount = 0;
    data->unk_1D8 = 0;
    data->unk_1DC = 0;
    data->fillValue = 0;
    data->state = PHONOGRAPH_HUD_STATE_INIT;
    script->varTable[10] = 0;
    script->varTable[11] = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateGuardBooPos)) {
    Npc* npc = get_npc_unsafe(NPC_GuardBoo);
    PhonographData* data = N(GetPhonographData)();
    f32 booPosZ = -136.0f;
    f32 x = npc->pos.x;
    f32 z = npc->pos.z;
    f32 dancePosX = -92.0f;
    f32 guardPosX = 168.0f;
    f32 speed;

    if (data->state == PHONOGRAPH_HUD_STATE_DESTROYED) {
        // return to guard position
        speed = 2.0f;
        npc->curAnim = ANIM_Boo_Run;
        if (dist2D(x, z, guardPosX, booPosZ) < speed) {
            npc->pos.x = guardPosX;
            npc->pos.z = booPosZ;
            npc->yaw = atan2(x, z, dancePosX, booPosZ);
            script->varTable[10] = 0;
            script->varTable[11] = 1;
            return ApiStatus_DONE2;
        } else {
            npc->yaw = atan2(x, z, guardPosX, booPosZ);
            npc_move_heading(npc, speed, npc->yaw);
        }
        return ApiStatus_DONE2;
    }

    if (data->meterFillAmount > 7000) {
        // lure toward dance position
        speed = 2.0f;
        script->varTable[10] = 1;
        if (dist2D(x, z, dancePosX, booPosZ) < speed) {
            npc->pos.x = dancePosX;
            npc->pos.z = booPosZ;
        } else {
            npc->yaw = atan2(x, z, dancePosX, booPosZ);
            npc_move_heading(npc, speed, npc->yaw);
        }
    }

    if (data->meterFillAmount < 3000) {
        // return to guard position
        speed = 2.0f;
        script->varTable[10] = 0;
        if (dist2D(x, z, guardPosX, booPosZ) < speed) {
            npc->pos.x = guardPosX;
            npc->pos.z = booPosZ;
            npc->yaw = atan2(x, z, dancePosX, -136.0f);
        } else {
            npc->yaw = atan2(x, z, guardPosX, booPosZ);
            npc_move_heading(npc, speed, npc->yaw);
        }
    }

    if (data->meterFillAmount > 7000) {
        npc->curAnim = ANIM_Boo_Wave;
    } else if (data->meterFillAmount > 5000) {
        npc->curAnim = ANIM_Boo_Run;
    } else if (data->meterFillAmount > 3000) {
        npc->curAnim = ANIM_Boo_Walk;
    } else {
        npc->curAnim = ANIM_Boo_Idle;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitGuardBooAlpha)) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->alpha = 180;
    npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePhonographScale) = {
    EVT_LABEL(30)
        EVT_CALL(MakeLerp, 100, 200, 30, EASING_COS_IN_OUT)
        EVT_LABEL(31)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_CALL(N(GetPhonographScaleDivisor))
            EVT_DIVF(LVar2, LVar3)
            EVT_CALL(N(SetPhonographScale))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(31)
            EVT_END_IF
        EVT_CALL(MakeLerp, 200, 100, 30, EASING_COS_IN_OUT)
        EVT_LABEL(32)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_CALL(N(GetPhonographScaleDivisor))
            EVT_DIVF(LVar2, LVar3)
            EVT_CALL(N(SetPhonographScale))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(32)
            EVT_END_IF
        EVT_GOTO(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateCrankRotation) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_CALL(N(SetCrankRotation))
        EVT_ADD(LVar0, 2)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateRecordRotation) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(20)
        EVT_CALL(N(SetRecordRotation))
        EVT_ADD(LVar0, 10)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetPhonographScale) = {
    EVT_SET(MF_CancelScaleScript, FALSE)
    EVT_LOOP(0)
        EVT_IF_EQ(MF_CancelScaleScript, TRUE)
            EVT_CALL(N(CheckScaleNearUnity))
            EVT_IF_EQ(LVar2, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(SaveLastUpdateValue))
        EVT_CALL(N(GetPhonographScale))
        EVT_CALL(ScaleModel, MODEL_rap, LVar0, LVar0, LVar0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_t)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MF_CancelScaleScript, FALSE)
    EVT_CALL(ScaleModel, MODEL_rap, 1, 1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCrankRotation) = {
    EVT_SET(MF_CancelCrankScript, FALSE)
    EVT_LOOP(0)
        EVT_IF_EQ(MF_CancelCrankScript, TRUE)
            EVT_CALL(N(CheckAngleNearZero))
            EVT_IF_EQ(LVar2, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(SaveLastUpdateValue))
        EVT_CALL(N(GetCrankRotation))
        EVT_CALL(RotateGroup, MODEL_bo, LVar0, 1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MF_CancelCrankScript, FALSE)
    EVT_CALL(RotateGroup, MODEL_bo, 0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetRecordRotation) = {
    EVT_SET(MF_CancelRecordScript, FALSE)
    EVT_LOOP(0)
        EVT_IF_EQ(MF_CancelRecordScript, TRUE)
            EVT_CALL(N(CheckAngleNearZero))
            EVT_IF_EQ(LVar2, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(SaveLastUpdateValue))
        EVT_CALL(N(GetRecordRotation))
        EVT_CALL(RotateGroup, MODEL_rec, LVar0, 0, -1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MF_CancelRecordScript, FALSE)
    EVT_CALL(RotateGroup, MODEL_rec, 0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WindDownPhonograph) = {
    EVT_SET(MV_WindingDown, TRUE)
    EVT_CALL(MakeLerp, MV_MashInputsAmount, 0, LVar0, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_80240EF8_BCFAE8))
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
    // signal scripts should stop
    EVT_SET(MF_CancelScaleScript, TRUE)
    EVT_SET(MF_CancelCrankScript, TRUE)
    EVT_SET(MF_CancelRecordScript, TRUE)
    // wait for canceled scripts to end
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_CancelScaleScript, FALSE)
            EVT_IF_EQ(MF_CancelCrankScript, FALSE)
                EVT_IF_EQ(MF_CancelRecordScript, FALSE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_LOOP
    // kill the completed scripts
    EVT_KILL_THREAD(MV_UpdateScaleScript)
    EVT_KILL_THREAD(MV_UpdateCrankScript)
    EVT_KILL_THREAD(MV_UpdateRecordScript)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(MV_WindingDown, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayPhonograph) = {
    EVT_IF_EQ(MV_WindingDown, TRUE)
        EVT_IS_THREAD_RUNNING(MV_WindDownScript, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_KILL_THREAD(MV_WindDownScript)
            EVT_IS_THREAD_RUNNING(MV_UpdateScaleScript, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_KILL_THREAD(MV_UpdateScaleScript)
            EVT_END_IF
            EVT_IS_THREAD_RUNNING(MV_UpdateCrankScript, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_KILL_THREAD(MV_UpdateCrankScript)
            EVT_END_IF
            EVT_IS_THREAD_RUNNING(MV_UpdateRecordScript, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_KILL_THREAD(MV_UpdateRecordScript)
            EVT_END_IF
            EVT_IS_THREAD_RUNNING(MV_SetScaleScript, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_KILL_THREAD(MV_SetScaleScript)
            EVT_END_IF
            EVT_IS_THREAD_RUNNING(MV_SetCrankScript, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_KILL_THREAD(MV_SetCrankScript)
            EVT_END_IF
            EVT_IS_THREAD_RUNNING(MV_SetRecordScript, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_KILL_THREAD(MV_SetRecordScript)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar2, -170)
        EVT_GOTO(33)
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(PlayerMoveTo, -202, -170, 0)
    EVT_LABEL(33)
    EVT_CALL(PlayerMoveTo, -216, -115, 0)
    EVT_CALL(InterpPlayerYaw, 38, 1)
    EVT_LOOP(0)
        // wait for tutorial message dismissal if there is one
        EVT_WAIT(1)
        EVT_IF_EQ(MV_ReadyToPlay, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(5)
    EVT_CALL(N(CreatePhonographHudData))
    EVT_CALL(N(PlayRecordSong))
    EVT_WAIT(30)
    EVT_CALL(N(InitPhonographHud))
    EVT_IF_EQ(MV_GuardDeparted, FALSE)
        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_Wary)))
        EVT_EXEC_GET_TID(N(EVS_UpdateGuardBoo), MV_UpdateGuardScript)
    EVT_ELSE
        EVT_EXEC_GET_TID(N(EVS_DummyUpdateGuardBoo), MV_UpdateGuardScript)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(EVS_UpdatePhonographScale), MV_UpdateScaleScript)
    EVT_EXEC_GET_TID(N(EVS_UpdateCrankRotation),   MV_UpdateCrankScript)
    EVT_EXEC_GET_TID(N(EVS_UpdateRecordRotation),  MV_UpdateRecordScript)
    EVT_EXEC_GET_TID(N(EVS_SetPhonographScale),    MV_SetScaleScript)
    EVT_EXEC_GET_TID(N(EVS_SetCrankRotation),      MV_SetCrankScript)
    EVT_EXEC_GET_TID(N(EVS_SetRecordRotation),     MV_SetRecordScript)
    EVT_CALL(N(SavePhonographUpdateScriptIDs))
    EVT_LOOP(0)
        EVT_CALL(N(func_80241790_BD0380))
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(N(DestroyPhonographHudData))
            EVT_WAIT(1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        // wait for the guard to finish jumping or spinning
        EVT_WAIT(1)
        EVT_IF_EQ(MF_GuardBusy, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(MV_UpdateGuardScript)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(MV_GuardDeparted, FALSE)
        EVT_IF_EQ(MV_GuardDancing, TRUE)
            EVT_SET(LVar0, 150)
        EVT_ELSE
            EVT_SET(LVar0, 80)
        EVT_END_IF
        EVT_EXEC_GET_TID(N(EVS_WindDownPhonograph), MV_WindDownScript)
        EVT_EXEC_GET_TID(N(EVS_GuardBoo_ReturnToPost), MV_GuardReturnScript)
    EVT_ELSE
        EVT_SET(LVar0, 80)
        EVT_EXEC_GET_TID(N(EVS_WindDownPhonograph), MV_WindDownScript)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_Phonograph) = {
    EVT_IF_EQ(MV_GuardDancing, TRUE)
        EVT_IF_EQ(MV_GuardDeparted, FALSE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_PLAYED_THE_RECORD)
        EVT_GOTO(50)
    EVT_END_IF
    // choose a record
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Phonograph, 160, 40)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(N(GetSelectedRecordIndex))
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_SET(GB_OBK07_SelectedRecord, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GB_StoryProgress, STORY_CH3_PLAYED_THE_RECORD)
    EVT_CALL(EnableModel, MODEL_reco, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_CarryIdle)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(15)
    EVT_CALL(CloseChoicePopup)
    // try playing
    EVT_LABEL(50)
    EVT_SET(MV_ReadyToPlay, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_GOT_WEIGHT)
        EVT_SET(MV_ReadyToPlay, FALSE)
        EVT_THREAD
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0181, 160, 40)
            EVT_SET(MV_ReadyToPlay, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_PlayPhonograph))
    EVT_RETURN
    // done
    EVT_LABEL(100)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_GuardBoo_Wary) = {
    EVT_CALL(SetNpcAnimation, NPC_GuardBoo, ANIM_Boo_Idle)
    EVT_LABEL(0)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(InterpNpcYaw, NPC_GuardBoo, 90, 5)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(InterpNpcYaw, NPC_GuardBoo, 270, 5)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_GuardBoo_DoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_GuardBoo_Dancing) = {
    EVT_LOOP(0)
        EVT_CALL(RandInt, 99, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_LT(30)
                EVT_CALL(RandInt, 10, LVar0)
                EVT_ADD(LVar0, 10)
                EVT_WAIT(LVar0)
                EVT_CALL(InterpNpcYaw, NPC_GuardBoo, 90, 5)
                EVT_CALL(RandInt, 10, LVar0)
                EVT_ADD(LVar0, 10)
                EVT_WAIT(LVar0)
                EVT_CALL(InterpNpcYaw, NPC_GuardBoo, 270, 5)
            EVT_CASE_LT(60)
                EVT_CALL(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcJumpscale, NPC_GuardBoo, EVT_FLOAT(1.0))
                EVT_CALL(NpcJump0, NPC_GuardBoo, LVar0, LVar1, LVar2, 10)
            EVT_CASE_LT(99)
                EVT_CALL(MakeLerp, 0, 720, 20, EASING_QUADRATIC_OUT)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetNpcRotation, NPC_GuardBoo, 0, LVar0, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GuardBoo_ReturnToPost) = {
    EVT_WAIT(1)
    EVT_IF_EQ(MV_GuardDancing, TRUE)
        EVT_WAIT(150)
        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_DoNothing)))
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
        EVT_WAIT(90)
    EVT_ELSE
        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_DoNothing)))
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(AwaitPlayerLeave, 168, -136, 50)
    EVT_CALL(MakeLerp, 180, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_GuardBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_GuardBoo, 168, 0, -136)
    EVT_CALL(MakeLerp, 0, 180, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_GuardBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(MV_GuardDancing, FALSE)
    EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_Wary)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateGuardBoo) = {
    EVT_SET(MV_GuardDancing, FALSE)
    EVT_SET(MF_GuardBusy, FALSE)
    EVT_CALL(InterpNpcYaw, NPC_GuardBoo, 270, 5)
    EVT_SET(LVarC, 0)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
        EVT_IF_LE(LVar0, -92)
            EVT_SET(MV_GuardDancing, TRUE)
            EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_Dancing)))
            EVT_RETURN
        EVT_END_IF
        EVT_IF_EQ(LVarA, 0)
            EVT_CALL(N(UpdateGuardBooPos))
            EVT_IF_NE(LVarC, 0)
                EVT_SUB(LVarC, 1)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_ELSE
            EVT_IF_NE(LVarC, 0)
                EVT_CALL(N(UpdateGuardBooPos))
                EVT_IF_NE(LVarC, 0)
                    EVT_SUB(LVarC, 1)
                EVT_END_IF
                EVT_WAIT(1)
            EVT_ELSE
                EVT_SET(LVarC, 20)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_LT(60)
                    EVT_CASE_LT(80)
                        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_DoNothing)))
                        EVT_SET(MF_GuardBusy, TRUE)
                        EVT_CALL(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
                        EVT_CALL(SetNpcJumpscale, NPC_GuardBoo, EVT_FLOAT(1.0))
                        EVT_CALL(NpcJump0, NPC_GuardBoo, LVar0, LVar1, LVar2, 10)
                        EVT_SET(MF_GuardBusy, FALSE)
                        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_Wary)))
                    EVT_CASE_LT(99)
                        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_DoNothing)))
                        EVT_SET(MF_GuardBusy, TRUE)
                        EVT_CALL(MakeLerp, 0, 720, 20, EASING_QUADRATIC_OUT)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_CALL(SetNpcRotation, NPC_GuardBoo, 0, LVar0, 0)
                            EVT_WAIT(1)
                            EVT_IF_EQ(LVar1, 0)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_SET(MF_GuardBusy, FALSE)
                        EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_Wary)))
                EVT_END_SWITCH
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVarB, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DummyUpdateGuardBoo) = {
    EVT_LOOP(0)
        EVT_CALL(N(GuardBooDoNothing))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GuardBooVanish) = {
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(PlaySoundAtNpc, NPC_GuardBoo, SOUND_BOO_SPOOK, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_GuardBoo, ANIM_Boo_Spook)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 255, 0, 60, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_GuardBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_GuardBoo, NPC_DISPOSE_LOCATION)
    EVT_SET(MV_GuardDeparted, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_GuardBoo) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_PLAYED_THE_RECORD)
            EVT_IF_EQ(GF_OBK08_Item_Record, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0036)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0035)
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH3_PLAYED_THE_RECORD)
            EVT_IF_EQ(MV_GuardDancing, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0037)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0038)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_PlayerGotChestItem) = {
    EVT_KILL_THREAD(MV_GuardReturnScript)
    EVT_CALL(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(BindNpcAI, NPC_GuardBoo, EVT_PTR(N(EVS_NpcAI_GuardBoo_DoNothing)))
    EVT_CALL(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Cower, ANIM_Boo_Cower, 0, MSG_CH3_0039)
    EVT_CALL(SetNpcAnimation, NPC_GuardBoo, ANIM_Boo_Idle)
    EVT_CALL(EndSpeech, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0)
    EVT_EXEC_WAIT(N(EVS_GuardBooVanish))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGuardBoo) = {
    EVT_CALL(SetNpcScale, NPC_GuardBoo, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetNpcCollisionSize, NPC_GuardBoo, 40, 40)
    EVT_CALL(N(InitGuardBooAlpha))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GuardBoo)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_GuardBoo_Wary)))
    EVT_CALL(SetNpcPos, NPC_GuardBoo, 168, 0, -136)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPhonograph) = {
    EVT_CALL(N(CreatePhonographData))
    EVT_CALL(ParentColliderToModel, COLLIDER_t, MODEL_rap)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_PLAYED_THE_RECORD)
        EVT_CALL(EnableModel, MODEL_reco, FALSE)
    EVT_END_IF
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_Inspect_Phonograph)), TRIGGER_WALL_PRESS_A, COLLIDER_o344, EVT_PTR(N(ItemList_Records)), 0, 1)
    EVT_RETURN
    EVT_END
};
