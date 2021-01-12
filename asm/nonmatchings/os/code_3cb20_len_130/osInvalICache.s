.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osInvalICache
/* 3CBD0 800617D0 18A00011 */  blez      $a1, .L80061818
/* 3CBD4 800617D4 00000000 */   nop
/* 3CBD8 800617D8 240B4000 */  addiu     $t3, $zero, 0x4000
/* 3CBDC 800617DC 00AB082B */  sltu      $at, $a1, $t3
/* 3CBE0 800617E0 1020000F */  beqz      $at, .L80061820
/* 3CBE4 800617E4 00000000 */   nop
/* 3CBE8 800617E8 00804021 */  addu      $t0, $a0, $zero
/* 3CBEC 800617EC 00854821 */  addu      $t1, $a0, $a1
/* 3CBF0 800617F0 0109082B */  sltu      $at, $t0, $t1
/* 3CBF4 800617F4 10200008 */  beqz      $at, .L80061818
/* 3CBF8 800617F8 00000000 */   nop
/* 3CBFC 800617FC 2529FFE0 */  addiu     $t1, $t1, -0x20
/* 3CC00 80061800 310A001F */  andi      $t2, $t0, 0x1f
/* 3CC04 80061804 010A4023 */  subu      $t0, $t0, $t2
.L80061808:
/* 3CC08 80061808 BD100000 */  cache     0x10, ($t0)
/* 3CC0C 8006180C 0109082B */  sltu      $at, $t0, $t1
/* 3CC10 80061810 1420FFFD */  bnez      $at, .L80061808
/* 3CC14 80061814 25080020 */   addiu    $t0, $t0, 0x20
.L80061818:
/* 3CC18 80061818 03E00008 */  jr        $ra
/* 3CC1C 8006181C 00000000 */   nop
.L80061820:
/* 3CC20 80061820 3C088000 */  lui       $t0, 0x8000
/* 3CC24 80061824 010B4821 */  addu      $t1, $t0, $t3
/* 3CC28 80061828 2529FFE0 */  addiu     $t1, $t1, -0x20
.L8006182C:
/* 3CC2C 8006182C BD000000 */  cache     0, ($t0)
/* 3CC30 80061830 0109082B */  sltu      $at, $t0, $t1
/* 3CC34 80061834 1420FFFD */  bnez      $at, .L8006182C
/* 3CC38 80061838 25080020 */   addiu    $t0, $t0, 0x20
/* 3CC3C 8006183C 03E00008 */  jr        $ra
/* 3CC40 80061840 00000000 */   nop
/* 3CC44 80061844 00000000 */  nop
/* 3CC48 80061848 00000000 */  nop
/* 3CC4C 8006184C 00000000 */  nop
