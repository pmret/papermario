#include "hos_04.h"

extern u32 D_80243250_A2A120; // mode
extern s32 D_80243254_A2A124; // alpha related
extern s32* D_80243258_A2A128;
extern s32* D_80243284_A2A154[4]; // array of pointers to ints

const char N(exit_str_0)[] = "hos_20";
const char N(exit_str_1)[] = "kpa_60";
const char N(exit_str_2)[] = "hos_00";
const char N(exit_str_3)[] = "osr_03";
const char N(exit_str_4)[] = "hos_05";

BSS s32 D_80243380;

void func_80240BD0_A27AA0(s32** arg0) {
    u8 type;
    f32 zoom1;
    f32 zoom2;
    s32 messageID;
    s32 opacity;
    s32 yOffset;
    s32 t;
    s32 t2;

    if (D_80243258_A2A128 == NULL) {
        D_80243258_A2A128 = arg0[D_800779B0];
    }

    switch (D_80243250_A2A120) {
        case 0:
            if (D_80243258_A2A128[0] == -1) {
                D_80243250_A2A120 = 4;
                D_80243380 = D_80243258_A2A128[1];
            } else {
                D_80243254_A2A124 += 10;
                if (D_80243254_A2A124 > 255) {
                    D_80243254_A2A124 = 255;
                    D_80243250_A2A120 = 1;
                    D_80243380 = D_80243258_A2A128[1];
                }
            }
            break;
        case 1:
            if (D_80243380 == 0) {
                D_80243250_A2A120 = 2;
            } else {
                D_80243380--;
            }
            break;
        case 2:
            D_80243254_A2A124 -= 10;
            if (D_80243254_A2A124 < 0) {
                D_80243254_A2A124 = 0;
                t = D_80243258_A2A128[2];
                D_80243258_A2A128 += 2;
                if (t == 0) {
                    D_80243250_A2A120 = 3;
                } else {
                    D_80243250_A2A120 = 0;
                }
            }
            break;
        case 3:
            break;
        case 4:
            if (D_80243380 != 0) {
                D_80243380--;
                break;
            }
            t2 = D_80243258_A2A128[2];
            D_80243258_A2A128 += 2;
            if (t2 == 0) {
                D_80243250_A2A120 = 3;
            } else {
                D_80243250_A2A120 = 0;
            }
            break;
    }
    get_screen_overlay_params(1, &type, &zoom1);
    get_screen_overlay_params(0, &type, &zoom2);
    opacity = ((D_80243254_A2A124 * (255.0f - zoom1) * (255.0f - zoom2)) / 255.0f) / 255.0f;
    if (opacity > 0) {
        messageID = D_80243258_A2A128[0];
        if (messageID != 0) {
            yOffset = 0;
            if (get_msg_lines(messageID) >= 2) {
                yOffset = -7;
            }
            draw_msg(D_80243258_A2A128[0], 0, yOffset + 196, opacity, -1, 0);
        }
    }
}

ApiStatus func_80240E40_A27D10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_curtain_draw_callback((void (*)) evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

void func_80240E6C_A27D3C(void) {
    func_80240BD0_A27AA0(D_80243284_A2A154);
}
