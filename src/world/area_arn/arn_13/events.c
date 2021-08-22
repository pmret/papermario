#include "arn_13.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/tubbas_heart.h"

EvtSource N(exitSingleDoor_80240100) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 0;
    SI_VAR(1) = 2;
    SI_VAR(2) = 0;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_12", 1);
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
    GotoMap("arn_11", 0);
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
    SetSpriteShading(524292);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80240BCC));
    await N(makeEntities);
    spawn N(80240060);
    spawn N(enterSingleDoor_80240290);
    sleep 1;
});

static s32 N(pad_424)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(80240430) = SCRIPT({

});

EvtSource N(80240440) = SCRIPT({

});

NpcSettings N(npcSettings_80240450) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80240430),
    .onDefeat = &N(80240440),
    .level = 13,
};

NpcAISettings N(npcAISettings_8024047C) = {
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

EvtSource N(npcAI_802404AC) = SCRIPT({
    DoBasicAI(N(npcAISettings_8024047C));
});

NpcSettings N(npcSettings_802404CC) = {
    .height = 20,
    .radius = 23,
    .ai = &N(npcAI_802404AC),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
};

EvtSource N(idle_802404F8) = SCRIPT({
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
    SI_STORY_PROGRESS = STORY_CH3_HEART_FLED_SECOND_TUNNEL;
});

EvtSource N(defeat_802406F4) = SCRIPT({
    SI_SAVE_FLAG(1018) = 1;
    DoNpcDefeat();
});

EvtSource N(init_80240720) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_802404F8));
    if (SI_STORY_PROGRESS != STORY_CH3_HEART_FLED_FIRST_TUNNEL) {
        RemoveNpc(NPC_SELF);
    }
});

EvtSource N(init_8024076C) = SCRIPT({
    if (SI_STORY_PROGRESS < STORY_CH4_FRYING_PAN_STOLEN) {
        if (SI_SAVE_FLAG(1018) == 1) {
            RemoveNpc(NPC_SELF);
            return;
        }
        BindNpcDefeat(NPC_SELF, N(defeat_802406F4));
    }
    BindNpcDefeat(NPC_SELF, N(defeat_802406F4));
});

StaticNpc N(npcGroup_802407EC) = {
    .id = 0,
    .settings = &N(npcSettings_80240450),
    .pos = { 80.0f, 50.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80240720),
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

StaticNpc N(npcGroup_802409DC) = {
    .id = 1,
    .settings = &N(npcSettings_802404CC),
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024076C),
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

NpcGroupList N(npcGroupList_80240BCC) = {
    NPC_GROUP(N(npcGroup_802407EC), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802409DC), BATTLE_ID(14, 2, 0, 5)),
    {},
};

EvtSource N(80240BF0) = SCRIPT({
    DisablePlayerInput(TRUE);
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x0184), 160, 40);
    DisablePlayerInput(FALSE);
});

EvtSource N(makeEntities) = SCRIPT({
    MakeEntity(0x802EAFDC, 200, 0, -40, 0, MAKE_ENTITY_END);
    AssignScript(N(80240BF0));
});
