.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80025CFC
/* 10FC 80025CFC AFA40000 */  sw        $a0, ($sp)
/* 1100 80025D00 AFA50004 */  sw        $a1, 4($sp)
/* 1104 80025D04 AFA60008 */  sw        $a2, 8($sp)
/* 1108 80025D08 AFA7000C */  sw        $a3, 0xc($sp)
/* 110C 80025D0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1110 80025D10 0080302D */  daddu     $a2, $a0, $zero
/* 1114 80025D14 3C048002 */  lui       $a0, %hi(D_80025D74)
/* 1118 80025D18 24845D74 */  addiu     $a0, $a0, %lo(D_80025D74)
/* 111C 80025D1C 0000282D */  daddu     $a1, $zero, $zero
/* 1120 80025D20 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1124 80025D24 0C0192A8 */  jal       _Printf
/* 1128 80025D28 27A7001C */   addiu    $a3, $sp, 0x1c
/* 112C 80025D2C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1130 80025D30 03E00008 */  jr        $ra
/* 1134 80025D34 27BD0018 */   addiu    $sp, $sp, 0x18
