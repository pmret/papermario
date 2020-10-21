#include "kmr_12.h"

Script M(ExitWest) = EXIT_WALK_SCRIPT(60, 0, "kmr_07", 1);
Script M(ExitEast) = EXIT_WALK_SCRIPT(60, 1, "kmr_11", 0);

Script M(BindExits) = {
    SI_BIND(M(ExitWest), TriggerFlag_FLOOR_ABOVE, 0 /* deili1 */, NULL),
    SI_BIND(M(ExitEast), TriggerFlag_FLOOR_ABOVE, 3 /* deili2 */, NULL),
    SI_RETURN(),
    SI_END(),
};

Script M(Main) = {
    SI_SET(SI_SAVE_VAR(425), 31),
    SI_CALL(SetSpriteShading, -1),
    SI_CALL(SetCamPerspective, 0, 3, 25, 16, 4096),
    SI_CALL(SetCamBGColor, 0, 0, 0, 0),
    SI_CALL(SetCamEnabled, 0, 1),
    SI_CALL(MakeNpcs, 0, M(npcGroupList)),
    SI_EXEC_WAIT(M(MakeEntities)),
    SI_EXEC(M(PlayMusic)),
    SI_SET(SI_VAR(0), M(BindExits)),
    SI_EXEC(EnterWalk),
    SI_WAIT_FRAMES(1),
    SI_BIND(M(ReadWestSign), TriggerFlag_WALL_INTERACT, 10, NULL),
    SI_RETURN(),
    SI_END(),
};

NpcAISettings M(goombaAISettings) = {
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

Script M(GoombaAI) = {
    SI_CALL(DoBasicAI, &M(goombaAISettings)),
    SI_RETURN(),
    SI_END(),
};

NpcSettings M(goombaNpcSettings) = {
    .height = 20,
    .radius = 23,
    .ai = &M(GoombaAI),
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 5,
};

// *INDENT-OFF*
/// @bug The RETURN command is after the END command, so this script will never terminate.
Script M(ReadWestSign) = {
    SI_GROUP(0),

    // "Eat a Mushroom to regain your energy!"
    SI_SUSPEND_GROUP(1),
    SI_CALL(DisablePlayerInput, TRUE),
    SI_CALL(ShowMessageAtScreenPos, MessageID_SIGN_MUSHROOM_GOOMBA_TRAP, 160, 40),
    SI_RESUME_GROUP(1),

    SI_SET(SI_FLAG(0), FALSE),
    SI_CALL(M(GetGoomba)),
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
    SI_RETURN(),
};

Script M(GoombaIdle) = {
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
    SI_BIND(M(ReadWestSign), TriggerFlag_WALL_INTERACT, 10, NULL),

    // Behave like a normal enemy from now on
    SI_CALL(BindNpcAI, NpcId_SELF, &M(GoombaAI)),

    SI_RETURN(),
    SI_END(),
};

Script M(GoombaInit) = {
    SI_CALL(BindNpcIdle, NpcId_SELF, &M(GoombaIdle)),
    SI_RETURN(),
    SI_END(),
};
// *INDENT-ON*

StaticNpc M(GoombaNPC) = {
    .id = NpcId_GOOMBA,
    .settings = &M(goombaNpcSettings),
    .pos = { -33.0f, 30.0f, -25.0f },
    .flags = 0x00000C00,
    .init = M(GoombaInit),
    .yaw = 90,
    .dropFlags = 0x80,
    .itemDropChance = 5,
    .itemDrops = { { ItemId_MUSHROOM, 10 } },
    .heartDrops = GENEROUS_WHEN_LOW_HEART_DROPS(2),
    .flowerDrops = GENEROUS_WHEN_LOW_FLOWER_DROPS(2),
    .movement = {
        // Wander
        /* center x, y, z */ -33, 0, 30,
        /* size x, z */ 40, 20,
        /* speed */ NO_OVERRIDE_MOVEMENT_SPEED,
        /* box? */ TRUE,

        // Detect
        /* center x, y, z */ 200, 0, 0,
        /* size x, z */ 400, 60,
        /* box? */ TRUE,

        /* flying? */ TRUE,
    },
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

NpcGroupList M(npcGroupList) = {
    NPC_GROUP(M(GoombaNPC), FORMATION_ID(1, 0, 3)),
    NPC_GROUP_LIST_END(),
};

// *INDENT-OFF*
Script M(ReadEastSign) = {
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

Script M(MakeEntities) = {
    SI_CALL(MakeEntity, 0x802EAFDC, 436, 0, -42, 0, 0x80000000),
    SI_CALL(AssignScript, &M(ReadEastSign)),

    SI_RETURN(),
    SI_END(),
};
// *INDENT-ON*
