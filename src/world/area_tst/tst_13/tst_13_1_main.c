#include "tst_13.h"

void mdl_project_tex_coords(s32 modelID, Gfx* destGfx, Matrix4f destMtx, void* destVertices);

extern EvtScript N(EVS_Main);
extern EvtScript N(D_80240510_B1DC70);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [tst_13_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

#include "world/common/atomic/BetaFloorPanels.inc.c"

EvtScript N(EVS_NpcAuxAI_00) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_00) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldBombette_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_01) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldParakarry_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_02) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldBow_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_03) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldWatt_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_04) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldSushie_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_05) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldLakilester_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_06) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldLakilester_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_07) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldLakilester_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_08) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldGoombario_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInteract_09) = {
    Call(SetNpcSprite, NPC_SELF, ANIM_WorldKooper_Idle)
    Return
    End
};

NpcSettings N(NpcSettings_00) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_00),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_01) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_01),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_02) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_02),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_03) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_03),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_04) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_04),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_05) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_05),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_06) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_06),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_07) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_07),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_08) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_08),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_09) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_09),
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcData N(NpcData_Testing)[] = {
    {
        .id = NPC_00,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_00),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_01,
        .pos = { 20.0f, 0.0f, 20.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_01),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_02,
        .pos = { 40.0f, 0.0f, 40.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_02),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_03,
        .pos = { 60.0f, 0.0f, 60.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_03),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_04,
        .pos = { 80.0f, 0.0f, 80.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_04),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_05,
        .pos = { 100.0f, 0.0f, 100.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_05),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_06,
        .pos = { 120.0f, 0.0f, 120.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_06),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_07,
        .pos = { 140.0f, 0.0f, 140.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_07),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_08,
        .pos = { 160.0f, 0.0f, 160.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_08),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
    {
        .id = NPC_09,
        .pos = { 180.0f, 0.0f, 180.0f },
        .yaw = 0,
        .settings = &N(NpcSettings_09),
        .flags = COMMON_PASSIVE_FLAGS,
        .animations = {
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Testing)),
    {}
};

#include "world/area_tst/tst_13/shockwave.vtx.inc.c"
#include "world/area_tst/tst_13/shockwave.gfx.inc.c"

Gfx N(dummy_gfx)[] = {
    gsSPEndDisplayList()
};

s32 N(BuildGfxCallCount) = 0;

void N(build_gfx_floor)(void) {
    Matrix4f sp10;
    Matrix4f sp50;
    f32 x, y, z;

    N(BuildGfxCallCount)++;
    guTranslateF(sp10, gPlayerStatus.pos.x, 0.0f, gPlayerStatus.pos.z);

    x = (sin_rad(N(BuildGfxCallCount) / 50.0f) * 0.5) + 0.5;
    y = SQ(cos_rad(N(BuildGfxCallCount) / 50.0f)) + 0.1;
    z = (sin_rad(N(BuildGfxCallCount) / 50.0f) * 0.5) + 0.5;

    guScaleF(sp50, x, y, z);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);
    mdl_project_tex_coords(MODEL_o152, N(shockwave_gfx), sp10, NULL);

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    mdl_draw_hidden_panel_surface(&gMainGfxPos, 1);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, N(shockwave_gfx));
    gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
}


s32 N(BetaPanelData)[] = {
    MODEL_point, COLLIDER_point, -35, 0, -45, ITEM_HEART
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TESTING)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Set(LVar0, Ref(N(BetaPanelData)))
    Exec(N(EVS_BetaPanel_Setup))
    Call(SetModelCustomGfx, MODEL_o152, CUSTOM_GFX_0, -1)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, 0, Ref(N(build_gfx_floor)))
    Return
    End
};
