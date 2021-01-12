.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7DE0
/* 109660 802E7DE0 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 109664 802E7DE4 AFB3009C */  sw        $s3, 0x9c($sp)
/* 109668 802E7DE8 0080982D */  daddu     $s3, $a0, $zero
/* 10966C 802E7DEC AFB400A0 */  sw        $s4, 0xa0($sp)
/* 109670 802E7DF0 00C0A02D */  daddu     $s4, $a2, $zero
/* 109674 802E7DF4 27A40050 */  addiu     $a0, $sp, 0x50
/* 109678 802E7DF8 AFB20098 */  sw        $s2, 0x98($sp)
/* 10967C 802E7DFC 0000902D */  daddu     $s2, $zero, $zero
/* 109680 802E7E00 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 109684 802E7E04 24160014 */  addiu     $s6, $zero, 0x14
/* 109688 802E7E08 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 10968C 802E7E0C 2415FFF6 */  addiu     $s5, $zero, -0xa
/* 109690 802E7E10 AFBF00AC */  sw        $ra, 0xac($sp)
/* 109694 802E7E14 AFB10094 */  sw        $s1, 0x94($sp)
/* 109698 802E7E18 AFB00090 */  sw        $s0, 0x90($sp)
/* 10969C 802E7E1C F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 1096A0 802E7E20 8E620040 */  lw        $v0, 0x40($s3)
/* 1096A4 802E7E24 30A5FFFF */  andi      $a1, $a1, 0xffff
/* 1096A8 802E7E28 0040802D */  daddu     $s0, $v0, $zero
/* 1096AC 802E7E2C 8E620044 */  lw        $v0, 0x44($s3)
/* 1096B0 802E7E30 3C014120 */  lui       $at, 0x4120
/* 1096B4 802E7E34 4481A000 */  mtc1      $at, $f20
/* 1096B8 802E7E38 00451021 */  addu      $v0, $v0, $a1
/* 1096BC 802E7E3C AE020008 */  sw        $v0, 8($s0)
/* 1096C0 802E7E40 3C02802F */  lui       $v0, %hi(func_802E854C)
/* 1096C4 802E7E44 2442854C */  addiu     $v0, $v0, %lo(func_802E854C)
/* 1096C8 802E7E48 AE62003C */  sw        $v0, 0x3c($s3)
/* 1096CC 802E7E4C 240200FF */  addiu     $v0, $zero, 0xff
/* 1096D0 802E7E50 A262000B */  sb        $v0, 0xb($s3)
/* 1096D4 802E7E54 C600000C */  lwc1      $f0, 0xc($s0)
/* 1096D8 802E7E58 8E650048 */  lw        $a1, 0x48($s3)
/* 1096DC 802E7E5C 8E670050 */  lw        $a3, 0x50($s3)
/* 1096E0 802E7E60 44060000 */  mfc1      $a2, $f0
/* 1096E4 802E7E64 0200882D */  daddu     $s1, $s0, $zero
/* 1096E8 802E7E68 0C019E40 */  jal       guTranslateF
/* 1096EC 802E7E6C AE66004C */   sw       $a2, 0x4c($s3)
.L802E7E70:
/* 1096F0 802E7E70 3282FFFF */  andi      $v0, $s4, 0xffff
/* 1096F4 802E7E74 26940040 */  addiu     $s4, $s4, 0x40
/* 1096F8 802E7E78 8E650044 */  lw        $a1, 0x44($s3)
/* 1096FC 802E7E7C 27A40010 */  addiu     $a0, $sp, 0x10
/* 109700 802E7E80 0C019D60 */  jal       guMtxL2F
/* 109704 802E7E84 00A22821 */   addu     $a1, $a1, $v0
/* 109708 802E7E88 27A40050 */  addiu     $a0, $sp, 0x50
/* 10970C 802E7E8C 27A50010 */  addiu     $a1, $sp, 0x10
/* 109710 802E7E90 0C019D80 */  jal       guMtxCatF
/* 109714 802E7E94 00A0302D */   daddu    $a2, $a1, $zero
/* 109718 802E7E98 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 10971C 802E7E9C E6000154 */  swc1      $f0, 0x154($s0)
/* 109720 802E7EA0 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 109724 802E7EA4 E60001E4 */  swc1      $f0, 0x1e4($s0)
/* 109728 802E7EA8 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 10972C 802E7EAC 240400FF */  addiu     $a0, $zero, 0xff
/* 109730 802E7EB0 0C00A67F */  jal       rand_int
/* 109734 802E7EB4 E6000274 */   swc1     $f0, 0x274($s0)
/* 109738 802E7EB8 24040005 */  addiu     $a0, $zero, 5
/* 10973C 802E7EBC 00021023 */  negu      $v0, $v0
/* 109740 802E7EC0 A2220034 */  sb        $v0, 0x34($s1)
/* 109744 802E7EC4 0C00A67F */  jal       rand_int
/* 109748 802E7EC8 A23600A0 */   sb       $s6, 0xa0($s1)
/* 10974C 802E7ECC 0040182D */  daddu     $v1, $v0, $zero
/* 109750 802E7ED0 32420001 */  andi      $v0, $s2, 1
/* 109754 802E7ED4 14400002 */  bnez      $v0, .L802E7EE0
/* 109758 802E7ED8 2462000A */   addiu    $v0, $v1, 0xa
/* 10975C 802E7EDC 02A31023 */  subu      $v0, $s5, $v1
.L802E7EE0:
/* 109760 802E7EE0 44820000 */  mtc1      $v0, $f0
/* 109764 802E7EE4 00000000 */  nop       
/* 109768 802E7EE8 46800020 */  cvt.s.w   $f0, $f0
/* 10976C 802E7EEC E60000C4 */  swc1      $f0, 0xc4($s0)
/* 109770 802E7EF0 E6140304 */  swc1      $f20, 0x304($s0)
/* 109774 802E7EF4 A2200010 */  sb        $zero, 0x10($s1)
/* 109778 802E7EF8 A2200058 */  sb        $zero, 0x58($s1)
/* 10977C 802E7EFC A220007C */  sb        $zero, 0x7c($s1)
/* 109780 802E7F00 26310001 */  addiu     $s1, $s1, 1
/* 109784 802E7F04 26520001 */  addiu     $s2, $s2, 1
/* 109788 802E7F08 2A420023 */  slti      $v0, $s2, 0x23
/* 10978C 802E7F0C 1440FFD8 */  bnez      $v0, .L802E7E70
/* 109790 802E7F10 26100004 */   addiu    $s0, $s0, 4
/* 109794 802E7F14 8FBF00AC */  lw        $ra, 0xac($sp)
/* 109798 802E7F18 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 10979C 802E7F1C 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 1097A0 802E7F20 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 1097A4 802E7F24 8FB3009C */  lw        $s3, 0x9c($sp)
/* 1097A8 802E7F28 8FB20098 */  lw        $s2, 0x98($sp)
/* 1097AC 802E7F2C 8FB10094 */  lw        $s1, 0x94($sp)
/* 1097B0 802E7F30 8FB00090 */  lw        $s0, 0x90($sp)
/* 1097B4 802E7F34 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 1097B8 802E7F38 03E00008 */  jr        $ra
/* 1097BC 802E7F3C 27BD00B8 */   addiu    $sp, $sp, 0xb8
