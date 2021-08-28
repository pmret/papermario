#include "common/UnkAngleFunc2.inc.c"

EvtSource N(clouds1) = SCRIPT({
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(7) = EVT_VAR(2);
    EVT_VAR(7) *= 10;
0:
    EVT_VAR(7) += 4;
    if (EVT_VAR(7) > 3599) {
        EVT_VAR(7) -= 3600;
    }
    N(UnkAngleFunc2)(EVT_VAR(7), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    TranslateModel(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    RotateModel(EVT_VAR(10), EVT_VAR(3), 0, 1, 0);
    sleep 1;
    goto 0;
});

EvtSource N(clouds2) = SCRIPT({
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(3);
    EVT_VAR(12) = EVT_VAR(4);
    EVT_VAR(7) = EVT_VAR(2);
    EVT_VAR(7) *= 10;
0:
    EVT_VAR(7) += 4;
    if (EVT_VAR(7) > 3599) {
        EVT_VAR(7) -= 3600;
    }
    N(UnkAngleFunc2)(EVT_VAR(7), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    EVT_VAR(1) += (float) EVT_VAR(11);
    EVT_VAR(2) += (float) EVT_VAR(12);
    TranslateModel(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    RotateModel(EVT_VAR(10), EVT_VAR(3), 0, 1, 0);
    sleep 1;
    goto 0;
});

EvtSource N(clouds3) = SCRIPT({
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(3);
    EVT_VAR(12) = EVT_VAR(4);
    EVT_VAR(13) = EVT_VAR(5);
    EVT_VAR(7) = EVT_VAR(2);
    EVT_VAR(7) *= 10;
0:
    EVT_VAR(7) += 4;
    if (EVT_VAR(7) > 3599) {
        EVT_VAR(7) -= 3600;
    }
    N(UnkAngleFunc2)(EVT_VAR(7), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(3));
    EVT_VAR(0) += (float) EVT_VAR(11);
    EVT_VAR(1) += (float) EVT_VAR(12);
    EVT_VAR(2) += (float) EVT_VAR(13);
    TranslateModel(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    RotateModel(EVT_VAR(10), EVT_VAR(3), 0, 1, 0);
    sleep 1;
    goto 0;
});
