#include "trd_01.h"
#include "entity.h"

extern EvtScript N(EVS_ExitDoors_trd_02_0);

EvtScript N(EVS_FocusCamOnLock) = {
    EVT_LABEL(0)
        EVT_IF_EQ(GF_TRD01_Item_FortressKey, TRUE)
            EVT_CALL(AwaitPlayerApproach, 320, 0, 40)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 220, 0, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 0, 0)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
            EVT_CALL(GetCamPosA, CAM_DEFAULT, LVar0, LVar1)
            EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-64.0), LVar1)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(AwaitPlayerLeave, 320, 0, 60)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockDoors) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_KOOPA_FORTRESS_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_TRD01_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_Padlock_EntityIndex, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_Padlock_EntityIndex)
    EVT_CALL(N(RemovePadlock))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindLockTrigger) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TRD01_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 315, 8, 0, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BindLockTrigger)))
        EVT_SET(MV_Padlock_EntityIndex, LVar0)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 0, 220, 255, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TRD01_RaiseStairs))
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_SMASH_CHARGE, -268, 656, -40, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_TRD01_Item_SmashCharge)
    EVT_IF_EQ(GF_TRD01_Defeated_KoopaGuard, TRUE)
        EVT_IF_EQ(GF_TRD01_Item_FortressKey, FALSE)
            EVT_CALL(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, 254, 0, 30, ITEM_SPAWN_MODE_KEY, GF_TRD01_Item_FortressKey)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
