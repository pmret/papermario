#include "common.h"
#include <PR/osint.h>

INCLUDE_ASM(void, "os/seteventmesg", osSetEventMesg, OSEvent event, OSMesgQueue* queue, OSMesg mesg);
