#include "mac_01.h"

EvtScript N(EVS_UpdateBulletinKootFavor) = {
    IfNe(GB_KootFavor_Current, KOOT_FAVOR_CH4_2)
        Return
    EndIf
    Set(LVar1, GF_MAC01_KootFavor_ReadNewsBulletin)
    Add(LVar1, GF_MAC01_KootFavor_ReadGossipBulletin)
    IfEq(LVar1, 2)
        Return
    EndIf
    IfEq(LVar0, 0)
        Set(GF_MAC01_KootFavor_ReadNewsBulletin, TRUE)
    Else
        Set(GF_MAC01_KootFavor_ReadGossipBulletin, TRUE)
    EndIf
    Set(LVar0, GF_MAC01_KootFavor_ReadNewsBulletin)
    Add(LVar0, GF_MAC01_KootFavor_ReadGossipBulletin)
    IfEq(LVar0, 2)
        Set(GF_MAC02_KootFavor_CurrentComplete, TRUE)
    EndIf
    Return
    End
};

typedef struct BulletinBoardEntry {
    /* 0x00 */ s32 newsMessage;
    /* 0x04 */ s32 gossipMessage;
    /* 0x08 */ s32 requiredProgress;
} BulletinBoardEntry; // size = 0xC

BulletinBoardEntry N(BulletinBoardData)[] = {
    { MSG_NewsBoard_0000, MSG_GossipBoard_0000, STORY_INTRO },
    { MSG_NewsBoard_0001, MSG_GossipBoard_0001, STORY_CH0_MET_STAR_SPIRITS },
    { MSG_NewsBoard_0002, MSG_GossipBoard_0002, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE },
    { MSG_NewsBoard_0003, MSG_GossipBoard_0003, STORY_CH1_STAR_SPRIT_DEPARTED },
    { MSG_NewsBoard_0004, MSG_GossipBoard_0004, STORY_CH2_SHADY_MOUSE_LEFT_SHOP },
    { MSG_NewsBoard_0005, MSG_GossipBoard_0005, STORY_CH2_GOT_SUPER_HAMMER },
    { MSG_NewsBoard_0006, MSG_GossipBoard_0006, STORY_UNUSED_FFFFFFCC },
    { MSG_NewsBoard_0007, MSG_GossipBoard_0007, STORY_CH3_ARRIVED_AT_BOOS_MANSION },
    { MSG_NewsBoard_0008, MSG_GossipBoard_0008, STORY_CH3_SAW_TUBBA_EAT_BOO },
    { MSG_NewsBoard_0009, MSG_GossipBoard_0009, STORY_CH3_STAR_SPIRIT_RESCUED },
    { MSG_NewsBoard_000A, MSG_GossipBoard_000A, STORY_CH4_FOUND_HIDDEN_DOOR },
    { MSG_NewsBoard_000B, MSG_GossipBoard_000B, STORY_CH4_GOT_TOY_TRAIN },
    { MSG_NewsBoard_000C, MSG_GossipBoard_000C, STORY_CH4_GOT_TAYCE_TS_CAKE },
    { MSG_NewsBoard_000D, MSG_GossipBoard_000D, STORY_CH4_WATT_JOINED_PARTY },
    { MSG_NewsBoard_000E, MSG_GossipBoard_000E, STORY_CH4_STAR_SPIRIT_RESCUED },
    { MSG_NewsBoard_000F, MSG_GossipBoard_000F, STORY_CH5_REACHED_LAVA_LAVA_ISLAND },
    { MSG_NewsBoard_0010, MSG_GossipBoard_0010, STORY_CH5_ZIP_LINE_READY },
#if VERSION_JP
    { MSG_NewsBoard_0011, MSG_GossipBoard_0011, STORY_CH5_OPENED_ESCAPE_ROUTE },
#else
    { MSG_NewsBoard_0011, MSG_GossipBoard_0011, STORY_CH5_TRADED_VASE_FOR_SEED },
#endif
    { MSG_NewsBoard_0012, MSG_GossipBoard_0012, STORY_CH6_ARRIVED_AT_FLOWER_FIELDS },
    { MSG_NewsBoard_0013, MSG_GossipBoard_0013, STORY_CH6_SPOKE_WITH_THE_SUN },
    { MSG_NewsBoard_0014, MSG_GossipBoard_0014, STORY_CH6_STAR_SPIRIT_RESCUED },
    { MSG_NewsBoard_0015, MSG_GossipBoard_0015, STORY_CH7_INVITED_TO_STARBORN_VALLEY },
    { MSG_NewsBoard_0016, MSG_GossipBoard_0016, STORY_CH7_ARRIVED_AT_SHIVER_CITY },
    { MSG_NewsBoard_0017, MSG_GossipBoard_0017, STORY_CH7_STAR_SPIRIT_RESCUED },
    { MSG_NewsBoard_0018, MSG_GossipBoard_0018, STORY_CH8_STAR_SHIP_ACTIVATED },
    { MSG_NewsBoard_0019, MSG_GossipBoard_0019, STORY_EPILOGUE },
};

API_CALLABLE(N(GetBulletinMessages)) {
    s32 idx = evt_get_variable(script, GB_MAC02_CurrentBulletin);

    script->varTable[0] = N(BulletinBoardData)[idx].newsMessage;
    script->varTable[1] = N(BulletinBoardData)[idx].gossipMessage;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SelectBulletinMessages)) {
    s32 storyProgress = evt_get_variable(script, GB_StoryProgress);
    BulletinBoardEntry* entry;
    s32 i;

    entry = &N(BulletinBoardData)[ARRAY_COUNT(N(BulletinBoardData)) - 1];

    for (i = ARRAY_COUNT(N(BulletinBoardData)) - 1; i >= 0; i--, entry--) {
        if (storyProgress >= entry->requiredProgress) {
            break;
        }
    }
    evt_set_variable(script, GB_MAC02_CurrentBulletin, i);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ReadBulletin_News) = {
    Call(N(SelectBulletinMessages))
    Call(DisablePlayerInput, TRUE)
    Call(N(GetBulletinMessages))
    Call(ShowMessageAtScreenPos, LVar0, 160, 40)
    Set(LVar0, 0)
    ExecWait(N(EVS_UpdateBulletinKootFavor))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ReadBulletin_Gossip) = {
    Call(N(SelectBulletinMessages))
    Call(DisablePlayerInput, TRUE)
    Call(N(GetBulletinMessages))
    Call(ShowMessageAtScreenPos, LVar1, 160, 40)
    Set(LVar0, 1)
    ExecWait(N(EVS_UpdateBulletinKootFavor))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupBulletinBoard) = {
    BindTrigger(Ref(N(EVS_ReadBulletin_News)), TRIGGER_WALL_PRESS_A, COLLIDER_syoumen, 1, 0)
    BindTrigger(Ref(N(EVS_ReadBulletin_Gossip)), TRIGGER_WALL_PRESS_A, COLLIDER_yoko_ushiro, 1, 0)
    Return
    End
};
