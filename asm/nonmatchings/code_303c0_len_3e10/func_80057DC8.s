.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80057DC8
/* 0331C8 80057DC8 28820002 */  slti  $v0, $a0, 2
/* 0331CC 80057DCC 10400005 */  beqz  $v0, .L80057DE4
/* 0331D0 80057DD0 00000000 */   nop   
/* 0331D4 80057DD4 3C01800A */  lui   $at, 0x800a
/* 0331D8 80057DD8 AC203FF0 */  sw    $zero, 0x3ff0($at)
/* 0331DC 80057DDC 3C01800A */  lui   $at, 0x800a
/* 0331E0 80057DE0 A4203FEE */  sh    $zero, 0x3fee($at)
.L80057DE4:
/* 0331E4 80057DE4 3C03800A */  lui   $v1, 0x800a
/* 0331E8 80057DE8 24633FF0 */  addiu $v1, $v1, 0x3ff0
/* 0331EC 80057DEC 28820005 */  slti  $v0, $a0, 5
/* 0331F0 80057DF0 14400003 */  bnez  $v0, .L80057E00
/* 0331F4 80057DF4 AC640000 */   sw    $a0, ($v1)
/* 0331F8 80057DF8 24020004 */  addiu $v0, $zero, 4
/* 0331FC 80057DFC AC620000 */  sw    $v0, ($v1)
.L80057E00:
/* 033200 80057E00 03E00008 */  jr    $ra
/* 033204 80057E04 00000000 */   nop   

