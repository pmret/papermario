#include "arn_05.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/world_tubba.h"

enum {
    NPC_BOO0,
    NPC_BOO1,
    NPC_BOO2,
    NPC_BOO3,
    NPC_BOO4,
    NPC_WORLD_TUBBA,
    NPC_BOO5,
    NPC_BOO6,
    NPC_BOO7,
    NPC_BOO8,
};

Script N(exitWalk_80241430) = EXIT_WALK_SCRIPT(60,  0, "arn_03",  1);

Script N(exitWalk_8024148C) = EXIT_WALK_SCRIPT(60,  1, "arn_02",  0);

Script N(802414E8) = SCRIPT({
    bind N(exitWalk_80241430) to TRIGGER_FLOOR_ABOVE 1;
    bind N(exitWalk_8024148C) to TRIGGER_FLOOR_ABOVE 5;
});

Script N(enterWalk_80241530) = SCRIPT({
    GetLoadType(SI_VAR(1));
    if (SI_VAR(1) == 1) {
        spawn EnterSavePoint;
        spawn N(802414E8);
        return;
    }
    SI_VAR(0) = N(802414E8);
    spawn EnterWalk;
    sleep 1;
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    if (STORY_PROGRESS < STORY_CH3_DEFEATED_TUBBA_BLUBBA) {
        MakeNpcs(0, N(npcGroupList_80244FA4));
    } else {
        MakeNpcs(0, N(npcGroupList_80244FC8));
    }
    await N(makeEntities);
    spawn N(802441FC);
    spawn N(80241360);
    spawn N(enterWalk_80241530);
});

static s32 N(pad_16A8)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_802416B0) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcAISettings N(npcAISettings_802416DC) = {
    .moveSpeed = 1.0f,
    .moveTime = 25,
    .waitTime = 30,
    .alertRadius = 50.0f,
    .unk_10 = { .f = 50.0f },
    .unk_14 = 10,
    .chaseRadius = 100.0f,
    .unk_28 = { .f = 80.0f },
    .unk_2C = 1,
};

Script N(npcAI_8024170C) = SCRIPT({
    N(func_8024113C_BE8D1C)(N(npcAISettings_802416DC));
});

NpcSettings N(npcSettings_8024172C) = {
    .height = 24,
    .radius = 24,
    .ai = &N(npcAI_8024170C),
    .level = 99,
};

NpcSettings N(npcSettings_80241758) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

Script N(idle_80241784) = SCRIPT({

});

Script N(interact_80241794) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(6) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0092));
                SI_AREA_FLAG(6) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0093));
                SI_AREA_FLAG(6) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0095));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0096));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0097));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0098));
        }
    }
});

Script N(interact_802418F4) = SCRIPT({
    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0094));
});

Script N(interact_80241924) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(7) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x0099));
                SI_AREA_FLAG(7) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x009A));
                SI_AREA_FLAG(7) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x009C));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x009D));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x009E));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x009F));
        }
    }
});

Script N(interact_80241A84) = SCRIPT({
    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x009B));
});

Script N(interact_80241AB4) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {}
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {}
        < STORY_CH3_BEGAN_PEACH_MISSION {}
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00A9));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            if (SI_SAVE_FLAG(1014) == 1) {
                if (SI_AREA_FLAG(9) == 1) {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_5), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AE));
                } else {
                    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B0));
                }
            } else {
                SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_7));
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_7), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AA));
                SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_9));
                ContinueSpeech(-1, NPC_ANIM(boo, Palette_01, Anim_9), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AB));
                SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_A));
                ContinueSpeech(-1, NPC_ANIM(boo, Palette_01, Anim_A), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AC));
                ShowChoice(1966110);
                match SI_VAR(0) {
                    == 0 {
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_5));
                        ContinueSpeech(-1, NPC_ANIM(boo, Palette_01, Anim_5), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AD));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_1));
                        SI_SAVE_FLAG(1014) = 1;
                        SI_AREA_FLAG(9) = 1;
                    }
                    == 1 {
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_5));
                        ContinueSpeech(-1, NPC_ANIM(boo, Palette_01, Anim_5), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AD));
                        SetNpcAnimation(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_1));
                        SI_SAVE_FLAG(1014) = 1;
                        SI_AREA_FLAG(9) = 1;
                    }
                    == 2 {
                        ContinueSpeech(-1, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00AF));
                    }
                }
            }
        }
    }
});

Script N(interact_80241D88) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {}
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {}
        < STORY_CH3_BEGAN_PEACH_MISSION {}
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B1));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B2));
        }
    }
});

Script N(interact_80241E28) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            if (SI_AREA_FLAG(8) == 0) {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B3));
                SI_AREA_FLAG(8) = 1;
            } else {
                SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B4));
                SI_AREA_FLAG(8) = 0;
            }
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B6));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B7));
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B8));
        }
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
            SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B9));
        }
    }
});

Script N(interact_80241F88) = SCRIPT({
    SpeakToPlayer(NPC_SELF, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00B5));
});

Script N(init_80241FB8) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH3_SAW_TUBBA_EAT_BOO) {
        BindNpcIdle(NPC_SELF, N(idle_80241784));
    }
    BindNpcInteract(NPC_SELF, N(interact_80241794));
});

Script N(init_80242008) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80241924));
});

Script N(init_8024202C) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80241AB4));
    match STORY_PROGRESS {
        < STORY_CH3_SAW_TUBBA_EAT_BOO {
            SetNpcFlagBits(NPC_SELF, NPC_FLAG_100, TRUE);
        }
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            SetNpcPos(NPC_SELF, 0, -1000, 0);
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            SetNpcPos(NPC_SELF, 0, -1000, 0);
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {}
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
        }
    }
});

Script N(init_8024212C) = SCRIPT({
    BindNpcInteract(NPC_SELF, N(interact_80241D88));
    match STORY_PROGRESS {
        < STORY_CH3_SAW_TUBBA_EAT_BOO {
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH3_DEFEATED_TUBBA_BLUBBA {
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            RemoveNpc(NPC_SELF);
        }
        < STORY_CH5_STAR_SPRIT_DEPARTED {}
        >= STORY_CH5_STAR_SPRIT_DEPARTED {
        }
    }
});

Script N(init_802421EC) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH3_SAW_TUBBA_EAT_BOO) {
        BindNpcIdle(NPC_SELF, N(idle_80241784));
    }
    BindNpcInteract(NPC_SELF, N(interact_80241E28));
});

StaticNpc N(npcGroup_8024223C)[] = {
    {
        .id = NPC_BOO0,
        .settings = &N(npcSettings_8024172C),
        .pos = { 55.0f, 195.0f, 160.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80241FB8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 55, 10, 160, 75, 10, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 55, 195, 160, 50 },
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00AE),
    },
    {
        .id = NPC_BOO1,
        .settings = &N(npcSettings_80241758),
        .pos = { 160.0f, 191.0f, 250.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80242008),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00AF),
    },
    {
        .id = NPC_BOO2,
        .settings = &N(npcSettings_80241758),
        .pos = { 390.0f, 190.0f, 255.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_8024202C),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00B0),
    },
    {
        .id = NPC_BOO3,
        .settings = &N(npcSettings_80241758),
        .pos = { 503.0f, 206.0f, 210.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_8024212C),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00B1),
    },
    {
        .id = NPC_BOO4,
        .settings = &N(npcSettings_8024172C),
        .pos = { 350.0f, 185.0f, 197.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802421EC),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 350, 10, 197, 330, 10, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 350, 185, 197, 50 },
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
        .tattle = MESSAGE_ID(0x1A, 0x00B2),
    },
};

Script N(80242BEC) = SCRIPT({
    loop SI_VAR(0) {
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_20F6, 0);
        ShakeCam(0, 0, 10, 0.5);
        sleep 5;
    }
});

Script N(80242C50) = SCRIPT({
    DisablePlayerInput(TRUE);
    NpcFacePlayer(NPC_BOO2, 1);
    PlaySoundAtNpc(NPC_BOO2, SOUND_UNKNOWN_262, 0);
    ShowEmote(2, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0);
    sleep 20;
    GetNpcPos(NPC_BOO2, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetPlayerPos(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(0) -= SI_VAR(3);
    SI_VAR(0) -= 50;
    SI_VAR(1) -= SI_VAR(4);
    SI_VAR(2) -= SI_VAR(5);
    GetNpcPos(NPC_BOO2, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(3) -= SI_VAR(0);
    SI_VAR(4) -= SI_VAR(1);
    SI_VAR(5) -= SI_VAR(2);
    NpcMoveTo(NPC_BOO2, SI_VAR(3), SI_VAR(5), 30);
    SetCamType(0, 6, 1);
    SetCamSpeed(0, 5.0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 350);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_BOO2, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 0, MESSAGE_ID(0x0E, 0x00A0));
    PlaySoundAt(SOUND_UNKNOWN_20F6, 0, 450, 200, 160);
    ShakeCam(0, 0, 20, 0.80078125);
    PlaySoundAtNpc(NPC_BOO0, SOUND_UNKNOWN_262, 0);
    PlaySoundAtNpc(NPC_BOO1, SOUND_UNKNOWN_262, 0);
    PlaySoundAtNpc(NPC_BOO2, SOUND_UNKNOWN_262, 0);
    PlaySoundAtNpc(NPC_BOO4, SOUND_UNKNOWN_262, 0);
    ShowEmote(0, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0);
    ShowEmote(1, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0);
    ShowEmote(2, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0);
    ShowEmote(4, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0);
    FadeOutMusic(0, 500);
    ClearAmbientSounds(250);
    sleep 20;
    InterpNpcYaw(NPC_BOO2, 90, 1);
    InterpNpcYaw(NPC_BOO4, 90, 1);
    sleep 20;
    PlaySound(SOUND_BOO_APPEAR);
    SI_VAR(0) = 240.0;
    loop 20 {
        SI_VAR(0) -= 12.0;
        func_802CFD30(NPC_BOO0, 7, SI_VAR(0), 0, 0, 0);
        func_802CFD30(NPC_BOO1, 7, SI_VAR(0), 0, 0, 0);
        func_802CFD30(NPC_BOO4, 7, SI_VAR(0), 0, 0, 0);
        sleep 1;
    }
    SetNpcPos(NPC_BOO0, 420, 300, 220);
    SetNpcPos(NPC_BOO1, 460, 250, 210);
    SetNpcPos(NPC_BOO4, 0, -1000, 0);
    EnableNpcShadow(NPC_BOO0, FALSE);
    EnableNpcShadow(NPC_BOO1, FALSE);
    EnableNpcShadow(NPC_BOO4, FALSE);
    PlaySound(SOUND_BOO_VANISH);
    SI_VAR(0) = 0.0;
    loop 20 {
        SI_VAR(0) += 12.0;
        func_802CFD30(NPC_BOO0, 7, SI_VAR(0), 0, 0, 0);
        func_802CFD30(NPC_BOO1, 7, SI_VAR(0), 0, 0, 0);
        sleep 1;
    }
    SpeakToPlayer(NPC_BOO2, NPC_ANIM(boo, Palette_01, Anim_6), NPC_ANIM(boo, Palette_01, Anim_6), 0, MESSAGE_ID(0x0E, 0x00A1));
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 9) {
        N(func_802412C8_BE8EA8)(9);
        spawn {
            SI_MAP_VAR(0) = 0;
            ShowMessageAtScreenPos(MESSAGE_ID(0x0E, 0x00A2), 160, 40);
            SI_MAP_VAR(0) = 1;
        }
        sleep 50;
        DisablePartnerAI(0);
        SetNpcYaw(NPC_PARTNER, 90);
        EnablePartnerAI();
        loop {
            sleep 1;
            if (SI_MAP_VAR(0) == 1) {
                break loop;
            }
        }
    }
    DisablePartnerAI(0);
    SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_bow, Palette_00, Anim_4), NPC_ANIM(world_bow, Palette_00, Anim_1), 0, MESSAGE_ID(0x0E, 0x00A3));
    EnablePartnerAI();
    InterpPlayerYaw(90, 0);
    sleep 5;
    N(func_802412B0_BE8E90)();
    CloseMessage();
    func_802D2B50();
    sleep 60;
    SetMusicTrack(0, SONG_TUBBAS_MANOR, 1, 8);
    SetCamType(0, 6, 1);
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 17.0, -11.5);
    SetCamDistance(0, 450);
    SetCamPosA(0, -40, 206);
    SetCamPosB(0, 530, 206);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 426, 190, 194);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SetNpcFlagBits(NPC_WORLD_TUBBA, NPC_FLAG_GRAVITY, TRUE);
    SetNpcSpeed(NPC_WORLD_TUBBA, 2.5);
    SetNpcPos(NPC_WORLD_TUBBA, 675, 200, 180);
    NpcFaceNpc(NPC_BOO0, NPC_WORLD_TUBBA, 1);
    NpcFaceNpc(NPC_BOO1, NPC_WORLD_TUBBA, 1);
    SetNpcPos(NPC_BOO2, 272, 190, 214);
    PlaySoundAtNpc(NPC_BOO0, SOUND_UNKNOWN_262, 0);
    PlaySoundAtNpc(NPC_BOO1, SOUND_UNKNOWN_262, 0);
    ShowEmote(0, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    ShowEmote(1, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0);
    spawn {
        PlaySound(SOUND_BOO_APPEAR);
        sleep 20;
        SI_VAR(0) = 240.0;
        loop 20 {
            SI_VAR(0) -= 12.0;
            func_802CFD30(NPC_BOO0, 7, SI_VAR(0), 0, 0, 0);
            func_802CFD30(NPC_BOO1, 7, SI_VAR(0), 0, 0, 0);
            sleep 1;
        }
        SetNpcPos(NPC_BOO0, 0, -1000, 0);
        SetNpcPos(NPC_BOO1, 0, -1000, 0);
        sleep 10;
    }
    SI_VAR(0) = 4;
    spawn N(80242BEC);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_9));
    NpcMoveTo(NPC_WORLD_TUBBA, 550, 196, 0);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    SetCamSpeed(0, 4.0);
    SetCamPitch(0, 17.0, -11.5);
    SetCamDistance(0, 375);
    SetCamPosA(0, -40, 206);
    SetCamPosB(0, 530, 206);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 426, 190, 194);
    PanToTarget(0, 0, 1);
    sleep 30;
    SI_MAP_VAR(1) = 0;
    spawn {
        SI_VAR(0) = 7;
        spawn N(80242BEC);
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_9));
        NpcMoveTo(NPC_WORLD_TUBBA, 370, 220, 0);
        GetNpcPos(NPC_BOO2, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        NpcMoveTo(NPC_WORLD_TUBBA, 330, SI_VAR(2), 0);
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_6));
        SI_MAP_VAR(1) = 1;
    }
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 17.0, -11.5);
    SetCamDistance(0, 375);
    SetCamPosA(0, -40, 206);
    SetCamPosB(0, 530, 206);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 240, 169, 206);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_BOO2, NPC_ANIM(boo, Palette_01, Anim_6), NPC_ANIM(boo, Palette_01, Anim_6), 0, MESSAGE_ID(0x0E, 0x00A4));
    sleep 15;
    loop {
        sleep 1;
        if (SI_MAP_VAR(1) == 1) {
            break loop;
        }
    }
    NpcFaceNpc(NPC_BOO2, NPC_WORLD_TUBBA, 1);
    sleep 30;
    SpeakToPlayer(NPC_BOO2, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x00A5));
    SetNpcAnimation(NPC_BOO2, NPC_ANIM(boo, Palette_01, Anim_9));
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1E));
    SetNpcJumpscale(NPC_BOO2, 0.0);
    NpcJump1(NPC_BOO2, 265, 206, 212, 3);
    sleep 20;
    SpeakToPlayer(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1E), NPC_ANIM(world_tubba, Palette_00, Anim_1E), 5, MESSAGE_ID(0x0E, 0x00A6));
    SetNpcPos(NPC_BOO2, 303, 237, 228);
    SetNpcAnimation(NPC_BOO2, NPC_ANIM(boo, Palette_01, Anim_6));
    EnableNpcShadow(NPC_BOO2, FALSE);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_1F));
    SetCamSpeed(0, 5.0);
    SetCamPitch(0, 17.0, -17.0);
    SetCamDistance(0, 250);
    SetCamPosA(0, -40, 206);
    SetCamPosB(0, 530, 206);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 280, 169, 206);
    PanToTarget(0, 0, 1);
    spawn {
        sleep 50;
        PlaySoundAtNpc(NPC_WORLD_TUBBA, SOUND_UNKNOWN_315, 0);
    }
    sleep 40;
    SetNpcPos(NPC_BOO2, 0, -1000, 0);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_20));
    sleep 80;
    SetCamSpeed(0, 90.0);
    SetCamPitch(0, 17.0, -11.5);
    SetCamDistance(0, 375);
    SetCamPosA(0, -40, 206);
    SetCamPosB(0, 530, 206);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 240, 169, 206);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    sleep 15;
    SpeakToPlayer(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_21), NPC_ANIM(world_tubba, Palette_00, Anim_6), 5, MESSAGE_ID(0x0E, 0x00A7));
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_21));
    GetNpcPos(NPC_WORLD_TUBBA, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -50;
    SI_VAR(1) += 50;
    SI_VAR(2) += 10;
    PlayEffect(0x6, 1, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 20;
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    InterpNpcYaw(NPC_WORLD_TUBBA, 90, 1);
    sleep 30;
    SI_VAR(0) = 7;
    spawn N(80242BEC);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_9));
    NpcMoveTo(NPC_WORLD_TUBBA, 370, 220, 0);
    NpcMoveTo(NPC_WORLD_TUBBA, 550, 196, 0);
    SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    SetNpcPos(NPC_WORLD_TUBBA, 0, -1000, 0);
    SetNpcFlagBits(NPC_WORLD_TUBBA, NPC_FLAG_GRAVITY, FALSE);
    NpcFacePlayer(NPC_BOO0, 3);
    SetNpcPos(NPC_BOO0, 55, 195, 160);
    SetNpcPos(NPC_BOO1, 160, 191, 250);
    SetNpcPos(NPC_BOO4, 350, 185, 197);
    EnableNpcShadow(NPC_BOO0, TRUE);
    EnableNpcShadow(NPC_BOO1, TRUE);
    EnableNpcShadow(NPC_BOO4, TRUE);
    PlaySound(SOUND_BOO_VANISH);
    SI_VAR(0) = 0.0;
    loop 20 {
        SI_VAR(0) += 12.5;
        func_802CFD30(NPC_BOO0, 7, SI_VAR(0), 0, 0, 0);
        func_802CFD30(NPC_BOO1, 7, SI_VAR(0), 0, 0, 0);
        func_802CFD30(NPC_BOO4, 7, SI_VAR(0), 0, 0, 0);
        sleep 1;
    }
    func_802CFD30(NPC_BOO0, 0, 0, 0, 0, 0);
    func_802CFD30(NPC_BOO1, 0, 0, 0, 0, 0);
    func_802CFD30(NPC_BOO4, 0, 0, 0, 0, 0);
    sleep 10;
    SetCamType(0, 4, 0);
    SetCamSpeed(0, 3.0);
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    PanToTarget(0, 0, 0);
    SpeakToPlayer(NPC_BOO4, NPC_ANIM(boo, Palette_01, Anim_4), NPC_ANIM(boo, Palette_01, Anim_1), 5, MESSAGE_ID(0x0E, 0x00A8));
    DisablePlayerInput(FALSE);
});

Script N(802441FC) = SCRIPT({
    if (STORY_PROGRESS < STORY_CH3_SAW_TUBBA_EAT_BOO) {
        SetNpcPos(NPC_BOO2, 330, 184, 240);
        loop {
            SI_VAR(10) = 0;
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            if (SI_VAR(2) >= 110) {
                if (SI_VAR(0) >= 220) {
                    SI_VAR(10) = 1;
                }
            }
            if (SI_VAR(10) == 1) {
                break loop;
            }
            sleep 1;
        }
        func_802D2B6C();
        await N(80242C50);
        BindNpcInteract(NPC_BOO0, N(interact_802418F4));
        BindNpcInteract(NPC_BOO1, N(interact_80241A84));
        BindNpcInteract(NPC_BOO4, N(interact_80241F88));
        STORY_PROGRESS = STORY_CH3_SAW_TUBBA_EAT_BOO;
        spawn N(80241360);
    }
});

Script N(init_80244358) = SCRIPT({
    if (STORY_PROGRESS >= STORY_CH3_SAW_TUBBA_EAT_BOO) {
        RemoveNpc(NPC_SELF);
    }
});

NpcAnimID N(extraAnimationList_80244390)[] = {
    NPC_ANIM(world_tubba, Palette_00, Anim_6),
    NPC_ANIM(world_tubba, Palette_00, Anim_9),
    NPC_ANIM(world_tubba, Palette_00, Anim_1E),
    NPC_ANIM(world_tubba, Palette_00, Anim_1F),
    NPC_ANIM(world_tubba, Palette_00, Anim_20),
    NPC_ANIM(world_tubba, Palette_00, Anim_21),
    ANIM_END,
};

StaticNpc N(npcGroup_802443AC) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802416B0),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80244358),
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
    .extraAnimations = N(extraAnimationList_80244390),
};

Script N(idle_8024459C) = SCRIPT({
    GetNpcPos(NPC_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = SI_VAR(0);
    SI_VAR(3) += -60;
    SI_VAR(4) = SI_VAR(0);
    SI_VAR(4) += 60;
    loop {
        RandInt(5, SI_VAR(5));
        SI_VAR(6) = (float) SI_VAR(5);
        SI_VAR(6) *= 0.1005859375;
        SI_VAR(6) += 0.80078125;
        SetNpcSpeed(NPC_SELF, SI_VAR(6));
        NpcMoveTo(NPC_SELF, SI_VAR(3), SI_VAR(2), 0);
        RandInt(5, SI_VAR(5));
        SI_VAR(6) = (float) SI_VAR(5);
        SI_VAR(6) *= 0.1005859375;
        SI_VAR(6) += 0.80078125;
        SetNpcSpeed(NPC_SELF, SI_VAR(6));
        NpcMoveTo(NPC_SELF, SI_VAR(4), SI_VAR(2), 0);
    }
});

Script N(init_80244704) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_8024459C));
    EnableNpcShadow(NPC_SELF, FALSE);
});

Script N(init_8024473C) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_8024459C));
    EnableNpcShadow(NPC_SELF, FALSE);
});

Script N(init_80244774) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_8024459C));
    EnableNpcShadow(NPC_SELF, FALSE);
});

Script N(init_802447AC) = SCRIPT({
    BindNpcIdle(NPC_SELF, N(idle_8024459C));
    EnableNpcShadow(NPC_SELF, FALSE);
});

StaticNpc N(npcGroup_802447E4)[] = {
    {
        .id = NPC_BOO5,
        .settings = &N(npcSettings_80241758),
        .pos = { 36.0f, 277.0f, 140.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80244704),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
    },
    {
        .id = NPC_BOO6,
        .settings = &N(npcSettings_80241758),
        .pos = { 200.0f, 275.0f, 182.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_8024473C),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
    },
    {
        .id = NPC_BOO7,
        .settings = &N(npcSettings_80241758),
        .pos = { 379.0f, 300.0f, 192.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80244774),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
    },
    {
        .id = NPC_BOO8,
        .settings = &N(npcSettings_80241758),
        .pos = { 525.0f, 286.0f, 178.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_802447AC),
        .yaw = 90,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_2),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_1),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_0),
            NPC_ANIM(boo, Palette_01, Anim_A),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
            NPC_ANIM(boo, Palette_01, Anim_3),
        },
    },
};

NpcGroupList N(npcGroupList_80244FA4) = {
    NPC_GROUP(N(npcGroup_802443AC), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_8024223C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80244FC8) = {
    NPC_GROUP(N(npcGroup_802443AC), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_8024223C), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_802447E4), BATTLE_ID(0, 0, 0, 0)),
    {},
};

static s32 N(pad_4FF8)[] = {
    0x00000000, 0x00000000,
};

Script N(makeEntities) = SCRIPT({
    MakeEntity(0x802EA7E0, 17, 238, 80, 0, MAKE_ENTITY_END);
});

void N(func_80240000_BE7BE0)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;

    script->functionTemp[1].s = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->functionTemp[2].s = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        ret = dist2D(posX, posZ, i[enemy->territory->patrol.points].x, i[enemy->territory->patrol.points].z);
        if (ret < max) {
            max = ret;
            script->functionTemp[2].s = j;
        }
    }

    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
}

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

void N(func_8024067C_BE825C)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
}

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80240B94_BE8774)(ScriptInstance* script, s32 isInitialCall) {
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
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_BE7BE0)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(func_8024067C_BE825C)(script, aiSettings, territoryPtr);
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
    }

    return ApiStatus_BLOCK;
}

void N(func_80240E90_BE8A70)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f20;
    f32 temp_f22;

    posX = npc->pos.x;
    posZ = npc->pos.z;
    temp_f22 = script->functionTemp[2].s[enemy->territory->patrol.points].x;
    temp_f20 = script->functionTemp[2].s[enemy->territory->patrol.points].z;

    npc->yaw = atan2(posX, posZ, temp_f22, temp_f20);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    posX = npc->pos.x;
    posY = npc->pos.y + script->functionTemp[2].s[enemy->territory->patrol.points].y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
    posY += script->functionTemp[2].s[enemy->territory->patrol.points].y;
    posW = posY - npc->pos.y;
    if (posW > 2.0) {
        npc->pos.y += 2.0;
    } else if (posW < -2.0) {
        npc->pos.y -= 2.0;
    } else {
        npc->pos.y = posY;
    }

    posW = dist2D(npc->pos.x, npc->pos.z, temp_f22, temp_f20);
    if (!(posW > npc->moveSpeed)) {
        script->functionTemp[0].s = 2;
    }
}

void N(func_80241068_BE8C48)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration < 0) {
        script->functionTemp[1].s--;
        if (script->functionTemp[1].s >= 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
        } else {
            script->functionTemp[0].s = 4;
            npc->currentAnim = enemy->animList[0];
        }
    }
}

ApiStatus N(func_8024113C_BE8D1C)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240000_BE7BE0)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240E90_BE8A70)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80241068_BE8C48)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(func_8024067C_BE825C)(script, aiSettings, territoryPtr);
    }

    enemy->varTable[0] = npc->pos.y;
    return ApiStatus_BLOCK;
}

ApiStatus N(func_802412B0_BE8E90)(ScriptInstance* script, s32 isInitialCall) {
    return (gGameStatusPtr->pressedButtons >> 1) & ApiStatus_DONE2;
}

ApiStatus N(func_802412C8_BE8EA8)(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
