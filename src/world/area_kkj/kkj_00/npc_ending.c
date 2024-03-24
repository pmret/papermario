#include "kkj_00.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Peach.inc.c"
#include "world/common/npc/Dummy.inc.c"

EvtScript N(EVS_NpcInit_RussT) = {
    Call(SetNpcPos, NPC_SELF, -300, 0, 295)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShiverToad_02) = {
    Call(SetNpcPos, NPC_SELF, -175, 0, -75)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

EvtScript N(EVS_NpcInit_Unused) = {
    Call(SetNpcPos, NPC_SELF, -440, 0, 220)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_03) = {
    Call(SetNpcPos, NPC_SELF, 295, 0, -15)
    Call(SetNpcYaw, NPC_SELF, 270)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_04) = {
    Call(SetNpcPos, NPC_SELF, 325, 0, -10)
    Call(SetNpcYaw, NPC_SELF, 270)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadGuard_03) = {
    Call(SetNpcPos, NPC_SELF, 50, 100, -365)
    Call(SetNpcYaw, NPC_SELF, 270)
    Return
    End
};

AnimID N(ExtraAnims_Peach)[] = {
    ANIM_Peach1_Still,
    ANIM_Peach1_Idle,
    ANIM_Peach2_TalkIdle,
    ANIM_Peach2_RaiseArms,
    ANIM_Peach2_Talk,
    ANIM_Peach2_LowerArms,
    ANIM_Peach1_Walk,
    ANIM_Peach2_SpreadArms,
    ANIM_Peach3_Pray,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Minister)[] = {
    ANIM_ToadMinister_Still,
    ANIM_ToadMinister_Idle,
    ANIM_ToadMinister_Walk,
    ANIM_ToadMinister_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_TayceT)[] = {
    ANIM_TayceT_Still,
    ANIM_TayceT_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_RussT)[] = {
    ANIM_RussT_Still,
    ANIM_RussT_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_ShiverToad)[] = {
    ANIM_ShiverToad_Red_Still,
    ANIM_ShiverToad_Red_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Toad)[] = {
    ANIM_Toad_Red_Still,
    ANIM_Toad_Red_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Toadette)[] = {
    ANIM_Toadette_Orange_Still,
    ANIM_Toadette_Orange_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_ToadGuard)[] = {
    ANIM_ToadGuard_Red_Still,
    ANIM_ToadGuard_Red_Idle,
    ANIM_ToadGuard_Red_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Goombario)[] = {
    ANIM_WorldGoombario_Still,
    ANIM_WorldGoombario_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kooper)[] = {
    ANIM_WorldKooper_Still,
    ANIM_WorldKooper_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bombette)[] = {
    ANIM_WorldBombette_Still,
    ANIM_WorldBombette_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Parakarry)[] = {
    ANIM_WorldParakarry_Still,
    ANIM_WorldParakarry_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bow)[] = {
    ANIM_WorldBow_Still,
    ANIM_WorldBow_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Watt)[] = {
    ANIM_WorldWatt_Still,
    ANIM_WorldWatt_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Sushie)[] = {
    ANIM_WorldSushie_Still,
    ANIM_WorldSushie_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Lakilester)[] = {
    ANIM_WorldLakilester_Still,
    ANIM_WorldLakilester_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Merlon)[] = {
    ANIM_Merlon_Still,
    ANIM_Merlon_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Merluvlee)[] = {
    ANIM_Merluvlee_Still,
    ANIM_Merluvlee_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Merlow)[] = {
    ANIM_Merlow_Still,
    ANIM_Merlow_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Merlee)[] = {
    ANIM_WorldMerlee_Still,
    ANIM_WorldMerlee_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Merle)[] = {
    ANIM_Merle_Still,
    ANIM_Merle_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Lakilulu)[] = {
    ANIM_Lakilulu_Still,
    ANIM_Lakilulu_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bootler)[] = {
    ANIM_Bootler_Still,
    ANIM_Bootler_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Goompa)[] = {
    ANIM_Goompa_Still,
    ANIM_Goompa_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Goombaria)[] = {
    ANIM_Goombaria_Still,
    ANIM_Goombaria_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Yoshi)[] = {
    ANIM_Yoshi_Green_Still,
    ANIM_Yoshi_Green_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Penguin)[] = {
    ANIM_Penguin_Still,
    ANIM_Penguin_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Dryite)[] = {
    ANIM_Dryite_Green_Still,
    ANIM_Dryite_Green_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Ninji)[] = {
    ANIM_Ninji_Still,
    ANIM_Ninji_Idle,
    ANIM_LIST_END
};

NpcData N(NpcData_Peach) = {
    .id = NPC_Peach,
    .pos = { 0.0f, 100.0f, -440.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_Peach),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_PLAYER_SPRITE,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
    .extraAnimations = N(ExtraAnims_Peach),
};

NpcData N(NpcData_SpecialToads)[] = {
    {
        .id = NPC_ToadMinister,
        .pos = { 100.0f, 0.0f, 250.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_MINISTER_ANIMS,
        .extraAnimations = N(ExtraAnims_Minister),
    },
    {
        .id = NPC_TayceT,
        .pos = { -200.0f, 0.0f, 260.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_TayceT_Idle,
        },
        .extraAnimations = N(ExtraAnims_TayceT),
    },
    {
        .id = NPC_RussT_02,
        .pos = { 300.0f, 0.0f, 150.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_RussT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_RussT_Idle,
            .walk   = ANIM_RussT_Idle,
            .run    = ANIM_RussT_Idle,
            .chase  = ANIM_RussT_Idle,
            .anim_4 = ANIM_RussT_Idle,
            .anim_5 = ANIM_RussT_Idle,
            .death  = ANIM_RussT_Idle,
            .hit    = ANIM_RussT_Idle,
            .anim_8 = ANIM_RussT_Idle,
            .anim_9 = ANIM_RussT_Idle,
            .anim_A = ANIM_RussT_Idle,
            .anim_B = ANIM_RussT_Idle,
            .anim_C = ANIM_RussT_Idle,
            .anim_D = ANIM_RussT_Idle,
            .anim_E = ANIM_RussT_Idle,
            .anim_F = ANIM_RussT_Idle,
        },
        .extraAnimations = N(ExtraAnims_RussT),
    },
    {
        .id = NPC_ShiverToad_02,
        .pos = { 330.0f, 0.0f, 135.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShiverToad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Green_Idle,
            .walk   = ANIM_ShiverToad_Green_Walk,
            .run    = ANIM_ShiverToad_Green_Idle,
            .chase  = ANIM_ShiverToad_Green_Idle,
            .anim_4 = ANIM_ShiverToad_Green_Idle,
            .anim_5 = ANIM_ShiverToad_Green_Idle,
            .death  = ANIM_ShiverToad_Green_Idle,
            .hit    = ANIM_ShiverToad_Green_Idle,
            .anim_8 = ANIM_ShiverToad_Green_Idle,
            .anim_9 = ANIM_ShiverToad_Green_Idle,
            .anim_A = ANIM_ShiverToad_Green_Idle,
            .anim_B = ANIM_ShiverToad_Green_Idle,
            .anim_C = ANIM_ShiverToad_Green_Idle,
            .anim_D = ANIM_ShiverToad_Green_Idle,
            .anim_E = ANIM_ShiverToad_Green_Idle,
            .anim_F = ANIM_ShiverToad_Green_Idle,
        },
        .extraAnimations = N(ExtraAnims_ShiverToad),
    },
};

NpcData N(NpcData_Party)[] = {
    {
        .id = NPC_Goombario,
        .pos = { 180.0f, 0.0f, 80.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldGoombario_Idle,
            .walk   = ANIM_WorldGoombario_Walk,
            .run    = ANIM_WorldGoombario_Run,
            .chase  = ANIM_WorldGoombario_Run,
            .anim_4 = ANIM_WorldGoombario_Idle,
            .anim_5 = ANIM_WorldGoombario_Idle,
            .death  = ANIM_WorldGoombario_Still,
            .hit    = ANIM_WorldGoombario_Still,
            .anim_8 = ANIM_WorldGoombario_Run,
            .anim_9 = ANIM_WorldGoombario_Run,
            .anim_A = ANIM_WorldGoombario_Run,
            .anim_B = ANIM_WorldGoombario_Run,
            .anim_C = ANIM_WorldGoombario_Run,
            .anim_D = ANIM_WorldGoombario_Run,
            .anim_E = ANIM_WorldGoombario_Run,
            .anim_F = ANIM_WorldGoombario_Run,
        },
        .extraAnimations = N(ExtraAnims_Goombario),
    },
    {
        .id = NPC_Kooper,
        .pos = { 225.0f, 0.0f, 225.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
        .extraAnimations = N(ExtraAnims_Kooper),
    },
    {
        .id = NPC_Bombette,
        .pos = { 270.0f, 0.0f, 115.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldBombette_Idle,
            .walk   = ANIM_WorldBombette_Walk,
            .run    = ANIM_WorldBombette_Walk,
            .chase  = ANIM_WorldBombette_Walk,
            .anim_4 = ANIM_WorldBombette_Walk,
            .anim_5 = ANIM_WorldBombette_Walk,
            .death  = ANIM_WorldBombette_Still,
            .hit    = ANIM_WorldBombette_Still,
            .anim_8 = ANIM_WorldBombette_Still,
            .anim_9 = ANIM_WorldBombette_Still,
            .anim_A = ANIM_WorldBombette_Still,
            .anim_B = ANIM_WorldBombette_Still,
            .anim_C = ANIM_WorldBombette_Still,
            .anim_D = ANIM_WorldBombette_Still,
            .anim_E = ANIM_WorldBombette_Still,
            .anim_F = ANIM_WorldBombette_Still,
        },
        .extraAnimations = N(ExtraAnims_Bombette),
    },
    {
        .id = NPC_Parakarry,
        .pos = { 325.0f, 10.0f, 175.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
        .extraAnimations = N(ExtraAnims_Parakarry),
    },
    {
        .id = NPC_Bow,
        .pos = { -270.0f, 0.0f, 145.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldBow_Idle,
            .walk   = ANIM_WorldBow_Walk,
            .run    = ANIM_WorldBow_Run,
            .chase  = ANIM_WorldBow_Run,
            .anim_4 = ANIM_WorldBow_Idle,
            .anim_5 = ANIM_WorldBow_Idle,
            .death  = ANIM_WorldBow_Still,
            .hit    = ANIM_WorldBow_Still,
            .anim_8 = ANIM_WorldBow_Run,
            .anim_9 = ANIM_WorldBow_Run,
            .anim_A = ANIM_WorldBow_Run,
            .anim_B = ANIM_WorldBow_Run,
            .anim_C = ANIM_WorldBow_Run,
            .anim_D = ANIM_WorldBow_Run,
            .anim_E = ANIM_WorldBow_Run,
            .anim_F = ANIM_WorldBow_Run,
        },
        .extraAnimations = N(ExtraAnims_Bow),
    },
    {
        .id = NPC_Watt,
        .pos = { -235.0f, 0.0f, 85.0f },
        .yaw = 90,
        .initVarCount = 1,
        .initVar = { .value = 0 },
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldWatt_Idle,
            .walk   = ANIM_WorldWatt_Idle,
            .run    = ANIM_WorldWatt_Idle,
            .chase  = ANIM_WorldWatt_Idle,
            .anim_4 = ANIM_WorldWatt_Idle,
            .anim_5 = ANIM_WorldWatt_Idle,
            .death  = ANIM_WorldWatt_Idle,
            .hit    = ANIM_WorldWatt_Idle,
            .anim_8 = ANIM_WorldWatt_Idle,
            .anim_9 = ANIM_WorldWatt_Idle,
            .anim_A = ANIM_WorldWatt_Idle,
            .anim_B = ANIM_WorldWatt_Idle,
            .anim_C = ANIM_WorldWatt_Idle,
            .anim_D = ANIM_WorldWatt_Idle,
            .anim_E = ANIM_WorldWatt_Idle,
            .anim_F = ANIM_WorldWatt_Idle,
        },
        .extraAnimations = N(ExtraAnims_Watt),
    },
    {
        .id = NPC_Sushie,
        .pos = { -190.0f, 0.0f, 50.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldSushie_Idle,
            .walk   = ANIM_WorldSushie_Idle,
            .run    = ANIM_WorldSushie_Idle,
            .chase  = ANIM_WorldSushie_Idle,
            .anim_4 = ANIM_WorldSushie_Idle,
            .anim_5 = ANIM_WorldSushie_Idle,
            .death  = ANIM_WorldSushie_Idle,
            .hit    = ANIM_WorldSushie_Idle,
            .anim_8 = ANIM_WorldSushie_Idle,
            .anim_9 = ANIM_WorldSushie_Idle,
            .anim_A = ANIM_WorldSushie_Idle,
            .anim_B = ANIM_WorldSushie_Idle,
            .anim_C = ANIM_WorldSushie_Idle,
            .anim_D = ANIM_WorldSushie_Idle,
            .anim_E = ANIM_WorldSushie_Idle,
            .anim_F = ANIM_WorldSushie_Idle,
        },
        .extraAnimations = N(ExtraAnims_Sushie),
    },
    {
        .id = NPC_Lakilester,
        .pos = { -320.0f, 0.0f, -60.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldLakilester_Idle,
            .walk   = ANIM_WorldLakilester_Idle,
            .run    = ANIM_WorldLakilester_Idle,
            .chase  = ANIM_WorldLakilester_Idle,
            .anim_4 = ANIM_WorldLakilester_Idle,
            .anim_5 = ANIM_WorldLakilester_Idle,
            .death  = ANIM_WorldLakilester_Idle,
            .hit    = ANIM_WorldLakilester_Idle,
            .anim_8 = ANIM_WorldLakilester_Idle,
            .anim_9 = ANIM_WorldLakilester_Idle,
            .anim_A = ANIM_WorldLakilester_Idle,
            .anim_B = ANIM_WorldLakilester_Idle,
            .anim_C = ANIM_WorldLakilester_Idle,
            .anim_D = ANIM_WorldLakilester_Idle,
            .anim_E = ANIM_WorldLakilester_Idle,
            .anim_F = ANIM_WorldLakilester_Idle,
        },
        .extraAnimations = N(ExtraAnims_Lakilester),
    },
};

NpcData N(NpcData_Wizards)[] = {
    {
        .id = NPC_Merlon,
        .pos = { -145.0f, 0.0f, 415.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merlon_Idle,
        },
        .extraAnimations = N(ExtraAnims_Merlon),
    },
    {
        .id = NPC_Merluvlee,
        .pos = { -225.0f, 0.0f, 380.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merluvlee_Idle,
        },
        .extraAnimations = N(ExtraAnims_Merluvlee),
    },
    {
        .id = NPC_Merlow,
        .pos = { -175.0f, 0.0f, 330.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merlow_Idle,
        },
        .extraAnimations = N(ExtraAnims_Merlow),
    },
    {
        .id = NPC_Merlee,
        .pos = { -250.0f, 0.0f, 350.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldMerlee_Idle,
            .walk   = ANIM_WorldMerlee_Walk,
            .run    = ANIM_WorldMerlee_Run,
            .chase  = ANIM_WorldMerlee_Run,
            .anim_4 = ANIM_WorldMerlee_Idle,
            .anim_5 = ANIM_WorldMerlee_Idle,
            .death  = ANIM_WorldMerlee_Idle,
            .hit    = ANIM_WorldMerlee_Idle,
            .anim_8 = ANIM_WorldMerlee_Idle,
            .anim_9 = ANIM_WorldMerlee_Idle,
            .anim_A = ANIM_WorldMerlee_Idle,
            .anim_B = ANIM_WorldMerlee_Idle,
            .anim_C = ANIM_WorldMerlee_Idle,
            .anim_D = ANIM_WorldMerlee_Idle,
            .anim_E = ANIM_WorldMerlee_Idle,
            .anim_F = ANIM_WorldMerlee_Idle,
        },
        .extraAnimations = N(ExtraAnims_Merlee),
    },
    {
        .id = NPC_Merle,
        .pos = { -220.0f, 0.0f, 450.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merle_Idle,
            .walk   = ANIM_Merle_Idle,
            .run    = ANIM_Merle_Idle,
            .chase  = ANIM_Merle_Idle,
            .anim_4 = ANIM_Merle_Idle,
            .anim_5 = ANIM_Merle_Idle,
            .death  = ANIM_Merle_Idle,
            .hit    = ANIM_Merle_Idle,
            .anim_8 = ANIM_Merle_Idle,
            .anim_9 = ANIM_Merle_Idle,
            .anim_A = ANIM_Merle_Idle,
            .anim_B = ANIM_Merle_Idle,
            .anim_C = ANIM_Merle_Idle,
            .anim_D = ANIM_Merle_Idle,
            .anim_E = ANIM_Merle_Idle,
            .anim_F = ANIM_Merle_Idle,
        },
        .extraAnimations = N(ExtraAnims_Merle),
    },
};

NpcData N(NpcData_PartyFamily)[] = {
    {
        .id = NPC_Lakilulu,
        .pos = { -365.0f, 0.0f, -60.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Lakilulu_Idle,
            .walk   = ANIM_Lakilulu_Idle,
            .run    = ANIM_Lakilulu_Idle,
            .chase  = ANIM_Lakilulu_Idle,
            .anim_4 = ANIM_Lakilulu_Idle,
            .anim_5 = ANIM_Lakilulu_Idle,
            .death  = ANIM_Lakilulu_Idle,
            .hit    = ANIM_Lakilulu_Idle,
            .anim_8 = ANIM_Lakilulu_Idle,
            .anim_9 = ANIM_Lakilulu_Idle,
            .anim_A = ANIM_Lakilulu_Idle,
            .anim_B = ANIM_Lakilulu_Idle,
            .anim_C = ANIM_Lakilulu_Idle,
            .anim_D = ANIM_Lakilulu_Idle,
            .anim_E = ANIM_Lakilulu_Idle,
            .anim_F = ANIM_Lakilulu_Idle,
        },
        .extraAnimations = N(ExtraAnims_Lakilulu),
    },
    {
        .id = NPC_Bootler,
        .pos = { -340.0f, 0.0f, 100.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bootler_Idle,
            .walk   = ANIM_Bootler_Walk,
            .run    = ANIM_Bootler_Run,
            .chase  = ANIM_Bootler_Run,
            .anim_4 = ANIM_Bootler_Idle,
            .anim_5 = ANIM_Bootler_Idle,
            .death  = ANIM_Bootler_Still,
            .hit    = ANIM_Bootler_Still,
            .anim_8 = ANIM_Bootler_Shock,
            .anim_9 = ANIM_Bootler_Panic,
            .anim_A = ANIM_Bootler_Dejected,
            .anim_B = ANIM_Bootler_Quaver,
            .anim_C = ANIM_Bootler_Shock,
            .anim_D = ANIM_Bootler_Panic,
            .anim_E = ANIM_Bootler_Dejected,
            .anim_F = ANIM_Bootler_Quaver,
        },
        .extraAnimations = N(ExtraAnims_Bootler),
    },
    {
        .id = NPC_Goompa,
        .pos = { 170.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Goompa_Idle,
            .walk   = ANIM_Goompa_Walk,
            .run    = ANIM_Goompa_Run,
            .chase  = ANIM_Goompa_Run,
            .anim_4 = ANIM_Goompa_Idle,
            .anim_5 = ANIM_Goompa_Idle,
            .death  = ANIM_Goompa_Still,
            .hit    = ANIM_Goompa_Still,
            .anim_8 = ANIM_Goompa_Run,
            .anim_9 = ANIM_Goompa_Run,
            .anim_A = ANIM_Goompa_Run,
            .anim_B = ANIM_Goompa_Run,
            .anim_C = ANIM_Goompa_Run,
            .anim_D = ANIM_Goompa_Run,
            .anim_E = ANIM_Goompa_Run,
            .anim_F = ANIM_Goompa_Run,
        },
        .extraAnimations = N(ExtraAnims_Goompa),
    },
    {
        .id = NPC_Goombaria,
        .pos = { 140.0f, 0.0f, 50.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Goombaria_Idle,
            .walk   = ANIM_Goombaria_Walk,
            .run    = ANIM_Goombaria_Run,
            .chase  = ANIM_Goombaria_Run,
            .anim_4 = ANIM_Goombaria_Idle,
            .anim_5 = ANIM_Goombaria_Idle,
            .death  = ANIM_Goombaria_Still,
            .hit    = ANIM_Goombaria_Still,
            .anim_8 = ANIM_Goombaria_Run,
            .anim_9 = ANIM_Goombaria_Run,
            .anim_A = ANIM_Goombaria_Run,
            .anim_B = ANIM_Goombaria_Run,
            .anim_C = ANIM_Goombaria_Run,
            .anim_D = ANIM_Goombaria_Run,
            .anim_E = ANIM_Goombaria_Run,
            .anim_F = ANIM_Goombaria_Run,
        },
        .extraAnimations = N(ExtraAnims_Goombaria),
    },
};

NpcData N(NpcData_Visitors)[] = {
    {
        .id = NPC_Yoshi,
        .pos = { -340.0f, 0.0f, 310.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Yoshi_Blue_Idle,
            .walk   = ANIM_Yoshi_Blue_Walk,
            .run    = ANIM_Yoshi_Blue_Idle,
            .chase  = ANIM_Yoshi_Blue_Idle,
            .anim_4 = ANIM_Yoshi_Blue_Idle,
            .anim_5 = ANIM_Yoshi_Blue_Idle,
            .death  = ANIM_Yoshi_Blue_Idle,
            .hit    = ANIM_Yoshi_Blue_Idle,
            .anim_8 = ANIM_Yoshi_Blue_Idle,
            .anim_9 = ANIM_Yoshi_Blue_Idle,
            .anim_A = ANIM_Yoshi_Blue_Idle,
            .anim_B = ANIM_Yoshi_Blue_Idle,
            .anim_C = ANIM_Yoshi_Blue_Idle,
            .anim_D = ANIM_Yoshi_Blue_Idle,
            .anim_E = ANIM_Yoshi_Blue_Idle,
            .anim_F = ANIM_Yoshi_Blue_Idle,
        },
        .extraAnimations = N(ExtraAnims_Yoshi),
    },
    {
        .id = NPC_Penguin_02,
        .pos = { 225.0f, 0.0f, -80.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Penguin_Idle,
            .walk   = ANIM_Penguin_Walk,
            .run    = ANIM_Penguin_Run,
            .chase  = ANIM_Penguin_Run,
            .anim_4 = ANIM_Penguin_Idle,
            .anim_5 = ANIM_Penguin_Idle,
            .death  = ANIM_Penguin_Idle,
            .hit    = ANIM_Penguin_Idle,
            .anim_8 = ANIM_Penguin_Idle,
            .anim_9 = ANIM_Penguin_Idle,
            .anim_A = ANIM_Penguin_Idle,
            .anim_B = ANIM_Penguin_Idle,
            .anim_C = ANIM_Penguin_Idle,
            .anim_D = ANIM_Penguin_Idle,
            .anim_E = ANIM_Penguin_Idle,
            .anim_F = ANIM_Penguin_Idle,
        },
        .extraAnimations = N(ExtraAnims_Penguin),
    },
    {
        .id = NPC_Penguin_03,
        .pos = { -250.0f, 0.0f, -150.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Penguin_Idle,
            .walk   = ANIM_Penguin_Walk,
            .run    = ANIM_Penguin_Run,
            .chase  = ANIM_Penguin_Run,
            .anim_4 = ANIM_Penguin_Idle,
            .anim_5 = ANIM_Penguin_Idle,
            .death  = ANIM_Penguin_Idle,
            .hit    = ANIM_Penguin_Idle,
            .anim_8 = ANIM_Penguin_Idle,
            .anim_9 = ANIM_Penguin_Idle,
            .anim_A = ANIM_Penguin_Idle,
            .anim_B = ANIM_Penguin_Idle,
            .anim_C = ANIM_Penguin_Idle,
            .anim_D = ANIM_Penguin_Idle,
            .anim_E = ANIM_Penguin_Idle,
            .anim_F = ANIM_Penguin_Idle,
        },
        .extraAnimations = N(ExtraAnims_Penguin),
    },
    {
        .id = NPC_Dryite,
        .pos = { -320.0f, 0.0f, 245.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Dryite_Yellow_Idle,
            .walk   = ANIM_Dryite_Yellow_Walk,
            .run    = ANIM_Dryite_Yellow_Run,
            .chase  = ANIM_Dryite_Yellow_Run,
            .anim_4 = ANIM_Dryite_Yellow_Idle,
            .anim_5 = ANIM_Dryite_Yellow_Idle,
            .death  = ANIM_Dryite_Yellow_Still,
            .hit    = ANIM_Dryite_Yellow_Still,
            .anim_8 = ANIM_Dryite_Yellow_Idle,
            .anim_9 = ANIM_Dryite_Yellow_Idle,
            .anim_A = ANIM_Dryite_Yellow_Idle,
            .anim_B = ANIM_Dryite_Yellow_Idle,
            .anim_C = ANIM_Dryite_Yellow_Idle,
            .anim_D = ANIM_Dryite_Yellow_Idle,
            .anim_E = ANIM_Dryite_Yellow_Idle,
            .anim_F = ANIM_Dryite_Yellow_Idle,
        },
        .extraAnimations = N(ExtraAnims_Dryite),
    },
    {
        .id = NPC_Ninji,
        .pos = { -395.0f, 68.0f, 50.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .extraAnimations = N(ExtraAnims_Ninji),
    },
};

NpcData N(NpcData_Toads)[] = {
    {
        .id = NPC_Toad_04,
        .pos = { 200.0f, 0.0f, 420.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
    },
    {
        .id = NPC_Toad_05,
        .pos = { -120.0f, 0.0f, 205.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
    },
    {
        .id = NPC_Toad_06,
        .pos = { -440.0f, 0.0f, 220.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
    },
    {
        .id = NPC_Toad_07,
        .pos = { 285.0f, 0.0f, 290.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .extraAnimations = N(ExtraAnims_Toad),
    },
};

NpcData N(NpcData_Toadettes)[] = {
    {
        .id = NPC_Toadette_03,
        .pos = { -300.0f, 0.0f, 100.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Toadette),
    },
    {
        .id = NPC_Toadette_04,
        .pos = { -270.0f, 0.0f, 85.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toadette_04),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Toadette),
    },
    {
        .id = NPC_Toadette_05,
        .pos = { -190.0f, 0.0f, 160.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .extraAnimations = N(ExtraAnims_Toadette),
    },
    {
        .id = NPC_Toadette_06,
        .pos = { 190.0f, 0.0f, 300.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .extraAnimations = N(ExtraAnims_Toadette),
    },
};

NpcData N(NpcData_ToadGuards)[] = {
    {
        .id = NPC_ToadGuard_03,
        .pos = { 100.0f, 0.0f, 150.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadGuard_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
    {
        .id = NPC_ToadGuard_04,
        .pos = { -50.0f, 100.0f, -365.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_BLUE_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
    {
        .id = NPC_ToadGuard_05,
        .pos = { 225.0f, 0.0f, 125.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
    {
        .id = NPC_ToadGuard_06,
        .pos = { -392.0f, 40.0f, -230.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_GREEN_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
    {
        .id = NPC_ToadGuard_07,
        .pos = { -392.0f, 40.0f, -230.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .extraAnimations = N(ExtraAnims_ToadGuard),
    },
};

NpcGroupList N(EndingNPCs) = {
    NPC_GROUP(N(NpcData_Peach)),
    NPC_GROUP(N(NpcData_SpecialToads)),
    NPC_GROUP(N(NpcData_Party)),
    NPC_GROUP(N(NpcData_Wizards)),
    NPC_GROUP(N(NpcData_PartyFamily)),
    NPC_GROUP(N(NpcData_Visitors)),
    NPC_GROUP(N(NpcData_Toads)),
    NPC_GROUP(N(NpcData_Toadettes)),
    NPC_GROUP(N(NpcData_ToadGuards)),
    {}
};
