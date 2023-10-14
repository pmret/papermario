#include "trd_01.h"
#include "entity.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_UnlockDoors);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_EnterMap) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_01_ENTRY_0)
            EVT_SET(LVar2, MODEL_ew_doa)
            EVT_SET(LVar3, MODEL_ew_doa2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(trd_01_ENTRY_1)
            EVT_SET(LVar2, MODEL_e2_doa)
            EVT_SET(LVar3, MODEL_e2_doa2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(trd_01_ENTRY_2)
            EVT_SET(LVar2, MODEL_e3_doa)
            EVT_SET(LVar3, MODEL_e3_doa2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(trd_01_ENTRY_3)
            EVT_SET(LVar2, MODEL_e4_doa)
            EVT_SET(LVar3, MODEL_e4_doa2)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_trd_00_1) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_0, "trd_00", trd_00_ENTRY_1, COLLIDER_ttw, MODEL_ew_doa, MODEL_ew_doa2);
EvtScript N(EVS_ExitDoors_trd_02_0) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_1, "trd_02", trd_02_ENTRY_0, COLLIDER_tte, MODEL_e2_doa, MODEL_e2_doa2);
EvtScript N(EVS_ExitDoors_trd_02_2) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_2, "trd_02", trd_02_ENTRY_2, COLLIDER_tte2, MODEL_e3_doa, MODEL_e3_doa2);
EvtScript N(EVS_ExitDoors_trd_09_0) = EVT_EXIT_DOUBLE_DOOR(trd_01_ENTRY_3, "trd_09", trd_09_ENTRY_0, COLLIDER_tte3, MODEL_e4_doa, MODEL_e4_doa2);

EvtScript N(EVS_Scene_RaiseStairs) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_WAIT(1)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_WAIT(20 * DT)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 220)
    EVT_SET(LVar2, 255)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, 12)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.4 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o162, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    EVT_CALL(PlaySound, SOUND_LOOP_TRD_FLOWING_WATER)
    EVT_CHILD_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_WAIT(4 * DT)
        EVT_CALL(EnableModel, MODEL_sui1, TRUE)
        EVT_CALL(EnableModel, MODEL_sui2, TRUE)
        EVT_CALL(EnableTexPanning, MODEL_sui1, TRUE)
        EVT_CALL(EnableTexPanning, MODEL_sui2, TRUE)
        EVT_CALL(EnableTexPanning, MODEL_o145, TRUE)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_AUX,  LVar2, LVar3)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar4, LVar5)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX,  LVar6, LVar7)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, LVar8, LVar9)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_AUX,  LVarA, LVarB)
            EVT_ADD(LVar0, -600)
            EVT_ADD(LVar1, -600)
            EVT_ADD(LVar2, -300)
            EVT_ADD(LVar3, -300)
            EVT_ADD(LVar4, 140)
            EVT_ADD(LVar5, -600)
            EVT_ADD(LVar6, -30)
            EVT_ADD(LVar7, -600)
            EVT_ADD(LVar8, 100)
            EVT_ADD(LVar9, -600)
            EVT_ADD(LVarA, -100)
            EVT_ADD(LVarB, -300)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_LOOP_TRD_RAISE_STAIRS)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20 * DT, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 250 * DT, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30 * DT, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(1.2))
        EVT_CALL(StopSound, SOUND_LOOP_TRD_RAISE_STAIRS)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(50 * DT)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 500, LVar2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_KoopaTroopa_02, LVar4, LVar5, LVar6)
        EVT_CALL(SetNpcPos, NPC_KoopaTroopa_02, LVar4, -27, LVar6)
        EVT_WAIT(100 * DT)
        EVT_CALL(MakeLerp, -27, 300, 210 * DT, EASING_QUADRATIC_OUT)
        EVT_LOOP(210 * DT)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_KoopaTroopa_02, LVar4, LVar0, LVar6)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaTroopa_02, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_KoopaTroopa_02, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(120 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaTroopa_02, ANIM_KoopaTroopa_ShellExit)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaTroopa_02, ANIM_KoopaTroopa_Panic)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaTroopa_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_KoopaTroopa_02, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
        EVT_LOOP(4)
            EVT_CALL(InterpNpcYaw, NPC_KoopaTroopa_02, 270, 0)
            EVT_WAIT(20 * DT)
            EVT_CALL(InterpNpcYaw, NPC_KoopaTroopa_02, 90, 0)
            EVT_WAIT(15 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(210 * DT)
        EVT_SET(NPC_KoopaTroopa_02_DonePanic, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_KoopaTroopa_03, LVar4, LVar5, LVar6)
        EVT_CALL(SetNpcPos, NPC_KoopaTroopa_03, LVar4, -27, LVar6)
        EVT_WAIT(85 * DT)
        EVT_CALL(MakeLerp, -27, 350, 215 * DT, EASING_QUADRATIC_OUT)
        EVT_LOOP(215 * DT)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_KoopaTroopa_03, LVar4, LVar0, LVar6)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(25 * DT)
        EVT_CALL(ShowEmote, NPC_KoopaTroopa_03, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(120 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaTroopa_03, ANIM_KoopaTroopa_ShellExit)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_KoopaTroopa_03, ANIM_KoopaTroopa_Panic)
        EVT_CALL(PlaySoundAtNpc, NPC_KoopaTroopa_03, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_KoopaTroopa_03, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
        EVT_LOOP(4)
            EVT_CALL(InterpNpcYaw, NPC_KoopaTroopa_03, 270, 0)
            EVT_WAIT(20 * DT)
            EVT_CALL(InterpNpcYaw, NPC_KoopaTroopa_03, 90, 0)
            EVT_WAIT(15 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(180 * DT)
        EVT_SET(NPC_KoopaTroopa_03_DonePanic, TRUE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, -450, 0, 300 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_dan, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_k_soku, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_k_kusari, 0, LVar0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o158)
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 400)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(EnableModel, MODEL_o145, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 375)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag1, FALSE)
            EVT_SET(LFlag1, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(TranslateModel, MODEL_o145, 50, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 350)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag2, FALSE)
            EVT_SET(LFlag2, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(TranslateModel, MODEL_o145, 100, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 325)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag3, FALSE)
            EVT_SET(LFlag3, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(TranslateModel, MODEL_o145, 150, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 299)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag4, FALSE)
            EVT_SET(LFlag4, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(TranslateModel, MODEL_o145, 200, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 273)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag5, FALSE)
            EVT_SET(LFlag5, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(TranslateModel, MODEL_o145, 250, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 245)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag6, FALSE)
            EVT_SET(LFlag6, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(TranslateModel, MODEL_o145, 300, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar2, LVar0)
    EVT_ADD(LVar2, 220)
    EVT_IF_GE(LVar2, -20)
        EVT_IF_EQ(LFlag7, FALSE)
            EVT_SET(LFlag7, TRUE)
            EVT_CALL(PlaySound, SOUND_TRD_WATER_SPLASH)
            EVT_CALL(EnableModel, MODEL_o145, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_WAIT(28 * DT)
        EVT_CALL(EnableModel, MODEL_sui1, FALSE)
        EVT_CALL(EnableModel, MODEL_sui2, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 220, 255)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(StopSound, SOUND_LOOP_TRD_FLOWING_WATER)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_suimenn, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        EVT_ADD(LVar0, 100)
        EVT_SUB(LVar1, 100)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

s32 N(KeyList)[] = {
    ITEM_KOOPA_FORTRESS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_00_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_IF_EQ(GF_TRD01_UnlockedDoor, FALSE)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockDoors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_02_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_09_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte3, 1, 0)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(AF_TRD01_RaiseStairs, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o158, MODEL_dan)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        EVT_SET(LVar0, -450)
        EVT_CALL(TranslateModel, MODEL_dan, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_k_soku, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_k_kusari, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o158)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_RaiseStairs)), TRIGGER_AREA_FLAG_SET, AF_TRD01_RaiseStairs, 0, 0)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o162, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_CALL(EnableModel, MODEL_sui1, FALSE)
    EVT_CALL(EnableModel, MODEL_sui2, FALSE)
    EVT_CALL(EnableModel, MODEL_o145, FALSE)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_CALL(EnableTexPanning, MODEL_suimenn, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
