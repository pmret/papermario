#include "obk_03.h"
#include "entity.h"
#include "sprite/player.h"

extern EvtScript N(EVS_HitSwitch_Second);
extern EvtScript N(EVS_HitSwitch_Third);

#include "world/common/todo/SetEntityPosition.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_SecondSwitch_Drop) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(N(GetEntityPosition), LVar7, LVarA, LVarB, LVarC)
        EVT_CALL(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, LVarA, LVarB, LVarC)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar3, LVar5, LVar6, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), LVar7, LVar2, LVar0, LVar4)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(GetEntityPosition), LVar7, LVarA, LVarB, LVarC)
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVarA, LVarB, LVarC)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, LVar8, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ThirdSwitch_Drop) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(N(GetEntityPosition), LVar7, LVarA, LVarB, LVarC)
        EVT_CALL(PlaySoundAt, SOUND_LARGE_FALL_QUICK, SOUND_SPACE_DEFAULT, LVarA, LVarB, LVarC)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, LVar3, LVar5, LVar6, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), LVar7, LVar2, LVar0, LVar4)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(GetEntityPosition), LVar7, LVarA, LVarB, LVarC)
    EVT_CALL(PlaySoundAt, SOUND_HEAVY_OBJECT_DROP, SOUND_SPACE_DEFAULT, LVarA, LVarB, LVarC)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, LVar8, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

// if the player is under the switch as it falls, jump out of the way
EvtScript N(EVS_SecondSwitch_JumpToSafety) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, 340)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar0, 372)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar2, -115)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar2, -85)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
    EVT_WAIT(8 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_CALL(PlayerJump1, 330, -210, -49, 10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(5 * DT)
    EVT_RETURN
    EVT_END
};

// if the player is under the switch as it falls, jump out of the way
EvtScript N(EVS_ThirdSwitch_JumpToSafety) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, 394)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar0, 470)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar2, -135)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar2, -62)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
    EVT_WAIT(8 * DT)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_CALL(PlayerJump1, 352, -210, -5, 10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(5 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitSwitch_First) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 360, -210, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_OBK03_HitSecondSwitch))
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_HitSwitch_Second)))
    EVT_EXEC(N(EVS_SecondSwitch_JumpToSafety))
    EVT_SET(LVar2, 360)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, -100)
    EVT_SET(LVar5, -210)
    EVT_SET(LVar6, 20 * DT)
    EVT_SET(LVar7, LVar0)
    EVT_SET(LVar8, 5)
    EVT_EXEC_WAIT(N(EVS_SecondSwitch_Drop))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitSwitch_Second) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HugeBlueSwitch), 440, -210, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_OBK03_HitThirdSwitch))
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_HitSwitch_Third)))
    EVT_EXEC(N(EVS_ThirdSwitch_JumpToSafety))
    EVT_SET(LVar2, 440)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, -100)
    EVT_SET(LVar5, -210)
    EVT_SET(LVar6, 20 * DT)
    EVT_SET(LVar7, LVar0)
    EVT_SET(LVar8, 30)
    EVT_EXEC_WAIT(N(EVS_ThirdSwitch_Drop))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitSwitch_Third) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_HIT_HUGE_BLUE_SWITCH)
        EVT_EXEC(N(EVS_Scene_DropSteps))
        EVT_SET(GB_StoryProgress, STORY_CH3_HIT_HUGE_BLUE_SWITCH)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_HIT_HUGE_BLUE_SWITCH)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 300, -210, -100, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_OBK03_HitFirstSwitch))
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_HitSwitch_First)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -130, 0, -50, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignCrateFlag, GF_OBK03_Crate_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 155, 0, -100, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -165, 0, -50, 0, -1, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
