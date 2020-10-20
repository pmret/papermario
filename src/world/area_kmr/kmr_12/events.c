#include "kmr_12.h"

static Script make_entities;
static Script read_west_sign;
static NpcGroupList npc_groups;

static Script exit_west = EXIT_WALK_SCRIPT(60, 0, "kmr_07", 1);
static Script exit_east = EXIT_WALK_SCRIPT(60, 1, "kmr_11", 0);

static Script bind_exits = {
    SI_BIND(exit_west, TriggerFlag_FLOOR_ABOVE, 0 /* deili1 */, NULL),
    SI_BIND(exit_east, TriggerFlag_FLOOR_ABOVE, 3 /* deili2 */, NULL),
    SI_RETURN(),
    SI_END(),
};

Script kmr_12_main = {
    SI_SET(SI_SAVE_VAR(425), 31),
    SI_CALL(SetSpriteShading, -1),
    SI_CALL(SetCamPerspective, 0, 3, 25, 16, 4096),
    SI_CALL(SetCamBGColor, 0, 0, 0, 0),
    SI_CALL(SetCamEnabled, 0, 1),
    SI_CALL(MakeNpcs, 0, npc_groups),
    SI_EXEC_WAIT(make_entities),
    SI_EXEC(kmr_12_play_music),
    SI_SET(SI_VAR(0), bind_exits),
    SI_EXEC(EnterWalk),
    SI_WAIT_FRAMES(1),
    SI_BIND(read_west_sign, TriggerFlag_WALL_INTERACT, 10, NULL),
    SI_RETURN(),
    SI_END(),
};

static NpcAISettings goomba_ai_settings = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .unk_10 = 0.0f,
    .unk_14 = 1,
    .chaseSpeed = 2.5f,
    .unk_1C = 180,
    .unk_20 = 3,
    .chaseRadius = 150.0f,
    .unk_28 = 0.0f,
    .unk_2C = TRUE,
};

static Script goomba_ai = {
    SI_CALL(DoBasicAI, &goomba_ai_settings),
    SI_RETURN(),
    SI_END(),
};

static NpcSettings goomba_npc_settings = {
    .height = 20,
    .radius = 23,
    .ai = &goomba_ai,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 5,
};

// *INDENT-OFF*
static Script read_west_sign = {
    SI_GROUP(0),

    // "Eat a Mushroom to regain your energy!"
    SI_SUSPEND_GROUP(1),
    SI_CALL(DisablePlayerInput, TRUE),
    SI_CALL(ShowMessageAtScreenPos, MessageID_SIGN_MUSHROOM_GOOMBA_TRAP, 160, 40),
    SI_RESUME_GROUP(1),

    SI_SET(SI_FLAG(0), FALSE),
    SI_CALL(kmr_12_get_goomba_ref),
    SI_IF_NE(SI_VAR(0), FALSE),
        SI_CALL(GetNpcVar, NpcId_GOOMBA, 0, SI_VAR(0)),
        SI_IF_EQ(SI_VAR(0), FALSE),
            // Trigger Goomba to peel off
            SI_CALL(SetNpcVar, NpcId_GOOMBA, 0, TRUE),
            SI_SET(SI_FLAG(0), TRUE),
            SI_WAIT_FRAMES(10),
        SI_END_IF(),
    SI_END_IF(),
    SI_CALL(DisablePlayerInput, FALSE),
    SI_IF_EQ(SI_FLAG(0), TRUE),
        SI_UNBIND_ME(),
    SI_END_IF(),

    SI_END(),
    SI_RETURN(), // Whoops!
};

static Script goomba_idle = {
    SI_WAIT_FRAMES(1),

    SI_CALL(SetSelfVar, 0, FALSE),
    SI_CALL(SetNpcAnimation, NpcId_SELF, ANIMATION(SpriteId_GOOMBA, 0, 13)),
    SI_CALL(EnableNpcShadow, NpcId_SELF, FALSE),
    SI_CALL(SetSelfEnemyFlagBits, 0x00000020, TRUE),

    // Wait until read_sign sets NPC var 0
    SI_LABEL(0),
    SI_CALL(GetSelfVar, 0, SI_VAR(0)),
    SI_WAIT_FRAMES(1),
    SI_IF_EQ(SI_VAR(0), FALSE),
        SI_GOTO(0),
    SI_END_IF(),

    // Peel and jump off the sign
    SI_CALL(SetNpcFlagBits, NpcId_SELF, 0x00240000, TRUE),
    SI_WAIT_FRAMES(3),
    SI_SET_F(SI_VAR(0), SI_FIXED(0.0f)),
    SI_LOOP(9),
        SI_ADD_F(SI_VAR(0), SI_FIXED(10.0f)),
        SI_CALL(SetNpcRotation, NpcId_SELF, 0, SI_VAR(0), 0),
        SI_WAIT_FRAMES(1),
    SI_END_LOOP(),
    SI_CALL(SetNpcAnimation, NpcId_SELF, ANIMATION(SpriteId_GOOMBA, 0, 0)),
    SI_LOOP(9),
        SI_ADD_F(SI_VAR(0), SI_FIXED(10.0f)),
        SI_CALL(SetNpcRotation, NpcId_SELF, 0, SI_VAR(0), 0),
        SI_WAIT_FRAMES(1),
    SI_END_LOOP(),
    SI_CALL(SetNpcAnimation, NpcId_SELF, ANIMATION(SpriteId_GOOMBA, 0, 7)),
    SI_WAIT_FRAMES(20),
    SI_CALL(SetNpcAnimation, NpcId_SELF, ANIMATION(SpriteId_GOOMBA, 0, 1)),
    SI_CALL(PlaySoundAtNpc, NpcId_SELF, 248, 0),
    SI_CALL(func_802CFE2C, NpcId_SELF, 8192),
    SI_CALL(func_802CFD30, NpcId_SELF, 5, 6, 1, 1, 0),
    SI_WAIT_FRAMES(12),
    SI_WAIT_FRAMES(5),
    SI_CALL(PlaySoundAtNpc, NpcId_SELF, 812, 0),
    SI_CALL(EnableNpcShadow, NpcId_SELF, TRUE),
    SI_CALL(SetNpcJumpscale, NpcId_SELF, SI_FIXED(0.6005859375f)),
    SI_CALL(NpcJump0, NpcId_SELF, -35, 0, 30, 23),
    SI_CALL(func_802CFD30, NpcId_SELF, 0, 0, 0, 0, 0),
    SI_CALL(InterpNpcYaw, NpcId_SELF, 90, 0),
    SI_CALL(SetNpcFlagBits, NpcId_SELF, 0x00240000, FALSE),
    SI_CALL(SetSelfEnemyFlagBits, 0x00000020, FALSE),
    SI_CALL(SetSelfEnemyFlagBits, 0x40000000, TRUE),

    // We're done jumping off; the player can read the sign again
    SI_BIND(read_west_sign, TriggerFlag_WALL_INTERACT, 10, NULL),

    // Behave like a normal enemy from now on
    SI_CALL(BindNpcAI, NpcId_SELF, &goomba_ai),

    SI_RETURN(),
    SI_END(),
};

static Script goomba_init = {
    SI_CALL(BindNpcIdle, NpcId_SELF, &goomba_idle),
    SI_RETURN(),
    SI_END(),
};
// *INDENT-ON*

static StaticNpc goomba_npc = {
    .id = NpcId_GOOMBA,
    .settings = &goomba_npc_settings,
    .pos = { -33.0f, 30.0f, -25.0f },
    .flags = 0x00000C00,
    .init = goomba_init,
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = { { ItemId_MUSHROOM, 10 } },
    .heartDrops = GENEROUS_WHEN_LOW_HEART_DROPS(2),
    .flowerDrops = GENEROUS_WHEN_LOW_FLOWER_DROPS(2),
    .movement = { 0xFFFFFFDF, 0x0, 0x1E, 0x28, 0x14, 0xFFFF8001, 0x1, 0xC8, 0x0, 0x0, 0x190, 0x3C, 0x1, 0x1 },
    .animations = {
        ANIMATION(SpriteId_GOOMBA, 0, 1),
        ANIMATION(SpriteId_GOOMBA, 0, 2),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 1),
        ANIMATION(SpriteId_GOOMBA, 0, 1),
        ANIMATION(SpriteId_GOOMBA, 0, 5),
        ANIMATION(SpriteId_GOOMBA, 0, 5),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
        ANIMATION(SpriteId_GOOMBA, 0, 3),
    },
};

static NpcGroupList npc_groups = {
    NPC_GROUP(goomba_npc, 0x00010003),
    NPC_GROUP_LIST_END(),
};

// *INDENT-OFF*
static Script read_east_sign = {
    SI_CALL(func_800441F0, SI_VAR(0)),
    SI_IF_EQ(SI_VAR(0), 1),
        SI_RETURN(),
    SI_END_IF(),

    SI_GROUP(0),

    SI_CALL(func_802D5830, 1),
    SI_CALL(DisablePlayerInput, 1),
    SI_CALL(ShowMessageAtScreenPos, MessageID_SIGN_GOOMBA_KINGS_FORTRESS_AHEAD, 160, 40),
    SI_CALL(DisablePlayerInput, 0),
    SI_CALL(func_802D5830, 0),

    SI_RETURN(),
    SI_END(),
};

static Script make_entities = {
    SI_CALL(MakeEntity, 0x802EAFDC, 436, 0, -42, 0, 0x80000000),
    SI_CALL(AssignScript, &read_east_sign),

    SI_RETURN(),
    SI_END(),
};
// *INDENT-ON*
