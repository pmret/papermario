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
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleMamar_Idle)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleMamar_Shout)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_LULLABY)
    EVT_CALL(N(SpawnMusicNotesFX))
    EVT_WAIT(30)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, 0, 0, 0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, DMG_STATUS_KEY(STATUS_FLAG_SLEEP, 3, 100), 0, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_LABEL(1)
        EVT_WAIT(5)
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
