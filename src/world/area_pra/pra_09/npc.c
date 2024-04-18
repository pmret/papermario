#include "pra_09.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/enemy/Duplighost.h"

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/enemy/Bombette.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/todo/PlayBigSmokePuff.inc.c"

API_CALLABLE(N(ChooseImposterBattleFormation)) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Encounter* encounter;
    s32 unmaskedCount = 0;

    if (evt_get_variable(script, *args++) == 0) {
        unmaskedCount++;
    }
    if (evt_get_variable(script, *args++) == 0) {
        unmaskedCount++;
    }
    if (evt_get_variable(script, *args++) == 0) {
        unmaskedCount++;
    }
    if (evt_get_variable(script, *args++) == 0) {
        unmaskedCount++;
    }

    switch (unmaskedCount) {
        case 1:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = BTL_PRA3_FORMATION_01;
            break;
        case 2:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = BTL_PRA3_FORMATION_02;
            break;
        case 3:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = BTL_PRA3_FORMATION_03;
            break;
        case 4:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = BTL_PRA3_FORMATION_04;
            break;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ImposterFallFromCeiling)) {
    Npc* npc = resolve_npc(script, script->varTable[0]);

    if (isInitialCall) {
        npc->pos.x = script->varTable[1];
        npc->pos.y = script->varTable[2];
        npc->pos.z = script->varTable[3];
        npc->jumpVel = 0.0f;
        npc->curAnim = ANIM_WorldBombette_Aftermath;
        npc->jumpScale = 0.8f;
    }
    npc->rot.z -= 39.0f;
    npc->rot.x -= 33.0f;
    npc->pos.y -= npc->jumpVel;
    npc->jumpVel += npc->jumpScale;
    if (npc->pos.y <= 0.0f) {
        npc->pos.y = 0.0f;
        npc->rot.z = 0.0f;
        npc->rot.x = 0.0f;
        npc->jumpVel = 0.0f;
        npc->jumpScale = 0.0f;
        npc->curAnim = ANIM_WorldBombette_Idle;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ChangeNpcCollisionRadius)) {
    Npc* npc1 = resolve_npc(script, script->varTable[3]);
    Npc* npc2 = resolve_npc(script, script->varTable[4]);

    npc1->collisionDiameter = npc2->collisionDiameter;
    npc1->collisionHeight = npc2->collisionHeight;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_FocusCam_OnPosition) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, LVarA)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-5.5))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(20.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_StartBattle) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(6.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(386.0), Float(20.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_FocusCam_OnPlayer) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar0, 386)
        Set(LVar0, 386)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(6.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(20.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Return
    End
};

EvtScript N(EVS_Imposter_Unmask) = {
    Call(N(ChangeNpcCollisionRadius))
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SpeakToPlayer, LVar3, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, LVar5)
    Call(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
    Call(SetNpcPos, LVar3, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcPos, LVar4, LVar0, LVar1, LVar2)
    Call(PlaySoundAtNpc, LVar4, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 2880, 40, EASING_QUADRATIC_OUT)
    Label(1)
    Call(UpdateLerp)
    Call(SetNpcRotation, LVar4, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(1)
    EndIf
    Call(EndSpeech, LVar4, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0)
    ExecWait(N(EVS_FocusCam_OnPlayer))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Thread
        Call(SetNpcAnimation, LVar4, ANIM_Duplighost_Anim04)
        Call(InterpNpcYaw, LVar4, 90, 0)
        Call(SetNpcSpeed, LVar4, Float(6.5))
        Call(PlaySoundAtNpc, LVar4, SOUND_DUPLIGHOST_LEAP, SOUND_SPACE_DEFAULT)
        Call(NpcMoveTo, LVar4, 0, LVar2, 0)
        Call(SetNpcPos, LVar4, NPC_DISPOSE_LOCATION)
    EndThread
    Wait(15)
    Return
    End
};

EvtScript N(EVS_Imposter_HopTwice) = {
    Call(SetNpcJumpscale, LVar3, Float(1.0))
    Call(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    Call(NpcJump0, LVar3, LVar0, LVar1, LVar2, 10)
    Call(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    Call(NpcJump0, LVar3, LVar0, LVar1, LVar2, 10)
    Return
    End
};

EvtScript N(EVS_RevealEveryImposter) = {
    IfEq(MV_RevealedFakeBombette1, 0)
        Thread
            Call(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Bombette_02, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Duplighost_01, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_Duplighost_01, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim04)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_Duplighost_01, LVar0, LVar2, 30)
        EndThread
    EndIf
    IfEq(MV_RevealedFakeBombette2, 0)
        Thread
            Call(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Bombette_03, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Duplighost_02, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_Duplighost_02, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim04)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_Duplighost_02, LVar0, LVar2, 30)
        EndThread
    EndIf
    IfEq(MV_RevealedFakeBombette3, 0)
        Thread
            Call(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Bombette_04, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Duplighost_03, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_Duplighost_03, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(SetNpcAnimation, NPC_Duplighost_03, ANIM_Duplighost_Anim04)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_Duplighost_03, LVar0, LVar2, 30)
        EndThread
    EndIf
    IfEq(MV_RevealedFakeBombette4, 0)
        Thread
            Call(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Bombette_05, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_Duplighost_04, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_Duplighost_04, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(SetNpcAnimation, NPC_Duplighost_04, ANIM_Duplighost_Anim04)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_Duplighost_04, LVar0, LVar2, 30)
        EndThread
    EndIf
    Wait(20)
    Return
    End
};

EvtScript N(EVS_Imposter_ChaseDownPlayer) = {
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, LVar3, ANIM_WorldBombette_Run)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(NpcMoveTo, LVar3, LVar0, LVar2, 30)
    Return
    End
};

EvtScript N(EVS_Imposter_CarryPlayerBack) = {
    Call(InterpNpcYaw, LVar3, LVar9, 0)
    Loop(30)
        Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
        Add(LVar0, LVar4)
        Add(LVar1, LVar5)
        Add(LVar2, LVar6)
        Call(SetNpcPos, LVar3, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Imposter_ReturnToStation) = {
    Call(NpcMoveTo, LVar3, LVar0, LVar2, 20)
    Call(SetNpcAnimation, LVar3, ANIM_WorldBombette_Idle)
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(InterpNpcYaw, LVar3, 90, 0)
    Return
    End
};

EvtScript N(EVS_PreventPlayerLeaving) = {
    Call(DisablePlayerInput, TRUE)
    Loop(0)
        Wait(1)
        Call(GetPlayerActionState, LVar0)
        IfEq(LVar0, ACTION_STATE_IDLE)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerPhysics, TRUE)
    IfEq(MV_RevealedFakeBombette1, 0)
        Set(LVar3, NPC_Bombette_02)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    IfEq(MV_RevealedFakeBombette2, 0)
        Set(LVar3, NPC_Bombette_03)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    IfEq(MV_RevealedFakeBombette3, 0)
        Set(LVar3, NPC_Bombette_04)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    IfEq(MV_RevealedFakeBombette4, 0)
        Set(LVar3, NPC_Bombette_05)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    Set(LVar3, 0)
    ExecWait(N(EVS_Imposter_ChaseDownPlayer))
    Call(InterpPlayerYaw, 90, 3)
    Call(SetPlayerAnimation, ANIM_MarioW2_LayingDown)
    Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    Wait(10)
    Thread
        Loop(35)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Wait(1)
        EndLoop
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Thread
        Loop(30)
            Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    IfEq(MV_RevealedFakeBombette1, 0)
        Set(LVar3, NPC_Bombette_02)
        Set(LVar4, 0)
        Set(LVar5, 0)
        Set(LVar6, 10)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    IfEq(MV_RevealedFakeBombette2, 0)
        Set(LVar3, NPC_Bombette_03)
        Set(LVar4, -20)
        Set(LVar5, 0)
        Set(LVar6, 0)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    IfEq(MV_RevealedFakeBombette3, 0)
        Set(LVar3, NPC_Bombette_04)
        Set(LVar4, -20)
        Set(LVar5, 0)
        Set(LVar6, 10)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    IfEq(MV_RevealedFakeBombette4, 0)
        Set(LVar3, NPC_Bombette_05)
        Set(LVar4, -20)
        Set(LVar5, 0)
        Set(LVar6, 20)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    Call(NpcMoveTo, NPC_Bombette_01, 370, 73, 30)
    Call(DisablePlayerPhysics, FALSE)
    IfEq(MV_RevealedFakeBombette1, 0)
        Set(LVar3, NPC_Bombette_02)
        Set(LVar0, 280)
        Set(LVar2, 100)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    IfEq(MV_RevealedFakeBombette2, 0)
        Set(LVar3, NPC_Bombette_03)
        Set(LVar0, 315)
        Set(LVar2, 55)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    IfEq(MV_RevealedFakeBombette3, 0)
        Set(LVar3, NPC_Bombette_04)
        Set(LVar0, 350)
        Set(LVar2, 80)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    IfEq(MV_RevealedFakeBombette4, 0)
        Set(LVar3, NPC_Bombette_05)
        Set(LVar0, 420)
        Set(LVar2, 60)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    Set(LVar3, 0)
    Set(LVar0, 385)
    Set(LVar2, 120)
    ExecWait(N(EVS_Imposter_ReturnToStation))
    Call(ShowMessageAtScreenPos, MSG_CH7_014E, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ManageImpostersScene) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
        Return
    EndIf
    Label(0)
        Set(LVar0, GF_PRA09_BombedWall)
        Wait(1)
        IfEq(LVar0, 0)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Wait(25)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, 386, 0, 93)
    Call(SetPanTarget, CAM_DEFAULT, 386, 0, 93)
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-7.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(500.0), Float(20.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Set(LVar0, NPC_Bombette_04)
        Set(LVar1, 350)
        Set(LVar2, 150)
        Set(LVar3, 90)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(N(ImposterFallFromCeiling))
        Wait(1)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Wait(5)
    Thread
        Set(LVar0, NPC_Bombette_02)
        Set(LVar1, 280)
        Set(LVar2, 150)
        Set(LVar3, 100)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(N(ImposterFallFromCeiling))
        Wait(1)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Wait(5)
    Thread
        Set(LVar0, NPC_Bombette_05)
        Set(LVar1, 420)
        Set(LVar2, 150)
        Set(LVar3, 60)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(N(ImposterFallFromCeiling))
        Wait(1)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Wait(5)
    Thread
        Set(LVar0, NPC_Bombette_01)
        Set(LVar1, 385)
        Set(LVar2, 150)
        Set(LVar3, 120)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(N(ImposterFallFromCeiling))
        Wait(1)
        Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Wait(5)
    Set(LVar0, NPC_Bombette_03)
    Set(LVar1, 315)
    Set(LVar2, 150)
    Set(LVar3, 55)
    Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(N(ImposterFallFromCeiling))
    Wait(1)
    Call(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Wait(30)
    Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, 0)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_Bombette_01, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013C)
    Call(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, 1)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_Bombette_02, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013D)
    Call(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, 2)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_Bombette_03, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013E)
    Call(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, 3)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_Bombette_04, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013F)
    Call(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, 4)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_Bombette_05, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0140)
    Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Call(SpeakToPlayer, NPC_Bombette_01, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0141)
    Call(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Call(SpeakToPlayer, NPC_Bombette_03, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0142)
    Call(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Call(SpeakToPlayer, NPC_Bombette_04, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0143)
    Call(ResetCam, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, TRUE)
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar0, 490)
            Set(LVar9, 270)
            ExecWait(N(EVS_PreventPlayerLeaving))
        EndIf
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 190)
            Set(LVar9, 90)
            ExecWait(N(EVS_PreventPlayerLeaving))
        EndIf
        IfEq(MV_RevealedFakeBombette1, 1)
            IfEq(MV_RevealedFakeBombette2, 1)
                IfEq(MV_RevealedFakeBombette3, 1)
                    IfEq(MV_RevealedFakeBombette4, 1)
                        Call(DisablePlayerInput, TRUE)
                        Call(DisablePartnerAI, 0)
                        Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
                        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        Call(SetNpcPos, NPC_Bombette_01, NPC_DISPOSE_LOCATION)
                        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE, FALSE)
                        Call(GetAngleToNPC, NPC_PARTNER, LVarA)
                        Call(GetPlayerPos, LVar0, LVar1, LVar2)
                        IfLe(LVarA, 180)
                            Add(LVar0, 20)
                        Else
                            Add(LVar0, -20)
                        EndIf
                        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Walk)
                        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 20)
                        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Idle)
                        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_014F)
                        Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
                        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_HappyJump)
                        Thread
                            Wait(5)
                            Add(LVar1, 10)
                            Call(GetAngleToNPC, NPC_PARTNER, LVarA)
                            IfGe(LVarA, 180)
                                Add(LVar0, 20)
                            EndIf
                            PlayEffect(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 0)
                            Call(PlaySoundAtPlayer, SOUND_HEART_BOUNCE, SOUND_SPACE_DEFAULT)
                        EndThread
                        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
                        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Idle)
                        Wait(10)
                        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                        Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
                        Call(EnablePartnerAI)
                        Call(DisablePlayerInput, FALSE)
                        Set(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
                        BindTrigger(Ref(N(EVS_ExitWalk_pra_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
                        BreakLoop
                    EndIf
                EndIf
            EndIf
        EndIf
        Switch(MV_UnmaskingState)
            CaseEq(0)
                Wait(1)
            CaseEq(1)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Call(SpeakToPlayer, NPC_Bombette_01, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Hurt, 0, MSG_CH7_0149)
                ExecWait(N(EVS_FocusCam_StartBattle))
                Call(SetPlayerAnimation, ANIM_Mario1_Flail)
                ExecWait(N(EVS_RevealEveryImposter))
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(N(ChooseImposterBattleFormation), MV_RevealedFakeBombette1, MV_RevealedFakeBombette2, MV_RevealedFakeBombette3, MV_RevealedFakeBombette4)
                Call(DisablePlayerInput, FALSE)
                Call(StartBossBattle, SONG_SPECIAL_BATTLE)
                BreakLoop
            CaseEq(2)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_Bombette_02)
                Set(LVar4, NPC_Duplighost_01)
                Set(LVar5, MSG_CH7_014A)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeBombette1, 1)
                Call(DisablePlayerInput, FALSE)
            CaseEq(3)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_Bombette_03)
                Set(LVar4, NPC_Duplighost_02)
                Set(LVar5, MSG_CH7_014B)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeBombette2, 1)
                Call(DisablePlayerInput, FALSE)
            CaseEq(4)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_Bombette_04)
                Set(LVar4, NPC_Duplighost_03)
                Set(LVar5, MSG_CH7_014C)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeBombette3, 1)
                Call(DisablePlayerInput, FALSE)
            CaseEq(5)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_Bombette_05)
                Set(LVar4, NPC_Duplighost_04)
                Set(LVar5, MSG_CH7_014D)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeBombette4, 1)
                Call(DisablePlayerInput, FALSE)
        EndSwitch
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Duplighost_05) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_Bombette_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Set(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bombette_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0144)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bombette_02) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0145)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bombette_03) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0146)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bombette_04) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0147)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bombette_05) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0148)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_05) = {
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Duplighost_05)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Exec(N(EVS_ManageImpostersScene))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bombette_01)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bombette_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bombette_03)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bombette_04)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bombette_05)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_01) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_02) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_03) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_04) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

NpcData N(NpcData_InteractableBombettes)[] = {
    {
        .id = NPC_Bombette_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bombette_01),
        .settings = &N(NpcSettings_Bombette),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bombette_02),
        .settings = &N(NpcSettings_Bombette),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bombette_03),
        .settings = &N(NpcSettings_Bombette),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bombette_04),
        .settings = &N(NpcSettings_Bombette),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bombette_05),
        .settings = &N(NpcSettings_Bombette),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
};

NpcData N(NpcData_Duplighosts)[] = {
    {
        .id = NPC_Duplighost_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_01),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_02),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_03),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_04),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_05),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
};

EvtScript N(EVS_NpcHit_TargetBombette_01) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_Bombette_01 + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetBombette_02) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_Bombette_02 + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetBombette_03) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_Bombette_03 + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetBombette_04) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_Bombette_04 + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetBombette_05) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_Bombette_05 + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetBombette_01) = {
    Loop(0)
        Call(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_Bombette_01_Target, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetBombette_02) = {
    Loop(0)
        Call(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_Bombette_02_Target, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetBombette_03) = {
    Loop(0)
        Call(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_Bombette_03_Target, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetBombette_04) = {
    Loop(0)
        Call(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_Bombette_04_Target, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetBombette_05) = {
    Loop(0)
        Call(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_Bombette_05_Target, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetBombette_01) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetBombette_01)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetBombette_01)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetBombette_02) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetBombette_02)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetBombette_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetBombette_03) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetBombette_03)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetBombette_03)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetBombette_04) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetBombette_04)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetBombette_04)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetBombette_05) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetBombette_05)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetBombette_05)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

NpcData N(NpcData_TargetBombettes)[] = {
    {
        .id = NPC_Bombette_01_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_01),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_02_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_02),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_03_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_03),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_04_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_04),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_05_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_05),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_InteractableBombettes), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_00),
    NPC_GROUP(N(NpcData_Duplighosts), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_00),
    NPC_GROUP(N(NpcData_TargetBombettes), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_00),
    {}
};
