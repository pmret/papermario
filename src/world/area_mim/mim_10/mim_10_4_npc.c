#include "mim_10.h"

API_CALLABLE(N(AwaitPlayerApproachForest)) {
    if (gPlayerStatus.position.x < 100.0f) {
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
    .level = 99,
};

NpcSettings N(NpcSettings_JrTroopa) = {
    .height = 32,
    .radius = 24,
    .level = 99,
};

EvtScript N(EVS_Bootler_SpookPlayer) = {
    EVT_CHILD_THREAD
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_LOOP(0)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Spook, ANIM_Bootler_Spook, 0, MSG_CH3_0002)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BootlersInvitation) = {
    EVT_CALL(N(AwaitPlayerApproachForest))
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 650)
    EVT_CALL(N(InitializeLightingBright))
    EVT_THREAD
        EVT_CALL(N(ReduceFogEndDist))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(DarkenBackground))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Bootler, 200, 44, 0)
    EVT_CALL(func_802CFD30, 0, FOLD_TYPE_7, 0, 0, 0, 0)
    EVT_SET(MV_Unk_00, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80022)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(20)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH, 0)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(20)
        EVT_ADDF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(func_802CFD30, 0, FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(GetNpcPos, NPC_Bootler, LVarA, LVarB, LVarC)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 270)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_0000)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, TRUE)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_0001)
    EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR, 0)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(20)
        EVT_SUBF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(func_802CFD30, 0, FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(25)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Bootler, LVarA, LVarB, LVarC)
        EVT_SUB(LVarB, 40)
        EVT_CALL(SetNpcPos, NPC_Bootler, LVarA, LVarB, LVarC)
        EVT_CALL(SetNpcScale, NPC_Bootler, EVT_FLOAT(3.0), EVT_FLOAT(3.0), EVT_FLOAT(3.0))
        EVT_SETF(LVar0, EVT_FLOAT(0.0))
        EVT_LOOP(20)
            EVT_ADDF(LVar0, EVT_FLOAT(12.0))
            EVT_CALL(func_802CFD30, 0, FOLD_TYPE_7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_292, 0)
    EVT_EXEC_WAIT(N(EVS_Bootler_SpookPlayer))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(20)
        EVT_SUBF(LVar0, EVT_FLOAT(12.0))
        EVT_CALL(func_802CFD30, 0, FOLD_TYPE_7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(SetNpcPos, NPC_Bootler, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBootlerTrigger) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_SAW_BOO_ENTER_FOREST)
            EVT_RETURN
        EVT_CASE_LT(STORY_CH3_INVITED_TO_BOOS_MANSION)
            EVT_EXEC(N(EVS_Scene_BootlersInvitation))
        EVT_CASE_RANGE(STORY_CH3_INVITED_TO_BOOS_MANSION, STORY_CH3_STAR_SPIRIT_RESCUED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bootler) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_SAW_BOO_ENTER_FOREST)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_LT(STORY_CH3_INVITED_TO_BOOS_MANSION)
            EVT_SET(GF_KMR20_ReunitedWithLuigi, TRUE)
        EVT_CASE_GE(STORY_CH3_INVITED_TO_BOOS_MANSION)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(MV_Unk_00, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(3.0), LVar0, LVar1, LVar2, 300, 15, -7)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle, 5, MSG_CH3_0023)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp)
    EVT_SUB(LVar0, 200)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 25)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_SET(GF_MIM10_JrTroopaEscaped, TRUE)
    EVT_SET(MV_Unk_00, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JrTroopa)))
    EVT_IF_EQ(GF_MIM10_JrTroopaEscaped, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MIM10_Defeated_JrTroopa, FALSE)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Bootler) = {
    .id = NPC_Bootler,
    .settings = &N(NpcSettings_Bootler),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_Bootler),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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

StaticNpc N(NpcData_JrTroopa) = {
    .id = NPC_JrTroopa,
    .settings = &N(NpcSettings_JrTroopa),
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_JrTroopa),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
