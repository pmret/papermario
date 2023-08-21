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
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005F)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_NOK02_StolenShellComplaintB, FALSE)
        EVT_SET(GF_NOK02_StolenShellComplaintB, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_005C)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Koopa_02, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_005D)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopa_02_Crisis) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_NpcAI_Koopa_Wander))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopa_01_Crisis) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0057)
        EVT_RETURN
    EVT_END_IF
    EVT_SUSPEND_THREAD(MV_KoopaChaseThiefScript)
    EVT_WAIT(1)
    EVT_IF_EQ(GF_NOK02_StolenShellComplaintA, FALSE)
        EVT_SET(GF_NOK02_StolenShellComplaintA, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0054)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0055)
    EVT_END_IF
    EVT_RESUME_THREAD(MV_KoopaChaseThiefScript)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherShellToFuzzy) = {
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_FuzzyThief, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 1)
        EVT_CALL(SetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FuzzyThief_AvoidCapture) = {
    EVT_CALL(GetNpcPointer, NPC_FuzzyThief, LVarF)
    EVT_CALL(GetNpcPointer, NPC_Koopa_01, LVarE)
    EVT_SET(LVar2, 0)
    EVT_LABEL(0)
        EVT_CALL(N(IsPlayerOrKoopaNearby), LVarF, LVarE)
        EVT_SET(MV_IsPlayerNearbyThief, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_LABEL(1)
            EVT_CALL(N(ChooseSafeJumpLocation), LVarF, LVarE)
            EVT_CALL(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVarA, 0, LVarB, LVarC)
            EVT_CALL(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(N(IsPlayerOrKoopaNearby), LVarF, LVarE)
            EVT_SET(MV_IsPlayerNearbyThief, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Koopa_01_ChaseThief) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcAnimation, NPC_Koopa_01, LVarF)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryRun)
        EVT_CALL(NpcMoveTo, NPC_Koopa_01, LVar0, LVar2, 30)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_CryIdle)
        EVT_CALL(RandInt, 20, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_WAIT(LVar0)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Koopa_01_FaceShell) = {
    EVT_LABEL(0)
        EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_KoopaShell_01, 0)
        EVT_WAIT(5)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BDB0_9E2DD0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, 0)
    EVT_LOOP(0)
        EVT_CALL(N(IsPlayerWalking))
        EVT_CALL(IsPlayerWithin, -150, 250, 150, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET(LVar3, 1)
            EVT_ELSE
                EVT_SET(LVar3, 0)
                EVT_WAIT(20)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar3, 0)
        EVT_END_IF
        EVT_IF_NE(LVar3, LVar4)
            EVT_IF_EQ(LVar3, 0)
                EVT_EXEC_GET_TID(N(EVS_Koopa_01_ChaseThief), MV_KoopaChaseThiefScript)
            EVT_ELSE
                EVT_IF_NE(MV_KoopaChaseThiefScript, -1)
                    EVT_KILL_THREAD(MV_KoopaChaseThiefScript)
                    EVT_SET(MV_KoopaChaseThiefScript, -1)
                EVT_END_IF
            EVT_END_IF
            EVT_SET(LVar4, LVar3)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopa_01_Crisis) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_FuzzyThief, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_KoopaShell_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcSpeed, NPC_Koopa_01, EVT_FLOAT(3.0))
        EVT_LABEL(5)
            EVT_CALL(GetNpcPointer, NPC_Koopa_01, LVarF)
            EVT_CALL(N(ChooseLocationNotNearPlayer), LVarF)
            EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Run)
            EVT_CALL(NpcMoveTo, NPC_Koopa_01, LVarA, LVarB, 0)
            EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Talk)
            EVT_WAIT(10)
            EVT_GOTO(5)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(EVS_TetherShellToFuzzy), LVar9)
    EVT_EXEC_GET_TID(N(EVS_FuzzyThief_AvoidCapture), LVar8)
    EVT_EXEC_GET_TID(N(EVS_Koopa_01_ChaseThief), MV_KoopaChaseThiefScript)
    EVT_EXEC_GET_TID(N(D_8024BDB0_9E2DD0), MV_Unk_01)
    EVT_LABEL(10)
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_KILL_THREAD(LVar9)
        EVT_KILL_THREAD(LVar8)
        EVT_IS_THREAD_RUNNING(MV_KoopaChaseThiefScript, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_KILL_THREAD(MV_KoopaChaseThiefScript)
        EVT_END_IF
        EVT_IS_THREAD_RUNNING(MV_Unk_01, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_KILL_THREAD(MV_Unk_01)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 25)
            EVT_ADD(LVar0, 40)
            EVT_ADD(LVar2, -40)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Hurt)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 15)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Anim09)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 13)
            EVT_ADD(LVar0, 20)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 11)
            EVT_ADD(LVar0, 10)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 9)
            EVT_ADD(LVar0, 160)
            EVT_CALL(SetNpcAnimation, NPC_FuzzyThief, ANIM_Fuzzy_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_FUZZY_HOP_A, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_FuzzyThief, LVar0, 0, LVar2, 15)
            EVT_CALL(SetNpcFlagBits, NPC_FuzzyThief, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_FuzzyThief, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_KoopaShell_01, LVar0, 0, LVar2, 15)
        EVT_LOOP(70)
            EVT_CALL(PlayerFaceNpc, NPC_FuzzyThief, FALSE)
            EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_FuzzyThief, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlayerFaceNpc, NPC_KoopaShell_01, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_Koopa_01, NPC_KoopaShell_01, 0)
        EVT_THREAD
            EVT_CALL(AdjustCam, CAM_DEFAULT, 4, 0, EVT_FLOAT(300.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Happy)
        EVT_CALL(NpcJump0, NPC_Koopa_01, LVar0, 0, LVar2, 15)
        EVT_CALL(GetNpcPos, NPC_KoopaShell_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Run)
        EVT_CALL(NpcMoveTo, NPC_Koopa_01, LVar0, LVar2, 15)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Idle)
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 10)
        EVT_CALL(NpcJump0, NPC_KoopaShell_01, LVar0, LVar1, LVar2, 10)
        EVT_CALL(PlayerFaceNpc, NPC_Koopa_01, FALSE)
        EVT_CALL(NpcFacePlayer, NPC_Koopa_01, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_KoopaWithoutShell_Still)
        EVT_CALL(EnableNpcBlur, NPC_KoopaShell_01, TRUE)
        EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 20)
        EVT_SET(LVar3, NPC_KoopaShell_01)
        EVT_SET(LVar4, NPC_Koopa_01)
        EVT_EXEC(N(EVS_GetIntoShell))
        EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
        EVT_CALL(NpcJump0, NPC_KoopaShell_01, LVar0, LVar1, LVar2, 30)
        EVT_CALL(SetNpcPos, NPC_KoopaShell_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcSprite, NPC_Koopa_01, ANIM_Koopa_Idle)
        EVT_CALL(SetNpcFlagBits, NPC_Koopa_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Still)
        EVT_WAIT(4)
        EVT_CALL(EnableNpcBlur, NPC_KoopaShell_01, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Happy)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Koopa_01, ANIM_Koopa_Idle)
        EVT_CALL(SpeakToPlayer, NPC_Koopa_01, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0056)
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, 4)
        EVT_END_THREAD
        EVT_WAIT(30)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_01_Crisis)))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Fuzzy_Thief) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(GF_NOK02_RecoveredShellA, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(GF_NOK02_RecoveredShellA, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_DISABLE_AI, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_01_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_01_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_01_Crisis)))
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_KoopaWithoutShell_CryIdle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy_Thief) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Fuzzy_Thief)))
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaShell_01_Crisis) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopa_02_Crisis) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopa_02_Crisis)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopa_02_Crisis)))
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, FALSE)
        EVT_CALL(SetNpcPos, NPC_KoopaShell_02, 150, 106, 250)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_Koopa_02, ANIM_Koopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaShell_02_Crisis) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kooper) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_PROMISED_TO_HELP_KOOPER)
            EVT_CALL(SetNpcPos, NPC_Kooper, NPC_DISPOSE_LOCATION)
        EVT_CASE_GE(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kooper)))
            EVT_CALL(SetNpcPos, NPC_Kooper, NPC_DISPOSE_LOCATION)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kooper)))
    EVT_END_SWITCH
    EVT_CALL(SetNpcSprite, NPC_Kooper, ANIM_KooperWithoutShell_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_FuzzyBoss) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
        EVT_CALL(SetNpcPos, NPC_FuzzyBoss, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopersShell) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    EVT_RETURN
    EVT_END
};
