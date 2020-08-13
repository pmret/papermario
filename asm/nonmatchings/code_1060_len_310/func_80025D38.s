.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80025D38
/* 001138 80025D38 AFA40000 */  sw    $a0, ($sp)
/* 00113C 80025D3C AFA50004 */  sw    $a1, 4($sp)
/* 001140 80025D40 AFA60008 */  sw    $a2, 8($sp)
/* 001144 80025D44 AFA7000C */  sw    $a3, 0xc($sp)
/* 001148 80025D48 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00114C 80025D4C 0080302D */  daddu $a2, $a0, $zero
/* 001150 80025D50 3C048002 */  lui   $a0, 0x8002
/* 001154 80025D54 24845D74 */  addiu $a0, $a0, 0x5d74
/* 001158 80025D58 0000282D */  daddu $a1, $zero, $zero
/* 00115C 80025D5C AFBF0010 */  sw    $ra, 0x10($sp)
/* 001160 80025D60 0C0192A8 */  jal   _Printf
/* 001164 80025D64 27A7001C */   addiu $a3, $sp, 0x1c
/* 001168 80025D68 8FBF0010 */  lw    $ra, 0x10($sp)
/* 00116C 80025D6C 03E00008 */  jr    $ra
/* 001170 80025D70 27BD0018 */   addiu $sp, $sp, 0x18

