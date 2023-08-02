#include "kmr_11.h"
#include "entity.h"
#include "effects.h"

API_CALLABLE(N(SetBlueSwitchPosition)) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->pos.x = script->varTable[0];
    entity->pos.y = script->varTable[1];
    entity->pos.z = script->varTable[2];

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_OverhearEnemies) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_RedGoombaBro, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, LVar0, LVar1, LVar2)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D3)
    EVT_CALL(SpeakToPlayer, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00D4)
    EVT_CALL(SpeakToPlayer, NPC_GoombaKing, ANIM_GoombaKing_Idle, ANIM_GoombaKing_Idle, 0, MSG_CH0_00D5)
    EVT_CALL(SpeakToPlayer, NPC_BlueGoombaBro, ANIM_GoombaBros_Blue_Talk, ANIM_GoombaBros_Blue_Idle, 0, MSG_CH0_00D6)
    EVT_CALL(SpeakToPlayer, NPC_RedGoombaBro, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Idle, 0, MSG_CH0_00D7)
    EVT_CALL(SetNpcPos, NPC_RedGoombaBro, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

// NPC_BlueGoombaBro is reused here to do the blue switch jumping
EvtScript N(EVS_TetherSwitchToBlueGoomba) = {
    EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_BlueGoombaBro, LVar0, LVar1, LVar2)
        EVT_SET(LVarA, MV_SwitchEntityID)
        EVT_CALL(N(SetBlueSwitchPosition))
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_SwitchBush) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_FOUND_GATEHOUSE_SWITCH)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, -377, -8, 81)
    EVT_CALL(SetNpcFlagBits, NPC_BlueGoombaBro, NPC_FLAG_HAS_NO_SPRITE, TRUE)
    EVT_EXEC_GET_TID(N(EVS_TetherSwitchToBlueGoomba), LVarB)
    EVT_CALL(SetNpcJumpscale, NPC_BlueGoombaBro, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump0, NPC_BlueGoombaBro, -445, 0, 92, 15 * DT)
    EVT_CALL(PlaySoundAt, SOUND_48, SOUND_SPACE_MODE_0, -469, 1, 92)
    EVT_CALL(SetNpcJumpscale, NPC_BlueGoombaBro, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump0, NPC_BlueGoombaBro, -469, 0, 92, 7 * DT)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(SetNpcPos, NPC_BlueGoombaBro, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH0_FOUND_GATEHOUSE_SWITCH)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreak_SpecialBrick) = {
    EVT_CALL(PlaySound, SOUND_B)
    EVT_CALL(PlaySoundAt, SOUND_2108, SOUND_SPACE_MODE_0, 665, 35, 70)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, 665, 48, 70, 10)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 665, 35, 70, 45, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR11_ItemBlock_SuperShroom)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LE(GB_StoryProgress, STORY_CH0_FOUND_GATEHOUSE_SWITCH)
        EVT_IF_EQ(GB_StoryProgress, STORY_CH0_FOUND_GATEHOUSE_SWITCH)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), -469, 0, 153, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KMR_04))
            EVT_SET(MV_SwitchEntityID, LVar0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_SelfDestruct)), TRIGGER_AREA_FLAG_SET, AF_KMR_04, 1, 0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_OverhearEnemies)), TRIGGER_WALL_PRESS_A, COLLIDER_tt, 1, 0)
        EVT_ELSE
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KMR_04))
            EVT_SET(MV_SwitchEntityID, LVar0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_SelfDestruct)), TRIGGER_AREA_FLAG_SET, AF_KMR_04, 1, 0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_OverhearEnemies)), TRIGGER_WALL_PRESS_A, COLLIDER_tt, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 625, -25, 110, 45, MAKE_ENTITY_END)
    EVT_IF_EQ(GF_KMR11_ItemBlock_SuperShroom, FALSE)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreak_SpecialBrick)))
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 665, 35, 70, 45, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
        EVT_CALL(AssignBlockFlag, GF_KMR11_ItemBlock_SuperShroom)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 550, 0, -550, 0, MODEL_point, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KMR11_HiddenPanel)
    EVT_RETURN
    EVT_END
};
