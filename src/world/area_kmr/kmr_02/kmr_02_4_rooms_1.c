#include "kmr_02.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Rooms1
#include "world/common/npc/GoombaFamily_Wander.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_SetDoorRot_House) = {
    Call(RotateModel, MODEL_syoumen_enter, LVar0, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropDoor_House) = {
    Call(RotateModel, MODEL_syoumen_enter, LVar0, Float(54.56), 0, Float(31.5))
    Return
    End
};

EvtScript N(EVS_SetWallRot_House) = {
    Call(RotateModel, MODEL_door_ki, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o122, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o123, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o121, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o137, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o140, LVar0, -1, 0, 0)
    IfEq(LVar0, 90)
        Call(EnableModel, MODEL_door_ki, FALSE)
        Call(EnableModel, MODEL_o122, FALSE)
        Call(EnableModel, MODEL_o123, FALSE)
        Call(EnableModel, MODEL_o121, FALSE)
        Call(EnableModel, MODEL_o137, FALSE)
    Else
        Call(EnableModel, MODEL_door_ki, TRUE)
        Call(EnableModel, MODEL_o122, TRUE)
        Call(EnableModel, MODEL_o123, TRUE)
        Call(EnableModel, MODEL_o121, TRUE)
        Call(EnableModel, MODEL_o137, TRUE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_Goombario_NoAI) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_Goombario) = {
    ExecWait(N(EVS_NpcAI_GoombaFamily_Wander_Rooms1))
    Return
    End
};

EvtScript N(EVS_RoomListener_House) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(SetGroupVisibility, MODEL_of, MODEL_GROUP_VISIBLE)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            // do nothing
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            IfEq(GB_StoryProgress, STORY_CH0_MET_GOOMPA)
                IfEq(GF_KMR02_Met_Goompapa, TRUE)
                    IfEq(GF_KMR02_Goombario_RelayedMessage, FALSE)
                        Call(DisablePlayerInput, TRUE)
                        Call(BindNpcAI, NPC_Goombario, Ref(N(EVS_NpcAI_Goombario_NoAI)))
                        Call(SetNpcPos, NPC_Goombario, -54, 0, -55)
                    EndIf
                EndIf
            EndIf
        CaseEq(ROOM_UPDATE_EXIT_END)
            Call(SetGroupVisibility, MODEL_of, MODEL_GROUP_HIDDEN)
            IfEq(GB_StoryProgress, STORY_CH0_MET_GOOMPA)
                IfEq(GF_KMR02_Met_Goompapa, TRUE)
                    IfEq(GF_KMR02_Goombario_RelayedMessage, FALSE)
                        Call(SetNpcAnimation, NPC_Goombario, ANIM_WorldGoombario_Walk)
                        Call(NpcMoveTo, NPC_Goombario, 8, -94, 20)
                        Call(SpeakToPlayer, NPC_Goombario, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH0_0050)
                        Call(BindNpcAI, NPC_Goombario, Ref(N(EVS_NpcAI_Goombario)))
                        Set(GF_KMR02_Goombario_RelayedMessage, TRUE)
                        Call(DisablePlayerInput, FALSE)
                    EndIf
                EndIf
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetDoorRot_Verdana) = {
    Call(RotateModel, MODEL_ura_exit, LVar0, 0, -1, 0)
    Return
    End
};

EvtScript N(EVS_SetWallRot_Verdana) = {
    Return
    End
};

EvtScript N(EVS_RoomListener_Verdana) = {
    Switch(LVar0)
        CaseEq(ROOM_UPDATE_ENTER_BEGIN)
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
        CaseEq(ROOM_UPDATE_ENTER_DONE)
            Wait(30 * DT)
            Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
        CaseEq(ROOM_UPDATE_EXIT_BEGIN)
            IfGt(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                IfLt(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_DangerSealed, 160, 40)
                    Set(LVar0, -1)
                    Return
                EndIf
            EndIf
            Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_VISIBLE)
            Call(UseSettingsFrom, CAM_DEFAULT, 499, 0, -378)
            Call(SetPanTarget, CAM_DEFAULT, 499, 70, -378)
            Call(SetCamDistance, CAM_DEFAULT, 370)
            Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH0_GATE_CRUSHED)
                CaseLt(STORY_CH0_FELL_OFF_CLIFF)
                    Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
                    Call(DisablePlayerInput, TRUE)
                CaseLt(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
                CaseGe(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    Call(EnableModel, MODEL_o437, FALSE)
                    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o625, COLLIDER_FLAGS_UPPER_MASK)
            EndSwitch
        CaseEq(ROOM_UPDATE_EXIT_END)
            IfGe(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                IfLt(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
                    Wait(12)
                    IfEq(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                        Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
                        Loop(3)
                            Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_VISIBLE)
                            Wait(10 * DT)
                            Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
                            Wait(10 * DT)
                        EndLoop
                        Call(FadeOutMusic, 0, 0)
                        Call(SetPlayerAnimation, ANIM_MarioW2_Surprise)
                        Wait(30 * DT)
                        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                        Call(InterpPlayerYaw, 233, 1)
                        Wait(10 * DT)
                        Call(InterpPlayerYaw, 53, 1)
                        Wait(15 * DT)
                        Call(InterpPlayerYaw, 233, 1)
                        Wait(3 * DT)
                        Call(InterpPlayerYaw, 53, 1)
                        Wait(3 * DT)
                        Wait(10 * DT)
                        Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
                        Wait(30 * DT)
                        Set(GB_StoryProgress, STORY_CH0_FELL_OFF_CLIFF)
                    EndIf
                    Call(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
                    Wait(5 * DT)
                    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
                    Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Sub(LVar1, 150)
                    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    Call(PlaySoundAtPlayer, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
                    Call(DisablePlayerPhysics, TRUE)
                    Call(DisablePartnerAI, 0)
                    Call(SetPlayerAnimation, ANIM_MarioW2_Panic)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Thread
                        Loop(0)
                            Sub(LVar1, 16 / DT)
                            Call(SetPlayerPos, LVar0, LVar1, LVar2)
                            Wait(1)
                        EndLoop
                    EndThread
                    IfGt(GB_StoryProgress, STORY_CH0_GATE_CRUSHED)
                        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        Thread
                            Loop(0)
                                Sub(LVar1, 16 / DT)
                                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                                Wait(1)
                            EndLoop
                        EndThread
                    EndIf
                    Wait(20 * DT)
                    Call(GotoMap, Ref("kmr_03"), kmr_03_ENTRY_2)
                    Wait(100 * DT)
                EndIf
            EndIf
    EndSwitch
    Return
    End
};

MAP_RODATA_PAD(1,unk);

s32 N(InsideNPCs_House)[] = {
    NPC_Gooma,
    NPC_Goompa,
    -1
};

EvtScript N(EVS_SetupRooms) = {
    // goomba family home, main room
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_RIGHT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_House)),
        Ref(N(EVS_SetWallRot_House)),
        Ref(N(EVS_DropDoor_House)),
        Ref(N(EVS_RoomListener_House)),
        COLLIDER_deilit5,
        COLLIDER_deilit6,
        MODEL_kuribou_house,
        Ref(N(InsideNPCs_House)))
    // verdana
    Call(CreateMapRoom,
        PACK_ROOM_FLAGS(VIS_GROUP_0, ROOM_LARGE_DOOR_LEFT_HINGE_OPENS_OUT),
        Ref(N(EVS_SetDoorRot_Verdana)),
        Ref(N(EVS_SetWallRot_Verdana)),
        NULL,
        Ref(N(EVS_RoomListener_Verdana)),
        COLLIDER_deilit4,
        COLLIDER_deilit4_1,
        MODEL_kuribou_house,
        Ref(N(InsideNPCs_House)))
    Set(LVar0, ROOM_UPDATE_EXIT_END)
    Exec(N(EVS_RoomListener_House))
    Call(SetGroupVisibility, MODEL_monohoshi, MODEL_GROUP_HIDDEN)
    Return
    End
};

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    IfEq(GF_KMR02_ToadHouse_Intro, FALSE)
        Set(LVar0, MSG_CH0_0013)
        Set(LVar8, MSG_CH0_0013)
        Set(GF_KMR02_ToadHouse_Intro, TRUE)
    Else
        Set(LVar0, MSG_CH0_0014)
        Set(LVar8, MSG_CH0_0015)
    EndIf
    Set(LVar1, MSG_CH0_0016)
    Set(LVar2, MSG_CH0_0017)
    Set(LVar3, MSG_CH0_0018)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Thread
        Wait(20)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamPitch, CAM_DEFAULT, 34, -8)
        Call(SetCamDistance, CAM_DEFAULT, 220)
        Call(SetCamPosA, CAM_DEFAULT, Float(-46.0), Float(-311.0))
        Call(SetCamPosB, CAM_DEFAULT, Float(-262.4), Float(-324.6))
        Call(SetCamPosC, CAM_DEFAULT, 1, 10)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -212, -376, 0)
    Call(InterpPlayerYaw, 191, 1)
    Call(SetPlayerPos, -212, 21, -376)
    Wait(5)
    Call(InterpPlayerYaw, 114, 1)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Wait(61)
    Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    Thread
        Wait(70)
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
    Call(SetPlayerPos, -183, 19, -341)
    Call(PlayerMoveTo, -132, -325, 20)
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadHouse) = {
    ExecWait(N(EVS_NpcInteract_ToadHouseKeeper))
    Return
    End
};
