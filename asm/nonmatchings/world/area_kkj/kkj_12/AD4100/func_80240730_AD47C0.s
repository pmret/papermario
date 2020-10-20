.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_AD47C0
/* AD47C0 80240730 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AD47C4 80240734 AFB3001C */  sw        $s3, 0x1c($sp)
/* AD47C8 80240738 0080982D */  daddu     $s3, $a0, $zero
/* AD47CC 8024073C AFBF0030 */  sw        $ra, 0x30($sp)
/* AD47D0 80240740 AFB7002C */  sw        $s7, 0x2c($sp)
/* AD47D4 80240744 AFB60028 */  sw        $s6, 0x28($sp)
/* AD47D8 80240748 AFB50024 */  sw        $s5, 0x24($sp)
/* AD47DC 8024074C AFB40020 */  sw        $s4, 0x20($sp)
/* AD47E0 80240750 AFB20018 */  sw        $s2, 0x18($sp)
/* AD47E4 80240754 AFB10014 */  sw        $s1, 0x14($sp)
/* AD47E8 80240758 AFB00010 */  sw        $s0, 0x10($sp)
/* AD47EC 8024075C F7B80048 */  sdc1      $f24, 0x48($sp)
/* AD47F0 80240760 F7B60040 */  sdc1      $f22, 0x40($sp)
/* AD47F4 80240764 F7B40038 */  sdc1      $f20, 0x38($sp)
/* AD47F8 80240768 8E70000C */  lw        $s0, 0xc($s3)
/* AD47FC 8024076C 8E050000 */  lw        $a1, ($s0)
/* AD4800 80240770 0C0B1EAF */  jal       get_variable
/* AD4804 80240774 26100004 */   addiu    $s0, $s0, 4
/* AD4808 80240778 8E150000 */  lw        $s5, ($s0)
/* AD480C 8024077C 26100004 */  addiu     $s0, $s0, 4
/* AD4810 80240780 0260202D */  daddu     $a0, $s3, $zero
/* AD4814 80240784 8E160000 */  lw        $s6, ($s0)
/* AD4818 80240788 8E170004 */  lw        $s7, 4($s0)
/* AD481C 8024078C 0C0B36B0 */  jal       resolve_npc
/* AD4820 80240790 0040282D */   daddu    $a1, $v0, $zero
/* AD4824 80240794 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* AD4828 80240798 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* AD482C 8024079C 0040802D */  daddu     $s0, $v0, $zero
/* AD4830 802407A0 1200002F */  beqz      $s0, .L80240860
/* AD4834 802407A4 0220902D */   daddu    $s2, $s1, $zero
/* AD4838 802407A8 C62C0028 */  lwc1      $f12, 0x28($s1)
/* AD483C 802407AC C62E0030 */  lwc1      $f14, 0x30($s1)
/* AD4840 802407B0 8E060038 */  lw        $a2, 0x38($s0)
/* AD4844 802407B4 8E070040 */  lw        $a3, 0x40($s0)
/* AD4848 802407B8 3C0142C8 */  lui       $at, 0x42c8
/* AD484C 802407BC 4481C000 */  mtc1      $at, $f24
/* AD4850 802407C0 0C00A7B5 */  jal       dist2D
/* AD4854 802407C4 24140001 */   addiu    $s4, $zero, 1
/* AD4858 802407C8 4618003C */  c.lt.s    $f0, $f24
/* AD485C 802407CC 00000000 */  nop       
/* AD4860 802407D0 45030001 */  bc1tl     .L802407D8
/* AD4864 802407D4 0000A02D */   daddu    $s4, $zero, $zero
.L802407D8:
/* AD4868 802407D8 C64C0028 */  lwc1      $f12, 0x28($s2)
/* AD486C 802407DC C64E0030 */  lwc1      $f14, 0x30($s2)
/* AD4870 802407E0 8E060038 */  lw        $a2, 0x38($s0)
/* AD4874 802407E4 0C00A720 */  jal       atan2
/* AD4878 802407E8 8E070040 */   lw       $a3, 0x40($s0)
/* AD487C 802407EC 0C00A6C9 */  jal       clamp_angle
/* AD4880 802407F0 46000306 */   mov.s    $f12, $f0
/* AD4884 802407F4 46000506 */  mov.s     $f20, $f0
/* AD4888 802407F8 0C00A8BB */  jal       sin_deg
/* AD488C 802407FC 4600A306 */   mov.s    $f12, $f20
/* AD4890 80240800 46180002 */  mul.s     $f0, $f0, $f24
/* AD4894 80240804 00000000 */  nop       
/* AD4898 80240808 C6560028 */  lwc1      $f22, 0x28($s2)
/* AD489C 8024080C 4600B580 */  add.s     $f22, $f22, $f0
/* AD48A0 80240810 0C00A8D4 */  jal       cos_deg
/* AD48A4 80240814 4600A306 */   mov.s    $f12, $f20
/* AD48A8 80240818 46180002 */  mul.s     $f0, $f0, $f24
/* AD48AC 8024081C 00000000 */  nop       
/* AD48B0 80240820 0260202D */  daddu     $a0, $s3, $zero
/* AD48B4 80240824 02A0282D */  daddu     $a1, $s5, $zero
/* AD48B8 80240828 C6540030 */  lwc1      $f20, 0x30($s2)
/* AD48BC 8024082C 0280302D */  daddu     $a2, $s4, $zero
/* AD48C0 80240830 0C0B2026 */  jal       set_variable
/* AD48C4 80240834 4600A501 */   sub.s    $f20, $f20, $f0
/* AD48C8 80240838 0260202D */  daddu     $a0, $s3, $zero
/* AD48CC 8024083C 4600B08D */  trunc.w.s $f2, $f22
/* AD48D0 80240840 44061000 */  mfc1      $a2, $f2
/* AD48D4 80240844 0C0B2026 */  jal       set_variable
/* AD48D8 80240848 02C0282D */   daddu    $a1, $s6, $zero
/* AD48DC 8024084C 0260202D */  daddu     $a0, $s3, $zero
/* AD48E0 80240850 4600A08D */  trunc.w.s $f2, $f20
/* AD48E4 80240854 44061000 */  mfc1      $a2, $f2
/* AD48E8 80240858 0C0B2026 */  jal       set_variable
/* AD48EC 8024085C 02E0282D */   daddu    $a1, $s7, $zero
.L80240860:
/* AD48F0 80240860 24020002 */  addiu     $v0, $zero, 2
/* AD48F4 80240864 8FBF0030 */  lw        $ra, 0x30($sp)
/* AD48F8 80240868 8FB7002C */  lw        $s7, 0x2c($sp)
/* AD48FC 8024086C 8FB60028 */  lw        $s6, 0x28($sp)
/* AD4900 80240870 8FB50024 */  lw        $s5, 0x24($sp)
/* AD4904 80240874 8FB40020 */  lw        $s4, 0x20($sp)
/* AD4908 80240878 8FB3001C */  lw        $s3, 0x1c($sp)
/* AD490C 8024087C 8FB20018 */  lw        $s2, 0x18($sp)
/* AD4910 80240880 8FB10014 */  lw        $s1, 0x14($sp)
/* AD4914 80240884 8FB00010 */  lw        $s0, 0x10($sp)
/* AD4918 80240888 D7B80048 */  ldc1      $f24, 0x48($sp)
/* AD491C 8024088C D7B60040 */  ldc1      $f22, 0x40($sp)
/* AD4920 80240890 D7B40038 */  ldc1      $f20, 0x38($sp)
/* AD4924 80240894 03E00008 */  jr        $ra
/* AD4928 80240898 27BD0050 */   addiu    $sp, $sp, 0x50
