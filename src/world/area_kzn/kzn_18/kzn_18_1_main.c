#include "kzn_18.h"

extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/kzn_SmokeTexPanners.inc.c"

EvtScript N(D_80240704_C8C7A4) = EVT_EXIT_WALK(60, kzn_18_ENTRY_0, "kzn_17", kzn_17_ENTRY_1);
EvtScript N(D_80240760_C8C800) = EVT_EXIT_WALK(60, kzn_18_ENTRY_1, "kzn_19", kzn_19_ENTRY_0);
EvtScript N(D_802407BC_C8C85C) = EVT_EXIT_WALK(60, kzn_18_ENTRY_2, "kzn_19", kzn_19_ENTRY_1);

EvtScript N(D_80240818_C8C8B8) = {
    EVT_BIND_TRIGGER(N(D_80240704_C8C7A4), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(N(D_80240760_C8C800), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(N(D_802407BC_C8C85C), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024087C_C8C91C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yougan1_1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_off1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_toro, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_poko, TRUE)
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_SET(LVar1, 200)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 400)
        EVT_SET(LVar4, -100)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 1)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 5)
        EVT_SET(LVar1, 300)
        EVT_SET(LVar2, -500)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, 13, 0, LVar0, 0)
            EVT_ADD(LVar0, 0x00008000)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o382, .pos = { 50.0, 200.0, -185.0 }},
    { .colliderID = -1 }
};

EvtScript N(D_80240B4C_C8CBEC) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(D_80240818_C8C8B8))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, N(D_80240818_C8C8B8))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_18)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(D_80240B4C_C8CBEC))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_CALL(EnableModel, MODEL_off1, FALSE)
        EVT_CALL(EnableModel, MODEL_o506, FALSE)
        EVT_CALL(EnableModel, MODEL_o509, FALSE)
        EVT_CALL(EnableModel, MODEL_o511, FALSE)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_off1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_off2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_off1, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(D_8024087C_C8C91C))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeRight))
    EVT_RETURN
    EVT_END
};
