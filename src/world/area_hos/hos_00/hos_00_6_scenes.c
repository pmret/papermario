#include "hos_00.h"
#include "sprite/player.h"

#include "world/common/complete/GiveReward.inc.c"

Vec3f N(TwinkArrivePath)[] = {
    {    0.0,     0.0,    2.0 },
    {   73.0,    -6.0,    2.0 },
    {  106.0,    32.0,    2.0 },
    {   70.0,    43.0,    2.0 },
    {   30.0,    12.0,    2.0 },
    {  -17.0,   -19.0,    2.0 },
    {  -35.0,    29.0,    2.0 },
    {  -20.0,    43.0,    2.0 },
    {  -11.0,    39.0,    2.0 },
    {    0.0,    -1.0,    0.0 },
};

Vec3f N(FlightPath_Magikoopa)[] = {
    {   15.0,   174.0,  -45.0 },
    { -157.0,    92.0,  -44.0 },
    { -371.0,   103.0,  -45.0 },
    { -350.0,    75.0,  -45.0 },
    { -250.0,    40.0,  -45.0 },
};

Vec3f N(TwinkDepartPath1)[] = {
    {    0.0,     0.0,    0.0 },
    {  -60.0,     3.0,  -11.0 },
    {  -55.0,    13.0,    0.0 },
    {    4.0,    40.0,   -5.0 },
    {   23.0,    35.0,  -10.0 },
    {   63.0,    25.0,  -20.0 },
    {   94.0,    30.0,  -40.0 },
    {  134.0,   250.0,  -80.0 },
};

Vec3f N(TwinkReturnPath)[] = {
    {  -72.0,   318.0,  -80.0 },
    { -127.0,   153.0,  -60.0 },
    { -174.0,   114.0,  -44.0 },
    { -243.0,    90.0,  -45.0 },
    { -268.0,    50.0,  -46.0 },
    { -174.0,    10.0,  -43.0 },
};

Vec3f N(TwinkDepartPath2)[] = {
    {    0.0,     0.0,    0.0 },
    {  -30.0,     3.0,  -11.0 },
    {  -55.0,    13.0,    0.0 },
    {  -73.0,    20.0,   -5.0 },
    { -103.0,    40.0,    0.0 },
    { -143.0,    60.0,    0.0 },
    { -173.0,    50.0,   26.0 },
    { -126.0,    35.0,   16.0 },
    { 1111.0,   570.0, -527.0 },
};

API_CALLABLE(N(EnableActionCommands)) {
    gPlayerData.hasActionCommands = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UnusedTrigFunc)) {
    Bytecode* args = script->ptrReadPos;
    f32 magnitude = evt_get_float_variable(script, *args++);
    f32 angle = evt_get_float_variable(script, *args++);

    evt_set_float_variable(script, *args++, magnitude * sin_deg(angle));
    return ApiStatus_DONE2;
}

f32 N(LastTwinkPosX) = 0;
f32 N(LastTwinkPosZ) = 0;

API_CALLABLE(N(HavePartyFaceTwink)) {
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    Npc* npc = get_npc_unsafe(NPC_Twink);

    partner->yaw = atan2(partner->pos.x, partner->pos.z, npc->pos.x, npc->pos.z);
    gPlayerStatus.targetYaw = atan2(gPlayerStatus.pos.x, gPlayerStatus.pos.z, npc->pos.x, npc->pos.z);
    npc->yaw = atan2(N(LastTwinkPosX), N(LastTwinkPosZ), npc->pos.x, npc->pos.z);
    N(LastTwinkPosX) = npc->pos.x;
    N(LastTwinkPosZ) = npc->pos.z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateMagikoopaAngles)) {
    Npc* npc = get_npc_unsafe(NPC_FlyingMagikoopa);

    if (npc->yaw < 180.0f) {
        script->varTable[0] = npc->pos.x - 40.0f;
        script->varTable[1] = npc->pos.y + 10.0f;
        script->varTable[2] = npc->pos.z;
    } else {
        script->varTable[0] = npc->pos.x + 40.0f;
        script->varTable[1] = npc->pos.y + 10.0f;
        script->varTable[2] = npc->pos.z;
    }
    npc->yaw = atan2(script->varTable[6], script->varTable[8], npc->pos.x, npc->pos.z);
    return ApiStatus_DONE2;
}

#include "world/common/DisableCameraLeadingPlayer.inc.c"

API_CALLABLE(N(AddOffsetForCamPos)) {
    s32 baseX = script->varTable[0];
    s32 baseZ = script->varTable[2];

    script->varTable[0] = baseX + (sin_deg(310.0f) * 100.0f);
    script->varTable[1] = baseZ - (cos_deg(310.0f) * 100.0f);
    script->varTable[2] = baseX + (sin_deg(130.0f) * 100.0f);
    script->varTable[3] = baseZ - (cos_deg(130.0f) * 100.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateFacingMagikoopa) = {
    EVT_CALL(GetNpcPos, NPC_FlyingMagikoopa, LVar6, LVar7, LVar8)
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_FlyingMagikoopa, LVar3, LVar4, LVar5)
        EVT_SET(LVar9, LVar3)
        EVT_SET(LVarA, LVar4)
        EVT_SET(LVarB, LVar5)
        EVT_SUB(LVar3, LVar6)
        EVT_SUB(LVar4, LVar7)
        EVT_SUB(LVar5, LVar8)
        EVT_CALL(N(UpdateMagikoopaAngles))
        EVT_SET(LVar6, LVar9)
        EVT_SET(LVar7, LVarA)
        EVT_SET(LVar8, LVarB)
        EVT_CALL(PlayerFaceNpc, NPC_FlyingMagikoopa, FALSE)
        EVT_CALL(GetAngleBetweenNPCs, NPC_Twink, NPC_FlyingMagikoopa, LVar0)
        EVT_CALL(InterpNpcYaw, NPC_Twink, LVar0, 0)
        EVT_CALL(GetAngleBetweenNPCs, NPC_PARTNER, NPC_FlyingMagikoopa, LVar0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ConfusedTwinkLookingAround) = {
    EVT_LOOP(0)
        EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
        EVT_WAIT(10 * DT)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

// add an offset to Twink's position to counter the one from his sprite
EvtScript N(EVS_Twink_CancelHoverOffset) = {
    EVT_LOOP(0)
        EVT_LOOP(5)
            EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            EVT_WAIT(3)
        EVT_END_LOOP
        EVT_WAIT(3)
        EVT_LOOP(5)
            EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            EVT_WAIT(3)
        EVT_END_LOOP
        EVT_WAIT(3)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Twink_CarryItem) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetItemPos, MV_LuckyStarItem, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_MeetingTwink) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, -100)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 2)
    EVT_THREAD
        EVT_ADD(LVar0, -20)
        EVT_CALL(PlayerMoveTo, LVar0, LVar2, 10 * DT)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_Twink, 50, 180, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Twink, 0)
    EVT_ADD(LVar0, -10)
    EVT_CALL(NpcJump0, NPC_Twink, LVar0, 20, LVar2, 15 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_VacantStare)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Cringe)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Disappointed)
        EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(0.6))
        EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -100)
        EVT_CALL(NpcJump0, NPC_Twink, LVar0, 10, LVar2, 20 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar3, 360)
        EVT_LOOP(3)
            EVT_LABEL(22)
            EVT_WAIT(1)
            EVT_SUB(LVar3, 45)
            EVT_IF_GT(LVar3, 0)
                EVT_CALL(SetNpcRotation, NPC_Twink, 0, LVar3, 0)
                EVT_IF_EQ(LVar3, 270)
                    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
                EVT_END_IF
                EVT_IF_EQ(LVar3, 90)
                    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Disappointed)
                EVT_END_IF
                EVT_GOTO(22)
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_Twink, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(ShowMessageAtScreenPos, MSG_HOS_000D, 160, 40)
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    EVT_CALL(NpcFacePlayer, NPC_Twink, 0)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Shout, ANIM_Twink_Idle, 0, MSG_HOS_000E)
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcSpeed, NPC_Twink, EVT_FLOAT(3.0 / DT))
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_CALL(NpcMoveTo, NPC_Twink, LVar0, LVar2, 0)
    EVT_CALL(ShowEmote, NPC_Twink, EMOTE_SHOCK, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_ShoutJoy)
    EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(1.0))
    EVT_LOOP(2)
        EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 15 * DT)
    EVT_END_LOOP
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 25)
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_000F)
    EVT_WAIT(5 * DT)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 70 * DT, EVT_PTR(N(TwinkArrivePath)), ARRAY_COUNT(N(TwinkArrivePath)), EASING_LINEAR)
    EVT_LABEL(1)
        EVT_CALL(GetNextPathPos)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_ADDF(LVar3, LVar6)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_CALL(N(HavePartyFaceTwink))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0010)
    EVT_CALL(SetNpcYaw, NPC_Twink, 270)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
    EVT_CALL(SpeakToPlayer, NPC_Twink, -1, -1, 5, MSG_HOS_0011)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(MakeItemEntity, ITEM_LUCKY_STAR, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_LuckyStarItem, LVar0)
    EVT_EXEC_GET_TID(N(EVS_Twink_CancelHoverOffset), LVar8)
    EVT_EXEC_GET_TID(N(EVS_Twink_CarryItem), LVar9)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Wink)
    EVT_CALL(ContinueSpeech, NPC_Twink, -1, -1, 512, MSG_HOS_0012)
    EVT_CALL(GetPlayerPos, LVar5, LVar3, LVar4)
    EVT_ADD(LVar5, -30)
    EVT_CALL(NpcMoveTo, NPC_Twink, LVar5, LVar4, 15 * DT)
    EVT_KILL_THREAD(LVar9)
    EVT_KILL_THREAD(LVar8)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_SET(LVar4, LVar1)
        EVT_ADD(LVar4, 30)
        EVT_SET(LVar3, LVar0)
        EVT_CALL(MakeLerp, LVar1, LVar4, 7, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemPos, MV_LuckyStarItem, LVar3, LVar0, LVar2)
            EVT_WAIT(1)
            EVT_ADD(LVar3, 2)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetPlayerPos, LVar5, LVar6, LVar7)
        EVT_ADD(LVar6, 38)
        EVT_CALL(MakeLerp, LVar0, LVar6, 7, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemPos, MV_LuckyStarItem, LVar3, LVar0, LVar2)
            EVT_WAIT(1)
            EVT_ADD(LVar3, 2)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, MV_LuckyStarItem)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_TossItem)
    EVT_WAIT(11)
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Pleased)
    EVT_SET(LVar0, 7)
    EVT_SET(LVar1, 4)
    EVT_CALL(ShowGotItem, LVar0, TRUE, 0)
    EVT_CALL(AddKeyItem, LVar0)
    EVT_CALL(N(EnableActionCommands))
    EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0013)
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0014)
        EVT_CALL(ShowChoice, MSG_Choice_0013)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(ContinueSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0015)
        EVT_ELSE
            EVT_GOTO(15)
        EVT_END_IF
    EVT_ELSE
        EVT_LABEL(15)
        EVT_CALL(ContinueSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0016)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_0017)
        EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0018)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
        EVT_CALL(SetNpcVar, NPC_Twink, 0, 1)
        EVT_LOOP(0)
            EVT_CALL(GetNpcVar, NPC_Twink, 0, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_002F)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_0030)
    EVT_WAIT(20 * DT)
    EVT_EXEC(N(EVS_PlayKammyKoopaSong))
    EVT_CALL(ShowMessageAtScreenPos, MSG_HOS_0031, 320, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -250)
        EVT_DIV(LVar0, 2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, 53, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.4 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(EVS_UpdateFacingMagikoopa), LVarA)
    EVT_CALL(LoadPath, 67 * DT, EVT_PTR(N(FlightPath_Magikoopa)), ARRAY_COUNT(N(FlightPath_Magikoopa)), EASING_LINEAR)
    EVT_LABEL(2)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_FlyingMagikoopa, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_KILL_THREAD(LVarA)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_LOOP(10)
                EVT_CALL(GetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 1)
                EVT_CALL(SetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                EVT_WAIT(2)
            EVT_END_LOOP
            EVT_WAIT(3)
            EVT_LOOP(10)
                EVT_CALL(GetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, -1)
                EVT_CALL(SetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                EVT_WAIT(2)
            EVT_END_LOOP
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetNpcAnimation, NPC_FlyingMagikoopa, ANIM_FlyingMagikoopa_Anim00)
    EVT_LOOP(3)
        EVT_CALL(SetNpcRotation, NPC_FlyingMagikoopa, 0, 0, 10)
        EVT_WAIT(1)
        EVT_CALL(SetNpcRotation, NPC_FlyingMagikoopa, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_EXEC_GET_TID(N(EVS_ConfusedTwinkLookingAround), LVarA)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Still, 5, MSG_HOS_0032)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(260.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(13.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SpeakToPlayer, NPC_FlyingMagikoopa, ANIM_FlyingMagikoopa_Anim09, ANIM_FlyingMagikoopa_Anim00, 512, MSG_HOS_0033)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -250)
    EVT_DIV(LVar0, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcVar, NPC_FlyingMagikoopa, 0, 1)
    EVT_CALL(EnablePartnerAI)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_TwinkDeparts) = {
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, TRUE)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar3, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0034)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 15 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0035)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(700.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.3 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    EVT_CALL(LoadPath, 85 * DT, EVT_PTR(N(TwinkDepartPath1)), ARRAY_COUNT(N(TwinkDepartPath1)), EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(GetNextPathPos)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_ADDF(LVar3, LVar6)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_CALL(N(HavePartyFaceTwink))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(45 * DT)
    EVT_THREAD
        EVT_CALL(LoadPath, 60 * DT, EVT_PTR(N(TwinkReturnPath)), ARRAY_COUNT(N(TwinkReturnPath)), EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            EVT_CALL(N(HavePartyFaceTwink))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(GetNpcPos, NPC_Twink, LVar3, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_DIV(LVar0, 2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-8.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0036)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
        EVT_CALL(LoadPath, 120 * DT, EVT_PTR(N(TwinkDepartPath2)), ARRAY_COUNT(N(TwinkDepartPath2)), EASING_QUADRATIC_IN)
        EVT_LABEL(2)
            EVT_CALL(GetNextPathPos)
            EVT_ADDF(LVar1, LVar4)
            EVT_ADDF(LVar2, LVar5)
            EVT_ADDF(LVar3, LVar6)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            EVT_CALL(N(HavePartyFaceTwink))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(2)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.5), EVT_FLOAT(-10.0))
    EVT_CALL(N(AddOffsetForCamPos))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_Twink, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(10)
        EVT_ADDF(LVar0, EVT_FLOAT(36.0))
        EVT_CALL(SetNpcRotation, NPC_Twink, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcFlagBits, NPC_Twink, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    EVT_WAIT(120 * DT)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(13.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_0037)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_THREAD
        EVT_SET(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
