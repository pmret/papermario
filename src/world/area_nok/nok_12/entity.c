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
    Call(N(SetNpcVarSafe), NPC_SpikedGoomba, 0, 1)
    Return
    End
};

EvtScript N(EVS_OnShakeTree_DropSwitch) = {
    IfLt(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
        Set(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
        Wait(15)
        SetGroup(EVT_GROUP_NEVER_PAUSE)
        Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        Call(DisablePlayerInput, TRUE)
        Call(MakeLerp, 95, 0, 12, EASING_QUADRATIC_IN)
        Label(0)
            Call(UpdateLerp)
            Call(N(SetEntityPosition), MV_SwitchEntityID, -470, LVar0, -150)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(0)
            EndIf
        Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, -470, LVar0, -150)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
        Thread
            Wait(5)
            Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
        EndThread
        Call(DisablePlayerInput, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfLe(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
        IfEq(GB_StoryProgress, STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
            Call(MakeEntity, Ref(Entity_BlueSwitch), -470, 0, -150, 0, MAKE_ENTITY_END)
            Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_NOK12_HitSwitch))
        Else
            Call(MakeEntity, Ref(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
            Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_NOK12_HitSwitch))
            Set(MV_SwitchEntityID, LVar0)
        EndIf
    EndIf
    Call(MakeEntity, Ref(Entity_YellowBlock), -560, 60, -120, 0, ITEM_POW_BLOCK, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_NOK12_ItemBlock_POWBlock)
    Call(MakeEntity, Ref(Entity_BrickBlock), -165, 60, -130, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_BreakBlock_Ambush)))
    Call(MakeEntity, Ref(Entity_BrickBlock), 520, 110, -180, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 595, 110, -180, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 720, 135, -180, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 820, 135, -180, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_NOK12_MultiCoinBrick)
    Call(MakeItemEntity, ITEM_STAR_PIECE, -220, -50, 155, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK12_Item_StarPiece)
    Call(MakeItemEntity, ITEM_SLEEPY_SHEEP, 392, 25, -145, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK12_Item_SleepySheep)
    Return
    End
};
