#include "common.h"
#include "npc.h"

void ai_suspend_for_time(Evt* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = script->functionTemp[1];
    }
}

void basic_ai_suspend(Evt* script) {
    Enemy* enemy = script->owner1.enemy;

    get_npc_unsafe(enemy->npcID);
    if (enemy->aiSuspendTime == 0) {
        script->functionTemp[0] = script->functionTemp[1];
    }
}

b32 ai_check_fwd_collisions(Npc* npc, f32 time, f32* outYaw, f32* outDistFwd, f32* outDistCW, f32* outDistCCW) {
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    f32 x3, y3, z3;
    f32 fwdHitDist = -1.0f;
    f32 cwHitDist = -1.0f;
    f32 ccwHitDist = -1.0f;
    f32 yaw;
    b32 fwdHit;

    x1 = npc->pos.x;
    y1 = npc->pos.y;
    z1 = npc->pos.z;
    yaw = *outYaw;

    fwdHit = npc_test_move_simple_with_slipping(npc->collisionChannel,
            &x1, &y1, &z1,
            npc->moveSpeed * time,
            yaw,
            npc->collisionHeight,
            npc->collisionDiameter);

    if (fwdHit) {
        fwdHitDist = dist2D(npc->pos.x, npc->pos.z, x1, z1);

        x2 = npc->pos.x;
        y2 = npc->pos.y;
        z2 = npc->pos.z;
        if (npc_test_move_simple_with_slipping(npc->collisionChannel,
                &x2, &y2, &z2, npc->moveSpeed * time,
                clamp_angle(yaw + 35.0f),
                npc->collisionHeight,
                npc->collisionDiameter) != 0) {
            cwHitDist = dist2D(npc->pos.x, npc->pos.z, x2, z2);
        }

        x3 = npc->pos.x;
        y3 = npc->pos.y;
        z3 = npc->pos.z;
        if (npc_test_move_simple_with_slipping(npc->collisionChannel,
                &x3, &y3, &z3,
                npc->moveSpeed * time,
                clamp_angle(yaw - 35.0f),
                npc->collisionHeight,
                npc->collisionDiameter) != 0) {
            ccwHitDist = dist2D(npc->pos.x, npc->pos.z, x3, z3);
        }

        if ((cwHitDist < fwdHitDist && ccwHitDist < cwHitDist) || (ccwHitDist < fwdHitDist && cwHitDist < ccwHitDist)) {
            yaw = npc->yaw;
        } else if ((fwdHitDist < cwHitDist && ccwHitDist < fwdHitDist) || (ccwHitDist < cwHitDist && fwdHitDist < ccwHitDist)) {
            yaw = npc->yaw + 35.0f;
        } else if ((fwdHitDist < ccwHitDist && cwHitDist < fwdHitDist) || (cwHitDist < ccwHitDist && fwdHitDist < cwHitDist)) {
            yaw = npc->yaw - 35.0f;
        }
    }

    if (outYaw != nullptr) {
        *outYaw = clamp_angle(yaw);
    }
    if (outDistFwd != nullptr) {
        *outDistFwd = fwdHitDist;
    }
    if (outDistCW != nullptr) {
        *outDistCW = cwHitDist;
    }
    if (outDistCCW != nullptr) {
        *outDistCCW = ccwHitDist;
    }
    return fwdHit;
}
