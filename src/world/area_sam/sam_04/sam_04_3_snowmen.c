#include "sam_04.h"
#include "effects.h"
#include "sprite/player.h"

#include "common/SetAngleClamped.inc.c"

s32 N(CloneSet1)[] = {
    CLONED_MODEL(0), CLONED_MODEL(1), CLONED_MODEL(2), CLONED_MODEL(3)
};

s32 N(CloneSet2)[] = {
    CLONED_MODEL(4), CLONED_MODEL(5), CLONED_MODEL(6), CLONED_MODEL(7)
};

s32 N(CloneSet3)[] = {
    CLONED_MODEL(8), CLONED_MODEL(9), CLONED_MODEL(10), CLONED_MODEL(11)
};

s32 N(CloneSet4)[] = {
    CLONED_MODEL(12), CLONED_MODEL(13), CLONED_MODEL(14), CLONED_MODEL(15)
};

s32 N(CloneSet5)[] = {
    CLONED_MODEL(16), CLONED_MODEL(17), CLONED_MODEL(18), CLONED_MODEL(19)
};

s32 N(OriginalModels)[] = {
    MODEL_d_me, MODEL_body, MODEL_baketu, MODEL_mafu
};

s32* N(SnowmanModelSets)[] = {
    N(CloneSet1),
    N(CloneSet2),
    N(CloneSet3),
    N(CloneSet4),
    N(CloneSet5),
    N(OriginalModels),
};

EvtScript N(EVS_SetSnowmanPosition) = {
    EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_USE_BUF(EVT_PTR(N(SnowmanModelSets)))
    EVT_ADD(LVar0, 1)
    EVT_LOOP(LVar0)
        EVT_BUF_READ1(LVar4)
    EVT_END_LOOP
    EVT_USE_BUF(LVar4)
    EVT_BUF_READ1(LVar4)
    EVT_CALL(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    EVT_BUF_READ1(LVar4)
    EVT_CALL(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    EVT_BUF_READ1(LVar4)
    EVT_CALL(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    EVT_BUF_READ1(LVar4)
    EVT_CALL(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SnowmanJump) = {
    EVT_THREAD
        EVT_SET(LVarA, LVar0)
        EVT_USE_BUF(EVT_PTR(N(SnowmanModelSets)))
        EVT_ADD(LVarA, 1)
        EVT_LOOP(LVarA)
            EVT_BUF_READ1(LVarB)
        EVT_END_LOOP
        EVT_USE_BUF(LVarB)
        EVT_BUF_READ4(LVarC, LVarD, LVarE, LVarF)
        EVT_ADD(LVar4, 1)
        EVT_LOOP(LVar4)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_CALL(TranslateModel, LVarC, LVar1, LVar2, LVar3)
            EVT_CALL(TranslateModel, LVarD, LVar1, LVar2, LVar3)
            EVT_CALL(TranslateModel, LVarE, LVar1, LVar2, LVar3)
            EVT_CALL(TranslateModel, LVarF, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, LVar0, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, LVar0, LVar1, LVar2, LVar3, LVar4)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar1, LVar2, LVar3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SnowmanMove) = {
    EVT_CALL(GetNpcPos, LVar0, LVar5, LVar6, LVar7)
    EVT_SETF(LVar8, LVar1)
    EVT_SETF(LVar9, LVar2)
    EVT_SETF(LVarA, LVar3)
    EVT_SETF(LVarB, LVar4)
    EVT_SUBF(LVar8, LVar5)
    EVT_SUBF(LVar9, LVar6)
    EVT_SUBF(LVarA, LVar7)
    EVT_DIVF(LVar8, LVarB)
    EVT_DIVF(LVar9, LVarB)
    EVT_DIVF(LVarA, LVarB)
    EVT_LOOP(LVarB)
        EVT_ADDF(LVar5, LVar8)
        EVT_ADDF(LVar6, LVar9)
        EVT_ADDF(LVar7, LVarA)
        EVT_SETF(LVar1, LVar5)
        EVT_SETF(LVar2, LVar6)
        EVT_SETF(LVar3, LVar7)
        EVT_SET(LVar4, 20)
        EVT_EXEC_WAIT(N(EVS_SnowmanJump))
        EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SAM_SNOWMAN_JUMP, SOUND_SPACE_DEFAULT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_SnowmenSpeak) = {
    EVT_WAIT(20 * DT)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetNpcPos, NPC_Snowman_03, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_Snowman_03, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011B)
        EVT_CALL(GetNpcPos, NPC_Snowman_06, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(15 * DT)
        EVT_CALL(SpeakToPlayer, NPC_Snowman_06, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011C)
    EVT_ELSE
        EVT_CALL(GetNpcPos, NPC_Snowman_06, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_Snowman_06, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011C)
        EVT_CALL(GetNpcPos, NPC_Snowman_03, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(15 * DT)
        EVT_CALL(SpeakToPlayer, NPC_Snowman_03, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011B)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, -140)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -100)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_011D, 160, 40)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_06, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_WAIT(22 * DT)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetAngleClamped), LVar3, LVar0, LVar2, 0, 0)
        EVT_CALL(GetDist2D, LVar4, LVar0, LVar2, 0, 0)
        EVT_SETF(LVar5, LVar4)
        EVT_DIVF(LVar5, EVT_FLOAT(5.0))
        EVT_SETF(LVar8, LVar3)
        EVT_SUBF(LVar8, EVT_FLOAT(90.0))
        EVT_LOOP(4)
            EVT_CALL(AddVectorPolar, LVar0, LVar2, LVar5, LVar3)
            EVT_SETF(LVar6, LVar0)
            EVT_SETF(LVar7, LVar2)
            EVT_CALL(AddVectorPolar, LVar6, LVar7, EVT_FLOAT(20.0), LVar8)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
            EVT_CALL(PlayerJump1, LVar6, 0, LVar7, 16 * DT)
            EVT_ADDF(LVar8, EVT_FLOAT(180.0))
            EVT_WAIT(6 * DT)
        EVT_END_LOOP
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0 / DT))
        EVT_CALL(PlayerJump1, 0, 0, 0, 16 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(InterpPlayerYaw, 0, 0)
        EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(110 * DT)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump1, NPC_PARTNER, 50, 0, 0, 22)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_WAIT(110 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(22 * DT)
        EVT_LOOP(5)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 6 * DT, EVT_FLOAT(2.0))
            EVT_WAIT(16 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LVar0, NPC_Snowman_01)
    EVT_SETF(LVar1, EVT_FLOAT(-175.0))
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(-180.0))
    EVT_SETF(LVar4, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SnowmanMove))
    EVT_SET(LVar0, NPC_Snowman_02)
    EVT_SETF(LVar1, EVT_FLOAT(-125.0))
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(-220.0))
    EVT_SETF(LVar4, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SnowmanMove))
    EVT_SET(LVar0, NPC_Snowman_03)
    EVT_SETF(LVar1, EVT_FLOAT(-75.0))
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(-260.0))
    EVT_SETF(LVar4, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SnowmanMove))
    EVT_SET(LVar0, NPC_Snowman_04)
    EVT_SETF(LVar1, EVT_FLOAT(75.0))
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(-260.0))
    EVT_SETF(LVar4, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SnowmanMove))
    EVT_SET(LVar0, NPC_Snowman_05)
    EVT_SETF(LVar1, EVT_FLOAT(125.0))
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(-220.0))
    EVT_SETF(LVar4, EVT_FLOAT(5.0))
    EVT_EXEC(N(EVS_SnowmanMove))
    EVT_WAIT(1)
    EVT_SET(LVar0, NPC_Snowman_06)
    EVT_SETF(LVar1, EVT_FLOAT(175.0))
    EVT_SETF(LVar2, EVT_FLOAT(0.0))
    EVT_SETF(LVar3, EVT_FLOAT(-180.0))
    EVT_SETF(LVar4, EVT_FLOAT(5.0))
    EVT_EXEC_WAIT(N(EVS_SnowmanMove))
    EVT_WAIT(80 * DT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 200, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(10)
            EVT_SET(LVar0, -150)
            EVT_LOOP(6)
                EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, 0, -260, 0)
                EVT_ADD(LVar0, 60)
            EVT_END_LOOP
            EVT_WAIT(20 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(40 * DT)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, -240)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -240)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_SAM_SNOWMEN_RAISE_WALL, SOUND_SPACE_DEFAULT, 0, 0, -300)
    EVT_CALL(MakeLerp, 0, 100, 200 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o65, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o64, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o66, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(60 * DT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetModelCenter, MODEL_o65)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2, 0)
        EVT_CALL(GetModelCenter, MODEL_o64)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_SAM_SNOWMEN_OPEN_PASSAGE, SOUND_SPACE_DEFAULT, 0, 0, -300)
    EVT_CALL(MakeLerp, 0, 80, 100 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_o65, 0, 100, 0)
    EVT_CALL(TranslateModel, MODEL_o64, 0, 100, 0)
    EVT_CALL(RotateModel, MODEL_o65, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o64, LVar0, 0, -1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_WAIT(60 * DT)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_011E, 160, 40)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o78)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o79)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o80)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Snowman_06, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(BindNpcInteract, NPC_Snowman_01, NULL)
    EVT_CALL(BindNpcInteract, NPC_Snowman_02, NULL)
    EVT_CALL(BindNpcInteract, NPC_Snowman_03, NULL)
    EVT_CALL(BindNpcInteract, NPC_Snowman_04, NULL)
    EVT_CALL(BindNpcInteract, NPC_Snowman_05, NULL)
    EVT_CALL(BindNpcInteract, NPC_Snowman_06, NULL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o106, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o118, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o119, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o120, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o121, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSnowmen) = {
    EVT_CALL(CloneModel, MODEL_d_me,    CLONED_MODEL(0))
    EVT_CALL(CloneModel, MODEL_body,    CLONED_MODEL(1))
    EVT_CALL(CloneModel, MODEL_baketu,  CLONED_MODEL(2))
    EVT_CALL(CloneModel, MODEL_mafu,    CLONED_MODEL(3))
    EVT_CALL(CloneModel, MODEL_d_me,    CLONED_MODEL(4))
    EVT_CALL(CloneModel, MODEL_body,    CLONED_MODEL(5))
    EVT_CALL(CloneModel, MODEL_baketu,  CLONED_MODEL(6))
    EVT_CALL(CloneModel, MODEL_mafu,    CLONED_MODEL(7))
    EVT_CALL(CloneModel, MODEL_d_me,    CLONED_MODEL(8))
    EVT_CALL(CloneModel, MODEL_body,    CLONED_MODEL(9))
    EVT_CALL(CloneModel, MODEL_baketu,  CLONED_MODEL(10))
    EVT_CALL(CloneModel, MODEL_mafu,    CLONED_MODEL(11))
    EVT_CALL(CloneModel, MODEL_d_me,    CLONED_MODEL(12))
    EVT_CALL(CloneModel, MODEL_body,    CLONED_MODEL(13))
    EVT_CALL(CloneModel, MODEL_baketu,  CLONED_MODEL(14))
    EVT_CALL(CloneModel, MODEL_mafu,    CLONED_MODEL(15))
    EVT_CALL(CloneModel, MODEL_d_me,    CLONED_MODEL(16))
    EVT_CALL(CloneModel, MODEL_body,    CLONED_MODEL(17))
    EVT_CALL(CloneModel, MODEL_baketu,  CLONED_MODEL(18))
    EVT_CALL(CloneModel, MODEL_mafu,    CLONED_MODEL(19))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o87, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o88, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o89, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o104, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o105, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o106, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o118, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o119, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o120, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o121, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        EVT_SET(LVar0, NPC_Snowman_01)
        EVT_SET(LVar1, -150)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -270)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_02)
        EVT_SET(LVar1, -90)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -270)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_03)
        EVT_SET(LVar1, -30)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -270)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_04)
        EVT_SET(LVar1, 30)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -270)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_05)
        EVT_SET(LVar1, 90)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -270)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_06)
        EVT_SET(LVar1, 150)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -270)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_SET(LVar0, NPC_Snowman_01)
        EVT_SET(LVar1, -175)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -180)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_02)
        EVT_SET(LVar1, -125)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -220)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0,  NPC_Snowman_03)
        EVT_SET(LVar1, -75)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -260)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_04)
        EVT_SET(LVar1, 75)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -260)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_05)
        EVT_SET(LVar1, 125)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -220)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_SET(LVar0, NPC_Snowman_06)
        EVT_SET(LVar1, 175)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, -180)
        EVT_EXEC_WAIT(N(EVS_SetSnowmanPosition))
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o106, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o118, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o119, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o120, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o121, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_SAM04_PlacedScarf, FALSE)
        EVT_CALL(EnableModel, CLONED_MODEL(11), FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_SAM04_PlacedBucket, FALSE)
        EVT_CALL(EnableModel, MODEL_baketu, FALSE)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ParentColliderToModel, COLLIDER_o78, MODEL_o65)
    EVT_CALL(ParentColliderToModel, COLLIDER_o79, MODEL_o64)
    EVT_CALL(ParentColliderToModel, COLLIDER_o80, MODEL_o66)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        EVT_CALL(TranslateModel, MODEL_o65, 0, 100, 0)
        EVT_CALL(TranslateModel, MODEL_o64, 0, 100, 0)
        EVT_CALL(TranslateModel, MODEL_o66, 0, 100, 0)
        EVT_CALL(RotateModel, MODEL_o65, 80, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o64, 80, 0, -1, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o78)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o79)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o80)
        EVT_CALL(BindNpcInteract, NPC_Snowman_01, 0)
        EVT_CALL(BindNpcInteract, NPC_Snowman_02, 0)
        EVT_CALL(BindNpcInteract, NPC_Snowman_03, 0)
        EVT_CALL(BindNpcInteract, NPC_Snowman_04, 0)
        EVT_CALL(BindNpcInteract, NPC_Snowman_05, 0)
        EVT_CALL(BindNpcInteract, NPC_Snowman_06, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
