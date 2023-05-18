#include "kmr_23.h"
#include "sprite/player.h"

API_CALLABLE(N(func_80240010_907A40)) {
    set_curtain_scale_goal(2.0f);
    set_curtain_draw_callback(NULL);
    return ApiStatus_DONE2;
}

EvtScript N(D_80241190_908BC0) = {
    EVT_SET(AF_JAN01_TreeDrop_StarPiece, FALSE)
        EVT_LOOP(0)
            EVT_IF_NE(AF_JAN01_TreeDrop_StarPiece, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kmr_23_ENTRY_4)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_24"), kmr_24_ENTRY_0, TRANSITION_BEGIN_OR_END_CHAPTER)
    EVT_ELSE
        EVT_CALL(GotoMapSpecial, EVT_PTR("kzn_19"), kzn_19_ENTRY_3, TRANSITION_END_CHAPTER_INTERRUPTED)
    EVT_END_IF
    EVT_CALL(FadeOutMusic, 0, 2000)
    EVT_CALL(N(func_80240010_907A40))
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, -2, 0, 0)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetItem)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 440)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 100)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 65)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kmr_23_ENTRY_0)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Eldstar)))
        EVT_CASE_EQ(kmr_23_ENTRY_1)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Mamar)))
        EVT_CASE_EQ(kmr_23_ENTRY_2)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Skolar)))
        EVT_CASE_EQ(kmr_23_ENTRY_3)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Muskular)))
        EVT_CASE_EQ(kmr_23_ENTRY_4)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Misstar)))
        EVT_CASE_EQ(kmr_23_ENTRY_5)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Klevar)))
        EVT_CASE_EQ(kmr_23_ENTRY_6)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup_Kalmar)))
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(1)
    EVT_EXEC(N(D_80241190_908BC0))
    EVT_THREAD
        EVT_CALL(FadeOutMusic, 0, 150)
        EVT_CALL(ClearAmbientSounds, 150)
        EVT_WAIT(10)
        EVT_CALL(SetMusicTrack, 0, SONG_CHAPTER_END, 0, 8)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};
