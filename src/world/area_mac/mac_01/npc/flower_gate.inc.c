EvtScript N(EVS_MinhThankYou) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetNpcPos, NPC_MinhT, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, 4, LVar0, LVar1, LVar2, 300, 16, -8)
    Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_006F)
    Call(ResetCam, CAM_DEFAULT, 4)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_GardenShyGuy1) = {
    Call(SetNpcPos, NPC_SELF, 170, 27, 380)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Loop(0)
        Call(InterpNpcYaw, NPC_SELF, 90, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 180, 27, 280, 15)
        Call(NpcMoveTo, NPC_SELF, 220, 250, 15)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 310, 27, 250, 15)
        Call(NpcMoveTo, NPC_SELF, 350, 280, 15)
        Call(InterpNpcYaw, NPC_SELF, 270, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 360, 27, 380, 15)
        Call(NpcMoveTo, NPC_SELF, 300, 450, 15)
        Call(NpcMoveTo, NPC_SELF, 230, 450, 15)
        Call(NpcMoveTo, NPC_SELF, 170, 380, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_GardenShyGuy2) = {
    Call(SetNpcPos, NPC_SELF, 350, 27, 280)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Loop(0)
        Call(InterpNpcYaw, NPC_SELF, 270, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 360, 27, 380, 15)
        Call(NpcMoveTo, NPC_SELF, 300, 450, 15)
        Call(NpcMoveTo, NPC_SELF, 230, 450, 15)
        Call(NpcMoveTo, NPC_SELF, 170, 380, 15)
        Call(InterpNpcYaw, NPC_SELF, 90, 1)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 180, 27, 280, 15)
        Call(NpcMoveTo, NPC_SELF, 220, 250, 15)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, 310, 27, 250, 15)
        Call(NpcMoveTo, NPC_SELF, 350, 280, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_GardenShyGuy_RunAway) = {
    Set(LVarA, GF_MAC01_ChasedShyGuysFromGardenA)
    Add(LVarA, GF_MAC01_ChasedShyGuysFromGardenB)
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, 27, LVar2, 10)
    Call(SetNpcSpeed, NPC_SELF, Float(8.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Set(LVar0, -1)
    Call(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    ExecGetTID(N(D_8024E6F8_80EF78), LVar9)
    Call(NpcMoveTo, NPC_SELF, 160, 400, 0)
    KillThread(LVar9)
    Call(DisablePlayerInput, FALSE)
    IfEq(LVarA, 2)
        Exec(N(EVS_MinhThankYou))
    EndIf
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 110, 20, 420, 0)
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 40, 0, 450, 0)
    Call(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    Call(NpcMoveTo, NPC_SELF, -30, 550, 0)
    Call(NpcMoveTo, NPC_SELF, -30, 700, 0)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_GardenShyGuy_PlayHitReactionSounds) = {
    Set(LVar0, 1)
    Call(GetOwnerEncounterTrigger, LVar1)
    Switch(LVar1)
        CaseEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
        CaseEq(ENCOUNTER_TRIGGER_PARTNER)
        CaseDefault
            Return
    EndSwitch
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfLe(LVar1, 50)
        Return
    EndIf
    IfLe(LVar3, 80)
        Return
    EndIf
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Return
    End
};

EvtScript N(EVS_NpcHit_GardenShyGuy1) = {
    ExecWait(N(EVS_GardenShyGuy_PlayHitReactionSounds))
    IfEq(LVar0, 1)
        Return
    EndIf
    Set(GF_MAC01_ChasedShyGuysFromGardenA, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_GardenShyGuy_RunAway)))
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Return
    End
};

EvtScript N(EVS_NpcHit_GardenShyGuy2) = {
    ExecWait(N(EVS_GardenShyGuy_PlayHitReactionSounds))
    IfEq(LVar0, 1)
        Return
    EndIf
    Set(GF_MAC01_ChasedShyGuysFromGardenB, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_GardenShyGuy_RunAway)))
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_GardenShyGuy1) = {
    IfEq(GF_MAC01_ChasedShyGuysFromGardenA, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GardenShyGuy1)))
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_GardenShyGuy1)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_GardenShyGuy2) = {
    IfEq(GF_MAC01_ChasedShyGuysFromGardenB, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_GardenShyGuy2)))
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_GardenShyGuy2)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

// BUBULB

EvtScript N(EVS_NpcInteract_Bubulb) = {
    IfEq(GB_StoryProgress, STORY_EPILOGUE)
        Set(LVar0, MSG_Outro_0045)
    Else
        Set(LVar0, MSG_MAC_Plaza_0077)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, LVar0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_STAR_SPRIT_DEPARTED, STORY_CH6_FLOWER_GATE_OPEN)
            Call(SetNpcPos, NPC_SELF, 200, 20, 500)
            Call(SetNpcYaw, NPC_SELF, 270)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb)))
        CaseEq(STORY_EPILOGUE)
            Call(SetNpcPos, NPC_SELF, 230, 30, 400)
            Call(SetNpcYaw, NPC_SELF, 270)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bubulb)))
    EndSwitch
    Return
    End
};

// MINH T

s32 N(FlowerGatePrimAlpha) = 0;

API_CALLABLE(N(SetFlowerGateGlowAlpha)) {
    Bytecode* args = script->ptrReadPos;

    N(FlowerGatePrimAlpha) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(gfx_build_flower_gate_glow)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_FLOWER_GATE_GLOW, PM_CC_FLOWER_GATE_GLOW);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(FlowerGatePrimAlpha));
}

API_CALLABLE(N(SetPartnerTetherClose)) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ResetPartnerTetherDist)) {
    partner_reset_tether_distance();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_FadeInFlowerGateGlowAlpha) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_pica, TRUE)
    Call(SetModelCustomGfx, MODEL_pica, CUSTOM_GFX_4, -1)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_4, Ref(N(gfx_build_flower_gate_glow)), NULL)
    Call(MakeLerp, 0, 255, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetFlowerGateGlowAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_ModulateFlowerGateGlowAlpha) = {
    Set(LVar1, 255)
    Loop(LVar0)
        Loop(15)
            Add(LVar1, -5)
            Call(N(SetFlowerGateGlowAlpha), LVar1)
            Wait(1)
        EndLoop
        Loop(15)
            Add(LVar1, 5)
            Call(N(SetFlowerGateGlowAlpha), LVar1)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_FadeOutFlowerGateGlowAlpha) = {
    Call(MakeLerp, 255, 0, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetFlowerGateGlowAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, MODEL_pica, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_Scene_FlowerGateAppears) = {
#if VERSION_PAL
    Call(SetCamProperties, CAM_DEFAULT, Float(1.0 / DT), 266, 27, 373, 300, 15, -6)
#else
    Call(SetCamProperties, CAM_DEFAULT, 1, 266, 27, 373, 300, 15, -6)
#endif
    Exec(N(EVS_PlayFlowerGateSong))
    PlayEffect(EFFECT_LIGHT_RAYS, 0, 266, 50, 338, 1, LVar9)
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_FadeInFlowerGateGlowAlpha))
    Thread
        Wait(10)
        PlayEffect(EFFECT_FLOATING_FLOWER, 266, 50, 338, 100, 0)
        Wait(10)
        PlayEffect(EFFECT_FLOATING_FLOWER, 240, 50, 338, 100, 0)
        Wait(10)
        PlayEffect(EFFECT_FLOATING_FLOWER, 292, 50, 338, 100, 0)
    EndThread
    Set(LVar0, 3)
    ExecGetTID(N(EVS_ModulateFlowerGateGlowAlpha), LVar2)
    Wait(30 / DT)
    Call(EnableModel, MODEL_r_door, TRUE)
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_SPINNING, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 3060, 80, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_r_door, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, MODEL_r_door, FALSE)
    Call(EnableGroup, MODEL_to_flo, TRUE)
    Call(DismissEffect, LVar9)
    Call(PlaySoundAt, SOUND_WOODEN_DOOR_WAVES, SOUND_SPACE_DEFAULT, 266, 50, 338)
    Loop(3)
        PlayEffect(EFFECT_ENERGY_ORB_WAVE, 5, 266, 50, 338, 1, 20)
        Wait(5)
    EndLoop
    Loop(0)
        Wait(1)
        IsThreadRunning(LVar2, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    ExecWait(N(EVS_FadeOutFlowerGateGlowAlpha))
#if VERSION_PAL
    Call(ResetCam, CAM_DEFAULT, Float(1 * DT))
#else
    Call(ResetCam, CAM_DEFAULT, 1)
#endif
    Exec(N(EVS_SetupMusic))
    Return
    End
};

s32 N(LetterList_MinhT_Unused)[] = {
    ITEM_LETTER_TO_MINH_T,
    ITEM_NONE
};

s32 N(ItemList_MagicalSeeds)[] = {
    ITEM_MAGICAL_SEED1,
    ITEM_MAGICAL_SEED2,
    ITEM_MAGICAL_SEED3,
    ITEM_MAGICAL_SEED4,
    ITEM_NONE
};

EvtScript N(EVS_MinhT_PlantSeed) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, LVar4)
    Wait(10 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 266, 27, 373)
    Call(SetPanTarget, CAM_DEFAULT, 266, 27, 373)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 1)
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(InterpNpcYaw, NPC_SELF, 90, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
    Call(NpcMoveTo, NPC_SELF, 175, 444, 0)
    Call(NpcJump0, NPC_SELF, 200, 27, 435, 0)
    Switch(LVar5)
        CaseEq(0)
            Call(NpcMoveTo, NPC_SELF, 200, 407, 0)
        CaseEq(1)
            Call(NpcMoveTo, NPC_SELF, 220, 420, 0)
            Call(NpcMoveTo, NPC_SELF, 200, 270, 0)
        CaseEq(2)
            Call(NpcMoveTo, NPC_SELF, 310, 420, 0)
            Call(NpcMoveTo, NPC_SELF, 330, 270, 0)
        CaseEq(3)
            Call(NpcMoveTo, NPC_SELF, 310, 420, 0)
            Call(NpcMoveTo, NPC_SELF, 330, 407, 0)
    EndSwitch
    Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Cheer)
    Wait(20 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_PLANT_FLOWERS, SOUND_SPACE_DEFAULT)
    Switch(LVar5)
        CaseEq(0)
            Call(EnableModel, MODEL_o375, TRUE)
            Call(EnableModel, MODEL_o370, TRUE)
        CaseEq(1)
            Call(EnableModel, MODEL_o377, TRUE)
            Call(EnableModel, MODEL_o372, TRUE)
        CaseEq(2)
            Call(EnableModel, MODEL_o376, TRUE)
            Call(EnableModel, MODEL_o371, TRUE)
        CaseEq(3)
            Call(EnableModel, MODEL_o378, TRUE)
            Call(EnableModel, MODEL_o373, TRUE)
    EndSwitch
    IfNe(LVar3, 3)
        Thread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
        EndThread
    EndIf
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
    Switch(LVar5)
        CaseEq(1)
            Call(NpcMoveTo, NPC_SELF, 220, 420, 0)
        CaseOrEq(2)
        CaseOrEq(3)
            Call(NpcMoveTo, NPC_SELF, 310, 420, 0)
        EndCaseGroup
    EndSwitch
    Call(NpcMoveTo, NPC_SELF, 186, 425, 0)
    Call(NpcJump0, NPC_SELF, 175, 20, 444, 0)
    Call(NpcMoveTo, NPC_SELF, 150, 480, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    IfEq(LVar3, 3)
        Call(InterpNpcYaw, NPC_MinhT, 90, 0)
        ExecWait(N(EVS_Scene_FlowerGateAppears))
        Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0070)
        Set(GB_StoryProgress, STORY_CH6_FLOWER_GATE_OPEN)
    EndIf
    Return
    End
};

EvtScript N(D_80258FFC_81987C) = {
    IfNe(LVar5, 0)
        Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0075)
    EndIf
    Set(LVar0, Ref(N(ItemList_MagicalSeeds)))
    Set(LVar1, 18)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseEq(0)
            Return
        CaseEq(-1)
            Return
        CaseEq(ITEM_MAGICAL_SEED1)
            Set(GF_MAC01_Planted_MagicalSeed1, TRUE)
            Set(LVar4, MSG_MAC_Plaza_0076)
            Set(LVar5, 0)
            ExecWait(N(EVS_MinhT_PlantSeed))
        CaseEq(ITEM_MAGICAL_SEED2)
            Set(GF_MAC01_Planted_MagicalSeed2, TRUE)
            Set(LVar4, MSG_MAC_Plaza_0076)
            Set(LVar5, 1)
            ExecWait(N(EVS_MinhT_PlantSeed))
        CaseEq(ITEM_MAGICAL_SEED3)
            Set(GF_MAC01_Planted_MagicalSeed3, TRUE)
            Set(LVar4, MSG_MAC_Plaza_0076)
            Set(LVar5, 2)
            ExecWait(N(EVS_MinhT_PlantSeed))
        CaseEq(ITEM_MAGICAL_SEED4)
            Set(GF_MAC01_Planted_MagicalSeed4, TRUE)
            Set(LVar4, MSG_MAC_Plaza_0076)
            Set(LVar5, 3)
            ExecWait(N(EVS_MinhT_PlantSeed))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_MinhT) = {
    ExecWait(N(EVS_LetterPrompt_MinhT))
    ExecWait(N(EVS_LetterReward_MinhT))
    IfNe(LVarC, 0)
        Return
    EndIf
    Set(LVar2, 0)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_MET_STAR_SPIRITS)
            Set(LVar0, MSG_MAC_Plaza_0065)
            Set(LVar1, MSG_MAC_Plaza_0065)
        CaseLt(STORY_CH3_STAR_SPIRIT_RESCUED)
            Set(LVar2, 1)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
            Add(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
            IfEq(LVar0, 2)
                Set(LVar2, 1)
            Else
                Set(LVar0, MSG_MAC_Plaza_006D)
                Set(LVar1, MSG_MAC_Plaza_006E)
            EndIf
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Set(LVar2, 1)
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Set(LVar0, MSG_MAC_Plaza_0071)
            Set(LVar1, MSG_MAC_Plaza_0071)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MAC_Plaza_0072)
            Set(LVar1, MSG_MAC_Plaza_0072)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MAC_Plaza_0073)
            Set(LVar1, MSG_MAC_Plaza_0073)
        CaseGe(STORY_EPILOGUE)
            Set(LVar0, MSG_Outro_0042)
            Set(LVar1, MSG_Outro_0042)
    EndSwitch
    IfEq(LVar2, 1)
        Set(LVar3, GF_MAC01_Planted_MagicalSeed1)
        Add(LVar3, GF_MAC01_Planted_MagicalSeed2)
        Add(LVar3, GF_MAC01_Planted_MagicalSeed3)
        Add(LVar3, GF_MAC01_Planted_MagicalSeed4)
        Switch(GB_StoryProgress)
            CaseRange(STORY_CH5_STAR_SPRIT_DEPARTED, STORY_CH5_RETURNED_TO_TOAD_TOWN)
                Set(LVar4, GF_MAC02_Gift_MagicalSeed1)
                Add(LVar4, GF_IWA02_Gift_MagicalSeed2)
                Add(LVar4, GF_MIM04_Gift_MagicalSeed3)
                Add(LVar4, GF_JAN03_Gift_MagicalSeed4)
                Set(LVar5, GF_MAC01_HeardAboutBubulbs)
                IfEq(LVar5, 0)
                    Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0074)
                    Set(GF_MAC01_HeardAboutBubulbs, TRUE)
                EndIf
                IfNe(LVar4, 0)
                    ExecWait(N(D_80258FFC_81987C))
                    Return
                EndIf
                Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0075)
                Return
        EndSwitch
        Switch(LVar3)
            CaseEq(0)
                Set(LVar0, MSG_MAC_Plaza_0066)
                Set(LVar1, MSG_MAC_Plaza_0066)
            CaseEq(1)
                Set(LVar0, MSG_MAC_Plaza_0068)
                Set(LVar1, MSG_MAC_Plaza_0068)
            CaseEq(2)
                Set(LVar0, MSG_MAC_Plaza_006A)
                Set(LVar1, MSG_MAC_Plaza_006A)
            CaseEq(3)
                Set(LVar0, MSG_MAC_Plaza_006C)
                Set(LVar1, MSG_MAC_Plaza_006C)
        EndSwitch
    EndIf
    IfEq(AF_MAC_14, FALSE)
        Set(AF_MAC_14, TRUE)
    Else
        Set(LVar0, LVar1)
        Set(AF_MAC_14, FALSE)
    EndIf
    Call(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, LVar0)
    IfEq(LVar2, 1)
        Set(LVar0, Ref(N(ItemList_MagicalSeeds)))
        Set(LVar1, 18)
        ExecWait(N(EVS_ChooseKeyItem))
        Switch(LVar0)
            CaseEq(0)
                Return
            CaseEq(-1)
                Return
            CaseEq(ITEM_MAGICAL_SEED1)
                Set(GF_MAC01_Planted_MagicalSeed1, TRUE)
                Set(LVar4, MSG_MAC_Plaza_0067)
                Set(LVar5, 0)
                ExecWait(N(EVS_MinhT_PlantSeed))
            CaseEq(ITEM_MAGICAL_SEED2)
                Set(GF_MAC01_Planted_MagicalSeed2, TRUE)
                Set(LVar4, MSG_MAC_Plaza_0069)
                Set(LVar5, 1)
                ExecWait(N(EVS_MinhT_PlantSeed))
            CaseEq(ITEM_MAGICAL_SEED3)
                Set(GF_MAC01_Planted_MagicalSeed3, TRUE)
                Set(LVar4, MSG_MAC_Plaza_006B)
                Set(LVar5, 2)
                ExecWait(N(EVS_MinhT_PlantSeed))
            CaseEq(ITEM_MAGICAL_SEED4)
                Set(LVar5, 3)
                ExecWait(N(EVS_MinhT_PlantSeed))
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_MinhT) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_MinhT) = {
    Thread
        Loop(0)
            Set(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
            Add(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
            IfEq(LVar0, 2)
                Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 0)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_MinhT)))
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcSpeed, NPC_SELF, Float(3.0))
    Add(LVar0, 25)
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
        Call(InterpNpcYaw, NPC_SELF, 270, 7)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 90, 7)
        Wait(10)
        Add(LVar0, -50)
        Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
        Call(InterpNpcYaw, NPC_SELF, 90, 7)
        Wait(10)
        Call(InterpNpcYaw, NPC_SELF, 270, 7)
        Wait(10)
        Add(LVar0, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_MinhT) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            Set(GF_MAC01_ShyGuysTramplingGarden, TRUE)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 1)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_MinhT)))
    EndSwitch
    Call(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_MinhT)))
    Return
    End
};

// FLOWER GATE

EvtScript N(EVS_ExitFlowerGate) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Wait(2)
    Call(GetPlayerActionState, LVar3)
    Set(LVar4, 0)
    IfEq(LVar3, ACTION_STATE_IDLE)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_WALK)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar3, ACTION_STATE_RUN)
        Add(LVar4, 1)
    EndIf
    IfEq(LVar4, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(N(SetPartnerTetherClose))
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_FadeInFlowerGateGlowAlpha))
    Set(LVar0, 3)
    ExecGetTID(N(EVS_ModulateFlowerGateGlowAlpha), LVar2)
    Call(PlayerMoveTo, 300, 370, 15)
    Call(InterpPlayerYaw, -22, 0)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, -120, 15, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(45)
        Call(MakeLerp, -120, 0, 15, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(15)
    Call(PlayerMoveTo, 257, 300, 30)
    Wait(60)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, 0, -500, 0)
    Call(N(ResetPartnerTetherDist))
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, 0, -500, 0)
    Loop(0)
        Wait(1)
        IsThreadRunning(LVar2, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_FadeOutFlowerGateGlowAlpha))
    Call(EnableGroup, MODEL_to_flo, FALSE)
    Call(EnableGroup, MODEL_r_door, TRUE)
    Call(MakeLerp, 180, 360, 20, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_r_door, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_r_gate, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    IfEq(GF_StartedChapter6, FALSE)
        Set(GF_StartedChapter6, TRUE)
        Call(FadeOutMusic, 0, 1500)
        Call(GotoMapSpecial, Ref("kmr_22"), kmr_22_ENTRY_6, TRANSITION_BEGIN_OR_END_CHAPTER)
        Wait(100)
        Return
    EndIf
    Call(GotoMap, Ref("flo_00"), flo_00_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterFlowerGate) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 180, 2)
    Call(SetPlayerPos, 264, 27, 320)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, 264, 27, 320)
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_FadeInFlowerGateGlowAlpha))
    Set(LVar0, 2)
    ExecGetTID(N(EVS_ModulateFlowerGateGlowAlpha), LVar2)
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -120, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnablePartnerAI)
    Call(N(SetPartnerTetherClose))
    Call(PlayerMoveTo, 264, 407, 30)
    Call(MakeLerp, -120, 0, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Loop(0)
        Wait(1)
        IsThreadRunning(LVar2, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    Call(N(ResetPartnerTetherDist))
    Call(DisablePlayerInput, FALSE)
    Call(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT)
    ExecWait(N(EVS_FadeOutFlowerGateGlowAlpha))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_SetupFlowerModels) = {
    IfEq(GF_MAC01_Planted_MagicalSeed1, FALSE)
        Call(EnableModel, MODEL_o375, FALSE)
        Call(EnableModel, MODEL_o370, FALSE)
    EndIf
    IfEq(GF_MAC01_Planted_MagicalSeed2, FALSE)
        Call(EnableModel, MODEL_o377, FALSE)
        Call(EnableModel, MODEL_o372, FALSE)
    EndIf
    IfEq(GF_MAC01_Planted_MagicalSeed3, FALSE)
        Call(EnableModel, MODEL_o376, FALSE)
        Call(EnableModel, MODEL_o371, FALSE)
    EndIf
    IfEq(GF_MAC01_Planted_MagicalSeed4, FALSE)
        Call(EnableModel, MODEL_o378, FALSE)
        Call(EnableModel, MODEL_o373, FALSE)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH6_FLOWER_GATE_OPEN)
        Call(EnableGroup, MODEL_to_flo, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_pica, FALSE)
    Call(EnableModel, MODEL_r_door, FALSE)
    Return
    End
};
