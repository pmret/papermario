.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

#ifndef SHIFT

.section .bss

dlabel PulseStoneNotificationCallback
.space 4

dlabel D_8010C924
.space 4

dlabel D_8010C928
.space 4

dlabel D_8010C92C
.space 4

dlabel wPartnerNpc
.space 4

dlabel TweesterTouchingPlayer
.space 4

dlabel D_8010C938
.space 4

dlabel ISpyNotificationCallback
.space 4

dlabel TalkNotificationCallback
.space 4

dlabel gSpinHistoryBufferPos
.space 4

dlabel D_8010C948
.space 4

dlabel D_8010C94C
.space 4

dlabel D_8010C950
.space 4

dlabel TweesterTouchingPartner
.space 4

dlabel InteractNotificationCallback
.space 4

dlabel PrevPlayerDirection
.space 4

dlabel JumpedOnSwitchX
.space 4

dlabel D_8010C964
.space 4

dlabel D_8010C968
.space 4

dlabel PeachDisguiseNpcIndex
.space 4

dlabel D_8010C970
.space 4

dlabel D_8010C974
.space 4

dlabel NpcHitQueryColliderID
.space 4

dlabel JumpedOnSwitchZ
.space 4

dlabel D_8010C980
.space 4

dlabel D_8010C984
.space 4

dlabel D_8010C988
.space 4

dlabel D_8010C98C
.space 4

dlabel D_8010C990
.space 4

dlabel D_8010C994
.space 0x0000000c

dlabel D_8010C9A0
.space 4

dlabel D_8010C9A4
.space 0x0000000c

dlabel D_8010C9B0
.space 4

dlabel D_8010C9B4
.space 0x0000000c

#endif
