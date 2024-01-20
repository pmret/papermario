#include "mac_00.h"
#include "effects.h"

#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/enemy/ShyGuy_Stationary.inc.c"
#include "world/common/npc/Dummy.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

#include "npc/russ_and_thief.inc.c"

EvtScript N(EVS_NpcAI_ShyGuy_03) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim0C)
    Wait(10)
    Call(SetNpcAnimation, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim03)
    Call(SetNpcJumpscale, NPC_ShyGuy_02, Float(1.0))
    Call(PlaySoundAtNpc, NPC_ShyGuy_02, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_ShyGuy_02, 400, 20, -300, 20)
    Call(NpcFacePlayer, NPC_ShyGuy_02, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim11, ANIM_ShyGuy_Red_Anim01, 0, MSG_MAC_Gate_0002)
    Call(ShowSweat, NPC_ShyGuy_02, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Wait(10)
    Call(ShowSweat, NPC_ShyGuy_02, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Wait(10)
    Thread
        Call(SetPlayerSpeed, Float(2.0))
        Call(PlayerMoveTo, 410, -340, 0)
    EndThread
    Set(LVar0, 22)
    Call(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(EVS_ShyGuy_PlayRunningSounds), LVarA)
    Call(SetNpcSpeed, NPC_ShyGuy_02, Float(8.0))
    Call(NpcMoveTo, NPC_ShyGuy_02, 170, -140, 0)
    KillThread(LVarA)
    Call(SetNpcPos, NPC_ShyGuy_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Toad_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Toad_01, 170, 20, -140)
    Call(SetNpcFlagBits, NPC_Toad_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcSpeed, NPC_Toad_01, Float(8.0))
    Call(SetNpcAnimation, NPC_Toad_01, ANIM_HarryT_Run)
    Call(NpcMoveTo, NPC_Toad_01, 430, -373, 0)
    Call(SetNpcPos, NPC_Toad_01, 430, 20, -373)
    Call(SetNpcAnimation, NPC_Toad_01, ANIM_HarryT_Idle)
    Call(SetNpcFlagBits, NPC_Toad_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(NpcFacePlayer, NPC_Toad_01, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_Toad_01, ANIM_HarryT_Talk, ANIM_HarryT_Idle, 0, MSG_MAC_Gate_0003)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono4, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono5, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mono6, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

#include "world/common/util/CheckPositionRelativeToPlane.inc.c"

EvtScript N(EVS_NpcHit_ShyGuy_03) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Set(LVar1, 1)
        CaseEq(ENCOUNTER_TRIGGER_PARTNER)
            Set(LVar1, 1)
        CaseDefault
            Set(LVar1, 0)
    EndSwitch
    IfEq(LVar1, 0)
        Return
    EndIf
    Call(N(CheckPositionRelativeToPlane), 266, -350, 366, -253)
    IfEq(LVar0, PLANE_SIDE_POSITIVE)
        Return
    EndIf
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    Set(GF_MAC00_ShyGuyChasedFromShop, TRUE)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(SetEnemyFlagBits, NPC_ShyGuy_02, ENEMY_FLAG_CANT_INTERACT, 1)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_03)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_ShyGuy_02) = {
    Call(SpeakToPlayer, NPC_ShyGuy_02, ANIM_ShyGuy_Red_Anim11, ANIM_ShyGuy_Red_Anim01, 0, MSG_MAC_Gate_0001)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy_02) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            IfEq(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                Set(GF_MAC01_ShyGuyTookOverShop, TRUE)
                Call(SetNpcPos, NPC_SELF, 430, 20, -373)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ShyGuy_02)))
                Return
            EndIf
    EndSwitch
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_GardenShyGuy1) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            IfEq(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono1, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono2, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono3, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono4, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono5, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mono6, COLLIDER_FLAGS_UPPER_MASK)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_dummy, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
                Call(SetNpcPos, NPC_SELF, 430, 20, -373)
                Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_ShyGuy_03)))
                Return
            EndIf
    EndSwitch
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    ExecWait(EVS_ShopOwnerDialog)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MAC_Gate_0000)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            IfEq(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                Call(SetNpcPos, NPC_Toad_01, NPC_DISPOSE_LOCATION)
            EndIf
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            IfEq(GF_MAC00_ShyGuyChasedFromShop, FALSE)
                Call(SetNpcPos, NPC_SELF, 105, 0, -40)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
                Return
            EndIf
    EndSwitch
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

#include "npc/dojo_members.inc.c"
#include "npc/waterfront_family.inc.c"
#include "npc/trading_toad.inc.c"

NpcData N(NpcData_ShyGuy_01)[] = {
    {
        .id = NPC_ShyGuyThief,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuyThief),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_02),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShyGuyShopOwner,
    },
    {
        .id = NPC_GardenShyGuy1,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GardenShyGuy1),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShyGuyShopOwner,
    },
};

NpcData N(NpcData_RussT) = {
    .id = NPC_RussT,
    .pos = { -66.0f, 20.0f, -532.0f },
    .yaw = 119,
    .init = &N(EVS_NpcInit_RussT),
    .settings = &N(NpcSettings_RussT),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_RussT_Idle,
        .walk   = ANIM_RussT_Idle,
        .run    = ANIM_RussT_Idle,
        .chase  = ANIM_RussT_Idle,
        .anim_4 = ANIM_RussT_Idle,
        .anim_5 = ANIM_RussT_Idle,
        .death  = ANIM_RussT_Idle,
        .hit    = ANIM_RussT_Idle,
        .anim_8 = ANIM_RussT_Idle,
        .anim_9 = ANIM_RussT_Idle,
        .anim_A = ANIM_RussT_Idle,
        .anim_B = ANIM_RussT_Idle,
        .anim_C = ANIM_RussT_Idle,
        .anim_D = ANIM_RussT_Idle,
        .anim_E = ANIM_RussT_Idle,
        .anim_F = ANIM_RussT_Idle,
    },
    .tattle = MSG_NpcTattle_RussT,
};

NpcData N(NpcData_Toad_01)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { 430.0f, 20.0f, -373.0f },
        .yaw = 223,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
    {
        .id = NPC_Toad_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 223,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .tattle = MSG_NpcTattle_MAC00_ShopOwner,
    },
};

AnimID N(ExtraAnims_TheMaster)[] = {
    ANIM_TheMaster_Still,
    ANIM_TheMaster_Idle,
    ANIM_TheMaster_Walk,
    ANIM_TheMaster_Talk,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Chan)[] = {
    ANIM_Chan_Still,
    ANIM_Chan_Idle,
    ANIM_Chan_Walk,
    ANIM_Chan_Run,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Lee)[] = {
    ANIM_Lee_Still,
    ANIM_Lee_Idle,
    ANIM_Lee_Walk,
    ANIM_Lee_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Toad_03)[] = {
    {
        .id = NPC_TheMaster,
        .pos = { 375.0f, 115.0f, -440.0f },
        .yaw = 225,
        .init = &N(EVS_NpcInit_TheMaster),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_TheMaster_Idle,
            .walk   = ANIM_TheMaster_Still,
            .run    = ANIM_TheMaster_Still,
            .chase  = ANIM_TheMaster_Still,
            .anim_4 = ANIM_TheMaster_Still,
            .anim_5 = ANIM_TheMaster_Still,
            .death  = ANIM_TheMaster_Still,
            .hit    = ANIM_TheMaster_Still,
            .anim_8 = ANIM_TheMaster_Still,
            .anim_9 = ANIM_TheMaster_Still,
            .anim_A = ANIM_TheMaster_Still,
            .anim_B = ANIM_TheMaster_Still,
            .anim_C = ANIM_TheMaster_Still,
            .anim_D = ANIM_TheMaster_Still,
            .anim_E = ANIM_TheMaster_Still,
            .anim_F = ANIM_TheMaster_Still,
        },
        .extraAnimations = N(ExtraAnims_TheMaster),
        .tattle = MSG_NpcTattle_TheMaster,
    },
    {
        .id = NPC_Chan,
        .pos = { 310.0f, 115.0f, -390.0f },
        .yaw = 45,
        .init = &N(EVS_NpcInit_Chan),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Chan_Idle,
        },
        .extraAnimations = N(ExtraAnims_Chan),
        .tattle = MSG_NpcTattle_Chan,
    },
    {
        .id = NPC_Lee,
        .pos = { 330.0f, 115.0f, -410.0f },
        .yaw = 45,
        .init = &N(EVS_NpcInit_Lee),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Lee_Idle,
        },
        .extraAnimations = N(ExtraAnims_Lee),
        .tattle = MSG_NpcTattle_Lee,
    },
};

NpcData N(NpcData_Quizmo_Unused) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 545.0f, 20.0f, 150.0f },
    .yaw = 30,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_00 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcData N(NpcData_Waterfront_Family)[] = {
    {
        .id = NPC_Waterfront_Dad,
        .pos = { -496.0f, 20.0f, 218.0f },
        .yaw = 133,
        .init = &N(EVS_NpcInit_WaterfrontDad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_LuckyCastleWorker,
    },
    {
        .id = NPC_Waterfront_Mom,
        .pos = { -566.0f, 20.0f, 267.0f },
        .yaw = 133,
        .init = &N(EVS_NpcInit_WaterfrontMom),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_Homemaker,
    },
    {
        .id = NPC_Waterfront_Kid1,
        .pos = { -508.0f, 20.0f, 324.0f },
        .yaw = 313,
        .init = &N(EVS_NpcInit_WaterfrontKid1),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_FriendlyToadKid,
    },
    {
        .id = NPC_Waterfront_Kid2,
        .pos = { -480.0f, 20.0f, 329.0f },
        .yaw = 313,
        .init = &N(EVS_NpcInit_WaterfrontKid2),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_PowerHungryToadKid,
    },
};

NpcData N(NpcData_PrizeToad) = {
    .id = NPC_Toad_11,
    .pos = { -112.0f, 0.0f, -62.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_TradingToad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Toad_Pink_Idle,
        .walk   = ANIM_Toad_Pink_Walk,
        .run    = ANIM_Toad_Pink_Run,
        .chase  = ANIM_Toad_Pink_Run,
        .anim_4 = ANIM_Toad_Pink_Idle,
        .anim_5 = ANIM_Toad_Pink_Idle,
        .death  = ANIM_Toad_Pink_Idle,
        .hit    = ANIM_Toad_Pink_Disappointed,
        .anim_8 = ANIM_Toad_Pink_Run,
        .anim_9 = ANIM_Toad_Pink_Run,
        .anim_A = ANIM_Toad_Pink_Run,
        .anim_B = ANIM_Toad_Pink_Run,
        .anim_C = ANIM_Toad_Pink_Run,
        .anim_D = ANIM_Toad_Pink_Run,
        .anim_E = ANIM_Toad_Pink_Run,
        .anim_F = ANIM_Toad_Pink_Run,
    },
    .tattle = MSG_NpcTattle_PrizeToad,
};

extern NpcData N(NpcData_SharedTownsfolk)[10];

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Toad_03)),
    NPC_GROUP(N(NpcData_ShyGuy_01)),
    NPC_GROUP(N(NpcData_RussT)),
    NPC_GROUP(N(NpcData_Toad_01)),
    NPC_GROUP(N(NpcData_SharedTownsfolk)),
    NPC_GROUP(N(NpcData_Waterfront_Family)),
    NPC_GROUP(N(NpcData_PrizeToad)),
    {}
};
