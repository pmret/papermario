#include "tik_09.h"
#include "entity.h"

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_SpawnSwitch) = {
    EVT_CALL(AwaitPlayerLeave, -10, 10, 50)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 8)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerActionState, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(InterpCamTargetPos, 0, 1, -10, -10, 10, 20)
    EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
    EVT_CALL(PlaySoundAt, SOUND_301, SOUND_SPACE_MODE_0, -10, 200, 10)
    EVT_CALL(MakeLerp, 200, -10, 25, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_Unk_00, -10, LVar0, 10)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_48, SOUND_SPACE_MODE_0, -10, LVar0, 10)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(InterpCamTargetPos, 0, 1, LVar0, LVar1, LVar2, 20)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_mim_11_3) = {
    EVT_CALL(GotoMap, EVT_PTR("mim_11"), mim_11_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayRisingPipeSound) = {
    EVT_WAIT(10)
    EVT_CALL(PlaySound, SOUND_208E)
    EVT_SET(GF_TIK09_WarpPipe, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TIK09_WarpPipe, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TIK_05))
        EVT_SET(MV_Unk_00, LVar0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PlayRisingPipeSound)), TRIGGER_AREA_FLAG_SET, AF_TIK_05, 1, 0)
        EVT_IF_EQ(GF_TIK09_Defeated_Ambush, TRUE)
            EVT_CALL(N(SetEntityPosition), MV_Unk_00, -10, -10, 10)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), -30, -10, -40, 0, tik_09_ENTRY_2, EVT_PTR(N(EVS_GotoMap_mim_11_3)), EVT_INDEX_OF_GAME_FLAG(GF_TIK09_WarpPipe), MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1,entity);
