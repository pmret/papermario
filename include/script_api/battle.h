#ifndef _SCRIPT_API_BATTLE_H_
#define _SCRIPT_API_BATTLE_H_

#include "common_structs.h"
#include "evt.h"

#include "script_api/common.h"

ApiStatus EnablePartnerBlur(Evt* script, s32 isInitialCall);
ApiStatus DisablePartnerBlur(Evt* script, s32 isInitialCall);
ApiStatus UseBattleCamPreset(Evt* script, s32 isInitialCall);
ApiStatus SetBattleCamTarget(Evt* script, s32 isInitialCall);
ApiStatus SetBattleCamOffsetZ(Evt* script, s32 isInitialCall);
ApiStatus AddBattleCamOffsetZ(Evt* script, s32 isInitialCall);
ApiStatus SetBattleCamYaw(Evt* script, s32 isInitialCall);
ApiStatus BattleCamTargetActor(Evt* script, s32 isInitialCall);
ApiStatus MoveBattleCamOver(Evt* script, s32 isInitialCall);
ApiStatus SetBattleCamZoom(Evt* script, s32 isInitialCall);
ApiStatus AddBattleCamZoom(Evt* script, s32 isInitialCall);
ApiStatus FreezeBattleCam(Evt* script, s32 isInitialCall);
ApiStatus ShowMessageBox(Evt* script, s32 isInitialCall);
ApiStatus ShowVariableMessageBox(Evt* script, s32 isInitialCall);
ApiStatus IsMessageBoxDisplayed(Evt* script, s32 isInitialCall);
ApiStatus WaitForMessageBoxDone(Evt* script, s32 isInitialCall);
ApiStatus ForceCloseMessageBox(Evt* script, s32 isInitialCall);
ApiStatus SetMessageBoxDuration(Evt* script, s32 isInitialCall);
ApiStatus ItemDamageEnemy(Evt* script, s32 isInitialCall);
ApiStatus ItemAfflictEnemy(Evt* script, s32 isInitialCall);
ApiStatus ItemCheckHit(Evt* script, s32 isInitialCall);
ApiStatus ActorSpeak(Evt* script, s32 isInitialCall);
ApiStatus EndActorSpeech(Evt* script, s32 isInitialCall);
ApiStatus ShowBattleChoice(Evt* script, s32 isInitialCall);
ApiStatus OverrideBattleDmaDest(Evt* script, s32 isInitialCall);
ApiStatus LoadBattleDmaData(Evt* script, s32 isInitialCall);
ApiStatus func_802536A8(Evt* script, s32 isInitialCall);
ApiStatus func_80253734(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtActor(Evt* script, s32 isInitialCall);
ApiStatus PlaySoundAtPart(Evt* script, s32 isInitialCall);
ApiStatus SetForegroundModelsVisibleUnchecked(Evt* script, s32 isInitialCall);
ApiStatus SetForegroundModelsVisible(Evt* script, s32 isInitialCall);
ApiStatus MakeStatusField(Evt* script, s32 isInitialCall);
ApiStatus MultiplyByActorScale(Evt* script, s32 isInitialCall);
ApiStatus MultiplyVec2ByActorScale(Evt* script, s32 isInitialCall);
ApiStatus MultiplyVec3ByActorScale(Evt* script, s32 isInitialCall);
ApiStatus ApplyShrinkFromOwner(Evt* script, s32 isInitialCall);
ApiStatus StartRumble(Evt* script, s32 isInitialCall);
ApiStatus HasMerleeCastsLeft(Evt* script, s32 isInitialCall);
ApiStatus FXRecoverHP(Evt* script, s32 isInitialCall);
ApiStatus FXRecoverFP(Evt* script, s32 isInitialCall);
ApiStatus IncrementPlayerHP(Evt* script, s32 isInitialCall);
ApiStatus IncrementPlayerFP(Evt* script, s32 isInitialCall);
ApiStatus StartRumbleWithParams(Evt* script, s32 isInitialCall);
ApiStatus LoadItemScript(Evt* script, s32 isInitialCall);
ApiStatus LoadFreeItemScript(Evt* script, s32 isInitialCall);
ApiStatus LoadMoveScript(Evt* script, s32 isInitialCall);
ApiStatus LoadActionCommand(Evt* script, s32 isInitialCall);
ApiStatus GetActionSuccess(Evt* script, s32 isInitialCall);
ApiStatus SetActionSuccess(Evt* script, s32 isInitialCall);
ApiStatus GetActionSuccessCopy(Evt* script, s32 isInitialCall);
ApiStatus GetBlockResult(Evt* script, s32 isInitialCall);
ApiStatus CloseActionCommandInfo(Evt* script, s32 isInitialCall);
ApiStatus func_80269470(Evt* script, s32 isInitialCall);
ApiStatus LoadBattleSection(Evt* script, s32 isInitialCall);
ApiStatus GetBattlePhase(Evt* script, s32 isInitialCall);
ApiStatus GetLastElement(Evt* script, s32 isInitialCall);
ApiStatus func_80269EAC(Evt* script, s32 isInitialCall);
ApiStatus func_80269E80(Evt* script, s32 isInitialCall);
ApiStatus SetGoalToHome(Evt* script, s32 isInitialCall);
ApiStatus SetIdleGoalToHome(Evt* script, s32 isInitialCall);
ApiStatus SetGoalToIndex(Evt* script, s32 isInitialCall);
ApiStatus GetIndexFromPos(Evt* script, s32 isInitialCall);
ApiStatus GetIndexFromHome(Evt* script, s32 isInitialCall);
ApiStatus CountPlayerTargets(Evt* script, s32 isInitialCall);
ApiStatus ForceHomePos(Evt* script, s32 isInitialCall);
ApiStatus SetHomePos(Evt* script, s32 isInitialCall);
ApiStatus SetGoalToTarget(Evt* script, s32 isInitialCall);
ApiStatus SetPartGoalToTarget(Evt* script, s32 isInitialCall);
ApiStatus SetGoalToFirstTarget(Evt* script, s32 isInitialCall);
ApiStatus SetGoalPos(Evt* script, s32 isInitialCall);
ApiStatus SetIdleGoal(Evt* script, s32 isInitialCall);
ApiStatus AddGoalPos(Evt* script, s32 isInitialCall);
ApiStatus GetGoalPos(Evt* script, s32 isInitialCall);
ApiStatus GetIdleGoal(Evt* script, s32 isInitialCall);
ApiStatus GetPartTarget(Evt* script, s32 isInitialCall);
ApiStatus GetActorPos(Evt* script, s32 isInitialCall);
ApiStatus GetPartOffset(Evt* script, s32 isInitialCall);
ApiStatus GetPartPos(Evt* script, s32 isInitialCall);
ApiStatus GetHomePos(Evt* script, s32 isInitialCall);
ApiStatus SetActorPos(Evt* script, s32 isInitialCall);
ApiStatus SetPartPos(Evt* script, s32 isInitialCall);
ApiStatus SetEnemyTargetOffset(Evt* script, s32 isInitialCall);
ApiStatus SetAnimation(Evt* script, s32 isInitialCall);
ApiStatus GetAnimation(Evt* script, s32 isInitialCall);
ApiStatus SetAnimationRate(Evt* script, s32 isInitialCall);
ApiStatus SetActorYaw(Evt* script, s32 isInitialCall);
ApiStatus GetActorYaw(Evt* script, s32 isInitialCall);
ApiStatus SetPartYaw(Evt* script, s32 isInitialCall);
ApiStatus GetPartYaw(Evt* script, s32 isInitialCall);
ApiStatus SetActorJumpGravity(Evt* script, s32 isInitialCall);
ApiStatus SetActorIdleJumpGravity(Evt* script, s32 isInitialCall);
ApiStatus SetActorSpeed(Evt* script, s32 isInitialCall);
ApiStatus SetActorIdleSpeed(Evt* script, s32 isInitialCall);
ApiStatus SetPartJumpGravity(Evt* script, s32 isInitialCall);
ApiStatus SetPartMoveSpeed(Evt* script, s32 isInitialCall);
ApiStatus SetJumpAnimations(Evt* script, s32 isInitialCall);
ApiStatus AddActorPos(Evt* script, s32 isInitialCall);
ApiStatus SetActorDispOffset(Evt* script, s32 isInitialCall);
ApiStatus GetPartDispOffset(Evt* script, s32 isInitialCall);
ApiStatus SetPartDispOffset(Evt* script, s32 isInitialCall);
ApiStatus AddPartDispOffset(Evt* script, s32 isInitialCall);
ApiStatus func_8026BF48(Evt* script, s32 isInitialCall);
ApiStatus GetActorVar(Evt* script, s32 isInitialCall);
ApiStatus SetActorVar(Evt* script, s32 isInitialCall);
ApiStatus AddActorVar(Evt* script, s32 isInitialCall);
ApiStatus GetPartMovementVar(Evt* script, s32 isInitialCall);
ApiStatus SetPartMovementVar(Evt* script, s32 isInitialCall);
ApiStatus AddPartMovementVar(Evt* script, s32 isInitialCall);
ApiStatus SetActorRotation(Evt* script, s32 isInitialCall);
ApiStatus SetActorRotationOffset(Evt* script, s32 isInitialCall);
ApiStatus GetActorRotation(Evt* script, s32 isInitialCall);
ApiStatus SetPartRotation(Evt* script, s32 isInitialCall);
ApiStatus SetPartRotationOffset(Evt* script, s32 isInitialCall);
ApiStatus GetPartRotation(Evt* script, s32 isInitialCall);
ApiStatus SetActorScale(Evt* script, s32 isInitialCall);
ApiStatus SetActorScaleModifier(Evt* script, s32 isInitialCall);
ApiStatus GetActorScale(Evt* script, s32 isInitialCall);
ApiStatus SetPartScale(Evt* script, s32 isInitialCall);
ApiStatus GetPartScale(Evt* script, s32 isInitialCall);
ApiStatus GetBattleFlags(Evt* script, s32 isInitialCall);
ApiStatus SetBattleFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetBattleFlags2(Evt* script, s32 isInitialCall);
ApiStatus SetBattleFlagBits2(Evt* script, s32 isInitialCall);
ApiStatus SetActorFlags(Evt* script, s32 isInitialCall);
ApiStatus SetActorFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetActorFlags(Evt* script, s32 isInitialCall);
ApiStatus SetPartFlags(Evt* script, s32 isInitialCall);
ApiStatus SetPartFlagBits(Evt* script, s32 isInitialCall);
ApiStatus SetPartTargetFlags(Evt* script, s32 isInitialCall);
ApiStatus SetPartTargetFlagBits(Evt* script, s32 isInitialCall);
ApiStatus GetPartFlags(Evt* script, s32 isInitialCall);
ApiStatus GetPartTargetFlags(Evt* script, s32 isInitialCall);
ApiStatus SetPartEventFlags(Evt* script, s32 isInitialCall);
ApiStatus SetPartEventBits(Evt* script, s32 isInitialCall);
ApiStatus GetPartEventFlags(Evt* script, s32 isInitialCall);
ApiStatus HPBarToHome(Evt* script, s32 isInitialCall);
ApiStatus HPBarToCurrent(Evt* script, s32 isInitialCall);
ApiStatus func_8026D940(Evt* script, s32 isInitialCall);
ApiStatus func_8026DA94(Evt* script, s32 isInitialCall);
ApiStatus SummonEnemy(Evt* script, s32 isInitialCall);
ApiStatus GetOwnerID(Evt* script, s32 isInitialCall);
ApiStatus SetOwnerID(Evt* script, s32 isInitialCall);
ApiStatus ActorExists(Evt* script, s32 isInitialCall);
ApiStatus func_8026E038(Evt* script, s32 isInitialCall);
ApiStatus SetBattleInputMask(Evt* script, s32 isInitialCall);
ApiStatus SetBattleInputButtons(Evt* script, s32 isInitialCall);
ApiStatus CheckButtonPress(Evt* script, s32 isInitialCall);
ApiStatus CheckButtonHeld(Evt* script, s32 isInitialCall);
ApiStatus CheckButtonDown(Evt* script, s32 isInitialCall);
ApiStatus GetBattleState(Evt* script, s32 isInitialCall);
ApiStatus PlayerCreateTargetList(Evt* script, s32 isInitialCall);
ApiStatus EnemyCreateTargetList(Evt* script, s32 isInitialCall);
ApiStatus InitTargetIterator(Evt* script, s32 isInitialCall);
ApiStatus SetOwnerTarget(Evt* script, s32 isInitialCall);
ApiStatus ChooseNextTarget(Evt* script, s32 isInitialCall);
ApiStatus GetTargetListLength(Evt* script, s32 isInitialCall);
ApiStatus GetOwnerTarget(Evt* script, s32 isInitialCall);
ApiStatus func_8026E914(Evt* script, s32 isInitialCall);
ApiStatus GetPlayerActorID(Evt* script, s32 isInitialCall);
ApiStatus GetDistanceToGoal(Evt* script, s32 isInitialCall);
ApiStatus func_8026EA7C(Evt* script, s32 isInitialCall);
ApiStatus AddActorDecoration(Evt* script, s32 isInitialCall);
ApiStatus RemoveActorDecoration(Evt* script, s32 isInitialCall);
ApiStatus ModifyActorDecoration(Evt* script, s32 isInitialCall);
ApiStatus UseIdleAnimation(Evt* script, s32 isInitialCall);
ApiStatus GetStatusFlags(Evt* script, s32 isInitialCall);
ApiStatus RemovePlayerBuffs(Evt* script, s32 isInitialCall);
ApiStatus SetPartAlpha(Evt* script, s32 isInitialCall);
ApiStatus CreatePartShadow(Evt* script, s32 isInitialCall);
ApiStatus RemovePartShadow(Evt* script, s32 isInitialCall);
ApiStatus func_8026F60C(Evt* script, s32 isInitialCall);
ApiStatus SetBattleVar(Evt* script, s32 isInitialCall);
ApiStatus GetBattleVar(Evt* script, s32 isInitialCall);
ApiStatus ResetAllActorSounds(Evt* script, s32 isInitialCall);
ApiStatus SetActorSounds(Evt* script, s32 isInitialCall);
ApiStatus ResetActorSounds(Evt* script, s32 isInitialCall);
ApiStatus SetPartSounds(Evt* script, s32 isInitialCall);
ApiStatus SetActorType(Evt* script, s32 isInitialCall);
ApiStatus ShowShockEffect(Evt* script, s32 isInitialCall);
ApiStatus GetActorAttackBoost(Evt* script, s32 isInitialCall);
ApiStatus GetActorDefenseBoost(Evt* script, s32 isInitialCall);
ApiStatus BoostAttack(Evt* script, s32 isInitialCall);
ApiStatus BoostDefense(Evt* script, s32 isInitialCall);
ApiStatus VanishActor(Evt* script, s32 isInitialCall);
ApiStatus ElectrifyActor(Evt* script, s32 isInitialCall);
ApiStatus HealActor(Evt* script, s32 isInitialCall);
ApiStatus WaitForBuffDone(Evt* script, s32 isInitialCall);
ApiStatus CopyBuffs(Evt* script, s32 isInitialCall);
ApiStatus GetMenuSelection(Evt* script, s32 isInitialCall);
ApiStatus PlayerFallToGoal(Evt* script, s32 isInitialCall);
ApiStatus PlayerLandJump(Evt* script, s32 isInitialCall);
ApiStatus PlayerRunToGoal(Evt* script, s32 isInitialCall);
ApiStatus CancelablePlayerRunToGoal(Evt* script, s32 isInitialCall);
ApiStatus GetPlayerHP(Evt* script, s32 isInitialCall);
ApiStatus PlayerDamageEnemy(Evt* script, s32 isInitialCall);
ApiStatus PlayerPowerBounceEnemy(Evt* script, s32 isInitialCall);
ApiStatus PlayerTestEnemy(Evt* script, s32 isInitialCall);
ApiStatus DispatchDamagePlayerEvent(Evt* script, s32 isInitialCall);
ApiStatus EnablePlayerBlur(Evt* script, s32 isInitialCall);
ApiStatus func_80274A18(Evt* script, s32 isInitialCall);
ApiStatus func_802752AC(Evt* script, s32 isInitialCall);
ApiStatus func_80275F00(Evt* script, s32 isInitialCall);
ApiStatus DidActionSucceed(Evt* script, s32 isInitialCall);
ApiStatus BindTakeTurn(Evt* script, s32 isInitialCall);
ApiStatus PauseTakeTurn(Evt* script, s32 isInitialCall);
ApiStatus ResumeTakeTurn(Evt* script, s32 isInitialCall);
ApiStatus BindIdle(Evt* script, s32 isInitialCall);
ApiStatus EnableIdleScript(Evt* script, s32 isInitialCall);
ApiStatus BindHandleEvent(Evt* script, s32 isInitialCall);
ApiStatus BindNextTurn(Evt* script, s32 isInitialCall);
ApiStatus JumpToGoal(Evt* script, s32 isInitialCall);
ApiStatus IdleJumpToGoal(Evt* script, s32 isInitialCall);
ApiStatus JumpWithBounce(Evt* script, s32 isInitialCall);
ApiStatus LandJump(Evt* script, s32 isInitialCall);
ApiStatus FallToGoal(Evt* script, s32 isInitialCall);
ApiStatus RunToGoal(Evt* script, s32 isInitialCall);
ApiStatus IdleRunToGoal(Evt* script, s32 isInitialCall);
ApiStatus JumpPartTo(Evt* script, s32 isInitialCall);
ApiStatus FallPartTo(Evt* script, s32 isInitialCall);
ApiStatus LandJumpPart(Evt* script, s32 isInitialCall);
ApiStatus RunPartTo(Evt* script, s32 isInitialCall);
ApiStatus FlyToGoal(Evt* script, s32 isInitialCall);
ApiStatus IdleFlyToGoal(Evt* script, s32 isInitialCall);
ApiStatus FlyPartTo(Evt* script, s32 isInitialCall);
ApiStatus GetLastEvent(Evt* script, s32 isInitialCall);
ApiStatus SetTargetActor(Evt* script, s32 isInitialCall);
ApiStatus SetEnemyHP(Evt* script, s32 isInitialCall);
ApiStatus GetActorHP(Evt* script, s32 isInitialCall);
ApiStatus GetEnemyMaxHP(Evt* script, s32 isInitialCall);
ApiStatus RemoveActor(Evt* script, s32 isInitialCall);
ApiStatus DropStarPoints(Evt* script, s32 isInitialCall);
ApiStatus SetDefenseTable(Evt* script, s32 isInitialCall);
ApiStatus SetStatusTable(Evt* script, s32 isInitialCall);
ApiStatus SetIdleAnimations(Evt* script, s32 isInitialCall);
ApiStatus EnemyDamageTarget(Evt* script, s32 isInitialCall);
ApiStatus EnemyFollowupAfflictTarget(Evt* script, s32 isInitialCall);
ApiStatus EnemyTestTarget(Evt* script, s32 isInitialCall);
ApiStatus DispatchDamageEvent(Evt* script, s32 isInitialCall);
ApiStatus DispatchEvent(Evt* script, s32 isInitialCall);
ApiStatus func_8027D2D8(Evt* script, s32 isInitialCall);
ApiStatus SetTargetOffset(Evt* script, s32 isInitialCall);
ApiStatus func_8027D4C8(Evt* script, s32 isInitialCall);
ApiStatus EnableActorBlur(Evt* script, s32 isInitialCall);
ApiStatus AfflictActor(Evt* script, s32 isInitialCall);
ApiStatus func_8027D75C(Evt* script, s32 isInitialCall);
ApiStatus GetEncounterState(Evt* script, s32 isInitialCall);
ApiStatus YieldTurn(Evt* script, s32 isInitialCall);
ApiStatus SetActorSize(Evt* script, s32 isInitialCall);
ApiStatus GetActorSize(Evt* script, s32 isInitialCall);
ApiStatus SetPartSize(Evt* script, s32 isInitialCall);
ApiStatus GetOriginalActorType(Evt* script, s32 isInitialCall);
ApiStatus GetCurrentActorType(Evt* script, s32 isInitialCall);
ApiStatus GetLastDamage(Evt* script, s32 isInitialCall);
ApiStatus EnableActorGlow(Evt* script, s32 isInitialCall);
ApiStatus WasStatusInflicted(Evt* script, s32 isInitialCall);
ApiStatus CopyStatusEffects(Evt* script, s32 isInitialCall);
ApiStatus ClearStatusEffects(Evt* script, s32 isInitialCall);
ApiStatus MakeOwnerTargetIndex(Evt* script, s32 isInitialCall);
ApiStatus GetActorLevel(Evt* script, s32 isInitialCall);
ApiStatus PartnerDamageEnemy(Evt* script, s32 isInitialCall);
ApiStatus PartnerAfflictEnemy(Evt* script, s32 isInitialCall);
ApiStatus PartnerPowerBounceEnemy(Evt* script, s32 isInitialCall);
ApiStatus PartnerTestEnemy(Evt* script, s32 isInitialCall);
ApiStatus DeletePartner(Evt* script, s32 isInitialCall);
ApiStatus GetDamageIntensity(Evt* script, s32 isInitialCall);
ApiStatus AddEffectOffset(Evt* script, s32 isInitialCall);
ApiStatus LoadStarPowerScript(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_B(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_F(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_M(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_G(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_I(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_H(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_N(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_C(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_D(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_E(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_J(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_K(Evt* script, s32 isInitialCall);
ApiStatus CamPresetUpdate_L(Evt* script, s32 isInitialCall);
ApiStatus SetBattleCamPos(Evt* script, s32 isInitialCall);
ApiStatus SetBattleCamParam(Evt* script, s32 isInitialCall);
ApiStatus func_8026DF88(Evt* script, s32 isInitialCall);
ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);
ApiStatus func_8024CE9C(Evt* script, s32 isInitialCall);
ApiStatus func_802CABE8(Evt* script, s32 isInitialCall);
ApiStatus func_802CAE50(Evt* script, s32 isInitialCall);
ApiStatus func_802A9000_430020(Evt* script, s32 isInitialCall);
ApiStatus func_802A9120_421B10(Evt* script, s32 isInitialCall);
ApiStatus func_802807D0(Evt* script, s32 isInitialCall);
ApiStatus func_802694A4(Evt* script, s32 isInitialCall);
ApiStatus func_80269524(Evt* script, s32 isInitialCall);
ApiStatus func_80269550(Evt* script, s32 isInitialCall);
ApiStatus func_8026919C(Evt* script, s32 isInitialCall);
ApiStatus func_80280818(Evt* script, s32 isInitialCall); ///< YieldTurn copy
ApiStatus func_8024ECF8(Evt* script, s32 isInitialCall);
ApiStatus UseBattleCamPresetImmediately(Evt* script, s32 isInitialCall);
ApiStatus UseBattleCamPresetWait(Evt* script, s32 isInitialCall);
ApiStatus func_8027D32C(Evt* script, s32 isInitialCall);
ApiStatus GetActionCommandResult(Evt* script, s32 isInitialCall);
ApiStatus CreateNpc(Evt* script, s32 isInitialCall);
ApiStatus func_802535B4(Evt* script, s32 isInitialCall);
ApiStatus func_80276EFC(Evt* script, s32 isInitialCall);
ApiStatus ShowStartRecoveryShimmer(Evt* script, s32 isInitialCall);
ApiStatus ShowRecoveryShimmer(Evt* script, s32 isInitialCall);
ApiStatus func_80273444(Evt* script, s32 isInitialCall);
ApiStatus GetActionCommandMode(Evt* script, s32 isInitialCall);
ApiStatus SetActionCommandMode(Evt* script, s32 isInitialCall);
ApiStatus SetCommandAutoSuccess(Evt* script, s32 isInitialCall);
ApiStatus func_802693F0(Evt* script, s32 isInitialCall);
ApiStatus WaitForState(Evt* script, s32 isInitialCall);
ApiStatus func_8026E020(Evt* script, s32 isInitialCall);
ApiStatus GetActionResult(Evt* script, s32 isInitialCall);
ApiStatus SetBattleState(Evt* script, s32 isInitialCall);
ApiStatus func_8027D434(Evt* script, s32 isInitialCall);
ApiStatus func_8026F1A0(Evt* script, s32 isInitialCall);
ApiStatus PlayLoopingSoundAtActor(Evt* script, s32 isInitialCall);
ApiStatus StopLoopingSoundAtActor(Evt* script, s32 isInitialCall);
ApiStatus func_8026ED20(Evt* script, s32 isInitialCall);
ApiStatus func_8026EBF8(Evt* script, s32 isInitialCall);
ApiStatus SetupMashMeter(Evt* script, s32 isInitialCall);
ApiStatus SetActionResult(Evt* script, s32 isInitialCall);
ApiStatus BattleCamTargetActorPart(Evt* script, s32 isInitialCall);
ApiStatus func_802537C0(Evt* script, s32 isInitialCall);
ApiStatus CancelEnemyTurn(Evt* script, s32 isInitialCall);
ApiStatus GetAnimatedNodeRotation(Evt* script, s32 isInitialCall);
ApiStatus GetAnimatedNodePosition(Evt* script, s32 isInitialCall);
ApiStatus DispatchEventPlayer(Evt* script, s32 isInitialCall);

extern EvtScript PlayerScriptDispatcher;
extern EvtScript PeachScriptDispatcher;
extern EvtScript ExecutePlayerAction;
extern EvtScript ExecutePeachAction;
extern EvtScript HandleEvent_Player;
extern EvtScript BtlPutPartnerAway;
extern EvtScript BtlBringPartnerOut;
extern EvtScript MarioEnterStage;
extern EvtScript PeachEnterStage;
extern EvtScript PlayerFirstStrike;
extern EvtScript StartDefend;
extern EvtScript RunAwayStart;
extern EvtScript RunAwayFail;
extern EvtScript RunAwayReset;
extern EvtScript PlayEatFX;
extern EvtScript PlayDrinkFX;
extern EvtScript UseLifeShroom;
extern EvtScript MerleeRunOut;
extern EvtScript MerleeAttackBonus;
extern EvtScript MerleeDefenseBonus;
extern EvtScript MerleeExpBonus;
extern EvtScript PlayerHappy;
extern EvtScript DoDizzyAttack;
extern EvtScript RegainAbility;
extern EvtScript UseMystery;
extern EvtScript DoSleepHit;
extern EvtScript DoDizzyHit;
extern EvtScript DoParalyzeHit;
extern EvtScript DoPoisonHit;
extern EvtScript DoStopHit;
extern EvtScript DoFreezeHit;
extern EvtScript DoShrinkHit;
extern EvtScript ForceNextTarget;
extern EvtScript DoNormalHit;
extern EvtScript DoRunAway;
extern EvtScript DoPartnerSpikeContact;
extern EvtScript D_80295350;
extern EvtScript DoPartnerBurnContact;
extern EvtScript DoPartnerRecover;
extern EvtScript D_80295744;
extern EvtScript D_8029621C;
extern EvtScript D_802977BC;
extern EvtScript D_80296014;
extern EvtScript DoPartnerBlock;
extern EvtScript D_802976E8;
extern EvtScript D_8029C12C;
extern EvtScript DoBurnHit;
extern EvtScript DoShockHit;
extern EvtScript D_8029A76C;
extern EvtScript D_80294720;
extern EvtScript DoImmune;
extern EvtScript DoDeath;
extern EvtScript D_8029AF08;
extern EvtScript Collapse;
extern EvtScript DoScareAway;
extern EvtScript DoSpinSmashHit;
extern EvtScript D_8029BBB4;
extern EvtScript DoJumpBack;
extern EvtScript DoReturnHome;
extern EvtScript DoRecover;
extern EvtScript D_8029C0A4;
extern EvtScript DoAirLift;
extern EvtScript DoBlowAway;
extern EvtScript Rumble_1;
extern EvtScript Rumble_2;
extern EvtScript Rumble_3;
extern EvtScript Rumble_4;
extern EvtScript Rumble_5;
extern EvtScript Rumble_6;
extern EvtScript Rumble_7;
extern EvtScript Rumble_Unused_1;
extern EvtScript Rumble_Unused_2;
extern EvtScript Rumble_Unused_3;
extern EvtScript Rumble_Unused_4;
extern EvtScript CamPreset_A;
extern EvtScript CamPreset_B;
extern EvtScript CamPreset_C;
extern EvtScript CamPreset_D;
extern EvtScript CamPreset_E;
extern EvtScript CamPreset_F;
extern EvtScript CamPreset_G;
extern EvtScript CamPreset_H;
extern EvtScript CamPreset_I;
extern EvtScript CamPreset_J;
extern EvtScript CamPreset_K;
extern EvtScript CamPreset_L;
extern EvtScript CamPreset_M;
extern EvtScript CamPreset_N;

#endif
