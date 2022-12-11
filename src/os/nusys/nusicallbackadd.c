#include "common.h"
#include "nu/nusys.h"

void nuSiCallBackAdd(NUCallBackList* list) {
    OSIntMask mask;
    NUCallBackList** siCallBackListPtr = &nuSiCallBackList;
    u32 i;

    while (*siCallBackListPtr != NULL) {
        if ((*siCallBackListPtr)->majorNo == list->majorNo) {
            return;
        }
        siCallBackListPtr = &(*siCallBackListPtr)->next;
    }

    for (i = 1; list->func[i] != NULL; i++);

    mask = osSetIntMask(OS_IM_NONE);
    *siCallBackListPtr = list;
    list->next = NULL;
    list->funcNum = i;
    osSetIntMask(mask);
}
