/// @file script_api/common.h
/// EVT scripting API functions available at all times.
/// @sa script_api/battle.h script_api/map.h

// Command for reading all declarations in a source file:
// $ cat src/evt/*.c | grep "ApiStatus [^{]*" -o | sed "s/ $/;/"

#ifndef _SCRIPT_API_COMMON_H_
#define _SCRIPT_API_COMMON_H_

#include "common_structs.h"
#include "macros.h"

/// @{
/// @name Map

/// @evtapi
ApiStatus TranslateModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RotateModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ScaleModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetModelIndex(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus InvalidateModelTransform(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CloneModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetModelCenter(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetTexPanner(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCustomGfxEnabled(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetModelCustomGfx(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetModelTexVariant(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableTexPanning(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetGroupVisibility(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetTexPanOffset(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCustomGfx(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCustomGfxBuilders(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetModelFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MakeTransformGroup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetTransformGroupEnabled(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus TranslateGroup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RotateGroup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ScaleGroup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetTransformGroup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableGroup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MakeLocalVertexCopy(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ModifyColliderFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ResetFromLava(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetColliderCenter(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ParentColliderToModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UpdateColliderTransform(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetZoneEnabled(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GotoMap(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GotoMapSpecial(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GotoMapByID(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetEntryID(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetMapID(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetLoadType(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetRenderMode(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundAtModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundAtCollider(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Animated Model

/// @evtapi
ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus LoadAnimatedModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus LoadAnimatedMesh(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayModelAnimation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayModelAnimationStartingFrom(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ChangeModelAnimation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetAnimatedModelRootPosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAnimatedModelRootPosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddAnimatedModelRootPosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetAnimatedModelRootRotation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetAnimatedModelRootScale(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetAnimatorFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAnimatedNodePosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAnimatedNodeRotation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAnimatedPositionByTreeIndex(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAnimatedRotationByTreeIndex(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetAnimatedNodeFlags(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Camera

/// @evtapi
ApiStatus SetCamEnabled(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamNoDraw(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamPerspective(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CA90C(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CA988(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamViewport(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CABE8(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CACC0(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamBGColor(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CAE50(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamTarget(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus InterpCamTargetPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShakeCam(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamLeadPlayer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CB710(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PanToTarget(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UseSettingsFrom(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus LoadSettings(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamType(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamPitch(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamDistance(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamPosA(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamPosB(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamPosC(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPanTarget(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamSpeed(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamType(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamPitch(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamDistance(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamPosA(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamPosB(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamPosC(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamPosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus WaitForCam(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetCamProperties(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AdjustCam(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ResetCam(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name NPC

/// @evtapi
ApiStatus CreateNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DeleteNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetNpcPointer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcRotation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcRotationPivot(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcScale(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcCollisionSize(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcSpeed(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcJumpscale(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcAnimation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetNpcAnimation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcAnimationSpeed(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcMoveTo(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcJump0(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcJump1(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcFlyTo(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetNpcYaw(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcYaw(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus InterpNpcYaw(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcFacePlayer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcFaceNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcFlagBits(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetNpcPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcCollisionChannel(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcSprite(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableNpcShadow(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableNpcBlur(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ClearPartnerMoveHistory(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus NpcSetHomePosToCurrent(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetPartnerPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DisablePartnerAI(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnablePartnerAI(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CF54C(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802CF56C(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BringPartnerOut(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PutPartnerAway(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCurrentPartnerID(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PartnerCanUseAbility(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PartnerIsFlying(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcImgFXParams(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcImgFXFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcPaletteSwapMode(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcPaletteSwapLower(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcPaletteSwapping(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcDecoration(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundAtNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcRenderMode(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Encounter

/// @evtapi
ApiStatus SetEncounterStatusFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus IsStartingConversation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_80044238(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus LoadDemoBattle(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_80044290(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MakeNpcs(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveEncounter(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetBattleOutcome(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_800445A8(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_800445D4(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetOwnerEncounterTrigger(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DoNpcDefeat(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus StartBattle(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus StartBattleWith(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus StartBossBattle(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetBattleMusic(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BindNpcAI(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BindNpcIdle(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RestartNpcAI(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableNpcAI(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcAux(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BindNpcAux(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RestartNpcAux(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableNpcAux(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BindNpcInteract(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BindNpcHit(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus BindNpcDefeat(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetSelfVar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetSelfVar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetNpcVar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetNpcVar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetSelfRotation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetSelfEnemyFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetSelfEnemyFlagBits(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SelfEnemyOverrideSyncPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetSelfNpcID(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ClearDefeatedEnemies(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetEnemyFlagBits(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_8004572C(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetSelfAnimationFromTable(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_80045798(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetOwnerInstigatorValue(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetBattleAsScripted(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetEncounterTriggerHitTier(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_80045838(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_800458CC(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus OnPlayerFled(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetTattleMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowMerleeCoinMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowMerleeRanOutMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeInMerlee(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeOutMerlee(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MerleeUpdateFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MerleeStopFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayMerleeGatherFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayMerleeOrbFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowMerleeCoinMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowMerleeRanOutMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeBackgroundDarken(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeBackgroundLighten(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeInMerlee(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeOutMerlee(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MerleeUpdateFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MerleeStopFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetCamLookAtObjVector(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus HasMerleeCasts(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayMerleeGatherFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayMerleeOrbFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus OnDefeatEnemy(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus OnFleeBattleDrops(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Message

/// @evtapi
ApiStatus SpeakToPlayer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EndSpeech(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ContinueSpeech(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SpeakToNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowMessageAtScreenPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowMessageAtWorldPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CloseMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SwitchMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowChoice(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CloseChoice(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CancelMessage(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetMessageImages(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D0C94(Evt* script, s32 initialCall);

/// @evtapi
ApiStatus SetMessageText(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetMessageValue(Evt* script, s32 initialCall);

/// @}

/// @{
/// @name Player

/// Hides the player's shadow if `hide` is `TRUE`, shows it if `FALSE`.
/// @evtapi
/// @param hide Whether to hide the player's shadow.
/// @see disable_player_shadow, enable_player_shadow
ApiStatus HidePlayerShadow(Evt* script, s32 isInitialCall);

/// Disables player physics if `disable` is `TRUE`, enables it if `FALSE`.
/// @evtapi
/// @param disable Whether to disable player physics.
/// @see disable_player_static_collisions, enable_player_static_collisions
ApiStatus DisablePlayerPhysics(Evt* script, s32 isInitialCall);

/// Disables player and partner input, and disables the status menu.
/// @evtapi
/// @param disable Whether to disable player input.
ApiStatus DisablePlayerInput(Evt* script, s32 isInitialCall);

/// Sets the player position.
/// @evtapi
/// @param x
/// @param y `-1000` is used for hiding the player.
/// @param z
/// @see GetPlayerPos
ApiStatus SetPlayerPos(Evt* script, s32 isInitialCall);

/// Overrides the player collision size.
/// @evtapi
/// @param height
/// @param diameter
ApiStatus SetPlayerCollisionSize(Evt* script, s32 isInitialCall);

/// Sets the move speed of the player for subequent \ref PlayerMoveTo calls.
/// @evtapi
/// @param speed Float multiplier.
/// @see SetNpcSpeed
ApiStatus SetPlayerSpeed(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerJumpscale(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerAnimation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerActionState(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerAnimationSpeed(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayerMoveTo(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D1270(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D1380(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayerJump(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayerJump1(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayerJump2(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus InterpPlayerYaw(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayerFaceNpc(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetPlayerTargetYaw(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerFlagBits(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetPlayerActionState(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetPlayerPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetPlayerAnimation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FullyRestoreHPandFP(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FullyRestoreSP(Evt* script, s32 isInitialCall);

/// Enables switching to the given partner.
/// @evtapi
/// @param partnerID The \ref PartnerIDs "partner id" to enable.
/// @see DisablePartner
ApiStatus EnablePartner(Evt* script, s32 isInitialCall);

/// Disables switching to the given partner.
/// @evtapi
/// @param partnerID The \ref PartnerIDs "partner id" to disable.
/// @see EnablePartner
ApiStatus DisablePartner(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UseEntryHeading(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D2148(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UseExitHeading(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus WaitForPlayerTouchingFloor(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D2484(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus IsPlayerOnValidFloor(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus WaitForPlayerMoveToComplete(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus WaitForPlayerInputEnabled(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UpdatePlayerImgFX(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerImgFXFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FacePlayerTowardPoint(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DisablePulseStone(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetPartnerInUse(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ForceUsePartner(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus InterruptUsePartner(Evt* script, s32 isInitialCall);

/// Enables and disables the 8-bit Mario easter egg.
///
/// @evtapi
/// @param disable Disable the easter egg if `TRUE`, enable it if `FALSE`.
///
/// Whilst active, the player uses a retro sprite, and the following actions are disabled:
/// - Spin dash
/// - Hammer
/// - Spin jump and tornado jump
/// - Menus
/// - Partner usage and partner switching
///
/// @see PA_FLAG_8BIT_MARIO
ApiStatus Disable8bitMario(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D2C14(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetPlayerPushVelocity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundAtPlayer(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Math

/// @evtapi
ApiStatus MakeLerp(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UpdateLerp(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RandInt(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAngleBetweenNPCs(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAngleToNPC(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetAngleToPlayer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AwaitPlayerApproach(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus IsPlayerWithin(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AwaitPlayerLeave(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddVectorPolar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D4BDC(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D4C4C(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D4CC4(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D4D14(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D4D88(Evt* script, s32 isInitialCall);

/// @evtapi
/// @see GetNextPathPos
ApiStatus LoadPath(Evt* script, s32 isInitialCall);

/// @evtapi
/// @see LoadPath
ApiStatus GetNextPathPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetDist2D(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetTimeFreezeMode(Evt* script, s32 initialCall);

/// @evtapi
ApiStatus ModifyGlobalOverrideFlags(Evt* script, s32 initialCall);

/// @evtapi
ApiStatus SetValueByRef(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetValueByRef(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetGameMode(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ClampAngleInt(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ClampAngleFloat(Evt* script, s32 isInitialCall);

#ifdef VERSION_PAL
/// @evtapi
ApiStatus GetLanguage(Evt* script, s32 isInitialCall);
#endif

/// @}

/// @{
/// @name UI

/// @evtapi
ApiStatus EnableWorldStatusBar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowWorldStatusBar(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowCoinCounter(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Audio

/// @evtapi
ApiStatus PollMusicEvents(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RegisterMusicEvents(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeOutMusic(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetMusicTrack(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FadeInMusic(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableMusicProximityMix(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AdjustMusicProximityMix(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetMusicTrackVolumes(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PopSong(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PushSong(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PopBattleSong(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PushBattleSong(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetBattleSong(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ClearAmbientSounds(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayAmbientSounds(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySound(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundWithVolume(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundAt(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus StopSound(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus StopTrackingSoundPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UseDoorSounds(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UseRoomDoorSounds(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlaySoundAtF(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Virtual Entity

/// @evtapi
ApiStatus InitVirtualEntityList(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CreateVirtualEntityAt(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CreateVirtualEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CreateVirtualEntity_ALT(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DeleteVirtualEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityRenderCommands(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityPosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetVirtualEntityPosition(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityRotation(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityScale(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityMoveSpeed(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityJumpGravity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus VirtualEntityMoveTo(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus VirtualEntityJumpTo(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus VirtualEntityLandJump(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityFlagBits(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetVirtualEntityRenderMode(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Item

/// @evtapi
ApiStatus ShowKeyChoicePopup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowConsumableChoicePopup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveKeyItemAt(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveItemAt(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddKeyItem(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CloseChoicePopup(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus HasKeyItem(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FindKeyItem(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddItem(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ClearVariable(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus FindItem(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveItem(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus CountFortessKeys(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveFortressKeys(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus MakeItemEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DropItemEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DropResizableItemEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveItemEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddBadge(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveBadge(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetItemPos(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetItemFlags(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetItemAlpha(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddCoin(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddStarPoints(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AddStarPieces(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus GetItemPower(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowGotItem(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Effect

/// @evtapi
ApiStatus ShowStartRecoveryShimmer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowRecoveryShimmer(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D7690(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowEmote(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus RemoveEffect(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DismissEffect(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DismissItemOutline(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus func_802D7B74(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus InterpMotionBlurParams(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetMotionBlurParams(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowSweat(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus ShowSleepBubble(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetSleepBubbleTimeLeft(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus PlayEffect(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Entity

// TODO: document varargs better
/// Creates an entity.
///
/// @evtapi
/// @param blueprint Pointer to \ref EntityBlueprint to use.
/// @param x
/// @param y
/// @param z
/// @param flags \ref EntityFlags
/// @param ... Varargs.
/// @param MAKE_ENTITY_END Terminates the varargs.
/// @vars{out | LVar0 | Created entity's ID.}
ApiStatus MakeEntity(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus SetEntityCullMode(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus UseDynamicShadow(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AssignScript(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AssignSwitchFlag(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AssignBlockFlag(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AssignChestFlag(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AssignPanelFlag(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus AssignCrateFlag(Evt* script, s32 isInitialCall);

/// Removes a trigger previously bound with \ref EVT_BIND_TRIGGER.
/// @evtapi
/// @param triggerPtr
ApiStatus DeleteTrigger(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Sprite shading

/// @evtapi
ApiStatus SetSpriteShading(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus EnableSpriteShading(Evt* script, s32 isInitialCall);

/// @}

/// @{
/// @name Demo

/// @evtapi
ApiStatus GetDemoState(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DemoPressButton(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DemoReleaseButton(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DemoSetButtons(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DemoJoystickRadial(Evt* script, s32 isInitialCall);

/// @evtapi
ApiStatus DemoJoystickXY(Evt* script, s32 isInitialCall);

/// @}

extern EvtScript EnemyNpcHit;
extern EvtScript EnemyNpcDefeat;

#endif
