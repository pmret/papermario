.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel StartRumbleWithParams
/* 19667C 80267D9C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 196680 80267DA0 AFB10014 */  sw    $s1, 0x14($sp)
/* 196684 80267DA4 0080882D */  daddu $s1, $a0, $zero
/* 196688 80267DA8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 19668C 80267DAC AFB00010 */  sw    $s0, 0x10($sp)
/* 196690 80267DB0 8E30000C */  lw    $s0, 0xc($s1)
/* 196694 80267DB4 8E050000 */  lw    $a1, ($s0)
/* 196698 80267DB8 0C0B1EAF */  jal   get_variable
/* 19669C 80267DBC 26100004 */   addiu $s0, $s0, 4
/* 1966A0 80267DC0 0220202D */  daddu $a0, $s1, $zero
/* 1966A4 80267DC4 8E050000 */  lw    $a1, ($s0)
/* 1966A8 80267DC8 0C0B1EAF */  jal   get_variable
/* 1966AC 80267DCC 0040802D */   daddu $s0, $v0, $zero
/* 1966B0 80267DD0 0200202D */  daddu $a0, $s0, $zero
/* 1966B4 80267DD4 0C00A3C2 */  jal   start_rumble
/* 1966B8 80267DD8 0040282D */   daddu $a1, $v0, $zero
/* 1966BC 80267DDC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1966C0 80267DE0 8FB10014 */  lw    $s1, 0x14($sp)
/* 1966C4 80267DE4 8FB00010 */  lw    $s0, 0x10($sp)
/* 1966C8 80267DE8 24020002 */  addiu $v0, $zero, 2
/* 1966CC 80267DEC 03E00008 */  jr    $ra
/* 1966D0 80267DF0 27BD0020 */   addiu $sp, $sp, 0x20

