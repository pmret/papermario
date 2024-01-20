#include "sam_10.h"
#include "effects.h"

Vec2i N(StaircaseStepsData)[] = {
    { MODEL_1,   -200 },
    { MODEL_2,   -230 },
    { MODEL_3,   -260 },
    { MODEL_4,   -290 },
    { MODEL_5,   -320 },
    { MODEL_6,   -350 },
    { MODEL_7,   -380 },
    { MODEL_8,   -410 },
    { MODEL_9,   -440 },
    { MODEL_10,  -470 },
    { MODEL_11,  -530 },
    { MODEL_12,  -560 },
    { MODEL_13,  -590 },
    { MODEL_14,  -620 },
    { MODEL_15,  -650 },
    { MODEL_16,  -680 },
    { MODEL_17,  -710 },
    { MODEL_18,  -740 },
    { MODEL_19,  -770 },
    { MODEL_20,  -800 },
    { MODEL_21,  -860 },
    { MODEL_22,  -890 },
    { MODEL_23,  -920 },
    { MODEL_24,  -950 },
    { MODEL_25,  -980 },
    { MODEL_26, -1010 },
    { MODEL_27, -1040 },
    { MODEL_28, -1070 },
    { MODEL_29, -1100 },
    { MODEL_30, -1130 },
};

API_CALLABLE(N(GetCamPointsNearPlayer)) {
    script->varTable[0] = gPlayerStatus.pos.x + (sin_deg(310.0f) * 100.0f);
    script->varTable[1] = gPlayerStatus.pos.z - (cos_deg(310.0f) * 100.0f);
    script->varTable[2] = gPlayerStatus.pos.x + (sin_deg(130.0f) * 100.0f);
    script->varTable[3] = gPlayerStatus.pos.z - (cos_deg(130.0f) * 100.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ItemPrompt_StarStoneSocket) = {
    Call(DisablePlayerInput, TRUE)
    Call(FindKeyItem, ITEM_STAR_STONE, LVar0)
    IfNe(LVar0, -1)
        Call(ShowKeyChoicePopup)
        Call(CloseChoicePopup)
        Switch(LVar0)
            CaseEq(0)
                Call(DisablePlayerInput, FALSE)
                Return
            CaseEq(-1)
                Call(DisablePlayerInput, FALSE)
                Return
            CaseDefault
                Call(RemoveKeyItemAt, LVar1)
        EndSwitch
    Else
        Call(ShowMessageAtScreenPos, MSG_Menus_SAM10_PlaceItemTip, 160, 40)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(SetItemPos, MV_StarStoneItemID, -117, 179, -32)
    Call(PlaySoundAt, SOUND_SAM_PLACE_STAR_STONE, SOUND_SPACE_DEFAULT, -117, 179, -32)
    Wait(30)
    Thread
        Call(MakeLerp, -32, -55, 100 * DT, EASING_COS_IN_OUT)
        Label(1)
        Call(UpdateLerp)
        Call(SetItemPos, MV_StarStoneItemID, -117, 179, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    EndThread
    Call(PlaySoundAtCollider, COLLIDER_o61, SOUND_SAM_STAIRS_ACTIVATE, 0)
    Call(MakeLerp, 0, -23, 100 * DT, EASING_COS_IN_OUT)
    Label(2)
    Call(UpdateLerp)
    Call(TranslateGroup, MODEL_g51, 0, 0, LVar0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(2)
    EndIf
    Call(UpdateColliderTransform, COLLIDER_o61)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o89, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(2.0), Float(5.0))
    Call(N(GetCamPointsNearPlayer))
    Call(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    Call(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Call(PlaySound, SOUND_SAM_STAIRS_LOUD_THUD)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(3.0))
    PlayEffect(EFFECT_LANDING_DUST, 3, -20, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 20, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 60, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 100, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 140, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 180, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 220, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 240, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 280, -20, -66, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, -20, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 20, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 60, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 100, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 140, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 180, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 220, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 240, -20, -166, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, 280, -20, -166, 0)
    Wait(20)
    Call(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_move2, MODEL_GROUP_VISIBLE)
    Call(SetGroupVisibility, MODEL_move3, MODEL_GROUP_HIDDEN)
    Call(PlaySound, SOUND_LOOP_SAM_STAIRS_RISE)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 600, Float(0.15))
    EndThread
    Set(LVar2, 0)
    UseBuf(Ref(N(StaircaseStepsData)))
    Loop(30)
        Add(LVar2, 1)
        BufRead2(LVar3, LVar4)
        Thread
            Set(LVar5, LVar4)
            Div(LVar5, -2)
            Call(MakeLerp, LVar4, 0, LVar5, EASING_LINEAR)
            Label(3)
            Call(UpdateLerp)
            Call(TranslateGroup, LVar3, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(3)
            EndIf
            IfEq(LVar2, 30)
                Call(PlaySound, SOUND_SAM_STAIRS_FINAL_THUD)
                Call(StopSound, SOUND_LOOP_SAM_STAIRS_RISE)
                Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(3.0))
                Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(2.0))
                Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
                Set(LVarB, LVar0)
                Call(GetModelCenter, LVar3)
                Set(LVarA, -20)
                Sub(LVarA, LVarB)
            Else
                Call(PlaySoundAt, SOUND_SAM_ICE_STEP_THUD, SOUND_SPACE_DEFAULT, LVar0, LVarA, LVar2)
                Mod(LVar2, 3)
                IfEq(LVar2, 0)
                    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
                EndIf
            EndIf
        EndThread
    EndLoop
    Wait(150)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 140, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(MakeLerp, 150, 1050, 200, EASING_LINEAR)
        Call(UseSettingsFrom, CAM_DEFAULT, 150, 150, -70)
        Label(100)
        Call(UpdateLerp)
        Call(SetPanTarget, CAM_DEFAULT, 150, LVar0, -70)
        Call(SetCamDistance, CAM_DEFAULT, Float(750.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-14.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(100)
        EndIf
    EndThread
    Wait(480)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m1_kabe, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_m2_kabe, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_m2_yuka, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_move2, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_move2, MODEL_GROUP_HIDDEN)
    Call(SetGroupVisibility, MODEL_move3, MODEL_GROUP_VISIBLE)
    Set(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 337.0f, -20.0f, -103.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 2, 135, 11, 1, 10, 30)
    Call(EnableModel, MODEL_a_oku, TRUE)
    Loop(10)
        Call(EnableModel, MODEL_a_kabe, TRUE)
        Call(EnableModel, MODEL_a_hibi, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_a_kabe, FALSE)
        Call(EnableModel, MODEL_a_hibi, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_SAM10_BombedWall, TRUE)
    Unbind
    Return
    End
};

s32 N(StarStoneList)[] = {
    ITEM_STAR_STONE,
    ITEM_NONE
};

EvtScript N(EVS_SetupStairs) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yuka, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o79, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o80, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o81, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o86, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    Call(ParentColliderToModel, COLLIDER_o61, MODEL_kouri)
    IfLt(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
        Call(SetGroupVisibility, MODEL_move2, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_move3, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m2_kabe, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m2_yuka, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_move2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_m1_kabe, SURFACE_TYPE_SNOW)
        UseBuf(Ref(N(StaircaseStepsData)))
        Loop(30)
            BufRead2(LVarA, LVarB)
            Call(TranslateGroup, LVarA, 0, LVarB, 0)
        EndLoop
        BindPadlock(Ref(N(EVS_ItemPrompt_StarStoneSocket)), TRIGGER_WALL_PRESS_A, COLLIDER_o61, Ref(N(StarStoneList)), 0, 1)
    Else
        Call(TranslateGroup, MODEL_g51, 0, 0, -23)
        Call(UpdateColliderTransform, COLLIDER_o61)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o89, COLLIDER_FLAGS_UPPER_MASK)
        Call(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_move2, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m1_kabe, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH7_GOT_STAR_STONE)
        Set(GF_SAM10_BombedWall, TRUE)
    EndIf
    IfEq(GF_SAM10_BombedWall, FALSE)
        Call(EnableModel, MODEL_a_oku, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
    Else
        Call(EnableModel, MODEL_a_kabe, FALSE)
        Call(EnableModel, MODEL_a_hibi, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
