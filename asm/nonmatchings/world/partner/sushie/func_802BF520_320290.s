.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BF520_320290
/* 320290 802BF520 24020018 */  addiu     $v0, $zero, 0x18
/* 320294 802BF524 A48200A8 */  sh        $v0, 0xa8($a0)
/* 320298 802BF528 24020024 */  addiu     $v0, $zero, 0x24
/* 32029C 802BF52C A48200A6 */  sh        $v0, 0xa6($a0)
/* 3202A0 802BF530 3C020001 */  lui       $v0, 1
/* 3202A4 802BF534 AC820080 */  sw        $v0, 0x80($a0)
/* 3202A8 802BF538 3C01802C */  lui       $at, %hi(D_802BFEEC)
/* 3202AC 802BF53C AC20FEEC */  sw        $zero, %lo(D_802BFEEC)($at)
/* 3202B0 802BF540 3C01802C */  lui       $at, %hi(D_802BFEE4)
/* 3202B4 802BF544 AC20FEE4 */  sw        $zero, %lo(D_802BFEE4)($at)
/* 3202B8 802BF548 3C01802C */  lui       $at, %hi(D_802BFEE8)
/* 3202BC 802BF54C AC20FEE8 */  sw        $zero, %lo(D_802BFEE8)($at)
/* 3202C0 802BF550 3C01802C */  lui       $at, %hi(D_802BFEF0)
/* 3202C4 802BF554 AC20FEF0 */  sw        $zero, %lo(D_802BFEF0)($at)
/* 3202C8 802BF558 3C01802C */  lui       $at, %hi(D_802BFEF4)
/* 3202CC 802BF55C AC20FEF4 */  sw        $zero, %lo(D_802BFEF4)($at)
/* 3202D0 802BF560 03E00008 */  jr        $ra
/* 3202D4 802BF564 00000000 */   nop
