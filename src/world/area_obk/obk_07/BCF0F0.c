#include "obk_07.h"
#include "hud_element.h"
#include "battle/action_cmd.h"

extern HudScript HES_SlowlyMashAButton;

typedef struct UnkObk07 {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C; // song name
    /* 0x010 */ s32 unk_10[6]; // probably more
    /* 0x028 */ s32 unk_28;
    /* 0x02C */ s32 unk_2C; // entity id
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34; // x
    /* 0x038 */ s32 unk_38; // y
    /* 0x03C */ s32 unk_3C; // entity id
    /* 0x040 */ s32 unk_40; // entity id
    /* 0x044 */ s32 unk_44; // entity id
    /* 0x048 */ char unk_48[0x4];
    /* 0x04C */ s32 unk_4C;
    /* 0x050 */ s32 unk_50;
    /* 0x054 */ s32 unk_54;
    /* 0x058 */ s32 aPressed[90];
    /* 0x1C0 */ s32 unk_1C0;
    /* 0x1C4 */ f32 unk_1C4;
    /* 0x1C8 */ f32 unk_1C8;
    /* 0x1CC */ f32 unk_1CC;
    /* 0x1D0 */ f32 unk_1D0;
    /* 0x1D4 */ s32 unk_1D4;
    /* 0x1D8 */ s32 unk_1D8;
    /* 0x1DC */ s8 unk_1DC;
    /* 0x1DD */ char unk_1DD[0x3];
} UnkObk07; // size = 0x1E0

extern s32 D_80243090_BD1C80[];
extern s32 D_80243098_BD1C88[];
extern u8 D_802430A0_BD1C90[];
extern u8 D_802430B0_BD1CA0[];
extern u8 D_802430C0_BD1CB0[];

ApiStatus func_80240500_BCF0F0(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, MapVar(6), (s32) heap_malloc(sizeof(UnkObk07)));
    return ApiStatus_DONE2;
}

UnkObk07* func_80240540_BCF130(void) {
    return (UnkObk07*) evt_get_variable(NULL, MapVar(6));
}

void func_80240564_BCF154(s32, s32, s32);
INCLUDE_ASM(s32, "world/area_obk/obk_07/BCF0F0", func_80240564_BCF154);

void func_80240A10_BCF600(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80240540_BCF130()->unk_00 = arg3;
    func_80240564_BCF154(arg0, arg1, arg2);
}

void func_80240A6C_BCF65C(void) {
    UnkObk07* temp_v0 = func_80240540_BCF130();
    s32 id;
    s32 temp;
    s32 count;
    s32 arrCount;
    s32 idx;
    s32 i;

    temp_v0->aPressed[temp_v0->unk_1C0] = gGameStatusPtr->pressedButtons[0] & A_BUTTON;
    temp_v0->unk_1C0++;
    if (temp_v0->unk_1C0 >= ARRAY_COUNT(temp_v0->aPressed)) {
        temp_v0->unk_1C0 = 0;
    }

    switch (temp_v0->unk_30) {
        case 0:
            id = temp_v0->unk_3C;
            hud_element_set_alpha(id, 255);
            hud_element_clear_flags(id, 2);
            id = temp_v0->unk_40;
            hud_element_set_alpha(id, 255);
            hud_element_clear_flags(id, 2);
            id = temp_v0->unk_44;
            hud_element_set_alpha(id, 255);
            hud_element_clear_flags(id, 2);
            temp_v0->unk_30 = 1;
            break;
        case 1:
            temp_v0->unk_34 += 20;
            if (temp_v0->unk_34 > 50) {
                temp_v0->unk_34 = 50;
            }
            hud_element_set_render_pos(temp_v0->unk_3C, temp_v0->unk_34, temp_v0->unk_38);
            hud_element_set_render_pos(temp_v0->unk_40, temp_v0->unk_34, temp_v0->unk_38 + 28);
            hud_element_set_render_pos(temp_v0->unk_44, temp_v0->unk_34 + 2, temp_v0->unk_38 + 14);
            break;
        case 10:
            hud_element_set_script(temp_v0->unk_3C, &HES_SlowlyMashAButton);
            temp_v0->unk_30 = 11;
            // fallthrough
        case 11:
            arrCount = ARRAY_COUNT(temp_v0->aPressed);
            idx = temp_v0->unk_1C0;
            idx -= arrCount;
            temp_v0->unk_04 = 0;
            if (idx < 0) {
                idx += arrCount;
            }

            count = 0;
            for (i = 0; i < arrCount; i++, idx++) {
                if (idx >= ARRAY_COUNT(temp_v0->aPressed)) {
                    idx -= ARRAY_COUNT(temp_v0->aPressed);
                }
                if (temp_v0->aPressed[idx] != 0) {
                    count++;
                }
            }
            evt_set_variable(NULL, MapVar(7), count * 1000);
            temp_v0->unk_04 = (count * 100) / 22;
            if (temp_v0->unk_04 < 0) {
                temp_v0->unk_04 = 0;
            }
            if (temp_v0->unk_04 > 100) {
                temp_v0->unk_04 = 100;
            }

            id = temp_v0->unk_08 / 60; // TODO use of id required to match - weird
            if (id <= 50) {
                temp = 50.0f;
                temp *= sin_rad((((id * 90) / 50) * TAU) / 360.0f);
            } else {
                temp = ((1.0 - sin_rad((((((id - 50) * 90) / 50) + 90) * TAU) / 360.0f)) * 50.0) + 50.0;
            }
            temp_v0->unk_1C4 = (((100 - temp) * 0.25) / 100.0) + ((2.0 * temp) / 100.0);
            func_80055D38(temp_v0->unk_0C, temp_v0->unk_1C4);
            set_script_timescale(get_script_by_id(temp_v0->unk_4C), temp_v0->unk_1C4 * 3.0f);
            set_script_timescale(get_script_by_id(temp_v0->unk_50), temp_v0->unk_1C4 * 5.0f);
            set_script_timescale(get_script_by_id(temp_v0->unk_54), temp_v0->unk_1C4 * 5.0f);
            break;
    }
}

ApiStatus func_80240EF8_BCFAE8(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_s0 = func_80240540_BCF130();
    s32 temp_f6 = script->varTable[0] / 1000;

    temp_f6 = sin_rad(DEG_TO_RAD((temp_f6 * 90) / 50)) * 50.0f;
    temp_s0->unk_1C4 = (((100 - temp_f6) * 0.25) / 100.0) + ((2.0 * temp_f6) / 100.0);
    func_80055D38(temp_s0->unk_0C, temp_s0->unk_1C4);
    get_script_by_id(temp_s0->unk_4C);
    set_script_timescale(script, temp_s0->unk_1C4 * 3.0f);
    get_script_by_id(temp_s0->unk_50);
    set_script_timescale(script, temp_s0->unk_1C4 * 5.0f);
    get_script_by_id(temp_s0->unk_54);
    set_script_timescale(script, temp_s0->unk_1C4 * 5.0f);
    return ApiStatus_DONE2;
}

void func_802410C0_BCFCB0(void) {
    UnkObk07* temp_v0 = func_80240540_BCF130();
    s32 x, y;
    s32 id;

    hud_element_draw_clipped(temp_v0->unk_3C);
    id = temp_v0->unk_40;
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);
    func_80240A10_BCF600(x, y, temp_v0->unk_04, 2);
    hud_element_draw_clipped(temp_v0->unk_44);
}

ApiStatus func_80241130_BCFD20(Evt* script, s32 isInitialCall) {
    s32 outVal = 0;
    s32* it = D_80243090_BD1C80;

    while (TRUE) {
        if (*it == 0) {
            outVal = -1;
        } else if (*it++ != script->varTable[0]) {
            outVal++;
            continue;
        }
        break;
    }
    script->varTable[0] = outVal;
    return ApiStatus_DONE2;
}

ApiStatus func_80241168_BCFD58(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_s1 = func_80240540_BCF130();
    s32 id;
    s32 i;

    gOverrideFlags |= GLOBAL_OVERRIDES_10;
    temp_s1->unk_2C = create_worker_frontUI(func_80240A6C_BCF65C, func_802410C0_BCFCB0);
    temp_s1->unk_30 = 0;
    temp_s1->unk_04 = 0;
    temp_s1->unk_08 = 0;
    temp_s1->unk_10[0] = 0;
    temp_s1->unk_10[1] = 20;
    temp_s1->unk_10[2] = 40;
    temp_s1->unk_10[3] = 60;
    temp_s1->unk_10[4] = 80;
    temp_s1->unk_10[5] = 100;
    temp_s1->unk_28 = 5;

    for (i = 0; i < ARRAY_COUNT(temp_s1->aPressed); i++) {
        temp_s1->aPressed[i] = 0;
    }

    temp_s1->unk_34 = -48;
    temp_s1->unk_1C0 = 0;
    temp_s1->unk_1C8 = 0;
    temp_s1->unk_1CC = 0;
    temp_s1->unk_38 = 64;
    temp_s1->unk_1C4 = 1.0f;
    temp_s1->unk_1D0 = 1.0f;

    temp_s1->unk_3C = id = hud_element_create(&HES_AButton);
    hud_element_set_render_pos(id, temp_s1->unk_34, temp_s1->unk_38);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    temp_s1->unk_40 = id = hud_element_create(&HES_BlueMeter);
    hud_element_set_render_pos(id, temp_s1->unk_34, temp_s1->unk_38 + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    temp_s1->unk_44 = id = hud_element_create(&HES_RunAwayOK);
    hud_element_set_render_pos(id, temp_s1->unk_34, temp_s1->unk_38 + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    return ApiStatus_DONE2;
}

ApiStatus func_8024130C_BCFEFC(Evt* script) {
    bgm_set_song(0, D_80243098_BD1C88[evt_get_variable(script, GameByte(182))], 0, 500, 8);
    return ApiStatus_DONE2;
}

ApiStatus func_80241358_BCFF48(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_v0 = func_80240540_BCF130();

    temp_v0->unk_30 = 10;
    temp_v0->unk_4C = evt_get_variable(NULL, MapVar(8));
    temp_v0->unk_50 = evt_get_variable(NULL, MapVar(9));
    temp_v0->unk_54 = evt_get_variable(NULL, MapVar(10));
    temp_v0->unk_0C = gMusicSettings->songName;
    return ApiStatus_DONE2;
}

ApiStatus func_802413D0_BCFFC0(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_v0 = func_80240540_BCF130();

    temp_v0->unk_30 = -1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_10;
    hud_element_free(temp_v0->unk_3C);
    hud_element_free(temp_v0->unk_40);
    hud_element_free(temp_v0->unk_44);
    free_worker(temp_v0->unk_2C);
    return ApiStatus_DONE2;
}

ApiStatus func_8024143C_BD002C(Evt* script, s32 isInitialCall) {
    func_80240540_BCF130();
    script->varTable[3] = 150;
    return ApiStatus_DONE2;
}

ApiStatus func_8024146C_BD005C(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_s0 = func_80240540_BCF130();

    temp_s0->unk_1D0 = evt_get_float_variable(script, LocalVar(2));
    return ApiStatus_DONE2;
}

ApiStatus func_802414B4_BD00A4(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_s1 = func_80240540_BCF130();

    temp_s1->unk_1C8 = clamp_angle(evt_get_float_variable(script, LocalVar(0)));
    evt_set_float_variable(script, LocalVar(0), temp_s1->unk_1C8);
    return ApiStatus_DONE2;
}

ApiStatus func_80241518_BD0108(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_s1 = func_80240540_BCF130();

    temp_s1->unk_1CC = clamp_angle(evt_get_float_variable(script, LocalVar(0)));
    evt_set_float_variable(script, LocalVar(0), temp_s1->unk_1CC);
    return ApiStatus_DONE2;
}

ApiStatus func_8024157C_BD016C(Evt* script, s32 isInitialCall) {
    evt_set_float_variable(script, LocalVar(0), func_80240540_BCF130()->unk_1D0);
    return ApiStatus_DONE2;
}

ApiStatus func_802415B8_BD01A8(Evt* script, s32 isInitialCall) {
    evt_set_float_variable(script, LocalVar(0), func_80240540_BCF130()->unk_1C8);
    return ApiStatus_DONE2;
}

ApiStatus func_802415F4_BD01E4(Evt* script, s32 isInitialCall) {
    evt_set_float_variable(script, LocalVar(0), func_80240540_BCF130()->unk_1CC);
    return ApiStatus_DONE2;
}

ApiStatus func_80241630_BD0220(Evt* script, s32 isInitialCall) {
    evt_set_float_variable(script, LocalVar(1), evt_get_float_variable(script, LocalVar(0)));
    return ApiStatus_DONE2;
}

ApiStatus func_80241674_BD0264(Evt* script, s32 isInitialCall) {
    f32 lv0 = evt_get_float_variable(script, LocalVar(0));
    f32 lv1 = evt_get_float_variable(script, LocalVar(1));

    if (lv1 <= 1.0f && lv0 >= 1.0f) {
        script->varTable[2] = 1;
    } else {
        script->varTable[2] = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802416F8_BD02E8(Evt* script, s32 isInitialCall) {
    f32 lv0 = evt_get_float_variable(script, LocalVar(0));
    f32 lv1 = evt_get_float_variable(script, LocalVar(1));

    if (lv1 <= 360.0f && lv0 <= 100.0f) {
        script->varTable[2] = 1;
    } else {
        script->varTable[2] = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus N(80241788_BD0378)(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING // various issues
ApiStatus func_80241790_BD0380(Evt* script) {
    UnkObk07* temp_v0 = func_80240540_BCF130();
    s32 temp_v0_2 = abs(temp_v0->unk_04 - 50);
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    var_v1 = -temp_v0_2;
    if (temp_v0_2 >= 10) {
        var_v0 = temp_v0_2 * 4;
    } else {
        goto moved;
    }

after:
    temp_v0->unk_1D4 += (var_v0 + var_v1) * 2;
    if (temp_v0->unk_04 != 0) {
        temp_v0->unk_1DC = 1;
    }
    if (temp_v0->unk_1DC == 1) {
        var_v1 = temp_v0->unk_04;
        if (var_v1 <= 0) {
            temp_v0->unk_1D8++;
        } else {
            temp_v0->unk_1D8 = 0;
        }
    }

    if (FALSE) {
moved:
        var_v1 = 10;
        var_v1 -= temp_v0_2;
        var_v0 = var_v1 * 24;
        goto after;
    }

    if (temp_v0->unk_1D4 > 10000) {
        temp_v0->unk_1D4 = 10000;
    }
    if (temp_v0->unk_1D4 < 0) {
        temp_v0->unk_1D4 = 0;
    }

    script->varTable[0] = 0;
    if (temp_v0->unk_1D8 >= 46 || (gGameStatusPtr->pressedButtons[0] & B_BUTTON)) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_obk/obk_07/BCF0F0", func_80241790_BD0380);
#endif

ApiStatus func_80241898_BD0488(Evt* script, s32 isInitialCall) {
    UnkObk07* temp_v0 = func_80240540_BCF130();

    temp_v0->unk_1D4 = 0;
    temp_v0->unk_1D8 = 0;
    temp_v0->unk_1DC = 0;
    temp_v0->unk_04 = 0;
    temp_v0->unk_30 = 0;
    script->varTable[10] = 0;
    script->varTable[11] = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802418E0_BD04D0(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(2);
    UnkObk07* temp_v0 = func_80240540_BCF130();
    f32 y2 = -136.0f;
    f32 x = npc->pos.x;
    f32 z = npc->pos.z;
    f32 x2 = -92.0f;
    f32 x3 = 168.0f;
    f32 speed;

    if (temp_v0->unk_30 == -1) {
        speed = 2.0f;
        npc->currentAnim = 0x950003;
        if (dist2D(x, z, x3, y2) < speed) {
            npc->pos.x = x3;
            npc->pos.z = y2;
            npc->yaw = atan2(x, z, x2, y2);
            script->varTable[10] = 0;
            script->varTable[11] = 1;
            return ApiStatus_DONE2;
        } else {
            npc->yaw = atan2(x, z, x3, y2);
            npc_move_heading(npc, speed, npc->yaw);
        }
        return ApiStatus_DONE2;
    }

    if (temp_v0->unk_1D4 > 7000) {
        speed = 2.0f;
        script->varTable[10] = 1;
        if (dist2D(x, z, x2, y2) < speed) {
            npc->pos.x = x2;
            npc->pos.z = y2;
        } else {
            npc->yaw = atan2(x, z, x2, y2);
            npc_move_heading(npc, speed, npc->yaw);
        }
    }

    if (temp_v0->unk_1D4 < 3000) {
        speed = 2.0f;
        script->varTable[10] = 0;
        if (dist2D(x, z, x3, y2) < speed) {
            npc->pos.x = x3;
            npc->pos.z = y2;
            npc->yaw = atan2(x, z, x2, -136.0f);
        } else {
            npc->yaw = atan2(x, z, x3, y2);
            npc_move_heading(npc, speed, npc->yaw);
        }
    }

    if (temp_v0->unk_1D4 > 7000) {
        npc->currentAnim = 0x950005;
    } else if (temp_v0->unk_1D4 > 5000) {
        npc->currentAnim = 0x950003;
    } else if (temp_v0->unk_1D4 > 3000) {
        npc->currentAnim = 0x950002;
    } else {
        npc->currentAnim = 0x950001;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80241B50_BD0740(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->alpha = 180;
    npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
    return ApiStatus_DONE2;
}
