#include "mgm_00.h"

#define MINIGAME_TYPE_JUMP      1
#define MINIGAME_TYPE_SMASH     2

#define FADE_IN_TIME  5
#define FADE_OUT_TIME 5

typedef enum RecordDisplayState {
    RECORD_START_SHOW       = 0,
    RECORD_STATE_FADE_IN    = 1,
    RECORD_STATE_VISIBLE    = 2,
    RECORD_START_HIDE       = 3,
    RECORD_STATE_FADE_OUT   = 4,
    RECORD_STATE_DONE       = 5
} RecordDisplayState;

typedef struct RecordDisplayData {
    /* 0x00 */ RecordDisplayState state;
    /* 0x04 */ s32 stateTimer;
    /* 0x08 */ s32 gameType;
    /* 0x0C */ s32 alpha;
    /* 0x10 */ s32 curAlpha;
    /* 0x14 */ s32 workerID;
} RecordDisplayData; /* size = 0x18 */

EvtScript N(D_80243C40_E123E0) = {
    Return
    End
};

#if VERSION_PAL
s32  N(RecordBox_Widths)[] = {
  230, 238, 234, 246,
};

s32 N(RecordBox_OffsetsX)[] = {
    45, 41, 43, 37
};
#endif

Gfx N(Gfx_RecordDisplay_Init)[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
#if VERSION_US || VERSION_IQUE
    gsDPSetPrimColor(0, 0, 255, 0, 0, 0),
    gsDPFillRectangle(44, 49, 276, 51),
    gsDPFillRectangle(44, 49, 46, 133),
    gsDPFillRectangle(275, 49, 276, 133),
    gsDPFillRectangle(44, 132, 276, 133),
#elif VERSION_JP
    gsDPSetPrimColor(0, 0, 255, 0, 0, 0),
    gsDPFillRectangle(64, 49, 256, 51),
    gsDPFillRectangle(64, 49, 66, 133),
    gsDPFillRectangle(255, 49, 256, 133),
    gsDPFillRectangle(64, 132, 256, 133),
#endif
    gsSPEndDisplayList(),
};

#if VERSION_PAL
#define RECORD_BOX_POSX        N(RecordBox_OffsetsX)[gCurrentLanguage]
#define RECORD_BOX_WIDTH       N(RecordBox_Widths)[gCurrentLanguage]
#define MSG_RESULT_JUMP_WIDTH  get_msg_width(MSG_MGM_001C, 0)
#define MSG_RESULT_SMASH_WIDTH get_msg_width(MSG_MGM_001D, 0)
#define NUMBER_X_OFFSET(x)     (x + 174)
#elif VERSION_JP
#define RECORD_BOX_POSX        65
#define RECORD_BOX_WIDTH       190
#define MSG_RESULT_JUMP_WIDTH  164
#define MSG_RESULT_SMASH_WIDTH 164
#define RESULT_COL1_X          87
#define RESULT_COL2_X          211
#define NUMBER_X_OFFSET(x)     144
#else
#define RECORD_BOX_POSX        45
#define RECORD_BOX_WIDTH       230
#define MSG_RESULT_JUMP_WIDTH  188
#define MSG_RESULT_SMASH_WIDTH 192
#define RESULT_COL1_X          (RECORD_BOX_POSX + 13)
#define RESULT_COL2_X          (RECORD_BOX_POSX + 178)
#define NUMBER_X_OFFSET(x)     174
#endif

void N(draw_record_display)(RecordDisplayData* data, s32 alpha) {
#if VERSION_PAL
    s32 var_fp;
    s32 GamePlaysMsg;
    s32 GameTotalMsg;
    s32 GameRecordMsg;
#endif

    if (alpha > 0) {
        gSPDisplayList(gMainGfxPos++, N(Gfx_RecordDisplay_Init));
#if VERSION_PAL
        var_fp = gCurrentLanguage == LANGUAGE_FR ? 36 : 0;
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 0, 0, 0);
        gDPFillRectangle(gMainGfxPos++, RECORD_BOX_POSX - 1,                 49, RECORD_BOX_POSX + RECORD_BOX_WIDTH + 1,  51);
        gDPFillRectangle(gMainGfxPos++, RECORD_BOX_POSX - 1,                 49, RECORD_BOX_POSX + 1,                    133);
        gDPFillRectangle(gMainGfxPos++, RECORD_BOX_POSX + RECORD_BOX_WIDTH,  49, RECORD_BOX_POSX + RECORD_BOX_WIDTH + 1, 133);
        gDPFillRectangle(gMainGfxPos++, RECORD_BOX_POSX - 1,                132, RECORD_BOX_POSX + RECORD_BOX_WIDTH + 1, 133);
#endif
        gDPPipeSync(gMainGfxPos++);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 16, 120, 24, alpha * 0.65);
        gDPFillRectangle(gMainGfxPos++, RECORD_BOX_POSX + 3, 53, RECORD_BOX_POSX + RECORD_BOX_WIDTH - 3, 129);
        gDPPipeSync(gMainGfxPos++);
        msg_draw_frame(RECORD_BOX_POSX, 50, RECORD_BOX_WIDTH, 82, MSG_STYLE_INSPECT, 0, 1, (s32)(alpha * 0.55), alpha); // cast needed if signature isn't present
        if (data->gameType == MINIGAME_TYPE_JUMP) {
            s32 posX = NUMBER_X_OFFSET(var_fp);  //! required to match

            draw_msg(MSG_MGM_001C, RECORD_BOX_POSX + (RECORD_BOX_WIDTH - MSG_RESULT_JUMP_WIDTH) / 2, 57, alpha, MSG_PAL_TEAL, 0);
            draw_number(gPlayerData.jumpGamePlays,   RECORD_BOX_POSX + posX, 78,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.jumpGameTotal,   RECORD_BOX_POSX + posX, 93,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.jumpGameRecord,  RECORD_BOX_POSX + posX, 108, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);

#if VERSION_PAL
            GamePlaysMsg  = gPlayerData.jumpGamePlays == 1 ? MSG_PAL_MGM_0024 : MSG_MGM_0023;
            GameTotalMsg  = gPlayerData.jumpGameTotal == 1 ? MSG_PAL_MGM_0021 : MSG_MGM_0021;
            GameRecordMsg = gPlayerData.jumpGameRecord == 1 ? MSG_PAL_MGM_0021 : MSG_MGM_0021;
#endif
        } else {
            s32 posX = NUMBER_X_OFFSET(var_fp);  //! required, cannot be merged to the same var above

            draw_msg(MSG_MGM_001D, RECORD_BOX_POSX + (RECORD_BOX_WIDTH - MSG_RESULT_SMASH_WIDTH) / 2, 57, alpha, MSG_PAL_TEAL, 0);
            draw_number(gPlayerData.smashGamePlays,  RECORD_BOX_POSX + posX, 78,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.smashGameTotal,  RECORD_BOX_POSX + posX, 93,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.smashGameRecord, RECORD_BOX_POSX + posX, 108, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);

#if VERSION_PAL
            GamePlaysMsg  = gPlayerData.smashGamePlays == 1 ? MSG_PAL_MGM_0024 : MSG_MGM_0023;
            GameTotalMsg  = gPlayerData.smashGameTotal == 1 ? MSG_PAL_MGM_0021 : MSG_MGM_0021;
            GameRecordMsg = gPlayerData.smashGameRecord == 1 ? MSG_PAL_MGM_0021 : MSG_MGM_0021;
#endif
        }

#if VERSION_PAL
        draw_msg(MSG_MGM_001E, RECORD_BOX_POSX + 13,  78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        if (gCurrentLanguage != LANGUAGE_FR) {
            s32 width2 = var_fp + 178;  //! required to match and can't be merged with the same two below
            draw_msg(GamePlaysMsg, RECORD_BOX_POSX + width2,  78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        }
        draw_msg(MSG_MGM_001F, RECORD_BOX_POSX + 13,  93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        if (gCurrentLanguage != LANGUAGE_FR) {
            s32 width2 = var_fp + 178;
            draw_msg(GameTotalMsg, RECORD_BOX_POSX + width2,  93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        }
        draw_msg(MSG_MGM_0020, RECORD_BOX_POSX + 13,  108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        if (gCurrentLanguage != LANGUAGE_FR) {
            s32 width2 = var_fp + 178;
            draw_msg(GameRecordMsg,RECORD_BOX_POSX + width2, 108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        }
#else
        draw_msg(MSG_MGM_001E, RESULT_COL1_X, 78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0023, RESULT_COL2_X, 78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_001F, RESULT_COL1_X, 93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0021, RESULT_COL2_X, 93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0020, RESULT_COL1_X, 108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0021, RESULT_COL2_X, 108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
#endif
    }
}

void N(animate_and_draw_record)(void* renderData) {
    RecordDisplayData* data = (RecordDisplayData*)evt_get_variable(nullptr, MV_RecordDisplayData);

    switch (data->state) {
        case RECORD_START_SHOW:
            data->stateTimer = 0;
            data->state = RECORD_STATE_FADE_IN;
            snd_start_sound(SOUND_APPROVE, 0, 0);
            // fallthrough
        case RECORD_STATE_FADE_IN:
            data->stateTimer++;
            data->alpha = update_lerp(EASING_LINEAR, 32.0f, 255.0f, data->stateTimer, FADE_IN_TIME);
            data->curAlpha = data->alpha;
            if (data->stateTimer >= FADE_IN_TIME) {
                data->state = RECORD_STATE_VISIBLE;
                data->alpha = 255;
                data->curAlpha = 255;
            }
            break;
        case RECORD_STATE_VISIBLE:
            data->alpha = 255;
            data->curAlpha = 255;
            if (gGameStatusPtr->curButtons[0] & (BUTTON_A | BUTTON_B)) {
                data->state = RECORD_START_HIDE;
            }
            if (data->state != RECORD_START_HIDE) {
                break;
            }
            // fallthrough
        case RECORD_START_HIDE:
            data->stateTimer = 0;
            data->state = RECORD_STATE_FADE_OUT;
            snd_start_sound(SOUND_MENU_BACK, 0, 0);
            // fallthrough
        case RECORD_STATE_FADE_OUT:
            data->stateTimer++;
            data->alpha = update_lerp(EASING_LINEAR, data->curAlpha, 0.0f, data->stateTimer, FADE_OUT_TIME);
            if (data->stateTimer >= FADE_OUT_TIME) {
                data->state = RECORD_STATE_DONE;
            }
            break;
    }
    N(draw_record_display)(data, data->alpha);
}

void N(work_draw_record)(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;
    task.appendGfxArg = 0;
    task.appendGfx = &N(animate_and_draw_record);
    task.dist = 0;

    queue_render_task(&task);
}

API_CALLABLE(N(UpdateRecordDisplay)) {
    RecordDisplayData* data;
    Bytecode* args = script->ptrReadPos;
    s32 gameType = evt_get_variable(script, *args++);

    if (isInitialCall) {
        data = heap_malloc(sizeof(*data));
        script->functionTempPtr[0] = data;
        data->state = RECORD_START_SHOW;
        data->alpha = 255;
        data->workerID = create_worker_scene(nullptr, &N(work_draw_record));
        data->gameType = gameType;
        evt_set_variable(script, MV_RecordDisplayData, (s32)data);
    }
    data = script->functionTempPtr[0];
    if (data->state == RECORD_STATE_DONE) {
        free_worker(data->workerID);
        heap_free(data);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_OnInteract_JumpRecords) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(N(UpdateRecordDisplay), MINIGAME_TYPE_JUMP)
    Call(DisablePlayerInput, false)
    Call(DisablePlayerPhysics, false)
    Return
    End
};

EvtScript N(EVS_OnInteract_SmashRecords) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(N(UpdateRecordDisplay), MINIGAME_TYPE_SMASH)
    Call(DisablePlayerInput, false)
    Call(DisablePlayerPhysics, false)
    Return
    End
};

EvtScript N(EVS_BindInteractTriggers) = {
    BindTrigger(Ref(N(EVS_OnInteract_JumpRecords)), TRIGGER_WALL_PRESS_A, COLLIDER_score1, 1, 0)
    BindTrigger(Ref(N(EVS_OnInteract_SmashRecords)), TRIGGER_WALL_PRESS_A, COLLIDER_score2, 1, 0)
    Return
    End
};
