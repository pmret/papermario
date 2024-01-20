API_CALLABLE(N(SpawnExplosionEffect)) {
    Bytecode* args = script->ptrReadPos;
    f32 posY;
    f32 posX;
    f32 posZ;

    posX = evt_get_variable(script, *args++);
    posY = evt_get_variable(script, *args++);
    posZ = evt_get_variable(script, *args++);

    fx_explosion(0, posX, posY + 15.0f, posZ);
    exec_ShakeCam1(0, 0, 20);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IsPlayerOrKoopaNearby)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Npc* fuzzyNpc = (Npc*) evt_get_variable(script, *args++);
    Npc* koopaNpc = (Npc*) evt_get_variable(script, *args++);
    s32 outVal = FALSE;
    f32 xDiff, zDiff;

    if (playerStatus->curSpeed >= 4.0f) {
        script->varTable[2]++;
        if (script->varTable[2] > 2) {
            script->varTable[2] = 2;
        }
    } else {
        script->varTable[2] = 0;
    }

    do {
        xDiff = fuzzyNpc->pos.x - playerStatus->pos.x;
        zDiff = fuzzyNpc->pos.z - playerStatus->pos.z;
        if ((SQ(xDiff) + SQ(zDiff) < SQ(80.0f)) && (script->varTable[2] >= 2)) {
            do {
                outVal = TRUE;
            } while (0); // TODO required to match
        }

        xDiff = fuzzyNpc->pos.x - koopaNpc->pos.x;
        zDiff = fuzzyNpc->pos.z - koopaNpc->pos.z;
        if (SQ(xDiff) + SQ(zDiff) < SQ(40.0f)) {
            outVal = TRUE;
        }
    } while (0); // TODO required to match

    script->varTable[0] = outVal;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IsPlayerWalking)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->curSpeed >= 4.0f) {
        script->varTable[2]++;
        if (script->varTable[2] > 2) {
            script->varTable[2] = 2;
        }
    } else {
        script->varTable[2] = 0;
    }

    script->varTable[0] = TRUE;
    if (script->varTable[2] >= 2) {
        script->varTable[0] = FALSE;
    }
    if (playerStatus->curSpeed == 0.0f) {
        script->varTable[0] = FALSE;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ChooseSafeJumpLocation)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 randRange = 10000;
    Npc* fuzzyNpc = (Npc*) evt_get_variable(script, *args++);
    Npc* koopaNpc = (Npc*) evt_get_variable(script, *args++);
    f32 xDiff, zDiff;
    f32 x, z;
    f32 dist;
    s32 rand;

    while (TRUE) {
        rand = rand_int(randRange);
        x = ((rand - (randRange / 2)) / 100) + fuzzyNpc->pos.x;
        rand = rand_int(randRange);
        z = ((rand - (randRange / 2)) / 100) + fuzzyNpc->pos.z;

        xDiff = x - -150.0f;
        zDiff = z - 250.0f;
        if (SQ(xDiff) + SQ(zDiff) < SQ(150.0f)) {
            xDiff = x - playerStatus->pos.x;
            zDiff = z - playerStatus->pos.z;
            if (SQ(xDiff) + SQ(zDiff) > SQ(80.0f)) {
                xDiff = x - koopaNpc->pos.x;
                zDiff = z - koopaNpc->pos.z;
                if (SQ(xDiff) + SQ(zDiff) > SQ(40.0f)) {
                    break;
                }
            }
        }

        randRange += 5000;
        if (randRange > 30000) {
            randRange = 30000;
        }
    }
    xDiff = x - fuzzyNpc->pos.x;
    zDiff = z - fuzzyNpc->pos.z;
    dist = SQ(xDiff) + SQ(zDiff);
    if (dist != 0.0f) {
        dist = sqrtf(dist) / 10.0f;
    }
    script->varTable[10] = x;
    script->varTable[11] = z;
    script->varTable[12] = (s32) dist + 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ChooseLocationNotNearPlayer)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 randRange = 10000;
    Npc* koopaNpc = (Npc*) evt_get_variable(script, *args++);
    f32 xDiff, zDiff;
    f32 x, z;
    f32 dist;
    s32 rand;

    while (TRUE) {
        rand = rand_int(randRange);
        x = ((rand - (randRange / 2)) / 100) + koopaNpc->pos.x;
        rand = rand_int(randRange);
        z = ((rand - (randRange / 2)) / 100) + koopaNpc->pos.z;

        xDiff = x - -150.0f;
        zDiff = z - 250.0f;
        if (SQ(xDiff) + SQ(zDiff) < SQ(150.0f)) {
            xDiff = x - playerStatus->pos.x;
            zDiff = z - playerStatus->pos.z;
            if (SQ(xDiff) + SQ(zDiff) > SQ(80.0f)) {
                break;
            }
        }

        randRange += 5000;
        if (randRange > 30000) {
            randRange = 30000;
        }
    }
    xDiff = x - koopaNpc->pos.x;
    zDiff = z - koopaNpc->pos.z;
    dist = SQ(xDiff) + SQ(zDiff);
    if (dist != 0.0f) {
        dist = sqrtf(dist) / 10.0f;
    }
    script->varTable[10] = x;
    script->varTable[11] = z;
    script->varTable[12] = (s32) dist + 1;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_Koopa_02_Crisis) = {
    IfEq(GF_NOK02_RecoveredShellB, TRUE)
        Call(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005F)
        Return
    EndIf
    IfEq(GF_NOK02_StolenShellComplaintB, FALSE)
        Set(GF_NOK02_StolenShellComplaintB, TRUE)
        Call(SpeakToPlayer, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_005C)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_005D)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopa_02_Crisis) = {
    IfEq(GF_NOK02_RecoveredShellB, TRUE)
        Return
    EndIf
    ExecWait(N(EVS_NpcAI_Koopa_Wander))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopa_01_Crisis) = {
    IfEq(GF_NOK02_RecoveredShellA, TRUE)
        Call(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0057)
        Return
    EndIf
    SuspendThread(MV_KoopaChaseThiefScript)
    Wait(1)
    IfEq(GF_NOK02_StolenShellComplaintA, FALSE)
        Set(GF_NOK02_StolenShellComplaintA, TRUE)
        Call(SpeakToPlayer, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0054)
    Else
        Call(SpeakToPlayer, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0055)
    EndIf
    ResumeThread(MV_KoopaChaseThiefScript)
    Return
    End
};

EvtScript N(EVS_TetherShellToFuzzy) = {
    Label(0)
        Call(GetNpcPos, NPC_FuzzyThief, LVar0, LVar1, LVar2)
        Add(LVar2, 1)
        Call(SetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_FuzzyThief_AvoidCapture) = {
    Call(GetNpcPointer, NPC_FuzzyThief, LVarF)
    Call(GetNpcPointer, NPC_Koopa_01, LVarE)
    Set(LVar2, 0)
    Label(0)
        Call(N(IsPlayerOrKoopaNearby), LVarF, LVarE)
        Set(MV_IsPlayerNearbyThief, LVar0)
        IfNe(LVar0, 0)
            Label(1)
            Call(N(ChooseSafeJumpLocation), LVarF, LVarE)
            Call(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVarA, 0, LVarB, LVarC)
            Call(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Call(N(IsPlayerOrKoopaNearby), LVarF, LVarE)
            Set(MV_IsPlayerNearbyThief, LVar0)
            IfNe(LVar0, 0)
                Goto(1)
            EndIf
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Koopa_01_ChaseThief) = {
    SetGroup(EVT_GROUP_0B)
    Label(0)
        Call(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        Call(GetNpcAnimation, NPC_Koopa_01, LVarF)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryRun)
        Call(NpcMoveTo, NPC_Koopa_01, LVar0, LVar2, 30)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryIdle)
        Call(RandInt, 20, LVar0)
        IfNe(LVar0, 0)
            Wait(LVar0)
        EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Koopa_01_FaceShell) = {
    Label(0)
        Call(NpcFaceNpc, NPC_Koopa_01, NPC_KoopaShell_01, 0)
        Wait(5)
        Goto(0)
    Return
    End
};

EvtScript N(D_8024BDB0_9E2DD0) = {
    SetGroup(EVT_GROUP_0B)
    Set(LVar3, 0)
    Set(LVar4, 0)
    Loop(0)
        Call(N(IsPlayerWalking))
        Call(IsPlayerWithin, -150, 250, 150, LVar1)
        IfEq(LVar1, TRUE)
            IfEq(LVar0, 1)
                Set(LVar3, 1)
            Else
                Set(LVar3, 0)
                Wait(20)
            EndIf
        Else
            Set(LVar3, 0)
        EndIf
        IfNe(LVar3, LVar4)
            IfEq(LVar3, 0)
                ExecGetTID(N(EVS_Koopa_01_ChaseThief), MV_KoopaChaseThiefScript)
            Else
                IfNe(MV_KoopaChaseThiefScript, -1)
                    KillThread(MV_KoopaChaseThiefScript)
                    Set(MV_KoopaChaseThiefScript, -1)
                EndIf
            EndIf
            Set(LVar4, LVar3)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopa_01_Crisis) = {
    IfEq(GF_NOK02_RecoveredShellA, TRUE)
        Call(SetNpcPos, NPC_FuzzyThief, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_KoopaShell_01, NPC_DISPOSE_LOCATION)
        Call(SetNpcSpeed, NPC_Koopa_01, Float(3.0))
        Label(5)
            Call(GetNpcPointer, NPC_Koopa_01, LVarF)
            Call(N(ChooseLocationNotNearPlayer), LVarF)
            Call(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Run)
            Call(NpcMoveTo, NPC_Koopa_01, LVarA, LVarB, 0)
            Call(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Talk)
            Wait(10)
            Goto(5)
    EndIf
    ExecGetTID(N(EVS_TetherShellToFuzzy), LVar9)
    ExecGetTID(N(EVS_FuzzyThief_AvoidCapture), LVar8)
    ExecGetTID(N(EVS_Koopa_01_ChaseThief), MV_KoopaChaseThiefScript)
    ExecGetTID(N(D_8024BDB0_9E2DD0), MV_Unk_01)
    Label(10)
    IfEq(GF_NOK02_RecoveredShellA, FALSE)
        Wait(1)
        Goto(10)
    Else
        KillThread(LVar9)
        KillThread(LVar8)
        IsThreadRunning(MV_KoopaChaseThiefScript, LVar0)
        IfEq(LVar0, 1)
            KillThread(MV_KoopaChaseThiefScript)
        EndIf
        IsThreadRunning(MV_Unk_01, LVar0)
        IfEq(LVar0, 1)
            KillThread(MV_Unk_01)
        EndIf
        Call(DisablePlayerInput, TRUE)
        Thread
            Call(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
            Call(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Hurt)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 25)
            Add(LVar0, 40)
            Add(LVar2, -40)
            Call(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Hurt)
            Wait(10)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 15)
            Add(LVar0, 30)
            Call(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Anim09)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 13)
            Add(LVar0, 20)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 11)
            Add(LVar0, 10)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 9)
            Add(LVar0, 160)
            Call(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Run)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 15)
            Call(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_GRAVITY, FALSE)
            Call(SetNpcPos, NPC_FuzzyThief, NPC_DISPOSE_LOCATION)
        EndThread
        Call(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_KoopaShell_01, LVar0, 0, LVar2, 15)
        Loop(70)
            Call(PlayerFaceNpc, NPC_FuzzyThief, FALSE)
            Call(NpcFaceNpc, NPC_Koopa_01, NPC_FuzzyThief, 0)
            Wait(1)
        EndLoop
        Call(PlayerFaceNpc, NPC_KoopaShell_01, FALSE)
        Call(NpcFaceNpc, NPC_Koopa_01, NPC_KoopaShell_01, 0)
        Thread
            Call(AdjustCam, CAM_DEFAULT, 4, 0, Float(300.0), Float(17.0), Float(-7.0))
        EndThread
        Call(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Happy)
        Call(NpcJump0, NPC_Koopa_01, LVar0, 0, LVar2, 15)
        Call(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Run)
        Call(NpcMoveTo, NPC_Koopa_01, LVar0, LVar2, 15)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Idle)
        Call(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Add(LVar1, 10)
        Call(NpcJump0, NPC_KoopaShell_01, LVar0, LVar1, LVar2, 10)
        Call(PlayerFaceNpc, NPC_Koopa_01, FALSE)
        Call(NpcFacePlayer, NPC_Koopa_01, 0)
        Wait(10)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Still)
        Call(EnableNpcBlur, NPC_KoopaShell_01, TRUE)
        Call(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        Add(LVar0, 1)
        Add(LVar2, 1)
        Add(LVar1, 20)
        Set(LVar3, NPC_KoopaShell_01)
        Set(LVar4, NPC_Koopa_01)
        Exec(N(EVS_GetIntoShell))
        Call(InterpNpcYaw, LVar3, 60, 0)
        Call(NpcJump0, NPC_KoopaShell_01, LVar0, LVar1, LVar2, 30)
        Call(SetNpcPos, NPC_KoopaShell_01, NPC_DISPOSE_LOCATION)
        Call(SetNpcSprite, NPC_Koopa_01, ANIM_Koopa_Idle)
        Call(SetNpcFlagBits, NPC_Koopa_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Still)
        Wait(4)
        Call(EnableNpcBlur, NPC_KoopaShell_01, TRUE)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Happy)
        Wait(30)
        Call(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Idle)
        Call(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0056)
        Thread
            Call(ResetCam, CAM_DEFAULT, 4)
        EndThread
        Wait(30)
        Call(DisablePlayerInput, FALSE)
        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcIdle_Koopa_01_Crisis)))
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcHit_Fuzzy_Thief) = {
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
            Set(GF_NOK02_RecoveredShellA, TRUE)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
            Set(GF_NOK02_RecoveredShellA, TRUE)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_01_Crisis) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopa_01_Crisis)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_01_Crisis)))
    IfEq(GF_NOK02_RecoveredShellA, TRUE)
        Return
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcSprite, NPC_SELF, ANIM_KoopaWithoutShell_CryIdle)
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy_Thief) = {
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Fuzzy_Thief)))
    IfEq(GF_NOK02_RecoveredShellA, TRUE)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaShell_01_Crisis) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopa_02_Crisis) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopa_02_Crisis)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopa_02_Crisis)))
    IfEq(GF_NOK02_RecoveredShellB, FALSE)
        Call(SetNpcPos, NPC_KoopaShell_02, 150, 106, 250)
        Return
    EndIf
    Call(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaShell_02_Crisis) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kooper) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_PROMISED_TO_HELP_KOOPER)
            Call(SetNpcPos, NPC_Kooper, NPC_DISPOSE_LOCATION)
        CaseGe(STORY_CH1_KOOPER_JOINED_PARTY)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kooper)))
            Call(SetNpcPos, NPC_Kooper, NPC_DISPOSE_LOCATION)
            Return
        CaseDefault
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kooper)))
    EndSwitch
    Call(SetNpcSprite, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    Return
    End
};

EvtScript N(EVS_NpcInit_FuzzyBoss) = {
    IfGe(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
        Call(SetNpcPos, NPC_FuzzyBoss, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopersShell) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    Return
    End
};
