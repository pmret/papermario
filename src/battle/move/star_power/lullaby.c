#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleMamar.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_lullaby

#include "battle/common/move/StarPowerSupport.inc.c"

API_CALLABLE(N(SpawnMusicNotesFX)) {
    s32 x, y;
    
    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[2] = -80;
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
        case 1:
            x = script->functionTemp[2];
            y = 30.0f + 30.0f * sin_rad(DEG_TO_RAD(script->functionTemp[1]));
            fx_music_note(0, x, y, 50.0f);

            script->functionTemp[2] += 14;
            script->functionTemp[1] += 20;

            if (script->functionTemp[1] >= 360) {
                return ApiStatus_DONE2;
            }
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_UsePower) = {
    ExecWait(N(EVS_StarPower_WishForSpirit))
    SetConst(LVar0, ANIM_BattleMamar_Idle)
    ExecWait(N(EVS_StarPower_SpiritSummoned))
    Call(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMamar_Shout)
    Wait(16)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Wait(15)
    Call(PlaySound, SOUND_LULLABY)
    Call(N(SpawnMusicNotesFX))
    Wait(30)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, 0, 0, 0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, DMG_STATUS_KEY(STATUS_FLAG_SLEEP, 3, 100), 0, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Wait(5)
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
