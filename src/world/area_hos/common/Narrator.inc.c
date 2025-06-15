#include "common.h"

#define INTRO_MSG_BLANK -1

enum {
    INTRO_MSG_STATE_APPEAR    = 0,
    INTRO_MSG_STATE_SHOWING   = 1,
    INTRO_MSG_STATE_VANISH    = 2,
    INTRO_MSG_STATE_DONE      = 3,
    INTRO_MSG_STATE_BLANK     = 4,
};

typedef struct IntroMessage {
    /* 00 */ s32 messageID;
    /* 04 */ s32 duration;
} IntroMessage; // size: 0x8

u32 N(IntroMessageState) = 0; // mode
s32 N(IntroMessageAlpha) = 0; // alpha related
IntroMessage* N(CurMessageList) = nullptr;

void N(UpdateIntroMessages)(IntroMessage** introMessageLists) {
    u8 type;
    f32 zoom1;
    f32 zoom2;
    s32 messageID;
    s32 opacity;
    s32 yOffset;
    static s32 N(IntroMessageDelay);

    if (N(CurMessageList) == nullptr) {
        N(CurMessageList) = introMessageLists[IntroMessageIdx];
    }

    switch (N(IntroMessageState)) {
        case INTRO_MSG_STATE_APPEAR:
            if (N(CurMessageList)->messageID == INTRO_MSG_BLANK) {
                N(IntroMessageState) = INTRO_MSG_STATE_BLANK;
                N(IntroMessageDelay) = N(CurMessageList)->duration;
            } else {
                N(IntroMessageAlpha) += 10;
                if (N(IntroMessageAlpha) > 255) {
                    N(IntroMessageAlpha) = 255;
                    N(IntroMessageState) = INTRO_MSG_STATE_SHOWING;
                    N(IntroMessageDelay) = N(CurMessageList)->duration;
                }
            }
            break;
        case INTRO_MSG_STATE_SHOWING:
            if (N(IntroMessageDelay) == 0) {
                N(IntroMessageState) = INTRO_MSG_STATE_VANISH;
            } else {
                N(IntroMessageDelay)--;
            }
            break;
        case INTRO_MSG_STATE_VANISH:
            N(IntroMessageAlpha) -= 10;
            if (N(IntroMessageAlpha) < 0) {
                N(IntroMessageAlpha) = 0;
                N(CurMessageList)++;
                if (N(CurMessageList)->messageID == MSG_NONE) {
                    N(IntroMessageState) = INTRO_MSG_STATE_DONE;
                } else {
                    N(IntroMessageState) = INTRO_MSG_STATE_APPEAR;
                }
            }
            break;
        case INTRO_MSG_STATE_DONE:
            break;
        case INTRO_MSG_STATE_BLANK:
            if (N(IntroMessageDelay) != 0) {
                N(IntroMessageDelay)--;
                break;
            }
            N(CurMessageList)++;
            if (N(CurMessageList)->messageID == MSG_NONE) {
                N(IntroMessageState) = INTRO_MSG_STATE_DONE;
            } else {
                N(IntroMessageState) = INTRO_MSG_STATE_APPEAR;
            }
            break;
    }
    get_screen_overlay_params(SCREEN_LAYER_BACK, &type, &zoom1);
    get_screen_overlay_params(SCREEN_LAYER_FRONT, &type, &zoom2);
    opacity = ((N(IntroMessageAlpha) * (255.0f - zoom1) * (255.0f - zoom2)) / 255.0f) / 255.0f;
    if (opacity > 0) {
        messageID = N(CurMessageList)->messageID;
        if (messageID != 0) {
#if VERSION_JP
            draw_msg(N(CurMessageList)->messageID, 0, 200, opacity, -1, 0);
#else
            yOffset = 0;
            if (get_msg_lines(messageID) >= 2) {
                yOffset = -7;
            }
            draw_msg(N(CurMessageList)->messageID, 0, yOffset + 196, opacity, -1, 0);
#endif
        }
    }
}

API_CALLABLE(N(SetCurtainCallback)) {
    Bytecode* args = script->ptrReadPos;

    set_curtain_draw_callback((void (*)) evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}
