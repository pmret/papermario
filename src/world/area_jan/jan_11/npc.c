#include "jan_11.h"
#include "sprite/player.h"

#include "world/common/npc/YoshiKid.inc.c"

EvtScript N(EVS_YoshiKid_CryForHelp) = {
    Set(AF_JAN_02, FALSE)
    Loop(0)
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        Wait(20)
        IfEq(AF_JAN_02, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

#include "world/common/todo/GetFloorCollider.inc.c"

API_CALLABLE(N(IsPartnerWatt)) {
    if (gPartnerStatus.actingPartner == PARTNER_WATT) {
        script->varTable[9] = TRUE;
    } else {
        script->varTable[9] = FALSE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_YoshiKid) = {
    Label(0)
        Wait(1)
        Call(N(GetFloorCollider), LVar0)
        IfNe(LVar0, 10)
            Goto(0)
        EndIf
        Call(N(IsPartnerWatt))
        IfEq(LVar9, 0)
            Goto(0)
        EndIf
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        IfLt(LVar2, 85)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
    IfLt(LVar1, LVar4)
        Set(LVar1, LVar4)
        Add(LVar1, -50)
    Else
        Set(LVar1, LVar4)
        Add(LVar1, 30)
    EndIf
    Call(SetPlayerSpeed, Float(1.0))
    Call(PlayerMoveTo, LVar1, LVar3, 0)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Sub(LVar4, LVar1)
    Div(LVar4, 2)
    Add(LVar1, LVar4)
    Call(AdjustCam, CAM_DEFAULT, Float(4.0), LVar4, 350, Float(17.0), Float(-7.0))
    Set(AF_JAN_02, TRUE)
    Wait(15)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Thread
        Wait(10)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_SadTalk, ANIM_YoshiKid_Green_SadIdle, 0, MSG_CH5_00AE)
    Call(EndSpeech, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0)
    Thread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Green_Run)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, -100, 50, 0)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Set(GF_JAN11_SavedYoshi, TRUE)
    Set(LVar0, 0)
    Add(LVar0, GF_JAN05_SavedYoshi)
    Add(LVar0, GF_JAN07_SavedYoshi)
    Add(LVar0, GF_JAN08_SavedYoshi)
    Add(LVar0, GF_JAN10_SavedYoshi)
    Add(LVar0, GF_JAN11_SavedYoshi)
    IfEq(LVar0, 5)
        Call(SetMusic, 0, SONG_YOSHI_KIDS_FOUND, 0, VOL_LEVEL_FULL)
        Set(GB_StoryProgress, STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        Call(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        Wait(120)
        Exec(N(EVS_SetupMusic))
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Else
        Wait(35)
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Cry, ANIM_YoshiKid_Green_Cry, 0, MSG_CH5_00AD)
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    IfEq(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        Exec(N(EVS_YoshiKid_CryForHelp))
        IfEq(GF_JAN11_SavedYoshi, FALSE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Green_Cry)
            Call(SetNpcPos, NPC_SELF, 132, 85, 11)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_YoshiKid)))
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid)))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -450.0f, 0.0f, -160.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = YOSHI_KID_GREEN_ANIMS,
    .tattle = MSG_NpcTattle_GreenYoshiKid,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_YoshiKid)),
    {}
};
