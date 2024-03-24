#include "sam_06.h"
#include "model.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Wander.inc.c"

MobileAISettings N(AISettings_Ninji_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Ninji_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_Ninji_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Ninji_Wander) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Ninji_Wander),
};

MobileAISettings N(AISettings_ShiverToad_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShiverToad_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_ShiverToad_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_ShiverToad_Wander) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_ShiverToad_Wander),
};

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/npc/StarSpirit_Wander.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

NpcSettings N(NpcSettings_Ninji_Stationary) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_ShiverToad_Stationary) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/GiveReward.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#if VERSION_PAL
#include "sprite/npc/ShiverToad.h"
#define TOADHOUSE_ANIM_TALK ANIM_ShiverToad_Red_Talk
#define TOADHOUSE_ANIM_IDLE ANIM_ShiverToad_Red_Idle
#endif

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_FrostT)[] = {
    ITEM_LETTER_CHAIN_FROST_T,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_FrostT) = {
    Call(N(LetterDelivery_Init),
        NPC_ShiverToad_03, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle,
        ITEM_LETTER_CHAIN_FROST_T, ITEM_LETTER_CHAIN_GOOMPAPA_2,
        MSG_CH7_00FE, MSG_CH7_00FF, MSG_CH7_0100, MSG_CH7_0101,
        Ref(N(LetterList_FrostT)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Merle) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F4)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F5)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_SAM06_Merle_HeardLongerMessage, FALSE)
                Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F6)
                Set(GF_SAM06_Merle_HeardLongerMessage, TRUE)
            Else
                Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F7)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Merle_CarryScarf) = {
    Label(0)
        Call(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 15)
        Call(GetNpcYaw, NPC_Merle, LVar3)
        IfGe(LVar3, 90)
            IfLe(LVar3, 270)
                Add(LVar2, 10)
            Else
                Add(LVar2, -10)
            EndIf
        Else
            Add(LVar2, -10)
        EndIf
        Call(SetItemPos, MV_ScarfItemID, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Merle_HandOverScarf) = {
    Set(LVar4, 10)
    Loop(10)
        Call(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 15)
        Call(GetNpcYaw, NPC_Merle, LVar3)
        IfGe(LVar3, 90)
            IfLe(LVar3, 270)
                Add(LVar2, LVar4)
            Else
                Sub(LVar2, LVar4)
            EndIf
        Else
            Sub(LVar2, LVar4)
        EndIf
        Call(SetItemPos, MV_ScarfItemID, LVar0, LVar1, LVar2)
        Add(LVar4, 1)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_Merle_Greeting) = {
    Call(WaitForPlayerInputEnabled)
    Wait(1)
    Call(GetPartnerInUse, LVar0)
    IfEq(LVar0, PARTNER_LAKILESTER)
        Call(InterruptUsePartner)
        Call(WaitForPlayerTouchingFloor)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -240, 300, 0)
    Call(PlayerFaceNpc, NPC_Merle, FALSE)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00E9)
    Call(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EA)
    Call(UseSettingsFrom, CAM_DEFAULT, -250, 0, 300)
    Call(SetPanTarget, CAM_DEFAULT, -250, 0, 300)
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    Call(SetNpcSpeed, NPC_Merle, Float(3.0 / DT))
    Call(NpcMoveTo, NPC_Merle, -110, 300, 0)
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    Call(GetAngleToPlayer, NPC_Merle, LVar0)
    Call(InterpNpcYaw, NPC_Merle, LVar0, 0)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EB)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(AF_SAM_05, TRUE)
    Set(GB_StoryProgress, STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
    Call(DisablePlayerInput, FALSE)
    Set(MF_MerleReady, FALSE)
    Thread
        Call(BindNpcInteract, NPC_Merle, 0)
        Call(SetNpcFlagBits, NPC_Merle, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(SetNpcSpeed, NPC_Merle, Float(2.0 / DT))
        Call(NpcMoveTo, NPC_Merle, -78, 287, 0)
        Call(SetNpcJumpscale, NPC_Merle, Float(0.5))
        Call(NpcJump0, NPC_Merle, -25, 20, 253, 17)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(NpcJump0, NPC_Merle, -40, 45, 188, 17)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(NpcMoveTo, NPC_Merle, -90, 190, 0)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        Set(MF_MerleReady, TRUE)
    EndThread
    Return
    End
};

EvtScript N(EVS_Scene_Merle_WaitingOnHill) = {
    Label(60)
    Call(GetPlayerActionState, LVar0)
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    Wait(1)
    IfEq(LVar0, ACTION_STATE_JUMP)
        Goto(60)
    EndIf
    IfEq(LVar0, ACTION_STATE_FALLING)
        Goto(60)
    EndIf
    IfLt(LVar1, -60)
        Goto(60)
    EndIf
    IfLt(LVar2, 20)
        Goto(60)
    EndIf
    IfGt(LVar3, 300)
        Goto(60)
    EndIf
    Call(GetPartnerInUse, LVar0)
    IfEq(LVar0, PARTNER_LAKILESTER)
        Call(InterruptUsePartner)
        Call(WaitForPlayerTouchingFloor)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Loop(0)
        Wait(1)
        IfEq(MF_MerleReady, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(PlayerFaceNpc, NPC_Merle, FALSE)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EC)
    Set(GB_StoryProgress, STORY_CH7_MERLE_APOLOGIZED)
    Call(DisablePlayerInput, FALSE)
    Set(MF_MerleReady, FALSE)
    Thread
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(NpcMoveTo, NPC_Merle, -110, 145, 0)
        Call(NpcJump0, NPC_Merle, -131, 60, 91, 20 * DT)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(NpcJump0, NPC_Merle, -117, 90, 7, 20 * DT)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(NpcMoveTo, NPC_Merle, 0, -143, 0)
        Call(InterpNpcYaw, NPC_Merle, 270, 0)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
        Set(MF_MerleReady, TRUE)
    EndThread
    Return
    End
};

API_CALLABLE(N(func_80242538_D223C8)) {
    s32 alpha;

    if (isInitialCall) {
        if (script->varTable[0] == 0) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
        }
        script->functionTemp[0] = 0;
    }

    script->functionTemp[0] += 32;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = 255 - script->functionTemp[0];
    }

    mdl_set_shroud_tint_params(0, 0, 0, alpha);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 3) {
            mdl_group_set_custom_gfx(script->varTable[15], CUSTOM_GFX_NONE, ENV_TINT_NONE, TRUE);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Scene_Merle_EnterHouse) = {
    Call(AwaitPlayerApproach, 0, -140, 60)
    Call(GetPartnerInUse, LVar0)
    IfEq(LVar0, PARTNER_LAKILESTER)
        Call(InterruptUsePartner)
        Call(WaitForPlayerTouchingFloor)
    EndIf
    Call(WaitForPlayerTouchingFloor)
    Call(DisablePlayerInput, TRUE)
    Loop(0)
        Wait(1)
        IfEq(MF_MerleReady, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Set(MF_MerleReady, FALSE)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00ED)
    Thread
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(SetNpcSpeed, NPC_Merle, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Merle, 27, -120, 0)
    EndThread
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 15, -90, 0)
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    Call(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 10, EASING_QUADRATIC_OUT)
    Label(70)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(70)
        EndIf
    Set(AF_SAM_Snowing, FALSE)
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    Thread
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
        Call(SetNpcSpeed, NPC_Merle, Float(4.0 / DT))
        Call(NpcMoveTo, NPC_Merle, 0, -330, 0)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.8 / DT))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k_d1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_k_d2, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlayerMoveTo, 0, -200, 0)
    Thread
        Set(LVar0, 0)
        Set(LVarF, MODEL_k)
        Call(SetNpcFlagBits, NPC_Merle, NPC_FLAG_HIDING, FALSE)
        Call(SetNpcFlagBits, NPC_StarKid_03, NPC_FLAG_HIDING, TRUE)
        Call(N(func_80242538_D223C8))
    EndThread
    Thread
        Call(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
        Label(71)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_km_yane, LVar0, 0, 0, 1)
            Call(RotateGroup, MODEL_km_sita, LVar0, 0, 0, -1)
            Set(LVar2, 90)
            Sub(LVar2, LVar0)
            Call(RotateModel, MODEL_km_doa, LVar2, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(71)
            EndIf
        Call(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_HIDDEN)
        Call(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Call(PlayerMoveTo, 0, -240, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k_d1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_k_d2, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Call(GetAngleToPlayer, NPC_Merle, LVar0)
    Call(InterpNpcYaw, NPC_Merle, LVar0, 0)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EE)
    Call(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(200.7), Float(-321.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(0.7), Float(-321.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(21.0), Float(-14.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00EF)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(200.7), Float(-250.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(0.7), Float(-250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(21.0), Float(-14.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcSpeed, NPC_Merle, Float(2.0 / DT))
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    ExecGetTID(N(EVS_Merle_CarryScarf), LVarA)
    Call(NpcMoveTo, NPC_Merle, 0, -275, 0)
    KillThread(LVarA)
    ExecGetTID(N(EVS_Merle_HandOverScarf), LVarA)
    Wait(20 * DT)
    KillThread(LVarA)
    Call(SetItemPos, MV_ScarfItemID, NPC_DISPOSE_LOCATION)
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EVT_GIVE_KEY_REWARD(ITEM_SNOWMAN_SCARF)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F1)
    Wait(10 * DT)
    Call(SetCamPosA, CAM_DEFAULT, Float(200.7), Float(-321.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(0.7), Float(-321.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.7))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcSpeed, NPC_Merle, Float(2.0 / DT))
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    Call(NpcMoveTo, NPC_Merle, 0, -330, 0)
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    Call(GetAngleToPlayer, NPC_Merle, LVar0)
    Call(InterpNpcYaw, NPC_Merle, LVar0, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(15 * DT)
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(BindNpcInteract, NPC_Merle, Ref(N(EVS_NpcInteract_Merle)))
    Call(SetNpcFlagBits, NPC_Merle, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Merle) = {
    Wait(3)
    IfLt(GB_StoryProgress, STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
        ExecWait(N(EVS_Scene_Merle_Greeting))
        ExecWait(N(EVS_Scene_Merle_WaitingOnHill))
        ExecWait(N(EVS_Scene_Merle_EnterHouse))
        Return
    EndIf
    IfEq(GB_StoryProgress, STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
        Call(SetNpcPos, NPC_Merle, -90, 45, 190)
        Call(InterpNpcYaw, NPC_Merle, 270, 0)
        Set(MF_MerleReady, TRUE)
        ExecWait(N(EVS_Scene_Merle_WaitingOnHill))
        ExecWait(N(EVS_Scene_Merle_EnterHouse))
        Return
    EndIf
    IfEq(GB_StoryProgress, STORY_CH7_MERLE_APOLOGIZED)
        Call(SetNpcPos, NPC_Merle, 0, 90, -143)
        Call(InterpNpcYaw, NPC_Merle, 270, 0)
        Set(MF_MerleReady, TRUE)
        ExecWait(N(EVS_Scene_Merle_EnterHouse))
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_Merle_OneLastThing) = {
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcSpeed, NPC_PARTNER, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_PARTNER, -28, -80, 0)
        Call(EnablePartnerAI)
    EndThread
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 0, -100, 0)
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    Call(SetGroupVisibility, MODEL_km_sita, MODEL_GROUP_VISIBLE)
    Call(SetNpcPos, NPC_Merle, 0, 90, -180)
    Call(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SetNpcSpeed, NPC_Merle, Float(3.0 / DT))
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    Call(NpcMoveTo, NPC_Merle, 40, -140, 0)
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    Call(MakeLerp, 90, 0, 10, EASING_QUADRATIC_IN)
    Label(1)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
    Call(GetNpcPos, NPC_Merle, LVar0, LVar1, LVar2)
    Call(PlayerFaceNpc, NPC_Merle, FALSE)
    Call(DisablePartnerAI, 0)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Merle, 0)
    Call(EnablePartnerAI)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Merle, ANIM_Merle_Talk, ANIM_Merle_Idle, 0, MSG_CH7_00F3)
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_VISIBLE)
    Call(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 10, EASING_QUADRATIC_IN)
    Label(2)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Call(SetNpcSpeed, NPC_Merle, Float(3.0 / DT))
    Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Walk)
    Call(NpcMoveTo, NPC_Merle, 0, -180, 0)
    Thread
        Call(NpcMoveTo, NPC_Merle, 0, -300, 0)
        Call(SetNpcAnimation, NPC_Merle, ANIM_Merle_Idle)
    EndThread
    Call(MakeLerp, 90, 0, 10, EASING_QUADRATIC_IN)
    Label(3)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_km_doa, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(3)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_k_d1, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(SetGroupVisibility, MODEL_k_naiso, MODEL_GROUP_HIDDEN)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Set(AF_SAM_05, FALSE)
    Set(GB_StoryProgress, STORY_CH7_GOT_SNOWMAN_SCARF)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ShiverToad_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Red_Talk, ANIM_ShiverToad_Red_Idle, 0, MSG_CH7_00F8)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Red_Talk, ANIM_ShiverToad_Red_Idle, 0, MSG_CH7_00F9)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_ShiverToad_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Blue_Talk, ANIM_ShiverToad_Blue_Idle, 0, MSG_CH7_00FA)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Blue_Talk, ANIM_ShiverToad_Blue_Idle, 0, MSG_CH7_00FB)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_ShiverToad_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle, 0, MSG_CH7_00FC)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShiverToad_Green_Talk, ANIM_ShiverToad_Green_Idle, 0, MSG_CH7_00FD)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_FrostT))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Ninji_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0102)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0103)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Ninji_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0104)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0105)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Ninji_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0106)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0107)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Ninji_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0114)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Ninji_Talk, ANIM_Ninji_Idle, 0, MSG_CH7_0115)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0108)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0109)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010A)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010B)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_03) = {
    IfEq(GF_SAM06_FoundSidewaysStarKid, FALSE)
        Set(GF_SAM06_FoundSidewaysStarKid, TRUE)
        Call(MakeLerp, 90, 360, 20, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010C)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010D)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010E)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_010F)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0110)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0111)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_06) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0112)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_CH7_0113)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_CH7_0116)
    Set(LVar8, MSG_CH7_0117)
    Set(LVar1, MSG_CH7_0118)
    Set(LVar2, MSG_CH7_0119)
    Set(LVar3, MSG_CH7_011A)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -336, -48, 0)
    Thread
        Wait(15)
        Call(N(ToadHouse_CamSetFOV), 0, Float(40.0))
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamPitch, CAM_DEFAULT, Float(50.0), Float(-16.0))
        Call(SetCamDistance, CAM_DEFAULT, Float(111.0))
        Call(SetCamPosA, CAM_DEFAULT, Float(-92.0), Float(94.0))
        Call(SetCamPosB, CAM_DEFAULT, Float(-318.1), Float(-35.5))
        Call(SetCamPosC, CAM_DEFAULT, Float(-641.0), Float(122.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(PlayerMoveTo, -347, -114, 0)
    Call(InterpPlayerYaw, 229, 1)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Thread
        Wait(60)
        Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EndThread
    Wait(20)
    Thread
        Wait(81)
        Call(N(ToadHouse_CamSetFOV), 0, 25)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Exec(N(EVS_SetupMusic))
    Call(HidePlayerShadow, FALSE)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(PlayerMoveTo, -347, -114, 0)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -309, -16, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Merle) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Merle)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Merle)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_GOT_SNOWMAN_SCARF)
            Call(SetNpcPos, NPC_SELF, -200, 0, 300)
        CaseGe(STORY_CH7_GOT_SNOWMAN_SCARF)
            Call(SetNpcPos, NPC_SELF, 0, 90, -300)
            Call(InterpNpcYaw, NPC_SELF, 180, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_ShiverToad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ShiverToad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ShiverToad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ShiverToad_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ShiverToad_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ShiverToad_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Ninji_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Ninji_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Ninji_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Ninji_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Ninji_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Ninji_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Ninji_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Ninji_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_03)))
    IfEq(GF_SAM06_FoundSidewaysStarKid, FALSE)
        Call(SetNpcRotation, NPC_SELF, 0, 90, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_05)))
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_06)))
    Return
    End
};

EvtScript N(EVS_NpcInit_ShiverToad_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    Return
    End
};

NpcData N(NpcData_Merle)[] = {
    {
        .id = NPC_Merle,
        .pos = { 0.0f, 90.0f, -300.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Merle),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Merle_Idle,
            .walk   = ANIM_Merle_Idle,
            .run    = ANIM_Merle_Idle,
            .chase  = ANIM_Merle_Idle,
            .anim_4 = ANIM_Merle_Idle,
            .anim_5 = ANIM_Merle_Idle,
            .death  = ANIM_Merle_Idle,
            .hit    = ANIM_Merle_Idle,
            .anim_8 = ANIM_Merle_Idle,
            .anim_9 = ANIM_Merle_Idle,
            .anim_A = ANIM_Merle_Idle,
            .anim_B = ANIM_Merle_Idle,
            .anim_C = ANIM_Merle_Idle,
            .anim_D = ANIM_Merle_Idle,
            .anim_E = ANIM_Merle_Idle,
            .anim_F = ANIM_Merle_Idle,
        },
        .tattle = MSG_NpcTattle_Merle,
    },
    {
        .id = NPC_ShiverToad_01,
        .pos = { -376.0f, 60.0f, 112.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ShiverToad_01),
        .settings = &N(NpcSettings_ShiverToad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Red_Idle,
            .walk   = ANIM_ShiverToad_Red_Walk,
            .run    = ANIM_ShiverToad_Red_Idle,
            .chase  = ANIM_ShiverToad_Red_Idle,
            .anim_4 = ANIM_ShiverToad_Red_Idle,
            .anim_5 = ANIM_ShiverToad_Red_Idle,
            .death  = ANIM_ShiverToad_Red_Idle,
            .hit    = ANIM_ShiverToad_Red_Idle,
            .anim_8 = ANIM_ShiverToad_Red_Idle,
            .anim_9 = ANIM_ShiverToad_Red_Idle,
            .anim_A = ANIM_ShiverToad_Red_Idle,
            .anim_B = ANIM_ShiverToad_Red_Idle,
            .anim_C = ANIM_ShiverToad_Red_Idle,
            .anim_D = ANIM_ShiverToad_Red_Idle,
            .anim_E = ANIM_ShiverToad_Red_Idle,
            .anim_F = ANIM_ShiverToad_Red_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_ShiverToadA,
    },
    {
        .id = NPC_ShiverToad_02,
        .pos = { 208.0f, 80.0f, 150.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 208, 80, 150 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_ShiverToad_02),
        .settings = &N(NpcSettings_ShiverToad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Blue_Idle,
            .walk   = ANIM_ShiverToad_Blue_Walk,
            .run    = ANIM_ShiverToad_Blue_Idle,
            .chase  = ANIM_ShiverToad_Blue_Idle,
            .anim_4 = ANIM_ShiverToad_Blue_Idle,
            .anim_5 = ANIM_ShiverToad_Blue_Idle,
            .death  = ANIM_ShiverToad_Blue_Idle,
            .hit    = ANIM_ShiverToad_Blue_Idle,
            .anim_8 = ANIM_ShiverToad_Blue_Idle,
            .anim_9 = ANIM_ShiverToad_Blue_Idle,
            .anim_A = ANIM_ShiverToad_Blue_Idle,
            .anim_B = ANIM_ShiverToad_Blue_Idle,
            .anim_C = ANIM_ShiverToad_Blue_Idle,
            .anim_D = ANIM_ShiverToad_Blue_Idle,
            .anim_E = ANIM_ShiverToad_Blue_Idle,
            .anim_F = ANIM_ShiverToad_Blue_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_ShiverToadB,
    },
    {
        .id = NPC_ShiverToad_03,
        .pos = { 127.0f, 0.0f, 445.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_ShiverToad_03),
        .settings = &N(NpcSettings_ShiverToad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Green_Idle,
            .walk   = ANIM_ShiverToad_Green_Walk,
            .run    = ANIM_ShiverToad_Green_Idle,
            .chase  = ANIM_ShiverToad_Green_Idle,
            .anim_4 = ANIM_ShiverToad_Green_Idle,
            .anim_5 = ANIM_ShiverToad_Green_Idle,
            .death  = ANIM_ShiverToad_Green_Idle,
            .hit    = ANIM_ShiverToad_Green_Idle,
            .anim_8 = ANIM_ShiverToad_Green_Idle,
            .anim_9 = ANIM_ShiverToad_Green_Idle,
            .anim_A = ANIM_ShiverToad_Green_Idle,
            .anim_B = ANIM_ShiverToad_Green_Idle,
            .anim_C = ANIM_ShiverToad_Green_Idle,
            .anim_D = ANIM_ShiverToad_Green_Idle,
            .anim_E = ANIM_ShiverToad_Green_Idle,
            .anim_F = ANIM_ShiverToad_Green_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_ShiverToadC,
    },
    {
        .id = NPC_Ninji_01,
        .pos = { -99.0f, 90.0f, -90.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -99, 90, -90 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Ninji_01),
        .settings = &N(NpcSettings_Ninji_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiA,
    },
    {
        .id = NPC_Ninji_02,
        .pos = { -48.0f, 0.0f, 400.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -48, 0, 400 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Ninji_02),
        .settings = &N(NpcSettings_Ninji_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiB,
    },
    {
        .id = NPC_Ninji_03,
        .pos = { 239.0f, 50.0f, 315.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Ninji_03),
        .settings = &N(NpcSettings_Ninji_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiC,
    },
    {
        .id = NPC_Ninji_04,
        .pos = { 390.0f, 80.0f, 50.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Ninji_04),
        .settings = &N(NpcSettings_Ninji_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Ninji_Idle,
            .walk   = ANIM_Ninji_Walk,
            .run    = ANIM_Ninji_Idle,
            .chase  = ANIM_Ninji_Idle,
            .anim_4 = ANIM_Ninji_Idle,
            .anim_5 = ANIM_Ninji_Idle,
            .death  = ANIM_Ninji_Idle,
            .hit    = ANIM_Ninji_Idle,
            .anim_8 = ANIM_Ninji_Idle,
            .anim_9 = ANIM_Ninji_Idle,
            .anim_A = ANIM_Ninji_Idle,
            .anim_B = ANIM_Ninji_Idle,
            .anim_C = ANIM_Ninji_Idle,
            .anim_D = ANIM_Ninji_Idle,
            .anim_E = ANIM_Ninji_Idle,
            .anim_F = ANIM_Ninji_Idle,
        },
        .tattle = MSG_NpcTattle_SAM_NinjiD,
    },
    {
        .id = NPC_StarKid_01,
        .pos = { -166.0f, 10.0f, 390.0f },
        .yaw = 180,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -166, 10, 390 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_StarKid_01),
        .settings = &N(NpcSettings_StarKid_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidA,
    },
    {
        .id = NPC_StarKid_02,
        .pos = { 3.0f, 60.0f, 137.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_02),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidB,
    },
    {
        .id = NPC_StarKid_03,
        .pos = { 120.0f, 100.0f, -210.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_StarKid_03),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_PranksterStarKid,
    },
    {
        .id = NPC_StarKid_04,
        .pos = { 369.0f, 90.0f, 9.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_04),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_BabyStarKid,
    },
    {
        .id = NPC_StarKid_05,
        .pos = { 405.0f, 90.0f, -19.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_05),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidC,
    },
    {
        .id = NPC_StarKid_06,
        .pos = { 364.0f, 90.0f, -47.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_StarKid_06),
        .settings = &N(NpcSettings_StarKid),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = STAR_KID_ANIMS,
        .tattle = MSG_NpcTattle_SAM_StarKidD,
    },
    {
        .id = NPC_ShiverToad_04,
        .pos = { -274.0f, 60.0f, -28.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_ShiverToad_04),
        .settings = &N(NpcSettings_ShiverToad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShiverToad_Red_Idle,
            .walk   = ANIM_ShiverToad_Red_Walk,
            .run    = ANIM_ShiverToad_Red_Idle,
            .chase  = ANIM_ShiverToad_Red_Idle,
            .anim_4 = ANIM_ShiverToad_Red_Idle,
            .anim_5 = ANIM_ShiverToad_Red_Idle,
            .death  = ANIM_ShiverToad_Red_Idle,
            .hit    = ANIM_ShiverToad_Red_Idle,
            .anim_8 = ANIM_ShiverToad_Red_Idle,
            .anim_9 = ANIM_ShiverToad_Red_Idle,
            .anim_A = ANIM_ShiverToad_Red_Idle,
            .anim_B = ANIM_ShiverToad_Red_Idle,
            .anim_C = ANIM_ShiverToad_Red_Idle,
            .anim_D = ANIM_ShiverToad_Red_Idle,
            .anim_E = ANIM_ShiverToad_Red_Idle,
            .anim_F = ANIM_ShiverToad_Red_Idle,
        },
        .tattle = MSG_NpcTattle_SAM06_ToadHouseToad,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Merle), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    {}
};
