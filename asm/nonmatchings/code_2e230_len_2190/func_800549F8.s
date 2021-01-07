.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800549F8
/* 2FDF8 800549F8 00A0582D */  daddu     $t3, $a1, $zero
/* 2FDFC 800549FC 3C03800A */  lui       $v1, %hi(D_8009A5C0)
/* 2FE00 80054A00 8C63A5C0 */  lw        $v1, %lo(D_8009A5C0)($v1)
/* 2FE04 80054A04 93AA0013 */  lbu       $t2, 0x13($sp)
/* 2FE08 80054A08 9162000E */  lbu       $v0, 0xe($t3)
/* 2FE0C 80054A0C 8C690004 */  lw        $t1, 4($v1)
/* 2FE10 80054A10 14400021 */  bnez      $v0, .L80054A98
/* 2FE14 80054A14 C4620000 */   lwc1     $f2, ($v1)
/* 2FE18 80054A18 10E0001D */  beqz      $a3, .L80054A90
/* 2FE1C 80054A1C 0000402D */   daddu    $t0, $zero, $zero
.L80054A20:
/* 2FE20 80054A20 8CC30000 */  lw        $v1, ($a2)
/* 2FE24 80054A24 50600016 */  beql      $v1, $zero, .L80054A80
/* 2FE28 80054A28 ACC90000 */   sw       $t1, ($a2)
/* 2FE2C 80054A2C 8C620000 */  lw        $v0, ($v1)
/* 2FE30 80054A30 10400002 */  beqz      $v0, .L80054A3C
/* 2FE34 80054A34 00441021 */   addu     $v0, $v0, $a0
/* 2FE38 80054A38 AC620000 */  sw        $v0, ($v1)
.L80054A3C:
/* 2FE3C 80054A3C 8C620008 */  lw        $v0, 8($v1)
/* 2FE40 80054A40 10400002 */  beqz      $v0, .L80054A4C
/* 2FE44 80054A44 00451021 */   addu     $v0, $v0, $a1
/* 2FE48 80054A48 AC620008 */  sw        $v0, 8($v1)
.L80054A4C:
/* 2FE4C 80054A4C 8C620018 */  lw        $v0, 0x18($v1)
/* 2FE50 80054A50 10400002 */  beqz      $v0, .L80054A5C
/* 2FE54 80054A54 00451021 */   addu     $v0, $v0, $a1
/* 2FE58 80054A58 AC620018 */  sw        $v0, 0x18($v1)
.L80054A5C:
/* 2FE5C 80054A5C 8C62002C */  lw        $v0, 0x2c($v1)
/* 2FE60 80054A60 10400002 */  beqz      $v0, .L80054A6C
/* 2FE64 80054A64 00451021 */   addu     $v0, $v0, $a1
/* 2FE68 80054A68 AC62002C */  sw        $v0, 0x2c($v1)
.L80054A6C:
/* 2FE6C 80054A6C C4600020 */  lwc1      $f0, 0x20($v1)
/* 2FE70 80054A70 46800020 */  cvt.s.w   $f0, $f0
/* 2FE74 80054A74 46020003 */  div.s     $f0, $f0, $f2
/* 2FE78 80054A78 A06A0025 */  sb        $t2, 0x25($v1)
/* 2FE7C 80054A7C E4600020 */  swc1      $f0, 0x20($v1)
.L80054A80:
/* 2FE80 80054A80 25080001 */  addiu     $t0, $t0, 1
/* 2FE84 80054A84 0107102B */  sltu      $v0, $t0, $a3
/* 2FE88 80054A88 1440FFE5 */  bnez      $v0, .L80054A20
/* 2FE8C 80054A8C 24C60004 */   addiu    $a2, $a2, 4
.L80054A90:
/* 2FE90 80054A90 24020001 */  addiu     $v0, $zero, 1
/* 2FE94 80054A94 A162000E */  sb        $v0, 0xe($t3)
.L80054A98:
/* 2FE98 80054A98 03E00008 */  jr        $ra
/* 2FE9C 80054A9C 00000000 */   nop      
