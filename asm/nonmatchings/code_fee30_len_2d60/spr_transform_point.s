.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_transform_point
/* FFDF0 802DCD00 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* FFDF4 802DCD04 F7B800C8 */  sdc1      $f24, 0xc8($sp)
/* FFDF8 802DCD08 4487C000 */  mtc1      $a3, $f24
/* FFDFC 802DCD0C F7BA00D0 */  sdc1      $f26, 0xd0($sp)
/* FFE00 802DCD10 C7BA00F0 */  lwc1      $f26, 0xf0($sp)
/* FFE04 802DCD14 F7BC00D8 */  sdc1      $f28, 0xd8($sp)
/* FFE08 802DCD18 C7BC00F4 */  lwc1      $f28, 0xf4($sp)
/* FFE0C 802DCD1C AFB300A4 */  sw        $s3, 0xa4($sp)
/* FFE10 802DCD20 8FB300F8 */  lw        $s3, 0xf8($sp)
/* FFE14 802DCD24 AFB400A8 */  sw        $s4, 0xa8($sp)
/* FFE18 802DCD28 8FB400FC */  lw        $s4, 0xfc($sp)
/* FFE1C 802DCD2C AFB500AC */  sw        $s5, 0xac($sp)
/* FFE20 802DCD30 8FB50100 */  lw        $s5, 0x100($sp)
/* FFE24 802DCD34 AFB200A0 */  sw        $s2, 0xa0($sp)
/* FFE28 802DCD38 0080902D */  daddu     $s2, $a0, $zero
/* FFE2C 802DCD3C AFB1009C */  sw        $s1, 0x9c($sp)
/* FFE30 802DCD40 AFBF00B0 */  sw        $ra, 0xb0($sp)
/* FFE34 802DCD44 AFB00098 */  sw        $s0, 0x98($sp)
/* FFE38 802DCD48 F7B600C0 */  sdc1      $f22, 0xc0($sp)
/* FFE3C 802DCD4C F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* FFE40 802DCD50 16400009 */  bnez      $s2, .L802DCD78
/* FFE44 802DCD54 00C0882D */   daddu    $s1, $a2, $zero
/* FFE48 802DCD58 14A00007 */  bnez      $a1, .L802DCD78
/* FFE4C 802DCD5C 00000000 */   nop
/* FFE50 802DCD60 16200005 */  bnez      $s1, .L802DCD78
/* FFE54 802DCD64 00000000 */   nop
/* FFE58 802DCD68 E6780000 */  swc1      $f24, ($s3)
/* FFE5C 802DCD6C E69A0000 */  swc1      $f26, ($s4)
/* FFE60 802DCD70 080B73A9 */  j         .L802DCEA4
/* FFE64 802DCD74 E6BC0000 */   swc1     $f28, ($s5)
.L802DCD78:
/* FFE68 802DCD78 44859000 */  mtc1      $a1, $f18
/* FFE6C 802DCD7C 00000000 */  nop
/* FFE70 802DCD80 468094A0 */  cvt.s.w   $f18, $f18
/* FFE74 802DCD84 4480A000 */  mtc1      $zero, $f20
/* FFE78 802DCD88 3C013F80 */  lui       $at, 0x3f80
/* FFE7C 802DCD8C 4481B000 */  mtc1      $at, $f22
/* FFE80 802DCD90 44059000 */  mfc1      $a1, $f18
/* FFE84 802DCD94 4406A000 */  mfc1      $a2, $f20
/* FFE88 802DCD98 4407B000 */  mfc1      $a3, $f22
/* FFE8C 802DCD9C 27A40018 */  addiu     $a0, $sp, 0x18
/* FFE90 802DCDA0 0C019EC8 */  jal       guRotateF
/* FFE94 802DCDA4 E7B40010 */   swc1     $f20, 0x10($sp)
/* FFE98 802DCDA8 27B00058 */  addiu     $s0, $sp, 0x58
/* FFE9C 802DCDAC 44919000 */  mtc1      $s1, $f18
/* FFEA0 802DCDB0 00000000 */  nop
/* FFEA4 802DCDB4 468094A0 */  cvt.s.w   $f18, $f18
/* FFEA8 802DCDB8 4406A000 */  mfc1      $a2, $f20
/* FFEAC 802DCDBC 4407A000 */  mfc1      $a3, $f20
/* FFEB0 802DCDC0 44059000 */  mfc1      $a1, $f18
/* FFEB4 802DCDC4 0200202D */  daddu     $a0, $s0, $zero
/* FFEB8 802DCDC8 0C019EC8 */  jal       guRotateF
/* FFEBC 802DCDCC E7B60010 */   swc1     $f22, 0x10($sp)
/* FFEC0 802DCDD0 0200202D */  daddu     $a0, $s0, $zero
/* FFEC4 802DCDD4 27A50018 */  addiu     $a1, $sp, 0x18
/* FFEC8 802DCDD8 0C019D80 */  jal       guMtxCatF
/* FFECC 802DCDDC 00A0302D */   daddu    $a2, $a1, $zero
/* FFED0 802DCDE0 44929000 */  mtc1      $s2, $f18
/* FFED4 802DCDE4 00000000 */  nop
/* FFED8 802DCDE8 468094A0 */  cvt.s.w   $f18, $f18
/* FFEDC 802DCDEC 4406B000 */  mfc1      $a2, $f22
/* FFEE0 802DCDF0 4407A000 */  mfc1      $a3, $f20
/* FFEE4 802DCDF4 44059000 */  mfc1      $a1, $f18
/* FFEE8 802DCDF8 0200202D */  daddu     $a0, $s0, $zero
/* FFEEC 802DCDFC 0C019EC8 */  jal       guRotateF
/* FFEF0 802DCE00 AFA70010 */   sw       $a3, 0x10($sp)
/* FFEF4 802DCE04 0200202D */  daddu     $a0, $s0, $zero
/* FFEF8 802DCE08 27A50018 */  addiu     $a1, $sp, 0x18
/* FFEFC 802DCE0C 0C019D80 */  jal       guMtxCatF
/* FFF00 802DCE10 00A0302D */   daddu    $a2, $a1, $zero
/* FFF04 802DCE14 C7A80018 */  lwc1      $f8, 0x18($sp)
/* FFF08 802DCE18 46184202 */  mul.s     $f8, $f8, $f24
/* FFF0C 802DCE1C 00000000 */  nop
/* FFF10 802DCE20 C7B00028 */  lwc1      $f16, 0x28($sp)
/* FFF14 802DCE24 461A8402 */  mul.s     $f16, $f16, $f26
/* FFF18 802DCE28 00000000 */  nop
/* FFF1C 802DCE2C C7AE0038 */  lwc1      $f14, 0x38($sp)
/* FFF20 802DCE30 461C7382 */  mul.s     $f14, $f14, $f28
/* FFF24 802DCE34 00000000 */  nop
/* FFF28 802DCE38 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* FFF2C 802DCE3C 46181082 */  mul.s     $f2, $f2, $f24
/* FFF30 802DCE40 00000000 */  nop
/* FFF34 802DCE44 C7AA002C */  lwc1      $f10, 0x2c($sp)
/* FFF38 802DCE48 461A5282 */  mul.s     $f10, $f10, $f26
/* FFF3C 802DCE4C 00000000 */  nop
/* FFF40 802DCE50 C7AC003C */  lwc1      $f12, 0x3c($sp)
/* FFF44 802DCE54 461C6302 */  mul.s     $f12, $f12, $f28
/* FFF48 802DCE58 00000000 */  nop
/* FFF4C 802DCE5C C7A00020 */  lwc1      $f0, 0x20($sp)
/* FFF50 802DCE60 46180002 */  mul.s     $f0, $f0, $f24
/* FFF54 802DCE64 00000000 */  nop
/* FFF58 802DCE68 C7A40030 */  lwc1      $f4, 0x30($sp)
/* FFF5C 802DCE6C 461A2102 */  mul.s     $f4, $f4, $f26
/* FFF60 802DCE70 00000000 */  nop
/* FFF64 802DCE74 C7A60040 */  lwc1      $f6, 0x40($sp)
/* FFF68 802DCE78 461C3182 */  mul.s     $f6, $f6, $f28
/* FFF6C 802DCE7C 00000000 */  nop
/* FFF70 802DCE80 46104200 */  add.s     $f8, $f8, $f16
/* FFF74 802DCE84 460A1080 */  add.s     $f2, $f2, $f10
/* FFF78 802DCE88 46040000 */  add.s     $f0, $f0, $f4
/* FFF7C 802DCE8C 460E4200 */  add.s     $f8, $f8, $f14
/* FFF80 802DCE90 460C1080 */  add.s     $f2, $f2, $f12
/* FFF84 802DCE94 46060000 */  add.s     $f0, $f0, $f6
/* FFF88 802DCE98 E6680000 */  swc1      $f8, ($s3)
/* FFF8C 802DCE9C E6820000 */  swc1      $f2, ($s4)
/* FFF90 802DCEA0 E6A00000 */  swc1      $f0, ($s5)
.L802DCEA4:
/* FFF94 802DCEA4 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* FFF98 802DCEA8 8FB500AC */  lw        $s5, 0xac($sp)
/* FFF9C 802DCEAC 8FB400A8 */  lw        $s4, 0xa8($sp)
/* FFFA0 802DCEB0 8FB300A4 */  lw        $s3, 0xa4($sp)
/* FFFA4 802DCEB4 8FB200A0 */  lw        $s2, 0xa0($sp)
/* FFFA8 802DCEB8 8FB1009C */  lw        $s1, 0x9c($sp)
/* FFFAC 802DCEBC 8FB00098 */  lw        $s0, 0x98($sp)
/* FFFB0 802DCEC0 D7BC00D8 */  ldc1      $f28, 0xd8($sp)
/* FFFB4 802DCEC4 D7BA00D0 */  ldc1      $f26, 0xd0($sp)
/* FFFB8 802DCEC8 D7B800C8 */  ldc1      $f24, 0xc8($sp)
/* FFFBC 802DCECC D7B600C0 */  ldc1      $f22, 0xc0($sp)
/* FFFC0 802DCED0 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* FFFC4 802DCED4 03E00008 */  jr        $ra
/* FFFC8 802DCED8 27BD00E0 */   addiu    $sp, $sp, 0xe0
