#include "flo_25.h"

#include "world/common/foliage.inc.c"

s32 N(treeModelList_Tree1_Leaves)[] = {
    0x00000003, 0x00000016, 0x00000017, 0x00000018,
};

s32 N(treeModelList_Tree1_Trunk)[] = {
    0x00000001, 0x00000015,
};

s32 N(treeDropList_Tree1)[] = {
    2,
    ITEM_YELLOW_BERRY, -432, 84, -44, 0xC, 0, SI_AREA_FLAG(33),
    ITEM_YELLOW_BERRY, -346, 72, -114, 0xC, 0, SI_AREA_FLAG(34),
};

s32 N(shakeTreeEvent_Tree1)[] = {
    N(treeModelList_Tree1_Leaves), N(treeModelList_Tree1_Trunk), N(treeDropList_Tree1), 0x00000000, 0x00000000,
};

s32 N(triggerCoord_802446AC)[] = {
    0xC3C20000, 0x00000000, 0xC2B80000, 0x00000000,
};

Script N(802446BC) = SCRIPT({
    SI_AREA_FLAG(33) = 0;
    SI_AREA_FLAG(34) = 0;
    SI_VAR(0) = N(shakeTreeEvent_Tree1);
    bind N(shakeTree) to TRIGGER_WALL_HAMMER 12;
    bind N(shakeTree) to TRIGGER_POINT_BOMB N(triggerCoord_802446AC);
});

static s32 N(pad_4734)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80244740) = SCRIPT({
    group 11;
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    SI_VAR(12) = SI_VAR(2);
    SI_VAR(13) = SI_VAR(3);
    SI_VAR(14) = SI_VAR(4);
    SI_VAR(12) -= SI_VAR(0);
    SI_VAR(13) -= SI_VAR(1);
    SI_VAR(0) = (float) SI_VAR(12);
    SI_VAR(0) /= 100.0;
    SI_VAR(15) = 100.0;
    SI_VAR(15) /= (float) SI_VAR(0);
    SI_VAR(15) += 11;
    SI_VAR(5) = 200;
    SI_VAR(5) /= SI_VAR(15);
    SI_VAR(5) += 1;
    loop SI_VAR(5) {
        RandInt(SI_VAR(12), SI_VAR(0));
        RandInt(SI_VAR(13), SI_VAR(1));
        RandInt(199, SI_VAR(2));
        SI_VAR(3) = 210;
        SI_VAR(3) -= SI_VAR(2);
        SI_VAR(0) += SI_VAR(10);
        SI_VAR(1) += SI_VAR(11);
        SI_VAR(2) += SI_VAR(14);
        PlayEffect(0xD, SI_VAR(0), SI_VAR(2), SI_VAR(1), SI_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep SI_VAR(15);
0:
    RandInt(SI_VAR(12), SI_VAR(0));
    RandInt(SI_VAR(13), SI_VAR(1));
    SI_VAR(0) += SI_VAR(10);
    SI_VAR(1) += SI_VAR(11);
    PlayEffect(0xD, SI_VAR(0), SI_VAR(14), SI_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep SI_VAR(15);
    goto 0;
});

Script N(802449EC) = SCRIPT({
    SI_VAR(9) = SI_VAR(6);
    SI_VAR(8) = SI_VAR(5);
    SI_VAR(7) = SI_VAR(4);
    SI_VAR(6) = SI_VAR(3);
    SI_VAR(5) = SI_VAR(2);
    SI_VAR(4) = SI_VAR(1);
    SI_VAR(3) = SI_VAR(0);
    EnableModel(SI_VAR(6), 0);
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(UnkFunc43)();
    if (SI_VAR(0) == 0) {
        sleep 1;
        goto 0;
    }
    spawn {
        sleep 5;
        EnableModel(SI_VAR(6), 1);
    }
    if (SI_VAR(10) != 0) {
        spawn {
            sleep 5;
            SI_VAR(0) = SI_VAR(3);
            SI_VAR(1) = SI_VAR(4);
            SI_VAR(2) = SI_VAR(5);
            SI_VAR(1) += 10;
            SI_VAR(2) += 8;
            PlayEffect(0x11, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            SI_VAR(1) -= 10;
            MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 14, 0);
        }
    }
    spawn {
        sleep 10;
        PlaySoundAt(0xF8, 0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(SI_VAR(8), SI_VAR(0), 1, 0, 0);
    RotateModel(SI_VAR(9), SI_VAR(0), 1, 0, 0);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(SI_VAR(7), 0);
});

Script N(80244D0C) = SCRIPT({
    GetModelCenter(57);
    SI_VAR(3) = 57;
    SI_VAR(4) = 58;
    SI_VAR(5) = 59;
    SI_VAR(6) = 60;
    SI_VAR(10) = 0;
    spawn N(802449EC);
    GetModelCenter(63);
    SI_VAR(3) = 63;
    SI_VAR(4) = 64;
    SI_VAR(5) = 65;
    SI_VAR(6) = 66;
    SI_VAR(10) = 0;
    spawn N(802449EC);
    GetModelCenter(69);
    SI_VAR(3) = 69;
    SI_VAR(4) = 70;
    SI_VAR(5) = 71;
    SI_VAR(6) = 72;
    SI_VAR(10) = 174;
    spawn N(802449EC);
    GetModelCenter(75);
    SI_VAR(3) = 75;
    SI_VAR(4) = 76;
    SI_VAR(5) = 77;
    SI_VAR(6) = 78;
    SI_VAR(10) = 0;
    spawn N(802449EC);
});
