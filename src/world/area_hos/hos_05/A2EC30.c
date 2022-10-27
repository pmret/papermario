#include "hos_05.h"

u32 D_8024DA90_A37CD0 = 0; // mode
s32 D_8024DA94_A37CD4 = 0; // alpha related
s32* D_8024DA98_A37CD8 = NULL;
s32 D_8024DA9C_A37CDC[] = {
    -1, 30, 1, 50, 2, 50, -1, 50, 3, 50, 4, 50, 5, 50, -1, 50, 6, 50, 7, 50, 8, 50, -1, 50, 9, 50, 10, 50, 11, 50,
    -1, 50, 12, 30, 13, 30, 14, 50, 15, 30, 16, 30, 17, 30, 18, 50, 19, 30, -1, 40, 20, 56, -1, 50, 21, 30,
    -1, 30, 22, 50, -1, 30, 23, 50, 24, 50, -1, 60, 25, 50, -1, 24, 26, 30, 0, 0
};
s32* D_8024DBCC_A37E0C[4] = { D_8024DA9C_A37CDC, D_8024DA9C_A37CDC, D_8024DA9C_A37CDC, D_8024DA9C_A37CDC };

EvtScript D_8024DBDC_A37E1C = {
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(3)
            EVT_CALL(func_80244C60_A2EEA0, EVT_PTR(func_80244C8C_A2EECC))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

// BSS
extern s32 D_8024F570;

void func_802449F0_A2EC30(s32** arg0) {
    u8 type;
    f32 zoom1;
    f32 zoom2;
    s32 messageID;
    s32 opacity;
    s32 yOffset;
    s32 t;
    s32 t2;

    if (D_8024DA98_A37CD8 == NULL) {
        D_8024DA98_A37CD8 = arg0[D_800779B0];
    }

    switch (D_8024DA90_A37CD0) {
        case 0:
            if (D_8024DA98_A37CD8[0] == -1) {
                D_8024DA90_A37CD0 = 4;
                D_8024F570 = D_8024DA98_A37CD8[1];
            } else {
                D_8024DA94_A37CD4 += 10;
                if (D_8024DA94_A37CD4 > 255) {
                    D_8024DA94_A37CD4 = 255;
                    D_8024DA90_A37CD0 = 1;
                    D_8024F570 = D_8024DA98_A37CD8[1];
                }
            }
            break;
        case 1:
            if (D_8024F570 == 0) {
                D_8024DA90_A37CD0 = 2;
            } else {
                D_8024F570--;
            }
            break;
        case 2:
            D_8024DA94_A37CD4 -= 10;
            if (D_8024DA94_A37CD4 < 0) {
                D_8024DA94_A37CD4 = 0;
                t = D_8024DA98_A37CD8[2];
                D_8024DA98_A37CD8 += 2;
                if (t == 0) {
                    D_8024DA90_A37CD0 = 3;
                } else {
                    D_8024DA90_A37CD0 = 0;
                }
            }
            break;
        case 3:
            break;
        case 4:
            if (D_8024F570 != 0) {
                D_8024F570--;
                break;
            }
            t2 = D_8024DA98_A37CD8[2];
            D_8024DA98_A37CD8 += 2;
            if (t2 == 0) {
                D_8024DA90_A37CD0 = 3;
            } else {
                D_8024DA90_A37CD0 = 0;
            }
            break;
    }
    get_screen_overlay_params(1, &type, &zoom1);
    get_screen_overlay_params(0, &type, &zoom2);
    opacity = ((D_8024DA94_A37CD4 * (255.0f - zoom1) * (255.0f - zoom2)) / 255.0f) / 255.0f;
    if (opacity > 0) {
        messageID = D_8024DA98_A37CD8[0];
        if (messageID != 0) {
            yOffset = 0;
            if (get_msg_lines(messageID) >= 2) {
                yOffset = -7;
            }
            draw_msg(D_8024DA98_A37CD8[0], 0, yOffset + 196, opacity, -1, 0);
        }
    }
}

ApiStatus func_80244C60_A2EEA0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    void (*callback)(void) = (void (*)(void))evt_get_variable(script, *args++);
    set_curtain_draw_callback(callback);
    return ApiStatus_DONE2;
}

void func_80244C8C_A2EECC(void) {
    func_80243100_A2D340();
    func_802449F0_A2EC30(D_8024DBCC_A37E0C);
}

static const f32 padding[2] = { 0.0f, 0.0f };
