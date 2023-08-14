#include "jan_11.h"
#include "sprite/player.h"

#include "world/common/npc/YoshiKid.inc.c"

EvtScript N(EVS_YoshiKid_CryForHelp) = {
    EVT_SET(AF_JAN_02, FALSE)
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        EVT_WAIT(20)
        EVT_IF_EQ(AF_JAN_02, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_NE(LVar0, 10)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(N(IsPartnerWatt))
        EVT_IF_EQ(LVar9, 0)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_LT(LVar2, 85)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
    EVT_IF_LT(LVar1, LVar4)
        EVT_SET(LVar1, LVar4)
        EVT_ADD(LVar1, -50)
    EVT_ELSE
        EVT_SET(LVar1, LVar4)
        EVT_ADD(LVar1, 30)
    EVT_END_IF
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(1.0))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 0)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_SUB(LVar4, LVar1)
    EVT_DIV(LVar4, 2)
    EVT_ADD(LVar1, LVar4)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), LVar4, 350, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_SET(AF_JAN_02, TRUE)
    EVT_WAIT(15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_SadTalk, ANIM_YoshiKid_Green_SadIdle, 0, MSG_CH5_00AE)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Green_Run)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -100, 50, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_JAN11_SavedYoshi, TRUE)
    EVT_SET(LVar0, 0)
    EVT_ADD(LVar0, GF_JAN05_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN07_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN08_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN10_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN11_SavedYoshi)
    EVT_IF_EQ(LVar0, 5)
        EVT_CALL(SetMusicTrack, 0, SONG_YOSHI_KIDS_FOUND, 0, 8)
        EVT_SET(GB_StoryProgress, STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        EVT_WAIT(120)
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_ELSE
        EVT_WAIT(35)
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_YoshiKid) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Cry, ANIM_YoshiKid_Green_Cry, 0, MSG_CH5_00AD)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_EXEC(N(EVS_YoshiKid_CryForHelp))
        EVT_IF_EQ(GF_JAN11_SavedYoshi, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Green_Cry)
            EVT_CALL(SetNpcPos, NPC_SELF, 132, 85, 11)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_YoshiKid)))
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -450.0f, 0.0f, -160.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = YOSHI_KID_GREEN_ANIMS,
    .tattle = MSG_NpcTattle_GreenYoshiKid,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_YoshiKid)),
    {}
};
