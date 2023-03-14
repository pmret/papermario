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
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_06_ENTRY_0)
            EVT_EXEC(N(EVS_Scene_FallIntoCell))
        EVT_CASE_EQ(trd_06_ENTRY_1)
            EVT_SET(LVar2, MODEL_o93)
            EVT_SET(LVar3, MODEL_o94)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_LE(trd_06_ENTRY_3)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INACTIVE, TRUE)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
            EVT_EXEC(N(EVS_Scene_ImprisonedKoopaBros))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_CellWall) = {
    .pos = { 160.0f, 0.0f, 160.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BombWall_Cell) = {
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, TRUE)
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 19, 19, 1, 10, 30)
    EVT_CALL(SetGroupVisibility, MODEL_ana, MODEL_GROUP_VISIBLE)
    EVT_LOOP(10)
        EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_VISIBLE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GF_TRD06_BombedWall, TRUE)
    EVT_WAIT(60 * DT)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 110)
            EVT_IF_LT(LVar2, 140)
                EVT_WAIT(25 * DT)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
                EVT_CALL(PlayerMoveTo, 110, 140, 0)
                EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_03, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
                EVT_CALL(SetNpcFlagBits, NPC_Bobomb_04, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Walk)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.5 / DT))
#if !VERSION_PAL
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 156, 156, 0)
#endif
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E2)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E3)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_CHANGE_PARTNER | PS_FLAG_NO_PARTNER_USAGE, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar2, 200)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_GT(LVar0, -120)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(SetNpcVar, NPC_Jailer_KoopaTroopa, 0, 1)
    EVT_END_THREAD
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_suimen, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        EVT_ADD(LVar0, 100)
        EVT_SUB(LVar1, 100)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_KOOPA_BROS)
            EVT_CALL(EnableModel, MODEL_o97, FALSE)
            EVT_CALL(EnableModel, MODEL_o98, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o109, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
        EVT_SET(GF_TRD06_BombedWall, TRUE)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_DEFEATED_KOOPA_BROS)
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(NpcGroup_Prisoners)))
            EVT_CALL(SetGroupVisibility, MODEL_g27, MODEL_GROUP_HIDDEN)
        EVT_CASE_LT(STORY_CH1_DEFEATED_JR_TROOPA)
            EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(NpcGroup_KoopaBros)))
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_04_5)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0) //@bug unterminated switch
    EVT_IF_LE(LVar0, trd_06_ENTRY_1)
        EVT_IF_EQ(GF_TRD06_BombedWall, FALSE)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BombWall_Cell)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_CellWall)), 1, 0)
            EVT_CALL(SetGroupVisibility, MODEL_ana, MODEL_GROUP_HIDDEN)
        EVT_ELSE
            EVT_CALL(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttse, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_ana, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_CALL(EnableTexPanning, MODEL_suimen, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
