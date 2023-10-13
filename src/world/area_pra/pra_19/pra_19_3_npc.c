#include "pra_19.h"
#include "sprite.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Kooper) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Goompa) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_KoopaKoot) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Kolorado.inc.c"

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Luigi.h"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
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

void N(appendGfx_example_player)(void* data);
void N(worker_draw_example_player)(void);

API_CALLABLE(N(CreateExamplePlayerRenderer)) {
    script->array[0] = create_worker_world(NULL, N(worker_draw_example_player));
    return ApiStatus_DONE2;
}

void N(worker_draw_example_player)(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    Npc* npc = get_npc_safe(NPC_ExamplePlayer);

    if (gPlayerStatusPtr->flags & PS_FLAG_HAS_REFLECTION) {
        s32 x, y, z;

        get_screen_coords(gCurrentCamID, npc->pos.x, npc->pos.y, -npc->pos.z, &x, &y, &z);
        rtPtr->renderMode = npc->renderMode;
        rtPtr->dist = -z;
        rtPtr->appendGfxArg = npc;
        rtPtr->appendGfx = N(appendGfx_example_player);
        queue_render_task(rtPtr);
    }
}

void N(appendGfx_example_player)(void* data) {
    Npc* npc = data;
    Matrix4f mtxTransform, mtxTranslate, mtxScale;

    npc_get_render_yaw(npc);
    guRotateF(mtxTransform, npc->renderYaw + gCameras[gCurrentCamID].curYaw, 0.0f, 1.0f, 0.0f);
    guScaleF(mtxScale, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(mtxTransform, mtxScale, mtxTransform);
    guTranslateF(mtxTranslate, npc->pos.x, npc->pos.y, npc->pos.z);
    guMtxCatF(mtxTransform, mtxTranslate, mtxTransform);
    spr_update_player_sprite(PLAYER_SPRITE_AUX2, npc->curAnim, 1.0f);
    spr_draw_player_sprite(PLAYER_SPRITE_AUX2, 0, 0, 0, mtxTransform);
}


API_CALLABLE(N(SetPlayerFacingAngle)) {
    gPlayerStatus.spriteFacingAngle = script->varTable[0];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ChangeNpcCollisionRadius)) {
    Npc* npc1 = resolve_npc(script, script->varTable[3]);
    Npc* npc2 = resolve_npc(script, script->varTable[4]);

    npc1->collisionDiameter = npc2->collisionDiameter;
    npc1->collisionHeight = npc2->collisionHeight;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AwaitImposterHitPlayer)) {
    Npc* npc0 = get_npc_unsafe(NPC_FakeKooper);
    Npc* npc1 = get_npc_unsafe(NPC_FakeGoompa);
    Npc* npc2 = get_npc_unsafe(NPC_FakeLuigi);
    Npc* npc3 = get_npc_unsafe(NPC_FakeKoopaKoot);
    Npc* npc4 = get_npc_unsafe(NPC_FakeKolorado);
    f32 playerX = gPlayerStatus.pos.x;

    if (npc0->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc1->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc2->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc3->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc4->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(UpdateExampleKooperMotion)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(evt_get_variable(script, *args++));

    if (isInitialCall) {
        script->varTable[10] = evt_get_variable(script, *args++);
        script->varTable[11] = 8;
        script->varTable[12] = evt_get_variable(script, *args++);
        if (npc->pos.x < script->varTable[10]) {
            script->varTable[13] = 0;
        } else {
            script->varTable[13] = 1;
        }
    }

    if (script->varTable[13] == 0) {
        if (npc->pos.x >= script->varTable[10]) {
            npc->pos.x = script->varTable[10];
            return ApiStatus_DONE2;
        }
        npc->pos.x += script->varTable[11];
    } else {
        if (npc->pos.x <= script->varTable[10]) {
            npc->pos.x = script->varTable[10];
            return ApiStatus_DONE2;
        }
        npc->pos.x -= script->varTable[11];
    }

    if (script->varTable[12] == 0) {
        // move forward
        script->varTable[11] += 2;
        if (script->varTable[11] >= 14) {
            script->varTable[11] = 14;
        }
    } else {
        // return to player
        script->varTable[11] -= 2;
        if (script->varTable[11] <= 8) {
            script->varTable[11] = 8;
        }
    }
    return ApiStatus_BLOCK;
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
    EVT_CALL(SpeakToPlayer, LVar3, LVar6, LVar7, 0, LVar5)
    EVT_CALL(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, LVar3, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcPos, LVar4, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 8 * 360, 40, EASING_QUADRATIC_OUT)
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
        EVT_CALL(PlaySoundAtNpc, LVar4, SOUND_DUPLIGHOST_LEAP, SOUND_SPACE_DEFAULT)
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
    EVT_IF_EQ(MV_RevealedFakeGoompa, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_FakeGoompa, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_GoompaGhost, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_GoompaGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_GoompaGhost, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeLuigi, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_FakeLuigi, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_LuigiGhost, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_LuigiGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_LuigiGhost, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKoopaKoot, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_FakeKoopaKoot, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_KoopaKootGhost, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_KoopaKootGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_KoopaKootGhost, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKolorado, 0)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_FakeKolorado, NPC_DISPOSE_LOCATION)
            EVT_CALL(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_KoloradoGhost, LVar0, LVar1, LVar2)
            EVT_CALL(PlaySoundAtNpc, NPC_KoloradoGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(NpcMoveTo, NPC_KoloradoGhost, LVar0, LVar2, 30)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_ChaseDownPlayer) = {
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, LVar3, LVar4)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(NpcMoveTo, LVar3, LVar0, LVar2, 30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_CarryPlayerBack) = {
    EVT_CALL(InterpNpcYaw, LVar3, LVar9, 0)
    EVT_LOOP(30)
        EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
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
    EVT_CALL(SetNpcAnimation, LVar3, LVar4)
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
    EVT_IF_EQ(MV_RevealedFakeGoompa, 0)
        EVT_SET(LVar3, NPC_FakeGoompa)
        EVT_SET(LVar4, ANIM_Goompa_Run)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeLuigi, 0)
        EVT_SET(LVar3, NPC_FakeLuigi)
        EVT_SET(LVar4, ANIM_Luigi_Run)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKoopaKoot, 0)
        EVT_SET(LVar3, NPC_FakeKoopaKoot)
        EVT_SET(LVar4, ANIM_KoopaKoot_Run)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKolorado, 0)
        EVT_SET(LVar3, NPC_FakeKolorado)
        EVT_SET(LVar4, ANIM_Kolorado_Run)
        EVT_EXEC(N(EVS_Imposter_ChaseDownPlayer))
    EVT_END_IF
    EVT_SET(LVar3, NPC_FakeKooper)
    EVT_SET(LVar4, ANIM_WorldKooper_Run)
    EVT_EXEC_WAIT(N(EVS_Imposter_ChaseDownPlayer))
    EVT_CALL(InterpPlayerYaw, 90, 3)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_LayingDown)
    EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
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
            EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_IF_EQ(MV_RevealedFakeGoompa, 0)
        EVT_SET(LVar3, NPC_FakeGoompa)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 10)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeLuigi, 0)
        EVT_SET(LVar3, NPC_FakeLuigi)
        EVT_SET(LVar4, -20)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 0)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKoopaKoot, 0)
        EVT_SET(LVar3, NPC_FakeKoopaKoot)
        EVT_SET(LVar4, -20)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 10)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKolorado, 0)
        EVT_SET(LVar3, NPC_FakeKolorado)
        EVT_SET(LVar4, -20)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 20)
        EVT_EXEC(N(EVS_Imposter_CarryPlayerBack))
    EVT_END_IF
    EVT_CALL(NpcMoveTo, NPC_FakeKooper, 370, 73, 30)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_IF_EQ(MV_RevealedFakeGoompa, 0)
        EVT_SET(LVar3, NPC_FakeGoompa)
        EVT_SET(LVar4, ANIM_Goompa_Idle)
        EVT_SET(LVar0, 350)
        EVT_SET(LVar2, 90)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeLuigi, 0)
        EVT_SET(LVar3, NPC_FakeLuigi)
        EVT_SET(LVar4, ANIM_Luigi_Idle)
        EVT_SET(LVar0, 280)
        EVT_SET(LVar2, 90)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKoopaKoot, 0)
        EVT_SET(LVar3, NPC_FakeKoopaKoot)
        EVT_SET(LVar4, ANIM_KoopaKoot_Idle)
        EVT_SET(LVar0, 420)
        EVT_SET(LVar2, 60)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_IF_EQ(MV_RevealedFakeKolorado, 0)
        EVT_SET(LVar3, NPC_FakeKolorado)
        EVT_SET(LVar4, ANIM_Kolorado_Idle)
        EVT_SET(LVar0, 315)
        EVT_SET(LVar2, 55)
        EVT_EXEC(N(EVS_Imposter_ReturnToStation))
    EVT_END_IF
    EVT_SET(LVar3, NPC_FakeKooper)
    EVT_SET(LVar4, ANIM_WorldKooper_Idle)
    EVT_SET(LVar0, 385)
    EVT_SET(LVar2, 120)
    EVT_EXEC_WAIT(N(EVS_Imposter_ReturnToStation))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH7_0165, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Example_UseKooper) = {
    EVT_CALL(GetNpcPos, NPC_ExamplePlayer, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_CALL(NpcMoveTo, NPC_ExampleKooper, LVar0, LVar2, 4)
        EVT_WAIT(2)
        EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_EnterShell)
        EVT_WAIT(2)
        EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_SpinShell)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Jump)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Land)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_ExamplePlayer, EVT_FLOAT(2.0))
    EVT_CALL(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_ExamplePlayer, LVar0, LVar1, LVar2, 10)
    EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_ExampleKooper, LVar0, LVar1, LVar2)
        EVT_SET(LVar3, LVar0)
        EVT_ADD(LVar3, 140)
        EVT_CALL(N(UpdateExampleKooperMotion), NPC_ExampleKooper, LVar3, 0)
        EVT_CALL(N(UpdateExampleKooperMotion), NPC_ExampleKooper, LVar0, 1)
        EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_StillShell)
        EVT_THREAD
            EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Jump)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Land)
        EVT_END_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_ExamplePlayer, EVT_FLOAT(2.0))
        EVT_CALL(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_ExamplePlayer, LVar0, LVar1, LVar2, 10)
        EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_SpinShell)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Imposter_BurstFromWall) = {
    EVT_CALL(SetNpcPos, LVar3, 533, 0, 77)
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcSpeed, LVar3, EVT_FLOAT(6.0))
    EVT_CALL(SetNpcAnimation, LVar3, LVar4)
    EVT_CALL(NpcMoveTo, LVar3, LVar0, LVar2, 0)
    EVT_CALL(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetNpcAnimation, LVar3, LVar5)
    EVT_CALL(InterpNpcYaw, LVar3, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageImpostersScene) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_IF_EQ(GB_PRA19_TutorialState, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(GB_PRA19_TutorialState, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(GB_PRA19_TutorialState, 2)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_LABEL(0)
        EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
        EVT_CALL(SetNpcPos, NPC_ExamplePlayer, 53, 0, -75)
        EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
        EVT_CALL(SetNpcPos, NPC_ExampleKooper, 23, 0, -75)
        EVT_LABEL(1)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_LT(LVar0, 110)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(SetNpcSpeed, NPC_ExamplePlayer, EVT_FLOAT(3.0))
        EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Walk)
        EVT_THREAD
            EVT_CALL(SetNpcSpeed, NPC_ExampleKooper, EVT_FLOAT(3.0))
            EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Walk)
            EVT_CALL(NpcMoveTo, NPC_ExampleKooper, 385, -75, 0)
            EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
        EVT_END_THREAD
        EVT_CALL(NpcMoveTo, NPC_ExamplePlayer, 415, -75, 0)
        EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
        EVT_SET(GB_PRA19_TutorialState, 1)
        EVT_GOTO(11)
    EVT_LABEL(10)
        EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
        EVT_CALL(SetNpcPos, NPC_ExamplePlayer, 415, 0, -75)
        EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
        EVT_CALL(SetNpcPos, NPC_ExampleKooper, 385, 0, -75)
        EVT_LABEL(11)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_LT(LVar0, 380)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_EXEC(N(EVS_Example_UseKooper))
        EVT_SET(GB_PRA19_TutorialState, 2)
        EVT_GOTO(21)
    EVT_LABEL(20)
    EVT_CALL(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcPos, NPC_ExamplePlayer, 415, 0, -75)
    EVT_CALL(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
    EVT_CALL(SetNpcPos, NPC_ExampleKooper, 385, 0, -75)
    EVT_EXEC(N(EVS_Example_UseKooper))
    EVT_LABEL(21)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        EVT_IF_LT(LVar0, 510)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_IF_LT(LVar3, LVar0)
            EVT_GOTO(21)
        EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, TRUE)
    EVT_WAIT(60)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Question)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_WAIT(35)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1054, SOUND_TROMP_CRASH, SOUND_SPACE_DEFAULT)
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 34, 22, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_o1024, FALSE)
    EVT_CALL(EnableModel, MODEL_o1026, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1054, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar3, NPC_FakeGoompa)
    EVT_SET(LVar4, ANIM_Goompa_Run)
    EVT_SET(LVar5, ANIM_Goompa_Idle)
    EVT_SET(LVar0, 350)
    EVT_SET(LVar2, 90)
    EVT_EXEC(N(EVS_Imposter_BurstFromWall))
    EVT_SET(LVar3, NPC_FakeLuigi)
    EVT_SET(LVar4, ANIM_Luigi_Run)
    EVT_SET(LVar5, ANIM_Luigi_Idle)
    EVT_SET(LVar0, 280)
    EVT_SET(LVar2, 90)
    EVT_EXEC(N(EVS_Imposter_BurstFromWall))
    EVT_SET(LVar3, NPC_FakeKoopaKoot)
    EVT_SET(LVar4, ANIM_KoopaKoot_Run)
    EVT_SET(LVar5, ANIM_KoopaKoot_Idle)
    EVT_SET(LVar0, 420)
    EVT_SET(LVar2, 60)
    EVT_EXEC(N(EVS_Imposter_BurstFromWall))
    EVT_SET(LVar3, NPC_FakeKolorado)
    EVT_SET(LVar4, ANIM_Kolorado_Run)
    EVT_SET(LVar5, ANIM_Kolorado_Idle)
    EVT_SET(LVar0, 315)
    EVT_SET(LVar2, 55)
    EVT_EXEC(N(EVS_Imposter_BurstFromWall))
    EVT_SET(LVar3, NPC_FakeKooper)
    EVT_SET(LVar4, ANIM_WorldKooper_Run)
    EVT_SET(LVar5, ANIM_WorldKooper_Idle)
    EVT_SET(LVar0, 385)
    EVT_SET(LVar2, 120)
    EVT_EXEC(N(EVS_Imposter_BurstFromWall))
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(N(AwaitImposterHitPlayer))
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, TRUE)
        EVT_CALL(MakeLerp, 0, 11 * 180, 30, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(InterpPlayerYaw, LVar0, 0)
            EVT_CALL(N(SetPlayerFacingAngle))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, FALSE)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10)
    // kolorado imposter speaks
    EVT_CALL(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, NPC_FakeKolorado)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_FakeKolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH7_0153)
    // goomba imposter speaks
    EVT_CALL(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, NPC_FakeGoompa)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_FakeGoompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH7_0154)
     // goomba imposter speaks
    EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, NPC_FakeKooper)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_FakeKooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_0155)
     // goomba imposter speaks
    EVT_CALL(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, NPC_FakeKoopaKoot)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_FakeKoopaKoot, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH7_0156)
     // luigi imposter speaks
    EVT_CALL(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_SET(LVar3, NPC_FakeLuigi)
    EVT_EXEC(N(EVS_Imposter_HopTwice))
    EVT_CALL(SpeakToPlayer, NPC_FakeLuigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH7_0157)
     // follow-up dialogue
    EVT_CALL(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_CALL(SpeakToPlayer, NPC_FakeKolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH7_0158)
    EVT_CALL(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_CALL(SpeakToPlayer, NPC_FakeGoompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH7_0159)
    EVT_CALL(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
    EVT_SETF(LVarA, EVT_FLOAT(3.0))
    EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
    EVT_CALL(SpeakToPlayer, NPC_FakeLuigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH7_015A)
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
        EVT_IF_EQ(MV_RevealedFakeGoompa, 1)
            EVT_IF_EQ(MV_RevealedFakeLuigi, 1)
                EVT_IF_EQ(MV_RevealedFakeKoopaKoot, 1)
                    EVT_IF_EQ(MV_RevealedFakeKolorado, 1)
                        EVT_CALL(DisablePlayerInput, TRUE)
                        EVT_CALL(DisablePartnerAI, 0)
                        EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
                        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        EVT_CALL(SetNpcPos, NPC_FakeKooper, NPC_DISPOSE_LOCATION)
                        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE, FALSE)
                        EVT_CALL(GetAngleToNPC, NPC_PARTNER, LVarA)
                        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                        EVT_IF_LE(LVarA, 180)
                            EVT_ADD(LVar0, 50)
                        EVT_ELSE
                            EVT_ADD(LVar0, -50)
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldKooper_Walk)
                        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 20)
                        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldKooper_Idle)
                        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_0166)
                        EVT_WAIT(10)
                        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
                        EVT_CALL(EnablePartnerAI)
                        EVT_CALL(DisablePlayerInput, FALSE)
                        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
                        EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_SWITCH(MV_UnmaskingState)
            EVT_CASE_EQ(0)
                EVT_WAIT(1)
            EVT_CASE_EQ(NPC_FakeKooper + 1)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_FakeKooper, ANIM_WorldKooper_Hurt)
                EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_CALL(SpeakToPlayer, NPC_FakeKooper, ANIM_WorldKooper_Hurt, ANIM_WorldKooper_Hurt, 0, MSG_CH7_0162)
                EVT_EXEC_WAIT(N(EVS_FocusCam_StartBattle))
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
                EVT_EXEC_WAIT(N(EVS_RevealEveryImposter))
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(N(ChooseImposterBattleFormation), MV_RevealedFakeGoompa, MV_RevealedFakeLuigi, MV_RevealedFakeKoopaKoot, MV_RevealedFakeKolorado)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
                EVT_BREAK_LOOP
            EVT_CASE_EQ(NPC_FakeGoompa + 1)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_FakeGoompa)
                EVT_SET(LVar4, NPC_GoompaGhost)
                EVT_SET(LVar5, MSG_CH7_0161)
                EVT_SET(LVar6, ANIM_Goompa_Talk)
                EVT_SET(LVar7, ANIM_Goompa_Idle)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeGoompa, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CASE_EQ(NPC_FakeLuigi + 1)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_FakeLuigi)
                EVT_SET(LVar4, NPC_LuigiGhost)
                EVT_SET(LVar5, MSG_CH7_0164)
                EVT_SET(LVar6, ANIM_Luigi_Talk)
                EVT_SET(LVar7, ANIM_Luigi_Idle)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeLuigi, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CASE_EQ(NPC_FakeKoopaKoot + 1)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_FakeKoopaKoot)
                EVT_SET(LVar4, NPC_KoopaKootGhost)
                EVT_SET(LVar5, MSG_CH7_0163)
                EVT_SET(LVar6, ANIM_KoopaKoot_Talk)
                EVT_SET(LVar7, ANIM_KoopaKoot_Idle)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeKoopaKoot, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CASE_EQ(NPC_FakeKolorado + 1)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
                EVT_SETF(LVarA, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_FocusCam_OnPosition))
                EVT_SET(LVar3, NPC_FakeKolorado)
                EVT_SET(LVar4, NPC_KoloradoGhost)
                EVT_SET(LVar5, MSG_CH7_0160)
                EVT_SET(LVar6, ANIM_Kolorado_Talk)
                EVT_SET(LVar7, ANIM_Kolorado_Idle)
                EVT_EXEC_WAIT(N(EVS_Imposter_Unmask))
                EVT_WAIT(1)
                EVT_SET(MV_UnmaskingState, 0)
                EVT_SET(MV_RevealedFakeKolorado, 1)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_LABEL(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_DefeatMiniboss) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_FakeKooper, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_SET(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FakeKooper) = {
    EVT_CALL(SpeakToPlayer, NPC_FakeKooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_015D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FakeGoompa) = {
    EVT_CALL(SpeakToPlayer, NPC_FakeGoompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH7_015C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FakeLuigi) = {
    EVT_CALL(SpeakToPlayer, NPC_FakeLuigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH7_015F)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FakeKoopaKoot) = {
    EVT_CALL(SpeakToPlayer, NPC_FakeKoopaKoot, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH7_015E)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_FakeKolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_FakeKolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH7_015B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_Controller) = {
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_Scene_DefeatMiniboss)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_EXEC(N(EVS_ManageImpostersScene))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeKooper) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FakeKooper)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeGoompa) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FakeGoompa)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeLuigi) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FakeLuigi)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeKoopaKoot) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FakeKoopaKoot)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FakeKolorado) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_FakeKolorado)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ExamplePlayer) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Mario1_Idle)
    EVT_MALLOC_ARRAY(16, LVarA)
    EVT_CALL(N(CreateExamplePlayerRenderer))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ExampleKooper) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_Goompa) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_Luigi) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_KoopaKoot) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost_Kolorado) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Goompa)[] = {
    ANIM_Goompa_Idle,
    ANIM_Goompa_Walk,
    ANIM_Goompa_Talk,
    ANIM_Goompa_Run,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Luigi)[] = {
    ANIM_Luigi_Idle,
    ANIM_Luigi_Walk,
    ANIM_Luigi_Talk,
    ANIM_Luigi_Run,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_KoopaKoot)[] = {
    ANIM_KoopaKoot_Idle,
    ANIM_KoopaKoot_Walk,
    ANIM_KoopaKoot_Talk,
    ANIM_KoopaKoot_Run,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kolorado)[] = {
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_Walk,
    ANIM_Kolorado_Talk,
    ANIM_Kolorado_Run,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Duplighost)[] = {
    ANIM_Duplighost_Anim02,
    ANIM_Duplighost_Anim03,
    ANIM_Duplighost_Anim05,
    ANIM_Duplighost_Anim04,
    ANIM_LIST_END
};

NpcData N(NpcData_Imposters)[] = {
    {
        .id = NPC_FakeKooper,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FakeKooper),
        .settings = &N(NpcSettings_Kooper),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
    {
        .id = NPC_FakeGoompa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FakeGoompa),
        .settings = &N(NpcSettings_Goompa),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Goompa_Idle,
            .walk   = ANIM_Goompa_Walk,
            .run    = ANIM_Goompa_Run,
            .chase  = ANIM_Goompa_Run,
            .anim_4 = ANIM_Goompa_Idle,
            .anim_5 = ANIM_Goompa_Idle,
            .death  = ANIM_Goompa_Still,
            .hit    = ANIM_Goompa_Still,
            .anim_8 = ANIM_Goompa_Run,
            .anim_9 = ANIM_Goompa_Run,
            .anim_A = ANIM_Goompa_Run,
            .anim_B = ANIM_Goompa_Run,
            .anim_C = ANIM_Goompa_Run,
            .anim_D = ANIM_Goompa_Run,
            .anim_E = ANIM_Goompa_Run,
            .anim_F = ANIM_Goompa_Run,
        },
        .extraAnimations = N(ExtraAnims_Goompa),
    },
    {
        .id = NPC_FakeLuigi,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FakeLuigi),
        .settings = &N(NpcSettings_Kooper),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .extraAnimations = N(ExtraAnims_Luigi),
    },
    {
        .id = NPC_FakeKoopaKoot,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FakeKoopaKoot),
        .settings = &N(NpcSettings_KoopaKoot),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaKoot_Idle,
            .walk   = ANIM_KoopaKoot_Idle,
            .run    = ANIM_KoopaKoot_Idle,
            .chase  = ANIM_KoopaKoot_Idle,
            .anim_4 = ANIM_KoopaKoot_Idle,
            .anim_5 = ANIM_KoopaKoot_Idle,
            .death  = ANIM_KoopaKoot_Idle,
            .hit    = ANIM_KoopaKoot_Idle,
            .anim_8 = ANIM_KoopaKoot_Idle,
            .anim_9 = ANIM_KoopaKoot_Idle,
            .anim_A = ANIM_KoopaKoot_Idle,
            .anim_B = ANIM_KoopaKoot_Idle,
            .anim_C = ANIM_KoopaKoot_Idle,
            .anim_D = ANIM_KoopaKoot_Idle,
            .anim_E = ANIM_KoopaKoot_Idle,
            .anim_F = ANIM_KoopaKoot_Idle,
        },
        .extraAnimations = N(ExtraAnims_KoopaKoot),
    },
    {
        .id = NPC_FakeKolorado,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FakeKolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .extraAnimations = N(ExtraAnims_Kolorado),
    },
    {
        .id = NPC_ExamplePlayer,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ExamplePlayer),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
        .extraAnimations = N(ExtraAnims_Duplighost),
    },
    {
        .id = NPC_ExampleKooper,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ExampleKooper),
        .settings = &N(NpcSettings_Kooper),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
};

NpcData N(NpcData_Duplighosts)[] = {
    {
        .id = NPC_GoompaGhost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_Goompa),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
        .extraAnimations = N(ExtraAnims_Duplighost),
    },
    {
        .id = NPC_LuigiGhost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_Luigi),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
        .extraAnimations = N(ExtraAnims_Duplighost),
    },
    {
        .id = NPC_KoopaKootGhost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_KoopaKoot),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
        .extraAnimations = N(ExtraAnims_Duplighost),
    },
    {
        .id = NPC_KoloradoGhost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_Kolorado),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
        .extraAnimations = N(ExtraAnims_Duplighost),
    },
    {
        .id = NPC_Duplighost_Controller,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Duplighost_Controller),
        .settings = &N(NpcSettings_Duplighost),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
        .extraAnimations = N(ExtraAnims_Duplighost),
    },
};

EvtScript N(EVS_NpcIdle_TargetKooper) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_TargetKooper, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetGoompa) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_TargetGoompa, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetLuigi) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_TargetLuigi, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetKoopaKoot) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_TargetKoopaKoot, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_TargetKolorado) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_TargetKolorado, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetKooper) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_FakeKooper + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetGoompa) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_FakeGoompa + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetLuigi) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_FakeLuigi + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetKoopaKoot) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_FakeKoopaKoot + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_TargetKolorado) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(MV_UnmaskingState, NPC_FakeKolorado + 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetKooper) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetKooper)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetKooper)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetGoompa) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetGoompa)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetGoompa)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetLuigi) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetLuigi)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetLuigi)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetKoopaKoot) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetKoopaKoot)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetKoopaKoot)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TargetKolorado) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_TargetKolorado)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TargetKolorado)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Targets)[] = {
    {
        .id = NPC_TargetKooper,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetKooper),
        .settings = &N(NpcSettings_Kooper),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
    {
        .id = NPC_TargetGoompa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetGoompa),
        .settings = &N(NpcSettings_Goompa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Goompa_Idle,
            .walk   = ANIM_Goompa_Walk,
            .run    = ANIM_Goompa_Run,
            .chase  = ANIM_Goompa_Run,
            .anim_4 = ANIM_Goompa_Idle,
            .anim_5 = ANIM_Goompa_Idle,
            .death  = ANIM_Goompa_Still,
            .hit    = ANIM_Goompa_Still,
            .anim_8 = ANIM_Goompa_Run,
            .anim_9 = ANIM_Goompa_Run,
            .anim_A = ANIM_Goompa_Run,
            .anim_B = ANIM_Goompa_Run,
            .anim_C = ANIM_Goompa_Run,
            .anim_D = ANIM_Goompa_Run,
            .anim_E = ANIM_Goompa_Run,
            .anim_F = ANIM_Goompa_Run,
        },
        .extraAnimations = N(ExtraAnims_Goompa),
    },
    {
        .id = NPC_TargetLuigi,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetLuigi),
        .settings = &N(NpcSettings_Kooper),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .extraAnimations = N(ExtraAnims_Luigi),
    },
    {
        .id = NPC_TargetKoopaKoot,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetKoopaKoot),
        .settings = &N(NpcSettings_KoopaKoot),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaKoot_Idle,
            .walk   = ANIM_KoopaKoot_Idle,
            .run    = ANIM_KoopaKoot_Idle,
            .chase  = ANIM_KoopaKoot_Idle,
            .anim_4 = ANIM_KoopaKoot_Idle,
            .anim_5 = ANIM_KoopaKoot_Idle,
            .death  = ANIM_KoopaKoot_Idle,
            .hit    = ANIM_KoopaKoot_Idle,
            .anim_8 = ANIM_KoopaKoot_Idle,
            .anim_9 = ANIM_KoopaKoot_Idle,
            .anim_A = ANIM_KoopaKoot_Idle,
            .anim_B = ANIM_KoopaKoot_Idle,
            .anim_C = ANIM_KoopaKoot_Idle,
            .anim_D = ANIM_KoopaKoot_Idle,
            .anim_E = ANIM_KoopaKoot_Idle,
            .anim_F = ANIM_KoopaKoot_Idle,
        },
        .extraAnimations = N(ExtraAnims_KoopaKoot),
    },
    {
        .id = NPC_TargetKolorado,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TargetKolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .extraAnimations = N(ExtraAnims_Kolorado),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Imposters), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_01),
    NPC_GROUP(N(NpcData_Duplighosts), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_01),
    NPC_GROUP(N(NpcData_Targets), BTL_PRA3_FORMATION_01, BTL_PRA3_STAGE_01),
    {}
};

