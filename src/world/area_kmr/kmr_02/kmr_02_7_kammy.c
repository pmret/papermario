#include "kmr_02.h"
#include "sprite/player.h"

#include "world/common/todo/CheckPartnerFlags1000.inc.c"

#define NAME_SUFFIX _6
#include "world/common/npc/GoombaFamily_Wander.inc.c"
#include "wander_territories.inc.c"
#define NAME_SUFFIX

#include "world/common/todo/UnkFunc42.inc.c"

Vec3f N(FlightPath_KammyAppear)[] = {
    {  473.0,   150.0,  301.0 },
    {  234.0,    80.0,  200.0 },
    {   46.0,   150.0,  180.0 },
};

Vec3f N(FlightPath_ToGate1)[] = {
    {   46.0,   150.0,  180.0 },
    {  -93.0,   262.0,  114.0 },
    {  118.0,   121.0,  141.0 },
    {  340.0,   141.0,  406.0 },
    {  550.0,   108.0,  320.0 },
};

Vec3f N(FlightPath_ToGate2)[] = {
    {  465.0,   108.0,  320.0 },
    {  433.0,    78.0,  306.0 },
    {  399.0,    56.0,  288.0 },
};

Vec3f N(FlightPath_ToGate3)[] = {
    {  399.0,    56.0,  288.0 },
    {  390.0,    53.0,  284.0 },
    {  380.0,    50.0,  282.0 },
};

Vec3f N(FlightPath_KammyDepart)[] = {
    {  380.0,    50.0,  282.0 },
    {  290.0,   100.0,  240.0 },
    {  204.0,   142.0,  202.0 },
    { -391.0,   520.0, -212.0 },
};

EvtScript N(EVS_PlayKammyFlightSounds) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_FLIGHT, SOUND_SPACE_DEFAULT)
        EVT_WAIT(4 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeNpcsFaceKammy) = {
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

EvtScript N(EVS_Scene_KammyStrikes) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
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
        EVT_EXEC_GET_TID(N(EVS_PlayKammyFlightSounds), MV_Unk_04)
        EVT_EXEC_GET_TID(N(EVS_MakeNpcsFaceKammy), MV_Unk_05)
        EVT_CALL(LoadPath, 40 * DT, EVT_PTR(N(FlightPath_KammyAppear)), ARRAY_COUNT(N(FlightPath_KammyAppear)), EASING_LINEAR)
        EVT_LABEL(10)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(10)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Shocked)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 3, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 166, 756)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 159, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(109.7))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1220)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(LoadPath, 120 * DT, EVT_PTR(N(FlightPath_ToGate1)), ARRAY_COUNT(N(FlightPath_ToGate1)), EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_WAIT(10 * DT)
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
    EVT_CALL(LoadPath, 10 * DT, EVT_PTR(N(FlightPath_ToGate2)), ARRAY_COUNT(N(FlightPath_ToGate2)), EASING_LINEAR)
    EVT_LABEL(30)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(30)
        EVT_END_IF
    EVT_KILL_THREAD(MV_Unk_04)
    EVT_KILL_THREAD(MV_Unk_05)
    EVT_CALL(PlaySoundAtNpc, NPC_Kammy, SOUND_SKID, SOUND_SPACE_DEFAULT)
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
    EVT_CALL(LoadPath, 10, EVT_PTR(N(FlightPath_ToGate3)), ARRAY_COUNT(N(FlightPath_ToGate3)), EASING_LINEAR)
    EVT_LABEL(40)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_WAIT(30 * DT)
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
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_SummonGateBlock))
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicHoverStill)
        EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
        EVT_CALL(UpdatePlayerImgFX, ANIM_MarioW2_PanicHoverStill, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
        EVT_WAIT(13 * DT)
        EVT_CALL(UpdatePlayerImgFX, ANIM_MarioW2_PanicHoverStill, IMGFX_CLEAR, 0, 0, 0, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicHover)
        EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
        EVT_CALL(UpdatePlayerImgFX, ANIM_MarioW2_PanicHover, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
        EVT_WAIT(13 * DT)
        EVT_CALL(UpdatePlayerImgFX, ANIM_MarioW2_PanicHover, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.8))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerJump1, LVar0, LVar1, LVar2, 25 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Shock)
        EVT_CALL(SetNpcImgFXFlags, NPC_Goombaria, IMGFX_FLAG_REVERSE_ANIM)
        EVT_CALL(SetNpcImgFXParams, NPC_Goombaria, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Goombaria, EVT_FLOAT(1.5))
        EVT_CALL(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Goombaria, LVar0, LVar1, LVar2, 25 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LookUp)
        EVT_CALL(SetNpcImgFXParams, NPC_Goombaria, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcImgFXFlags, NPC_Goompapa, IMGFX_FLAG_REVERSE_ANIM)
    EVT_CALL(SetNpcImgFXParams, NPC_Goompapa, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Shock)
    EVT_CALL(SetNpcJumpscale, NPC_Goompapa, EVT_FLOAT(1.2))
    EVT_CALL(GetNpcPos, NPC_Goompapa, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Goompapa, LVar0, LVar1, LVar2, 25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_LookUp)
    EVT_CALL(SetNpcImgFXParams, NPC_Goompapa, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-1731.4), EVT_FLOAT(974.9))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(399.0), EVT_FLOAT(277.1))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(60.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005D)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 3, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 166, 756)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 159, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, EVT_FLOAT(109.7))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1220)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_LOOP(150 * DT)
            EVT_CALL(PlayerFaceNpc, NPC_Kammy, FALSE)
            EVT_CALL(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
            EVT_CALL(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVar0)
            EVT_CALL(InterpNpcYaw, NPC_Goompapa, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    EVT_EXEC_GET_TID(N(EVS_MakeNpcsFaceKammy), MV_Unk_05)
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 0x200, MSG_CH0_005E)
    EVT_CALL(FadeOutMusic, 0, 3000 * DT)
    EVT_EXEC_GET_TID(N(EVS_PlayKammyFlightSounds), MV_Unk_04)
    EVT_CALL(LoadPath, 90 * DT, EVT_PTR(N(FlightPath_KammyDepart)), ARRAY_COUNT(N(FlightPath_KammyDepart)), EASING_QUADRATIC_IN)
    EVT_LABEL(70)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(70)
        EVT_END_IF
    EVT_KILL_THREAD(MV_Unk_04)
    EVT_KILL_THREAD(MV_Unk_05)
    EVT_WAIT(20 * DT)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Angry)
    EVT_CALL(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    EVT_CALL(SetNpcPos, NPC_Goombaria, 166, 0, 188)
    EVT_CALL(SetPlayerPos, 231, 0, 196)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(GetAngleToPlayer, NPC_Goombaria, LVar0)
    EVT_CALL(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, EVT_FLOAT(-300.0), EVT_FLOAT(12.0), EVT_FLOAT(-8.5))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_AngryTalk, ANIM_Goompapa_Angry, 0, MSG_CH0_005F)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
    EVT_WAIT(15 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0060)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0061)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0062)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcSpeed, NPC_Goombario, EVT_FLOAT(2.0))
    EVT_CALL(EnableNpcAI, NPC_Goombario, TRUE)
    EVT_CALL(EnableNpcAI, NPC_Goomama, TRUE)
    EVT_CALL(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    EVT_CALL(EnableNpcShadow, NPC_Goombaria, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(SetNpcPos, NPC_Goompa, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, NPC_Goompa, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
    EVT_CALL(N(SetWanderTerritory_6), NPC_Goomama, 1)
    EVT_CALL(BindNpcAI, NPC_Goomama, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_6)))
    EVT_CALL(N(SetWanderTerritory_6), NPC_Goombario, 2)
    EVT_CALL(BindNpcAI, NPC_Goombario, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_6)))
    EVT_CALL(N(SetWanderTerritory_6), NPC_Goombaria, 3)
    EVT_CALL(BindNpcAI, NPC_Goombaria, EVT_PTR(N(EVS_NpcIdle_SwitchedWander_6)))
    EVT_CALL(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};
