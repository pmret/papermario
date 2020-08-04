.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel bind_enemy_ai
/* 019D4C 8003E94C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 019D50 8003E950 AFB00010 */  sw    $s0, 0x10($sp)
/* 019D54 8003E954 0080802D */  daddu $s0, $a0, $zero
/* 019D58 8003E958 AFBF0018 */  sw    $ra, 0x18($sp)
/* 019D5C 8003E95C AFB10014 */  sw    $s1, 0x14($sp)
/* 019D60 8003E960 8E02003C */  lw    $v0, 0x3c($s0)
/* 019D64 8003E964 10400004 */  beqz  $v0, .L8003E978
/* 019D68 8003E968 00A0882D */   daddu $s1, $a1, $zero
/* 019D6C 8003E96C 8C440144 */  lw    $a0, 0x144($v0)
/* 019D70 8003E970 0C0B102B */  jal   kill_script_by_ID
/* 019D74 8003E974 00000000 */   nop   
.L8003E978:
/* 019D78 8003E978 0220202D */  daddu $a0, $s1, $zero
/* 019D7C 8003E97C 2405000A */  addiu $a1, $zero, 0xa
/* 019D80 8003E980 0000302D */  daddu $a2, $zero, $zero
/* 019D84 8003E984 0C0B0CF8 */  jal   start_script
/* 019D88 8003E988 AE040024 */   sw    $a0, 0x24($s0)
/* 019D8C 8003E98C 0040182D */  daddu $v1, $v0, $zero
/* 019D90 8003E990 AE03003C */  sw    $v1, 0x3c($s0)
/* 019D94 8003E994 8C620144 */  lw    $v0, 0x144($v1)
/* 019D98 8003E998 AE020054 */  sw    $v0, 0x54($s0)
/* 019D9C 8003E99C AC700148 */  sw    $s0, 0x148($v1)
/* 019DA0 8003E9A0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 019DA4 8003E9A4 8FB10014 */  lw    $s1, 0x14($sp)
/* 019DA8 8003E9A8 8FB00010 */  lw    $s0, 0x10($sp)
/* 019DAC 8003E9AC 03E00008 */  jr    $ra
/* 019DB0 8003E9B0 27BD0020 */   addiu $sp, $sp, 0x20

