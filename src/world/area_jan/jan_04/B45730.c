#include "jan_04.h"
#include "world/partners.h"

extern s32 D_8024625C_B4A9CC;
extern Evt* D_8024A290;

ApiStatus func_80240FC0_B45730(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    EvtScript* rideScript;

    switch (D_8024625C_B4A9CC) {
        case 0:
            rideScript = partner_get_ride_script();
            if (rideScript != NULL) {
                Evt* newScript;

                D_8024625C_B4A9CC++;
                newScript = start_script(rideScript, 0, EVT_FLAG_20);
                newScript->varTable[1] = playerStatus->position.x - 10.0f;
                newScript->varTable[2] = playerStatus->position.y;
                newScript->varTable[3] = playerStatus->position.z;
                D_8024A290 = newScript;
                newScript->varTable[12] = 1;
            }
            break;
        case 1:
        case 2:
            D_8024625C_B4A9CC++;
            break;
        case 3:
            wPartnerNpc->yaw = 270.0f;
            playerStatus->targetYaw = 270.0f;
            playerStatus->currentYaw = 270.0f;
            playerStatus->spriteFacingAngle = 180.0f;
            D_8024A290->functionTemp[1] = 1;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
