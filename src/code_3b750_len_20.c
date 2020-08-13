#include "common.h"

typedef struct {
    char unk_0[0xC];
    void* unk_C;
} NUScTask;

void nuGfxSwapCfb(NUScTask* task) {
    osViSwapBuffer(task->unk_C);
}
