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
    Call(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
    UseBuf(Ref(N(SnowmanModelSets)))
    Add(LVar0, 1)
    Loop(LVar0)
        BufRead1(LVar4)
    EndLoop
    UseBuf(LVar4)
    BufRead1(LVar4)
    Call(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    BufRead1(LVar4)
    Call(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    BufRead1(LVar4)
    Call(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    BufRead1(LVar4)
    Call(TranslateModel, LVar4, LVar1, LVar2, LVar3)
    Return
    End
};

EvtScript N(EVS_SnowmanJump) = {
    Thread
        Set(LVarA, LVar0)
        UseBuf(Ref(N(SnowmanModelSets)))
        Add(LVarA, 1)
        Loop(LVarA)
            BufRead1(LVarB)
        EndLoop
        UseBuf(LVarB)
        BufRead4(LVarC, LVarD, LVarE, LVarF)
        Add(LVar4, 1)
        Loop(LVar4)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Call(TranslateModel, LVarC, LVar1, LVar2, LVar3)
            Call(TranslateModel, LVarD, LVar1, LVar2, LVar3)
            Call(TranslateModel, LVarE, LVar1, LVar2, LVar3)
            Call(TranslateModel, LVarF, LVar1, LVar2, LVar3)
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcJumpscale, LVar0, Float(1.0))
    Call(NpcJump0, LVar0, LVar1, LVar2, LVar3, LVar4)
    PlayEffect(EFFECT_LANDING_DUST, 4, LVar1, LVar2, LVar3, 0)
    Return
    End
};

EvtScript N(EVS_SnowmanMove) = {
    Call(GetNpcPos, LVar0, LVar5, LVar6, LVar7)
    SetF(LVar8, LVar1)
    SetF(LVar9, LVar2)
    SetF(LVarA, LVar3)
    SetF(LVarB, LVar4)
    SubF(LVar8, LVar5)
    SubF(LVar9, LVar6)
    SubF(LVarA, LVar7)
    DivF(LVar8, LVarB)
    DivF(LVar9, LVarB)
    DivF(LVarA, LVarB)
    Loop(LVarB)
        AddF(LVar5, LVar8)
        AddF(LVar6, LVar9)
        AddF(LVar7, LVarA)
        SetF(LVar1, LVar5)
        SetF(LVar2, LVar6)
        SetF(LVar3, LVar7)
        Set(LVar4, 20)
        ExecWait(N(EVS_SnowmanJump))
        Call(PlaySoundAtNpc, LVar0, SOUND_SAM_SNOWMAN_JUMP, SOUND_SPACE_DEFAULT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_SnowmenSpeak) = {
    Wait(20 * DT)
    IfEq(LVar0, 0)
        Call(GetNpcPos, NPC_Snowman_03, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(10.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_Snowman_03, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011B)
        Call(GetNpcPos, NPC_Snowman_06, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(15 * DT)
        Call(SpeakToPlayer, NPC_Snowman_06, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011C)
    Else
        Call(GetNpcPos, NPC_Snowman_06, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(10.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_Snowman_06, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011C)
        Call(GetNpcPos, NPC_Snowman_03, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(15 * DT)
        Call(SpeakToPlayer, NPC_Snowman_03, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH7_011B)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, -140)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, -100)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(ShowMessageAtScreenPos, MSG_CH7_011D, 160, 40)
    Call(SetNpcFlagBits, NPC_Snowman_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Snowman_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Snowman_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Snowman_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Snowman_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Snowman_06, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Wait(1)
    Thread
        Wait(22 * DT)
        Call(DisablePlayerPhysics, TRUE)
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(N(SetAngleClamped), LVar3, LVar0, LVar2, 0, 0)
        Call(GetDist2D, LVar4, LVar0, LVar2, 0, 0)
        SetF(LVar5, LVar4)
        DivF(LVar5, Float(5.0))
        SetF(LVar8, LVar3)
        SubF(LVar8, Float(90.0))
        Loop(4)
            Call(AddVectorPolar, LVar0, LVar2, LVar5, LVar3)
            SetF(LVar6, LVar0)
            SetF(LVar7, LVar2)
            Call(AddVectorPolar, LVar6, LVar7, Float(20.0), LVar8)
            Call(SetPlayerJumpscale, Float(2.0))
            Call(PlayerJump1, LVar6, 0, LVar7, 16 * DT)
            AddF(LVar8, Float(180.0))
            Wait(6 * DT)
        EndLoop
        Call(SetPlayerJumpscale, Float(2.0 / DT))
        Call(PlayerJump1, 0, 0, 0, 16 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(InterpPlayerYaw, 0, 0)
        Call(DisablePlayerPhysics, FALSE)
    EndThread
    Thread
        Wait(110 * DT)
        Call(DisablePartnerAI, 0)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(NpcJump1, NPC_PARTNER, 50, 0, 0, 22)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Wait(110 * DT)
    EndThread
    Thread
        Wait(22 * DT)
        Loop(5)
            Call(ShakeCam, CAM_DEFAULT, 0, 6 * DT, Float(2.0))
            Wait(16 * DT)
        EndLoop
    EndThread
    Set(LVar0, NPC_Snowman_01)
    SetF(LVar1, Float(-175.0))
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(-180.0))
    SetF(LVar4, Float(5.0))
    Exec(N(EVS_SnowmanMove))
    Set(LVar0, NPC_Snowman_02)
    SetF(LVar1, Float(-125.0))
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(-220.0))
    SetF(LVar4, Float(5.0))
    Exec(N(EVS_SnowmanMove))
    Set(LVar0, NPC_Snowman_03)
    SetF(LVar1, Float(-75.0))
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(-260.0))
    SetF(LVar4, Float(5.0))
    Exec(N(EVS_SnowmanMove))
    Set(LVar0, NPC_Snowman_04)
    SetF(LVar1, Float(75.0))
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(-260.0))
    SetF(LVar4, Float(5.0))
    Exec(N(EVS_SnowmanMove))
    Set(LVar0, NPC_Snowman_05)
    SetF(LVar1, Float(125.0))
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(-220.0))
    SetF(LVar4, Float(5.0))
    Exec(N(EVS_SnowmanMove))
    Wait(1)
    Set(LVar0, NPC_Snowman_06)
    SetF(LVar1, Float(175.0))
    SetF(LVar2, Float(0.0))
    SetF(LVar3, Float(-180.0))
    SetF(LVar4, Float(5.0))
    ExecWait(N(EVS_SnowmanMove))
    Wait(80 * DT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 200, Float(1.0))
    EndThread
    Thread
        Loop(10)
            Set(LVar0, -150)
            Loop(6)
                PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, 0, -260, 0)
                Add(LVar0, 60)
            EndLoop
            Wait(20 * DT)
        EndLoop
    EndThread
    Thread
        Wait(40 * DT)
        Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, -240)
        Call(SetPanTarget, CAM_DEFAULT, 0, 0, -240)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(PlaySoundAt, SOUND_SAM_SNOWMEN_RAISE_WALL, SOUND_SPACE_DEFAULT, 0, 0, -300)
    Call(MakeLerp, 0, 100, 200 * DT, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o65, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o64, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o66, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Wait(60 * DT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 100, Float(0.3))
    EndThread
    Thread
        Call(GetModelCenter, MODEL_o65)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2, 0)
        Call(GetModelCenter, MODEL_o64)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, 0, LVar2, 0)
    EndThread
    Call(PlaySoundAt, SOUND_SAM_SNOWMEN_OPEN_PASSAGE, SOUND_SPACE_DEFAULT, 0, 0, -300)
    Call(MakeLerp, 0, 80, 100 * DT, EASING_COS_IN_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(TranslateModel, MODEL_o65, 0, 100, 0)
    Call(TranslateModel, MODEL_o64, 0, 100, 0)
    Call(RotateModel, MODEL_o65, LVar0, 0, 1, 0)
    Call(RotateModel, MODEL_o64, LVar0, 0, -1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Wait(60 * DT)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(10.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH7_011E, 160, 40)
    Call(EnablePartnerAI)
    Call(UpdateColliderTransform, COLLIDER_o78)
    Call(UpdateColliderTransform, COLLIDER_o79)
    Call(UpdateColliderTransform, COLLIDER_o80)
    Call(SetNpcFlagBits, NPC_Snowman_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Snowman_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Snowman_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Snowman_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Snowman_05, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcFlagBits, NPC_Snowman_06, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(BindNpcInteract, NPC_Snowman_01, NULL)
    Call(BindNpcInteract, NPC_Snowman_02, NULL)
    Call(BindNpcInteract, NPC_Snowman_03, NULL)
    Call(BindNpcInteract, NPC_Snowman_04, NULL)
    Call(BindNpcInteract, NPC_Snowman_05, NULL)
    Call(BindNpcInteract, NPC_Snowman_06, NULL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o106, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o118, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o119, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o120, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o121, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
    Return
    End
};

EvtScript N(EVS_SetupSnowmen) = {
    Call(CloneModel, MODEL_d_me,    CLONED_MODEL(0))
    Call(CloneModel, MODEL_body,    CLONED_MODEL(1))
    Call(CloneModel, MODEL_baketu,  CLONED_MODEL(2))
    Call(CloneModel, MODEL_mafu,    CLONED_MODEL(3))
    Call(CloneModel, MODEL_d_me,    CLONED_MODEL(4))
    Call(CloneModel, MODEL_body,    CLONED_MODEL(5))
    Call(CloneModel, MODEL_baketu,  CLONED_MODEL(6))
    Call(CloneModel, MODEL_mafu,    CLONED_MODEL(7))
    Call(CloneModel, MODEL_d_me,    CLONED_MODEL(8))
    Call(CloneModel, MODEL_body,    CLONED_MODEL(9))
    Call(CloneModel, MODEL_baketu,  CLONED_MODEL(10))
    Call(CloneModel, MODEL_mafu,    CLONED_MODEL(11))
    Call(CloneModel, MODEL_d_me,    CLONED_MODEL(12))
    Call(CloneModel, MODEL_body,    CLONED_MODEL(13))
    Call(CloneModel, MODEL_baketu,  CLONED_MODEL(14))
    Call(CloneModel, MODEL_mafu,    CLONED_MODEL(15))
    Call(CloneModel, MODEL_d_me,    CLONED_MODEL(16))
    Call(CloneModel, MODEL_body,    CLONED_MODEL(17))
    Call(CloneModel, MODEL_baketu,  CLONED_MODEL(18))
    Call(CloneModel, MODEL_mafu,    CLONED_MODEL(19))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o87, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o88, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o89, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o104, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o105, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o106, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o118, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o119, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o120, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o121, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    IfLt(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        Set(LVar0, NPC_Snowman_01)
        Set(LVar1, -150)
        Set(LVar2, 0)
        Set(LVar3, -270)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_02)
        Set(LVar1, -90)
        Set(LVar2, 0)
        Set(LVar3, -270)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_03)
        Set(LVar1, -30)
        Set(LVar2, 0)
        Set(LVar3, -270)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_04)
        Set(LVar1, 30)
        Set(LVar2, 0)
        Set(LVar3, -270)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_05)
        Set(LVar1, 90)
        Set(LVar2, 0)
        Set(LVar3, -270)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_06)
        Set(LVar1, 150)
        Set(LVar2, 0)
        Set(LVar3, -270)
        ExecWait(N(EVS_SetSnowmanPosition))
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o103, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Set(LVar0, NPC_Snowman_01)
        Set(LVar1, -175)
        Set(LVar2, 0)
        Set(LVar3, -180)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_02)
        Set(LVar1, -125)
        Set(LVar2, 0)
        Set(LVar3, -220)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0,  NPC_Snowman_03)
        Set(LVar1, -75)
        Set(LVar2, 0)
        Set(LVar3, -260)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_04)
        Set(LVar1, 75)
        Set(LVar2, 0)
        Set(LVar3, -260)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_05)
        Set(LVar1, 125)
        Set(LVar2, 0)
        Set(LVar3, -220)
        ExecWait(N(EVS_SetSnowmanPosition))
        Set(LVar0, NPC_Snowman_06)
        Set(LVar1, 175)
        Set(LVar2, 0)
        Set(LVar3, -180)
        ExecWait(N(EVS_SetSnowmanPosition))
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o106, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o118, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o119, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o120, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o121, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_SAM04_PlacedScarf, FALSE)
        Call(EnableModel, CLONED_MODEL(11), FALSE)
    EndIf
    IfEq(GF_SAM04_PlacedBucket, FALSE)
        Call(EnableModel, MODEL_baketu, FALSE)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttn, COLLIDER_FLAGS_UPPER_MASK)
    Call(ParentColliderToModel, COLLIDER_o78, MODEL_o65)
    Call(ParentColliderToModel, COLLIDER_o79, MODEL_o64)
    Call(ParentColliderToModel, COLLIDER_o80, MODEL_o66)
    IfGe(GB_StoryProgress, STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
        Call(TranslateModel, MODEL_o65, 0, 100, 0)
        Call(TranslateModel, MODEL_o64, 0, 100, 0)
        Call(TranslateModel, MODEL_o66, 0, 100, 0)
        Call(RotateModel, MODEL_o65, 80, 0, 1, 0)
        Call(RotateModel, MODEL_o64, 80, 0, -1, 0)
        Call(UpdateColliderTransform, COLLIDER_o78)
        Call(UpdateColliderTransform, COLLIDER_o79)
        Call(UpdateColliderTransform, COLLIDER_o80)
        Call(BindNpcInteract, NPC_Snowman_01, 0)
        Call(BindNpcInteract, NPC_Snowman_02, 0)
        Call(BindNpcInteract, NPC_Snowman_03, 0)
        Call(BindNpcInteract, NPC_Snowman_04, 0)
        Call(BindNpcInteract, NPC_Snowman_05, 0)
        Call(BindNpcInteract, NPC_Snowman_06, 0)
    EndIf
    Return
    End
};
