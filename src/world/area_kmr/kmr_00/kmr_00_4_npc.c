#include "kmr_00.h"

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Goombaria_Stationary.inc.c"

// initial delay to start bobbing, ensuring star spirits motions are desync'd from one another
s16 N(StarSpiritBobDelays)[] = {
    [NPC_Eldstar  - 1]   1,
    [NPC_Mamar    - 1]   3,
    [NPC_Skolar   - 1]   5,
    [NPC_Muskular - 1]   7,
    [NPC_Misstar  - 1]   7,
    [NPC_Klevar   - 1]   5,
    [NPC_Kalmar   - 1]   3,
};

API_CALLABLE(N(UpdateStarSpiritBobbing)) {
    s32 retVal;
    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = N(StarSpiritBobDelays)[script->owner2.npcID - 1];
    }
    if (script->functionTemp[3] == 0) {
        Npc* npc = script->functionTempPtr[2];
        npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
        script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
        retVal = ApiStatus_BLOCK;
    } else {
        script->functionTemp[3]--;
        retVal = ApiStatus_BLOCK;
    }
    return retVal;
}

EvtScript N(EVS_NpcAux_StarSpirit) = {
    EVT_THREAD
        EVT_CALL(N(UpdateStarSpiritBobbing))
    EVT_END_THREAD
    EVT_CALL(RandInt, 100, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_WAIT(LVar0)
    EVT_MALLOC_ARRAY(1, LVarA)
    EVT_USE_ARRAY(LVarA)
    EVT_THREAD
        EVT_USE_ARRAY(LVarA)
        EVT_LABEL(0)
        EVT_CALL(RandInt, 90, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_SETF(ArrayVar(0), EVT_FLOAT(10.0))
        EVT_WAIT(LVar0)
        EVT_CALL(RandInt, 100, LVar1)
        EVT_IF_LT(LVar1, 80)
            EVT_SET(LVar1, 1)
        EVT_ELSE
            EVT_SET(LVar1, 2)
        EVT_END_IF
        EVT_LOOP(LVar1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(40.0))
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(50.0))
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(80.0))
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(70.0))
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(60.0))
            EVT_WAIT(1)
            EVT_SETF(ArrayVar(0), EVT_FLOAT(50.0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_SETF(LVar0, EVT_FLOAT(100.0))
    EVT_LABEL(1)
    EVT_LOOP(50)
        EVT_ADDF(LVar0, EVT_FLOAT(0.8))
        EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), MV_Unk_01, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADDF(LVar0, EVT_FLOAT(-0.8))
        EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), MV_Unk_01, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarSpirit) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_StarSpirit)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Goombaria) = {
    .id = NPC_Goombaria,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Goombaria),
    .settings = &N(NpcSettings_Goombaria_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = GOOMBARIA_ANIMS,
};

NpcData N(NpcData_StarSpirits)[] = {
    {
        .id = NPC_Eldstar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = ELDSTAR_ANIMS,
    },
    {
        .id = NPC_Mamar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MAMAR_ANIMS,
    },
    {
        .id = NPC_Skolar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SKOLAR_ANIMS,
    },
    {
        .id = NPC_Muskular,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_Misstar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MISSTAR_ANIMS,
    },
    {
        .id = NPC_Klevar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KLEVAR_ANIMS,
    },
    {
        .id = NPC_Kalmar,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarSpirit),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KALMAR_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Goombaria)),
    NPC_GROUP(N(NpcData_StarSpirits)),
    {}
};
