#include "common.h"

void get_npc_pos(s32 npcID, f32* outX, f32* outY, f32* outZ, s32* outAirborne) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc;

    *outX = 0.0f;
    *outY = 0.0f;
    *outZ = 0.0f;
    *outAirborne = FALSE;

    if (npcID == NPC_SELF) {
        *outX = playerStatus->position.x;
        *outY = playerStatus->position.y;
        *outZ = playerStatus->position.z;
        if (playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING)) {
            *outAirborne = TRUE;
        }
    } else {
        npc = get_npc_unsafe(npcID);
        *outX = npc->pos.x;
        *outY = npc->pos.y;
        *outZ = npc->pos.z;
        if (npc->flags & NPC_FLAG_JUMPING) {
            *outAirborne = TRUE;
        }
    }

}

void func_8005DECC(Npc* npc, s32 arg1, s32* animIDs, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Unk2A4Blur* blur;
    s32 i;

    npc->blur.unk2A4 = blur = heap_malloc(sizeof(*blur));
    ASSERT(blur != NULL);

    for (i = 0; i < ARRAY_COUNT(blur->unk_00); i++) {
        blur->unk_00[i].pos.x = playerStatus->position.x;
        blur->unk_00[i].pos.y = playerStatus->position.y;
        blur->unk_00[i].pos.z = playerStatus->position.z;
        blur->unk_00[i].unk_00 = 0;
    }
    blur->partIdx = 0;
    blur->unk_284 = 0;
    blur->unk_288 = 0;
    blur->npcID = arg1;
    blur->animIDs = animIDs;
    blur->unk_294 = arg3;
    blur->unk_298 = arg4;
    blur->unk_29C = arg5;
    blur->unk_2A0 = arg6;
    npc->currentAnim = blur->animIDs[4];
    npc->jumpVelocity = 0.0f;
    npc->flags |= NPC_FLAG_GRAVITY;
    npc->flags &= ~NPC_FLAG_100;
    npc->collisionChannel = 0x10000;
}

void func_8005DFD4(Npc* npc) {
    Unk2A4Blur* blur = npc->blur.unk2A4;
    f32 x, y, z;
    s32 airborne;
    s32 isAirborne;
    Unk2A4Part* part;

    get_npc_pos(blur->npcID, &x, &y, &z, &airborne);
    part = &blur->unk_00[blur->partIdx];
    isAirborne = airborne != FALSE;

    if (part->unk_00 != 0 && isAirborne) {
        return;
    }

    if (!isAirborne && dist2D(npc->pos.x, npc->pos.z, x, z) <= blur->unk_29C && part->unk_00 == 0) {
        return;
    }

    part = &blur->unk_00[blur->partIdx];
    if (part->pos.x != x || part->pos.y != y || part->pos.z != z) {
        if (blur->unk_284 != blur->partIdx + 1) {
            blur->partIdx++;
            if (blur->partIdx >= ARRAY_COUNT(blur->unk_00)) {
                blur->partIdx = 0;
            }
            part = &blur->unk_00[blur->partIdx];
            part->pos.x = x;
            part->pos.y = y;
            part->pos.z = z;
            part->unk_00 = isAirborne;
        }
    }
}

// float regalloc
#ifdef NON_MATCHING
void func_8005E12C(Npc* npc) {
    Unk2A4Blur* blur = npc->blur.unk2A4;
    f32 x, y, z;
    s32 airborne;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 dist;
    Unk2A4Part* part;
    f32 npcX, npcZ;
    f32 partX, partY, partZ;
    f32 theta;
    f32 yaw;

    get_npc_pos(blur->npcID, &x, &y, &z, &airborne);

    switch (blur->unk_288) {
        case 0:
            part = &blur->unk_00[blur->unk_284];
            partX = part->pos.x;
            partZ = part->pos.z;
            npcX = npc->pos.x;
            npcZ = npc->pos.z;
            sp28 = npcX;
            sp2C = npc->pos.y;
            sp30 = npcZ;
            npc->moveSpeed = blur->unk_294;
            dist = dist2D(npc->pos.x, npc->pos.z, x, z);
            if (blur->unk_2A0 <= dist) {
                npc->moveSpeed = blur->unk_298;
            }
            npc->currentAnim = blur->animIDs[5];
            if (!(npc->flags & NPC_FLAG_1000)) {
                npc->currentAnim = blur->animIDs[2];
            }

            while (TRUE) {
                dist = dist2D(sp28, sp30, partX, partZ);
                yaw = atan2(sp28, sp30, partX, partZ);
                if (npc->moveSpeed < dist) {
                    dist = dist2D(sp28, sp30, x, z);
                    if (blur->unk_2A0 < dist) {
                        break;
                    }

                    if (blur->unk_29C < dist) {
                        npc->moveSpeed = dist - blur->unk_29C;
                        if (npc->moveSpeed > blur->unk_294) {
                            npc->moveSpeed = blur->unk_294;
                        } else {
                            npc->moveSpeed += 1.0;
                        }
                        break;
                    }
                }

                if (blur->unk_284 == blur->partIdx) {
                    npc->moveSpeed = 0.0f;
                    yaw = npc->yaw;
                    npc->currentAnim = blur->animIDs[4];
                } else {
                    dist = dist2D(npc->pos.x, npc->pos.z, x, z);
                    if (dist <= blur->unk_29C) {
                        npc->moveSpeed = 0.0f;
                        yaw = npc->yaw;
                        npc->currentAnim = blur->animIDs[4];
                        blur->unk_288 = 0xA;
                    } else {
                        blur->unk_284++;
                        if (blur->unk_284 >= ARRAY_COUNT(blur->unk_00)) {
                            blur->unk_284 = 0;
                        }
                        part = &blur->unk_00[blur->unk_284];
                        partX = part->pos.x;
                        partZ = part->pos.z;
                        if (npc->flags & NPC_FLAG_1000) {
                            if (part->unk_00 != 0) {
                                blur->unk_288 = 1;
                                break;
                            }
                        }
                        continue;
                    }
                }
                break;
            }

            if (!(npc->flags & NPC_FLAG_1000)) {
                npc->moveSpeed *= 0.5f;
            }
            npc->yaw = yaw;
            npc_move_heading(npc, npc->moveSpeed, yaw);
            if ((npc->flags & (NPC_FLAG_4000 | NPC_FLAG_1000)) == (NPC_FLAG_4000 | NPC_FLAG_1000)) {
                blur->unk_288 = 1;
            }
            break;
        case 1:
            if (blur->unk_284 != blur->partIdx) {
                blur->unk_284++;
                if (blur->unk_284 >= ARRAY_COUNT(blur->unk_00)) {
                    blur->unk_284 = 0;
                }
                part = &blur->unk_00[blur->unk_284];
                partX = part->pos.x;
                partY = part->pos.y;
                partZ = part->pos.z;
                npc->moveToPos.x = partX;
                npc->moveToPos.y = partY;
                npc->moveToPos.z = partZ;
                npc->duration = 0;
                npc->jumpScale = 2.0f;
                npc->moveSpeed = blur->unk_298;
                npc->planarFlyDist = dist2D(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
                npc->yaw = atan2(npc->pos.x, npc->pos.z, npc->moveToPos.x, npc->moveToPos.z);
                dist = npc->planarFlyDist;
                sp2C = partY - npc->pos.y;
                if (dist < sp2C) {
                    dist = sp2C;
                }
                if (dist < blur->unk_29C) {
                    npc->jumpVelocity = 0.0f;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
                    blur->unk_288 = 0;
                    return;
                }
                npc->duration = dist / npc->moveSpeed;
                if (npc->duration < 10) {
                    npc->duration = 10;
                }
                npc->moveSpeed = npc->planarFlyDist / npc->duration;
                npc->jumpVelocity = (sp2C + (npc->jumpScale * npc->duration * npc->duration * 0.5f)) / npc->duration;
                npc->currentAnim = blur->animIDs[1];
                npc->flags &= ~NPC_FLAG_GRAVITY;
                blur->unk_288 = 2;
            }
            break;
        case 2:
            npc->jumpVelocity -= npc->jumpScale;
            npc->pos.y += npc->jumpVelocity;
            if (npc->jumpVelocity <= 0.0f) {
                npc->currentAnim = blur->animIDs[2];
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->jumpVelocity <= 0.0f) {
                sp28 = npc->pos.x;
                sp30 = npc->pos.z;
                dist = fabsf(npc->jumpVelocity) + 8.0;
                sp2C = npc->pos.y + dist;
                if ((npc_raycast_down_sides(npc->collisionChannel, &sp28, &sp2C, &sp30, &dist) != 0) &&
                    (dist <= (fabsf(npc->jumpVelocity) + 8.0)))
                {
                    npc->currentAnim = blur->animIDs[3];
                    npc->jumpVelocity = 0.0f;
                    npc->pos.y = sp2C;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    npc->yaw = atan2(sp28, sp30, x, z);
                    blur->unk_288 = 0;
                }
            }
            break;
        case 10:
            npcX = npc->pos.x;
            npcZ = npc->pos.z;
            part = &blur->unk_00[blur->unk_284];
            partX = part->pos.x;
            partZ = part->pos.z;
            sp28 = npcX;
            sp2C = npc->pos.y;
            sp30 = npcZ;
            dist = dist2D(npcX, npcZ, x, z);
            if (dist <= blur->unk_29C) {
                break;
            }

            while (TRUE) {
                if (part->unk_00 != 0) {
                    break;
                }

                theta = atan2(npc->pos.x, npc->pos.z, partX, partZ);
                if (fabsf(get_clamped_angle_diff(theta, atan2(npc->pos.x, npc->pos.z, x, z))) < 90.0f) {
                    break;
                }

                if (blur->unk_284 == blur->partIdx) {
                    break;
                }

                blur->unk_284++;
                if (blur->unk_284 >= ARRAY_COUNT(blur->unk_00)) {
                    blur->unk_284 = 0;
                }
                part = &blur->unk_00[blur->unk_284];
                partX = part->pos.x;
                partZ = part->pos.z;
                continue;
            }

            if (part->unk_00 == 0) {
                blur->unk_288 = 0;
                return;
            }

            while (TRUE) {
                if (part->unk_00 == 0) {
                    break;
                }

                theta = atan2(npc->pos.x, npc->pos.z, partX, partZ);
                if (fabsf(get_clamped_angle_diff(theta, atan2(npc->pos.x, npc->pos.z, x, z))) < 90.0f) {
                    break;
                }

                if (blur->unk_284 == blur->partIdx) {
                    break;
                }

                blur->unk_284++;
                if (blur->unk_284 >= ARRAY_COUNT(blur->unk_00)) {
                    blur->unk_284 = 0;
                }
                part = &blur->unk_00[blur->unk_284];
                partX = part->pos.x;
                partZ = part->pos.z;
            }
            blur->unk_288 = 1;
            break;
    }
}
#else
INCLUDE_ASM(s32, "39210_len_aa0", func_8005E12C);
#endif
