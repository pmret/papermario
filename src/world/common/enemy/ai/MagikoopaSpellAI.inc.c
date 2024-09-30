#include "common.h"
#include "effects.h"

s32 N(MagikoopaAI_CanShootSpell)(Evt* script, f32 arg1, f32 arg2, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];

    if (basic_ai_check_player_dist(territory, enemy, arg1, arg2, 0)) {
        f32 angle;
        f32 t1;

        if (clamp_angle(get_clamped_angle_diff(camera->curYaw, npc->yaw)) < 180.0) {
            angle = 90.0f;
        } else {
            angle = 270.0f;
        }

        t1 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        if (fabsf(get_clamped_angle_diff(angle, t1)) > 75.0) {
            return -1;
        }

        t1 = atan2(0.0f, npc->pos.y, fabsf(npc->pos.x - gPlayerStatusPtr->pos.x), gPlayerStatusPtr->pos.y);
        if (fabsf(t1 - 90.0) > 70.0) {
            return -1;
        }

        if (gPartnerStatus.actingPartner == PARTNER_BOW || gPartnerStatus.actingPartner == PARTNER_SUSHIE) {
            return -1;
        }

        if ((get_enemy(enemy->npcID + 1)->varTable[0] == 0)) {
            return 1;
        }
    }

    return -1;
}

API_CALLABLE(N(MagikoopaAI_SpellMain)) {
    Enemy* enemy = script->owner1.enemy;
    Npc sp20;
    Npc* sp20Ptr = &sp20;
    s32 timer = 0;
    Npc* npc1 = get_npc_unsafe(enemy->npcID);
    Npc* npc2 = get_npc_unsafe(get_enemy(enemy->npcID - 1)->npcID);
    f32 t1;
    f32 t2;

    if (isInitialCall || (enemy->aiFlags & AI_FLAG_SUSPEND)) {
        script->functionTemp[0] = 0;
        npc1->duration = 0;
        npc1->flags |= NPC_FLAG_200000 | NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION |  NPC_FLAG_INVISIBLE;
        enemy->flags |= ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_JUMP |
                        ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_PROJECTILE;
        npc1->scale.x = 0.4f;
        npc1->scale.y = 0.4f;
        if (enemy->aiFlags & AI_FLAG_SUSPEND) {
            enemy->aiFlags &= ~AI_FLAG_SUSPEND;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            enemy->varTable[3] = NULL;
            npc1->collisionDiameter = 20;
            npc1->collisionHeight = 20;
            npc1->pos.x = NPC_DISPOSE_POS_X;
            npc1->pos.y = NPC_DISPOSE_POS_Y;
            npc1->pos.z = NPC_DISPOSE_POS_Z;
            enemy->varTable[0] = 0;
            script->functionTemp[0] = 1;
            // fallthrough
        case 1:
            if (enemy->varTable[0] == 1) {
                s32 duration;

                enemy->varTable[0] = 2;
                sp20Ptr->pos.x = npc2->pos.x;
                sp20Ptr->pos.y = npc2->pos.y;
                sp20Ptr->pos.z = npc2->pos.z;
                npc_move_heading(sp20Ptr, enemy->varTable[2], 270.0f - npc2->renderYaw);
                npc1->pos.x = sp20Ptr->pos.x;
                npc1->pos.y = npc2->pos.y + enemy->varTable[1];
                npc1->pos.z = sp20Ptr->pos.z;
                enemy->hitboxIsActive = TRUE;
                enemy->unk_10.x = npc1->pos.x;
                enemy->unk_10.y = npc1->pos.y;
                enemy->unk_10.z = npc1->pos.z;
                npc1->moveSpeed = 3.6f;

                t1 = fabsf(npc1->pos.x - gPlayerStatusPtr->pos.x);
                t2 = atan2(0.0f, npc1->pos.y, t1, (gPlayerStatusPtr->pos.y + 10.0)) - 90.0;
                npc1->jumpVel = cosine(t2) * npc1->moveSpeed;
                npc1->yaw = atan2(npc1->pos.x, npc1->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
                duration = dist3D(npc1->pos.x, npc1->pos.y, npc1->pos.z,
                                  gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.y + 10.0,
                                  gPlayerStatusPtr->pos.z) / npc1->moveSpeed;
                if (duration <= 0) {
                    duration = 1;
                }
                enemy->varTable[3] = (s32)fx_shape_spell(0, npc1->pos.x, npc1->pos.y + 14.0f, npc1->pos.z,
                                                    gPlayerStatusPtr->pos.x,
                                                    gPlayerStatusPtr->pos.y + 10.0f + 14.0f,
                                                    gPlayerStatusPtr->pos.z, duration);
                npc1->duration = duration;
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            npc1->duration--;
            if (npc1->duration <= 0) {
                timer = 20;
            }
            if (timer == 0) {
                npc_move_heading(npc1, npc1->moveSpeed, npc1->yaw);
                npc1->pos.y += npc1->jumpVel;
                break;
            }
            // fallthrough
        case 3:
            npc1->jumpVel = 0.0f;
            npc1->moveSpeed = 0.0f;
            npc1->pos.y -= npc1->collisionHeight * 0.5;
            enemy->varTable[0] = 3;
            npc1->duration = 0;
            script->functionTemp[0] = 4;
            break;
        case 4:
            npc1->duration++;
            if (npc1->duration < 7) {
                npc1->pos.y -= 3.5;
                npc1->collisionDiameter = ((f32) npc1->duration * 7.0) + 20.0;
                npc1->collisionHeight = ((f32) npc1->duration * 7.0) + 20.0;
            } else if (npc1->duration == 7) {
                npc1->pos.x = NPC_DISPOSE_POS_X;
                npc1->pos.y = NPC_DISPOSE_POS_Y;
                npc1->pos.z = NPC_DISPOSE_POS_Z;
                npc1->collisionDiameter = 20;
                npc1->collisionHeight = 20;
            } else if (npc1->duration >= 16) {
                enemy->varTable[0] = 0;
                script->functionTemp[0] = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}
