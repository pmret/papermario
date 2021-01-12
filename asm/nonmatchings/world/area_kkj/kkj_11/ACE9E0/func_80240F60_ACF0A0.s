.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F60_ACF0A0
/* ACF0A0 80240F60 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* ACF0A4 80240F64 AFB3001C */  sw        $s3, 0x1c($sp)
/* ACF0A8 80240F68 0080982D */  daddu     $s3, $a0, $zero
/* ACF0AC 80240F6C AFBF0030 */  sw        $ra, 0x30($sp)
/* ACF0B0 80240F70 AFB7002C */  sw        $s7, 0x2c($sp)
/* ACF0B4 80240F74 AFB60028 */  sw        $s6, 0x28($sp)
/* ACF0B8 80240F78 AFB50024 */  sw        $s5, 0x24($sp)
/* ACF0BC 80240F7C AFB40020 */  sw        $s4, 0x20($sp)
/* ACF0C0 80240F80 AFB20018 */  sw        $s2, 0x18($sp)
/* ACF0C4 80240F84 AFB10014 */  sw        $s1, 0x14($sp)
/* ACF0C8 80240F88 AFB00010 */  sw        $s0, 0x10($sp)
/* ACF0CC 80240F8C F7B80048 */  sdc1      $f24, 0x48($sp)
/* ACF0D0 80240F90 F7B60040 */  sdc1      $f22, 0x40($sp)
/* ACF0D4 80240F94 F7B40038 */  sdc1      $f20, 0x38($sp)
/* ACF0D8 80240F98 8E70000C */  lw        $s0, 0xc($s3)
/* ACF0DC 80240F9C 8E050000 */  lw        $a1, ($s0)
/* ACF0E0 80240FA0 0C0B1EAF */  jal       get_variable
/* ACF0E4 80240FA4 26100004 */   addiu    $s0, $s0, 4
/* ACF0E8 80240FA8 8E150000 */  lw        $s5, ($s0)
/* ACF0EC 80240FAC 26100004 */  addiu     $s0, $s0, 4
/* ACF0F0 80240FB0 0260202D */  daddu     $a0, $s3, $zero
/* ACF0F4 80240FB4 8E160000 */  lw        $s6, ($s0)
/* ACF0F8 80240FB8 8E170004 */  lw        $s7, 4($s0)
/* ACF0FC 80240FBC 0C0B36B0 */  jal       resolve_npc
/* ACF100 80240FC0 0040282D */   daddu    $a1, $v0, $zero
/* ACF104 80240FC4 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* ACF108 80240FC8 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* ACF10C 80240FCC 0040802D */  daddu     $s0, $v0, $zero
/* ACF110 80240FD0 1200002F */  beqz      $s0, .L80241090
/* ACF114 80240FD4 0220902D */   daddu    $s2, $s1, $zero
/* ACF118 80240FD8 C62C0028 */  lwc1      $f12, 0x28($s1)
/* ACF11C 80240FDC C62E0030 */  lwc1      $f14, 0x30($s1)
/* ACF120 80240FE0 8E060038 */  lw        $a2, 0x38($s0)
/* ACF124 80240FE4 8E070040 */  lw        $a3, 0x40($s0)
/* ACF128 80240FE8 3C0142C8 */  lui       $at, 0x42c8
/* ACF12C 80240FEC 4481C000 */  mtc1      $at, $f24
/* ACF130 80240FF0 0C00A7B5 */  jal       dist2D
/* ACF134 80240FF4 24140001 */   addiu    $s4, $zero, 1
/* ACF138 80240FF8 4618003C */  c.lt.s    $f0, $f24
/* ACF13C 80240FFC 00000000 */  nop
/* ACF140 80241000 45030001 */  bc1tl     .L80241008
/* ACF144 80241004 0000A02D */   daddu    $s4, $zero, $zero
.L80241008:
/* ACF148 80241008 C64C0028 */  lwc1      $f12, 0x28($s2)
/* ACF14C 8024100C C64E0030 */  lwc1      $f14, 0x30($s2)
/* ACF150 80241010 8E060038 */  lw        $a2, 0x38($s0)
/* ACF154 80241014 0C00A720 */  jal       atan2
/* ACF158 80241018 8E070040 */   lw       $a3, 0x40($s0)
/* ACF15C 8024101C 0C00A6C9 */  jal       clamp_angle
/* ACF160 80241020 46000306 */   mov.s    $f12, $f0
/* ACF164 80241024 46000506 */  mov.s     $f20, $f0
/* ACF168 80241028 0C00A8BB */  jal       sin_deg
/* ACF16C 8024102C 4600A306 */   mov.s    $f12, $f20
/* ACF170 80241030 46180002 */  mul.s     $f0, $f0, $f24
/* ACF174 80241034 00000000 */  nop
/* ACF178 80241038 C6560028 */  lwc1      $f22, 0x28($s2)
/* ACF17C 8024103C 4600B580 */  add.s     $f22, $f22, $f0
/* ACF180 80241040 0C00A8D4 */  jal       cos_deg
/* ACF184 80241044 4600A306 */   mov.s    $f12, $f20
/* ACF188 80241048 46180002 */  mul.s     $f0, $f0, $f24
/* ACF18C 8024104C 00000000 */  nop
/* ACF190 80241050 0260202D */  daddu     $a0, $s3, $zero
/* ACF194 80241054 02A0282D */  daddu     $a1, $s5, $zero
/* ACF198 80241058 C6540030 */  lwc1      $f20, 0x30($s2)
/* ACF19C 8024105C 0280302D */  daddu     $a2, $s4, $zero
/* ACF1A0 80241060 0C0B2026 */  jal       set_variable
/* ACF1A4 80241064 4600A501 */   sub.s    $f20, $f20, $f0
/* ACF1A8 80241068 0260202D */  daddu     $a0, $s3, $zero
/* ACF1AC 8024106C 4600B08D */  trunc.w.s $f2, $f22
/* ACF1B0 80241070 44061000 */  mfc1      $a2, $f2
/* ACF1B4 80241074 0C0B2026 */  jal       set_variable
/* ACF1B8 80241078 02C0282D */   daddu    $a1, $s6, $zero
/* ACF1BC 8024107C 0260202D */  daddu     $a0, $s3, $zero
/* ACF1C0 80241080 4600A08D */  trunc.w.s $f2, $f20
/* ACF1C4 80241084 44061000 */  mfc1      $a2, $f2
/* ACF1C8 80241088 0C0B2026 */  jal       set_variable
/* ACF1CC 8024108C 02E0282D */   daddu    $a1, $s7, $zero
.L80241090:
/* ACF1D0 80241090 24020002 */  addiu     $v0, $zero, 2
/* ACF1D4 80241094 8FBF0030 */  lw        $ra, 0x30($sp)
/* ACF1D8 80241098 8FB7002C */  lw        $s7, 0x2c($sp)
/* ACF1DC 8024109C 8FB60028 */  lw        $s6, 0x28($sp)
/* ACF1E0 802410A0 8FB50024 */  lw        $s5, 0x24($sp)
/* ACF1E4 802410A4 8FB40020 */  lw        $s4, 0x20($sp)
/* ACF1E8 802410A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* ACF1EC 802410AC 8FB20018 */  lw        $s2, 0x18($sp)
/* ACF1F0 802410B0 8FB10014 */  lw        $s1, 0x14($sp)
/* ACF1F4 802410B4 8FB00010 */  lw        $s0, 0x10($sp)
/* ACF1F8 802410B8 D7B80048 */  ldc1      $f24, 0x48($sp)
/* ACF1FC 802410BC D7B60040 */  ldc1      $f22, 0x40($sp)
/* ACF200 802410C0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* ACF204 802410C4 03E00008 */  jr        $ra
/* ACF208 802410C8 27BD0050 */   addiu    $sp, $sp, 0x50
/* ACF20C 802410CC 00000000 */  nop
