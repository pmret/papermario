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
    Call(SpeakToPlayer, LVar3, LVar6, LVar7, 0, LVar5)
    Call(GetNpcPos, LVar3, LVar0, LVar1, LVar2)
    Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
    Call(SetNpcPos, LVar3, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcPos, LVar4, LVar0, LVar1, LVar2)
    Call(PlaySoundAtNpc, LVar4, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 8 * 360, 40, EASING_QUADRATIC_OUT)
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
    IfEq(MV_RevealedFakeGoompa, 0)
        Thread
            Call(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_FakeGoompa, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_GoompaGhost, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_GoompaGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_GoompaGhost, LVar0, LVar2, 30)
        EndThread
    EndIf
    IfEq(MV_RevealedFakeLuigi, 0)
        Thread
            Call(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_FakeLuigi, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_LuigiGhost, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_LuigiGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_LuigiGhost, LVar0, LVar2, 30)
        EndThread
    EndIf
    IfEq(MV_RevealedFakeKoopaKoot, 0)
        Thread
            Call(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_FakeKoopaKoot, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_KoopaKootGhost, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_KoopaKootGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_KoopaKootGhost, LVar0, LVar2, 30)
        EndThread
    EndIf
    IfEq(MV_RevealedFakeKolorado, 0)
        Thread
            Call(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_FakeKolorado, NPC_DISPOSE_LOCATION)
            Call(N(PlayBigSmokePuff), LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_KoloradoGhost, LVar0, LVar1, LVar2)
            Call(PlaySoundAtNpc, NPC_KoloradoGhost, SOUND_SMOKE_BURST, SOUND_SPACE_DEFAULT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(NpcMoveTo, NPC_KoloradoGhost, LVar0, LVar2, 30)
        EndThread
    EndIf
    Wait(20)
    Return
    End
};

EvtScript N(EVS_Imposter_ChaseDownPlayer) = {
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcAnimation, LVar3, LVar4)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(NpcMoveTo, LVar3, LVar0, LVar2, 30)
    Return
    End
};

EvtScript N(EVS_Imposter_CarryPlayerBack) = {
    Call(InterpNpcYaw, LVar3, LVar9, 0)
    Loop(30)
        Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
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
    Call(SetNpcAnimation, LVar3, LVar4)
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
    IfEq(MV_RevealedFakeGoompa, 0)
        Set(LVar3, NPC_FakeGoompa)
        Set(LVar4, ANIM_Goompa_Run)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    IfEq(MV_RevealedFakeLuigi, 0)
        Set(LVar3, NPC_FakeLuigi)
        Set(LVar4, ANIM_Luigi_Run)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    IfEq(MV_RevealedFakeKoopaKoot, 0)
        Set(LVar3, NPC_FakeKoopaKoot)
        Set(LVar4, ANIM_KoopaKoot_Run)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    IfEq(MV_RevealedFakeKolorado, 0)
        Set(LVar3, NPC_FakeKolorado)
        Set(LVar4, ANIM_Kolorado_Run)
        Exec(N(EVS_Imposter_ChaseDownPlayer))
    EndIf
    Set(LVar3, NPC_FakeKooper)
    Set(LVar4, ANIM_WorldKooper_Run)
    ExecWait(N(EVS_Imposter_ChaseDownPlayer))
    Call(InterpPlayerYaw, 90, 3)
    Call(SetPlayerAnimation, ANIM_MarioW2_LayingDown)
    Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
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
            Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
            Add(LVar1, 30)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    IfEq(MV_RevealedFakeGoompa, 0)
        Set(LVar3, NPC_FakeGoompa)
        Set(LVar4, 0)
        Set(LVar5, 0)
        Set(LVar6, 10)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    IfEq(MV_RevealedFakeLuigi, 0)
        Set(LVar3, NPC_FakeLuigi)
        Set(LVar4, -20)
        Set(LVar5, 0)
        Set(LVar6, 0)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    IfEq(MV_RevealedFakeKoopaKoot, 0)
        Set(LVar3, NPC_FakeKoopaKoot)
        Set(LVar4, -20)
        Set(LVar5, 0)
        Set(LVar6, 10)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    IfEq(MV_RevealedFakeKolorado, 0)
        Set(LVar3, NPC_FakeKolorado)
        Set(LVar4, -20)
        Set(LVar5, 0)
        Set(LVar6, 20)
        Exec(N(EVS_Imposter_CarryPlayerBack))
    EndIf
    Call(NpcMoveTo, NPC_FakeKooper, 370, 73, 30)
    Call(DisablePlayerPhysics, FALSE)
    IfEq(MV_RevealedFakeGoompa, 0)
        Set(LVar3, NPC_FakeGoompa)
        Set(LVar4, ANIM_Goompa_Idle)
        Set(LVar0, 350)
        Set(LVar2, 90)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    IfEq(MV_RevealedFakeLuigi, 0)
        Set(LVar3, NPC_FakeLuigi)
        Set(LVar4, ANIM_Luigi_Idle)
        Set(LVar0, 280)
        Set(LVar2, 90)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    IfEq(MV_RevealedFakeKoopaKoot, 0)
        Set(LVar3, NPC_FakeKoopaKoot)
        Set(LVar4, ANIM_KoopaKoot_Idle)
        Set(LVar0, 420)
        Set(LVar2, 60)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    IfEq(MV_RevealedFakeKolorado, 0)
        Set(LVar3, NPC_FakeKolorado)
        Set(LVar4, ANIM_Kolorado_Idle)
        Set(LVar0, 315)
        Set(LVar2, 55)
        Exec(N(EVS_Imposter_ReturnToStation))
    EndIf
    Set(LVar3, NPC_FakeKooper)
    Set(LVar4, ANIM_WorldKooper_Idle)
    Set(LVar0, 385)
    Set(LVar2, 120)
    ExecWait(N(EVS_Imposter_ReturnToStation))
    Call(ShowMessageAtScreenPos, MSG_CH7_0165, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Example_UseKooper) = {
    Call(GetNpcPos, NPC_ExamplePlayer, LVar3, LVar4, LVar5)
    Thread
        Call(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Call(NpcMoveTo, NPC_ExampleKooper, LVar0, LVar2, 4)
        Wait(2)
        Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_EnterShell)
        Wait(2)
        Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_SpinShell)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Jump)
        Wait(10)
        Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Land)
    EndThread
    Call(SetNpcJumpscale, NPC_ExamplePlayer, Float(2.0))
    Call(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_ExamplePlayer, LVar0, LVar1, LVar2, 10)
    Label(10)
        Call(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_ExampleKooper, LVar0, LVar1, LVar2)
        Set(LVar3, LVar0)
        Add(LVar3, 140)
        Call(N(UpdateExampleKooperMotion), NPC_ExampleKooper, LVar3, 0)
        Call(N(UpdateExampleKooperMotion), NPC_ExampleKooper, LVar0, 1)
        Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_StillShell)
        Thread
            Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Jump)
            Wait(10)
            Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Land)
        EndThread
        Call(SetNpcJumpscale, NPC_ExamplePlayer, Float(2.0))
        Call(GetNpcPos, NPC_ExamplePlayer, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_ExamplePlayer, LVar0, LVar1, LVar2, 10)
        Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_SpinShell)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Imposter_BurstFromWall) = {
    Call(SetNpcPos, LVar3, 533, 0, 77)
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcSpeed, LVar3, Float(6.0))
    Call(SetNpcAnimation, LVar3, LVar4)
    Call(NpcMoveTo, LVar3, LVar0, LVar2, 0)
    Call(SetNpcFlagBits, LVar3, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetNpcAnimation, LVar3, LVar5)
    Call(InterpNpcYaw, LVar3, 90, 0)
    Return
    End
};

EvtScript N(EVS_ManageImpostersScene) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
        Goto(30)
    EndIf
    IfEq(GB_PRA19_TutorialState, 0)
        Goto(0)
    EndIf
    IfEq(GB_PRA19_TutorialState, 1)
        Goto(10)
    EndIf
    IfEq(GB_PRA19_TutorialState, 2)
        Goto(20)
    EndIf
    Label(0)
        Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
        Call(SetNpcPos, NPC_ExamplePlayer, 53, 0, -75)
        Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
        Call(SetNpcPos, NPC_ExampleKooper, 23, 0, -75)
        Label(1)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
            IfLt(LVar0, 110)
                Goto(1)
            EndIf
        Call(SetNpcSpeed, NPC_ExamplePlayer, Float(3.0))
        Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Walk)
        Thread
            Call(SetNpcSpeed, NPC_ExampleKooper, Float(3.0))
            Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Walk)
            Call(NpcMoveTo, NPC_ExampleKooper, 385, -75, 0)
            Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
        EndThread
        Call(NpcMoveTo, NPC_ExamplePlayer, 415, -75, 0)
        Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
        Set(GB_PRA19_TutorialState, 1)
        Goto(11)
    Label(10)
        Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
        Call(SetNpcPos, NPC_ExamplePlayer, 415, 0, -75)
        Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
        Call(SetNpcPos, NPC_ExampleKooper, 385, 0, -75)
        Label(11)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
            IfLt(LVar0, 380)
                Goto(11)
            EndIf
        Exec(N(EVS_Example_UseKooper))
        Set(GB_PRA19_TutorialState, 2)
        Goto(21)
    Label(20)
    Call(SetNpcAnimation, NPC_ExamplePlayer, ANIM_Mario1_Idle)
    Call(SetNpcPos, NPC_ExamplePlayer, 415, 0, -75)
    Call(SetNpcAnimation, NPC_ExampleKooper, ANIM_WorldKooper_Idle)
    Call(SetNpcPos, NPC_ExampleKooper, 385, 0, -75)
    Exec(N(EVS_Example_UseKooper))
    Label(21)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Wait(1)
        Call(GetNpcPos, NPC_PARTNER, LVar3, LVar4, LVar5)
        IfLt(LVar0, 510)
            Goto(21)
        EndIf
        IfLt(LVar3, LVar0)
            Goto(21)
        EndIf
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, TRUE)
    Wait(60)
    Call(SetPlayerAnimation, ANIM_Mario1_Question)
    Call(PlaySoundAtPlayer, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, 0, EMOTE_QUESTION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
    Wait(35)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Call(PlaySoundAtCollider, COLLIDER_o1054, SOUND_TROMP_CRASH, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 34, 22, 1, 10, 30)
    Call(EnableModel, MODEL_o1024, FALSE)
    Call(EnableModel, MODEL_o1026, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1054, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar3, NPC_FakeGoompa)
    Set(LVar4, ANIM_Goompa_Run)
    Set(LVar5, ANIM_Goompa_Idle)
    Set(LVar0, 350)
    Set(LVar2, 90)
    Exec(N(EVS_Imposter_BurstFromWall))
    Set(LVar3, NPC_FakeLuigi)
    Set(LVar4, ANIM_Luigi_Run)
    Set(LVar5, ANIM_Luigi_Idle)
    Set(LVar0, 280)
    Set(LVar2, 90)
    Exec(N(EVS_Imposter_BurstFromWall))
    Set(LVar3, NPC_FakeKoopaKoot)
    Set(LVar4, ANIM_KoopaKoot_Run)
    Set(LVar5, ANIM_KoopaKoot_Idle)
    Set(LVar0, 420)
    Set(LVar2, 60)
    Exec(N(EVS_Imposter_BurstFromWall))
    Set(LVar3, NPC_FakeKolorado)
    Set(LVar4, ANIM_Kolorado_Run)
    Set(LVar5, ANIM_Kolorado_Idle)
    Set(LVar0, 315)
    Set(LVar2, 55)
    Exec(N(EVS_Imposter_BurstFromWall))
    Set(LVar3, NPC_FakeKooper)
    Set(LVar4, ANIM_WorldKooper_Run)
    Set(LVar5, ANIM_WorldKooper_Idle)
    Set(LVar0, 385)
    Set(LVar2, 120)
    Exec(N(EVS_Imposter_BurstFromWall))
    Thread
        Wait(2)
        Call(N(AwaitImposterHitPlayer))
        Call(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, TRUE)
        Call(MakeLerp, 0, 11 * 180, 30, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(InterpPlayerYaw, LVar0, 0)
            Call(N(SetPlayerFacingAngle))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetPlayerFlagBits, PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_ROTATION_LOCKED | PS_FLAG_FACE_FORWARD, FALSE)
    EndThread
    Wait(60)
    Call(InterpPlayerYaw, 270, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(10)
    // kolorado imposter speaks
    Call(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, NPC_FakeKolorado)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_FakeKolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH7_0153)
    // goomba imposter speaks
    Call(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, NPC_FakeGoompa)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_FakeGoompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH7_0154)
     // goomba imposter speaks
    Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, NPC_FakeKooper)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_FakeKooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_0155)
     // goomba imposter speaks
    Call(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, NPC_FakeKoopaKoot)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_FakeKoopaKoot, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH7_0156)
     // luigi imposter speaks
    Call(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Set(LVar3, NPC_FakeLuigi)
    Exec(N(EVS_Imposter_HopTwice))
    Call(SpeakToPlayer, NPC_FakeLuigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH7_0157)
     // follow-up dialogue
    Call(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Call(SpeakToPlayer, NPC_FakeKolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH7_0158)
    Call(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Call(SpeakToPlayer, NPC_FakeGoompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH7_0159)
    Call(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
    SetF(LVarA, Float(3.0))
    ExecWait(N(EVS_FocusCam_OnPosition))
    Call(SpeakToPlayer, NPC_FakeLuigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH7_015A)
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
        IfEq(MV_RevealedFakeGoompa, 1)
            IfEq(MV_RevealedFakeLuigi, 1)
                IfEq(MV_RevealedFakeKoopaKoot, 1)
                    IfEq(MV_RevealedFakeKolorado, 1)
                        Call(DisablePlayerInput, TRUE)
                        Call(DisablePartnerAI, 0)
                        Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
                        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                        Call(SetNpcPos, NPC_FakeKooper, NPC_DISPOSE_LOCATION)
                        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE, FALSE)
                        Call(GetAngleToNPC, NPC_PARTNER, LVarA)
                        Call(GetPlayerPos, LVar0, LVar1, LVar2)
                        IfLe(LVarA, 180)
                            Add(LVar0, 50)
                        Else
                            Add(LVar0, -50)
                        EndIf
                        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldKooper_Walk)
                        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 20)
                        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldKooper_Idle)
                        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_0166)
                        Wait(10)
                        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                        Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
                        Call(EnablePartnerAI)
                        Call(DisablePlayerInput, FALSE)
                        BindTrigger(Ref(N(EVS_ExitWalk_pra_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
                        Set(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
                        BreakLoop
                    EndIf
                EndIf
            EndIf
        EndIf
        Switch(MV_UnmaskingState)
            CaseEq(0)
                Wait(1)
            CaseEq(NPC_FakeKooper + 1)
                Call(DisablePlayerInput, TRUE)
                Call(SetNpcAnimation, NPC_FakeKooper, ANIM_WorldKooper_Hurt)
                Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Call(SpeakToPlayer, NPC_FakeKooper, ANIM_WorldKooper_Hurt, ANIM_WorldKooper_Hurt, 0, MSG_CH7_0162)
                ExecWait(N(EVS_FocusCam_StartBattle))
                Call(SetPlayerAnimation, ANIM_Mario1_Flail)
                ExecWait(N(EVS_RevealEveryImposter))
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                Call(N(ChooseImposterBattleFormation), MV_RevealedFakeGoompa, MV_RevealedFakeLuigi, MV_RevealedFakeKoopaKoot, MV_RevealedFakeKolorado)
                Call(DisablePlayerInput, FALSE)
                Call(StartBossBattle, SONG_SPECIAL_BATTLE)
                BreakLoop
            CaseEq(NPC_FakeGoompa + 1)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_FakeGoompa)
                Set(LVar4, NPC_GoompaGhost)
                Set(LVar5, MSG_CH7_0161)
                Set(LVar6, ANIM_Goompa_Talk)
                Set(LVar7, ANIM_Goompa_Idle)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeGoompa, 1)
                Call(DisablePlayerInput, FALSE)
            CaseEq(NPC_FakeLuigi + 1)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_FakeLuigi)
                Set(LVar4, NPC_LuigiGhost)
                Set(LVar5, MSG_CH7_0164)
                Set(LVar6, ANIM_Luigi_Talk)
                Set(LVar7, ANIM_Luigi_Idle)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeLuigi, 1)
                Call(DisablePlayerInput, FALSE)
            CaseEq(NPC_FakeKoopaKoot + 1)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_FakeKoopaKoot)
                Set(LVar4, NPC_KoopaKootGhost)
                Set(LVar5, MSG_CH7_0163)
                Set(LVar6, ANIM_KoopaKoot_Talk)
                Set(LVar7, ANIM_KoopaKoot_Idle)
                ExecWait(N(EVS_Imposter_Unmask))
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeKoopaKoot, 1)
                Call(DisablePlayerInput, FALSE)
            CaseEq(NPC_FakeKolorado + 1)
                Call(DisablePlayerInput, TRUE)
                Call(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
                SetF(LVarA, Float(6.0))
                ExecWait(N(EVS_FocusCam_OnPosition))
                Set(LVar3, NPC_FakeKolorado)
                Set(LVar4, NPC_KoloradoGhost)
                Set(LVar5, MSG_CH7_0160)
                Set(LVar6, ANIM_Kolorado_Talk)
                Set(LVar7, ANIM_Kolorado_Idle)
                ExecWait(N(EVS_Imposter_Unmask))
                Wait(1)
                Set(MV_UnmaskingState, 0)
                Set(MV_RevealedFakeKolorado, 1)
                Call(DisablePlayerInput, FALSE)
        EndSwitch
    EndLoop
    Label(30)
    Return
    End
};

EvtScript N(EVS_Scene_DefeatMiniboss) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_FakeKooper, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Set(GB_StoryProgress, STORY_CH7_DEFEATED_KOOPER_DUPLIGHOSTS)
    Return
    End
};

EvtScript N(EVS_NpcInteract_FakeKooper) = {
    Call(SpeakToPlayer, NPC_FakeKooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH7_015D)
    Return
    End
};

EvtScript N(EVS_NpcInteract_FakeGoompa) = {
    Call(SpeakToPlayer, NPC_FakeGoompa, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH7_015C)
    Return
    End
};

EvtScript N(EVS_NpcInteract_FakeLuigi) = {
    Call(SpeakToPlayer, NPC_FakeLuigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_CH7_015F)
    Return
    End
};

EvtScript N(EVS_NpcInteract_FakeKoopaKoot) = {
    Call(SpeakToPlayer, NPC_FakeKoopaKoot, ANIM_KoopaKoot_Talk, ANIM_KoopaKoot_Idle, 0, MSG_CH7_015E)
    Return
    End
};

EvtScript N(EVS_NpcInteract_FakeKolorado) = {
    Call(SpeakToPlayer, NPC_FakeKolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH7_015B)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_Controller) = {
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_Scene_DefeatMiniboss)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Exec(N(EVS_ManageImpostersScene))
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeKooper) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_FakeKooper)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeGoompa) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_FakeGoompa)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeLuigi) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_FakeLuigi)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeKoopaKoot) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_FakeKoopaKoot)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_FakeKolorado) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_FakeKolorado)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_ExamplePlayer) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Mario1_Idle)
    MallocArray(16, LVarA)
    Call(N(CreateExamplePlayerRenderer))
    Return
    End
};

EvtScript N(EVS_NpcInit_ExampleKooper) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_Goompa) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_Luigi) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_KoopaKoot) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Duplighost_Kolorado) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR | NPC_FLAG_10000000, TRUE)
    Return
    End
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
    Loop(0)
        Call(GetNpcPos, NPC_FakeKooper, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_TargetKooper, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetGoompa) = {
    Loop(0)
        Call(GetNpcPos, NPC_FakeGoompa, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_TargetGoompa, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetLuigi) = {
    Loop(0)
        Call(GetNpcPos, NPC_FakeLuigi, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_TargetLuigi, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetKoopaKoot) = {
    Loop(0)
        Call(GetNpcPos, NPC_FakeKoopaKoot, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_TargetKoopaKoot, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_TargetKolorado) = {
    Loop(0)
        Call(GetNpcPos, NPC_FakeKolorado, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_TargetKolorado, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetKooper) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_FakeKooper + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetGoompa) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_FakeGoompa + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetLuigi) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_FakeLuigi + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetKoopaKoot) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_FakeKoopaKoot + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcHit_TargetKolorado) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(MV_UnmaskingState, NPC_FakeKolorado + 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetKooper) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetKooper)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetKooper)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetGoompa) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetGoompa)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetGoompa)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetLuigi) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetLuigi)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetLuigi)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetKoopaKoot) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetKoopaKoot)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetKoopaKoot)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TargetKolorado) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_TargetKolorado)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TargetKolorado)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Return
    End
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

