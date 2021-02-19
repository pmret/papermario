#include "common.h"

extern s32 D_8023CDA4;

ApiStatus func_80238000_6F10E0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* secondBattleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 posX = partnerActor->currentPos.x;
    f32 posY = partnerActor->currentPos.y;
    f32 posZ = partnerActor->currentPos.z;
    f32 goalX = partnerActor->movePos.goal.x;
    f32 goalY = partnerActor->movePos.goal.y;
    f32 goalZ = partnerActor->movePos.goal.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (secondBattleStatus->unk_83 != 0) {
        if (script->varTable[0] < 10) {
            script->varTable[0] = 10;
        }
    } else if (script->varTable[0] < 15) {
        script->varTable[0] = 15;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_802380E4_6F11C4);

#ifdef NON_MATCHING
ApiStatus func_8023817C_6F125C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorMovePos partnerMovePos = partnerActor->movePos;
    f32 curPosX;
    f32 curPosY;
    f32 curPosZ;
    f32 goalPosX;
    f32 goalPosY;
    f32 goalPosZ;

    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f20;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f22_4;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f8;
    f32 temp_f8_2;
    f64 temp_f20_2;
    f64 temp_f20_3;
    f64 temp_f20_5;
    f64 temp_f20_6;
    f64 temp_f20_7;
    f64 temp_f22_2;
    f64 temp_f22_3;
    f64 temp_f22_5;
    f64 temp_f22_6;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_v1_3;
    s32 temp_f10;
    s32 temp_v1_2;
    void *temp_s2;
    f32 phi_f8;
    f64 phi_f20;
    f64 phi_f0;
    f64 phi_f2;
    f64 phi_f22;
    f32 phi_f12;
    f64 phi_f20_2;
    f64 phi_f0_2;
    f64 phi_f2_2;
    f64 phi_f22_2;

    if (isInitialCall != 0) {
        partnerActor->moveTime = get_variable(script, *args++);
        partnerActor->moveArcAmplitude = get_variable(script, *args++);
        script->functionTemp[1].s = 0;
        script->functionTemp[0].s = 0;
        if (partnerActor->moveArcAmplitude == 1) {
            script->functionTemp[0].s = 2;
        }
    }
    if (script->functionTemp[0].s == 0) {
        temp_f24 = partnerMovePos.goal.x;
        temp_f26 = partnerMovePos.goal.z;
        partnerMovePos.current.x = (f32) partnerActor->currentPos.x;
        temp_f22 = partnerMovePos.current.x;
        partnerMovePos.current.y = (f32) partnerActor->currentPos.y;
        temp_f20 = partnerActor->currentPos.z;
        partnerMovePos.current.z = temp_f20;
        partnerMovePos->unk48 = atan2(temp_f22, temp_f20, temp_f24, temp_f26);
        temp_v0 = partnerMovePos->unk64;
        temp_f4 = dist2D(temp_f22, temp_f20, temp_f24, temp_f26);
        partnerMovePos->unk4C = temp_f4;
        if (temp_v0 == 0) {
            temp_f10 = (s32) (temp_f4 / partnerMovePos->unk40);
            partnerMovePos->unk64 = (s16) temp_f10;
            phi_f8 = temp_f4 - ((f32) (s16) temp_f10 * partnerMovePos->unk40);
        } else {
            temp_f2 = temp_f4 / (f32) temp_v0;
            partnerMovePos->unk40 = temp_f2;
            phi_f8 = partnerMovePos->unk4C - ((f32) partnerMovePos->unk64 * temp_f2);
        }
        temp_v1 = partnerMovePos->unk64;
        phi_return = 2;
        if (temp_v1 != 0) {
            temp_f6 = (f32) partnerMovePos->unk64;
            partnerMovePos->unk3C = (f32) (3.14159f / temp_f6);
            partnerMovePos->unk30 = (f32) ((partnerMovePos.goal.x - partnerMovePos.current.x) / (f32) temp_v1);
            partnerMovePos->unk44 = 0.0f;
            partnerMovePos->unk34 = (f32) ((partnerMovePos.goal.y - partnerMovePos.current.y) / temp_f6);
            partnerMovePos->unk38 = (f32) ((partnerMovePos.goal.z - partnerMovePos.current.z) / temp_f6);
            partnerMovePos->unk40 = (f32) (partnerMovePos->unk40 + (phi_f8 / temp_f6));
            if ((s32) partnerMovePos->unk66 < 3) {
                temp_f8 = (f32) ((f64) (f32) ((f64) (f32) ((f64) partnerMovePos->unk4C - 20.0) / 6.0) + D_8023CD50_6F5E30);
                partnerMovePos->unk24 = 90.0f;
                partnerMovePos->unk50 = temp_f8;
                partnerMovePos->unk28 = (f32) (0x168 / (s32) partnerMovePos->unk64);
                if (partnerMovePos->unk66 == 2) {
                    partnerMovePos->unk50 = (f32) ((f64) temp_f8 * D_8023CD58_6F5E38);
                }
                partnerMovePos->unk18 = 0.0f;
                partnerMovePos->unk1C = 0.0f;
                temp_f20_2 = (f64) partnerMovePos->unk44;
                temp_f22_2 = (f64) partnerMovePos->unk3C;
                phi_f20 = temp_f20_2;
                phi_f0 = (f64) sin_rad((partnerMovePos->unk24 * 6.28318f) / 360.0f);
                phi_f2 = D_8023CD60_6F5E40;
                phi_f22 = temp_f22_2;
            } else {
                temp_f8_2 = (f32) ((f64) (f32) ((f64) (f32) ((f64) partnerMovePos->unk4C - 20.0) / 6.0) + D_8023CD68_6F5E48);
                partnerMovePos->unk24 = 90.0f;
                partnerMovePos->unk50 = temp_f8_2;
                partnerMovePos->unk28 = (f32) (0x168 / (s32) partnerMovePos->unk64);
                if (partnerMovePos->unk66 == 4) {
                    partnerMovePos->unk50 = (f32) ((f64) temp_f8_2 * 1.25);
                }
                partnerMovePos->unk18 = 0.0f;
                partnerMovePos->unk1C = 0.0f;
                temp_f20_3 = (f64) partnerMovePos->unk44;
                temp_f22_3 = (f64) partnerMovePos->unk3C;
                phi_f20 = temp_f20_3;
                phi_f0 = (f64) sin_rad((partnerMovePos->unk24 * 6.28318f) / 360.0f);
                phi_f2 = D_8023CD70_6F5E50;
                phi_f22 = temp_f22_3;
            }
            partnerMovePos->unk44 = (f32) (phi_f20 + ((phi_f0 * phi_f2 * phi_f22) + phi_f22));
            set_animation(0x100, 1, partnerMovePos->unk58);
            script->unk70 = 1;
block_16:
            temp_v1_2 = script->unk70;
            if (temp_v1_2 != 2) {
                if (temp_v1_2 < 3) {
                    if (temp_v1_2 != 1) {
                        return 0;
                    }
                    if (partnerMovePos->unk44 > 1.570795f) {
                        set_animation(0x100, 1, partnerMovePos->unk5C);
                    }
                    temp_f22_4 = partnerActor->currentPos.x;
                    temp_f6_2 = partnerMovePos.current.x + partnerMovePos->unk30;
                    temp_f20_4 = partnerActor->currentPos.y;
                    partnerMovePos.current.x = temp_f6_2;
                    partnerMovePos.current.y = (f32) (partnerMovePos.current.y + partnerMovePos->unk34);
                    partnerMovePos.current.z = (f32) (partnerMovePos.current.z + partnerMovePos->unk38);
                    partnerMovePos->unk18 = (f32) partnerActor->currentPos.y;
                    partnerActor->currentPos.x = temp_f6_2;
                    partnerActor->currentPos.y = (f32) (partnerMovePos.current.y + (partnerMovePos->unk50 * sin_rad(partnerMovePos->unk44)));
                    partnerActor->currentPos.z = (f32) partnerMovePos.current.z;
                    temp_f2_2 = partnerMovePos.goal.y;
                    phi_f12 = temp_f22_4;
                    if (partnerActor->currentPos.y < temp_f2_2) {
                        if ((s32) partnerMovePos->unk64 < 3) {
                            partnerActor->currentPos.y = temp_f2_2;
                        }
                    }
                    partnerActor->unk164 = (f32) -atan2(phi_f12, -temp_f20_4, (bitwise s32) partnerActor->currentPos.x, -temp_s2->currentPos.y);
                    partnerMovePos->unk1C = (f32) partnerActor->currentPos.y;
                    if ((s32) partnerMovePos->unk66 < 3) {
                        temp_f20_5 = (f64) partnerMovePos->unk44;
                        temp_f22_5 = (f64) partnerMovePos->unk3C;
                        phi_f20_2 = temp_f20_5;
                        phi_f0_2 = (f64) sin_rad((partnerMovePos->unk24 * 6.28318f) / 360.0f);
                        phi_f2_2 = D_8023CD78_6F5E58;
                        phi_f22_2 = temp_f22_5;
                    } else {
                        temp_f20_6 = (f64) partnerMovePos->unk44;
                        temp_f22_6 = (f64) partnerMovePos->unk3C;
                        phi_f20_2 = temp_f20_6;
                        phi_f0_2 = (f64) sin_rad((partnerMovePos->unk24 * 6.28318f) / 360.0f);
                        phi_f2_2 = D_8023CD80_6F5E60;
                        phi_f22_2 = temp_f22_6;
                    }
                    partnerMovePos->unk44 = (f32) (phi_f20_2 + ((phi_f0_2 * phi_f2_2 * phi_f22_2) + phi_f22_2));
                    temp_f12 = partnerMovePos->unk24 + partnerMovePos->unk28;
                    partnerMovePos->unk24 = temp_f12;
                    partnerMovePos->unk24 = clamp_angle(temp_f12);
                    temp_v0_2 = (u16) partnerMovePos->unk64 - 1;
                    partnerMovePos->unk64 = temp_v0_2;
                    phi_return = 0;
                    if ((temp_v0_2 << 0x10) == 0) {
                        partnerActor->currentPos.y = (f32) partnerMovePos.goal.y;
                        partnerMovePos->unk3C = 1.8f;
                        partnerMovePos->unk44 = (f32) -(partnerMovePos->unk18 - partnerMovePos->unk1C);
                        set_animation(0x100, 1, partnerMovePos->unk60);
                        return 1;
                    }
                } else {
                    if (temp_v1_2 != 3) {
                        return 0;
                    }
block_37:
                    temp_f20_7 = (f64) partnerMovePos.current.x;
                    partnerMovePos.current.x = (f32) (temp_f20_7 + ((f64) (partnerMovePos->unk50 * sin_rad((partnerMovePos->unk24 * 6.28318f) / 360.0f)) / D_8023CD90_6F5E70));
                    temp_f12_2 = partnerMovePos->unk24 + partnerMovePos->unk28;
                    temp_f0 = partnerMovePos.current.y - (partnerMovePos->unk50 * sin_rad((partnerMovePos->unk24 * 6.28318f) / 360.0f));
                    partnerMovePos->unk24 = temp_f12_2;
                    partnerMovePos.current.y = temp_f0;
                    partnerMovePos->unk24 = clamp_angle(temp_f12_2);
                    partnerActor->currentPos.x = (f32) partnerMovePos.current.x;
                    partnerActor->currentPos.y = (f32) partnerMovePos.current.y;
                    partnerActor->currentPos.z = (f32) partnerMovePos.current.z;
                    if ((gBattleStatus.unk0 & 0x2000) != 0) {
block_38:
                        return 2;
                    }
                    temp_v1_3 = (u16) partnerMovePos->unk64 - 1;
                    partnerMovePos->unk64 = temp_v1_3;
                    phi_return = 1;
                    if ((temp_v1_3 << 0x10) != 0) {
                        phi_return = 0;
                    }
                }
            } else {
                if (gBattleStatus.unk83 == 0) {
                    goto block_38;
                }
                partnerMovePos->unk64 = (u16)1;
                partnerMovePos->unk3C = 1.8f;
                partnerMovePos->unk24 = 90.0f;
                partnerMovePos->unk44 = (f32) -(partnerMovePos->unk18 - partnerMovePos->unk1C);
                partnerMovePos->unk50 = (f32) ((f64) fabsf(partnerMovePos->unk18 - partnerMovePos->unk1C) / D_8023CD88_6F5E68);
                partnerMovePos->unk28 = (f32) (0x168 / (s32) partnerMovePos->unk64);
                partnerMovePos.current.x = (f32) partnerActor->currentPos.x;
                partnerMovePos.current.y = (f32) partnerActor->currentPos.y;
                partnerMovePos->unk8 = (f32) partnerActor->currentPos.z;
                script->unk70 = 3;
                goto block_37;
            }
        }
    } else {
        goto block_16;
    }
    return phi_return;
}
#else
INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_8023817C_6F125C);
#endif

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238A20_6F1B00);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238B60_6F1C40);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238BCC_6F1CAC);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238E04_6F1EE4);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238E48_6F1F28);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238E74_6F1F54);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80238EDC_6F1FBC);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_8023903C_6F211C);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_80239068_6F2148);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_802390B0_6F2190);

INCLUDE_ASM(s32, "battle/partner/goombario_6F10E0", func_802390C8_6F21A8);

ApiStatus func_80239190_6F2270(ScriptInstance* script, s32 isInitialCall) {
    if (D_8023CDA4 == 0) {
        script->varTable[0] = 36;
    } else {
        script->varTable[0] = 37;
    }

    return ApiStatus_DONE2;
}
