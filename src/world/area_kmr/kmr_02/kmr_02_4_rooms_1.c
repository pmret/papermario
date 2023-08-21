#include "kmr_02.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Rooms1
#include "world/common/npc/GoombaFamily_Wander.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_SetDoorRot_House) = {
    EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDoor_House) = {
    EVT_CALL(RotateModel, MODEL_syoumen_enter, LVar0, EVT_FLOAT(54.56), 0, EVT_FLOAT(31.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_House) = {
    EVT_CALL(RotateModel, MODEL_door_ki, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o122, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o123, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o121, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o137, LVar0, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o140, LVar0, -1, 0, 0)
    EVT_IF_EQ(LVar0, 90)
        EVT_CALL(EnableModel, MODEL_door_ki, FALSE)
        EVT_CALL(EnableModel, MODEL_o122, FALSE)
        EVT_CALL(EnableModel, MODEL_o123, FALSE)
        EVT_CALL(EnableModel, MODEL_o121, FALSE)
        EVT_CALL(EnableModel, MODEL_o137, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_door_ki, TRUE)
        EVT_CALL(EnableModel, MODEL_o122, TRUE)
        EVT_CALL(EnableModel, MODEL_o123, TRUE)
        EVT_CALL(EnableModel, MODEL_o121, TRUE)
        EVT_CALL(EnableModel, MODEL_o137, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Goombario_NoAI) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Goombario) = {
    EVT_EXEC_WAIT(N(EVS_NpcAI_GoombaFamily_Wander_Rooms1))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_House) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(SetGroupVisibility, MODEL_of, MODEL_GROUP_VISIBLE)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH0_MET_GOOMPA)
                EVT_IF_EQ(GF_KMR02_Met_Goompapa, TRUE)
                    EVT_IF_EQ(GF_KMR02_Goombario_RelayedMessage, FALSE)
                        EVT_CALL(DisablePlayerInput, TRUE)
                        EVT_CALL(BindNpcAI, NPC_Goombario, EVT_PTR(N(EVS_NpcAI_Goombario_NoAI)))
                        EVT_CALL(SetNpcPos, NPC_Goombario, -54, 0, -55)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_CALL(SetGroupVisibility, MODEL_of, MODEL_GROUP_HIDDEN)
            EVT_IF_EQ(GB_StoryProgress, STORY_CH0_MET_GOOMPA)
                EVT_IF_EQ(GF_KMR02_Met_Goompapa, TRUE)
                    EVT_IF_EQ(GF_KMR02_Goombario_RelayedMessage, FALSE)
                        EVT_CALL(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Walk)
                        EVT_CALL(NpcMoveTo, NPC_Goombario, 8, -94, 20)
                        EVT_CALL(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0050)
                        EVT_CALL(BindNpcAI, NPC_Goombario, EVT_PTR(N(EVS_NpcAI_Goombario)))
                        EVT_SET(GF_KMR02_Goombario_RelayedMessage, TRUE)
                        EVT_CALL(DisablePlayerInput, FALSE)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRot_Verdana) = {
    EVT_CALL(RotateModel, MODEL_ura_exit, LVar0, 0, -1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetWallRot_Verdana) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RoomListener_Verdana) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_BEGIN)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CASE_EQ(ROOM_UPDATE_ENTER_DONE)
            EVT_WAIT(30 * DT)
            EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_BEGIN)
            EVT_IF_GT(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_DangerSealed, 160, 40)
                    EVT_SET(LVar0, -1)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_VISIBLE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 499, 0, -378)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 499, 70, -378)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 370)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_SWITCH(GB_StoryProgress)
                EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
                EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
                    EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
                    EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CASE_LT(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
                EVT_CASE_GE(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    EVT_CALL(EnableModel, MODEL_o437, FALSE)
                    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o625, COLLIDER_FLAGS_UPPER_MASK)
            EVT_END_SWITCH
        EVT_CASE_EQ(ROOM_UPDATE_EXIT_END)
            EVT_IF_GE(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    EVT_WAIT(12)
                    EVT_IF_EQ(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
                        EVT_LOOP(3)
                            EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_VISIBLE)
                            EVT_WAIT(10 * DT)
                            EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
                            EVT_WAIT(10 * DT)
                        EVT_END_LOOP
                        EVT_CALL(FadeOutMusic, 0, 0)
                        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Surprise)
                        EVT_WAIT(30 * DT)
                        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                        EVT_CALL(InterpPlayerYaw, 233, 1)
                        EVT_WAIT(10 * DT)
                        EVT_CALL(InterpPlayerYaw, 53, 1)
                        EVT_WAIT(15 * DT)
                        EVT_CALL(InterpPlayerYaw, 233, 1)
                        EVT_WAIT(3 * DT)
                        EVT_CALL(InterpPlayerYaw, 53, 1)
                        EVT_WAIT(3 * DT)
                        EVT_WAIT(10 * DT)
                        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Flail)
                        EVT_WAIT(30 * DT)
                        EVT_SET(GB_StoryProgress, STORY_CH0_FELL_OFF_CLIFF)
                    EVT_END_IF
                    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
                    EVT_WAIT(5 * DT)
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
                    EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar1, 150)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(PlaySoundAtPlayer, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
                    EVT_CALL(DisablePlayerPhysics, TRUE)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Panic)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_THREAD
                        EVT_LOOP(0)
                            EVT_SUB(LVar1, 16 / DT)
                            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_IF_GT(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        EVT_THREAD
                            EVT_LOOP(0)
                                EVT_SUB(LVar1, 16 / DT)
                                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                                EVT_WAIT(1)
                            EVT_END_LOOP
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_WAIT(20 * DT)
                    EVT_CALL(GotoMap, EVT_PTR("kmr_03"), kmr_03_ENTRY_2)
                    EVT_WAIT(100 * DT)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1,unk);

s32 N(InsideNPCs_House)[] = {
    NPC_Gooma,
    NPC_Goompa,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // goomba family home, main room
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_House)),
        EVT_PTR(N(EVS_SetWallRot_House)),
        EVT_PTR(N(EVS_DropDoor_House)),
        EVT_PTR(N(EVS_RoomListener_House)),
        COLLIDER_deilit5,
        COLLIDER_deilit6,
        MODEL_kuribou_house,
        EVT_PTR(N(InsideNPCs_House)))
    // verdana
    EVT_CALL(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_LEFT_HINGE_OPENS_OUT),
        EVT_PTR(N(EVS_SetDoorRot_Verdana)),
        EVT_PTR(N(EVS_SetWallRot_Verdana)),
        NULL,
        EVT_PTR(N(EVS_RoomListener_Verdana)),
        COLLIDER_deilit4,
        COLLIDER_deilit4_1,
        MODEL_kuribou_house,
        EVT_PTR(N(InsideNPCs_House)))
    EVT_SET(LVar0, ROOM_UPDATE_EXIT_END)
    EVT_EXEC(N(EVS_RoomListener_House))
    EVT_CALL(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_IF_EQ(GF_KMR02_ToadHouse_Intro, FALSE)
        EVT_SET(LVar0, MSG_CH0_0013)
        EVT_SET(LVar8, MSG_CH0_0013)
        EVT_SET(GF_KMR02_ToadHouse_Intro, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, MSG_CH0_0014)
        EVT_SET(LVar8, MSG_CH0_0015)
    EVT_END_IF
    EVT_SET(LVar1, MSG_CH0_0016)
    EVT_SET(LVar2, MSG_CH0_0017)
    EVT_SET(LVar3, MSG_CH0_0018)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 34, -8)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 220)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-46.0), EVT_FLOAT(-311.0))
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-262.4), EVT_FLOAT(-324.6))
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 1, 10)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -212, -376, 0)
    EVT_CALL(InterpPlayerYaw, 191, 1)
    EVT_CALL(SetPlayerPos, -212, 21, -376)
    EVT_WAIT(5)
    EVT_CALL(InterpPlayerYaw, 114, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_WAIT(61)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_THREAD
        EVT_WAIT(70)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -183, 19, -341)
    EVT_CALL(PlayerMoveTo, -132, -325, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadHouse) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ToadHouseKeeper))
    EVT_RETURN
    EVT_END
};
