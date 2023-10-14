#include "flo_14.h"
#include "effects.h"
#include "model.h"

#include "../common/FlowerSpawnRegion.inc.c"
#include "../common/DroppingVine.inc.c"

s32 N(BlowingBubbles) = FALSE;

EvtScript N(EVS_BubbleUpdateCamera) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(MakeLerp, LVar1, 48, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, 48, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherParterToPlayer) = {
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, -5)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SavePartnerFlags)) {
    if (gPlayerData.curPartner == PARTNER_NONE) {
        script->varTable[14] = FALSE;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = TRUE;
    evt_set_variable(NULL, MV_SavedPartnerFlags, get_npc_unsafe(NPC_PARTNER)->flags);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RestorePartnerFlags)) {
    get_npc_unsafe(NPC_PARTNER)->flags = evt_get_variable(NULL, MV_SavedPartnerFlags);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateBubbleSoundPos)) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_LRAW_BUBBLE_DRIFT, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    return ApiStatus_DONE2;
}

Vec3f N(BubbleFlightPath)[] = {
    {  531.0,    75.0,   81.0 },
    {  481.0,    80.0,   81.0 },
    {  431.0,    75.0,   81.0 },
    {  381.0,    70.0,   81.0 },
    {  331.0,    75.0,   81.0 },
    {  281.0,    80.0,   81.0 },
    {  231.0,    75.0,   81.0 },
    {  181.0,    70.0,   81.0 },
    {  131.0,    75.0,   81.0 },
    {   81.0,    80.0,   81.0 },
    {   31.0,    75.0,   81.0 },
    {  -19.0,    70.0,   81.0 },
    {  -69.0,    75.0,   81.0 },
};

EvtScript N(EVS_BubbleFollowPath) = {
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_LOOP_BUBBLE_DRIFT)
    EVT_CALL(LoadPath, 165, EVT_PTR(N(BubbleFlightPath)), ARRAY_COUNT(N(BubbleFlightPath)), EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(TranslateModel, MODEL_o167, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, -27)
        EVT_ADD(LVar3, -10)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_CALL(N(UpdateBubbleSoundPos), LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(StopSound, SOUND_LOOP_BUBBLE_DRIFT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RideBigBubble) = {
    EVT_CALL(IsPlayerWithin, 531, 81, 30, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(GetModelCenter, MODEL_o167)
    EVT_THREAD
        EVT_ADD(LVar2, -10)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
        EVT_CALL(PlayerJump, 531, 48, LVar2, 10)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_ADD(LVar2, -15)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.2))
        EVT_CALL(NpcJump0, NPC_PARTNER, 531, 68, LVar2, 10)
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(EVS_BubbleUpdateCamera), MV_BubbleCamScript)
    EVT_WAIT(15)
    EVT_CALL(N(SavePartnerFlags))
    EVT_IF_TRUE(LVarE)
        EVT_EXEC_GET_TID(N(EVS_TetherParterToPlayer), LVarE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_BubbleFollowPath))
    EVT_IF_TRUE(LVarE)
        EVT_KILL_THREAD(LVarE)
        EVT_CALL(N(RestorePartnerFlags))
    EVT_END_IF
    EVT_CALL(GetModelCenter, MODEL_o167)
    EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, 2, 0)
    EVT_CALL(PlaySoundAt, SOUND_BUBBLE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(EnableModel, MODEL_o167, FALSE)
    EVT_SET(AF_FLO_BigBubbleReady, FALSE)
    EVT_KILL_THREAD(MV_BubbleCamScript)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BlowBigBubble) = {
    EVT_CALL(PlaySoundAt, SOUND_FLO_BLOW_BUBBLE, SOUND_SPACE_DEFAULT, 591, 55, 121)
    EVT_CALL(EnableModel, MODEL_o167, TRUE)
    EVT_SETF(LVar2, EVT_FLOAT(1.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_SETF(LVar6, EVT_FLOAT(0.0))
    EVT_SET(LVar7, -30)
    EVT_SET(LVar8, 20)
    EVT_DIVF(LVar7, EVT_FLOAT(90.0))
    EVT_DIVF(LVar8, EVT_FLOAT(90.0))
    EVT_SET(LVar9, 180)
    EVT_LOOP(LVar9)
        EVT_CALL(TranslateModel, MODEL_o167, 591, 55, 121)
        EVT_SETF(LVar3, LVar2)
        EVT_DIVF(LVar3, 10)
        EVT_CALL(ScaleModel, MODEL_o167, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, MODEL_o167, LVar4, LVar5, LVar6)
        EVT_ADDF(LVar2, EVT_FLOAT(0.05))
        EVT_IF_GT(LVar9, 90)
            EVT_ADDF(LVar4, LVar7)
            EVT_ADDF(LVar5, LVar8)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar7, -30)
    EVT_SET(LVar8, -40)
    EVT_DIVF(LVar7, EVT_FLOAT(60.0))
    EVT_DIVF(LVar8, EVT_FLOAT(60.0))
    EVT_LOOP(60)
        EVT_CALL(TranslateModel, MODEL_o167, 591, 55, 121)
        EVT_CALL(ScaleModel, MODEL_o167, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, MODEL_o167, LVar4, LVar5, LVar6)
        EVT_ADDF(LVar4, LVar7)
        EVT_ADDF(LVar6, LVar8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(AF_FLO_BlowingBigBubble, FALSE)
    EVT_SET(AF_FLO_BigBubbleReady, TRUE)
    EVT_RETURN
    EVT_END
};

f32 N(BubblePhase) = 0.0f;

void N(gfx_build_big_bubble)(void) {
    Matrix4f matrix;
    Vtx* src;
    Vtx* dest;
    s32 copyCount;
    s32 new_var;

    guMtxIdentF(matrix);

    matrix[0][0] = (sin_rad(N(BubblePhase) / 11.0f) * 0.04) + 0.98;
    matrix[0][1] = (sin_rad(N(BubblePhase) / 12.0f) * 0.04);
    matrix[0][2] = (cos_rad(N(BubblePhase) / 13.0f) * 0.04);

    matrix[1][1] = (sin_rad(N(BubblePhase) / 7.0f + 1.0f) * 0.04) + 0.98;
    matrix[1][0] = (sin_rad(N(BubblePhase) / 14.0f) * 0.04);
    matrix[1][2] = (cos_rad(N(BubblePhase) / 15.0f) * 0.04);

    matrix[2][2] = (sin_rad(N(BubblePhase) * 0.25f + 2.0f)  * 0.04) + 0.98;
    matrix[2][0] = (sin_rad(N(BubblePhase) * 0.0625f) * 0.04);
    matrix[2][1] = (cos_rad(N(BubblePhase) / 17.0f) * 0.04);

    guMtxF2L(matrix, &gDisplayContext->matrixStack[gMatrixListPos]);
    mdl_get_copied_vertices(VTX_COPY_0, &src, &dest, &copyCount);

    new_var = 0;
    while (new_var); // TODO required to match

    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_0));

    N(BubblePhase) += 1.0f;
}

s32 N(FlowerPhase) = 90;

void N(gfx_build_bubble_flower)(void) {
    s32 i;
    Vtx* verts;
    Vtx* copied;
    s32 numCopied;
    f32 openedScale; // controls how open the flower is
    f32 lengthScale; // controls longitudinal pulsing

    mdl_get_copied_vertices(VTX_COPY_1, &verts, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        Vtx* src = &verts[i];
        Vtx* copy = &copied[i];

        if (src->v.ob[0] <= 600) {
            openedScale = 0.7 + (sin_rad((N(FlowerPhase) / 180.0f) * PI_D) * 0.3);
            lengthScale = 0.2 - (sin_rad((N(FlowerPhase) / 180.0f) * PI_D) * 0.2);
            copy->v.ob[0] = ((src->v.ob[0] - 616) * openedScale) + 616.0f + (lengthScale * -48.0f);
            copy->v.ob[1] = ((src->v.ob[1] -  44) * openedScale) +  44.0f + (lengthScale *  25.0f);
            copy->v.ob[2] = ((src->v.ob[2] - 113) * openedScale) + 113.0f + (lengthScale * -87.0f);
        }
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_1));

    if (evt_get_variable(NULL, AF_FLO_BlowingBigBubble)) {
        if (N(FlowerPhase) > 90) {
            N(FlowerPhase) -= 360;
        }
        if (N(FlowerPhase) >= -90) {
            N(FlowerPhase) += 5;
        } else {
            N(FlowerPhase) += 20;
        }
        if (N(FlowerPhase) >= 90) {
            N(FlowerPhase) = 90;
        }
    } else {
        if (N(FlowerPhase) > 140 && N(FlowerPhase) < 260) {
            N(BlowingBubbles) = TRUE;
        } else {
            N(BlowingBubbles) = FALSE;
        }
        N(FlowerPhase) += 5;
    }

    if (N(FlowerPhase) >= 360) {
        N(FlowerPhase) -= 360;
    }
}

EvtScript N(EVS_ManageBlownBubble) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVarF, LVar0)
    EVT_LABEL(0)
        EVT_IF_EQ(AF_FLO_PauseBlowingBubbles, TRUE)
            EVT_WAIT(10)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_USE_BUF(EVT_PTR(N(BlowingBubbles)))
        EVT_BUF_READ1(LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_CALL(RandInt, 10, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_WAIT(LVar0)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(EnableModel, LVarF, TRUE)
        EVT_CALL(RandInt, 4, LVar0)
        EVT_ADDF(LVar0, EVT_FLOAT(4.0))
        EVT_MULF(LVar0, EVT_FLOAT(-1.0))
        EVT_SETF(LVar1, EVT_FLOAT(2.0))
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, EVT_FLOAT(10.0))
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
        EVT_SETF(LVar4, EVT_FLOAT(591.0))
        EVT_SETF(LVar5, EVT_FLOAT(60.0))
        EVT_SETF(LVar6, EVT_FLOAT(121.0))
        EVT_CALL(RandInt, 3, LVar7)
        EVT_ADDF(LVar7, EVT_FLOAT(3.0))
        EVT_MULF(LVar7, EVT_FLOAT(0.04))
        EVT_SETF(LVar9, LVar7)
        EVT_DIVF(LVar9, EVT_FLOAT(5.0))
        EVT_CALL(RandInt, 50, LVar8)
        EVT_ADD(LVar8, 50)
        EVT_LOOP(LVar8)
            EVT_SETF(LVarE, LVar2)
            EVT_SUBF(LVarE, LVar0)
            EVT_MULF(LVarE, EVT_FLOAT(0.046))
            EVT_ADDF(LVar0, LVarE)
            EVT_SETF(LVarE, LVar3)
            EVT_SUBF(LVarE, LVar1)
            EVT_MULF(LVarE, EVT_FLOAT(0.046))
            EVT_ADDF(LVar1, LVarE)
            EVT_ADDF(LVar4, LVar0)
            EVT_ADDF(LVar5, LVar1)
            EVT_SETF(LVarE, LVar7)
            EVT_SUBF(LVarE, LVar9)
            EVT_MULF(LVarE, EVT_FLOAT(0.203))
            EVT_ADDF(LVar9, LVarE)
            EVT_CALL(TranslateModel, LVarF, LVar4, LVar5, LVar6)
            EVT_CALL(ScaleModel, LVarF, LVar9, LVar9, LVar9)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableModel, LVarF, FALSE)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBubbles) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o129, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o155, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o156, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o157, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o158, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -730, -130, -470,  -70,  0)
    EVT_FLOWER_SPAWN_REGION( -730,   70, -470,  140,  0)
    EVT_FLOWER_SPAWN_REGION( -280,  130, -110,  -70,  0)
    EVT_FLOWER_SPAWN_REGION( -280,   70,  -10,  140,  0)
    EVT_DROPPING_VINE(ITEM_STINKY_HERB, MODEL_o92, MODEL_o93, MODEL_o94, MODEL_o95)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o82, MODEL_o83, MODEL_o84, MODEL_o85)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o78, MODEL_o79, MODEL_o80, MODEL_o81)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o88, MODEL_o89, MODEL_o90, MODEL_o91)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o113, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(CloneModel, MODEL_o169, CLONED_MODEL(1))
    EVT_CALL(CloneModel, MODEL_o169, CLONED_MODEL(2))
    EVT_CALL(CloneModel, MODEL_o169, CLONED_MODEL(3))
    EVT_CALL(CloneModel, MODEL_o169, CLONED_MODEL(4))
    EVT_CALL(CloneModel, MODEL_o169, CLONED_MODEL(5))
    EVT_CALL(EnableModel, MODEL_o167, FALSE)
    EVT_CALL(EnableModel, MODEL_o169, FALSE)
    EVT_CALL(EnableModel, CLONED_MODEL(1), FALSE)
    EVT_CALL(EnableModel, CLONED_MODEL(2), FALSE)
    EVT_CALL(EnableModel, CLONED_MODEL(3), FALSE)
    EVT_CALL(EnableModel, CLONED_MODEL(4), FALSE)
    EVT_CALL(EnableModel, CLONED_MODEL(5), FALSE)
    EVT_SET(LVar0, CLONED_MODEL(1))
    EVT_EXEC(N(EVS_ManageBlownBubble))
    EVT_SET(LVar0, CLONED_MODEL(2))
    EVT_EXEC(N(EVS_ManageBlownBubble))
    EVT_SET(LVar0, CLONED_MODEL(3))
    EVT_EXEC(N(EVS_ManageBlownBubble))
    EVT_SET(LVar0, CLONED_MODEL(4))
    EVT_EXEC(N(EVS_ManageBlownBubble))
    EVT_SET(LVar0, CLONED_MODEL(5))
    EVT_EXEC(N(EVS_ManageBlownBubble))
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_0, MODEL_o167, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(gfx_build_big_bubble)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_o167, CUSTOM_GFX_1, -1)
    EVT_CALL(SetModelCustomGfx, CLONED_MODEL(1), 1, -1)
    EVT_CALL(SetModelCustomGfx, CLONED_MODEL(2), 1, -1)
    EVT_CALL(SetModelCustomGfx, CLONED_MODEL(3), 1, -1)
    EVT_CALL(SetModelCustomGfx, CLONED_MODEL(4), 1, -1)
    EVT_CALL(SetModelCustomGfx, CLONED_MODEL(5), 1, -1)
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_1, MODEL_o57, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_2, EVT_PTR(N(gfx_build_bubble_flower)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_o57, CUSTOM_GFX_2, -1)
    EVT_RETURN
    EVT_END
};
