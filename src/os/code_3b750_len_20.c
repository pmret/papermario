#include "nu/nusys.h"

void nuGfxSwapCfb(void* task) {
    osViSwapBuffer(((NUScTask*)task)->framebuffer);
}
