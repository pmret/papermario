#include "tst_13.h"

void mdl_project_tex_coords(s32 modelID, Gfx* destGfx, Matrix4f destMtx, void* destVertices);

extern EvtScript N(EVS_Main);
extern EvtScript N(D_80240510_B1DC70);
extern EvtScript N(D_80240894_B1DFF4);
extern EvtScript N(D_80240A58_B1E1B8);
extern NpcGroupList N(DefaultNPCs);

extern Gfx N(shockwave_gfx)[];
extern s32 N(D_80242BF8_B20358);

ApiStatus N(func_80240000_B1D760)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 dist = dist2D(playerStatus->position.x, playerStatus->position.z, script->array[2], script->array[3]);

    script->varTable[0] = 1;
    if (playerStatus->actionState != ACTION_STATE_SPIN_POUND && playerStatus->actionState != ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = 0;
    }
    if (script->array[4] <= dist) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

#include "world/common/UnkDistFunc2.inc.c"

void N(func_8024013C_B1D89C)(void) {
    Matrix4f sp10;
    Matrix4f sp50;
    f32 x, y, z;

    N(D_80242BF8_B20358) += 1;
    guTranslateF(sp10, gPlayerStatus.position.x, 0.0f, gPlayerStatus.position.z);

    x = (sin_rad(N(D_80242BF8_B20358) / 50.0f) * 0.5) + 0.5;
    y = SQ(cos_rad(N(D_80242BF8_B20358) / 50.0f)) + 0.1;
    z = (sin_rad(N(D_80242BF8_B20358) / 50.0f) * 0.5) + 0.5;

    guScaleF(sp50, x, y, z);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);
    mdl_project_tex_coords(1, N(shockwave_gfx), sp10, NULL);

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    mdl_draw_hidden_panel_surface(&gMasterGfxPos, 1);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, N(shockwave_gfx));
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}

EntryList N(Entrances) = {
    [tst_13_ENTRY_0]    {    0.0,    0.0,  100.0,   90.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
};

EvtScript N(EVS_80240410) = {
    EVT_USE_BUF(LVar0)
    EVT_MALLOC_ARRAY(6, LVarA)
    EVT_BUF_READ1(LVar0)
    EVT_SET(ArrayVar(0), LVar0)
    EVT_BUF_READ1(LVar0)
    EVT_SET(ArrayVar(1), LVar0)
    EVT_BUF_READ1(LVar0)
    EVT_SET(ArrayVar(2), LVar0)
    EVT_BUF_READ1(LVar0)
    EVT_SET(ArrayVar(3), LVar0)
    EVT_BUF_READ1(LVar0)
    EVT_SET(ArrayVar(4), LVar0)
    EVT_BUF_READ1(LVar0)
    EVT_SET(ArrayVar(5), LVar0)
    EVT_SET(LVar0, LVarA)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80240510_B1DC70)), TRIGGER_FLOOR_TOUCH, ArrayVar(0), 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240510_B1DC70) = {
    EVT_USE_ARRAY(LVar0)
    EVT_CALL(N(func_80240000_B1D760))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_LOOP(5)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, ArrayVar(0), COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, ArrayVar(1), TRUE)
        EVT_WAIT(1)
        EVT_CALL(ModifyColliderFlags, 0, ArrayVar(0), COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, ArrayVar(1), FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_IF_NE(ArrayVar(5), 0)
        EVT_EXEC_WAIT(ArrayVar(5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240600_B1DD60) = {
    EVT_USE_BUF(LVar0)
    EVT_MALLOC_ARRAY(6, LVar9)
    EVT_BUF_READ1(LVar1)
    EVT_SET(ArrayVar(0), LVar1)
    EVT_BUF_READ1(LVar1)
    EVT_SET(ArrayVar(1), LVar1)
    EVT_BUF_READ1(LVar1)
    EVT_SET(ArrayVar(2), LVar1)
    EVT_BUF_READ1(LVar1)
    EVT_SET(ArrayVar(3), LVar1)
    EVT_BUF_READ1(LVar1)
    EVT_SET(ArrayVar(4), LVar1)
    EVT_BUF_READ1(LVar1)
    EVT_SET(ArrayVar(5), LVar1)
    EVT_CALL(ParentColliderToModel, ArrayVar(1), ArrayVar(0))
    EVT_LABEL(0)
    EVT_LABEL(1)
    EVT_CALL(GetPlayerActionState, LVarA)
    EVT_IF_EQ(LVarA, ACTION_STATE_SPIN_JUMP)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_IF_EQ(LVarA, ACTION_STATE_TORNADO_JUMP)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_LABEL(2)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_NE(LVar2, ArrayVar(3))
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(N(UnkDistFunc2))
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(D_80240894_B1DFF4))
    EVT_END_IF
    EVT_IF_EQ(LVar0, 2)
        EVT_EXEC_WAIT(N(D_80240A58_B1E1B8))
    EVT_END_IF
    EVT_LABEL(3)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN_JUMP)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_IF_EQ(LVar0, ACTION_STATE_TORNADO_JUMP)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240894_B1DFF4) = {
    EVT_USE_ARRAY(LVar9)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, 0, 5, 3, EASING_QUADRATIC_IN)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, LVar0)
    EVT_CALL(SetPlayerPos, LVar2, LVar5, LVar4)
    EVT_CALL(UpdateColliderTransform, ArrayVar(1))
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(MakeLerp, 5, 0, 3, EASING_QUADRATIC_IN)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, LVar0)
    EVT_CALL(SetPlayerPos, LVar2, LVar5, LVar4)
    EVT_CALL(UpdateColliderTransform, ArrayVar(1))
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240A58_B1E1B8) = {
    EVT_USE_ARRAY(LVar9)
    EVT_CALL(MakeItemEntity, ArrayVar(5), ArrayVar(2), ArrayVar(3), ArrayVar(4), ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    EVT_SET(LVar2, 0)
    EVT_CALL(MakeLerp, 0, 150, 19, EASING_QUADRATIC_OUT)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
    EVT_ADD(LVar2, 45)
    EVT_CALL(RotateModel, ArrayVar(0), LVar2, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(MakeLerp, 150, 0, 19, EASING_QUADRATIC_OUT)
    EVT_LABEL(3)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, ArrayVar(0), 0, LVar0, 0)
    EVT_ADD(LVar2, 45)
    EVT_CALL(RotateModel, ArrayVar(0), LVar2, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_00) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_00) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldBombette_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_01) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldParakarry_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_02) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldBow_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_03) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldWatt_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_04) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldSushie_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_05) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldLakilester_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_06) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldLakilester_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_07) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldLakilester_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_08) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_09) = {
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_WorldKooper_Idle)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_00) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_00),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_01) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_01),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_02) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_02),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_03) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_03),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_04) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_04),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_05) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_05),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_06) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_06),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_07) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_07),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_08) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_08),
    .flags = ENEMY_FLAGS_1,
};

NpcSettings N(NpcSettings_09) = {
    .defaultAnim = ANIM_Koopa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .onInteract = &N(EVS_NpcInteract_09),
    .flags = ENEMY_FLAGS_1,
};

StaticNpc N(D_80240F38_B1E698)[] = {
    {
        .id = NPC_00,
        .settings = &N(NpcSettings_00),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_01,
        .settings = &N(NpcSettings_01),
        .pos = { 20.0f, 0.0f, 20.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_02,
        .settings = &N(NpcSettings_02),
        .pos = { 40.0f, 0.0f, 40.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_03,
        .settings = &N(NpcSettings_03),
        .pos = { 60.0f, 0.0f, 60.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_04,
        .settings = &N(NpcSettings_04),
        .pos = { 80.0f, 0.0f, 80.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_05,
        .settings = &N(NpcSettings_05),
        .pos = { 100.0f, 0.0f, 100.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_06,
        .settings = &N(NpcSettings_06),
        .pos = { 120.0f, 0.0f, 120.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_07,
        .settings = &N(NpcSettings_07),
        .pos = { 140.0f, 0.0f, 140.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_08,
        .settings = &N(NpcSettings_08),
        .pos = { 160.0f, 0.0f, 160.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
    {
        .id = NPC_09,
        .settings = &N(NpcSettings_09),
        .pos = { 180.0f, 0.0f, 180.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .animations = {
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(D_80240F38_B1E698)),
    {}
};

#include "world/area_tst/tst_13/shockwave.vtx.inc.c"
#include "world/area_tst/tst_13/shockwave.gfx.inc.c"

Gfx N(dummy_gfx)[] = {
    gsSPEndDisplayList()
};

s32 N(D_80242BF8_B20358) = 0;

s32 N(D_80242BFC_B2035C)[] = {
    5, 4, -35, 0, -45, 342 
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TESTING)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, EVT_PTR(N(D_80242BFC_B2035C)))
    EVT_EXEC(N(D_80240600_B1DD60))
    EVT_CALL(SetModelCustomGfx, MODEL_o152, 0, -1)
    EVT_CALL(SetCustomGfxBuilders, 0, 0, EVT_PTR(N(func_8024013C_B1D89C)))
    EVT_RETURN
    EVT_END
};
