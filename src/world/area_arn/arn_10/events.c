#include "arn_10.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/goomba.h"

Script N(script_ExitSingleDoor_80240100) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 0;
    SI_VAR(1) = 6;
    SI_VAR(2) = 0;
    SI_VAR(3) = -1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_09", 0);
    sleep 100;
});

Script N(script_ExitSingleDoor_802401A4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 1;
    SI_VAR(1) = 11;
    SI_VAR(2) = 2;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_12", 0);
    sleep 100;
});

Script N(script_80240248) = SCRIPT({
    bind N(script_ExitSingleDoor_80240100) to TRIGGER_WALL_PRESS_A 6;
    bind N(script_ExitSingleDoor_802401A4) to TRIGGER_WALL_PRESS_A 11;
});

Script N(script_EnterSingleDoor_80240290) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SI_VAR(2) = 0;
            SI_VAR(3) = -1;
            await EnterSingleDoor;
            spawn N(script_80240248);
        }
        == 1 {
            SI_VAR(2) = 2;
            SI_VAR(3) = 1;
            await EnterSingleDoor;
            spawn N(script_80240248);
        }
    }
});

Script N(script_Main) = SCRIPT({
    WORLD_LOCATION = LOCATION_WINDY_MILL;
    SetSpriteShading(524289);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80240BB8));
    await N(script_MakeEntities);
    spawn N(script_80240060);
    spawn N(script_EnterSingleDoor_80240290);
    sleep 1;
});

static s32 N(pad_424)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

Script N(script_80240430) = SCRIPT({

});

Script N(script_80240440) = SCRIPT({

});

NpcSettings N(npcSettings_80240450) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(script_80240430),
    .onDefeat = &N(script_80240440),
    .level = 13,
};

NpcAISettings N(aISettings_8024047C) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 15,
    .alertRadius = 150.0f,
    .unk_14 = 2,
    .chaseSpeed = 3.3f,
    .unk_1C = 70,
    .unk_20 = 1,
    .chaseRadius = 180.0f,
    .unk_2C = 1,
};

Script N(script_NpcAI_802404AC) = SCRIPT({
    DoBasicAI(N(aISettings_8024047C));
});

NpcSettings N(npcSettings_802404CC) = {
    .height = 20,
    .radius = 23,
    .ai = &N(script_NpcAI_802404AC),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 12,
};

Script N(script_Idle_802404F8) = SCRIPT({
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
    STORY_PROGRESS = STORY_CH3_HEART_FLED_SECOND_TUNNEL;
});

Script N(script_Defeat_802406F4) = SCRIPT({
    SI_SAVE_FLAG(1016) = 1;
    DoNpcDefeat();
});

Script N(script_Init_80240720) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(script_Idle_802404F8));
    if (STORY_PROGRESS != STORY_UNUSED_FFFFFFEC) {
        RemoveNpc(NPC_SELF);
    }
});

Script N(script_Init_8024076C) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH4_FRYING_PAN_STOLEN) {
        if (SI_SAVE_FLAG(1016) == 1) {
            RemoveNpc(NPC_SELF);
            return;
        }
        BindNpcDefeat(NPC_SELF, N(script_Defeat_802406F4));
    }
});

StaticNpc N(npcGroup_802407D8) = {
    .id = 0,
    .settings = &N(npcSettings_80240450),
    .pos = { 80.0f, 50.0f, 0.0f },
    .flags = 0x00000D05,
    .init = &N(script_Init_80240720),
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

StaticNpc N(npcGroup_802409C8) = {
    .id = 1,
    .settings = &N(npcSettings_802404CC),
    .flags = 0x00000C00,
    .init = &N(script_Init_8024076C),
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

NpcGroupList N(npcGroupList_80240BB8) = {
    NPC_GROUP(N(npcGroup_802407D8), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802409C8), BATTLE_ID(14, 0, 0, 5)),
    {},
};

static s32 N(pad_BDC)[] = {
    0x00000000,
};

Script N(script_80240BE0) = SCRIPT({
    DisablePlayerInput(TRUE);
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x0182), 160, 40);
    DisablePlayerInput(FALSE);
});

Script N(script_MakeEntities) = SCRIPT({
    MakeEntity(0x802EAFDC, 200, 0, -40, 0, ARGS_END);
    AssignScript(N(script_80240BE0));
});
