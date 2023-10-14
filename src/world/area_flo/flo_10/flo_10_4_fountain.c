#include "flo_10.h"
#include "sprite/npc/Lily.h"
#include "sprite/player.h"

#include "world/common/complete/GiveReward.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_RaiseFountain) = {
    EVT_CALL(MakeLerp, -50, 170, 385, EASING_LINEAR)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g22, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GrowFountain) = {
    EVT_CALL(MakeLerp, 0, 100, 90, EASING_QUADRATIC_IN)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_SETF(LVar3, LVar0)
        EVT_DIVF(LVar2, EVT_FLOAT(333.0))
        EVT_DIVF(LVar3, EVT_FLOAT(100.0))
        EVT_ADDF(LVar2, EVT_FLOAT(0.703))
        EVT_CALL(ScaleGroup, MODEL_g22, LVar2, LVar3, LVar2)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Rainbow) = {
    EVT_CALL(EnableTexPanning, MODEL_o73, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_A)
        TEX_PAN_PARAMS_STEP( -150,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnableRainbow) = {
    EVT_WAIT(60)
    EVT_CALL(EnableModel, MODEL_o73, TRUE)
    EVT_EXEC(N(EVS_TexPan_Rainbow))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseLily) = {
    EVT_WAIT(80)
    EVT_CALL(EnableNpcShadow, NPC_Lily, FALSE)
    EVT_CALL(GetNpcPos, NPC_Lily, LVar3, LVar4, LVar5)
    EVT_CALL(MakeLerp, 10, 55, 108, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar6, LVar4)
        EVT_ADD(LVar6, LVar0)
        EVT_ADD(LVar6, -10)
        EVT_CALL(SetNpcPos, NPC_Lily, LVar3, LVar6, LVar5)
        EVT_CALL(TranslateGroup, MODEL_g31, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaisePlayer) = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SitIdle)
    EVT_CALL(GetPlayerPos, LVar2, LVar0, LVar3)
    EVT_CALL(MakeLerp, -50, 90, 60, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar2, EVT_FLOAT(1.2))
        EVT_DIVF(LVar3, EVT_FLOAT(1.2))
        EVT_CALL(SetPlayerPos, LVar2, LVar0, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 90, 270, 280, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseCamera) = {
    EVT_WAIT(80)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.7))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(25.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnleashFountain) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(EVS_RaiseFountain))
    EVT_EXEC(N(EVS_GrowFountain))
    EVT_EXEC(N(EVS_EnableRainbow))
    EVT_EXEC(N(EVS_RaiseLily))
    EVT_EXEC(N(EVS_RaisePlayer))
    EVT_EXEC(N(EVS_RaiseCamera))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerFountain) = {
    EVT_CALL(MakeLerp, 170, 75, 150, EASING_LINEAR)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g22, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShrinkFountain) = {
    EVT_CALL(MakeLerp, 100, 15, 150, EASING_QUADRATIC_IN)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_SETF(LVar3, LVar0)
        EVT_DIVF(LVar2, EVT_FLOAT(333.0))
        EVT_DIVF(LVar3, EVT_FLOAT(100.0))
        EVT_ADDF(LVar2, EVT_FLOAT(0.703))
        EVT_CALL(ScaleGroup, MODEL_g22, LVar2, LVar3, LVar2)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FountainSlowing) = {
    EVT_EXEC(N(EVS_LowerFountain))
    EVT_EXEC(N(EVS_ShrinkFountain))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_ReleaseFountain) = {
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(EnableGroup, MODEL_g22, TRUE)
    EVT_CALL(TranslateGroup, MODEL_g22, 0, -50, 0)
    EVT_CALL(ScaleGroup, MODEL_g22, 0, 0, 0)
    EVT_CALL(EnableGroup, MODEL_g31, TRUE)
    EVT_EXEC_WAIT(N(EVS_UnleashFountain))
    EVT_WAIT(20)
    EVT_CALL(PlaySound, SOUND_LOOP_FLO_RELEASE_FOUNTAIN)
    EVT_WAIT(360)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Flail)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
    EVT_CALL(PlayerJump1, -100, -10, -172, 75)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_FountainSlowing))
    EVT_WAIT(60)
    EVT_CALL(GotoMap, EVT_PTR("flo_24"), flo_24_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_PostReleaseFountain) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, -100, -10, -172)
    EVT_CALL(InterpPlayerYaw, 150, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fallen)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -129, 9, -177)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(EnableGroup, MODEL_water, TRUE)
    EVT_CALL(EnableGroup, MODEL_g2, FALSE)
    EVT_CALL(EnableGroup, MODEL_g12, FALSE)
    EVT_CALL(EnableGroup, MODEL_g31, FALSE)
    EVT_CALL(SetNpcPos, NPC_Lily, -57, -20, -105)
    EVT_CALL(InterpNpcYaw, NPC_Lily, 90, 0)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 450, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetUp)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_PushFlowerSong))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Lily, ANIM_Lily_Talk, ANIM_Lily_Idle, 5, MSG_CH6_0082)
    EVT_CALL(NpcFacePlayer, NPC_Lily, 1)
    EVT_CALL(SpeakToPlayer, NPC_Lily, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0083)
    EVT_CALL(SetNpcAnimation, NPC_Lily, ANIM_Lily_GiveItem)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Lily, ANIM_Lily_Idle)
    EVT_GIVE_KEY_REWARD(ITEM_MIRACLE_WATER)
    EVT_CALL(SpeakToPlayer, NPC_Lily, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0084)
    EVT_CALL(EndSpeech, NPC_Lily, ANIM_Lily_Talk, ANIM_Lily_Idle, 0)
    EVT_CALL(SetNpcAnimation, NPC_Lily, ANIM_Lily_Idle)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_EXEC_WAIT(N(EVS_PopSong))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupFountain) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        EVT_CALL(EnableGroup, MODEL_water, FALSE)
        EVT_CALL(EnableGroup, MODEL_g12, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_water, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g2, FALSE)
        EVT_CALL(EnableGroup, MODEL_g12, FALSE)
        EVT_CALL(EnableGroup, MODEL_g31, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o83, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o86, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o87, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, MODEL_o25, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o40, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o78, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o77, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o118, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o119, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,-2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -100,   80,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(-1000, 2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_6)
        TEX_PAN_PARAMS_STEP(    0,-2000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_8)
        TEX_PAN_PARAMS_STEP(    0,-1500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_9)
        TEX_PAN_PARAMS_STEP(    0,-1000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_FILLED_SPRING_WITH_WATER)
        EVT_EXEC(N(EVS_TexPan_Rainbow))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
