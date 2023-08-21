API_CALLABLE(N(func_80244984_805204)) {
    s32 flagBase = GF_MAC01_RowfBadge_00;
    s32 count = 0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(N(RowfBadgeInventory)); i++) {
        if (evt_get_variable(NULL, flagBase + i) == 0) {
            count++;
        }
    }
    script->varTable[0] = count;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RhuffUnravelUpdate)) {
    s32 rugRotAngle = -evt_get_variable(NULL, MV_RowfRugRotateAngle);
    s32 rugRippleAmt = evt_get_variable(NULL, MV_RowfRugRippleAmount);
    Npc* npc = script->varTablePtr[7];
    Enemy* enemy = get_enemy(NPC_Rhuff);
    f32 theta = (rugRotAngle / 180.0f) * PI;
    f32 sinTheta = sin_rad(theta);
    f32 cosTheta = cos_rad(theta);
    f32 initialPosX = script->varTable[0];
    f32 initialPosY = script->varTable[1];

    script->varTable[4] = script->varTable[2] + (s32) ((initialPosX * cosTheta) - (initialPosY * sinTheta));
    script->varTable[5] = script->varTable[3] + (s32) ((initialPosX * sinTheta) + (initialPosY * cosTheta));

    if (rugRotAngle == 0) {
        npc->curAnim = ANIM_Rowf_Idle;
        enemy->flags &= ~ENEMY_FLAG_CANT_INTERACT;
    } else {
        npc->curAnim = ANIM_Rowf_Walk;
        enemy->flags |= ENEMY_FLAG_CANT_INTERACT;
    }

    if (rugRotAngle == -60) {
        npc->flags |= NPC_FLAG_INVISIBLE;
    } else {
        npc->flags &= ~NPC_FLAG_INVISIBLE;
    }

    if (rugRippleAmt != 0) {
        npc->curAnim = ANIM_Rowf_Think;
    }
    return ApiStatus_DONE2;
}

void N(gfx_build_rowf_rug_with_ripples)(void) {
    s32 rippleAmt = evt_get_variable(NULL, MV_RowfRugRippleAmount);
    Vtx* src;
    Vtx* copy;
    Vtx* vtx;
    s32 numCopied;
    s32 i;

    mdl_get_copied_vertices(VTX_COPY_0, &src, &copy, &numCopied);

    for (i = 0; i < numCopied; i++) {
        // 5th set of vertices on the rug from the left
        if (src[i].v.ob[0] == -78) {
            vtx = &copy[i];

            if (src[i].v.ob[1] == 0) {
                vtx->v.ob[1] = src[i].v.ob[1] - (rippleAmt / 4);
            } else {
                vtx->v.ob[1] = src[i].v.ob[1] + (rippleAmt / 4);
            }
        // 3rd set of vertices on the rug from the left
        } else if (src[i].v.ob[0] == -16) {
            vtx = &copy[i];

            if (src[i].v.ob[1] == 0) {
                vtx->v.ob[1] = src[i].v.ob[1] - (rippleAmt / 4);
            } else {
                vtx->v.ob[1] = src[i].v.ob[1] + (rippleAmt / 4);
            }
        }
    }

    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_0));
}

API_CALLABLE(N(RevealRowfBadges)) {
    if (!evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableA)) {
        clear_item_entity_flags(gGameStatusPtr->shopItemEntities[0].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    if (!evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableB)) {
        clear_item_entity_flags(gGameStatusPtr->shopItemEntities[1].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    if (!evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableC)) {
        clear_item_entity_flags(gGameStatusPtr->shopItemEntities[2].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(HideRowfBadges)) {
    if (!evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableA)) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[0].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    if (!evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableB)) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[1].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    if (!evt_get_variable(NULL, GF_MAC01_RowfBadgeAvailableC)) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[2].index, ITEM_ENTITY_FLAG_HIDDEN);
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_Rowf_A) = {
    EVT_IF_EQ(GF_MAC01_Met_Rowf_Early, FALSE)
        EVT_SET(GF_MAC01_Met_Rowf_Early, TRUE)
        EVT_SET(AF_MAC_41, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0000)
    EVT_ELSE
        EVT_IF_EQ(AF_MAC_41, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0001)
        EVT_ELSE
            EVT_SET(AF_MAC_41, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Think, 0, MSG_MAC_Plaza_0002)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rowf_B) = {
    EVT_SET(LVar0, GF_MAC01_RowfBadgeAvailableA)
    EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableB)
    EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableC)
    EVT_IF_EQ(LVar0, 3)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
            EVT_SET(LVar1, MSG_MAC_Plaza_0005)
        EVT_ELSE
            EVT_CALL(N(func_80244984_805204))
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar1, MSG_MAC_Plaza_0006)
            EVT_ELSE
                EVT_SET(LVar1, MSG_MAC_Plaza_0005)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, LVar1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_Met_Rowf_Late, FALSE)
        EVT_SET(GF_MAC01_Met_Rowf_Late, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0003)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0004)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_Calculator)[] = {
    ITEM_CALCULATOR,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Rowf_C) = {
    EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_000A)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0008)
    EVT_SET(LVar0, EVT_PTR(N(ItemList_Calculator)))
    EVT_SET(LVar1, 1)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(-1)
            EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_000B)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0009)
            EVT_WAIT(10)
            EVT_SET(LVar0, ITEM_I_SPY)
            EVT_SET(LVar3, 2)
            EVT_EXEC_WAIT(N(GiveItemReward))
            EVT_CALL(AddBadge, LVar0, LVar1)
            EVT_SET(GF_MAC01_CalculatorReturned, TRUE)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0011)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RhuffChapter1) = {
    EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000C)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rhuff_B) = {
    EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0014)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rhuff_C) = {
    EVT_CALL(N(func_80244984_805204))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000F)
    EVT_ELSE
        EVT_SET(LVar0, GF_MAC01_RowfBadgeAvailableA)
        EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableB)
        EVT_ADD(LVar0, GF_MAC01_RowfBadgeAvailableC)
        EVT_IF_EQ(LVar0, 3)
            EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000E)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000D)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Rhuff_D) = {
    EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0012)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0010)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Rowf) = {
    EVT_CALL(SetNpcPos, NPC_Rowf, -250, 0, 295)
    EVT_LABEL(0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    EVT_CALL(NpcMoveTo, NPC_Rowf, -260, 281, 4)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Walk)
    EVT_CALL(NpcMoveTo, NPC_Rowf, -410, 281, 60)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Idle)
    EVT_CALL(RotateGroup, MODEL_jutan2, 60, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Rowf, -407, 0, 281)
    EVT_CALL(RotateGroup, MODEL_jutan2, 40, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Rowf, -404, 0, 281)
    EVT_CALL(RotateGroup, MODEL_jutan2, 20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Rowf, -401, 0, 281)
    EVT_CALL(RotateGroup, MODEL_jutan2, 0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_Rhuff, 90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Think)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_WaveOff)
            EVT_WAIT(1)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
            EVT_WAIT(20)
        EVT_END_LOOP
        EVT_LOOP(3)
            EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_WaveOff)
            EVT_WAIT(1)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 1, 0)
            EVT_WAIT(2)
            EVT_CALL(TranslateModel, MODEL_omote2, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Idle)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Walk)
    EVT_CALL(NpcMoveTo, NPC_Rowf, -250, 295, 60)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Idle)
    EVT_WAIT(3)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_WaveOff)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Cheer)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Still)
    EVT_CALL(InterpNpcYaw, NPC_Rhuff, -90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Talk)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Still)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Think)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Talk)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Talk)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_jutan2, LVar0, 0, 0, 1)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(ShowEmote, NPC_Rhuff, EMOTE_SHOCK, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Still)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Rhuff_C) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -225, 0, 330)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_SET(LVar0, 0)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_LT(LVar1, 50)
            EVT_ADD(LVar0, 1)
        EVT_END_IF
        EVT_SWITCH(LVar3)
            EVT_CASE_RANGE(280, 380)
                EVT_ADD(LVar0, 1)
        EVT_END_SWITCH
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0013)
    EVT_THREAD
        EVT_CALL(func_802D1270, -280, 330, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Run)
    EVT_CALL(NpcMoveTo, NPC_SELF, -305, 330, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Idle)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0014)
    EVT_SET(GF_MAC01_Met_Rhuff, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateRhuffAnims) = {
    EVT_SET(LVar0, EVT_FLOAT(53.0))
    EVT_SET(LVar1, EVT_FLOAT(-192.0))
    EVT_SET(LVar2, EVT_FLOAT(-300.0))
    EVT_SET(LVar3, EVT_FLOAT(425.0))
    EVT_CALL(GetNpcPointer, NPC_Rhuff, LVar7)
    EVT_LOOP(0)
        EVT_CALL(N(RhuffUnravelUpdate))
        EVT_CALL(SetNpcPos, NPC_Rhuff, LVar4, 0, LVar5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_802555AC_815E2C)[] = {
    600,   0, 598,   0,
    595,   0, 590,   0,
    583,   0, 574,   0,
    562,   0, 547,   0,
    529,   0, 509,   0,
    489,   0, 469,   0,
    449,   0, 429,   0,
    409,   0, 389,   0,
    369,   0, 349,   0,
    329,   0, 309,   0,
    289,   0, 269,   0,
    249,   0, 229,   0,
    209,   0, 189,   0,
    169,   0, 149,   0,
    129,   0, 109,   0,
     89,   0,  69,   0,
     49,   0,  29,   0,
      9,   0, -11, -11,
    -16, -16, -18, -18,
    -19, -19, -19, -19,
    -19, -19, -19, -19,
    -15, -15,  -5,  -5,
      2,   2,   3,   3,
      1,   1,   0,   0,
      0,   0,   0,   0,
};

EvtScript N(EVS_Rhuff_RevealBadges) = {
    EVT_SET(MF_BadgeShopOpen, TRUE)
    EVT_CALL(SetNpcYaw, NPC_Rowf, 270)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_ROWF_OPEN_SHOP, SOUND_SPACE_DEFAULT, -220, 37, 271)
        EVT_CALL(MakeLerp, 0, -220, 30, EASING_COS_BOUNCE)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_omote, LVar0, 1, 0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(4)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -120, 10, EASING_COS_SLOW_OVERSHOOT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_omote2, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 100, 5, EASING_COS_SLOW_OVERSHOOT)
        EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_ura, 0, 0, LVar0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(EnableModel, MODEL_ju_1, TRUE)
    EVT_CALL(N(RevealRowfBadges))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o295, SOUND_ROWF_PULL_RUG_OUT, SOUND_SPACE_DEFAULT)
    EVT_USE_BUF(EVT_PTR(N(D_802555AC_815E2C)))
    EVT_LOOP(50)
        EVT_BUF_READ2(LVar0, MV_RowfRugRippleAmount)
        EVT_CALL(RotateGroup, MODEL_jutan2, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_SET(MV_RowfRugRotateAngle, LVar0)
        EVT_CALL(RotateGroup, MODEL_jutan1, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(200.0))
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(ScaleGroup, MODEL_jutan2, LVar0, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(NpcJump0, NPC_Rowf, -213, 6, 256, 16)
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Rhuff_HideBadges) = {
    EVT_SET(MF_BadgeShopOpen, FALSE)
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(NpcJump0, NPC_Rowf, -220, -54, 261, 16)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o295, SOUND_ROWF_PUSH_RUG_IN, SOUND_SPACE_DEFAULT)
        EVT_CALL(MakeLerp, 0, 600, 50, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_jutan2, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_SET(MV_RowfRugRotateAngle, LVar0)
        EVT_CALL(RotateGroup, MODEL_jutan1, LVar0, 0, 1, 0)
        EVT_DIVF(LVar0, EVT_FLOAT(200.0))
        EVT_ADDF(LVar0, EVT_FLOAT(1.0))
        EVT_CALL(ScaleGroup, MODEL_jutan2, LVar0, 1, LVar0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(EnableModel, MODEL_ju_1, FALSE)
        EVT_CALL(N(HideRowfBadges))
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(MakeLerp, -220, 0, 20, EASING_QUADRATIC_IN)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_omote, LVar0, 1, 0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_ROWF_CLOSE_SHOP, SOUND_SPACE_DEFAULT, -220, 37, 271)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(MakeLerp, -120, 0, 10, EASING_COS_IN_OUT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_omote2, 0, LVar0, 0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 0, 5, EASING_COS_IN_OUT)
        EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, MODEL_ura, 0, 0, LVar0)
        EVT_IF_EQ(LVar1, 1)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(31)
    EVT_RETURN
    EVT_END
};

enum BadgeShopStates {
    BADGE_SHOP_OPEN_READY         = 0,
    BADGE_SHOP_OPENING            = 1,
    BADGE_SHOP_OPEN               = 2,
    BADGE_SHOP_CLOSE_WAITING      = 1,
    BADGE_SHOP_CLOSING            = 2,
    BADGE_SHOP_CLOSE_READY        = 0,
};

EvtScript N(EVS_EnterBadgeShop) = {
    EVT_IF_GE(MV_BadgeShopOpenState, BADGE_SHOP_OPENING)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(MV_BadgeShopCloseState, BADGE_SHOP_CLOSE_WAITING)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MF_BadgeShopOpen, TRUE)
    EVT_SET(MV_BadgeShopOpenState, BADGE_SHOP_OPENING)
    EVT_EXEC_WAIT(N(EVS_Rhuff_RevealBadges))
    EVT_SET(MV_BadgeShopOpenState, BADGE_SHOP_OPEN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitBadgeShop) = {
    EVT_IF_EQ(MV_BadgeShopOpenState, BADGE_SHOP_OPEN_READY)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_BadgeShopCloseState, BADGE_SHOP_CLOSE_WAITING)
    EVT_SET(MF_BadgeShopOpen, FALSE)
    EVT_LABEL(10)
        EVT_IF_EQ(MV_BadgeShopOpenState, BADGE_SHOP_OPENING)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(MV_BadgeShopCloseState, BADGE_SHOP_CLOSING)
    EVT_EXEC_WAIT(N(EVS_Rhuff_HideBadges))
    EVT_SET(MV_BadgeShopOpenState, BADGE_SHOP_OPEN_READY)
    EVT_SET(MV_BadgeShopCloseState, BADGE_SHOP_CLOSE_READY)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(RowfShop_SetBadgePos)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    set_item_entity_position(
        gGameStatusPtr->shopItemEntities[idx].index,
        script->varTable[0], script->varTable[1], script->varTable[2] + 6
    );
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInit_Rowf) = {
    EVT_SET(MV_BadgeShopOpenState, 0)
    EVT_SET(MV_BadgeShopCloseState, 0)
    EVT_SET(AF_MAC_40, FALSE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_JR_TROOPA)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rowf_A)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Rowf)))
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rowf_B)))
            EVT_SET(AF_MAC_40, TRUE)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rowf_B)))
                EVT_SET(AF_MAC_40, TRUE)
            EVT_ELSE
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rowf_C)))
                EVT_CALL(SetNpcPos, NPC_Rowf, -250, 0, 295)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(AF_MAC_41, FALSE)
    EVT_CALL(SetModelFlags, MODEL_ju_2, MODEL_FLAG_DO_BOUNDS_CULLING, FALSE)
    EVT_CALL(EnableGroup, MODEL_jutan1, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(RotateGroup, MODEL_jutan1, 60, 0, 1, 0)
    EVT_CALL(RotateGroup, MODEL_jutan2, 0, 0, 1, 0)
    EVT_CALL(ScaleGroup, MODEL_jutan2, EVT_FLOAT(1.3), 1, EVT_FLOAT(1.3))
    EVT_SET(MV_RowfRugRotateAngle, 60)
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_0, MODEL_ju_1, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(gfx_build_rowf_rug_with_ripples)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_ju_1, CUSTOM_GFX_0, -1)
    EVT_IF_EQ(AF_MAC_40, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_EnterBadgeShop)), TRIGGER_FLOOR_TOUCH, COLLIDER_roten, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitBadgeShop)), TRIGGER_FLOOR_TOUCH, COLLIDER_o444, 1, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Rowf, 1)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetModelFlags, MODEL_b1, MODEL_FLAG_INACTIVE, FALSE)
        EVT_CALL(SetModelFlags, MODEL_b2, MODEL_FLAG_INACTIVE, FALSE)
        EVT_CALL(SetModelFlags, MODEL_b3, MODEL_FLAG_INACTIVE, FALSE)
        EVT_CALL(N(HideRowfBadges))
        EVT_LABEL(0)
        EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableA, FALSE)
            EVT_CALL(GetModelCenter, MODEL_b3)
            EVT_CALL(N(RowfShop_SetBadgePos), 0)
        EVT_END_IF
        EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableB, FALSE)
            EVT_CALL(GetModelCenter, MODEL_b2)
            EVT_CALL(N(RowfShop_SetBadgePos), 1)
        EVT_END_IF
        EVT_IF_EQ(GF_MAC01_RowfBadgeAvailableC, FALSE)
            EVT_CALL(GetModelCenter, MODEL_b1)
            EVT_CALL(N(RowfShop_SetBadgePos), 2)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Rhuff) = {
    EVT_CALL(SetNpcScale, NPC_Rhuff, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(0.75))
    EVT_CALL(SetNpcPos, NPC_Rhuff, -230, 0, 320)
    EVT_CALL(InterpNpcYaw, NPC_Rhuff, -90, 0)
    EVT_CALL(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_JR_TROOPA)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RhuffChapter1)))
        EVT_CASE_LT(STORY_CH2_BEGAN_PEACH_MISSION)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rhuff_B)))
            EVT_IF_EQ(GF_MAC01_Met_Rhuff, FALSE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Rhuff_C)))
            EVT_ELSE
                EVT_CALL(SetNpcPos, NPC_SELF, -305, 0, 330)
                EVT_CALL(SetNpcYaw, NPC_SELF, 90)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rhuff_C)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_UpdateRhuffAnims)))
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_MAC01_CalculatorReturned, TRUE)
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rhuff_C)))
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_UpdateRhuffAnims)))
            EVT_ELSE
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Rhuff_D)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Rowf)[] = {
    ANIM_Rowf_Still,
    ANIM_Rowf_Idle,
    ANIM_Rowf_Walk,
    ANIM_Rowf_Talk,
    ANIM_Rowf_Cheer,
    ANIM_Rowf_Think,
    ANIM_Rowf_WaveOff,
    ANIM_LIST_END
};

NpcSettings N(NpcSettings_Rowf) = {
    .height = 36,
    .radius = 24,
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcSettings N(NpcSettings_Rhuff) = {
    .height = 27,
    .radius = 18,
    .flags = ENEMY_FLAG_PASSIVE,
};

NpcData N(NpcData_RowfAndRhuff)[] = {
    {
        .id = NPC_Rowf,
        .pos = { -213.0f, -54.0f, 256.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Rowf),
        .settings = &N(NpcSettings_Rowf),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(ExtraAnims_Rowf),
        .tattle = MSG_NpcTattle_Rowf,
    },
    {
        .id = NPC_Rhuff,
        .pos = { -250.0f, 0.0f, 263.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Rhuff),
        .settings = &N(NpcSettings_Rhuff),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Rowf_Idle,
        },
        .extraAnimations = N(ExtraAnims_Rowf),
        .tattle = MSG_NpcTattle_Rhuff,
    },
};
