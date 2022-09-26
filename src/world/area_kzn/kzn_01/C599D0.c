#include "kzn_01.h"
#include "sprite/npc/LargePiranha.h"
#include "world/entrances.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNpcs);

enum {
	NPC_PutridPiranha   = 0,
};

EntryList N(Entrances) = {
    { -445.0,    0.0,    0.0,   90.0 },  /* kzn_01_ENTRY_0 */
    {  425.0, -255.0,    0.0,  270.0 },  /* kzn_01_ENTRY_1 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_01 },
};

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(EVS_StartTexPanner3) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(-200, 0, 600, -400)
        TEX_PAN_PARAMS_FREQ(   1, 0,   1,    1)
        TEX_PAN_PARAMS_INIT(   0, 0,   0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanner4) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_4)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(500, 0, 0, -400)
        TEX_PAN_PARAMS_FREQ(  1, 0, 0,    1)
        TEX_PAN_PARAMS_INIT(  0, 0, 0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_jan_22) = EXIT_WALK_SCRIPT(60,  kzn_01_ENTRY_0, "jan_22",  jan_22_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_02) = EXIT_WALK_SCRIPT(60,  kzn_01_ENTRY_1, "kzn_02",  kzn_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_jan_22), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_02), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_01)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_SET(GF_MAP_MtLavalava, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_ENTERED_MT_LAVA_LAVA)
        EVT_SET(GB_StoryProgress, STORY_CH5_ENTERED_MT_LAVA_LAVA)
    EVT_END_IF
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNpcs)))
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner3))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PutridPiranha) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

EvtScript N(EVS_NpcIdle_PutridPiranha) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 225)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 270, -200, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_SELF, 320, -220, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim17)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LargePiranha_Putrid_Anim04, ANIM_LargePiranha_Putrid_Anim01, 0, MSG_CH5_00ED)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_DIG, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim18)
    EVT_WAIT(25)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_SET(GF_KZN01_IntruderAlert, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PutridPiranha) = {
    EVT_IF_EQ(GF_KZN01_IntruderAlert, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PutridPiranha)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcPutridPiranha) = {
    .id = NPC_PutridPiranha,
    .settings = &N(NpcSettings_PutridPiranha),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .yaw = 270,
    .flags = NPC_FLAG_4 | NPC_FLAG_200000,
    .init = &N(EVS_NpcInit_PutridPiranha),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_FIRE_FLOWER, 10, 0 }
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(3),
        .minCoinBonus = 0,
        .maxCoinBonus = 2,
    },
    .animations = {
        .idle   = ANIM_LargePiranha_Putrid_Anim01,
        .walk   = ANIM_LargePiranha_Putrid_Anim02,
        .run    = ANIM_LargePiranha_Putrid_Anim03,
        .chase  = ANIM_LargePiranha_Putrid_Anim03,
        .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
        .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
        .death  = ANIM_LargePiranha_Putrid_Anim0E,
        .hit    = ANIM_LargePiranha_Putrid_Anim0E,
        .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
        .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
        .anim_A = ANIM_LargePiranha_Putrid_Anim05,
        .anim_B = ANIM_LargePiranha_Putrid_Anim06,
        .anim_C = ANIM_LargePiranha_Putrid_Anim07,
        .anim_D = ANIM_LargePiranha_Putrid_Anim01,
        .anim_E = ANIM_LargePiranha_Putrid_Anim01,
        .anim_F = ANIM_LargePiranha_Putrid_Anim01,
    },
};

NpcGroupList N(DefaultNpcs) = {
    NPC_GROUP(N(NpcPutridPiranha)),
    {}
};
