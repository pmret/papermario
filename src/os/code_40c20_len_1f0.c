#include "common.h"

INCLUDE_ASM_T(s32, "os/code_40c20_len_1f0", osSendMesg, OSMesgQueue* queue, OSMesg mesg, s32 unk);

INCLUDE_ASM_T(void, "os/code_40c20_len_1f0", osSetEventMesg, OSEvent event, OSMesgQueue* queue, OSMesg mesg);

INCLUDE_ASM_T(u32, "os/code_40c20_len_1f0", osGetCount, void);
