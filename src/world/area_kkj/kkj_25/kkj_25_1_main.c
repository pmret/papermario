#include "kkj_25.h"

EvtScript N(EVS_ExitDoors_kkj_24_1) = EVT_EXIT_DOUBLE_DOOR(kkj_25_ENTRY_0, "kkj_24", kkj_24_ENTRY_1, COLLIDER_ttw, MODEL_o84, MODEL_o85);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_24_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kkj_25_ENTRY_0)
            EVT_IF_EQ(GF_KKJ25_Visited, FALSE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(SetPlayerPos, -645, 0, 0)
                EVT_CALL(GetPartnerInUse, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SetNpcPos, NPC_PARTNER, -660, 0, 0)
                    EVT_WAIT(1)
                    EVT_CALL(EnablePartnerAI)
                EVT_END_IF
                EVT_WAIT(150)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_ttw, SOUND_LARGE_DOOR_OPEN, 0)
                EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
                EVT_LOOP(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_o84, LVar0, 0, -1, 0)
                    EVT_CALL(RotateModel, MODEL_o85, LVar0, 0, 1, 0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_LOOP
                EVT_CALL(SetPlayerPos, -605, 0, 0)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(SetZoneEnabled, ZONE_o15, FALSE)
                EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_SET(GF_KKJ25_Visited, TRUE)
            EVT_ELSE
                EVT_CALL(SetZoneEnabled, ZONE_o15, FALSE)
                EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_END_IF
            EVT_SET(LVar0, 0)
            EVT_SET(LVar2, MODEL_o84)
            EVT_SET(LVar3, MODEL_o85)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_EXEC(N(EVS_Scene_BowserTrapsMario))
        EVT_CASE_EQ(kkj_25_ENTRY_1)
            EVT_EXEC(N(EVS_Scene_KammyDefeated))
        EVT_CASE_EQ(kkj_25_ENTRY_2)
            EVT_EXEC(N(EVS_Scene_BowserDefeated))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Rotate_Propellers) = {
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar2, 10)
            EVT_CALL(RotateGroup, MODEL_g3, LVar2, 0, 1, 0)
            EVT_CALL(RotateGroup, MODEL_g12, LVar2, 0, 1, 0)
            EVT_CALL(RotateGroup, MODEL_g14, LVar2, 0, 1, 0)
            EVT_CALL(RotateGroup, MODEL_g16, LVar2, 0, 1, 0)
            EVT_CALL(RotateGroup, MODEL_g18, LVar2, 0, 1, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LVar2, 90)
    EVT_LOOP(0)
        EVT_ADD(LVar2, 10)
        EVT_CALL(RotateGroup, MODEL_g11, LVar2, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g13, LVar2, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g15, LVar2, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g17, LVar2, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_SET(GF_KKJ25_Defeated_Kammy, TRUE)
        EVT_CASE_EQ(2)
            EVT_SET(GF_KKJ25_Defeated_Kammy, TRUE)
            EVT_SET(GF_KKJ25_Defeated_Bowser, TRUE)
    EVT_END_SWITCH
    EVT_SET(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_KKJ_25)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.75))
    EVT_IF_EQ(GF_KKJ25_Defeated_Bowser, FALSE)
        EVT_IF_EQ(GF_KKJ25_Defeated_Kammy, FALSE)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(InitialNpcs)))
        EVT_ELSE
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(MidpointNpcs)))
            EVT_CALL(EnableGroup, MODEL_g30, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(FinaleNpcs)))
        EVT_CALL(EnableGroup, MODEL_g30, FALSE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_LARGE)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(ParentColliderToModel, COLLIDER_o128, MODEL_o1)
    EVT_EXEC(N(EVS_Rotate_Propellers))
    EVT_CALL(GetEntryID, LVar0)
    EVT_THREAD
        EVT_SET(MV_ArenaState, ARENA_STATE_IDLE)
        EVT_IF_EQ(LVar0, kkj_25_ENTRY_0)
            EVT_CALL(EnableModel, MODEL_o122, FALSE)
            EVT_LOOP(0)
                EVT_WAIT(1)
                EVT_IF_EQ(MV_ArenaState, ARENA_STATE_ACTIVATING)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_ELSE
            EVT_CALL(ScaleModel, MODEL_o122, 250, 1, 250)
        EVT_END_IF
        EVT_EXEC(N(EVS_ManageArenaEffects))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
