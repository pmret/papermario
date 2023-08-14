#include "mac_05.h"

EvtScript N(D_802522E0_864450) = {
    EVT_CALL(RotateModel, MODEL_o80, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80252310_864480) = {
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o95, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o96, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o98, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o99, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o100, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o101, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o102, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o104, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_o133, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o134, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o137, LVar1, 1, 0, 0)
    EVT_SET(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-1.0))
    EVT_CALL(RotateModel, MODEL_o82, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o83, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o84, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o136, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o81, LVar1, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o135, LVar1, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80252580_8646F0) = {
    EVT_CALL(RotateModel, MODEL_o80, LVar0, 1, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802525B0_864720) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetMusicTrack, 0, SONG_CLUB64, 0, 8)
            EVT_CALL(StopSound, SOUND_LOOP_MAC_HARBOR_WATER)
            EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_MAC_HARBOR_WATER)
            EVT_CALL(EnableGroup, MODEL_bar_inn, TRUE)
            EVT_CALL(EnableModel, MODEL_o139, FALSE)
            EVT_CALL(EnableModel, MODEL_o140, FALSE)
        EVT_CASE_EQ(3)
            EVT_SET(AF_JAN01_TreeDrop_StarPiece, FALSE)
            EVT_CALL(EnableGroup, MODEL_bar_inn, FALSE)
            EVT_CALL(EnableModel, MODEL_o139, TRUE)
            EVT_CALL(EnableModel, MODEL_o140, TRUE)
            EVT_WAIT(5)
            EVT_EXEC(N(EVS_SetupMusic))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_802526C8_864838)[] = {
    NPC_Toad_02,
    NPC_Bartender,
    NPC_Chanterelle,
    NPC_ArtistToad,
    NPC_TradeEventToad,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    EVT_CALL(CreateMapRoom,
        2,
        EVT_PTR(N(D_802522E0_864450)),
        EVT_PTR(N(D_80252310_864480)),
        EVT_PTR(N(D_80252580_8646F0)),
        EVT_PTR(N(D_802525B0_864720)),
        COLLIDER_deilit1,
        COLLIDER_deilit1u,
        MODEL_harbour_club,
        EVT_PTR(N(D_802526C8_864838)))
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(D_802525B0_864720))
    EVT_RETURN
    EVT_END
};
