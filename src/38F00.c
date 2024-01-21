#include "common.h"

API_CALLABLE(func_8005DB00);
API_CALLABLE(func_8005DD54);
API_CALLABLE(func_8005DDF0);

EvtScript EVS_800936C0 = {
    Call(func_8005DB00)
    Return
    End
};

EvtScript EVS_NpcHitRecoil = {
    Call(SetNpcAnimation, NPC_SELF, LVar0)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar3, LVar2)
    Set(LVar1, LVar3)
    Add(LVar1, 1)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 4)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 16)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 8)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 20)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 8)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 12)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 6)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Set(LVar1, LVar3)
    Add(LVar1, 0)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Wait(1)
    Return
    End
};

EvtScript D_800939A4 = {
    Return
    End
};

EvtScript D_800939B4 = {
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SetSelfVar, 0, 1)
        Call(BindNpcAI, NPC_SELF, Ref(D_800939A4))
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_JUMPING, FALSE)
        Call(SetNpcAnimation, NPC_SELF, LVar2)
        Set(LVar0, 0)
        Loop(30)
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Call(func_8005DD54)
            Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_COLOR, LVar2, LVar2, LVar2, 0)
            Add(LVar0, 30)
            Wait(1)
        EndLoop
        Call(SetNpcRotation, NPC_SELF, 0, 0, 0)
        Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_COLOR, 255, 255, 255, 0)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
        Call(SetSelfVar, 0, 0)
        Call(func_8005DDF0)
        Call(BindNpcAI, NPC_SELF, LVar1)
    EndIf
    Return
    End
};

API_CALLABLE(func_8005DB00) {
    Npc* npc;
    f32 targetDir, npcYaw;
    PlayerStatus* playerStatus;
    PartnerStatus* partnerStatus;

    npc = get_npc_unsafe(script->owner1.enemy->npcID);
    playerStatus = &gPlayerStatus;
    partnerStatus = &gPartnerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            npc->planarFlyDist = evt_get_float_variable(script, LVar0);
            npc->duration = evt_get_variable(script, LVar1);
            script->functionTemp[1] = evt_get_variable(script, LVar2);
            script->functionTemp[2] = evt_get_variable(script, LVar3) / 2;
            npc->curAnim = script->varTable[10];
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (partnerStatus->actingPartner != PARTNER_BOW) {
                if (npc->duration != 0 && npc->duration != script->functionTemp[0]) {
                    return ApiStatus_BLOCK;
                }

                if (npc->duration == 0) {
                    if (sqrtf(SQ((playerStatus->pos.x - npc->pos.x)) +
                            SQ((playerStatus->pos.y - npc->pos.y)) +
                            SQ((playerStatus->pos.z - npc->pos.z))) <= npc->planarFlyDist) {
                        targetDir = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        npcYaw = script->functionTemp[1] == -1 ? npc->yaw : script->functionTemp[1];

                        if (fabsf(get_clamped_angle_diff(npcYaw, targetDir)) < script->functionTemp[2]) {
                            script->varTable[0] = 1;
                            return ApiStatus_DONE2;
                        }
                    }
                } else {
                    if (dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z) <= npc->planarFlyDist) {
                        targetDir = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        npcYaw = script->functionTemp[1] == -1 ? npc->yaw : script->functionTemp[1];

                        if (fabsf(get_clamped_angle_diff(npcYaw, targetDir)) < script->functionTemp[2]) {
                            script->varTable[0] = 1;
                            return ApiStatus_DONE2;
                        }
                    }
                }
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(func_8005DD54) {
    f32 angle = clamp_angle(script->varTable[0]);

    script->varTable[0] = angle;
    if (angle >= 180.0f) {
        angle -= 180.0f;
    }
    if (angle >= 90.0f) {
        angle = 180.0f - angle;
    }
    script->varTable[2] = (s32) (((90.0f - angle) * 95.0f) / 90.0f) + 160;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_8005DDF0) {
    if (gCurrentEncounter.unk_08 != -1) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}
