#include "trd_06.h"
#include "effects.h"

extern EvtScript N(EVS_Main);
extern NpcGroupList N(NpcGroup_Prisoners);
extern NpcGroupList N(NpcGroup_KoopaBros);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_FallIntoCell);
extern EvtScript N(EVS_Scene_ImprisonedKoopaBros);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitDoors_trd_04_5) = EVT_EXIT_DOUBLE_DOOR(trd_06_ENTRY_1, "trd_04", trd_04_ENTRY_5,
    COLLIDER_ttw, MODEL_o93, MODEL_o94);

MAP_RODATA_PAD(1,unk); // fixed if map uses subalign 16

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_06_ENTRY_0)
            Exec(N(EVS_Scene_FallIntoCell))
        CaseEq(trd_06_ENTRY_1)
            Set(LVar2, MODEL_o93)
            Set(LVar3, MODEL_o94)
            ExecWait(EnterDoubleDoor)
        CaseLe(trd_06_ENTRY_3)
            Call(DisablePlayerInput, TRUE)
            Call(DisablePlayerPhysics, TRUE)
            Call(DisablePartnerAI, 0)
            Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
            Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INACTIVE, TRUE)
            Call(EnableNpcShadow, NPC_PARTNER, FALSE)
            Exec(N(EVS_Scene_ImprisonedKoopaBros))
    EndSwitch
    Return
    End
};

BombTrigger N(BombPos_CellWall) = {
    .pos = { 160.0f, 0.0f, 160.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BombWall_Cell) = {
    Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, TRUE)
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 19, 19, 1, 10, 30)
    Call(SetGroupVisibility, MODEL_ana, MODEL_GROUP_VISIBLE)
    Loop(10)
        Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_VISIBLE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttse, COLLIDER_FLAGS_UPPER_MASK)
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Set(GF_TRD06_BombedWall, TRUE)
    Wait(60 * DT)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 110)
            IfLt(LVar2, 140)
                Wait(25 * DT)
                Call(SetNpcFlagBits, NPC_Bobomb_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcFlagBits, NPC_Bobomb_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcFlagBits, NPC_Bobomb_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetNpcFlagBits, NPC_Bobomb_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                Call(SetPlayerSpeed, Float(3.0))
                Call(PlayerMoveTo, 110, 140, 0)
                Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
                Call(SetNpcFlagBits, NPC_Bobomb_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                Call(SetNpcFlagBits, NPC_Bobomb_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                Call(SetNpcFlagBits, NPC_Bobomb_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                Call(SetNpcFlagBits, NPC_Bobomb_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EndIf
        EndIf
    EndThread
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Walk)
    Call(SetNpcSpeed, NPC_PARTNER, Float(3.5 / DT))
#if !VERSION_PAL
    Call(NpcMoveTo, NPC_PARTNER, 156, 156, 0)
#endif
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Idle)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E2)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Wait(20 * DT)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E3)
    Call(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Thread
        Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar2, 200)
            Goto(0)
        EndIf
        IfGt(LVar0, -120)
            Goto(0)
        EndIf
        Call(SetNpcVar, NPC_Jailer_KoopaTroopa, 0, 1)
    EndThread
    Unbind
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_suimen, TEX_PANNER_1)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        Add(LVar0, 100)
        Sub(LVar1, 100)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_DEFEATED_KOOPA_BROS)
            Call(EnableModel, MODEL_o97, FALSE)
            Call(EnableModel, MODEL_o98, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o109, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
        Set(GF_TRD06_BombedWall, TRUE)
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_DEFEATED_KOOPA_BROS)
            Call(MakeNpcs, TRUE, Ref(N(NpcGroup_Prisoners)))
            Call(SetGroupVisibility, MODEL_g27, MODEL_GROUP_HIDDEN)
        CaseLt(STORY_CH1_DEFEATED_JR_TROOPA)
            Call(MakeNpcs, TRUE, Ref(N(NpcGroup_KoopaBros)))
    EndSwitch
    Wait(2)
    ExecWait(N(EVS_MakeEntities))
    BindTrigger(Ref(N(EVS_ExitDoors_trd_04_5)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Call(GetEntryID, LVar0)
    Switch(LVar0) //@bug unterminated switch
    IfLe(LVar0, trd_06_ENTRY_1)
        IfEq(GF_TRD06_BombedWall, FALSE)
            BindTrigger(Ref(N(EVS_BombWall_Cell)), TRIGGER_POINT_BOMB, Ref(N(BombPos_CellWall)), 1, 0)
            Call(SetGroupVisibility, MODEL_ana, MODEL_GROUP_HIDDEN)
        Else
            Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttse, COLLIDER_FLAGS_UPPER_MASK)
        EndIf
    Else
        Call(SetGroupVisibility, MODEL_ana, MODEL_GROUP_HIDDEN)
    EndIf
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_TexPan_Water))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Call(EnableTexPanning, MODEL_suimen, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};
