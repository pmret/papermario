#include "end_00.h"
#include "effects.h"

s32 N(UnusedAlpha) = 255;

API_CALLABLE(N(SetUnusedAlpha)) {
    N(UnusedAlpha) = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_MoveBoosToTubbaBody) = {
    Call(GetNpcPos, NPC_TubbasBody, LVar0, LVar1, LVar2)
    SetF(LVar0, LVar0)
    SetF(LVar3, LVar0)
    SetF(LVar4, LVar0)
    SubF(LVar3, Float(25.0))
    AddF(LVar4, Float(25.0))
    Call(SetNpcPos, NPC_Boo1, LVar0, 20, 2)
    Call(SetNpcPos, NPC_Boo2, LVar3, 20, -2)
    Call(SetNpcPos, NPC_Boo3, LVar4, 20, 2)
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_Boo1)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_Boo2)
    EndChildThread
    ChildThread
        Call(N(AddScrollToNpcPos), NPC_Boo3)
    EndChildThread
    Call(N(AddScrollToNpcPos), 49)
    Return
    End
};

EvtScript N(EVS_ParadePhase_Tutankoopa) = {
    Thread
        Call(SetNpcPos, NPC_Tutankoopa2, -960, 0, 30)
        Call(NpcMoveTo, NPC_Tutankoopa2, -240, 30, 90 * DT)
        Call(SetNpcPos, NPC_Tutankoopa2, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcPos, NPC_ChainChomp2, -1020, 0, 30)
        Call(NpcMoveTo, NPC_ChainChomp2, -300, 30, 90 * DT)
        Call(SetNpcPos, NPC_ChainChomp2, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcPos, NPC_ChainChomp3, -1050, 0, 30)
        Call(NpcMoveTo, NPC_ChainChomp3, -330, 30, 90 * DT)
        Call(SetNpcPos, NPC_ChainChomp3, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcPos, NPC_ChainChomp4, -1080, 0, 30)
        Call(NpcMoveTo, NPC_ChainChomp4, -360, 30, 90 * DT)
        Call(SetNpcPos, NPC_ChainChomp4, 0, -500, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_ParadePhase_Boos) = {
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, -580)
            BreakLoop
        EndIf
    EndLoop
    Call(InterpNpcYaw, NPC_Bootler, 90, 0)
    Set(LVar0, NPC_Bootler)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarA)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, -540)
            BreakLoop
        EndIf
    EndLoop
    Wait(10 * DT)
    Call(N(SetUnusedAlpha), 255)
    Call(SetNpcImgFXParams, NPC_Boo1, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Boo2, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(SetNpcImgFXParams, NPC_Boo3, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Call(EnableNpcShadow, NPC_Boo1, false)
    Call(EnableNpcShadow, NPC_Boo2, false)
    Call(EnableNpcShadow, NPC_Boo3, false)
    Call(NpcMoveTo, NPC_TubbasBody, -460, 0, 100 * DT)
    ExecGetTID(N(EVS_MoveBoosToTubbaBody), LVarB)
    Wait(20 * DT)
    Call(SetNpcPos, NPC_TubbasHeart, -260, 0, 0)
    Call(SetNpcJumpscale, NPC_TubbasHeart, Float(1.0))
    Call(NpcJump0, NPC_TubbasHeart, -290, 0, 0, 10 * DT)
    Call(NpcJump0, NPC_TubbasHeart, -320, 0, 0, 10 * DT)
    Set(LVar0, 53)
    ExecGetTID(N(EVS_OffsetNpcScroll), LVarC)
    Call(InterpNpcYaw, NPC_TubbasBody, 90, 0)
    Thread
        Call(MakeLerp, 0, 255, 30 * DT, EASING_LINEAR)
        Loop(30 * DT)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_Boo1, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Call(SetNpcImgFXParams, NPC_Boo2, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Call(SetNpcImgFXParams, NPC_Boo3, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
        EndLoop
        Call(EnableNpcShadow, NPC_Boo1, true)
        Call(EnableNpcShadow, NPC_Boo2, true)
        Call(EnableNpcShadow, NPC_Boo3, true)
    EndThread
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Spook)
    Call(SetNpcAnimation, NPC_Boo1, ANIM_Boo_CarryWalk)
    Call(SetNpcAnimation, NPC_Boo2, ANIM_Boo_CarryWalk)
    Call(SetNpcAnimation, NPC_Boo3, ANIM_Boo_CarryWalk)
    Wait(10 * DT)
    Thread
        Loop(6)
            Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim16)
            Wait(5)
            Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B)
            Wait(10)
        EndLoop
    EndThread
    Wait(60 * DT)
    KillThread(LVarA)
    Thread
        Call(InterpNpcYaw, NPC_Bootler, 270, 0)
        Call(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Talk)
        Call(GetNpcPos, NPC_Bootler, LVar0, LVar1, LVar2)
        Sub(LVar0, 180)
        Call(NpcMoveTo, NPC_Bootler, LVar0, LVar2, 60 * DT)
    EndThread
    KillThread(LVarB)
    Thread
        Call(InterpNpcYaw, NPC_TubbasBody, 270, 0)
        Call(GetNpcPos, NPC_TubbasBody, LVar0, LVar1, LVar2)
        Sub(LVar0, 180)
        Call(NpcMoveTo, NPC_TubbasBody, LVar0, LVar2, 60 * DT)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_Boo1, 270, 0)
        Call(SetNpcAnimation, NPC_Boo1, ANIM_Boo_Wave)
        Call(GetNpcPos, NPC_Boo1, LVar0, LVar1, LVar2)
        Sub(LVar0, 180)
        Call(NpcMoveTo, NPC_Boo1, LVar0, LVar2, 60 * DT)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_Boo2, 270, 0)
        Call(SetNpcAnimation, NPC_Boo2, ANIM_Boo_Wave)
        Call(GetNpcPos, NPC_Boo2, LVar0, LVar1, LVar2)
        Sub(LVar0, 180)
        Call(NpcMoveTo, NPC_Boo2, LVar0, LVar2, 60 * DT)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_Boo3, 270, 0)
        Call(SetNpcAnimation, NPC_Boo3, ANIM_Boo_Wave)
        Call(GetNpcPos, NPC_Boo3, LVar0, LVar1, LVar2)
        Sub(LVar0, 180)
        Call(NpcMoveTo, NPC_Boo3, LVar0, LVar2, 60 * DT)
    EndThread
    Wait(30 * DT)
    KillThread(LVarC)
    Call(SetNpcAnimation, NPC_TubbasHeart, ANIM_TubbasHeart_Anim0B)
    Call(GetNpcPos, NPC_TubbasHeart, LVar0, LVar1, LVar2)
    Loop(6)
        Sub(LVar0, 45)
        Call(NpcJump0, NPC_TubbasHeart, LVar0, LVar1, LVar2, 15 * DT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ParadePhase_GoombaKing) = {
    Wait(1)
    Call(SetNpcRotation, NPC_GoombaKing, 0, 0, 180)
    Thread
        Loop(8)
            Call(NpcMoveTo, NPC_RedGoombaBros, -30, -28, 20)
            Call(NpcMoveTo, NPC_RedGoombaBros, -110, -28, 20)
        EndLoop
        Call(NpcMoveTo, NPC_RedGoombaBros, -30, -28, 20)
        Call(GetNpcPos, NPC_RedGoombaBros, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_RedGoombaBros, LVar0, LVar1, LVar2, 20)
    EndThread
    Thread
        Loop(8)
            Call(NpcMoveTo, NPC_BlueGoombaBros, -110, -32, 20)
            Call(NpcMoveTo, NPC_BlueGoombaBros, -30, -32, 20)
        EndLoop
        Call(NpcMoveTo, NPC_BlueGoombaBros, -110, -32, 20)
        Call(GetNpcPos, NPC_BlueGoombaBros, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_BlueGoombaBros, LVar0, LVar1, LVar2, 20)
    EndThread
    Loop(16)
        Call(ShowSweat, NPC_RedGoombaBros, 0, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Call(ShowSweat, NPC_BlueGoombaBros, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Wait(10)
        Call(ShowSweat, NPC_RedGoombaBros, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Call(ShowSweat, NPC_BlueGoombaBros, 0, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Wait(10)
    EndLoop
    Call(SetNpcFlagBits, NPC_GoombaKing, NPC_FLAG_GRAVITY, true)
    Call(SetNpcAnimation, NPC_GoombaKing, ANIM_GoombaKing_Dead)
    Loop(0)
        Call(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
        IfLt(LVar1, 80)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2)
    Call(SetNpcFlagBits, NPC_GoombaKing, NPC_FLAG_GRAVITY, false)
    Wait(60)
    Thread
        Call(SetNpcAnimation, NPC_GoombaKing, ANIM_GoombaKing_Angry)
        Call(MakeLerp, 180, 360, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_GoombaKing, 0, 0, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(GetNpcPos, NPC_GoombaKing, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_GoombaKing, Float(0.5))
    Call(NpcJump0, NPC_GoombaKing, LVar0, 0, 0, 20)
    Wait(30)
    Thread
        Call(NpcMoveTo, NPC_RedGoombaBros, -30, 0, 15)
        Call(NpcMoveTo, NPC_RedGoombaBros, -210, 0, 180)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_BlueGoombaBros, -30, 0, 55)
        Call(NpcMoveTo, NPC_BlueGoombaBros, -170, 0, 140)
    EndThread
    Call(NpcMoveTo, NPC_GoombaKing, -250, 0, 180)
    Return
    End
};
