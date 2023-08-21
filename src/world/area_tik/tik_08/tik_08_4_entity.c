#include "tik_08.h"
#include "entity.h"

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_SpawnSwitch) = {
    EVT_CALL(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, 90, 200, 100)
    EVT_CALL(MakeLerp, 200, -10, 25, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_BlueSwitch, 90, LVar0, 100)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, 90, LVar0, 100)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_jan_03_3) = {
    EVT_CALL(GotoMap, EVT_PTR("jan_03"), jan_03_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSwitchActivate) = {
    EVT_WAIT(10)
    EVT_CALL(PlaySound, SOUND_GROW)
    EVT_SET(GF_TIK08_WarpPipe, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TIK08_WarpPipe, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TIK_04))
        EVT_SET(MV_BlueSwitch, LVar0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnSwitchActivate)), TRIGGER_AREA_FLAG_SET, AF_TIK_04, 1, 0)
        EVT_IF_EQ(GF_TIK08_Defeated_Blooper, TRUE)
            EVT_CALL(N(SetEntityPosition), MV_BlueSwitch, 90, -10, 100)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), 95, -10, -88, 0, tik_08_ENTRY_4, EVT_PTR(N(EVS_GotoMap_jan_03_3)), EVT_INDEX_OF_GAME_FLAG(GF_TIK08_WarpPipe), MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
