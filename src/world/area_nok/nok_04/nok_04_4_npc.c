
#include "nok_04.h"
#include "effects.h"

typedef struct Unk80241440_2 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
} Unk80241440_2; //size = 0x44

typedef struct Unk80241440 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ Unk80241440_2* unk_40;
    /* 0x44 */ Unk80241440_2* unk_44;
} Unk80241440; //size = 0x48

/*
trees in this room are labeled with a 0 through 5 system, meaning there are "6" tree values
(tree indexes from left to right in both rows, each tree has 2 unique numbers besides 0)
0, 1, 2, 3
0, 5, 4, 3
*/

#include "world/common/util/ChangeNpcToPartner.inc.c"

NpcSettings N(NpcSettings_Fuzzy_02) = {
    .height = 20,
    .radius = 22,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Kooper_01) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

EvtScript N(D_80241328_9EEF18) = {
    EVT_CALL(GetNpcYaw, LVar4, LVar1)
    EVT_SET(LVar2, 30)
    EVT_IF_GT(LVar1, 151)
        EVT_IF_LE(LVar1, 331)
            EVT_SET(LVar2, -30)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, LVar2)
        EVT_CALL(SetNpcRotation, LVar3, 0, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Unk80241440 N(D_802413F8_9EEFE8) = {};

s32 N(D_80241440_9EF030)[] = {
    -82, 101, 130, 38,
    164, 130, 158, 135, 
    157, 281, 156, 202, 
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(D_80241470_9EF060) = {
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, LVar1)
    EVT_SET(LVar4, 600)
    EVT_DIV(LVar4, 100)
    EVT_ADD(LVar4, 27)
    EVT_CALL(RandInt, 1, LVar5)
    EVT_MUL(LVar5, 20)
    EVT_SUB(LVar5, 10)
    EVT_SET(LVar6, 0)
    EVT_SETF(LVar8, EVT_FLOAT(5.0))
    EVT_CALL(MakeLerp, LVar5, 0, LVar4, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_MULF(LVar0, EVT_FLOAT(0.40625))
    EVT_ADD(LVar6, 1)
    EVT_SETF(LVar9, LVar8)
    EVT_MULF(LVar9, EVT_FLOAT(-1.0))
    EVT_CALL(N(CosInterpMinMax), LVar6, LVar7, LVar9, LVar8, 3, 0, 0)
    EVT_MULF(LVar8, EVT_FLOAT(0.90625))
    EVT_CALL(TranslateModel, LVar2, LVar7, LVar0, 0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024161C_9EF20C) = {
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, LVar1)
    EVT_SET(LVar4, 600)
    EVT_DIV(LVar4, 100)
    EVT_ADD(LVar4, 27)
    EVT_SET(LVar0, 5)
    EVT_LOOP(LVar0)
        EVT_CALL(TranslateModel, LVar2, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_SET(LVar1, LVar0)
        EVT_MUL(LVar1, -1)
        EVT_CALL(TranslateModel, LVar2, LVar1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241710_9EF300) = {
    EVT_CALL(InterpCamTargetPos, 0, 1, LVarA, LVarB, LVarC, LVarD)
    EVT_RETURN
    EVT_END
};

 // split?

 static s32 N(pad_1744)[] = {
    0x00000000, 
};


s32 N(D_80241748_9EF338)[] = {
    0xFFFE0000, 0, 0, -1,
    0x00010000, 0, 0x02000000, -1 
};

s32 N(D_80241768_9EF358)[] = {
    0xD7000000, -1,
    0xE7000000, 0,
    0xE3000A01, 0,
    0xFCFFFFFF, 0xFFFE793C ,
    0xE3001201, 0,
    0xE200001C, 0x00552078,
    0xD9C0F9FB, 0,
    0xD9FFFFFF, 0x00200005 ,
    0xDF000000, 0 ,
};

API_CALLABLE(N(func_80240314_9EDF04)) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    f32 temp_f6 = evt_get_variable(script, *args++);

    N(D_802413F8_9EEFE8).unk_00.x = temp_s2;
    N(D_802413F8_9EEFE8).unk_00.y = temp_s0_3 + 4.0f;
    N(D_802413F8_9EEFE8).unk_00.z = temp_f6;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802403C0_9EDFB0)) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s2 = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    s32 temp_a0 = evt_get_variable(script, *args++);
    s32 phi_s0 = temp_s0_3;
    Unk80241440* d802413F8 = &N(D_802413F8_9EEFE8); //needed to match
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;
    f32 temp_f10;

    if (temp_s0_3 < 0) {
        phi_s0 = temp_s0_3 + 15;
    }

    temp_f8 = phi_s0 >> 4;
    N(D_802413F8_9EEFE8).unk_34 = 0.0f;
    temp_f6 = temp_s2 * 0.0625f;
    temp_f10 = N(D_802413F8_9EEFE8).unk_34;
    temp_f4 = temp_a0;
    N(D_802413F8_9EEFE8).unk_18 = temp_f8;
    N(D_802413F8_9EEFE8).unk_30 = temp_f4;
    N(D_802413F8_9EEFE8).unk_0C = temp_f6;

    if (temp_f10 < temp_f4) {
        N(D_802413F8_9EEFE8).unk_38 = (temp_f6 - N(D_802413F8_9EEFE8).unk_10) / temp_f4;
        N(D_802413F8_9EEFE8).unk_3C = (temp_f8 - N(D_802413F8_9EEFE8).unk_20) / temp_f4;
    }

    if (temp_f4 < temp_f10) {
        N(D_802413F8_9EEFE8).unk_10 = temp_f6;
        N(D_802413F8_9EEFE8).unk_20 = temp_f8;
        N(D_802413F8_9EEFE8).unk_30 = temp_f10;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802404D0_9EE0C0)) {
    N(D_802413F8_9EEFE8).unk_00.x = 0;
    N(D_802413F8_9EEFE8).unk_00.y = 0;
    N(D_802413F8_9EEFE8).unk_00.z = 0;
    N(D_802413F8_9EEFE8).unk_10 = 0;
    N(D_802413F8_9EEFE8).unk_0C = 0;
    N(D_802413F8_9EEFE8).unk_14 = 0;
    N(D_802413F8_9EEFE8).unk_18 = 0;
    N(D_802413F8_9EEFE8).unk_20 = 0;
    N(D_802413F8_9EEFE8).unk_1C = 0;
    N(D_802413F8_9EEFE8).unk_40 = NULL;
    N(D_802413F8_9EEFE8).unk_44 = NULL;
    N(D_802413F8_9EEFE8).unk_34 = 0;
    N(D_802413F8_9EEFE8).unk_30 = 0;
    N(D_802413F8_9EEFE8).unk_38 = 0;
    N(D_802413F8_9EEFE8).unk_3C = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024051C_9EE10C)) {
    Bytecode* args = script->ptrReadPos;
    N(D_802413F8_9EEFE8).unk_40 = (Unk80241440_2*) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240548_9EE138)) {
    Bytecode* args = script->ptrReadPos;
    N(D_802413F8_9EEFE8).unk_44 = (Unk80241440_2*) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240574_9EE164)) {
    Bytecode *args = script->ptrReadPos;
    s32 mapVar1 = evt_get_variable(script, *args++) * 3;
    s32 var1 = *args++;
    s32 var2 = *args++;
    s32 var3 = *args++;

    evt_set_variable(script, var1, N(D_80241440_9EF030)[mapVar1]);
    evt_set_variable(script, var2, N(D_80241440_9EF030)[mapVar1 + 1]);
    evt_set_variable(script, var3, N(D_80241440_9EF030)[mapVar1 + 2]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240630_9EE220)) {
    Bytecode* args = script->ptrReadPos;
    s32 evtVar = evt_get_variable(script, *args++);
    Bytecode outVar = *args++;
    evtVar %= 6;

    if (evtVar < 4) {
        evt_set_variable(script, outVar, evtVar);
    } else {
        evt_set_variable(script, outVar, 6 - evtVar);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802406C4_9EE2B4)) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s1_2 = evt_get_variable(script, *args++);
    s32 temp_s2 = evt_get_variable(script, *args++);
    Evt* script2;
    EvtScript* phi_a0;

    temp_s1_2 %= 6;

    if (temp_s1_2 >= 4) {
        temp_s1_2 = 6 - temp_s1_2;
    }

    if (does_script_exist(script->varTable[temp_s1_2 + 6])) {
        kill_script_by_ID(script->varTable[temp_s1_2 + 6]);
    }

    phi_a0 = &N(D_80241470_9EF060);

    switch (temp_s2) {
        case 0:
            phi_a0 = &N(D_80241470_9EF060);
            break;
        case 1:
            phi_a0 = &N(D_8024161C_9EF20C);
            break;
    }

    script2 = start_script(phi_a0, EVT_PRIORITY_1, 0);
    script->varTable[temp_s1_2 + 6] = script2->id;

    switch (temp_s1_2) {
        case 0:
            script2->varTable[0] = 0x4C;
            break;
        case 1:
            script2->varTable[0] = 0x4D;
            break;
        case 2:
            script2->varTable[0] = 0x4E;
            break;
        case 3:
            script2->varTable[0] = 0x4F;
            break;
    }

    return ApiStatus_DONE2;
}

void N(func_80240814_9EE404)(s32 index) {
    f32 x = N(D_802413F8_9EEFE8).unk_00.x;
    f32 y = N(D_802413F8_9EEFE8).unk_00.y;
    f32 z = N(D_802413F8_9EEFE8).unk_00.z;
    s32 i;
    f32 angle, deltaY, fs3;

    N(D_802413F8_9EEFE8).unk_14 += 0.2;
    if (N(D_802413F8_9EEFE8).unk_30 != 0.0f) {
        N(D_802413F8_9EEFE8).unk_10 += N(D_802413F8_9EEFE8).unk_38;
        if (N(D_802413F8_9EEFE8).unk_0C < N(D_802413F8_9EEFE8).unk_10) {
            N(D_802413F8_9EEFE8).unk_14 += (N(D_802413F8_9EEFE8).unk_0C - N(D_802413F8_9EEFE8).unk_10) * 0.5f;
        }
        N(D_802413F8_9EEFE8).unk_34 += 1.0f;
        N(D_802413F8_9EEFE8).unk_1C = (N(D_802413F8_9EEFE8).unk_1C + (N(D_802413F8_9EEFE8).unk_18 - N(D_802413F8_9EEFE8).unk_20) / 10.0f) * 0.92;
        N(D_802413F8_9EEFE8).unk_20 += N(D_802413F8_9EEFE8).unk_3C;
        if (N(D_802413F8_9EEFE8).unk_30 <= N(D_802413F8_9EEFE8).unk_34) {
            N(D_802413F8_9EEFE8).unk_30 = 0.0f;
        }
    } else {
        N(D_802413F8_9EEFE8).unk_10 += N(D_802413F8_9EEFE8).unk_14;
        if (N(D_802413F8_9EEFE8).unk_0C < N(D_802413F8_9EEFE8).unk_10) {
            N(D_802413F8_9EEFE8).unk_14 += (N(D_802413F8_9EEFE8).unk_0C - N(D_802413F8_9EEFE8).unk_10) * 0.5f;
        }
        N(D_802413F8_9EEFE8).unk_1C = (N(D_802413F8_9EEFE8).unk_1C + (N(D_802413F8_9EEFE8).unk_18 - N(D_802413F8_9EEFE8).unk_20) / 10.0f) * 0.92;
        N(D_802413F8_9EEFE8).unk_20 += N(D_802413F8_9EEFE8).unk_1C;
    }
    N(D_802413F8_9EEFE8).unk_14 *= 0.5;

    gSPDisplayList(gMasterGfxPos++, N(D_80241768_9EF358));
    guTranslate(&gDisplayContext->matrixStack[gMatrixListPos], N(D_802413F8_9EEFE8).unk_00.x, N(D_802413F8_9EEFE8).unk_00.y, N(D_802413F8_9EEFE8).unk_00.z);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    angle = N(D_802413F8_9EEFE8).unk_20;
    deltaY = -N(D_802413F8_9EEFE8).unk_10;
    x += -deltaY * sin_rad(N(D_802413F8_9EEFE8).unk_20 * 0 / 180.0f * PI);
    y += deltaY * cos_rad(N(D_802413F8_9EEFE8).unk_20 * 0 / 180.0f * PI);

    guPosition(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, 0.0f, angle, 1.0f, 0.0f, deltaY, 0.0f);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    for (i = 1; i < 16; i++) {
        angle = N(D_802413F8_9EEFE8).unk_20;
        deltaY = -N(D_802413F8_9EEFE8).unk_10;
        x += -deltaY * sin_rad(N(D_802413F8_9EEFE8).unk_20 * i / 180.0f * PI);
        y += deltaY * cos_rad(N(D_802413F8_9EEFE8).unk_20 * i / 180.0f * PI);
        gSPVertex(gMasterGfxPos++, N(D_80241748_9EF338), 2, 0);
        guPosition(&gDisplayContext->matrixStack[gMatrixListPos], 0.0f, 0.0f, angle, 1.0f, 0.0f, deltaY, 0.0f);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPVertex(gMasterGfxPos++, N(D_80241748_9EF338), 2, 2);
        gSP2Triangles(gMasterGfxPos++, 0, 2, 1, 0, 2, 3, 1, 0);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    gDPPipeSync(gMasterGfxPos++);

    N(D_802413F8_9EEFE8).unk_24 = x;
    N(D_802413F8_9EEFE8).unk_28 = y;
    N(D_802413F8_9EEFE8).unk_2C = z;

    if (N(D_802413F8_9EEFE8).unk_40 != NULL) {
        N(D_802413F8_9EEFE8).unk_40->unk_38 = x;
        N(D_802413F8_9EEFE8).unk_40->unk_3C = y - 4.0f;
        N(D_802413F8_9EEFE8).unk_40->unk_40 = z + 6.0f;
    }

    if (N(D_802413F8_9EEFE8).unk_44 != NULL) {
        N(D_802413F8_9EEFE8).unk_44->unk_38 = x;
        N(D_802413F8_9EEFE8).unk_44->unk_3C = y - 4.0f;
        N(D_802413F8_9EEFE8).unk_44->unk_40 = z + 3.0f;
    }
}

EvtScript N(D_802417B0_9EF3A0) = {
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, LVarD)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802417F8_9EF3E8) = {
    EVT_CALL(PlayerFaceNpc, NPC_Fuzzy_01, FALSE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00BE, 160, 40)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -597)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 10, -11)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 707)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 90, 0, 228)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(60)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002A)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Kooper_01, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_03, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_04, 3)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_05, 3)
    EVT_SWITCH(MV_Unk_00)
        EVT_CASE_EQ(0)
            EVT_SET(LVarE, 10)
        EVT_CASE_EQ(1)
            EVT_SET(LVarE, 9)
        EVT_CASE_EQ(2)
            EVT_SET(LVarE, 8)
    EVT_END_SWITCH
    EVT_CALL(RandInt, 3, LVar0)
    EVT_ADD(LVarE, LVar0)
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 0)
    EVT_SET(LVarF, MV_Unk_01)
    EVT_LOOP(LVarE)
        EVT_SET(LVarA, MV_Unk_01)
        EVT_CALL(N(func_80240630_9EE220), LVarF, MV_Unk_01)
        EVT_SWITCH(LVarF)
            EVT_CASE_EQ(0)
                EVT_SET(LVarB, 2)
                EVT_SET(LVarC, 3)
            EVT_CASE_EQ(1)
                EVT_IF_EQ(LVarA, 2)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 3)
                EVT_ELSE
                    EVT_SET(LVarB, 2)
                    EVT_SET(LVarC, 3)
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 1)
                EVT_ELSE
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 3)
                EVT_END_IF
            EVT_CASE_EQ(3)
                EVT_SET(LVarB, 0)
                EVT_SET(LVarC, 1)
            EVT_CASE_EQ(4)
                EVT_IF_EQ(LVarA, 1)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 3)
                EVT_ELSE
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 1)
                EVT_END_IF
            EVT_CASE_EQ(5)
                EVT_IF_EQ(LVarA, 0)
                    EVT_SET(LVarB, 2)
                    EVT_SET(LVarC, 3)
                EVT_ELSE
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 3)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_CALL(RandInt, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_ADD(LVarF, -1)
        EVT_ELSE
            EVT_ADD(LVarF, 1)
        EVT_END_IF
        EVT_IF_GE(LVarF, 6)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_IF_LT(LVarF, 0)
            EVT_SET(LVarF, 5)
        EVT_END_IF
        EVT_SWITCH(MV_Unk_00)
            EVT_CASE_EQ(0)
                EVT_SET(LVarD, 15)
            EVT_CASE_EQ(1)
                EVT_SET(LVarD, 10)
            EVT_CASE_EQ(2)
                EVT_SET(LVarD, 6)
        EVT_END_SWITCH
        EVT_SET(LVar0, 0x002B0005)
        EVT_CALL(RandInt, 2, LVar1)
        EVT_ADD(LVar0, LVar1)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_03, LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_04, LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_05, LVar0)
        EVT_CALL(PlaySound, SOUND_B0000017)
        EVT_THREAD
            EVT_CALL(N(func_80240574_9EE164), MV_Unk_01, LVar0, LVar1, LVar2)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVar0, LVar1, LVar2, LVarD)
        EVT_END_THREAD
        EVT_IF_NE(MV_Unk_01, LVarA)
            EVT_THREAD
                EVT_CALL(N(func_80240574_9EE164), MV_Unk_01, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                EVT_CALL(N(func_80240574_9EE164), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
            EVT_SET(LocalFlag(0), FALSE)
            EVT_IF_EQ(LVarB, 0)
                EVT_IF_EQ(LVarC, 3)
                    EVT_SET(LocalFlag(0), TRUE)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(0), FALSE)
                EVT_THREAD
                    EVT_CALL(N(func_80240574_9EE164), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_04, LVar0, LVar1, LVar2)
                    EVT_CALL(N(func_80240574_9EE164), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_04, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(N(func_80240574_9EE164), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_05, LVar0, LVar1, LVar2)
                    EVT_CALL(N(func_80240574_9EE164), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_05, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
            EVT_ELSE
                EVT_THREAD
                    EVT_CALL(N(func_80240574_9EE164), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_04, LVar0, LVar1, LVar2)
                    EVT_CALL(N(func_80240574_9EE164), LVarB, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_04, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
                EVT_THREAD
                    EVT_CALL(N(func_80240574_9EE164), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_Fuzzy_05, LVar0, LVar1, LVar2)
                    EVT_CALL(N(func_80240574_9EE164), LVarC, LVar0, LVar1, LVar2)
                    EVT_CALL(NpcJump0, NPC_Fuzzy_05, LVar0, LVar1, LVar2, LVarD)
                EVT_END_THREAD
            EVT_END_IF
        EVT_ELSE
            EVT_THREAD
                EVT_ADD(LVarA, 1)
                EVT_MOD(LVarA, 4)
                EVT_CALL(N(func_80240574_9EE164), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
            EVT_THREAD
                EVT_ADD(LVarA, 2)
                EVT_MOD(LVarA, 4)
                EVT_CALL(N(func_80240574_9EE164), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_04, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_04, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
            EVT_THREAD
                EVT_ADD(LVarA, 3)
                EVT_MOD(LVarA, 4)
                EVT_CALL(N(func_80240574_9EE164), LVarA, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_Fuzzy_05, LVar0, LVar1, LVar2)
                EVT_CALL(NpcJump0, NPC_Fuzzy_05, LVar0, LVar1, LVar2, LVarD)
            EVT_END_THREAD
        EVT_END_IF
        EVT_WAIT(2)
        EVT_CALL(N(func_80240574_9EE164), MV_Unk_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 2)
        EVT_CALL(NpcJump0, NPC_Kooper_01, LVar0, LVar1, LVar2, LVarD)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Still)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_03, ANIM_Fuzzy_Still)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_04, ANIM_Fuzzy_Still)
        EVT_CALL(SetNpcAnimation, NPC_Fuzzy_05, ANIM_Fuzzy_Still)
        EVT_CALL(N(func_802406C4_9EE2B4), 0, 0)
        EVT_CALL(N(func_802406C4_9EE2B4), 1, 0)
        EVT_CALL(N(func_802406C4_9EE2B4), 2, 0)
        EVT_CALL(N(func_802406C4_9EE2B4), 3, 0)
        EVT_CALL(PlaySound, SOUND_SHAKE_TREE)
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(30)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242500_9F00F0) = {
    EVT_SET(AF_NOK_03, TRUE)
    EVT_IF_EQ(LocalFlag(0), FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_THREAD
            EVT_WAIT(20)
            EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(N(func_802406C4_9EE2B4), 2, 0)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0B)
    EVT_CALL(N(func_80240574_9EE164), 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_80240314_9EDF04), LVar0, LVar1, LVar2)
    EVT_CALL(N(func_802403C0_9EDFB0), 50, 0, 0)
    EVT_CALL(GetNpcPointer, NPC_Fuzzy_01, LVar0)
    EVT_CALL(GetNpcPointer, NPC_Kooper_01, LVar1)
    EVT_CALL(N(func_80240548_9EE138), LVar0)
    EVT_CALL(N(func_8024051C_9EE10C), LVar1)
    EVT_CALL(SetModelFlags, MODEL_o177, 16, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        EVT_SET(LVar0, 0x000C00BC)
        EVT_SET(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
    EVT_ELSE
        EVT_SET(LVar0, 0x000C00BD)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, LVar0)
    EVT_CALL(SetMusicTrack, 0, SONG_PLAYROOM, 0, 8)
    EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, 30)
    EVT_WAIT(30)
    EVT_CALL(SetModelFlags, MODEL_o177, 16, FALSE)
    EVT_CALL(N(func_8024051C_9EE10C), 0)
    EVT_CALL(N(func_80240548_9EE138), 0)
    EVT_EXEC(N(D_802417F8_9EF3E8))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024274C_9F033C) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
            EVT_LABEL(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, 60)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_SET(LocalFlag(0), FALSE)
            EVT_EXEC(N(D_80242500_9F00F0))
            EVT_RETURN
        EVT_CASE_GE(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
            EVT_CALL(SetNpcPos, NPC_Kooper_01, 0, -1000, 0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetPlayerSpeed, 4)
        EVT_CALL(PlayerMoveTo, -300, 325, 0)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, EVT_FLOAT(0.703125))
    EVT_CALL(SetNpcJumpscale, NPC_Kooper_01, EVT_FLOAT(0.703125))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_SET(LVarA, 58)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 227)
        EVT_SET(LVarD, 80)
        EVT_EXEC(N(D_80241710_9EF300))
    EVT_END_THREAD
    EVT_SET(LVarA, -260)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 290)
    EVT_SET(LVarD, 20)
    EVT_EXEC(N(D_802417B0_9EF3A0))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_Kooper_01, LVarA, 0, 293, LVarD)
    EVT_SET(LVarA, -180)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 245)
    EVT_SET(LVarD, 15)
    EVT_EXEC(N(D_802417B0_9EF3A0))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_Kooper_01, LVarA, LVarB, 248, LVarD)
    EVT_SET(LVarA, -100)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 235)
    EVT_SET(LVarD, 15)
    EVT_EXEC(N(D_802417B0_9EF3A0))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_Kooper_01, LVarA, LVarB, 238, LVarD)
    EVT_SET(LVarA, 85)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 217)
    EVT_SET(LVarD, 30)
    EVT_EXEC(N(D_802417B0_9EF3A0))
    EVT_WAIT(1)
    EVT_CALL(NpcJump0, NPC_Kooper_01, LVarA, LVarB, 220, LVarD)
    EVT_CALL(N(func_80240574_9EE164), 2, LVar0, LVar1, LVar2)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar3)
    EVT_SET(LVarD, 30)
    EVT_EXEC(N(D_802417B0_9EF3A0))
    EVT_WAIT(1)
    EVT_ADD(LVarC, 3)
    EVT_CALL(NpcJump0, NPC_Kooper_01, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Kooper_01, FALSE)
    EVT_CALL(N(func_802406C4_9EE2B4), 2, 0)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE)
    EVT_CALL(SetPlayerPos, -152, 0, 235)
    EVT_CALL(PlayerMoveTo, 58, 227, 60)
    EVT_SET(LocalFlag(0), TRUE)
    EVT_EXEC(N(D_80242500_9F00F0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242C5C_9F084C) = {
    EVT_LABEL(0)
    EVT_IF_EQ(MV_Unk_02, 1)
        EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
        EVT_LABEL(1)
        EVT_IF_EQ(MV_Unk_02, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80242CF4) = {
    EVT_CALL(RandInt, 399, LVar4)
    EVT_DIV(LVar4, 100)
    EVT_LABEL(0)
    EVT_CALL(RandInt, 300, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_LT(100)
            EVT_SUB(LVar4, 1)
        EVT_CASE_LT(200)
            EVT_ADD(LVar4, 1)
    EVT_END_SWITCH
    EVT_IF_LT(LVar4, 0)
        EVT_SET(LVar4, 1)
    EVT_END_IF
    EVT_IF_GT(LVar4, 3)
        EVT_SET(LVar4, 2)
    EVT_END_IF
    EVT_CALL(N(func_80240574_9EE164), LVar4, LVar0, LVar1, LVar2)
    EVT_CALL(RandInt, 10, LVar3)
    EVT_ADD(LVar3, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_B0000017, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, LVar3)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242E68_9F0A58) = {
    EVT_CALL(N(func_802404D0_9EE0C0))
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_02, ANIM_Fuzzy_Anim0B)
    EVT_CALL(N(func_80240574_9EE164), MV_Unk_03, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_80240314_9EDF04), LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 50)
    EVT_CALL(GetNpcPointer, NPC_Fuzzy_02, LVar3)
    EVT_CALL(N(func_8024051C_9EE10C), LVar3)
    EVT_CALL(N(func_80240548_9EE138), 0)
    EVT_CALL(N(func_802403C0_9EDFB0), LVar1, 0, -1)
    EVT_CALL(SetModelFlags, MODEL_o177, 16, TRUE)
    EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, 30)
    EVT_WAIT(30)
    EVT_CALL(N(func_8024051C_9EE10C), 0)
    EVT_CALL(SetModelFlags, MODEL_o177, 16, FALSE)
    EVT_SET(MV_Unk_02, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242F9C_9F0B8C) = {
    EVT_SET(LVar3, LVar0)
    EVT_CALL(MakeLerp, LVarB, LVarD, 30, EASING_QUARTIC_IN)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcPos, NPC_Kooper_01, LVar3, LVar0, LVar2)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024303C_9F0C2C) = {
    EVT_SET(LVar3, LVar0)
    EVT_CALL(MakeLerp, LVarB, LVarD, 30, EASING_QUARTIC_IN)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(SetNpcPos, NPC_Kooper_01, LVar3, LVar0, LVar2)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Fuzzy_01A) = {
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Fuzzy_01B) = {
    EVT_IF_EQ(AF_NOK_04, FALSE)
        EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
        EVT_SET(AF_NOK_04, TRUE)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Fuzzy_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(AF_NOK_05, TRUE)
            EVT_SET(AF_NOK_08, FALSE)
            EVT_LABEL(10)
            EVT_IF_EQ(AF_NOK_08, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(BindNpcAI, NPC_Fuzzy_01, EVT_PTR(N(EVS_NpcAI_Fuzzy_01A)))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80243254_9F0E44) = 0;

API_CALLABLE(N(func_80240E4C_9EEA3C)) {
    if (isInitialCall) {
        N(D_80243254_9F0E44) = FALSE;
    }

    if (N(D_80243254_9F0E44)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80240E70_9EEA60)) {
    N(D_80243254_9F0E44) = TRUE;
    return ApiStatus_DONE2;
}


EvtScript N(D_80243258_9F0E48) = {
    EVT_SET(LocalFlag(10), FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(0)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_CALL(CloseChoicePopup)
    EVT_IF_NE(LVar0, 25)
        EVT_IF_EQ(LocalFlag(10), FALSE)
            EVT_SET(LocalFlag(10), TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C5)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C6)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(N(func_80240E70_9EEA60))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

s32 N(D_80243374_9F0F64)[] = {
    ITEM_KOOPER_SHELL,
    ITEM_NONE
};

EvtScript N(D_8024337C_9F0F6C) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(D_80243258_9F0E48)), TRIGGER_FORCE_ACTIVATE, 0, EVT_PTR(N(D_80243374_9F0F64)), 0, 1)
    EVT_CALL(N(func_80240E4C_9EEA3C))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802433B8_9F0FA8) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, -104)
    EVT_SUB(LVar2, 241)
    EVT_MUL(LVar0, -101)
    EVT_MUL(LVar2, 35)
    EVT_ADD(LVar0, LVar2)
    EVT_IF_LE(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_Kooper_02, -350, 0, 350)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -220, 0, 270)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -220, 0, 270)
    EVT_CALL(GetCamDistance, CAM_DEFAULT, LVarA)
    EVT_MULF(LVarA, EVT_FLOAT(0.703125))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, LVarA)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(PlayerMoveTo, -205, 267, 40)
        EVT_CALL(PlayerFaceNpc, NPC_Kooper_02, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_RunAngry)
    EVT_CALL(NpcMoveTo, NPC_Kooper_02, -246, 290, 30)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_IdleAngry)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_KooperWithoutShell_TalkAngry, ANIM_KooperWithoutShell_IdleAngry, 0, MSG_CH1_00C3)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kooper_02, 0)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper_02, MSG_CH1_00C4)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_Idle)
    EVT_EXEC_WAIT(N(D_8024337C_9F0F6C))
    EVT_CALL(PlayerMoveTo, -207, 268, 7)
    EVT_CALL(PlayerFaceNpc, NPC_Kooper_02, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
    EVT_CALL(SetNpcJumpscale, NPC_Kooper_01, 1)
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, -15)
            EVT_ADD(LVar1, 8)
            EVT_ADD(LVar2, 12)
            EVT_CALL(SetNpcPos, NPC_Kooper_01, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_Idle)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00C7)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_Celebrate)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_Idle)
    EVT_CALL(EndSpeech, NPC_Kooper_02, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Kooper_02, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_Kooper_02, 0)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_KooperWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_Kooper_01, TRUE)
    EVT_CALL(GetNpcPos, NPC_Kooper_02, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, 1)
    EVT_SET(LVar4, 6)
    EVT_EXEC(N(D_80241328_9EEF18))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_Kooper_01, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_Kooper_01, 0, -1000, 0)
    EVT_CALL(SetNpcSprite, NPC_Kooper_02, ANIM_WorldKooper_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_Kooper_02, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcSprite, NPC_Kooper_02, ANIM_WorldKooper_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_Kooper_01, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_WorldKooper_Idle)
    EVT_CALL(SetNpcSprite, NPC_Kooper_02, ANIM_WorldKooper_Celebrate)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_WorldKooper_Idle)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper_02, MSG_CH1_00C8)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00C9)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtPlayer, SOUND_263, 0)
    EVT_CALL(ShowEmote, NPC_Fuzzy_01, EMOTE_QUESTION, -45, 50, FALSE, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH1_00CA)
    EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CB)
    EVT_WAIT(10)
    EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, NPC_Kooper_02, MSG_CH1_00CC)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PlayerFaceNpc, NPC_Kooper_02, FALSE)
    EVT_LABEL(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
    EVT_CALL(ShowChoice, MSG_Choice_000F)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(EndSpeech, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
        EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CD)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_CALL(EndSpeech, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
        EVT_CALL(SpeakToPlayer, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH1_00CE)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_WorldKooper_Celebrate)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_02, ANIM_WorldKooper_Idle)
        EVT_CALL(EndSpeech, NPC_Kooper_02, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0)
        EVT_SET(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
    EVT_END_IF
    EVT_CALL(N(ChangeNpcToPartner), 6, 2)
    EVT_CALL(N(LoadPartyImage))
    EVT_EXEC(N(EVS_PushPartnerSong))
    EVT_WAIT(15)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_018A, 160, 40)
    EVT_EXEC(N(EVS_PopSong))
    EVT_WAIT(10)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(AwaitPlayerApproach, -400, 400, 100)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00CF, 160, 40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 0, 225)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 0, 225)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -250)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Walk)
    EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 63, 0, 212)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, EVT_FLOAT(2.0))
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, -100, 0, 225, 20)
    EVT_SET(AF_NOK_06, FALSE)
    EVT_SET(AF_NOK_07, FALSE)
    EVT_SET(AF_NOK_05, FALSE)
    EVT_THREAD
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00D0, 160, 40)
        EVT_SET(AF_NOK_06, TRUE)
    EVT_END_THREAD
    EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVarA, LVarB, LVarC)
    EVT_LABEL(30)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, EVT_FLOAT(2.0))
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 12)
    EVT_IF_EQ(AF_NOK_06, FALSE)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(27)
        EVT_CALL(BindNpcDefeat, NPC_Fuzzy_01, EVT_PTR(N(EVS_NpcDefeat_Fuzzy_01)))
        EVT_CALL(BindNpcAI, NPC_Fuzzy_01, EVT_PTR(N(EVS_NpcAI_Fuzzy_01B)))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, -212, 0, 237, 15)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_ADD(LVarB, 37)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 20)
        EVT_WAIT(2)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_80012)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 15)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_LABEL(21)
        EVT_IF_EQ(AF_NOK_05, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, -255, 0, 287)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVarA, LVarB, LVarC)
        EVT_LABEL(31)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 15)
        EVT_IF_EQ(AF_NOK_07, FALSE)
            EVT_GOTO(31)
        EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 15)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 20)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 2)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, 63, 0, 212)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_03, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, -100, 0, 225, 10)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, -197, 0, 227, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, -233, 0, 285, 10)
        EVT_LABEL(22)
        EVT_IF_EQ(AF_NOK_05, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(22)
        EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, -210, 0, 244)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_03, LVarA, LVarB, LVarC)
        EVT_LABEL(32)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_03, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 12)
        EVT_IF_EQ(AF_NOK_07, FALSE)
            EVT_GOTO(32)
        EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 10)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_03, LVarA, LVarB, LVarC, 20)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_03, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_04, 63, 0, 212)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_04, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_04, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_04, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_04, -122, 0, 219, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_04, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_04, -177, 0, 242, 10)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_04, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_04, -213, 0, 300, 15)
        EVT_LABEL(23)
        EVT_IF_EQ(AF_NOK_05, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(23)
        EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_04, -210, 0, 266)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_04, LVarA, LVarB, LVarC)
        EVT_WAIT(2)
        EVT_LABEL(33)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_04, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_04, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_04, LVarA, LVarB, LVarC, 12)
        EVT_IF_EQ(AF_NOK_07, FALSE)
            EVT_GOTO(33)
        EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_04, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_04, LVarA, LVarB, LVarC, 20)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_04, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_04, LVarA, LVarB, LVarC, 15)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_04, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_04, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_05, 63, 0, 212)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_05, TRUE)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_05, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_05, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_05, -100, 0, 269, 20)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_05, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_05, -217, 0, 212, 10)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_05, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_05, -253, 0, 270, 10)
        EVT_LABEL(24)
        EVT_IF_EQ(AF_NOK_05, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(24)
        EVT_END_IF
        EVT_CALL(SetNpcPos, NPC_Fuzzy_05, -183, 0, 257)
        EVT_CALL(GetNpcPos, NPC_Fuzzy_05, LVarA, LVarB, LVarC)
        EVT_WAIT(5)
        EVT_LABEL(34)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_05, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_05, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_05, LVarA, LVarB, LVarC, 12)
        EVT_IF_EQ(AF_NOK_07, FALSE)
            EVT_GOTO(34)
        EVT_END_IF
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_05, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_05, LVarA, LVarB, LVarC, 15)
        EVT_ADD(LVarA, 70)
        EVT_ADD(LVarC, -30)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_05, SOUND_B0000017, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_05, LVarA, LVarB, LVarC, 20)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_05, FALSE)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_05, 0, -1000, 0)
    EVT_END_THREAD
    EVT_LABEL(40)
    EVT_IF_EQ(AF_NOK_05, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(40)
    EVT_END_IF
    EVT_CALL(SetPlayerPos, -305, 0, 329)
    EVT_CALL(InterpPlayerYaw, 50, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -335, 0, 355)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 50, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00D1, 160, 40)
    EVT_SET(AF_NOK_07, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -260, 0, 284)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(AF_NOK_08, TRUE)
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244D0C_9F28FC) = {
    EVT_THREAD
        EVT_CALL(N(func_80240574_9EE164), LVar0, LVar0, LVar1, LVar2)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_ADD(LVarA, LVar0)
        EVT_ADD(LVarC, LVar2)
        EVT_DIV(LVarA, 2)
        EVT_DIV(LVarC, 2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -11)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(N(func_80240574_9EE164), LVar0, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPointer, NPC_Fuzzy_01, LVarE)
    EVT_CALL(GetNpcPointer, NPC_Kooper_01, LVarF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SWITCH(MV_Unk_00)
        EVT_CASE_EQ(0)
            EVT_SET(LVar4, LVarC)
            EVT_SUB(LVar4, 4)
            EVT_CALL(N(func_80240314_9EDF04), LVarA, LVarB, LVar4)
            EVT_CALL(SetModelFlags, MODEL_o177, 16, TRUE)
            EVT_SET(LVar3, LVarB)
            EVT_DIV(LVar3, 2)
            EVT_SET(LVarD, LVarB)
            EVT_SUB(LVarD, LVar3)
            EVT_EXEC(N(D_8024303C_9F0C2C))
            EVT_WAIT(1)
            EVT_WAIT(30)
            EVT_CALL(N(func_8024051C_9EE10C), 0)
            EVT_CALL(N(func_80240548_9EE138), 0)
            EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, -1)
            EVT_CALL(N(func_802403C0_9EDFB0), LVar3, 0, -1)
            EVT_WAIT(1)
            EVT_CALL(N(func_8024051C_9EE10C), LVarF)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlayerFaceNpc, NPC_Fuzzy_01, FALSE)
            EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, 0)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarD, LVarC, 30)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim09)
            EVT_SET(LVar9, LVarC)
            EVT_CALL(SpeakToPlayer, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00BF)
            EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, 30)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0B)
            EVT_SET(LVarC, LVar9)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 30)
            EVT_CALL(N(func_8024051C_9EE10C), 0)
            EVT_CALL(SetModelFlags, MODEL_o177, 16, FALSE)
            EVT_ADD(MV_Unk_00, 1)
            EVT_EXEC(N(D_802417F8_9EF3E8))
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_SET(LVar4, LVarC)
            EVT_SUB(LVar4, 4)
            EVT_CALL(N(func_80240314_9EDF04), LVarA, LVarB, LVar4)
            EVT_CALL(SetModelFlags, MODEL_o177, 16, TRUE)
            EVT_SET(LVar3, LVarB)
            EVT_MUL(LVar3, 2)
            EVT_DIV(LVar3, 3)
            EVT_SET(LVarD, LVarB)
            EVT_SUB(LVarD, LVar3)
            EVT_EXEC(N(D_80242F9C_9F0B8C))
            EVT_WAIT(1)
            EVT_WAIT(30)
            EVT_CALL(N(func_8024051C_9EE10C), 0)
            EVT_CALL(N(func_80240548_9EE138), 0)
            EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, -1)
            EVT_CALL(N(func_802403C0_9EDFB0), LVar3, 0, -1)
            EVT_WAIT(1)
            EVT_CALL(N(func_8024051C_9EE10C), LVarF)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlayerFaceNpc, NPC_Fuzzy_01, FALSE)
            EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, 0)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarD, LVarC, 30)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim09)
            EVT_SET(LVar9, LVarC)
            EVT_CALL(SpeakToPlayer, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C0)
            EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, 30)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0B)
            EVT_SET(LVarC, LVar9)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_B0000017, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, LVarB, LVarC, 30)
            EVT_CALL(N(func_8024051C_9EE10C), 0)
            EVT_CALL(SetModelFlags, MODEL_o177, 16, FALSE)
            EVT_ADD(MV_Unk_00, 1)
            EVT_EXEC(N(D_802417F8_9EF3E8))
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlayerFaceNpc, NPC_Fuzzy_01, FALSE)
            EVT_CALL(N(func_80240314_9EDF04), LVarA, LVarB, LVarC)
            EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, -1)
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, 50)
            EVT_CALL(N(func_802403C0_9EDFB0), LVar0, 0, 0)
            EVT_CALL(N(func_8024051C_9EE10C), LVarF)
            EVT_CALL(N(func_80240548_9EE138), LVarE)
            EVT_CALL(SetModelFlags, MODEL_o177, 16, TRUE)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim09)
            EVT_CALL(SpeakToPlayer, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C1)
            EVT_WAIT(10)
            EVT_CALL(N(func_8024051C_9EE10C), 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetNpcJumpscale, NPC_Kooper_01, EVT_FLOAT(0.6))
            EVT_CALL(NpcJump0, NPC_Kooper_01, LVar0, LVar1, LVar2, 10)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10024)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_ADD(LVar4, 50)
                EVT_ADD(LVar5, 2)
                EVT_ADD(LVar3, 8)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
                EVT_ADD(LVar3, -16)
                EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
            EVT_END_THREAD
            EVT_CALL(PlaySound, SOUND_D2)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_GotKooperShell, 160, 40)
            EVT_CALL(SetNpcPos, NPC_Kooper_01, 0, -1000, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(AddKeyItem, ITEM_KOOPER_SHELL)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 5, MSG_CH1_00C2)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0B)
            EVT_CALL(N(func_802403C0_9EDFB0), 0, 0, 20)
            EVT_WAIT(20)
            EVT_CALL(SetModelFlags, MODEL_o177, 16, FALSE)
            EVT_CALL(N(func_80240548_9EE138), 0)
            EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
            EVT_CALL(SetNpcPos, NPC_Kooper_01, 0, -1000, 0)
            EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_VILLAGE, 0, 8)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(AF_NOK_03, FALSE)
            EVT_EXEC(N(D_802433B8_9F0FA8))
    EVT_END_SWITCH
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245858_9F3448) = {
    EVT_THREAD
        EVT_CALL(N(func_80240574_9EE164), LVar0, LVar0, LVar1, LVar2)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_ADD(LVarA, LVar0)
        EVT_ADD(LVarC, LVar2)
        EVT_DIV(LVarA, 2)
        EVT_DIV(LVarC, 2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -11)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_SET(MV_Unk_03, LVar0)
    EVT_CALL(N(func_80240574_9EE164), MV_Unk_03, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPointer, NPC_Kooper_01, LVarF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(RandInt, 999, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(200)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_HEART, LVar0, 200, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
            EVT_WAIT(30)
        EVT_CASE_LT(400)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, 200, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
            EVT_WAIT(30)
        EVT_CASE_LT(1000)
            EVT_CALL(SetNpcAnimation, NPC_Fuzzy_02, ANIM_Fuzzy_Anim06)
            EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_02, 1)
            EVT_CALL(SetNpcPos, NPC_Fuzzy_02, LVarA, LVarB, LVarC)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar2, 10)
            EVT_ADD(LVar1, 10)
            EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_02, SOUND_B0000017, 0)
            EVT_CALL(NpcJump0, NPC_Fuzzy_02, LVar0, LVar1, LVar2, 20)
            EVT_SET(MV_Unk_02, 1)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_IF_EQ(MV_Unk_02, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_EXEC(N(D_802417F8_9EF3E8))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80245BD8) = {
    EVT_CALL(N(func_802406C4_9EE2B4), LVar0, 1)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE)
    EVT_IF_EQ(AF_NOK_03, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_END_THREAD
    EVT_IF_EQ(LVar0, MV_Unk_01)
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(PlaySound, SOUND_21C)
        EVT_END_THREAD
        EVT_EXEC_WAIT(N(D_80244D0C_9F28FC))
    EVT_ELSE
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_END_THREAD
        EVT_EXEC_WAIT(N(D_80245858_9F3448))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245CF8_9F38E8) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245D08_9F38F8) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024274C_9F033C)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, 0, -1000, 0)
        EVT_CALL(SetNpcPos, NPC_Kooper_01, 0, -1000, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MV_Unk_00, 0)
    EVT_SET(MV_Unk_01, 2)
    EVT_SET(MV_Unk_04, 2)
    EVT_CALL(N(func_802404D0_9EE0C0))
    EVT_CALL(SetCustomGfxBuilders, 0, 0, EVT_PTR(N(func_80240814_9EE404)))
    EVT_CALL(SetNpcPos, NPC_Fuzzy_01, -293, 0, 319)
    EVT_CALL(SetNpcPos, NPC_Kooper_01, -293, 0, 322)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_02, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_04, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Fuzzy_05, FALSE)
    EVT_CALL(SetModelFlags, MODEL_o177, 512, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        EVT_CALL(N(func_80240574_9EE164), LVar4, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Kooper_01, LVar0, LVar1, LVar2)
        EVT_CALL(EnableNpcShadow, NPC_Fuzzy_01, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_Kooper_01, FALSE)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245F18_9F3B08) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245F50_9F3B40) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_80242C5C_9F084C)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(D_80242E68_9F0A58)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245F88_9F3B78) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245FAC_9F3B9C) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_80245CF8_9F38E8)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_IF_LT(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(InterpNpcYaw, NPC_Kooper_02, 225, 0)
            EVT_CALL(SetNpcPos, NPC_Kooper_02, -275, 0, 305)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_Kooper_02, ANIM_KooperWithoutShell_IdleAngry)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Kooper_01)[] = {
    {
        .id = NPC_Kooper_01,
        .settings = &N(NpcSettings_Kooper_01),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(D_80245F18_9F3B08),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .id = NPC_Fuzzy_02,
        .settings = &N(NpcSettings_Fuzzy_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(D_80245F50_9F3B40),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_Fuzzy_03,
        .settings = &N(NpcSettings_Fuzzy_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(D_80245F88_9F3B78),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_Fuzzy_04,
        .settings = &N(NpcSettings_Fuzzy_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(D_80245F88_9F3B78),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_Fuzzy_05,
        .settings = &N(NpcSettings_Fuzzy_02),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(D_80245F88_9F3B78),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_Kooper_02,
        .settings = &N(NpcSettings_Kooper_01),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .init = &N(D_80245FAC_9F3B9C),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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

StaticNpc N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .settings = &N(NpcSettings_Fuzzy_02),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
    .init = &N(D_80245D08_9F38F8),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kooper_01), BTL_NOK_FORMATION_16, BTL_NOK_STAGE_03),
    NPC_GROUP(N(NpcData_Fuzzy_01), BTL_NOK_FORMATION_17, BTL_NOK_STAGE_03),
    {}
};
