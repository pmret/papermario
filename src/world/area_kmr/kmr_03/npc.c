#include "kmr_03.h"
#include "sprite/player.h"

#include "world/common/util/ChangeNpcToPartner.inc.c"

#include "world/common/todo/CheckPartnerFlags1000.inc.c"

API_CALLABLE(N(func_802401B0_8C8140)) {
    Npc* npc = get_npc_unsafe(NPC_Goompa);

    script->varTable[1] = get_xz_dist_to_player(npc->pos.x, npc->pos.z) / npc->moveSpeed * 0.8f;
    return ApiStatus_DONE2;
}

#include "world/common/util/CheckPositionRelativeToPlane.inc.c"

NpcSettings N(NpcSettings_Goompa) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

EvtScript N(EVS_NpcAux_Goompa) = {
    Label(1)
    IfEq(AF_KMR_08, true)
        Label(100)
        Call(AwaitPlayerLeave, 294, 123, 170)
        Call(EnableNpcAI, NPC_Goompa, false)
        Call(DisablePlayerInput, true)
        Call(SetNpcSpeed, NPC_Goompa, Float(4.0))
        Call(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Run)
        Call(N(func_802401B0_8C8140))
        Call(GetAngleToPlayer, NPC_Goompa, LVar2)
        Loop(LVar1)
            Call(GetNpcPos, NPC_Goompa, LVar7, LVar8, LVar9)
            Call(AddVectorPolar, LVar7, LVar9, Float(4.0), LVar2)
            Call(SetNpcPos, NPC_Goompa, LVar7, LVar8, LVar9)
            Wait(1)
        EndLoop
        Call(PlayerFaceNpc, NPC_Goompa, 3)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, 243, 243, 0)
        Call(SetNpcVar, NPC_Goompa, 0, 1)
        Call(EnableNpcAI, NPC_Goompa, true)
        Call(DisablePlayerInput, false)
        Goto(100)
    EndIf
    Wait(1)
    Goto(1)
    Return
    End
};

EvtScript N(EVS_NpcAI_Goompa) = {
    Label(1)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH0_FELL_OFF_CLIFF)
            Label(89)
            Call(N(CheckPositionRelativeToPlane), -118, 86, -70, -15)
            Wait(1)
            IfEq(LVar0, 0)
                Goto(89)
            EndIf
            Call(DisablePlayerInput, true)
            Call(SetNpcAux, NPC_Goompa, 0)
            Call(PlaySoundAtNpc, NPC_Goompa, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
            Call(ShowEmote, NPC_Goompa, EMOTE_EXCLAMATION, 45, 15, EMOTER_NPC, 0, 0, 0, 0)
            Wait(15 * DT)
            Call(NpcFacePlayer, NPC_SELF, 5)
            Wait(10 * DT)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A6)
            Call(UseSettingsFrom, CAM_DEFAULT, -220, 20, -72)
            Call(SetPanTarget, CAM_DEFAULT, -20, 0, 68)
            Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-8.5))
            Call(SetCamDistance, CAM_DEFAULT, 275)
            Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Thread
                Wait(20 * DT)
                Call(SetPlayerSpeed, Float(2.0))
                Call(PlayerMoveTo, -38, 68, 0)
            EndThread
            Call(GetNpcPos, NPC_Goompa, LVar7, LVar8, LVar9)
            Call(SetNpcSpeed, NPC_Goompa, Float(4.0 / DT))
            Call(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Run)
            Call(NpcMoveTo, NPC_Goompa, 0, 70, 0)
            Call(SetNpcAnimation, NPC_Goompa, ANIM_Goompa_Idle)
            Call(InterpNpcYaw, NPC_Goompa, 276, 20 * DT)
            Wait(30 * DT)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A7)
            Wait(5 * DT)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(30 * DT)
            Call(SpeakToPlayer, NPC_Goompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A8)
            Call(N(ChangeNpcToPartner), 0, 5)
            Set(GB_StoryProgress, STORY_CH0_GOOMPA_JOINED_PARTY)
            Call(UseSettingsFrom, CAM_DEFAULT, -220, 20, -72)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PanToTarget, CAM_DEFAULT, 0, false)
            Call(EnablePartnerAI)
            Call(DisablePlayerInput, false)
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_Goompa) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Injured)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Idle)
    Add(MV_Unk_00, 1)
    IfLt(MV_Unk_00, 3)
        Call(GetOwnerEncounterTrigger, LVar0)
        Switch(LVar0)
            CaseEq(ENCOUNTER_TRIGGER_JUMP)
                Call(SetNpcVar, NPC_Goompa, 0, 1)
                IfEq(AF_KMR_06, true)
                Else
                    Set(AF_KMR_06, true)
                    Set(AF_KMR_07, false)
                EndIf
            CaseEq(ENCOUNTER_TRIGGER_HAMMER)
                Call(SetNpcVar, NPC_Goompa, 0, 1)
                IfEq(AF_KMR_07, true)
                Else
                    Set(AF_KMR_06, false)
                    Set(AF_KMR_07, true)
                EndIf
        EndSwitch
        Wait(10)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Goompa_Run)
    Else
        Wait(10)
        Call(GetNpcPos, NPC_Goompa, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, true)
        Call(SetNpcPos, NPC_Goompa, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_Goompa, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
        Call(EnablePartnerAI)
        Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Goompa)))
        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Goompa)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Goompa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_Goompa)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_Goompa)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Goompa)))
    Switch(GB_StoryProgress)
        CaseGe(STORY_CH0_GOOMPA_JOINED_PARTY)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, false)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, true)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_GoombaFamily) = {
    .id = NPC_Goompa,
    .pos = { -50.0f, 0.0f, 80.0f },
    .yaw = 45,
    .init = &N(EVS_NpcInit_Goompa),
    .settings = &N(NpcSettings_Goompa),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Goompa_Idle,
        .walk   = ANIM_Goompa_Walk,
        .run    = ANIM_Goompa_Run,
        .chase  = ANIM_Goompa_Run,
        .anim_4 = ANIM_Goompa_Idle,
        .anim_5 = ANIM_Goompa_Idle,
        .death  = ANIM_Goompa_Still,
        .hit    = ANIM_Goompa_Still,
        .anim_8 = ANIM_Goompa_Run,
        .anim_9 = ANIM_Goompa_Run,
        .anim_A = ANIM_Goompa_Run,
        .anim_B = ANIM_Goompa_Run,
        .anim_C = ANIM_Goompa_Run,
        .anim_D = ANIM_Goompa_Run,
        .anim_E = ANIM_Goompa_Run,
        .anim_F = ANIM_Goompa_Run,
    },
    .tattle = MSG_NpcTattle_Goompa,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GoombaFamily), BTL_KMR_1_FORMATION_02),
    {}
};
