#include "jan_00.h"
#include "effects.h"
#include "npc.h"
#include "sprite/player.h"

NpcSettings N(NpcSettings_Kolorado_01) = {
    .height = 24,
    .radius = 48,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/JrTroopa.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    Call(N(LetterDelivery_Init),
        NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH5_001D, MSG_CH5_001E, MSG_CH5_001F, MSG_CH5_0020,
        Ref(N(LetterList)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

API_CALLABLE(func_80240B4C_B2108C) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s1 = evt_get_variable(script, *args++);
    Npc* npc;
    f32 temp_f20;
    f32 var_f22;
    f32 x, y, z;
    s32 outX, outY, outZ;

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;

    outX = *args++;
    outY = *args++;
    outZ = *args++;
    npc = get_npc_safe(NPC_Whale);

    switch (temp_s1) {
        case 0:
            var_f22 = 130.0f;
            break;
        case 1:
            var_f22 = 160.0f;
            break;
        case 2:
            var_f22 = 100.0f;
            break;
        default:
            var_f22 = 80.0f;
            break;
    }
    if (temp_s1 < 4) {
        temp_f20 = -npc->yaw;
        x = npc->pos.x + 30.0f + sin_deg(temp_f20) * var_f22;
        z = npc->pos.z + cos_deg(temp_f20) * var_f22;
        y = npc->pos.y + 50.0f;
    }
    evt_set_float_variable(script, outX, x);
    evt_set_float_variable(script, outY, y);
    evt_set_float_variable(script, outZ, z);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240CF8_B21238)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc0 = get_npc_safe(NPC_Whale);
    Npc* npc1;
    Npc* partner;
    f32 theta;
    f32 x, y, z;
    f32 temp_f22;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);

        switch (script->functionTemp[0]) {
            case 0:
                script->functionTemp[1] = 55;
                break;
            case 1:
                script->functionTemp[1] = 85;
                break;
            default:
                script->functionTemp[1] = 25;
                break;
        }
    }
    temp_f22 = script->functionTemp[1];
    theta = -npc0->yaw;
    x = ((npc0->pos.x + 30.0f) - 75.0f) + (sin_deg(theta) * temp_f22);
    z = npc0->pos.z + (cos_deg(theta) * temp_f22);
    y = npc0->pos.y + 50.0f;

    switch (script->functionTemp[0]) {
        case 0:
            gPlayerStatus.pos.x = x;
            gPlayerStatus.pos.y = y;
            gPlayerStatus.pos.z = z;
            npc0->colliderPos.x = npc0->pos.x;
            npc0->colliderPos.y = npc0->pos.y;
            npc0->colliderPos.z = npc0->pos.z;
            npc0->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
        case 1:
            partner = get_npc_safe(NPC_PARTNER);
            if (partner == NULL) {
                return ApiStatus_DONE2;
            }
            partner->pos.x = x;
            partner->pos.y = y;
            partner->pos.z = z;
            partner->colliderPos.x = partner->pos.x;
            partner->colliderPos.y = partner->pos.y;
            partner->colliderPos.z = partner->pos.z;
            partner->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
        case 2:
            npc1 = get_npc_safe(NPC_Kolorado_02);
            npc1->pos.x = x;
            npc1->pos.y = y;
            npc1->pos.z = z;
            npc1->colliderPos.x = npc1->pos.x;
            npc1->colliderPos.y = npc1->pos.y;
            npc1->colliderPos.z = npc1->pos.z;
            npc1->flags |= NPC_FLAG_DIRTY_SHADOW;
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240F14_B21454)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(NPC_Whale);

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        switch (script->functionTemp[0]) {
            case 0:
                script->functionTemp[2] = 0;
                script->functionTemp[1] = 90;
                npc->pos.x = 158.0f;
                npc->pos.y = -50.0f;
                npc->pos.z = -38.0f;
                break;
            case 1:
                script->functionTemp[2] = 10;
                script->functionTemp[1] = 200;
                npc->pos.x = -442.0f;
                npc->pos.y = -50.0f;
                npc->pos.z = -38.0f;
                break;
        }
    }

    switch (script->functionTemp[2]) {
        case 0:
            npc->curAnim = 0xB60001;
            npc->yaw -= 1.0f;
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 1;
                script->functionTemp[1] = 90;
            }
            break;
        case 1:
            npc->yaw -= 1.0f;
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[2] = 2;
                script->functionTemp[1] = 120;
            }
            break;
        case 2:
            npc->pos.x -= 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                return ApiStatus_DONE2;
            }
            break;
        case 10:
            npc->yaw = 90.0f;
            npc->pos.x += 3.0f;
            script->functionTemp[1]--;
            if (script->functionTemp[1] <= 0) {
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(func_80241134_B21674) {
    Npc* npc = get_npc_safe(NPC_JrTroopa);
    f32 x = npc->pos.x;
    f32 y = npc->pos.y;
    f32 z = npc->pos.z - 20.0f;

    if (y < 0.0f) {
        fx_rising_bubble(0, x, y, z, 0.0f);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(D_80242D90_B232D0) = {
    Call(N(func_80240CF8_B21238), LVar0)
    Return
    End
};

EvtScript N(D_80242DB0_B232F0) = {
    Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    IfEq(LVar0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Else
        Call(SetCamSpeed, CAM_DEFAULT, 1)
    EndIf
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, 1)
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar0, -300)
        Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Else
        Set(LVar3, LVar0)
        Sub(LVar3, -300)
        Call(GetNpcPos, NPC_Whale, LVar0, LVar1, LVar2)
        Sub(LVar0, LVar3)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EndIf
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(D_80242FA8_B234E8) = {
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 310)
        Call(SetPanTarget, CAM_DEFAULT, 0, 0, 310)
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.5))
        Call(SetCamPosA, CAM_DEFAULT, Float(5.0), Float(0.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Wait(60)
        Call(SetPanTarget, CAM_DEFAULT, 180, 0, 0)
        Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.5))
        Call(SetCamPosA, CAM_DEFAULT, Float(0.0), Float(0.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.4))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Set(LVar0, 0)
    ExecGetTID(N(D_80242D90_B232D0), LVar3)
    Set(LVar0, 1)
    ExecGetTID(N(D_80242D90_B232D0), LVar4)
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Set(LVar0, 2)
        ExecGetTID(N(D_80242D90_B232D0), LVar5)
    EndIf
    Call(N(func_80240F14_B21454), 1)
    KillThread(LVar3)
    KillThread(LVar4)
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        KillThread(LVar5)
    EndIf
    Wait(1)
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Call(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
        Call(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        Call(NpcMoveTo, NPC_Kolorado_02, LVar0, LVar2, 10)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Thrown)
        Call(SetNpcJumpscale, NPC_Kolorado_02, Float(1.0))
        Call(PlaySoundAtNpc, NPC_Kolorado_02, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Kolorado_02, 224, 0, 20, 20)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        Call(NpcMoveTo, NPC_Kolorado_02, 290, 20, 20)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Idle)
        Call(SetNpcFlagBits, NPC_Kolorado_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(InterpNpcYaw, NPC_Kolorado_02, 270, 0)
    EndIf
    Call(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    Call(PlayerMoveTo, LVar0, LVar2, 15)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, 224, 0, 20, 20)
    Call(SetPlayerAnimation, ANIM_Mario1_Walk)
    Call(PlayerMoveTo, 260, 20, 15)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 20)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Call(NpcJump0, NPC_PARTNER, 224, 0, 20, 20)
    Call(PartnerIsFlying, LVar0)
    IfEq(LVar0, FALSE)
        Call(EnablePartnerAI)
        Wait(10)
        Call(DisablePartnerAI, 0)
    EndIf
    Call(NpcMoveTo, NPC_PARTNER, 230, 20, 10)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_TalkSad)
    Call(SetNpcJumpscale, NPC_Whale, 0)
    Call(NpcJump0, NPC_Whale, 158, -10, -38, 20)
    Call(InterpPlayerYaw, 270, 0)
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_CH5_0000)
    Call(SetMusic, 0, SONG_YOSHIS_VILLAGE, 0, VOL_LEVEL_FULL)
    IfLt(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        Call(AdjustCam, CAM_DEFAULT, Float(5.0), 0, 300, 15, Float(-6.0))
        Call(InterpNpcYaw, NPC_Kolorado_02, 90, 0)
        Wait(20)
        Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 1, MSG_CH5_0001)
        Wait(5)
        Call(InterpNpcYaw, NPC_Kolorado_02, 270, 4)
        Wait(10)
        Call(InterpNpcYaw, NPC_Kolorado_02, 90, 4)
        Wait(15)
        Thread
            Call(PlaySoundAtNpc, NPC_Kolorado_02, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            Call(GetNpcPos, NPC_Kolorado_02, LVar0, LVar1, LVar2)
            Call(NpcJump0, NPC_Kolorado_02, LVar0, LVar1, LVar2, 15)
            Wait(25)
            Call(NpcFacePlayer, NPC_Kolorado_02, 4)
        EndThread
        Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 5, MSG_CH5_0002)
        Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_Idle)
        Call(SetNpcSpeed, NPC_Kolorado_02, Float(6.0))
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        Call(NpcMoveTo, NPC_Kolorado_02, 330, 190, 0)
        Call(SetNpcPos, NPC_Kolorado_02, NPC_DISPOSE_LOCATION)
        Set(GB_StoryProgress, STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
        SetF(LVar9, Float(4.0))
    Else
        SetF(LVar9, Float(1.0))
    EndIf
    Exec(N(D_80245860_B25DA0))
    Call(DisablePlayerPhysics, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Call(ResetCam, CAM_DEFAULT, LVar9)
    Return
    End
};

EvtScript N(D_802437C4_B23D04) = {
    Label(0)
    Call(GetNpcYaw, NPC_Whale, LVar0)
    Call(InterpPlayerYaw, LVar0, 0)
    Call(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado_01) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 250, 0, 200)
    Call(SetPanTarget, CAM_DEFAULT, 250, 0, 200)
    Call(SetCamPosA, CAM_DEFAULT, Float(20.0), Float(0.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Exec(N(D_80242FA8_B234E8))
    Return
    End
};

Vec3f N(D_802438E4_B23E24)[] = {
    {  290.0,     0.0,   20.0 },
    {  245.0,     6.0,  -35.0 },
    {  190.0,    10.0,  -50.0 },
};

EvtScript N(EVS_NpcInteract_Kolorado_01) = {
    Call(DisablePlayerPhysics, TRUE)
    Call(InterpPlayerYaw, 270, 0)
    Call(SpeakToPlayer, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_CH5_0003)
    Call(ShowChoice, MSG_Choice_0010)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Whale, ANIM_Kolorado_Walk, ANIM_Kolorado_Still, 5, MSG_CH5_0005)
        Call(DisablePlayerPhysics, FALSE)
        Return
    EndIf
    Call(EndSpeech, NPC_SELF, -1, -1, 5)
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        Call(NpcFacePlayer, NPC_Kolorado_02, 0)
    EndIf
    Call(SetNpcJumpscale, NPC_SELF, 0)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, 158, -50, -38, 20)
    Set(LVar0, 0)
    Exec(N(D_80242DB0_B232F0))
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(0.5))
    Call(PlayerJump, LVar0, LVar1, LVar2, 20)
    Call(func_80240B4C_B2108C, 0, LVar0, LVar1, LVar2)
    Call(PlayerMoveTo, LVar0, LVar2, 10)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Thread
        Call(N(func_80240CF8_B21238), 0)
    EndThread
    Call(NpcMoveTo, NPC_PARTNER, LVar3, LVar5, 20)
    Call(func_80240B4C_B2108C, 3, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 18)
    Call(func_80240B4C_B2108C, 1, LVar0, LVar1, LVar2)
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 18)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Thread
        Call(N(func_80240CF8_B21238), 1)
    EndThread
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Walk)
        Call(LoadPath, 20, Ref(N(D_802438E4_B23E24)), ARRAY_COUNT(N(D_802438E4_B23E24)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Kolorado_02, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(func_80240B4C_B2108C, 2, LVar0, LVar1, LVar2)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Thrown)
        Call(SetNpcJumpscale, NPC_Kolorado_02, Float(0.5))
        Call(PlaySoundAtNpc, NPC_Kolorado_02, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Kolorado_02, LVar0, LVar1, LVar2, 20)
        Call(SetNpcAnimation, NPC_Kolorado_02, ANIM_Kolorado_Idle)
        Call(InterpNpcYaw, NPC_Kolorado_02, 90, 0)
        Thread
            Call(N(func_80240CF8_B21238), 2)
        EndThread
        Call(SpeakToPlayer, NPC_Kolorado_02, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0007)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_MAC01_Defeated_JrTroopa4, TRUE)
            Goto(90)
        EndIf
        Call(SetNpcVar, NPC_JrTroopa, 0, 1)
        Loop(0)
            Call(GetNpcVar, NPC_JrTroopa, 0, LVar0)
            Wait(1)
            IfNe(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
        Exec(N(D_802437C4_B23D04))
        Call(N(func_80240F14_B21454), 0)
        Call(EnableGroup, MODEL_kujira, FALSE)
    Else
        Label(90)
        Exec(N(D_802437C4_B23D04))
        Call(N(func_80240F14_B21454), 0)
        Call(EnableGroup, MODEL_kujira, FALSE)
        Call(GotoMap, Ref("mac_06"), mac_06_ENTRY_1)
        Wait(100)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado_01) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_NO_SPRITE, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Still)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_00_ENTRY_0)
        Call(DisablePlayerPhysics, TRUE)
        Call(InterpPlayerYaw, 90, 0)
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcYaw, NPC_PARTNER, 90)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado_01)))
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado_01)))
    Else
        Call(SetNpcPos, NPC_SELF, 158, -10, -38)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado_01)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado_02) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0006)
    ExecWait(N(EVS_LetterPrompt_Kolorado))
    ExecWait(N(EVS_LetterReward_Kolorado))
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado_02) = {
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        Call(SetNpcPos, NPC_SELF, 290, 0, 20)
        Call(InterpNpcYaw, NPC_SELF, 270, 1)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado_02)))
    EndIf
    Return
    End
};

EvtScript N(D_802441C8_B24708) = {
    Loop(0)
        Call(PlayerFaceNpc, NPC_JrTroopa, FALSE)
        Call(NpcFaceNpc, NPC_Kolorado_02, NPC_JrTroopa, 0)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_JrTroopa, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Wait(1)
        Goto(0)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, 0xFFFFFFFF, 0xFFFFFFFF, 5, MSG_CH5_0008)
    ExecGetTID(N(D_802441C8_B24708), LVar9)
    Call(SetMusic, 0, SONG_JR_TROOPA_THEME, 0, VOL_LEVEL_FULL)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_LOOP_JR_TROOPA_SWIM, SOUND_SPACE_DEFAULT)
    Thread
        Call(func_80241134_B21674)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 85, 0, 320)
    Call(SetPanTarget, CAM_DEFAULT, 85, 0, 320)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(22.5), Float(-12.5))
    Call(SetCamPosA, CAM_DEFAULT, Float(23.0), Float(0.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0))
    Call(NpcMoveTo, NPC_SELF, 80, 90, 0)
    Call(SetPanTarget, CAM_DEFAULT, 250, 0, 90)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(14.5), Float(-10.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.7))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(StopSound, SOUND_LOOP_JR_TROOPA_SWIM)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SPLASH, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, 250, 0, 90, 20)
    KillThread(LVar9)
    Thread
        Wait(15)
        Call(SetSelfVar, 0, 2)
    EndThread
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_OutOfBreath)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_OutOfBreath, 5, MSG_CH5_0009)
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_OutOfBreath, 0, MSG_CH5_000A)
    Wait(20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Panic)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20)
    Call(NpcJump0, NPC_SELF, 250, 0, 90, 10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Panic, ANIM_JrTroopa_Panic, 0, MSG_CH5_000B)
    Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Charge)
    Wait(10)
    Thread
        Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_ChargeArmsUp, ANIM_JrTroopa_Charge, 0, MSG_CH5_000C)
        Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_ChargeTripped)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, 85, 0, 320)
    Call(SetPanTarget, CAM_DEFAULT, 85, 0, 320)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-10.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(24.0), Float(0.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.5))
    Call(NpcJump0, NPC_SELF, 80, -50, 90, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_JR_TROOPA_SPLASH, SOUND_SPACE_DEFAULT)
    Call(SetNpcRotation, NPC_SELF, 0, -20, 0)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_LOOP_JR_TROOPA_SWIM, SOUND_SPACE_DEFAULT)
    Thread
        Call(SetNpcSpeed, NPC_SELF, Float(2.0))
        Call(NpcMoveTo, NPC_SELF, -555, -32, 0)
    EndThread
    Wait(100)
    Call(GotoMap, Ref("mac_06"), mac_06_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    IfEq(GF_MAC01_Defeated_JrTroopa4, FALSE)
        Call(SetNpcPos, NPC_SELF, -530, -50, 20)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa)))
    EndIf
    Return
    End
};

NpcData N(NpcData_Characters)[] = {
    {
        .id = NPC_Whale,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado_01),
        .settings = &N(NpcSettings_Kolorado_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Whale,
    },
    {
        .id = NPC_Kolorado_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado_02),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_JrTroopa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_JrTroopa),
        .settings = &N(NpcSettings_JrTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = NO_DROPS,
        .animations = JR_TROOPA_ANIMS,
    },
};

NpcData N(NpcData_HeartPlant_01) = {
    .id = NPC_HeartPlant_01,
    .pos = { 455.0f, 0.0f, 115.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_02) = {
    .id = NPC_HeartPlant_02,
    .pos = { 167.0f, 0.0f, 404.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_03) = {
    .id = NPC_HeartPlant_03,
    .pos = { 90.0f, 0.0f, 316.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_04) = {
    .id = NPC_HeartPlant_04,
    .pos = { 424.0f, 0.0f, 182.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_05) = {
    .id = NPC_HeartPlant_05,
    .pos = { 143.0f, 0.0f, 260.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Characters)),
    NPC_GROUP(N(NpcData_HeartPlant_01)),
    NPC_GROUP(N(NpcData_HeartPlant_02)),
    NPC_GROUP(N(NpcData_HeartPlant_03)),
    NPC_GROUP(N(NpcData_HeartPlant_04)),
    NPC_GROUP(N(NpcData_HeartPlant_05)),
    {}
};
