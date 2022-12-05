#include "kmr_20.h"

typedef struct UnkKmr20 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0xC];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[0x2];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ u16 equippedBadges;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk_28;
} UnkKmr20;

extern Gfx D_80252D50_8FEB70[];
extern s32 D_80252DC0_8FEBE0[];

void func_802421A0_8EDFC0(UnkKmr20* arg0, s32 opacity) {
    s32 width;

    if (opacity > 0) {
        gSPDisplayList(gMasterGfxPos++, D_80252D50_8FEB70);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 16, 120, 24, opacity * 0.65);
        gDPFillRectangle(gMasterGfxPos++, 33, 43, 287, 192);
        gDPPipeSync(gMasterGfxPos++);

        msg_draw_frame(30, 40, 260, 155, 6, 0, 1, opacity * 0.55, opacity);
        draw_msg(0xB00FC, 206 - get_msg_width(0xB00FC, 0), 50, opacity, 0, 1);
        draw_number(gPlayerData.totalCoinsEarned, 216, 0x33, 1, 0, opacity, 2);
        draw_msg(0xB00FD, 206 - get_msg_width(0xB00FD, 0), 65, opacity, 0, 1);
        draw_number(arg0->equippedBadges, 231, 66, 1, 0, opacity, 3);
        draw_msg(0x1F0034, 232, 63, opacity, 0, 0);
        draw_number(80, 244, 66, 1, 0, opacity, 2);
        if (gPlayerData.starPiecesCollected == 0) {
            draw_msg(0xB00FA, 109, 80, opacity, 0, 1);
        } else {
            draw_msg(0xB00FB, 206 - get_msg_width(0xB00FB, 0), 80, opacity, 0, 1);
            draw_number(gPlayerData.starPiecesCollected, 231, 81, 1, 0, opacity, 3);
            draw_msg(0x1F0034, 232, 78, opacity, 0, 0);
            draw_number(0xA0, 244, 80, 1, 0, opacity, 2);
        }

        width = get_msg_width(0xB00FE, 0);
        if (arg0->unk_26 == 0) {
            draw_msg(0xB00FA, 110, 95, opacity, 0, 1);
        } else {
            if (arg0->unk_26 == -1) {
                draw_msg(0xB00FE, 206 - width, 95, opacity, 0, 1);
                draw_number(0, 231, 96, 1, 0, opacity, 3);
            } else {
                draw_msg(0xB00FE, 206 - width, 95, opacity, 0, 1);
                draw_number(arg0->unk_26, 231, 96, 1, 0, opacity, 3);
            }
            draw_msg(0x1F0034, 232, 93, opacity, 0, 0);
            draw_number(arg0->unk_28, 244, 95, 1, 0, opacity, 2);
        }

        if (gPlayerData.quizzesAnswered == 0) {
            draw_msg(0xB00FA, 109, 110, opacity, 0, 1);
        } else {
            draw_msg(0xB00FF, 206 - get_msg_width(0xB00FF, 0), 110, opacity, 0, 1);
            draw_number(gPlayerData.quizzesCorrect, 231, 111, 1, 0, opacity, 3);
            draw_msg(0x1F0034, 232, 108, opacity, 0, 0);
            draw_number(gPlayerData.quizzesAnswered, 244, 111, 1, 0, opacity, 2);
        }

        draw_msg(0xB00F4, 206 - get_msg_width(0xB00F4, 0), 125, opacity, 0, 1);
        draw_number(gPlayerData.battlesCount, 216, 126, 1, 0, opacity, 2);
        width = get_msg_width(0xB00F7, 0);
        draw_msg(0xB00F7, 206 - width, 140, opacity, 0, 1);
        draw_number(gPlayerData.playerFirstStrikes, 216, 141, 1, 0, opacity, 2);
        draw_msg(0xB00F8, 206 - get_msg_width(0xB00F8, 0), 155, opacity, 0, 1);
        draw_number(gPlayerData.enemyFirstStrikes, 216, 156, 1, 0, opacity, 2);

        if (gPlayerData.powerBounces == 0) {
            draw_msg(0xB00FA, 109, 170, opacity, 0, 1);
        } else {
            draw_msg(0xB00F9, 206 - get_msg_width(0xB00F9, 0), 170, opacity, 0, 1);
            draw_number(gPlayerData.powerBounces, 216, 171, 1, 0, opacity, 2);
        }
    }
}

void func_80242870_8EE690(void* data) {
    UnkKmr20* temp_v0 = (UnkKmr20*) evt_get_variable(NULL, MapVar(10));
    s32 temp_f2;

    switch (temp_v0->unk_00) {
        case 0:
            temp_v0->unk_18 = 0;
            temp_v0->unk_08 = 0;
            temp_v0->unk_0A = 0;
            temp_v0->unk_04 = 0;
            temp_v0->unk_00 = 1;
            snd_start_sound(SOUND_21C, 0, 0);
            // fallthrough
        case 1:
            temp_v0->unk_04++;
            temp_f2 = update_lerp(0, 32.0f, 255.0f, temp_v0->unk_04, 3);
            temp_v0->unk_1A = temp_f2;
            temp_v0->unk_1C = temp_f2;
            if (temp_v0->unk_04 >= 3) {
                temp_v0->unk_00 = 2;
                temp_v0->unk_1A = 255;
                temp_v0->unk_1C = 255;
            }
            break;
        case 2:
            temp_v0->unk_1A = 255;
            temp_v0->unk_1C = 255;
            if (gGameStatusPtr->currentButtons[0] & (BUTTON_A | BUTTON_B)) {
                temp_v0->unk_00 = 3;
            }
            if (temp_v0->unk_00 != 3) {
                break;
            }
        case 3:
            temp_v0->unk_04 = 0;
            temp_v0->unk_00 = 4;
            snd_start_sound(SOUND_MENU_BACK, 0, 0);
            // fallthrough
        case 4:
            temp_v0->unk_04++;
            temp_v0->unk_1A = update_lerp(0, temp_v0->unk_1C, 0.0f, temp_v0->unk_04, 3);
            if (temp_v0->unk_04 >= 3) {
                temp_v0->unk_00 = 5;
            }
            break;
    }
    func_802421A0_8EDFC0(temp_v0, temp_v0->unk_1A);
}

void func_80242A04_8EE824(void) {
    RenderTask rt;

    rt.renderMode = RENDER_MODE_2D;
    rt.appendGfxArg = NULL;
    rt.appendGfx = func_80242870_8EE690;
    rt.distance = 0;
    queue_render_task(&rt);
}

void func_80242A3C_8EE85C(UnkKmr20*);
INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8EDFC0", func_80242A3C_8EE85C);

ApiStatus func_80242B04_8EE924(Evt* script, s32 isInitialCall) {
    UnkKmr20* temp_v0;

    if (isInitialCall) {
        temp_v0 = script->functionTempPtr[0] = heap_malloc(sizeof(*temp_v0));
        temp_v0->unk_00 = 0;
        temp_v0->unk_1A = 255;
        temp_v0->unk_20 = create_worker_world(0, func_80242A04_8EE824);
        evt_set_variable(script, MapVar(10), (s32) temp_v0);
        func_80242A3C_8EE85C(temp_v0);
    }

    temp_v0 = script->functionTempPtr[0];
    if (temp_v0->unk_00 == 5) {
        free_worker(temp_v0->unk_20);
        heap_free(temp_v0);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}
