#include "PR/osint.h"

void __osDequeueThread(OSThread **queue, OSThread *t) {
    register OSThread *pred;
    register OSThread *succ;

    pred = (OSThread *) queue;
    succ = pred->next;

    while (succ != NULL) {
        if (succ == t) {
            pred->next = t->next;
            return;
        }
        pred = succ;
        succ = pred->next;
    }
}
