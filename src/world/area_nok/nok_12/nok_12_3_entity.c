#include "nok_12.h"
#include "entity.h"

API_CALLABLE(N(SetNpcVarSafe)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 varIdx = evt_get_variable(script, *args++);
    s32 val = evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = enemy->npcID;
    }

    enemy = get_enemy_safe(npcID);
    if (enemy != NULL) {
        enemy->varTable[varIdx] = val;
    }

    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"

EvtScript N(EVS_BreakBlock_Ambush) = {
    EVT_CALL(N(SetNpcVarSafe), NPC_SpikedGoomba, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnShakeTree_DropSwitch) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
        EVT_SET(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
        EVT_WAIT(15)
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(MakeLerp, 95, 0, 12, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetEntityPosition), MV_SwitchEntityID, -470, LVar0, -150)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, -470, LVar0, -150)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_END_THREAD
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LE(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
        EVT_IF_EQ(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), -470, 0, -150, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_NOK12_HitSwitch))
        EVT_ELSE
            EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_NOK12_HitSwitch))
            EVT_SET(MV_SwitchEntityID, LVar0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -560, 60, -120, 0, ITEM_POW_BLOCK, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_NOK12_ItemBlock_POWBlock)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -165, 60, -130, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_Ambush)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 520, 110, -180, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 595, 110, -180, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 720, 135, -180, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 820, 135, -180, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_NOK12_MultiCoinBrick)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -220, -50, 155, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK12_Item_StarPiece)
    EVT_CALL(MakeItemEntity, ITEM_SLEEPY_SHEEP, 392, 25, -145, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK12_Item_SleepySheep)
    EVT_RETURN
    EVT_END
};
