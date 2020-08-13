.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801452E8
/* 0DB9E8 801452E8 3C018015 */  lui   $at, 0x8015
/* 0DB9EC 801452EC AC24EFC0 */  sw    $a0, -0x1040($at)
/* 0DB9F0 801452F0 14800005 */  bnez  $a0, .L80145308
/* 0DB9F4 801452F4 3C020001 */   lui   $v0, 1
/* 0DB9F8 801452F8 34421000 */  ori   $v0, $v0, 0x1000
/* 0DB9FC 801452FC 3C018015 */  lui   $at, 0x8015
/* 0DBA00 80145300 03E00008 */  jr    $ra
/* 0DBA04 80145304 AC22EFC4 */   sw    $v0, -0x103c($at)

.L80145308:
/* 0DBA08 80145308 3C018015 */  lui   $at, 0x8015
/* 0DBA0C 8014530C 03E00008 */  jr    $ra
/* 0DBA10 80145310 AC25EFC4 */   sw    $a1, -0x103c($at)

/* 0DBA14 80145314 00000000 */  nop   
/* 0DBA18 80145318 00000000 */  nop   
/* 0DBA1C 8014531C 00000000 */  nop   


