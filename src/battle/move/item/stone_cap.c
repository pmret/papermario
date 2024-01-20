#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_stone_cap

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_7217DC)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            inflict_status(player, STATUS_KEY_STONE, script->varTable[0]);
            player->statusAfflicted = 0;
            script->functionTemp[1] = 3;
            script->functionTemp[0] = 1;
            break;

        case 1:
            for (i = 0; i < 10; i++) {
                f32 x = player->curPos.x + ((rand_int(20) - 10) * player->scalingFactor);
                f32 y = player->curPos.y + ((rand_int(20) + 10) * player->scalingFactor);
                f32 z = player->curPos.z + 5.0f;
                fx_floating_cloud_puff(0, x, y, z, 1.0f, 25);
            }

            if (script->functionTemp[1] == 0) {
                BattleStatus* battleStatus2 = &gBattleStatus;

                battleStatus2->flags1 &= ~BS_FLAGS1_HUSTLED;
                battleStatus->hustleTurns = 0;
                battleStatus->itemUsesLeft = 0;

                return ApiStatus_DONE2;
            }

            script->functionTemp[1]--;
            break;
    }

    return ApiStatus_BLOCK;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_STONE_CAP)
    ExecWait(N(UseItemWithEffect))
    Call(PlaySound, SOUND_PUT_ON_CAP)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_AdjustCap)
    Wait(30)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
    Call(GetItemPower, ITEM_STONE_CAP, LVar0, LVar1)
    Call(PlaySound, SOUND_BECOME_STONE)
    Call(N(func_802A123C_7217DC))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Wait(20)
    Return
    End
};
