#include "common.h"
#include <PR/osint.h>

INCLUDE_ASM(void, "os/40c20_len_1f0", osSetEventMesg, OSEvent event, OSMesgQueue* queue, OSMesg mesg);
