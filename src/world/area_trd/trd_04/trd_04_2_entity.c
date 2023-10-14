#include "trd_04.h"
#include "entity.h"

extern EvtScript N(EVS_ExitDoors_trd_05_0);
extern EvtScript N(EVS_ExitDoors_trd_03_3);

#include "world/common/todo/RemovePadlock.inc.c"

#include "world/common/todo/SetEntityPosition.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(missing_80244D70_4D70)[] = {
    0x00000000, 0x00010101, 0x01010101, 0x01010101,
    0x01000000, 0x00000000, 0x00000101, 0x01010101,
    0x01010101, 0x01010000, 0x00000000, 0x00000001,
    0x01010101, 0x01010101, 0x01010100, 0x00000000,
    0x00000000, 0x01010101, 0x01010101, 0x01010101,
    0x00000000, 0x00000000, 0x00010101, 0x01010101,
    0x01010101, 0x01000000, 0x00000000, 0x00000101,
    0x01010101, 0x01010101, 0x01010000, 0x00000000,
    0x00000001, 0x01010101, 0x01010101, 0x01010100,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x01010101, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00010101, 0x01000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000101, 0x01010000,
    0x00000000, 0x00000000,
};

EvtScript N(EVS_UnlockUpperLeftDoors) = {
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
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_TRD04_UnlockedUpperDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_Unk_00, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_Unk_00)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnlockLowerRightDoors) = {
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
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_TRD04_UnlockedLowerDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_Unk_01, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_Unk_01)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Padlock_LowerDoors) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Padlock_UpperDoors) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_03_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropSwitch) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -188, 0, -43)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -188, 0, -43)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(510.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(3 * DT)
    EVT_CALL(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, -180, 175, -35)
    EVT_CALL(MakeLerp, 175, 0, 20 * DT, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_EntityID_Switch, -180, LVar0, -35)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, -180, 0, -35)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_WAIT(20 * DT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TRD04_UnlockedLowerDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 265, 8, 90, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_Padlock_LowerDoors)))
        EVT_SET(MV_Unk_01, LVar0)
    EVT_END_IF
    EVT_IF_EQ(GF_TRD04_UnlockedUpperDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), -265, 195, -55, 80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_Padlock_UpperDoors)))
        EVT_SET(MV_Unk_00, LVar0)
    EVT_END_IF
    EVT_IF_LE(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TRD04_LowerStairs))
        EVT_SET(MV_EntityID_Switch, LVar0)
        EVT_IF_EQ(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
            EVT_CALL(N(SetEntityPosition), MV_EntityID_Switch, -180, 0, -35)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
