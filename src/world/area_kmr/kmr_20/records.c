#include "kmr_20.h"

#include "world/area_kmr/kmr_20/records_screen.gfx.inc.c"

enum {
    RECORDS_STATE_BEGIN_FADE_IN     = 0,
    RECORDS_STATE_FADING_IN         = 1,
    RECORDS_STATE_IDLE              = 2,
    RECORDS_STATE_BEGIN_FADE_OUT    = 3,
    RECORDS_STATE_FADING_OUT        = 4,
    RECORDS_STATE_DONE              = 5,
};

typedef struct GameRecords {
    /* 0x00 */ u16 state;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s32 lerpTime;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0xC];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 alpha;
    /* 0x1C */ s16 lastAlpha;
    /* 0x1E */ char unk_1E[0x2];
    /* 0x20 */ s32 workerID;
    /* 0x24 */ u16 equippedBadges;
    /* 0x26 */ s16 recipesFoundCount;
    /* 0x28 */ s16 totalRecipesCount;
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

void N(appendGfx_records_impl)(GameRecords* records, s32 alpha) {
    s32 width;

#if VERSION_PAL
#define CHARSET (1)
#else
#define CHARSET (0)
#endif

    if (alpha > 0) {
#if VERSION_JP
        gSPDisplayList(gMainGfxPos++, N(records_screen_gfx));
        gDPPipeSync(gMainGfxPos++);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 16, 120, 24, alpha * 0.65);
        gDPFillRectangle(gMainGfxPos++, 63, 43, 257, 192);
        gDPPipeSync(gMainGfxPos++);

        msg_draw_frame(60, 40, 200, 155, MSG_STYLE_INSPECT, MSG_PAL_WHITE, true, alpha * 0.55, alpha);
        draw_msg(MSG_CH0_00FC, 88, 50, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.totalCoinsEarned, 194, 50, 1, MSG_PAL_WHITE, alpha, 2);
        draw_msg(MSG_CH0_00FD, 124, 65, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(records->equippedBadges, 209, 65, 1, MSG_PAL_WHITE, alpha, 3);
        draw_msg(MSG_MenuTip_0034, 210, 63, alpha, MSG_PAL_WHITE, 0);
        draw_number(80, 222, 65, 1, MSG_PAL_WHITE, alpha, 2);
        if (gPlayerData.starPiecesCollected == 0) {
            draw_msg(MSG_CH0_00FA, 139, 80, alpha, MSG_PAL_WHITE, 1);
        } else {
            draw_msg(MSG_CH0_00FB, 96, 80, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
            draw_number(gPlayerData.starPiecesCollected, 209, 80, 1, MSG_PAL_WHITE, alpha, 3);
            draw_msg(MSG_MenuTip_0034, 210, 78, alpha, MSG_PAL_WHITE, 0);
            draw_number(160, 222, 80, 1, MSG_PAL_WHITE, alpha, 2);
        }

        if (records->recipesFoundCount == 0) {
            draw_msg(MSG_CH0_00FA, 140, 95, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        } else {
            if (records->recipesFoundCount == -1) {
                draw_msg(MSG_CH0_00FE, 103, 95, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
                draw_number(0, 209, 95, 1, MSG_PAL_WHITE, alpha, 3);
            } else {
                draw_msg(MSG_CH0_00FE, 103, 95, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
                draw_number(records->recipesFoundCount, 209, 95, 1, MSG_PAL_WHITE, alpha, 3);
            }
            draw_msg(MSG_MenuTip_0034, 210, 93, alpha, MSG_PAL_WHITE, 0);
            draw_number(records->totalRecipesCount, 222, 95, 1, MSG_PAL_WHITE, alpha, 2);
        }

        if (gPlayerData.quizzesAnswered == 0) {
            draw_msg(MSG_CH0_00FA, 139, 110, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        } else {
            draw_msg(MSG_CH0_00FF, 94, 110, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
            draw_number(gPlayerData.quizzesCorrect, 209, 110, 1, MSG_PAL_WHITE, alpha, 3);
            draw_msg(MSG_MenuTip_0034, 210, 108, alpha, MSG_PAL_WHITE, 0);
            draw_number(gPlayerData.quizzesAnswered, 222, 110, 1, MSG_PAL_WHITE, alpha, 2);
        }

        draw_msg(MSG_CH0_00F4, 93, 125, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.battlesCount, 194, 125, 1, MSG_PAL_WHITE, alpha, 2);
        draw_msg(MSG_CH0_00F7, 84, 140, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.playerFirstStrikes, 194, 140, 1, MSG_PAL_WHITE, alpha, 2);
        draw_msg(MSG_CH0_00F8, 75, 155, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.enemyFirstStrikes, 194, 155, 1, MSG_PAL_WHITE, alpha, 2);

        if (gPlayerData.powerBounces == 0) {
            draw_msg(MSG_CH0_00FA, 139, 170, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        } else {
            draw_msg(MSG_CH0_00F9, 102, 170, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
            draw_number(gPlayerData.powerBounces, 194, 170, 1, MSG_PAL_WHITE, alpha, 2);
        }
#else
        gSPDisplayList(gMainGfxPos++, N(records_screen_gfx));
        gDPPipeSync(gMainGfxPos++);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 16, 120, 24, alpha * 0.65);
        gDPFillRectangle(gMainGfxPos++, 33, 43, 287, 192);
        gDPPipeSync(gMainGfxPos++);

        msg_draw_frame(30, 40, 260, 155, MSG_STYLE_INSPECT, MSG_PAL_WHITE, true, alpha * 0.55, alpha);
        draw_msg(MSG_CH0_00FC, 206 - get_msg_width(MSG_CH0_00FC, CHARSET), 50, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.totalCoinsEarned, 216, 51, 1, MSG_PAL_WHITE, alpha, 2);
        draw_msg(MSG_CH0_00FD, 206 - get_msg_width(MSG_CH0_00FD, CHARSET), 65, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(records->equippedBadges, 231, 66, 1, MSG_PAL_WHITE, alpha, 3);
        draw_msg(MSG_MenuTip_0034, 232, 63, alpha, MSG_PAL_WHITE, 0);
        draw_number(80, 244, 66, 1, MSG_PAL_WHITE, alpha, 2);
        if (gPlayerData.starPiecesCollected == 0) {
            draw_msg(MSG_CH0_00FA, 109, 80, alpha, MSG_PAL_WHITE, 1);
        } else {
            draw_msg(MSG_CH0_00FB, 206 - get_msg_width(MSG_CH0_00FB, CHARSET), 80, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
            draw_number(gPlayerData.starPiecesCollected, 231, 81, 1, MSG_PAL_WHITE, alpha, 3);
            draw_msg(MSG_MenuTip_0034, 232, 78, alpha, MSG_PAL_WHITE, 0);
            draw_number(160, 244, 80, 1, MSG_PAL_WHITE, alpha, 2);
        }

        width = get_msg_width(MSG_CH0_00FE, CHARSET);
        if (records->recipesFoundCount == 0) {
            draw_msg(MSG_CH0_00FA, 110, 95, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        } else {
            if (records->recipesFoundCount == -1) {
                draw_msg(MSG_CH0_00FE, 206 - width, 95, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
                draw_number(0, 231, 96, 1, MSG_PAL_WHITE, alpha, 3);
            } else {
                draw_msg(MSG_CH0_00FE, 206 - width, 95, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
                draw_number(records->recipesFoundCount, 231, 96, 1, MSG_PAL_WHITE, alpha, 3);
            }
            draw_msg(MSG_MenuTip_0034, 232, 93, alpha, MSG_PAL_WHITE, 0);
            draw_number(records->totalRecipesCount, 244, 95, 1, MSG_PAL_WHITE, alpha, 2);
        }

        if (gPlayerData.quizzesAnswered == 0) {
            draw_msg(MSG_CH0_00FA, 109, 110, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        } else {
            draw_msg(MSG_CH0_00FF, 206 - get_msg_width(MSG_CH0_00FF, CHARSET), 110, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
            draw_number(gPlayerData.quizzesCorrect, 231, 111, 1, MSG_PAL_WHITE, alpha, 3);
            draw_msg(MSG_MenuTip_0034, 232, 108, alpha, MSG_PAL_WHITE, 0);
            draw_number(gPlayerData.quizzesAnswered, 244, 111, 1, MSG_PAL_WHITE, alpha, 2);
        }

        draw_msg(MSG_CH0_00F4, 206 - get_msg_width(MSG_CH0_00F4, CHARSET), 125, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.battlesCount, 216, 126, 1, MSG_PAL_WHITE, alpha, 2);
        width = get_msg_width(MSG_CH0_00F7, CHARSET);
        draw_msg(MSG_CH0_00F7, 206 - width, 140, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.playerFirstStrikes, 216, 141, 1, MSG_PAL_WHITE, alpha, 2);
        draw_msg(MSG_CH0_00F8, 206 - get_msg_width(MSG_CH0_00F8, CHARSET), 155, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_number(gPlayerData.enemyFirstStrikes, 216, 156, 1, MSG_PAL_WHITE, alpha, 2);

        if (gPlayerData.powerBounces == 0) {
            draw_msg(MSG_CH0_00FA, 109, 170, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        } else {
            draw_msg(MSG_CH0_00F9, 206 - get_msg_width(MSG_CH0_00F9, CHARSET), 170, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
            draw_number(gPlayerData.powerBounces, 216, 171, 1, MSG_PAL_WHITE, alpha, 2);
        }
#endif
    }

#undef CHARSET
}

void N(appendGfx_records)(void* data) {
    GameRecords* records = (GameRecords*) evt_get_variable(nullptr, MV_RecordsDataPtr);

    switch (records->state) {
        case RECORDS_STATE_BEGIN_FADE_IN:
            records->unk_18 = 0;
            records->unk_08 = 0;
            records->unk_0A = 0;
            records->lerpTime = 0;
            records->state = RECORDS_STATE_FADING_IN;
            snd_start_sound(SOUND_APPROVE, 0, 0);
            // fallthrough
        case RECORDS_STATE_FADING_IN:
            records->lerpTime++;
            records->alpha = update_lerp(EASING_LINEAR, 32.0f, 255.0f, records->lerpTime, 3);
            records->lastAlpha = records->alpha;
            if (records->lerpTime >= 3) {
                records->state = RECORDS_STATE_IDLE;
                records->alpha = 255;
                records->lastAlpha = records->alpha;
            }
            break;
        case RECORDS_STATE_IDLE:
            records->alpha = 255;
            records->lastAlpha = records->alpha;
            if (gGameStatusPtr->curButtons[0] & (BUTTON_A | BUTTON_B)) {
                records->state = RECORDS_STATE_BEGIN_FADE_OUT;
            }
            if (records->state != RECORDS_STATE_BEGIN_FADE_OUT) {
                break;
            }
        case RECORDS_STATE_BEGIN_FADE_OUT:
            records->lerpTime = 0;
            records->state = RECORDS_STATE_FADING_OUT;
            snd_start_sound(SOUND_MENU_BACK, 0, 0);
            // fallthrough
        case RECORDS_STATE_FADING_OUT:
            records->lerpTime++;
            records->alpha = update_lerp(EASING_LINEAR, records->lastAlpha, 0.0f, records->lerpTime, 3);
            if (records->lerpTime >= 3) {
                records->state = RECORDS_STATE_DONE;
            }
            break;
    }
    N(appendGfx_records_impl)(records, records->alpha);
}

void N(worker_draw_game_records)(void) {
    RenderTask rt;

    rt.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;
    rt.appendGfxArg = nullptr;
    rt.appendGfx = N(appendGfx_records);
    rt.dist = 0;
    queue_render_task(&rt);
}

void N(calculate_records)(GameRecords* records) {
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
    for (i = 0; true; i++) {
        if (N(RecipeFoundVars)[i] != 0) {
            if (evt_get_variable(nullptr, N(RecipeFoundVars)[i]) != 0) {
                count++;
            }
        } else {
            break;
        }
    }
    records->totalRecipesCount = i;
    records->recipesFoundCount = count;
    if (records->recipesFoundCount == 0 && evt_get_variable(nullptr, GF_MAC02_DiscoveredRecipe_12)) {
        records->recipesFoundCount = -1;
    }
}

API_CALLABLE(N(ShowGameRecords)) {
    GameRecords* records;

    if (isInitialCall) {
        records = script->functionTempPtr[0] = heap_malloc(sizeof(*records));
        records->state = RECORDS_STATE_BEGIN_FADE_IN;
        records->alpha = 255;
        records->workerID = create_worker_scene(nullptr, N(worker_draw_game_records));
        evt_set_variable(script, MV_RecordsDataPtr, (s32) records);
        N(calculate_records)(records);
    }

    records = script->functionTempPtr[0];
    if (records->state == RECORDS_STATE_DONE) {
        free_worker(records->workerID);
        heap_free(records);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Inspect_Records) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(GetPlayerPos, LVarA, LVarB, LVarC)
    Call(UseSettingsFrom, CAM_DEFAULT, LVarA, 30, LVarC)
    Call(SetPanTarget, CAM_DEFAULT, LVarA, 30, LVarC)
    Call(SetCamDistance, CAM_DEFAULT, Float(320.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.2))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(N(ShowGameRecords))
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.2))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Call(DisablePlayerPhysics, false)
    Return
    End
};
