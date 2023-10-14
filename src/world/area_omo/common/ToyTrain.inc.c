#include "common.h"
#include "sprite/player.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"

#include "common/SetAngleClamped.inc.c"

#include "common/CompareFloats.inc.c"

#include "common/AdvanceBuffer.inc.c"

#include "common/SetPlayerStatusPosYaw.inc.c"

#include "common/SetNpcPosYaw.inc.c"

#include "common/CosInterpMinMax.inc.c"

#include "common/IsAOrBPressed.inc.c"

EvtScript N(EVS_Scene_RideTrain) = {
    EVT_MALLOC_ARRAY(20, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SETF(ArrayVar(2), EVT_FLOAT(0.0))
    EVT_SETF(ArrayVar(3), EVT_FLOAT(0.0))
    EVT_SETF(ArrayVar(7), EVT_FLOAT(0.0))
    EVT_SETF(ArrayVar(8), EVT_FLOAT(0.0))
    EVT_SETF(ArrayVar(14), EVT_FLOAT(0.0))
    EVT_SETF(ArrayVar(15), EVT_FLOAT(0.0))
    EVT_SETF(ArrayVar(16), EVT_FLOAT(0.0))
    EVT_SET(AF_OMO_03, FALSE)
    EVT_LABEL(0)
        EVT_SWITCH(MV_TrainUnk_00)
            EVT_CASE_EQ(0)
                EVT_USE_BUF(MV_TrainUnk_01)
                EVT_BUF_READ3(LVar0, LVar1, LVar2)
                EVT_SETF(ArrayVar(0), LVar0)
                EVT_SETF(ArrayVar(1), LVar1)
                EVT_CALL(AddVectorPolar, ArrayVar(0), ArrayVar(1), EVT_FLOAT(40.0), LVar2)
                EVT_SETF(ArrayVar(5), LVar0)
                EVT_SETF(ArrayVar(6), LVar1)
                EVT_SETF(LVar3, LVar2)
                EVT_ADDF(LVar3, EVT_FLOAT(180.0))
                EVT_CALL(AddVectorPolar, ArrayVar(5), ArrayVar(6), EVT_FLOAT(40.0), LVar3)
                EVT_SETF(ArrayVar(11), LVar0)
                EVT_SETF(ArrayVar(12), LVar1)
                EVT_SETF(MV_TrainPos, ArrayVar(11))
                EVT_SETF(MV_TrainUnk_0C, ArrayVar(12))
                EVT_SETF(MV_TrainUnk_0D, LVar2)
                EVT_SETF(ArrayVar(17), EVT_FLOAT(0.0))
                EVT_LABEL(11)
                    EVT_BUF_READ2(LVar2, LVar3)
                    EVT_IF_EQ(LVar2, -1)
                        EVT_GOTO(12)
                    EVT_END_IF
                    EVT_CALL(GetDist2D, LVar4, LVar0, LVar1, LVar2, LVar3)
                    EVT_ADDF(ArrayVar(17), LVar4)
                    EVT_SETF(LVar0, LVar2)
                    EVT_SETF(LVar1, LVar3)
                    EVT_GOTO(11)
                EVT_LABEL(12)
                EVT_SUBF(ArrayVar(17), EVT_FLOAT(40.0))
                EVT_SETF(ArrayVar(10), EVT_FLOAT(0.0))
                EVT_SETF(ArrayVar(13), EVT_FLOAT(0.0))
                EVT_SET(ArrayVar(18), 0)
                EVT_IF_EQ(MF_TrainUnk_00, TRUE)
                    EVT_SET(MV_TrainUnk_00, 1)
                EVT_END_IF
            EVT_CASE_EQ(1)
                EVT_USE_BUF(MV_TrainUnk_01)
                EVT_CALL(N(AdvanceBuffer), 3, 0, 0)
                EVT_BUF_READ2(LVar0, LVar1)
                EVT_IF_EQ(LVar0, -1)
                    EVT_SET(MV_TrainUnk_00, 100)
                    EVT_SET(MF_TrainUnk_00, FALSE)
                EVT_ELSE
                    EVT_SETF(ArrayVar(2), LVar0)
                    EVT_SETF(ArrayVar(3), LVar1)
                    EVT_SET(ArrayVar(4), 1)
                    EVT_SETF(ArrayVar(7), LVar0)
                    EVT_SETF(ArrayVar(8), LVar1)
                    EVT_SET(ArrayVar(9), 1)
                    EVT_SET(MV_TrainUnk_00, 10)
                EVT_END_IF
            EVT_CASE_EQ(10)
                EVT_SWITCH(MV_TrainUnk_02)
                    EVT_CASE_EQ(0)
                        EVT_SETF(ArrayVar(10), EVT_FLOAT(10.0))
                    EVT_CASE_EQ(1)
                        EVT_CALL(N(CosInterpMinMax), ArrayVar(18), ArrayVar(10), EVT_FLOAT(0.0), EVT_FLOAT(10.0), 100, 1, EVT_FLOAT(0.0))
                        EVT_ADD(ArrayVar(18), 1)
                    EVT_CASE_EQ(2)
                        EVT_SET(LVar0, ArrayVar(13))
                        EVT_SET(LVar1, ArrayVar(17))
                        EVT_CALL(N(CosInterpMinMax), LVar0, ArrayVar(10), EVT_FLOAT(10.0), EVT_FLOAT(2.0), LVar1, 0, EVT_FLOAT(0.0))
                    EVT_CASE_EQ(3)
                        EVT_SET(LVar0, ArrayVar(13))
                        EVT_SET(LVar1, ArrayVar(17))
                        EVT_DIV(LVar1, 2)
                        EVT_CALL(N(CosInterpMinMax), LVar0, ArrayVar(10), EVT_FLOAT(1.0), EVT_FLOAT(10.0), LVar1, 0, EVT_FLOAT(0.0))
                EVT_END_SWITCH
                EVT_CALL(GetDist2D, LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(2), ArrayVar(3))
                EVT_CALL(N(CompareFloats), LVar0, ArrayVar(10), LVar2)
                EVT_IF_EQ(LVar2, 1)
                    EVT_CALL(N(SetAngleClamped), LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(2), ArrayVar(3))
                    EVT_CALL(AddVectorPolar, ArrayVar(0), ArrayVar(1), ArrayVar(10), LVar0)
                EVT_ELSE
                    EVT_SETF(LVar1, ArrayVar(10))
                    EVT_SUBF(LVar1, LVar0)
                    EVT_SETF(ArrayVar(0), ArrayVar(2))
                    EVT_SETF(ArrayVar(1), ArrayVar(3))
                    EVT_USE_BUF(MV_TrainUnk_01)
                    EVT_CALL(N(AdvanceBuffer), 3, 2, ArrayVar(4))
                    EVT_BUF_READ2(ArrayVar(2), ArrayVar(3))
                    EVT_ADD(ArrayVar(4), 1)
                    EVT_IF_EQ(ArrayVar(2), -1)
                        EVT_SET(MV_TrainUnk_00, 100)
                        EVT_SET(MF_TrainUnk_00, FALSE)
                        EVT_SET(LFlag1, TRUE)
                    EVT_ELSE
                        EVT_CALL(N(SetAngleClamped), LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(2), ArrayVar(3))
                        EVT_CALL(AddVectorPolar, ArrayVar(0), ArrayVar(1), LVar1, LVar0)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(GetDist2D, LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(7), ArrayVar(8))
                EVT_CALL(N(CompareFloats), LVar0, ArrayVar(10), LVar2)
                EVT_IF_EQ(LVar2, 1)
                    EVT_CALL(N(SetAngleClamped), LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(7), ArrayVar(8))
                    EVT_CALL(AddVectorPolar, ArrayVar(5), ArrayVar(6), ArrayVar(10), LVar0)
                EVT_ELSE
                    EVT_SETF(LVar1, ArrayVar(10))
                    EVT_SUBF(LVar1, LVar0)
                    EVT_SETF(ArrayVar(5), ArrayVar(7))
                    EVT_SETF(ArrayVar(6), ArrayVar(8))
                    EVT_USE_BUF(MV_TrainUnk_01)
                    EVT_CALL(N(AdvanceBuffer), 3, 2, ArrayVar(9))
                    EVT_BUF_READ2(ArrayVar(7), ArrayVar(8))
                    EVT_ADD(ArrayVar(9), 1)
                    EVT_IF_EQ(ArrayVar(7), -1)
                        EVT_SET(MV_TrainUnk_00, 100)
                        EVT_SET(MF_TrainUnk_00, FALSE)
                        EVT_SET(LFlag1, FALSE)
                    EVT_ELSE
                        EVT_CALL(N(SetAngleClamped), LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(7), ArrayVar(8))
                        EVT_CALL(AddVectorPolar, ArrayVar(5), ArrayVar(6), LVar1, LVar0)
                    EVT_END_IF
                EVT_END_IF
                EVT_IF_EQ(MV_TrainUnk_00, 100)
                    EVT_IF_EQ(LFlag1, TRUE)
                        EVT_CALL(N(SetAngleClamped), LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(5), ArrayVar(6))
                        EVT_SETF(ArrayVar(5), ArrayVar(0))
                        EVT_SETF(ArrayVar(6), ArrayVar(1))
                        EVT_CALL(AddVectorPolar, ArrayVar(5), ArrayVar(6), EVT_FLOAT(80.0), LVar0)
                    EVT_ELSE
                        EVT_CALL(N(SetAngleClamped), LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(0), ArrayVar(1))
                        EVT_SETF(ArrayVar(0), ArrayVar(5))
                        EVT_SETF(ArrayVar(1), ArrayVar(6))
                        EVT_CALL(AddVectorPolar, ArrayVar(0), ArrayVar(1), EVT_FLOAT(80.0), LVar0)
                    EVT_END_IF
                EVT_END_IF
                EVT_SETF(LVar0, ArrayVar(0))
                EVT_SETF(LVar1, ArrayVar(1))
                EVT_ADDF(LVar0, ArrayVar(5))
                EVT_ADDF(LVar1, ArrayVar(6))
                EVT_DIVF(LVar0, EVT_FLOAT(2.0))
                EVT_DIVF(LVar1, EVT_FLOAT(2.0))
                EVT_CALL(N(SetAngleClamped), LVar2, ArrayVar(5), ArrayVar(6), ArrayVar(0), ArrayVar(1))
                EVT_SETF(MV_TrainPos, LVar0)
                EVT_SETF(MV_TrainUnk_0C, LVar1)
                EVT_SETF(MV_TrainUnk_0D, LVar2)
                EVT_CALL(GetDist2D, LVar3, LVar0, LVar1, ArrayVar(11), ArrayVar(12))
                EVT_ADDF(ArrayVar(13), LVar3)
                EVT_SETF(ArrayVar(14), ArrayVar(13))
                EVT_MULF(ArrayVar(14), EVT_FLOAT(1.432))
                EVT_IF_EQ(LFlag0, FALSE)
                    EVT_SETF(LVar0, ArrayVar(10))
                    EVT_IF_LT(LVar0, 1)
                        EVT_SETF(LVar0, EVT_FLOAT(1.0))
                    EVT_END_IF
                    EVT_DIVF(LVar0, EVT_FLOAT(3.0))
                    EVT_SUBF(ArrayVar(15), LVar0)
                    EVT_IF_LT(ArrayVar(15), -10)
                        EVT_SETF(ArrayVar(15), EVT_FLOAT(-10.0))
                        EVT_SET(LFlag0, TRUE)
                        EVT_IF_EQ(AF_OMO_03, FALSE)
                            EVT_CALL(PlaySound, SOUND_OMO_TOY_TRAIN_WHISTLE_A)
                        EVT_ELSE
                            EVT_CALL(PlaySound, SOUND_OMO_TOY_TRAIN_WHISTLE_B)
                        EVT_END_IF
                    EVT_END_IF
                EVT_ELSE
                    EVT_SETF(LVar0, ArrayVar(10))
                    EVT_IF_LT(LVar0, 1)
                        EVT_SETF(LVar0, EVT_FLOAT(1.0))
                    EVT_END_IF
                    EVT_DIVF(LVar0, EVT_FLOAT(3.0))
                    EVT_ADDF(ArrayVar(15), LVar0)
                    EVT_IF_GT(ArrayVar(15), 10)
                        EVT_SETF(ArrayVar(15), EVT_FLOAT(10.0))
                        EVT_SET(LFlag0, FALSE)
                        EVT_IF_EQ(AF_OMO_03, FALSE)
                            EVT_CALL(PlaySound, SOUND_OMO_TOY_TRAIN_CLICK)
                            EVT_SET(AF_OMO_03, TRUE)
                        EVT_ELSE
                            EVT_CALL(PlaySound, SOUND_OMO_TOY_TRAIN_CLICK)
                            EVT_SET(AF_OMO_03, FALSE)
                        EVT_END_IF
                    EVT_END_IF
                EVT_END_IF
                EVT_SETF(LVar0, MV_TrainPos)
                EVT_SETF(LVar1, MV_TrainUnk_0C)
                EVT_SETF(LVar2, MV_TrainUnk_0D)
                EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(15.0), LVar2)
                EVT_CALL(N(SetPlayerStatusPosYaw), LVar0, 50, LVar1, MV_TrainUnk_0D)
                EVT_SETF(LVar0, MV_TrainPos)
                EVT_SETF(LVar1, MV_TrainUnk_0C)
                EVT_SETF(LVar2, MV_TrainUnk_0D)
                EVT_ADDF(LVar2, EVT_FLOAT(180.0))
                EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(15.0), LVar2)
                EVT_CALL(N(SetNpcPosYaw), -4, LVar0, 50, LVar1, MV_TrainUnk_0D)
                EVT_SETF(LVar0, MV_TrainPos)
                EVT_SETF(LVar1, MV_TrainUnk_0C)
                EVT_SETF(LVar2, MV_TrainUnk_0D)
                EVT_IF_LT(LVar2, 180)
                    EVT_ADDF(LVar2, EVT_FLOAT(90.0))
                EVT_ELSE
                    EVT_SUBF(LVar2, EVT_FLOAT(90.0))
                EVT_END_IF
                EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(20.0), LVar2)
                EVT_CALL(N(SetNpcPosYaw), 0, LVar0, 50, LVar1, MV_TrainUnk_0D)
            EVT_CASE_EQ(100)
        EVT_END_SWITCH
        EVT_CALL(TranslateGroup, MODEL_p2, EVT_FLOAT(79.1), EVT_FLOAT(-27.93), EVT_FLOAT(-29.53))
        EVT_CALL(TranslateGroup, MODEL_p3, EVT_FLOAT(-35.1), EVT_FLOAT(-27.93), EVT_FLOAT(-29.53))
        EVT_CALL(RotateGroup, MODEL_p2, EVT_FLOAT(-45.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0))
        EVT_CALL(RotateGroup, MODEL_p3, EVT_FLOAT(45.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0))
        EVT_CALL(TranslateGroup, MODEL_p5, EVT_FLOAT(40.5), EVT_FLOAT(-20.0), EVT_FLOAT(-0.4))
        EVT_CALL(TranslateGroup, MODEL_p6, EVT_FLOAT(-39.5), EVT_FLOAT(-20.0), EVT_FLOAT(-0.4))
        EVT_CALL(TranslateGroup, MODEL_popo, MV_TrainPos, EVT_FLOAT(10.0), MV_TrainUnk_0C)
        EVT_IF_LT(MV_TrainUnk_0D, 180)
            EVT_SETF(LVar1, MV_TrainUnk_0D)
            EVT_SUBF(LVar1, EVT_FLOAT(90.0))
            EVT_CALL(RotateGroup, MODEL_popo, LVar1, EVT_FLOAT(0.0), EVT_FLOAT(-1.0), EVT_FLOAT(0.0))
        EVT_ELSE
            EVT_SETF(LVar1, MV_TrainUnk_0D)
            EVT_SUBF(LVar1, EVT_FLOAT(180.0))
            EVT_SUBF(LVar1, EVT_FLOAT(90.0))
            EVT_CALL(RotateGroup, MODEL_popo, LVar1, EVT_FLOAT(0.0), EVT_FLOAT(-1.0), EVT_FLOAT(0.0))
        EVT_END_IF
        EVT_CALL(RotateGroup, MODEL_p2, EVT_FLOAT(45.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0))
        EVT_CALL(RotateGroup, MODEL_p3, EVT_FLOAT(-45.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0))
        EVT_CALL(TranslateGroup, MODEL_p2, EVT_FLOAT(-79.1), EVT_FLOAT(27.93), EVT_FLOAT(29.53))
        EVT_CALL(TranslateGroup, MODEL_p3, EVT_FLOAT(35.1), EVT_FLOAT(27.93), EVT_FLOAT(29.53))
        EVT_CALL(TranslateGroup, MODEL_p5, EVT_FLOAT(-40.5), EVT_FLOAT(20.0), EVT_FLOAT(0.4))
        EVT_CALL(TranslateGroup, MODEL_p6, EVT_FLOAT(39.5), EVT_FLOAT(20.0), EVT_FLOAT(0.4))
        EVT_IF_LT(MV_TrainUnk_0D, 180)
            EVT_CALL(RotateGroup, MODEL_p5, ArrayVar(14), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(-1.0))
            EVT_CALL(RotateGroup, MODEL_p6, ArrayVar(14), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(-1.0))
        EVT_ELSE
            EVT_CALL(RotateGroup, MODEL_p5, ArrayVar(14), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0))
            EVT_CALL(RotateGroup, MODEL_p6, ArrayVar(14), EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0))
        EVT_END_IF
        EVT_CALL(TranslateGroup, MODEL_p2, EVT_FLOAT(0.0), ArrayVar(15), EVT_FLOAT(0.0))
        EVT_SETF(LVar0, ArrayVar(15))
        EVT_MULF(LVar0, EVT_FLOAT(-1.0))
        EVT_CALL(TranslateGroup, MODEL_p3, EVT_FLOAT(0.0), LVar0, EVT_FLOAT(0.0))
        EVT_SETF(LVar0, ArrayVar(10))
        EVT_IF_LT(LVar0, 1)
            EVT_SETF(LVar0, EVT_FLOAT(1.0))
        EVT_END_IF
        EVT_ADDF(ArrayVar(16), LVar0)
        EVT_IF_GT(ArrayVar(16), 360)
            EVT_SUBF(ArrayVar(16), EVT_FLOAT(360.0))
        EVT_END_IF
        EVT_CALL(RotateGroup, MODEL_p4, ArrayVar(16), EVT_FLOAT(0.0), EVT_FLOAT(1.0), EVT_FLOAT(0.0))
        EVT_SETF(ArrayVar(11), MV_TrainPos)
        EVT_SETF(ArrayVar(12), MV_TrainUnk_0C)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrainUnk_A) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrainUnk_B) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(MakeLerp, 0, LVar1, 45, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrainUnk_C) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(MakeLerp, LVar1, 0, 40, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrainUnk_D) = {
    EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_THREAD
        EVT_USE_BUF(LVar0)
        EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_CALL(AddVectorPolar, LVar1, LVar2, EVT_FLOAT(15.0), LVar3)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
        EVT_CALL(PlayerMoveTo, LVar1, LVar2, 0)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(0.7))
        EVT_CALL(PlayerMoveTo, LVar1, LVar2, 0)
        EVT_CALL(SetPlayerPos, LVar1, 50, LVar2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(InterpPlayerYaw, LVar3, 0)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ3(LVar1, LVar2, LVar3)
    EVT_SETF(LVarA, LVar3)
    EVT_ADDF(LVar3, EVT_FLOAT(180.0))
    EVT_CALL(AddVectorPolar, LVar1, LVar2, EVT_FLOAT(15.0), LVar3)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, 50, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(0.5))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar1, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
    EVT_WAIT(5)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ3(LVar1, LVar2, LVar3)
    EVT_SETF(LVarA, LVar3)
    EVT_IF_LT(LVar3, 180)
        EVT_ADDF(LVar3, EVT_FLOAT(90.0))
    EVT_ELSE
        EVT_SUBF(LVar3, EVT_FLOAT(90.0))
    EVT_END_IF
    EVT_SETF(LVar4, LVar1)
    EVT_SETF(LVar5, LVar2)
    EVT_SETF(LVar6, LVar3)
    EVT_CALL(AddVectorPolar, LVar1, LVar2, EVT_FLOAT(100.0), LVar3)
    EVT_CALL(SetNpcSpeed, NPC_Conductor, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
    EVT_CALL(NpcMoveTo, NPC_Conductor, LVar1, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
    EVT_CALL(AddVectorPolar, LVar4, LVar5, EVT_FLOAT(20.0), LVar6)
    EVT_CALL(SetNpcJumpscale, NPC_Conductor, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_Conductor, LVar4, 50, LVar5, 10)
    EVT_CALL(InterpNpcYaw, NPC_Conductor, LVarA, 0)
    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_0009)
    EVT_CALL(PlaySound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    EVT_CALL(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

#ifdef INCLUDE_ALTERNATES
EvtScript N(EVS_TrainUnk_AltD) = {
    EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SET(AF_OMO_06, FALSE)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LT(LVar2, 50)
        EVT_USE_BUF(LVar9)
        EVT_BUF_READ4(LVar3, LVar4, LVar5, LVar6)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.5))
        EVT_CALL(PlayerMoveTo, LVar3, LVar4, 0)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
        EVT_CALL(PlayerJump, LVar5, 50, LVar6, 15)
    EVT_END_IF
    EVT_THREAD
        EVT_USE_BUF(LVar0)
        EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_CALL(AddVectorPolar, LVar1, LVar2, EVT_FLOAT(15.0), LVar3)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
        EVT_CALL(PlayerMoveTo, LVar1, LVar2, 0)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(0.7))
        EVT_CALL(PlayerMoveTo, LVar1, LVar2, 0)
        EVT_CALL(SetPlayerPos, LVar1, 50, LVar2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(InterpPlayerYaw, LVar3, 0)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ3(LVar1, LVar2, LVar3)
    EVT_SETF(LVarA, LVar3)
    EVT_ADDF(LVar3, EVT_FLOAT(180.0))
    EVT_CALL(AddVectorPolar, LVar1, LVar2, EVT_FLOAT(15.0), LVar3)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar1, 50, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(0.1))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar1, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
    EVT_WAIT(5)
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ3(LVar1, LVar2, LVar3)
    EVT_SETF(LVarA, LVar3)
    EVT_ADDF(LVar3, EVT_FLOAT(90.0))
    EVT_SETF(LVar4, LVar1)
    EVT_SETF(LVar5, LVar2)
    EVT_SETF(LVar6, LVar3)
    EVT_CALL(AddVectorPolar, LVar1, LVar2, EVT_FLOAT(60.0), LVar3)
    EVT_CALL(SetNpcSpeed, NPC_Conductor, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
    EVT_CALL(NpcMoveTo, NPC_Conductor, LVar1, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
    EVT_CALL(AddVectorPolar, LVar4, LVar5, EVT_FLOAT(20.0), LVar6)
    EVT_CALL(SetNpcJumpscale, NPC_Conductor, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_Conductor, LVar4, 50, LVar5, 10)
    EVT_CALL(InterpNpcYaw, NPC_Conductor, LVarA, 0)
    EVT_CALL(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_0009)
    EVT_CALL(PlaySound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    EVT_CALL(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};
#endif

EvtScript N(EVS_TrainUnk_E) = {
    EVT_CALL(StopSound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SETF(LVar0, MV_TrainPos)
    EVT_SETF(LVar1, MV_TrainUnk_0C)
    EVT_SETF(LVar2, MV_TrainUnk_0D)
    EVT_IF_LT(LVar2, 180)
        EVT_ADDF(LVar2, EVT_FLOAT(90.0))
    EVT_ELSE
        EVT_SUBF(LVar2, EVT_FLOAT(90.0))
    EVT_END_IF
    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(100.0), LVar2)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Conductor, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_Conductor, LVar0, 50, LVar1, 10)
        EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Conductor, EVT_FLOAT(2.0))
        EVT_USE_BUF(LVar9)
        EVT_BUF_READ2(LVar3, LVar4)
        EVT_CALL(NpcMoveTo, NPC_Conductor, LVar3, LVar4, 0)
        EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
        EVT_CALL(InterpNpcYaw, NPC_Conductor, 270, 15)
        EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_ADDF(LVar2, EVT_FLOAT(60.0))
        EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(20.0), LVar2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, LVar0, LVar1, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.5))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar1, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

#ifdef INCLUDE_ALTERNATES
EvtScript N(EVS_TrainUnk_AltE) = {
    EVT_CALL(StopSound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SET(AF_OMO_06, TRUE)
    EVT_SETF(LVar0, MV_TrainPos)
    EVT_SETF(LVar1, MV_TrainUnk_0C)
    EVT_SETF(LVar2, MV_TrainUnk_0D)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Conductor, EVT_FLOAT(3.5))
        EVT_USE_BUF(LVar9)
        EVT_BUF_READ2(LVar3, LVar4)
        EVT_CALL(NpcMoveTo, NPC_Conductor, LVar3, LVar4, 0)
        EVT_CALL(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_SadIdle)
        EVT_CALL(InterpNpcYaw, NPC_Conductor, 90, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_ADDF(LVar2, EVT_FLOAT(85.0))
        EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(80.0), LVar2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, LVar0, LVar1, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_ADDF(LVar2, EVT_FLOAT(50.0))
    EVT_CALL(AddVectorPolar, LVar0, LVar1, EVT_FLOAT(85.0), LVar2)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.5))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar1, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};
#endif

EvtScript N(EVS_TrainUnk_F) = {
    EVT_SWITCH(AB_OMO_6)
        EVT_CASE_EQ(0)
            EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_3, TRANSITION_TOY_TRAIN)
        EVT_CASE_EQ(1)
            EVT_CALL(GotoMapSpecial, EVT_PTR("omo_06"), omo_06_ENTRY_3, TRANSITION_TOY_TRAIN)
        EVT_CASE_EQ(2)
            EVT_CALL(GotoMapSpecial, EVT_PTR("omo_08"), omo_08_ENTRY_2, TRANSITION_TOY_TRAIN)
        EVT_CASE_EQ(3)
            EVT_CALL(GotoMapSpecial, EVT_PTR("omo_10"), omo_10_ENTRY_3, TRANSITION_TOY_TRAIN)
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrainUnk_G) = {
    EVT_SWITCH(AB_OMO_5)
        EVT_CASE_RANGE(0, 1)
            EVT_SWITCH(AB_OMO_6)
                EVT_CASE_EQ(0)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                EVT_CASE_EQ(1)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_06"), omo_06_ENTRY_2, TRANSITION_TOY_TRAIN)
                EVT_CASE_EQ(2)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_08"), omo_08_ENTRY_1, TRANSITION_TOY_TRAIN)
                EVT_CASE_EQ(3)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_10"), omo_10_ENTRY_2, TRANSITION_TOY_TRAIN)
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
            EVT_SWITCH(AB_OMO_6)
                EVT_CASE_EQ(0)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                EVT_CASE_EQ(1)
                    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, TRUE)
                        EVT_CALL(GotoMapSpecial, EVT_PTR("omo_06"), omo_06_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EVT_ELSE
                        EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EVT_END_IF
                EVT_CASE_EQ(3)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_10"), omo_10_ENTRY_2, TRANSITION_TOY_TRAIN)
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_SWITCH(AB_OMO_6)
                EVT_CASE_EQ(0)
                    EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                EVT_CASE_EQ(1)
                    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, TRUE)
                        EVT_CALL(GotoMapSpecial, EVT_PTR("omo_06"), omo_06_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EVT_ELSE
                        EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EVT_END_IF
                EVT_CASE_EQ(2)
                    EVT_IF_EQ(GF_OMO03_BlueSwitchActivated, TRUE)
                        EVT_CALL(GotoMapSpecial, EVT_PTR("omo_08"), omo_08_ENTRY_1, TRANSITION_TOY_TRAIN)
                    EVT_ELSE
                        EVT_CALL(GotoMapSpecial, EVT_PTR("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EVT_END_IF
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrainUnk_H) = {
    EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_CALL(N(IsAOrBPressed))
        EVT_IF_NE(LVar0, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
        EVT_EXEC_WAIT(N(EVS_TrainUnk_F))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_TrainUnk_G))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
