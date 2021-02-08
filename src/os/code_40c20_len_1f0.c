#include "common.h"

INCLUDE_ASM(s32, "os/code_40c20_len_1f0", osSendMesg, OSMesgQueue* queue, OSMesg mesg, s32 unk);

INCLUDE_ASM(void, "os/code_40c20_len_1f0", osSetEventMesg, OSEvent event, OSMesgQueue* queue, OSMesg mesg);
