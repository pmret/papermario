#include "kmr_20.h"

Gfx N(D_80252D50_8FEB70)[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0x00),
    gsDPFillRectangle(29, 39, 291, 41),
    gsDPFillRectangle(29, 39, 31, 196),
    gsDPFillRectangle(290, 39, 291, 196),
    gsDPFillRectangle(29, 195, 291, 196),
    gsSPEndDisplayList(),
};

typedef struct GameRecords {
    /* 0x00 */ u16 state;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0xC];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[0x2];
    /* 0x20 */ s32 workerID;
    /* 0x24 */ u16 equippedBadges;
    /* 0x26 */ s16 recipeCount;
    /* 0x28 */ s16 unk_28;
} GameRecords;

s32 N(RecipeFoundVars)[] = {
    GF_MAC02_DiscoveredRecipe_00, GF_MAC02_DiscoveredRecipe_01,
    GF_MAC02_DiscoveredRecipe_02, GF_MAC02_DiscoveredRecipe_03,
    GF_MAC02_DiscoveredRecipe_04, GF_MAC02_DiscoveredRecipe_05,
    GF_MAC02_DiscoveredRecipe_06, GF_MAC02_DiscoveredRecipe_07,
    GF_MAC02_DiscoveredRecipe_08, GF_MAC02_DiscoveredRecipe_09,
    GF_MAC02_DiscoveredRecipe_0A, GF_MAC02_DiscoveredRecipe_0B,
    GF_MAC02_DiscoveredRecipe_0C, GF_MAC02_DiscoveredRecipe_0D,
    GF_MAC02_DiscoveredRecipe_0E, GF_MAC02_DiscoveredRecipe_0F,
    GF_MAC02_DiscoveredRecipe_10, GF_MAC02_DiscoveredRecipe_11,
    GF_MAC02_DiscoveredRecipe_13, GF_MAC02_DiscoveredRecipe_14,
    GF_MAC02_DiscoveredRecipe_15, GF_MAC02_DiscoveredRecipe_16,
    GF_MAC02_DiscoveredRecipe_17, GF_MAC02_DiscoveredRecipe_18,
    GF_MAC02_DiscoveredRecipe_19, GF_MAC02_DiscoveredRecipe_1A,
    GF_MAC02_DiscoveredRecipe_1B, GF_MAC02_DiscoveredRecipe_1C,
    GF_MAC02_DiscoveredRecipe_1D, GF_MAC02_DiscoveredRecipe_1E,
    GF_MAC02_DiscoveredRecipe_1F, GF_MAC02_DiscoveredRecipe_20,
    GF_MAC02_DiscoveredRecipe_21, GF_MAC02_DiscoveredRecipe_22,
    GF_MAC02_DiscoveredRecipe_23, GF_MAC02_DiscoveredRecipe_24,
    GF_MAC02_DiscoveredRecipe_25, GF_MAC02_DiscoveredRecipe_26,
    GF_MAC02_DiscoveredRecipe_27, GF_MAC02_DiscoveredRecipe_28,
    GF_MAC02_DiscoveredRecipe_29, GF_MAC02_DiscoveredRecipe_2A,
    GF_MAC02_DiscoveredRecipe_2B, GF_MAC02_DiscoveredRecipe_2C,
    GF_MAC02_DiscoveredRecipe_2D, GF_MAC02_DiscoveredRecipe_2F,
    GF_MAC02_DiscoveredRecipe_30, GF_MAC02_DiscoveredRecipe_31,
    GF_MAC02_DiscoveredRecipe_32, GF_MAC02_DiscoveredRecipe_33,
    0 
};

void N(func_802421A0_8EDFC0)(GameRecords* records, s32 opacity) {
    s32 width;

    if (opacity > 0) {
        gSPDisplayList(gMasterGfxPos++, N(D_80252D50_8FEB70));
        gDPPipeSync(gMasterGfxPos++);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 16, 120, 24, opacity * 0.65);
        gDPFillRectangle(gMasterGfxPos++, 33, 43, 287, 192);
        gDPPipeSync(gMasterGfxPos++);

        msg_draw_frame(30, 40, 260, 155, 6, 0, 1, opacity * 0.55, opacity);
        draw_msg(MSG_CH0_00FC, 206 - get_msg_width(MSG_CH0_00FC, 0), 50, opacity, 0, 1);
        draw_number(gPlayerData.totalCoinsEarned, 216, 51, 1, 0, opacity, 2);
        draw_msg(MSG_CH0_00FD, 206 - get_msg_width(MSG_CH0_00FD, 0), 65, opacity, 0, 1);
        draw_number(records->equippedBadges, 231, 66, 1, 0, opacity, 3);
        draw_msg(MSG_MenuTip_0034, 232, 63, opacity, 0, 0);
        draw_number(80, 244, 66, 1, 0, opacity, 2);
        if (gPlayerData.starPiecesCollected == 0) {
            draw_msg(MSG_CH0_00FA, 109, 80, opacity, 0, 1);
        } else {
            draw_msg(MSG_CH0_00FB, 206 - get_msg_width(MSG_CH0_00FB, 0), 80, opacity, 0, 1);
            draw_number(gPlayerData.starPiecesCollected, 231, 81, 1, 0, opacity, 3);
            draw_msg(MSG_MenuTip_0034, 232, 78, opacity, 0, 0);
            draw_number(160, 244, 80, 1, 0, opacity, 2);
        }

        width = get_msg_width(MSG_CH0_00FE, 0);
        if (records->recipeCount == 0) {
            draw_msg(MSG_CH0_00FA, 110, 95, opacity, 0, 1);
        } else {
            if (records->recipeCount == -1) {
                draw_msg(MSG_CH0_00FE, 206 - width, 95, opacity, 0, 1);
                draw_number(0, 231, 96, 1, 0, opacity, 3);
            } else {
                draw_msg(MSG_CH0_00FE, 206 - width, 95, opacity, 0, 1);
                draw_number(records->recipeCount, 231, 96, 1, 0, opacity, 3);
            }
            draw_msg(MSG_MenuTip_0034, 232, 93, opacity, 0, 0);
            draw_number(records->unk_28, 244, 95, 1, 0, opacity, 2);
        }

        if (gPlayerData.quizzesAnswered == 0) {
            draw_msg(MSG_CH0_00FA, 109, 110, opacity, 0, 1);
        } else {
            draw_msg(MSG_CH0_00FF, 206 - get_msg_width(MSG_CH0_00FF, 0), 110, opacity, 0, 1);
            draw_number(gPlayerData.quizzesCorrect, 231, 111, 1, 0, opacity, 3);
            draw_msg(MSG_MenuTip_0034, 232, 108, opacity, 0, 0);
            draw_number(gPlayerData.quizzesAnswered, 244, 111, 1, 0, opacity, 2);
        }

        draw_msg(MSG_CH0_00F4, 206 - get_msg_width(MSG_CH0_00F4, 0), 125, opacity, 0, 1);
        draw_number(gPlayerData.battlesCount, 216, 126, 1, 0, opacity, 2);
        width = get_msg_width(MSG_CH0_00F7, 0);
        draw_msg(MSG_CH0_00F7, 206 - width, 140, opacity, 0, 1);
        draw_number(gPlayerData.playerFirstStrikes, 216, 141, 1, 0, opacity, 2);
        draw_msg(MSG_CH0_00F8, 206 - get_msg_width(MSG_CH0_00F8, 0), 155, opacity, 0, 1);
        draw_number(gPlayerData.enemyFirstStrikes, 216, 156, 1, 0, opacity, 2);

        if (gPlayerData.powerBounces == 0) {
            draw_msg(MSG_CH0_00FA, 109, 170, opacity, 0, 1);
        } else {
            draw_msg(MSG_CH0_00F9, 206 - get_msg_width(MSG_CH0_00F9, 0), 170, opacity, 0, 1);
            draw_number(gPlayerData.powerBounces, 216, 171, 1, 0, opacity, 2);
        }
    }
}

void N(func_80242870_8EE690)(void* data) {
    GameRecords* records = (GameRecords*) evt_get_variable(NULL, MapVar(10));
    s32 temp_f2;

    switch (records->state) {
        case 0:
            records->unk_18 = 0;
            records->unk_08 = 0;
            records->unk_0A = 0;
            records->unk_04 = 0;
            records->state = 1;
            snd_start_sound(SOUND_21C, 0, 0);
            // fallthrough
        case 1:
            records->unk_04++;
            temp_f2 = update_lerp(0, 32.0f, 255.0f, records->unk_04, 3);
            records->unk_1A = temp_f2;
            records->unk_1C = temp_f2;
            if (records->unk_04 >= 3) {
                records->state = 2;
                records->unk_1A = 255;
                records->unk_1C = 255;
            }
            break;
        case 2:
            records->unk_1A = 255;
            records->unk_1C = 255;
            if (gGameStatusPtr->currentButtons[0] & (BUTTON_A | BUTTON_B)) {
                records->state = 3;
            }
            if (records->state != 3) {
                break;
            }
        case 3:
            records->unk_04 = 0;
            records->state = 4;
            snd_start_sound(SOUND_MENU_BACK, 0, 0);
            // fallthrough
        case 4:
            records->unk_04++;
            records->unk_1A = update_lerp(0, records->unk_1C, 0.0f, records->unk_04, 3);
            if (records->unk_04 >= 3) {
                records->state = 5;
            }
            break;
    }
    N(func_802421A0_8EDFC0)(records, records->unk_1A);
}

void N(worker_draw_game_records)(void) {
    RenderTask rt;

    rt.renderMode = RENDER_MODE_2D;
    rt.appendGfxArg = NULL;
    rt.appendGfx = N(func_80242870_8EE690);
    rt.distance = 0;
    queue_render_task(&rt);
}

void N(func_80242A3C_8EE85C)(GameRecords* records) {
    PlayerData* playerData = &gPlayerData;
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        if (playerData->badges[i] != 0) {
            count++;
        }
    }
    records->equippedBadges = count;

    count = 0;
    for (i = 0; TRUE; i++) {
        if (N(RecipeFoundVars)[i] != 0) {
            if (evt_get_variable(NULL, N(RecipeFoundVars)[i]) != 0) {
                count++;
            }
        } else {
            break;
        }
    }
    records->unk_28 = i;
    records->recipeCount = count;
    if (records->recipeCount == 0 && evt_get_variable(NULL, GF_MAC02_DiscoveredRecipe_12)) {
        records->recipeCount = -1;
    }
}

API_CALLABLE(N(ShowGameRecords)) {
    GameRecords* records;

    if (isInitialCall) {
        records = script->functionTempPtr[0] = heap_malloc(sizeof(*records));
        records->state = 0;
        records->unk_1A = 255;
        records->workerID = create_worker_world(0, N(worker_draw_game_records));
        evt_set_variable(script, MapVar(10), (s32) records);
        N(func_80242A3C_8EE85C)(records);
    }

    records = script->functionTempPtr[0];
    if (records->state == 5) {
        free_worker(records->workerID);
        heap_free(records);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_80252E8C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, 30, LVarC)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, 30, LVarC)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(N(ShowGameRecords))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};
