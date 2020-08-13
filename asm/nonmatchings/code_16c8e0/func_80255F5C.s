.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80255F5C
/* 18483C 80255F5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 184840 80255F60 AFB10014 */  sw    $s1, 0x14($sp)
/* 184844 80255F64 0000882D */  daddu $s1, $zero, $zero
/* 184848 80255F68 AFB00010 */  sw    $s0, 0x10($sp)
/* 18484C 80255F6C 3C10800E */  lui   $s0, 0x800e
/* 184850 80255F70 2610C070 */  addiu $s0, $s0, -0x3f90
/* 184854 80255F74 AFBF0018 */  sw    $ra, 0x18($sp)
.L80255F78:
/* 184858 80255F78 8E0500E0 */  lw    $a1, 0xe0($s0)
/* 18485C 80255F7C 26100004 */  addiu $s0, $s0, 4
/* 184860 80255F80 26310001 */  addiu $s1, $s1, 1
/* 184864 80255F84 0C09566F */  jal   func_802559BC
/* 184868 80255F88 0000202D */   daddu $a0, $zero, $zero
/* 18486C 80255F8C 2A220018 */  slti  $v0, $s1, 0x18
/* 184870 80255F90 1440FFF9 */  bnez  $v0, .L80255F78
/* 184874 80255F94 00000000 */   nop   
/* 184878 80255F98 8FBF0018 */  lw    $ra, 0x18($sp)
/* 18487C 80255F9C 8FB10014 */  lw    $s1, 0x14($sp)
/* 184880 80255FA0 8FB00010 */  lw    $s0, 0x10($sp)
/* 184884 80255FA4 03E00008 */  jr    $ra
/* 184888 80255FA8 27BD0020 */   addiu $sp, $sp, 0x20

