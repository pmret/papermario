.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB710_E2BE40
/* E2BE40 802BB710 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* E2BE44 802BB714 AFB3009C */  sw        $s3, 0x9c($sp)
/* E2BE48 802BB718 0080982D */  daddu     $s3, $a0, $zero
/* E2BE4C 802BB71C AFB400A0 */  sw        $s4, 0xa0($sp)
/* E2BE50 802BB720 00C0A02D */  daddu     $s4, $a2, $zero
/* E2BE54 802BB724 27A40050 */  addiu     $a0, $sp, 0x50
/* E2BE58 802BB728 AFB20098 */  sw        $s2, 0x98($sp)
/* E2BE5C 802BB72C 0000902D */  daddu     $s2, $zero, $zero
/* E2BE60 802BB730 AFB600A8 */  sw        $s6, 0xa8($sp)
/* E2BE64 802BB734 24160014 */  addiu     $s6, $zero, 0x14
/* E2BE68 802BB738 AFB500A4 */  sw        $s5, 0xa4($sp)
/* E2BE6C 802BB73C 2415FFF6 */  addiu     $s5, $zero, -0xa
/* E2BE70 802BB740 AFBF00AC */  sw        $ra, 0xac($sp)
/* E2BE74 802BB744 AFB10094 */  sw        $s1, 0x94($sp)
/* E2BE78 802BB748 AFB00090 */  sw        $s0, 0x90($sp)
/* E2BE7C 802BB74C F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* E2BE80 802BB750 8E620040 */  lw        $v0, 0x40($s3)
/* E2BE84 802BB754 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2BE88 802BB758 0040802D */  daddu     $s0, $v0, $zero
/* E2BE8C 802BB75C 8E620044 */  lw        $v0, 0x44($s3)
/* E2BE90 802BB760 3C014120 */  lui       $at, 0x4120
/* E2BE94 802BB764 4481A000 */  mtc1      $at, $f20
/* E2BE98 802BB768 00451021 */  addu      $v0, $v0, $a1
/* E2BE9C 802BB76C AE020000 */  sw        $v0, ($s0)
/* E2BEA0 802BB770 3C02802C */  lui       $v0, %hi(func_802BBE3C_E2C56C)
/* E2BEA4 802BB774 2442BE3C */  addiu     $v0, $v0, %lo(func_802BBE3C_E2C56C)
/* E2BEA8 802BB778 AE62003C */  sw        $v0, 0x3c($s3)
/* E2BEAC 802BB77C 240200FF */  addiu     $v0, $zero, 0xff
/* E2BEB0 802BB780 A262000B */  sb        $v0, 0xb($s3)
/* E2BEB4 802BB784 C6000004 */  lwc1      $f0, 4($s0)
/* E2BEB8 802BB788 8E650048 */  lw        $a1, 0x48($s3)
/* E2BEBC 802BB78C 8E670050 */  lw        $a3, 0x50($s3)
/* E2BEC0 802BB790 44060000 */  mfc1      $a2, $f0
/* E2BEC4 802BB794 0200882D */  daddu     $s1, $s0, $zero
/* E2BEC8 802BB798 0C019E40 */  jal       guTranslateF
/* E2BECC 802BB79C AE66004C */   sw       $a2, 0x4c($s3)
.L802BB7A0:
/* E2BED0 802BB7A0 3282FFFF */  andi      $v0, $s4, 0xffff
/* E2BED4 802BB7A4 26940040 */  addiu     $s4, $s4, 0x40
/* E2BED8 802BB7A8 8E650044 */  lw        $a1, 0x44($s3)
/* E2BEDC 802BB7AC 27A40010 */  addiu     $a0, $sp, 0x10
/* E2BEE0 802BB7B0 0C019D60 */  jal       guMtxL2F
/* E2BEE4 802BB7B4 00A22821 */   addu     $a1, $a1, $v0
/* E2BEE8 802BB7B8 27A40050 */  addiu     $a0, $sp, 0x50
/* E2BEEC 802BB7BC 27A50010 */  addiu     $a1, $sp, 0x10
/* E2BEF0 802BB7C0 0C019D80 */  jal       guMtxCatF
/* E2BEF4 802BB7C4 00A0302D */   daddu    $a2, $a1, $zero
/* E2BEF8 802BB7C8 C7A00040 */  lwc1      $f0, 0x40($sp)
/* E2BEFC 802BB7CC E6000080 */  swc1      $f0, 0x80($s0)
/* E2BF00 802BB7D0 C7A00044 */  lwc1      $f0, 0x44($sp)
/* E2BF04 802BB7D4 E60000B4 */  swc1      $f0, 0xb4($s0)
/* E2BF08 802BB7D8 C7A00048 */  lwc1      $f0, 0x48($sp)
/* E2BF0C 802BB7DC 240400FF */  addiu     $a0, $zero, 0xff
/* E2BF10 802BB7E0 0C00A67F */  jal       rand_int
/* E2BF14 802BB7E4 E60000E8 */   swc1     $f0, 0xe8($s0)
/* E2BF18 802BB7E8 24040005 */  addiu     $a0, $zero, 5
/* E2BF1C 802BB7EC 00021023 */  negu      $v0, $v0
/* E2BF20 802BB7F0 A2220015 */  sb        $v0, 0x15($s1)
/* E2BF24 802BB7F4 0C00A67F */  jal       rand_int
/* E2BF28 802BB7F8 A236003C */   sb       $s6, 0x3c($s1)
/* E2BF2C 802BB7FC 0040182D */  daddu     $v1, $v0, $zero
/* E2BF30 802BB800 32420001 */  andi      $v0, $s2, 1
/* E2BF34 802BB804 14400002 */  bnez      $v0, .L802BB810
/* E2BF38 802BB808 2462000A */   addiu    $v0, $v1, 0xa
/* E2BF3C 802BB80C 02A31023 */  subu      $v0, $s5, $v1
.L802BB810:
/* E2BF40 802BB810 44820000 */  mtc1      $v0, $f0
/* E2BF44 802BB814 00000000 */  nop       
/* E2BF48 802BB818 46800020 */  cvt.s.w   $f0, $f0
/* E2BF4C 802BB81C E600004C */  swc1      $f0, 0x4c($s0)
/* E2BF50 802BB820 E614011C */  swc1      $f20, 0x11c($s0)
/* E2BF54 802BB824 A2200008 */  sb        $zero, 8($s1)
/* E2BF58 802BB828 A2200022 */  sb        $zero, 0x22($s1)
/* E2BF5C 802BB82C A220002F */  sb        $zero, 0x2f($s1)
/* E2BF60 802BB830 26310001 */  addiu     $s1, $s1, 1
/* E2BF64 802BB834 26520001 */  addiu     $s2, $s2, 1
/* E2BF68 802BB838 2A42000C */  slti      $v0, $s2, 0xc
/* E2BF6C 802BB83C 1440FFD8 */  bnez      $v0, .L802BB7A0
/* E2BF70 802BB840 26100004 */   addiu    $s0, $s0, 4
/* E2BF74 802BB844 8FBF00AC */  lw        $ra, 0xac($sp)
/* E2BF78 802BB848 8FB600A8 */  lw        $s6, 0xa8($sp)
/* E2BF7C 802BB84C 8FB500A4 */  lw        $s5, 0xa4($sp)
/* E2BF80 802BB850 8FB400A0 */  lw        $s4, 0xa0($sp)
/* E2BF84 802BB854 8FB3009C */  lw        $s3, 0x9c($sp)
/* E2BF88 802BB858 8FB20098 */  lw        $s2, 0x98($sp)
/* E2BF8C 802BB85C 8FB10094 */  lw        $s1, 0x94($sp)
/* E2BF90 802BB860 8FB00090 */  lw        $s0, 0x90($sp)
/* E2BF94 802BB864 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* E2BF98 802BB868 03E00008 */  jr        $ra
/* E2BF9C 802BB86C 27BD00B8 */   addiu    $sp, $sp, 0xb8
