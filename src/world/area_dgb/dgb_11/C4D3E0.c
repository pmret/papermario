#include "dgb_11.h"
#include "entity.h"
#include "message_ids.h"

extern s16 Entity_ScriptSpring_AnimLaunch[];

EntryList N(entryList) = {
    { 450.0f,   0.0f,  -40.0f,   0.0f },
    { 500.0f, 180.0f, -100.0f, 180.0f },
    { 500.0f, 180.0f, -250.0f, 180.0f },
    { 375.0f, 180.0f, -250.0f, 180.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_11 },
};

EvtScript N(802400D0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_168)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitSingleDoor_80240170) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 11)
    EVT_SET(LVar2, 21)
    EVT_SET(LVar3, -1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), 3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterSingleDoor_80240224) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(UseDoorSounds, 0)
            EVT_SET(LVar2, 21)
            EVT_SET(LVar3, -1)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_CALL(UseSettingsFrom, 0, 500, 0, -100)
            EVT_CALL(SetPanTarget, 0, 500, 0, -100)
            EVT_SET(LVar3, 1)
        EVT_CASE_EQ(2)
            EVT_CALL(UseSettingsFrom, 0, 500, 75, -250)
            EVT_CALL(SetPanTarget, 0, 500, 75, -250)
            EVT_SET(LVar3, 75)
        EVT_CASE_EQ(3)
            EVT_CALL(SetZoneEnabled, 5, 0)
            EVT_CALL(UseSettingsFrom, 0, 375, 0, -175)
            EVT_CALL(SetPanTarget, 0, 375, 0, -175)
            EVT_SET(AreaFlag(2), 1)
            EVT_SET(LVar3, 1)
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterpPlayerYaw, 180, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LE(LVar1, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802400D0))
    EVT_BIND_TRIGGER(N(exitSingleDoor_80240170), TRIGGER_WALL_PRESS_A, 11, 1, 0)
    EVT_EXEC(N(enterSingleDoor_80240224))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_56C) = {
    0x00000000,
};

EvtScript N(80240570) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GE(LVar1, LVar3)
        EVT_SET(LVar1, LVar3)
    EVT_END_IF
    EVT_CALL(SetCamTarget, 0, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240600) = {
    EVT_CALL(PlayerJump, 375, 270, -250, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024062C) = {
    EVT_IF_EQ(AreaFlag(3), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AreaFlag(3), 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetZoneEnabled, 5, 0)
    EVT_IF_EQ(AreaFlag(2), 0)
        EVT_IF_EQ(GF_DGB10_BoardedFloor3, 0)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, 3)
            EVT_WAIT(1)
            EVT_SET(LVar3, 500)
            EVT_EXEC_GET_TID(N(80240570), LVarA)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_EXEC_GET_TID(N(80240600), LVarB)
            EVT_LOOP(0)
                EVT_WAIT(1)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_GE(LVar1, 165)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(SetPlayerPos, LVar0, 165, LVar2)
            EVT_KILL_THREAD(LVarB)
            EVT_CALL(SetPlayerAnimation, 524309)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.0))
            EVT_CALL(PlayerJump1, 375, 25, -250, 10)
            EVT_CALL(N(func_80240000_C4D3E0))
            EVT_CALL(PlaySoundAtPlayer, 8326, 0)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_CALL(PlayerJump, 375, 0, -175, 15)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(SetPlayerActionState, 0)
            EVT_WAIT(2)
            EVT_CALL(SetZoneEnabled, 5, 1)
            EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(AreaFlag(3), 0)
        EVT_ELSE
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerActionState, 3)
            EVT_WAIT(1)
            EVT_THREAD
                EVT_WAIT(8)
                EVT_CALL(GotoMap, EVT_PTR("dgb_10"), 1)
                EVT_WAIT(100)
            EVT_END_THREAD
            EVT_SET(LVar3, 500)
            EVT_EXEC_GET_TID(N(80240570), LVarA)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
            EVT_CALL(PlayerJump, 375, 270, -250, 20)
            EVT_SET(AreaFlag(3), 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetPlayerActionState, 3)
        EVT_WAIT(1)
        EVT_SET(LVar3, 25)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, 375, 0, -175, 15)
        EVT_SET(AreaFlag(2), 0)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetPlayerActionState, 0)
        EVT_WAIT(2)
        EVT_CALL(SetZoneEnabled, 5, 1)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_SET(AreaFlag(3), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_D_DOWN_JUMP, 250, 75, -100, 17, GF_DGB11_Item_DDownJump)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 375, 0, -250, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(8024062C)))
    EVT_SET(MapVar(0), LVar0)
    EVT_RETURN
    EVT_END
};

ApiStatus N(func_80240000_C4D3E0)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(evt_get_variable(NULL, 0xFD050F80));

    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }

    play_model_animation(entity->virtualModelIndex, Entity_ScriptSpring_AnimLaunch);

    return ApiStatus_DONE2;
}
