#include "common.h"

u32 __osPreNMI = 0;

INCLUDE_ASM(s32, "os/40c20_len_1f0", osSendMesg, OSMesgQueue* queue, OSMesg mesg, s32 unk);

INCLUDE_ASM(void, "os/40c20_len_1f0", osSetEventMesg, OSEvent event, OSMesgQueue* queue, OSMesg mesg);
