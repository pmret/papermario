#include "end_00.h"

#include "world/common/atomic/WhaleGeyser.inc.c"

EvtScript N(EVS_FakeBowserFloat) = {
    EVT_CALL(EnableModel, MODEL_o81, FALSE)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 15, -15, 30, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -15, 15, 30, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_Red) = {
    EVT_CALL(EnableNpcShadow, NPC_KoopaBrosRed, FALSE)
    EVT_WAIT(150)
    EVT_CALL(GetNpcPos, NPC_KoopaBrosRed, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(100)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ExitShell)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_BurnHurt)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosRed, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_KoopaBrosRed, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_KoopaBrosRed, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_BurnStill)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_Black) = {
    EVT_CALL(EnableNpcShadow, NPC_KoopaBrosBlack, FALSE)
    EVT_WAIT(155)
    EVT_CALL(GetNpcPos, NPC_KoopaBrosBlack, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(95)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlack, ANIM_KoopaBros_Black_ExitShell)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlack, ANIM_KoopaBros_Black_BurnHurt)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosBlack, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_KoopaBrosBlack, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_KoopaBrosBlack, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosBlack, ANIM_KoopaBros_Black_BurnStill)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_Yellow) = {
    EVT_CALL(EnableNpcShadow, NPC_KoopaBrosYellow, FALSE)
    EVT_WAIT(160)
    EVT_CALL(GetNpcPos, NPC_KoopaBrosYellow, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(90)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYellow, ANIM_KoopaBros_Yellow_ExitShell)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYellow, ANIM_KoopaBros_Yellow_BurnHurt)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosYellow, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_KoopaBrosYellow, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_KoopaBrosYellow, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosYellow, ANIM_KoopaBros_Yellow_BurnStill)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_Green) = {
    EVT_CALL(EnableNpcShadow, NPC_KoopaBrosGreen, FALSE)
    EVT_WAIT(165)
    EVT_CALL(GetNpcPos, NPC_KoopaBrosGreen, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(85)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGreen, ANIM_KoopaBros_Green_ExitShell)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGreen, ANIM_KoopaBros_Green_BurnHurt)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBrosGreen, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_KoopaBrosGreen, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_KoopaBrosGreen, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBrosGreen, ANIM_KoopaBros_Green_BurnStill)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Bobomb1) = {
    EVT_CALL(SetNpcFlagBits, NPC_Bobomb1, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_Bobomb1, -1900, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_AngryIdle)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_Buildup)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_FaceFwd)
    EVT_CALL(GetNpcPos, NPC_Bobomb1, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    EVT_CALL(EnableNpcShadow, NPC_Bobomb1, FALSE)
    EVT_CALL(NpcFlyTo, NPC_Bobomb1, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Bobomb1, -1870, 200, 40)
    EVT_CALL(NpcFlyTo, NPC_Bobomb1, -1870, 12, 40, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_Bobomb1, 270)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_WaveFwd)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Bobomb2) = {
    EVT_CALL(SetNpcFlagBits, NPC_Bobomb2, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_Bobomb2, -1870, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_AngryIdle)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_Buildup)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_FaceFwd)
    EVT_CALL(GetNpcPos, NPC_Bobomb2, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    EVT_CALL(EnableNpcShadow, NPC_Bobomb2, FALSE)
    EVT_CALL(NpcFlyTo, NPC_Bobomb2, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Bobomb2, -1860, 200, 13)
    EVT_CALL(NpcFlyTo, NPC_Bobomb2, -1860, 65, 13, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_Bobomb2, 270)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_WaveFwd)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Bobomb3) = {
    EVT_CALL(SetNpcFlagBits, NPC_Bobomb3, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_Bobomb3, -1840, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_AngryIdle)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_Buildup)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_FaceFwd)
    EVT_CALL(GetNpcPos, NPC_Bobomb3, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    EVT_CALL(EnableNpcShadow, NPC_Bobomb3, FALSE)
    EVT_CALL(NpcFlyTo, NPC_Bobomb3, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Bobomb3, -1840, 200, 13)
    EVT_CALL(NpcFlyTo, NPC_Bobomb3, -1840, 65, 13, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_Bobomb3, 90)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_WaveFwd)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Bobomb4) = {
    EVT_CALL(SetNpcFlagBits, NPC_Bobomb4, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_Bobomb4, -1810, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_AngryIdle)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_Buildup)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_FaceFwd)
    EVT_CALL(GetNpcPos, NPC_Bobomb4, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    EVT_CALL(EnableNpcShadow, NPC_Bobomb4, FALSE)
    EVT_CALL(NpcFlyTo, NPC_Bobomb4, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Bobomb4, -1830, 200, 40)
    EVT_CALL(NpcFlyTo, NPC_Bobomb4, -1830, 12, 40, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_Bobomb4, 90)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_WaveFwd)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_KoopaBros) = {
    EVT_EXEC_GET_TID(N(EVS_FakeBowserFloat), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOOPA_BROS + 80)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_KoopaBros_Red))
    EVT_EXEC(N(EVS_KoopaBros_Black))
    EVT_EXEC(N(EVS_KoopaBros_Yellow))
    EVT_EXEC(N(EVS_KoopaBros_Green))
    EVT_EXEC(N(EVS_Bobomb1))
    EVT_EXEC(N(EVS_Bobomb2))
    EVT_EXEC(N(EVS_Bobomb3))
    EVT_EXEC(N(EVS_Bobomb4))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOOPA_BROS + 550)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Whale_WagTail) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 20, -20, 40, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o88, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -20, 20, 40, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o88, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Kolorado) = {
    EVT_EXEC_GET_TID(N(EVS_Whale_WagTail), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOLORADO + 500)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar1, 15)
    EVT_CALL(N(CreateWhaleGeyser), 0, -1565, LVar1, -200, 0, -1, 0, 30)
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
    EVT_CALL(GetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
    EVT_LOOP(5)
        EVT_ADD(LVar3, 8)
        EVT_CALL(SetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
        EVT_ADD(LVar6, 8)
        EVT_CALL(SetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_ParadeKolorado_Wave)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife, ANIM_ParadeKolorado_WifeWave)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_LOOP(20)
                EVT_SUB(LVar1, 1)
                EVT_CALL(N(SetWhaleGeyserPos), LVar0, -1565, LVar1, -200)
                EVT_SUB(LVar3, 1)
                EVT_CALL(SetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
                EVT_SUB(LVar6, 1)
                EVT_CALL(SetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_ADD(LVar1, 1)
                EVT_CALL(N(SetWhaleGeyserPos), LVar0, -1565, LVar1, -200)
                EVT_ADD(LVar3, 1)
                EVT_CALL(SetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
                EVT_ADD(LVar6, 1)
                EVT_CALL(SetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(LVar3, LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOLORADO + 900)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(N(DisposeWhaleGeyser), LVar3)
    EVT_KILL_THREAD(LVarA)
    EVT_RETURN
    EVT_END
};
