#include "kzn_02.h"
#include "sprite/player.h"

#include "world/common/enemy/LavaBubble.inc.c"

#include "world/common/npc/Kolorado.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado,
    ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Call(DisablePlayerInput, TRUE)
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar0, -825)
            BreakLoop
        EndIf
    EndLoop
    Wait(30)
    Call(AdjustCam, CAM_DEFAULT, Float(5.0), 100, 350, Float(15.0), Float(-7.0))
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00EE)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Loop(30)
        Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Wait(1)
        Sub(LVar0, 1)
    EndLoop
    Call(SetNpcSpeed, NPC_SELF, Float(3.0))
    Call(NpcMoveTo, NPC_SELF, -740, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -650, 20, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Thrown)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, -655, 20, 0, 20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
    Call(NpcJump0, NPC_SELF, -645, 20, 0, 5)
    Call(NpcJump0, NPC_SELF, -635, 20, 0, 5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Wait(15)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Wait(5)
    Call(InterpNpcYaw, NPC_SELF, 90, 1)
    Wait(10)
    Exec(N(EVS_KoloradoSinkingPlatform))
    Set(LVar0, 2)
    Loop(3)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        Call(ShowSweat, NPC_Kolorado, 1, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Call(InterpNpcYaw, NPC_SELF, 270, 1)
        Call(NpcMoveTo, NPC_SELF, -655, 0, LVar0)
        Call(ShowSweat, NPC_Kolorado, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Call(InterpNpcYaw, NPC_SELF, 90, 1)
        Call(NpcMoveTo, NPC_SELF, -635, 0, LVar0)
        Mul(LVar0, 2)
    EndLoop
    Call(ShowSweat, NPC_Kolorado, 0, 45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(InterpNpcYaw, NPC_SELF, 270, 2)
    Call(ShowSweat, NPC_Kolorado, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(InterpNpcYaw, NPC_SELF, 90, 2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Hurt)
    Call(ShowSweat, NPC_Kolorado, 0, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(SetSelfVar, 0, 1)
    Thread
        Label(15)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 10)
        Call(GetSelfVar, 0, LVar3)
        IfEq(LVar3, 1)
            Wait(1)
            Goto(15)
        EndIf
    EndThread
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_TOUCH_LAVA, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, -700, 150, 0, 35)
    Thread
        Call(ResetCam, CAM_DEFAULT, Float(5.0))
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(NpcJump0, NPC_SELF, -775, 20, -40, 40)
    Call(SetSelfVar, 0, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    Call(InterpNpcYaw, NPC_SELF, 270, 2)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, -760, 50, -40, 10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Wait(4)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Wait(8)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    Call(InterpNpcYaw, NPC_SELF, 90, 2)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, -760, 40, -40, 10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Wait(4)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Wait(8)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Wait(5)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(InterpNpcYaw, NPC_SELF, 90, 4)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH5_00EF)
    Wait(5)
    Call(InterpNpcYaw, NPC_SELF, 270, 4)
    Set(GB_StoryProgress, STORY_CH5_KOLORADO_FELL_IN_LAVA)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Thread
        Wait(20)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00F0)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 7)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(CloseMessage)
    EVT_LETTER_CHECK(Kolorado)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_KOLORADO_FELL_IN_LAVA)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
        CaseLt(STORY_CH5_LAVA_STREAM_BLOCKED)
            IfEq(GF_KZN06_Visited, FALSE)
                Call(SetNpcPos, NPC_SELF, -760, 20, -40)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
            Else
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EndIf
        CaseDefault
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -740.0f, 20.0f, 0.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_RAYCAST_TO_INTERACT | ENEMY_FLAG_SKIP_BATTLE,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_LavaBubble) = {
    .id = NPC_LavaBubble,
    .pos = { 250.0f, 50.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 250, 50, 0 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 250, 50, 0 },
            .detectSize = { 70, 200 },
        }
    },
    .settings = &N(NpcSettings_LavaBubble),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAVA_BUBBLE_DROPS,
    .animations = LAVA_BUBBLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_LavaBubble), BTL_KZN_FORMATION_00, BTL_KZN_STAGE_02),
    {}
};
