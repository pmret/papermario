#include "kkj_16.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Later

#include "world/common/enemy/HammerBros.inc.c"

AnimID N(ExtraAnims_HammerBros)[] = {
    ANIM_HammerBros_Anim00,
    ANIM_HammerBros_Anim02,
    ANIM_HammerBros_Anim03,
    ANIM_HammerBros_Anim04,
    ANIM_HammerBros_Anim06,
    ANIM_HammerBros_Anim07,
    ANIM_HammerBros_Anim09,
    ANIM_HammerBros_Anim0A,
    ANIM_HammerBros_Anim0B,
    ANIM_HammerBros_Anim1A,
    ANIM_LIST_END
};

#include "../common/Searchlights.inc.c"
#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/PreventNextPeachDisguise.inc.c"
#include "../common/ApproachPlayer50Units.inc.c"

EvtScript N(EVS_NpcInteract_HammerBros_01) = {
    IfEq(GF_KKJ16_Gift_ShootingStar, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 16, MSG_Peach_013A)
        Call(ShowGotItem, ITEM_SHOOTING_STAR, TRUE, ITEM_PICKUP_FLAG_NO_ANIMS)
        Set(GF_KKJ16_Gift_ShootingStar, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 16, MSG_Peach_013B)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_HammerBros_02) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0136)
        Call(SetSelfVar, 0, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0137)
        Call(SetSelfVar, 0, 0)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_HammerBros_03) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0138)
        Call(SetSelfVar, 0, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0139)
        Call(SetSelfVar, 0, 0)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_CapturePeach) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(PreventNextPeachDisguise))
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Wait(20)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
    Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0174)
    Call(N(ApproachPlayer50Units), -1, LVar3, LVar0, LVar2)
    IfNe(LVar3, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim07)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_Peach_0175)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    Wait(20)
    Call(GotoMapSpecial, Ref("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    Wait(100)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_WatchForPlayer) = {
    Loop(0)
        Call(N(GetPeachDisguise), LVar1)
        IfEq(LVar1, PEACH_DISGUISE_NONE)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
            Call(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            IfNe(LVar0, 0)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                Return
            EndIf
        Else
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_HammerBros_01) = {
    Exec(N(EVS_WatchForPlayer))
    Return
    End
};

EvtScript N(EVS_NpcIdle_HammerBros_02) = {
    Exec(N(EVS_WatchForPlayer))
    Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
    Call(SetNpcSpeed, NPC_SELF, Float(1.7))
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        Wait(20)
        Call(InterpNpcYaw, NPC_SELF, 90, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        Call(NpcMoveTo, NPC_SELF, 280, 50, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        Wait(20)
        Call(InterpNpcYaw, NPC_SELF, 270, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        Call(NpcMoveTo, NPC_SELF, 80, 50, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_HammerBros_03) = {
    Exec(N(EVS_WatchForPlayer))
    Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
    Call(SetNpcSpeed, NPC_SELF, Float(1.7))
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        Wait(30)
        Call(InterpNpcYaw, NPC_SELF, 270, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        Call(NpcMoveTo, NPC_SELF, -600, 50, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim02)
        Wait(30)
        Call(InterpNpcYaw, NPC_SELF, 90, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_HammerBros_Anim04)
        Call(NpcMoveTo, NPC_SELF, -420, 50, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_HammerBros_01) = {
    Call(SetNpcPos, NPC_SELF, -700, 0, 50)
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_HammerBros_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_HammerBros_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_HammerBros_02) = {
    Call(SetNpcPos, NPC_SELF, 180, 0, 50)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_HammerBros_02)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_HammerBros_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_HammerBros_03) = {
    Call(SetNpcPos, NPC_SELF, -510, 0, 50)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_HammerBros_03)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_HammerBros_03)))
    Return
    End
};

NpcData N(NpcData_Minions)[] = {
    {
        .id = NPC_HammerBros_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros_01),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
    {
        .id = NPC_HammerBros_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros_02),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
    {
        .id = NPC_HammerBros_03,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros_03),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
};

#define NAME_SUFFIX

NpcGroupList N(LaterNPCs) = {
    NPC_GROUP(N(NpcData_Minions_Later)),
    {}
};
