#include "kmr_20.h"

API_CALLABLE(N(SetAmbienceVolumeHalf_Rooms)){
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetAmbienceVolumeFull_Rooms)){
    snd_ambient_set_volume(0, 1000, 127);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetDoorRot_House) = {
    Call(RotateGroup, MODEL_g14, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_House) = {
    Call(RotateGroup, MODEL_g60, LVar0, 1, 0, 0)
    Call(RotateGroup, MODEL_g34, LVar0, -1, 0, 0)
    Switch(LVar0)
        CaseEq(90)
            Set(MF_Unk_0C, TRUE)
            Call(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_INVISIBLE, FALSE)
            Call(EnableGroup, MODEL_g60, FALSE)
            Call(EnableGroup, MODEL_g34, FALSE)
        CaseEq(0)
            IfEq(MF_Unk_0C, TRUE)
                Call(EnableGroup, MODEL_g72, TRUE)
                Set(MF_Unk_0C, FALSE)
                Call(SetNpcFlagBits, NPC_Luigi_0, NPC_FLAG_INVISIBLE, TRUE)
            EndIf
        CaseDefault
            Call(EnableGroup, MODEL_g60, TRUE)
            Call(EnableGroup, MODEL_g34, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RoomListener_House) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(N(SetAmbienceVolumeHalf_Rooms))
            Call(EnableGroup, MODEL_g20, TRUE)
            Call(EnableGroup, MODEL_g21, TRUE)
            Call(EnableGroup, MODEL_g49, TRUE)
            Call(EnableModel, MODEL_g56, TRUE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(N(SetAmbienceVolumeFull_Rooms))
            Call(EnableGroup, MODEL_g20, FALSE)
            Call(EnableGroup, MODEL_g21, FALSE)
            Call(EnableGroup, MODEL_g49, FALSE)
            Call(EnableModel, MODEL_g56, FALSE)
            Call(EnableGroup, MODEL_g72, FALSE)
    EndSwitch
    Return
    End
};

s32 N(InteriorNPCs_House)[] = {
    NPC_Luigi_0,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_House)),
        Ref(N(EVS_SetWallRot_House)),
        NULL,
        Ref(N(EVS_RoomListener_House)),
        COLLIDER_o246,
        COLLIDER_o245,
        MODEL_g62,
        Ref(N(InteriorNPCs_House)))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseOrEq(kmr_20_ENTRY_2)
        CaseOrEq(kmr_20_ENTRY_3)
            Call(EnableGroup, MODEL_g20, TRUE)
            Call(EnableGroup, MODEL_g21, TRUE)
            Call(EnableGroup, MODEL_g49, TRUE)
            Call(EnableModel, MODEL_g56, TRUE)
            Call(EnableGroup, MODEL_g72, FALSE)
            Call(N(func_80241C9C_8EDABC))
            Call(RotateGroup, MODEL_g60, 90, 1, 0, 0)
            Call(RotateGroup, MODEL_g34, 90, -1, 0, 0)
            Call(EnableGroup, MODEL_g60, FALSE)
            Call(EnableGroup, MODEL_g34, FALSE)
            Call(N(SetAmbienceVolumeHalf_Rooms))
        EndCaseGroup
        CaseDefault
            Set(LVar0, ROOM_UPDATE_EXIT_END)
            Exec(N(EVS_RoomListener_House))
    EndSwitch
    Return
    End
};
