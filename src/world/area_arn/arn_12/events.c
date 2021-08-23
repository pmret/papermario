#include "arn_12.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/goomba.h"

EvtSource N(exitSingleDoor_80240100) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 0;
    SI_VAR(1) = 2;
    SI_VAR(2) = 0;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_10", 1);
    sleep 100;
});

EvtSource N(exitSingleDoor_802401A4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 1;
    SI_VAR(1) = 7;
    SI_VAR(2) = 2;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_13", 0);
    sleep 100;
});

EvtSource N(80240248) = SCRIPT({
    bind N(exitSingleDoor_80240100) TRIGGER_WALL_PRESS_A 2;
    bind N(exitSingleDoor_802401A4) TRIGGER_WALL_PRESS_A 7;
});

EvtSource N(enterSingleDoor_80240290) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 0;
            SI_VAR(3) = -1;
            await EnterSingleDoor;
            spawn N(80240248);
        }
        == 1 {
            SI_VAR(2) = 2;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
            spawn N(80240248);
        }
    }
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_WINDY_MILL;
    SetSpriteShading(524291);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80240BBC));
    await N(makeEntities);
    spawn N(enterSingleDoor_80240290);
    spawn N(80240060);
});

static s32 N(pad_418)[] = {
    0x00000000, 0x00000000,
};

EvtSource N(80240420) = SCRIPT({

});

EvtSource N(80240430) = SCRIPT({

});

NpcSettings N(npcSettings_80240440) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80240420),
    .onDefeat = &N(80240430),
    .level = 13,
};

NpcAISettings N(npcAISettings_8024046C) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 15,
    .alertRadius = 150.0f,
    .unk_14 = 2,
    .chaseSpeed = 3.3f,
    .unk_1C = { .s = 70 },
    .unk_20 = 1,
    .chaseRadius = 180.0f,
    .unk_2C = 1,
};

EvtSource N(npcAI_8024049C) = SCRIPT({
    DoBasicAI(N(npcAISettings_8024046C));
});

NpcSettings N(npcSettings_802404BC) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_8024049C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

EvtSource N(idle_802404E8) = SCRIPT({
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_13));
    SetNpcJumpscale(NPC_SELF, 3.0);
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 30;
    PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
    NpcJump0(NPC_SELF, SI_VAR(0), 0, SI_VAR(2), 8);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_14));
    sleep 1;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_13));
    SI_VAR(0) -= 80;
    SetNpcJumpscale(NPC_SELF, 2.5);
    PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
    NpcJump0(NPC_SELF, SI_VAR(0), 0, SI_VAR(2), 12);
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_14));
    sleep 1;
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tubbas_heart, Palette_00, Anim_13));
    SI_VAR(0) -= 80;
    SetNpcJumpscale(NPC_SELF, 2.5);
    PlaySoundAtNpc(NPC_SELF, 0x20C8, 0);
    NpcJump0(NPC_SELF, SI_VAR(0), 0, SI_VAR(2), 12);
    EnableNpcShadow(NPC_SELF, FALSE);
    SetNpcPos(NPC_SELF, 0, -1000, 0);
    SI_STORY_PROGRESS = STORY_UNUSED_FFFFFFEC;
});

EvtSource N(defeat_802406E4) = SCRIPT({
    SI_SAVE_FLAG(1017) = 1;
    DoNpcDefeat();
});

EvtSource N(init_80240710) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_802404E8));
    if (SI_STORY_PROGRESS != STORY_UNUSED_FFFFFFEB) {
        RemoveNpc(NPC_SELF);
    }
});

EvtSource N(init_8024075C) = SCRIPT({
    if (SI_STORY_PROGRESS < STORY_CH4_FRYING_PAN_STOLEN) {
        if (SI_SAVE_FLAG(1017) == 1) {
            RemoveNpc(NPC_SELF);
            return;
        }
        BindNpcDefeat(NPC_SELF, N(defeat_802406E4));
    }
    BindNpcDefeat(NPC_SELF, N(defeat_802406E4));
});

StaticNpc N(npcGroup_802407DC) = {
    .id = 0,
    .settings = &N(npcSettings_80240440),
    .pos = { 80.0f, 50.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80240710),
    .yaw = 270,
    .dropFlags = 0x80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
        NPC_ANIM(tubbas_heart, Palette_00, Anim_1),
    },
};

StaticNpc N(npcGroup_802409CC) = {
    .id = 1,
    .settings = &N(npcSettings_802404BC),
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024075C),
    .yaw = 270,
    .dropFlags = 0x80,
    .itemDropChance = 20,
    { ITEM_DRIED_SHROOM, 10, 0 },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 0, 0, 0, 20, 0, -32767, 0, 0, 0, 0, 150, 0, 0, 1 },
    .animations = {
        NPC_ANIM(goomba, hyper, idle),
        NPC_ANIM(goomba, hyper, walk),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, idle),
        NPC_ANIM(goomba, hyper, idle),
        NPC_ANIM(goomba, hyper, pain),
        NPC_ANIM(goomba, hyper, pain),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
        NPC_ANIM(goomba, hyper, run),
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

NpcGroupList N(npcGroupList_80240BBC) = {
    NPC_GROUP(N(npcGroup_802407DC), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802409CC), BATTLE_ID(14, 1, 0, 5)),
    {},
};

EvtSource N(80240BE0) = SCRIPT({
    DisablePlayerInput(TRUE);
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x0183), 160, 40);
    DisablePlayerInput(FALSE);
});

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAFDC, 200, 0, -40, 0, MAKE_ENTITY_END);
    AssignScript(N(80240BE0));
});
