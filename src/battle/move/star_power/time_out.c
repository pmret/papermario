#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKlevar.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_time_out

#include "battle/common/move/StarPowerSupport.inc.c"

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleKlevar_Idle)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleKlevar_Shout)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(PlaySound, SOUND_TIME_OUT)
    EVT_PLAY_EFFECT(EFFECT_STOP_WATCH, 0, 0, 0, 0, EVT_FLOAT(1.0), 200, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TIME_OUT)
    EVT_WAIT(200)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, DMG_STATUS_KEY(STATUS_FLAG_STOP, 5, 100), 0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_WAIT(5)
        EVT_LABEL(1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlayerYieldTurn)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritDeparts))
    EVT_EXEC_WAIT(N(EVS_StarPower_EndWish))
    EVT_RETURN
    EVT_END
};
