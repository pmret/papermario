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

EvtSource N(exitWalk_80241430) = EXIT_WALK_SCRIPT(60,  0, "arn_03",  1);

EvtSource N(exitWalk_8024148C) = EXIT_WALK_SCRIPT(60,  1, "arn_02",  0);

EvtSource N(802414E8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80241430), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_8024148C), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterWalk_80241530) = {
    EVT_CALL(GetLoadType, EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(802414E8))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_VAR(0), EVT_PTR(N(802414E8)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT_FRAMES(1)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_IF_LT(EVT_SAVE_VAR(0), -16)
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244FA4)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244FC8)))
    EVT_END_IF
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802441FC))
    EVT_EXEC(N(80241360))
    EVT_EXEC(N(enterWalk_80241530))
    EVT_RETURN
    EVT_END
};

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

EvtSource N(npcAI_8024170C) = {
    EVT_CALL(N(func_8024113C_BE8D1C), EVT_PTR(N(npcAISettings_802416DC)))
    EVT_RETURN
    EVT_END
};

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

EvtSource N(idle_80241784) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241794) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(6), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0092))
                EVT_SET(EVT_AREA_FLAG(6), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0093))
                EVT_SET(EVT_AREA_FLAG(6), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0095))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0096))
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0097))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0098))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_802418F4) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0094))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241924) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(7), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x0099))
                EVT_SET(EVT_AREA_FLAG(7), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x009A))
                EVT_SET(EVT_AREA_FLAG(7), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x009C))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x009D))
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x009E))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x009F))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241A84) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x009B))
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241AB4) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
        EVT_CASE_LT(-16)
        EVT_CASE_LT(-14)
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00A9))
        EVT_CASE_GE(39)
            EVT_IF_EQ(EVT_SAVE_FLAG(1014), 1)
                EVT_IF_EQ(EVT_AREA_FLAG(9), 1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_5, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AE))
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B0))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_7)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_7, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AA))
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_9)
                EVT_CALL(ContinueSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_9, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AB))
                EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_A)
                EVT_CALL(ContinueSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_A, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AC))
                EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x001E))
                EVT_SWITCH(EVT_VAR(0))
                    EVT_CASE_EQ(0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_5)
                        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_5, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AD))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_1)
                        EVT_SET(EVT_SAVE_FLAG(1014), 1)
                        EVT_SET(EVT_AREA_FLAG(9), 1)
                    EVT_CASE_EQ(1)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_5)
                        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_5, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AD))
                        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_1)
                        EVT_SET(EVT_SAVE_FLAG(1014), 1)
                        EVT_SET(EVT_AREA_FLAG(9), 1)
                    EVT_CASE_EQ(2)
                        EVT_CALL(ContinueSpeech, -1, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00AF))
                EVT_END_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241D88) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
        EVT_CASE_LT(-16)
        EVT_CASE_LT(-14)
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B1))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B2))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241E28) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-26)
            EVT_IF_EQ(EVT_AREA_FLAG(8), 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B3))
                EVT_SET(EVT_AREA_FLAG(8), 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B4))
                EVT_SET(EVT_AREA_FLAG(8), 0)
            EVT_END_IF
        EVT_CASE_LT(-16)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B6))
        EVT_CASE_LT(-14)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B7))
        EVT_CASE_LT(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B8))
        EVT_CASE_GE(39)
            EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B9))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(interact_80241F88) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00B5))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80241FB8) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), -33)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80241784)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241794)))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80242008) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241924)))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024202C) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241AB4)))
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-33)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
        EVT_CASE_LT(-26)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(-16)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(-14)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(39)
        EVT_CASE_GE(39)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024212C) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241D88)))
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-33)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(-26)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(-16)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(-14)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(39)
        EVT_CASE_GE(39)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802421EC) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), -33)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80241784)))
    EVT_END_IF
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241E28)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_8024223C)[] = {
    {
        .id = NPC_BOO0,
        .settings = &N(npcSettings_8024172C),
        .pos = { 55.0f, 195.0f, 160.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_80241FB8),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 55, 10, 160, 75, 10, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 55, 195, 160, 50 },
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
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
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
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
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
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
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
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
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .movement = { 2, 350, 10, 197, 330, 10, 197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 350, 185, 197, 50 },
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
        .tattle = MESSAGE_ID(0x1A, 0x00B2),
    },
};

EvtSource N(80242BEC) = {
    EVT_LOOP(EVT_VAR(0))
        EVT_CALL(PlaySoundAtNpc, 5, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FIXED(0.5))
        EVT_WAIT_FRAMES(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(80242C50) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcFacePlayer, 2, 1)
    EVT_CALL(PlaySoundAtNpc, 2, SOUND_262, 0)
    EVT_CALL(ShowEmote, 2, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetPlayerPos, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_SUB(EVT_VAR(0), EVT_VAR(3))
    EVT_SUB(EVT_VAR(0), 50)
    EVT_SUB(EVT_VAR(1), EVT_VAR(4))
    EVT_SUB(EVT_VAR(2), EVT_VAR(5))
    EVT_CALL(GetNpcPos, 2, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_SUB(EVT_VAR(3), EVT_VAR(0))
    EVT_SUB(EVT_VAR(4), EVT_VAR(1))
    EVT_SUB(EVT_VAR(5), EVT_VAR(2))
    EVT_CALL(NpcMoveTo, 2, EVT_VAR(3), EVT_VAR(5), 30)
    EVT_CALL(SetCamType, 0, 6, 1)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(5.0))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, 350)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00A0))
    EVT_CALL(PlaySoundAt, SOUND_20F6, 0, 450, 200, 160)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FIXED(0.8))
    EVT_CALL(PlaySoundAtNpc, 0, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 1, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 2, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 4, SOUND_262, 0)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 1, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 2, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 4, EMOTE_EXCLAMATION, -45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(InterpNpcYaw, 2, 90, 1)
    EVT_CALL(InterpNpcYaw, 4, 90, 1)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySound, SOUND_BOO_APPEAR)
    EVT_SETF(EVT_VAR(0), EVT_FIXED(240.0))
    EVT_LOOP(20)
        EVT_SUBF(EVT_VAR(0), EVT_FIXED(12.0))
        EVT_CALL(func_802CFD30, 0, 7, EVT_VAR(0), 0, 0, 0)
        EVT_CALL(func_802CFD30, 1, 7, EVT_VAR(0), 0, 0, 0)
        EVT_CALL(func_802CFD30, 4, 7, EVT_VAR(0), 0, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, 0, 420, 300, 220)
    EVT_CALL(SetNpcPos, 1, 460, 250, 210)
    EVT_CALL(SetNpcPos, 4, 0, -1000, 0)
    EVT_CALL(EnableNpcShadow, 0, FALSE)
    EVT_CALL(EnableNpcShadow, 1, FALSE)
    EVT_CALL(EnableNpcShadow, 4, FALSE)
    EVT_CALL(PlaySound, SOUND_BOO_VANISH)
    EVT_SETF(EVT_VAR(0), EVT_FIXED(0.0))
    EVT_LOOP(20)
        EVT_ADDF(EVT_VAR(0), EVT_FIXED(12.0))
        EVT_CALL(func_802CFD30, 0, 7, EVT_VAR(0), 0, 0, 0)
        EVT_CALL(func_802CFD30, 1, 7, EVT_VAR(0), 0, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_boo_Palette_01_Anim_6, NPC_ANIM_boo_Palette_01_Anim_6, 0, MESSAGE_ID(0x0E, 0x00A1))
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 9)
        EVT_CALL(N(SwitchToPartner), 9)
        EVT_THREAD
            EVT_SET(EVT_MAP_VAR(0), 0)
            EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x0E, 0x00A2), 160, 40)
            EVT_SET(EVT_MAP_VAR(0), 1)
        EVT_END_THREAD
        EVT_WAIT_FRAMES(50)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
        EVT_CALL(EnablePartnerAI)
        EVT_LOOP(0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_MAP_VAR(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00A3))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(N(func_802412B0_BE8E90))
    EVT_CALL(CloseMessage)
    EVT_CALL(func_802D2B50)
    EVT_WAIT_FRAMES(60)
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 1, 8)
    EVT_CALL(SetCamType, 0, 6, 1)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-11.5))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(SetCamPosA, 0, -40, 206)
    EVT_CALL(SetCamPosB, 0, 530, 206)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 426, 190, 194)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_GRAVITY)), TRUE)
    EVT_CALL(SetNpcSpeed, 5, EVT_FIXED(2.5))
    EVT_CALL(SetNpcPos, 5, 675, 200, 180)
    EVT_CALL(NpcFaceNpc, 0, 5, 1)
    EVT_CALL(NpcFaceNpc, 1, 5, 1)
    EVT_CALL(SetNpcPos, 2, 272, 190, 214)
    EVT_CALL(PlaySoundAtNpc, 0, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 1, SOUND_262, 0)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 1, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_BOO_APPEAR)
        EVT_WAIT_FRAMES(20)
        EVT_SETF(EVT_VAR(0), EVT_FIXED(240.0))
        EVT_LOOP(20)
            EVT_SUBF(EVT_VAR(0), EVT_FIXED(12.0))
            EVT_CALL(func_802CFD30, 0, 7, EVT_VAR(0), 0, 0, 0)
            EVT_CALL(func_802CFD30, 1, 7, EVT_VAR(0), 0, 0, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
        EVT_CALL(SetNpcPos, 1, 0, -1000, 0)
        EVT_WAIT_FRAMES(10)
    EVT_END_THREAD
    EVT_SET(EVT_VAR(0), 4)
    EVT_EXEC(N(80242BEC))
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_9)
    EVT_CALL(NpcMoveTo, 5, 550, 196, 0)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-11.5))
    EVT_CALL(SetCamDistance, 0, 375)
    EVT_CALL(SetCamPosA, 0, -40, 206)
    EVT_CALL(SetCamPosB, 0, 530, 206)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 426, 190, 194)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT_FRAMES(30)
    EVT_SET(EVT_MAP_VAR(1), 0)
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 7)
        EVT_EXEC(N(80242BEC))
        EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_9)
        EVT_CALL(NpcMoveTo, 5, 370, 220, 0)
        EVT_CALL(GetNpcPos, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcMoveTo, 5, 330, EVT_VAR(2), 0)
        EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_6)
        EVT_SET(EVT_MAP_VAR(1), 1)
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-11.5))
    EVT_CALL(SetCamDistance, 0, 375)
    EVT_CALL(SetCamPosA, 0, -40, 206)
    EVT_CALL(SetCamPosB, 0, 530, 206)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 240, 169, 206)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_boo_Palette_01_Anim_6, NPC_ANIM_boo_Palette_01_Anim_6, 0, MESSAGE_ID(0x0E, 0x00A4))
    EVT_WAIT_FRAMES(15)
    EVT_LOOP(0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_MAP_VAR(1), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(NpcFaceNpc, 2, 5, 1)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SpeakToPlayer, 2, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00A5))
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_boo_Palette_01_Anim_9)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_1E)
    EVT_CALL(SetNpcJumpscale, 2, EVT_FIXED(0.0))
    EVT_CALL(NpcJump1, 2, 265, 206, 212, 3)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_world_tubba_Palette_00_Anim_1E, NPC_ANIM_world_tubba_Palette_00_Anim_1E, 5, MESSAGE_ID(0x0E, 0x00A6))
    EVT_CALL(SetNpcPos, 2, 303, 237, 228)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(EnableNpcShadow, 2, FALSE)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_1F)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(5.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-17.0))
    EVT_CALL(SetCamDistance, 0, 250)
    EVT_CALL(SetCamPosA, 0, -40, 206)
    EVT_CALL(SetCamPosB, 0, 530, 206)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 280, 169, 206)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_THREAD
        EVT_WAIT_FRAMES(50)
        EVT_CALL(PlaySoundAtNpc, 5, SOUND_315, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SetNpcPos, 2, 0, -1000, 0)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_20)
    EVT_WAIT_FRAMES(80)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(17.0), EVT_FIXED(-11.5))
    EVT_CALL(SetCamDistance, 0, 375)
    EVT_CALL(SetCamPosA, 0, -40, 206)
    EVT_CALL(SetCamPosB, 0, 530, 206)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 240, 169, 206)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SpeakToPlayer, 5, NPC_ANIM_world_tubba_Palette_00_Anim_21, NPC_ANIM_world_tubba_Palette_00_Anim_6, 5, MESSAGE_ID(0x0E, 0x00A7))
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_21)
    EVT_CALL(GetNpcPos, 5, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), -50)
    EVT_ADD(EVT_VAR(1), 50)
    EVT_ADD(EVT_VAR(2), 10)
    EVT_CALL(PlayEffect, 0x6, 1, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_CALL(InterpNpcYaw, 5, 90, 1)
    EVT_WAIT_FRAMES(30)
    EVT_SET(EVT_VAR(0), 7)
    EVT_EXEC(N(80242BEC))
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_9)
    EVT_CALL(NpcMoveTo, 5, 370, 220, 0)
    EVT_CALL(NpcMoveTo, 5, 550, 196, 0)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_CALL(SetNpcPos, 5, 0, -1000, 0)
    EVT_CALL(SetNpcFlagBits, 5, ((NPC_FLAG_GRAVITY)), FALSE)
    EVT_CALL(NpcFacePlayer, 0, 3)
    EVT_CALL(SetNpcPos, 0, 55, 195, 160)
    EVT_CALL(SetNpcPos, 1, 160, 191, 250)
    EVT_CALL(SetNpcPos, 4, 350, 185, 197)
    EVT_CALL(EnableNpcShadow, 0, TRUE)
    EVT_CALL(EnableNpcShadow, 1, TRUE)
    EVT_CALL(EnableNpcShadow, 4, TRUE)
    EVT_CALL(PlaySound, SOUND_BOO_VANISH)
    EVT_SETF(EVT_VAR(0), EVT_FIXED(0.0))
    EVT_LOOP(20)
        EVT_ADDF(EVT_VAR(0), EVT_FIXED(12.5))
        EVT_CALL(func_802CFD30, 0, 7, EVT_VAR(0), 0, 0, 0)
        EVT_CALL(func_802CFD30, 1, 7, EVT_VAR(0), 0, 0, 0)
        EVT_CALL(func_802CFD30, 4, 7, EVT_VAR(0), 0, 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(func_802CFD30, 0, 0, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, 1, 0, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, 4, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetCamType, 0, 4, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(3.0))
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00A8))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(802441FC) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), -33)
        EVT_CALL(SetNpcPos, 2, 330, 184, 240)
        EVT_LOOP(0)
            EVT_SET(EVT_VAR(10), 0)
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_IF_GE(EVT_VAR(2), 110)
                EVT_IF_GE(EVT_VAR(0), 220)
                    EVT_SET(EVT_VAR(10), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(EVT_VAR(10), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(func_802D2B6C)
        EVT_EXEC_WAIT(N(80242C50))
        EVT_CALL(BindNpcInteract, 0, EVT_PTR(N(interact_802418F4)))
        EVT_CALL(BindNpcInteract, 1, EVT_PTR(N(interact_80241A84)))
        EVT_CALL(BindNpcInteract, 4, EVT_PTR(N(interact_80241F88)))
        EVT_SET(EVT_SAVE_VAR(0), -33)
        EVT_EXEC(N(80241360))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80244358) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), -33)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(extraAnimationList_80244390)[] = {
    NPC_ANIM_world_tubba_Palette_00_Anim_6,
    NPC_ANIM_world_tubba_Palette_00_Anim_9,
    NPC_ANIM_world_tubba_Palette_00_Anim_1E,
    NPC_ANIM_world_tubba_Palette_00_Anim_1F,
    NPC_ANIM_world_tubba_Palette_00_Anim_20,
    NPC_ANIM_world_tubba_Palette_00_Anim_21,
    ANIM_END,
};

StaticNpc N(npcGroup_802443AC) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802416B0),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80244358),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_6,
        NPC_ANIM_world_tubba_Palette_00_Anim_9,
        NPC_ANIM_world_tubba_Palette_00_Anim_C,
        NPC_ANIM_world_tubba_Palette_00_Anim_C,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
    },
    .extraAnimations = N(extraAnimationList_80244390),
};

EvtSource N(idle_8024459C) = {
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_ADD(EVT_VAR(3), -60)
    EVT_SET(EVT_VAR(4), EVT_VAR(0))
    EVT_ADD(EVT_VAR(4), 60)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, EVT_VAR(5))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_MULF(EVT_VAR(6), EVT_FIXED(0.1))
        EVT_ADDF(EVT_VAR(6), EVT_FIXED(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_VAR(6))
        EVT_CALL(NpcMoveTo, NPC_SELF, EVT_VAR(3), EVT_VAR(2), 0)
        EVT_CALL(RandInt, 5, EVT_VAR(5))
        EVT_SETF(EVT_VAR(6), EVT_VAR(5))
        EVT_MULF(EVT_VAR(6), EVT_FIXED(0.1))
        EVT_ADDF(EVT_VAR(6), EVT_FIXED(0.8))
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_VAR(6))
        EVT_CALL(NpcMoveTo, NPC_SELF, EVT_VAR(4), EVT_VAR(2), 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80244704) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024459C)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024473C) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024459C)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80244774) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024459C)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_802447AC) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024459C)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802447E4)[] = {
    {
        .id = NPC_BOO5,
        .settings = &N(npcSettings_80241758),
        .pos = { 36.0f, 277.0f, 140.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80244704),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
    },
    {
        .id = NPC_BOO6,
        .settings = &N(npcSettings_80241758),
        .pos = { 200.0f, 275.0f, 182.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_8024473C),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
    },
    {
        .id = NPC_BOO7,
        .settings = &N(npcSettings_80241758),
        .pos = { 379.0f, 300.0f, 192.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_80244774),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
    },
    {
        .id = NPC_BOO8,
        .settings = &N(npcSettings_80241758),
        .pos = { 525.0f, 286.0f, 178.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW | NPC_FLAG_400000,
        .init = &N(init_802447AC),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
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

EvtSource N(makeEntities) = {
    EVT_CALL(MakeEntity, 0x802EA7E0, 17, 238, 80, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_80240B94_BE8774)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
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
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
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
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
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
    }

    return ApiStatus_BLOCK;
}

void N(func_80240E90_BE8A70)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f20;
    f32 temp_f22;

    posX = npc->pos.x;
    posZ = npc->pos.z;
    temp_f22 = script->functionTemp[2][enemy->territory->patrol.points].x;
    temp_f20 = script->functionTemp[2][enemy->territory->patrol.points].z;

    npc->yaw = atan2(posX, posZ, temp_f22, temp_f20);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    posX = npc->pos.x;
    posY = npc->pos.y + script->functionTemp[2][enemy->territory->patrol.points].y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
    posY += script->functionTemp[2][enemy->territory->patrol.points].y;
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
        script->functionTemp[0] = 2;
    }
}

void N(func_80241068_BE8C48)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration < 0) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] >= 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
        } else {
            script->functionTemp[0] = 4;
            npc->currentAnim.w = enemy->animList[0];
        }
    }
}

ApiStatus N(func_8024113C_BE8D1C)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->flags &= ~0x800;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80240E90_BE8A70)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80241068_BE8C48)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, aiSettings, territoryPtr);
    }

    enemy->varTable[0] = npc->pos.y;
    return ApiStatus_BLOCK;
}

ApiStatus N(func_802412B0_BE8E90)(Evt* script, s32 isInitialCall) {
    return (gGameStatusPtr->pressedButtons >> 1) & ApiStatus_DONE2;
}

#include "world/common/SwitchToPartner.inc.c"
