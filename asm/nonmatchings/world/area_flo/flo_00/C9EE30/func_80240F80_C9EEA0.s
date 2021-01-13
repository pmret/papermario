.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F80_C9EEA0
/* C9EEA0 80240F80 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C9EEA4 80240F84 AFB00010 */  sw        $s0, 0x10($sp)
/* C9EEA8 80240F88 0080802D */  daddu     $s0, $a0, $zero
/* C9EEAC 80240F8C AFBF0018 */  sw        $ra, 0x18($sp)
/* C9EEB0 80240F90 AFB10014 */  sw        $s1, 0x14($sp)
/* C9EEB4 80240F94 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* C9EEB8 80240F98 F7B80030 */  sdc1      $f24, 0x30($sp)
/* C9EEBC 80240F9C F7B60028 */  sdc1      $f22, 0x28($sp)
/* C9EEC0 80240FA0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* C9EEC4 80240FA4 8E05008C */  lw        $a1, 0x8c($s0)
/* C9EEC8 80240FA8 0C0B1EAF */  jal       get_variable
/* C9EECC 80240FAC 0000202D */   daddu    $a0, $zero, $zero
/* C9EED0 80240FB0 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* C9EED4 80240FB4 468010A0 */  cvt.s.w   $f2, $f2
/* C9EED8 80240FB8 44061000 */  mfc1      $a2, $f2
/* C9EEDC 80240FBC C60200B0 */  lwc1      $f2, 0xb0($s0)
/* C9EEE0 80240FC0 468010A0 */  cvt.s.w   $f2, $f2
/* C9EEE4 80240FC4 4482A000 */  mtc1      $v0, $f20
/* C9EEE8 80240FC8 00000000 */  nop
/* C9EEEC 80240FCC 4680A520 */  cvt.s.w   $f20, $f20
/* C9EEF0 80240FD0 3C01C2A6 */  lui       $at, 0xc2a6
/* C9EEF4 80240FD4 4481C000 */  mtc1      $at, $f24
/* C9EEF8 80240FD8 3C0142AE */  lui       $at, 0x42ae
/* C9EEFC 80240FDC 4481D000 */  mtc1      $at, $f26
/* C9EF00 80240FE0 44071000 */  mfc1      $a3, $f2
/* C9EF04 80240FE4 4600C306 */  mov.s     $f12, $f24
/* C9EF08 80240FE8 0C00A7B5 */  jal       dist2D
/* C9EF0C 80240FEC 4600D386 */   mov.s    $f14, $f26
/* C9EF10 80240FF0 4600C306 */  mov.s     $f12, $f24
/* C9EF14 80240FF4 4600D386 */  mov.s     $f14, $f26
/* C9EF18 80240FF8 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* C9EF1C 80240FFC 468010A0 */  cvt.s.w   $f2, $f2
/* C9EF20 80241000 44061000 */  mfc1      $a2, $f2
/* C9EF24 80241004 C60200B0 */  lwc1      $f2, 0xb0($s0)
/* C9EF28 80241008 468010A0 */  cvt.s.w   $f2, $f2
/* C9EF2C 8024100C 44071000 */  mfc1      $a3, $f2
/* C9EF30 80241010 0C00A720 */  jal       atan2
/* C9EF34 80241014 46000586 */   mov.s    $f22, $f0
/* C9EF38 80241018 0C00A6C9 */  jal       clamp_angle
/* C9EF3C 8024101C 46140301 */   sub.s    $f12, $f0, $f20
/* C9EF40 80241020 46000506 */  mov.s     $f20, $f0
/* C9EF44 80241024 0C00A8BB */  jal       sin_deg
/* C9EF48 80241028 4600A306 */   mov.s    $f12, $f20
/* C9EF4C 8024102C 4600B002 */  mul.s     $f0, $f22, $f0
/* C9EF50 80241030 00000000 */  nop
/* C9EF54 80241034 46180000 */  add.s     $f0, $f0, $f24
/* C9EF58 80241038 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* C9EF5C 8024103C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* C9EF60 80241040 E6200028 */  swc1      $f0, 0x28($s1)
/* C9EF64 80241044 8E0500AC */  lw        $a1, 0xac($s0)
/* C9EF68 80241048 0C0B1EAF */  jal       get_variable
/* C9EF6C 8024104C 0000202D */   daddu    $a0, $zero, $zero
/* C9EF70 80241050 0000202D */  daddu     $a0, $zero, $zero
/* C9EF74 80241054 8E050090 */  lw        $a1, 0x90($s0)
/* C9EF78 80241058 0C0B1EAF */  jal       get_variable
/* C9EF7C 8024105C 0040802D */   daddu    $s0, $v0, $zero
/* C9EF80 80241060 4600A306 */  mov.s     $f12, $f20
/* C9EF84 80241064 02028021 */  addu      $s0, $s0, $v0
/* C9EF88 80241068 44900000 */  mtc1      $s0, $f0
/* C9EF8C 8024106C 00000000 */  nop
/* C9EF90 80241070 46800020 */  cvt.s.w   $f0, $f0
/* C9EF94 80241074 0C00A8D4 */  jal       cos_deg
/* C9EF98 80241078 E620002C */   swc1     $f0, 0x2c($s1)
/* C9EF9C 8024107C 4600B582 */  mul.s     $f22, $f22, $f0
/* C9EFA0 80241080 00000000 */  nop
/* C9EFA4 80241084 4616D681 */  sub.s     $f26, $f26, $f22
/* C9EFA8 80241088 E63A0030 */  swc1      $f26, 0x30($s1)
/* C9EFAC 8024108C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9EFB0 80241090 8FB10014 */  lw        $s1, 0x14($sp)
/* C9EFB4 80241094 8FB00010 */  lw        $s0, 0x10($sp)
/* C9EFB8 80241098 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* C9EFBC 8024109C D7B80030 */  ldc1      $f24, 0x30($sp)
/* C9EFC0 802410A0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* C9EFC4 802410A4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* C9EFC8 802410A8 24020002 */  addiu     $v0, $zero, 2
/* C9EFCC 802410AC 03E00008 */  jr        $ra
/* C9EFD0 802410B0 27BD0040 */   addiu    $sp, $sp, 0x40
