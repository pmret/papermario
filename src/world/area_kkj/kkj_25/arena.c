#include "kkj_25.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/todo/GetFloorCollider.inc.c"

#include "world/common/util/SetLightningBoltPurple.inc.c"

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

API_CALLABLE(N(SpawnLensFlare)) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_lens_flare(0, posX, posY, posZ, duration);
    return ApiStatus_DONE2;
}

#define NAME_SUFFIX _Unused1A
#include "world/common/npc/Bowser.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/enemy/Kammy_Flying.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"
#define NAME_SUFFIX _Unused1B
#include "world/common/npc/Dummy.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_ArenaEyesFlash) = {
    Call(PlaySoundAt, SOUND_KKJ_ARENA_LENS_FLARE, SOUND_SPACE_DEFAULT, 300, -70, 280)
    Call(N(SpawnLensFlare), 225, -70, 280, 240)
    Call(N(SpawnLensFlare), 380, -70, 280, 240)
    Return
    End
};

EvtScript N(EVS_BowserActivatesSwitch) = {
    Thread
        Wait(20)
        Call(N(GetEntityPosition), MV_SwitchEntityIdx, LVar7, LVar8, LVar9)
        Call(MakeLerp, 0, -13, 5, EASING_COS_IN_OUT)
        Label(0)
        Call(UpdateLerp)
        Call(N(SetEntityPositionF), MV_SwitchEntityIdx, LVar7, LVar0, LVar9)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Wait(30)
        Call(N(SetEntityPositionF), MV_SwitchEntityIdx, LVar7, -20, LVar9)
        Call(SetNpcFlagBits, NPC_Bowser_01, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EndThread
    Thread
        Set(MV_Unk_0A, 0)
        Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Jump)
        Wait(10)
        Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Land)
        Wait(10)
        Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_RearUpLaugh)
        Call(PlaySound, SOUND_LRAW_RUMBLE)
        Loop(0)
            Call(ShakeCam, CAM_DEFAULT, 0, 1, Float(2.0))
            Wait(1)
            IfEq(MV_Unk_0A, 11)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySound, SOUND_LRAW_RUMBLE | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EndThread
    Call(SetNpcJumpscale, NPC_Bowser_01, Float(1.0))
    Call(NpcJump0, NPC_Bowser_01, 300, 0, 0, 20)
    Call(PlaySoundAtNpc, NPC_Bowser_01, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_Bowser_01, SOUND_LARGE_NPC_IMPACT, SOUND_SPACE_DEFAULT)
    Set(AF_KKJ_1A, TRUE)
    Return
    End
};

EvtScript N(EVS_802459E4) = {
    Call(GetCurrentPartnerID, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_GOOMBARIO)
        CaseEq(PARTNER_KOOPER)
        CaseEq(PARTNER_BOMBETTE)
        CaseEq(PARTNER_SUSHIE)
        CaseDefault
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
            Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Set(LVar1, 19)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EndSwitch
    Return
    End
};

s32 N(BridgeModels)[] = {
    MODEL_g49,
    MODEL_g48,
    MODEL_g47,
    MODEL_g46,
    MODEL_g45,
    MODEL_g44,
    MODEL_g43,
    MODEL_g42,
    MODEL_g41,
    MODEL_g40,
    MODEL_g39,
    MODEL_g38,
    MODEL_g37,
    MODEL_g36,
    MODEL_g35,
    MODEL_g34,
};

EvtScript N(EVS_Scene_BowserTrapsMario) = {
    Label(0)
        Call(N(GetFloorCollider), LVar0)
        IfNe(LVar0, COLLIDER_o128)
            Wait(1)
            Goto(0)
        EndIf
#if VERSION_PAL
    Call(DisablePlayerInput, TRUE)
#endif
    Thread
        Wait(1)
#if !VERSION_PAL
        Call(DisablePlayerInput, TRUE)
#endif
        Call(PlayerFaceNpc, NPC_Bowser_01, FALSE)
        Call(GetPartnerInUse, LVar0)
        Call(GetCurrentPartnerID, LVar1)
        IfEq(LVar1, PARTNER_BOMBETTE)
            IfNe(LVar0, PARTNER_NONE)
                Goto(1)
            EndIf
        EndIf
        IfNe(LVar0, PARTNER_NONE)
            Call(GetCurrentPartnerID, LVar1)
            IfNe(LVar1, PARTNER_LAKILESTER)
                Call(WaitForPlayerTouchingFloor)
            EndIf
            Call(InterruptUsePartner)
            Wait(5)
        EndIf
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        IfLt(LVar0, 20)
            Call(GetPlayerPos, LVar3, LVar4, LVar5)
            IfLt(LVar5, 0)
                Add(LVar5, 25)
            Else
                Add(LVar5, -25)
            EndIf
            Add(LVar3, -10)
            Call(DisablePartnerAI, 0)
            Call(SetNpcJumpscale, NPC_PARTNER, Float(0.8))
            Call(NpcJump0, NPC_PARTNER, LVar3, LVar1, LVar5, 12)
            Call(EnablePartnerAI)
        EndIf
        Label(1)
    EndThread
    Call(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_007C)
    Wait(20)
    Call(UseSettingsFrom, CAM_DEFAULT, 350, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 350, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_007D)
    ExecWait(N(EVS_BowserActivatesSwitch))
    Call(UseSettingsFrom, CAM_DEFAULT, -150, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -150, 0, 100)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(26.0), Float(-18.0))
    Call(SetCamPosA, CAM_DEFAULT, -480, -480)
    Call(SetCamPosB, CAM_DEFAULT, 0, 480)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_WaveBridgeModels) = {
    UseBuf(Ref(N(BridgeModels)))
    SetF(LVar1, Float(1.0))
    Set(LVar2, 1)
    Loop(ARRAY_COUNT(N(BridgeModels)))
        BufRead1(LVar3)
        SetF(LVar0, 0)
        Thread
            Loop(5)
                SubF(LVar0, LVar1)
                Call(TranslateGroup, LVar3, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Loop(5)
                AddF(LVar0, LVar1)
                Call(TranslateGroup, LVar3, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Loop(5)
                AddF(LVar0, LVar1)
                Call(TranslateGroup, LVar3, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Loop(5)
                SubF(LVar0, LVar1)
                Call(TranslateGroup, LVar3, 0, LVar0, 0)
                Wait(1)
            EndLoop
        EndThread
        IfLt(LVar2, 8)
            AddF(LVar1, Float(0.5))
        Else
            SubF(LVar1, Float(0.5))
        EndIf
        Add(LVar2, 1)
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_AnimateBridgeCollapsing) = {
    Loop(4)
        Exec(N(EVS_WaveBridgeModels))
        Wait(25)
    EndLoop
    Thread
        Wait(15)
        Set(MV_Unk_0A, 11)
    EndThread
    UseBuf(Ref(N(BridgeModels)))
    Set(LVar2, 35)
    Set(LVar5, -15)
    Loop(ARRAY_COUNT(N(BridgeModels)))
        Call(PlaySoundAt, SOUND_SEQ_FINALE_BRIDGE_COLLAPSE, SOUND_SPACE_DEFAULT, LVar5, 0, 0)
        Add(LVar5, -30)
        BufRead1(LVar3)
        Thread
            Call(MakeLerp, 0, -25, 5, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateGroup, LVar3, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Set(LVar4, 0)
            Call(MakeLerp, -25, -1000, LVar2, EASING_CUBIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Call(TranslateGroup, LVar3, 0, LVar0, 0)
                Add(LVar4, -20)
                Call(RotateGroup, LVar3, LVar4, 0, 0, 1)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(EnableGroup, LVar3, FALSE)
        EndThread
        Add(LVar2, 2)
        Wait(5)
    EndLoop
    Return
    End
};

Vec3i N(PowerUpBoltOrigins1)[] = {
    { 230, 160,   0 },
    { 350, 160,  90 },
    { 420, 160,  10 },
    { 280, 160, -10 },
};

Vec3i N(PowerUpBoltOrigins2)[] = {
    { 330, 160,  50 },
    { 360, 160, -50 },
    { 370, 160,  50 },
    { 330, 160, -50 },
};

EvtScript N(EVS_Scene_ActivateMachine) = {
    Set(AF_KKJ_1A, FALSE)
    Wait(10)
    Call(UseSettingsFrom, CAM_DEFAULT, -150, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -150, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 1000)
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-5.0))
    Call(SetCamPosA, CAM_DEFAULT, -480, -480)
    Call(SetCamPosB, CAM_DEFAULT, 0, 480)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(1)
    Thread
        Call(InterpPlayerYaw, 270, 0)
        Wait(30)
        Call(SetPlayerAnimation, ANIM_MarioW2_Shocked)
    EndThread
    Set(MV_Unk_0A, 10)
    ExecWait(N(EVS_AnimateBridgeCollapsing))
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerPos, 100, 0, 0)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, FALSE)
        Call(SetNpcPos, NPC_PARTNER, 60, 10, 0)
    Else
        Call(SetNpcPos, NPC_PARTNER, 60, 0, 0)
    EndIf
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcPos, NPC_PARTNER, 70, 0, 0)
    Call(GetNpcPos, NPC_Bowser_01, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 330)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(10)
    Call(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_RearUpLaugh, ANIM_WorldBowser_RearUpLaugh, 0, MSG_CH8_007E)
    Thread
        Call(SetNpcJumpscale, NPC_Peach_01, Float(1.0))
        Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Peach_01, LVar0, LVar1, LVar2, 12)
        Wait(8)
        Call(GetNpcPos, NPC_Peach_01, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Peach_01, LVar0, LVar1, LVar2, 7)
        Wait(10)
    EndThread
    Call(SpeakToPlayer, NPC_Peach_01, ANIM_Peach3_TiedShout, ANIM_Peach2_TiedIdle, 0, MSG_CH8_007F)
    Wait(15)
    Call(SpeakToPlayer, NPC_Kammy_01, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim04, 512, MSG_CH8_0080)
    Wait(15)
    Call(GetNpcPos, NPC_Kammy_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    Wait(10)
    Thread
        Wait(10)
        Call(InterpNpcYaw, NPC_Peach_01, 90, 0)
        Wait(30)
        Call(InterpNpcYaw, NPC_Peach_01, 270, 0)
    EndThread
    Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim07)
    Call(SpeakToPlayer, NPC_Kammy_01, ANIM_BattleKammy_Anim07, ANIM_BattleKammy_Anim07, 512, MSG_CH8_0081)
    Call(FadeOutMusic, 0, 1500)
    Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim08)
    Call(GetNpcPos, NPC_Kammy_01, LVar0, LVar1, LVar2)
    Add(LVar0, -30)
    Call(PlaySoundAt, SOUND_KAMMY_SUMMON_MAGIC, SOUND_SPACE_DEFAULT, LVar0, 22, 0)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, 22, 0, 1, 80)
    Thread
        Wait(80)
        Call(SetNpcAnimation, NPC_Kammy_01, ANIM_BattleKammy_Anim04)
    EndThread
    Wait(40)
    Call(SetCamProperties, CAM_DEFAULT, Float(4.0), 300, 0, 0, 1100, Float(7.0), Float(0.0))
    Wait(20)
    Call(SetMusic, 0, SONG_BOWSER_BATTLE, 0, VOL_LEVEL_FULL)
    Exec(N(EVS_ArenaEyesFlash))
    Wait(30)
    Set(MV_ArenaState, ARENA_STATE_ACTIVATING)
    Loop(0)
        Wait(1)
        IfNe(MV_ArenaState, ARENA_STATE_ACTIVATING)
            BreakLoop
        EndIf
    EndLoop
    Call(GetNpcPos, NPC_Bowser_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Shock)
    Call(GetNpcPos, NPC_Bowser_01, LVar3, LVar4, LVar5)
    Thread
        UseBuf(Ref(N(PowerUpBoltOrigins1)))
        Loop(ARRAY_COUNT(N(PowerUpBoltOrigins1)))
            BufRead3(LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 8)
            Wait(8)
        EndLoop
    EndThread
    Thread
        UseBuf(Ref(N(PowerUpBoltOrigins2)))
        Loop(ARRAY_COUNT(N(PowerUpBoltOrigins2)))
            BufRead3(LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 8)
            Wait(12)
        EndLoop
        Call(SetNpcDecoration, NPC_Bowser_01, 0, NPC_DECORATION_BOWSER_AURA)
    EndThread
    Wait(15)
    Call(PlaySoundAtNpc, NPC_Bowser_01, SOUND_KPA_BOWSER_POWER_UP, SOUND_SPACE_DEFAULT)
    SetF(LVar0, Float(1.0))
    Loop(50)
        AddF(LVar0, Float(0.01))
        Call(SetNpcScale, NPC_Bowser_01, LVar0, LVar0, LVar0)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_RearUpLaugh)
    Wait(20)
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    Call(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0082)
    Wait(40)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 500)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Thread
        Wait(8)
        Loop(4)
            Call(ShakeCam, CAM_DEFAULT, 0, 4, Float(2.0))
            Wait(3)
            Call(ShakeCam, CAM_DEFAULT, 0, 2, Float(1.0))
            Wait(3)
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Bowser_01, 200, 0, 45)
    Call(SetNpcAnimation, NPC_Bowser_01, ANIM_WorldBowser_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_Bowser_01, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_CH8_0083)
    Wait(10)
    Call(SetNpcVar, NPC_Bowser_01, 0, 1)
    Return
    End
};

Vec3i N(CirculatingBoltPositions)[] = {
    { Float(625.825), Float(-9.194), Float(-91.893)  }, { Float(609.671), Float(-9.194), Float(136.274)  },
    { Float(609.671), Float(-9.194), Float(136.274)  }, { Float(450.634), Float(-9.194), Float(300.677)  },
    { Float(450.634), Float(-9.194), Float(300.677)  }, { Float(223.128), Float(-9.194), Float(324.39)   },
    { Float(223.128), Float(-9.194), Float(324.39)   }, { Float(33.606),  Float(-9.194), Float(196.317)  },
    { Float(33.606),  Float(-9.194), Float(196.317)  }, { Float(-29.252), Float(-9.194), Float(-23.615)  },
    { Float(-29.252), Float(-9.194), Float(-23.615)  }, { Float(63.964),  Float(-9.194), Float(-232.497) },
    { Float(63.964),  Float(-9.194), Float(-232.497) }, { Float(269.64),  Float(-9.194), Float(-332.591) },
    { Float(269.64),  Float(-9.194), Float(-332.591) }, { Float(491.536), Float(-9.194), Float(-277.063) },
    { Float(491.536), Float(-9.194), Float(-277.063) }, { Float(625.825), Float(-9.194), Float(-91.893)  },
};

Vec3i N(RandomBoltPositions)[] = {
    { 180, 300, -200 }, { 250, 0, -150 },
    { 270, 300, -200 }, { 200, 0, -150 },
    { 350, 300, -240 }, { 500, 0, -160 },
    { 550, 300, -240 }, { 400, 0, -160 },
    { 500, 300,  -50 }, { 550, 0,  -50 },
    { 585, 300,  100 }, { 535, 0,  100 },
    {  95, 300,  -50 }, { 180, 0,  -50 },
    { 215, 300,  -50 }, { 130, 0,  -50 },
};

EvtScript N(EVS_ManageArenaEffects) = {
    ChildThread
        Set(LVar2, 0)
        Set(LVar3, 0)
        IfEq(GF_KKJ25_Defeated_Kammy, FALSE)
            Thread
                Wait(50)
                Call(PlaySound, SOUND_LRAW_KPA_ARENA_TURN_ON)
            EndThread
            Call(MakeLerp, 0, 50, 120, EASING_QUADRATIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Div(LVar0, 10)
                Sub(LVar2, LVar0)
                Call(RotateGroup, MODEL_g31, LVar2, 0, 1, 0)
                Add(LVar3, LVar0)
                Call(RotateGroup, MODEL_g7, LVar3, 0, 1, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        Else
            IfEq(GF_KKJ25_Defeated_Bowser, FALSE)
                Call(PlaySound, SOUND_LRAW_KPA_ARENA_ACTIVE)
            EndIf
            Set(LVar0, 5)
        EndIf
        Loop(0)
            AddF(LVar2, LVar0)
            IfGt(LVar2, 360)
                SubF(LVar2, 360)
            EndIf
            Call(RotateGroup, MODEL_g31, LVar2, 0, 1, 0)
            SubF(LVar3, LVar0)
            IfLt(LVar3, -360)
                AddF(LVar3, 360)
            EndIf
            Call(RotateGroup, MODEL_g7, LVar3, 0, 1, 0)
            Wait(1)
        EndLoop
    EndChildThread
    Wait(45)
    ChildThread
        Loop(0)
            UseBuf(Ref(N(CirculatingBoltPositions)))
            Loop(ARRAY_COUNT(N(CirculatingBoltPositions)) / 2)
                BufRead3(LVar0, LVar1, LVar2)
                BufRead3(LVar3, LVar4, LVar5)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 5)
                Call(N(SetLightningBoltPurple))
                Wait(5)
            EndLoop
        EndLoop
    EndChildThread
    ChildThread
        Loop(0)
            UseBuf(Ref(N(RandomBoltPositions)))
            Call(RandInt, 7, LVar6)
            Add(LVar6, 1)
            Loop(LVar6)
                BufRead3(LVar0, LVar1, LVar2)
                BufRead3(LVar3, LVar4, LVar5)
            EndLoop
            IfNe(MV_ArenaState, ARENA_STATE_OVERLOADING)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 10)
                Call(N(SetLightningBoltPurple))
                Wait(30)
            Else
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 5)
                Call(N(SetLightningBoltPurple))
                Wait(15)
            EndIf
        EndLoop
    EndChildThread
    ChildThread
        Set(LVar0, 0)
        Loop(0)
            Add(LVar0, 20)
            IfGe(LVar0, 360)
                Sub(LVar0, 360)
            EndIf
            Call(RotateGroup, MODEL_g51, LVar0, 0, 1, 0)
            Wait(1)
        EndLoop
    EndChildThread
    ChildThread
        IfEq(GF_KKJ25_Defeated_Kammy, FALSE)
            Call(EnableModel, MODEL_o122, TRUE)
            Call(MakeLerp, 0, 250, 100, EASING_QUADRATIC_IN)
            Loop(0)
                Call(UpdateLerp)
                Call(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndIf
        Loop(0)
            IfNe(MV_ArenaState, ARENA_STATE_OVERLOADING)
                Set(LVar2, 250)
            Else
                Set(LVar2, 90)
            EndIf
            Call(MakeLerp, LVar2, 90, 45, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Loop(15)
                Call(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                Wait(1)
            EndLoop
            Call(MakeLerp, 90, LVar2, 30, EASING_COS_IN_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(ScaleModel, MODEL_o122, LVar0, 1, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndChildThread
    Wait(180)
    Set(MV_ArenaState, ARENA_STATE_FULL_POWER)
    Loop(0)
        Wait(1)
        IfEq(MV_ArenaState, ARENA_STATE_BROKEN)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_LRAW_KPA_ARENA_ACTIVE)
    Return
    End
};
