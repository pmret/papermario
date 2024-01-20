#include "omo_05.h"
#include "sprite/player.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"
#include "world/common/enemy/GrooveGuy.inc.c"
#include "world/common/enemy/SkyGuy.inc.c"

#include "world/common/npc/GourmetGuy.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

API_CALLABLE(N(JudgeFoodQuality)) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    ItemData* item = &gItemTable[itemID];

    if (itemID == ITEM_CAKE || itemID == ITEM_STRANGE_CAKE || itemID == ITEM_SHROOM_CAKE) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & ITEM_TYPE_FLAG_FOOD_OR_DRINK) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpinCameraAround)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        camera->flags |= CAMERA_FLAG_SHAKING;
        script->functionTempF[0] = 0.0f;
    }
    script->functionTempF[0] += 10.0f;
    guRotateF(camera->viewMtxShaking, script->functionTempF[0], 0.0f, 0.0f, -1.0f);

    if (script->functionTempF[0] >= 360.0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

BSS s32 N(AllConsumables)[ITEM_NUM_CONSUMABLES + 1];

API_CALLABLE(N(MakeAllConsumablesItemList)) {
    s32 i;

    for (i = 0; i < ITEM_NUM_CONSUMABLES; i++) {
        N(AllConsumables)[i] = ITEM_FIRST_CONSUMABLE + i;
    }
    N(AllConsumables)[i] = ITEM_NONE;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_GourmetGuy) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.5), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(N(MakeAllConsumablesItemList))
    Call(NpcFacePlayer, NPC_SELF, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Idle)
    IfEq(GF_OMO01_Met_GourmetGuy, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0040)
        Set(GF_OMO01_Met_GourmetGuy, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0041)
    EndIf
    EVT_CHOOSE_CONSUMABLE_FROM(N(AllConsumables), -1)
    IfLe(LVar0, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        Call(ResetCam, CAM_DEFAULT, Float(8.0 / DT))
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Set(LVar8, LVar0)
    Call(N(JudgeFoodQuality), LVar0)
    Call(MakeItemEntity, LVar8, -255, 35, 110, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVar7, LVar0)
    Call(SetItemFlags, LVar7, 64, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Eat)
    Loop(6)
        Wait(10 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
    EndLoop
    IfNe(LVar9, 2)
        Call(ResetCam, CAM_DEFAULT, Float(10.0 / DT))
        Wait(10 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SpitOut)
        Call(SetItemFlags, LVar7, 64, 0)
        Call(GetAngleToPlayer, NPC_SELF, LVar0)
        IfLt(LVar0, 180)
            Call(MakeLerp, 0, 100, 7 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                SetF(LVar2, Float(-1.0))
                SetF(LVar3, Float(-0.35))
                SetF(LVar4, Float(0.0))
                MulF(LVar2, LVar0)
                MulF(LVar3, LVar0)
                MulF(LVar4, LVar0)
                AddF(LVar2, Float(-270.0))
                AddF(LVar3, Float(35.0))
                AddF(LVar4, Float(110.0))
                Call(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 0, 100, 7 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                SetF(LVar2, Float(-1.0))
                SetF(LVar3, Float(0.35))
                SetF(LVar4, Float(0.0))
                MulF(LVar2, LVar0)
                MulF(LVar3, LVar0)
                MulF(LVar4, LVar0)
                AddF(LVar2, Float(-355.0))
                AddF(LVar3, Float(0.0))
                AddF(LVar4, Float(110.0))
                Call(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        Else
            Call(MakeLerp, 0, 100, 7 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                SetF(LVar2, Float(1.0))
                SetF(LVar3, Float(-0.35))
                SetF(LVar4, Float(0.0))
                MulF(LVar2, LVar0)
                MulF(LVar3, LVar0)
                MulF(LVar4, LVar0)
                AddF(LVar2, Float(-240.0))
                AddF(LVar3, Float(35.0))
                AddF(LVar4, Float(110.0))
                Call(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 0, 100, 7 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                SetF(LVar2, Float(1.0))
                SetF(LVar3, Float(0.35))
                SetF(LVar4, Float(0.0))
                MulF(LVar2, LVar0)
                MulF(LVar3, LVar0)
                MulF(LVar4, LVar0)
                AddF(LVar2, Float(-155.0))
                AddF(LVar3, Float(0.0))
                AddF(LVar4, Float(110.0))
                Call(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndIf
    EndIf
    Call(RemoveItemEntity, LVar7)
    Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Idle)
    Switch(LVar9)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0042)
            Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0043)
            Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        CaseEq(2)
            Thread
                Call(ShowMessageAtScreenPos, MSG_CH4_0044, 160, 40)
            EndThread
            Call(DisablePartnerAI, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Surprise)
            Thread
                Call(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_INVISIBLE, FALSE)
                Call(GetNpcPos, NPC_GourmetGuy_Fork, LVar0, LVar1, LVar2)
                Call(SetNpcJumpscale, NPC_GourmetGuy_Fork, Float(0.05))
                Call(NpcJump0, NPC_GourmetGuy_Fork, LVar0, 2, LVar2, 8 * DT)
                Call(SetNpcRotationPivot, NPC_GourmetGuy_Fork, 15)
                Set(LVar3, 0)
                Loop(5)
                    Add(LVar3, 50)
                    Call(SetNpcRotation, NPC_GourmetGuy_Fork, 0, 0, LVar3)
                    Wait(1)
                EndLoop
                Add(LVar2, 20)
                Call(SetNpcJumpscale, NPC_GourmetGuy_Fork, Float(0.2))
                Call(NpcJump0, NPC_GourmetGuy_Fork, LVar0, -10, LVar2, 8 * DT)
                Wait(10 * DT)
                Call(RemoveNpc, NPC_GourmetGuy_Fork)
            EndThread
            Thread
                Call(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_INVISIBLE, FALSE)
                Call(GetNpcPos, NPC_GourmetGuy_Knife, LVar0, LVar1, LVar2)
                Call(SetNpcJumpscale, NPC_GourmetGuy_Knife, Float(0.05))
                Call(NpcJump0, NPC_GourmetGuy_Knife, LVar0, 2, LVar2, 8 * DT)
                Call(SetNpcRotationPivot, NPC_GourmetGuy_Knife, 15)
                Set(LVar3, 0)
                Loop(5)
                    Sub(LVar3, 50)
                    Call(SetNpcRotation, NPC_GourmetGuy_Knife, 0, 0, LVar3)
                    Wait(1)
                EndLoop
                Add(LVar2, 20)
                Call(SetNpcJumpscale, NPC_GourmetGuy_Knife, Float(0.2))
                Call(NpcJump0, NPC_GourmetGuy_Knife, LVar0, -10, LVar2, 8 * DT)
                Wait(10 * DT)
                Call(RemoveNpc, NPC_GourmetGuy_Knife)
            EndThread
            Call(UseSettingsFrom, CAM_DEFAULT, -250, 25, -100)
            Call(SetPanTarget, CAM_DEFAULT, -250, 25, -100)
            Call(SetCamDistance, CAM_DEFAULT, Float(420.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-1.5))
            Call(SetCamSpeed, CAM_DEFAULT, Float(25.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_SHOCK_1, SOUND_SPACE_DEFAULT)
            Wait(33 * DT)
            Call(SetCamDistance, CAM_DEFAULT, Float(320.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(13.0), Float(-0.8))
            Call(SetCamSpeed, CAM_DEFAULT, Float(25.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_SHOCK_2, SOUND_SPACE_DEFAULT)
            Wait(33 * DT)
            Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(14.0), Float(0.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(25.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_SHOCK_3, SOUND_SPACE_DEFAULT)
            Wait(18 * DT)
            Call(SetMusicTrack, 0, SONG_GOURMET_GUY_FREAKOUT, 0, 8)
            Wait(30 * DT)
            Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
            Loop(7)
                Call(SetCamDistance, CAM_DEFAULT, Float(320.0))
                Call(SetCamPitch, CAM_DEFAULT, Float(14.0), Float(0.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(15.0 / DT))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
                Call(SetCamPitch, CAM_DEFAULT, Float(14.0), Float(0.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(15.0 / DT))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            EndLoop
            Call(RotateModel, MODEL_o331, 105, 0, 1, 0)
            Call(RotateModel, MODEL_o332, 105, 0, 1, 0)
            Call(RotateModel, MODEL_o333, 105, 0, 1, 0)
            Call(RotateModel, MODEL_o328, 105, 0, 1, 0)
            Call(RotateModel, MODEL_o329, 105, 0, 1, 0)
            Call(RotateModel, MODEL_o330, 105, 0, 1, 0)
            Wait(5 * DT)
            Call(N(SpinCameraAround))
            Call(N(SpinCameraAround))
            Call(N(SpinCameraAround))
            Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
            Call(UseSettingsFrom, CAM_DEFAULT, -250, 0, 100)
            Call(SetPanTarget, CAM_DEFAULT, -250, 0, 100)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(SetSelfVar, 0, 1)
            Thread
                Label(19)
                Call(PlayerFaceNpc, NPC_SELF, FALSE)
                Call(GetSelfVar, 0, LVar0)
                IfNe(LVar0, 0)
                    Wait(1)
                    Goto(19)
                EndIf
            EndThread
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
            Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Panic)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcSpeed, NPC_SELF, Float(20.0 / DT))
            Call(NpcMoveTo, NPC_SELF, 0, 110, 0)
            Wait(20 * DT)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_UPSIDE_DOWN, TRUE)
            Call(SetNpcPos, NPC_SELF, 0, 145, 110)
            Call(NpcMoveTo, NPC_SELF, -500, 110, 0)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_UPSIDE_DOWN, FALSE)
            Wait(20 * DT)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
            Call(SetNpcRotation, NPC_SELF, 0, 0, -45)
            Call(InterpNpcYaw, NPC_SELF, 90, 0)
            Call(MakeLerp, 0, 100, 30 * DT, EASING_LINEAR)
            Label(10)
            Call(UpdateLerp)
            SetF(LVar2, Float(3.95))
            SetF(LVar3, Float(-1.9))
            SetF(LVar4, Float(0.0))
            MulF(LVar2, LVar0)
            MulF(LVar3, LVar0)
            MulF(LVar4, LVar0)
            AddF(LVar2, Float(-445.0))
            AddF(LVar3, Float(130.0))
            AddF(LVar4, Float(230.0))
            Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
            Wait(20 * DT)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_RUN, SOUND_SPACE_DEFAULT)
            Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
            Call(SetNpcPos, NPC_SELF, -500, 0, 110)
            Call(NpcMoveTo, NPC_SELF, -250, 110, 0)
            Wait(20 * DT)
            Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_TalkSurprise)
            Thread
                Wait(15 * DT)
                Call(SetCamPitch, CAM_DEFAULT, Float(-2.5), Float(-24.0))
                Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
            EndThread
            Thread
                Wait(15 * DT)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_GOURMET_GUY_LAUNCH, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Leap)
                Call(SetNpcJumpscale, NPC_SELF, Float(0.002))
                Call(NpcJump0, NPC_SELF, -250, 500, 110, 40 * DT)
                Call(SetSelfVar, 0, 2)
            EndThread
            Call(ShowMessageAtScreenPos, MSG_CH4_0045, 160, 40)
            Label(12)
            Call(GetSelfVar, 0, LVar0)
            IfNe(LVar0, 2)
                Wait(1)
                Goto(12)
            EndIf
            Call(SetSelfVar, 0, 0)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(MakeItemEntity, ITEM_COOKBOOK, LVar0, 400, LVar2, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_OMO05_Item_Cookbook)
            Wait(30 * DT)
            Call(EnablePartnerAI)
            Wait(20 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
            Wait(1)
            Call(ResetCam, CAM_DEFAULT, Float(90.0))
            Wait(60 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
            Set(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
    EndSwitch
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerInput, FALSE)
    IfEq(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_GourmetGuy) = {
    IfGe(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
        Call(RemoveNpc, NPC_GourmetGuy_Fork)
        Call(RemoveNpc, NPC_GourmetGuy_Knife)
        Call(RemoveNpc, NPC_SELF)
    Else
        Call(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        Call(SetNpcAnimation, NPC_GourmetGuy_Fork, ANIM_GourmetGuy_Fork)
        Call(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_INVISIBLE, TRUE)
        Call(SetNpcPos, NPC_GourmetGuy_Fork, -285, 50, 90)
        Call(SetNpcAnimation, NPC_GourmetGuy_Knife, ANIM_GourmetGuy_Knife)
        Call(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_INVISIBLE, TRUE)
        Call(SetNpcPos, NPC_GourmetGuy_Knife, -210, 50, 90)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GourmetGuy)))
    EndIf
    Return
    End
};

NpcData N(NpcData_GourmetGuy)[] = {
    {
        .id = NPC_GourmetGuy,
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_GourmetGuy),
        .settings = &N(NpcSettings_GourmetGuy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = GOURMET_GUY_ANIMS,
        .tattle = MSG_NpcTattle_GourmetGuy,
    },
    {
        .id = NPC_GourmetGuy_Knife,
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_GourmetGuy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GOURMET_GUY_ANIMS,
        .tattle = MSG_NpcTattle_GourmetGuy,
    },
    {
        .id = NPC_GourmetGuy_Fork,
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .settings = &N(NpcSettings_GourmetGuy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GOURMET_GUY_ANIMS,
        .tattle = MSG_NpcTattle_GourmetGuy,
    },
};

NpcData N(NpcData_GrooveGuy) = {
    .id = NPC_GrooveGuy,
    .pos = { 320.0f, 10.0f, -145.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 320, 10, -145 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 320, 10, -145 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_GrooveGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = GROOVE_GUY_DROPS_A,
    .animations = GROOVE_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GourmetGuy)),
    NPC_GROUP(N(NpcData_GrooveGuy), BTL_OMO_FORMATION_2A, BTL_OMO_STAGE_06),
    {}
};
