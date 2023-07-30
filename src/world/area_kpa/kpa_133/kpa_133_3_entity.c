#include "kpa_133.h"
#include "entity.h"
#include "effects.h"
#include "sprite/player.h"

extern EvtScript N(EVS_TriggerSwitch);
extern EvtScript N(EVS_SetupHiddenSpring);

API_CALLABLE(N(SetSpringRotation)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, MV_SpringEntityID));

    entity->rot.x = evt_get_variable(script, *args++);
    entity->rot.y = evt_get_variable(script, *args++);
    entity->rot.z = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetSpringPosition)) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, MV_SpringEntityID));

    entity->pos.x = evt_get_variable(script, *args++);
    entity->pos.y = evt_get_variable(script, *args++);
    entity->pos.z = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA133_BlueSwitch, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 60, 115, 10, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA133_HitWaterSwitch))
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_TriggerSwitch)))
    EVT_END_IF
    EVT_IF_EQ(GF_KPA133_BlueSwitch, TRUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 150, 115, 0, 90, 60, MAKE_ENTITY_END)
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 150, 150, -105, 90, 60, MAKE_ENTITY_END)
        EVT_SET(MV_SpringEntityID, LVar0)
        EVT_CALL(N(SetSpringRotation), -90, 0, 0)
        EVT_EXEC(N(EVS_SetupHiddenSpring))
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, -350, 215, -50, ITEM_SPAWN_MODE_KEY, GF_KPA133_Item_CastleKey2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupHiddenSpring) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_RevealHiddenSpring, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GF_KPA133_BlueSwitch, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GE(LVar0, 115)
        EVT_IF_LE(LVar0, 180)
            EVT_SET(LVar3, LVar0)
            EVT_IF_LT(LVar0, 150)
                EVT_ADD(LVar3, -40)
                EVT_SET(LVar4, 90)
            EVT_ELSE
                EVT_ADD(LVar3, 40)
                EVT_SET(LVar4, 270)
            EVT_END_IF
            EVT_THREAD
                EVT_WAIT(2)
                EVT_CALL(InterpPlayerYaw, LVar4, 0)
                EVT_WAIT(2)
                EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
                EVT_CALL(PlayerJump1, LVar3, LVar1, LVar2, 10)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_WAIT(5)
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 80, 15, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_kakusitobira, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 135, 115, -70, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 180, 115, -70, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 135, 115, -55, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 180, 115, -55, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 135, 115, -40, 0)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 180, 115, -40, 0)
        EVT_WAIT(20)
        EVT_CALL(EnableModel, MODEL_kakusitobira, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_123, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(18)
        EVT_CALL(PlaySoundAtNpc, NPC_Dummy, SOUND_1EF, SOUND_SPACE_MODE_0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, -90, 0, 15, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetSpringRotation), LVar0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(23)
            EVT_CALL(GetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
            EVT_CALL(N(SetSpringPosition), LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Dummy, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(SetNpcPos, NPC_Dummy, 150, 150, -105)
    EVT_CALL(SetNpcJumpscale, NPC_Dummy, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Dummy, 150, 115, 0, 17)
    EVT_CALL(GetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
    EVT_WAIT(20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TriggerSwitch) = {
    EVT_SET(MV_RevealHiddenSpring, TRUE)
    EVT_RETURN
    EVT_END
};
