#include "mgm_02.h"

void set_message_images(MessageImageData* images);

extern MessageImageData N(MsgImg_PeachPanel);

ApiStatus N(SetMsgImgs_Panel)(Evt* script, s32 isInitialCall) {
    set_message_images(&N(MsgImg_PeachPanel));
    return ApiStatus_DONE2;
}
