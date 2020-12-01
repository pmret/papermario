.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80025CC0
/* 10C0 80025CC0 AFA40000 */  sw        $a0, ($sp)
/* 10C4 80025CC4 AFA50004 */  sw        $a1, 4($sp)
/* 10C8 80025CC8 AFA60008 */  sw        $a2, 8($sp)
/* 10CC 80025CCC AFA7000C */  sw        $a3, 0xc($sp)
/* 10D0 80025CD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10D4 80025CD4 0080302D */  daddu     $a2, $a0, $zero
/* 10D8 80025CD8 3C048002 */  lui       $a0, %hi(D_80025D74)
/* 10DC 80025CDC 24845D74 */  addiu     $a0, $a0, %lo(D_80025D74)
/* 10E0 80025CE0 0000282D */  daddu     $a1, $zero, $zero
/* 10E4 80025CE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10E8 80025CE8 0C0192A8 */  jal       _Printf
/* 10EC 80025CEC 27A7001C */   addiu    $a3, $sp, 0x1c
/* 10F0 80025CF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10F4 80025CF4 03E00008 */  jr        $ra
/* 10F8 80025CF8 27BD0018 */   addiu    $sp, $sp, 0x18
