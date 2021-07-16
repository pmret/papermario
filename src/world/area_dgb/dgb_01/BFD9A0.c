#include "dgb_01.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_tubba.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {    0.0f,   0.0f, 485.0f,   0.0f },
    { -485.0f,   0.0f,   0.0f,  90.0f },
    {  485.0f,   0.0f,   0.0f, 270.0f },
    { -485.0f, 210.0f,   0.0f,  90.0f },
    {  485.0f, 210.0f,   0.0f, 270.0f },
    { -485.0f, 420.0f,   0.0f,  90.0f },
    {  485.0f, 420.0f,   0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_01_tattle },
};

Script N(802434A0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetMusicTrack(0, SONG_TUBBA_ESCAPE, 0, 8);
        } else {
            SetMusicTrack(0, SONG_TUBBAS_MANOR, 0, 8);
        }
    }
    ClearAmbientSounds(250);
});

static s32 N(pad_3548)[] = {
    0x00000000, 0x00000000,
};

Script N(exitDoubleDoor_80243550) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 0;
    SI_VAR(1) = 4;
    SI_VAR(2) = 54;
    SI_VAR(3) = 57;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_00", 1);
    sleep 100;
});

Script N(exitDoubleDoor_80243604) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 1;
    SI_VAR(1) = 8;
    SI_VAR(2) = 34;
    SI_VAR(3) = 36;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_02", 1);
    sleep 100;
});

Script N(exitDoubleDoor_802436B8) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 2;
    SI_VAR(1) = 20;
    SI_VAR(2) = 41;
    SI_VAR(3) = 39;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_08", 0);
    sleep 100;
});

Script N(exitDoubleDoor_8024376C) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 3;
    SI_VAR(1) = 12;
    SI_VAR(2) = 29;
    SI_VAR(3) = 31;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_09", 1);
    sleep 100;
});

Script N(exitDoubleDoor_80243820) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 4;
    SI_VAR(1) = 24;
    SI_VAR(2) = 46;
    SI_VAR(3) = 44;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_08", 1);
    sleep 100;
});

Script N(exitDoubleDoor_802438D4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 5;
    SI_VAR(1) = 16;
    SI_VAR(2) = 24;
    SI_VAR(3) = 26;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_17", 1);
    sleep 100;
});

Script N(exitDoubleDoor_80243988) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    UseDoorSounds(3);
    SI_VAR(0) = 6;
    SI_VAR(1) = 28;
    SI_VAR(2) = 51;
    SI_VAR(3) = 49;
    spawn ExitDoubleDoor;
    sleep 17;
    GotoMap("dgb_18", 0);
    sleep 100;
});

Script N(enterDoubleDoor_80243A3C) = SCRIPT({
    UseDoorSounds(3);
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            if (SI_SAVE_FLAG(1041) == 0) {
                SI_SAVE_FLAG(1041) = 1;
                STORY_PROGRESS = STORY_CH3_ARRIVED_AT_TUBBAS_MANOR;
            }
            SI_VAR(2) = 54;
            SI_VAR(3) = 57;
            await EnterDoubleDoor;
        }
        == 1 {
            SI_VAR(2) = 34;
            SI_VAR(3) = 36;
            await EnterDoubleDoor;
        }
        == 2 {
            SI_VAR(2) = 41;
            SI_VAR(3) = 39;
            await EnterDoubleDoor;
        }
        == 3 {
            SI_VAR(2) = 29;
            SI_VAR(3) = 31;
            await EnterDoubleDoor;
        }
        == 4 {
            SI_VAR(2) = 46;
            SI_VAR(3) = 44;
            await EnterDoubleDoor;
        }
        == 5 {
            SI_VAR(2) = 24;
            SI_VAR(3) = 26;
            await EnterDoubleDoor;
        }
        == 6 {
            SI_VAR(2) = 51;
            SI_VAR(3) = 49;
            await EnterDoubleDoor;
        }
    }
});

s32 N(itemList_80243C40)[] = {
    ITEM_CASTLE_KEY1,
    ITEM_NONE,
};

// *INDENT-OFF*
Script N(main) = {
    SI_CMD(ScriptOpcode_SET, SI_SAVE_VAR(425), 15),
    SI_CMD(ScriptOpcode_CALL, SetSpriteShading, -1),
    SI_CMD(ScriptOpcode_CALL, SetCamPerspective, 0, 3, 25, 16, 4096),
    SI_CMD(ScriptOpcode_CALL, SetCamBGColor, 0, 0, 0, 0),
    SI_CMD(ScriptOpcode_CALL, SetCamEnabled, 0, 1),
    SI_CMD(ScriptOpcode_CALL, SetCamLeadPlayer, 0, 0),
    SI_CMD(ScriptOpcode_SET, SI_SAVE_FLAG(1978), 1),
    SI_CMD(ScriptOpcode_AWAIT_SCRIPT, N(makeEntities)),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(802449C4)),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(802434A0)),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80243550), TRIGGER_WALL_PRESS_A, 4, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80243604), TRIGGER_WALL_PRESS_A, 8, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_8024376C), TRIGGER_WALL_PRESS_A, 12, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80243820), TRIGGER_WALL_PRESS_A, 24, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_802438D4), TRIGGER_WALL_PRESS_A, 16, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_80243988), TRIGGER_WALL_PRESS_A, 28, 1, 0),
    SI_CMD(ScriptOpcode_IF_EQ, SI_SAVE_FLAG(1040), 0),
        SI_CMD(ScriptOpcode_BIND_PADLOCK, N(80244AD0), TRIGGER_WALL_PRESS_A, 16384, N(itemList_80243C40), 0, 1),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitDoubleDoor_802436B8), TRIGGER_WALL_PRESS_A, 20, 1, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_MATCH, SI_SAVE_VAR(0)),
        SI_CMD(ScriptOpcode_CASE_LT, -29),
            SI_CMD(ScriptOpcode_CALL, MakeNpcs, 1, N(npcGroupList_80246E50)),
        SI_CMD(ScriptOpcode_CASE_LT, -16),
            SI_CMD(ScriptOpcode_CALL, GetEntryID, SI_VAR(0)),
            SI_CMD(ScriptOpcode_MATCH, SI_VAR(0)),
                SI_CMD(ScriptOpcode_CASE_EQ, 2),
                    SI_CMD(ScriptOpcode_CALL, MakeNpcs, 1, N(npcGroupList_80246F1C)),
                SI_CMD(ScriptOpcode_CASE_EQ, 4),
                    SI_CMD(ScriptOpcode_CALL, MakeNpcs, 1, N(npcGroupList_80246ED4)),
                SI_CMD(ScriptOpcode_CASE_EQ, 6),
                    SI_CMD(ScriptOpcode_CALL, MakeNpcs, 1, N(npcGroupList_80246E8C)),
            SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_END_MATCH),
    SI_CMD(ScriptOpcode_SPAWN_SCRIPT, N(enterDoubleDoor_80243A3C)),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

static s32 N(pad_3EE4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(80243EF0) = SCRIPT({
    loop {
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        if (SI_VAR(0) < 100) {
            break loop;
        }
        sleep 1;
    }
    DisablePlayerInput(TRUE);
    N(func_80240000_BFD880)();
    InitAnimatedModels();
    sleep 1;
    func_802D2B6C();
    SetPlayerAnimation(0x8000A);
    spawn {
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
        sleep 5;
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
        sleep 5;
    }
    spawn {
        ShakeCam(0, 0, 10, 1.0);
    }
    sleep 30;
    spawn {
        loop 12 {
            PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
            sleep 5;
        }
    }
    spawn {
        ShakeCam(0, 0, 60, 1.0);
    }
    UseSettingsFrom(0, 400, 420, 0);
    SetPanTarget(0, 400, 420, 0);
    SetCamDistance(0, 450.0);
    SetCamPitch(0, 20.0, -11.0);
    SetCamPosB(0, 500.0, 0.0);
    SetCamSpeed(0, 3.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SI_SAVE_VAR(203) = 1;
    SetNpcVar(4, 0, 1);
    loop {
        GetNpcVar(4, 0, SI_VAR(0));
        if (SI_VAR(0) == 3) {
            break loop;
        }
        sleep 1;
    }
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -50;
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 90.0);
    SetCamDistance(0, 750.0);
    SetCamPitch(0, 0.0, 3.0);
    DisablePartnerAI(0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 1;
    EnablePartnerAI();
    ShakeCam(0, 0, 20, 1.0);
    LoadAnimatedModel(0, N(D_80252F4C_C107CC));
    PlayModelAnimation(0, N(D_802539A0_C11220));
    SetAnimatedModelRootPosition(0, 0, 0, 0);
    SetAnimatedModelRenderMode(0, 1);
    spawn {
        PlaySound(0x95);
        sleep 60;
        PlaySound(0x96);
        sleep 25;
        PlaySound(0x98);
        sleep 70;
        PlaySound(0x97);
    }
    spawn {
        sleep 100;
        PlaySound(0xA8);
        sleep 50;
        PlaySound(0xA8);
        sleep 30;
        PlaySound(0xA8);
        sleep 70;
        PlaySound(0xA8);
        sleep 30;
        PlaySound(0xA8);
    }
    spawn {
        DisablePlayerPhysics(TRUE);
        sleep 1;
        SetGroupEnabled(100, 0);
        SetGroupEnabled(111, 0);
        SetPlayerAnimation(0x80013);
        SetPlayerJumpscale(0.5);
        PlayerJump1(121, 210, 0, 60);
        sleep 10;
        SetPlayerAnimation(0x8001F);
        sleep 20;
        SetPlayerAnimation(ANIM_RUN_PANIC);
        SetPlayerSpeed(8.0);
        PlayerMoveTo(412, -29, 0);
        sleep 10;
        InterpPlayerYaw(270, 0);
        SetPlayerAnimation(ANIM_10002);
        ModifyColliderFlags(1, 50, 0x7FFFFE00);
        DisablePlayerPhysics(FALSE);
    }
    spawn {
        DisablePartnerAI(0);
        GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) -= 210;
        sleep 1;
        SetNpcJumpscale(NPC_PARTNER, 0.5);
        NpcJump1(NPC_PARTNER, 151, SI_VAR(1), 0, 60);
        sleep 30;
        EnablePartnerAI();
    }
    ShakeCam(0, 0, 300, 1.0);
    StopSound(0x8000005D);
    spawn {
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_D));
        SetNpcSpeed(NPC_WORLD_TUBBA, 3.0);
        NpcMoveTo(NPC_WORLD_TUBBA, 176, 0, 0);
    }
    spawn {
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
        ShakeCam(0, 0, 5, 0.30078125);
        sleep 5;
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
        ShakeCam(0, 0, 2, 0.150390625);
        sleep 8;
    }
    sleep 20;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamSpeed(0, 2.0);
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    STORY_PROGRESS = STORY_CH3_TUBBA_SMASHED_THE_BRIDGES;
    SetGroupEnabled(210, 1);
    DeleteAnimatedModel(0);
    spawn {
        sleep 30;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_D));
        SetNpcPos(NPC_WORLD_TUBBA, 137, 244, 35);
        SetNpcSpeed(NPC_WORLD_TUBBA, 3.0);
        NpcMoveTo(NPC_WORLD_TUBBA, 470, 0, 0);
        ShakeCam(0, 0, 10, 3.0);
    }
    spawn {
        loop {
            PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
            ShakeCam(0, 0, 5, 0.30078125);
            sleep 5;
            PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
            ShakeCam(0, 0, 2, 0.150390625);
            sleep 8;
        }
    }
    SetPlayerSpeed(3.0);
    PlayerMoveTo(470, 0, 0);
    DisablePlayerInput(FALSE);
    spawn N(exitDoubleDoor_80243820);
});

Script N(802449C4) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_WOKE_UP {
            SetGroupEnabled(210, 0);
            ModifyColliderFlags(0, 50, 0x7FFFFE00);
        }
        == STORY_CH3_TUBBA_WOKE_UP {
            SetGroupEnabled(210, 0);
            ModifyColliderFlags(0, 50, 0x7FFFFE00);
            spawn N(80243EF0);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetGroupEnabled(112, 0);
            ModifyColliderFlags(0, 40, 0x7FFFFE00);
        } else {
            SetGroupEnabled(210, 0);
            ModifyColliderFlags(0, 50, 0x7FFFFE00);
        }
    }
});

Script N(80244AD0) = SCRIPT({
    group 0;
    suspend group 1;
    ShowKeyChoicePopup();
    if (SI_VAR(0) == 0) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00D8), 160, 40);
        CloseChoicePopup();
        resume group 1;
        return;
    }
    if (SI_VAR(0) == -1) {
        CloseChoicePopup();
        resume group 1;
        return;
    }
    FindKeyItem(19, SI_VAR(0));
    RemoveKeyItemAt(SI_VAR(0));
    CloseChoicePopup();
    SI_SAVE_FLAG(1040) = 1;
    N(GetEntityPosition)(SI_MAP_VAR(0), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlaySoundAt(0x269, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) = SI_MAP_VAR(0);
    N(SetEntityFlags100000)();
    resume group 1;
    unbind;
});

Script N(80244C38) = SCRIPT({
    bind N(exitDoubleDoor_802436B8) to TRIGGER_WALL_PRESS_A 20;
});

Script N(makeEntities) = SCRIPT({
    if (SI_SAVE_FLAG(1040) == 0) {
        MakeEntity(0x802BCD68, 490, 8, 0, -80, MAKE_ENTITY_END);
        AssignScript(N(80244C38));
        SI_MAP_VAR(0) = SI_VAR(0);
    }
});

f32 N(D_80244CD0_C02550)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

Script N(80244CE8) = SCRIPT({
    SetSelfEnemyFlagBits(((0x00100000 | 0x01000000 | 0x02000000 | 0x04000000 | 0x08000000 | 0x10000000 | 0x20000000)), TRUE);
    SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT)), TRUE);
});

NpcAISettings N(npcAISettings_80244D24) = {
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

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_MATCHING
// second npc_raycast_down_sides call
void N(func_802402D0_BFDB50)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
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
INCLUDE_ASM(void, "world/area_dgb/dgb_01/BFD9A0", dgb_01_func_802402D0_BFDB50, ScriptInstance* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240D74_BFE5F4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80244CD0_C02550)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024142C_BFECAC)(ScriptInstance* script, s32 isInitialCall) {
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
            N(func_802402D0_BFDB50)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240D74_BFE5F4)(script, aiSettings, territoryPtr);
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

void N(func_80241618_BFEE98)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f0;
    f32 phi_f20;

    npc->duration--;
    if (npc->duration <= 0) {
        npc->flags &= ~0x00200000;
        npc->duration = aiSettings->unk_20 / 2 + rand_int(aiSettings->unk_20 / 2 + 1);
        npc->currentAnim.w = enemy->animList[8];
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
        script->functionTemp[0] = 13;
    }
}

void N(func_80241770_BFEFF0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                   gPlayerStatusPtr->position.z) <= (npc->moveSpeed * 2.5)) {
            npc->duration = 0;
            script->functionTemp[0] = 14;
        } else {
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags |= 0x200000;
                script->functionTemp[0] = 12;
            }
        }
    } else {
        script->functionTemp[0] = 16;
    }

}

void N(func_80241874_BFF0F4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i != npc->npcID && (get_enemy(i)->varTable[0] & 0x100)) {
            return;
        }
    }

    enemy->varTable[0] |= 0x100;
    npc->pos.x = gPlayerStatusPtr->position.x;
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & 0x1000)) {
        enemy->varTable[0] |= 0x1000;
    }

    sfx_play_sound_at_position(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->functionTemp[0] = 15;
}

void N(func_80241954_BFF1D4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    s32 temp_f8_2;

    sfx_adjust_env_sound_pos(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    if (!func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        enemy->varTable[0] &= ~0x100;
        npc->rotation.y = 0.0f;
        npc->flags &= ~0x00200000;
        script->functionTemp[0] = 16;
    } else {
        npc->pos.x = gPlayerStatusPtr->position.x;
        npc->pos.z = gPlayerStatusPtr->position.z + 2.0f;
        npc->rotation.y += 25.0f;
        if (npc->rotation.y > 360.0) {
            npc->rotation.y -= 360.0;
        }
        temp_f8_2 = 255.0f - (cosine((s32)npc->rotation.y % 180) * 56.0f);
        func_802DE894(npc->spriteInstanceID, 6, temp_f8_2, temp_f8_2, temp_f8_2, 255, 0);

        posX = gPlayerStatusPtr->position.x;
        posY = gPlayerStatusPtr->position.y;
        posZ = gPlayerStatusPtr->position.z;
        posW = 1000.0f;
        npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        if (fabsf(npc->pos.y - posY) > 24.0) {
            npc->pos.y -= 1.8;
        } else {
            npc->rotation.y = 0.0f;
            npc->flags &= ~0x00200000;
            if (D_8010EBB0.unk_03 != 9) {
                disable_player_input();
                partner_disable_input();
                npc->duration = 0;
                script->functionTemp[0] = 20;
            } else {
                script->functionTemp[0] = 16;
            }
        }
    }
}

void N(func_80241BF0_BFF470)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    if (enemy->varTable[0] & 0x1000) {
        sfx_stop_sound(0x80000011);
        enemy->varTable[0] &= ~0x1000;
    }
    npc->currentAnim.w = enemy->animList[9];
    npc->duration = 20;
    script->functionTemp[0] = 17;
}

void N(func_80241CA8_BFF528)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
    npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
    if (!(npc->pos.y < (posY + temp_f20))) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc->pos.y = posY + temp_f20;
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &var);
        npc->duration = 10;
        script->functionTemp[0] = 18;
    }
}

void N(func_80241E28_BFF6A8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 30;
    }
}

void N(func_80241E70_BFF6F0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration >= 3) {
        if (D_8010EBB0.unk_03 != 9) {
            npc->duration = 0;
            script->functionTemp[0] = 100;
        } else {
            enable_player_input();
            partner_enable_input();
            script->functionTemp[0] = 16;
        }
    }
}

void N(func_80241EF0_BFF770)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    npc->flags &= ~0x00200000;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1] = 0x1E;
}

void N(func_80241F98_BFF818)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

    if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
        npc->pos.y = posY + temp_f26 + (temp_f20 * temp_f22);
    } else {
        npc->pos.y = temp_f24 + (temp_f20 * temp_f22);
    }

    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.5, aiSettings->unk_10.f * 0.5, 0)) {
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->moveToPos.y = npc->pos.y;
            script->functionTemp[0] = 12;
            return;
        }
    }

    script->functionTemp[1]--;
    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        posW = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        if (posW <= (2.0f * npc->moveSpeed)) {
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            script->functionTemp[0] = 2;
        }
    }
}

ApiStatus N(func_802422B0_BFFB30)(ScriptInstance* script, s32 isInitialCall) {
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
    territory.unk_18 = 125.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
        case 1:
            N(func_802402D0_BFDB50)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 12:
            N(func_80241618_BFEE98)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(func_80241770_BFEFF0)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241874_BFF0F4)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 15) {
                break;
            }
        case 15:
            N(func_80241954_BFF1D4)(script, aiSettings, territoryPtr);
            break;
        case 16:
            N(func_80241BF0_BFF470)(script, aiSettings, territoryPtr);
        case 17:
            N(func_80241CA8_BFF528)(script, aiSettings, territoryPtr);
            break;
        case 18:
            N(func_80241E28_BFF6A8)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(func_80241E70_BFF6F0)(script, aiSettings, territoryPtr);
            break;
        case 30:
            N(func_80241EF0_BFF770)(script, aiSettings, territoryPtr);
        case 31:
            N(func_80241F98_BFF818)(script, aiSettings, territoryPtr);
    }

    return (script->functionTemp[0] == 100) * ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[];

Script N(npcAI_80244D54) = SCRIPT({
    SetSelfVar(0, 0);
    SetSelfVar(5, -650);
    SetSelfVar(6, 30);
    SetSelfVar(1, 600);
    N(func_802422B0_BFFB30)(N(npcAISettings_80244D24));
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
    SetTimeFreezeMode(1);
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

Script N(8024517C) = SCRIPT({
    GetOwnerEncounterTrigger(SI_VAR(0));
    match SI_VAR(0) {
        == 1, 2, 4, 6 {
            GetSelfAnimationFromTable(7, SI_VAR(0));
            await 0x800936DC;
        }
    }
});

Script N(80245208) = SCRIPT({
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

NpcSettings N(npcSettings_8024526C) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80244CE8),
    .ai = &N(npcAI_80244D54),
    .level = 99,
};

NpcAISettings N(npcAISettings_80245298) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .unk_10 = { .f = 90.0f },
    .unk_14 = 1,
    .chaseSpeed = 3.9f,
    .unk_1C = { .s = 180 },
    .unk_20 = 2,
    .chaseRadius = 170.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 1,
};

Script N(npcAI_802452C8) = SCRIPT({
    N(func_802430C0_C00940)(N(npcAISettings_80245298));
});

NpcSettings N(npcSettings_802452E8) = {
    .height = 90,
    .radius = 65,
    .ai = &N(npcAI_802452C8),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80245314) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80245340) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

Script N(idle_8024536C) = SCRIPT({
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) == 1) {
            break loop;
        }
        sleep 1;
    }
    SI_SAVE_VAR(203) = 1;
    PlaySoundAtCollider(28, 455, 0);
    MakeLerp(0, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(49, SI_VAR(0), 0, 1, 0);
        RotateModel(51, SI_VAR(0), 0, -1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_A));
    SetNpcPos(NPC_SELF, 520, 420, 0);
    SetNpcYaw(NPC_SELF, 270);
    NpcMoveTo(NPC_SELF, 390, 0, 30);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_7));
    spawn {
        sleep 20;
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(49, SI_VAR(0), 0, 1, 0);
            RotateModel(51, SI_VAR(0), 0, -1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(28, 456, 0);
    }
    SpeakToPlayer(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_10), NPC_ANIM(world_tubba, Palette_00, Anim_6), 0, MESSAGE_ID(0x0E, 0x0101));
    spawn {
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_19));
        sleep 4;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1A));
        sleep 17;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1B));
        sleep 11;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1C));
        sleep 30;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1D));
    }
    sleep 4;
    SetNpcJumpscale(NPC_WORLD_TUBBA, 1.0);
    GetNpcPos(NPC_WORLD_TUBBA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    NpcJump0(NPC_WORLD_TUBBA, SI_VAR(0), SI_VAR(1), SI_VAR(2), 30);
    PlaySoundAtNpc(NPC_WORLD_TUBBA, 0x20A0, 0);
    PlaySound(0x8000005D);
    ShakeCam(0, 0, 15, 4.0);
    ShakeCam(0, 0, 15, 2.0);
    SetSelfVar(0, 3);
});

Script N(init_80245784) = SCRIPT({
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    SetSelfVar(0, 0);
    BindNpcIdle(NPC_SELF, N(idle_8024536C));
});

const char N(dgb_00_name_hack)[] = "dgb_00";

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_802430C0_C00940)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1_copy)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, aiSettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc1.inc.c"

const char N(dgb_08_name_hack)[];

Script N(defeat_802457D8) = SCRIPT({
    N(UnkFunc1)();
    GotoMap(N(dgb_08_name_hack), 1);
    sleep 100;
});

Script N(init_80245814) = SCRIPT({
    if (SI_SAVE_VAR(203) != 1) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_4)), TRUE);
        return;
    }
    if (STORY_PROGRESS >= STORY_CH3_TUBBA_CHASED_MARIO_IN_HALL) {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_4)), TRUE);
        return;
    }
    SetNpcPos(NPC_WORLD_TUBBA, 137, 244, 35);
    BindNpcDefeat(NPC_SELF, N(defeat_802457D8));
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
    spawn {
        loop {
            ShakeCam(0, 0, 5, 2.0);
            sleep 5;
            ShakeCam(0, 0, 2, 1.0);
            sleep 8;
        }
    }
});

Script N(idle_8024598C) = SCRIPT({
    AwaitPlayerApproach(0, 420, 400);
    SI_SAVE_VAR(203) = 1;
    STORY_PROGRESS = STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER;
    PlaySoundAtCollider(20, 455, 0);
    MakeLerp(0, 80, 10, 0);
    loop {
        UpdateLerp();
        RotateModel(39, SI_VAR(0), 0, -1, 0);
        RotateModel(41, SI_VAR(0), 0, 1, 0);
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
    }
    SetNpcPos(NPC_SELF, 555, 0, 0);
    SetNpcYaw(NPC_SELF, 270);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_A));
    NpcMoveTo(NPC_SELF, 426, 0, 30);
    spawn {
        sleep 20;
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(39, SI_VAR(0), 0, -1, 0);
            RotateModel(41, SI_VAR(0), 0, 1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(20, 456, 0);
    }
    spawn {
        loop {
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 4194304);
            ShakeCam(0, 0, 5, 2.0);
            sleep 5;
            PlaySoundAtNpc(NPC_SELF, SOUND_UNKNOWN_20F6, 4194304);
            ShakeCam(0, 0, 2, 1.0);
            sleep 8;
        }
    }
    SetNpcSpeed(NPC_SELF, 5.0);
    NpcMoveTo(NPC_SELF, 259, 167, 0);
    N(func_802430C0_C00940)(N(npcAISettings_80245298));
});

Script N(defeat_80245CB4) = SCRIPT({
    N(UnkFunc1)();
    GotoMap(N(dgb_00_name_hack), 1);
    sleep 100;
});

Script N(init_80245CF0) = SCRIPT({
    if (SI_SAVE_VAR(203) != 1) {
        BindNpcIdle(NPC_SELF, N(idle_8024598C));
    } else {
        SetNpcPos(NPC_SELF, 136, 0, -330);
    }
    BindNpcDefeat(NPC_SELF, N(defeat_80245CB4));
    SetNpcScale(NPC_SELF, 1.25, 1.25, 1.25);
});

Script N(init_80245D80) = SCRIPT({
    SI_VAR(0) = STORY_PROGRESS;
    if (SI_VAR(0) >= -29) {
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | 0x00000040)), TRUE);
        EnableNpcShadow(NPC_SELF, FALSE);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(sentinel, Palette_00, Anim_1));
        SetNpcPos(NPC_SELF, -33, -3, 8);
        SetNpcRotation(NPC_SELF, -50, 30, 10);
        BindNpcIdle(NPC_SELF, 0);
    }
});

Script N(init_80245E44) = SCRIPT({
    SI_VAR(0) = STORY_PROGRESS;
    if (SI_VAR(0) >= -29) {
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | 0x00000040)), TRUE);
        EnableNpcShadow(NPC_SELF, FALSE);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(sentinel, Palette_00, Anim_1));
        SetNpcPos(NPC_SELF, -486, 182, 28);
        SetNpcRotation(NPC_SELF, -10, 50, 0);
        BindNpcIdle(NPC_SELF, 0);
    }
});

Script N(init_80245F08) = SCRIPT({
    SI_VAR(0) = STORY_PROGRESS;
    if (SI_VAR(0) >= -29) {
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | 0x00000040)), TRUE);
        EnableNpcShadow(NPC_SELF, FALSE);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(sentinel, Palette_00, Anim_1));
        SetNpcPos(NPC_SELF, -201, 0, -143);
        SetNpcRotation(NPC_SELF, -50, 0, 0);
        BindNpcIdle(NPC_SELF, 0);
    }
});

Script N(init_80245FCC) = SCRIPT({
    SI_VAR(0) = STORY_PROGRESS;
    if (SI_VAR(0) >= -29) {
        SetNpcFlagBits(NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | 0x00000040)), TRUE);
        EnableNpcShadow(NPC_SELF, FALSE);
        SetNpcAnimation(NPC_SELF, NPC_ANIM(sentinel, Palette_00, Anim_1));
        SetNpcPos(NPC_SELF, -305, -1, -80);
        SetNpcRotation(NPC_SELF, -65, -30, 0);
        BindNpcIdle(NPC_SELF, 0);
    }
});

StaticNpc N(npcGroup_80246090) = {
    .id = NPC_SENTINEL0,
    .settings = &N(npcSettings_8024526C),
    .pos = { -180.0f, 100.0f, 230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245D80),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -180, 100, 230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
};

StaticNpc N(npcGroup_80246280) = {
    .id = NPC_SENTINEL1,
    .settings = &N(npcSettings_8024526C),
    .pos = { 180.0f, 100.0f, 230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245E44),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 180, 100, 230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
};

StaticNpc N(npcGroup_80246470) = {
    .id = NPC_SENTINEL2,
    .settings = &N(npcSettings_8024526C),
    .pos = { -180.0f, 100.0f, -230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245F08),
    .yaw = 90,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -180, 100, -230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
};

StaticNpc N(npcGroup_80246660) = {
    .id = NPC_SENTINEL3,
    .settings = &N(npcSettings_8024526C),
    .pos = { 180.0f, 100.0f, -230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245FCC),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 180, 100, -230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
};

NpcAnimID N(extraAnimationList_80246850)[] = {
    NPC_ANIM(world_tubba, Palette_00, Anim_6),
    NPC_ANIM(world_tubba, Palette_00, Anim_10),
    NPC_ANIM(world_tubba, Palette_00, Anim_9),
    NPC_ANIM(world_tubba, Palette_00, Anim_7),
    NPC_ANIM(world_tubba, Palette_00, Anim_A),
    NPC_ANIM(world_tubba, Palette_00, Anim_D),
    NPC_ANIM(world_tubba, Palette_00, Anim_19),
    NPC_ANIM(world_tubba, Palette_00, Anim_1A),
    NPC_ANIM(world_tubba, Palette_00, Anim_1B),
    NPC_ANIM(world_tubba, Palette_00, Anim_1C),
    NPC_ANIM(world_tubba, Palette_00, Anim_1D),
    ANIM_END,
};

StaticNpc N(npcGroup_80246880) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_80245314),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245784),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(world_tubba, Palette_00, Anim_6),
        NPC_ANIM(world_tubba, Palette_00, Anim_9),
        NPC_ANIM(world_tubba, Palette_00, Anim_C),
        NPC_ANIM(world_tubba, Palette_00, Anim_C),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
        NPC_ANIM(world_tubba, Palette_00, Anim_0),
    },
    .extraAnimations = N(extraAnimationList_80246850),
};

StaticNpc N(npcGroup_80246A70) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802452E8),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245814),
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 2,
    .maxCoinBonus = 3,
    .movement = { 2, 320, 210, 0, 370, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 350, 210, 0, 1000, 250, 1 },
    .animations = {
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_A),
        NPC_ANIM(world_tubba, Palette_00, Anim_D),
        NPC_ANIM(world_tubba, Palette_00, Anim_D),
        NPC_ANIM(world_tubba, Palette_00, Anim_19),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    .extraAnimations = N(extraAnimationList_80246850),
};

StaticNpc N(npcGroup_80246C60) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802452E8),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245CF0),
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 2,
    .maxCoinBonus = 3,
    .movement = { 8, 156, 0, 187, -36, 0, 290, -159, 0, 50, -80, 0, -218, 66, 0, -362, 196, 0, -268, 280, 0, -124, 250, 0, 100, 0, 0, 0, 0, 0, 0, -32767, 250, 0, 100, 1000, 250, 1 },
    .animations = {
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_A),
        NPC_ANIM(world_tubba, Palette_00, Anim_D),
        NPC_ANIM(world_tubba, Palette_00, Anim_D),
        NPC_ANIM(world_tubba, Palette_00, Anim_19),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
        NPC_ANIM(world_tubba, Palette_00, Anim_7),
    },
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    .extraAnimations = N(extraAnimationList_80246850),
};

NpcGroupList N(npcGroupList_80246E50) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80246E8C) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246880), BATTLE_ID(15, 4, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80246ED4) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246A70), BATTLE_ID(15, 4, 0, 1)),
    {},
};

NpcGroupList N(npcGroupList_80246F1C) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246C60), BATTLE_ID(15, 4, 0, 1)),
    {},
};

const char N(dgb_08_name_hack)[] = "dgb_08";
