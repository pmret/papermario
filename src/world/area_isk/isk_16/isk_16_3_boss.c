#include "isk_16.h"
#include "sprite/player.h"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_Scene_TutankoopaAppears) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, -1, ENV_TINT_SHROUD)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_SHROUD)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_SHROUD, 0, 0, 0, 255, 0, 0, 0, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 410, -910, 410)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 336, -910, 467)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetPlayerPos, 279, -910, 520)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_PARAKARRY)
        EVT_SET(LVar1, -899)
    EVT_ELSE
        EVT_SET(LVar1, -910)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_PARTNER, 243, LVar1, 535)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 45)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.5 / DT))
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 311, 487, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PlayerMoveTo, 343, 460, 0)
    EVT_EXEC_WAIT(N(EVS_BindExitTriggers))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 410, -910, 410)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH2_00E2, 160, 40)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcPos, NPC_Tutankoopa_01, 410, -1300, 410)
    EVT_THREAD
        EVT_WAIT(50 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_02, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Tutankoopa_02, 410, -905, 410)
    EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_02, ANIM_Tutankoopa_HeaddressWithEyes)
    EVT_CALL(MakeLerp, 0, 255, 100 * DT, EASING_QUADRATIC_IN)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_02, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_WAIT(30 * DT)
    EVT_SET(LVar0, 255)
    EVT_LOOP(60 * DT)
#if VERSION_PAL
        EVT_ADD(LVar0, -5)
#else
        EVT_ADD(LVar0, -4)
#endif
        EVT_CALL(N(SetModelTintParams), ENV_TINT_SHROUD, 0, 0, 0, LVar0, 0, 0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(SetModelTintParams), ENV_TINT_SHROUD, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(530.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Tutankoopa_02, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, 0, 110, 100 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar0, LVar3)
        EVT_CALL(SetNpcPos, NPC_Tutankoopa_02, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_Tutankoopa_02, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, 0, 100, 60 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar5, EVT_FLOAT(0.47))
        EVT_SETF(LVar6, EVT_FLOAT(-0.94))
        EVT_MULF(LVar5, LVar0)
        EVT_MULF(LVar6, LVar0)
        EVT_ADDF(LVar5, LVar2)
        EVT_ADDF(LVar6, LVar4)
        EVT_CALL(SetNpcPos, NPC_Tutankoopa_02, LVar5, LVar3, LVar6)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Tutankoopa_01, 457, -800, 316)
    EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Idle)
    EVT_THREAD
        EVT_WAIT(59)
        EVT_CALL(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_BOWSER_CHARGE_LIGHTNING, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ALPHA, 255, 0, 0, 0)
    EVT_CALL(SetNpcImgFXFlags, NPC_Tutankoopa_01, IMGFX_FLAG_800)
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ANIM, IMGFX_ANIM_TUTANKOOPA_SWIRL_1, 2, 1, 0)
    EVT_WAIT(39)
    EVT_CALL(SetNpcImgFXFlags, NPC_Tutankoopa_01, IMGFX_FLAG_800)
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ANIM, IMGFX_ANIM_TUTANKOOPA_SWIRL_2, 2, 1, 0)
    EVT_WAIT(39)
    EVT_CALL(SetNpcImgFXFlags, NPC_Tutankoopa_01, IMGFX_FLAG_800)
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_SET_ANIM, IMGFX_ANIM_TUTANKOOPA_GATHER, 2, 1, 0)
    EVT_WAIT(55)
    EVT_CALL(SetNpcImgFXParams, NPC_Tutankoopa_01, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Tutankoopa_02, 457, -1300, 316)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 438, -800, 332)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(225.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-7.5), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Tutankoopa_01, ANIM_Tutankoopa_Talk, ANIM_Tutankoopa_Idle, 0, MSG_CH2_00E3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetNpcVar, NPC_Tutankoopa_01, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayChompSounds) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_ChainChomp, SOUND_CHAIN_CHOMP_BITE, SOUND_SPACE_DEFAULT)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_TutankoopaDefeated) = {
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_THREAD
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH2_00E8, 160, 40)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Hurt)
    EVT_CALL(SetNpcJumpscale, NPC_Tutankoopa_01, EVT_FLOAT(1.0))
    EVT_CALL(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_WITHER, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_Tutankoopa_01, 442, -910, 393, 30 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_Tutankoopa_01, 416, -910, 420, 20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_Tutankoopa_01, 395, -910, 440, 10 * DT)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Idle)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 410, -910, 410)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 490, -910, 327)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnableModel, MODEL_o2359, FALSE)
    EVT_EXEC_GET_TID(N(EVS_PlayChompSounds), LVarA)
    EVT_CALL(SetNpcPos, NPC_ChainChomp, 516, -910, 263)
    EVT_CALL(SetNpcSpeed, NPC_ChainChomp, EVT_FLOAT(3.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_ChainChomp, 493, 292, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(GetNpcPos, NPC_Tutankoopa_01, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(EnableModel, MODEL_o2359, TRUE)
    EVT_CALL(NpcFaceNpc, NPC_Tutankoopa_01, NPC_ChainChomp, 0)
    EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Hurt)
    EVT_CALL(GetNpcPos, NPC_Tutankoopa_01, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, NPC_Tutankoopa_01, SOUND_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_Tutankoopa_01, LVar0, LVar1, LVar2, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Tutankoopa_01, ANIM_Tutankoopa_Talk, ANIM_Tutankoopa_Idle, 5, MSG_CH2_00E9)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_ChainChomp, ANIM_ChainChomp_QuickBite)
        EVT_CALL(SetNpcSpeed, NPC_ChainChomp, EVT_FLOAT(8.0 / DT))
        EVT_CALL(SetNpcPos, NPC_ChainChomp, 486, -910, 340)
        EVT_CALL(GetNpcPos, NPC_Tutankoopa_01, LVar0, LVar1, LVar2)
        EVT_CALL(NpcMoveTo, NPC_ChainChomp, LVar0, LVar2, 0)
        EVT_LOOP(2)
            EVT_CALL(NpcMoveTo, NPC_ChainChomp, 304, 434, 0)
            EVT_CALL(NpcMoveTo, NPC_ChainChomp, 444, 316, 0)
            EVT_CALL(NpcMoveTo, NPC_ChainChomp, 473, 337, 0)
            EVT_CALL(NpcMoveTo, NPC_ChainChomp, 318, 460, 0)
        EVT_END_LOOP
        EVT_CALL(NpcMoveTo, NPC_ChainChomp, 259, 522, 0)
        EVT_CALL(SetNpcPos, NPC_ChainChomp, 0, -1500, 0)
        EVT_KILL_THREAD(LVarA)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_ChainChomp, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_Tutankoopa_01, LVar3, LVar4, LVar5)
        EVT_CALL(GetDist2D, LVar6, LVar0, LVar2, LVar3, LVar5)
        EVT_IF_LT(LVar6, 50)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetSelfVar, 1, 1)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Tutankoopa_01, ANIM_Tutankoopa_Run)
        EVT_CALL(SetNpcSpeed, NPC_Tutankoopa_01, EVT_FLOAT(8.0 / DT))
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LookAround)
        EVT_LOOP(2)
            EVT_CALL(NpcMoveTo, NPC_Tutankoopa_01, 304, 434, 0)
            EVT_CALL(NpcMoveTo, NPC_Tutankoopa_01, 444, 316, 0)
            EVT_CALL(NpcMoveTo, NPC_Tutankoopa_01, 473, 337, 0)
            EVT_CALL(NpcMoveTo, NPC_Tutankoopa_01, 318, 460, 0)
        EVT_END_LOOP
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_CALL(NpcMoveTo, NPC_Tutankoopa_01, 259, 522, 0)
        EVT_CALL(SetNpcPos, NPC_Tutankoopa_01, 0, -1500, 0)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(SetSelfVar, 1, 0)
    EVT_END_THREAD
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH2_00EA, 160, 40)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_SET(GF_ISK16_Defeated_Tutankoopa, TRUE)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_RETURN
    EVT_END
};
