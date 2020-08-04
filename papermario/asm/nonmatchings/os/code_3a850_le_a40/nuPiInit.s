.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuPiInit
/* 03A850 8005F450 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03A854 8005F454 24040096 */  addiu $a0, $zero, 0x96
/* 03A858 8005F458 3C05800B */  lui   $a1, 0x800b
/* 03A85C 8005F45C 24A5C5D0 */  addiu $a1, $a1, -0x3a30
/* 03A860 8005F460 3C06800B */  lui   $a2, 0x800b
/* 03A864 8005F464 24C6C5E8 */  addiu $a2, $a2, -0x3a18
/* 03A868 8005F468 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03A86C 8005F46C 0C018278 */  jal   osCreatePiManager
/* 03A870 8005F470 24070032 */   addiu $a3, $zero, 0x32
/* 03A874 8005F474 0C0183C4 */  jal   osCartRomInit
/* 03A878 8005F478 00000000 */   nop   
/* 03A87C 8005F47C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03A880 8005F480 3C01800A */  lui   $at, 0x800a
/* 03A884 8005F484 AC22A638 */  sw    $v0, -0x59c8($at)
/* 03A888 8005F488 03E00008 */  jr    $ra
/* 03A88C 8005F48C 27BD0018 */   addiu $sp, $sp, 0x18

