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
    Loop(0)
        Call(PlaySoundAtNpc, NPC_Kammy, SOUND_FLIGHT, SOUND_SPACE_DEFAULT)
        Wait(4 * DT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MakeNpcsFaceKammy) = {
    Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Label(0)
        Call(GetNpcPos, NPC_Kammy, LVar3, LVar4, LVar5)
        Call(N(UnkFunc42))
        Call(InterpNpcYaw, NPC_Kammy, LVarA, 0)
        Set(LVar0, LVar3)
        Set(LVar1, LVar4)
        Set(LVar2, LVar5)
        Call(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVarA)
        Call(InterpNpcYaw, NPC_Goombaria, LVarA, 0)
        Call(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVarB)
        Call(InterpNpcYaw, NPC_Goompapa, LVarB, 0)
        Call(GetAngleBetweenNPCs, NPC_Goombario, NPC_Kammy, LVarB)
        Call(InterpNpcYaw, NPC_Goombario, LVarB, 0)
        Call(GetAngleBetweenNPCs, NPC_Goomama, NPC_Kammy, LVarB)
        Call(InterpNpcYaw, NPC_Goomama, LVarB, 0)
        Call(PlayerFaceNpc, NPC_Kammy, FALSE)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Scene_KammyStrikes) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(EnableNpcAI, NPC_Goombario, FALSE)
    Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Idle)
    Call(EnableNpcAI, NPC_Goomama, FALSE)
    Call(SetNpcAnimation, NPC_Goomama, ANIM_Goomama_Idle)
    Call(EnableNpcAI, NPC_Kammy, TRUE)
    Call(SetNpcAux, NPC_Kammy, Ref(N(EVS_NpcAux_Kammy)))
    Call(ShowMessageAtScreenPos, MSG_CH0_0059, 160, 40)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    Thread
        ExecGetTID(N(EVS_PlayKammyFlightSounds), MV_Unk_04)
        ExecGetTID(N(EVS_MakeNpcsFaceKammy), MV_Unk_05)
        Call(LoadPath, 40 * DT, Ref(N(FlightPath_KammyAppear)), ARRAY_COUNT(N(FlightPath_KammyAppear)), EASING_LINEAR)
        Label(10)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 1)
                Goto(10)
            EndIf
    EndThread
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_Shocked)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 3, 0)
    Call(SetCamPosA, CAM_DEFAULT, 166, 756)
    Call(SetCamPosB, CAM_DEFAULT, 159, 0)
    Call(SetCamPosC, CAM_DEFAULT, 0, Float(109.7))
    Call(SetCamDistance, CAM_DEFAULT, 1220)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(LoadPath, 120 * DT, Ref(N(FlightPath_ToGate1)), ARRAY_COUNT(N(FlightPath_ToGate1)), EASING_LINEAR)
    Label(20)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(20)
        EndIf
    Wait(10 * DT)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 8, -10)
    Call(SetCamPosA, CAM_DEFAULT, 41, 729)
    Call(SetCamPosB, CAM_DEFAULT, 300, 245)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 440)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(PlayerFaceNpc, NPC_Kammy, FALSE)
    Call(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVar0)
    Call(InterpNpcYaw, NPC_Goompapa, LVar0, 0)
    Call(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVar0)
    Call(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    Call(SetPlayerPos, 220, 0, 213)
    Call(SetNpcPos, NPC_Goompapa, 255, 0, 232)
    Call(SetNpcPos, NPC_Goombaria, 190, 0, 212)
    Call(LoadPath, 10 * DT, Ref(N(FlightPath_ToGate2)), ARRAY_COUNT(N(FlightPath_ToGate2)), EASING_LINEAR)
    Label(30)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(30)
        EndIf
    KillThread(MV_Unk_04)
    KillThread(MV_Unk_05)
    Call(PlaySoundAtNpc, NPC_Kammy, SOUND_SKID, SOUND_SPACE_DEFAULT)
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -5)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -10)
        Wait(1)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, -15)
        Wait(3)
        Call(SetNpcRotation, NPC_Kammy, 0, 0, 0)
    EndThread
    Call(LoadPath, 10, Ref(N(FlightPath_ToGate3)), ARRAY_COUNT(N(FlightPath_ToGate3)), EASING_LINEAR)
    Label(40)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(40)
        EndIf
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005A)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 7, -10)
    Call(SetCamPosA, CAM_DEFAULT, 41, 729)
    Call(SetCamPosB, CAM_DEFAULT, 220, 213)
    Call(SetCamPosC, CAM_DEFAULT, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_LookUpTalk, ANIM_Goombaria_LookUp, 5, MSG_CH0_005B)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, Float(6.0), Float(-6.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-1731.4), Float(974.9))
    Call(SetCamPosB, CAM_DEFAULT, Float(399.0), Float(277.1))
    Call(SetCamPosC, CAM_DEFAULT, 0, Float(60.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005C)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LookUp)
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_LookUp)
    Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(398.9), Float(242.7))
    Call(SetCamPosC, CAM_DEFAULT, 0, Float(10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Wait(10 * DT)
    ExecWait(N(EVS_SummonGateBlock))
    Thread
        Call(SetPlayerAnimation, ANIM_MarioW2_PanicHoverStill)
        Call(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
        Call(UpdatePlayerImgFX, ANIM_MarioW2_PanicHoverStill, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
        Wait(13 * DT)
        Call(UpdatePlayerImgFX, ANIM_MarioW2_PanicHoverStill, IMGFX_CLEAR, 0, 0, 0, 0)
        Call(SetPlayerAnimation, ANIM_MarioW2_PanicHover)
        Call(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
        Call(UpdatePlayerImgFX, ANIM_MarioW2_PanicHover, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
        Wait(13 * DT)
        Call(UpdatePlayerImgFX, ANIM_MarioW2_PanicHover, IMGFX_CLEAR, 0, 0, 0, 0)
    EndThread
    Thread
        Call(SetPlayerJumpscale, Float(0.8))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(PlayerJump1, LVar0, LVar1, LVar2, 25 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Shock)
        Call(SetNpcImgFXFlags, NPC_Goombaria, IMGFX_FLAG_REVERSE_ANIM)
        Call(SetNpcImgFXParams, NPC_Goombaria, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
        Call(SetNpcJumpscale, NPC_Goombaria, Float(1.5))
        Call(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Goombaria, LVar0, LVar1, LVar2, 25 * DT)
        Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_LookUp)
        Call(SetNpcImgFXParams, NPC_Goombaria, IMGFX_CLEAR, 0, 0, 0, 0)
    EndThread
    Call(SetNpcImgFXFlags, NPC_Goompapa, IMGFX_FLAG_REVERSE_ANIM)
    Call(SetNpcImgFXParams, NPC_Goompapa, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Shock)
    Call(SetNpcJumpscale, NPC_Goompapa, Float(1.2))
    Call(GetNpcPos, NPC_Goompapa, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Goompapa, LVar0, LVar1, LVar2, 25 * DT)
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_LookUp)
    Call(SetNpcImgFXParams, NPC_Goompapa, IMGFX_CLEAR, 0, 0, 0, 0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, Float(6.0), Float(-6.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-1731.4), Float(974.9))
    Call(SetCamPosB, CAM_DEFAULT, Float(399.0), Float(277.1))
    Call(SetCamPosC, CAM_DEFAULT, 0, Float(60.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 512, MSG_CH0_005D)
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamPitch, CAM_DEFAULT, 3, 0)
    Call(SetCamPosA, CAM_DEFAULT, 166, 756)
    Call(SetCamPosB, CAM_DEFAULT, 159, 0)
    Call(SetCamPosC, CAM_DEFAULT, 0, Float(109.7))
    Call(SetCamDistance, CAM_DEFAULT, 1220)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Loop(150 * DT)
            Call(PlayerFaceNpc, NPC_Kammy, FALSE)
            Call(GetAngleBetweenNPCs, NPC_Goombaria, NPC_Kammy, LVar0)
            Call(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
            Call(GetAngleBetweenNPCs, NPC_Goompapa, NPC_Kammy, LVar0)
            Call(InterpNpcYaw, NPC_Goompapa, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim15)
    ExecGetTID(N(EVS_MakeNpcsFaceKammy), MV_Unk_05)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Kammy, ANIM_WorldKammy_Anim16, ANIM_WorldKammy_Anim13, 0x200, MSG_CH0_005E)
    Call(FadeOutMusic, 0, 3000 * DT)
    ExecGetTID(N(EVS_PlayKammyFlightSounds), MV_Unk_04)
    Call(LoadPath, 90 * DT, Ref(N(FlightPath_KammyDepart)), ARRAY_COUNT(N(FlightPath_KammyDepart)), EASING_QUADRATIC_IN)
    Label(70)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(70)
        EndIf
    KillThread(MV_Unk_04)
    KillThread(MV_Unk_05)
    Wait(20 * DT)
    Exec(N(EVS_SetupMusic))
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Angry)
    Call(SetNpcAnimation, NPC_Goombaria, ANIM_Goombaria_Idle)
    Call(SetNpcPos, NPC_Goombaria, 166, 0, 188)
    Call(SetPlayerPos, 231, 0, 196)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(GetAngleToPlayer, NPC_Goombaria, LVar0)
    Call(InterpNpcYaw, NPC_Goombaria, LVar0, 0)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, Float(-300.0), Float(12.0), Float(-8.5))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_AngryTalk, ANIM_Goompapa_Angry, 0, MSG_CH0_005F)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0060)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goombaria, ANIM_Goombaria_Talk, ANIM_Goombaria_Idle, 0, MSG_CH0_0061)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0062)
    Wait(10 * DT)
    Call(SetNpcSpeed, NPC_Goombario, Float(2.0))
    Call(EnableNpcAI, NPC_Goombario, TRUE)
    Call(EnableNpcAI, NPC_Goomama, TRUE)
    Call(GetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_Goombaria, LVar0, LVar1, LVar2)
    Call(EnableNpcShadow, NPC_Goombaria, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_FLYING, TRUE)
    Call(SetNpcPos, NPC_Goompa, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_Goompa, FALSE)
    Set(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
    Thread
        Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
    EndThread
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(SetNpcAnimation, NPC_Goompapa, ANIM_Goompapa_Idle)
    Call(N(SetWanderTerritory_6), NPC_Goomama, 1)
    Call(BindNpcAI, NPC_Goomama, Ref(N(EVS_NpcIdle_SwitchedWander_6)))
    Call(N(SetWanderTerritory_6), NPC_Goombario, 2)
    Call(BindNpcAI, NPC_Goombario, Ref(N(EVS_NpcIdle_SwitchedWander_6)))
    Call(N(SetWanderTerritory_6), NPC_Goombaria, 3)
    Call(BindNpcAI, NPC_Goombaria, Ref(N(EVS_NpcIdle_SwitchedWander_6)))
    Call(SetNpcFlagBits, NPC_Goombaria, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Goompapa, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};
