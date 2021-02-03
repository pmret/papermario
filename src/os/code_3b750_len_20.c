#include "nu/nusys.h"

// TODO make this better if we ever update our nusys header
// This should take NUScTask*, not void*
void nuGfxSwapCfb(void* task) {
    osViSwapBuffer(((NUScTask*)task)->framebuffer);
}
