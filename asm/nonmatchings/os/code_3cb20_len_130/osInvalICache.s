.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osInvalICache
/* 03CBD0 800617D0 18A00011 */  blez  $a1, .L80061818
/* 03CBD4 800617D4 00000000 */   nop   
/* 03CBD8 800617D8 240B4000 */  addiu $t3, $zero, 0x4000
/* 03CBDC 800617DC 00AB082B */  sltu  $at, $a1, $t3
/* 03CBE0 800617E0 1020000F */  beqz  $at, .L80061820
/* 03CBE4 800617E4 00000000 */   nop   
/* 03CBE8 800617E8 00804021 */  addu  $t0, $a0, $zero
/* 03CBEC 800617EC 00854821 */  addu  $t1, $a0, $a1
/* 03CBF0 800617F0 0109082B */  sltu  $at, $t0, $t1
/* 03CBF4 800617F4 10200008 */  beqz  $at, .L80061818
/* 03CBF8 800617F8 00000000 */   nop   
/* 03CBFC 800617FC 2529FFE0 */  addiu $t1, $t1, -0x20
/* 03CC00 80061800 310A001F */  andi  $t2, $t0, 0x1f
/* 03CC04 80061804 010A4023 */  subu  $t0, $t0, $t2
.L80061808:
/* 03CC08 80061808 BD100000 */  cache 0x10, ($t0)
/* 03CC0C 8006180C 0109082B */  sltu  $at, $t0, $t1
/* 03CC10 80061810 1420FFFD */  bnez  $at, .L80061808
/* 03CC14 80061814 25080020 */   addiu $t0, $t0, 0x20
.L80061818:
/* 03CC18 80061818 03E00008 */  jr    $ra
/* 03CC1C 8006181C 00000000 */   nop   

.L80061820:
/* 03CC20 80061820 3C088000 */  lui   $t0, 0x8000
/* 03CC24 80061824 010B4821 */  addu  $t1, $t0, $t3
/* 03CC28 80061828 2529FFE0 */  addiu $t1, $t1, -0x20
.L8006182C:
/* 03CC2C 8006182C BD000000 */  cache 0, ($t0)
/* 03CC30 80061830 0109082B */  sltu  $at, $t0, $t1
/* 03CC34 80061834 1420FFFD */  bnez  $at, .L8006182C
/* 03CC38 80061838 25080020 */   addiu $t0, $t0, 0x20
/* 03CC3C 8006183C 03E00008 */  jr    $ra
/* 03CC40 80061840 00000000 */   nop   

/* 03CC44 80061844 00000000 */  nop   
/* 03CC48 80061848 00000000 */  nop   
/* 03CC4C 8006184C 00000000 */  nop   


