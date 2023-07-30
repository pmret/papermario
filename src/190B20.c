#include "common.h"
#include "nu/nusys.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "model.h"
#include "sprite.h"

EvtScript D_80293820 = {
    EVT_WAIT(LVar0)
    EVT_LOOP(4)
        EVT_CALL(SetBattleCamParam, 4, 11)
        EVT_WAIT(1)
        EVT_CALL(SetBattleCamParam, 4, 5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetBattleCamParam, 4, 8)
    EVT_RETURN
    EVT_END
};

f32 D_802938A4 = 0.0f;

s16 D_802938A8 = 4;

EffectInstance* gDamageCountEffects[] = {
    NULL, NULL, NULL, NULL, 
    NULL, NULL, NULL, NULL, 
    NULL, NULL, NULL, NULL, 
    NULL, NULL, NULL, NULL, 
    NULL, NULL, NULL, NULL, 
    NULL, NULL, NULL, NULL,
};

s32 gDamageCountTimers[] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
};

Gfx D_80293970[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

s32 D_802939C0 = 0;

// from 17D6A0
extern s32 bMarioDefenseTable[];
extern s32 bPlayerStatusTable[];
extern ActorBlueprint bPlayerActorBlueprint;
extern ActorPartBlueprint bMarioParts[];

extern PartnerDMAData bPartnerDmaTable[];

s32 get_npc_anim_for_status(AnimID*, s32);

void create_target_list(Actor* actor, s32 arg1) {
    s32 numTargets = 0;
    BattleStatus* battleStatus = &gBattleStatus;
    SelectableTarget* targetDataList = actor->targetData;
    Actor* playerActor = battleStatus->playerActor;
    Actor* partnerActor = battleStatus->partnerActor;
    SelectableTarget* targetData;
    SelectableTarget* otherTarget;
    Actor* targetActor;
    ActorPart* targetPart;
    s8* targetIndexList;
    s32 numParts;
    s32 i, j;
    f32 targetX, targetY, targetZ;
    f32 f2, f12, f14;
    u8 overlayType;
    f32 overlayZoom;
    s32 sp18 = FALSE;
    s32 col;
    s32 row;
    s32 skip;

    if (battleStatus->curTargetListFlags & TARGET_FLAG_80000000) {
        actor->targetListLength = -1;
        return;
    }

    if (battleStatus->curTargetListFlags & TARGET_FLAG_PLAYER) {
        targetDataList->actorID = ACTOR_PLAYER;
        targetDataList->partID = 1;
        if (!arg1) {
            targetDataList->posA.x = playerActor->curPos.x + playerActor->size.x * 0.3 * playerActor->scalingFactor;
            targetDataList->posA.y = playerActor->curPos.y + playerActor->size.y * 0.9 * playerActor->scalingFactor;
            targetDataList->posA.z = playerActor->curPos.z;
        } else {
            targetDataList->posA.x = playerActor->homePos.x + playerActor->size.x * 0.3 * playerActor->scalingFactor;
            targetDataList->posA.y = playerActor->homePos.y + playerActor->size.y * 0.9 * playerActor->scalingFactor;
            targetDataList->posA.z = playerActor->homePos.z;
        }
        targetDataList->unk_10 = -100;
        numTargets++;
        targetDataList++;
    }

    if ((battleStatus->curTargetListFlags & TARGET_FLAG_100) && partnerActor != NULL) {
        targetDataList->actorID = ACTOR_PARTNER;
        targetDataList->partID = 1;
        if (!arg1) {
            targetDataList->posA.x = partnerActor->curPos.x + partnerActor->size.x * 0.1 * partnerActor->scalingFactor;
            targetDataList->posA.y = partnerActor->curPos.y + partnerActor->size.y * 0.8 * partnerActor->scalingFactor;
            targetDataList->posA.z = partnerActor->curPos.z;
        } else {
            targetDataList->posA.x = partnerActor->homePos.x + partnerActor->size.x * 0.1 * partnerActor->scalingFactor;
            targetDataList->posA.y = partnerActor->homePos.y + partnerActor->size.y * 0.8 * partnerActor->scalingFactor;
            targetDataList->posA.z = partnerActor->homePos.z;
        }
        targetDataList->unk_10 = -50;
        numTargets++;
        targetDataList++;
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        targetActor = battleStatus->enemyActors[i];
        if (targetActor == NULL) {
            continue;
        }
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_100) || (battleStatus->curTargetListFlags & TARGET_FLAG_PLAYER)) {
            break;
        }
        targetPart = targetActor->partsTable;
        numParts = targetActor->numParts;
        for (j = 0; j < numParts; targetPart = targetPart->nextPart, j++) {
            if (!(targetPart->flags & ACTOR_PART_FLAG_NO_TARGET)) {
                ActorPartBlueprint* partBlueprint = targetPart->staticData;
                s8 partIndex;
                if (!(targetPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                    row = !arg1; // required to match
                    if (row) {
                        targetX = targetActor->curPos.x;
                        targetY = targetActor->curPos.y;
                        targetZ = targetActor->curPos.z;
                    } else {
                        targetX = targetActor->homePos.x;
                        targetY = targetActor->homePos.y;
                        targetZ = targetActor->homePos.z;
                    }
                    targetX += targetPart->partOffset.x * targetActor->scalingFactor;
                    if (!(targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                        targetY += targetPart->partOffset.y * targetActor->scalingFactor;
                    }
                    targetZ += targetPart->partOffset.z * targetActor->scalingFactor;
                    f12 = targetX;
                    targetX = targetActor->scalingFactor;
                    targetX = f12 + targetPart->targetOffset.x * targetX;
                    f2 = targetY;
                    f14 = targetZ + 5.0f;
                    if (!(targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                        targetY = f2 + targetPart->targetOffset.y * targetActor->scalingFactor;
                    }
                } else {
                    targetY = targetPart->absolutePos.y;
                    targetZ = targetPart->absolutePos.z;
                    f12 = targetPart->absolutePos.x;
                    f2 = targetY;
                    f14 = targetZ + 5.0f;
                    targetX = f12 + targetPart->targetOffset.x;
                    if (!(targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                        targetY = f2 + targetPart->targetOffset.y;
                    }
                }

                targetDataList->actorID = ACTOR_CLASS_ENEMY | i;
                partIndex = partBlueprint->index;
                targetDataList->posA.x = targetX;
                targetDataList->posA.y = targetY;
                targetDataList->posA.z = targetZ;
                targetDataList->unk_10 = 0;
                targetDataList->partID = partIndex;

                if ((targetActor->flags & ACTOR_FLAG_TARGET_ONLY) && !(targetActor->flags & ACTOR_FLAG_10)) {
                    targetDataList->unk_10 = 100;
                }
                targetDataList->unk_10 += targetPart->unk_70;
                targetDataList->posB.x = f12 + targetDataList->unk_10 * 100;
                targetDataList->posB.y = f2;
                targetDataList->posB.z = f14;

                if (targetDataList->posB.y < 40) {
                    targetDataList->homeRow = 0;
                } else if (targetDataList->posB.y < 85) {
                    targetDataList->homeRow = 1;
                } else if (targetDataList->posB.y < 100) {
                    targetDataList->homeRow = 2;
                } else {
                    do {
                        do {
                            targetDataList->homeRow = 3;
                        } while (0);
                    } while (0);
                }

                if (targetDataList->posB.x < 25) {
                    targetDataList->homeCol = 0;
                } else if (targetDataList->posB.x < 65) {
                    targetDataList->homeCol = 1;
                } else if (targetDataList->posB.x < 105) {
                    targetDataList->homeCol = 2;
                } else {
                    do {
                        targetDataList->homeCol = 3;
                    } while (0);
                }

                if (targetDataList->posB.z < -30) {
                    targetDataList->layer = 0;
                } else {
                    targetDataList->layer = 1;
                }
                numTargets++;
                targetDataList++;
            }
        }
    }
    do {
        actor->selectedTargetIndex = 0;
    } while (0);
    actor->targetListLength = numTargets;

    // @bug this should be % 4
    col = battleStatus->targetHomeIndex & 4;
    row = battleStatus->targetHomeIndex / 4;

    targetDataList = actor->targetData;
    numTargets = actor->targetListLength;

    for (i = 0; i < numTargets; i++) {
        targetData = &targetDataList[i];
        targetActor = get_actor(targetData->actorID);
        targetPart = get_actor_part(targetActor, targetData->partID);
        if (targetData->actorID == ACTOR_PLAYER || targetData->actorID == ACTOR_PARTNER) {
            continue;
        }
        if (battleStatus->curTargetListFlags & TARGET_FLAG_80000000) {
            skip = TRUE;
            goto END2;
        }
        if (!(gBattleStatus.flags2 & BS_FLAGS2_4000) && battleStatus->darknessMode > 0) {
            get_screen_overlay_params(SCREEN_LAYER_BACK, &overlayType, &overlayZoom);
            if (overlayZoom >= 215.0f) {
                skip = TRUE;
                sp18 = 1;
                goto END2;
            }
        }
        if (battleStatus->curTargetListFlags & TARGET_FLAG_8000) {
            if (!(targetPart->flags & ACTOR_PART_FLAG_MULTI_TARGET) ||
                 (targetActor->flags & ACTOR_FLAG_40) ||
                 (targetPart->flags & ACTOR_PART_FLAG_40))
            {
                skip = TRUE;
                goto END2;
            }
        }
        skip = 0;
END2:
        if (skip) {
            for (j = i; j < numTargets - 1; j++) {
                actor->targetData[j] = actor->targetData[j + 1];
            }
            numTargets--;
            i--;
        }
    }

    for (i = 0; i < numTargets; i++) {
        targetData = &targetDataList[i];
        targetActor = get_actor(targetData->actorID);
        targetPart = get_actor_part(targetActor, targetData->partID);
        if (targetData->actorID == ACTOR_PLAYER || targetData->actorID == ACTOR_PARTNER) {
            continue;
        }
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_800) && (targetPart->targetFlags & ACTOR_PART_TARGET_FLAG_1)) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_1000) && (targetPart->targetFlags & ACTOR_PART_TARGET_FLAG_2)) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_20000) && ((targetActor->flags & ACTOR_FLAG_80) || (targetPart->flags & ACTOR_PART_FLAG_80))) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_400) && (targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
            skip = TRUE;
            goto END;
        }
        if (!(battleStatus->curTargetListFlags & TARGET_FLAG_10000) && (targetActor->flags & ACTOR_FLAG_TARGET_ONLY)) {
            skip = TRUE;
            goto END;
        }
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_40000) && (targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
            skip = TRUE;
            goto END;
        }
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_4) && targetData->homeRow != 0) {
            skip = TRUE;
            goto END;
        }
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_10) && targetData->homeRow >= 2) {
            skip = TRUE;
            goto END;
        }
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_40) && targetData->homeRow <= 0) {
            skip = TRUE;
            goto END;
        }
        if ((battleStatus->curTargetListFlags & TARGET_FLAG_4000) && !(targetPart->flags & ACTOR_PART_FLAG_20)) {
            s32 cond = FALSE;
            do {
                for (j = 0; j < numTargets; j++) {
                    otherTarget = &targetDataList[j];
                    if (targetData != otherTarget) {
                        if (targetData->layer == otherTarget->layer &&
                            targetData->homeCol == otherTarget->homeCol &&
                            targetData->homeRow < otherTarget->homeRow) {
                            cond = TRUE;
                            break;
                        }
                    }
                }
            } while (0);
            if (cond) {
                skip = TRUE;
                goto END;
            }
        }
        if (battleStatus->curTargetListFlags & TARGET_FLAG_2000) {
            s32 cond = FALSE;

            for (j = 0; j < numTargets; j++) {
                otherTarget = &targetDataList[j];
                if (targetData != otherTarget) {
                    if (targetData->layer == otherTarget->layer &&
                        targetData->homeRow == otherTarget->homeRow &&
                        targetData->homeCol > otherTarget->homeCol) {
                        cond = TRUE;
                        break;
                    }
                }
            }

            if (cond) {
                skip = TRUE;
                goto END;
            }
        }
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_20) && (targetActor->flags & ACTOR_FLAG_FLYING)) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_100000) && targetData->homeRow == row + 1) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_200000) && targetData->homeRow == row - 1) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_400000) && targetData->homeCol == col - 1) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_800000) && targetData->homeCol == col + 1) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_100000) && targetData->homeRow < row) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_200000) && targetData->homeRow > row) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_400000) && targetData->homeCol > col) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        do {
            if ((battleStatus->curTargetListFlags & TARGET_FLAG_800000) && targetData->homeCol < col) {
                skip = TRUE;
                goto END;
            }
        } while (0);
        skip = FALSE;
END:
        if (skip) {
            for (j = i; j < numTargets - 1; j++) {
                actor->targetData[j] = actor->targetData[j + 1];
            }
            numTargets--;
            i--;
        }
    }

    actor->targetListLength = numTargets;
    if (numTargets == 0 && sp18) {
        gBattleStatus.flags2 |= BS_FLAGS2_NO_TARGET_AVAILABLE;
    } else {
        gBattleStatus.flags2 &= ~BS_FLAGS2_NO_TARGET_AVAILABLE;
    }

    targetDataList = actor->targetData;

    numTargets = actor->targetListLength;
    targetIndexList = actor->targetIndexList;
    for (i = 0; i < numTargets; i++) {
        targetIndexList[i] = i;
    }
    for (i = 0; i < numTargets - 1; i++) {
        for (j = i + 1; j < numTargets; j++) {
            s32 index1 = targetIndexList[i];
            s32 index2 = targetIndexList[j];
            targetData = &targetDataList[index1];
            otherTarget = &targetDataList[index2];
            if (targetData->posA.x + targetData->unk_10 * 10 > otherTarget->posA.x + otherTarget->unk_10 * 10) {
                targetIndexList[i] = targetIndexList[j];
                targetIndexList[j] = index1;
            }
        }
    }
}

void set_actor_pal_adjustment(Actor* actor, s32 palAdjust);

void player_create_target_list(Actor* actor) {
    create_target_list(actor, 0);
}

void enemy_create_target_list(Actor* actor) {
    create_target_list(actor, 1);
}

s32 func_80263064(Actor* actor0, Actor* actor1, s32 unused) {
    s32 ret = 0;
    SelectableTarget* target = actor0->targetData;
    s32 numParts;
    ActorPart* part;
    s32 i;

    if (actor1 == NULL) {
        return ret;
    }

    numParts = actor1->numParts;
    part = actor1->partsTable;

    for (i = 0; i < numParts; i++) {
        if (!(part->flags & ACTOR_PART_FLAG_NO_TARGET)) {
            if (!(part->flags & ACTOR_PART_FLAG_MULTI_TARGET)) {
                continue;
            } else {
                ActorPartBlueprint* bp = part->staticData;
                f32 x, y, z;

                if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                    x = actor1->curPos.x;
                    y = actor1->curPos.y;
                    z = actor1->curPos.z;

                    x += part->partOffset.x;
                    if (!(actor1->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                        y += part->partOffset.y;
                    } else {
                        y -= part->partOffset.y;
                    }
                    z += part->partOffset.z;

                    x += part->targetOffset.x;
                    if (!(actor1->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                        y += part->targetOffset.y;
                    } else {
                        y -= part->targetOffset.y;
                    }
                } else {
                    x = part->absolutePos.x;
                    y = part->absolutePos.y;
                    z = part->absolutePos.z;

                    x += part->targetOffset.x;
                    if (!(actor1->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                        y += part->targetOffset.y;
                    } else {
                        y -= part->targetOffset.y;
                    }
                }

                actor0->targetActorID = target->actorID = actor1->actorID;
                actor0->targetPartIndex = target->partID = bp->index;
                target->posA.x = x;
                target->posA.y = y;
                target->posA.z = z;
                target->unk_10 = 0;
                target++;
                ret++;
            }
        }
        part = part->nextPart;
    }
    actor0->targetListLength = ret;
    return ret;
}

s32 func_80263230(Actor* arg0, Actor* arg1) {
    return func_80263064(arg0, arg1, 0);
}

void func_8026324C(Actor* arg0, Actor* arg1) {
    func_80263064(arg0, arg1, 1);
}

void func_80263268(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* partner = battleStatus->partnerActor;

    battleStatus->changePartnerAllowed = 0;
    if (partner != NULL) {
        s32 partnersEnabled;
        s32 i;

        battleStatus->changePartnerAllowed = 1;
        partnersEnabled = 0;

        for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
            if (playerData->partners[i].enabled) {
                partnersEnabled++;
            }
        }

        if (partnersEnabled >= 2) {
            if (partner->koStatus == STATUS_KEY_DAZE) {
                battleStatus->changePartnerAllowed = 0;
            } else if (partner->debuff == STATUS_KEY_FROZEN) {
                battleStatus->changePartnerAllowed = 0;
            } else if (playerData->curPartner == PARTNER_GOOMPA) {
                battleStatus->changePartnerAllowed = -1;
            }
        } else {
            battleStatus->changePartnerAllowed = -1;
        }
    } else {
        battleStatus->changePartnerAllowed = -1;
    }
}

void func_80263300(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    PlayerData* playerData = &gPlayerData;
    s32 cond;
    s32 i;

    battleStatus->menuStatus[0] = 0;
    cond = FALSE;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        s16 itemID = playerData->invItems[i];

        if (itemID != 0) {
            ItemData* itemData = &gItemTable[itemID];

            if (itemData->typeFlags & ITEM_TYPE_FLAG_BATTLE_USABLE) {
                battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                battleStatus->moveArgument = playerData->invItems[i];
                battleStatus->curTargetListFlags = itemData->targetFlags;
                player_create_target_list(player);

                if (player->targetListLength != 0) {
                    battleStatus->menuStatus[0]++;
                    cond = TRUE;
                }
            }
        }
    }

    if (!cond) {
        battleStatus->menuStatus[0] = 0;
    }
}

s32 btl_are_all_enemies_defeated(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* enemy;
    s32 enemiesStillAlive = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        enemy = battleStatus->enemyActors[i];
        if (enemy != NULL) {
            if(!(enemy->flags & (ACTOR_FLAG_NO_DMG_APPLY | ACTOR_FLAG_TARGET_ONLY))) {
                enemiesStillAlive = TRUE;
            }
        }
    }
    return !enemiesStillAlive;
}

s32 btl_check_enemies_defeated(void) {
    if (btl_are_all_enemies_defeated()) {
        btl_set_state(BATTLE_STATE_VICTORY);
        return TRUE;
    }
    return FALSE;
}

s32 btl_check_player_defeated(void) {
    if (gPlayerData.curHP > 0) {
        return FALSE;
    }
    gDefeatedBattleState = gBattleState;
    gDefeatedBattleSubstate = gBattleSubState;
    btl_set_state(BATTLE_STATE_DEFEAT);
    return TRUE;
}

void btl_init_menu_boots(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    MoveData* move;
    s32 i;
    s32 moveCount;
    s32 hasAnyBadgeMoves;
    s32 fpCost;

    // If you don't have boots equipped, disable this menu
    if (playerData->bootsLevel == -1) {
        battleStatus->menuStatus[1] = 0;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
        battleStatus->submenuMoves[i] = MOVE_NONE;
    }

    // Standard jump move
    moveCount = 1;
    battleStatus->submenuMoves[0] = playerData->bootsLevel + MOVE_JUMP1;
    battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;

    // Jump badges
    do {
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            s16 badge = playerData->equippedBadges[i];

            if (badge != ITEM_NONE) {
                MoveData* moveTable = gMoveTable;
                u8 moveID = gItemTable[badge].moveID;

                move = &moveTable[moveID];
                if (move->category == MOVE_TYPE_JUMP) {
                    battleStatus->submenuMoves[moveCount] = moveID;
                    battleStatus->submenuIcons[moveCount] = playerData->equippedBadges[i];
                    moveCount++;
                }
            }
        }
    } while (0);

    battleStatus->submenuMoveCount = moveCount;

    hasAnyBadgeMoves = FALSE;
    for (i = 0; i < battleStatus->submenuMoveCount; i++) {
        move = &gMoveTable[battleStatus->submenuMoves[i]];

        // Calculate FP cost
        fpCost = move->costFP;
        if (fpCost != 0) {
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_SAVER);
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_FANATIC) * 2;
            if (fpCost < 1) {
                fpCost = 1;
            }
        }

        // See if there are any targets for this move
        battleStatus->moveCategory = BTL_MENU_TYPE_JUMP;
        battleStatus->moveArgument = playerData->bootsLevel;
        battleStatus->curTargetListFlags = move->flags; // Controls target filters
        player_create_target_list(player);

        // If there are targets, enable the move
        if (player->targetListLength != 0) {
            hasAnyBadgeMoves = TRUE;
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_ENABLED;
        }

        // If you don't have enough FP, disable the move
        if (playerData->curFP < fpCost) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NOT_ENOUGH_FP;
        }

        // If there are no targets available, disable the move
        if (player->targetListLength == 0) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS_2;
        }
        if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
            battleStatus->submenuStatus[moveCount] = BATTLE_SUBMENU_STATUS_NO_TARGETS;
        }
    }

    if (!hasAnyBadgeMoves) {
        // Only the standard jump is available - no badge moves.
        // Selecting this submenu should immediately pick the standard jump move
        battleStatus->menuStatus[1] = -1;
    } else {
        // Enable this submenu
        battleStatus->menuStatus[1] = 1;
    }
}

void btl_init_menu_hammer(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    MoveData* move;
    s32 i;
    s32 moveCount;
    s32 hasAnyBadgeMoves;
    s32 fpCost;

    // If you don't have a hammer, disable this menu
    if (playerData->hammerLevel == -1) {
        battleStatus->menuStatus[2] = 0;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
        battleStatus->submenuMoves[i] = 0;
    }

    // Standard hammer move
    moveCount = 1;
    battleStatus->submenuMoves[0] = playerData->hammerLevel + MOVE_HAMMER1;
    battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;

    // Hammer badges
    do {
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            s16 badge = playerData->equippedBadges[i];
            if (badge != MOVE_NONE) {
                MoveData* moveTable = gMoveTable;
                u8 moveID = gItemTable[badge].moveID;
                move = &moveTable[moveID];
                if (move->category == MOVE_TYPE_HAMMER) {
                    battleStatus->submenuMoves[moveCount] = moveID;
                    battleStatus->submenuIcons[moveCount] = playerData->equippedBadges[i];
                    moveCount++;
                }
            }
        }
    } while (0);

    battleStatus->submenuMoveCount = moveCount;

    hasAnyBadgeMoves = FALSE;
    for (i = 0; i < battleStatus->submenuMoveCount; i++) {
        move = &gMoveTable[battleStatus->submenuMoves[i]];

        // Calculate FP cost
        fpCost = move->costFP;
        if (fpCost != 0) {
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_SAVER);
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_FANATIC) * 2;
            if (fpCost < 1) {
                fpCost = 1;
            }
        }

        // See if there are any targets for this move
        battleStatus->moveCategory = BTL_MENU_TYPE_SMASH;
        battleStatus->moveArgument = playerData->hammerLevel;
        battleStatus->curTargetListFlags = move->flags;
        player_create_target_list(player);

        // If there are targets, enable the move
        if (player->targetListLength != 0) {
            hasAnyBadgeMoves = TRUE;
            battleStatus->submenuStatus[i] = 1;
        }

        // If you don't have enough FP, disable the move
        if (playerData->curFP < fpCost) {
            battleStatus->submenuStatus[i] = 0;
        }

        // If there are no targets available, disable the move
        if (player->targetListLength == 0) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS_2;
        }
        if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
            battleStatus->submenuStatus[moveCount] = BATTLE_SUBMENU_STATUS_NO_TARGETS;
        }
    }

    if (!hasAnyBadgeMoves) {
        // Only the standard hammer is available - no badge moves.
        // Selecting this submenu should immediately pick the standard hammer move
        battleStatus->menuStatus[2] = -1;
    } else {
        // Enable this submenu
        battleStatus->menuStatus[2] = 1;
    }
}

void btl_init_menu_partner(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 fpCost;
    s32 i;
    s32 hasAnyBadgeMoves;

    for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
        battleStatus->submenuMoves[i] = 0;
    }

    // In the move table (enum MoveIDs), partners get move IDs set up like this:
    //
    //  Move ID offset | Description          | Goombario example
    // ----------------+----------------------+-------------------
    //  0              | No rank only         | Headbonk
    //  1              | Super rank only      | Headbonk (2)
    //  2              | Ultra rank only      | Headbonk (3)
    //  3              | Always unlocked      | Tattle
    //  4              | Unlocked after super | Charge
    //  5              | Unlocked after ultra | Multibonk

    battleStatus->submenuMoveCount = partner->actorBlueprint->level + 2;

    // Offsets 0,1,2
    battleStatus->submenuMoves[0] =
        playerData->curPartner * 6
        + (MOVE_HEADBONK1 - 6)
        + partner->actorBlueprint->level;

    // Offsets 3,4,5
    for (i = 1; i < battleStatus->submenuMoveCount; i++) {
        battleStatus->submenuMoves[i] =
            playerData->curPartner * 6
            + (MOVE_TATTLE - 6)
            + (i - 1);
    }

    hasAnyBadgeMoves = FALSE;
    for (i = 0; i < battleStatus->submenuMoveCount; i++){
        MoveData* move = &gMoveTable[battleStatus->submenuMoves[i]];

        fpCost = move->costFP;
        if (fpCost != 0) {
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_SAVER);
            fpCost -= player_team_is_ability_active(player, ABILITY_FLOWER_FANATIC) * 2;
            if (fpCost < 1) {
                fpCost = 1;
            }
        }

        battleStatus->moveCategory = BTL_MENU_TYPE_CHANGE_PARTNER;
        battleStatus->moveArgument = partner->actorBlueprint->level;
        battleStatus->curTargetListFlags = move->flags;
        player_create_target_list(partner);

        if (partner->targetListLength != 0){
            hasAnyBadgeMoves = TRUE;
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_ENABLED;
        }

        if (partner->targetListLength == 0) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS_2;
        }

        if (playerData->curFP < fpCost) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NOT_ENOUGH_FP;
        }
        if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
            battleStatus->submenuStatus[i] = BATTLE_SUBMENU_STATUS_NO_TARGETS;
        }
    }

    if (!hasAnyBadgeMoves) {
        battleStatus->menuStatus[3] = -1;
    } else {
        battleStatus->menuStatus[3] = 1;
    }
}

s32 count_power_plus(s32 damageType) {
    s32 count;
    s32 i;

    if (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_IS_PEACH) {
        return 0;
    }

    count = 0;
    for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
        u8 moveID = gItemTable[gPlayerData.equippedBadges[i]].moveID;

        if (gMoveTable[moveID].category == MOVE_TYPE_ATTACK_UP && moveID == MOVE_POWER_PLUS) {
            if (gBattleStatus.flags1 & BS_FLAGS1_10 || damageType & DAMAGE_TYPE_JUMP) {
                count++;
            }
        }
    }

    return count;
}

void deduct_current_move_fp(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* actor = battleStatus->playerActor;
    s32 fpCost = gMoveTable[battleStatus->selectedMoveID].costFP;

    if (fpCost != 0) {
        fpCost -= player_team_is_ability_active(actor, ABILITY_FLOWER_SAVER);
        fpCost -= player_team_is_ability_active(actor, ABILITY_FLOWER_FANATIC) * 2;
        if (fpCost < 1) {
            fpCost = 1;
        }
    }

    playerData->curFP -= fpCost;
}

void reset_actor_turn_info(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        actor = battleStatus->enemyActors[i];
        if (actor != NULL) {
            actor->hpChangeCounter = 0;
            actor->damageCounter = 0;
            actor->actionRatingCombo = 0;
        }

    }
    actor = battleStatus->playerActor;
    actor->hpChangeCounter = 0;
    actor->damageCounter = 0;
    actor->actionRatingCombo = 0;

    actor = battleStatus->partnerActor;
    if (actor != NULL) {
        actor->hpChangeCounter = 0;
        actor->damageCounter = 0;
        actor->actionRatingCombo = 0;
    }
}

void func_80263CC4(s32 arg0) {
    start_script(&D_80293820, 10, 0)->varTable[0] = arg0;
}

void set_animation(s32 actorID, s32 partID, AnimID animID) {
    if ((s32) animID >= 0) {
        Actor* actor = get_actor(actorID);
        ActorPart* part;

        switch (actorID & ACTOR_CLASS_MASK) {
            case ACTOR_CLASS_PLAYER:
                part = &actor->partsTable[0];
                if (part->curAnimation != animID) {
                    part->curAnimation = animID;
                    spr_update_player_sprite(PLAYER_SPRITE_MAIN, animID, part->animationRate);
                }
                break;
            case ACTOR_CLASS_PARTNER:
                if (partID != 0) {
                    part = get_actor_part(actor, partID);

                    if (part == NULL) {
                        part = &actor->partsTable[0];
                    }
                } else {
                    part = &actor->partsTable[0];
                }

                if (part->curAnimation != animID) {
                    part->curAnimation = animID;
                    spr_update_sprite(part->spriteInstanceID, animID, part->animationRate);
                    part->animNotifyValue = spr_get_notify_value(part->spriteInstanceID);
                }
                break;
            case ACTOR_CLASS_ENEMY:
                part = get_actor_part(actor, partID);
                if (part->curAnimation != animID) {
                    part->curAnimation = animID;
                    spr_update_sprite(part->spriteInstanceID, animID, part->animationRate);
                    part->animNotifyValue = spr_get_notify_value(part->spriteInstanceID);
                }
                break;
        }
    }
}

void func_80263E08(Actor* actor, ActorPart* part, AnimID anim) {
    if ((s32) anim >= 0) {
        switch (actor->actorID & ACTOR_CLASS_MASK) {
            case ACTOR_CLASS_PLAYER:
                if (part->curAnimation != anim) {
                    part->curAnimation = anim;
                    spr_update_player_sprite(PLAYER_SPRITE_MAIN, anim, part->animationRate);
                }
                break;
            case ACTOR_CLASS_PARTNER:
            case ACTOR_CLASS_ENEMY:
                if (part->curAnimation != anim) {
                    part->curAnimation = anim;
                    spr_update_sprite(part->spriteInstanceID, anim, part->animationRate);
                    part->animNotifyValue = spr_get_notify_value(part->spriteInstanceID);
                }
                break;
        }
    }
}

void set_animation_rate(s32 actorID, s32 partID, f32 rate) {
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PARTNER:
            if (partID != 0) {
                part = get_actor_part(actor, partID);
                if (part != NULL) {
                    part->animationRate = rate;
                    return;
                }
            }
            actor->partsTable[0].animationRate = rate;
            break;
        case ACTOR_CLASS_PLAYER:
        case ACTOR_CLASS_ENEMY:
            part = get_actor_part(actor, partID);
            part->animationRate = rate;
            break;
    }
}

void set_actor_yaw(s32 actorID, s32 yaw) {
    get_actor(actorID)->yaw = yaw;
}

void set_part_yaw(s32 actorID, s32 partID, s32 value) {
    get_actor_part(get_actor(actorID), partID)->yaw = value;
}

void set_part_flag_bits(s32 actorID, s32 partID, s32 flags) {
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            actor->flags |= flags;
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            if (partID == 0) {
                actor->flags |= flags;
            } else {
                part = get_actor_part(actor, partID);
                part->flags |= flags;
            }
            break;
    }
}

void clear_part_flag_bits(s32 actorID, s32 partID, s32 flags) {
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            actor->flags &= ~flags;
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            if (partID == 0) {
                actor->flags &= ~flags;
            } else {
                part = get_actor_part(actor, partID);
                part->flags &= ~flags;
            }
            break;
    }
}

void add_xz_vec3f(Vec3f* vector, f32 speed, f32 angleDeg) {
    f32 angleRad = DEG_TO_RAD(angleDeg);
    f32 sinAngleRad = sin_rad(angleRad);
    f32 cosAngleRad = cos_rad(angleRad);

    vector->x += speed * sinAngleRad;
    vector->z += -speed * cosAngleRad;
}

void add_xz_vec3f_copy1(Vec3f* vector, f32 speed, f32 angleDeg) {
    f32 angleRad = DEG_TO_RAD(angleDeg);
    f32 sinAngleRad = sin_rad(angleRad);
    f32 cosAngleRad = cos_rad(angleRad);

    vector->x += speed * sinAngleRad;
    vector->z += -speed * cosAngleRad;
}

void add_xz_vec3f_copy2(Vec3f* vector, f32 speed, f32 angleDeg) {
    f32 angleRad = DEG_TO_RAD(angleDeg);
    f32 sinAngleRad = sin_rad(angleRad);
    f32 cosAngleRad = cos_rad(angleRad);

    vector->x += speed * sinAngleRad;
    vector->z += -speed * cosAngleRad;
}

void play_movement_dust_effects(s32 var0, f32 xPos, f32 yPos, f32 zPos, f32 angleDeg) {
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;

    if (var0 == 2) {
        fx_landing_dust(0, xPos, yPos + 0.0f, zPos, D_802938A4);
    } else if (var0 == 1) {
        D_802938A8 = 4;
    } else if (D_802938A8++ >= 4) {
        D_802938A8 = 0;
        theta = DEG_TO_RAD(clamp_angle(-angleDeg));
        sinTheta = sin_rad(theta);
        cosTheta = cos_rad(theta);
        fx_walking_dust(
            0,
            xPos + (sinTheta * 24.0f * 0.2f),
            yPos + 1.5f,
            zPos + (cosTheta * 24.0f * 0.2f),
            sinTheta,
            cosTheta
        );
    }
}

ActorPart* get_actor_part(Actor* actor, s32 partID) {
    ActorPart* part = &actor->partsTable[0];

    if (partID < 0 || part->nextPart == NULL) {
        return part;
    }

    while (part != NULL) {
        if (part->staticData->index == partID) {
            return part;
        }
        part = part->nextPart;
    }

    return NULL;
}

void load_player_actor(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player;
    ActorPart* part;
    DecorationTable* decorationTable;
    ActorPartMovement* partMovement;
    s32 i;
    s32 j;

    player = battleStatus->playerActor = heap_malloc(sizeof(*player));

    ASSERT(player != NULL);

    player->unk_134 = battleStatus->unk_93++;
    player->footStepCounter = 0;
    player->flags = 0;
    player->actorBlueprint = &bPlayerActorBlueprint;
    player->actorType = bPlayerActorBlueprint.type;

    if ((gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) || (gGameStatusPtr->demoFlags & 2)) {
        player->homePos.x = player->curPos.x = -130.0f;
        player->homePos.y = player->curPos.y = 0.0f;
        player->homePos.z = player->curPos.z = -10.0f;
    } else {
        player->homePos.x = player->curPos.x = -95.0f;
        player->homePos.y = player->curPos.y = 0.0f;
        player->homePos.z = player->curPos.z = 0.0f;
    }

    player->headOffset.x = 0;
    player->headOffset.y = 0;
    player->headOffset.z = 0;
    player->rot.x = 0.0f;
    player->rot.y = 0.0f;
    player->rot.z = 0.0f;
    player->rotPivotOffset.x = 0;
    player->rotPivotOffset.y = 0;
    player->rotPivotOffset.z = 0;
    player->verticalRenderOffset = 0;
    player->yaw = 0.0f;
    player->renderMode = RENDER_MODE_ALPHATEST;
    player->scale.x = 1.0f;
    player->scale.y = 1.0f;
    player->scale.z = 1.0f;
    player->scaleModifier.x = 1.0f;
    player->scaleModifier.y = 1.0f;
    player->scaleModifier.z = 1.0f;
    player->size.x = player->actorBlueprint->size.x;
    player->size.y = player->actorBlueprint->size.y;
    player->actorID = 0;
    player->healthBarPos.x = player->curPos.x;
    player->healthBarPos.y = player->curPos.y;
    player->healthBarPos.z = player->curPos.z;
    player->scalingFactor = 1.0f;
    player->attackResultEffect = NULL;
    player->actionRatingCombo = 0;
    player->actionRatingTime = 0;
    player->statusIconOffset.x = 0;
    player->statusIconOffset.y = 0;
    player->statusTextOffset.x = 0;
    player->statusTextOffset.y = 0;
    player->idleSource = NULL;
    player->takeTurnSource = NULL;
    player->handleEventSource = NULL;
    player->handlePhaseSource = NULL;
    player->idleScript = NULL;
    player->takeTurnScript = NULL;
    player->handleEventScript = NULL;
    player->handlePhaseScript = NULL;
    player->turnPriority = 0;
    player->statusTable = bPlayerStatusTable;
    player->debuff = 0;
    player->debuffDuration = 0;
    player->staticStatus = 0;
    player->staticDuration = 0;
    player->stoneStatus = 0;
    player->stoneDuration = 0;
    player->koStatus = 0;
    player->koDuration = 0;
    player->transparentStatus = 0;
    player->transparentDuration = 0;
    player->isGlowing = 0;
    player->unk_21E = 0;
    player->disableDismissTimer = 0;
    player->attackBoost = 0;
    player->defenseBoost = 0;
    player->chillOutAmount = 0;
    player->chillOutTurns = 0;
    player->statusAfflicted = 0;
    player->actorTypeData1[0] = bActorSoundTable[player->actorType].walk[0];
    player->actorTypeData1[1] = bActorSoundTable[player->actorType].walk[1];
    player->actorTypeData1[2] = bActorSoundTable[player->actorType].fly[0];
    player->actorTypeData1[3] = bActorSoundTable[player->actorType].fly[1];
    player->actorTypeData1[4] = bActorSoundTable[player->actorType].jump;
    player->actorTypeData1[5] = bActorSoundTable[player->actorType].hurt;
    player->actorTypeData1b[0] = bActorSoundTable[player->actorType].delay[0];
    player->actorTypeData1b[1] = bActorSoundTable[player->actorType].delay[1];

    for (i = 0; i < ARRAY_COUNT(player->loopingSoundID); i++) {
        player->loopingSoundID[i] = 0;
    }

    part = heap_malloc(sizeof(*part));
    player->partsTable = part;

    ASSERT(part != NULL)

    player->numParts = 1;
    part->staticData = bMarioParts;
    part->partOffset.x = 0;
    part->partOffset.y = 0;
    part->partOffset.z = 0;
    part->partOffset.x = 12;
    part->partOffset.y = 32;
    part->partOffset.z = 5;
    part->decorationTable = NULL;
    part->flags = 0;
    part->targetFlags = 0;
    part->partOffsetFloat.x = 0.0f;
    part->partOffsetFloat.y = 0.0f;
    part->partOffsetFloat.z = 0.0f;
    part->rotPivotOffset.x = 0;
    part->rotPivotOffset.y = 0;
    part->rotPivotOffset.z = 0;
    part->visualOffset.x = 0;
    part->visualOffset.y = 0;
    part->visualOffset.z = 0;
    part->absolutePos.x = 0.0f;
    part->absolutePos.y = 0.0f;
    part->absolutePos.z = 0.0f;
    part->defenseTable = bMarioDefenseTable;

    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
        part->idleAnimations = bPeachIdleAnims;
    } else {
        part->idleAnimations = bMarioIdleAnims;
    }

    part->eventFlags = 0;
    part->elementalImmunities = 0;
    part->opacity = 255;
    part->size.y = player->size.y;
    part->size.x = player->size.x;
    part->yaw = 0.0f;
    part->targetOffset.x = 0;
    part->targetOffset.y = 0;
    part->unk_70 = 0;
    part->rot.x = 0.0f;
    part->rot.y = 0.0f;
    part->rot.z = 0.0f;
    part->scale.x = 1.0f;
    part->scale.y = 1.0f;
    part->scale.z = 1.0f;
    part->verticalStretch = 1;
    part->palAnimPosOffset[0] = 0;
    part->palAnimPosOffset[1] = 0;
    part->animationRate = 1.0f;
    part->curAnimation = get_npc_anim_for_status(part->idleAnimations, 1U);
    part->nextPart = NULL;
    part->partTypeData[0] = bActorSoundTable[player->actorType].walk[0];
    part->partTypeData[1] = bActorSoundTable[player->actorType].walk[1];
    part->partTypeData[2] = bActorSoundTable[player->actorType].fly[0];
    part->partTypeData[3] = bActorSoundTable[player->actorType].fly[1];
    part->partTypeData[4] = bActorSoundTable[player->actorType].jump;
    part->partTypeData[5] = bActorSoundTable[player->actorType].hurt;
    part->actorTypeData2b[0] = bActorSoundTable[player->actorType].delay[0];
    part->actorTypeData2b[1] = bActorSoundTable[player->actorType].delay[1];

    if (part->idleAnimations != NULL) {
        s32 j;

        part->decorationTable = heap_malloc(sizeof(*decorationTable));
        decorationTable = part->decorationTable;

        ASSERT(decorationTable != NULL);

        decorationTable->paletteAdjustment = PAL_ADJUST_NONE;
        decorationTable->unk_750 = 0;
        decorationTable->unk_764 = 0;
        decorationTable->unk_768 = 0;
        decorationTable->unk_7D8 = 0;
        decorationTable->unk_7D9 = 0;

        for (j = 0; j < ARRAY_COUNT(decorationTable->posX); j++) {
            decorationTable->posX[j] = player->curPos.x;
            decorationTable->posY[j] = player->curPos.y;
            decorationTable->posZ[j] = player->curPos.z;
        }

        decorationTable->unk_7DA = 3;
        decorationTable->unk_7DB = 0;
        decorationTable->effectType = 0;

        for (j = 0; j < ARRAY_COUNT(decorationTable->effect); j++) {
            decorationTable->effect[j] = NULL;
            decorationTable->type[j] = 0;
        }
    }

    partMovement = part->movement = heap_malloc(sizeof(*partMovement));
    ASSERT(partMovement != NULL);

    player->shadow.id = create_shadow_type(0, player->curPos.x, player->curPos.y, player->curPos.z);
    player->shadowScale = player->size.x / 24.0;
    player->hudElementDataIndex = create_status_icon_set();
    player->disableEffect = fx_disable_x(0, -142.0f, 34.0f, 1.0f, 0);
    player->icePillarEffect = NULL;

    if (is_ability_active(ABILITY_ZAP_TAP)) {
        player->staticStatus = STATUS_KEY_STATIC;
        player->staticDuration = 127;
    }
}

void load_partner_actor(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor;
    ActorBlueprint* actorBP;
    Evt* takeTurnScript;
    s32 partCount;
    s32 currentPartner;
    PartnerDMAData* partnerData;
    f32 x;
    f32 y;
    f32 z;
    ActorPart* part;
    s32 i;
    s32 i2;

    currentPartner = playerData->curPartner;
    battleStatus->partnerActor = NULL;

    if (currentPartner != PARTNER_NONE) {
        partnerData = &bPartnerDmaTable[currentPartner];
        actorBP = partnerData->ActorBlueprint;

        ASSERT(actorBP != NULL);

        nuPiReadRom(partnerData->dmaStart, partnerData->dmaDest, partnerData->dmaEnd - partnerData->dmaStart);
        if ((gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) || (gGameStatusPtr->demoFlags & 2)) {
            x = -95.0f;
            y = partnerData->y;
            z = 0.0f;
            gBattleStatus.flags1 |= BS_FLAGS1_PLAYER_IN_BACK;
        } else {
            x = -130.0f;
            y = partnerData->y;
            z = -10.0f;
        }
        partCount = actorBP->partCount;
        battleStatus->partnerActor = heap_malloc(sizeof(*partnerActor));
        partnerActor = battleStatus->partnerActor;

        ASSERT(partnerActor != NULL);

        actorBP->level = playerData->partners[playerData->curPartner].level;
        partnerActor->unk_134 = battleStatus->unk_93++;
        partnerActor->footStepCounter = 0;
        partnerActor->actorBlueprint = actorBP;
        partnerActor->actorType = actorBP->type;
        partnerActor->flags = actorBP->flags;
        partnerActor->homePos.x = partnerActor->curPos.x = x;
        partnerActor->homePos.y = partnerActor->curPos.y = y;
        partnerActor->homePos.z = partnerActor->curPos.z = z;
        partnerActor->headOffset.x = 0;
        partnerActor->headOffset.y = 0;
        partnerActor->headOffset.z = 0;
        partnerActor->curHP = actorBP->maxHP;
        partnerActor->numParts = partCount;
        partnerActor->idleSource = NULL;
        partnerActor->takeTurnSource = actorBP->initScript;
        partnerActor->handleEventSource = NULL;
        partnerActor->handlePhaseSource = NULL;
        partnerActor->idleScript = NULL;
        partnerActor->takeTurnScript = NULL;
        partnerActor->handleEventScript = NULL;
        partnerActor->handlePhaseScript = NULL;
        partnerActor->turnPriority = 0;
        partnerActor->enemyIndex = 0;
        partnerActor->yaw = 0.0f;
        partnerActor->rot.x = 0.0f;
        partnerActor->rot.y = 0.0f;
        partnerActor->rot.z = 0.0f;
        partnerActor->rotPivotOffset.x = 0;
        partnerActor->rotPivotOffset.y = 0;
        partnerActor->rotPivotOffset.z = 0;
        partnerActor->scale.x = 1.0f;
        partnerActor->scale.y = 1.0f;
        partnerActor->scale.z = 1.0f;
        partnerActor->scaleModifier.x = 1.0f;
        partnerActor->scaleModifier.y = 1.0f;
        partnerActor->scaleModifier.z = 1.0f;
        partnerActor->verticalRenderOffset = 0;
        partnerActor->size.x = actorBP->size.x;
        partnerActor->size.y = actorBP->size.y;
        partnerActor->healthBarPos.x = partnerActor->homePos.x;
        partnerActor->healthBarPos.y = partnerActor->homePos.y;
        partnerActor->healthBarPos.z = partnerActor->homePos.z;
        partnerActor->scalingFactor = 1.0f;
        partnerActor->attackResultEffect = NULL;
        partnerActor->actionRatingCombo = 0;
        partnerActor->actionRatingTime = 0;
        partnerActor->statusIconOffset.x = 0;
        partnerActor->statusIconOffset.y = 0;
        partnerActor->statusTextOffset.x = 0;
        partnerActor->statusTextOffset.y = 0;
        partnerActor->renderMode = RENDER_MODE_ALPHATEST;
        partnerActor->actorID = ACTOR_PARTNER;
        partnerActor->statusTable = actorBP->statusTable;
        partnerActor->debuff = 0;
        partnerActor->debuffDuration = 0;
        partnerActor->staticStatus = 0;
        partnerActor->staticDuration = 0;
        partnerActor->stoneStatus = 0;
        partnerActor->stoneDuration = 0;
        partnerActor->koStatus = 0;
        partnerActor->koDuration = 0;
        partnerActor->transparentStatus = 0;
        partnerActor->transparentDuration = 0;
        partnerActor->isGlowing = 0;
        partnerActor->unk_21E = 0;
        partnerActor->disableDismissTimer = 0;
        partnerActor->attackBoost = 0;
        partnerActor->defenseBoost = 0;
        partnerActor->chillOutAmount = 0;
        partnerActor->chillOutTurns = 0;
        partnerActor->statusAfflicted = 0;
        partnerActor->actorTypeData1[0] = bActorSoundTable[partnerActor->actorType].walk[0];
        partnerActor->actorTypeData1[1] = bActorSoundTable[partnerActor->actorType].walk[1];
        partnerActor->actorTypeData1[2] = bActorSoundTable[partnerActor->actorType].fly[0];
        partnerActor->actorTypeData1[3] = bActorSoundTable[partnerActor->actorType].fly[1];
        partnerActor->actorTypeData1[4] = bActorSoundTable[partnerActor->actorType].jump;
        partnerActor->actorTypeData1[5] = bActorSoundTable[partnerActor->actorType].hurt;
        partnerActor->actorTypeData1b[0] = bActorSoundTable[partnerActor->actorType].delay[0];
        partnerActor->actorTypeData1b[1] = bActorSoundTable[partnerActor->actorType].delay[1];

        for (i2 = 0; i2 < ARRAY_COUNT(partnerActor->loopingSoundID); i2++) {
            partnerActor->loopingSoundID[i2] = 0;
        }

        part = heap_malloc(sizeof(*part));
        partnerActor->partsTable = part;

        ASSERT(part != NULL);

        for (i = 0; i < partCount; i++) {
            ActorPartBlueprint* ActorPartBlueprint = &actorBP->partsData[i];
            part->decorationTable = NULL;
            part->staticData = ActorPartBlueprint;

            part->flags = ActorPartBlueprint->flags | ACTOR_PART_FLAG_4;
            part->targetFlags = 0;

            part->partOffsetFloat.x = part->partOffset.x = ActorPartBlueprint->posOffset.x;
            part->partOffsetFloat.y = part->partOffset.y = ActorPartBlueprint->posOffset.y;
            part->partOffsetFloat.z = part->partOffset.z = ActorPartBlueprint->posOffset.z;

            part->visualOffset.x = 0;
            part->visualOffset.y = 0;
            part->visualOffset.z = 0;
            part->absolutePos.x = 0.0f;
            part->absolutePos.y = 0.0f;
            part->absolutePos.z = 0.0f;
            part->defenseTable = ActorPartBlueprint->defenseTable;
            part->idleAnimations = ActorPartBlueprint->idleAnimations;
            part->eventFlags = ActorPartBlueprint->eventFlags;
            part->elementalImmunities = ActorPartBlueprint->elementImmunityFlags;
            part->opacity = ActorPartBlueprint->opacity;
            part->size.y = partnerActor->size.y;
            part->size.x = partnerActor->size.x;
            part->yaw = 0.0f;
            part->targetOffset.x = ActorPartBlueprint->targetOffset.x;
            part->targetOffset.y = ActorPartBlueprint->targetOffset.y;
            part->unk_70 = 0;
            part->rotPivotOffset.x = 0;
            part->rotPivotOffset.y = 0;
            part->rotPivotOffset.z = 0;
            part->rot.x = 0.0f;
            part->rot.y = 0.0f;
            part->rot.z = 0.0f;
            part->scale.x = 1.0f;
            part->scale.y = 1.0f;
            part->scale.z = 1.0f;
            part->verticalStretch = 1;
            part->palAnimPosOffset[0] = 0;
            part->palAnimPosOffset[1] = 0;
            part->partTypeData[0] = bActorSoundTable[partnerActor->actorType].walk[0];
            part->partTypeData[1] = bActorSoundTable[partnerActor->actorType].walk[1];
            part->partTypeData[2] = bActorSoundTable[partnerActor->actorType].fly[0];
            part->partTypeData[3] = bActorSoundTable[partnerActor->actorType].fly[1];
            part->partTypeData[4] = bActorSoundTable[partnerActor->actorType].jump;
            part->partTypeData[5] = bActorSoundTable[partnerActor->actorType].hurt;
            part->actorTypeData2b[0] = bActorSoundTable[partnerActor->actorType].delay[0];
            part->actorTypeData2b[1] = bActorSoundTable[partnerActor->actorType].delay[1];

            if (part->idleAnimations != NULL) {
                DecorationTable* decorationTable;
                s32 j;

                part->decorationTable  = heap_malloc(sizeof(*decorationTable));
                decorationTable = part->decorationTable;

                ASSERT(decorationTable != NULL);

                decorationTable->paletteAdjustment = PAL_ADJUST_NONE;
                decorationTable->unk_750 = 0;
                decorationTable->unk_764 = 0;
                decorationTable->unk_768 = 0;
                decorationTable->unk_7D8 = 0;
                decorationTable->unk_7D9 = 0;

                for (j = 0; j < ARRAY_COUNT(decorationTable->posX); j++) {
                    decorationTable->posX[j] = partnerActor->curPos.x;
                    decorationTable->posY[j] = partnerActor->curPos.y;
                    decorationTable->posZ[j] = partnerActor->curPos.z;
                }

                decorationTable->unk_7DA = 3;
                decorationTable->unk_7DB = 0;
                decorationTable->effectType = 0;

                for (j = 0; j < ARRAY_COUNT(decorationTable->effect); j++) {
                    decorationTable->effect[j] = NULL;
                    decorationTable->type[j] = 0;
                }
            }

            if (part->flags >= 0) {
                part->movement = heap_malloc(sizeof(*part->movement));
                ASSERT(part->movement != NULL);
            }

            part->animationRate = 1.0f;
            part->curAnimation = 0;
            part->spriteInstanceID = -1;

            if (part->idleAnimations != NULL) {
                part->curAnimation = get_npc_anim_for_status(part->idleAnimations, 1);
                part->spriteInstanceID = spr_load_npc_sprite(part->curAnimation | SPRITE_ID_TAIL_ALLOCATE, NULL);
            }

            if (i + 1 >= partCount) {
                part->nextPart = NULL;
                continue;
            }

            part->nextPart = heap_malloc(sizeof(*part->nextPart));
            part = part->nextPart;
            if (part == NULL) {
                PANIC();
            }

            part->nextPart = NULL;
        }

        partnerActor->shadow.id = create_shadow_type(0, partnerActor->curPos.x, partnerActor->curPos.y, partnerActor->curPos.z);
        partnerActor->shadowScale = partnerActor->size.x / 24.0;
        partnerActor->hudElementDataIndex = create_status_icon_set();
        partnerActor->disableEffect = fx_disable_x(0, -142.0f, 34.0f, 1.0f, 0);
        partnerActor->icePillarEffect = NULL;

        takeTurnScript = start_script(partnerActor->takeTurnSource, EVT_PRIORITY_A, 0);
        partnerActor->takeTurnScriptID = takeTurnScript->id;
        takeTurnScript->owner1.actorID = ACTOR_PARTNER;
    }
}

Actor* create_actor(Formation formation) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    ActorBlueprint* formationActor;
    ActorPart* part;
    ActorPartBlueprint* partBP;
    Evt* takeTurnScript;
    s32 partCount;
    f32 x, y, z;
    DecorationTable* decorationTable;
    s32 i, j, k;

    if (formation->home.index >= EVT_LIMIT) {
        x = btl_actorHomePositions[formation->home.index].x;
        y = btl_actorHomePositions[formation->home.index].y;
        z = btl_actorHomePositions[formation->home.index].z;
    } else {
        x = formation->home.vec->x;
        y = formation->home.vec->y;
        z = formation->home.vec->z;
    }

    formationActor = formation->actor;
    partCount = formationActor->partCount;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        if (battleStatus->enemyActors[i] == NULL) {
            break;
        }
    }

    actor = battleStatus->enemyActors[i] = heap_malloc(sizeof(*actor));

    ASSERT(actor != NULL);

    actor->unk_134 = battleStatus->unk_93++;
    actor->footStepCounter = 0;
    actor->actorBlueprint = formationActor;
    actor->actorType = formationActor->type;
    actor->flags = formationActor->flags;
    actor->homePos.x = actor->curPos.x = x;
    actor->homePos.y = actor->curPos.y = y;
    actor->homePos.z = actor->curPos.z = z;
    actor->headOffset.x = 0;
    actor->headOffset.y = 0;
    actor->headOffset.z = 0;
    actor->maxHP = actor->curHP = formationActor->maxHP;
    actor->numParts = partCount;
    actor->idleSource = NULL;
    actor->takeTurnSource = formationActor->initScript;
    actor->handleEventSource = NULL;
    actor->handlePhaseSource = NULL;
    actor->idleScript = NULL;
    actor->takeTurnScript = NULL;
    actor->handleEventScript = NULL;
    actor->turnPriority = formation->priority;
    actor->enemyIndex = i;
    actor->yaw = 0.0f;
    actor->rot.x = 0.0f;
    actor->rot.y = 0.0f;
    actor->rot.z = 0.0f;
    actor->rotPivotOffset.x = 0;
    actor->rotPivotOffset.y = 0;
    actor->rotPivotOffset.z = 0;
    actor->scale.x = 1.0f;
    actor->scale.y = 1.0f;
    actor->scale.z = 1.0f;
    actor->scaleModifier.x = 1.0f;
    actor->scaleModifier.y = 1.0f;
    actor->scaleModifier.z = 1.0f;
    actor->verticalRenderOffset = 0;
    actor->extraCoinBonus = 0;
    actor->size.x = formationActor->size.x;
    actor->size.y = formationActor->size.y;
    actor->scalingFactor = 1.0f;
    actor->statusIconOffset.x = 0;
    actor->statusIconOffset.y = 0;
    actor->statusTextOffset.x = 0;
    actor->statusTextOffset.y = 0;
    actor->healthBarOffset.x = 0;
    actor->healthBarOffset.y = 0;
    actor->healthBarHideTime = 0;
    actor->attackResultEffect = NULL;
    actor->actionRatingCombo = 0;
    actor->actionRatingTime = 0;

    actor->healthBarPos.x = actor->curPos.x + formationActor->healthBarOffset.x;
    actor->healthBarPos.y = actor->curPos.y + formationActor->healthBarOffset.y;
    actor->healthBarPos.z = actor->curPos.z;
    if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
        actor->healthBarPos.y = actor->curPos.y - actor->size.y - formationActor->healthBarOffset.y;
    }

    actor->statusTable = formationActor->statusTable;
    actor->debuff = 0;
    actor->debuffDuration = 0;
    actor->staticStatus = 0;
    actor->staticDuration = 0;
    actor->stoneStatus = 0;
    actor->stoneDuration = 0;
    actor->koStatus = 0;
    actor->koDuration = 0;
    actor->transparentStatus = 0;
    actor->transparentDuration = 0;
    actor->isGlowing = 0;
    actor->unk_21E = 0;
    actor->disableDismissTimer = 0;
    actor->attackBoost = 0;
    actor->defenseBoost = 0;
    actor->chillOutAmount = 0;
    actor->chillOutTurns = 0;
    actor->statusAfflicted = 0;
    actor->actorTypeData1[0] = bActorSoundTable[actor->actorType].walk[0];
    actor->actorTypeData1[1] = bActorSoundTable[actor->actorType].walk[1];
    actor->actorTypeData1[2] = bActorSoundTable[actor->actorType].fly[0];
    actor->actorTypeData1[3] = bActorSoundTable[actor->actorType].fly[1];
    actor->actorTypeData1[4] = bActorSoundTable[actor->actorType].jump;
    actor->actorTypeData1[5] = bActorSoundTable[actor->actorType].hurt;
    actor->actorTypeData1b[0] = bActorSoundTable[actor->actorType].delay[0];
    actor->actorTypeData1b[1] = bActorSoundTable[actor->actorType].delay[1];

    for (i = 0; i < ARRAY_COUNT(actor->loopingSoundID); i++) {
        actor->loopingSoundID[i] = 0;
    }

    actor->state.varTable[0] = formation->var0;
    actor->state.varTable[1] = formation->var1;
    actor->state.varTable[2] = formation->var2;
    actor->state.varTable[3] = formation->var3;
    actor->renderMode = RENDER_MODE_ALPHATEST;
    actor->instigatorValue = 0;
    part = heap_malloc(sizeof(*part));
    actor->partsTable = part;
    ASSERT(part != NULL);

    for (j = 0; j < partCount; j++) {
        ActorPartBlueprint* actorPartBP = &formationActor->partsData[j];

        part->decorationTable = NULL;
        part->staticData = actorPartBP;
        part->flags = actorPartBP->flags | ACTOR_PART_FLAG_4;
        part->targetFlags = 0;

        part->partOffsetFloat.x = part->partOffset.x = actorPartBP->posOffset.x;
        part->partOffsetFloat.y = part->partOffset.y = actorPartBP->posOffset.y;
        part->partOffsetFloat.z = part->partOffset.z = actorPartBP->posOffset.z;

        part->visualOffset.x = 0;
        part->visualOffset.y = 0;
        part->visualOffset.z = 0;

        part->absolutePos.x = actor->curPos.x;
        part->absolutePos.y = actor->curPos.y;
        part->absolutePos.z = actor->curPos.z;
        part->curPos.x = actor->curPos.x;
        part->curPos.y = actor->curPos.y;
        part->curPos.z = actor->curPos.z;
        part->defenseTable = actorPartBP->defenseTable;
        part->idleAnimations = actorPartBP->idleAnimations;
        part->eventFlags = actorPartBP->eventFlags;
        part->elementalImmunities = actorPartBP->elementImmunityFlags;
        part->opacity = actorPartBP->opacity;
        if (part->opacity < 255) {
            actor->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
        }
        part->size.y = actor->size.y;
        part->size.x = actor->size.x;
        part->yaw = 0.0f;
        part->targetOffset.x = actorPartBP->targetOffset.x;
        part->targetOffset.y = actorPartBP->targetOffset.y;
        part->unk_70 = 0;
        part->projectileTargetOffset.x = actorPartBP->projectileTargetOffset.x;
        part->projectileTargetOffset.y = actorPartBP->projectileTargetOffset.y;
        part->rot.x = 0.0f;
        part->rot.y = 0.0f;
        part->rot.z = 0.0f;
        part->rotPivotOffset.x = 0;
        part->rotPivotOffset.y = 0;
        part->rotPivotOffset.z = 0;
        part->scale.x = 1.0f;
        part->scale.y = 1.0f;
        part->scale.z = 1.0f;
        part->verticalStretch = 1;
        part->palAnimPosOffset[0] = 0;
        part->palAnimPosOffset[1] = 0;
        part->partTypeData[0] = bActorSoundTable[actor->actorType].walk[0];
        part->partTypeData[1] = bActorSoundTable[actor->actorType].walk[1];
        part->partTypeData[2] = bActorSoundTable[actor->actorType].fly[0];
        part->partTypeData[3] = bActorSoundTable[actor->actorType].fly[1];
        part->partTypeData[4] = bActorSoundTable[actor->actorType].jump;
        part->partTypeData[5] = bActorSoundTable[actor->actorType].hurt;
        part->actorTypeData2b[0] = bActorSoundTable[actor->actorType].delay[0];
        part->actorTypeData2b[1] = bActorSoundTable[actor->actorType].delay[1];

        if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
            part->decorationTable = heap_malloc(sizeof(*decorationTable));
            decorationTable = part->decorationTable;
            ASSERT(decorationTable != NULL);

            decorationTable->paletteAdjustment = PAL_ADJUST_NONE;
            decorationTable->unk_750 = 0;
            decorationTable->unk_764 = 0;
            decorationTable->unk_768 = 0;
            decorationTable->unk_7D8 = 0;
            decorationTable->unk_7D9 = 0;

            for (k = 0; k < ARRAY_COUNT(decorationTable->posX); k++) {
                decorationTable->posX[k] = actor->curPos.x;
                decorationTable->posY[k] = actor->curPos.y;
                decorationTable->posZ[k] = actor->curPos.z;
            }

            decorationTable->unk_7DA = 3;
            decorationTable->unk_7DB = 0;
            decorationTable->effectType = 0;

            for (k = 0; k < ARRAY_COUNT(decorationTable->effect); k++) {
                decorationTable->effect[k] = NULL;
                decorationTable->type[k] = 0;
            }

        }

        if (part->flags >= 0) {
            part->movement = heap_malloc(sizeof(*part->movement));
            ASSERT(part->movement != NULL);
        }

        if (actor->flags & ACTOR_FLAG_TARGET_ONLY) {
            part->flags |= ACTOR_PART_FLAG_4000;
        }

        part->animationRate = 1.0f;
        part->curAnimation = 0;
        part->spriteInstanceID = -1;

        if (part->idleAnimations != NULL) {
            part->curAnimation = get_npc_anim_for_status(part->idleAnimations, 1) & ~SPRITE_ID_TAIL_ALLOCATE;
            part->spriteInstanceID = spr_load_npc_sprite(part->curAnimation, NULL);
        }

        if (j + 1 >= partCount) {
            part->nextPart = NULL;
            continue;
        }

        part->nextPart = heap_malloc(sizeof(*part->nextPart));
        part = part->nextPart;
        if (part == NULL) {
            PANIC();
        }

        part->nextPart = NULL;
    }

    actor->healthFraction = 25;
    actor->actorID = actor->enemyIndex | ACTOR_CLASS_ENEMY;
    takeTurnScript = start_script(actor->takeTurnSource, EVT_PRIORITY_A, 0);
    actor->takeTurnScriptID = takeTurnScript->id;
    takeTurnScript->owner1.enemyID = actor->enemyIndex | ACTOR_CLASS_ENEMY;
    actor->shadow.id = create_shadow_type(0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
    actor->shadowScale = actor->size.x / 24.0;
    actor->disableEffect = fx_disable_x(0, -142.0f, 34.0f, 1.0f, 0);
    actor->icePillarEffect = NULL;
    actor->hudElementDataIndex = create_status_icon_set();
    return actor;
}

s32 get_npc_anim_for_status(AnimID* animations, s32 statusKey) {
    AnimID foundAnim;

    if (animations == NULL) {
        return 0;
    }

    foundAnim = 0;
    while (animations[DICTIONARY_KEY] != NULL) {
        if (animations[DICTIONARY_KEY] == STATUS_KEY_NORMAL) {
            foundAnim = animations[DICTIONARY_VALUE];
        }
        if (animations[DICTIONARY_KEY] == statusKey) {
            foundAnim = animations[DICTIONARY_VALUE];
            break;
        }
        animations += DICTIONARY_SIZE;
    }
    return foundAnim;
}

s32 get_player_anim_for_status(s32 statusKey) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    u32* anim = &player->partsTable->idleAnimations[0];
    s32 ret;

    if (anim == NULL) {
        return 0;
    }
    ret = 0;

    if (!(battleStatus->flags2 & BS_FLAGS2_PEACH_BATTLE)) {
        // switch to danger override animations
        if (playerData->curHP <= DANGER_THRESHOLD) {
            if (statusKey == STATUS_KEY_NORMAL) {
                statusKey = STATUS_KEY_DANGER;
            }
            if (statusKey == STATUS_KEY_INACTIVE) {
                statusKey = STATUS_KEY_INACTIVE_WEARY;
            }
            if (statusKey == STATUS_KEY_THINKING) {
                statusKey = STATUS_KEY_WEARY;
            }
        }

        // switch to poisoned override animations
        if (player->debuff == STATUS_KEY_POISON) {
            if (statusKey == STATUS_KEY_NORMAL) {
                statusKey = STATUS_KEY_DANGER;
            }
            if (statusKey == STATUS_KEY_INACTIVE) {
                statusKey = STATUS_KEY_INACTIVE_WEARY;
            }
            if (statusKey == STATUS_KEY_THINKING) {
                statusKey = STATUS_KEY_WEARY;
            }
        }

        // switch to dizzy override animations
        if (player->debuff == STATUS_KEY_DIZZY) {
            if (statusKey == STATUS_KEY_INACTIVE) {
                statusKey = STATUS_KEY_INACTIVE_DIZZY;
            }
        }
    }

    // search IdleAnimations to get animID for key
    while (*anim != NULL) {
        if (*anim == 1) {
            ret = anim[1];
        }
        if (*anim == statusKey) {
            ret = anim[1];
            break;
        }
        anim += 2;
    }

    return ret;
}

s32 lookup_defense(s32* defenseTable, s32 elementKey) {
    s32 normalDefense = 0;

    while (defenseTable[DICTIONARY_KEY] != ELEMENT_END) {
        if (defenseTable[DICTIONARY_KEY] == ELEMENT_NORMAL) {
            normalDefense = defenseTable[DICTIONARY_VALUE];
        }

        if (defenseTable[DICTIONARY_KEY] == elementKey) {
            normalDefense = defenseTable[DICTIONARY_VALUE];
            break;
        }
        defenseTable += DICTIONARY_SIZE;
    }

    // Fall back to normal defense if given element is not specified in table
    return normalDefense;
}

s32 lookup_status_chance(s32* statusTable, s32 statusKey) {
    s32 defaultChance = 0;

    while (statusTable[DICTIONARY_KEY] != STATUS_END) {
        if (statusTable[DICTIONARY_KEY] == STATUS_KEY_DEFAULT) {
            defaultChance = statusTable[DICTIONARY_VALUE];
        }

        if (statusTable[DICTIONARY_KEY] == statusKey) {
            defaultChance = statusTable[DICTIONARY_VALUE];
            break;
        }
        statusTable += DICTIONARY_SIZE;
    }

    // Fall back to normal chance if given element is not specified in table
    return defaultChance;
}

s32 lookup_status_duration_mod(s32* statusTable, s32 statusKey) {
    s32 defaultTurnMod = 0;

    while (statusTable[DICTIONARY_KEY] != ELEMENT_END) {
        if (statusTable[DICTIONARY_KEY] == STATUS_TURN_MOD_DEFAULT) {
            defaultTurnMod = statusTable[DICTIONARY_VALUE];
        }

        if (statusTable[DICTIONARY_KEY] == statusKey) {
            defaultTurnMod = statusTable[DICTIONARY_VALUE];
            break;
        }
        statusTable += DICTIONARY_SIZE;
    }

    // Fall back to normal duration if given element is not specified in table
    return defaultTurnMod;
}

s32 inflict_status(Actor* target, s32 statusTypeKey, s32 duration) {
    BattleStatus* battleStatus = &gBattleStatus;
    EffectInstance* effect;

    switch (statusTypeKey) {
        case STATUS_KEY_FEAR:
        case STATUS_KEY_DIZZY:
        case STATUS_KEY_PARALYZE:
        case STATUS_KEY_SLEEP:
        case STATUS_KEY_FROZEN:
        case STATUS_KEY_STOP:
        case STATUS_KEY_POISON:
        case STATUS_KEY_SHRINK:
            if (target->actorID != ACTOR_PLAYER || (!is_ability_active(ABILITY_FEELING_FINE) &&
                !is_ability_active(ABILITY_BERSERKER) && battleStatus->hustleTurns == 0)) {

                if (target->actorID != ACTOR_PARTNER) {
                    if (target->debuff != statusTypeKey) {
                        target->statusAfflicted = statusTypeKey;
                    }
                    target->disableEffect->data.disableX->koDuration = 0;
                    target->debuff = statusTypeKey;
                    target->debuffDuration = duration;
                    if ((s8)duration > 9) {
                        target->debuffDuration = 9;
                    }

                    switch (statusTypeKey) {
                        case STATUS_KEY_FROZEN:
                            if (target->actorID != ACTOR_PARTNER) {
                                effect = target->icePillarEffect;
                                if (effect != NULL) {
                                    effect->flags |= FX_INSTANCE_FLAG_DISMISS;
                                }
                                target->icePillarEffect = fx_ice_pillar(0, target->curPos.x, target->curPos.y,
                                                            target->curPos.z, 1.0f, 0);
                                create_status_debuff(target->hudElementDataIndex, STATUS_KEY_FROZEN);
                            }
                            return TRUE;
                        case STATUS_KEY_SLEEP:
                            set_actor_pal_adjustment(target, PAL_ADJUST_SLEEP);
                            create_status_debuff(target->hudElementDataIndex, STATUS_KEY_SLEEP);
                            return TRUE;
                        case STATUS_KEY_PARALYZE:
                            set_actor_pal_adjustment(target, PAL_ADJUST_PARALYZE);
                            create_status_debuff(target->hudElementDataIndex, STATUS_KEY_PARALYZE);
                            return TRUE;
                        case STATUS_KEY_DIZZY:
                            create_status_debuff(target->hudElementDataIndex, STATUS_KEY_DIZZY);
                            return TRUE;
                        case STATUS_KEY_FEAR:
                            set_actor_pal_adjustment(target, PAL_ADJUST_FEAR);
                            create_status_debuff(target->hudElementDataIndex, STATUS_KEY_FEAR);
                            return TRUE;
                        case STATUS_KEY_POISON:
                            set_actor_pal_adjustment(target, PAL_ADJUST_POISON);
                            create_status_debuff(target->hudElementDataIndex, STATUS_KEY_POISON);
                            return TRUE;
                        case STATUS_KEY_SHRINK:
                            create_status_debuff(target->hudElementDataIndex, STATUS_KEY_SHRINK);
                            return TRUE;
                    }
                }
                return TRUE;
            } else {
                return FALSE;
            }
            break;
        case STATUS_KEY_STATIC:
            if (target->actorID != ACTOR_PARTNER) {
                target->staticStatus = statusTypeKey;
                target->staticDuration = duration;
                if ((s8)duration > 9) {
                    target->staticDuration = 9;
                }
                target->statusAfflicted = STATUS_KEY_STATIC;
                set_actor_pal_adjustment(target, PAL_ADJUST_STATIC);
                create_status_static(target->hudElementDataIndex, STATUS_KEY_STATIC);
            }
            return TRUE;
        case STATUS_KEY_STONE:
            if (target->actorID != ACTOR_PARTNER) {
                target->stoneStatus = STATUS_KEY_STONE;
                target->stoneDuration = duration;
                if ((s8)duration > 9) {
                    target->stoneDuration = 9;
                }
                target->statusAfflicted = STATUS_KEY_STONE;
            }
            return TRUE;
        case STATUS_KEY_DAZE:
            if (target->koStatus < statusTypeKey) {
                target->koStatus = STATUS_KEY_DAZE;
                target->koDuration = duration;
                if ((s8)duration > 9) {
                    target->koDuration = 9;
                }
                target->statusAfflicted = STATUS_KEY_DAZE;
            }
            return TRUE;
        case STATUS_KEY_TRANSPARENT:
            if (target->actorID != ACTOR_PARTNER) {
                target->transparentStatus = STATUS_KEY_TRANSPARENT;
                target->transparentDuration = duration;
                if ((s8)duration > 9) {
                    target->transparentDuration = 9;
                }
                target->statusAfflicted = STATUS_KEY_TRANSPARENT;
                create_status_transparent(target->hudElementDataIndex, STATUS_KEY_TRANSPARENT);
            }
            return TRUE;
        case 0:
        case STATUS_KEY_NORMAL:
        case STATUS_KEY_DEFAULT:
        default:
            return TRUE;
    }
}

s32 inflict_partner_ko(Actor* target, s32 statusTypeKey, s32 duration) {
    if (statusTypeKey == STATUS_KEY_DAZE) {
        if (statusTypeKey != target->koStatus) {
            inflict_status(target, STATUS_KEY_DAZE, duration);
            sfx_play_sound(SOUND_2107);
        } else {
            target->koDuration += duration;
            if (target->koDuration > 9) {
                target->koDuration = 9;
            }
        }
    }

    return TRUE;
}

s32 get_defense(Actor* actor, s32* defenseTable, s32 elementFlags) {
    s32 defense;
    s32 minDefense = 255;

    if (defenseTable != NULL) {

        #define CHECK_DEFENSE(element) \
        if (elementFlags & DAMAGE_TYPE_##element) { \
            defense = lookup_defense(defenseTable, ELEMENT_##element); \
            if (defense < minDefense) { \
                minDefense = defense; \
            } \
        } \

        CHECK_DEFENSE(FIRE);
        CHECK_DEFENSE(WATER);
        CHECK_DEFENSE(ICE);
        CHECK_DEFENSE(MAGIC);
        CHECK_DEFENSE(SMASH);
        CHECK_DEFENSE(JUMP);
        CHECK_DEFENSE(COSMIC);
        CHECK_DEFENSE(BLAST);
        CHECK_DEFENSE(SHOCK);
        CHECK_DEFENSE(QUAKE);
        CHECK_DEFENSE(THROW);

        #undef CHECK_DEFENSE
    }

    // If no element flags were set, fall back to normal defense.
    if (minDefense == 255) {
        defense = lookup_defense(defenseTable, ELEMENT_NORMAL);
        if (defense < 255) {
            minDefense = defense;
        }
    }

    if (elementFlags & DAMAGE_TYPE_IGNORE_DEFENSE) {
        if (minDefense == 99) {
            // Immune
            minDefense = 999;
        } else if (minDefense > 0) {
            minDefense = 0;
        }
    }

    return minDefense;
}

// refresh the first (primary) damage popup
void show_primary_damage_popup(f32 posX, f32 posY, f32 posZ, s32 damageAmt, b32 angle) {
    s32 i;

    for (i = 0; i < 1; i++) {
        if (gDamageCountEffects[i] == NULL) {
            break;
        }
    }

    if (i > 0) {
        i = 0;
        gDamageCountEffects[i]->data.damageIndicator->timeLeft = 5;
        gDamageCountEffects[i] = NULL;
    }

    if (angle == 0) {
        angle = -55;
    } else {
        angle = 55;
    }

    fx_damage_indicator(0, posX, posY, posZ, 10.0f, angle, damageAmt, &gDamageCountEffects[i]);
    gDamageCountTimers[i] = 40;
}

// show another damage popup, if any are available
void show_next_damage_popup(f32 posX, f32 posY, f32 posZ, s32 damageAmt, b32 angle) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gDamageCountEffects); i++) {
        if (gDamageCountEffects[i] == NULL) {
            break;
        }
    }

    if (i > ARRAY_COUNT(gDamageCountEffects) - 1) {
        i = 0;
        gDamageCountEffects[i]->data.damageIndicator->timeLeft = 5;
        gDamageCountEffects[i] = NULL;
    }

    if (angle == 0) {
        angle = -55;
    } else {
        angle = 55;
    }

    fx_damage_indicator(0, posX, posY, posZ, 10.0f, angle, damageAmt, &gDamageCountEffects[i]);
    gDamageCountTimers[i] = 40;
}

void update_damage_popups(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gDamageCountEffects); i++) {
        if (gDamageCountEffects[i] != NULL) {
            gDamageCountTimers[i]--;
            if (gDamageCountTimers[i] == 0) {
                gDamageCountEffects[i]->data.damageIndicator->timeLeft = 5;
                gDamageCountEffects[i] = NULL;
            }
        }
    };
}

void show_damage_fx(Actor* actor, f32 x, f32 y, f32 z, s32 damage) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 intensity;

    if (damage < 3) {
        intensity = DAMAGE_INTENSITY_LIGHT;
    } else if (damage < 5) {
        intensity = DAMAGE_INTENSITY_MEDIUM;
    } else if (damage < 9) {
        intensity = DAMAGE_INTENSITY_HEAVY;
    } else {
        intensity = DAMAGE_INTENSITY_EXTREME;
    }

    do {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_FIRE) {
            fx_ring_blast(0, x, y, z, 1.0f, 24);
        } else if (battleStatus->curAttackElement & DAMAGE_TYPE_SHOCK) {
            apply_shock_effect(actor);
        } else if (battleStatus->curAttackElement & DAMAGE_TYPE_WATER) {
            fx_water_splash(0, x, y, z, 1.0f, 24);
        } else {
            fx_firework(0, x, y, z, 1.0, intensity);
        }
    } while (0); // required to match
}

// grossness
void show_action_rating(s32 rating, Actor* actor, f32 x, f32 y, f32 z) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player;
    s32 new_var; // TODO required to match
    s32 type;

    actor->attackResultEffect = actor->attackResultEffect; // TODO required to match
    player = battleStatus->playerActor;

    if (actor->attackResultEffect == NULL) {
        type = 0;
        switch (rating) {
            case ACTION_RATING_NICE:
                type = 0;
                actor->actionRatingCombo = 1;
                break;
            case ACTION_RATING_MISS:
                type = 4;
                actor->actionRatingCombo = 0;
                break;
            case ACTION_RATING_LUCKY:
                type = 3;
                actor->actionRatingCombo = 0;
                break;
            case ACTION_RATING_SUPER:
                type = 2;
                actor->actionRatingCombo = 2;
                break;
            case ACTION_RATING_NICE_NO_COMBO:
                type = 0;
                actor->actionRatingCombo = 0;
                break;
            case ACTION_RATING_NICE_SUPER_COMBO:
                type = player->actionRatingCombo;
                player->actionRatingCombo++;
                if (player->actionRatingCombo > 2) {
                    player->actionRatingCombo = 2;
                }
                break;
        }
        actor->attackResultEffect = fx_attack_result_text(type, x, y, z - 10.0f, 12.0f, 90);
        actor->actionRatingTime = 80;
        new_var = 2; // TODO required to match
    } else {
        actor->attackResultEffect->data.attackResultText->timeLeft = 0;
        type = actor->actionRatingCombo;
        new_var = rating; // TODO required to match
        switch (new_var) { // TODO required to match
            case ACTION_RATING_NICE:
                actor->actionRatingCombo++;
                if (actor->actionRatingCombo > 2) {
                    actor->actionRatingCombo = 2;
                }
                break;
            case ACTION_RATING_MISS:
                type = 4;
                break;
            case ACTION_RATING_LUCKY:
                type = 3;
                break;
            case ACTION_RATING_SUPER:
                type = 2;
                break;
            case ACTION_RATING_NICE_NO_COMBO:
                type = 0;
                break;
            case ACTION_RATING_NICE_SUPER_COMBO:
                type = player->actionRatingCombo;
                player->actionRatingCombo++;
                if (player->actionRatingCombo > 2) {
                    player->actionRatingCombo = 2;
                }
                break;
        }
        actor->attackResultEffect = fx_attack_result_text(type, x, y, z - 10.0f, 12.0f, 90);
        actor->actionRatingTime = 80;
    }
}

void func_80266970(Actor* target) {
    target->actionRatingCombo = 0;
}

void update_action_ratings(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        actor = gBattleStatus.enemyActors[i];
        if (actor != NULL) {
            if (actor->actionRatingTime == 60) {
                if (actor->attackResultEffect != NULL) {
                    actor->attackResultEffect->data.attackResultText->isVisible = FALSE;
                }
            }
            if (actor->actionRatingTime == 5) {
                if (actor->attackResultEffect != NULL) {
                    actor->attackResultEffect->data.attackResultText->timeLeft = 0;
                    actor->attackResultEffect = NULL;
                }
            }
            if (actor->actionRatingTime > 0) {
                actor->actionRatingTime--;
            }
        }
    }

    actor = battleStatus->playerActor;
    if (actor != NULL) {
        if (actor->actionRatingTime == 60) {
            if (actor->attackResultEffect != NULL) {
                actor->attackResultEffect->data.attackResultText->isVisible = FALSE;
            }
        }
        if (actor->actionRatingTime == 5) {
            if (actor->attackResultEffect != NULL) {
                actor->attackResultEffect->data.attackResultText->timeLeft = 0;
                actor->attackResultEffect = NULL;
            }
        }
        if (actor->actionRatingTime > 0) {
            actor->actionRatingTime--;
        }
    }

    actor = battleStatus->partnerActor;
    if (actor != NULL) {
        if (actor->actionRatingTime == 60) {
            if (actor->attackResultEffect != NULL) {
                actor->attackResultEffect->data.attackResultText->isVisible = FALSE;
            }
        }
        if (actor->actionRatingTime == 5) {
            if (actor->attackResultEffect != NULL) {
                actor->attackResultEffect->data.attackResultText->timeLeft = 0;
                actor->attackResultEffect = NULL;
            }
        }
        if (actor->actionRatingTime > 0) {
            actor->actionRatingTime--;
        }
    }
}

void show_actor_health_bar(Actor* target) {
    target->healthBarHideTime = -1;
    target->flags |= ACTOR_FLAG_HEALTH_BAR_HIDDEN;
}

void hide_actor_health_bar(Actor* target) {
    target->healthBarHideTime = 0;
    target->flags &= ~ACTOR_FLAG_HEALTH_BAR_HIDDEN;
}

void update_health_bars(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gBattleStatus.enemyActors); i++) {
        Actor* enemy = gBattleStatus.enemyActors[i];

        if (enemy != NULL) {
            if (enemy->healthBarHideTime > 0) {
                enemy->healthBarHideTime--;
                if (enemy->healthBarHideTime == 0) {
                    enemy->flags &= ~ACTOR_FLAG_HEALTH_BAR_HIDDEN;
                }
            }
        }
    }
}

// TODO dumb label required to match, clean up
s32 try_inflict_status(Actor* actor, s32 statusTypeKey, s32 statusKey) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 chance;
    s32 duration;

    if (battleStatus->statusChance == STATUS_KEY_IGNORE_RES) {
        duration = battleStatus->statusDuration;
        duration += lookup_status_duration_mod(actor->statusTable, statusKey);
        return inflict_status_set_duration(actor, statusTypeKey, statusKey, duration);
    }

    duration = 0;

    if (actor->statusTable != NULL) {
        if (!(battleStatus->curAttackStatus & STATUS_FLAG_RIGHT_ON)) {
            chance = lookup_status_chance(actor->statusTable, statusTypeKey);
        } else {
            if (lookup_status_chance(actor->statusTable, statusTypeKey) != 0) {
                chance = 100;
            } else {
                goto meow;
            }
        }

        if (chance > 0) {
            chance = (chance * battleStatus->statusChance) / 100;
            if (chance > 0 && chance >= rand_int(100)) {
                duration = 3;
                duration += lookup_status_duration_mod(actor->statusTable, statusKey);
            }
        }
    } else {
        duration = 3;
    }

meow:
    if (duration > 0) {
        if (battleStatus->curAttackStatus < 0) {
            duration = battleStatus->statusDuration;
            duration += lookup_status_duration_mod(actor->statusTable, statusKey);
            inflict_status(actor, statusTypeKey, duration);
        } else {
            inflict_status(actor, statusTypeKey, duration);

        }
    } else {
        duration = 0;
    }
    return duration;
}

s32 inflict_status_set_duration(Actor* actor, s32 statusTypeKey, s32 statusDurationKey, s32 duration) {
    s32 var0 = duration; // TODO required to match, look into
    s32 statusDuration = 0;

    if (actor->statusTable == NULL || lookup_status_chance(actor->statusTable, statusTypeKey) > 0) {
        statusDuration = var0;
    }

    if (statusDuration > 0) {
        return inflict_status(actor, statusTypeKey, statusDuration);
    } else {
        var0 = 0;
    }

    return 0;
}

void set_part_pal_adjustment(ActorPart* part, s32 palAdjust) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        if (decorationTable->paletteAdjustment != palAdjust) {
            decorationTable->paletteAdjustment = palAdjust;
            decorationTable->palAnimState = 0;
            decorationTable->resetPalAdjust = TRUE;
        }
    }
}

void set_actor_pal_adjustment(Actor* actor, s32 palAdjust) {
    ActorPart* partIt = &actor->partsTable[0];

    while (partIt != NULL) {
        if (!(partIt->flags & ACTOR_PART_FLAG_INVISIBLE)
            && (partIt->idleAnimations != NULL)
            && !(partIt->flags & ACTOR_PART_FLAG_2)
        ) {
            set_part_pal_adjustment(partIt, palAdjust);
        }
        partIt = partIt->nextPart;
    }
}

void clear_part_pal_adjustment(ActorPart* part) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        part->decorationTable->paletteAdjustment = PAL_ADJUST_NONE;
    }
}

// TODO: improve match
void func_80266E40(Actor* actor) {
    ActorPart* partIt = actor->partsTable;
    s8 e = PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS;
    s8 f = PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS;

    while (partIt != NULL) {
        DecorationTable* decorationTable = partIt->decorationTable;

        do {
            if (!(partIt->flags & (ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_INVISIBLE)) &&
                (partIt->idleAnimations != NULL) &&
                !(partIt->flags & ACTOR_PART_FLAG_2))
            {
                if (decorationTable->paletteAdjustment != e && decorationTable->paletteAdjustment != f) {
                    decorationTable->paletteAdjustment = PAL_ADJUST_NONE;
                }
            }
        } while (0); // required to match
        partIt = partIt->nextPart;
    }
}

void func_80266EA8(ActorPart* part, s32 arg1) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        if (decorationTable->unk_750 != arg1) {
            decorationTable->unk_750 = arg1;
            decorationTable->unk_752 = 0;
            decorationTable->unk_751 = 1;
        }
    }
}

void func_80266EE8(Actor* actor, s32 arg1) {
    ActorPart* partIt = &actor->partsTable[0];

    while (partIt != NULL) {
        if (!(partIt->flags & (ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_INVISIBLE)) &&
            (partIt->idleAnimations != NULL) &&
            !(partIt->flags & ACTOR_PART_FLAG_2))
        {
            func_80266EA8(partIt, arg1);
        }
        partIt = partIt->nextPart;
    }
}

void func_80266F60(ActorPart* part) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        part->decorationTable->unk_750 = 0;
    }
}

void func_80266F8C(Actor* actor) {
    ActorPart* actorPart = &actor->partsTable[0];

    while (actorPart != NULL) {
        DecorationTable* decorationTable = actorPart->decorationTable;

        do {
            if (!(actorPart->flags & (ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_INVISIBLE)) &&
                actorPart->idleAnimations != NULL &&
                !(actorPart->flags & ACTOR_PART_FLAG_2))
            {
                decorationTable->unk_750 = 0;
            }
        } while (0); // required to match
        actorPart = actorPart->nextPart;
    }
}

void func_80266FD8(ActorPart* part, s32 arg1) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        if (decorationTable->unk_764 != arg1) {
            decorationTable->unk_764 = arg1;
            decorationTable->unk_766 = 0;
            decorationTable->unk_765 = 1;
        }
    }
}

void func_80267018(Actor* actor, s32 arg1) {
    ActorPart* actorPart = &actor->partsTable[0];

    while (actorPart != NULL) {
        if (!(actorPart->flags & (ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) &&
            actorPart->decorationTable != NULL && !(actorPart->flags & ACTOR_PART_FLAG_2) &&
            actorPart->idleAnimations != NULL)
        {
            func_80266FD8(actorPart, arg1);
        }
        actorPart = actorPart->nextPart;
    }
}

void func_8026709C(ActorPart* part) {
    if (part->idleAnimations != NULL && !(part->flags & ACTOR_PART_FLAG_2)) {
        part->decorationTable->unk_764 = 0;
    }
}

void func_802670C8(Actor* actor) {
    ActorPart* partIt;

   for (partIt = actor->partsTable; partIt != NULL; partIt = partIt->nextPart) {
        DecorationTable* decorationTable = partIt->decorationTable;

        do {
            if (!(partIt->flags & (ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_INVISIBLE)) &&
                (partIt->idleAnimations != NULL) &&
                !(partIt->flags & ACTOR_PART_FLAG_2))
            {
                decorationTable->unk_764 = 0;
            }
        } while (0); // TODO make match better
    }
}

void add_part_decoration(ActorPart* part, s32 decorationIndex, s32 decorationType) {
    if ((part->idleAnimations) && !(part->flags & ACTOR_PART_FLAG_2)) {
        DecorationTable* decorationTable = part->decorationTable;

        _remove_part_decoration(part, decorationIndex);
        decorationTable->type[decorationIndex] = decorationType;
        decorationTable->changed[decorationIndex] = TRUE;
        decorationTable->state[decorationIndex] = 0;
        _add_part_decoration(part);
    }
}

void add_actor_decoration(Actor* actor, s32 decorationIndex, s32 decorationType) {
    ActorPart* part;
    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if (!(part->flags & (ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION))
            && part->idleAnimations
            && !(part->flags & ACTOR_PART_FLAG_2)
        ) {
            add_part_decoration(part, decorationIndex, decorationType);
        }
    }
}

void remove_part_decoration(ActorPart* part, s32 decorationIndex) {
    _remove_part_decoration(part, decorationIndex);
}

void remove_actor_decoration(Actor* actor, s32 decorationIndex) {
    ActorPart* part;

    for (part = actor->partsTable; part != NULL; part = part->nextPart) {
        if (!(part->flags & (ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION))
            && part->idleAnimations
            && !(part->flags & ACTOR_PART_FLAG_2)
        ) {
            remove_part_decoration(part, decorationIndex);
        }
    }
}

s32 player_team_is_ability_active(Actor* actor, s32 ability) {
    s32 actorClass = actor->actorID & ACTOR_CLASS_MASK;
    s32 hasAbility = FALSE;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            if (!(gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE)) {
                hasAbility = is_ability_active(ability);
            }
            break;
        case ACTOR_CLASS_PARTNER:
            hasAbility = is_partner_ability_active(ability);
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    return hasAbility;
}

void create_part_shadow(s32 actorID, s32 partID) {
    ActorPart* part = get_actor_part(get_actor(actorID), partID);

    part->flags &= ~ACTOR_PART_FLAG_4;
    part->shadowIndex = create_shadow_type(0, part->curPos.x, part->curPos.y, part->curPos.z);
    part->shadowScale = part->size.x / 24.0;
}

void remove_part_shadow(s32 actorID, s32 partID) {
    ActorPart* part = get_actor_part(get_actor(actorID), partID);

    part->flags |= ACTOR_PART_FLAG_4;
    delete_shadow(part->shadowIndex);
}

void create_part_shadow_by_ref(UNK_TYPE arg0, ActorPart* part) {
    part->flags &= ~ACTOR_PART_FLAG_4;
    part->shadowIndex = create_shadow_type(0, part->curPos.x, part->curPos.y, part->curPos.z);
    part->shadowScale = part->size.x / 24.0;
}

void remove_player_buffs(s32 buffs) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    ActorPart* playerActorParts = player->partsTable;

    if (buffs & PLAYER_BUFF_JUMP_CHARGE) {
        battleStatus->jumpCharge = 0;
        battleStatus->flags1 &= ~BS_FLAGS1_JUMP_CHARGED;
    }
    if (buffs & PLAYER_BUFF_HAMMER_CHARGE) {
        battleStatus->hammerCharge = 0;
        battleStatus->flags1 &= ~BS_FLAGS1_HAMMER_CHARGED;
    }
    if (buffs & PLAYER_BUFF_STONE) {
        player->stoneDuration = 0;
        player->stoneStatus = 0;
    }
    if (buffs & PLAYER_BUFF_HUSTLE) {
        battleStatus->hustleTurns = 0;
        battleStatus->flags1 &= ~BS_FLAGS1_HUSTLED;
    }
    if (buffs & PLAYER_BUFF_STATIC && (player->staticStatus != 0)) {
        player->staticDuration = 0;
        player->staticStatus = 0;
        remove_status_static(player->hudElementDataIndex);
    }
    if (buffs & PLAYER_BUFF_TRANSPARENT && (player->transparentStatus != 0)) {
        player->transparentDuration = 0;
        player->transparentStatus = 0;
        playerActorParts->flags &= ~ACTOR_PART_FLAG_100;
        remove_status_transparent(player->hudElementDataIndex);
    }
    if (buffs & PLAYER_BUFF_WATER_BLOCK && (battleStatus->waterBlockTurnsLeft != 0)) {
        battleStatus->waterBlockTurnsLeft = 0;
        battleStatus->buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_WATER_BLOCK].turnsLeft = 0;
        battleStatus->waterBlockEffect->flags |= FX_INSTANCE_FLAG_DISMISS;

        fx_water_block(1, player->curPos.x, player->curPos.y + 18.0f, player->curPos.z + 5.0f, 1.5f, 0xA);
        fx_water_splash(0, player->curPos.x - 10.0f, player->curPos.y + 5.0f, player->curPos.z + 5.0f, 1.0f, 0x18);
        fx_water_splash(0, player->curPos.x - 15.0f, player->curPos.y + 32.0f, player->curPos.z + 5.0f, 1.0f, 0x18);
        fx_water_splash(1, player->curPos.x + 15.0f, player->curPos.y + 22.0f, player->curPos.z + 5.0f, 1.0f, 0x18);

        battleStatus->waterBlockEffect = NULL;
        sfx_play_sound(SOUND_299);
    }
    if (buffs & PLAYER_BUFF_TURBO_CHARGE && (battleStatus->turboChargeTurnsLeft != 0)) {
        battleStatus->turboChargeTurnsLeft = 0;
        battleStatus->buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_TURBO_CHARGE].turnsLeft = 0;
    }
    if (buffs & PLAYER_BUFF_CLOUD_NINE && (battleStatus->cloudNineTurnsLeft != 0)) {
        battleStatus->cloudNineTurnsLeft = 0;
        battleStatus->buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_CLOUD_NINE].turnsLeft = 0;
        remove_effect(battleStatus->cloudNineEffect);
        battleStatus->cloudNineEffect = NULL;
    }

    if (partner != NULL && (buffs & PLAYER_BUFF_PARTNER_GLOWING)) {
        partner->isGlowing = FALSE;
        gBattleStatus.flags1 &= ~BS_FLAGS1_GOOMBARIO_CHARGED;
    }
}

void btl_update_ko_status(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 koDuration = player->koDuration;
    s32 i;

    player->koDuration = player->debuffDuration;
    if (player->koDuration > 0) {
        player->koStatus = STATUS_KEY_DAZE;
        player->disableEffect->data.disableX->koDuration = player->koDuration;

        if (koDuration == 0) {
            sfx_play_sound(SOUND_2107);
        }
    }

    if (partner != NULL) {
        if (partner->koDuration < partner->debuffDuration) {
            partner->koStatus = STATUS_KEY_DAZE;
            partner->koDuration = partner->debuffDuration;
        }

        if (partner->koDuration > 0) {
            partner->koStatus = STATUS_KEY_DAZE;
            partner->disableEffect->data.disableX->koDuration = partner->koDuration;
        }
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        Actor* enemy = battleStatus->enemyActors[i];

        if (enemy != NULL) {
            enemy->koDuration = enemy->debuffDuration;
            if (enemy->koDuration > 0) {
                enemy->koStatus = STATUS_KEY_DAZE;
                enemy->disableEffect->data.disableX->koDuration = enemy->koDuration;
            }
        }
    }
}

void btl_appendGfx_prim_quad(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 right, u16 bottom) {
    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, D_80293970);

    if (a == 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gMainGfxPos++, PM_CC_08, PM_CC_08);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMainGfxPos++, left, top, right, bottom);

    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
}

void btl_draw_prim_quad(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 arg6, u16 arg7) {
    u16 right = left + arg6;
    u16 bottom = top + arg7;

    btl_appendGfx_prim_quad(r, g, b, a, left, top, right, bottom);
}

void reset_all_actor_sounds(Actor* actor) {
    ActorPart* partIt = &actor->partsTable[0];

    actor->actorTypeData1[0] = bActorSoundTable[actor->actorType].walk[0];
    actor->actorTypeData1[1] = bActorSoundTable[actor->actorType].walk[1];
    actor->actorTypeData1[2] = bActorSoundTable[actor->actorType].fly[0];
    actor->actorTypeData1[3] = bActorSoundTable[actor->actorType].fly[1];
    actor->actorTypeData1[4] = bActorSoundTable[actor->actorType].jump;
    actor->actorTypeData1[5] = bActorSoundTable[actor->actorType].hurt;
    actor->actorTypeData1b[0] = bActorSoundTable[actor->actorType].delay[0];
    actor->actorTypeData1b[1] = bActorSoundTable[actor->actorType].delay[1];

    while (partIt != NULL) {
        partIt->partTypeData[0] = actor->actorTypeData1[0];
        partIt->partTypeData[1] = actor->actorTypeData1[1];
        partIt->partTypeData[2] = actor->actorTypeData1[2];
        partIt->partTypeData[3] = actor->actorTypeData1[3];
        partIt->partTypeData[4] = actor->actorTypeData1[4];
        partIt->partTypeData[5] = actor->actorTypeData1[5];
        partIt->actorTypeData2b[0] = actor->actorTypeData1b[0];
        partIt->actorTypeData2b[1] = actor->actorTypeData1b[1];
        partIt = partIt->nextPart;
    }
}

void hide_foreground_models_unchecked(void) {
    Stage* stage = gBattleStatus.curStage;

    if (stage != NULL && stage->foregroundModelList != NULL) {
        s32* idList = stage->foregroundModelList;
        while (*idList != STAGE_MODEL_LIST_END) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= MODEL_FLAG_HIDDEN;
            }
        }
    }
}

void show_foreground_models_unchecked(void) {
    Stage* stage = gBattleStatus.curStage;

    if (stage != NULL && stage->foregroundModelList != NULL) {
        s32* idList = stage->foregroundModelList;
        while (*idList != STAGE_MODEL_LIST_END) {
            s32 id = *idList++;
            if (id >= 0) {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~MODEL_FLAG_HIDDEN;
            }
        }
    }
}

void hide_foreground_models(void) {
    Stage* stage = gBattleStatus.curStage;

    if (stage != NULL && stage->foregroundModelList != NULL) {
        s32* idList = stage->foregroundModelList;
        while (*idList != STAGE_MODEL_LIST_END) {
            s32 id = *idList++;
            if (id < 0) {
                break;
            } else {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags |= MODEL_FLAG_HIDDEN;
            }

        }
    }
}

void show_foreground_models(void) {
    Stage* stage = gBattleStatus.curStage;

    if (stage != NULL && stage->foregroundModelList != NULL) {
        s32* idList = stage->foregroundModelList;
        while (*idList != STAGE_MODEL_LIST_END) {
            s32 id = *idList++;
            if (id < 0) {
                break;
            } else {
                Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(id));
                model->flags &= ~MODEL_FLAG_HIDDEN;
            }
        }
    }
}

#include "common/StartRumbleWithParams.inc.c"

EvtScript D_802939C4 = {
    EVT_CALL(N(StartRumbleWithParams), 256, 30)
    EVT_CALL(N(StartRumbleWithParams), 200, 15)
    EVT_CALL(N(StartRumbleWithParams), 50, 15)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293A10 = {
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293A34 = {
    EVT_CALL(N(StartRumbleWithParams), 150, 20)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293A58 = {
    EVT_CALL(N(StartRumbleWithParams), 200, 30)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293A7C = {
    EVT_CALL(N(StartRumbleWithParams), 256, 40)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293AA0 = {
    EVT_CALL(N(StartRumbleWithParams), 256, 60)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293AC4 = {
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293AE8 = {
    EVT_CALL(N(StartRumbleWithParams), 150, 20)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293B0C = {
    EVT_CALL(N(StartRumbleWithParams), 200, 30)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293B30 = {
    EVT_CALL(N(StartRumbleWithParams), 256, 40)
    EVT_RETURN
    EVT_END
};

EvtScript D_80293B54 = {
    EVT_CALL(N(StartRumbleWithParams), 256, 60)
    EVT_RETURN
    EVT_END
};

void start_rumble_type(u32 arg0) {
    if (D_802939C0 != 0) {
        kill_script_by_ID(D_802939C0);
    }

    switch (arg0) {
        case 0:
            break;
        case 1:
            D_802939C0 = start_script(&D_802939C4, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
        case 2:
            D_802939C0 = start_script(&D_80293A10, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
        case 3:
            D_802939C0 = start_script(&D_80293A34, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
        case 4:
            D_802939C0 = start_script(&D_80293A58, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
        case 5:
            D_802939C0 = start_script(&D_80293A7C, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
        case 6:
            D_802939C0 = start_script(&D_80293AA0, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            D_802939C0 = start_script(&D_80293AC4, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY)->id;
            break;
    }
}
