#include "common.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_peach_focus

#include "battle/common/move/StarPowerSupport.inc.c"

enum N(ActorVars) {
    AVAR_Twink_PowerLevel   = 0,
    AVAR_Twink_DefensePtr   = 1,
};

API_CALLABLE(N(IncreaseTwinkDefense)) {
    // a pointer to Twink's DefenseTable is stored in his actorVar1 in twink.c
    // it has now been copied to this script var, where we can retrieve it
    s32* twinkDefenseTable = script->varTablePtr[0];

    // increment the value of the first key in the defense table
    twinkDefenseTable[1]++;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Run)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 16)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach2_Startle)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -105, -7, 0)
    EVT_CALL(SetBattleCamZoom, 213)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach3_Pray)
    EVT_CALL(PlaySound, SOUND_BEGIN_WISH)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(N(SpawnStarSparkleFX), LVar0, LVar1, LVar2)
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(GetActorVar, ACTOR_PARTNER, AVAR_Twink_PowerLevel, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ActorSpeak, MSG_CH8_0096, ACTOR_PLAYER, 0, ANIM_Peach3_Pray, ANIM_Peach3_Pray)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Idle)
    EVT_WAIT(10)
    EVT_CALL(PlaySound, SOUND_WISH_ASCENDING)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(N(SpawnWishSparkleFX), LVar0, LVar1, LVar2)
    EVT_WAIT(30)
    EVT_CALL(PlaySound, SOUND_STAR_POWER_RECOVERY)
    EVT_CALL(GetActorVar, ACTOR_PARTNER, AVAR_Twink_PowerLevel, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_PARTNER, AVAR_Twink_PowerLevel, LVar0)
    EVT_CALL(ModifyActorDecoration, ACTOR_PARTNER, 1, 0, LVar0, 0, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_PARTNER, AVAR_Twink_DefensePtr, LVar0)
    EVT_CALL(N(IncreaseTwinkDefense))
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT(1)
    EVT_CALL(PlayerYieldTurn)
    EVT_CALL(N(FadeBackgroundLighten))
    EVT_WAIT(15)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Peach1_Walk)
    EVT_RETURN
    EVT_END
};
