EvtScript N(EVS_MinhThankYou) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_MinhT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, 4, LVar0, LVar1, LVar2, 300, 16, -8)
    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_006F)
    EVT_CALL(ResetCam, CAM_DEFAULT, 4)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_GardenShyGuy1) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 170, 27, 380)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, 180, 27, 280, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 220, 250, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, 310, 27, 250, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 350, 280, 15)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, 360, 27, 380, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 300, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 230, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 170, 380, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_GardenShyGuy2) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 350, 27, 280)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, 360, 27, 380, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 300, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 230, 450, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 170, 380, 15)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, 180, 27, 280, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 220, 250, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, 310, 27, 250, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 350, 280, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GardenShyGuy_RunAway) = {
    EVT_SET(LVarA, GF_MAC01_ChasedShyGuysFromGardenA)
    EVT_ADD(LVarA, GF_MAC01_ChasedShyGuysFromGardenB)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim0C)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 27, LVar2, 10)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_SET(LVar0, -1)
    EVT_CALL(PlaySoundAtNpc, LVar0, SOUND_SHY_GUY_RUN_AWAY, SOUND_SPACE_DEFAULT)
    EVT_EXEC_GET_TID(N(D_8024E6F8_80EF78), LVar9)
    EVT_CALL(NpcMoveTo, NPC_SELF, 160, 400, 0)
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(LVarA, 2)
        EVT_EXEC(N(EVS_MinhThankYou))
    EVT_END_IF
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, 110, 20, 420, 0)
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(NpcJump0, NPC_SELF, 40, 0, 450, 0)
    EVT_CALL(ShowSweat, NPC_SELF, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
    EVT_CALL(NpcMoveTo, NPC_SELF, -30, 550, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -30, 700, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GardenShyGuy_PlayHitReactionSounds) = {
    EVT_SET(LVar0, 1)
    EVT_CALL(GetOwnerEncounterTrigger, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LE(LVar1, 50)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar3, 80)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SHY_GUY_OUCH, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_GardenShyGuy1) = {
    EVT_EXEC_WAIT(N(EVS_GardenShyGuy_PlayHitReactionSounds))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_MAC01_ChasedShyGuysFromGardenA, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_GardenShyGuy_RunAway)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_GardenShyGuy2) = {
    EVT_EXEC_WAIT(N(EVS_GardenShyGuy_PlayHitReactionSounds))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_MAC01_ChasedShyGuysFromGardenB, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_GardenShyGuy_RunAway)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GardenShyGuy1) = {
    EVT_IF_EQ(GF_MAC01_ChasedShyGuysFromGardenA, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GardenShyGuy1)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_GardenShyGuy1)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GardenShyGuy2) = {
    EVT_IF_EQ(GF_MAC01_ChasedShyGuysFromGardenB, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_GardenShyGuy2)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_GardenShyGuy2)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// BUBULB

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_EPILOGUE)
        EVT_SET(LVar0, MSG_Outro_0045)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MAC_Plaza_0077)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Pink_Talk, ANIM_Bubulb_Pink_Idle, 0, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_STAR_SPRIT_DEPARTED, STORY_CH6_FLOWER_GATE_OPEN)
            EVT_CALL(SetNpcPos, NPC_SELF, 200, 20, 500)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
        EVT_CASE_EQ(STORY_EPILOGUE)
            EVT_CALL(SetNpcPos, NPC_SELF, 230, 30, 400)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_pica, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_pica, CUSTOM_GFX_4, -1)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_4, EVT_PTR(N(gfx_build_flower_gate_glow)), NULL)
    EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetFlowerGateGlowAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ModulateFlowerGateGlowAlpha) = {
    EVT_SET(LVar1, 255)
    EVT_LOOP(LVar0)
        EVT_LOOP(15)
            EVT_ADD(LVar1, -5)
            EVT_CALL(N(SetFlowerGateGlowAlpha), LVar1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(15)
            EVT_ADD(LVar1, 5)
            EVT_CALL(N(SetFlowerGateGlowAlpha), LVar1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FadeOutFlowerGateGlowAlpha) = {
    EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetFlowerGateGlowAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_pica, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_FlowerGateAppears) = {
#if VERSION_PAL
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(1.0 / DT), 266, 27, 373, 300, 15, -6)
#else
    EVT_CALL(SetCamProperties, CAM_DEFAULT, 1, 266, 27, 373, 300, 15, -6)
#endif
    EVT_EXEC(N(EVS_PlayFlowerGateSong))
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 0, 266, 50, 338, 1, LVar9)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE, SOUND_SPACE_DEFAULT)
    EVT_EXEC_WAIT(N(EVS_FadeInFlowerGateGlowAlpha))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, 266, 50, 338, 100, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, 240, 50, 338, 100, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, 292, 50, 338, 100, 0)
    EVT_END_THREAD
    EVT_SET(LVar0, 3)
    EVT_EXEC_GET_TID(N(EVS_ModulateFlowerGateGlowAlpha), LVar2)
    EVT_WAIT(30 / DT)
    EVT_CALL(EnableModel, MODEL_r_door, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_SPINNING, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 3060, 80, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_r_door, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_r_door, FALSE)
    EVT_CALL(EnableGroup, MODEL_to_flo, TRUE)
    EVT_CALL(DismissEffect, LVar9)
    EVT_CALL(PlaySoundAt, SOUND_WOODEN_DOOR_WAVES, SOUND_SPACE_DEFAULT, 266, 50, 338)
    EVT_LOOP(3)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 5, 266, 50, 338, 1, 20)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVar2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_WAIT(N(EVS_FadeOutFlowerGateGlowAlpha))
#if VERSION_PAL
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1 * DT))
#else
    EVT_CALL(ResetCam, CAM_DEFAULT, 1)
#endif
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
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
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, LVar4)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 266, 27, 373)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 266, 27, 373)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 1)
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, 175, 444, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 200, 27, 435, 0)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 200, 407, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 220, 420, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 200, 270, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(NpcMoveTo, NPC_SELF, 310, 420, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 330, 270, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(NpcMoveTo, NPC_SELF, 310, 420, 0)
            EVT_CALL(NpcMoveTo, NPC_SELF, 330, 407, 0)
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Cheer)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_PLANT_FLOWERS, SOUND_SPACE_DEFAULT)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_CALL(EnableModel, MODEL_o375, TRUE)
            EVT_CALL(EnableModel, MODEL_o370, TRUE)
        EVT_CASE_EQ(1)
            EVT_CALL(EnableModel, MODEL_o377, TRUE)
            EVT_CALL(EnableModel, MODEL_o372, TRUE)
        EVT_CASE_EQ(2)
            EVT_CALL(EnableModel, MODEL_o376, TRUE)
            EVT_CALL(EnableModel, MODEL_o371, TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(EnableModel, MODEL_o378, TRUE)
            EVT_CALL(EnableModel, MODEL_o373, TRUE)
    EVT_END_SWITCH
    EVT_IF_NE(LVar3, 3)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(1)
            EVT_CALL(NpcMoveTo, NPC_SELF, 220, 420, 0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(NpcMoveTo, NPC_SELF, 310, 420, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(NpcMoveTo, NPC_SELF, 186, 425, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 175, 20, 444, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 150, 480, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_IF_EQ(LVar3, 3)
        EVT_CALL(InterpNpcYaw, NPC_MinhT, 90, 0)
        EVT_EXEC_WAIT(N(EVS_Scene_FlowerGateAppears))
        EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0070)
        EVT_SET(GB_StoryProgress, STORY_CH6_FLOWER_GATE_OPEN)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80258FFC_81987C) = {
    EVT_IF_NE(LVar5, 0)
        EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0075)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(ItemList_MagicalSeeds)))
    EVT_SET(LVar1, 18)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_RETURN
        EVT_CASE_EQ(ITEM_MAGICAL_SEED1)
            EVT_SET(GF_MAC01_Planted_MagicalSeed1, TRUE)
            EVT_SET(LVar4, MSG_MAC_Plaza_0076)
            EVT_SET(LVar5, 0)
            EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
        EVT_CASE_EQ(ITEM_MAGICAL_SEED2)
            EVT_SET(GF_MAC01_Planted_MagicalSeed2, TRUE)
            EVT_SET(LVar4, MSG_MAC_Plaza_0076)
            EVT_SET(LVar5, 1)
            EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
        EVT_CASE_EQ(ITEM_MAGICAL_SEED3)
            EVT_SET(GF_MAC01_Planted_MagicalSeed3, TRUE)
            EVT_SET(LVar4, MSG_MAC_Plaza_0076)
            EVT_SET(LVar5, 2)
            EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
        EVT_CASE_EQ(ITEM_MAGICAL_SEED4)
            EVT_SET(GF_MAC01_Planted_MagicalSeed4, TRUE)
            EVT_SET(LVar4, MSG_MAC_Plaza_0076)
            EVT_SET(LVar5, 3)
            EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_MinhT) = {
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_MinhT))
    EVT_EXEC_WAIT(N(EVS_LetterReward_MinhT))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar2, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_MET_STAR_SPIRITS)
            EVT_SET(LVar0, MSG_MAC_Plaza_0065)
            EVT_SET(LVar1, MSG_MAC_Plaza_0065)
        EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar2, 1)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
            EVT_ADD(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
            EVT_IF_EQ(LVar0, 2)
                EVT_SET(LVar2, 1)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MAC_Plaza_006D)
                EVT_SET(LVar1, MSG_MAC_Plaza_006E)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_FLOWER_GATE_OPEN)
            EVT_SET(LVar2, 1)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_SET(LVar0, MSG_MAC_Plaza_0071)
            EVT_SET(LVar1, MSG_MAC_Plaza_0071)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MAC_Plaza_0072)
            EVT_SET(LVar1, MSG_MAC_Plaza_0072)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MAC_Plaza_0073)
            EVT_SET(LVar1, MSG_MAC_Plaza_0073)
        EVT_CASE_GE(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_Outro_0042)
            EVT_SET(LVar1, MSG_Outro_0042)
    EVT_END_SWITCH
    EVT_IF_EQ(LVar2, 1)
        EVT_SET(LVar3, GF_MAC01_Planted_MagicalSeed1)
        EVT_ADD(LVar3, GF_MAC01_Planted_MagicalSeed2)
        EVT_ADD(LVar3, GF_MAC01_Planted_MagicalSeed3)
        EVT_ADD(LVar3, GF_MAC01_Planted_MagicalSeed4)
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_RANGE(STORY_CH5_STAR_SPRIT_DEPARTED, STORY_CH5_RETURNED_TO_TOAD_TOWN)
                EVT_SET(LVar4, GF_MAC02_Gift_MagicalSeed1)
                EVT_ADD(LVar4, GF_IWA02_Gift_MagicalSeed2)
                EVT_ADD(LVar4, GF_MIM04_Gift_MagicalSeed3)
                EVT_ADD(LVar4, GF_JAN03_Gift_MagicalSeed4)
                EVT_SET(LVar5, GF_MAC01_HeardAboutBubulbs)
                EVT_IF_EQ(LVar5, 0)
                    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0074)
                    EVT_SET(GF_MAC01_HeardAboutBubulbs, TRUE)
                EVT_END_IF
                EVT_IF_NE(LVar4, 0)
                    EVT_EXEC_WAIT(N(D_80258FFC_81987C))
                    EVT_RETURN
                EVT_END_IF
                EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, MSG_MAC_Plaza_0075)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_SWITCH(LVar3)
            EVT_CASE_EQ(0)
                EVT_SET(LVar0, MSG_MAC_Plaza_0066)
                EVT_SET(LVar1, MSG_MAC_Plaza_0066)
            EVT_CASE_EQ(1)
                EVT_SET(LVar0, MSG_MAC_Plaza_0068)
                EVT_SET(LVar1, MSG_MAC_Plaza_0068)
            EVT_CASE_EQ(2)
                EVT_SET(LVar0, MSG_MAC_Plaza_006A)
                EVT_SET(LVar1, MSG_MAC_Plaza_006A)
            EVT_CASE_EQ(3)
                EVT_SET(LVar0, MSG_MAC_Plaza_006C)
                EVT_SET(LVar1, MSG_MAC_Plaza_006C)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_IF_EQ(AF_MAC_14, FALSE)
        EVT_SET(AF_MAC_14, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, LVar1)
        EVT_SET(AF_MAC_14, FALSE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_MinhT, ANIM_MinhT_Talk, ANIM_MinhT_Idle, 0, LVar0)
    EVT_IF_EQ(LVar2, 1)
        EVT_SET(LVar0, EVT_PTR(N(ItemList_MagicalSeeds)))
        EVT_SET(LVar1, 18)
        EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_RETURN
            EVT_CASE_EQ(-1)
                EVT_RETURN
            EVT_CASE_EQ(ITEM_MAGICAL_SEED1)
                EVT_SET(GF_MAC01_Planted_MagicalSeed1, TRUE)
                EVT_SET(LVar4, MSG_MAC_Plaza_0067)
                EVT_SET(LVar5, 0)
                EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
            EVT_CASE_EQ(ITEM_MAGICAL_SEED2)
                EVT_SET(GF_MAC01_Planted_MagicalSeed2, TRUE)
                EVT_SET(LVar4, MSG_MAC_Plaza_0069)
                EVT_SET(LVar5, 1)
                EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
            EVT_CASE_EQ(ITEM_MAGICAL_SEED3)
                EVT_SET(GF_MAC01_Planted_MagicalSeed3, TRUE)
                EVT_SET(LVar4, MSG_MAC_Plaza_006B)
                EVT_SET(LVar5, 2)
                EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
            EVT_CASE_EQ(ITEM_MAGICAL_SEED4)
                EVT_SET(LVar5, 3)
                EVT_EXEC_WAIT(N(EVS_MinhT_PlantSeed))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_MinhT) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_MinhT) = {
    EVT_THREAD
        EVT_LOOP(0)
            EVT_SET(LVar0, GF_MAC01_ChasedShyGuysFromGardenA)
            EVT_ADD(LVar0, GF_MAC01_ChasedShyGuysFromGardenB)
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 0)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MinhT)))
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
    EVT_ADD(LVar0, 25)
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_ADD(LVar0, -50)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Run)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 7)
        EVT_WAIT(10)
        EVT_ADD(LVar0, 50)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MinhT) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH3_STAR_SPRIT_DEPARTED, STORY_CH4_STAR_SPIRIT_RESCUED)
            EVT_SET(GF_MAC01_ShyGuysTramplingGarden, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_400000, 1)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_MinhT)))
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MinhT_Idle)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_MinhT)))
    EVT_RETURN
    EVT_END
};

// FLOWER GATE

EvtScript N(EVS_ExitFlowerGate) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_CALL(GetPlayerActionState, LVar3)
    EVT_SET(LVar4, 0)
    EVT_IF_EQ(LVar3, ACTION_STATE_IDLE)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_WALK)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar3, ACTION_STATE_RUN)
        EVT_ADD(LVar4, 1)
    EVT_END_IF
    EVT_IF_EQ(LVar4, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(SetPartnerTetherClose))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE, SOUND_SPACE_DEFAULT)
    EVT_EXEC_WAIT(N(EVS_FadeInFlowerGateGlowAlpha))
    EVT_SET(LVar0, 3)
    EVT_EXEC_GET_TID(N(EVS_ModulateFlowerGateGlowAlpha), LVar2)
    EVT_CALL(PlayerMoveTo, 300, 370, 15)
    EVT_CALL(InterpPlayerYaw, -22, 0)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, -120, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(45)
        EVT_CALL(MakeLerp, -120, 0, 15, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(PlayerMoveTo, 257, 300, 30)
    EVT_WAIT(60)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, 0, -500, 0)
    EVT_CALL(N(ResetPartnerTetherDist))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -500, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVar2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT)
    EVT_EXEC_WAIT(N(EVS_FadeOutFlowerGateGlowAlpha))
    EVT_CALL(EnableGroup, MODEL_to_flo, FALSE)
    EVT_CALL(EnableGroup, MODEL_r_door, TRUE)
    EVT_CALL(MakeLerp, 180, 360, 20, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_r_door, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_r_gate, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_EQ(GF_StartedChapter6, FALSE)
        EVT_SET(GF_StartedChapter6, TRUE)
        EVT_CALL(FadeOutMusic, 0, 1500)
        EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_22"), kmr_22_ENTRY_6, TRANSITION_BEGIN_OR_END_CHAPTER)
        EVT_WAIT(100)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), flo_00_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterFlowerGate) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 180, 2)
    EVT_CALL(SetPlayerPos, 264, 27, 320)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 264, 27, 320)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE, SOUND_SPACE_DEFAULT)
    EVT_EXEC_WAIT(N(EVS_FadeInFlowerGateGlowAlpha))
    EVT_SET(LVar0, 2)
    EVT_EXEC_GET_TID(N(EVS_ModulateFlowerGateGlowAlpha), LVar2)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -120, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(N(SetPartnerTetherClose))
    EVT_CALL(PlayerMoveTo, 264, 407, 30)
    EVT_CALL(MakeLerp, -120, 0, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_to_flo, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVar2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(N(ResetPartnerTetherDist))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitf, SOUND_FLOWER_GATE | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT)
    EVT_EXEC_WAIT(N(EVS_FadeOutFlowerGateGlowAlpha))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupFlowerModels) = {
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed1, FALSE)
        EVT_CALL(EnableModel, MODEL_o375, FALSE)
        EVT_CALL(EnableModel, MODEL_o370, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed2, FALSE)
        EVT_CALL(EnableModel, MODEL_o377, FALSE)
        EVT_CALL(EnableModel, MODEL_o372, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed3, FALSE)
        EVT_CALL(EnableModel, MODEL_o376, FALSE)
        EVT_CALL(EnableModel, MODEL_o371, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Planted_MagicalSeed4, FALSE)
        EVT_CALL(EnableModel, MODEL_o378, FALSE)
        EVT_CALL(EnableModel, MODEL_o373, FALSE)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_FLOWER_GATE_OPEN)
        EVT_CALL(EnableGroup, MODEL_to_flo, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitf, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_door_ura, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_stopper, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_pica, FALSE)
    EVT_CALL(EnableModel, MODEL_r_door, FALSE)
    EVT_RETURN
    EVT_END
};
