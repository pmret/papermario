#include "common/UnkAngleFunc2.inc.c"

EvtSource N(clouds1) = SCRIPT({
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(7) = SI_VAR(2);
    SI_VAR(7) *= 10;
0:
    SI_VAR(7) += 4;
    if (SI_VAR(7) > 3599) {
        SI_VAR(7) -= 3600;
    }
    N(UnkAngleFunc2)(SI_VAR(7), SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
    TranslateModel(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    RotateModel(SI_VAR(10), SI_VAR(3), 0, 1, 0);
    sleep 1;
    goto 0;
});

EvtSource N(clouds2) = SCRIPT({
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(3);
    SI_VAR(12) = SI_VAR(4);
    SI_VAR(7) = SI_VAR(2);
    SI_VAR(7) *= 10;
0:
    SI_VAR(7) += 4;
    if (SI_VAR(7) > 3599) {
        SI_VAR(7) -= 3600;
    }
    N(UnkAngleFunc2)(SI_VAR(7), SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SI_VAR(1) += (float) SI_VAR(11);
    SI_VAR(2) += (float) SI_VAR(12);
    TranslateModel(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    RotateModel(SI_VAR(10), SI_VAR(3), 0, 1, 0);
    sleep 1;
    goto 0;
});

EvtSource N(clouds3) = SCRIPT({
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(3);
    SI_VAR(12) = SI_VAR(4);
    SI_VAR(13) = SI_VAR(5);
    SI_VAR(7) = SI_VAR(2);
    SI_VAR(7) *= 10;
0:
    SI_VAR(7) += 4;
    if (SI_VAR(7) > 3599) {
        SI_VAR(7) -= 3600;
    }
    N(UnkAngleFunc2)(SI_VAR(7), SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SI_VAR(0) += (float) SI_VAR(11);
    SI_VAR(1) += (float) SI_VAR(12);
    SI_VAR(2) += (float) SI_VAR(13);
    TranslateModel(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    RotateModel(SI_VAR(10), SI_VAR(3), 0, 1, 0);
    sleep 1;
    goto 0;
});
