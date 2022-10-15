.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .bss

dlabel D_8010C920
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

dlabel D_8010C93C
.space 4

dlabel D_8010C940
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

dlabel D_8010C958
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

dlabel D_8010C978
.space 2

dlabel D_8010C97A
.space 2

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

dlabel D_8010C9C0
.space 4

dlabel D_8010C9C4
.space 4

dlabel D_8010C9C8
.space 0x330

dlabel D_8010CCF8
.space 2

dlabel D_8010CCFA
.space 2

dlabel D_8010CCFC
.space 2

dlabel D_8010CCFE
.space 2

dlabel D_8010CD00
.space 4

dlabel D_8010CD04
.space 0xC

dlabel D_8010CD10
.space 2

dlabel D_8010CD12
.space 2

dlabel D_8010CD14
.space 0xC

dlabel D_8010CD20
.space 4

dlabel D_8010CD24
.space 0xC
