#include "end_00.h"
#include "effects.h"

extern s32 N(D_80249D60_E00760);

extern EvtScript N(EVS_802447F4);

API_CALLABLE(N(func_80242898_DF9298));

ApiStatus N(func_80242B10_DF9510)(Evt *script, s32 isInitialCall) {
    N(D_80249D60_E00760) = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

EvtScript N(D_80248F30_DFF930) = {
    EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_SETF(LVar1, LVar1)
    EVT_LOOP(0)
        EVT_ADDF(LVar1, EVT_FLOAT(0.87))
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80248FB8) = {
    EVT_CALL(GetNpcPos, NPC_23, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_LOOP(0)
        EVT_ADDF(LVar0, EVT_FLOAT(0.87))
        EVT_CALL(SetNpcPos, NPC_23, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80249040) = {
    EVT_CALL(SetNpcScale, NPC_22, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(0.75))
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_21, -1447, -2, 200)
        EVT_SET(LVar0, 33)
        EVT_EXEC_GET_TID(N(D_80248F30_DFF930), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedIdle)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedTalk)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedCheer)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedIdle)
        EVT_WAIT(60)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedTalk)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedCheer)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedIdle)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_21, ANIM_Rowf_PackedWalk)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_21, -785, -2, 300)
        EVT_CALL(SetNpcPos, NPC_21, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_22, -1412, -2, 200)
        EVT_SET(LVar0, 34)
        EVT_EXEC_GET_TID(N(D_80248F30_DFF930), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_22, ANIM_Rowf_PackedIdle)
        EVT_WAIT(220)
        EVT_CALL(SetNpcAnimation, NPC_22, ANIM_Rowf_PackedWalk)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_22, -750, -2, 300)
        EVT_CALL(SetNpcPos, NPC_22, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_23, -1380, 2, 180)
        EVT_SET(LVar0, 35)
        EVT_EXEC_GET_TID(N(D_80248F30_DFF930), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Idle)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Toss)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Shout)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Talk)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_23, 90, 0)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Shout)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Talk)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_23, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Shout)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Talk)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Toss)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Idle)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_23, ANIM_Moustafa_Run)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_23, -1360, 2, 180)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(NpcMoveTo, NPC_24, -1342, 2, 180)
        EVT_SET(LVar0, 36)
        EVT_EXEC_GET_TID(N(D_80248F30_DFF930), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_24, ANIM_Mouser_Blue_IdleOnlyBlink)
        EVT_WAIT(110)
        EVT_CALL(SetNpcAnimation, NPC_24, ANIM_Mouser_Blue_Whisper)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_24, ANIM_Mouser_Blue_IdleOnlyBlink)
        EVT_WAIT(90)
        EVT_CALL(SetNpcAnimation, NPC_24, ANIM_Mouser_Blue_Run)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_24, -1330, 2, 180)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(NpcMoveTo, NPC_25, -1312, 2, 180)
        EVT_SET(LVar0, 37)
        EVT_EXEC_GET_TID(N(D_80248F30_DFF930), LVarA)
        EVT_CALL(SetNpcAnimation, NPC_25, ANIM_Mouser_Blue_IdleOnlyBlink)
        EVT_WAIT(230)
        EVT_CALL(SetNpcAnimation, NPC_25, ANIM_Mouser_Blue_Run)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(NpcMoveTo, NPC_25, -1300, 2, 180)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(240)
        EVT_CALL(NpcMoveTo, NPC_26, -1540, 30, 60)
        EVT_WAIT(210)
        EVT_CALL(SetNpcPos, NPC_26, -1350, 0, 30)
        EVT_CALL(SetNpcYaw, NPC_26, 90)
        EVT_CALL(NpcMoveTo, NPC_26, -1110, 30, 30)
        EVT_CALL(SetNpcAnimation, NPC_26, ANIM_Tutankoopa_Anim09)
        EVT_CALL(MakeLerp, 0, 90, 5, EASING_LINEAR)
        EVT_LOOP(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_26, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(ShowEmote, NPC_26, EMOTE_ELLIPSIS, 0, 60, TRUE, 0, 0, 0, 0)
        EVT_WAIT(60)
        EVT_CALL(MakeLerp, 90, 0, 5, EASING_LINEAR)
        EVT_LOOP(5)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_26, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_26, ANIM_Tutankoopa_Anim01)
        EVT_CALL(InterpNpcYaw, NPC_26, 270, 7)
        EVT_WAIT(15)
        EVT_CALL(InterpNpcYaw, NPC_26, 90, 7)
        EVT_WAIT(15)
        EVT_CALL(InterpNpcYaw, NPC_26, 270, 7)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_26, ANIM_Tutankoopa_Anim04)
        EVT_CALL(SetNpcJumpscale, NPC_26, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_26, -1140, 0, 30, 15)
        EVT_CALL(NpcJump0, NPC_26, -1170, 0, 30, 15)
        EVT_CALL(NpcJump0, NPC_26, -1200, 0, 30, 15)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(240)
        EVT_CALL(NpcMoveTo, NPC_27, -1480, 30, 60)
        EVT_WAIT(210)
        EVT_CALL(SetNpcPos, NPC_27, -1410, 0, 30)
        EVT_CALL(SetNpcYaw, NPC_27, 90)
        EVT_CALL(NpcMoveTo, NPC_27, -690, 30, 90)
        EVT_CALL(SetNpcPos, NPC_27, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

Vec3f N(D_802499FC_E003FC)[] = {
    { -805.0,   100.0,  -80.0 },
    { -675.0,   100.0, -230.0 },
    { -805.0,   100.0, -280.0 },
    { -935.0,   100.0, -230.0 },
    { -805.0,   100.0,  -80.0 },
};

EvtScript N(EVS_80249A38) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFB64)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(200)
    EVT_CALL(ShowEmote, NPC_28, EMOTE_SHOCK, 45, 30, TRUE, 0, 0, 0, 0)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_28, ANIM_Buzzar_Anim03)
    EVT_CALL(NpcFlyTo, NPC_28, -855, 100, -180, 60, 0, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_29, ANIM_ParadeChick_EggTremble)
    EVT_CALL(SetNpcAnimation, NPC_2A, ANIM_ParadeChick_EggTremble)
    EVT_CALL(SetNpcAnimation, NPC_2B, ANIM_ParadeChick_EggTremble)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_29, ANIM_ParadeChick_BreakEgg)
    EVT_CALL(SetNpcAnimation, NPC_2A, ANIM_ParadeChick_BreakEggFwd)
    EVT_CALL(SetNpcAnimation, NPC_2B, ANIM_ParadeChick_BreakEgg)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_29, ANIM_ParadeChick_Chirp)
    EVT_CALL(SetNpcAnimation, NPC_2A, ANIM_ParadeChick_ChirpFwd)
    EVT_CALL(SetNpcAnimation, NPC_2B, ANIM_ParadeChick_Chirp)
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_28, 90, 0)
    EVT_CALL(NpcFlyTo, NPC_28, -805, 100, -80, 30, 0, EASING_LINEAR)
    EVT_THREAD
        EVT_LOOP(6)
            EVT_WAIT(20)
            EVT_CALL(InterpNpcYaw, NPC_28, 270, 0)
            EVT_WAIT(40)
            EVT_CALL(InterpNpcYaw, NPC_28, 90, 0)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(LoadPath, 80, EVT_PTR(N(D_802499FC_E003FC)), 5, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(GetNextPathPos)
                EVT_CALL(SetNpcPos, NPC_28, LVar1, LVar2, LVar3)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

s32 N(D_80249D60_E00760) = 255;

EvtScript N(D_80249D64_E00764) = {
    EVT_CALL(GetNpcPos, NPC_31, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_SETF(LVar4, LVar0)
    EVT_SUBF(LVar3, EVT_FLOAT(25.0))
    EVT_ADDF(LVar4, EVT_FLOAT(25.0))
    EVT_CALL(SetNpcPos, NPC_32, LVar0, 20, 2)
    EVT_CALL(SetNpcPos, NPC_33, LVar3, 20, -2)
    EVT_CALL(SetNpcPos, NPC_34, LVar4, 20, 2)
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242898_DF9298), 50)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242898_DF9298), 51)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242898_DF9298), 52)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(func_80242898_DF9298), 49)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80249EA4) = {
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_2D, -960, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_2D, -240, 30, 90)
        EVT_CALL(SetNpcPos, NPC_2D, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_2E, -1020, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_2E, -300, 30, 90)
        EVT_CALL(SetNpcPos, NPC_2E, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_2F, -1050, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_2F, -330, 30, 90)
        EVT_CALL(SetNpcPos, NPC_2F, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_30, -1080, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_30, -360, 30, 90)
        EVT_CALL(SetNpcPos, NPC_30, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024A044) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -580)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_2C, 90, 0)
    EVT_SET(LVar0, 44)
    EVT_EXEC_GET_TID(N(EVS_802447F4), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -540)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(N(func_80242B10_DF9510), 255)
    EVT_CALL(func_802CFD30, 50, 7, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, 51, 7, 0, 0, 0, 0)
    EVT_CALL(func_802CFD30, 52, 7, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_32, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_33, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_34, FALSE)
    EVT_CALL(NpcMoveTo, NPC_31, -460, 0, 100)
    EVT_EXEC_GET_TID(N(D_80249D64_E00764), LVarB)
    EVT_WAIT(20)
    EVT_CALL(SetNpcPos, NPC_35, -260, 0, 0)
    EVT_CALL(SetNpcJumpscale, NPC_35, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_35, -290, 0, 0, 10)
    EVT_CALL(NpcJump0, NPC_35, -320, 0, 0, 10)
    EVT_SET(LVar0, 53)
    EVT_EXEC_GET_TID(N(EVS_802447F4), LVarC)
    EVT_CALL(InterpNpcYaw, NPC_31, 90, 0)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
        EVT_LOOP(30)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, 50, 7, LVar0, 0, 0, 0)
            EVT_CALL(func_802CFD30, 51, 7, LVar0, 0, 0, 0)
            EVT_CALL(func_802CFD30, 52, 7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableNpcShadow, NPC_32, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_33, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_34, TRUE)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_35, ANIM_TubbasHeart_Anim0B)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_2C, ANIM_Bootler_Spook)
    EVT_CALL(SetNpcAnimation, NPC_32, ANIM_Boo_CarryWalk)
    EVT_CALL(SetNpcAnimation, NPC_33, ANIM_Boo_CarryWalk)
    EVT_CALL(SetNpcAnimation, NPC_34, ANIM_Boo_CarryWalk)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(SetNpcAnimation, NPC_35, ANIM_TubbasHeart_Anim16)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, NPC_35, ANIM_TubbasHeart_Anim0B)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_2C, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_2C, ANIM_Bootler_Talk)
        EVT_CALL(GetNpcPos, NPC_2C, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_2C, LVar0, LVar2, 60)
    EVT_END_THREAD
    EVT_KILL_THREAD(LVarB)
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_31, 270, 0)
        EVT_CALL(GetNpcPos, NPC_31, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_31, LVar0, LVar2, 60)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_32, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_32, ANIM_Boo_Wave)
        EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_32, LVar0, LVar2, 60)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_33, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_33, ANIM_Boo_Wave)
        EVT_CALL(GetNpcPos, NPC_33, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_33, LVar0, LVar2, 60)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_34, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_34, ANIM_Boo_Wave)
        EVT_CALL(GetNpcPos, NPC_34, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_34, LVar0, LVar2, 60)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_KILL_THREAD(LVarC)
    EVT_CALL(SetNpcAnimation, NPC_35, ANIM_TubbasHeart_Anim0B)
    EVT_CALL(GetNpcPos, NPC_35, LVar0, LVar1, LVar2)
    EVT_LOOP(6)
        EVT_SUB(LVar0, 45)
        EVT_CALL(NpcJump0, NPC_35, LVar0, LVar1, LVar2, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024A804) = {
    EVT_WAIT(1)
    EVT_CALL(SetNpcRotation, NPC_36, 0, 0, 180)
    EVT_THREAD
        EVT_LOOP(8)
            EVT_CALL(NpcMoveTo, NPC_37, -30, -28, 20)
            EVT_CALL(NpcMoveTo, NPC_37, -110, -28, 20)
        EVT_END_LOOP
        EVT_CALL(NpcMoveTo, NPC_37, -30, -28, 20)
        EVT_CALL(GetNpcPos, NPC_37, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_37, LVar0, LVar1, LVar2, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(8)
            EVT_CALL(NpcMoveTo, NPC_38, -110, -32, 20)
            EVT_CALL(NpcMoveTo, NPC_38, -30, -32, 20)
        EVT_END_LOOP
        EVT_CALL(NpcMoveTo, NPC_38, -110, -32, 20)
        EVT_CALL(GetNpcPos, NPC_38, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_38, LVar0, LVar1, LVar2, 20)
    EVT_END_THREAD
    EVT_LOOP(16)
        EVT_CALL(ShowSweat, NPC_37, 0, 45, 1, 0, 0, 0, 0, 20)
        EVT_CALL(ShowSweat, NPC_38, 0, -45, 1, 0, 0, 0, 0, 20)
        EVT_WAIT(10)
        EVT_CALL(ShowSweat, NPC_37, 0, -45, 1, 0, 0, 0, 0, 20)
        EVT_CALL(ShowSweat, NPC_38, 0, 45, 1, 0, 0, 0, 0, 20)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_36, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_36, ANIM_GoombaKing_Dead)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_36, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, 80)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcFlagBits, NPC_36, NPC_FLAG_GRAVITY, FALSE)
    EVT_WAIT(60)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_36, ANIM_GoombaKing_Angry)
        EVT_CALL(MakeLerp, 180, 360, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_36, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_36, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_36, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_36, LVar0, 0, 0, 20)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_37, -30, 0, 15)
        EVT_CALL(NpcMoveTo, NPC_37, -210, 0, 180)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_38, -30, 0, 55)
        EVT_CALL(NpcMoveTo, NPC_38, -170, 0, 140)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_36, -250, 0, 180)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024AD30) = {
    EVT_CHILD_THREAD
        EVT_CALL(EnableTexPanning, MODEL_o119, TRUE)
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 512)
            EVT_CALL(SetTexPanOffset, 4, 1, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(SetNpcScale, NPC_3E, EVT_FLOAT(2.0), EVT_FLOAT(2.0), 1)
        EVT_LOOP(0)
            EVT_CALL(NpcFlyTo, NPC_3E, 357, 0, -30, 10, 0, EASING_LINEAR)
            EVT_WAIT(60)
            EVT_CALL(NpcFlyTo, NPC_3E, 357, -120, -30, 10, 0, EASING_LINEAR)
            EVT_WAIT(60)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(GetNpcPos, NPC_3F, LVar0, LVar1, LVar2)
        EVT_LOOP(0)
            EVT_WAIT(60)
            EVT_LOOP(10)
                EVT_ADD(LVar0, 5)
                EVT_ADD(LVar1, 5)
                EVT_CALL(SetNpcPos, NPC_3F, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(60)
            EVT_LOOP(10)
                EVT_SUB(LVar0, 5)
                EVT_SUB(LVar1, 5)
                EVT_CALL(SetNpcPos, NPC_3F, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 800)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
