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
    Label(30)
        Call(MakeLerp, 100, 200, 30, EASING_COS_IN_OUT)
        Label(31)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            Call(N(GetPhonographScaleDivisor))
            DivF(LVar2, LVar3)
            Call(N(SetPhonographScale))
            Wait(1)
            IfEq(LVar1, 1)
                Goto(31)
            EndIf
        Call(MakeLerp, 200, 100, 30, EASING_COS_IN_OUT)
        Label(32)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            Call(N(GetPhonographScaleDivisor))
            DivF(LVar2, LVar3)
            Call(N(SetPhonographScale))
            Wait(1)
            IfEq(LVar1, 1)
                Goto(32)
            EndIf
        Goto(30)
    Return
    End
};

EvtScript N(EVS_UpdateCrankRotation) = {
    Set(LVar0, 0)
    Label(10)
        Call(N(SetCrankRotation))
        Add(LVar0, 2)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_UpdateRecordRotation) = {
    Set(LVar0, 0)
    Label(20)
        Call(N(SetRecordRotation))
        Add(LVar0, 10)
        Wait(1)
        Goto(20)
    Return
    End
};

EvtScript N(EVS_SetPhonographScale) = {
    Set(MF_CancelScaleScript, FALSE)
    Loop(0)
        IfEq(MF_CancelScaleScript, TRUE)
            Call(N(CheckScaleNearUnity))
            IfEq(LVar2, 1)
                BreakLoop
            EndIf
        EndIf
        Call(N(SaveLastUpdateValue))
        Call(N(GetPhonographScale))
        Call(ScaleModel, MODEL_rap, LVar0, LVar0, LVar0)
        Call(UpdateColliderTransform, COLLIDER_t)
        Wait(1)
    EndLoop
    Set(MF_CancelScaleScript, FALSE)
    Call(ScaleModel, MODEL_rap, 1, 1, 1)
    Return
    End
};

EvtScript N(EVS_SetCrankRotation) = {
    Set(MF_CancelCrankScript, FALSE)
    Loop(0)
        IfEq(MF_CancelCrankScript, TRUE)
            Call(N(CheckAngleNearZero))
            IfEq(LVar2, 1)
                BreakLoop
            EndIf
        EndIf
        Call(N(SaveLastUpdateValue))
        Call(N(GetCrankRotation))
        Call(RotateGroup, MODEL_bo, LVar0, 1, 0, 0)
        Wait(1)
    EndLoop
    Set(MF_CancelCrankScript, FALSE)
    Call(RotateGroup, MODEL_bo, 0, 1, 0, 0)
    Return
    End
};

EvtScript N(EVS_SetRecordRotation) = {
    Set(MF_CancelRecordScript, FALSE)
    Loop(0)
        IfEq(MF_CancelRecordScript, TRUE)
            Call(N(CheckAngleNearZero))
            IfEq(LVar2, 1)
                BreakLoop
            EndIf
        EndIf
        Call(N(SaveLastUpdateValue))
        Call(N(GetRecordRotation))
        Call(RotateGroup, MODEL_rec, LVar0, 0, -1, 0)
        Wait(1)
    EndLoop
    Set(MF_CancelRecordScript, FALSE)
    Call(RotateGroup, MODEL_rec, 0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_WindDownPhonograph) = {
    Set(MV_WindingDown, TRUE)
    Call(MakeLerp, MV_MashInputsAmount, 0, LVar0, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(func_80240EF8_BCFAE8))
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
    // signal scripts should stop
    Set(MF_CancelScaleScript, TRUE)
    Set(MF_CancelCrankScript, TRUE)
    Set(MF_CancelRecordScript, TRUE)
    // wait for canceled scripts to end
    Loop(0)
        Wait(1)
        IfEq(MF_CancelScaleScript, FALSE)
            IfEq(MF_CancelCrankScript, FALSE)
                IfEq(MF_CancelRecordScript, FALSE)
                    BreakLoop
                EndIf
            EndIf
        EndIf
    EndLoop
    // kill the completed scripts
    KillThread(MV_UpdateScaleScript)
    KillThread(MV_UpdateCrankScript)
    KillThread(MV_UpdateRecordScript)
    Exec(N(EVS_SetupMusic))
    Set(MV_WindingDown, FALSE)
    Return
    End
};

EvtScript N(EVS_PlayPhonograph) = {
    IfEq(MV_WindingDown, TRUE)
        IsThreadRunning(MV_WindDownScript, LVar0)
        IfEq(LVar0, 1)
            KillThread(MV_WindDownScript)
            IsThreadRunning(MV_UpdateScaleScript, LVar0)
            IfEq(LVar0, 1)
                KillThread(MV_UpdateScaleScript)
            EndIf
            IsThreadRunning(MV_UpdateCrankScript, LVar0)
            IfEq(LVar0, 1)
                KillThread(MV_UpdateCrankScript)
            EndIf
            IsThreadRunning(MV_UpdateRecordScript, LVar0)
            IfEq(LVar0, 1)
                KillThread(MV_UpdateRecordScript)
            EndIf
            IsThreadRunning(MV_SetScaleScript, LVar0)
            IfEq(LVar0, 1)
                KillThread(MV_SetScaleScript)
            EndIf
            IsThreadRunning(MV_SetCrankScript, LVar0)
            IfEq(LVar0, 1)
                KillThread(MV_SetCrankScript)
            EndIf
            IsThreadRunning(MV_SetRecordScript, LVar0)
            IfEq(LVar0, 1)
                KillThread(MV_SetRecordScript)
            EndIf
        EndIf
    EndIf
    Call(SetPlayerSpeed, Float(2.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar2, -170)
        Goto(33)
    EndIf
    Label(11)
    Call(PlayerMoveTo, -202, -170, 0)
    Label(33)
    Call(PlayerMoveTo, -216, -115, 0)
    Call(InterpPlayerYaw, 38, 1)
    Loop(0)
        // wait for tutorial message dismissal if there is one
        Wait(1)
        IfEq(MV_ReadyToPlay, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Wait(5)
    Call(N(CreatePhonographHudData))
    Call(N(PlayRecordSong))
    Wait(30)
    Call(N(InitPhonographHud))
    IfEq(MV_GuardDeparted, FALSE)
        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_Wary)))
        ExecGetTID(N(EVS_UpdateGuardBoo), MV_UpdateGuardScript)
    Else
        ExecGetTID(N(EVS_DummyUpdateGuardBoo), MV_UpdateGuardScript)
    EndIf
    ExecGetTID(N(EVS_UpdatePhonographScale), MV_UpdateScaleScript)
    ExecGetTID(N(EVS_UpdateCrankRotation),   MV_UpdateCrankScript)
    ExecGetTID(N(EVS_UpdateRecordRotation),  MV_UpdateRecordScript)
    ExecGetTID(N(EVS_SetPhonographScale),    MV_SetScaleScript)
    ExecGetTID(N(EVS_SetCrankRotation),      MV_SetCrankScript)
    ExecGetTID(N(EVS_SetRecordRotation),     MV_SetRecordScript)
    Call(N(SavePhonographUpdateScriptIDs))
    Loop(0)
        Call(N(func_80241790_BD0380))
        IfEq(LVar0, 1)
            Call(N(DestroyPhonographHudData))
            Wait(1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Loop(0)
        // wait for the guard to finish jumping or spinning
        Wait(1)
        IfEq(MF_GuardBusy, FALSE)
            BreakLoop
        EndIf
    EndLoop
    KillThread(MV_UpdateGuardScript)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    IfEq(MV_GuardDeparted, FALSE)
        IfEq(MV_GuardDancing, TRUE)
            Set(LVar0, 150)
        Else
            Set(LVar0, 80)
        EndIf
        ExecGetTID(N(EVS_WindDownPhonograph), MV_WindDownScript)
        ExecGetTID(N(EVS_GuardBoo_ReturnToPost), MV_GuardReturnScript)
    Else
        Set(LVar0, 80)
        ExecGetTID(N(EVS_WindDownPhonograph), MV_WindDownScript)
    EndIf
    Return
    End
};

EvtScript N(EVS_Inspect_Phonograph) = {
    IfEq(MV_GuardDancing, TRUE)
        IfEq(MV_GuardDeparted, FALSE)
            Return
        EndIf
    EndIf
    Call(DisablePlayerInput, TRUE)
    IfGe(GB_StoryProgress, STORY_CH3_PLAYED_THE_RECORD)
        Goto(50)
    EndIf
    // choose a record
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_Phonograph, 160, 40)
        Goto(100)
    EndIf
    IfEq(LVar0, -1)
        Goto(100)
    EndIf
    Call(N(GetSelectedRecordIndex))
    IfEq(LVar0, -1)
        Goto(100)
    EndIf
    Set(GB_OBK07_SelectedRecord, LVar0)
    Call(RemoveKeyItemAt, LVar1)
    Set(GB_StoryProgress, STORY_CH3_PLAYED_THE_RECORD)
    Call(EnableModel, MODEL_reco, TRUE)
    Call(SetPlayerAnimation, ANIM_MarioW1_CarryIdle)
    Wait(15)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(15)
    Call(CloseChoicePopup)
    // try playing
    Label(50)
    Set(MV_ReadyToPlay, TRUE)
    IfLt(GB_StoryProgress, STORY_CH3_GOT_WEIGHT)
        Set(MV_ReadyToPlay, FALSE)
        Thread
            Call(ShowMessageAtScreenPos, MSG_Menus_0181, 160, 40)
            Set(MV_ReadyToPlay, TRUE)
        EndThread
    EndIf
    ExecWait(N(EVS_PlayPhonograph))
    Return
    // done
    Label(100)
    Call(CloseChoicePopup)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcAI_GuardBoo_Wary) = {
    Call(SetNpcAnimation, NPC_GuardBoo, ANIM_Boo_Idle)
    Label(0)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Call(InterpNpcYaw, NPC_GuardBoo, 90, 5)
        Call(RandInt, 30, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Call(InterpNpcYaw, NPC_GuardBoo, 270, 5)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcAI_GuardBoo_DoNothing) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_GuardBoo_Dancing) = {
    Loop(0)
        Call(RandInt, 99, LVar0)
        Switch(LVar0)
            CaseLt(30)
                Call(RandInt, 10, LVar0)
                Add(LVar0, 10)
                Wait(LVar0)
                Call(InterpNpcYaw, NPC_GuardBoo, 90, 5)
                Call(RandInt, 10, LVar0)
                Add(LVar0, 10)
                Wait(LVar0)
                Call(InterpNpcYaw, NPC_GuardBoo, 270, 5)
            CaseLt(60)
                Call(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
                Call(SetNpcJumpscale, NPC_GuardBoo, Float(1.0))
                Call(NpcJump0, NPC_GuardBoo, LVar0, LVar1, LVar2, 10)
            CaseLt(99)
                Call(MakeLerp, 0, 720, 20, EASING_QUADRATIC_OUT)
                Loop(0)
                    Call(UpdateLerp)
                    Call(SetNpcRotation, NPC_GuardBoo, 0, LVar0, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
        EndSwitch
    EndLoop
    Return
    End
};

EvtScript N(EVS_GuardBoo_ReturnToPost) = {
    Wait(1)
    IfEq(MV_GuardDancing, TRUE)
        Wait(150)
        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_DoNothing)))
        Wait(1)
        Call(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
        Wait(90)
    Else
        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_DoNothing)))
        Wait(1)
        Call(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
    EndIf
    Call(AwaitPlayerLeave, 168, -136, 50)
    Call(MakeLerp, 180, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_GuardBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_GuardBoo, 168, 0, -136)
    Call(MakeLerp, 0, 180, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_GuardBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Set(MV_GuardDancing, FALSE)
    Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_Wary)))
    Return
    End
};

EvtScript N(EVS_UpdateGuardBoo) = {
    Set(MV_GuardDancing, FALSE)
    Set(MF_GuardBusy, FALSE)
    Call(InterpNpcYaw, NPC_GuardBoo, 270, 5)
    Set(LVarC, 0)
    Loop(0)
        Call(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
        IfLe(LVar0, -92)
            Set(MV_GuardDancing, TRUE)
            Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_Dancing)))
            Return
        EndIf
        IfEq(LVarA, 0)
            Call(N(UpdateGuardBooPos))
            IfNe(LVarC, 0)
                Sub(LVarC, 1)
            EndIf
            Wait(1)
        Else
            IfNe(LVarC, 0)
                Call(N(UpdateGuardBooPos))
                IfNe(LVarC, 0)
                    Sub(LVarC, 1)
                EndIf
                Wait(1)
            Else
                Set(LVarC, 20)
                Call(RandInt, 99, LVar0)
                Switch(LVar0)
                    CaseLt(60)
                    CaseLt(80)
                        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_DoNothing)))
                        Set(MF_GuardBusy, TRUE)
                        Call(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
                        Call(SetNpcJumpscale, NPC_GuardBoo, Float(1.0))
                        Call(NpcJump0, NPC_GuardBoo, LVar0, LVar1, LVar2, 10)
                        Set(MF_GuardBusy, FALSE)
                        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_Wary)))
                    CaseLt(99)
                        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_DoNothing)))
                        Set(MF_GuardBusy, TRUE)
                        Call(MakeLerp, 0, 720, 20, EASING_QUADRATIC_OUT)
                        Loop(0)
                            Call(UpdateLerp)
                            Call(SetNpcRotation, NPC_GuardBoo, 0, LVar0, 0)
                            Wait(1)
                            IfEq(LVar1, 0)
                                BreakLoop
                            EndIf
                        EndLoop
                        Set(MF_GuardBusy, FALSE)
                        Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_Wary)))
                EndSwitch
            EndIf
        EndIf
        IfEq(LVarB, 1)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_DummyUpdateGuardBoo) = {
    Loop(0)
        Call(N(GuardBooDoNothing))
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_GuardBooVanish) = {
    Thread
        Wait(25)
        Call(PlaySoundAtNpc, NPC_GuardBoo, SOUND_BOO_SPOOK, SOUND_SPACE_DEFAULT)
    EndThread
    Call(SetNpcAnimation, NPC_GuardBoo, ANIM_Boo_Spook)
    Wait(10)
    Call(MakeLerp, 255, 0, 60, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_GuardBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SetNpcPos, NPC_GuardBoo, NPC_DISPOSE_LOCATION)
    Set(MV_GuardDeparted, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_GuardBoo) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_PLAYED_THE_RECORD)
            IfEq(GF_OBK08_Item_Record, TRUE)
                Call(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0036)
            Else
                Call(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0035)
            EndIf
        CaseEq(STORY_CH3_PLAYED_THE_RECORD)
            IfEq(MV_GuardDancing, TRUE)
                Call(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0037)
            Else
                Call(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0038)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Scene_PlayerGotChestItem) = {
    KillThread(MV_GuardReturnScript)
    Call(SetNpcRotation, NPC_GuardBoo, 0, 0, 0)
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerInput, TRUE)
    Call(BindNpcAI, NPC_GuardBoo, Ref(N(EVS_NpcAI_GuardBoo_DoNothing)))
    Call(GetNpcPos, NPC_GuardBoo, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_GuardBoo, ANIM_Boo_Cower, ANIM_Boo_Cower, 0, MSG_CH3_0039)
    Call(SetNpcAnimation, NPC_GuardBoo, ANIM_Boo_Idle)
    Call(EndSpeech, NPC_GuardBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0)
    ExecWait(N(EVS_GuardBooVanish))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupGuardBoo) = {
    Call(SetNpcScale, NPC_GuardBoo, Float(1.0), Float(1.0), Float(1.0))
    Call(SetNpcCollisionSize, NPC_GuardBoo, 40, 40)
    Call(N(InitGuardBooAlpha))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GuardBoo)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_GuardBoo_Wary)))
    Call(SetNpcPos, NPC_GuardBoo, 168, 0, -136)
    Return
    End
};

EvtScript N(EVS_SetupPhonograph) = {
    Call(N(CreatePhonographData))
    Call(ParentColliderToModel, COLLIDER_t, MODEL_rap)
    IfLt(GB_StoryProgress, STORY_CH3_PLAYED_THE_RECORD)
        Call(EnableModel, MODEL_reco, FALSE)
    EndIf
    BindPadlock(Ref(N(EVS_Inspect_Phonograph)), TRIGGER_WALL_PRESS_A, COLLIDER_o344, Ref(N(ItemList_Records)), 0, 1)
    Return
    End
};
