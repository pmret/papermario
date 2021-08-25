#include "common.h"
#include "map.h"

void func_8004A6F0(Evt* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = script->functionTemp[1];
    }
}

void func_8004A73C(Evt* script) {
    Enemy* enemy = script->owner1.enemy;

    get_npc_unsafe(enemy->npcID);
    if (enemy->unk_B4 == 0) {
        script->functionTemp[0] = script->functionTemp[1];
    }
}

s32 func_8004A784(Npc* npc, f32 arg1, f32* outYaw, f32* outDist1, f32* outDist2, f32* outDist3) {
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    f32 x3, y3, z3;
    f32 dist1 = -1.0f;
    f32 dist2 = -1.0f;
    f32 dist3 = -1.0f;
    f32 yaw;
    s32 ret;

    x1 = npc->pos.x;
    y1 = npc->pos.y;
    z1 = npc->pos.z;
    yaw = *outYaw;

    ret = npc_test_move_simple_with_slipping(npc->unk_80, &x1, &y1, &z1, npc->moveSpeed * arg1,
                                             yaw, npc->collisionHeight, npc->collisionRadius);
    if (ret != 0) {
        dist1 = dist2D(npc->pos.x, npc->pos.z, x1, z1);

        x2 = npc->pos.x;
        y2 = npc->pos.y;
        z2 = npc->pos.z;
        if (npc_test_move_simple_with_slipping(npc->unk_80, &x2, &y2, &z2, npc->moveSpeed * arg1,
                                               clamp_angle(yaw + 35.0f), npc->collisionHeight,
                                                           npc->collisionRadius) != 0) {
            dist2 = dist2D(npc->pos.x, npc->pos.z, x2, z2);
        }

        x3 = npc->pos.x;
        y3 = npc->pos.y;
        z3 = npc->pos.z;
        if (npc_test_move_simple_with_slipping(npc->unk_80, &x3, &y3, &z3, npc->moveSpeed * arg1,
                                               clamp_angle(yaw - 35.0f), npc->collisionHeight, npc->collisionRadius)
                                               != 0) {
            dist3 = dist2D(npc->pos.x, npc->pos.z, x3, z3);
        }

        if ((dist2 < dist1 && dist3 < dist2) || (dist3 < dist1 && dist2 < dist3)) {
            yaw = npc->yaw;
        } else if ((dist1 < dist2 && dist3 < dist1) || (dist3 < dist2 && dist1 < dist3)) {
            yaw = npc->yaw + 35.0f;
        } else if ((dist1 < dist3 && dist2 < dist1) || (dist2 < dist3 && dist1 < dist2)) {
            yaw = npc->yaw - 35.0f;
        }
    }

    if (outYaw != NULL) {
        *outYaw = clamp_angle(yaw);
    }
    if (outDist1 != NULL) {
        *outDist1 = dist1;
    }
    if (outDist2 != NULL) {
        *outDist2 = dist2;
    }
    if (outDist3 != NULL) {
        *outDist3 = dist3;
    }
    return ret;
}
