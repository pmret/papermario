#include "kkj_19.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

extern s32 D_80241B10_AF9460;
extern s32 D_80241B14_AF9464;

// Needs data migration, matching otherwise
#ifdef NON_MATCHING
ApiStatus func_802404DC_AF7E2C(Evt* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;

    if (isInitialCall) {
        D_80241B10_AF9460 = 0;
    }

    if (D_80241B10_AF9460 != 0) {
        D_80241B10_AF9460 = 0;
        evt_set_variable(script, *args++, D_80241B14_AF9464);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_kkj/kkj_19/AF7C00", func_802404DC_AF7E2C);
#endif

ApiStatus func_80240530_AF7E80(Evt* script, s32 isInitialCall) {
    D_80241B14_AF9464 = evt_get_variable(script, *script->ptrReadPos);
    D_80241B10_AF9460 = 1;

    return ApiStatus_DONE2;
}

extern s32 D_802461F0[];

ApiStatus func_80240568_AF7EB8(Evt* script, s32 isInitialCall) {
    s32* ptr = (s32*)evt_get_variable(script, *script->ptrReadPos);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802461F0[i] = ptr[i];
        }
        D_802461F0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802461F0[i] = i + 16;
            D_802461F0[112] = 0;
        }
    }

    return ApiStatus_DONE2;
}

extern s32 D_802463B8_kkj_19[];

ApiStatus func_80240604_AF7F54(Evt* script, s32 isInitialCall) {
    s32* ptr = (s32*) evt_get_variable(script, *script->ptrReadPos);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802463B8_kkj_19[i] = ptr[i];
        }
        D_802463B8_kkj_19[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_802463B8_kkj_19[i] = i + 128;
            D_802463B8_kkj_19[91] = 0;
        }
    }

    return ApiStatus_DONE2;
}

extern s32 D_80246568_C8C018[];

#include "hud_element.h"

void func_802406A0_AF7FF0(void) {
    hud_element_draw_clipped(D_80246568_C8C018[0]);
}

extern s32 D_8024652C;
extern s32 D_80246530;
extern s32 D_80246534;
extern s32 D_80246538_kkj_19[];
extern s32 D_80246550_kkj_19;
extern s32 D_80246554;
extern u32 D_80246558_kkj_19;
extern s32 D_8024655C;
extern s32 D_80246560_kkj_19;
extern s32 D_80246578[];
extern s32 D_8024659C[];
extern s32 D_802465A0;
extern HudScript HES_AButton;
extern HudScript HES_BlueMeter;
extern HudScript HES_MashAButton;
extern s32 dgb_08_npcGroup_80246528;

ApiStatus func_802406C4_AF8014(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 hudElemID;
    s32 temp;
    s32* ptr;
    s32 i;

    if (isInitialCall) {
        D_80246558_kkj_19 = 0;
    }

    switch (D_80246558_kkj_19) {
        case 0:
            D_80246534 = evt_get_variable(script, *args);
            D_80246554 = create_generic_entity_frontUI(NULL, func_802406A0_AF7FF0);
            dgb_08_npcGroup_80246528 = 0;
            D_80246530 = 0;
            for (i = 0, ptr=&D_8024659C[0]; i < 10; i++, ptr--) {
                *ptr = 0;
            }
            D_80246538_kkj_19[1] = 12;
            D_80246538_kkj_19[2] = 24;
            D_80246538_kkj_19[3] = 36;
            D_80246538_kkj_19[4] = 48;
            D_80246538_kkj_19[5] = 60;
            D_80246550_kkj_19 = 5;
            D_802465A0 = 0;
            D_80246538_kkj_19[0] = 0;
            D_8024655C = -48;
            D_80246560_kkj_19 = 64;

            hudElemID = hud_element_create(&HES_AButton);
            D_80246568_C8C018[0] = hudElemID;
            hud_element_set_render_pos(hudElemID, D_8024655C, D_80246560_kkj_19);
            hud_element_set_render_depth(hudElemID, 0);
            hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

            hudElemID = hud_element_create(&HES_BlueMeter);
            D_80246568_C8C018[1] = hudElemID;
            hud_element_set_render_pos(hudElemID, D_8024655C, D_80246560_kkj_19 + 28);
            hud_element_set_render_depth(hudElemID, 0);
            hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

            hudElemID = D_80246568_C8C018[0];
            hud_element_set_alpha(hudElemID, 255);
            hud_element_clear_flags(hudElemID, HUD_ELEMENT_FLAGS_DISABLED);

            hudElemID = D_80246568_C8C018[1];
            hud_element_set_alpha(hudElemID, 255);
            hud_element_clear_flags(hudElemID, HUD_ELEMENT_FLAGS_DISABLED);

            D_80246558_kkj_19 = 1;
            script->functionTemp[0] = 10;
            break;
        case 1:
            D_8024655C += 20;
            if (D_8024655C >= 51) {
                D_8024655C = 50;
            }
            hud_element_set_render_pos(D_80246568_C8C018[0], D_8024655C, D_80246560_kkj_19);
            hud_element_set_render_pos(D_80246568_C8C018[1], D_8024655C, D_80246560_kkj_19 + 28);
            if (script->functionTemp[0] != 0) {
                script->functionTemp[0]--;
            } else {
                D_80246558_kkj_19 = 10;
            }
            break;
        case 10:
            hud_element_set_script(D_80246568_C8C018[0], &HES_MashAButton);
            dgb_08_npcGroup_80246528 = 0;
            D_8024652C = 0;
            D_80246558_kkj_19 = 11;
            // fallthrough
        case 11:
            temp = D_80246538_kkj_19[D_80246550_kkj_19];
            if (gGameStatusPtr->pressedButtons[0] & A_BUTTON) {
                dgb_08_npcGroup_80246528++;
            }
            if (temp < dgb_08_npcGroup_80246528) {
                dgb_08_npcGroup_80246528 = temp;
            }
            if (D_8024652C == 2) {
                D_8024652C = 3;
            }
            for (i = 0; i < 10; i++) {
                if (D_80246578[i] != 0) {
                    break;
                }
            }
            if (i >= 10) {
                D_8024652C = 2;
            } else if (D_8024652C != 3) {
                D_8024652C = 2;
            }
            D_80246534--;
            if (D_80246534 == 0) {
                D_80246534 = 5;
                D_80246558_kkj_19 = 12;
            }
            break;
        case 12:
            if (D_80246534 != 0) {
                D_80246534--;
                break;
            }
            script->varTable[0] = dgb_08_npcGroup_80246528;
            hud_element_free(D_80246568_C8C018[0]);
            hud_element_free(D_80246568_C8C018[1]);
            free_generic_entity(D_80246554);
            return ApiStatus_DONE2;
    }

    D_80246578[D_802465A0++] = gGameStatusPtr->pressedButtons[0] & A_BUTTON;

    if (D_802465A0 >= 10) {
        D_802465A0 = 0;
    }

    evt_set_variable(script, -0x08F0D17D, D_8024652C);
    return ApiStatus_BLOCK;
}

static char* N(exit_str_0) = "kkj_18";

ApiStatus func_80240B4C_AF849C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        script->varTable[0] = script->functionTemp[1];
        return ApiStatus_DONE2;
    }

    script->functionTemp[1]++;
    return ApiStatus_BLOCK;
}

ApiStatus func_80240B8C_AF84DC(Evt* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;
    s32 itemID = evt_get_variable(script, args);

    evt_set_variable(script, args, gItemTable[itemID].nameMsg);
    return ApiStatus_DONE2;
}

#include "world/common/GetFloorCollider.inc.c"

ApiStatus func_80240C10_AF8560(Evt* script, s32 isInitialCall) {
    gPlayerStatus.unk_C4 = evt_get_variable(script, *script->ptrReadPos);
    gGameStatusPtr->peachCookingIngredient = gPlayerStatus.unk_C4;

    return ApiStatus_DONE2;
}

ApiStatus func_80240C4C_AF859C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 16;

    if (script->functionTemp[1] >= 256) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);
    return (script->functionTemp[1] == 255) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus func_80240CB4_AF8604(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}
