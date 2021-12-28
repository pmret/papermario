#ifndef _SCRIPT_API_COMMON_H_
#define _SCRIPT_API_COMMON_H_

#include "common_structs.h"
#include "macros.h"

ApiStatus FadeBackgroundToBlack(Evt* script, s32 isInitialCall);
ApiStatus UnfadeBackgroundFromBlack(Evt* script, s32 isInitialCall);
ApiStatus GetCamLookAtObjVector(Evt* script, s32 isInitialCall);
ApiStatus HasMerleeCasts(Evt* script, s32 isInitialCall);
ApiStatus OnDefeatEnemy(Evt* script, s32 isInitialCall);
ApiStatus OnFleeBattleDrops(Evt* script, s32 isInitialCall);
ApiStatus SetEncounterStatusFlags(Evt* script, s32 isInitialCall);
ApiStatus LoadDemoBattle(Evt* script, s32 isInitialCall);
ApiStatus RemoveNpc(Evt* script, s32 isInitialCall);
ApiStatus RemoveEncounter(Evt* script, s32 isInitialCall);
ApiStatus GetBattleOutcome(Evt* script, s32 isInitialCall);
ApiStatus GetOwnerEncounterTrigger(Evt* script, s32 isInitialCall);
ApiStatus DoNpcDefeat(Evt* script, s32 isInitialCall);
ApiStatus StartBattle(Evt* script, s32 isInitialCall);
ApiStatus StartBattleWith(Evt* script, s32 isInitialCall);
ApiStatus StartBossBattle(Evt* script, s32 isInitialCall);
ApiStatus SetBattleMusic(Evt* script, s32 isInitialCall);
ApiStatus BindNpcAI(Evt* script, s32 isInitialCall);
ApiStatus BindNpcIdle(Evt* script, s32 isInitialCall);
ApiStatus RestartNpcAI(Evt* script, s32 isInitialCall);
ApiStatus EnableNpcAI(Evt* script, s32 isInitialCall);
ApiStatus SetNpcAux(Evt* script, s32 isInitialCall);
ApiStatus BindNpcAux(Evt* script, s32 isInitialCall);
ApiStatus RestartNpcAux(Evt* script, s32 isInitialCall);
ApiStatus EnableNpcAux(Evt* script, s32 isInitialCall);
ApiStatus BindNpcInteract(Evt* script, s32 isInitialCall);
ApiStatus BindNpcHit(Evt* script, s32 isInitialCall);
ApiStatus BindNpcDefeat(Evt* script, s32 isInitialCall);
ApiStatus SetSelfVar(Evt* script, s32 isInitialCall);
ApiStatus GetSelfVar(Evt* script, s32 isInitialCall);
ApiStatus SetNpcVar(Evt* script, s32 isInitialCall);
ApiStatus GetNpcVar(Evt* script, s32 isInitialCall);
ApiStatus SetSelfRotation(Evt* script, s32 isInitialCall);
ApiStatus SetSelfEnemyFlags(Evt* script, s32 isInitialCall);
ApiStatus SetSelfEnemyFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetSelfNpcID(Evt* script, s32 isInitialCall);
ApiStatus ClearDefeatedEnemies(Evt* script, s32 isInitialCall);
ApiStatus SetEnemyFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetSelfAnimationFromTable(Evt* script, s32 isInitialCall);
ApiStatus ShowCoinCounter(Evt* script, s32 isInitialCall);
ApiStatus MakeEntity(Evt* script, s32 isInitialCall);
ApiStatus AssignScript(Evt* script, s32 isInitialCall);
ApiStatus AssignAreaFlag(Evt* script, s32 isInitialCall);
ApiStatus AssignFlag(Evt* script, s32 isInitialCall);
ApiStatus AssignBlockFlag(Evt* script, s32 isInitialCall);
ApiStatus AssignPanelFlag(Evt* script, s32 isInitialCall);
ApiStatus AssignCrateFlag(Evt* script, s32 isInitialCall);
ApiStatus DeleteTrigger(Evt* script, s32 isInitialCall);
ApiStatus TranslateModel(Evt* script, s32 isInitialCall);
ApiStatus RotateModel(Evt* script, s32 isInitialCall);
ApiStatus ScaleModel(Evt* script, s32 isInitialCall);
ApiStatus CloneModel(Evt* script, s32 isInitialCall);
ApiStatus GetModelIndex(Evt* script, s32 isInitialCall);
ApiStatus GetModelCenter(Evt* script, s32 isInitialCall);
ApiStatus SetTexPanner(Evt* script, s32 isInitialCall);
ApiStatus SetCustomGfxEnabled(Evt* script, s32 isInitialCall);
ApiStatus EnableTexPanning(Evt* script, s32 isInitialCall);
ApiStatus EnableModel(Evt* script, s32 isInitialCall);
ApiStatus SetGroupEnabled(Evt* script, s32 isInitialCall);
ApiStatus SetTexPanOffset(Evt* script, s32 isInitialCall);
ApiStatus SetModelFlags(Evt* script, s32 isInitialCall);
ApiStatus TranslateGroup(Evt* script, s32 isInitialCall);
ApiStatus RotateGroup(Evt* script, s32 isInitialCall);
ApiStatus ScaleGroup(Evt* script, s32 isInitialCall);
ApiStatus EnableGroup(Evt* script, s32 isInitialCall);
ApiStatus ModifyColliderFlags(Evt* script, s32 isInitialCall);
ApiStatus GetColliderCenter(Evt* script, s32 isInitialCall);
ApiStatus ParentColliderToModel(Evt* script, s32 isInitialCall);
ApiStatus UpdateColliderTransform(Evt* script, s32 isInitialCall);
ApiStatus SetZoneEnabled(Evt* script, s32 isInitialCall);
ApiStatus GotoMap(Evt* script, s32 isInitialCall);
ApiStatus GotoMapSpecial(Evt* script, s32 isInitialCall);
ApiStatus GotoMapByID(Evt* script, s32 isInitialCall);
ApiStatus GetEntryID(Evt* script, s32 isInitialCall);
ApiStatus GetMapID(Evt* script, s32 isInitialCall);
ApiStatus GetLoadType(Evt* script, s32 isInitialCall);
ApiStatus SetRenderMode(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtModel(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtCollider(Evt* script, s32 isInitialCall);
ApiStatus SetCamEnabled(Evt* script, s32 isInitialCall);
ApiStatus SetCamFlag80(Evt* script, s32 isInitialCall);
ApiStatus SetCamPerspective(Evt* script, s32 isInitialCall);
ApiStatus SetCamViewport(Evt* script, s32 isInitialCall);
ApiStatus SetCamBGColor(Evt* script, s32 isInitialCall);
ApiStatus SetCamTarget(Evt* script, s32 isInitialCall);
ApiStatus ShakeCam(Evt* script, s32 isInitialCall);
ApiStatus SetCamLeadPlayer(Evt* script, s32 isInitialCall);
ApiStatus PanToTarget(Evt* script, s32 isInitialCall);
ApiStatus UseSettingsFrom(Evt* script, s32 isInitialCall);
ApiStatus LoadSettings(Evt* script, s32 isInitialCall);
ApiStatus SetCamType(Evt* script, s32 isInitialCall);
ApiStatus SetCamPitch(Evt* script, s32 isInitialCall);
ApiStatus SetCamDistance(Evt* script, s32 isInitialCall);
ApiStatus SetCamPosA(Evt* script, s32 isInitialCall);
ApiStatus SetCamPosB(Evt* script, s32 isInitialCall);
ApiStatus SetCamPosC(Evt* script, s32 isInitialCall);
ApiStatus SetPanTarget(Evt* script, s32 isInitialCall);
ApiStatus SetCamSpeed(Evt* script, s32 isInitialCall);
ApiStatus GetCamType(Evt* script, s32 isInitialCall);
ApiStatus GetCamPitch(Evt* script, s32 isInitialCall);
ApiStatus GetCamDistance(Evt* script, s32 isInitialCall);
ApiStatus GetCamPosA(Evt* script, s32 isInitialCall);
ApiStatus GetCamPosB(Evt* script, s32 isInitialCall);
ApiStatus GetCamPosC(Evt* script, s32 isInitialCall);
ApiStatus GetCamPosition(Evt* script, s32 isInitialCall);
ApiStatus WaitForCam(Evt* script, s32 isInitialCall);
ApiStatus SetCamProperties(Evt* script, s32 isInitialCall);
ApiStatus AdjustCam(Evt* script, s32 isInitialCall);
ApiStatus ResetCam(Evt* script, s32 isInitialCall);
ApiStatus LoadAnimatedModel(Evt* script, s32 isInitialCall);
ApiStatus PlayModelAnimation(Evt* script, s32 isInitialCall);
ApiStatus SetAnimatedModelRootPosition(Evt* script, s32 isInitialCall);
ApiStatus ChangeModelAnimation(Evt* script, s32 isInitialCall);
ApiStatus DeleteNpc(Evt* script, s32 isInitialCall);
ApiStatus GetNpcPointer(Evt* script, s32 isInitialCall);
ApiStatus SetNpcPos(Evt* script, s32 isInitialCall);
ApiStatus SetNpcRotation(Evt* script, s32 isInitialCall);
ApiStatus SetNpcScale(Evt* script, s32 isInitialCall);
ApiStatus SetNpcCollisionSize(Evt* script, s32 isInitialCall);
ApiStatus SetNpcSpeed(Evt* script, s32 isInitialCall);
ApiStatus SetNpcJumpscale(Evt* script, s32 isInitialCall);
ApiStatus SetNpcAnimation(Evt* script, s32 isInitialCall);
ApiStatus GetNpcAnimation(Evt* script, s32 isInitialCall);
ApiStatus NpcMoveTo(Evt* script, s32 isInitialCall);
ApiStatus NpcJump0(Evt* script, s32 isInitialCall);
ApiStatus NpcJump1(Evt* script, s32 isInitialCall);
ApiStatus NpcFlyTo(Evt* script, s32 isInitialCall);
ApiStatus GetNpcYaw(Evt* script, s32 isInitialCall);
ApiStatus SetNpcYaw(Evt* script, s32 isInitialCall);
ApiStatus InterpNpcYaw(Evt* script, s32 isInitialCall);
ApiStatus NpcFacePlayer(Evt* script, s32 isInitialCall);
ApiStatus NpcFaceNpc(Evt* script, s32 isInitialCall);
ApiStatus SetNpcFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetNpcPos(Evt* script, s32 isInitialCall);
ApiStatus EnableNpcShadow(Evt* script, s32 isInitialCall);
ApiStatus EnableNpcBlur(Evt* script, s32 isInitialCall);
ApiStatus ClearPartnerMoveHistory(Evt* script, s32 isInitialCall);
ApiStatus GetPartnerPos(Evt* script, s32 isInitialCall);
ApiStatus DisablePartnerAI(Evt* script, s32 isInitialCall);
ApiStatus EnablePartnerAI(Evt* script, s32 isInitialCall);
ApiStatus BringPartnerOut(Evt* script, s32 isInitialCall);
ApiStatus PutPartnerAway(Evt* script, s32 isInitialCall);
ApiStatus GetCurrentPartnerID(Evt* script, s32 isInitialCall);
ApiStatus IsCurrentPartnerFlying(Evt* script, s32 isInitialCall);
ApiStatus SetNpcDecoration(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtNpc(Evt* script, s32 isInitialCall);
ApiStatus SpeakToPlayer(Evt* script, s32 isInitialCall);
ApiStatus EndSpeech(Evt* script, s32 isInitialCall);
ApiStatus ContinueSpeech(Evt* script, s32 isInitialCall);
ApiStatus SpeakToNpc(Evt* script, s32 isInitialCall);
ApiStatus ShowMessageAtScreenPos(Evt* script, s32 isInitialCall);
ApiStatus ShowMessageAtWorldPos(Evt* script, s32 isInitialCall);
ApiStatus CloseMessage(Evt* script, s32 isInitialCall);
ApiStatus SwitchMessage(Evt* script, s32 isInitialCall);
ApiStatus ShowChoice(Evt* script, s32 isInitialCall);
ApiStatus CloseChoice(Evt* script, s32 isInitialCall);
ApiStatus CancelMessage(Evt* script, s32 isInitialCall);
ApiStatus CancelMessageAndBlock(void); // ???
ApiStatus SetMessageImages(Evt* script, s32 isInitialCall);
ApiStatus SetMessageMsg(Evt* script, s32 isInitialCall);
ApiStatus SetMessageValue(Evt* script, s32 isInitialCall);
ApiStatus HidePlayerShadow(Evt* script, s32 isInitialCall);
ApiStatus DisablePlayerPhysics(Evt* script, s32 isInitialCall);
ApiStatus DisablePlayerInput(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerPos(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerCollisionSize(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerSpeed(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerJumpscale(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerAnimation(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerActionState(Evt* script, s32 isInitialCall);
ApiStatus PlayerMoveTo(Evt* script, s32 isInitialCall);
ApiStatus PlayerJump(Evt* script, s32 isInitialCall);
ApiStatus PlayerJump1(Evt* script, s32 isInitialCall);
ApiStatus PlayerJump2(Evt* script, s32 isInitialCall);
ApiStatus InterpPlayerYaw(Evt* script, s32 isInitialCall);
ApiStatus PlayerFaceNpc(Evt* script, s32 isInitialCall);
ApiStatus GetPlayerTargetYaw(Evt* script, s32 isInitialCall);
ApiStatus SetPlayerFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetPlayerActionState(Evt* script, s32 isInitialCall);
ApiStatus GetPlayerPos(Evt* script, s32 isInitialCall);
ApiStatus GetPlayerAnimation(Evt* script, s32 isInitialCall);
ApiStatus FullyRestoreHPandFP(Evt* script, s32 isInitialCall);
ApiStatus FullyRestoreSP(Evt* script, s32 isInitialCall);
ApiStatus EnablePartner(Evt* script, s32 isInitialCall);
ApiStatus DisablePartner(Evt* script, s32 isInitialCall);
ApiStatus UseEntryHeading(Evt* script, s32 isInitialCall);
ApiStatus UseExitHeading(Evt* script, s32 isInitialCall);
ApiStatus DisablePulseStone(Evt* script, s32 isInitialCall);
ApiStatus GetCurrentPartner(Evt* script, s32 isInitialCall);
ApiStatus Disable8bitMario(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtPlayer(Evt* script, s32 isInitialCall);
ApiStatus MakeLerp(Evt* script, s32 isInitialCall);
ApiStatus UpdateLerp(Evt* script, s32 isInitialCall);
ApiStatus RandInt(Evt* script, s32 isInitialCall);
ApiStatus GetAngleBetweenNPCs(Evt* script, s32 isInitialCall);
ApiStatus GetAngleToNPC(Evt* script, s32 isInitialCall);
ApiStatus GetAngleToPlayer(Evt* script, s32 isInitialCall);
ApiStatus AwaitPlayerApproach(Evt* script, s32 isInitialCall);
ApiStatus IsPlayerWithin(Evt* script, s32 isInitialCall);
ApiStatus AwaitPlayerLeave(Evt* script, s32 isInitialCall);
ApiStatus AddVectorPolar(Evt* script, s32 isInitialCall);
ApiStatus LoadPath(Evt* script, s32 isInitialCall);
ApiStatus GetNextPathPos(Evt* script, s32 isInitialCall);
ApiStatus GetDist2D(Evt* script, s32 isInitialCall);
ApiStatus SetValueByRef(Evt* script, s32 isInitialCall);
ApiStatus GetValueByRef(Evt* script, s32 isInitialCall);
ApiStatus EnableStatusMenu(Evt* script, s32 isInitialCall);
ApiStatus ShowStatusMenu(Evt* script, s32 isInitialCall);
ApiStatus SetGameMode(Evt* script, s32 isInitialCall);
ApiStatus ClampAngleInt(Evt* script, s32 isInitialCall);
ApiStatus ClampAngleFloat(Evt* script, s32 isInitialCall);
ApiStatus FadeOutMusic(Evt* script, s32 isInitialCall);
ApiStatus SetMusicTrack(Evt* script, s32 isInitialCall);
ApiStatus FadeInMusic(Evt* script, s32 isInitialCall);
ApiStatus ClearAmbientSounds(Evt* script, s32 isInitialCall);
ApiStatus PlayAmbientSounds(Evt* script, s32 isInitialCall);
ApiStatus PlaySound(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAt(Evt* script, s32 isInitialCall);
ApiStatus StopSound(Evt* script, s32 isInitialCall);
ApiStatus UseDoorSounds(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtF(Evt* script, s32 isInitialCall);
ApiStatus RemoveKeyItemAt(Evt* script, s32 isInitialCall);
ApiStatus RemoveItemAt(Evt* script, s32 isInitialCall);
ApiStatus AddKeyItem(Evt* script, s32 isInitialCall);
ApiStatus HasKeyItem(Evt* script, s32 isInitialCall);
ApiStatus FindKeyItem(Evt* script, s32 isInitialCall);
ApiStatus AddItem(Evt* script, s32 isInitialCall);
ApiStatus FindItem(Evt* script, s32 isInitialCall);
ApiStatus RemoveItem(Evt* script, s32 isInitialCall);
ApiStatus CountFortessKeys(Evt* script, s32 isInitialCall);
ApiStatus RemoveFortressKeys(Evt* script, s32 isInitialCall);
ApiStatus MakeItemEntity(Evt* script, s32 isInitialCall);
ApiStatus DropItemEntity(Evt* script, s32 isInitialCall);
ApiStatus DropItemEntityB(Evt* script, s32 isInitialCall);
ApiStatus RemoveItemEntity(Evt* script, s32 isInitialCall);
ApiStatus AddBadge(Evt* script, s32 isInitialCall);
ApiStatus RemoveBadge(Evt* script, s32 isInitialCall);
ApiStatus SetItemPos(Evt* script, s32 isInitialCall);
ApiStatus SetItemFlags(Evt* script, s32 isInitialCall);
ApiStatus AddCoin(Evt* script, s32 isInitialCall);
ApiStatus AddStarPoints(Evt* script, s32 isInitialCall);
ApiStatus AddStarPieces(Evt* script, s32 isInitialCall);
ApiStatus GetItemPower(Evt* script, s32 isInitialCall);
ApiStatus ShowGotItem(Evt* script, s32 isInitialCall);
ApiStatus ShowEmote(Evt* script, s32 isInitialCall);
ApiStatus ShowSleepBubble(Evt* script, s32 isInitialCall);
ApiStatus RemoveEffect(Evt* script, s32 isInitialCall);
ApiStatus PlayEffect(Evt* script, s32 isInitialCall);
ApiStatus SetSpriteShading(Evt* script, s32 isInitialCall);
ApiStatus EnableSpriteShading(Evt* script, s32 isInitialCall);
ApiStatus GetDemoState(Evt* script, s32 isInitialCall);
ApiStatus DemoPressButton(Evt* script, s32 isInitialCall);
ApiStatus DemoReleaseButton(Evt* script, s32 isInitialCall);
ApiStatus DemoSetButtons(Evt* script, s32 isInitialCall);
ApiStatus DemoJoystickRadial(Evt* script, s32 isInitialCall);
ApiStatus DemoJoystickXY(Evt* script, s32 isInitialCall);
ApiStatus WaitForPlayerInputEnabled(Evt* script, s32 isInitialCall);
ApiStatus IsPlayerOnValidFloor(Evt* script, s32 isInitialCall);
ApiStatus func_802CFE2C(Evt* script, s32 isInitialCall);
ApiStatus func_802CFD30(Evt* script, s32 isInitialCall);
ApiStatus IsStartingConversation(Evt* script, s32 isInitialCall);
ApiStatus SetTimeFreezeMode(Evt* script, s32 isInitialCall);
ApiStatus CreateVirtualEntity(Evt* script, s32 isInitialCall);
ApiStatus SetNpcSprite(Evt* script, s32 isInitialCall);

ApiStatus DeleteVirtualEntity(Evt* script, s32 isInitialCall);
ApiStatus SetVirtualEntityPosition(Evt* script, s32 isInitialCall);
ApiStatus SetVirtualEntityScale(Evt* script, s32 isInitialCall);
ApiStatus SetVirtualEntityRotation(Evt* script, s32 isInitialCall);
ApiStatus SetVirtualEntityJumpGravity(Evt* script, s32 isInitialCall);
ApiStatus SetVirtualEntityFlags(Evt* script, s32 isInitialCall);
ApiStatus GetVirtualEntityPosition(Evt* script, s32 isInitialCall);
ApiStatus VirtualEntityJumpTo(Evt* script, s32 isInitialCall);
ApiStatus func_802D2884(Evt* script, s32 isInitialCall);
ApiStatus func_802D2C14(Evt* script, s32 isInitialCall);
ApiStatus func_802D7B10(Evt* script, s32 isInitialCall);
ApiStatus ShowConsumableChoicePopup(Evt* script, s32 isInitialCall);
ApiStatus func_80045900(Evt* script, s32 isInitialCall);
ApiStatus ShowKeyChoicePopup(Evt* script, s32 isInitialCall);
ApiStatus CloseChoicePopup(Evt* script, s32 isInitialCall);
ApiStatus func_802D2B6C(Evt* script, s32 isInitialCall);
ApiStatus func_80045838(Evt* script, s32 isInitialCall);
ApiStatus ModifyGlobalOverrideFlags(Evt* script, s32 isInitialCall);
ApiStatus func_802CF56C(Evt* script, s32 isInitialCall);
ApiStatus func_802CA988(Evt* script, s32 isInitialCall);
ApiStatus func_802CDE68(Evt* script, s32 isInitialCall);
ApiStatus func_802D8248(Evt* script, s32 isInitialCall);
ApiStatus func_802D286C(Evt* script, s32 isInitialCall);
ApiStatus func_802D2520(Evt* script, s32 isInitialCall);
ApiStatus PushSong(Evt* script, s32 isInitialCall);
ApiStatus PopSong(Evt* script, s32 isInitialCall);
ApiStatus func_802D62E4(Evt* script, s32 isInitialCall);
ApiStatus func_80044238(Evt* script, s32 isInitialCall);
ApiStatus MakeLocalVertexCopy(Evt* script, s32 isInitialCall);
ApiStatus SetCustomGfxBuilders(Evt* script, s32 isInitialCall);
ApiStatus SetModelCustomGfx(Evt* script, s32 isInitialCall);
ApiStatus SetNpcPaletteSwapMode(Evt* script, s32 isInitialCall);
ApiStatus SetNpcPaletteSwapping(Evt* script, s32 isInitialCall);
ApiStatus MakeTransformGroup(Evt* script, s32 isInitialCall);

extern EvtSource EnemyNpcHit;
extern EvtSource EnemyNpcDefeat;

#endif
