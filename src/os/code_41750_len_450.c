#include "common.h"

INCLUDE_ASM_T(int, "os/code_41750_len_450", osSetTimer, OSTimer* timer, OSTime start, OSTime end, OSMesgQueue* queue,
              OSMesg mesg);

INCLUDE_API_ASM("os/code_41750_len_450", osTimerServicesInit);

INCLUDE_API_ASM("os/code_41750_len_450", osTimerInterrupt);

INCLUDE_API_ASM("os/code_41750_len_450", osSetTimerIntr);

INCLUDE_API_ASM("os/code_41750_len_450", osInsertTimer);
