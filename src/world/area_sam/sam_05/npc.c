#include "sam_05.h"
#include "sprite.h"
#include "include_asset.h"

NpcSettings N(NpcSettings_Monstar) = {
    .height = 150,
    .radius = 150,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/npc/Twink.inc.c"

#include "world/common/enemy/Gulpit.inc.c"
#include "world/common/enemy/FrostPiranha.inc.c"

EvtScript N(EVS_NpcAI_Monstar) = {
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            Goto(0)
        EndIf
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

extern EvtScript N(EVS_NpcAux_Monstar);

EvtScript N(EVS_NpcDefeat_Monstar) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Monstar)))
            ExecWait(N(EVS_Scene_MonstarDefeated))
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Call(ClearDefeatedEnemies)
    Return
    End
};

INCLUDE_IMG("world/area_sam/sam_05/monstar.png", sam_05_monstar_png);
INCLUDE_IMG("world/area_sam/sam_05/monstar_blank1.png", D_80242970);
INCLUDE_IMG("world/area_sam/sam_05/monstar_blank2.png", D_80242B70);
INCLUDE_IMG("world/area_sam/sam_05/monstar_blank3.png", D_80242D70);
INCLUDE_PAL("world/area_sam/sam_05/monstar.pal", sam_05_monstar_pal);
#include "world/area_sam/sam_05/monstar.png.h"

ImgFXOverlayTexture N(MonstarDetailTexture) = {
    .raster  = N(monstar_png),
    .palette = N(monstar_pal),
    .width   = N(monstar_png_width),
    .height  = N(monstar_png_height),
    .offsetX  = -2,
    .offsetY  = 0,
    .displayList  = N(monstar_gfx),
};

API_CALLABLE(N(UpdateMonstarSpriteEffects)) {
    #define RGBA_BUF_SIZE 20
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    u8 rbuf[RGBA_BUF_SIZE];
    u8 gbuf[RGBA_BUF_SIZE];
    u8 bbuf[RGBA_BUF_SIZE];
    u8 abuf[RGBA_BUF_SIZE];
    s32 i;

    if (isInitialCall) {
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }

    if (enemy->varTable[3] == 0) {
        set_npc_imgfx_comp(npc->spriteInstanceID, 1, IMGFX_SET_ALPHA, 255, 255, 255, 0, 0);
        return ApiStatus_BLOCK;
    }

    set_npc_imgfx_comp(npc->spriteInstanceID, 0, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
    script->functionTemp[0] += 10;
    if (script->functionTemp[0] >= 360) {
        script->functionTemp[0] %= 360;
    }

    for (i = 0; i < RGBA_BUF_SIZE; i++) {
        rbuf[i] = (cosine(script->functionTemp[0] + (i * 25)) + 1.0) * 56.0;
        gbuf[i] = (cosine(script->functionTemp[0] + (i * 25) + 45) + 1.0) * 56.0;
        bbuf[i] = (cosine(script->functionTemp[0] + (i * 25) + 90) + 1.0) * 56.0;
        abuf[i] = enemy->varTable[3];

        set_npc_imgfx_comp(npc->spriteInstanceID, 0, IMGFX_COLOR_BUF_SET_MODULATE, i,
                            (rbuf[i] << 24) | (gbuf[i] << 16) | (bbuf[i] << 8) | abuf[i], 0, 255, 0);
    }

    if (enemy->varTable[3] == 255) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        set_npc_imgfx_comp(npc->spriteInstanceID, 1, IMGFX_OVERLAY, (s32) &N(MonstarDetailTexture), 255, 0, 255, 0);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        set_npc_imgfx_comp(npc->spriteInstanceID, 1, IMGFX_OVERLAY, (s32) &N(MonstarDetailTexture),
                            enemy->varTable[3], 0, enemy->varTable[3], 0);
    }
    return ApiStatus_BLOCK;

    #undef RGBA_BUF_SIZE
}

API_CALLABLE(N(CheckSkipInput)) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_NpcAux_Monstar) = {
    Call(N(UpdateMonstarSpriteEffects))
    Return
    End
};

EvtScript N(EVS_NpcInit_Monstar) = {
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(SetNpcVar, NPC_Monstar, 3, 255)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Monstar)))
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_MONSTAR)
        Call(RemoveNpc, NPC_SELF)
    Else
        Exec(N(EVS_Scene_MonstarAppears))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Monstar)))
        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Monstar)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid) = {
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Twink_Shout)
    Return
    End
};

AnimID N(ExtraAnims_Monstar)[] = {
    ANIM_Monstar_Still,
    ANIM_Monstar_Idle1,
    ANIM_Monstar_Hurt,
    ANIM_Monstar_Talk,
    ANIM_Monstar_HappyTalk,
    ANIM_Monstar_Flail,
    ANIM_Monstar_HappyRearUp,
    ANIM_Monstar_RearUp,
    ANIM_LIST_END
};

NpcData N(NpcData_Monstar) = {
    .id = NPC_Monstar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Monstar),
    .settings = &N(NpcSettings_Monstar),
    .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Monstar_Idle1,
        .walk   = ANIM_Monstar_Idle1,
        .run    = ANIM_Monstar_Idle1,
        .chase  = ANIM_Monstar_Idle1,
        .anim_4 = ANIM_Monstar_Idle1,
        .anim_5 = ANIM_Monstar_Idle1,
        .death  = ANIM_Monstar_Idle1,
        .hit    = ANIM_Monstar_Idle1,
        .anim_8 = ANIM_Monstar_Idle1,
        .anim_9 = ANIM_Monstar_Idle1,
        .anim_A = ANIM_Monstar_Idle1,
        .anim_B = ANIM_Monstar_Idle1,
        .anim_C = ANIM_Monstar_Idle1,
        .anim_D = ANIM_Monstar_Idle1,
        .anim_E = ANIM_Monstar_Idle1,
        .anim_F = ANIM_Monstar_Idle1,
    },
    .extraAnimations = N(ExtraAnims_Monstar),
};

AnimID N(ExtraAnims_StarKid)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Angry,
    ANIM_Twink_Shout,
    ANIM_LIST_END
};

NpcData N(NpcData_StarKids)[] = {
    {
        .id = NPC_StarKid_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_10,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_11,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_12,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_13,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_14,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_15,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_16,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_StarKid),
        .settings = &N(NpcSettings_Twink),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
};

NpcData N(NpcData_Gulpit)[] = {
    {
        .id = NPC_Gulpit,
        .pos = { -75.0f, 0.0f, 0.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -75, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -75, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_Gulpit),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = GULPIT_DROPS,
        .animations = GULPIT_ANIMS,
        .extraAnimations = N(ExtraAnims_Gulpit),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    GULPIT_HITBOX(NPC_Gulpit_Hitbox),
};

NpcData N(NpcData_FrostPiranha_01)[] = {
    {
        .id = NPC_FrostPiranha_01,
        .pos = { 100.0f, 0.0f, 50.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 100, 0, 50 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 100, 0, 50 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_FrostPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = FROST_PIRANHA_DROPS,
        .animations = FROST_PIRANHA_ANIMS,
        .extraAnimations = N(ExtraAnims_FrostPiranha),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_PIRANHA_HITBOX(NPC_FrostPiranha_01_Hitbox),
};

NpcData N(NpcData_FrostPiranha_02)[] = {
    {
        .id = NPC_FrostPiranha_02,
        .pos = { -400.0f, 0.0f, 0.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -400, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -400, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .settings = &N(NpcSettings_FrostPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = FROST_PIRANHA_DROPS,
        .animations = FROST_PIRANHA_ANIMS,
        .extraAnimations = N(ExtraAnims_FrostPiranha),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_PIRANHA_HITBOX(NPC_FrostPiranha_02_Hitbox),
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_Monstar), BTL_SAM2_FORMATION_00, BTL_SAM2_STAGE_05),
    NPC_GROUP(N(NpcData_StarKids), BTL_SAM2_FORMATION_00, BTL_SAM2_STAGE_05),
    NPC_GROUP(N(NpcData_FrostPiranha_01), BTL_SAM_FORMATION_06, BTL_SAM_STAGE_05),
    NPC_GROUP(N(NpcData_FrostPiranha_02), BTL_SAM_FORMATION_0A, BTL_SAM_STAGE_05),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_FrostPiranha_01), BTL_SAM_FORMATION_06, BTL_SAM_STAGE_05),
    NPC_GROUP(N(NpcData_FrostPiranha_02), BTL_SAM_FORMATION_0A, BTL_SAM_STAGE_05),
    NPC_GROUP(N(NpcData_Gulpit), BTL_SAM_FORMATION_01, BTL_SAM_STAGE_05),
    {}
};
