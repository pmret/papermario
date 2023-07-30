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
    EVT_RETURN
    EVT_END
};

#if VERSION_PAL
s32  N(pal_unkdata)[] = {
  230, 238, 234, 246,
};

s32 N(pal_unkdata_2)[] = {
    45, 41, 43, 37
};

Gfx N(Gfx_RecordDisplay_Init)[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsSPEndDisplayList(),
};
#else
Gfx N(Gfx_RecordDisplay_Init)[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsDPSetPrimColor(0, 0, 255, 0, 0, 0),
    gsDPFillRectangle(44, 49, 276, 51),
    gsDPFillRectangle(44, 49, 46, 133),
    gsDPFillRectangle(275, 49, 276, 133),
    gsDPFillRectangle(44, 132, 276, 133),
    gsSPEndDisplayList(),
};
#endif

#if VERSION_PAL
void N(draw_record_display)(RecordDisplayData* data, s32 alpha);
INCLUDE_ASM(void, "world/area_mgm/mgm_00/mgm_00_3_scoreboard", mgm_00_draw_record_display);
#else
void N(draw_record_display)(RecordDisplayData* data, s32 alpha) {
    if (alpha > 0) {
        gSPDisplayList(gMainGfxPos++, N(Gfx_RecordDisplay_Init));
        gDPPipeSync(gMainGfxPos++);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 16, 120, 24, alpha * 0.65);
        gDPFillRectangle(gMainGfxPos++, 48, 53, 272, 129);
        gDPPipeSync(gMainGfxPos++);
        msg_draw_frame(45, 50, 230, 82, MSG_STYLE_INSPECT, 0, 1, (s32)(alpha * 0.55), alpha); // cast needed if signature isn't present
        if (data->gameType == MINIGAME_TYPE_JUMP) {
            draw_msg(MSG_MGM_001C, 66, 57, alpha, MSG_PAL_TEAL, 0);
            draw_number(gPlayerData.jumpGamePlays,   219, 78,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.jumpGameTotal,   219, 93,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.jumpGameRecord,  219, 108, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
        } else {
            draw_msg(MSG_MGM_001D, 64, 57, alpha, MSG_PAL_TEAL, 0);
            draw_number(gPlayerData.smashGamePlays,  219, 78,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.smashGameTotal,  219, 93,  DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            draw_number(gPlayerData.smashGameRecord, 219, 108, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
        }

        draw_msg(MSG_MGM_001E, 58,  78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0023, 223, 78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_001F, 58,  93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0021, 223, 93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0020, 58,  108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MSG_MGM_0021, 223, 108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
    }
}
#endif

void N(animate_and_draw_record)(void* renderData) {
    RecordDisplayData* data = (RecordDisplayData*)evt_get_variable(NULL, MV_RecordDisplayData);

    switch (data->state) {
        case RECORD_START_SHOW:
            data->stateTimer = 0;
            data->state = RECORD_STATE_FADE_IN;
            snd_start_sound(SOUND_21C, 0, 0);
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

    task.renderMode = RENDER_MODE_2D;
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
        data->workerID = create_worker_world(NULL, &N(work_draw_record));
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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(UpdateRecordDisplay), MINIGAME_TYPE_JUMP)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnInteract_SmashRecords) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(UpdateRecordDisplay), MINIGAME_TYPE_SMASH)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindInteractTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInteract_JumpRecords)), TRIGGER_WALL_PRESS_A, COLLIDER_score1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInteract_SmashRecords)), TRIGGER_WALL_PRESS_A, COLLIDER_score2, 1, 0)
    EVT_RETURN
    EVT_END
};
