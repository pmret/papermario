#include "hos_04.h"

EvtScript N(EVS_ExitWalk_hos_03_1) = EVT_EXIT_WALK(60, hos_04_ENTRY_0, "hos_03", hos_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_hos_05_0) = EVT_EXIT_WALK(60, hos_04_ENTRY_1, "hos_05", hos_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_hos_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_o163, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(AF_HOS_B5, FALSE)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_04_ENTRY_0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
            EVT_IF_EQ(GF_HOS04_Visited, FALSE)
                EVT_THREAD
                    EVT_CALL(DisablePlayerInput, TRUE)
                    EVT_CALL(SetPlayerPos, -630, 0, 0)
                    EVT_CALL(GetPartnerInUse, LVar0)
                    EVT_IF_EQ(LVar0, PARTNER_NONE)
                        EVT_CALL(DisablePartnerAI, 0)
                        EVT_CALL(SetNpcPos, NPC_PARTNER, -660, 0, 0)
                        EVT_WAIT(1)
                        EVT_CALL(EnablePartnerAI)
                    EVT_END_IF
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -565, 0, 0)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, -565, 0, 0)
                    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1350)
                    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-25.0))
                    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-15.0), EVT_FLOAT(-100.0))
                    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(87.5), EVT_FLOAT(50.0))
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                    EVT_WAIT(10)
                    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(4.0), EVT_FLOAT(-7.5))
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.15))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                    EVT_WAIT(30)
                    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
                    EVT_EXEC_WAIT(EnterWalk)
                    EVT_WAIT(20)
                    EVT_SET(GF_HOS04_Visited, TRUE)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                    EVT_SET(AF_HOS_B5, TRUE)
                    EVT_CALL(DisablePlayerInput, FALSE)
                EVT_END_THREAD
            EVT_ELSE
                EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
                EVT_EXEC(EnterWalk)
                EVT_WAIT(1)
            EVT_END_IF
        EVT_CASE_EQ(hos_04_ENTRY_1)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(hos_04_ENTRY_2)
            EVT_EXEC(N(EVS_Starship_FlyingAway))
        EVT_CASE_EQ(hos_04_ENTRY_3)
            EVT_EXEC_WAIT(N(EVS_Intro_PreHeist_Unused))
        EVT_CASE_EQ(hos_04_ENTRY_4)
            EVT_EXEC_WAIT(N(EVS_Intro_PostHeist))
        EVT_CASE_EQ(hos_04_ENTRY_5)
            EVT_CALL(EnableGroup, MODEL_g1, FALSE)
            EVT_EXEC(N(EVS_BetaStarship_Flight1))
        EVT_CASE_EQ(hos_04_ENTRY_6)
            EVT_CALL(EnableGroup, MODEL_g1, FALSE)
            EVT_EXEC(N(EVS_BetaStarship_Flight2))
        EVT_CASE_EQ(hos_04_ENTRY_7)
            EVT_CALL(EnableGroup, MODEL_g1, FALSE)
            EVT_EXEC(N(EVS_BetaStarship_Return))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_STAR_HAVEN)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_THREAD
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupFountains))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupNarrator))
    EVT_RETURN
    EVT_END
};
