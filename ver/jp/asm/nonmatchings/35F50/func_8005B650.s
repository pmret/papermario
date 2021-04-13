.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005B650
/* 36A50 8005B650 8CC80000 */  lw        $t0, ($a2)
/* 36A54 8005B654 19000009 */  blez      $t0, .L8005B67C
/* 36A58 8005B658 0000182D */   daddu    $v1, $zero, $zero
/* 36A5C 8005B65C 0080382D */  daddu     $a3, $a0, $zero
.L8005B660:
/* 36A60 8005B660 8CE20000 */  lw        $v0, ($a3)
/* 36A64 8005B664 10450005 */  beq       $v0, $a1, .L8005B67C
/* 36A68 8005B668 00000000 */   nop
/* 36A6C 8005B66C 24630001 */  addiu     $v1, $v1, 1
/* 36A70 8005B670 0068102A */  slt       $v0, $v1, $t0
/* 36A74 8005B674 1440FFFA */  bnez      $v0, .L8005B660
/* 36A78 8005B678 24E70004 */   addiu    $a3, $a3, 4
.L8005B67C:
/* 36A7C 8005B67C 8CC20000 */  lw        $v0, ($a2)
/* 36A80 8005B680 14620006 */  bne       $v1, $v0, .L8005B69C
/* 36A84 8005B684 00031080 */   sll      $v0, $v1, 2
/* 36A88 8005B688 00441021 */  addu      $v0, $v0, $a0
/* 36A8C 8005B68C AC450000 */  sw        $a1, ($v0)
/* 36A90 8005B690 8CC20000 */  lw        $v0, ($a2)
/* 36A94 8005B694 24420001 */  addiu     $v0, $v0, 1
/* 36A98 8005B698 ACC20000 */  sw        $v0, ($a2)
.L8005B69C:
/* 36A9C 8005B69C 03E00008 */  jr        $ra
/* 36AA0 8005B6A0 00000000 */   nop
