#include "omo_05.h"

#include "world/common/enemy/complete/ShyGuy_Wander.inc.c"
#include "world/common/enemy/complete/GrooveGuy.inc.c"
#include "world/common/enemy/complete/SkyGuy.inc.c"

NpcSettings N(NpcSettings_GourmetGuy) = {
    .height = 68,
    .radius = 60,
    .level = 99,
};

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
    }
    return ApiStatus_BLOCK;
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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(N(MakeAllConsumablesItemList))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Idle)
    EVT_IF_EQ(GF_OMO01_Met_GourmetGuy, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0040)
        EVT_SET(GF_OMO01_Met_GourmetGuy, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0041)
    EVT_END_IF
    EVT_CHOOSE_CONSUMABLE_FROM(N(AllConsumables), -1)
    EVT_IF_LE(LVar0, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(8.0))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar8, LVar0)
    EVT_CALL(N(JudgeFoodQuality), LVar0)
    EVT_CALL(MakeItemEntity, LVar8, -255, 35, 110, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVar7, LVar0)
    EVT_CALL(SetItemFlags, LVar7, 64, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Eat)
    EVT_LOOP(6)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, SOUND_SPACE_MODE_0)
    EVT_END_LOOP
    EVT_IF_NE(LVar9, 2)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(10.0))
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2096, SOUND_SPACE_MODE_0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SpitOut)
        EVT_CALL(SetItemFlags, LVar7, 64, 0)
        EVT_CALL(GetAngleToPlayer, NPC_SELF, LVar0)
        EVT_IF_LT(LVar0, 180)
            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SETF(LVar2, EVT_FLOAT(-1.0))
                EVT_SETF(LVar3, EVT_FLOAT(-0.35))
                EVT_SETF(LVar4, EVT_FLOAT(0.0))
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar0)
                EVT_MULF(LVar4, LVar0)
                EVT_ADDF(LVar2, EVT_FLOAT(-270.0))
                EVT_ADDF(LVar3, EVT_FLOAT(35.0))
                EVT_ADDF(LVar4, EVT_FLOAT(110.0))
                EVT_CALL(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SETF(LVar2, EVT_FLOAT(-1.0))
                EVT_SETF(LVar3, EVT_FLOAT(0.35))
                EVT_SETF(LVar4, EVT_FLOAT(0.0))
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar0)
                EVT_MULF(LVar4, LVar0)
                EVT_ADDF(LVar2, EVT_FLOAT(-355.0))
                EVT_ADDF(LVar3, EVT_FLOAT(0.0))
                EVT_ADDF(LVar4, EVT_FLOAT(110.0))
                EVT_CALL(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_ELSE
            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SETF(LVar2, EVT_FLOAT(1.0))
                EVT_SETF(LVar3, EVT_FLOAT(-0.35))
                EVT_SETF(LVar4, EVT_FLOAT(0.0))
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar0)
                EVT_MULF(LVar4, LVar0)
                EVT_ADDF(LVar2, EVT_FLOAT(-240.0))
                EVT_ADDF(LVar3, EVT_FLOAT(35.0))
                EVT_ADDF(LVar4, EVT_FLOAT(110.0))
                EVT_CALL(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_SETF(LVar2, EVT_FLOAT(1.0))
                EVT_SETF(LVar3, EVT_FLOAT(0.35))
                EVT_SETF(LVar4, EVT_FLOAT(0.0))
                EVT_MULF(LVar2, LVar0)
                EVT_MULF(LVar3, LVar0)
                EVT_MULF(LVar4, LVar0)
                EVT_ADDF(LVar2, EVT_FLOAT(-155.0))
                EVT_ADDF(LVar3, EVT_FLOAT(0.0))
                EVT_ADDF(LVar4, EVT_FLOAT(110.0))
                EVT_CALL(SetItemPos, LVar7, LVar2, LVar3, LVar4)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveItemEntity, LVar7)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Idle)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0042)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GourmetGuy_Talk, ANIM_GourmetGuy_Idle, 0, MSG_CH4_0043)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH4_0044, 160, 40)
            EVT_END_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Surprise)
            EVT_THREAD
                EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_2, FALSE)
                EVT_CALL(GetNpcPos, NPC_GourmetGuy_Fork, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Fork, EVT_FLOAT(0.05))
                EVT_CALL(NpcJump0, NPC_GourmetGuy_Fork, LVar0, 2, LVar2, 8)
                EVT_CALL(SetNpcRotationPivot, NPC_GourmetGuy_Fork, 15)
                EVT_SET(LVar3, 0)
                EVT_LOOP(5)
                    EVT_ADD(LVar3, 50)
                    EVT_CALL(SetNpcRotation, NPC_GourmetGuy_Fork, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_ADD(LVar2, 20)
                EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Fork, EVT_FLOAT(0.2))
                EVT_CALL(NpcJump0, NPC_GourmetGuy_Fork, LVar0, -10, LVar2, 8)
                EVT_WAIT(10)
                EVT_CALL(RemoveNpc, NPC_GourmetGuy_Fork)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_2, FALSE)
                EVT_CALL(GetNpcPos, NPC_GourmetGuy_Knife, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Knife, EVT_FLOAT(0.05))
                EVT_CALL(NpcJump0, NPC_GourmetGuy_Knife, LVar0, 2, LVar2, 8)
                EVT_CALL(SetNpcRotationPivot, NPC_GourmetGuy_Knife, 15)
                EVT_SET(LVar3, 0)
                EVT_LOOP(5)
                    EVT_SUB(LVar3, 50)
                    EVT_CALL(SetNpcRotation, NPC_GourmetGuy_Knife, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_ADD(LVar2, 20)
                EVT_CALL(SetNpcJumpscale, NPC_GourmetGuy_Knife, EVT_FLOAT(0.2))
                EVT_CALL(NpcJump0, NPC_GourmetGuy_Knife, LVar0, -10, LVar2, 8)
                EVT_WAIT(10)
                EVT_CALL(RemoveNpc, NPC_GourmetGuy_Knife)
            EVT_END_THREAD
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 25, -100)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, 25, -100)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(420.0))
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-1.5))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(25.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_381, SOUND_SPACE_MODE_0)
            EVT_WAIT(33)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(13.0), EVT_FLOAT(-0.8))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(25.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_382, SOUND_SPACE_MODE_0)
            EVT_WAIT(33)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(14.0), EVT_FLOAT(0.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(25.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_383, SOUND_SPACE_MODE_0)
            EVT_WAIT(18)
            EVT_CALL(SetMusicTrack, 0, SONG_GOURMET_GUY_FREAKOUT, 0, 8)
            EVT_WAIT(30)
            EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
            EVT_LOOP(7)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(14.0), EVT_FLOAT(0.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(15.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(14.0), EVT_FLOAT(0.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(15.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_END_LOOP
            EVT_CALL(RotateModel, MODEL_o331, 105, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o332, 105, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o333, 105, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o328, 105, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o329, 105, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_o330, 105, 0, 1, 0)
            EVT_WAIT(5)
            EVT_CALL(N(SpinCameraAround))
            EVT_CALL(N(SpinCameraAround))
            EVT_CALL(N(SpinCameraAround))
            EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 0, 100)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, 0, 100)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(SetSelfVar, 0, 1)
            EVT_THREAD
                EVT_LABEL(19)
                EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_NE(LVar0, 0)
                    EVT_WAIT(1)
                    EVT_GOTO(19)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_384, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Panic)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(20.0))
            EVT_CALL(NpcMoveTo, NPC_SELF, 0, 110, 0)
            EVT_WAIT(20)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_384, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_UPSIDE_DOWN, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 0, 145, 110)
            EVT_CALL(NpcMoveTo, NPC_SELF, -500, 110, 0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_UPSIDE_DOWN, FALSE)
            EVT_WAIT(20)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_384, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, -45)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(MakeLerp, 0, 100, 30, EASING_LINEAR)
            EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, EVT_FLOAT(3.95))
            EVT_SETF(LVar3, EVT_FLOAT(-1.9))
            EVT_SETF(LVar4, EVT_FLOAT(0.0))
            EVT_MULF(LVar2, LVar0)
            EVT_MULF(LVar3, LVar0)
            EVT_MULF(LVar4, LVar0)
            EVT_ADDF(LVar2, EVT_FLOAT(-445.0))
            EVT_ADDF(LVar3, EVT_FLOAT(130.0))
            EVT_ADDF(LVar4, EVT_FLOAT(230.0))
            EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_384, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
            EVT_CALL(SetNpcPos, NPC_SELF, -500, 0, 110)
            EVT_CALL(NpcMoveTo, NPC_SELF, -250, 110, 0)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_TalkSurprise)
            EVT_THREAD
                EVT_WAIT(15)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-2.5), EVT_FLOAT(-24.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(15)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_385, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_Leap)
                EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.002))
                EVT_CALL(NpcJump0, NPC_SELF, -250, 500, 110, 40)
                EVT_CALL(SetSelfVar, 0, 2)
            EVT_END_THREAD
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH4_0045, 160, 40)
            EVT_LABEL(12)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_WAIT(1)
                EVT_GOTO(12)
            EVT_END_IF
            EVT_CALL(SetSelfVar, 0, 0)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_COOKBOOK, LVar0, 400, LVar2, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_OMO05_Item_Cookbook)
            EVT_WAIT(30)
            EVT_CALL(EnablePartnerAI)
            EVT_WAIT(20)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
            EVT_WAIT(1)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_WAIT(60)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GourmetGuy) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
        EVT_CALL(RemoveNpc, NPC_GourmetGuy_Fork)
        EVT_CALL(RemoveNpc, NPC_GourmetGuy_Knife)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GourmetGuy_SitIdle)
        EVT_CALL(SetNpcAnimation, NPC_GourmetGuy_Fork, ANIM_GourmetGuy_Fork)
        EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Fork, NPC_FLAG_2, TRUE)
        EVT_CALL(SetNpcPos, NPC_GourmetGuy_Fork, -285, 50, 90)
        EVT_CALL(SetNpcAnimation, NPC_GourmetGuy_Knife, ANIM_GourmetGuy_Knife)
        EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy_Knife, NPC_FLAG_2, TRUE)
        EVT_CALL(SetNpcPos, NPC_GourmetGuy_Knife, -210, 50, 90)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GourmetGuy)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_GourmetGuy)[] = {
    {
        .id = NPC_GourmetGuy,
        .settings = &N(NpcSettings_GourmetGuy),
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_GourmetGuy),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_GourmetGuy_Idle,
            .walk   = ANIM_GourmetGuy_Idle,
            .run    = ANIM_GourmetGuy_Idle,
            .chase  = ANIM_GourmetGuy_Idle,
            .anim_4 = ANIM_GourmetGuy_Idle,
            .anim_5 = ANIM_GourmetGuy_Idle,
            .death  = ANIM_GourmetGuy_Idle,
            .hit    = ANIM_GourmetGuy_Idle,
            .anim_8 = ANIM_GourmetGuy_Idle,
            .anim_9 = ANIM_GourmetGuy_Idle,
            .anim_A = ANIM_GourmetGuy_Idle,
            .anim_B = ANIM_GourmetGuy_Idle,
            .anim_C = ANIM_GourmetGuy_Idle,
            .anim_D = ANIM_GourmetGuy_Idle,
            .anim_E = ANIM_GourmetGuy_Idle,
            .anim_F = ANIM_GourmetGuy_Idle,
        },
        .tattle = MSG_NpcTattle_GourmetGuy,
    },
    {
        .id = NPC_GourmetGuy_Knife,
        .settings = &N(NpcSettings_GourmetGuy),
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_GourmetGuy_Idle,
            .walk   = ANIM_GourmetGuy_Idle,
            .run    = ANIM_GourmetGuy_Idle,
            .chase  = ANIM_GourmetGuy_Idle,
            .anim_4 = ANIM_GourmetGuy_Idle,
            .anim_5 = ANIM_GourmetGuy_Idle,
            .death  = ANIM_GourmetGuy_Idle,
            .hit    = ANIM_GourmetGuy_Idle,
            .anim_8 = ANIM_GourmetGuy_Idle,
            .anim_9 = ANIM_GourmetGuy_Idle,
            .anim_A = ANIM_GourmetGuy_Idle,
            .anim_B = ANIM_GourmetGuy_Idle,
            .anim_C = ANIM_GourmetGuy_Idle,
            .anim_D = ANIM_GourmetGuy_Idle,
            .anim_E = ANIM_GourmetGuy_Idle,
            .anim_F = ANIM_GourmetGuy_Idle,
        },
        .tattle = MSG_NpcTattle_GourmetGuy,
    },
    {
        .id = NPC_GourmetGuy_Fork,
        .settings = &N(NpcSettings_GourmetGuy),
        .pos = { -250.0f, 10.0f, 85.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_GourmetGuy_Idle,
            .walk   = ANIM_GourmetGuy_Idle,
            .run    = ANIM_GourmetGuy_Idle,
            .chase  = ANIM_GourmetGuy_Idle,
            .anim_4 = ANIM_GourmetGuy_Idle,
            .anim_5 = ANIM_GourmetGuy_Idle,
            .death  = ANIM_GourmetGuy_Idle,
            .hit    = ANIM_GourmetGuy_Idle,
            .anim_8 = ANIM_GourmetGuy_Idle,
            .anim_9 = ANIM_GourmetGuy_Idle,
            .anim_A = ANIM_GourmetGuy_Idle,
            .anim_B = ANIM_GourmetGuy_Idle,
            .anim_C = ANIM_GourmetGuy_Idle,
            .anim_D = ANIM_GourmetGuy_Idle,
            .anim_E = ANIM_GourmetGuy_Idle,
            .anim_F = ANIM_GourmetGuy_Idle,
        },
        .tattle = MSG_NpcTattle_GourmetGuy,
    },
};

StaticNpc N(NpcData_GrooveGuy) = {
    .id = NPC_GrooveGuy,
    .settings = &N(NpcSettings_GrooveGuy),
    .pos = { 320.0f, 10.0f, -145.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = GROOVE_GUY_DROPS_A,
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
    .animations = GROOVE_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GourmetGuy)),
    NPC_GROUP(N(NpcData_GrooveGuy), BTL_OMO_FORMATION_2A, BTL_OMO_STAGE_06),
    {}
};
