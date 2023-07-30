#include "obk_05.h"

EvtScript N(EVS_EnterDoor_obk_05_0) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_05_ENTRY_0)
            EVT_SET(LVar2, MODEL_door1)
            EVT_SET(LVar4, MODEL_door1b)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC_WAIT(EnterSplitSingleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_obk_01_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, obk_05_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tt1)
    EVT_SET(LVar2, MODEL_door1)
    EVT_SET(LVar4, MODEL_door1b)
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSplitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("obk_01"), obk_01_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fog) = {
    EVT_CALL(SetTexPanner, MODEL_m1, 0)
    EVT_CALL(SetTexPanner, MODEL_m2, 0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 300)
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetTexPanOffset, 0, 0, LVar0, LVar1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"
#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

API_CALLABLE(N(RetroJar_AwaitPlayerEntry)) {
    if (gCollisionStatus.curFloor == COLLIDER_o420) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_ManageRetroJar) = {
    EVT_LOOP(0)
        EVT_CALL(N(RetroJar_AwaitPlayerEntry))
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_IsRetroMario, FALSE)
            EVT_CALL(PlaySoundAtPlayer, SOUND_JUMP_8BIT_MARIO, SOUND_SPACE_MODE_0)
            EVT_CALL(Disable8bitMario, FALSE)
            EVT_CALL(SetMusicTrack, 0, SONG_CHAPTER_START, 1, 8)
            EVT_SET(MF_IsRetroMario, TRUE)
        EVT_ELSE
            EVT_CALL(PlaySoundAtPlayer, SOUND_JUMP_2081, SOUND_SPACE_MODE_0)
            EVT_CALL(Disable8bitMario, TRUE)
            EVT_EXEC(N(EVS_SetupMusic))
            EVT_SET(MF_IsRetroMario, FALSE)
        EVT_END_IF
        EVT_CALL(N(SetCamera0MoveFlag1))
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump, -105, 30, -55, 30)
        EVT_WAIT(1)
        EVT_CALL(N(UnsetCamera0MoveFlag1))
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupRockingChairs))
    EVT_EXEC(N(EVS_ManageHole))
    EVT_EXEC(N(EVS_TexPan_Fog))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_obk_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EVT_EXEC(N(EVS_EnterDoor_obk_05_0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hip1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_ManageRetroJar))
    EVT_RETURN
    EVT_END
};
