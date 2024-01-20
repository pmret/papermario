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
    IfEq(GF_MAC01_Met_Rowf_Early, FALSE)
        Set(GF_MAC01_Met_Rowf_Early, TRUE)
        Set(AF_MAC_41, TRUE)
        Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0000)
    Else
        IfEq(AF_MAC_41, TRUE)
            Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0001)
        Else
            Set(AF_MAC_41, TRUE)
            Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Think, 0, MSG_MAC_Plaza_0002)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rowf_B) = {
    Set(LVar0, GF_MAC01_RowfBadgeAvailableA)
    Add(LVar0, GF_MAC01_RowfBadgeAvailableB)
    Add(LVar0, GF_MAC01_RowfBadgeAvailableC)
    IfEq(LVar0, 3)
        IfLt(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
            Set(LVar1, MSG_MAC_Plaza_0005)
        Else
            Call(N(func_80244984_805204))
            IfEq(LVar0, 0)
                Set(LVar1, MSG_MAC_Plaza_0006)
            Else
                Set(LVar1, MSG_MAC_Plaza_0005)
            EndIf
        EndIf
        Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, LVar1)
        Return
    EndIf
    IfEq(GF_MAC01_Met_Rowf_Late, FALSE)
        Set(GF_MAC01_Met_Rowf_Late, TRUE)
        Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0003)
    Else
        Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0004)
    EndIf
    Return
    End
};

s32 N(ItemList_Calculator)[] = {
    ITEM_CALCULATOR,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_Rowf_C) = {
    IfEq(GF_MAC01_CalculatorReturned, TRUE)
        Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_000A)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0008)
    Set(LVar0, Ref(N(ItemList_Calculator)))
    Set(LVar1, 1)
    ExecWait(N(EVS_ChooseKeyItem))
    Switch(LVar0)
        CaseEq(0)
        CaseEq(-1)
            Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_000B)
        CaseDefault
            Call(SpeakToPlayer, NPC_Rowf, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0009)
            Wait(10)
            Set(LVar0, ITEM_I_SPY)
            Set(LVar3, 2)
            ExecWait(N(GiveItemReward))
            Call(AddBadge, LVar0, LVar1)
            Set(GF_MAC01_CalculatorReturned, TRUE)
            Wait(10)
            Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0011)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_RhuffChapter1) = {
    Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000C)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rhuff_B) = {
    Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0014)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rhuff_C) = {
    Call(N(func_80244984_805204))
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000F)
    Else
        Set(LVar0, GF_MAC01_RowfBadgeAvailableA)
        Add(LVar0, GF_MAC01_RowfBadgeAvailableB)
        Add(LVar0, GF_MAC01_RowfBadgeAvailableC)
        IfEq(LVar0, 3)
            Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000E)
        Else
            Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_000D)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Rhuff_D) = {
    IfEq(GF_MAC01_CalculatorReturned, TRUE)
        Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0012)
    Else
        Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Idle, 0, MSG_MAC_Plaza_0010)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_Rowf) = {
    Call(SetNpcPos, NPC_Rowf, -250, 0, 295)
    Label(0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    Call(NpcMoveTo, NPC_Rowf, -260, 281, 4)
    Wait(5)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Walk)
    Call(NpcMoveTo, NPC_Rowf, -410, 281, 60)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Idle)
    Call(RotateGroup, MODEL_jutan2, 60, 0, 0, 1)
    Wait(1)
    Call(SetNpcPos, NPC_Rowf, -407, 0, 281)
    Call(RotateGroup, MODEL_jutan2, 40, 0, 0, 1)
    Wait(1)
    Call(SetNpcPos, NPC_Rowf, -404, 0, 281)
    Call(RotateGroup, MODEL_jutan2, 20, 0, 0, 1)
    Wait(1)
    Call(SetNpcPos, NPC_Rowf, -401, 0, 281)
    Call(RotateGroup, MODEL_jutan2, 0, 0, 0, 1)
    Wait(1)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    Wait(5)
    Call(InterpNpcYaw, NPC_Rhuff, 90, 0)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Think)
    Wait(30)
    Thread
        Loop(2)
            Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_WaveOff)
            Wait(1)
            Call(TranslateModel, MODEL_omote2, 0, 1, 0)
            Wait(2)
            Call(TranslateModel, MODEL_omote2, 0, 0, 0)
            Wait(2)
            Call(TranslateModel, MODEL_omote2, 0, 1, 0)
            Wait(2)
            Call(TranslateModel, MODEL_omote2, 0, 0, 0)
            Wait(2)
            Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
            Wait(20)
        EndLoop
        Loop(3)
            Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_WaveOff)
            Wait(1)
            Call(TranslateModel, MODEL_omote2, 0, 1, 0)
            Wait(2)
            Call(TranslateModel, MODEL_omote2, 0, 0, 0)
            Wait(2)
            Call(TranslateModel, MODEL_omote2, 0, 1, 0)
            Wait(2)
            Call(TranslateModel, MODEL_omote2, 0, 0, 0)
            Wait(2)
            Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
            Wait(2)
        EndLoop
    EndThread
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    Wait(5)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Idle)
    Wait(20)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Walk)
    Call(NpcMoveTo, NPC_Rowf, -250, 295, 60)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Idle)
    Wait(3)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_WaveOff)
    Wait(15)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Cheer)
    Wait(8)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Still)
    Call(InterpNpcYaw, NPC_Rhuff, -90, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Talk)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Still)
    Wait(30)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Think)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Talk)
    Wait(30)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Talk)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
    Wait(20)
    Thread
        Call(MakeLerp, 0, 90, 40, EASING_CUBIC_IN)
        Label(10)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_jutan2, LVar0, 0, 0, 1)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(10)
        EndIf
    EndThread
    Wait(15)
    Call(ShowEmote, NPC_Rhuff, EMOTE_SHOCK, -45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Still)
    Wait(10)
    Call(SetNpcAnimation, NPC_Rowf, ANIM_Rowf_Still)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Rhuff_C) = {
    Call(SetNpcPos, NPC_SELF, -225, 0, 330)
    Loop(0)
        Wait(1)
        Set(LVar0, 0)
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        IfLt(LVar1, 50)
            Add(LVar0, 1)
        EndIf
        Switch(LVar3)
            CaseRange(280, 380)
                Add(LVar0, 1)
        EndSwitch
        IfEq(LVar0, 2)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -25)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Run)
    Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Idle)
    Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0013)
    Thread
        Call(func_802D1270, -280, 330, Float(4.0))
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(4.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Run)
    Call(NpcMoveTo, NPC_SELF, -305, 330, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Rowf_Idle)
    Wait(10)
    Call(SpeakToPlayer, NPC_Rhuff, ANIM_Rowf_Talk, ANIM_Rowf_Cheer, 0, MSG_MAC_Plaza_0014)
    Set(GF_MAC01_Met_Rhuff, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UpdateRhuffAnims) = {
    Set(LVar0, Float(53.0))
    Set(LVar1, Float(-192.0))
    Set(LVar2, Float(-300.0))
    Set(LVar3, Float(425.0))
    Call(GetNpcPointer, NPC_Rhuff, LVar7)
    Loop(0)
        Call(N(RhuffUnravelUpdate))
        Call(SetNpcPos, NPC_Rhuff, LVar4, 0, LVar5)
        Wait(1)
    EndLoop
    Return
    End
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
    Set(MF_BadgeShopOpen, TRUE)
    Call(SetNpcYaw, NPC_Rowf, 270)
    Thread
        Call(PlaySoundAt, SOUND_ROWF_OPEN_SHOP, SOUND_SPACE_DEFAULT, -220, 37, 271)
        Call(MakeLerp, 0, -220, 30, EASING_COS_BOUNCE)
        Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_omote, LVar0, 1, 0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(0)
        EndIf
    EndThread
    Wait(4)
    Thread
        Call(MakeLerp, 0, -120, 10, EASING_COS_SLOW_OVERSHOOT)
        Label(1)
        Call(UpdateLerp)
        DivF(LVar0, Float(10.0))
        Call(TranslateModel, MODEL_omote2, 0, LVar0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    EndThread
    Thread
        Call(MakeLerp, 0, 100, 5, EASING_COS_SLOW_OVERSHOOT)
        Label(2)
        Call(UpdateLerp)
        DivF(LVar0, Float(10.0))
        Call(TranslateModel, MODEL_ura, 0, 0, LVar0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(2)
        EndIf
    EndThread
    Call(EnableModel, MODEL_ju_1, TRUE)
    Call(N(RevealRowfBadges))
    Call(PlaySoundAtCollider, COLLIDER_o295, SOUND_ROWF_PULL_RUG_OUT, SOUND_SPACE_DEFAULT)
    UseBuf(Ref(N(D_802555AC_815E2C)))
    Loop(50)
        BufRead2(LVar0, MV_RowfRugRippleAmount)
        Call(RotateGroup, MODEL_jutan2, LVar0, 0, 1, 0)
        DivF(LVar0, Float(10.0))
        Set(MV_RowfRugRotateAngle, LVar0)
        Call(RotateGroup, MODEL_jutan1, LVar0, 0, 1, 0)
        DivF(LVar0, Float(200.0))
        AddF(LVar0, Float(1.0))
        Call(ScaleGroup, MODEL_jutan2, LVar0, 1, LVar0)
        Wait(1)
    EndLoop
    Call(NpcJump0, NPC_Rowf, -213, 6, 256, 16)
    IfEq(GF_MAC01_RowfBadgeAvailableA, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_MAC01_RowfBadgeAvailableB, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_MAC01_RowfBadgeAvailableC, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};

EvtScript N(EVS_Rhuff_HideBadges) = {
    Set(MF_BadgeShopOpen, FALSE)
    IfEq(GF_MAC01_RowfBadgeAvailableA, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_MAC01_RowfBadgeAvailableB, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_MAC01_RowfBadgeAvailableC, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(NpcJump0, NPC_Rowf, -220, -54, 261, 16)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_o295, SOUND_ROWF_PUSH_RUG_IN, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, 600, 50, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_jutan2, LVar0, 0, 1, 0)
        DivF(LVar0, Float(10.0))
        Set(MV_RowfRugRotateAngle, LVar0)
        Call(RotateGroup, MODEL_jutan1, LVar0, 0, 1, 0)
        DivF(LVar0, Float(200.0))
        AddF(LVar0, Float(1.0))
        Call(ScaleGroup, MODEL_jutan2, LVar0, 1, LVar0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(10)
        EndIf
        Call(EnableModel, MODEL_ju_1, FALSE)
        Call(N(HideRowfBadges))
    EndThread
    Wait(10)
    Thread
        Call(MakeLerp, -220, 0, 20, EASING_QUADRATIC_IN)
        Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_omote, LVar0, 1, 0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(0)
        EndIf
        Call(PlaySoundAt, SOUND_ROWF_CLOSE_SHOP, SOUND_SPACE_DEFAULT, -220, 37, 271)
    EndThread
    Wait(15)
    Thread
        Call(MakeLerp, -120, 0, 10, EASING_COS_IN_OUT)
        Label(1)
        Call(UpdateLerp)
        DivF(LVar0, Float(10.0))
        Call(TranslateModel, MODEL_omote2, 0, LVar0, 0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(1)
        EndIf
    EndThread
    Thread
        Call(MakeLerp, 100, 0, 5, EASING_COS_IN_OUT)
        Label(2)
        Call(UpdateLerp)
        DivF(LVar0, Float(10.0))
        Call(TranslateModel, MODEL_ura, 0, 0, LVar0)
        IfEq(LVar1, 1)
            Wait(1)
            Goto(2)
        EndIf
    EndThread
    Wait(31)
    Return
    End
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
    IfGe(MV_BadgeShopOpenState, BADGE_SHOP_OPENING)
        Return
    EndIf
    IfGe(MV_BadgeShopCloseState, BADGE_SHOP_CLOSE_WAITING)
        Return
    EndIf
    Set(MF_BadgeShopOpen, TRUE)
    Set(MV_BadgeShopOpenState, BADGE_SHOP_OPENING)
    ExecWait(N(EVS_Rhuff_RevealBadges))
    Set(MV_BadgeShopOpenState, BADGE_SHOP_OPEN)
    Return
    End
};

EvtScript N(EVS_ExitBadgeShop) = {
    IfEq(MV_BadgeShopOpenState, BADGE_SHOP_OPEN_READY)
        Return
    EndIf
    Set(MV_BadgeShopCloseState, BADGE_SHOP_CLOSE_WAITING)
    Set(MF_BadgeShopOpen, FALSE)
    Label(10)
        IfEq(MV_BadgeShopOpenState, BADGE_SHOP_OPENING)
            Wait(1)
            Goto(10)
        EndIf
    Set(MV_BadgeShopCloseState, BADGE_SHOP_CLOSING)
    ExecWait(N(EVS_Rhuff_HideBadges))
    Set(MV_BadgeShopOpenState, BADGE_SHOP_OPEN_READY)
    Set(MV_BadgeShopCloseState, BADGE_SHOP_CLOSE_READY)
    Return
    End
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
    Set(MV_BadgeShopOpenState, 0)
    Set(MV_BadgeShopCloseState, 0)
    Set(AF_MAC_40, FALSE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_DEFEATED_JR_TROOPA)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rowf_A)))
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Rowf)))
        CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rowf_B)))
            Set(AF_MAC_40, TRUE)
        CaseDefault
            IfEq(GF_MAC01_CalculatorReturned, TRUE)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rowf_B)))
                Set(AF_MAC_40, TRUE)
            Else
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rowf_C)))
                Call(SetNpcPos, NPC_Rowf, -250, 0, 295)
            EndIf
    EndSwitch
    Set(AF_MAC_41, FALSE)
    Call(SetModelFlags, MODEL_ju_2, MODEL_FLAG_DO_BOUNDS_CULLING, FALSE)
    Call(EnableGroup, MODEL_jutan1, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_b3, COLLIDER_FLAGS_UPPER_MASK)
    Call(RotateGroup, MODEL_jutan1, 60, 0, 1, 0)
    Call(RotateGroup, MODEL_jutan2, 0, 0, 1, 0)
    Call(ScaleGroup, MODEL_jutan2, Float(1.3), 1, Float(1.3))
    Set(MV_RowfRugRotateAngle, 60)
    Call(MakeLocalVertexCopy, VTX_COPY_0, MODEL_ju_1, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(gfx_build_rowf_rug_with_ripples)), NULL)
    Call(SetModelCustomGfx, MODEL_ju_1, CUSTOM_GFX_0, -1)
    IfEq(AF_MAC_40, TRUE)
        BindTrigger(Ref(N(EVS_EnterBadgeShop)), TRIGGER_FLOOR_TOUCH, COLLIDER_roten, 1, 0)
        BindTrigger(Ref(N(EVS_ExitBadgeShop)), TRIGGER_FLOOR_TOUCH, COLLIDER_o444, 1, 0)
        Call(SetNpcJumpscale, NPC_Rowf, 1)
    EndIf
    Thread
        Wait(5)
        Call(SetModelFlags, MODEL_b1, MODEL_FLAG_INACTIVE, FALSE)
        Call(SetModelFlags, MODEL_b2, MODEL_FLAG_INACTIVE, FALSE)
        Call(SetModelFlags, MODEL_b3, MODEL_FLAG_INACTIVE, FALSE)
        Call(N(HideRowfBadges))
        Label(0)
        IfEq(GF_MAC01_RowfBadgeAvailableA, FALSE)
            Call(GetModelCenter, MODEL_b3)
            Call(N(RowfShop_SetBadgePos), 0)
        EndIf
        IfEq(GF_MAC01_RowfBadgeAvailableB, FALSE)
            Call(GetModelCenter, MODEL_b2)
            Call(N(RowfShop_SetBadgePos), 1)
        EndIf
        IfEq(GF_MAC01_RowfBadgeAvailableC, FALSE)
            Call(GetModelCenter, MODEL_b1)
            Call(N(RowfShop_SetBadgePos), 2)
        EndIf
        Wait(1)
        Goto(0)
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcInit_Rhuff) = {
    Call(SetNpcScale, NPC_Rhuff, Float(0.75), Float(0.75), Float(0.75))
    Call(SetNpcPos, NPC_Rhuff, -230, 0, 320)
    Call(InterpNpcYaw, NPC_Rhuff, -90, 0)
    Call(SetNpcAnimation, NPC_Rhuff, ANIM_Rowf_Idle)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_DEFEATED_JR_TROOPA)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RhuffChapter1)))
        CaseLt(STORY_CH2_BEGAN_PEACH_MISSION)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rhuff_B)))
            IfEq(GF_MAC01_Met_Rhuff, FALSE)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Rhuff_C)))
            Else
                Call(SetNpcPos, NPC_SELF, -305, 0, 330)
                Call(SetNpcYaw, NPC_SELF, 90)
            EndIf
        CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rhuff_C)))
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_UpdateRhuffAnims)))
        CaseDefault
            IfEq(GF_MAC01_CalculatorReturned, TRUE)
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rhuff_C)))
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_UpdateRhuffAnims)))
            Else
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Rhuff_D)))
            EndIf
    EndSwitch
    Return
    End
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
