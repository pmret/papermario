.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel guOrtho
/* 3EE40 80063A40 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 3EE44 80063A44 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 3EE48 80063A48 C7B600A0 */  lwc1      $f22, 0xa0($sp)
/* 3EE4C 80063A4C F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 3EE50 80063A50 C7BC00A4 */  lwc1      $f28, 0xa4($sp)
/* 3EE54 80063A54 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 3EE58 80063A58 C7B400A8 */  lwc1      $f20, 0xa8($sp)
/* 3EE5C 80063A5C AFB10054 */  sw        $s1, 0x54($sp)
/* 3EE60 80063A60 8FB100AC */  lw        $s1, 0xac($sp)
/* 3EE64 80063A64 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 3EE68 80063A68 4485D000 */  mtc1      $a1, $f26
/* 3EE6C 80063A6C F7B80070 */  sdc1      $f24, 0x70($sp)
/* 3EE70 80063A70 4486C000 */  mtc1      $a2, $f24
/* 3EE74 80063A74 AFB20058 */  sw        $s2, 0x58($sp)
/* 3EE78 80063A78 00809021 */  addu      $s2, $a0, $zero
/* 3EE7C 80063A7C AFB00050 */  sw        $s0, 0x50($sp)
/* 3EE80 80063A80 27B00010 */  addiu     $s0, $sp, 0x10
/* 3EE84 80063A84 F7BE0088 */  sdc1      $f30, 0x88($sp)
/* 3EE88 80063A88 4487F000 */  mtc1      $a3, $f30
/* 3EE8C 80063A8C AFBF005C */  sw        $ra, 0x5c($sp)
/* 3EE90 80063A90 0C019D28 */  jal       guMtxIdentF
/* 3EE94 80063A94 02002021 */   addu     $a0, $s0, $zero
/* 3EE98 80063A98 461AC001 */  sub.s     $f0, $f24, $f26
/* 3EE9C 80063A9C 3C014000 */  lui       $at, 0x4000
/* 3EEA0 80063AA0 44811000 */  mtc1      $at, $f2
/* 3EEA4 80063AA4 00000000 */  nop
/* 3EEA8 80063AA8 46001283 */  div.s     $f10, $f2, $f0
/* 3EEAC 80063AAC 461EB181 */  sub.s     $f6, $f22, $f30
/* 3EEB0 80063AB0 46061083 */  div.s     $f2, $f2, $f6
/* 3EEB4 80063AB4 461CA201 */  sub.s     $f8, $f20, $f28
/* 3EEB8 80063AB8 3C01C000 */  lui       $at, 0xc000
/* 3EEBC 80063ABC 44812000 */  mtc1      $at, $f4
/* 3EEC0 80063AC0 00000000 */  nop
/* 3EEC4 80063AC4 46082103 */  div.s     $f4, $f4, $f8
/* 3EEC8 80063AC8 461AC600 */  add.s     $f24, $f24, $f26
/* 3EECC 80063ACC 4600C607 */  neg.s     $f24, $f24
/* 3EED0 80063AD0 4600C603 */  div.s     $f24, $f24, $f0
/* 3EED4 80063AD4 461EB580 */  add.s     $f22, $f22, $f30
/* 3EED8 80063AD8 4600B587 */  neg.s     $f22, $f22
/* 3EEDC 80063ADC 4606B583 */  div.s     $f22, $f22, $f6
/* 3EEE0 80063AE0 461CA500 */  add.s     $f20, $f20, $f28
/* 3EEE4 80063AE4 4600A507 */  neg.s     $f20, $f20
/* 3EEE8 80063AE8 4608A503 */  div.s     $f20, $f20, $f8
/* 3EEEC 80063AEC 3C013F80 */  lui       $at, 0x3f80
/* 3EEF0 80063AF0 44810000 */  mtc1      $at, $f0
/* 3EEF4 80063AF4 00002821 */  addu      $a1, $zero, $zero
/* 3EEF8 80063AF8 E7A0004C */  swc1      $f0, 0x4c($sp)
/* 3EEFC 80063AFC E7AA0010 */  swc1      $f10, 0x10($sp)
/* 3EF00 80063B00 E7B80040 */  swc1      $f24, 0x40($sp)
/* 3EF04 80063B04 E7A20024 */  swc1      $f2, 0x24($sp)
/* 3EF08 80063B08 E7A40038 */  swc1      $f4, 0x38($sp)
/* 3EF0C 80063B0C E7B60044 */  swc1      $f22, 0x44($sp)
/* 3EF10 80063B10 E7B40048 */  swc1      $f20, 0x48($sp)
.L80063B14:
/* 3EF14 80063B14 00002021 */  addu      $a0, $zero, $zero
/* 3EF18 80063B18 02001821 */  addu      $v1, $s0, $zero
.L80063B1C:
/* 3EF1C 80063B1C C4600000 */  lwc1      $f0, ($v1)
/* 3EF20 80063B20 44916000 */  mtc1      $s1, $f12
/* 3EF24 80063B24 00000000 */  nop
/* 3EF28 80063B28 460C0002 */  mul.s     $f0, $f0, $f12
/* 3EF2C 80063B2C 24840001 */  addiu     $a0, $a0, 1
/* 3EF30 80063B30 28820004 */  slti      $v0, $a0, 4
/* 3EF34 80063B34 E4600000 */  swc1      $f0, ($v1)
/* 3EF38 80063B38 1440FFF8 */  bnez      $v0, .L80063B1C
/* 3EF3C 80063B3C 24630004 */   addiu    $v1, $v1, 4
/* 3EF40 80063B40 24A50001 */  addiu     $a1, $a1, 1
/* 3EF44 80063B44 28A20004 */  slti      $v0, $a1, 4
/* 3EF48 80063B48 1440FFF2 */  bnez      $v0, .L80063B14
/* 3EF4C 80063B4C 26100010 */   addiu    $s0, $s0, 0x10
/* 3EF50 80063B50 27A40010 */  addiu     $a0, $sp, 0x10
/* 3EF54 80063B54 0C019D40 */  jal       guMtxF2L
/* 3EF58 80063B58 02402821 */   addu     $a1, $s2, $zero
/* 3EF5C 80063B5C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 3EF60 80063B60 8FB20058 */  lw        $s2, 0x58($sp)
/* 3EF64 80063B64 8FB10054 */  lw        $s1, 0x54($sp)
/* 3EF68 80063B68 8FB00050 */  lw        $s0, 0x50($sp)
/* 3EF6C 80063B6C D7BE0088 */  ldc1      $f30, 0x88($sp)
/* 3EF70 80063B70 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 3EF74 80063B74 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 3EF78 80063B78 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 3EF7C 80063B7C D7B60068 */  ldc1      $f22, 0x68($sp)
/* 3EF80 80063B80 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 3EF84 80063B84 03E00008 */  jr        $ra
/* 3EF88 80063B88 27BD0090 */   addiu    $sp, $sp, 0x90
/* 3EF8C 80063B8C 00000000 */  nop
