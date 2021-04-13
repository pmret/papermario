#include "dgb_04.h"
#include "sprite/npc/sentinel.h"
#include "message_ids.h"

extern s32 D_800F7F00[];
extern s32 D_800F7F40[];
extern s32 D_8008EF20[11][4];

enum {
    NPC_SENTINEL,
};

EntryList N(entryList) = {
    { 575.0f,    0.0f, 180.0f, 270.0f },
    { 575.0f, -420.0f, 180.0f, 270.0f },
};

MapConfig N(config) = {
    .main = N(main),
    .entryList = N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = MSG_dgb_04_tattle,
};

Script N(80243170) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        }
        else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
});

static s32 N(pad_3208)[] = {
    0x00000000, 0x00000000,
};

Script N(exitSingleDoor_80243210) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(0);
    SI_VAR(0) = 0;
    SI_VAR(1) = 16;
    SI_VAR(2) = 16;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("dgb_06", 0);
    sleep 100;
});

Script N(exitDoubleDoor_802432C4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 20;
    SI_VAR(2) = 13;
    SI_VAR(3) = 11;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_03", 0);
    sleep 100;
});

Script N(enterSingleDoor_80243378) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            UseDoorSounds(3);
            SI_VAR(2) = 13;
            SI_VAR(3) = 11;
            await EnterDoubleDoor;
        }
        == 1 {
            UseDoorSounds(0);
            SI_VAR(2) = 16;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_TUBBAS_MANOR;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    if (STORY_PROGRESS < STORY_CH3_STAR_SPIRIT_RESCUED) {
        MakeNpcs(1, N(npcGroupList_80243D18));
    }
    await N(makeEntities);
    bind N(exitSingleDoor_80243210) to TRIGGER_WALL_PRESS_A 16;
    bind N(exitDoubleDoor_802432C4) to TRIGGER_WALL_PRESS_A 20;
    spawn N(80243170);
    spawn N(enterSingleDoor_80243378);
});

static s32 N(pad_3558)[] = {
    0x00000000, 0x00000000,
};

f32 N(D_80243560_C39A90)[] = {
     4.5f, 3.5f, 2.6f, 2.0f,
     1.5f, 20.0f,
};

Script N(80243578) = SCRIPT({
    SetSelfEnemyFlagBits(((0x00100000 | 0x01000000 | 0x02000000 | 0x04000000 | 0x08000000 | 0x10000000 | 0x20000000)), TRUE);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT)), TRUE);
});

NpcAISettings N(npcAISettings_802435B4) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .unk_14 = 1,
    .chaseSpeed = 5.3f,
    .unk_1C = { .s = 180 },
    .unk_20 = 1,
    .chaseRadius = 240.0f,
    .unk_2C = 1,
};

const char N(dgb_00_name_hack)[];

Script N(npcAI_802435E4) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -650);
    SetSelfVar(6, 30);
    SetSelfVar(1, 600);
    N(func_80242154_C38684)(N(npcAISettings_802435B4));
    DisablePlayerInput(TRUE);
    sleep 2;
20:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetNpcPos(NPC_SELF, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(4), SI_VAR(2));
    GetPlayerActionState(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        sleep 1;
        goto 20;
    }
    DisablePlayerPhysics(TRUE);
    func_802D2B6C();
    DisablePartnerAI(0);
    group 0;
    func_802D5830(1);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    SI_VAR(2) += 2;
    SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80045838(-1, 759, 0);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(sentinel, Palette_00, Anim_8));
    sleep 10;
    SetPlayerAnimation(ANIM_80017);
    sleep 10;
    func_80045838(-1, 1838, 0);
    spawn {
        loop 100 {
            GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(1) += 1;
            SetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
    }
    spawn {
        SetNpcAnimation(NPC_PARTNER, 0x108);
        GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        NpcJump0(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        NpcJump0(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        NpcJump0(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        NpcJump0(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    }
    sleep 30;
    GotoMap(N(dgb_00_name_hack), 2);
    sleep 100;
});

Script N(80243A0C) = SCRIPT({
    GetOwnerEncounterTrigger(SI_VAR(0));
    match SI_VAR(0) {
        == 1, 2, 4, 6 {
            GetSelfAnimationFromTable(7, SI_VAR(0));
            await 0x800936DC;
        }
    }
});

Script N(80243A98) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            DoNpcDefeat();
        }
        == 1 {}
        == 2 {
        }
    }
});

NpcSettings N(npcSettings_80243AFC) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80243578),
    .ai = &N(npcAI_802435E4),
    .level = 99,
};

StaticNpc N(npcGroup_80243B28) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_80243AFC),
    .pos = { 70.0f, -220.0f, 186.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 70, -220, 186, 15, 40, -32767, 1, 80, -220, 170, 80, 150, 1 },
    .animations = {
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_2),
        NPC_ANIM(sentinel, Palette_00, Anim_3),
        NPC_ANIM(sentinel, Palette_00, Anim_3),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_5),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_8),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
        NPC_ANIM(sentinel, Palette_00, Anim_1),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80243D18) = {
    NPC_GROUP(N(npcGroup_80243B28), BATTLE_ID(0, 0, 0, 0)),
    {},
};

s32 N(D_80243D30_C3A260)[] = {
    0x001D00F0, 0x001D00F1,
};

s16 N(D_80243D38_C3A268)[] = {
    0x0001, 0x0002, 0x0003, 0x0004,
    0x0009, 0x0006, 0x0007, 0x0008
};

s32 N(D_80243D48_C3A278)[8][2] = {
    {0x001D00E0, 0x001D00E1 }, {0x001D00E2, 0x001D00E3 },
    {0x001D00E4, 0x001D00E5 }, {0x001D00E6, 0x001D00E7 },
    {0x001D00E8, 0x001D00E9 }, {0x001D00EA, 0x001D00EB },
    {0x001D00EC, 0x001D00ED }, {0x001D00EE, 0x001D00EF }
};

f32 N(D_80243D88_C3A2B8)[] = {
    140.0f, 180.0f, 220.0f
};

Script N(80243D94) = SCRIPT({
    sleep 10;
    PlaySound(0x212D);
    N(func_80242914_C38E44)(SI_MAP_VAR(0));
    sleep 85;
    spawn {
        PlaySound(0x212E);
        N(func_80242F08_C39438)(70, 70);
        sleep 27;
        PlaySound(SOUND_UNKNOWN_208E);
        N(func_80242F08_C39438)(50, 50);
    }
    spawn {
        sleep 3;
        N(func_8024240C_C3893C)(SI_MAP_VAR(0));
    }
    spawn {
        sleep 47;
        N(func_80242978_C38EA8)();
        N(UnkPartnerPosFunc)();
        sleep 5;
        N(UnkPartnerPosFunc2)();
        sleep 5;
        N(UnkPartnerPosFunc)();
    }
    sleep 3;
    N(func_802429D0_C38F00)(SI_MAP_VAR(0));
    sleep 30;
});

Script N(80243EF8) = SCRIPT({
    if (SI_SAVE_FLAG(1046) == 1) {
        return;
    }
    IsStartingConversation(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        return;
    }
    N(func_802430D8_C39608)();
    if (SI_VAR(0) == 1) {
        return;
    }
    func_802D585C(1, 2097152);
    N(SetOverrideFlags_40)();
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    N(func_80242850_C38D80)(SI_MAP_VAR(0), SI_VAR(9));
    FindKeyItem(15, SI_VAR(12));
    N(func_802424F0_C38A20)();
    if (SI_VAR(0) == -1) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DC), 160, 40);
        sleep 10;
        N(func_802428E0_C38E10)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        func_802D585C(0, 2097152);
        N(func_802423EC_C3891C)();
        return;
    }
    if (SI_SAVE_FLAG(438) == 0) {
        SI_SAVE_FLAG(438) = 1;
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DA), 160, 40);
    } else {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DB), 160, 40);
    }
    N(func_8024259C_C38ACC)();
    if (SI_VAR(0) == -1) {
        N(func_802428E0_C38E10)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        func_802D585C(0, 2097152);
        N(func_802423EC_C3891C)();
        return;
    }
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    EnablePartnerAI();
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != SI_VAR(11)) {
        N(func_802427EC_C38D1C)(SI_VAR(11));
    } else {
        func_802CF56C(2);
    }
    sleep 10;
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DF), 160, 40);
    ShowChoice(1966093);
    CloseMessage();
    if (SI_VAR(0) != 0) {
        N(func_802428E0_C38E10)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        func_802D585C(0, 2097152);
        N(func_802423EC_C3891C)();
        return;
    }
    await N(80243D94);
    N(func_80242438_C38968)(SI_VAR(11), SI_VAR(13));
    SI_SAVE_FLAG(1046) = 1;
    N(func_802428E0_C38E10)(SI_VAR(9));
    N(func_80242818_C38D48)();
    if (SI_VAR(13) == 1) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DD), 160, 40);
    } else {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DE), 160, 40);
    }
    DisablePlayerInput(FALSE);
    EnablePartnerAI();
    func_802D585C(0, 2097152);
    N(func_802423EC_C3891C)();
});

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA910, 500, -360, 110, 0, MAKE_ENTITY_END);
    SI_MAP_VAR(0) = SI_VAR(0);
    AssignBlockFlag(SI_SAVE_FLAG(1046));
    AssignScript(N(80243EF8));
});

void N(func_80240000_C36530)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.point.x, enemy->territory->wander.point.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}

#ifdef NON_MATCHING
// second func_800DCB7C call
void N(func_802401B0_C366E0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            test = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            npc->pos.y = test;
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY;
            phi_f4 += temp_f26;
            d = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            test = d;
            npc->pos.y = test;
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }
        //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);

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
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
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
            if (script->functionTemp[1].s <= 0) {
                script->functionTemp[1].s = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    func_800494C0(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0].s = 10;
                    } else {
                        script->functionTemp[0].s = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1].s--;
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
            script->functionTemp[0].s = 2;
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1].s < 3)) {
                script->functionTemp[0].s = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_dgb/dgb_04/C36530", dgb_04_func_802401B0_C366E0, ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

void N(func_80240898_C36DC8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f24 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f26 = temp_f24 + (f32)((f32)enemy->varTable[7] / 100.0);
    s32 var;

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (enemy->varTable[1] > 0) {
        f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
        f32 sin_degrees = sin_deg(enemy->varTable[2]);
        s32 phi_v0;

        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        }

        if (phi_v0) {
            npc->pos.y = posY + temp_f24 + (sin_degrees * temp_f22);
        } else {
            npc->pos.y = temp_f26 + (sin_degrees * temp_f22);
        }

        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) && func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            npc->moveToPos.y = npc->pos.y;
            func_800494C0(npc, 0x2F4, 0x200000);
            if (enemy->npcSettings->unk_2A & 1) {
                script->functionTemp[0].s = 10;
            } else {
                script->functionTemp[0].s = 12;
            }
            return;
        }
    } else {
        enemy->varTable[9]--;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s > 0) {
            if (!(enemy->npcSettings->unk_2A & 0x10)) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
            }
            npc->duration = (rand_int(1000) % 11) + 5;
        } else {
            script->functionTemp[0].s = 0;
        }
    }
}

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240C54_C37184)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80243560_C39A90)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

void N(func_80240E58_C37388)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    s32 phi_v0;
    f32 phi_f20;
    f32 a = enemy->varTable[3];
    f32 b = enemy->varTable[7];

    npc->jumpVelocity += npc->jumpScale;
    temp_f20 = a / 100.0;
    temp_f22 = b / 100.0;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->jumpVelocity >= 0.0) {
        npc->pos.y += npc->jumpVelocity;
        npc->currentAnim = enemy->animList[9];
        enemy->unk_07 = 0;
        if (!(npc->flags & 8)) {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        } else {
            phi_v0 = FALSE;
        }
        if (phi_v0) {
            temp_f2 = posY + temp_f20;
            if (temp_f2 <= npc->pos.y) {
                npc->pos.y = temp_f2;
                script->functionTemp[0].s = 0;
            }
        } else if (npc->pos.y >= npc->moveToPos.y) {
            script->functionTemp[0].s = 0;
        }
    } else if (npc->jumpVelocity < 0.0) {
        npc->duration++;
        if (npc->duration >= aiSettings->unk_20) {
            npc->duration = 0;
            phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            temp_f0_2 = get_clamped_angle_diff(npc->yaw, phi_f20);
            if (aiSettings->unk_1C.s < fabsf(temp_f0_2)) {
                phi_f20 = npc->yaw;
                if (temp_f0_2 < 0.0f) {
                    phi_f20 += -aiSettings->unk_1C.s;
                } else {
                    phi_f20 += aiSettings->unk_1C.s;
                }
            }
            npc->yaw = clamp_angle(phi_f20);
        }

        if (npc->flags & 8) {
            if (npc->pos.y + npc->jumpVelocity < temp_f22) {
                npc->pos.y = temp_f22;
                npc->jumpVelocity = 0.0f;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = (fabsf(npc->jumpVelocity) + npc->collisionHeight) + 10.0;
        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            if (posW <= (npc->collisionHeight + fabsf(npc->jumpVelocity))) {
                npc->jumpVelocity = 0.0f;
                npc->pos.y = posY;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        } else if (fabsf(npc->jumpVelocity) < ((npc->pos.y - temp_f22) + npc->collisionHeight)) {
            npc->pos.y = npc->pos.y + npc->jumpVelocity;
            return;
        }
        npc->jumpVelocity = 0.0f;
    }
}

void N(func_802411E8_C37718)(Npc *npc, Enemy *enemy, ScriptInstance *script, NpcAISettings *aiSettings) {
    f32 posX, posY, posZ, posW;
    s32 temp_a1;
    s32 temp_v1;
    s32 phi_v0;

    script->functionTemp[0].s = 0;
    npc->duration = 0;
    temp_v1 = npc->flags & ~0x200;
    npc->flags = (npc->flags & ~0x200) | 0x800;
    if (enemy->territory->wander.isFlying) {
        npc->flags = temp_v1 | 0x808;
    } else {
        npc->flags = npc->flags & ~8;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    enemy->varTable[2] = 0;
    enemy->varTable[9] = 0;
    enemy->varTable[3] = ((posW * 100.0) + 0.5);
    enemy->varTable[7] = ((posY * 100.0) + 0.5);
    script->functionTemp[1].s = aiSettings->unk_14;
    enemy->unk_B0 |= 0x10;
}

ApiStatus N(func_8024130C_C3783C)(ScriptInstance *script, s32 isInitialCall) {
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
    territory.unk_34 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_802411E8_C37718)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_C36530)(script, aiSettings, territoryPtr);
        case 1:
            N(func_802401B0_C366E0)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80240898_C36DC8)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240C54_C37184)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80240E58_C37388)(script, aiSettings, territoryPtr);
    }

    return ApiStatus_BLOCK;
}

void N(func_802414F8_C37A28)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f0;
    f32 phi_f20;

    npc->duration--;
    if (npc->duration <= 0) {
        npc->flags &= 0xFFDFFFFF;
        npc->duration = aiSettings->unk_20 / 2 + rand_int(aiSettings->unk_20 / 2 + 1);
        npc->currentAnim = enemy->animList[8];
        npc->moveSpeed = aiSettings->chaseSpeed;
        phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        temp_f0 = get_clamped_angle_diff(npc->yaw, phi_f20);
        if (aiSettings->unk_1C.s < fabsf(temp_f0)) {
            phi_f20 = npc->yaw;
            if (temp_f0 < 0.0f) {
                phi_f20 += -aiSettings->unk_1C.s;
            } else {
                phi_f20 += aiSettings->unk_1C.s;
            }
        }
        npc->yaw = clamp_angle(phi_f20);
        script->functionTemp[0].s = 13;
    }
}

void N(func_80241650_C37B80)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) <= (npc->moveSpeed * 2.5)) {
            npc->duration = 0;
            script->functionTemp[0].s = 14;
        } else {
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags |= 0x200000;
                script->functionTemp[0].s = 12;
            }
        }
    } else {
        script->functionTemp[0].s = 16;
    }

}

void N(func_80241754_C37C84)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    do { enemy->varTable[0] |= 0x100; npc->pos.x = gPlayerStatusPtr->position.x; } while (0);
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & 0x1000)) {
        enemy->varTable[0] |= 0x1000;
    }
    sfx_play_sound_at_position(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->functionTemp[0].s = 15;
}

void N(func_802417F8_C37D28)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    s32 temp_f8_2;

    sfx_adjust_env_sound_pos(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    if (!func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        enemy->varTable[0] &= ~0x100;
        npc->rotation.y = 0.0f;
        npc->flags &= 0xFFDFFFFF;
        script->functionTemp[0].s = 16;
    } else {
        PlayerStatus** playerStatus = &gPlayerStatusPtr;

        npc->pos.x = (*playerStatus)->position.x;
        npc->pos.z = (*playerStatus)->position.z + 2.0f;
        npc->rotation.y += 25.0f;
        if (npc->rotation.y > 360.0) {
            npc->rotation.y -= 360.0;
        }
        temp_f8_2 = 255.0f - (cosine((s32)npc->rotation.y % 180) * 56.0f);
        func_802DE894(npc->spriteInstanceID, 6, temp_f8_2, temp_f8_2, temp_f8_2, 255, 0);

        posX = (*playerStatus)->position.x;
        posY = (*playerStatus)->position.y;
        posZ = (*playerStatus)->position.z;
        posW = 1000.0f;
        func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        if (fabsf(npc->pos.y - posY) > 24.0) {
            npc->pos.y -= 1.8;
        } else {
            npc->rotation.y = 0.0f;
            npc->flags &= 0xFFDFFFFF;
            if (D_8010EBB0.unk_03 != 9) {
                disable_player_input();
                func_800EF628();
                npc->duration = 0;
                script->functionTemp[0].s = 20;
            } else {
                script->functionTemp[0].s = 16;
            }
        }
    }
}

void N(func_80241A94_C37FC4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    if (enemy->varTable[0] & 0x1000) {
        sfx_stop_sound(0x80000011);
        enemy->varTable[0] &= ~0x1000;
    }
    npc->currentAnim = enemy->animList[9];
    npc->duration = 20;
    script->functionTemp[0].s = 17;
}

void N(func_80241B4C_C3807C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 tmp = enemy->varTable[3];
    f32 temp_f20 = tmp / 100.0;
    s32 var;

    npc->pos.y += 2.5;
    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    if (!(npc->pos.y < (posY + temp_f20))) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc->pos.y = posY + temp_f20;
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &var);
        npc->duration = 10;
        script->functionTemp[0].s = 18;
    }
}

void N(func_80241CCC_C381FC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0].s = 30;
    }
}

void N(func_80241D14_C38244)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration >= 3) {
        if (D_8010EBB0.unk_03 != 9) {
            npc->duration = 0;
            script->functionTemp[0].s = 100;
        } else {
            enable_player_input();
            func_800EF600();
            script->functionTemp[0].s = 16;
        }
    }
}

void N(func_80241D94_C382C4)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    npc->flags &= 0xFFDFFFFF;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1].s = 0x1E;
}

void N(func_80241E3C_C3836C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX = npc->pos.x;
    f32 posY = npc->pos.y;
    f32 posZ = npc->pos.z;
    f32 posW = 1000.0f;
    f32 temp_f26 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f24 = temp_f26 + (f32)((f32)enemy->varTable[7] / 100.0);
    f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
    f32 temp_f20 = sin_deg(enemy->varTable[2]);
    s32 var;
    s32 var2;

    if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
        npc->pos.y = posY + temp_f26 + (temp_f20 * temp_f22);
    } else {
        npc->pos.y = temp_f24 + (temp_f20 * temp_f22);
    }

    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (script->functionTemp[1].s <= 0) {
        script->functionTemp[1].s = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.5, aiSettings->unk_10.f * 0.5, 0)) {
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            func_800494C0(npc, 0x2F4, 0x200000);
            npc->moveToPos.y = npc->pos.y;
            script->functionTemp[0].s = 12;
            return;
        }
    }

    script->functionTemp[1].s--;
    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        posW = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        if (posW <= (2.0f * npc->moveSpeed)) {
            script->functionTemp[1].s = (rand_int(1000) % 3) + 2;
            script->functionTemp[0].s = 2;
        }
    }
}

ApiStatus N(func_80242154_C38684)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_34 = 125.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        N(func_802411E8_C37718)(npc, enemy, script, aiSettings);
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_C36530)(script, aiSettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
        case 1:
            N(func_802401B0_C366E0)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s == 12) {
                npc->duration = 6;
            }
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80240898_C36DC8)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s == 12) {
                npc->duration = 6;
            }
            break;
        case 12:
            N(func_802414F8_C37A28)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 13) {
                break;
            }
        case 13:
            N(func_80241650_C37B80)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241754_C37C84)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0].s != 15) {
                break;
            }
        case 15:
            N(func_802417F8_C37D28)(script, aiSettings, territoryPtr);
            break;
        case 16:
            N(func_80241A94_C37FC4)(script, aiSettings, territoryPtr);
        case 17:
            N(func_80241B4C_C3807C)(script, aiSettings, territoryPtr);
            break;
        case 18:
            N(func_80241CCC_C381FC)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(func_80241D14_C38244)(script, aiSettings, territoryPtr);
            break;
        case 30:
            N(func_80241D94_C382C4)(script, aiSettings, territoryPtr);
        case 31:
            N(func_80241E3C_C3836C)(script, aiSettings, territoryPtr);
    }

    return (script->functionTemp[0].s == 100) * ApiStatus_DONE2;
}

#include "world/common/SetOverrideFlags_40.inc.c"

ApiStatus N(func_802423EC_C3891C)(ScriptInstance *script, s32 isInitialCall) {
    OVERRIDE_FLAG_UNSET(0x40)
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024240C_C3893C)(ScriptInstance *script, s32 isInitialCall) {
    func_802E5690(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus N(func_80242438_C38968)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 partnerIdx = get_variable(script, *args++);
    s32 si_var = *args++;

    playerData->partners[partnerIdx].level++;
    set_variable(script, si_var, playerData->partners[partnerIdx].level);

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
s32 N(func_802424A4_C389D4)(s32 arg0, s16 arg1) {
    PlayerData* playerData = &gPlayerData;
    if (playerData->partners[arg0].enabled) {
        if (playerData->partners[arg0].level <= arg1) {
            return playerData->partners[arg0].level;
        }
    }
    return -1;
}
#else
INCLUDE_ASM(s32, "world/area_dgb/dgb_04/C36530", dgb_04_func_802424A4_C389D4, s32 arg0, s16 arg1)
#endif

ApiStatus N(func_802424F0_C38A20)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 i;
    s16 var = script->varTable[12] >= 0;

    script->varTable[0] = -1;

    for (i = 1; i < 12; i++) {
        if (playerData->partners[i].enabled && N(func_802424A4_C389D4)(i, var) != -1) {
            script->varTable[0] = 1;
            break;
        }
    }

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING

typedef struct {
    s32 unk_00[8];
    char unk_20[0x64];
    s32 unk_84[8];
    char unk_A4[0x64];
    s32 unk_108[8];
    char unk_128[0x64];
    s32 unk_18C[8];
    char unk_1AC[0x64];
    s32 unk_210[8];
    char unk_230[0x64];
    s32 unk_294[8];
    char unk_2B4[0x64];
    s32 unk_318;
    char unk_31C[8];
    s32 unk_324;
    s32 unk_328;
    s16 unk_32C;
} N(UnkStruct);


ApiStatus N(func_8024259C_C38ACC)(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    N(UnkStruct)* structPtr;
    N(UnkStruct)* ptr;
    s32 i;
    s32 temp_a0;
    s32 var, partnerActiveCount;

    if (isInitialCall) {
        script->functionTemp[2].s = heap_malloc(0x330);
        structPtr = script->functionTemp[2].s;

        ptr = structPtr;
        partnerActiveCount = 0;
        var = script->varTable[12] >= 0;

        for (i = 0; i < 8; i++) {
            s32 idx = *(N(D_80243D38_C3A268) + i);

            if (playerData->partners[idx].enabled) {
                continue;
            }

            ptr->unk_108[i] = idx;
            ptr->unk_84[i] = **(D_8008EF20 + idx);
            temp_a0 = N(func_802424A4_C389D4)(idx, var);
            if (temp_a0 >= 0) {
                ptr->unk_00[i] = *(D_800F7F00 + idx);
                ptr->unk_18C[i] = 1;
                ptr->unk_294[i] = *(temp_a0 + *(N(D_80243D48_C3A278) + i));
            } else {
                ptr->unk_00[i] = *(D_800F7F40 + idx);
                ptr->unk_18C[i] = 0;
                ptr->unk_294[i] = *(N(D_80243D30_C3A260) + var);
            }
            ptr->unk_210[i] = playerData->partners[idx].level;
            partnerActiveCount++;
        }

        structPtr->unk_318 = 4;
        structPtr->unk_324 = partnerActiveCount;
        structPtr->unk_328 = 0;
        func_800F4E40(structPtr);
        script->functionTemp[0].s = 0;
    }

    structPtr = script->functionTemp[2].s;
    if (script->functionTemp[0].s == 0) {
        script->functionTemp[1].s = structPtr->unk_32C;
        if (script->functionTemp[1].s != 0) {
            func_800F13B0();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0].s++;

    if (script->functionTemp[0].s < 15) {
        return ApiStatus_BLOCK;
    }

    func_800F1538();
    if (script->functionTemp[1].s != 0xFF) {
        script->varTable[0] = D_8008EF20[structPtr->unk_108[script->functionTemp[1].s - 1]][0];
        script->varTable[1] = structPtr->unk_108[script->functionTemp[1].s - 1];
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTemp[2].s);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_dgb/dgb_04/C36530", dgb_04_func_8024259C_C38ACC, ScriptInstance *script, s32 isInitialCall)
#endif

ApiStatus N(func_802427EC_C38D1C)(ScriptInstance* script, s32 isInitialCall) {
    s32 partnerID = get_variable(script, *script->ptrReadPos);
    func_800EB168(partnerID);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80242818_C38D48)(ScriptInstance *script, s32 isInitialCall) {
    set_message_string(D_8008EF20[gPlayerData.currentPartner][0], 0);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80242850_C38D80)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 entityIdx = get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIdx);
    s32 si_var = *args++;
    Effect* effect = func_80071750(0, entity->position.x, entity->position.y + 12.5f, entity->position.z, 0.7f, 0);

    set_variable(script, si_var, effect);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802428E0_C38E10)(ScriptInstance *script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);

    effect->flags |= 0x10;

    return ApiStatus_DONE2;
}

ApiStatus N(func_80242914_C38E44)(ScriptInstance *script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(get_variable(script, *script->ptrReadPos));

    func_80070BB0(4, entity->position.x, entity->position.y + 12.5f, entity->position.z, 1.0f, 0x4B);

    return ApiStatus_DONE2;
}

ApiStatus N(func_80242978_C38EA8)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_safe(-4);

    func_80070BB0(9, npc->pos.x, npc->pos.y + 12.5f, npc->pos.z, 1.0f, 0x1E);

    return ApiStatus_DONE2;
}

typedef struct {
    s32 unk_00;
    s32 unk_04;
    Effect* unk_08[3];
    f32 unk_14[3];
    f32 unk_20[3];
    f32 unk_2C[3];
    f32 unk_38[3];
    f32 unk_44[3];
    f32 unk_50[3];
    Entity* unk_5C;
    s32 unk_60;
    s32 unk_64;
} UserData;

Effect* func_800716F0(s32, f32, f32, f32, f32, s32);

ApiStatus N(func_802429D0_C38F00)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    Npc* npc = get_npc_safe(-4);
    f32 sinTheta, cosTheta;
    s32 i;
    f32 var;
    UserData* userDataPtr;
    UserData* scriptPtr;
    f32 save, save2;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (UserData*)general_heap_malloc(0x68);
        scriptPtr = (UserData*)script->userData;

        scriptPtr->unk_5C = get_entity_by_index(get_variable(script, *args));

        for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
            userDataPtr->unk_08[i] = func_800716F0(0, scriptPtr->unk_5C->position.x, scriptPtr->unk_5C->position.y + 12.5f, scriptPtr->unk_5C->position.z, 1.0f, -1);
            save = 0.0f;
            userDataPtr->unk_2C[i] = save;
            userDataPtr->unk_20[i] = save;
            userDataPtr->unk_14[i] = save;
            userDataPtr->unk_50[i] = save;
            userDataPtr->unk_44[i] = save;
            userDataPtr->unk_38[i] = save;
        }

        scriptPtr->unk_00 = 0;
        scriptPtr->unk_04 = 0;
        scriptPtr->unk_60 = 0;
        scriptPtr->unk_64 = 0;

        userDataPtr = scriptPtr;
        for (i = 0, save = 50.0f; i < 3; i++) {
            var = 0;
            add_vec2D_polar(&var, &scriptPtr->unk_44[i], save, *(N(D_80243D88_C3A2B8) + i)); //*(dataPtr++));
            userDataPtr->unk_38[i] = cosTheta * var;
            userDataPtr->unk_50[i] = sinTheta * var;
            userDataPtr->unk_38[i] = npc->pos.x - (scriptPtr->unk_5C->position.x + userDataPtr->unk_38[i]);
            userDataPtr->unk_44[i] = npc->pos.y - (scriptPtr->unk_5C->position.y + userDataPtr->unk_44[i]);
            userDataPtr->unk_50[i] = npc->pos.z - (scriptPtr->unk_5C->position.z + userDataPtr->unk_50[i]);
        }
    }

    scriptPtr = (UserData*)script->userData;
    switch (scriptPtr->unk_00) {
        case 0:
            save = update_lerp(5, 0.0f, 50.0f, scriptPtr->unk_60, 0x14);
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, *(N(D_80243D88_C3A2B8) + i));
                scriptPtr->unk_14[i] = cosTheta * var;
                scriptPtr->unk_2C[i] = sinTheta * var;
            }

            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x15) {
                scriptPtr->unk_00 = 1;
                scriptPtr->unk_60 = 0;
            }
            break;

        case 1:
            save = 50.0f;
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, *(N(D_80243D88_C3A2B8) + i));
                scriptPtr->unk_14[i] = cosTheta * var;
                scriptPtr->unk_2C[i] = sinTheta * var;
            }

            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x10) {
                scriptPtr->unk_60 = 0xF;
                scriptPtr->unk_00 = 2;
            }
            break;

        case 2:
            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x1F) {
                for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
                    userDataPtr->unk_08[i]->flags |= 0x10;
                }
                return ApiStatus_DONE2;
            }
    }

    switch (scriptPtr->unk_04) {
        case 0:
            scriptPtr->unk_64++;
            if (scriptPtr->unk_64 >= 0x10) {
                scriptPtr->unk_04 = 1;
                scriptPtr->unk_64 = 0;
            }
            break;

        case 1:
            for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
                userDataPtr->unk_14[i] = userDataPtr->unk_14[i] + update_lerp(1, 0.0f, userDataPtr->unk_38[i], scriptPtr->unk_64, 0x14);
                userDataPtr->unk_20[i] = userDataPtr->unk_20[i] + update_lerp(1, 0.0f, userDataPtr->unk_44[i], scriptPtr->unk_64, 0x14);
                userDataPtr->unk_2C[i] = userDataPtr->unk_2C[i] + update_lerp(1, 0.0f, userDataPtr->unk_50[i], scriptPtr->unk_64, 0x14);
            }

            scriptPtr->unk_64++;
            if (scriptPtr->unk_64 >= 0x15) {
                scriptPtr->unk_04 = 2;
                scriptPtr->unk_64 = 0;
            }
            break;
    }

    for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
        ((EffectInstanceData*)userDataPtr->unk_08[i]->unk_0C)->rotation.x = userDataPtr->unk_14[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->unk_0C)->rotation.y = userDataPtr->unk_20[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->unk_0C)->rotation.z = userDataPtr->unk_2C[i];
    }

    return ApiStatus_BLOCK;
}

s32 N(func_80242F08_C39438)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 ret = 0;

    if (isInitialCall) {
        script->varTable[0] = get_variable(script, *args++);
        script->varTable[1] = get_variable(script, *args++);
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 0;
        set_transition_stencil_color(0, 0xD0, 0xD0, 0xD0);
    }

    switch (script->functionTemp[0].s) {
        case 0:
            if (script->functionTemp[1].s == 0xFF) {
                script->functionTemp[0].s = 1;
                script->functionTemp[2].s = 0;
            }
            script->functionTemp[1].s += script->varTable[0];
            if (script->functionTemp[1].s >= 0x100) {
                script->functionTemp[1].s = 0xFF;
            }
            break;

        case 1:
            script->functionTemp[2].s++;
            if (script->functionTemp[2].s >= 2) {
                script->functionTemp[0].s = 2;
            }
            break;

        case 2:
            if (script->functionTemp[1].s == 0) {
                ret = 1;
            }
            script->functionTemp[1].s -= script->varTable[1];
            if (script->functionTemp[1].s < 0) {
                script->functionTemp[1].s = 0;
            }
            break;
    }

    set_transition_stencil_zoom_0(1, script->functionTemp[1].s);

    return ret;
}

#include "world/common/UnkPartnerPosFuncs.inc.c"

ApiStatus N(func_802430D8_C39608)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if ((D_8010EBB0.unk_00 != 0) && (D_8010EBB0.unk_03 == 3)) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[] = "dgb_00";
