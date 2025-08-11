#include "kmr_23.h"
#include "sprite/player.h"

API_CALLABLE(N(func_80240010_907A40)) {
    set_curtain_scale_goal(2.0f);
    set_curtain_draw_callback(nullptr);
    return ApiStatus_DONE2;
}

EvtScript N(D_80241190_908BC0) = {
    Set(AF_JAN01_TreeDrop_StarPiece, false)
        Loop(0)
            IfNe(AF_JAN01_TreeDrop_StarPiece, false)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kmr_23_ENTRY_4)
        Call(GotoMapSpecial, Ref("kmr_24"), kmr_24_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
    Else
        Call(GotoMapSpecial, Ref("kzn_19"), kzn_19_ENTRY_3, TRANSITION_END_CHAPTER_INTERRUPTED)
    EndIf
    Call(FadeOutMusic, 0, 2000)
    Call(N(func_80240010_907A40))
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerPos, -2, 0, 0)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, true)
    Call(InterpPlayerYaw, 90, 0)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_GetItem)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(DisablePartnerAI, false)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
        Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EndIf
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(SetCamType, CAM_DEFAULT, 4, false)
    Call(SetCamPitch, CAM_DEFAULT, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 440)
    Call(SetCamPosA, CAM_DEFAULT, 0, 100)
    Call(SetCamPosB, CAM_DEFAULT, 0, 0)
    Call(SetCamPosC, CAM_DEFAULT, 0, 65)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kmr_23_ENTRY_0)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Eldstar)))
        CaseEq(kmr_23_ENTRY_1)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Mamar)))
        CaseEq(kmr_23_ENTRY_2)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Skolar)))
        CaseEq(kmr_23_ENTRY_3)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Muskular)))
        CaseEq(kmr_23_ENTRY_4)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Misstar)))
        CaseEq(kmr_23_ENTRY_5)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Klevar)))
        CaseEq(kmr_23_ENTRY_6)
            Call(MakeNpcs, false, Ref(N(NpcGroup_Kalmar)))
    EndSwitch
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Wait(1)
    Exec(N(D_80241190_908BC0))
    Thread
        Call(FadeOutMusic, 0, 150)
        Call(ClearAmbientSounds, 150)
        Wait(10)
        Call(SetMusic, 0, SONG_CHAPTER_END, 0, VOL_LEVEL_FULL)
    EndThread
    Wait(20)
    Return
    End
};
