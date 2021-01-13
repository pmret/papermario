.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_8A9F10
/* 8A9F10 80240500 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x18)
/* 8A9F14 80240504 8442A568 */  lh        $v0, %lo(gCollisionStatus+0x18)($v0)
/* 8A9F18 80240508 04400002 */  bltz      $v0, .L80240514
/* 8A9F1C 8024050C 24020001 */   addiu    $v0, $zero, 1
/* 8A9F20 80240510 AC820088 */  sw        $v0, 0x88($a0)
.L80240514:
/* 8A9F24 80240514 03E00008 */  jr        $ra
/* 8A9F28 80240518 24020002 */   addiu    $v0, $zero, 2
/* 8A9F2C 8024051C 00000000 */  nop
