#include "flo_14.h"
#include "sprite/npc/bubulb.h"
#include "sprite/npc/bzzap.h"

enum {
    NPC_BUBULB,
    NPC_BZZAP,
};

BSS s32 N(D_802453B0_EF79C0)[91];

f32 N(D_802444C0_CCF7D0)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_802444D8) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .unk_10 = { .f = 30.0f },
    .unk_14 = 2,
    .chaseSpeed = 4.5f,
    .unk_1C = { .s = 6 },
    .unk_20 = 1,
    .chaseRadius = 90.0f,
    .unk_28 = { .f = 30.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_80244508) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -630);
    SetSelfVar(6, 50);
    SetSelfVar(1, 200);
    N(func_80241E1C_CCD12C)(N(npcAISettings_802444D8));
});

NpcSettings N(npcSettings_80244578) = {
    .height = 26,
    .radius = 24,
    .ai = &N(npcAI_80244508),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 19,
};

NpcSettings N(npcSettings_802445A4) = {
    .height = 56,
    .radius = 40,
    .level = 99,
};

NpcSettings N(npcSettings_802445D0) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

s32 N(D_802445FC_CCF90C) = {
    0x00000000,
};

s32 N(D_80244600_CCF910) = {
    0x00000000,
};

EvtSource N(80244604) = SCRIPT({
    SI_VAR(9) = SI_VAR(1);
    ShowConsumableChoicePopup();
    SI_VAR(10) = SI_VAR(0);
    match SI_VAR(0) {
        == 0 {}
        == -1 {}
        else {
            RemoveItemAt(SI_VAR(1));
            GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            N(AddPlayerHandsOffset)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
            MakeItemEntity(SI_VAR(0), SI_VAR(3), SI_VAR(4), SI_VAR(5), 1, 0);
            SetPlayerAnimation(0x60005);
            sleep 30;
            SetPlayerAnimation(ANIM_10002);
            RemoveItemEntity(SI_VAR(0));
        }
    }
    N(func_80242288_CCD598)(SI_VAR(10));
    CloseChoicePopup();
    unbind;
});

EvtSource N(80244738) = SCRIPT({
    N(func_802422C0_CCD5D0)(SI_VAR(0));
    bind_padlock N(80244604) 0x10 0 N(D_802453B0_EF79C0);
    N(func_80242234_CCD544)(SI_VAR(0));
});


s32 N(D_80244788_CCFA98)[] = {
    0x000000A1, 0x00000000,
};

EvtSource N(interact_80244790) = SCRIPT({
    if (SI_AREA_FLAG(37) == 1) {
        SI_AREA_FLAG(35) = 1;
        SpeakToPlayer(NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0063));
        SI_AREA_FLAG(35) = 0;
        return;
    }
    SI_AREA_FLAG(35) = 1;
    if (SI_SAVE_FLAG(1412) == 0) {
        SpeakToPlayer(NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x005F));
    } else {
        SpeakToPlayer(NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0060));
    }
    FindItem(161, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        SI_VAR(0) = N(D_80244788_CCFA98);
        SI_VAR(1) = 0;
        await N(80244738);
        if (SI_VAR(0) == -1) {
            SpeakToPlayer(NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0064));
        } else {
            SpeakToPlayer(NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0061));
            SI_AREA_FLAG(36) = 1;
            SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), TRUE);
            PlayerMoveTo(555, 110, 20);
            SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100)), FALSE);
            InterpPlayerYaw(90, 0);
            func_802CF56C(2);
            sleep 5;
            AdjustCam(0, 1.0, 0, 350, 17.0, -6.0);
            spawn N(80243870);
            SpeakToPlayer(NPC_SELF, -1, -1, 0, MESSAGE_ID(0x11, 0x0062));
            spawn {
                sleep 40;
                InterpPlayerYaw(315, 0);
            }
10:
            if (SI_AREA_FLAG(37) == 0) {
                sleep 1;
                goto 10;
            }
            ResetCam(0, 4.0);
            SpeakToPlayer(NPC_SELF, -1, -1, 5, MESSAGE_ID(0x11, 0x0063));
            SI_SAVE_FLAG(1412) = 1;
            bind N(8024352C) TRIGGER_FLOOR_PRESS_A 30;
        }
    }
    SI_AREA_FLAG(35) = 0;
});

EvtSource N(init_80244ADC) = SCRIPT({
    SI_AREA_FLAG(36) = 0;
    SI_AREA_FLAG(37) = 0;
    BindNpcInteract(NPC_SELF, N(interact_80244790));
});

StaticNpc N(npcGroup_80244B20) = {
    .id = NPC_BUBULB,
    .settings = &N(npcSettings_802445A4),
    .pos = { 617.0f, 0.0f, 108.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_4000,
    .init = &N(init_80244ADC),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_E,
        NPC_ANIM_bubulb_Palette_00_Anim_E,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
        NPC_ANIM_bubulb_Palette_00_Anim_2,
    },
    .tattle = MESSAGE_ID(0x1A, 0x00E3),
};

StaticNpc N(npcGroup_80244D10) = {
    .id = NPC_BZZAP,
    .settings = &N(npcSettings_80244578),
    .pos = { -175.0f, 55.0f, 15.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 15,
    .itemDrops = {
        { ITEM_MAPLE_SYRUP, 6, 0 },
        { ITEM_HONEY_SYRUP, 4, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 1,
    .maxCoinBonus = 4,
    .movement = { -175, 55, 15, 30, 0, -32767, 0, -175, 55, 15, 200, 0, 0, 1 },
    .animations = {
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_3,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_6,
        NPC_ANIM_bzzap_Palette_00_Anim_4,
        NPC_ANIM_bzzap_Palette_00_Anim_2,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
        NPC_ANIM_bzzap_Palette_00_Anim_1,
    },
    .unk_1E0 = { 00, 00, 00, 03, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80244F00) = {
    NPC_GROUP(N(npcGroup_80244B20), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80244D10), BATTLE_ID(24, 25, 0, 1)),
    {},
};

static s32 N(pad_4F24)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80244F30) = SCRIPT({
    MakeItemEntity(ITEM_STAR_PIECE, 675, 60, -100, 17, SI_SAVE_FLAG(1387));
});

static s32 N(pad_4F64)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80244F70) = SCRIPT({
    loop {
        N(func_80242360_CCD670)(SI_VAR(0));
        if (SI_VAR(0) == SI_VAR(4)) {
            GetPlayerActionState(SI_VAR(0));
            if (SI_VAR(0) != 23) {
                if (SI_VAR(8) == 0) {
                    spawn {
                        GetModelCenter(SI_VAR(5));
                        PlaySoundAt(0x1DB, 4194304, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                    }
                }
                if (SI_VAR(7) < 90) {
                    if (SI_VAR(7) == 0) {
                        sleep 5;
                        SI_VAR(8) = 6;
                        ModifyColliderFlags(0, SI_VAR(9), 0x7FFFFE00);
                    }
                    SI_VAR(8) += 1;
                    SI_VAR(7) += SI_VAR(8);
                }
                goto 50;
            }
        }
        if (SI_VAR(7) != 0) {
            SI_VAR(8) -= 1;
            SI_VAR(7) += SI_VAR(8);
            if (SI_VAR(7) <= 0) {
                SI_VAR(8) = 0;
                SI_VAR(7) = 0;
                spawn {
                    GetModelCenter(SI_VAR(5));
                    PlaySoundAt(0x1DC, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
                }
                ModifyColliderFlags(1, SI_VAR(9), 0x7FFFFE00);
            }
        }
50:
        if (SI_VAR(7) >= 90) {
            SI_VAR(8) = -1;
            SI_VAR(7) = 90;
        }
        RotateModel(SI_VAR(5), SI_VAR(7), -1, 0, 0);
        RotateModel(SI_VAR(6), SI_VAR(7), -1, 0, 0);
        sleep 1;
    }
});

EvtSource N(80245224) = SCRIPT({
    SI_VAR(4) = 21;
    SI_VAR(5) = 21;
    SI_VAR(6) = 20;
    SI_VAR(7) = SI_MAP_VAR(10);
    SI_VAR(8) = SI_MAP_VAR(11);
    SI_VAR(9) = 22;
    spawn N(80244F70);
    SI_VAR(4) = 17;
    SI_VAR(5) = 26;
    SI_VAR(6) = 25;
    SI_VAR(7) = SI_MAP_VAR(12);
    SI_VAR(8) = SI_MAP_VAR(13);
    SI_VAR(9) = 18;
    spawn N(80244F70);
});

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_MATCHING
// second npc_raycast_down_sides call
void N(func_80240CC0_CCBFD0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f24;
    f32 posX, posY, posZ, posW;
    s32 var;
    f32 temp_f0;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_s4 = 0;

    f32 a = enemy->varTable[7];
    f32 temp_f2  = a / 100.0;
    f32 b = enemy->varTable[3];
    f32 temp_f26 = b / 100.0;
    f32 c = enemy->varTable[4];
    f32 temp_f20 = c / 100.0;
    f32 d = enemy->varTable[1];
    f32 temp_f22 = d / 100.0;

    enemy->varTable[4] = npc->pos.y * 100.0;
    temp_f24 = temp_f26 + temp_f2;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (temp_f22 < (temp_f24 - npc->pos.y)) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        // original m2c reference:
        //if ((temp_s0->flags & 8) != 0) {
        //    phi_f0 = temp_f20 + ((temp_f24 - temp_f20) * D_802441A8_CB91A8);
        //    phi_f4 = temp_f24;
        //} else {
        //    npc_raycast_down_sides(temp_s0->unk_80, &subroutine_argA, &subroutine_argB, &subroutine_argC, &subroutine_argD, temp_s0->pos.x, temp_f20, temp_s0->pos.z, 1000.0f);
        //    temp_f4 = subroutine_argB + temp_f26;
        //    phi_f0 = temp_f20 + ((temp_f4 - temp_f20) * D_802441B0_CB91B0);
        //    phi_f4 = temp_f4;
        //}
        //temp_s0->pos.y = phi_f0;

        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY + temp_f26;
            npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }

        if (fabsf(phi_f4 - npc->pos.y) < 1.0) {
            npc->pos.y = phi_f4;
            enemy->varTable[0] &= ~0x10;
        }
    } else if (enemy->varTable[1] > 0) {
        temp_f0 = sin_deg(enemy->varTable[2]);
        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        }
        if (phi_v0) {
            npc->pos.y = posY + temp_f26 + (temp_f0 * temp_f22);
        } else {
            npc->pos.y = temp_f24 + (temp_f0 * temp_f22);
        }
        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0] = 10;
                    } else {
                        script->functionTemp[0] = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1]--;
        }
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
                               enemy->territory->wander.point.x, enemy->territory->wander.point.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            phi_s4 = 1;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | phi_s4) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            return;
        }
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0] = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1] < 3)) {
                script->functionTemp[0] = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_flo/flo_14/CCBE20", flo_14_func_80240CC0_CCBFD0, Evt* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80241764_CCCA74)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802444C0_CCF7D0)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_80241E1C_CCD12C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240CC0_CCBFD0)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241764_CCCA74)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

ApiStatus N(func_80242234_CCD544)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802445FC_CCF90C) = FALSE;
    }

    if (N(D_802445FC_CCF90C)) {
        N(D_802445FC_CCF90C) = FALSE;
        set_variable(script, *args, N(D_80244600_CCF910));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_80242288_CCD598)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80244600_CCF910) = get_variable(script, *args);
    N(D_802445FC_CCF90C) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus N(func_802422C0_CCD5D0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802453B0_EF79C0)[i] = ptr[i];
        }
        N(D_802453B0_EF79C0)[i] = 0;
    } else {
        for (i = 0; i <= 90; i++) {
            N(D_802453B0_EF79C0)[i] = i + 128;
            N(D_802453B0_EF79C0)[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}
