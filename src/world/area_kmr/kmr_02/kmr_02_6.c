#include "kmr_02.h"

#include "world/common/todo/CheckPartnerFlags1000.inc.c"

EvtScript N(D_80255160_8C51D0) = {
    EVT_CALL(RotateModel, MODEL_o275, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80255190_8C5200) = {
    EVT_SET(LVar1, LVar0)
    EVT_ADD(LVar1, LVar0)
    EVT_CALL(RotateModel, MODEL_k_k_1, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_k_k_2, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_k_k_3, LVar1, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o272, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80255240_8C52B0) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetGroupEnabled, MODEL_kino_in, 1)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o767, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_WAIT(5)
            EVT_END_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetGroupEnabled, MODEL_kino_in, 0)
            EVT_CALL(EnableModel, MODEL_o422, TRUE)
            EVT_CALL(EnableModel, MODEL_o424, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80255380) = {
    EVT_CALL(SetGroupEnabled, MODEL_kino_in, 1)
    EVT_CALL(RotateModel, MODEL_k_k_1, 180, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_k_k_2, 180, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_k_k_3, 180, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o272, 180, 0, 1, 0)
    EVT_CALL(EnableModel, MODEL_o561, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o767, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80255450_8C54C0) = {
    EVT_LABEL(9)
        EVT_CALL(MakeLerp, 10, -10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_kanban, LVar0, EVT_FLOAT(35.498), 0, EVT_FLOAT(-9.511))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(MakeLerp, -10, 10, 30, EASING_COS_IN_OUT)
        EVT_LABEL(11)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_kanban, LVar0, EVT_FLOAT(35.498), 0, EVT_FLOAT(-9.511))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_GOTO(9)
    EVT_RETURN
    EVT_END
};

s32 N(D_80255580_8C55F0)[] = {
    NPC_Toad,
    -1
};

EvtScript N(EVS_80255588) = {
    EVT_CALL(RotateModel, MODEL_o320, 180, 0, 1, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kmr_02_ENTRY_5)
        EVT_CALL(SetGroupEnabled, MODEL_kino_in, 0)
    EVT_END_IF
    EVT_CALL(MakeDoorAdvanced, 0, EVT_PTR(N(D_80255160_8C51D0)), EVT_PTR(N(D_80255190_8C5200)), 0, EVT_PTR(N(D_80255240_8C52B0)), COLLIDER_deilit7, COLLIDER_deilit8, MODEL_kinopi, EVT_PTR(N(D_80255580_8C55F0)))
    EVT_EXEC(N(D_80255450_8C54C0))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80255630_8C56A0) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(D_80255660_8C56D0) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80255630_8C56A0)))
    EVT_RETURN
    EVT_END
};

s32 N(missing_80255680_15680)[] = {
    0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x80255660, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630010, 
};

#define NAME_SUFFIX _6
#include "wander_territories.inc.c"
#define NAME_SUFFIX

MobileAISettings N(D_8025579C_8C580C) = {
    .moveSpeed = 2.0f,
    .moveTime = 15,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Goomama) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_8025579C_8C580C)))
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc42.inc.c"

Vec3f N(D_802557EC_8C585C)[] = {
    {  473.0,   150.0,  301.0 },
    {  234.0,    80.0,  200.0 },
    {   46.0,   150.0,  180.0 },
};

Vec3f N(D_80255810_8C5880)[] = {
    {   46.0,   150.0,  180.0 },
    {  -93.0,   262.0,  114.0 },
    {  118.0,   121.0,  141.0 },
    {  340.0,   141.0,  406.0 },
    {  550.0,   108.0,  320.0 },
};

Vec3f N(D_8025584C_8C58BC)[] = {
    {  465.0,   108.0,  320.0 },
    {  433.0,    78.0,  306.0 },
    {  399.0,    56.0,  288.0 },
};

Vec3f N(D_80255870_8C58E0)[] = {
    {  399.0,    56.0,  288.0 },
    {  390.0,    53.0,  284.0 },
    {  380.0,    50.0,  282.0 },
};

Vec3f N(D_80255894_8C5904)[] = {
    {  380.0,    50.0,  282.0 },
    {  290.0,   100.0,  240.0 },
    {  204.0,   142.0,  202.0 },
    { -391.0,   520.0, -212.0 },
};

EvtScript N(D_802558C4_8C5934) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_295, 0)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8025590C_8C597C) = {
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar3, LVar4, LVar5)
    EVT_CALL(N(UnkFunc42))
    EVT_CALL(InterpNpcYaw, NPC_Kammy, LVarA, 0)
    EVT_SET(LVar0, LVar3)
    EVT_SET(LVar1, LVar4)
    EVT_SET(LVar2, LVar5)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVarA)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVarA, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVarB)
    EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVarB, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombario, NPC_Kammy, LVarB)
    EVT_CALL(InterpNpcYaw, NPC_Goombario, LVarB, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goomama, NPC_Kammy, LVarB)
    EVT_CALL(InterpNpcYaw, NPC_Goomama, LVarB, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Kammy, FALSE)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80255AA0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_100, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(EnableNpcAI, NPC_Goombario, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    EVT_CALL(EnableNpcAI, NPC_Goomama, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Goomama, ANIM_Goomama_Idle)
    EVT_CALL(EnableNpcAI, NPC_Kammy, TRUE)
    EVT_CALL(SetNpcAux, NPC_Kammy, EVT_PTR(N(EVS_NpcAux_Kammy)))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH0_0059, 160, 40)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    EVT_THREAD
        EVT_EXEC_GET_TID(N(D_802558C4_8C5934), MV_Unk_04)
        EVT_EXEC_GET_TID(N(D_8025590C_8C597C), MV_Unk_05)
        EVT_CALL(LoadPath, 40, EVT_PTR(N(D_802557EC_8C585C)), 3, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000A)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 3, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 166, 756)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 159, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(109.7))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1220)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(LoadPath, 120, EVT_PTR(N(D_80255810_8C5880)), 5, EASING_LINEAR)
    EVT_LABEL(20)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 8, -10)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 41, 729)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 300, 245)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 440)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(PlayerFaceNpc, NPC_Kammy, FALSE)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar0, 0)
    EVT_CALL(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    EVT_CALL(SetPlayerPos, 220, 0, 213)
    EVT_CALL(SetNpcPos, NPC_Goompapa, 255, 0, 232)
    EVT_CALL(SetNpcPos, NPC_Goombaria, 190, 0, 212)
    EVT_CALL(LoadPath, 10, EVT_PTR(N(D_8025584C_8C58BC)), 3, EASING_LINEAR)
    EVT_LABEL(30)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_KILL_THREAD(MV_Unk_04)
    EVT_KILL_THREAD(MV_Unk_05)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_32B, 0)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -5)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        EVT_WAIT(3)
        EVT_CALL(SetNpcRotation, NPC_Kammy, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(LoadPath, 10, EVT_PTR(N(D_80255870_8C58E0)), 3, EASING_LINEAR)
    EVT_LABEL(40)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(40)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005A)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 7, -10)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 41, 729)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 220, 213)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_LookUpTalk, ANIM_Goombaria_LookUp, 5, MSG_CH0_005B)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-1731.4), EVT_FLOAT(974.9))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(399.0), EVT_FLOAT(277.1))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(60.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005C)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LookUp)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_LookUp)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(398.9), EVT_FLOAT(242.7))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(EVS_80254AE0))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80012)
        EVT_CALL(func_802D286C, 256)
        EVT_CALL(func_802D2520, ANIM_Mario_80012, 5, 0, 1, 1, 0)
        EVT_WAIT(13)
        EVT_CALL(func_802D2520, ANIM_Mario_80012, 0, 0, 0, 0, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80013)
        EVT_CALL(func_802D286C, 256)
        EVT_CALL(func_802D2520, ANIM_Mario_80013, 5, 0, 1, 1, 0)
        EVT_WAIT(13)
        EVT_CALL(func_802D2520, ANIM_Mario_80013, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.8))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 25)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Shock)
        EVT_CALL(func_802CFE2C, NPC_Goombaria, 0x100)
        EVT_CALL(func_802CFD30, NPC_Goombaria, FOLD_TYPE_5, 0, 1, 1, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(1.5))
        EVT_CALL(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Goombaria, LVar0, LVar1, LVar2, 25)
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LookUp)
        EVT_CALL(func_802CFD30, 1, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(func_802CFE2C, NPC_Goompapa, 0x100)
    EVT_CALL(func_802CFD30, NPC_Goompapa, FOLD_TYPE_5, 0, 1, 1, 0)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Shock)
    EVT_CALL(SetNpcJumpscale, NPC_Goompapa, EVT_FLOAT(1.2))
    EVT_CALL(GetNpcPos, NPC_Goompapa, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Goompapa, LVar0, LVar1, LVar2, 25)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_LookUp)
    EVT_CALL(func_802CFD30, 3, 0, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-1731.4), EVT_FLOAT(974.9))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(399.0), EVT_FLOAT(277.1))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(60.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005D)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 3, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 166, 756)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 159, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(109.7))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1220)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_LOOP(150)
            EVT_CALL(PlayerFaceNpc, NPC_Kammy, FALSE)
            EVT_CALL(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
            EVT_CALL(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    EVT_EXEC_GET_TID(N(D_8025590C_8C597C), MV_Unk_05)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 0x200, MSG_CH0_005E)
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_EXEC_GET_TID(N(D_802558C4_8C5934), MV_Unk_04)
    EVT_CALL(LoadPath, 90, EVT_PTR(N(D_80255894_8C5904)), 4, EASING_QUADRATIC_IN)
    EVT_LABEL(70)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(70)
    EVT_END_IF
    EVT_KILL_THREAD(MV_Unk_04)
    EVT_KILL_THREAD(MV_Unk_05)
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Angry)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    EVT_CALL(SetNpcPos, NPC_Goombaria, 166, 0, 188)
    EVT_CALL(SetPlayerPos, 231, 0, 196)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(GetAngleToPlayer, NPC_Goombaria, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, EVT_FLOAT(-300.0), EVT_FLOAT(12.0), EVT_FLOAT(-8.5))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_AngryTalk, ANIM_Goompapa_Angry, 0, MSG_CH0_005F)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0060)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0061)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0062)
    EVT_WAIT(10)
    EVT_CALL(SetNpcSpeed, NPC_Goombario, EVT_FLOAT(2.0))
    EVT_CALL(EnableNpcAI, NPC_Goombario, TRUE)
    EVT_CALL(EnableNpcAI, NPC_Goomama, TRUE)
    EVT_CALL(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    EVT_CALL(EnableNpcShadow, NPC_Goombaria, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_40, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE)
    EVT_CALL(SetNpcPos, NPC_Goompa, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, NPC_Goompa, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
    EVT_CALL(N(SetWanderTerritory_6), NPC_Goomama, 1)
    EVT_CALL(BindNpcAI, NPC_Goomama, EVT_PTR(N(EVS_NpcAI_Goomama)))
    EVT_CALL(N(SetWanderTerritory_6), NPC_Goombario, 2)
    EVT_CALL(BindNpcAI, NPC_Goombario, EVT_PTR(N(EVS_NpcAI_Goomama)))
    EVT_CALL(N(SetWanderTerritory_6), NPC_Goombaria, 3)
    EVT_CALL(BindNpcAI, NPC_Goombaria, EVT_PTR(N(EVS_NpcAI_Goomama)))
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_100, FALSE)
    EVT_RETURN
    EVT_END
};
