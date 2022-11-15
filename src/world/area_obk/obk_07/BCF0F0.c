#include "obk_07.h"
#include "hud_element.h"
#include "battle/action_cmd.h"

typedef struct UnkObk07 {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C; // song name
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
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
    /* 0x058 */ s32 unk_58[89];
    /* 0x1BC */ s32 unk_1BC;
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

void func_80240A6C_BCF65C(void);

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

INCLUDE_ASM(s32, "world/area_obk/obk_07/BCF0F0", func_80240A6C_BCF65C);

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

extern s32 D_80243090_BD1C80[];
extern s32 D_80243098_BD1C88[];

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
    temp_s1->unk_2C = create_generic_entity_frontUI(func_80240A6C_BCF65C, func_802410C0_BCFCB0);
    temp_s1->unk_30 = 0;
    temp_s1->unk_04 = 0;
    temp_s1->unk_08 = 0;
    temp_s1->unk_10 = 0;
    temp_s1->unk_14 = 20;
    temp_s1->unk_18 = 40;
    temp_s1->unk_1C = 60;
    temp_s1->unk_20 = 80;
    temp_s1->unk_24 = 100;
    temp_s1->unk_28 = 5;

    for (i = 0; i <= 89; i++) {
        temp_s1->unk_58[i] = 0;
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
    free_generic_entity(temp_v0->unk_2C);
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

INCLUDE_ASM(s32, "world/area_obk/obk_07/BCF0F0", func_802418E0_BD04D0);

ApiStatus func_80241B50_BD0740(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->alpha = 180;
    npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
    return ApiStatus_DONE2;
}
