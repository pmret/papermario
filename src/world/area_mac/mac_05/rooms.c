#include "mac_05.h"

EvtScript N(D_802522E0_864450) = {
    Call(RotateModel, MODEL_o80, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(D_80252310_864480) = {
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_o95, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o96, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o98, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o99, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o100, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o101, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o102, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o104, LVar1, 1, 0, 0)
    Set(LVar1, LVar0)
    Call(RotateModel, MODEL_o133, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o134, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o137, LVar1, 1, 0, 0)
    Set(LVar1, LVar0)
    MulF(LVar1, Float(-1.0))
    Call(RotateModel, MODEL_o82, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o83, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o84, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o136, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o81, LVar1, 1, 0, 0)
    Call(RotateModel, MODEL_o135, LVar1, 1, 0, 0)
    Return
    End
};

EvtScript N(D_80252580_8646F0) = {
    Call(RotateModel, MODEL_o80, LVar0, 1, 0, 0)
    Return
    End
};

EvtScript N(D_802525B0_864720) = {
    Switch(LVar0)
        CaseEq(0)
            Call(SetMusicTrack, 0, SONG_CLUB64, 0, 8)
            Call(StopSound, SOUND_LOOP_MAC_HARBOR_WATER)
#if !VERSION_JP
            Call(StopTrackingSoundPos, SOUND_LRAW_MAC_HARBOR_WATER)
#endif
            Call(EnableGroup, MODEL_bar_inn, TRUE)
            Call(EnableModel, MODEL_o139, FALSE)
            Call(EnableModel, MODEL_o140, FALSE)
        CaseEq(3)
            Set(AF_JAN01_TreeDrop_StarPiece, FALSE)
            Call(EnableGroup, MODEL_bar_inn, FALSE)
            Call(EnableModel, MODEL_o139, TRUE)
            Call(EnableModel, MODEL_o140, TRUE)
            Wait(5)
            Exec(N(EVS_SetupMusic))
    EndSwitch
    Return
    End
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
    Call(CreateMapRoom,
        2,
        Ref(N(D_802522E0_864450)),
        Ref(N(D_80252310_864480)),
        Ref(N(D_80252580_8646F0)),
        Ref(N(D_802525B0_864720)),
        COLLIDER_deilit1,
        COLLIDER_deilit1u,
        MODEL_harbour_club,
        Ref(N(D_802526C8_864838)))
    Set(LVar0, 3)
    Exec(N(D_802525B0_864720))
    Return
    End
};
