#include "mgm_00.h"


extern Gfx* D_80243C50_E123F0;

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

//TODO: matches on decomp.me, but not OK here
INCLUDE_ASM(s32, "world/area_mgm/mgm_00/E0F980", func_802411E0_E0F980);

/*
void msg_draw_frame(s32 posX, s32 posY, s32 sizeX, s32 sizeY, s32 style, s32 palette, s32 fading, u8 bgAlpha, u8 frameAlpha);

void func_802411E0_E0F980(RecordDisplayData* data, s32 alpha) {
    if (alpha > 0) {
        gSPDisplayList(gMasterGfxPos++, D_80243C50_E123F0);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 16, 120, 24, alpha * 0.65);
        gDPFillRectangle(gMasterGfxPos++, 48, 53, 272, 129);
        gDPPipeSync(gMasterGfxPos++);
        msg_draw_frame(0x2D, 0x32, 0xE6, 0x52, 6, 0, 1, alpha * 0.55, alpha);
        if (data->gameType == 1) {
            draw_msg(0x8001C, 0x42, 0x39, alpha, 1, 0);
            draw_number(gPlayerData.jumpGamePlays, 0xDB, 0x4E, 1, 0, alpha, 3);
            draw_number(gPlayerData.jumpGameTotal, 0xDB, 0x5D, 1, 0, alpha, 3);
            draw_number(gPlayerData.jumpGameRecord, 0xDB, 0x6C, 1, 0, alpha, 3);
        } else {
            draw_msg(0x8001D, 0x40, 0x39, alpha, 1, 0);
            draw_number(gPlayerData.smashGamePlays, 0xDB, 0x4E, 1, 0, alpha, 3);
            draw_number(gPlayerData.smashGameTotal, 0xDB, 0x5D, 1, 0, alpha, 3);
            draw_number(gPlayerData.smashGameRecord, 0xDB, 0x6C, 1, 0, alpha, 3);
        }
        
        draw_msg(0x8001E, 0x3A, 0x4E, alpha, 0, 1);
        draw_msg(0x80023, 0xDF, 0x4E, alpha, 0, 1);
        draw_msg(0x8001F, 0x3A, 0x5D, alpha, 0, 1);
        draw_msg(0x80021, 0xDF, 0x5D, alpha, 0, 1);
        draw_msg(0x80020, 0x3A, 0x6C, alpha, 0, 1);
        draw_msg(0x80021, 0xDF, 0x6C, alpha, 0, 1);
    }
}
*/

void func_80241540_E0FCE0(void) {
    RecordDisplayData* data = (RecordDisplayData*)evt_get_variable(NULL, GW(0xA));

    switch (data->state) {
    case RECORD_START_SHOW:
        data->stateTimer = 0;
        data->state = RECORD_STATE_FADE_IN;
        snd_start_sound(SOUND_21C, 0, 0);
        /* fallthrough */
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
        if (gGameStatusPtr->currentButtons & (BUTTON_A | BUTTON_B)) {
            data->state = RECORD_START_HIDE;
        }
        if (data->state != RECORD_START_HIDE) {
            break;
        }
        /* fallthrough */
    case RECORD_START_HIDE:
        data->stateTimer = 0;
        data->state = RECORD_STATE_FADE_OUT;
        snd_start_sound(SOUND_MENU_BACK, 0, 0);
        /* fallthrough */
    case RECORD_STATE_FADE_OUT:
        data->stateTimer++;
        data->alpha = update_lerp(EASING_LINEAR, data->curAlpha, 0.0f, data->stateTimer, FADE_OUT_TIME);
        if (data->stateTimer >= FADE_OUT_TIME) {
            data->state = RECORD_STATE_DONE;
        }
        break;
    }
    func_802411E0_E0F980(data, data->alpha);
}

/* N(work_draw_record) */
void func_802416C0_E0FE60(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_2D;
    task.appendGfxArg = 0;
    task.appendGfx = &func_80241540_E0FCE0;
    task.distance = 0;

    queue_render_task(&task);
}

/* N(UpdateRecordDisplay) */
ApiStatus func_802416F8_E0FE98(Evt* script, s32 isInitialCall) {
    RecordDisplayData* data;
    s32 gameType;

    gameType = evt_get_variable(script, *script->ptrReadPos);
    if (isInitialCall) {
        data = (RecordDisplayData*)heap_malloc(sizeof(RecordDisplayData));
        script->functionTemp[0] = data;
        data->state = RECORD_START_SHOW;
        data->alpha = 255;
        data->workerID = create_generic_entity_world(0, &func_802416C0_E0FE60);
        data->gameType = gameType;
        evt_set_variable(script, GW(0xA), data);
    }
    data = script->functionTemp[0];
    if (data->state == RECORD_STATE_DONE) {
        free_generic_entity(data->workerID);
        heap_free(data);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}
