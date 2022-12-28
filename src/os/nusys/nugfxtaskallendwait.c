#include "common.h"
#include "nu/nusys.h"

void nuGfxTaskAllEndWait(void) {
    while (nuGfxTaskSpool) {
    }
}
