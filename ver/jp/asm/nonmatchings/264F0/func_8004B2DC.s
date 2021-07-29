.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B2DC
/* 266DC 8004B2DC 24080008 */  addiu     $t0, $zero, 8
/* 266E0 8004B2E0 8C820000 */  lw        $v0, ($a0)
/* 266E4 8004B2E4 0000382D */  daddu     $a3, $zero, $zero
/* 266E8 8004B2E8 8C4500A0 */  lw        $a1, 0xa0($v0)
/* 266EC 8004B2EC 0080302D */  daddu     $a2, $a0, $zero
/* 266F0 8004B2F0 00A0182D */  daddu     $v1, $a1, $zero
/* 266F4 8004B2F4 AC850008 */  sw        $a1, 8($a0)
.L8004B2F8:
/* 266F8 8004B2F8 94620010 */  lhu       $v0, 0x10($v1)
/* 266FC 8004B2FC 50400004 */  beql      $v0, $zero, .L8004B310
/* 26700 8004B300 24C60004 */   addiu    $a2, $a2, 4
/* 26704 8004B304 00451021 */  addu      $v0, $v0, $a1
/* 26708 8004B308 ACC2000C */  sw        $v0, 0xc($a2)
/* 2670C 8004B30C 24C60004 */  addiu     $a2, $a2, 4
.L8004B310:
/* 26710 8004B310 24E70001 */  addiu     $a3, $a3, 1
/* 26714 8004B314 00E8102B */  sltu      $v0, $a3, $t0
/* 26718 8004B318 1440FFF7 */  bnez      $v0, .L8004B2F8
/* 2671C 8004B31C 24630002 */   addiu    $v1, $v1, 2
/* 26720 8004B320 90A3000E */  lbu       $v1, 0xe($a1)
/* 26724 8004B324 24020001 */  addiu     $v0, $zero, 1
/* 26728 8004B328 14620005 */  bne       $v1, $v0, .L8004B340
/* 2672C 8004B32C 00000000 */   nop
/* 26730 8004B330 94A20020 */  lhu       $v0, 0x20($a1)
/* 26734 8004B334 10400002 */  beqz      $v0, .L8004B340
/* 26738 8004B338 00451021 */   addu     $v0, $v0, $a1
/* 2673C 8004B33C AC82002C */  sw        $v0, 0x2c($a0)
.L8004B340:
/* 26740 8004B340 03E00008 */  jr        $ra
/* 26744 8004B344 00000000 */   nop
