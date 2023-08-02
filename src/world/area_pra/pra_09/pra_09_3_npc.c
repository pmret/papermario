#include "pra_09.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/enemy/Duplighost.h"

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = 99,
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
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVarA)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-5.5))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(20.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_StartBattle) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(6.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(386.0), EVT_FLOAT(20.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FocusCam_OnPlayer) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar0, 386)
        EVT_SET(LVar0, 386)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(6.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(20.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_Unmask) = {
    EVT_CALL(N(ChangeNpcCollisionRadius))
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SpeakToPlayer, LVar3, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, LVar5)
    EVT_CALL(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, LVar3, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcPos, LVar4, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_SMOKE_BURST, 0)
    EVT_CALL(MakeLerp, 0, 2880, 40, EASING_QUADRATIC_OUT)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcRotation, LVar4, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EndSpeech, LVar4, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0)
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPlayer))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, LVar4, ANIM_Duplighost_Anim04)
        EVT_CALL(InterpNpcYaw, LVar4, 90, 0)
        EVT_CALL(SetNpcSpeed, LVar4, EVT_FLOAT(6.5))
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_2CB, 0)
        EVT_CALL(NpcMoveTo, LVar4, 0, LVar2, 0)
        EVT_CALL(SetNpcPos, LVar4, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_HopTwice) = {
    EVT_CALL(SetNpcJumpscale, LVar3, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, LVar3, LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, LVar3, LVar0, LVar1, LVar2, 10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RevealEveryImposter) = {
    EVT_IF_EQ(MV_RevealedFakeBombette1, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Bombette_02, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Duplighost_01, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_01, SOUND_SMOKE_BURST, 0)
            EVT_CALL(SetNpcAnimation, NPC_Duplighost_01, ANIM_Duplighost_Anim04)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_Duplighost_01, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette2, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Bombette_03, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Duplighost_02, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_02, SOUND_SMOKE_BURST, 0)
            EVT_CALL(SetNpcAnimation, NPC_Duplighost_02, ANIM_Duplighost_Anim04)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_Duplighost_02, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette3, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Bombette_04, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Duplighost_03, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_03, SOUND_SMOKE_BURST, 0)
            EVT_CALL(SetNpcAnimation, NPC_Duplighost_03, ANIM_Duplighost_Anim04)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_Duplighost_03, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette4, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Bombette_05, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_Duplighost_04, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_Duplighost_04, SOUND_SMOKE_BURST, 0)
            EVT_CALL(SetNpcAnimation, NPC_Duplighost_04, ANIM_Duplighost_Anim04)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_Duplighost_04, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_ChaseDownPlayer) = {
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, LVar3, ANIM_WorldBombette_Run)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(NpcMoveTo, LVar3, LVar0, LVar2, 30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_CarryPlayerBack) = {
    EVT_CALL(InterpNpcYaw, LVar3, LVar9, 0)
    EVT_LOOP(30)
        EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, LVar4)
        EVT_ADD(LVar1, LVar5)
        EVT_ADD(LVar2, LVar6)
        EVT_CALL(SetNpcPos, LVar3, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_ReturnToStation) = {
    EVT_CALL(NpcMoveTo, LVar3, LVar0, LVar2, 20)
    EVT_CALL(SetNpcAnimation, LVar3, ANIM_WorldBombette_Idle)
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(InterpNpcYaw, LVar3, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreventPlayerLeaving) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_IF_EQ(MV_RevealedFakeBombette1, 0)
        EVT_SET(LVar3, NPC_Bombette_02)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette2, 0)
        EVT_SET(LVar3, NPC_Bombette_03)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette3, 0)
        EVT_SET(LVar3, NPC_Bombette_04)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette4, 0)
        EVT_SET(LVar3, NPC_Bombette_05)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_SET(LVar3, 0)
    EVT_EXEC_WAIT(N(EVS_Imposter_ChaseDownPlayer))
    EVT_CALL(InterpPlayerYaw, 90, 3)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LayingDown)
    EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_LOOP(35)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_IF_EQ(MV_RevealedFakeBombette1, 0)
        EVT_SET(LVar3, NPC_Bombette_02)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 10)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette2, 0)
        EVT_SET(LVar3, NPC_Bombette_03)
        EVT_SET(LVar4, -20)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 0)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette3, 0)
        EVT_SET(LVar3, NPC_Bombette_04)
        EVT_SET(LVar4, -20)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 10)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette4, 0)
        EVT_SET(LVar3, NPC_Bombette_05)
        EVT_SET(LVar4, -20)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 20)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_CALL(NpcMoveTo, NPC_Bombette_01, 370, 73, 30)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_IF_EQ(MV_RevealedFakeBombette1, 0)
        EVT_SET(LVar3, NPC_Bombette_02)
        EVT_SET(LVar0, 280)
        EVT_SET(LVar2, 100)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette2, 0)
        EVT_SET(LVar3, NPC_Bombette_03)
        EVT_SET(LVar0, 315)
        EVT_SET(LVar2, 55)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette3, 0)
        EVT_SET(LVar3, NPC_Bombette_04)
        EVT_SET(LVar0, 350)
        EVT_SET(LVar2, 80)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeBombette4, 0)
        EVT_SET(LVar3, NPC_Bombette_05)
        EVT_SET(LVar0, 420)
        EVT_SET(LVar2, 60)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_SET(LVar3, 0)
    EVT_SET(LVar0, 385)
    EVT_SET(LVar2, 120)
    EVT_EXEC_WAIT(N(EVS_Imposter_ReturnToStation))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_014E, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageImpostersScene) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(0)
        EVT_SET(LVar0, GF_PRA09_BombedWall)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(25)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 386, 0, 93)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 386, 0, 93)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(500.0), EVT_FLOAT(20.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_SET(LVar0, NPC_Bombette_04)
        EVT_SET(LVar1, 350)
        EVT_SET(LVar2, 150)
        EVT_SET(LVar3, 90)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(N(ImposterFallFromCeiling))
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_THREAD
        EVT_SET(LVar0, NPC_Bombette_02)
        EVT_SET(LVar1, 280)
        EVT_SET(LVar2, 150)
        EVT_SET(LVar3, 100)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(N(ImposterFallFromCeiling))
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_THREAD
        EVT_SET(LVar0, NPC_Bombette_05)
        EVT_SET(LVar1, 420)
        EVT_SET(LVar2, 150)
        EVT_SET(LVar3, 60)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(N(ImposterFallFromCeiling))
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_THREAD
        EVT_SET(LVar0, NPC_Bombette_01)
        EVT_SET(LVar1, 385)
        EVT_SET(LVar2, 150)
        EVT_SET(LVar3, 120)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(N(ImposterFallFromCeiling))
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_SET(LVar0, NPC_Bombette_03)
    EVT_SET(LVar1, 315)
    EVT_SET(LVar2, 150)
    EVT_SET(LVar3, 55)
    EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(N(ImposterFallFromCeiling))
    EVT_WAIT(1)
    EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_WAIT(30)
    EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_01, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013C)
    EVT_CALL(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, 1)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_02, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013D)
    EVT_CALL(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, 2)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_03, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013E)
    EVT_CALL(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, 3)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_04, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_013F)
    EVT_CALL(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, 4)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_05, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0140)
    EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_01, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0141)
    EVT_CALL(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_03, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0142)
    EVT_CALL(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_CALL(SpeakToPlayer, NPC_Bombette_04, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0143)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, TRUE)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 490)
            EVT_SET(LVar9, 270)
            EVT_EXEC_WAIT(N(EVS_PreventPlayerLeaving))
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 190)
            EVT_SET(LVar9, 90)
            EVT_EXEC_WAIT(N(EVS_PreventPlayerLeaving))
        EVT_END_IF
        EVT_IF_EQ(MV_RevealedFakeBombette1, 1)
            EVT_IF_EQ(MV_RevealedFakeBombette2, 1)
                EVT_IF_EQ(MV_RevealedFakeBombette3, 1)
                    EVT_IF_EQ(MV_RevealedFakeBombette4, 1)
                        EVT_CALL(DisablePlayerInput, TRUE)
                        EVT_CALL(DisablePartnerAI, 0)
                        EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
                        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        EVT_CALL(SetNpcPos, NPC_Bombette_01, NPC_DISPOSE_LOCATION)
                        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE, FALSE)
                        EVT_CALL(GetAngleToNPC, NPC_PARTNER, LVarA)
                        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                        EVT_IF_LE(LVarA, 180)
                            EVT_ADD(LVar0, 20)
                        EVT_ELSE
                            EVT_ADD(LVar0, -20)
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Walk)
                        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 20)
                        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Idle)
                        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_014F)
                        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.0))
                        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_HappyJump)
                        EVT_THREAD
                            EVT_WAIT(5)
                            EVT_ADD(LVar1, 10)
                            EVT_CALL(GetAngleToNPC, NPC_PARTNER, LVarA)
                            EVT_IF_GE(LVarA, 180)
                                EVT_ADD(LVar0, 20)
                            EVT_END_IF
                            EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar0, LVar1, LVar2, 0)
                            EVT_CALL(PlaySoundAtPlayer, SOUND_214, 0)
                        EVT_END_THREAD
                        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
                        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Idle)
                        EVT_WAIT(10)
                        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
                        EVT_CALL(EnablePartnerAI)
                        EVT_CALL(DisablePlayerInput, FALSE)
                        EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
                        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_SWITCH(MV_UnmaskingState)
            EVT_CASE_EQ(0)
                EVT_WAIT(1)
            EVT_CASE_EQ(1)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_CALL(SpeakToPlayer, NPC_Bombette_01, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Hurt, 0, MSG_CH7_0149)
                EVT_EXEC_WAIT(N(EVS_FocusCam_StartBattle))
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
                EVT_EXEC_WAIT(N(EVS_RevealEveryImposter))
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(N(ChooseImposterBattleFormation), MV_RevealedFakeBombette1, MV_RevealedFakeBombette2, MV_RevealedFakeBombette3, MV_RevealedFakeBombette4)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
                EVT_BREAK_LOOP
            EVT_CASE_EQ(2)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_Bombette_02)
                EVT_SET(LVar4, NPC_Duplighost_01)
                EVT_SET(LVar5, MSG_CH7_014A)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeBombette1, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CASE_EQ(3)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_Bombette_03)
                EVT_SET(LVar4, NPC_Duplighost_02)
                EVT_SET(LVar5, MSG_CH7_014B)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeBombette2, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CASE_EQ(4)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_Bombette_04)
                EVT_SET(LVar4, NPC_Duplighost_03)
                EVT_SET(LVar5, MSG_CH7_014C)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeBombette3, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CASE_EQ(5)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_Bombette_05)
                EVT_SET(LVar4, NPC_Duplighost_04)
                EVT_SET(LVar5, MSG_CH7_014D)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeBombette4, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Duplighost_05) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_Bombette_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombette_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0144)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombette_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0145)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombette_03) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0146)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombette_04) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0147)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bombette_05) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH7_0148)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_05) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Duplighost_05)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_EXEC(N(EVS_ManageImpostersScene))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombette_01)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombette_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombette_03)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombette_04)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bombette_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bombette_05)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_01) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_03) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_04) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_02),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_03),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_04),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
    {
        .id = NPC_Duplighost_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_05),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = DUPLIGHOST_ANIMS,
    },
};

EvtScript N(EVS_NpcHit_TargetBombette_01) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_Bombette_01 + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetBombette_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_Bombette_02 + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetBombette_03) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_Bombette_03 + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetBombette_04) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_Bombette_04 + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetBombette_05) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_Bombette_05 + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetBombette_01) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bombette_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Bombette_01_Target, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetBombette_02) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bombette_02, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Bombette_02_Target, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetBombette_03) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bombette_03, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Bombette_03_Target, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetBombette_04) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bombette_04, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Bombette_04_Target, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetBombette_05) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Bombette_05, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Bombette_05_Target, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetBombette_01) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetBombette_01)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetBombette_01)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetBombette_02) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetBombette_02)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetBombette_02)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetBombette_03) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetBombette_03)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetBombette_03)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetBombette_04) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetBombette_04)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetBombette_04)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetBombette_05) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetBombette_05)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetBombette_05)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_TargetBombettes)[] = {
    {
        .id = NPC_Bombette_01_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_01),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_02_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_02),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_03_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_03),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_04_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_04),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOMBETTE_ANIMS,
    },
    {
        .id = NPC_Bombette_05_Target,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetBombette_05),
        .settings = &N(NpcSettings_Bombette),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
