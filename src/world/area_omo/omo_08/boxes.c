#include "omo_08.h"
#include "effects.h"

extern EvtScript N(EVS_HitBox);

enum {
    BOX_COLOR_GREEN     = 0,
    BOX_COLOR_YELLOW    = 1,
    BOX_COLOR_RED       = 2,
    BOX_COLOR_BLUE      = 3,
};

#define BOX_SEQUENCE(a, b, c, d) (a << 6 | b << 4 | c << 2 | d)

s32 N(GreenBoxInfo)[] = {
    BOX_COLOR_GREEN,
    MODEL_bm1_2, MODEL_b1_2,
    MODEL_bm1_1, MODEL_b1_1,
};

s32 N(YellowBoxInfo)[] = {
    BOX_COLOR_YELLOW,
    MODEL_bm2_2, MODEL_b2_2,
    MODEL_bm2_1, MODEL_b2_1,
};

s32 N(RedBoxInfo)[] = {
    BOX_COLOR_RED,
    MODEL_bm3_2, MODEL_b3_2,
    MODEL_bm3_1, MODEL_b3_1,
};

s32 N(BlueBoxInfo)[] = {
    BOX_COLOR_BLUE,
    MODEL_bm4_2, MODEL_b4_2,
    MODEL_bm4_1, MODEL_b4_1,
};

EvtScript N(EVS_GreenLightOff) = {
    Call(EnableModel, MODEL_bm1_1, TRUE)
    Call(EnableModel, MODEL_b1_1, TRUE)
    Call(EnableModel, MODEL_bm1_2, FALSE)
    Call(EnableModel, MODEL_b1_2, FALSE)
    Return
    End
};

EvtScript N(EVS_YellowLightOff) = {
    Call(EnableModel, MODEL_bm2_1, TRUE)
    Call(EnableModel, MODEL_b2_1, TRUE)
    Call(EnableModel, MODEL_bm2_2, FALSE)
    Call(EnableModel, MODEL_b2_2, FALSE)
    Return
    End
};

EvtScript N(EVS_RedLightOff) = {
    Call(EnableModel, MODEL_bm3_1, TRUE)
    Call(EnableModel, MODEL_b3_1, TRUE)
    Call(EnableModel, MODEL_bm3_2, FALSE)
    Call(EnableModel, MODEL_b3_2, FALSE)
    Return
    End
};

EvtScript N(EVS_BlueLightOff) = {
    Call(EnableModel, MODEL_bm4_1, TRUE)
    Call(EnableModel, MODEL_b4_1, TRUE)
    Call(EnableModel, MODEL_bm4_2, FALSE)
    Call(EnableModel, MODEL_b4_2, FALSE)
    Return
    End
};

EvtScript N(EVS_GreenLightOn) = {
    Call(EnableModel, MODEL_bm1_1, FALSE)
    Call(EnableModel, MODEL_b1_1, FALSE)
    Call(EnableModel, MODEL_bm1_2, TRUE)
    Call(EnableModel, MODEL_b1_2, TRUE)
    Return
    End
};

EvtScript N(EVS_YellowLightOn) = {
    Call(EnableModel, MODEL_bm2_1, FALSE)
    Call(EnableModel, MODEL_b2_1, FALSE)
    Call(EnableModel, MODEL_bm2_2, TRUE)
    Call(EnableModel, MODEL_b2_2, TRUE)
    Return
    End
};

EvtScript N(EVS_RedLightOn) = {
    Call(EnableModel, MODEL_bm3_1, FALSE)
    Call(EnableModel, MODEL_b3_1, FALSE)
    Call(EnableModel, MODEL_bm3_2, TRUE)
    Call(EnableModel, MODEL_b3_2, TRUE)
    Return
    End
};

EvtScript N(EVS_BlueLightOn) = {
    Call(EnableModel, MODEL_bm4_1, FALSE)
    Call(EnableModel, MODEL_b4_1, FALSE)
    Call(EnableModel, MODEL_bm4_2, TRUE)
    Call(EnableModel, MODEL_b4_2, TRUE)
    Return
    End
};

EvtScript N(EVS_ResetBoxesAfterAmbush) = {
    // wait for all shy guys to be defeated
    Label(0)
        Call(GetNpcPos, NPC_ShyGuy_01, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_ShyGuy_02, LVar0, LVar2, LVar3)
        Call(GetNpcPos, NPC_ShyGuy_03, LVar0, LVar3, LVar4)
        Call(GetNpcPos, NPC_ShyGuy_04, LVar0, LVar4, LVar5)
        Add(LVar1, LVar2)
        Add(LVar1, LVar3)
        Add(LVar1, LVar4)
        IfNe(LVar1, 4 * NPC_DISPOSE_POS_Y)
            Wait(1)
            Goto(0)
        EndIf
    Thread
        Exec(N(EVS_GreenLightOff))
        Call(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm1_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm1_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(2)
    Thread
        Exec(N(EVS_YellowLightOff))
        Call(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm2_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm2_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(3)
    Thread
        Exec(N(EVS_RedLightOff))
        Call(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm3_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm3_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(3)
    Exec(N(EVS_BlueLightOff))
    Call(MakeLerp, 90, 0, 10, EASING_COS_IN_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_bm4_2, LVar0, -1, 0, 0)
        Call(RotateModel, MODEL_bm4_1, LVar0, -1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Set(MV_BoxHitSequence, 0)
    Set(MV_BoxHitCount, 0)
    Call(EnableModel, MODEL_bm1_2, FALSE)
    Call(EnableModel, MODEL_b1_2, FALSE)
    Set(LVar0, Ref(N(GreenBoxInfo)))
    BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o907, 1, 0)
    Call(EnableModel, MODEL_bm2_2, FALSE)
    Call(EnableModel, MODEL_b2_2, FALSE)
    Set(LVar0, Ref(N(YellowBoxInfo)))
    BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o911, 1, 0)
    Call(EnableModel, MODEL_bm3_2, FALSE)
    Call(EnableModel, MODEL_b3_2, FALSE)
    Set(LVar0, Ref(N(RedBoxInfo)))
    BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o915, 1, 0)
    Call(EnableModel, MODEL_bm4_2, FALSE)
    Call(EnableModel, MODEL_b4_2, FALSE)
    Set(LVar0, Ref(N(BlueBoxInfo)))
    BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o918, 1, 0)
    Return
    End
};

EvtScript N(EVS_BoxResult_GiveCoins) = {
    Set(LVar0, 4)
    Loop(3)
        Exec(N(EVS_GreenLightOff))
        Wait(LVar0)
        Exec(N(EVS_YellowLightOff))
        Wait(LVar0)
        Exec(N(EVS_RedLightOff))
        Wait(LVar0)
        Exec(N(EVS_BlueLightOff))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_CHIME_2, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_GreenLightOn))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_CHIME_1, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_YellowLightOn))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_CHIME_3, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_RedLightOn))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_CHIME_4, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_BlueLightOn))
        Wait(LVar0)
        Sub(LVar0, 1)
    EndLoop
    Wait(4)
    Set(LVar0, 4)
    Loop(3)
        Exec(N(EVS_GreenLightOff))
        Exec(N(EVS_YellowLightOff))
        Exec(N(EVS_RedLightOff))
        Exec(N(EVS_BlueLightOff))
        Wait(LVar0)
        Call(PlaySound, SOUND_OMO_BOX_DONE)
        Exec(N(EVS_GreenLightOn))
        Exec(N(EVS_YellowLightOn))
        Exec(N(EVS_RedLightOn))
        Exec(N(EVS_BlueLightOn))
        Wait(LVar0)
        Sub(LVar0, 1)
    EndLoop
    Wait(2)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm1_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm1_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_b1_1)
        Call(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
    EndThread
    Wait(3)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm2_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm2_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_b2_1)
        Call(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
    EndThread
    Wait(3)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm3_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm3_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_b3_1)
        Call(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
    EndThread
    Wait(3)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm4_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm4_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_b4_1)
        Call(MakeItemEntity, ITEM_COIN, LVar0, 40, LVar2, ITEM_SPAWN_MODE_BATTLE_REWARD, 0)
        Wait(20)
        Call(ResetCam, CAM_DEFAULT, 2)
    EndThread
    Return
    End
};

EvtScript N(EVS_BoxResult_RepairTrack) = {
    Call(DisablePlayerInput, TRUE)
    Loop(4)
        Exec(N(EVS_GreenLightOff))
        Wait(3)
        Exec(N(EVS_YellowLightOff))
        Wait(3)
        Exec(N(EVS_RedLightOff))
        Wait(3)
        Exec(N(EVS_BlueLightOff))
        Wait(3)
        Call(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_CHIME_2, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_GreenLightOn))
        Wait(3)
        Call(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_CHIME_1, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_YellowLightOn))
        Wait(3)
        Call(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_CHIME_3, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_RedLightOn))
        Wait(3)
        Call(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_CHIME_4, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_BlueLightOn))
        Wait(3)
    EndLoop
    Call(UseSettingsFrom, CAM_DEFAULT, 160, 10, -200)
    Call(SetPanTarget, CAM_DEFAULT, 160, 10, -200)
    Call(SetCamDistance, CAM_DEFAULT, 700)
    Call(SetCamPitch, CAM_DEFAULT, 40, Float(-4.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(30)
    Thread
        Call(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_t1, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_o875)
        Call(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.8))
    EndThread
    Wait(10)
    Thread
        Call(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_t2, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_o877)
        Call(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.8))
    EndThread
    Wait(10)
    Thread
        Call(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_t3, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_o879)
        Call(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.8))
    EndThread
    Wait(10)
    Thread
        Call(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_t4, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetModelCenter, MODEL_o881)
        Call(PlaySoundAt, SOUND_OMO_COLORED_PANEL_DROP, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0)
        Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.8))
    EndThread
    Wait(100)
    Call(UseSettingsFrom, CAM_DEFAULT, 100, 0, 370)
    Call(SetPanTarget, CAM_DEFAULT, 100, 0, 370)
    Call(SetCamDistance, CAM_DEFAULT, -450)
    Call(SetCamPitch, CAM_DEFAULT, 16, Float(-6.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(10)
    Thread
        Call(GetModelCenter, MODEL_b1_1)
        Call(SetGroupVisibility, MODEL_b1, MODEL_GROUP_HIDDEN)
        Call(PlaySoundAtCollider, COLLIDER_o907, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        Loop(4)
            Set(LVar3, 20)
            Call(RandInt, 40, LVar6)
            Sub(LVar3, LVar6)
            Add(LVar3, LVar0)
            Set(LVar4, 20)
            Call(RandInt, 40, LVar7)
            Sub(LVar4, LVar7)
            Add(LVar4, LVar1)
            Set(LVar5, 20)
            Call(RandInt, 40, LVar8)
            Sub(LVar5, LVar8)
            Add(LVar5, LVar2)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            Wait(2)
        EndLoop
    EndThread
    Wait(30)
    Thread
        Call(GetModelCenter, MODEL_b2_1)
        Call(SetGroupVisibility, MODEL_b2, MODEL_GROUP_HIDDEN)
        Call(PlaySoundAtCollider, COLLIDER_o911, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        Loop(4)
            Set(LVar3, 20)
            Call(RandInt, 40, LVar6)
            Sub(LVar3, LVar6)
            Add(LVar3, LVar0)
            Set(LVar4, 20)
            Call(RandInt, 40, LVar7)
            Sub(LVar4, LVar7)
            Add(LVar4, LVar1)
            Set(LVar5, 20)
            Call(RandInt, 40, LVar8)
            Sub(LVar5, LVar8)
            Add(LVar5, LVar2)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            Wait(2)
        EndLoop
    EndThread
    Wait(30)
    Thread
        Call(GetModelCenter, MODEL_b3_1)
        Call(SetGroupVisibility, MODEL_b3, MODEL_GROUP_HIDDEN)
        Call(PlaySoundAtCollider, COLLIDER_o915, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        Loop(4)
            Set(LVar3, 20)
            Call(RandInt, 40, LVar6)
            Sub(LVar3, LVar6)
            Add(LVar3, LVar0)
            Set(LVar4, 20)
            Call(RandInt, 40, LVar7)
            Sub(LVar4, LVar7)
            Add(LVar4, LVar1)
            Set(LVar5, 20)
            Call(RandInt, 40, LVar8)
            Sub(LVar5, LVar8)
            Add(LVar5, LVar2)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            Wait(2)
        EndLoop
    EndThread
    Wait(30)
    Thread
        Call(GetModelCenter, MODEL_b4_1)
        Call(SetGroupVisibility, MODEL_b4, MODEL_GROUP_HIDDEN)
        Call(PlaySoundAtCollider, COLLIDER_o918, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT)
        Loop(4)
            Set(LVar3, 20)
            Call(RandInt, 40, LVar6)
            Sub(LVar3, LVar6)
            Add(LVar3, LVar0)
            Set(LVar4, 20)
            Call(RandInt, 40, LVar7)
            Sub(LVar4, LVar7)
            Add(LVar4, LVar1)
            Set(LVar5, 20)
            Call(RandInt, 40, LVar8)
            Sub(LVar5, LVar8)
            Add(LVar5, LVar2)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar3, LVar4, LVar5)
            Wait(2)
        EndLoop
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o907, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o911, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o915, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o918, COLLIDER_FLAGS_UPPER_MASK)
    Wait(20)
    Call(ResetCam, CAM_DEFAULT, 2)
    Set(GB_StoryProgress, STORY_CH4_SOLVED_COLOR_PUZZLE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BoxResult_ReleaseShyGuys) = {
    Set(LVar0, 4)
    Loop(3)
        Exec(N(EVS_GreenLightOff))
        Wait(LVar0)
        Exec(N(EVS_YellowLightOff))
        Wait(LVar0)
        Exec(N(EVS_RedLightOff))
        Wait(LVar0)
        Exec(N(EVS_BlueLightOff))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_CHIME_2, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_BlueLightOn))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_CHIME_1, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_RedLightOn))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_CHIME_3, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_YellowLightOn))
        Wait(LVar0)
        Call(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_CHIME_4, SOUND_SPACE_DEFAULT)
        Exec(N(EVS_GreenLightOn))
        Wait(LVar0)
        Sub(LVar0, 1)
    EndLoop
    Wait(4)
    Set(LVar0, 4)
    Loop(3)
        Exec(N(EVS_GreenLightOff))
        Exec(N(EVS_YellowLightOff))
        Exec(N(EVS_RedLightOff))
        Exec(N(EVS_BlueLightOff))
        Wait(LVar0)
        Call(PlaySound, SOUND_OMO_BOX_DONE)
        Exec(N(EVS_GreenLightOn))
        Exec(N(EVS_YellowLightOn))
        Exec(N(EVS_RedLightOn))
        Exec(N(EVS_BlueLightOn))
        Wait(LVar0)
        Sub(LVar0, 1)
    EndLoop
    Wait(2)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm1_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm1_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_o907, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(GetModelCenter, MODEL_b1_1)
        Call(SetNpcPos, NPC_ShyGuy_01, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_ShyGuy_01, Float(1.0))
        Add(LVar2, 60)
        Call(NpcJump0, NPC_ShyGuy_01, LVar0, 0, LVar2, 20)
        Call(SetNpcFlagBits, NPC_ShyGuy_01, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EndThread
    Wait(3)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm2_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm2_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_o911, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(GetModelCenter, MODEL_b2_1)
        Call(SetNpcPos, NPC_ShyGuy_02, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_ShyGuy_02, Float(1.0))
        Add(LVar2, 60)
        Call(NpcJump0, NPC_ShyGuy_02, LVar0, 0, LVar2, 20)
        Call(SetNpcFlagBits, NPC_ShyGuy_02, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EndThread
    Wait(3)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm3_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm3_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_o915, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(GetModelCenter, MODEL_b3_1)
        Call(SetNpcPos, NPC_ShyGuy_03, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_ShyGuy_03, Float(1.0))
        Add(LVar2, 60)
        Call(NpcJump0, NPC_ShyGuy_03, LVar0, 0, LVar2, 20)
        Call(SetNpcFlagBits, NPC_ShyGuy_03, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EndThread
    Wait(3)
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_bm4_2, LVar0, -1, 0, 0)
            Call(RotateModel, MODEL_bm4_1, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_o918, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(GetModelCenter, MODEL_b4_1)
        Call(SetNpcPos, NPC_ShyGuy_04, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_ShyGuy_04, Float(1.0))
        Add(LVar2, 60)
        Call(NpcJump0, NPC_ShyGuy_04, LVar0, 0, LVar2, 20)
        Call(SetNpcFlagBits, NPC_ShyGuy_04, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
        Call(ResetCam, CAM_DEFAULT, 1)
        Exec(N(EVS_ResetBoxesAfterAmbush))
    EndThread
    Return
    End
};

EvtScript N(EVS_HitBox) = {
    Switch(LVar0)
        CaseEq(Ref(N(GreenBoxInfo)))
            Call(PlaySoundAtCollider, COLLIDER_o907, SOUND_OMO_BOX_GLOW_2, SOUND_SPACE_DEFAULT)
        CaseEq(Ref(N(YellowBoxInfo)))
            Call(PlaySoundAtCollider, COLLIDER_o911, SOUND_OMO_BOX_GLOW_1, SOUND_SPACE_DEFAULT)
        CaseEq(Ref(N(RedBoxInfo)))
            Call(PlaySoundAtCollider, COLLIDER_o915, SOUND_OMO_BOX_GLOW_3, SOUND_SPACE_DEFAULT)
        CaseEq(Ref(N(BlueBoxInfo)))
            Call(PlaySoundAtCollider, COLLIDER_o918, SOUND_OMO_BOX_GLOW_4, SOUND_SPACE_DEFAULT)
    EndSwitch
    UseBuf(LVar0)
    BufRead1(LVar1)
    BufRead4(LVar2, LVar3, LVar4, LVar5)
    Loop(5)
        Call(EnableModel, LVar2, FALSE)
        Call(EnableModel, LVar3, FALSE)
        Call(EnableModel, LVar4, TRUE)
        Call(EnableModel, LVar5, TRUE)
        Wait(1)
        Call(EnableModel, LVar2, TRUE)
        Call(EnableModel, LVar3, TRUE)
        Call(EnableModel, LVar4, FALSE)
        Call(EnableModel, LVar5, FALSE)
        Wait(1)
    EndLoop
    Mul(MV_BoxHitSequence, 4) // shift left by 2
    BitwiseOr(MV_BoxHitSequence, LVar1)
    Add(MV_BoxHitCount, 1)
    IfEq(MV_BoxHitCount, 4)
        Call(DisablePlayerInput, TRUE)
        Wait(5)
        Call(UseSettingsFrom, CAM_DEFAULT, 100, 0, 370)
        Call(SetPanTarget, CAM_DEFAULT, 100, 0, 370)
        Call(SetCamDistance, CAM_DEFAULT, -450)
        Call(SetCamPitch, CAM_DEFAULT, 16, Float(-6.0))
        Call(SetCamSpeed, CAM_DEFAULT, 1)
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Wait(30)
        Switch(MV_BoxHitSequence)
            CaseEq(BOX_SEQUENCE(BOX_COLOR_GREEN, BOX_COLOR_YELLOW, BOX_COLOR_RED, BOX_COLOR_BLUE))
                ExecWait(N(EVS_BoxResult_GiveCoins))
            CaseEq(BOX_SEQUENCE(BOX_COLOR_YELLOW, BOX_COLOR_GREEN, BOX_COLOR_RED, BOX_COLOR_BLUE))
                ExecWait(N(EVS_BoxResult_RepairTrack))
            CaseDefault
                ExecWait(N(EVS_BoxResult_ReleaseShyGuys))
        EndSwitch
        Call(DisablePlayerInput, FALSE)
    Else
        Thread
            Label(10)
            Call(EnableModel, LVar2, FALSE)
            Call(EnableModel, LVar3, FALSE)
            Call(EnableModel, LVar4, TRUE)
            Call(EnableModel, LVar5, TRUE)
            Wait(5)
            Call(EnableModel, LVar2, TRUE)
            Call(EnableModel, LVar3, TRUE)
            Call(EnableModel, LVar4, FALSE)
            Call(EnableModel, LVar5, FALSE)
            Wait(10)
            IfNe(MV_BoxHitCount, 4)
                Goto(10)
            EndIf
        EndThread
    EndIf
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupBoxes) = {
    IfLt(GB_StoryProgress, STORY_CH4_SOLVED_COLOR_PUZZLE)
        Set(MV_BoxHitSequence, 0)
        Set(MV_BoxHitCount, 0)
        Call(EnableModel, MODEL_bm1_2, FALSE)
        Call(EnableModel, MODEL_b1_2, FALSE)
        Set(LVar0, Ref(N(GreenBoxInfo)))
        BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o907, 1, 0)
        Call(EnableModel, MODEL_bm2_2, FALSE)
        Call(EnableModel, MODEL_b2_2, FALSE)
        Set(LVar0, Ref(N(YellowBoxInfo)))
        BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o911, 1, 0)
        Call(EnableModel, MODEL_bm3_2, FALSE)
        Call(EnableModel, MODEL_b3_2, FALSE)
        Set(LVar0, Ref(N(RedBoxInfo)))
        BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o915, 1, 0)
        Call(EnableModel, MODEL_bm4_2, FALSE)
        Call(EnableModel, MODEL_b4_2, FALSE)
        Set(LVar0, Ref(N(BlueBoxInfo)))
        BindTrigger(Ref(N(EVS_HitBox)), TRIGGER_WALL_HAMMER, COLLIDER_o918, 1, 0)
    Else
        Call(SetGroupVisibility, MODEL_box, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o907, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o911, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o915, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o918, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sen1, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sen2, COLLIDER_FLAGS_UPPER_MASK)
        Call(RotateGroup, MODEL_t1, 90, 1, 0, 0)
        Call(RotateGroup, MODEL_t2, 90, 1, 0, 0)
        Call(RotateGroup, MODEL_t3, 90, 1, 0, 0)
        Call(RotateGroup, MODEL_t4, 90, 1, 0, 0)
    EndIf
    Return
    End
};
