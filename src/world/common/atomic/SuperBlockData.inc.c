#include "common.h"
#include "SuperBlock.inc.h"

s32 N(SuperBlockDataA)[] = {
    0x001D00F0, 0x001D00F1,
};

s16 N(SuperBlockDataB)[] = {
    0x0001, 0x0002, 0x0003, 0x0004,
    0x0009, 0x0006, 0x0007, 0x0008
};

s32 N(SuperBlockDataC)[8][2] = {
    { 0x001D00E0, 0x001D00E1 }, { 0x001D00E2, 0x001D00E3 },
    { 0x001D00E4, 0x001D00E5 }, { 0x001D00E6, 0x001D00E7 },
    { 0x001D00E8, 0x001D00E9 }, { 0x001D00EA, 0x001D00EB },
    { 0x001D00EC, 0x001D00ED }, { 0x001D00EE, 0x001D00EF }
};

f32 N(SuperBlockDataD)[] = {
    140.0f, 180.0f, 220.0f
};

EvtScript N(80243D94) = {
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySound, 0x212D)
    EVT_CALL(N(UnkFunc21), EVT_MAP_VAR(0))
    EVT_WAIT_FRAMES(85)
    EVT_THREAD
        EVT_CALL(PlaySound, 0x212E)
        EVT_CALL(N(UnkFunc23), 70, 70)
        EVT_WAIT_FRAMES(27)
        EVT_CALL(PlaySound, SOUND_208E)
        EVT_CALL(N(UnkFunc23), 50, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(N(TempSuperBlockAlpha), EVT_MAP_VAR(0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(47)
        EVT_CALL(N(UnkFunc22))
        EVT_CALL(N(UnkPartnerPosFunc))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(N(UnkPartnerPosFunc2))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(N(UnkPartnerPosFunc))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(3)
    EVT_CALL(N(UnkFunc60), EVT_MAP_VAR(0))
    EVT_WAIT_FRAMES(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(HitSuperBlock) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1046), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsStartingConversation, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(UnkFunc40))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ModifyGlobalOverrideFlags, 1, 2097152)
    EVT_CALL(N(SetOverrideFlags_40))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(N(UnkFunc20), EVT_MAP_VAR(0), EVT_VAR(9))
    EVT_CALL(FindKeyItem, ITEM_ULTRA_STONE, EVT_VAR(12))
    EVT_CALL(N(UnkFunc38))
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DC), 160, 40)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(438), 0)
        EVT_SET(EVT_SAVE_FLAG(438), 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DA), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DB), 160, 40)
    EVT_END_IF
    EVT_CALL(N(TempSuperBlockBeta))
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), EVT_VAR(11))
        EVT_CALL(N(SwitchToPartner), EVT_VAR(11))
    EVT_ELSE
        EVT_CALL(func_802CF56C, 2)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DF), 160, 40)
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_CALL(CloseMessage)
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(80243D94))
    EVT_CALL(N(UnkFunc18), EVT_VAR(11), EVT_VAR(13))
    EVT_SET(EVT_SAVE_FLAG(1046), 1)
    EVT_CALL(N(UnkFunc39), EVT_VAR(9))
    EVT_CALL(N(UnkFunc19))
    EVT_IF_EQ(EVT_VAR(13), 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DD), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DE), 160, 40)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
    EVT_CALL(N(UnkFunc17))
    EVT_RETURN
    EVT_END
};
