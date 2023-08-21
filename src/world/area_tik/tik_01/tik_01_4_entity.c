#include "tik_01.h"
#include "entity.h"

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_SpawnSwitch) = {
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, -75)
    EVT_CALL(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, LVar2, 200, 25)
    EVT_CALL(MakeLerp, 200, -10, 25, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_Unk_01, LVar2, LVar0, 25)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar2, LVar0, 25)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SmashBlock) = {
    EVT_SET(GF_TIK01_Hammer2Block, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o64, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_kmr_02_3) = {
    EVT_CALL(GotoMap, EVT_PTR("kmr_02"), kmr_02_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_nok_02_2) = {
    EVT_CALL(GotoMap, EVT_PTR("nok_02"), nok_02_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_dro_01_2) = {
    EVT_CALL(GotoMap, EVT_PTR("dro_01"), dro_01_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSwitchActivate) = {
    EVT_WAIT(10)
    EVT_CALL(PlaySound, SOUND_GROW)
    EVT_SET(GF_TIK01_WarpPipes, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TIK01_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block), -240, -10, 0, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_SmashBlock)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o64, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o63, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_EQ(GF_TIK01_WarpPipes, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TIK_03))
        EVT_SET(MV_Unk_01, LVar0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnSwitchActivate)), TRIGGER_AREA_FLAG_SET, AF_TIK_03, 1, 0)
        EVT_IF_EQ(GF_TIK01_Defeated_Blooper, TRUE)
            EVT_CALL(N(SetEntityPosition), MV_Unk_01, 125, -10, 25)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), 150, -10, -82, 0, tik_01_ENTRY_2,
        EVT_PTR(N(EVS_GotoMap_kmr_02_3)), EVT_INDEX_OF_GAME_FLAG(GF_TIK01_WarpPipes), MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe),  50, -10, -82, 0, tik_01_ENTRY_3,
        EVT_PTR(N(EVS_GotoMap_nok_02_2)), EVT_INDEX_OF_GAME_FLAG(GF_TIK01_WarpPipes), MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), -50, -10, -82, 0, tik_01_ENTRY_4,
        EVT_PTR(N(EVS_GotoMap_dro_01_2)), EVT_INDEX_OF_GAME_FLAG(GF_TIK01_WarpPipes), MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
