#include "mim_10.h"
#include "sprite/player.h"

API_CALLABLE(N(AwaitPlayerApproachForest)) {
    if (gPlayerStatus.pos.x < 100.0f) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(InitializeLightingBright)) {
    enable_world_fog();
    set_world_fog_color(16, 16, 16, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 20;
    gCameras[CAM_DEFAULT].bgColor[1] = 20;
    gCameras[CAM_DEFAULT].bgColor[2] = 28;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitializeLightingGloomy)) {
    enable_world_fog();
    set_world_fog_dist(990, 1000);
    set_world_fog_color(16, 16, 16, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 20;
    gCameras[CAM_DEFAULT].bgColor[1] = 20;
    gCameras[CAM_DEFAULT].bgColor[2] = 28;
    gGameStatusPtr->backgroundDarkness = 240;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ReduceFogEndDist)) {
    s32 retVal = ApiStatus_BLOCK;

    if (isInitialCall) {
        script->functionTemp[1] = 1060;
    }

    script->functionTemp[1]--;
    if (script->functionTemp[1] <= 1000) {
        script->functionTemp[1] = 1000;
        retVal = ApiStatus_DONE2;
    }

    set_world_fog_dist(990, script->functionTemp[1]);
    return retVal;
}

API_CALLABLE(N(DarkenBackground)) {
    s32 retVal = ApiStatus_BLOCK;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 4;
    if (script->functionTemp[1] >= 240) {
        script->functionTemp[1] = 240;
        retVal = ApiStatus_DONE2;
    }
    gGameStatusPtr->backgroundDarkness = script->functionTemp[1];
    return retVal;
}

NpcSettings N(NpcSettings_Bootler) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_JrTroopa) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

EvtScript N(EVS_Bootler_SpookPlayer) = {
    ChildThread
        Call(GetPlayerPos, LVarA, LVarB, LVarC)
        Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Loop(0)
            Call(SetCamDistance, CAM_DEFAULT, 400)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Wait(1)
            Call(SetCamDistance, CAM_DEFAULT, 450)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Wait(1)
        EndLoop
    EndChildThread
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Spook, ANIM_Bootler_Spook, 0, MSG_CH3_0002)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Return
    End
};

#if VERSION_PAL
#define VAR_1 (15.0)
#else
#define VAR_1 (12.0)
#endif

EvtScript N(EVS_Scene_BootlersInvitation) = {
    Call(N(AwaitPlayerApproachForest))
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 650)
    Call(N(InitializeLightingBright))
    Thread
        Call(N(ReduceFogEndDist))
    EndThread
    Thread
        Call(N(DarkenBackground))
    EndThread
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_Bootler, 200, 44, 0)
    Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Set(MV_Unk_00, TRUE)
    Call(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_LookAround)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(10 * DT)
    Call(InterpPlayerYaw, 270, 0)
    Wait(20 * DT)
    Call(InterpPlayerYaw, 90, 0)
    Wait(20 * DT)
    Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(0.0))
    Loop(20 * DT)
        AddF(LVar0, Float(VAR_1))
        Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(20 * DT)
    Call(GetNpcPos, NPC_Bootler, LVarA, LVarB, LVarC)
    Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
    Call(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
    Call(SetCamDistance, CAM_DEFAULT, 270)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_0000)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamLeadPlayer, CAM_DEFAULT, TRUE)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_0001)
    Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(240.0))
    Loop(20 * DT)
        SubF(LVar0, Float(VAR_1))
        Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    Thread
        Call(GetNpcPos, NPC_Bootler, LVarA, LVarB, LVarC)
        Sub(LVarB, 40)
        Call(SetNpcPos, NPC_Bootler, LVarA, LVarB, LVarC)
        Call(SetNpcScale, NPC_Bootler, Float(3.0), Float(3.0), Float(3.0))
        SetF(LVar0, Float(0.0))
        Loop(20 * DT)
            AddF(LVar0, Float(VAR_1))
            Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(PlaySoundAtNpc, NPC_Bootler, SOUND_BOOTLER_SPOOK, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_Bootler_SpookPlayer))
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    SetF(LVar0, Float(240.0))
    Loop(20 * DT)
        SubF(LVar0, Float(VAR_1))
        Call(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Set(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
    Exec(N(EVS_SetupMusic))
    Call(SetNpcPos, NPC_Bootler, NPC_DISPOSE_LOCATION)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupBootlerTrigger) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_SAW_BOO_ENTER_FOREST)
            Return
        CaseLt(STORY_CH3_INVITED_TO_BOOS_MANSION)
            Exec(N(EVS_Scene_BootlersInvitation))
        CaseRange(STORY_CH3_INVITED_TO_BOOS_MANSION, STORY_CH3_STAR_SPIRIT_RESCUED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Bootler) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_SAW_BOO_ENTER_FOREST)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH3_INVITED_TO_BOOS_MANSION)
            Set(GF_KMR20_ReunitedWithLuigi, TRUE)
        CaseGe(STORY_CH3_INVITED_TO_BOOS_MANSION)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Set(MV_Unk_00, TRUE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, Float(3.0 / DT), LVar0, LVar1, LVar2, 300, 15, -7)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 5, MSG_CH3_0023)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp)
    Sub(LVar0, 200)
    Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 25 * DT)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Set(GF_MIM10_JrTroopaEscaped, TRUE)
    Set(MV_Unk_00, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa)))
    IfEq(GF_MIM10_JrTroopaEscaped, TRUE)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    IfEq(GF_MIM10_Defeated_JrTroopa, FALSE)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

NpcData N(NpcData_Bootler) = {
    .id = NPC_Bootler,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bootler),
    .settings = &N(NpcSettings_Bootler),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Bootler_Idle,
        .walk   = ANIM_Bootler_Walk,
        .run    = ANIM_Bootler_Run,
        .chase  = ANIM_Bootler_Run,
        .anim_4 = ANIM_Bootler_Idle,
        .anim_5 = ANIM_Bootler_Idle,
        .death  = ANIM_Bootler_Still,
        .hit    = ANIM_Bootler_Still,
        .anim_8 = ANIM_Bootler_Shock,
        .anim_9 = ANIM_Bootler_Panic,
        .anim_A = ANIM_Bootler_Dejected,
        .anim_B = ANIM_Bootler_Quaver,
        .anim_C = ANIM_Bootler_Shock,
        .anim_D = ANIM_Bootler_Panic,
        .anim_E = ANIM_Bootler_Dejected,
        .anim_F = ANIM_Bootler_Quaver,
    },
};

NpcData N(NpcData_JrTroopa) = {
    .id = NPC_JrTroopa,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_JrTroopa),
    .settings = &N(NpcSettings_JrTroopa),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_JrTroopa_Idle,
        .walk   = ANIM_JrTroopa_Walk,
        .run    = ANIM_JrTroopa_Walk,
        .chase  = ANIM_JrTroopa_Walk,
        .anim_4 = ANIM_JrTroopa_Idle,
        .anim_5 = ANIM_JrTroopa_Idle,
        .death  = ANIM_JrTroopa_Idle,
        .hit    = ANIM_JrTroopa_Idle,
        .anim_8 = ANIM_JrTroopa_Idle,
        .anim_9 = ANIM_JrTroopa_Idle,
        .anim_A = ANIM_JrTroopa_Idle,
        .anim_B = ANIM_JrTroopa_Idle,
        .anim_C = ANIM_JrTroopa_Idle,
        .anim_D = ANIM_JrTroopa_Idle,
        .anim_E = ANIM_JrTroopa_Idle,
        .anim_F = ANIM_JrTroopa_Idle,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bootler)),
    NPC_GROUP(N(NpcData_JrTroopa)),
    {}
};
