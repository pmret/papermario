#include "common.h"
#include "hud_element.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleEldstar.h"
#include "sprite/player.h"

#define NAMESPACE battle_move_refresh

#include "battle/common/move/StarPowerSupport.inc.c"

API_CALLABLE(N(FlyAroundPlayer)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID;
    Npc* npc;

    enum {
        STATE_INIT      = 0,
        STATE_FLYING    = 1,
        STATE_DONE      = 2,
    };

    if (isInitialCall) {
        script->functionTemp[0] = STATE_INIT;
    }

    npc = script->functionTempPtr[1];

    switch (script->functionTemp[0]) {
        case STATE_INIT:
            npcID = evt_get_variable(script, *args++);
            script->functionTempPtr[1] = npc = get_npc_unsafe(npcID);
            npc->planarFlyDist = 0;
            npc->yaw = 0;
            npc->duration = 0;
            npc->jumpVel = -1.5f;
            npc->jumpScale = 0.02f;
            npc->moveSpeed = 1.0f;
            npc->moveToPos.x = npc->pos.x;
            npc->moveToPos.y = npc->pos.y;
            npc->moveToPos.z = npc->pos.z;
            script->functionTemp[0] = STATE_FLYING;
            break;
        case STATE_FLYING:
            if (npc->jumpVel < 0.0f) {
                npc->planarFlyDist += 3.0;
                if (npc->planarFlyDist > 40.0f) {
                    npc->planarFlyDist = 40.0f;
                }
            } else {
                npc->planarFlyDist -= 2.0;
                if (npc->planarFlyDist < 20.0f) {
                    npc->planarFlyDist = 20.0f;
                }
            }

            npc->moveSpeed += 0.75;
            npc->jumpVel += npc->jumpScale;
            npc->pos.y += npc->jumpVel;
            if (npc->moveSpeed > 33.0f) {
                npc->moveSpeed = 33.0f;
            }

            npc->yaw += npc->moveSpeed;
            npc->pos.x = npc->moveToPos.x;
            npc->pos.z = npc->moveToPos.z;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->planarFlyDist, npc->yaw);
            if ((npc->duration % 14) == 0) {
                fx_sparkles(0, npc->pos.x, npc->pos.y, npc->pos.z, 30.0f);
            }

            npc->duration++;
            if (npc->duration > 40) {
                npc->jumpScale = 0.5f;
            }
            if (npc->pos.y > 200.0f) {
                script->functionTemp[0] = STATE_DONE;
            }
            break;
        case STATE_DONE:
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(RemovePlayerDebuffs)) {
    Actor* actor = gBattleStatus.playerActor;

    if (actor->debuff != 0) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_debuff(actor->hudElementDataIndex);
    }

    if (actor->koStatus != 0) {
        actor->koDuration = 0;
        actor->koStatus = 0;
        actor->disableEffect->data.disableX->koDuration = 0;
    }

    btl_update_ko_status();
    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

API_CALLABLE(N(SpawnHeartRecoverFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_recover(0, x, y, z, duration);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnFlowerRecoverFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_recover(1, x, y, z, duration);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(EVS_StarPower_WishForSpirit))
    EVT_SET_CONST(LVar0, ANIM_BattleEldstar_Idle)
    EVT_EXEC_WAIT(N(EVS_StarPower_SpiritSummoned))
    EVT_CALL(SetNpcAnimation, NPC_BTL_SPIRIT, ANIM_BattleEldstar_Shout)
    EVT_WAIT(16)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_REFRESH)
    EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
    EVT_CALL(N(FlyAroundPlayer), NPC_BTL_SPIRIT)
    EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
    EVT_CALL(DeleteNpc, NPC_BTL_SPIRIT)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_CALL(N(SpawnHeartRecoverFX), LVar0, LVar1, LVar2, 5)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 25)
    EVT_CALL(N(SpawnFlowerRecoverFX), LVar0, LVar1, LVar2, 5)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 5)
    EVT_CALL(N(AddHP), 5)
    EVT_CALL(N(AddFP), 5)
    EVT_CALL(N(RemovePlayerDebuffs))
    EVT_WAIT(30)
    EVT_CALL(PlayerYieldTurn)
    EVT_EXEC_WAIT(N(EVS_StarPower_EndWish))
    EVT_RETURN
    EVT_END
};
