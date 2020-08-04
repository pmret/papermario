.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055464
/* 030864 80055464 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030868 80055468 AFB00010 */  sw    $s0, 0x10($sp)
/* 03086C 8005546C 0080802D */  daddu $s0, $a0, $zero
/* 030870 80055470 AFB10014 */  sw    $s1, 0x14($sp)
/* 030874 80055474 AFBF0018 */  sw    $ra, 0x18($sp)
/* 030878 80055478 0C01430C */  jal   func_80050C30
/* 03087C 8005547C 00A0882D */   daddu $s1, $a1, $zero
/* 030880 80055480 14400003 */  bnez  $v0, .L80055490
/* 030884 80055484 0200202D */   daddu $a0, $s0, $zero
/* 030888 80055488 0C014328 */  jal   func_80050CA0
/* 03088C 8005548C 0220282D */   daddu $a1, $s1, $zero
.L80055490:
/* 030890 80055490 8FBF0018 */  lw    $ra, 0x18($sp)
/* 030894 80055494 8FB10014 */  lw    $s1, 0x14($sp)
/* 030898 80055498 8FB00010 */  lw    $s0, 0x10($sp)
/* 03089C 8005549C 03E00008 */  jr    $ra
/* 0308A0 800554A0 27BD0020 */   addiu $sp, $sp, 0x20

