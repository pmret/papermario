#include "common.h"

ApiStatus func_802A1000_73D860(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* secondBattleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 posX = playerActor->currentPos.x;
    f32 posY = playerActor->currentPos.y;
    f32 posZ = playerActor->currentPos.z;
    f32 goalX = playerActor->movePos.goal.x;
    f32 goalY = playerActor->movePos.goal.y;
    f32 goalZ = playerActor->movePos.goal.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (secondBattleStatus->unk_83 != 0) {
        if (script->varTable[0] < 6) {
            script->varTable[0] = 6;
        }
    } else if (script->varTable[0] < 12) {
        script->varTable[0] = 12;
    }

    return ApiStatus_DONE2;
}

// NOT WORKING
// TODO JUMP TABLE ETHAN
#ifdef NON_MATCHING
ApiStatus func_802A10E4_73D944(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[16] = 1;

    if (playerData->bootsLevel != 1) {
        if (playerData->bootsLevel < 2) {
            if (playerData->bootsLevel != 0) {
                return ApiStatus_DONE2;
            }
        } else {
            if (playerData->bootsLevel != 2) {
                return ApiStatus_DONE2;
            }
            script->varTable[16] = 3;
        }
    } else {
        script->varTable[16] = 2;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/move/jump_73D860", func_802A10E4_73D944);
#endif

