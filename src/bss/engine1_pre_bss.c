#define NO_EXTERN_VARIABLES
#include "common.h"
// DON'T DARE to put include headers here containing extern declarations...
// This will ruin the ordering of bss symbols below if you care about matching.

#ifndef SHIFT

BSS UNK_FUN_PTR(PulseStoneNotificationCallback);
BSS void* D_8010C924;
BSS f32 D_8010C928;
BSS s32 D_8010C92C;
BSS Npc* wPartnerNpc;
BSS Entity* TweesterTouchingPlayer;
BSS f32 PlayerNormalYaw;
BSS UNK_FUN_PTR(ISpyNotificationCallback);
BSS UNK_FUN_PTR(TalkNotificationCallback);
BSS s32 gSpinHistoryBufferPos;
BSS s32 D_8010C948;
BSS s32 NpcHitQueryBehindRightY;
BSS s32 D_8010C950;
BSS Entity* TweesterTouchingPartner;
BSS UNK_FUN_PTR(InteractNotificationCallback);
BSS s32 PrevPlayerDirection;
BSS f32 JumpedOnSwitchX;
BSS s32 D_8010C964;
BSS s32 NpcHitQueryBehindCollider;
BSS s32 PeachDisguiseNpcIndex;
BSS s32 NpcHitQueryAheadY;
BSS s32 NpcHitQueryBehindLeftY;
BSS s32 NpcHitQueryColliderID;
BSS f32 JumpedOnSwitchZ;
BSS s32 PlayerRunStateTime;
BSS f32 StepUpLastYaw;
BSS s32 D_8010C988;
BSS s32 NpcHitQueryAheadCollider;
BSS f32 PlayerNormalPitch;

#endif
