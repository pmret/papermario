.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80028838
/* 003C38 80028838 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 003C3C 8002883C AFBF0010 */  sw    $ra, 0x10($sp)
/* 003C40 80028840 0C00A1FC */  jal   func_800287F0
/* 003C44 80028844 00000000 */   nop   
/* 003C48 80028848 8FBF0010 */  lw    $ra, 0x10($sp)
/* 003C4C 8002884C 3C01800A */  lui   $at, 0x800a
/* 003C50 80028850 A420A6A0 */  sh    $zero, -0x5960($at)
/* 003C54 80028854 3C01800A */  lui   $at, 0x800a
/* 003C58 80028858 A420A6A2 */  sh    $zero, -0x595e($at)
/* 003C5C 8002885C 3C01800A */  lui   $at, 0x800a
/* 003C60 80028860 A420A6A4 */  sh    $zero, -0x595c($at)
/* 003C64 80028864 3C01800A */  lui   $at, 0x800a
/* 003C68 80028868 A420A6A6 */  sh    $zero, -0x595a($at)
/* 003C6C 8002886C 03E00008 */  jr    $ra
/* 003C70 80028870 27BD0018 */   addiu $sp, $sp, 0x18

