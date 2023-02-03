#include "sam_05.h"
#include "sprite.h"

NpcSettings N(NpcSettings_Monstar) = {
    .height = 150,
    .radius = 150,
    .level = 99,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/npc/Twink.inc.c"

#include "world/common/enemy/complete/Gulpit.inc.c"
#include "world/common/enemy/complete/FrostPiranha.inc.c"

EvtScript N(EVS_NpcAI_Monstar) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(EVS_NpcAux_Monstar);

EvtScript N(EVS_NpcDefeat_Monstar) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Monstar)))
            EVT_EXEC_WAIT(N(EVS_Scene_MonstarDefeated))
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_CALL(ClearDefeatedEnemies)
    EVT_RETURN
    EVT_END
};

#include "world/area_sam/sam_05/monstar.png.inc.c"
#include "world/area_sam/sam_05/monstar_blank1.png.inc.c"
#include "world/area_sam/sam_05/monstar_blank2.png.inc.c"
#include "world/area_sam/sam_05/monstar_blank3.png.inc.c"
#include "world/area_sam/sam_05/monstar.pal.inc.c"
#include "world/area_sam/sam_05/monstar.png.h"

//TODO borrowed from sprite.c
typedef struct UnkFoldStruct {
    /* 0x00 */ IMG_PTR raster;
    /* 0x04 */ PAL_PTR palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Gfx* unk_14;
} UnkFoldStruct; // size = 0x18

UnkFoldStruct N(MonstarDetailTexture) = {
    .raster  = N(monstar_png),
    .palette = N(monstar_pal),
    .width   = N(monstar_png_width),
    .height  = N(monstar_png_height),
    .unk_0C  = -2,
    .unk_10  = 0,
    .unk_14  = N(monstar_gfx),
};

API_CALLABLE(N(UpdateMonstarSpriteEffects)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    u8 sp20[20];
    u8 sp38[20];
    u8 sp50[20];
    u8 sp68[20];
    s32 i;

    if (isInitialCall) {
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }

    if (enemy->varTable[3] == 0) {
        func_802DE780(npc->spriteInstanceID, 1, FOLD_TYPE_7, 255, 255, 255, 0, 0);
        return ApiStatus_BLOCK;
    }

    func_802DE780(npc->spriteInstanceID, 0, FOLD_TYPE_11, 20, 0, 0, 255, 0);
    script->functionTemp[0] += 10;
    if (script->functionTemp[0] >= 360) {
        script->functionTemp[0] %= 360;
    }

    for (i = 0; i < 20; i++) {
        sp20[i] = (cosine(script->functionTemp[0] + (i * 25)) + 1.0) * 56.0;
        sp38[i] = (cosine(script->functionTemp[0] + (i * 25) + 45) + 1.0) * 56.0;
        sp50[i] = (cosine(script->functionTemp[0] + (i * 25) + 90) + 1.0) * 56.0;
        sp68[i] = enemy->varTable[3];

        func_802DE780(npc->spriteInstanceID, 0, FOLD_TYPE_C, i, (sp20[i] << 24) | (sp38[i] << 16) | (sp50[i] << 8) | sp68[i], 0, 255, 0);
    }

    if (enemy->varTable[3] == 255) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        func_802DE780(npc->spriteInstanceID, 1, FOLD_TYPE_F, (s32) &N(MonstarDetailTexture), 255, 0, 255, 0);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        func_802DE780(npc->spriteInstanceID, 1, FOLD_TYPE_F, (s32) &N(MonstarDetailTexture), enemy->varTable[3], 0, enemy->varTable[3], 0);
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(CheckSkipInput)) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_NpcAux_Monstar) = {
    EVT_CALL(N(UpdateMonstarSpriteEffects))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Monstar) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcVar, NPC_Monstar, 3, 255)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Monstar)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_MONSTAR)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_EXEC(N(EVS_Scene_MonstarAppears))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Monstar)))
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Monstar)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Twink_Shout)
    EVT_RETURN
    EVT_END
};

s32 N(ExtraAnims_Monstar)[] = {
    ANIM_Monstar_Still,
    ANIM_Monstar_Idle1,
    ANIM_Monstar_Hurt,
    ANIM_Monstar_Talk,
    ANIM_Monstar_HappyTalk,
    ANIM_Monstar_Flail,
    ANIM_Monstar_HappyRearUp,
    ANIM_Monstar_RearUp,
    -1
};

StaticNpc N(NpcData_Monstar) = {
    .id = NPC_Monstar,
    .settings = &N(NpcSettings_Monstar),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_40000,
    .init = &N(EVS_NpcInit_Monstar),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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

s32 N(ExtraAnims_StarKid)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Angry,
    ANIM_Twink_Shout,
    -1
};

StaticNpc N(NpcData_StarKids)[] = {
    {
        .id = NPC_StarKid_01,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_02,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_03,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_04,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_05,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_06,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_07,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_08,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_09,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_10,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_11,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_12,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_13,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_14,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_15,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
    {
        .id = NPC_StarKid_16,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_StarKid),
        .drops = NPC_NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_StarKid),
    },
};

StaticNpc N(NpcData_Gulpit)[] = {
    {
        .id = NPC_Gulpit,
        .settings = &N(NpcSettings_Gulpit),
        .pos = { -75.0f, 0.0f, 0.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400,
        .drops = GULPIT_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -75, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -75, 0, 0 },
                .detectSize = { 200 },
            }
        },
        .animations = GULPIT_ANIMS,
        .extraAnimations = N(ExtraAnims_Gulpit),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    GULPIT_HITBOX(NPC_Gulpit_Hitbox),
};

StaticNpc N(NpcData_FrostPiranha_01)[] = {
    {
        .id = NPC_FrostPiranha_01,
        .settings = &N(NpcSettings_FrostPiranha),
        .pos = { 100.0f, 0.0f, 50.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_400,
        .drops = FROST_PIRANHA_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 100, 0, 50 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 100, 0, 50 },
                .detectSize = { 200 },
            }
        },
        .animations = FROST_PIRANHA_ANIMS,
        .extraAnimations = N(ExtraAnims_FrostPiranha),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FROST_PIRANHA_HITBOX(NPC_FrostPiranha_01_Hitbox),
};

StaticNpc N(NpcData_FrostPiranha_02)[] = {
    {
        .id = NPC_FrostPiranha_02,
        .settings = &N(NpcSettings_FrostPiranha),
        .pos = { -400.0f, 0.0f, 0.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_400,
        .drops = FROST_PIRANHA_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -400, 0, 0 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -400, 0, 0 },
                .detectSize = { 200 },
            }
        },
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
