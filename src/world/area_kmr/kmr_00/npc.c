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
    Thread
        Call(N(UpdateStarSpiritBobbing))
    EndThread
    Call(RandInt, 100, LVar0)
    Add(LVar0, 1)
    Wait(LVar0)
    MallocArray(1, LVarA)
    UseArray(LVarA)
    Thread
        UseArray(LVarA)
        Label(0)
        Call(RandInt, 90, LVar0)
        Add(LVar0, 30)
        SetF(ArrayVar(0), Float(10.0))
        Wait(LVar0)
        Call(RandInt, 100, LVar1)
        IfLt(LVar1, 80)
            Set(LVar1, 1)
        Else
            Set(LVar1, 2)
        EndIf
        Loop(LVar1)
            SetF(ArrayVar(0), Float(40.0))
            Wait(1)
            SetF(ArrayVar(0), Float(50.0))
            Wait(1)
            SetF(ArrayVar(0), Float(80.0))
            Wait(1)
            SetF(ArrayVar(0), Float(70.0))
            Wait(1)
            SetF(ArrayVar(0), Float(60.0))
            Wait(1)
            SetF(ArrayVar(0), Float(50.0))
            Wait(1)
        EndLoop
        Goto(0)
    EndThread
    SetF(LVar0, Float(100.0))
    Label(1)
    Loop(50)
        AddF(LVar0, Float(0.8))
        Call(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), MV_Unk_01, LVar0)
        Wait(1)
    EndLoop
    Loop(50)
        AddF(LVar0, Float(-0.8))
        Call(SetNpcImgFXParams, NPC_SELF, IMGFX_HOLOGRAM, IMGFX_HOLOGRAM_NOISE, ArrayVar(0), MV_Unk_01, LVar0)
        Wait(1)
    EndLoop
    Goto(1)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarSpirit) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_StarSpirit)))
    IfGe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Goombaria) = {
    IfGe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
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
