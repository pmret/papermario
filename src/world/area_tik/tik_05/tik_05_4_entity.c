#include "tik_05.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

extern s16 Entity_ScriptSpring_AnimLaunch[];

API_CALLABLE(N(PlaySpringAnimation)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(script, *args++));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_BreakBlock_DropSpring) = {
    EVT_IF_EQ(GF_TIK05_SpringBrick, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_TIK05_SpringBrick, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar5, 25)
    EVT_CALL(MakeLerp, 75, 105, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_Unk_00, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_SUB(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, LVar0, -10, 22, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_Unk_00, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_SUB(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    EVT_CALL(PlaySoundAt, SOUND_SPRING, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    EVT_CALL(N(PlaySpringAnimation), MV_Unk_00)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest) = EVT_OPEN_CHEST_BADGE(ITEM_POWER_SMASH1, GF_TIK05_Chest_PowerSmash1);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), -185, 60, -25, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_TIK05_Chest_PowerSmash1)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 25, 50, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_DropSpring)))
    EVT_IF_EQ(GF_TIK05_SpringBrick, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 25, 75, 0, 0, 100, MAKE_ENTITY_END)
        EVT_SET(MV_Unk_00, LVar0)
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), -35, -10, 0, 0, 100, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
