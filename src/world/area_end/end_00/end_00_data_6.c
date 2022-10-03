#include "end_00.h"

#include "world/common/PlayFX3D.inc.c"

EvtScript N(D_80247BB0_DFE5B0) = {
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

EvtScript N(D_80247CF8_DFE6F8) = {
    EVT_CALL(EnableNpcShadow, NPC_17, FALSE)
    EVT_WAIT(150)
    EVT_CALL(GetNpcPos, NPC_17, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(100)
    EVT_CALL(SetNpcAnimation, NPC_17, ANIM_KoopaBros_Red_Anim20)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_17, ANIM_KoopaBros_Red_Anim0E)
    EVT_CALL(SetNpcJumpscale, NPC_17, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_17, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_17, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_17, ANIM_KoopaBros_Red_Anim0F)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247E4C_DFE84C) = {
    EVT_CALL(EnableNpcShadow, NPC_18, FALSE)
    EVT_WAIT(155)
    EVT_CALL(GetNpcPos, NPC_18, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(95)
    EVT_CALL(SetNpcAnimation, NPC_18, ANIM_KoopaBros_Black_Anim20)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_18, ANIM_KoopaBros_Black_Anim0E)
    EVT_CALL(SetNpcJumpscale, NPC_18, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_18, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_18, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_18, ANIM_KoopaBros_Black_Anim0F)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247FA0_DFE9A0) = {
    EVT_CALL(EnableNpcShadow, NPC_19, FALSE)
    EVT_WAIT(160)
    EVT_CALL(GetNpcPos, NPC_19, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(90)
    EVT_CALL(SetNpcAnimation, NPC_19, ANIM_KoopaBros_Yellow_Anim20)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_19, ANIM_KoopaBros_Yellow_Anim0E)
    EVT_CALL(SetNpcJumpscale, NPC_19, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_19, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_19, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_19, ANIM_KoopaBros_Yellow_Anim0F)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802480F4_DFEAF4) = {
    EVT_CALL(EnableNpcShadow, NPC_1A, FALSE)
    EVT_WAIT(165)
    EVT_CALL(GetNpcPos, NPC_1A, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(85)
    EVT_CALL(SetNpcAnimation, NPC_1A, ANIM_KoopaBros_Green_Anim20)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_1A, ANIM_KoopaBros_Green_Anim0E)
    EVT_CALL(SetNpcJumpscale, NPC_1A, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_1A, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_1A, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_1A, ANIM_KoopaBros_Green_Anim0F)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248248_DFEC48) = {
    EVT_CALL(SetNpcFlagBits, NPC_1B, NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_1B, -1900, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_1B, ANIM_Bobomb_Anim0B)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_1B, ANIM_Bobomb_Anim14)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_1B, ANIM_Bobomb_Anim16)
    EVT_CALL(GetNpcPos, NPC_1B, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2, 0, 0, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_1B, FALSE)
    EVT_CALL(NpcFlyTo, NPC_1B, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_1B, -1870, 200, 40)
    EVT_CALL(NpcFlyTo, NPC_1B, -1870, 12, 40, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_1B, 270)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_1B, ANIM_Bobomb_Anim17)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248400_DFEE00) = {
    EVT_CALL(SetNpcFlagBits, NPC_1C, NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_1C, -1870, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_Bobomb_Anim0B)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_Bobomb_Anim14)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_Bobomb_Anim16)
    EVT_CALL(GetNpcPos, NPC_1C, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2, 0, 0, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_1C, FALSE)
    EVT_CALL(NpcFlyTo, NPC_1C, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_1C, -1860, 200, 13)
    EVT_CALL(NpcFlyTo, NPC_1C, -1860, 65, 13, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_1C, 270)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_Bobomb_Anim17)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802485B8_DFEFB8) = {
    EVT_CALL(SetNpcFlagBits, NPC_1D, NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_1D, -1840, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_Bobomb_Anim0B)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_Bobomb_Anim14)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_Bobomb_Anim16)
    EVT_CALL(GetNpcPos, NPC_1D, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2, 0, 0, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_1D, FALSE)
    EVT_CALL(NpcFlyTo, NPC_1D, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_1D, -1840, 200, 13)
    EVT_CALL(NpcFlyTo, NPC_1D, -1840, 65, 13, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_1D, 90)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_Bobomb_Anim17)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248770_DFF170) = {
    EVT_CALL(SetNpcFlagBits, NPC_1E, NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_8000, TRUE)
    EVT_WAIT(180)
    EVT_CALL(NpcMoveTo, NPC_1E, -1810, 43, 70)
    EVT_CALL(SetNpcAnimation, NPC_1E, ANIM_Bobomb_Anim0B)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_1E, ANIM_Bobomb_Anim14)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_1E, ANIM_Bobomb_Anim16)
    EVT_CALL(GetNpcPos, NPC_1E, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2, 0, 0, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_1E, FALSE)
    EVT_CALL(NpcFlyTo, NPC_1E, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_1E, -1830, 200, 40)
    EVT_CALL(NpcFlyTo, NPC_1E, -1830, 12, 40, 20, 0, EASING_LINEAR)
    EVT_CALL(SetNpcYaw, NPC_1E, 90)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_1E, ANIM_Bobomb_Anim17)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80248928) = {
    EVT_EXEC_GET_TID(N(D_80247BB0_DFE5B0), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF7EA)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_EXEC(N(D_80247CF8_DFE6F8))
    EVT_EXEC(N(D_80247E4C_DFE84C))
    EVT_EXEC(N(D_80247FA0_DFE9A0))
    EVT_EXEC(N(D_802480F4_DFEAF4))
    EVT_EXEC(N(D_80248248_DFEC48))
    EVT_EXEC(N(D_80248400_DFEE00))
    EVT_EXEC(N(D_802485B8_DFEFB8))
    EVT_EXEC(N(D_80248770_DFF170))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF9C0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248A78_DFF478) = {
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

EvtScript N(EVS_80248BAC) = {
    EVT_EXEC_GET_TID(N(D_80248A78_DFF478), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF9CA)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar1, 15)
    EVT_CALL(N(PlayFX3D), 0, 0xFFFFF9E3, LVar1, -200, 0, -1, 0, 30)
    EVT_CALL(GetNpcPos, NPC_1F, LVar2, LVar3, LVar4)
    EVT_CALL(GetNpcPos, NPC_20, LVar5, LVar6, LVar7)
    EVT_LOOP(5)
        EVT_ADD(LVar3, 8)
        EVT_CALL(SetNpcPos, NPC_1F, LVar2, LVar3, LVar4)
        EVT_ADD(LVar6, 8)
        EVT_CALL(SetNpcPos, NPC_20, LVar5, LVar6, LVar7)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_1F, ANIM_ParadeKolorado_Wave)
    EVT_CALL(SetNpcAnimation, NPC_20, ANIM_ParadeKolorado_WifeWave)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_LOOP(20)
                EVT_SUB(LVar1, 1)
                EVT_CALL(N(UpdatePosFX3D), LVar0, 0xFFFFF9E3, LVar1, -200)
                EVT_SUB(LVar3, 1)
                EVT_CALL(SetNpcPos, NPC_1F, LVar2, LVar3, LVar4)
                EVT_SUB(LVar6, 1)
                EVT_CALL(SetNpcPos, NPC_20, LVar5, LVar6, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(20)
                EVT_ADD(LVar1, 1)
                EVT_CALL(N(UpdatePosFX3D), LVar0, 0xFFFFF9E3, LVar1, -200)
                EVT_ADD(LVar3, 1)
                EVT_CALL(SetNpcPos, NPC_1F, LVar2, LVar3, LVar4)
                EVT_ADD(LVar6, 1)
                EVT_CALL(SetNpcPos, NPC_20, LVar5, LVar6, LVar7)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(LVar3, LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFB5A)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(N(DisposeFX3D), LVar3)
    EVT_KILL_THREAD(LVarA)
    EVT_RETURN
    EVT_END
};
