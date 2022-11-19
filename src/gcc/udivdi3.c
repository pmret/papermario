#include "udivmoddi4.inc.c"

UDItype __udivdi3(UDItype n, UDItype d) {
    return __udivmoddi4(n, d, (UDItype *) 0);
}
