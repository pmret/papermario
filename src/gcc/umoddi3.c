#include "udivmoddi4.inc.c"

UDItype __umoddi3(UDItype u, UDItype v) {
    UDItype w;

    __udivmoddi4(u, v, &w);

    return w;
}
