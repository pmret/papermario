#include "kmr_03.h"
#include "sprite/npc/goompa.h"

enum {
    NPC_GOOMPA,
};

ApiStatus N(func_802401B0_8C8140)(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(0);

    script->varTable[1].s = func_800E0088(npc->pos.x, npc->pos.z) / npc->moveSpeed * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/UnkPositionFunc.inc.c"

Script N(exitWalk_802406F0) = EXIT_WALK_SCRIPT(60,  0, "kmr_04",  0);

Script N(exitWalk_8024074C) = EXIT_WALK_SCRIPT(60,  1, "kmr_05",  0);

Script N(802407A8) = SCRIPT({
    bind N(exitWalk_802406F0) to TRIGGER_FLOOR_ABOVE 3;
    bind N(exitWalk_8024074C) to TRIGGER_FLOOR_ABOVE 5;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GOOMBA_VILLAGE;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    SetCamLeadPlayer(0, 0);
    SI_AREA_FLAG(8) = 0;
    MakeNpcs(0, N(npcGroupList_80241450));
    ClearDefeatedEnemies();
    await N(makeEntities);
    await N(802422B8);
    spawn N(802406C0);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) != 2) {
        SI_VAR(0) = N(802407A8);
        spawn EnterWalk;
    } else {
        spawn N(802407A8);
        spawn N(80242340);
    }
    sleep 1;
});

static s32 N(pad_948)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80240950) = {
    .height = 22,
    .radius = 24,
    .level = 99,
    .unk_2A = 16,
};

Script N(8024097C) = SCRIPT({
1:
    if (SI_AREA_FLAG(8) == 1) {
    100:
        AwaitPlayerLeave(294, 123, 170);
        EnableNpcAI(0, 0);
        DisablePlayerInput(TRUE);
        SetNpcSpeed(NPC_GOOMPA, 4.0);
        SetNpcAnimation(NPC_GOOMPA, NPC_ANIM(goompa, Palette_00, Anim_3));
        N(func_802401B0_8C8140)();
        GetAngleToPlayer(0, SI_VAR(2));
        loop SI_VAR(1) {
            GetNpcPos(NPC_GOOMPA, SI_VAR(7), SI_VAR(8), SI_VAR(9));
            AddVectorPolar(SI_VAR(7), SI_VAR(9), 4.0, SI_VAR(2));
            SetNpcPos(NPC_GOOMPA, SI_VAR(7), SI_VAR(8), SI_VAR(9));
            sleep 1;
        }
        PlayerFaceNpc(0, 3);
        SetPlayerSpeed(3.0);
        PlayerMoveTo(243, 243, 0);
        SetNpcVar(0, 0, 1);
        EnableNpcAI(0, 1);
        DisablePlayerInput(FALSE);
        goto 100;
    }
    sleep 1;
    goto 1;
});

Script N(npcAI_80240B50) = SCRIPT({
1:
    match STORY_PROGRESS {
        == STORY_CH0_FELL_OFF_CLIFF {
        89:
            N(UnkPositionFunc)(-118, 86, -70, -15);
            sleep 1;
            if (SI_VAR(0) == 0) {
                goto 89;
            }
            DisablePlayerInput(TRUE);
            SetNpcAux(NPC_GOOMPA, 0);
            PlaySoundAtNpc(NPC_GOOMPA, SOUND_UNKNOWN_262, 0);
            ShowEmote(0, EMOTE_EXCLAMATION, 45, 15, 1, 0, 0, 0, 0);
            sleep 15;
            NpcFacePlayer(NPC_SELF, 5);
            sleep 10;
            SpeakToPlayer(NPC_GOOMPA, NPC_ANIM(goompa, Palette_00, Anim_8), NPC_ANIM(goompa, Palette_00, Anim_1), 0, MESSAGE_ID(0x0B, 0x00A6));
            UseSettingsFrom(0, -220, 20, -72);
            SetPanTarget(0, -20, 0, 68);
            SetCamPitch(0, 15.0, -8.5);
            SetCamDistance(0, 275);
            SetCamSpeed(0, 1.5);
            PanToTarget(0, 0, 1);
            spawn {
                sleep 20;
                SetPlayerSpeed(2.0);
                PlayerMoveTo(-38, 68, 0);
            }
            GetNpcPos(NPC_GOOMPA, SI_VAR(7), SI_VAR(8), SI_VAR(9));
            SetNpcSpeed(NPC_GOOMPA, 4.0);
            SetNpcAnimation(NPC_GOOMPA, NPC_ANIM(goompa, Palette_00, Anim_3));
            NpcMoveTo(NPC_GOOMPA, 0, 70, 0);
            SetNpcAnimation(NPC_GOOMPA, NPC_ANIM(goompa, Palette_00, Anim_1));
            InterpNpcYaw(NPC_GOOMPA, 276, 20);
            sleep 30;
            SpeakToPlayer(NPC_GOOMPA, NPC_ANIM(goompa, Palette_00, Anim_8), NPC_ANIM(goompa, Palette_00, Anim_1), 0, MESSAGE_ID(0x0B, 0x00A7));
            sleep 5;
            SetPlayerAnimation(ANIM_80007);
            sleep 30;
            SpeakToPlayer(NPC_GOOMPA, NPC_ANIM(goompa, Palette_00, Anim_8), NPC_ANIM(goompa, Palette_00, Anim_1), 0, MESSAGE_ID(0x0B, 0x00A8));
            N(UnkFunc41)(0, 5);
            STORY_PROGRESS = STORY_CH0_GOOMPA_JOINED_PARTY;
            UseSettingsFrom(0, -220, 20, -72);
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamSpeed(0, 3.0);
            PanToTarget(0, 0, 1);
            WaitForCam(0, 1.0);
            PanToTarget(0, 0, 0);
            EnablePartnerAI();
            DisablePlayerInput(FALSE);
            sleep 1;
        }
    }
});

Script N(hit_80240F64) = SCRIPT({
    SetNpcAnimation(NPC_SELF, NPC_ANIM(goompa, Palette_00, Anim_7));
    sleep 10;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(goompa, Palette_00, Anim_1));
    SI_MAP_VAR(0) += 1;
    if (SI_MAP_VAR(0) < 3) {
        GetOwnerEncounterTrigger(SI_VAR(0));
        match SI_VAR(0) {
            == 2 {
                SetNpcVar(0, 0, 1);
                if (SI_AREA_FLAG(6) == 1) {
                } else {
                    SI_AREA_FLAG(6) = 1;
                    SI_AREA_FLAG(7) = 0;
                }
            }
            == 4 {
                SetNpcVar(0, 0, 1);
                if (SI_AREA_FLAG(7) == 1) {
                } else {
                    SI_AREA_FLAG(6) = 0;
                    SI_AREA_FLAG(7) = 1;
                }
            }
        }
        sleep 10;
        SetNpcAnimation(NPC_SELF, NPC_ANIM(goompa, Palette_00, Anim_3));
    } else {
        sleep 10;
        GetNpcPos(NPC_GOOMPA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetNpcFlagBits(NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE);
        SetNpcPos(NPC_GOOMPA, 0, -1000, 0);
        SetNpcFlagBits(NPC_GOOMPA, NPC_FLAG_100, FALSE);
        EnablePartnerAI();
        SetNpcAux(NPC_SELF, N(8024097C));
        BindNpcAI(NPC_SELF, N(npcAI_80240B50));
    }
});

Script N(init_802411A8) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(npcAI_80240B50));
    BindNpcAux(-1, N(8024097C));
    BindNpcHit(-1, N(hit_80240F64));
    match STORY_PROGRESS {
        >= STORY_CH0_GOOMPA_JOINED_PARTY {
            SetNpcFlagBits(NPC_SELF, NPC_FLAG_GRAVITY, FALSE);
            SetNpcFlagBits(NPC_SELF, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE);
            SetNpcPos(NPC_SELF, 0, -1000, 0);
        }
    }
});

StaticNpc N(npcGroup_80241260) = {
    .id = NPC_GOOMPA,
    .settings = &N(npcSettings_80240950),
    .pos = { -50.0f, 0.0f, 80.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_400000,
    .init = &N(init_802411A8),
    .yaw = 45,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(goompa, Palette_00, Anim_1),
        NPC_ANIM(goompa, Palette_00, Anim_2),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_1),
        NPC_ANIM(goompa, Palette_00, Anim_1),
        NPC_ANIM(goompa, Palette_00, Anim_0),
        NPC_ANIM(goompa, Palette_00, Anim_0),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
        NPC_ANIM(goompa, Palette_00, Anim_3),
    },
    .tattle = MESSAGE_ID(0x1A, 0x0063),
};

NpcGroupList N(npcGroupList_80241450) = {
    NPC_GROUP(N(npcGroup_80241260), BATTLE_ID(0, 2, 0, 0)),
    {},
};

static s32 N(pad_1468)[] = {
    0x00000000, 0x00000000,
};

Script N(80241470) = SCRIPT({
    ModifyColliderFlags(0, 9, 0x7FFFFE00);
    STORY_PROGRESS = STORY_CH0_LEFT_THE_PLAYGROUND;
});

Script N(802414A8) = SCRIPT({
    SI_SAVE_FLAG(54) = 1;
});

Script N(802414C8) = SCRIPT({
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 1;
    goto 0;
});

Script N(makeEntities) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH0_LEFT_THE_PLAYGROUND) {
        MakeEntity(0x802EA10C, 45, 0, 70, 15, MAKE_ENTITY_END);
        AssignScript(N(80241470));
    } else {
        ModifyColliderFlags(0, 9, 0x7FFFFE00);
    }
    if (SI_SAVE_FLAG(54) == 0) {
        MakeEntity(0x802EA19C, 230, 0, 310, 15, MAKE_ENTITY_END);
        AssignScript(N(802414A8));
    }
    MakeEntity(0x802EA588, 230, 60, 310, 15, ITEM_REPEL_GEL, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(52));
    MakeEntity(0x802EA0C4, 230, 50, -160, 15, MAKE_ENTITY_END);
    MakeEntity(0x802EA0C4, 165, 0, 380, 20, MAKE_ENTITY_END);
    MakeEntity(0x802EA564, -170, 0, 370, 43, ITEM_COIN, MAKE_ENTITY_END);
    AssignBlockFlag(SI_SAVE_FLAG(50));
    MakeEntity(0x802EAA54, 345, 75, -250, 0, ITEM_WATER, MAKE_ENTITY_END);
    MakeItemEntity(ITEM_COIN, 345, 205, -250, 17, SI_SAVE_FLAG(56));
    MakeItemEntity(ITEM_COIN, 345, 230, -250, 17, SI_SAVE_FLAG(57));
    MakeItemEntity(ITEM_COIN, 345, 255, -250, 17, SI_SAVE_FLAG(58));
    MakeItemEntity(ITEM_COIN, 345, 280, -250, 17, SI_SAVE_FLAG(59));
    MakeItemEntity(ITEM_FIRE_FLOWER, 229, 250, -156, 17, SI_SAVE_FLAG(49));
    MakeEntity(0x802EAB04, 300, 0, 150, 0, ITEM_PULSE_STONE, MAKE_ENTITY_END);
    AssignPanelFlag(SI_SAVE_FLAG(88));
    MakeEntity(0x802EA7E0, 130, 60, 0, 0, MAKE_ENTITY_END);
});
