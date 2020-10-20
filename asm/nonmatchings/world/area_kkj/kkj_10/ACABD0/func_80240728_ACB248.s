.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240728_ACB248
/* ACB248 80240728 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* ACB24C 8024072C AFB3001C */  sw        $s3, 0x1c($sp)
/* ACB250 80240730 0080982D */  daddu     $s3, $a0, $zero
/* ACB254 80240734 AFBF0030 */  sw        $ra, 0x30($sp)
/* ACB258 80240738 AFB7002C */  sw        $s7, 0x2c($sp)
/* ACB25C 8024073C AFB60028 */  sw        $s6, 0x28($sp)
/* ACB260 80240740 AFB50024 */  sw        $s5, 0x24($sp)
/* ACB264 80240744 AFB40020 */  sw        $s4, 0x20($sp)
/* ACB268 80240748 AFB20018 */  sw        $s2, 0x18($sp)
/* ACB26C 8024074C AFB10014 */  sw        $s1, 0x14($sp)
/* ACB270 80240750 AFB00010 */  sw        $s0, 0x10($sp)
/* ACB274 80240754 F7B80048 */  sdc1      $f24, 0x48($sp)
/* ACB278 80240758 F7B60040 */  sdc1      $f22, 0x40($sp)
/* ACB27C 8024075C F7B40038 */  sdc1      $f20, 0x38($sp)
/* ACB280 80240760 8E70000C */  lw        $s0, 0xc($s3)
/* ACB284 80240764 8E050000 */  lw        $a1, ($s0)
/* ACB288 80240768 0C0B1EAF */  jal       get_variable
/* ACB28C 8024076C 26100004 */   addiu    $s0, $s0, 4
/* ACB290 80240770 8E150000 */  lw        $s5, ($s0)
/* ACB294 80240774 26100004 */  addiu     $s0, $s0, 4
/* ACB298 80240778 0260202D */  daddu     $a0, $s3, $zero
/* ACB29C 8024077C 8E160000 */  lw        $s6, ($s0)
/* ACB2A0 80240780 8E170004 */  lw        $s7, 4($s0)
/* ACB2A4 80240784 0C0B36B0 */  jal       resolve_npc
/* ACB2A8 80240788 0040282D */   daddu    $a1, $v0, $zero
/* ACB2AC 8024078C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* ACB2B0 80240790 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* ACB2B4 80240794 0040802D */  daddu     $s0, $v0, $zero
/* ACB2B8 80240798 1200002F */  beqz      $s0, .L80240858
/* ACB2BC 8024079C 0220902D */   daddu    $s2, $s1, $zero
/* ACB2C0 802407A0 C62C0028 */  lwc1      $f12, 0x28($s1)
/* ACB2C4 802407A4 C62E0030 */  lwc1      $f14, 0x30($s1)
/* ACB2C8 802407A8 8E060038 */  lw        $a2, 0x38($s0)
/* ACB2CC 802407AC 8E070040 */  lw        $a3, 0x40($s0)
/* ACB2D0 802407B0 3C0142C8 */  lui       $at, 0x42c8
/* ACB2D4 802407B4 4481C000 */  mtc1      $at, $f24
/* ACB2D8 802407B8 0C00A7B5 */  jal       dist2D
/* ACB2DC 802407BC 24140001 */   addiu    $s4, $zero, 1
/* ACB2E0 802407C0 4618003C */  c.lt.s    $f0, $f24
/* ACB2E4 802407C4 00000000 */  nop       
/* ACB2E8 802407C8 45030001 */  bc1tl     .L802407D0
/* ACB2EC 802407CC 0000A02D */   daddu    $s4, $zero, $zero
.L802407D0:
/* ACB2F0 802407D0 C64C0028 */  lwc1      $f12, 0x28($s2)
/* ACB2F4 802407D4 C64E0030 */  lwc1      $f14, 0x30($s2)
/* ACB2F8 802407D8 8E060038 */  lw        $a2, 0x38($s0)
/* ACB2FC 802407DC 0C00A720 */  jal       atan2
/* ACB300 802407E0 8E070040 */   lw       $a3, 0x40($s0)
/* ACB304 802407E4 0C00A6C9 */  jal       clamp_angle
/* ACB308 802407E8 46000306 */   mov.s    $f12, $f0
/* ACB30C 802407EC 46000506 */  mov.s     $f20, $f0
/* ACB310 802407F0 0C00A8BB */  jal       sin_deg
/* ACB314 802407F4 4600A306 */   mov.s    $f12, $f20
/* ACB318 802407F8 46180002 */  mul.s     $f0, $f0, $f24
/* ACB31C 802407FC 00000000 */  nop       
/* ACB320 80240800 C6560028 */  lwc1      $f22, 0x28($s2)
/* ACB324 80240804 4600B580 */  add.s     $f22, $f22, $f0
/* ACB328 80240808 0C00A8D4 */  jal       cos_deg
/* ACB32C 8024080C 4600A306 */   mov.s    $f12, $f20
/* ACB330 80240810 46180002 */  mul.s     $f0, $f0, $f24
/* ACB334 80240814 00000000 */  nop       
/* ACB338 80240818 0260202D */  daddu     $a0, $s3, $zero
/* ACB33C 8024081C 02A0282D */  daddu     $a1, $s5, $zero
/* ACB340 80240820 C6540030 */  lwc1      $f20, 0x30($s2)
/* ACB344 80240824 0280302D */  daddu     $a2, $s4, $zero
/* ACB348 80240828 0C0B2026 */  jal       set_variable
/* ACB34C 8024082C 4600A501 */   sub.s    $f20, $f20, $f0
/* ACB350 80240830 0260202D */  daddu     $a0, $s3, $zero
/* ACB354 80240834 4600B08D */  trunc.w.s $f2, $f22
/* ACB358 80240838 44061000 */  mfc1      $a2, $f2
/* ACB35C 8024083C 0C0B2026 */  jal       set_variable
/* ACB360 80240840 02C0282D */   daddu    $a1, $s6, $zero
/* ACB364 80240844 0260202D */  daddu     $a0, $s3, $zero
/* ACB368 80240848 4600A08D */  trunc.w.s $f2, $f20
/* ACB36C 8024084C 44061000 */  mfc1      $a2, $f2
/* ACB370 80240850 0C0B2026 */  jal       set_variable
/* ACB374 80240854 02E0282D */   daddu    $a1, $s7, $zero
.L80240858:
/* ACB378 80240858 24020002 */  addiu     $v0, $zero, 2
/* ACB37C 8024085C 8FBF0030 */  lw        $ra, 0x30($sp)
/* ACB380 80240860 8FB7002C */  lw        $s7, 0x2c($sp)
/* ACB384 80240864 8FB60028 */  lw        $s6, 0x28($sp)
/* ACB388 80240868 8FB50024 */  lw        $s5, 0x24($sp)
/* ACB38C 8024086C 8FB40020 */  lw        $s4, 0x20($sp)
/* ACB390 80240870 8FB3001C */  lw        $s3, 0x1c($sp)
/* ACB394 80240874 8FB20018 */  lw        $s2, 0x18($sp)
/* ACB398 80240878 8FB10014 */  lw        $s1, 0x14($sp)
/* ACB39C 8024087C 8FB00010 */  lw        $s0, 0x10($sp)
/* ACB3A0 80240880 D7B80048 */  ldc1      $f24, 0x48($sp)
/* ACB3A4 80240884 D7B60040 */  ldc1      $f22, 0x40($sp)
/* ACB3A8 80240888 D7B40038 */  ldc1      $f20, 0x38($sp)
/* ACB3AC 8024088C 03E00008 */  jr        $ra
/* ACB3B0 80240890 27BD0050 */   addiu    $sp, $sp, 0x50
/* ACB3B4 80240894 00000000 */  nop       
/* ACB3B8 80240898 00000000 */  nop       
/* ACB3BC 8024089C 00000000 */  nop       
