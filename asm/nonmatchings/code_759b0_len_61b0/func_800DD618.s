.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DD618
/* 76AC8 800DD618 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 76ACC 800DD61C C7AC00C4 */  lwc1      $f12, 0xc4($sp)
/* 76AD0 800DD620 3C0140C9 */  lui       $at, 0x40c9
/* 76AD4 800DD624 34210FD0 */  ori       $at, $at, 0xfd0
/* 76AD8 800DD628 44810000 */  mtc1      $at, $f0
/* 76ADC 800DD62C AFB00068 */  sw        $s0, 0x68($sp)
/* 76AE0 800DD630 0080802D */  daddu     $s0, $a0, $zero
/* 76AE4 800DD634 AFB30074 */  sw        $s3, 0x74($sp)
/* 76AE8 800DD638 00A0982D */  daddu     $s3, $a1, $zero
/* 76AEC 800DD63C AFB1006C */  sw        $s1, 0x6c($sp)
/* 76AF0 800DD640 00C0882D */  daddu     $s1, $a2, $zero
/* 76AF4 800DD644 AFB40078 */  sw        $s4, 0x78($sp)
/* 76AF8 800DD648 00E0A02D */  daddu     $s4, $a3, $zero
/* 76AFC 800DD64C F7B80098 */  sdc1      $f24, 0x98($sp)
/* 76B00 800DD650 C7B800C0 */  lwc1      $f24, 0xc0($sp)
/* 76B04 800DD654 27A50038 */  addiu     $a1, $sp, 0x38
/* 76B08 800DD658 F7B40088 */  sdc1      $f20, 0x88($sp)
/* 76B0C 800DD65C C7B400C8 */  lwc1      $f20, 0xc8($sp)
/* 76B10 800DD660 46006302 */  mul.s     $f12, $f12, $f0
/* 76B14 800DD664 00000000 */  nop       
/* 76B18 800DD668 3C0143B4 */  lui       $at, 0x43b4
/* 76B1C 800DD66C 44810000 */  mtc1      $at, $f0
/* 76B20 800DD670 27A6003C */  addiu     $a2, $sp, 0x3c
/* 76B24 800DD674 AFBF0080 */  sw        $ra, 0x80($sp)
/* 76B28 800DD678 AFB5007C */  sw        $s5, 0x7c($sp)
/* 76B2C 800DD67C AFB20070 */  sw        $s2, 0x70($sp)
/* 76B30 800DD680 F7BC00A8 */  sdc1      $f28, 0xa8($sp)
/* 76B34 800DD684 F7BA00A0 */  sdc1      $f26, 0xa0($sp)
/* 76B38 800DD688 F7B60090 */  sdc1      $f22, 0x90($sp)
/* 76B3C 800DD68C 0C00A82D */  jal       sin_cos_rad
/* 76B40 800DD690 46006303 */   div.s    $f12, $f12, $f0
/* 76B44 800DD694 C7A40038 */  lwc1      $f4, 0x38($sp)
/* 76B48 800DD698 4604C702 */  mul.s     $f28, $f24, $f4
/* 76B4C 800DD69C 00000000 */  nop       
/* 76B50 800DD6A0 4604A182 */  mul.s     $f6, $f20, $f4
/* 76B54 800DD6A4 00000000 */  nop       
/* 76B58 800DD6A8 3C013F00 */  lui       $at, 0x3f00
/* 76B5C 800DD6AC 44814000 */  mtc1      $at, $f8
/* 76B60 800DD6B0 00000000 */  nop       
/* 76B64 800DD6B4 4608A082 */  mul.s     $f2, $f20, $f8
/* 76B68 800DD6B8 00000000 */  nop       
/* 76B6C 800DD6BC 46083182 */  mul.s     $f6, $f6, $f8
/* 76B70 800DD6C0 00000000 */  nop       
/* 76B74 800DD6C4 2412FFFF */  addiu     $s2, $zero, -1
/* 76B78 800DD6C8 4614C000 */  add.s     $f0, $f24, $f20
/* 76B7C 800DD6CC 0000A82D */  daddu     $s5, $zero, $zero
/* 76B80 800DD6D0 46020580 */  add.s     $f22, $f0, $f2
/* 76B84 800DD6D4 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 76B88 800DD6D8 27A20040 */  addiu     $v0, $sp, 0x40
/* 76B8C 800DD6DC 46001087 */  neg.s     $f2, $f2
/* 76B90 800DD6E0 E7A2003C */  swc1      $f2, 0x3c($sp)
/* 76B94 800DD6E4 E7B6004C */  swc1      $f22, 0x4c($sp)
/* 76B98 800DD6E8 C66A0000 */  lwc1      $f10, ($s3)
/* 76B9C 800DD6EC C68C0000 */  lwc1      $f12, ($s4)
/* 76BA0 800DD6F0 4602A002 */  mul.s     $f0, $f20, $f2
/* 76BA4 800DD6F4 00000000 */  nop       
/* 76BA8 800DD6F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 76BAC 800DD6FC 27A20044 */  addiu     $v0, $sp, 0x44
/* 76BB0 800DD700 AFA20020 */  sw        $v0, 0x20($sp)
/* 76BB4 800DD704 27A20048 */  addiu     $v0, $sp, 0x48
/* 76BB8 800DD708 AFA20024 */  sw        $v0, 0x24($sp)
/* 76BBC 800DD70C 27A2004C */  addiu     $v0, $sp, 0x4c
/* 76BC0 800DD710 AFA20028 */  sw        $v0, 0x28($sp)
/* 76BC4 800DD714 27A20050 */  addiu     $v0, $sp, 0x50
/* 76BC8 800DD718 AFA2002C */  sw        $v0, 0x2c($sp)
/* 76BCC 800DD71C 27A20054 */  addiu     $v0, $sp, 0x54
/* 76BD0 800DD720 46080002 */  mul.s     $f0, $f0, $f8
/* 76BD4 800DD724 00000000 */  nop       
/* 76BD8 800DD728 AFA20030 */  sw        $v0, 0x30($sp)
/* 76BDC 800DD72C 27A20058 */  addiu     $v0, $sp, 0x58
/* 76BE0 800DD730 E7A40010 */  swc1      $f4, 0x10($sp)
/* 76BE4 800DD734 AFA00014 */  sw        $zero, 0x14($sp)
/* 76BE8 800DD738 46065281 */  sub.s     $f10, $f10, $f6
/* 76BEC 800DD73C E7A20018 */  swc1      $f2, 0x18($sp)
/* 76BF0 800DD740 AFA20034 */  sw        $v0, 0x34($sp)
/* 76BF4 800DD744 46006301 */  sub.s     $f12, $f12, $f0
/* 76BF8 800DD748 8E260000 */  lw        $a2, ($s1)
/* 76BFC 800DD74C 44055000 */  mfc1      $a1, $f10
/* 76C00 800DD750 44076000 */  mfc1      $a3, $f12
/* 76C04 800DD754 4602C682 */  mul.s     $f26, $f24, $f2
/* 76C08 800DD758 00000000 */  nop       
/* 76C0C 800DD75C 0C037513 */  jal       func_800DD44C
/* 76C10 800DD760 0200202D */   daddu    $a0, $s0, $zero
/* 76C14 800DD764 0040802D */  daddu     $s0, $v0, $zero
/* 76C18 800DD768 0600004E */  bltz      $s0, .L800DD8A4
/* 76C1C 800DD76C 00000000 */   nop      
/* 76C20 800DD770 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* 76C24 800DD774 4616003E */  c.le.s    $f0, $f22
/* 76C28 800DD778 00000000 */  nop       
/* 76C2C 800DD77C 45000049 */  bc1f      .L800DD8A4
/* 76C30 800DD780 00000000 */   nop      
/* 76C34 800DD784 C7A20050 */  lwc1      $f2, 0x50($sp)
/* 76C38 800DD788 46021082 */  mul.s     $f2, $f2, $f2
/* 76C3C 800DD78C 00000000 */  nop       
/* 76C40 800DD790 C7A00058 */  lwc1      $f0, 0x58($sp)
/* 76C44 800DD794 46000002 */  mul.s     $f0, $f0, $f0
/* 76C48 800DD798 00000000 */  nop       
/* 76C4C 800DD79C 46001300 */  add.s     $f12, $f2, $f0
/* 76C50 800DD7A0 46006004 */  sqrt.s    $f0, $f12
/* 76C54 800DD7A4 46000032 */  c.eq.s    $f0, $f0
/* 76C58 800DD7A8 00000000 */  nop       
/* 76C5C 800DD7AC 45010003 */  bc1t      .L800DD7BC
/* 76C60 800DD7B0 00000000 */   nop      
/* 76C64 800DD7B4 0C0187BC */  jal       sqrtf
/* 76C68 800DD7B8 00000000 */   nop      
.L800DD7BC:
/* 76C6C 800DD7BC 44060000 */  mfc1      $a2, $f0
/* 76C70 800DD7C0 C7A00054 */  lwc1      $f0, 0x54($sp)
/* 76C74 800DD7C4 44806000 */  mtc1      $zero, $f12
/* 76C78 800DD7C8 46000007 */  neg.s     $f0, $f0
/* 76C7C 800DD7CC 44070000 */  mfc1      $a3, $f0
/* 76C80 800DD7D0 0C00A720 */  jal       atan2
/* 76C84 800DD7D4 46006386 */   mov.s    $f14, $f12
/* 76C88 800DD7D8 3C014270 */  lui       $at, 0x4270
/* 76C8C 800DD7DC 44811000 */  mtc1      $at, $f2
/* 76C90 800DD7E0 46000106 */  mov.s     $f4, $f0
/* 76C94 800DD7E4 4604103C */  c.lt.s    $f2, $f4
/* 76C98 800DD7E8 00000000 */  nop       
/* 76C9C 800DD7EC 45000008 */  bc1f      .L800DD810
/* 76CA0 800DD7F0 00000000 */   nop      
/* 76CA4 800DD7F4 3C0142B4 */  lui       $at, 0x42b4
/* 76CA8 800DD7F8 44810000 */  mtc1      $at, $f0
/* 76CAC 800DD7FC 00000000 */  nop       
/* 76CB0 800DD800 4600203C */  c.lt.s    $f4, $f0
/* 76CB4 800DD804 00000000 */  nop       
/* 76CB8 800DD808 45030001 */  bc1tl     .L800DD810
/* 76CBC 800DD80C 24150001 */   addiu    $s5, $zero, 1
.L800DD810:
/* 76CC0 800DD810 3C013F00 */  lui       $at, 0x3f00
/* 76CC4 800DD814 44810000 */  mtc1      $at, $f0
/* 76CC8 800DD818 00000000 */  nop       
/* 76CCC 800DD81C 4600A002 */  mul.s     $f0, $f20, $f0
/* 76CD0 800DD820 00000000 */  nop       
/* 76CD4 800DD824 4614C080 */  add.s     $f2, $f24, $f20
/* 76CD8 800DD828 27A4005C */  addiu     $a0, $sp, 0x5c
/* 76CDC 800DD82C 4406E000 */  mfc1      $a2, $f28
/* 76CE0 800DD830 46001080 */  add.s     $f2, $f2, $f0
/* 76CE4 800DD834 C7B4004C */  lwc1      $f20, 0x4c($sp)
/* 76CE8 800DD838 4407D000 */  mfc1      $a3, $f26
/* 76CEC 800DD83C 4602A501 */  sub.s     $f20, $f20, $f2
/* 76CF0 800DD840 C7B60038 */  lwc1      $f22, 0x38($sp)
/* 76CF4 800DD844 C7A00050 */  lwc1      $f0, 0x50($sp)
/* 76CF8 800DD848 4616A582 */  mul.s     $f22, $f20, $f22
/* 76CFC 800DD84C 00000000 */  nop       
/* 76D00 800DD850 C7A2003C */  lwc1      $f2, 0x3c($sp)
/* 76D04 800DD854 27A50060 */  addiu     $a1, $sp, 0x60
/* 76D08 800DD858 E7A00010 */  swc1      $f0, 0x10($sp)
/* 76D0C 800DD85C C7A00058 */  lwc1      $f0, 0x58($sp)
/* 76D10 800DD860 4602A502 */  mul.s     $f20, $f20, $f2
/* 76D14 800DD864 00000000 */  nop       
/* 76D18 800DD868 0C03756D */  jal       func_800DD5B4
/* 76D1C 800DD86C E7A00014 */   swc1     $f0, 0x14($sp)
/* 76D20 800DD870 C7A0005C */  lwc1      $f0, 0x5c($sp)
/* 76D24 800DD874 4600B580 */  add.s     $f22, $f22, $f0
/* 76D28 800DD878 C6600000 */  lwc1      $f0, ($s3)
/* 76D2C 800DD87C 46160000 */  add.s     $f0, $f0, $f22
/* 76D30 800DD880 E6600000 */  swc1      $f0, ($s3)
/* 76D34 800DD884 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 76D38 800DD888 4600A500 */  add.s     $f20, $f20, $f0
/* 76D3C 800DD88C C6800000 */  lwc1      $f0, ($s4)
/* 76D40 800DD890 46140000 */  add.s     $f0, $f0, $f20
/* 76D44 800DD894 0200902D */  daddu     $s2, $s0, $zero
/* 76D48 800DD898 E6800000 */  swc1      $f0, ($s4)
/* 76D4C 800DD89C 3C018011 */  lui       $at, 0x8011
/* 76D50 800DD8A0 AC32C978 */  sw        $s2, -0x3688($at)
.L800DD8A4:
/* 76D54 800DD8A4 16A00007 */  bnez      $s5, .L800DD8C4
/* 76D58 800DD8A8 0240102D */   daddu    $v0, $s2, $zero
/* 76D5C 800DD8AC C6600000 */  lwc1      $f0, ($s3)
/* 76D60 800DD8B0 461C0000 */  add.s     $f0, $f0, $f28
/* 76D64 800DD8B4 E6600000 */  swc1      $f0, ($s3)
/* 76D68 800DD8B8 C6800000 */  lwc1      $f0, ($s4)
/* 76D6C 800DD8BC 461A0000 */  add.s     $f0, $f0, $f26
/* 76D70 800DD8C0 E6800000 */  swc1      $f0, ($s4)
.L800DD8C4:
/* 76D74 800DD8C4 8FBF0080 */  lw        $ra, 0x80($sp)
/* 76D78 800DD8C8 8FB5007C */  lw        $s5, 0x7c($sp)
/* 76D7C 800DD8CC 8FB40078 */  lw        $s4, 0x78($sp)
/* 76D80 800DD8D0 8FB30074 */  lw        $s3, 0x74($sp)
/* 76D84 800DD8D4 8FB20070 */  lw        $s2, 0x70($sp)
/* 76D88 800DD8D8 8FB1006C */  lw        $s1, 0x6c($sp)
/* 76D8C 800DD8DC 8FB00068 */  lw        $s0, 0x68($sp)
/* 76D90 800DD8E0 D7BC00A8 */  ldc1      $f28, 0xa8($sp)
/* 76D94 800DD8E4 D7BA00A0 */  ldc1      $f26, 0xa0($sp)
/* 76D98 800DD8E8 D7B80098 */  ldc1      $f24, 0x98($sp)
/* 76D9C 800DD8EC D7B60090 */  ldc1      $f22, 0x90($sp)
/* 76DA0 800DD8F0 D7B40088 */  ldc1      $f20, 0x88($sp)
/* 76DA4 800DD8F4 03E00008 */  jr        $ra
/* 76DA8 800DD8F8 27BD00B0 */   addiu    $sp, $sp, 0xb0
