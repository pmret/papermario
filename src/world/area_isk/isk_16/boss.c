#include "isk_16.h"
#include "sprite/player.h"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_Scene_TutankoopaAppears) = {
    Call(DisablePlayerInput, true)
    Call(DisablePartnerAI, 0)
    Call(N(SetModelTintMode), APPLY_TINT_MODELS, -1, ENV_TINT_SHROUD)
    Call(N(SetModelTintMode), APPLY_TINT_BG, nullptr, ENV_TINT_SHROUD)
    Call(N(SetModelTintParams), ENV_TINT_SHROUD, 0, 0, 0, 255, 0, 0, 0, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 410, -910, 410)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetPanTarget, CAM_DEFAULT, 336, -910, 467)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetPlayerPos, 279, -910, 520)
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_PARAKARRY)
        Set(LVar1, -899)
    Else
        Set(LVar1, -910)
    EndIf
    Call(SetNpcPos, NPC_PARTNER, 243, LVar1, 535)
    Call(SetNpcYaw, NPC_PARTNER, 45)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Thread
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(SetNpcSpeed, NPC_PARTNER, Float(2.5 / DT))
        Call(NpcMoveTo, NPC_PARTNER, 311, 487, 0)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, false)
    EndThread
    Call(SetPlayerSpeed, Float(4.0 / DT))
    Call(PlayerMoveTo, 343, 460, 0)
    ExecWait(N(EVS_BindExitTriggers))
    Wait(20 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 410, -910, 410)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(ShowMessageAtScreenPos, MSG_CH2_00E2, 160, 40)
    Wait(30 * DT)
    Call(SetNpcPos, NPC_Tutankoopa_01, 410, -1300, 410)
    Thread
        Wait(50 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Wait(30 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Call(SetNpcImgFXParams, NPC_Tutankoopa_02, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(SetNpcPos, NPC_Tutankoopa_02, 410, -905, 410)
    Call(SetNpcAnimation, NPC_Tutankoopa_02, ANIM_Tutankoopa_HeaddressWithEyes)
    Call(MakeLerp, 0, 255, 100 * DT, EASING_QUADRATIC_IN)
    Label(2)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_Tutankoopa_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(SetNpcImgFXParams, NPC_Tutankoopa_02, IMGFX_CLEAR, 0, 0, 0, 0)
    Wait(30 * DT)
    Set(LVar0, 255)
    Loop(60 * DT)
#if VERSION_PAL
        Add(LVar0, -5)
#else
        Add(LVar0, -4)
#endif
        Call(N(SetModelTintParams), ENV_TINT_SHROUD, 0, 0, 0, LVar0, 0, 0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(N(SetModelTintParams), ENV_TINT_SHROUD, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(530.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Thread
        Wait(30 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EndThread
    Call(GetNpcPos, NPC_Tutankoopa_02, LVar2, LVar3, LVar4)
    Call(MakeLerp, 0, 110, 100 * DT, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Add(LVar0, LVar3)
        Call(SetNpcPos, NPC_Tutankoopa_02, LVar2, LVar0, LVar4)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(GetNpcPos, NPC_Tutankoopa_02, LVar2, LVar3, LVar4)
    Call(MakeLerp, 0, 100, 60 * DT, EASING_COS_IN_OUT)
    Label(1)
        Call(UpdateLerp)
        SetF(LVar5, Float(0.47))
        SetF(LVar6, Float(-0.94))
        MulF(LVar5, LVar0)
        MulF(LVar6, LVar0)
        AddF(LVar5, LVar2)
        AddF(LVar6, LVar4)
        Call(SetNpcPos, NPC_Tutankoopa_02, LVar5, LVar3, LVar6)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(SetNpcPos, NPC_Tutankoopa_01, 457, -800, 316)
    Call(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Idle)
    Thread
        Wait(59)
        Call(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_BOWSER_CHARGE_LIGHTNING, SOUND_SPACE_DEFAULT)
    EndThread
    Call(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ALPHA, 255, 0, 0, 0)
    Call(SetNpcImgFXFlags, NPC_Tutankoopa_01, IMGFX_FLAG_800)
    Call(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ANIM, IMGFX_ANIM_TUTANKOOPA_SWIRL_1, 2, 1, 0)
    Wait(39)
    Call(SetNpcImgFXFlags, NPC_Tutankoopa_01, IMGFX_FLAG_800)
    Call(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ANIM, IMGFX_ANIM_TUTANKOOPA_SWIRL_2, 2, 1, 0)
    Wait(39)
    Call(SetNpcImgFXFlags, NPC_Tutankoopa_01, IMGFX_FLAG_800)
    Call(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ANIM, IMGFX_ANIM_TUTANKOOPA_GATHER, 2, 1, 0)
    Wait(55)
    Call(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcPos, NPC_Tutankoopa_02, 457, -1300, 316)
    Wait(10 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 438, -800, 332)
    Call(SetCamDistance, CAM_DEFAULT, Float(225.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(-7.5), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Tutankoopa_01, ANIM_Tutankoopa_Talk, ANIM_Tutankoopa_Idle, 0, MSG_CH2_00E3)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(DisablePlayerInput, false)
    Call(EnablePartnerAI)
    Call(SetNpcVar, NPC_Tutankoopa_01, 0, 1)
    Return
    End
};

EvtScript N(EVS_PlayChompSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_ChainChomp, SOUND_CHAIN_CHOMP_BITE, SOUND_SPACE_DEFAULT)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_TutankoopaDefeated) = {
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Thread
        Call(ShowMessageAtScreenPos, MSG_CH2_00E8, 160, 40)
    EndThread
    Call(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Hurt)
    Call(SetNpcJumpscale, NPC_Tutankoopa_01, Float(1.0))
    Call(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_WITHER, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Tutankoopa_01, 442, -910, 393, 30 * DT)
    Call(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Tutankoopa_01, 416, -910, 420, 20 * DT)
    Call(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Tutankoopa_01, 395, -910, 440, 10 * DT)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Idle)
    Call(UseSettingsFrom, CAM_DEFAULT, 410, -910, 410)
    Call(SetPanTarget, CAM_DEFAULT, 490, -910, 327)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnableModel, MODEL_o2359, false)
    ExecGetTID(N(EVS_PlayChompSounds), LVarA)
    Call(SetNpcPos, NPC_ChainChomp, 516, -910, 263)
    Call(SetNpcSpeed, NPC_ChainChomp, Float(3.0 / DT))
    Call(NpcMoveTo, NPC_ChainChomp, 493, 292, 0)
    Wait(30 * DT)
    Call(GetNpcPos, NPC_Tutankoopa_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(EnableModel, MODEL_o2359, true)
    Call(NpcFaceNpc, NPC_Tutankoopa_01, NPC_ChainChomp, 0)
    Call(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Hurt)
    Call(GetNpcPos, NPC_Tutankoopa_01, LVar0, LVar1, LVar2)
    Call(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Tutankoopa_01, LVar0, LVar1, LVar2, 20 * DT)
    Call(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Idle)
    Call(SpeakToPlayer, NPC_Tutankoopa_01, ANIM_Tutankoopa_Talk, ANIM_Tutankoopa_Idle, 5, MSG_CH2_00E9)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Thread
        Call(SetNpcAnimation, NPC_ChainChomp, ANIM_ChainChomp_QuickBite)
        Call(SetNpcSpeed, NPC_ChainChomp, Float(8.0 / DT))
        Call(SetNpcPos, NPC_ChainChomp, 486, -910, 340)
        Call(GetNpcPos, NPC_Tutankoopa_01, LVar0, LVar1, LVar2)
        Call(NpcMoveTo, NPC_ChainChomp, LVar0, LVar2, 0)
        Loop(2)
            Call(NpcMoveTo, NPC_ChainChomp, 304, 434, 0)
            Call(NpcMoveTo, NPC_ChainChomp, 444, 316, 0)
            Call(NpcMoveTo, NPC_ChainChomp, 473, 337, 0)
            Call(NpcMoveTo, NPC_ChainChomp, 318, 460, 0)
        EndLoop
        Call(NpcMoveTo, NPC_ChainChomp, 259, 522, 0)
        Call(SetNpcPos, NPC_ChainChomp, 0, -1500, 0)
        KillThread(LVarA)
    EndThread
    Loop(0)
        Call(GetNpcPos, NPC_ChainChomp, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_Tutankoopa_01, LVar3, LVar4, LVar5)
        Call(GetDist2D, LVar6, LVar0, LVar2, LVar3, LVar5)
        IfLt(LVar6, 50)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(SetSelfVar, 1, 1)
    Thread
        Call(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Run)
        Call(SetNpcSpeed, NPC_Tutankoopa_01, Float(8.0 / DT))
        Call(SetPlayerAnimation, ANIM_MarioW2_LookAround)
        Loop(2)
            Call(NpcMoveTo, NPC_Tutankoopa_01, 304, 434, 0)
            Call(NpcMoveTo, NPC_Tutankoopa_01, 444, 316, 0)
            Call(NpcMoveTo, NPC_Tutankoopa_01, 473, 337, 0)
            Call(NpcMoveTo, NPC_Tutankoopa_01, 318, 460, 0)
        EndLoop
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Call(NpcMoveTo, NPC_Tutankoopa_01, 259, 522, 0)
        Call(SetNpcPos, NPC_Tutankoopa_01, 0, -1500, 0)
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(SetSelfVar, 1, 0)
    EndThread
    Call(ShowMessageAtScreenPos, MSG_CH2_00EA, 160, 40)
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Wait(10 * DT)
    Set(GF_ISK16_Defeated_Tutankoopa, true)
    Call(FadeOutMusic, 0, 500)
    Return
    End
};
