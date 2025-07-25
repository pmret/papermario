#include "kzn_17.h"

#include "world/common/npc/Kolorado.inc.c"

#include "world/common/enemy/PutridPiranha.inc.c"
#include "world/common/enemy/SpikeTop.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado1, NPC_Kolorado,
    ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_PROMPT(Kolorado2, NPC_Kolorado,
    ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E8, MSG_CH5_00E9, MSG_CH5_00EA, MSG_CH5_00EB,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

Vec3f N(KoloradoThrownPath)[] = {
    {  447.0,     0.0,   39.0 },
    {  432.0,     5.0,   47.0 },
    {  427.0,    20.0,   55.0 },
    {  432.0,     5.0,   62.0 },
    {  447.0,     0.0,   70.0 },
};

EvtScript N(EVS_Kolorado_TrompPanic) = {
    Call(SetNpcPos, NPC_Kolorado, 447, 0, 39)
    Call(SetNpcYaw, NPC_Kolorado, 270)
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    Return
    End
};

EvtScript N(EVS_Kolorado_TrompImpact) = {
    Call(SetEnemyFlagBits, NPC_Kolorado, ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER, true)
    Call(SetNpcRotationPivot, NPC_Kolorado, 13)
    Call(SetNpcRotation, NPC_Kolorado, 0, 0, 250)
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_HurtStill)
    Call(SetNpcImgFXParams, NPC_Kolorado, IMGFX_SET_WAVY, Float(3.0), Float(3.0), 0, 0)
    Call(PlaySoundAtNpc, NPC_Kolorado, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Thread
        Call(SetNpcCollisionSize, NPC_Kolorado, 20, 24)
        Call(LoadPath, 30, Ref(N(KoloradoThrownPath)), ARRAY_COUNT(N(KoloradoThrownPath)), EASING_LINEAR)
        Label(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kolorado, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    EndThread
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_HurtStill, ANIM_Kolorado_HurtStill, 5, MSG_CH5_00F9)
    Return
    End
};

EvtScript N(EVS_Kolorado_HurtInit) = {
    Call(SetNpcPos, NPC_Kolorado, 447, 0, 70)
    Call(SetNpcYaw, NPC_Kolorado, 270)
    Call(SetEnemyFlagBits, NPC_Kolorado, ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER, true)
    Call(SetNpcRotationPivot, NPC_Kolorado, 13)
    Call(SetNpcRotation, NPC_Kolorado, 0, 0, 250)
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_HurtStill)
    Call(SetNpcImgFXParams, NPC_Kolorado, IMGFX_SET_WAVY, Float(3.0), Float(3.0), 0, 0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 605)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_CH5_00F7, 160, 40)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(SetNpcPos, NPC_SELF, 290, 0, 30)
    Call(SetNpcSpeed, NPC_SELF, Float(5.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Call(NpcMoveTo, NPC_SELF, 640, 80, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, false)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00F8)
    Set(GB_StoryProgress, STORY_CH5_KOLORADO_AT_DEAD_END)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00FC)
        ExecWait(N(EVS_LetterPrompt_Kolorado1))
        ExecWait(N(EVS_LetterReward_Kolorado))
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_HurtStill, 5, MSG_CH5_00FA)
        ExecWait(N(EVS_LetterPrompt_Kolorado2))
        ExecWait(N(EVS_LetterReward_Kolorado))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_KOLORADO_AT_DEAD_END)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
            Return
        CaseLt(STORY_CH5_HIDDEN_PASSAGE_OPEN)
            Call(SetNpcPos, NPC_SELF, 640, 0, 80)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Yell)
            Return
        CaseEq(STORY_CH5_HIDDEN_PASSAGE_OPEN)
            Call(SetNpcCollisionSize, NPC_Kolorado, 20, 24)
            Exec(N(EVS_Kolorado_HurtInit))
            Return
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_RAYCAST_TO_INTERACT | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Piranha)[] = {
    {
        .id = NPC_Piranha,
        .pos = { -325.0f, 0.0f, 150.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = true,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -325, 0, 150 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { -390, 0, 130 },
                .detectSize = { 270, 130 },
            }
        },
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = PUTRID_PIRANHA_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox)
};

NpcData N(NpcData_SpikeTop) = {
    .id = NPC_SpikeTop,
    .pos = { -450.0f, 0.0f, 100.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -450, 0, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -450, 0, 100 },
            .detectSize = { 270, 130 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Piranha), 0x1814, BTL_KZN_STAGE_00),
    NPC_GROUP(N(NpcData_SpikeTop), 0x180D, BTL_KZN_STAGE_00),
    {}
};
