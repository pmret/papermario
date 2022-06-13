#include "mgm_00.h"

void snd_start_sound(s32 soundID, u8 volume, u8 pan);
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, s32 bgAlpha, s32 frameAlpha);

extern Gfx D_80243C50_E123F0[];

#define RECORD_DISPLAY_MAP_VAR  0xA
#define MINIGAME_TYPE_SMASH     0
#define MINIGAME_TYPE_JUMP      1

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

void N(draw_record_display)(RecordDisplayData* data, s32 alpha) {
    if (alpha > 0) {
        gSPDisplayList(gMasterGfxPos++, D_80243C50_E123F0);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 16, 120, 24, alpha * 0.65);
        gDPFillRectangle(gMasterGfxPos++, 48, 53, 272, 129);
        gDPPipeSync(gMasterGfxPos++);
        msg_draw_frame(45, 50, 230, 82, 6, 0, 1, (s32)(alpha * 0.55), alpha); // cast needed if signature isn't present
        if (data->gameType == MINIGAME_TYPE_JUMP) {
            draw_msg(MESSAGE_ID(0x8,0x1C), 66, 57, alpha, MSG_PAL_TEAL, 0);
            draw_number(gPlayerData.jumpGamePlays,   219, 78,  TRUE, MSG_PAL_WHITE, alpha, 3);
            draw_number(gPlayerData.jumpGameTotal,   219, 93,  TRUE, MSG_PAL_WHITE, alpha, 3);
            draw_number(gPlayerData.jumpGameRecord,  219, 108, TRUE, MSG_PAL_WHITE, alpha, 3);
        } else {
            draw_msg(MESSAGE_ID(0x8,0x1D), 64, 57, alpha, MSG_PAL_TEAL, 0);
            draw_number(gPlayerData.smashGamePlays,  219, 78,  TRUE, MSG_PAL_WHITE, alpha, 3);
            draw_number(gPlayerData.smashGameTotal,  219, 93,  TRUE, MSG_PAL_WHITE, alpha, 3);
            draw_number(gPlayerData.smashGameRecord, 219, 108, TRUE, MSG_PAL_WHITE, alpha, 3);
        }

        draw_msg(MESSAGE_ID(0x8,0x1E), 58,  78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MESSAGE_ID(0x8,0x23), 223, 78,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MESSAGE_ID(0x8,0x1F), 58,  93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MESSAGE_ID(0x8,0x21), 223, 93,  alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MESSAGE_ID(0x8,0x20), 58,  108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
        draw_msg(MESSAGE_ID(0x8,0x21), 223, 108, alpha, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
    }
}

void N(animate_and_draw_record)(void* renderData) {
    RecordDisplayData* data = (RecordDisplayData*)evt_get_variable(NULL, GW(RECORD_DISPLAY_MAP_VAR));

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
            if (gGameStatusPtr->currentButtons[0] & (BUTTON_A | BUTTON_B)) {
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
    task.distance = 0;

    queue_render_task(&task);
}

ApiStatus N(UpdateRecordDisplay)(Evt* script, s32 isInitialCall) {
    RecordDisplayData* data;
    Bytecode* args = script->ptrReadPos;
    s32 gameType = evt_get_variable(script, *args++);

    if (isInitialCall) {
        data = heap_malloc(sizeof(*data));
        script->functionTempPtr[0] = data;
        data->state = RECORD_START_SHOW;
        data->alpha = 255;
        data->workerID = create_generic_entity_world(NULL, &N(work_draw_record));
        data->gameType = gameType;
        evt_set_variable(script, GW(RECORD_DISPLAY_MAP_VAR), (s32)data);
    }
    data = script->functionTempPtr[0];
    if (data->state == RECORD_STATE_DONE) {
        free_generic_entity(data->workerID);
        heap_free(data);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}
