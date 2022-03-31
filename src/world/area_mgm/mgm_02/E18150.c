#include "mgm_02.h"

extern s32 N(MsgImg_PeachPanel); // TODO: assign proper type for this data

ApiStatus N(SetMsgImgs_Panel)(Evt* script, s32 isInitialCall) {
    set_message_images(&N(MsgImg_PeachPanel));
    return ApiStatus_DONE2;
}
