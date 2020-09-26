#include "common.h"

INCLUDE_ASM(int, "os/code_41750_len_450", osSetTimer, OSTimer* timer, OSTime start, OSTime end, OSMesgQueue* queue,
            OSMesg mesg);

INCLUDE_ASM(s32, "os/code_41750_len_450", osTimerServicesInit);

INCLUDE_ASM(s32, "os/code_41750_len_450", osTimerInterrupt);

INCLUDE_ASM(s32, "os/code_41750_len_450", osSetTimerIntr);

INCLUDE_ASM(s32, "os/code_41750_len_450", osInsertTimer);
