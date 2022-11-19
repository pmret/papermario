#include "udivmoddi4.inc.c"

DItype __moddi3(DItype u, DItype v) {
    word_type c = 0;
    DIunion uu, vv;
    DItype w;

    uu.ll = u;
    vv.ll = v;

    if (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2(uu.ll);
    }

    if (vv.s.high < 0) {
        vv.ll = __negdi2(vv.ll);
    }

    __udivmoddi4 (uu.ll, vv.ll, &w);
    if (c) {
        w = __negdi2(w);
    }

    return w;
}
