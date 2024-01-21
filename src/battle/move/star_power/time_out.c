#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKlevar.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_time_out

#include "battle/common/move/StarPowerSupport.inc.c"

EvtScript N(EVS_UsePower) = {
    ExecWait(N(EVS_StarPower_WishForSpirit))
    SetConst(LVar0, ANIM_BattleKlevar_Idle)
    ExecWait(N(EVS_StarPower_SpiritSummoned))
    Call(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleKlevar_Shout)
    Wait(16)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(PlaySound, SOUND_TIME_OUT)
    PlayEffect(EFFECT_STOP_WATCH, 0, 0, 0, 0, Float(1.0), 200, 0)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TIME_OUT)
    Wait(200)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, 0, 0, 0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, DMG_STATUS_KEY(STATUS_FLAG_STOP, 5, 100), 0, BS_FLAGS1_TRIGGER_EVENTS)
        Wait(5)
        Label(1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(5)
    Call(PlayerYieldTurn)
    ExecWait(N(EVS_StarPower_SpiritDeparts))
    ExecWait(N(EVS_StarPower_EndWish))
    Return
    End
};
