#include "common.h"
#include "script_api/map.h"

Bytecode kmr_12_play_music[];
Bytecode make_entities[];
Bytecode read_sign[];

GEN_EXIT_WALK_SCRIPT(exit_west, 60, 0, "kmr_07", 1);
GEN_EXIT_WALK_SCRIPT(exit_east, 60, 1, "kmr_11", 0);

Bytecode bind_exits[] = {
    SI_BIND(&exit_west, TriggerFlag_FLOOR_ABOVE, 0 /* deili1 */, NULL),
    SI_BIND(&exit_east, TriggerFlag_FLOOR_ABOVE, 3 /* deili2 */, NULL),
    SI_RETURN(),
    SI_END(),
};

Bytecode kmr_12_main[] = {
    SI_SET(SI_SAVE_VAR(425), 31),
    SI_CALL(&SetSpriteShading, -1),
    SI_CALL(&SetCamPerspective, 0, 3, 25, 16, 4096),
    SI_CALL(&SetCamBGColor, 0, 0, 0, 0),
    SI_CALL(&SetCamEnabled, 0, 1),
    SI_CALL(&MakeNpcs, 0, 0x802409A8),
    SI_EXEC_WAIT(&make_entities),
    SI_EXEC(&kmr_12_play_music),
    SI_SET(SI_VAR(0), bind_exits),
    SI_EXEC(&EnterWalk),
    SI_WAIT_FRAMES(1),
    SI_BIND(read_sign, TriggerFlag_WALL_INTERACT, 10, NULL),
    SI_RETURN(),
    SI_END(),
};

NpcAISettings goomba_ai_settings = {
    1.5f,
    30,
    30,
    130.0f,
    0.0f,
    1,
    2.5f,
    180,
    3,
    150.0f,
    0.0f,
    TRUE
};

Bytecode goomba_ai[] = {
    SI_CALL(&DoBasicAI, &goomba_ai_settings),
    SI_RETURN(),
    SI_END(),
};

StaticNpcSettings goomba_npc_settings = {
    .radius = 20,
    .height = 23,
    .aiScript = &goomba_ai,
    .hitScript = (Bytecode*)0x80077F70,
    .defeatScript = (Bytecode*)0x8007809C,
};

ApiStatus get_goomba_ref(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = get_enemy_safe(0);
    return ApiStatus_DONE2;
}

Bytecode read_sign[] = { // *INDENT-OFF*
    SI_GROUP(0),

    // "Eat a Mushroom to regain your energy!"
    SI_SUSPEND_GROUP(1),
    SI_CALL(&DisablePlayerInput, TRUE),
    SI_CALL(&ShowMessageAtScreenPos, 0x1D0167, 160, 40),
    SI_RESUME_GROUP(1),

    SI_SET(SI_FLAG(0), FALSE),
    SI_CALL(&get_goomba_ref),
    SI_IF_NE(SI_VAR(0), FALSE),
        SI_CALL(&GetNpcVar, 0, 0, SI_VAR(0)),
        SI_IF_EQ(SI_VAR(0), FALSE),
            // Trigger Goomba to peel off
            SI_CALL(&SetNpcVar, 0, 0, TRUE),
            SI_SET(SI_FLAG(0), TRUE),
            SI_WAIT_FRAMES(10),
        SI_END_IF(),
    SI_END_IF(),
    SI_CALL(&DisablePlayerInput, FALSE),
    SI_IF_EQ(SI_FLAG(0), TRUE),
        SI_UNBIND_ME(),
    SI_END_IF(),

    SI_END(),
    SI_RETURN(), // Whoops!
}; // *INDENT-ON*

Bytecode goomba_idle[] = { // *INDENT-OFF*
    SI_WAIT_FRAMES(1),

    SI_CALL(&SetSelfVar, 0, FALSE),
    SI_CALL(&SetNpcAnimation, NpcId_SELF, 0x26000D),
    SI_CALL(&EnableNpcShadow, NpcId_SELF, 0),
    SI_CALL(&SetSelfEnemyFlagBits, 32, 1),

    // Wait until read_sign sets NPC var 0
    SI_LABEL(0),
    SI_CALL(&GetSelfVar, 0, SI_VAR(0)),
    SI_WAIT_FRAMES(1),
    SI_IF_EQ(SI_VAR(0), TRUE),
        SI_GOTO(0),
    SI_END_IF(),

    // Peel and jump off the sign
    SI_CALL(&SetNpcFlagBits, NpcId_SELF, 0x240000, 1),
    SI_WAIT_FRAMES(3),
    SI_SET_F(SI_VAR(0), SI_FIXED(0.0f)),
    SI_LOOP(9),
        SI_ADD_F(SI_VAR(0), SI_FIXED(10.0f)),
        SI_CALL(&SetNpcRotation, NpcId_SELF, 0, SI_VAR(0), 0),
        SI_WAIT_FRAMES(1),
    SI_END_LOOP(),
    SI_CALL(&SetNpcAnimation, NpcId_SELF, 0x260000),
    SI_LOOP(9),
        SI_ADD_F(SI_VAR(0), SI_FIXED(10.0f)),
        SI_CALL(&SetNpcRotation, NpcId_SELF, 0, SI_VAR(0), 0),
        SI_WAIT_FRAMES(1),
    SI_END_LOOP(),
    SI_CALL(&SetNpcAnimation, NpcId_SELF, 0x260007),
    SI_WAIT_FRAMES(20),
    SI_CALL(&SetNpcAnimation, NpcId_SELF, 0x260001),
    SI_CALL(&PlaySoundAtNpc, NpcId_SELF, 248, 0),
    SI_CALL(&func_802CFE2C, NpcId_SELF, 8192),
    SI_CALL(&func_802CFD30, NpcId_SELF, 5, 6, 1, 1, 0),
    SI_WAIT_FRAMES(12),
    SI_WAIT_FRAMES(5),
    SI_CALL(&PlaySoundAtNpc, NpcId_SELF, 812, 0),
    SI_CALL(&EnableNpcShadow, NpcId_SELF, 1),
    SI_CALL(&SetNpcJumpscale, NpcId_SELF, SI_FIXED(0.6005859375f)),
    SI_CALL(&NpcJump0, NpcId_SELF, 0xFFFFFFDD, 0, 30, 23),
    SI_CALL(&func_802CFD30, NpcId_SELF, 0, 0, 0, 0, 0),
    SI_CALL(&InterpNpcYaw, NpcId_SELF, 90, 0),
    SI_CALL(&SetNpcFlagBits, NpcId_SELF, 0x240000, 0),
    SI_CALL(&SetSelfEnemyFlagBits, 32, 0),
    SI_CALL(&SetSelfEnemyFlagBits, 0x40000000, 1),

    // We're done jumping off; the player can read the sign again
    SI_BIND(read_sign, TriggerFlag_WALL_INTERACT, 10, NULL),

    // Behave like a normal enemy from now on
    SI_CALL(&BindNpcAI, NpcId_SELF, &goomba_ai),

    SI_RETURN(),
    SI_END(),
}; // *INDENT-ON*

Bytecode goomba_init[] = {
    SI_CALL(&BindNpcIdle, NpcId_SELF, &goomba_idle),
    SI_RETURN(),
    SI_END(),
};
