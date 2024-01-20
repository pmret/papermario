#include "nok_02.h"
#include "sprite/player.h"

#include "world/common/npc/Koopa_Wander.inc.c"
#include "world/common/npc/KoopaWithoutShell_Patrol.inc.c"
#include "world/common/npc/Koopa.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/KoloradoWife.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/npc/KoopaKoot.inc.c"
#include "world/common/npc/Bobomb.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/KeyItemChoice.inc.c"

#include "world/common/atomic/MarioSalute.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Kolorado)[] = {
    ITEM_LETTER_TO_KOLORADO, ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    Call(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH1_0097, MSG_CH1_0098, MSG_CH1_0099, MSG_CH1_009A,
        Ref(N(LetterList_Kolorado)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

EvtScript N(EVS_DoNothing) = {
    Return
    End
};

#include "../common/GetIntoShell.inc.c"

#include "world/common/todo/SwitchToPartner.inc.c"

EvtScript N(EVS_NpcInteract_Kooper) = {
    IfLt(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
        Set(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
        Call(ShowMessageAtScreenPos, MSG_CH1_00B4, 160, 40)
        Call(GetPlayerPos, LVarA, LVarB, LVarC)
        Call(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        Call(SetPanTarget, CAM_DEFAULT, 0, 0, -180)
        Call(SetCamDistance, CAM_DEFAULT, 375)
        Call(SetCamPitch, CAM_DEFAULT, 17, Float(-5.5))

#if VERSION_PAL
        Call(SetCamSpeed, CAM_DEFAULT, Float(4 / DT))
#else
        Call(SetCamSpeed, CAM_DEFAULT, 4)
#endif
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(SetGroupVisibility, MODEL_g111, MODEL_GROUP_VISIBLE)
        Thread
            Wait(10 * DT)
            Call(PlaySoundAt, SOUND_BASIC_DOOR_OPEN, SOUND_SPACE_DEFAULT, 0, 0, -180)
            Call(MakeLerp, 0, 90, 15, EASING_COS_FAST_OVERSHOOT)
            Label(10)
                Call(UpdateLerp)
                Call(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(10)
                EndIf
        EndThread
        Thread
            Call(PlayerMoveTo, -25, -130, 10 * DT)
            Call(PlayerFaceNpc, NPC_Kooper, FALSE)
        EndThread
        Thread
            Call(N(SwitchToPartner), 1)
            Call(DisablePartnerAI, 0)
            Call(NpcMoveTo, NPC_PARTNER, -55, -130, 15 * DT)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_Kooper, 0)
            Call(EnablePartnerAI)
        EndThread
        Call(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcPos, NPC_Kooper, 0, 0, -207)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        Wait(35 * DT)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Run)
        Thread
            Loop(30 * DT)
                Call(PlayerFaceNpc, NPC_Kooper, FALSE)
                Wait(1)
            EndLoop
        EndThread
        Call(NpcMoveTo, NPC_Kooper, 0, -148, 20 * DT)
        Thread
            Call(MakeLerp, 90, 0, 30, EASING_COS_IN_OUT)
            Label(20)
                Call(UpdateLerp)
                Call(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(20)
                EndIf
            Call(PlaySoundAt, SOUND_BASIC_DOOR_CLOSE, SOUND_SPACE_DEFAULT, 0, 0, -180)
            Call(SetGroupVisibility, MODEL_g111, MODEL_GROUP_HIDDEN)
        EndThread
        Call(NpcMoveTo, NPC_Kooper, 25, -130, 10 * DT)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        Call(NpcFacePlayer, NPC_Kooper, 0)
        Call(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Wait(10 * DT)
        Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Celebrate, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B5)
        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
        Wait(15 * DT)
        Call(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Celebrate)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        Call(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
#if VERSION_PAL
        Call(AdjustCam, CAM_DEFAULT, Float(6 / DT), 30, Float(225.0), Float(17.0), Float(-8.5))
#else
        Call(AdjustCam, CAM_DEFAULT, 6, 30, Float(225.0), Float(17.0), Float(-8.5))
#endif
        Wait(5 * DT)
        Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B6)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Bow)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
        Call(EndSpeech, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
#if VERSION_PAL
        Call(AdjustCam, CAM_DEFAULT, Float(4 / DT), -30, Float(225.0), Float(17.0), Float(-8.5))
#else
        Call(AdjustCam, CAM_DEFAULT, 4, -30, Float(225.0), Float(17.0), Float(-8.5))
#endif
        Wait(10 * DT)
        Thread
            Wait(3 * DT)
            Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EndThread
        Call(DisablePartnerAI, 0)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH1_00B7)
        Call(EnablePartnerAI)
        Call(AdjustCam, CAM_DEFAULT, Float(90.0), 0, Float(375.0), Float(17.0), Float(-5.5))
        Wait(10 * DT)
        Call(PlayerFaceNpc, NPC_Kooper, FALSE)
        Wait(10 * DT)
        Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B8)
        Call(BindNpcInteract, NPC_Kooper, Ref(N(EVS_NpcInteract_Kooper)))
        Thread
#if VERSION_PAL
        Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
#else
        Call(ResetCam, CAM_DEFAULT, 3)
#endif
        EndThread
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00BA)
    Else
        Call(SpeakToPlayer, NPC_Kooper, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00BB)
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_MeetKooper) = {
    ExecWait(N(EVS_NpcInteract_Kooper))
    Return
    End
};

EvtScript N(EVS_FuzzyBoss_PlayerEntersKoopersHouse) = {
    IfGe(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
        Return
    EndIf
    IfEq(MF_FuzzyBossTaunt, TRUE)
        Return
    EndIf
    Set(MF_FuzzyBossTaunt, TRUE)
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_FuzzyBoss, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 0, MSG_CH1_00B9)
    Call(DisablePlayerInput, FALSE)
    Call(SetNpcAnimation, NPC_FuzzyBoss, ANIM_Fuzzy_Walk)
    Call(GetNpcPos, NPC_FuzzyBoss, LVarA, LVarB, LVarC)
    Set(LVarD, LVarA)
    Add(LVarD, -5)
    Label(10)
        Thread
            Call(SetNpcJumpscale, NPC_KoopersShell, 2)
            Call(NpcJump0, NPC_KoopersShell, LVarD, 0, LVarC, 12 * DT)
        EndThread
        Wait(1)
        Call(SetNpcJumpscale, NPC_FuzzyBoss, 2)
        Call(PlaySoundAtNpc, NPC_FuzzyBoss, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_FuzzyBoss, LVarA, 0, LVarC, 12 * DT)
        Call(IsPlayerWithin, 0, -400, 130, LVar0)
        IfEq(LVar0, 0)
            Goto(10)
        EndIf
    Set(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
    Set(LVarB, 0)
    Set(LVarC, 0)
    Set(LVarD, -514)
    Set(LVarE, 15 * DT)
    Thread
        Call(SetNpcJumpscale, NPC_KoopersShell, 2)
        Call(NpcJump0, NPC_KoopersShell, LVarB, LVarC, LVarD, LVarE)
    EndThread
    Wait(1)
    Call(SetNpcJumpscale, NPC_FuzzyBoss, 2)
    Call(PlaySoundAtNpc, NPC_FuzzyBoss, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_FuzzyBoss, LVarB, LVarC, LVarD, LVarE)
    Call(SetNpcFlagBits, NPC_FuzzyBoss, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_KoopersShell, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, NPC_FuzzyBoss, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
    Return
    End
};

Vec2i N(FuzzyJumpPath1)[] = {
    { -466,  103 },
    { -441,  213 },
    { -385,  285 },
    { -302,  324 },
    { -250,  428 },
    { -158,  451 },
    {  -45,  485 },
    {   62,  428 },
    {  214,  424 },
    {  324,  295 },
    {  416,  193 },
    {  293,  123 },
    {  181,   63 },
    {   95,   57 },
    {  -14,   16 },
    { -161,   56 },
    { -317,   81 },
    { -401,   73 },
};

Vec2i N(FuzzyJumpPath2)[] = {
    {  416,  193 },
    {  324,  295 },
    {  214,  424 },
    {   62,  428 },
    {  -45,  485 },
    { -158,  451 },
    { -250,  428 },
    { -302,  324 },
    { -385,  285 },
    { -441,  213 },
    { -466,  103 },
    { -401,   73 },
    { -317,   81 },
    { -161,   56 },
    {  -14,   16 },
    {   95,   57 },
    {  181,   63 },
    {  293,  123 },
};

EvtScript N(EVS_NpcIdle_MiscFuzzy1) = {
    Label(100)
    IfLt(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        Wait(8)
        Goto(100)
    EndIf
    UseBuf(Ref(N(FuzzyJumpPath1)))
    Set(LVar1, 200)
    BufRead2(LVar0, LVar2)
    Call(SetNpcPos, NPC_MiscFuzzy1, LVar0, LVar1, LVar2)
    Label(0)
        UseBuf(Ref(N(FuzzyJumpPath1)))
        Loop(18)
            Set(LVar1, 0)
            BufRead2(LVar0, LVar2)
            Call(RandInt, 10, LVar3)
            Add(LVar3, 15)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_MiscFuzzy1, LVar0, LVar1, LVar2, LVar3)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_MiscFuzzyFlee) = {
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Thread
        Call(MakeItemEntity, ITEM_COIN, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 25)
    Add(LVar0, 40)
    Add(LVar2, -40)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    Add(LVar0, 30)
    Add(LVar2, -30)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Anim09)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 13)
    Add(LVar0, 20)
    Add(LVar2, -20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 11)
    Add(LVar0, 10)
    Add(LVar2, -10)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 9)
    Add(LVar0, 80)
    Add(LVar2, -80)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Run)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_NpcHit_MiscFuzzy1) = {
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_MiscFuzzyFlee)))
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Return
    End
};

EvtScript N(EVS_NpcIdle_MiscFuzzy2) = {
    IfGe(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        Return
    EndIf
    Label(100)
        IfEq(AF_NOK_13, FALSE)
            Wait(1)
            Goto(100)
        EndIf
    Call(SetNpcPos, NPC_SELF, 438, 150, 155)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 438, 0, 150, 10)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 402, 0, 160, 15)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 384, 0, 160, 7)
    Label(0)
        UseBuf(Ref(N(FuzzyJumpPath2)))
        Loop(18)
            Set(LVar1, 0)
            BufRead2(LVar0, LVar2)
            Call(RandInt, 9, LVar3)
            Add(LVar3, 13)
            MulF(LVar0, Float(0.9))
            MulF(LVar2, Float(0.9))
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_C, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, LVar3)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcHit_MiscFuzzy2) = {
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_MiscFuzzyFlee)))
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_MiscFuzzy1) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MiscFuzzy1)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MiscFuzzy1)))
    Return
    End
};

EvtScript N(EVS_NpcInit_MiscFuzzy2) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MiscFuzzy2)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MiscFuzzy2)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy_Later) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MiscFuzzy2)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_MiscFuzzy2)))
    Return
    End
};

EvtScript N(EVS_BreakBlock_DropShell) = {
    IfEq(GF_NOK02_RecoveredShellB, TRUE)
        Return
    EndIf
    Set(GF_NOK02_RecoveredShellB, TRUE)
    Call(BindNpcAI, NPC_Koopa_02, Ref(N(EVS_DoNothing)))
    Call(DisablePlayerInput, TRUE)
    Call(NpcJump0, NPC_KoopaShell_02, 227, 0, 247, 20)
    Call(PlaySoundAtNpc, NPC_KoopaShell_02, SOUND_ITEM_BOUNCE, SOUND_SPACE_DEFAULT)
    Call(PlayerFaceNpc, NPC_KoopaShell_02, FALSE)
    Call(NpcFaceNpc, NPC_Koopa_02, NPC_KoopaShell_02, 0)
    Call(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Add(LVar0, -1)
    Add(LVar2, -1)
    Call(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Happy)
    Call(NpcJump0, NPC_Koopa_02, LVar0, 0, LVar2, 15)
    Call(GetNpcPos, NPC_KoopaShell_02, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Run)
    Call(NpcMoveTo, NPC_Koopa_02, LVar0, LVar2, 15)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Idle)
    Call(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 10)
    Call(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 10)
    Call(PlayerFaceNpc, NPC_Koopa_02, FALSE)
    Call(NpcFacePlayer, NPC_Koopa_02, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_KoopaWithoutShell_Still)
    Call(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    Call(GetNpcPos, NPC_Koopa_02, LVar0, LVar1, LVar2)
    Add(LVar0, 1)
    Add(LVar2, 1)
    Add(LVar1, 20)
    Set(LVar3, NPC_KoopaShell_02)
    Set(LVar4, NPC_Koopa_02)
    Exec(N(EVS_GetIntoShell))
    Call(InterpNpcYaw, LVar3, 60, 0)
    Call(NpcJump0, NPC_KoopaShell_02, LVar0, LVar1, LVar2, 30)
    Call(SetNpcPos, NPC_KoopaShell_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    Call(SetNpcFlagBits, NPC_Koopa_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Still)
    Wait(4)
    Call(EnableNpcBlur, NPC_KoopaShell_02, TRUE)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Happy)
    Wait(30)
    Call(SetNpcAnimation, NPC_Koopa_02, ANIM_Koopa_Idle)
    Call(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Happy, ANIM_Koopa_Idle, 0, MSG_CH1_005E)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

#include "npcs_crisis.inc.c"
#include "npcs_normal.inc.c"

EvtScript N(EVS_AnimateDoor_KoloradoHouse) = {
    Call(PlaySoundAtCollider, LVar9, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 15, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(MakeLerp, 80, 0, 15, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, LVarA, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, LVar9, SOUND_BASIC_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_KoloradoWife_FetchFromHouse) = {
    Call(EnableModel, MODEL_g98, TRUE)
    Call(EnableGroup, MODEL_g109, TRUE)
    Call(EnableGroup, MODEL_g47, TRUE)
    Set(LVarA, MODEL_g42)
    Set(LVar9, COLLIDER_o310)
    Exec(N(EVS_AnimateDoor_KoloradoHouse))
    Call(NpcMoveTo, NPC_KoloradoWife, -314, -94, 10)
    Wait(10)
    Call(NpcMoveTo, NPC_KoloradoWife, -304, -161, 20)
    Wait(100)
    Exec(N(EVS_AnimateDoor_KoloradoHouse))
    Wait(10)
    Call(NpcMoveTo, NPC_KoloradoWife, -308, -102, 20)
    Wait(10)
    Call(NpcMoveTo, NPC_KoloradoWife, -338, -85, 20)
    Call(NpcFacePlayer, NPC_KoloradoWife, 0)
    Wait(20)
    Call(SetNpcAnimation, NPC_KoloradoWife, ANIM_KoloradoWife_Idle)
    Call(EnableModel, MODEL_g98, FALSE)
    Call(EnableGroup, MODEL_g109, FALSE)
    Call(EnableGroup, MODEL_g47, FALSE)
    Return
    End
};

EvtScript N(EVS_KoloradoWife_FetchFromOffice) = {
    Set(LVarA, MODEL_g41)
    Set(LVar9, COLLIDER_o314)
    Call(NpcMoveTo, NPC_KoloradoWife, -277, -186, 20)
    Exec(N(EVS_AnimateDoor_KoloradoHouse))
    Wait(10)
    Call(NpcMoveTo, NPC_KoloradoWife, -265, -261, 20)
    Wait(100)
    Exec(N(EVS_AnimateDoor_KoloradoHouse))
    Wait(10)
    Call(NpcMoveTo, NPC_KoloradoWife, -277, -186, 20)
    Wait(10)
    Call(NpcMoveTo, NPC_KoloradoWife, -328, -180, 20)
    Call(NpcFacePlayer, NPC_KoloradoWife, 0)
    Wait(20)
    Call(SetNpcAnimation, NPC_KoloradoWife, ANIM_KoloradoWife_Idle)
    Return
    End
};

EvtScript N(EVS_KoloradoWife_FetchKoopaLegends) = {
    Call(SetNpcFlagBits, NPC_KoloradoWife, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0090)
    Call(SetNpcAnimation, NPC_KoloradoWife, ANIM_KoloradoWife_Walk)
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        ExecWait(N(EVS_KoloradoWife_FetchFromHouse))
    Else
        IfEq(GF_NOK11_Defeated_KentC, TRUE)
            ExecWait(N(EVS_KoloradoWife_FetchFromHouse))
        Else
            ExecWait(N(EVS_KoloradoWife_FetchFromOffice))
        EndIf
    EndIf
    Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0091)
    EVT_GIVE_KEY_REWARD(ITEM_KOOT_KOOPA_LEGENDS)
    Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0092)
    Call(SetNpcFlagBits, NPC_KoloradoWife, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoloradoWife) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            IfEq(GF_NOK02_KoloradoWife_FuzzyComplaint, FALSE)
                Set(GF_NOK02_KoloradoWife_FuzzyComplaint, TRUE)
                Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0088)
                Return
            EndIf
            Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0089)
        CaseLt(STORY_CH1_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008A)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008B)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008C)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008D)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            IfEq(GF_NOK11_Defeated_KentC, FALSE)
                Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008E)
            Else
                Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008F)
            EndIf
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_KoloradoWife, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008F)
    EndSwitch
    IfEq(GB_KootFavor_Current, KOOT_FAVOR_CH1_2)
        IfEq(GF_NOK02_Gift_KoopaLegends, FALSE)
            Set(GF_NOK02_Gift_KoopaLegends, TRUE)
            ExecWait(N(EVS_MarioSalute))
            ExecWait(N(EVS_KoloradoWife_FetchKoopaLegends))
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_KoloradoWife) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_KoloradoWife)))
    IfGe(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Call(SetNpcPos, NPC_SELF, -338, 0, -85)
        Return
    EndIf
    IfEq(GF_NOK11_Defeated_KentC, TRUE)
        Call(SetNpcPos, NPC_SELF, -338, 0, -85)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaKoot) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_KoopaKoot)))
    Exec(N(EVS_SetupKootFavors))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_Epilogue) = {
    Call(SetNpcPos, NPC_SELF, -25, 10, -50)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette_Epilogue) = {
    Call(SetNpcPos, NPC_SELF, 25, 0, -50)
    Call(SetNpcYaw, NPC_SELF, 270)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoloradoWife_Epilogue) = {
    Call(SetNpcPos, NPC_SELF, -150, 0, -50)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

NpcData N(NpcData_Crisis)[] = {
    {
        .id = NPC_Koopa_01,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -109, 0, 191 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -109, 0, 191 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_01_Crisis),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaC,
    },
    {
        .id = NPC_FuzzyThief,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Fuzzy_Thief),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KoopaShell_01,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaShell_01_Crisis),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Koopa_02,
        .pos = { 192.0f, 0.0f, 152.0f },
        .yaw = 0,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 199, 0, 152 },
                    { 107, 0, 152 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 192, 0, 152 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_02_Crisis),
        .settings = &N(NpcSettings_KoopaWithoutShell_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_WITHOUT_SHELL_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaD,
    },
    {
        .id = NPC_KoopaShell_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaShell_02_Crisis),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
    },
    {
        .id = NPC_Kooper,
        .pos = { 20.0f, 0.0f, -145.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Kooper),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPER_ANIMS,
        .tattle = MSG_NpcTattle_NOK_Kooper,
    },
    {
        .id = NPC_FuzzyBoss,
        .pos = { 12.0f, 10.0f, -351.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FuzzyBoss),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KoopersShell,
        .pos = { 12.0f, 0.0f, -351.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_KoopersShell),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPER_ANIMS,
    },
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_MiscFuzzy1,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_MiscFuzzy1),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_MiscFuzzy2,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_MiscFuzzy2),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Normal)[] = {
    {
        .id = NPC_Koopa_01,
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -124, 0, 250 },
                .wanderSize = { 80 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -85, 0, 260 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_01_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaC,
    },
    {
        .id = NPC_Koopa_02,
        .pos = { 200.0f, 0.0f, 117.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 200, 0, 117 },
                .wanderSize = { 50, 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 170 },
                .detectSize = { 500 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_02_Normal),
        .settings = &N(NpcSettings_Koopa_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_GenericKoopaD,
    },
    {
        .id = NPC_Bobomb_01,
        .pos = { 0.0f, 0.0f, -333.0f },
        .yaw = 180,
        .init = &N(EVS_NpcInit_Bobomb_01),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = BOBOMB_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombD,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { -7.0f, 0.0f, -285.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bobomb_02),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombE,
    },
    {
        .id = NPC_Bobomb_03,
        .pos = { 47.0f, 0.0f, -140.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Bobomb_03),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_NOK_BobombF,
    },
    {
        .id = NPC_Kolorado,
        .pos = { -240.0f, 0.0f, -70.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

NpcData N(NpcData_Fuzzy_Later) = {
    .id = NPC_Fuzzy_Later,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy_Later),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_PARTNER,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
};

NpcData N(NpcData_Shared)[] = {
    {
        .id = NPC_KoopaKoot,
        .pos = { 330.0f, 0.0f, -100.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_KoopaKoot),
        .settings = &N(NpcSettings_KoopaKoot),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_KOOT_ANIMS,
        .tattle = MSG_NpcTattle_KoopaKoot,
    },
    {
        .id = NPC_KoloradoWife,
        .pos = { -328.0f, 0.0f, -180.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoloradoWife),
        .settings = &N(NpcSettings_KoloradoWife),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOLORADO_WIFE_ANIMS,
        .tattle = MSG_NpcTattle_KoloradoWife,
    },
    {
        .id = NPC_Koopa_03,
        .pos = { -307.0f, 0.0f, 97.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Koopa_03),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_SenseOfJustice,
    },
    {
        .id = NPC_Koopa_04,
        .pos = { 285.0f, 0.0f, 223.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 240, 0, 175 },
                    { 350, 0, 250 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Koopa_04),
        .settings = &N(NpcSettings_KoopaWithoutShell_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = KOOPA_ANIMS,
        .tattle = MSG_NpcTattle_NOK_PrettyMellow,
    },
};

NpcData N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Parakarry,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopa_Epilogue),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
    },
    {
        .id = NPC_Bombette,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bombette_Epilogue),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldBombette_Idle,
            .walk   = ANIM_WorldBombette_Walk,
            .run    = ANIM_WorldBombette_Walk,
            .chase  = ANIM_WorldBombette_Walk,
            .anim_4 = ANIM_WorldBombette_Walk,
            .anim_5 = ANIM_WorldBombette_Walk,
            .death  = ANIM_WorldBombette_Still,
            .hit    = ANIM_WorldBombette_Still,
            .anim_8 = ANIM_WorldBombette_Still,
            .anim_9 = ANIM_WorldBombette_Still,
            .anim_A = ANIM_WorldBombette_Still,
            .anim_B = ANIM_WorldBombette_Still,
            .anim_C = ANIM_WorldBombette_Still,
            .anim_D = ANIM_WorldBombette_Still,
            .anim_E = ANIM_WorldBombette_Still,
            .anim_F = ANIM_WorldBombette_Still,
        },
    },
    {
        .id = NPC_KoloradoWife_Epilogue,
        .pos = { -328.0f, 0.0f, -180.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoloradoWife_Epilogue),
        .settings = &N(NpcSettings_Koopa),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = KOLORADO_WIFE_ANIMS,
        .tattle = MSG_NpcTattle_KoloradoWife,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 300.0f, 0.0f, 330.0f },
    .yaw = 270,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_NOK, QUIZ_COUNT_NOK, QUIZ_MAP_NOK_02 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(CrisisNPCs) = {
    NPC_GROUP(N(NpcData_Crisis)),
    NPC_GROUP(N(NpcData_Shared)),
    NPC_GROUP(N(NpcData_Fuzzy_01)),
    NPC_GROUP(N(NpcData_Fuzzy_02)),
    {}
};

NpcGroupList N(NormalNPCs) = {
    NPC_GROUP(N(NpcData_Normal)),
    NPC_GROUP(N(NpcData_Shared)),
    NPC_GROUP(N(NpcData_Fuzzy_Later)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Epilogue)),
    {}
};
