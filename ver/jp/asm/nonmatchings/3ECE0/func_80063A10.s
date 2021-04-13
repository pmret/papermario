.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80063A10
/* 3EE10 80063A10 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 3EE14 80063A14 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 3EE18 80063A18 C7B600A0 */  lwc1      $f22, 0xa0($sp)
/* 3EE1C 80063A1C F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 3EE20 80063A20 C7BC00A4 */  lwc1      $f28, 0xa4($sp)
/* 3EE24 80063A24 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 3EE28 80063A28 C7B400A8 */  lwc1      $f20, 0xa8($sp)
/* 3EE2C 80063A2C AFB10054 */  sw        $s1, 0x54($sp)
/* 3EE30 80063A30 8FB100AC */  lw        $s1, 0xac($sp)
/* 3EE34 80063A34 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 3EE38 80063A38 4485D000 */  mtc1      $a1, $f26
/* 3EE3C 80063A3C F7B80070 */  sdc1      $f24, 0x70($sp)
/* 3EE40 80063A40 4486C000 */  mtc1      $a2, $f24
/* 3EE44 80063A44 AFB20058 */  sw        $s2, 0x58($sp)
/* 3EE48 80063A48 00809021 */  addu      $s2, $a0, $zero
/* 3EE4C 80063A4C AFB00050 */  sw        $s0, 0x50($sp)
/* 3EE50 80063A50 27B00010 */  addiu     $s0, $sp, 0x10
/* 3EE54 80063A54 F7BE0088 */  sdc1      $f30, 0x88($sp)
/* 3EE58 80063A58 4487F000 */  mtc1      $a3, $f30
/* 3EE5C 80063A5C AFBF005C */  sw        $ra, 0x5c($sp)
/* 3EE60 80063A60 0C019D20 */  jal       func_80067480
/* 3EE64 80063A64 02002021 */   addu     $a0, $s0, $zero
/* 3EE68 80063A68 461AC001 */  sub.s     $f0, $f24, $f26
/* 3EE6C 80063A6C 3C014000 */  lui       $at, 0x4000
/* 3EE70 80063A70 44811000 */  mtc1      $at, $f2
/* 3EE74 80063A74 00000000 */  nop
/* 3EE78 80063A78 46001283 */  div.s     $f10, $f2, $f0
/* 3EE7C 80063A7C 461EB181 */  sub.s     $f6, $f22, $f30
/* 3EE80 80063A80 46061083 */  div.s     $f2, $f2, $f6
/* 3EE84 80063A84 461CA201 */  sub.s     $f8, $f20, $f28
/* 3EE88 80063A88 3C01C000 */  lui       $at, 0xc000
/* 3EE8C 80063A8C 44812000 */  mtc1      $at, $f4
/* 3EE90 80063A90 00000000 */  nop
/* 3EE94 80063A94 46082103 */  div.s     $f4, $f4, $f8
/* 3EE98 80063A98 461AC600 */  add.s     $f24, $f24, $f26
/* 3EE9C 80063A9C 4600C607 */  neg.s     $f24, $f24
/* 3EEA0 80063AA0 4600C603 */  div.s     $f24, $f24, $f0
/* 3EEA4 80063AA4 461EB580 */  add.s     $f22, $f22, $f30
/* 3EEA8 80063AA8 4600B587 */  neg.s     $f22, $f22
/* 3EEAC 80063AAC 4606B583 */  div.s     $f22, $f22, $f6
/* 3EEB0 80063AB0 461CA500 */  add.s     $f20, $f20, $f28
/* 3EEB4 80063AB4 4600A507 */  neg.s     $f20, $f20
/* 3EEB8 80063AB8 4608A503 */  div.s     $f20, $f20, $f8
/* 3EEBC 80063ABC 3C013F80 */  lui       $at, 0x3f80
/* 3EEC0 80063AC0 44810000 */  mtc1      $at, $f0
/* 3EEC4 80063AC4 00002821 */  addu      $a1, $zero, $zero
/* 3EEC8 80063AC8 E7A0004C */  swc1      $f0, 0x4c($sp)
/* 3EECC 80063ACC E7AA0010 */  swc1      $f10, 0x10($sp)
/* 3EED0 80063AD0 E7B80040 */  swc1      $f24, 0x40($sp)
/* 3EED4 80063AD4 E7A20024 */  swc1      $f2, 0x24($sp)
/* 3EED8 80063AD8 E7A40038 */  swc1      $f4, 0x38($sp)
/* 3EEDC 80063ADC E7B60044 */  swc1      $f22, 0x44($sp)
/* 3EEE0 80063AE0 E7B40048 */  swc1      $f20, 0x48($sp)
.L80063AE4:
/* 3EEE4 80063AE4 00002021 */  addu      $a0, $zero, $zero
/* 3EEE8 80063AE8 02001821 */  addu      $v1, $s0, $zero
.L80063AEC:
/* 3EEEC 80063AEC C4600000 */  lwc1      $f0, ($v1)
/* 3EEF0 80063AF0 44916000 */  mtc1      $s1, $f12
/* 3EEF4 80063AF4 00000000 */  nop
/* 3EEF8 80063AF8 460C0002 */  mul.s     $f0, $f0, $f12
/* 3EEFC 80063AFC 24840001 */  addiu     $a0, $a0, 1
/* 3EF00 80063B00 28820004 */  slti      $v0, $a0, 4
/* 3EF04 80063B04 E4600000 */  swc1      $f0, ($v1)
/* 3EF08 80063B08 1440FFF8 */  bnez      $v0, .L80063AEC
/* 3EF0C 80063B0C 24630004 */   addiu    $v1, $v1, 4
/* 3EF10 80063B10 24A50001 */  addiu     $a1, $a1, 1
/* 3EF14 80063B14 28A20004 */  slti      $v0, $a1, 4
/* 3EF18 80063B18 1440FFF2 */  bnez      $v0, .L80063AE4
/* 3EF1C 80063B1C 26100010 */   addiu    $s0, $s0, 0x10
/* 3EF20 80063B20 27A40010 */  addiu     $a0, $sp, 0x10
/* 3EF24 80063B24 0C019D38 */  jal       func_800674E0
/* 3EF28 80063B28 02402821 */   addu     $a1, $s2, $zero
/* 3EF2C 80063B2C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 3EF30 80063B30 8FB20058 */  lw        $s2, 0x58($sp)
/* 3EF34 80063B34 8FB10054 */  lw        $s1, 0x54($sp)
/* 3EF38 80063B38 8FB00050 */  lw        $s0, 0x50($sp)
/* 3EF3C 80063B3C D7BE0088 */  ldc1      $f30, 0x88($sp)
/* 3EF40 80063B40 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 3EF44 80063B44 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 3EF48 80063B48 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 3EF4C 80063B4C D7B60068 */  ldc1      $f22, 0x68($sp)
/* 3EF50 80063B50 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 3EF54 80063B54 03E00008 */  jr        $ra
/* 3EF58 80063B58 27BD0090 */   addiu    $sp, $sp, 0x90
/* 3EF5C 80063B5C 00000000 */  nop
