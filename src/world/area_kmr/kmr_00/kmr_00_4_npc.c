#include "kmr_00.h"

NpcSettings N(NpcSettings_StarSpirit) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused2) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Goombaria) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

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
        EVT_CALL(func_802CFD30, -1, 13, 0, ArrayVar(0), MV_Unk_01, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADDF(LVar0, EVT_FLOAT(-0.8))
        EVT_CALL(func_802CFD30, -1, 13, 0, ArrayVar(0), MV_Unk_01, LVar0)
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

StaticNpc N(NpcData_Goombaria) = {
    .id = NPC_Goombaria,
    .settings = &N(NpcSettings_Goombaria),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(EVS_NpcInit_Goombaria),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Goombaria_Idle,
        .walk   = ANIM_Goombaria_Walk,
        .run    = ANIM_Goombaria_Run,
        .chase  = ANIM_Goombaria_Run,
        .anim_4 = ANIM_Goombaria_Idle,
        .anim_5 = ANIM_Goombaria_Idle,
        .death  = ANIM_Goombaria_Still,
        .hit    = ANIM_Goombaria_Still,
        .anim_8 = ANIM_Goombaria_Run,
        .anim_9 = ANIM_Goombaria_Run,
        .anim_A = ANIM_Goombaria_Run,
        .anim_B = ANIM_Goombaria_Run,
        .anim_C = ANIM_Goombaria_Run,
        .anim_D = ANIM_Goombaria_Run,
        .anim_E = ANIM_Goombaria_Run,
        .anim_F = ANIM_Goombaria_Run,
    },
};

StaticNpc N(NpcData_Eldstar)[] = {
    {
        .id = NPC_Eldstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldEldstar_Idle,
            .walk   = ANIM_WorldEldstar_Idle,
            .run    = ANIM_WorldEldstar_Idle,
            .chase  = ANIM_WorldEldstar_Idle,
            .anim_4 = ANIM_WorldEldstar_Idle,
            .anim_5 = ANIM_WorldEldstar_Idle,
            .death  = ANIM_WorldEldstar_Idle,
            .hit    = ANIM_WorldEldstar_Idle,
            .anim_8 = ANIM_WorldEldstar_Still,
            .anim_9 = ANIM_WorldEldstar_Idle,
            .anim_A = ANIM_WorldEldstar_Idle,
            .anim_B = ANIM_WorldEldstar_Idle,
            .anim_C = ANIM_WorldEldstar_Idle,
            .anim_D = ANIM_WorldEldstar_Idle,
            .anim_E = ANIM_WorldEldstar_Idle,
            .anim_F = ANIM_WorldEldstar_Idle,
        },
    },
    {
        .id = NPC_Mamar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldMamar_Idle,
            .walk   = ANIM_WorldMamar_Idle,
            .run    = ANIM_WorldMamar_Idle,
            .chase  = ANIM_WorldMamar_Idle,
            .anim_4 = ANIM_WorldMamar_Idle,
            .anim_5 = ANIM_WorldMamar_Idle,
            .death  = ANIM_WorldMamar_Idle,
            .hit    = ANIM_WorldMamar_Idle,
            .anim_8 = ANIM_WorldMamar_Still,
            .anim_9 = ANIM_WorldMamar_Idle,
            .anim_A = ANIM_WorldMamar_Idle,
            .anim_B = ANIM_WorldMamar_Idle,
            .anim_C = ANIM_WorldMamar_Idle,
            .anim_D = ANIM_WorldMamar_Idle,
            .anim_E = ANIM_WorldMamar_Idle,
            .anim_F = ANIM_WorldMamar_Idle,
        },
    },
    {
        .id = NPC_Skolar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldSkolar_Idle,
            .walk   = ANIM_WorldSkolar_Idle,
            .run    = ANIM_WorldSkolar_Idle,
            .chase  = ANIM_WorldSkolar_Idle,
            .anim_4 = ANIM_WorldSkolar_Idle,
            .anim_5 = ANIM_WorldSkolar_Idle,
            .death  = ANIM_WorldSkolar_Idle,
            .hit    = ANIM_WorldSkolar_Idle,
            .anim_8 = ANIM_WorldSkolar_Still,
            .anim_9 = ANIM_WorldSkolar_Idle,
            .anim_A = ANIM_WorldSkolar_Idle,
            .anim_B = ANIM_WorldSkolar_Idle,
            .anim_C = ANIM_WorldSkolar_Idle,
            .anim_D = ANIM_WorldSkolar_Idle,
            .anim_E = ANIM_WorldSkolar_Idle,
            .anim_F = ANIM_WorldSkolar_Idle,
        },
    },
    {
        .id = NPC_Muskular,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldMuskular_Idle,
            .walk   = ANIM_WorldMuskular_Idle,
            .run    = ANIM_WorldMuskular_Idle,
            .chase  = ANIM_WorldMuskular_Idle,
            .anim_4 = ANIM_WorldMuskular_Idle,
            .anim_5 = ANIM_WorldMuskular_Idle,
            .death  = ANIM_WorldMuskular_Idle,
            .hit    = ANIM_WorldMuskular_Idle,
            .anim_8 = ANIM_WorldMuskular_Still,
            .anim_9 = ANIM_WorldMuskular_Idle,
            .anim_A = ANIM_WorldMuskular_Idle,
            .anim_B = ANIM_WorldMuskular_Idle,
            .anim_C = ANIM_WorldMuskular_Idle,
            .anim_D = ANIM_WorldMuskular_Idle,
            .anim_E = ANIM_WorldMuskular_Idle,
            .anim_F = ANIM_WorldMuskular_Idle,
        },
    },
    {
        .id = NPC_Misstar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldMisstar_Idle,
            .walk   = ANIM_WorldMisstar_Idle,
            .run    = ANIM_WorldMisstar_Idle,
            .chase  = ANIM_WorldMisstar_Idle,
            .anim_4 = ANIM_WorldMisstar_Idle,
            .anim_5 = ANIM_WorldMisstar_Idle,
            .death  = ANIM_WorldMisstar_Idle,
            .hit    = ANIM_WorldMisstar_Idle,
            .anim_8 = ANIM_WorldMisstar_Still,
            .anim_9 = ANIM_WorldMisstar_Idle,
            .anim_A = ANIM_WorldMisstar_Idle,
            .anim_B = ANIM_WorldMisstar_Idle,
            .anim_C = ANIM_WorldMisstar_Idle,
            .anim_D = ANIM_WorldMisstar_Idle,
            .anim_E = ANIM_WorldMisstar_Idle,
            .anim_F = ANIM_WorldMisstar_Idle,
        },
    },
    {
        .id = NPC_Klevar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldKlevar_Idle,
            .walk   = ANIM_WorldKlevar_Idle,
            .run    = ANIM_WorldKlevar_Idle,
            .chase  = ANIM_WorldKlevar_Idle,
            .anim_4 = ANIM_WorldKlevar_Idle,
            .anim_5 = ANIM_WorldKlevar_Idle,
            .death  = ANIM_WorldKlevar_Idle,
            .hit    = ANIM_WorldKlevar_Idle,
            .anim_8 = ANIM_WorldKlevar_Still,
            .anim_9 = ANIM_WorldKlevar_Idle,
            .anim_A = ANIM_WorldKlevar_Idle,
            .anim_B = ANIM_WorldKlevar_Idle,
            .anim_C = ANIM_WorldKlevar_Idle,
            .anim_D = ANIM_WorldKlevar_Idle,
            .anim_E = ANIM_WorldKlevar_Idle,
            .anim_F = ANIM_WorldKlevar_Idle,
        },
    },
    {
        .id = NPC_Kalmar,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .init = &N(EVS_NpcInit_StarSpirit),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldKalmar_Idle,
            .walk   = ANIM_WorldKalmar_Idle,
            .run    = ANIM_WorldKalmar_Idle,
            .chase  = ANIM_WorldKalmar_Idle,
            .anim_4 = ANIM_WorldKalmar_Idle,
            .anim_5 = ANIM_WorldKalmar_Idle,
            .death  = ANIM_WorldKalmar_Idle,
            .hit    = ANIM_WorldKalmar_Idle,
            .anim_8 = ANIM_WorldKalmar_Still,
            .anim_9 = ANIM_WorldKalmar_Idle,
            .anim_A = ANIM_WorldKalmar_Idle,
            .anim_B = ANIM_WorldKalmar_Idle,
            .anim_C = ANIM_WorldKalmar_Idle,
            .anim_D = ANIM_WorldKalmar_Idle,
            .anim_E = ANIM_WorldKalmar_Idle,
            .anim_F = ANIM_WorldKalmar_Idle,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Goombaria)),
    NPC_GROUP(N(NpcData_Eldstar)),
    {}
};
