#include "kzn_02.h"
#include "world/entrances.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_802444A4);
extern EvtScript N(EVS_802464A8);
extern NpcGroupList N(DefaultNpcs);

EntryList N(Entrances) = {
    { -810.0,   20.0,  -10.0,   90.0 },  /* kzn_02_ENTRY_0 */
    {  810.0,   20.0,  -10.0,  270.0 },  /* kzn_02_ENTRY_1 */
    { -810.0,   20.0,  -10.0,   90.0 },  /* kzn_02_ENTRY_2 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_02 },
};

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(D_8024292C_C5D06C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, 3)
    EVT_THREAD
        EVT_SET(LVar0, 3)
        EVT_SET(LVar1, -200)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 600)
        EVT_SET(LVar4, -400)
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
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242A48_C5D188) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, 4)
    EVT_THREAD
        EVT_SET(LVar0, 4)
        EVT_SET(LVar1, 500)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, -400)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 1)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242B64_C5D2A4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kzn_02_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, "kzn_01", kzn_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242BC0_C5D300) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kzn_02_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, "kzn_03", kzn_03_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242C1C_C5D35C) = {
    EVT_BIND_TRIGGER(N(D_80242B64_C5D2A4), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(D_80242BC0_C5D300), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242C64_C5D3A4) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kzn_02_ENTRY_2)
        EVT_SET(LVar0, N(D_80242C1C_C5D35C))
        EVT_EXEC(EnterWalk)
        EVT_WAIT(1)
    EVT_ELSE
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242CCC_C5D40C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yougan1_1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_yougan1_2, TRUE)
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
    { .colliderID = COLLIDER_o80, .pos = { -790.0, 20.0,  0.0 }},
    { .colliderID = COLLIDER_o81, .pos = { -790.0, 20.0,  0.0 }},
    { .colliderID = COLLIDER_o58, .pos = { -250.0, 20.0,  0.0 }},
    { .colliderID = COLLIDER_o59, .pos = { -250.0, 20.0,  0.0 }},
    { .colliderID = COLLIDER_o77, .pos = {  250.0, 20.0, 15.0 }},
    { .colliderID = COLLIDER_o78, .pos = {  250.0, 20.0, 15.0 }},
    { .colliderID = COLLIDER_o83, .pos = {  790.0, 20.0,  0.0 }},
    { .colliderID = COLLIDER_o84, .pos = {  790.0, 20.0,  0.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_02)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNpcs)))
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o112, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o217, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o218, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o219, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o220, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o221, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_o222, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_pp1, 0x3)
    EVT_CALL(ModifyColliderFlags, 3, COLLIDER_pp2, 0x3)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(D_80242CCC_C5D40C))
    EVT_SET(LVar0, 73)
    EVT_EXEC(N(D_8024292C_C5D06C))
    EVT_SET(LVar0, 74)
    EVT_EXEC(N(D_80242A48_C5D188))
    EVT_EXEC_WAIT(N(EVS_802444A4))
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_EXEC_WAIT(N(EVS_802464A8))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(D_80242C64_C5D3A4))
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_RETURN
    EVT_END
};
