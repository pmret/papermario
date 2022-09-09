#include "dgb_13.h"
#include "message_ids.h"

EntryList N(entryList) = {
    { -450.0f, 0.0f, -40.0f, 0.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_13_tattle },
};

EvtScript N(80240050) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_E8)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitWalk_802400F0) = EXIT_WALK_SCRIPT(26,  0, "dgb_03",  5);

EvtScript N(8024014C) = {
    EVT_BIND_TRIGGER(N(exitWalk_802400F0), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_EXEC_WAIT(N(80240270))
    EVT_CALL(ModifyColliderFlags, 0, 6, 0x7FFFFE00)
    EVT_EXEC_WAIT(N(80240680))
    EVT_EXEC(N(80240050))
    EVT_SET(LVar0, EVT_PTR(N(8024014C)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240270) = {
    EVT_CALL(MakeItemEntity, ITEM_MEGA_RUSH, -910, 50, -206, 17, GF_DGB13_Item_MegaRush)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -530, 55, -190, 17, GF_DGB13_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -510, 55, -175, 17, GF_DGB13_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -510, 55, -205, 17, GF_DGB13_Item_CoinC)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -490, 55, -160, 17, GF_DGB13_Item_CoinD)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -490, 55, -190, 17, GF_DGB13_Item_CoinE)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -490, 55, -220, 17, GF_DGB13_Item_CoinF)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_37C) = {
    0x00000000,
};

EvtScript N(80240380) = {
    EVT_CALL(MakeLerp, 0, 30, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, 47, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, 13)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80240424) = {
    EVT_CALL(MakeLerp, 30, 0, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, 47, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, 13)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(802404C8) = {
    EVT_CALL(MakeLerp, 0, 30, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, 53, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, 17)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8024056C) = {
    EVT_CALL(MakeLerp, 30, 0, 15, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, 53, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, 17)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80240610) = {
    EVT_IF_EQ(MapVar(0), 0)
        EVT_EXEC_WAIT(N(80240380))
        EVT_SET(MapVar(0), 1)
    EVT_ELSE
        EVT_EXEC_WAIT(N(80240424))
        EVT_SET(MapVar(0), 0)
    EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80240680) = {
    EVT_CALL(ParentColliderToModel, 13, 44)
    EVT_BIND_TRIGGER(N(80240610), TRIGGER_WALL_PRESS_A, 13, 1, 0)
    EVT_RETURN
    EVT_END
};
