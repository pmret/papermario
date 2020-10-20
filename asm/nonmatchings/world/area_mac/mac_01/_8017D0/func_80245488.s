.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245488
/* 805D08 80245488 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 805D0C 8024548C AFBF0010 */  sw        $ra, 0x10($sp)
/* 805D10 80245490 8C82000C */  lw        $v0, 0xc($a0)
/* 805D14 80245494 0C0B1EAF */  jal       get_variable
/* 805D18 80245498 8C450000 */   lw       $a1, ($v0)
/* 805D1C 8024549C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 805D20 802454A0 3C018026 */  lui       $at, 0x8026
/* 805D24 802454A4 AC228404 */  sw        $v0, -0x7bfc($at)
/* 805D28 802454A8 24020002 */  addiu     $v0, $zero, 2
/* 805D2C 802454AC 03E00008 */  jr        $ra
/* 805D30 802454B0 27BD0018 */   addiu    $sp, $sp, 0x18
