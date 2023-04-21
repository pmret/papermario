#include "end_00.h"
#include "effects.h"

s32 N(UnusedAlpha) = 255;

API_CALLABLE(N(SetUnusedAlpha)) {
    N(UnusedAlpha) = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MoveBoosToTubbaBody) = {
    EVT_CALL(GetNpcPos, NPC_TubbasBody, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_SETF(LVar4, LVar0)
    EVT_SUBF(LVar3, EVT_FLOAT(25.0))
    EVT_ADDF(LVar4, EVT_FLOAT(25.0))
    EVT_CALL(SetNpcPos, NPC_Boo1, LVar0, 20, 2)
    EVT_CALL(SetNpcPos, NPC_Boo2, LVar3, 20, -2)
    EVT_CALL(SetNpcPos, NPC_Boo3, LVar4, 20, 2)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_Boo1)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_Boo2)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_Boo3)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), 49)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Tutankoopa) = {
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_Tutankoopa2, -960, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_Tutankoopa2, -240, 30, 90 * DT)
        EVT_CALL(SetNpcPos, NPC_Tutankoopa2, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_ChainChomp2, -1020, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_ChainChomp2, -300, 30, 90 * DT)
        EVT_CALL(SetNpcPos, NPC_ChainChomp2, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_ChainChomp3, -1050, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_ChainChomp3, -330, 30, 90 * DT)
        EVT_CALL(SetNpcPos, NPC_ChainChomp3, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_ChainChomp4, -1080, 0, 30)
        EVT_CALL(NpcMoveTo, NPC_ChainChomp4, -360, 30, 90 * DT)
        EVT_CALL(SetNpcPos, NPC_ChainChomp4, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Boos) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -580)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_Bootler, 90, 0)
    EVT_SET(LVar0, NPC_Bootler)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -540)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_CALL(N(SetUnusedAlpha), 255)
    EVT_CALL(SetNpcImgFXParams, NPC_Boo1, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Boo2, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(SetNpcImgFXParams, NPC_Boo3, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_Boo1, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo2, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Boo3, FALSE)
    EVT_CALL(NpcMoveTo, NPC_TubbasBody, -460, 0, 100 * DT)
    EVT_EXEC_GET_TID(N(EVS_MoveBoosToTubbaBody), LVarB)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcPos, NPC_TubbasHeart, -260, 0, 0)
    EVT_CALL(SetNpcJumpscale, NPC_TubbasHeart, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_TubbasHeart, -290, 0, 0, 10 * DT)
    EVT_CALL(NpcJump0, NPC_TubbasHeart, -320, 0, 0, 10 * DT)
    EVT_SET(LVar0, 53)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarC)
    EVT_CALL(InterpNpcYaw, NPC_TubbasBody, 90, 0)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 30 * DT, EASING_LINEAR)
        EVT_LOOP(30 * DT)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcImgFXParams, NPC_Boo1, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_CALL(SetNpcImgFXParams, NPC_Boo2, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_CALL(SetNpcImgFXParams, NPC_Boo3, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableNpcShadow, NPC_Boo1, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_Boo2, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_Boo3, TRUE)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    EVT_CALL(SetNpcAnimation, NPC_Boo1, ANIM_Boo_CarryWalk)
    EVT_CALL(SetNpcAnimation, NPC_Boo2, ANIM_Boo_CarryWalk)
    EVT_CALL(SetNpcAnimation, NPC_Boo3, ANIM_Boo_CarryWalk)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim16)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Bootler, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Talk)
        EVT_CALL(GetNpcPos, NPC_Bootler, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_Bootler, LVar0, LVar2, 60 * DT)
    EVT_END_THREAD
    EVT_KILL_THREAD(LVarB)
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_TubbasBody, 270, 0)
        EVT_CALL(GetNpcPos, NPC_TubbasBody, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_TubbasBody, LVar0, LVar2, 60 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Boo1, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Boo1, ANIM_Boo_Wave)
        EVT_CALL(GetNpcPos, NPC_Boo1, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_Boo1, LVar0, LVar2, 60 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Boo2, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Boo2, ANIM_Boo_Wave)
        EVT_CALL(GetNpcPos, NPC_Boo2, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_Boo2, LVar0, LVar2, 60 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_Boo3, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Boo3, ANIM_Boo_Wave)
        EVT_CALL(GetNpcPos, NPC_Boo3, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 180)
        EVT_CALL(NpcMoveTo, NPC_Boo3, LVar0, LVar2, 60 * DT)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_KILL_THREAD(LVarC)
    EVT_CALL(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B)
    EVT_CALL(GetNpcPos, NPC_TubbasHeart, LVar0, LVar1, LVar2)
    EVT_LOOP(6)
        EVT_SUB(LVar0, 45)
        EVT_CALL(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 15 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_GoombaKing) = {
    EVT_WAIT(1)
    EVT_CALL(SetNpcRotation, NPC_GoombaKing, 0, 0, 180)
    EVT_THREAD
        EVT_LOOP(8)
            EVT_CALL(NpcMoveTo, NPC_RedGoombaBros, -30, -28, 20)
            EVT_CALL(NpcMoveTo, NPC_RedGoombaBros, -110, -28, 20)
        EVT_END_LOOP
        EVT_CALL(NpcMoveTo, NPC_RedGoombaBros, -30, -28, 20)
        EVT_CALL(GetNpcPos, NPC_RedGoombaBros, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_RedGoombaBros, LVar0, LVar1, LVar2, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(8)
            EVT_CALL(NpcMoveTo, NPC_BlueGoombaBros, -110, -32, 20)
            EVT_CALL(NpcMoveTo, NPC_BlueGoombaBros, -30, -32, 20)
        EVT_END_LOOP
        EVT_CALL(NpcMoveTo, NPC_BlueGoombaBros, -110, -32, 20)
        EVT_CALL(GetNpcPos, NPC_BlueGoombaBros, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_BlueGoombaBros, LVar0, LVar1, LVar2, 20)
    EVT_END_THREAD
    EVT_LOOP(16)
        EVT_CALL(ShowSweat, NPC_RedGoombaBros, 0, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_CALL(ShowSweat, NPC_BlueGoombaBros, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_WAIT(10)
        EVT_CALL(ShowSweat, NPC_RedGoombaBros, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_CALL(ShowSweat, NPC_BlueGoombaBros, 0, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_GoombaKing, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_GoombaKing, ANIM_GoombaKing_Dead)
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar1, 80)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2)
    EVT_CALL(SetNpcFlagBits, NPC_GoombaKing, NPC_FLAG_GRAVITY, FALSE)
    EVT_WAIT(60)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_GoombaKing, ANIM_GoombaKing_Angry)
        EVT_CALL(MakeLerp, 180, 360, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_GoombaKing, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_GoombaKing, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, NPC_GoombaKing, LVar0, 0, 0, 20)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_RedGoombaBros, -30, 0, 15)
        EVT_CALL(NpcMoveTo, NPC_RedGoombaBros, -210, 0, 180)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_BlueGoombaBros, -30, 0, 55)
        EVT_CALL(NpcMoveTo, NPC_BlueGoombaBros, -170, 0, 140)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_GoombaKing, -250, 0, 180)
    EVT_RETURN
    EVT_END
};
