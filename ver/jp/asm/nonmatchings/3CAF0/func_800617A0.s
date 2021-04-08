.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800617A0
/* 3CBA0 800617A0 18A00011 */  blez      $a1, .L800617E8
/* 3CBA4 800617A4 00000000 */   nop
/* 3CBA8 800617A8 240B4000 */  addiu     $t3, $zero, 0x4000
/* 3CBAC 800617AC 00AB082B */  sltu      $at, $a1, $t3
/* 3CBB0 800617B0 1020000F */  beqz      $at, .L800617F0
/* 3CBB4 800617B4 00000000 */   nop
/* 3CBB8 800617B8 00804021 */  addu      $t0, $a0, $zero
/* 3CBBC 800617BC 00854821 */  addu      $t1, $a0, $a1
/* 3CBC0 800617C0 0109082B */  sltu      $at, $t0, $t1
/* 3CBC4 800617C4 10200008 */  beqz      $at, .L800617E8
/* 3CBC8 800617C8 00000000 */   nop
/* 3CBCC 800617CC 2529FFE0 */  addiu     $t1, $t1, -0x20
/* 3CBD0 800617D0 310A001F */  andi      $t2, $t0, 0x1f
/* 3CBD4 800617D4 010A4023 */  subu      $t0, $t0, $t2
.L800617D8:
/* 3CBD8 800617D8 BD100000 */  cache     0x10, ($t0)
/* 3CBDC 800617DC 0109082B */  sltu      $at, $t0, $t1
/* 3CBE0 800617E0 1420FFFD */  bnez      $at, .L800617D8
/* 3CBE4 800617E4 25080020 */   addiu    $t0, $t0, 0x20
.L800617E8:
/* 3CBE8 800617E8 03E00008 */  jr        $ra
/* 3CBEC 800617EC 00000000 */   nop
.L800617F0:
/* 3CBF0 800617F0 3C088000 */  lui       $t0, 0x8000
/* 3CBF4 800617F4 010B4821 */  addu      $t1, $t0, $t3
/* 3CBF8 800617F8 2529FFE0 */  addiu     $t1, $t1, -0x20
.L800617FC:
/* 3CBFC 800617FC BD000000 */  cache     0, ($t0)
/* 3CC00 80061800 0109082B */  sltu      $at, $t0, $t1
/* 3CC04 80061804 1420FFFD */  bnez      $at, .L800617FC
/* 3CC08 80061808 25080020 */   addiu    $t0, $t0, 0x20
/* 3CC0C 8006180C 03E00008 */  jr        $ra
/* 3CC10 80061810 00000000 */   nop
/* 3CC14 80061814 00000000 */  nop
/* 3CC18 80061818 00000000 */  nop
/* 3CC1C 8006181C 00000000 */  nop
