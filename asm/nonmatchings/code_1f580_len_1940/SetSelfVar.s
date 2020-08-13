.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetSelfVar
/* 02065C 8004525C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020660 80045260 AFB00010 */  sw    $s0, 0x10($sp)
/* 020664 80045264 0080802D */  daddu $s0, $a0, $zero
/* 020668 80045268 AFBF001C */  sw    $ra, 0x1c($sp)
/* 02066C 8004526C AFB20018 */  sw    $s2, 0x18($sp)
/* 020670 80045270 AFB10014 */  sw    $s1, 0x14($sp)
/* 020674 80045274 8E11000C */  lw    $s1, 0xc($s0)
/* 020678 80045278 8E120148 */  lw    $s2, 0x148($s0)
/* 02067C 8004527C 8E250000 */  lw    $a1, ($s1)
/* 020680 80045280 0C0B1EAF */  jal   get_variable
/* 020684 80045284 26310004 */   addiu $s1, $s1, 4
/* 020688 80045288 0200202D */  daddu $a0, $s0, $zero
/* 02068C 8004528C 8E250000 */  lw    $a1, ($s1)
/* 020690 80045290 0C0B1EAF */  jal   get_variable
/* 020694 80045294 0040802D */   daddu $s0, $v0, $zero
/* 020698 80045298 00108080 */  sll   $s0, $s0, 2
/* 02069C 8004529C 02509021 */  addu  $s2, $s2, $s0
/* 0206A0 800452A0 AE42006C */  sw    $v0, 0x6c($s2)
/* 0206A4 800452A4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0206A8 800452A8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0206AC 800452AC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0206B0 800452B0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0206B4 800452B4 24020002 */  addiu $v0, $zero, 2
/* 0206B8 800452B8 03E00008 */  jr    $ra
/* 0206BC 800452BC 27BD0020 */   addiu $sp, $sp, 0x20

