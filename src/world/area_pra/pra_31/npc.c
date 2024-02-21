#include "pra_31.h"

#include "world/common/enemy/AlbinoDino.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

API_CALLABLE(N(GetAngleToPlayer)) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    script->varTable[0] = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatus.pos.x, gPlayerStatus.pos.z));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CalculateDinoLerpValues)) {
    script->varTable[6] = script->varTable[0] + 90;
    script->varTable[7] = script->varTable[5] + 90;
    script->varTable[8] = abs(script->varTable[6] - script->varTable[7]);

    if (script->varTable[8] == 270) {
        script->varTable[8] = 90;
        if (script->varTable[6] > script->varTable[7]) {
            script->varTable[6] -= 360;
        } else {
            script->varTable[7] -= 360;
        }
    }
    script->varTable[8] = (script->varTable[8] / 90) * 20;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ChangeDinoDirection) = {
    Call(N(GetAngleToPlayer))
    Switch(LVar0)
        CaseRange(45, 134)
            Set(LVar5, 90)
            Set(LVar6, ANIM_AlbinoDino_Still)
            Set(LVarA, 90)
        CaseRange(135, 224)
            Set(LVar5, 180)
            Set(LVar6, ANIM_AlbinoDino_StillFwd)
            Set(LVarA, 270)
        CaseRange(225, 314)
            Set(LVar5, 270)
            Set(LVar6, ANIM_AlbinoDino_Still)
            Set(LVarA, 270)
        CaseDefault
            Set(LVar5, 0)
            Set(LVar6, ANIM_AlbinoDino_StillBack)
            Set(LVarA, 270)
    EndSwitch
    Switch(LVar3)
        CaseEq(NPC_AlbinoDino_01)
            Set(LVar0, MV_DinoYaw_01)
        CaseEq(NPC_AlbinoDino_02)
            Set(LVar0, MV_DinoYaw_02)
        CaseEq(NPC_AlbinoDino_03)
            Set(LVar0, MV_DinoYaw_03)
    EndSwitch
    IfNe(LVar5, LVar0)
        Thread
            Call(N(CalculateDinoLerpValues))
            Call(MakeLerp, LVar6, LVar7, LVar8, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Switch(LVar3)
                    CaseEq(NPC_AlbinoDino_01)
                        Set(MV_StatueYaw_01, LVar0)
                    CaseEq(NPC_AlbinoDino_02)
                        Set(MV_StatueYaw_02, LVar0)
                    CaseEq(NPC_AlbinoDino_03)
                        Set(MV_StatueYaw_03, LVar0)
                EndSwitch
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_PRA_ROTATE_ALBINO_DINO, SOUND_SPACE_DEFAULT)
        Switch(LVar5)
            CaseOrEq(90)
            CaseOrEq(270)
                Call(MakeLerp, 0, 540, 30, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
                Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
                Call(SetNpcYaw, NPC_SELF, LVarA)
            CaseDefault
                Thread
                    Wait(15)
                    Call(SetNpcYaw, NPC_SELF, LVarA)
                EndThread
                Call(MakeLerp, 0, 360, 20, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
        EndSwitch
    EndIf
    Call(SetNpcAnimation, NPC_SELF, LVar6)
    Switch(LVar3)
        CaseEq(NPC_AlbinoDino_01)
            Set(MV_DinoYaw_01, LVar5)
        CaseEq(NPC_AlbinoDino_02)
            Set(MV_DinoYaw_02, LVar5)
        CaseEq(NPC_AlbinoDino_03)
            Set(MV_DinoYaw_03, LVar5)
    EndSwitch
    Call(N(SetDinoAngle), LVar3, LVar5)
    Call(SpeakToPlayer, NPC_SELF, LVar6, LVar6, 5, LVar4)
    Return
    End
};

EvtScript N(EVS_NpcInteract_AlbinoDino_01) = {
    Set(LVar3, NPC_AlbinoDino_01)
    Set(LVar4, MSG_CH7_0167)
    ExecWait(N(EVS_ChangeDinoDirection))
    Return
    End
};

EvtScript N(EVS_NpcInteract_AlbinoDino_02) = {
    Set(LVar3, NPC_AlbinoDino_02)
    Set(LVar4, MSG_CH7_0168)
    ExecWait(N(EVS_ChangeDinoDirection))
    Return
    End
};

EvtScript N(EVS_NpcInteract_AlbinoDino_03) = {
    Set(LVar3, NPC_AlbinoDino_03)
    Set(LVar4, MSG_CH7_0169)
    ExecWait(N(EVS_ChangeDinoDirection))
    Return
    End
};

EvtScript N(EVS_NpcInit_AlbinoDino_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_AlbinoDino_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_AlbinoDino_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_AlbinoDino_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_AlbinoDino_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_AlbinoDino_03)))
    Return
    End
};

NpcData N(NpcData_AlbinoDinos)[] = {
    {
        .id = NPC_AlbinoDino_01,
        .pos = { 190.0f, -10.0f, 165.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_AlbinoDino_01),
        .settings = &N(NpcSettings_AlbinoDino),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ALBINO_DINO_ANIMS,
        .tattle = MSG_NpcTattle_AlbinoDino,
    },
    {
        .id = NPC_AlbinoDino_02,
        .pos = { 300.0f, -10.0f, 89.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_AlbinoDino_02),
        .settings = &N(NpcSettings_AlbinoDino),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ALBINO_DINO_ANIMS,
        .tattle = MSG_NpcTattle_AlbinoDino,
    },
    {
        .id = NPC_AlbinoDino_03,
        .pos = { 452.0f, -10.0f, 139.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_AlbinoDino_03),
        .settings = &N(NpcSettings_AlbinoDino),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ALBINO_DINO_ANIMS,
        .tattle = MSG_NpcTattle_AlbinoDino,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_AlbinoDinos), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_01),
    {}
};
