.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel count_targets
/* 197F40 80269660 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197F44 80269664 AFB00010 */  sw    $s0, 0x10($sp)
/* 197F48 80269668 0080802D */  daddu $s0, $a0, $zero
/* 197F4C 8026966C 3C02800E */  lui   $v0, 0x800e
/* 197F50 80269670 2442C070 */  addiu $v0, $v0, -0x3f90
/* 197F54 80269674 AFBF0014 */  sw    $ra, 0x14($sp)
/* 197F58 80269678 A0450197 */  sb    $a1, 0x197($v0)
/* 197F5C 8026967C 0C098C0B */  jal   player_create_target_list
/* 197F60 80269680 AC460184 */   sw    $a2, 0x184($v0)
/* 197F64 80269684 8202040C */  lb    $v0, 0x40c($s0)
/* 197F68 80269688 8FBF0014 */  lw    $ra, 0x14($sp)
/* 197F6C 8026968C 8FB00010 */  lw    $s0, 0x10($sp)
/* 197F70 80269690 03E00008 */  jr    $ra
/* 197F74 80269694 27BD0018 */   addiu $sp, $sp, 0x18

