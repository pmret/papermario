#include "common.h"
#include "effects.h"
#include "entity.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_hammer_throw

#include "battle/common/move/HammerSupport.inc.c"

static s32 pad_images = 0;

#include "battle/move/hammer/dusty_hammer.png.inc.c"
#include "battle/move/hammer/dusty_hammer.pal.inc.c"

#include "battle/move/hammer/basic_hammer.png.inc.c"
#include "battle/move/hammer/basic_hammer.pal.inc.c"

#include "battle/move/hammer/super_hammer.png.inc.c"
#include "battle/move/hammer/super_hammer.pal.inc.c"

#include "battle/move/hammer/ultra_hammer.png.inc.c"
#include "battle/move/hammer/ultra_hammer.pal.inc.c"

#include "battle/move/hammer/hammer_throw.vtx.inc.c"

#include "battle/move/hammer/dusty_hammer.gfx.inc.c"
#include "battle/move/hammer/basic_hammer.gfx.inc.c"
#include "battle/move/hammer/super_hammer.gfx.inc.c"
#include "battle/move/hammer/ultra_hammer.gfx.inc.c"

EntityModelScript N(EMS_DustyHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(dusty_hammer_gfx), RENDER_MODE_ALPHATEST);
EntityModelScript N(EMS_BasicHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(basic_hammer_gfx), RENDER_MODE_ALPHATEST);
EntityModelScript N(EMS_SuperHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(super_hammer_gfx), RENDER_MODE_ALPHATEST);
EntityModelScript N(EMS_UltraHammer) = STANDARD_ENTITY_MODEL_SCRIPT(N(ultra_hammer_gfx), RENDER_MODE_ALPHATEST);

extern EvtScript N(EVS_UseMove_Impl);

EvtScript N(EVS_UseMove) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LVarD, 50)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
            EVT_EXEC_WAIT(N(EVS_UseMove_Impl))
        EVT_CASE_EQ(1)
            EVT_SET(LVarD, 50)
            EVT_SET(LVarE, 2)
            EVT_SET(LVarF, 4)
            EVT_EXEC_WAIT(N(EVS_UseMove_Impl))
        EVT_CASE_EQ(2)
            EVT_SET(LVarD, 50)
            EVT_SET(LVarE, 3)
            EVT_SET(LVarF, 6)
            EVT_EXEC_WAIT(N(EVS_UseMove_Impl))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3E5C) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Begin)
    EVT_SWITCH(LVar1)
        EVT_CASE_LT(3)
            EVT_WAIT(4)
        EVT_CASE_LT(5)
            EVT_WAIT(3)
        EVT_CASE_LT(7)
            EVT_WAIT(2)
        EVT_CASE_LT(9)
            EVT_WAIT(1)
        EVT_CASE_LT(11)
            EVT_WAIT(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A3FE0) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Begin)
    EVT_SWITCH(LVar1)
        EVT_CASE_LT(3)
            EVT_WAIT(4)
        EVT_CASE_LT(5)
            EVT_WAIT(3)
        EVT_CASE_LT(7)
            EVT_WAIT(2)
        EVT_CASE_LT(9)
            EVT_WAIT(1)
        EVT_CASE_LT(11)
            EVT_WAIT(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802A4164) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(10)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Begin)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Begin)
    EVT_SWITCH(LVar1)
        EVT_CASE_LT(3)
            EVT_WAIT(4)
        EVT_CASE_LT(5)
            EVT_WAIT(3)
        EVT_CASE_LT(7)
            EVT_WAIT(2)
        EVT_CASE_LT(9)
            EVT_WAIT(1)
        EVT_CASE_LT(11)
            EVT_WAIT(0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseMove_Impl) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 16)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(AddGoalPos, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_802A3E5C))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_802A3FE0))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_802A4164))
    EVT_END_SWITCH
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    EVT_CALL(AddBattleCamZoom, 50)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_WINDUP)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Raise)
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Hold1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Raise)
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Hold1)
        EVT_CASE_EQ(2)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Raise)
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Hold1)
    EVT_END_SWITCH
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(N(ShouldMovesAutoSucceed))
        EVT_IF_EQ(LVar0, 0)
            EVT_LOOP(45)
                EVT_WAIT(1)
                EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
                EVT_IF_NE(LVar0, FALSE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
        EVT_ADD(LVarD, 6)
        EVT_CALL(action_command_hammer_start, 0, LVarD, 3)
        EVT_CALL(SetActionQuality, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(30)
            EVT_WAIT(1)
            EVT_CALL(GetActionQuality, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_NE(LVar1, 1)
                    EVT_CALL(GetMenuSelection, LVar3, LVar4, LVar5)
                    EVT_SWITCH(LVar4)
                        EVT_CASE_EQ(0)
                            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Hold2)
                        EVT_CASE_EQ(1)
                            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Hold2)
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Hold2)
                    EVT_END_SWITCH
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_ELSE
        EVT_WAIT(10)
        EVT_CALL(GetMenuSelection, LVar3, LVar4, LVar5)
        EVT_SWITCH(LVar4)
            EVT_CASE_EQ(0)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Hold2)
            EVT_CASE_EQ(1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Hold2)
            EVT_CASE_EQ(2)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Hold2)
        EVT_END_SWITCH
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetActionSuccess, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow1_Throw)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow2_Throw)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_2)
        EVT_CASE_EQ(2)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB2_HammerThrow3_Throw)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HAMMER_SWING_3)
    EVT_END_SWITCH
    EVT_WAIT(3)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(EMS_BasicHammer)))
        EVT_CASE_EQ(1)
            EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(EMS_SuperHammer)))
        EVT_CASE_EQ(2)
            EVT_CALL(CreateVirtualEntity, LVarA, EVT_PTR(N(EMS_UltraHammer)))
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 42)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetVirtualEntityScale, LVarA, EVT_FLOAT(0.6), EVT_FLOAT(0.6), EVT_FLOAT(0.6))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetPlayerActionSuccess, LVar3)
    EVT_SWITCH(LVar3)
        EVT_CASE_GT(FALSE)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(9)
                    EVT_ADD(LVar0, 60)
                    EVT_CALL(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(1.3))
            EVT_ADD(LVar2, 5)
            EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 11)
        EVT_CASE_DEFAULT
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(18)
                    EVT_ADD(LVar0, 60)
                    EVT_CALL(SetVirtualEntityRotation, LVarA, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(0.7))
            EVT_ADD(LVar2, 5)
            EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 20)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(PlayerTestEnemy, LVar3, DAMAGE_TYPE_SMASH | DAMAGE_TYPE_NO_CONTACT, 25, 0, 0, 16)
    EVT_IF_EQ(LVar3, HIT_RESULT_MISS)
        EVT_CALL(VirtualEntityLandJump, LVarA)
        EVT_CALL(DeleteVirtualEntity, LVarA)
        EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_RETURN
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(GetPlayerActionSuccess, LVar3)
        EVT_SWITCH(LVar3)
            EVT_CASE_GT(FALSE)
                EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(1.4))
                EVT_ADD(LVar0, 60)
                EVT_ADD(LVar1, 0)
                EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 10)
                EVT_CALL(DeleteVirtualEntity, LVarA)
            EVT_CASE_DEFAULT
                EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(0.8))
                EVT_ADD(LVar0, 40)
                EVT_ADD(LVar1, 0)
                EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 15)
                EVT_CALL(DeleteVirtualEntity, LVarA)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MIN)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.3))
                    EVT_END_THREAD
                EVT_CASE_EQ(1)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.6))
                    EVT_END_THREAD
                EVT_CASE_EQ(2)
                    EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.9))
                    EVT_END_THREAD
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HAMMER_STRIKE)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_1)
        EVT_CASE_EQ(1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_2)
        EVT_CASE_EQ(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_D_DOWN_HIT_3)
    EVT_END_SWITCH
    EVT_CALL(GetPlayerActionSuccess, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_THROW | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENTS_HAMMER, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_NICE_HIT)
        EVT_CASE_DEFAULT
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_NORMAL)
                EVT_CASE_EQ(1)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
                EVT_CASE_EQ(2)
                    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_SILENT)
            EVT_END_SWITCH
            EVT_CALL(PlayerDamageEnemy, LVar0, DAMAGE_TYPE_THROW | DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENTS_HAMMER, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE)
        EVT_CASE_OR_EQ(HIT_RESULT_NICE_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_A))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_Hammer_ReturnHome_C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
