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
API_CALLABLE(TranslateModel);

/// @evtapi
API_CALLABLE(RotateModel);

/// @evtapi
API_CALLABLE(ScaleModel);

/// @evtapi
API_CALLABLE(GetModelIndex);

/// @evtapi
API_CALLABLE(InvalidateModelTransform);

/// @evtapi
API_CALLABLE(CloneModel);

/// @evtapi
API_CALLABLE(GetModelCenter);

/// @evtapi
API_CALLABLE(SetTexPanner);

/// @evtapi
API_CALLABLE(SetCustomGfxEnabled);

/// @evtapi
API_CALLABLE(SetModelCustomGfx);

/// @evtapi
API_CALLABLE(SetModelTexVariant);

/// @evtapi
API_CALLABLE(EnableTexPanning);

/// @evtapi
API_CALLABLE(EnableModel);

/// @evtapi
API_CALLABLE(SetGroupVisibility);

/// @evtapi
API_CALLABLE(SetTexPanOffset);

/// @evtapi
API_CALLABLE(SetCustomGfx);

/// @evtapi
API_CALLABLE(SetCustomGfxBuilders);

/// @evtapi
API_CALLABLE(SetModelFlags);

/// @evtapi
API_CALLABLE(MakeTransformGroup);

/// @evtapi
API_CALLABLE(SetTransformGroupEnabled);

/// @evtapi
API_CALLABLE(TranslateGroup);

/// @evtapi
API_CALLABLE(RotateGroup);

/// @evtapi
API_CALLABLE(ScaleGroup);

/// @evtapi
API_CALLABLE(GetTransformGroup);

/// @evtapi
API_CALLABLE(EnableGroup);

/// @evtapi
API_CALLABLE(MakeLocalVertexCopy);

/// @evtapi
API_CALLABLE(ModifyColliderFlags);

/// @evtapi
API_CALLABLE(ResetFromLava);

/// @evtapi
API_CALLABLE(GetColliderCenter);

/// @evtapi
API_CALLABLE(ParentColliderToModel);

/// @evtapi
API_CALLABLE(UpdateColliderTransform);

/// @evtapi
API_CALLABLE(SetZoneEnabled);

/// @evtapi
API_CALLABLE(GotoMap);

/// @evtapi
API_CALLABLE(GotoMapSpecial);

/// @evtapi
API_CALLABLE(GotoMapByID);

/// @evtapi
API_CALLABLE(GetEntryID);

/// @evtapi
API_CALLABLE(GetMapID);

/// @evtapi
API_CALLABLE(GetLoadType);

/// @evtapi
API_CALLABLE(SetRenderMode);

/// @evtapi
API_CALLABLE(PlaySoundAtModel);

/// @evtapi
API_CALLABLE(PlaySoundAtCollider);

/// @}

/// @{
/// @name Animated Model

/// @evtapi
API_CALLABLE(InitAnimatedModels);

/// @evtapi
API_CALLABLE(LoadAnimatedModel);

/// @evtapi
API_CALLABLE(LoadAnimatedMesh);

/// @evtapi
API_CALLABLE(PlayModelAnimation);

/// @evtapi
API_CALLABLE(PlayModelAnimationStartingFrom);

/// @evtapi
API_CALLABLE(ChangeModelAnimation);

/// @evtapi
API_CALLABLE(SetAnimatedModelRootPosition);

/// @evtapi
API_CALLABLE(GetAnimatedModelRootPosition);

/// @evtapi
API_CALLABLE(AddAnimatedModelRootPosition);

/// @evtapi
API_CALLABLE(SetAnimatedModelRootRotation);

/// @evtapi
API_CALLABLE(SetAnimatedModelRootScale);

/// @evtapi
API_CALLABLE(SetAnimatedModelRenderMode);

/// @evtapi
API_CALLABLE(DeleteAnimatedModel);

/// @evtapi
API_CALLABLE(SetAnimatorFlags);

/// @evtapi
API_CALLABLE(GetAnimatedNodePosition);

/// @evtapi
API_CALLABLE(GetAnimatedNodeRotation);

/// @evtapi
API_CALLABLE(GetAnimatedPositionByTreeIndex);

/// @evtapi
API_CALLABLE(GetAnimatedRotationByTreeIndex);

/// @evtapi
API_CALLABLE(SetAnimatedNodeFlags);

/// @}

/// @{
/// @name Camera

/// @evtapi
API_CALLABLE(SetCamEnabled);

/// @evtapi
API_CALLABLE(SetCamNoDraw);

/// @evtapi
API_CALLABLE(SetCamPerspective);

/// @evtapi
API_CALLABLE(func_802CA90C);

/// @evtapi
API_CALLABLE(func_802CA988);

/// @evtapi
API_CALLABLE(SetCamViewport);

/// @evtapi
API_CALLABLE(func_802CABE8);

/// @evtapi
API_CALLABLE(func_802CACC0);

/// @evtapi
API_CALLABLE(SetCamBGColor);

/// @evtapi
API_CALLABLE(func_802CAE50);

/// @evtapi
API_CALLABLE(SetCamTarget);

/// @evtapi
API_CALLABLE(InterpCamTargetPos);

/// @evtapi
API_CALLABLE(ShakeCam);

/// @evtapi
API_CALLABLE(SetCamLeadPlayer);

/// @evtapi
API_CALLABLE(func_802CB710);

/// @evtapi
API_CALLABLE(PanToTarget);

/// @evtapi
API_CALLABLE(UseSettingsFrom);

/// @evtapi
API_CALLABLE(LoadSettings);

/// @evtapi
API_CALLABLE(SetCamType);

/// @evtapi
API_CALLABLE(SetCamPitch);

/// @evtapi
API_CALLABLE(SetCamDistance);

/// @evtapi
API_CALLABLE(SetCamPosA);

/// @evtapi
API_CALLABLE(SetCamPosB);

/// @evtapi
API_CALLABLE(SetCamPosC);

/// @evtapi
API_CALLABLE(SetPanTarget);

/// @evtapi
API_CALLABLE(SetCamSpeed);

/// @evtapi
API_CALLABLE(GetCamType);

/// @evtapi
API_CALLABLE(GetCamPitch);

/// @evtapi
API_CALLABLE(GetCamDistance);

/// @evtapi
API_CALLABLE(GetCamPosA);

/// @evtapi
API_CALLABLE(GetCamPosB);

/// @evtapi
API_CALLABLE(GetCamPosC);

/// @evtapi
API_CALLABLE(GetCamPosition);

/// @evtapi
API_CALLABLE(WaitForCam);

/// @evtapi
API_CALLABLE(SetCamProperties);

/// @evtapi
API_CALLABLE(AdjustCam);

/// @evtapi
API_CALLABLE(ResetCam);

/// @}

/// @{
/// @name NPC

/// @evtapi
API_CALLABLE(CreateNpc);

/// @evtapi
API_CALLABLE(DeleteNpc);

/// @evtapi
API_CALLABLE(GetNpcPointer);

/// @evtapi
API_CALLABLE(SetNpcPos);

/// @evtapi
API_CALLABLE(SetNpcRotation);

/// @evtapi
API_CALLABLE(SetNpcRotationPivot);

/// @evtapi
API_CALLABLE(SetNpcScale);

/// @evtapi
API_CALLABLE(SetNpcCollisionSize);

/// @evtapi
API_CALLABLE(SetNpcSpeed);

/// @evtapi
API_CALLABLE(SetNpcJumpscale);

/// @evtapi
API_CALLABLE(SetNpcAnimation);

/// @evtapi
API_CALLABLE(GetNpcAnimation);

/// @evtapi
API_CALLABLE(SetNpcAnimationSpeed);

/// @evtapi
API_CALLABLE(NpcMoveTo);

/// @evtapi
API_CALLABLE(NpcJump0);

/// @evtapi
API_CALLABLE(NpcJump1);

/// @evtapi
API_CALLABLE(NpcFlyTo);

/// @evtapi
API_CALLABLE(GetNpcYaw);

/// @evtapi
API_CALLABLE(SetNpcYaw);

/// @evtapi
API_CALLABLE(InterpNpcYaw);

/// @evtapi
API_CALLABLE(NpcFacePlayer);

/// @evtapi
API_CALLABLE(NpcFaceNpc);

/// @evtapi
API_CALLABLE(SetNpcFlagBits);

/// @evtapi
API_CALLABLE(GetNpcPos);

/// @evtapi
API_CALLABLE(SetNpcCollisionChannel);

/// @evtapi
API_CALLABLE(SetNpcSprite);

/// @evtapi
API_CALLABLE(EnableNpcShadow);

/// @evtapi
API_CALLABLE(EnableNpcBlur);

/// @evtapi
API_CALLABLE(ClearPartnerMoveHistory);

/// @evtapi
API_CALLABLE(NpcSetHomePosToCurrent);

/// @evtapi
API_CALLABLE(GetPartnerPos);

/// @evtapi
API_CALLABLE(DisablePartnerAI);

/// @evtapi
API_CALLABLE(EnablePartnerAI);

/// @evtapi
API_CALLABLE(func_802CF54C);

/// @evtapi
API_CALLABLE(func_802CF56C);

/// @evtapi
API_CALLABLE(BringPartnerOut);

/// @evtapi
API_CALLABLE(PutPartnerAway);

/// @evtapi
API_CALLABLE(GetCurrentPartnerID);

/// @evtapi
API_CALLABLE(PartnerCanUseAbility);

/// @evtapi
API_CALLABLE(PartnerIsFlying);

/// @evtapi
API_CALLABLE(SetNpcImgFXParams);

/// @evtapi
API_CALLABLE(SetNpcImgFXFlags);

/// @evtapi
API_CALLABLE(SetNpcPaletteSwapMode);

/// @evtapi
API_CALLABLE(SetNpcPaletteSwapLower);

/// @evtapi
API_CALLABLE(SetNpcPaletteSwapping);

/// @evtapi
API_CALLABLE(SetNpcDecoration);

/// @evtapi
API_CALLABLE(PlaySoundAtNpc);

/// @evtapi
API_CALLABLE(SetNpcRenderMode);

/// @}

/// @{
/// @name Encounter

/// @evtapi
API_CALLABLE(SetEncounterStatusFlags);

/// @evtapi
API_CALLABLE(IsStartingConversation);

/// @evtapi
API_CALLABLE(func_80044238);

/// @evtapi
API_CALLABLE(LoadDemoBattle);

/// @evtapi
API_CALLABLE(func_80044290);

/// @evtapi
API_CALLABLE(MakeNpcs);

/// @evtapi
API_CALLABLE(RemoveNpc);

/// @evtapi
API_CALLABLE(RemoveEncounter);

/// @evtapi
API_CALLABLE(GetBattleOutcome);

/// @evtapi
API_CALLABLE(func_800445A8);

/// @evtapi
API_CALLABLE(func_800445D4);

/// @evtapi
API_CALLABLE(GetOwnerEncounterTrigger);

/// @evtapi
API_CALLABLE(DoNpcDefeat);

/// @evtapi
API_CALLABLE(StartBattle);

/// @evtapi
API_CALLABLE(StartBattleWith);

/// @evtapi
API_CALLABLE(StartBossBattle);

/// @evtapi
API_CALLABLE(SetBattleMusic);

/// @evtapi
API_CALLABLE(BindNpcAI);

/// @evtapi
API_CALLABLE(BindNpcIdle);

/// @evtapi
API_CALLABLE(RestartNpcAI);

/// @evtapi
API_CALLABLE(EnableNpcAI);

/// @evtapi
API_CALLABLE(SetNpcAux);

/// @evtapi
API_CALLABLE(BindNpcAux);

/// @evtapi
API_CALLABLE(RestartNpcAux);

/// @evtapi
API_CALLABLE(EnableNpcAux);

/// @evtapi
API_CALLABLE(BindNpcInteract);

/// @evtapi
API_CALLABLE(BindNpcHit);

/// @evtapi
API_CALLABLE(BindNpcDefeat);

/// @evtapi
API_CALLABLE(SetSelfVar);

/// @evtapi
API_CALLABLE(GetSelfVar);

/// @evtapi
API_CALLABLE(SetNpcVar);

/// @evtapi
API_CALLABLE(GetNpcVar);

/// @evtapi
API_CALLABLE(SetSelfRotation);

/// @evtapi
API_CALLABLE(SetSelfEnemyFlags);

/// @evtapi
API_CALLABLE(SetSelfEnemyFlagBits);

/// @evtapi
API_CALLABLE(SelfEnemyOverrideSyncPos);

/// @evtapi
API_CALLABLE(GetSelfNpcID);

/// @evtapi
API_CALLABLE(ClearDefeatedEnemies);

/// @evtapi
API_CALLABLE(SetEnemyFlagBits);

/// @evtapi
API_CALLABLE(func_8004572C);

/// @evtapi
API_CALLABLE(GetSelfAnimationFromTable);

/// @evtapi
API_CALLABLE(func_80045798);

/// @evtapi
API_CALLABLE(SetOwnerInstigatorValue);

/// @evtapi
API_CALLABLE(SetBattleAsScripted);

/// @evtapi
API_CALLABLE(GetEncounterTriggerHitTier);

/// @evtapi
API_CALLABLE(func_80045838);

/// @evtapi
API_CALLABLE(func_800458CC);

/// @evtapi
API_CALLABLE(OnPlayerFled);

/// @evtapi
API_CALLABLE(SetTattleMessage);

/// @evtapi
API_CALLABLE(ShowMerleeCoinMessage);

/// @evtapi
API_CALLABLE(ShowMerleeRanOutMessage);

/// @evtapi
API_CALLABLE(FadeInMerlee);

/// @evtapi
API_CALLABLE(FadeOutMerlee);

/// @evtapi
API_CALLABLE(MerleeUpdateFX);

/// @evtapi
API_CALLABLE(MerleeStopFX);

/// @evtapi
API_CALLABLE(PlayMerleeGatherFX);

/// @evtapi
API_CALLABLE(PlayMerleeOrbFX);

/// @evtapi
API_CALLABLE(ShowMerleeCoinMessage);

/// @evtapi
API_CALLABLE(ShowMerleeRanOutMessage);

/// @evtapi
API_CALLABLE(FadeBackgroundDarken);

/// @evtapi
API_CALLABLE(FadeBackgroundLighten);

/// @evtapi
API_CALLABLE(FadeInMerlee);

/// @evtapi
API_CALLABLE(FadeOutMerlee);

/// @evtapi
API_CALLABLE(MerleeUpdateFX);

/// @evtapi
API_CALLABLE(MerleeStopFX);

/// @evtapi
API_CALLABLE(GetCamLookAtObjVector);

/// @evtapi
API_CALLABLE(HasMerleeCasts);

/// @evtapi
API_CALLABLE(PlayMerleeGatherFX);

/// @evtapi
API_CALLABLE(PlayMerleeOrbFX);

/// @evtapi
API_CALLABLE(OnDefeatEnemy);

/// @evtapi
API_CALLABLE(OnFleeBattleDrops);

/// @}

/// @{
/// @name Message

/// @evtapi
API_CALLABLE(SpeakToPlayer);

/// @evtapi
API_CALLABLE(EndSpeech);

/// @evtapi
API_CALLABLE(ContinueSpeech);

/// @evtapi
API_CALLABLE(SpeakToNpc);

/// @evtapi
API_CALLABLE(ShowMessageAtScreenPos);

/// @evtapi
API_CALLABLE(ShowMessageAtWorldPos);

/// @evtapi
API_CALLABLE(CloseMessage);

/// @evtapi
API_CALLABLE(SwitchMessage);

/// @evtapi
API_CALLABLE(ShowChoice);

/// @evtapi
API_CALLABLE(CloseChoice);

/// @evtapi
API_CALLABLE(CancelMessage);

/// @evtapi
API_CALLABLE(SetMessageImages);

/// @evtapi
API_CALLABLE(func_802D0C94);

/// @evtapi
API_CALLABLE(SetMessageText);

/// @evtapi
API_CALLABLE(SetMessageValue);

/// @}

/// @{
/// @name Player

/// Hides the player's shadow if `hide` is `TRUE`, shows it if `FALSE`.
/// @evtapi
/// @param hide Whether to hide the player's shadow.
/// @see disable_player_shadow, enable_player_shadow
API_CALLABLE(HidePlayerShadow);

/// Disables player physics if `disable` is `TRUE`, enables it if `FALSE`.
/// @evtapi
/// @param disable Whether to disable player physics.
/// @see disable_player_static_collisions, enable_player_static_collisions
API_CALLABLE(DisablePlayerPhysics);

/// Disables player and partner input, and disables the status menu.
/// @evtapi
/// @param disable Whether to disable player input.
API_CALLABLE(DisablePlayerInput);

/// Sets the player position.
/// @evtapi
/// @param x
/// @param y `-1000` is used for hiding the player.
/// @param z
/// @see GetPlayerPos
API_CALLABLE(SetPlayerPos);

/// Overrides the player collision size.
/// @evtapi
/// @param height
/// @param diameter
API_CALLABLE(SetPlayerCollisionSize);

/// Sets the move speed of the player for subequent \ref PlayerMoveTo calls.
/// @evtapi
/// @param speed Float multiplier.
/// @see SetNpcSpeed
API_CALLABLE(SetPlayerSpeed);

/// @evtapi
API_CALLABLE(SetPlayerJumpscale);

/// @evtapi
API_CALLABLE(SetPlayerAnimation);

/// @evtapi
API_CALLABLE(SetPlayerActionState);

/// @evtapi
API_CALLABLE(SetPlayerAnimationSpeed);

/// @evtapi
API_CALLABLE(PlayerMoveTo);

/// @evtapi
API_CALLABLE(func_802D1270);

/// @evtapi
API_CALLABLE(func_802D1380);

/// @evtapi
API_CALLABLE(PlayerJump);

/// @evtapi
API_CALLABLE(PlayerJump1);

/// @evtapi
API_CALLABLE(PlayerJump2);

/// @evtapi
API_CALLABLE(InterpPlayerYaw);

/// @evtapi
API_CALLABLE(PlayerFaceNpc);

/// @evtapi
API_CALLABLE(GetPlayerTargetYaw);

/// @evtapi
API_CALLABLE(SetPlayerFlagBits);

/// @evtapi
API_CALLABLE(GetPlayerActionState);

/// @evtapi
API_CALLABLE(GetPlayerPos);

/// @evtapi
API_CALLABLE(GetPlayerAnimation);

/// @evtapi
API_CALLABLE(FullyRestoreHPandFP);

/// @evtapi
API_CALLABLE(FullyRestoreSP);

/// Enables switching to the given partner.
/// @evtapi
/// @param partnerID The \ref PartnerIDs "partner id" to enable.
/// @see DisablePartner
API_CALLABLE(EnablePartner);

/// Disables switching to the given partner.
/// @evtapi
/// @param partnerID The \ref PartnerIDs "partner id" to disable.
/// @see EnablePartner
API_CALLABLE(DisablePartner);

/// @evtapi
API_CALLABLE(UseEntryHeading);

/// @evtapi
API_CALLABLE(func_802D2148);

/// @evtapi
API_CALLABLE(UseExitHeading);

/// @evtapi
API_CALLABLE(WaitForPlayerTouchingFloor);

/// @evtapi
API_CALLABLE(func_802D2484);

/// @evtapi
API_CALLABLE(IsPlayerOnValidFloor);

/// @evtapi
API_CALLABLE(WaitForPlayerMoveToComplete);

/// @evtapi
API_CALLABLE(WaitForPlayerInputEnabled);

/// @evtapi
API_CALLABLE(UpdatePlayerImgFX);

/// @evtapi
API_CALLABLE(SetPlayerImgFXFlags);

/// @evtapi
API_CALLABLE(FacePlayerTowardPoint);

/// @evtapi
API_CALLABLE(DisablePulseStone);

/// @evtapi
API_CALLABLE(GetPartnerInUse);

/// @evtapi
API_CALLABLE(ForceUsePartner);

/// @evtapi
API_CALLABLE(InterruptUsePartner);

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
API_CALLABLE(Disable8bitMario);

/// @evtapi
API_CALLABLE(func_802D2C14);

/// @evtapi
API_CALLABLE(SetPlayerPushVelocity);

/// @evtapi
API_CALLABLE(PlaySoundAtPlayer);

/// @}

/// @{
/// @name Math

/// @evtapi
API_CALLABLE(MakeLerp);

/// @evtapi
API_CALLABLE(UpdateLerp);

/// @evtapi
API_CALLABLE(RandInt);

/// @evtapi
API_CALLABLE(GetAngleBetweenNPCs);

/// @evtapi
API_CALLABLE(GetAngleToNPC);

/// @evtapi
API_CALLABLE(GetAngleToPlayer);

/// @evtapi
API_CALLABLE(AwaitPlayerApproach);

/// @evtapi
API_CALLABLE(IsPlayerWithin);

/// @evtapi
API_CALLABLE(AwaitPlayerLeave);

/// @evtapi
API_CALLABLE(AddVectorPolar);

/// @evtapi
API_CALLABLE(func_802D4BDC);

/// @evtapi
API_CALLABLE(func_802D4C4C);

/// @evtapi
API_CALLABLE(func_802D4CC4);

/// @evtapi
API_CALLABLE(func_802D4D14);

/// @evtapi
API_CALLABLE(func_802D4D88);

/// @evtapi
/// @see GetNextPathPos
API_CALLABLE(LoadPath);

/// @evtapi
/// @see LoadPath
API_CALLABLE(GetNextPathPos);

/// @evtapi
API_CALLABLE(GetDist2D);

/// @evtapi
API_CALLABLE(SetTimeFreezeMode);

/// @evtapi
API_CALLABLE(ModifyGlobalOverrideFlags);

/// @evtapi
API_CALLABLE(SetValueByRef);

/// @evtapi
API_CALLABLE(GetValueByRef);

/// @evtapi
API_CALLABLE(SetGameMode);

/// @evtapi
API_CALLABLE(ClampAngleInt);

/// @evtapi
API_CALLABLE(ClampAngleFloat);

#ifdef VERSION_PAL
/// @evtapi
API_CALLABLE(GetLanguage);
#endif

/// @}

/// @{
/// @name UI

/// @evtapi
API_CALLABLE(EnableWorldStatusBar);

/// @evtapi
API_CALLABLE(ShowWorldStatusBar);

/// @evtapi
API_CALLABLE(ShowCoinCounter);

/// @}

/// @{
/// @name Audio

/// @evtapi
API_CALLABLE(PollMusicEvents);

/// @evtapi
API_CALLABLE(RegisterMusicEvents);

/// @evtapi
API_CALLABLE(FadeOutMusic);

/// @evtapi
API_CALLABLE(SetMusicTrack);

/// @evtapi
API_CALLABLE(FadeInMusic);

/// @evtapi
API_CALLABLE(EnableMusicProximityMix);

/// @evtapi
API_CALLABLE(AdjustMusicProximityMix);

/// @evtapi
API_CALLABLE(SetMusicTrackVolumes);

/// @evtapi
API_CALLABLE(PopSong);

/// @evtapi
API_CALLABLE(PushSong);

/// @evtapi
API_CALLABLE(PopBattleSong);

/// @evtapi
API_CALLABLE(PushBattleSong);

/// @evtapi
API_CALLABLE(SetBattleSong);

/// @evtapi
API_CALLABLE(ClearAmbientSounds);

/// @evtapi
API_CALLABLE(PlayAmbientSounds);

/// @evtapi
API_CALLABLE(PlaySound);

/// @evtapi
API_CALLABLE(PlaySoundWithVolume);

/// @evtapi
API_CALLABLE(PlaySoundAt);

/// @evtapi
API_CALLABLE(StopSound);

/// @evtapi
API_CALLABLE(StopTrackingSoundPos);

/// @evtapi
API_CALLABLE(UseDoorSounds);

/// @evtapi
API_CALLABLE(UseRoomDoorSounds);

/// @evtapi
API_CALLABLE(PlaySoundAtF);

/// @}

/// @{
/// @name Virtual Entity

/// @evtapi
API_CALLABLE(InitVirtualEntityList);

/// @evtapi
API_CALLABLE(CreateVirtualEntityAt);

/// @evtapi
API_CALLABLE(CreateVirtualEntity);

/// @evtapi
API_CALLABLE(CreateVirtualEntity_ALT);

/// @evtapi
API_CALLABLE(DeleteVirtualEntity);

/// @evtapi
API_CALLABLE(SetVirtualEntityRenderCommands);

/// @evtapi
API_CALLABLE(SetVirtualEntityPosition);

/// @evtapi
API_CALLABLE(GetVirtualEntityPosition);

/// @evtapi
API_CALLABLE(SetVirtualEntityRotation);

/// @evtapi
API_CALLABLE(SetVirtualEntityScale);

/// @evtapi
API_CALLABLE(SetVirtualEntityMoveSpeed);

/// @evtapi
API_CALLABLE(SetVirtualEntityJumpGravity);

/// @evtapi
API_CALLABLE(VirtualEntityMoveTo);

/// @evtapi
API_CALLABLE(VirtualEntityJumpTo);

/// @evtapi
API_CALLABLE(VirtualEntityLandJump);

/// @evtapi
API_CALLABLE(SetVirtualEntityFlags);

/// @evtapi
API_CALLABLE(SetVirtualEntityFlagBits);

/// @evtapi
API_CALLABLE(SetVirtualEntityRenderMode);

/// @}

/// @{
/// @name Item

/// @evtapi
API_CALLABLE(ShowKeyChoicePopup);

/// @evtapi
API_CALLABLE(ShowConsumableChoicePopup);

/// @evtapi
API_CALLABLE(RemoveKeyItemAt);

/// @evtapi
API_CALLABLE(RemoveItemAt);

/// @evtapi
API_CALLABLE(AddKeyItem);

/// @evtapi
API_CALLABLE(CloseChoicePopup);

/// @evtapi
API_CALLABLE(HasKeyItem);

/// @evtapi
API_CALLABLE(FindKeyItem);

/// @evtapi
API_CALLABLE(AddItem);

/// @evtapi
API_CALLABLE(ClearVariable);

/// @evtapi
API_CALLABLE(FindItem);

/// @evtapi
API_CALLABLE(RemoveItem);

/// @evtapi
API_CALLABLE(CountFortessKeys);

/// @evtapi
API_CALLABLE(RemoveFortressKeys);

/// @evtapi
API_CALLABLE(MakeItemEntity);

/// @evtapi
API_CALLABLE(DropItemEntity);

/// @evtapi
API_CALLABLE(DropResizableItemEntity);

/// @evtapi
API_CALLABLE(RemoveItemEntity);

/// @evtapi
API_CALLABLE(AddBadge);

/// @evtapi
API_CALLABLE(RemoveBadge);

/// @evtapi
API_CALLABLE(SetItemPos);

/// @evtapi
API_CALLABLE(SetItemFlags);

/// @evtapi
API_CALLABLE(SetItemAlpha);

/// @evtapi
API_CALLABLE(AddCoin);

/// @evtapi
API_CALLABLE(AddStarPoints);

/// @evtapi
API_CALLABLE(AddStarPieces);

/// @evtapi
API_CALLABLE(GetItemPower);

/// @evtapi
API_CALLABLE(ShowGotItem);

/// @}

/// @{
/// @name Effect

/// @evtapi
API_CALLABLE(ShowStartRecoveryShimmer);

/// @evtapi
API_CALLABLE(ShowRecoveryShimmer);

/// @evtapi
API_CALLABLE(func_802D7690);

/// @evtapi
API_CALLABLE(ShowEmote);

/// @evtapi
API_CALLABLE(RemoveEffect);

/// @evtapi
API_CALLABLE(DismissEffect);

/// @evtapi
API_CALLABLE(DismissItemOutline);

/// @evtapi
API_CALLABLE(func_802D7B74);

/// @evtapi
API_CALLABLE(InterpMotionBlurParams);

/// @evtapi
API_CALLABLE(SetMotionBlurParams);

/// @evtapi
API_CALLABLE(ShowSweat);

/// @evtapi
API_CALLABLE(ShowSleepBubble);

/// @evtapi
API_CALLABLE(SetSleepBubbleTimeLeft);

/// @evtapi
/// @see PlayEffect
API_CALLABLE(PlayEffect_impl);

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
API_CALLABLE(MakeEntity);

/// @evtapi
API_CALLABLE(SetEntityCullMode);

/// @evtapi
API_CALLABLE(UseDynamicShadow);

/// @evtapi
API_CALLABLE(AssignScript);

/// @evtapi
API_CALLABLE(AssignSwitchFlag);

/// @evtapi
API_CALLABLE(AssignBlockFlag);

/// @evtapi
API_CALLABLE(AssignChestFlag);

/// @evtapi
API_CALLABLE(AssignPanelFlag);

/// @evtapi
API_CALLABLE(AssignCrateFlag);

/// Removes a trigger previously bound with \ref BindTrigger.
/// @evtapi
/// @param triggerPtr
API_CALLABLE(DeleteTrigger);

/// @}

/// @{
/// @name Sprite shading

/// @evtapi
API_CALLABLE(SetSpriteShading);

/// @evtapi
API_CALLABLE(EnableSpriteShading);

/// @}

/// @{
/// @name Demo

/// @evtapi
API_CALLABLE(GetDemoState);

/// @evtapi
API_CALLABLE(DemoPressButton);

/// @evtapi
API_CALLABLE(DemoReleaseButton);

/// @evtapi
API_CALLABLE(DemoSetButtons);

/// @evtapi
API_CALLABLE(DemoJoystickRadial);

/// @evtapi
API_CALLABLE(DemoJoystickXY);

/// @}

extern EvtScript EnemyNpcHit;
extern EvtScript EnemyNpcDefeat;

#endif
