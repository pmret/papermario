#include "flo_25.h"

#include "world/common/foliage.inc.c"

FoliageModelList N(tree1_Leaves) = {
    .count = 3,
    .models = { 22, 23, 24 }
};

FoliageModelList N(tree1_Trunk) = {
    .count = 1,
    .models = { 21 }
};

FoliageDropList N(tree1_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_YELLOW_BERRY,
            .pos = { -432, 84, -44 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(33),
        },
        {
            .itemID = ITEM_YELLOW_BERRY,
            .pos = { -346, 72, -114 },
            .spawnMode = 0xC,
            .spawnFlag = EVT_AREA_FLAG(34),
        },
    }
};

ShakeTreeConfig N(tree1) = {
    .leaves = &N(tree1_Leaves),
    .trunk = &N(tree1_Trunk),
    .drops = &N(tree1_Drops),
};

Vec4f N(triggerCoord_802446AC) = { -388.0f, 0.0f, -92.0f, 0.0f };

EvtSource N(802446BC) = SCRIPT({
    EVT_AREA_FLAG(33) = 0;
    EVT_AREA_FLAG(34) = 0;
    EVT_VAR(0) = N(tree1);
    bind N(shakeTree) TRIGGER_WALL_HAMMER 12;
    bind N(shakeTree) TRIGGER_POINT_BOMB N(triggerCoord_802446AC);
});

static s32 N(pad_4734)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80244740) = SCRIPT({
    group 11;
    EVT_VAR(10) = EVT_VAR(0);
    EVT_VAR(11) = EVT_VAR(1);
    EVT_VAR(12) = EVT_VAR(2);
    EVT_VAR(13) = EVT_VAR(3);
    EVT_VAR(14) = EVT_VAR(4);
    EVT_VAR(12) -= EVT_VAR(0);
    EVT_VAR(13) -= EVT_VAR(1);
    EVT_VAR(0) = (float) EVT_VAR(12);
    EVT_VAR(0) /= 100.0;
    EVT_VAR(15) = 100.0;
    EVT_VAR(15) /= (float) EVT_VAR(0);
    EVT_VAR(15) += 11;
    EVT_VAR(5) = 200;
    EVT_VAR(5) /= EVT_VAR(15);
    EVT_VAR(5) += 1;
    loop EVT_VAR(5) {
        RandInt(EVT_VAR(12), EVT_VAR(0));
        RandInt(EVT_VAR(13), EVT_VAR(1));
        RandInt(199, EVT_VAR(2));
        EVT_VAR(3) = 210;
        EVT_VAR(3) -= EVT_VAR(2);
        EVT_VAR(0) += EVT_VAR(10);
        EVT_VAR(1) += EVT_VAR(11);
        EVT_VAR(2) += EVT_VAR(14);
        PlayEffect(0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep EVT_VAR(15);
0:
    RandInt(EVT_VAR(12), EVT_VAR(0));
    RandInt(EVT_VAR(13), EVT_VAR(1));
    EVT_VAR(0) += EVT_VAR(10);
    EVT_VAR(1) += EVT_VAR(11);
    PlayEffect(0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep EVT_VAR(15);
    goto 0;
});

EvtSource N(802449EC) = SCRIPT({
    EVT_VAR(9) = EVT_VAR(6);
    EVT_VAR(8) = EVT_VAR(5);
    EVT_VAR(7) = EVT_VAR(4);
    EVT_VAR(6) = EVT_VAR(3);
    EVT_VAR(5) = EVT_VAR(2);
    EVT_VAR(4) = EVT_VAR(1);
    EVT_VAR(3) = EVT_VAR(0);
    EnableModel(EVT_VAR(6), 0);
0:
    GetPlayerPos(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    N(UnkFunc43)();
    if (EVT_VAR(0) == 0) {
        sleep 1;
        goto 0;
    }
    spawn {
        sleep 5;
        EnableModel(EVT_VAR(6), 1);
    }
    if (EVT_VAR(10) != 0) {
        spawn {
            sleep 5;
            EVT_VAR(0) = EVT_VAR(3);
            EVT_VAR(1) = EVT_VAR(4);
            EVT_VAR(2) = EVT_VAR(5);
            EVT_VAR(1) += 10;
            EVT_VAR(2) += 8;
            PlayEffect(0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            EVT_VAR(1) -= 10;
            MakeItemEntity(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 14, 0);
        }
    }
    spawn {
        sleep 10;
        PlaySoundAt(0xF8, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(EVT_VAR(8), EVT_VAR(0), 1, 0, 0);
    RotateModel(EVT_VAR(9), EVT_VAR(0), 1, 0, 0);
    if (EVT_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(EVT_VAR(7), 0);
});

EvtSource N(80244D0C) = SCRIPT({
    GetModelCenter(57);
    EVT_VAR(3) = 57;
    EVT_VAR(4) = 58;
    EVT_VAR(5) = 59;
    EVT_VAR(6) = 60;
    EVT_VAR(10) = 0;
    spawn N(802449EC);
    GetModelCenter(63);
    EVT_VAR(3) = 63;
    EVT_VAR(4) = 64;
    EVT_VAR(5) = 65;
    EVT_VAR(6) = 66;
    EVT_VAR(10) = 0;
    spawn N(802449EC);
    GetModelCenter(69);
    EVT_VAR(3) = 69;
    EVT_VAR(4) = 70;
    EVT_VAR(5) = 71;
    EVT_VAR(6) = 72;
    EVT_VAR(10) = 174;
    spawn N(802449EC);
    GetModelCenter(75);
    EVT_VAR(3) = 75;
    EVT_VAR(4) = 76;
    EVT_VAR(5) = 77;
    EVT_VAR(6) = 78;
    EVT_VAR(10) = 0;
    spawn N(802449EC);
});
