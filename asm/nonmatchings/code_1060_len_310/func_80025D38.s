.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80025D38
/* 1138 80025D38 AFA40000 */  sw        $a0, ($sp)
/* 113C 80025D3C AFA50004 */  sw        $a1, 4($sp)
/* 1140 80025D40 AFA60008 */  sw        $a2, 8($sp)
/* 1144 80025D44 AFA7000C */  sw        $a3, 0xc($sp)
/* 1148 80025D48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 114C 80025D4C 0080302D */  daddu     $a2, $a0, $zero
/* 1150 80025D50 3C048002 */  lui       $a0, %hi(func_80025D74)
/* 1154 80025D54 24845D74 */  addiu     $a0, $a0, %lo(func_80025D74)
/* 1158 80025D58 0000282D */  daddu     $a1, $zero, $zero
/* 115C 80025D5C AFBF0010 */  sw        $ra, 0x10($sp)
/* 1160 80025D60 0C0192A8 */  jal       _Printf
/* 1164 80025D64 27A7001C */   addiu    $a3, $sp, 0x1c
/* 1168 80025D68 8FBF0010 */  lw        $ra, 0x10($sp)
/* 116C 80025D6C 03E00008 */  jr        $ra
/* 1170 80025D70 27BD0018 */   addiu    $sp, $sp, 0x18
