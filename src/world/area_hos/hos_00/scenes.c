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
    Call(GetNpcPos, NPC_FlyingMagikoopa, LVar6, LVar7, LVar8)
    Label(0)
        Call(GetNpcPos, NPC_FlyingMagikoopa, LVar3, LVar4, LVar5)
        Set(LVar9, LVar3)
        Set(LVarA, LVar4)
        Set(LVarB, LVar5)
        Sub(LVar3, LVar6)
        Sub(LVar4, LVar7)
        Sub(LVar5, LVar8)
        Call(N(UpdateMagikoopaAngles))
        Set(LVar6, LVar9)
        Set(LVar7, LVarA)
        Set(LVar8, LVarB)
        Call(PlayerFaceNpc, NPC_FlyingMagikoopa, FALSE)
        Call(GetAngleBetweenNPCs, NPC_Twink, NPC_FlyingMagikoopa, LVar0)
        Call(InterpNpcYaw, NPC_Twink, LVar0, 0)
        Call(GetAngleBetweenNPCs, NPC_PARTNER, NPC_FlyingMagikoopa, LVar0)
        Call(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ConfusedTwinkLookingAround) = {
    Loop(0)
        Call(InterpNpcYaw, NPC_Twink, 270, 0)
        Wait(10 * DT)
        Call(InterpNpcYaw, NPC_Twink, 90, 0)
        Wait(10 * DT)
    EndLoop
    Return
    End
};

// add an offset to Twink's position to counter the one from his sprite
EvtScript N(EVS_Twink_CancelHoverOffset) = {
    Loop(0)
        Loop(5)
            Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            Wait(3)
        EndLoop
        Wait(3)
        Loop(5)
            Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            Add(LVar1, -1)
            Call(SetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
            Wait(3)
        EndLoop
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Twink_CarryItem) = {
    Loop(0)
        Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Add(LVar2, 2)
        Call(SetItemPos, MV_LuckyStarItem, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_MeetingTwink) = {
    Loop(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, -100)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(func_802CF56C, 2)
    Thread
        Add(LVar0, -20)
        Call(PlayerMoveTo, LVar0, LVar2, 10 * DT)
    EndThread
    Call(SetNpcPos, NPC_Twink, 50, 180, 0)
    Call(SetNpcJumpscale, NPC_Twink, 0)
    Add(LVar0, -10)
    Call(NpcJump0, NPC_Twink, LVar0, 20, LVar2, 15 * DT)
    Call(PlaySoundAtPlayer, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_Mario1_VacantStare)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Cringe)
    Thread
        Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Disappointed)
        Call(SetNpcJumpscale, NPC_Twink, Float(0.6))
        Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        Add(LVar0, -100)
        Call(NpcJump0, NPC_Twink, LVar0, 10, LVar2, 20 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
    EndThread
    Thread
        Set(LVar3, 360)
        Loop(3)
            Label(22)
            Wait(1)
            Sub(LVar3, 45)
            IfGt(LVar3, 0)
                Call(SetNpcRotation, NPC_Twink, 0, LVar3, 0)
                IfEq(LVar3, 270)
                    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
                EndIf
                IfEq(LVar3, 90)
                    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Disappointed)
                EndIf
                Goto(22)
            EndIf
        EndLoop
        Call(SetNpcRotation, NPC_Twink, 0, 0, 0)
    EndThread
    Call(ShowMessageAtScreenPos, MSG_HOS_000D, 160, 40)
    Call(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    Call(NpcFacePlayer, NPC_Twink, 0)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Shout, ANIM_Twink_Idle, 0, MSG_HOS_000E)
    Call(N(DisableCameraLeadingPlayer))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -20)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-8.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcSpeed, NPC_Twink, Float(3.0 / DT))
    Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(NpcMoveTo, NPC_Twink, LVar0, LVar2, 0)
    Call(ShowEmote, NPC_Twink, EMOTE_SHOCK, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_ShoutJoy)
    Call(SetNpcJumpscale, NPC_Twink, Float(1.0))
    Loop(2)
        Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_Twink, LVar0, LVar1, LVar2, 15 * DT)
    EndLoop
    Call(DisablePartnerAI, 0)
    Call(SetNpcJumpscale, NPC_PARTNER, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, 25)
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_000F)
    Wait(5 * DT)
    Call(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    Call(LoadPath, 70 * DT, Ref(N(TwinkArrivePath)), ARRAY_COUNT(N(TwinkArrivePath)), EASING_LINEAR)
    Label(1)
        Call(GetNextPathPos)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        AddF(LVar3, LVar6)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Call(N(HavePartyFaceTwink))
        Wait(1)
        IfEq(LVar0, 1)
            Goto(1)
        EndIf
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0010)
    Call(SetNpcYaw, NPC_Twink, 270)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
    Call(SpeakToPlayer, NPC_Twink, -1, -1, 5, MSG_HOS_0011)
    Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(MakeItemEntity, ITEM_LUCKY_STAR, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_LuckyStarItem, LVar0)
    ExecGetTID(N(EVS_Twink_CancelHoverOffset), LVar8)
    ExecGetTID(N(EVS_Twink_CarryItem), LVar9)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Wink)
    Call(ContinueSpeech, NPC_Twink, -1, -1, 512, MSG_HOS_0012)
    Call(GetPlayerPos, LVar5, LVar3, LVar4)
    Add(LVar5, -30)
    Call(NpcMoveTo, NPC_Twink, LVar5, LVar4, 15 * DT)
    KillThread(LVar9)
    KillThread(LVar8)
    Thread
        Call(GetNpcPos, NPC_Twink, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Set(LVar4, LVar1)
        Add(LVar4, 30)
        Set(LVar3, LVar0)
        Call(MakeLerp, LVar1, LVar4, 7, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(SetItemPos, MV_LuckyStarItem, LVar3, LVar0, LVar2)
            Wait(1)
            Add(LVar3, 2)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(GetPlayerPos, LVar5, LVar6, LVar7)
        Add(LVar6, 38)
        Call(MakeLerp, LVar0, LVar6, 7, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetItemPos, MV_LuckyStarItem, LVar3, LVar0, LVar2)
            Wait(1)
            Add(LVar3, 2)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(RemoveItemEntity, MV_LuckyStarItem)
    EndThread
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_TossItem)
    Wait(11)
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Pleased)
    Set(LVar0, 7)
    Set(LVar1, 4)
    Call(ShowGotItem, LVar0, TRUE, 0)
    Call(AddKeyItem, LVar0)
    Call(N(EnableActionCommands))
    Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
    Wait(20 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0013)
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0014)
        Call(ShowChoice, MSG_Choice_0013)
        IfNe(LVar0, 0)
            Call(ContinueSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0015)
        Else
            Goto(15)
        EndIf
    Else
        Label(15)
        Call(ContinueSpeech, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0016)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_0017)
        Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0018)
        Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
        Call(SetNpcVar, NPC_Twink, 0, 1)
        Loop(0)
            Call(GetNpcVar, NPC_Twink, 0, LVar0)
            IfEq(LVar0, 2)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndIf
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_002F)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_0030)
    Wait(20 * DT)
    Exec(N(EVS_PlayKammyKoopaSong))
    Call(ShowMessageAtScreenPos, MSG_HOS_0031, 320, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Wait(20 * DT)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, -250)
        Div(LVar0, 2)
        Call(SetPanTarget, CAM_DEFAULT, -250, 53, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.4 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Wait(10 * DT)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    ExecGetTID(N(EVS_UpdateFacingMagikoopa), LVarA)
    Call(LoadPath, 67 * DT, Ref(N(FlightPath_Magikoopa)), ARRAY_COUNT(N(FlightPath_Magikoopa)), EASING_LINEAR)
    Label(2)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_FlyingMagikoopa, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(2)
        EndIf
    KillThread(LVarA)
    ChildThread
        Loop(0)
            Loop(10)
                Call(GetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                Add(LVar1, 1)
                Call(SetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                Wait(2)
            EndLoop
            Wait(3)
            Loop(10)
                Call(GetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                Add(LVar1, -1)
                Call(SetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
                Wait(2)
            EndLoop
            Wait(3)
        EndLoop
    EndChildThread
    Call(SetNpcAnimation, NPC_FlyingMagikoopa, ANIM_FlyingMagikoopa_Anim00)
    Loop(3)
        Call(SetNpcRotation, NPC_FlyingMagikoopa, 0, 0, 10)
        Wait(1)
        Call(SetNpcRotation, NPC_FlyingMagikoopa, 0, 0, 0)
        Wait(1)
    EndLoop
    Wait(20 * DT)
    ExecGetTID(N(EVS_ConfusedTwinkLookingAround), LVarA)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Still, 5, MSG_HOS_0032)
    KillThread(LVarA)
    Wait(10 * DT)
    Call(GetNpcPos, NPC_FlyingMagikoopa, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(260.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(13.0), Float(-8.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(SpeakToPlayer, NPC_FlyingMagikoopa, ANIM_FlyingMagikoopa_Anim09, ANIM_FlyingMagikoopa_Anim00, 512, MSG_HOS_0033)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -250)
    Div(LVar0, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcVar, NPC_FlyingMagikoopa, 0, 1)
    Call(EnablePartnerAI)
    Unbind
    Return
    End
};

EvtScript N(EVS_Scene_TwinkDeparts) = {
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    Wait(60 * DT)
    Call(SetCamLeadPlayer, CAM_DEFAULT, TRUE)
    Call(GetNpcPos, NPC_Twink, LVar3, LVar1, LVar2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(InterpNpcYaw, NPC_Twink, 90, 0)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0034)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(0.5))
    Call(PlayerJump, LVar0, LVar1, LVar2, 15 * DT)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0035)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(700.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.3 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
    Call(LoadPath, 85 * DT, Ref(N(TwinkDepartPath1)), ARRAY_COUNT(N(TwinkDepartPath1)), EASING_LINEAR)
    Label(0)
        Call(GetNextPathPos)
        AddF(LVar1, LVar4)
        AddF(LVar2, LVar5)
        AddF(LVar3, LVar6)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Call(N(HavePartyFaceTwink))
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Wait(45 * DT)
    Thread
        Call(LoadPath, 60 * DT, Ref(N(TwinkReturnPath)), ARRAY_COUNT(N(TwinkReturnPath)), EASING_LINEAR)
        Label(1)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            Call(N(HavePartyFaceTwink))
            Wait(1)
            IfEq(LVar0, 1)
                Goto(1)
            EndIf
    EndThread
    Wait(30 * DT)
    Call(GetNpcPos, NPC_Twink, LVar3, LVar1, LVar2)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Div(LVar0, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-8.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_HOS_0036)
    Thread
        Call(GetNpcPos, NPC_Twink, LVar4, LVar5, LVar6)
        Call(LoadPath, 120 * DT, Ref(N(TwinkDepartPath2)), ARRAY_COUNT(N(TwinkDepartPath2)), EASING_QUADRATIC_IN)
        Label(2)
            Call(GetNextPathPos)
            AddF(LVar1, LVar4)
            AddF(LVar2, LVar5)
            AddF(LVar3, LVar6)
            Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            Call(N(HavePartyFaceTwink))
            Wait(1)
            IfEq(LVar0, 1)
                Goto(2)
            EndIf
    EndThread
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(12.5), Float(-10.0))
    Call(N(AddOffsetForCamPos))
    Call(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    Call(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(30 * DT)
    Call(SetNpcFlagBits, NPC_Twink, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    SetF(LVar0, Float(0.0))
    Loop(10)
        AddF(LVar0, Float(36.0))
        Call(SetNpcRotation, NPC_Twink, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(SetNpcFlagBits, NPC_Twink, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    Wait(120 * DT)
    Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
    Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(13.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10 * DT)
    Call(DisablePartnerAI, 0)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_HOS_0037)
    Call(EnablePartnerAI)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Thread
        Set(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    EndThread
    Wait(10 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
