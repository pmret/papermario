#include "kzn_17.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_80245CE8);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [kzn_17_ENTRY_0]    { -670.0,    0.0,  160.0,   90.0 },
    [kzn_17_ENTRY_1]    {  620.0,    0.0,   30.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_17 },
};

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(D_8024319C_C88C4C) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, 3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -200,    0,  600, -400)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802432B8_C88D68) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, 4)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  500,    0,    0, -400)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kzn_11_1) = EVT_EXIT_WALK(60, kzn_17_ENTRY_0, "kzn_11", kzn_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_18_0) = EVT_EXIT_WALK(60, kzn_17_ENTRY_1, "kzn_18", kzn_18_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_17)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_EXEC(N(EVS_80245CE8))
    EVT_SET(LVar0, 42)
    EVT_EXEC(N(D_8024319C_C88C4C))
    EVT_SET(LVar0, 43)
    EVT_EXEC(N(D_802432B8_C88D68))
    EVT_RETURN
    EVT_END
};

s32 N(Unused_8024360C_360C)[] = {
    0x00000000, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x01010101, 
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x01010000, 
};

EvtScript N(D_8024364C_C890FC) = {
    EVT_SET(GF_KZN17_Hammer3BlockA, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024366C_C8911C) = {
    EVT_SET(GF_KZN17_Hammer3BlockB, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024368C_C8913C) = {
    EVT_SET(GF_KZN17_Hammer3BlockC, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802436AC_C8915C) = {
    EVT_SET(GF_KZN17_Hammer3BlockD, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802436CC_C8917C) = {
    EVT_SET(GF_KZN17_Hammer3BlockE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802436EC_C8919C) = {
    EVT_SET(GF_KZN17_Hammer3BlockF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024370C_C891BC) = {
    EVT_SET(GF_KZN17_Hammer3BlockG, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KZN17_Hammer3BlockA, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -195, 50, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_8024364C_C890FC)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockB, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -245, 60, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_8024366C_C8911C)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockC, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -295, 70, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_8024368C_C8913C)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockD, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -345, 80, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_802436AC_C8915C)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockE, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -395, 90, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_802436CC_C8917C)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockF, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -445, 100, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_802436EC_C8919C)))
    EVT_END_IF
    EVT_IF_EQ(GF_KZN17_Hammer3BlockG, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -495, 110, 27, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_8024370C_C891BC)))
    EVT_END_IF
    EVT_CALL(CreatePushBlockGrid, 0, 29, 2, -119, -3, 5, 0)
    EVT_CALL(SetPushBlock, 0, 28, 1, 1)
    EVT_RETURN
    EVT_END
};
