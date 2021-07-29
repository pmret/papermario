.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054D00
/* 30100 80054D00 24020001 */  addiu     $v0, $zero, 1
/* 30104 80054D04 3C018008 */  lui       $at, %hi(D_80078D84)
/* 30108 80054D08 A4228D84 */  sh        $v0, %lo(D_80078D84)($at)
/* 3010C 80054D0C 3C018008 */  lui       $at, %hi(D_80078D80)
/* 30110 80054D10 03E00008 */  jr        $ra
/* 30114 80054D14 AC208D80 */   sw       $zero, %lo(D_80078D80)($at)
