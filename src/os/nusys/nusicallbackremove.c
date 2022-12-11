#include "common.h"
#include "nu/nusys.h"

void nuSiCallBackRemove(NUCallBackList* list) {
    OSIntMask mask;
    NUCallBackList** siCallBackListPtr = &nuSiCallBackList;

    while (*siCallBackListPtr) {
        if ((*siCallBackListPtr)->next == list) {
            mask = osSetIntMask(OS_IM_NONE);
            (*siCallBackListPtr)->next = list->next;
            list->next = NULL;
            osSetIntMask(mask);
            break;
        }
        siCallBackListPtr = &(*siCallBackListPtr)->next;
    }
}
