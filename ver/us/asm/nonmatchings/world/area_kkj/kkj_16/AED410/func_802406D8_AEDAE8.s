.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406D8_AEDAE8
/* AEDAE8 802406D8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AEDAEC 802406DC AFB3001C */  sw        $s3, 0x1c($sp)
/* AEDAF0 802406E0 0080982D */  daddu     $s3, $a0, $zero
/* AEDAF4 802406E4 AFBF0030 */  sw        $ra, 0x30($sp)
/* AEDAF8 802406E8 AFB7002C */  sw        $s7, 0x2c($sp)
/* AEDAFC 802406EC AFB60028 */  sw        $s6, 0x28($sp)
/* AEDB00 802406F0 AFB50024 */  sw        $s5, 0x24($sp)
/* AEDB04 802406F4 AFB40020 */  sw        $s4, 0x20($sp)
/* AEDB08 802406F8 AFB20018 */  sw        $s2, 0x18($sp)
/* AEDB0C 802406FC AFB10014 */  sw        $s1, 0x14($sp)
/* AEDB10 80240700 AFB00010 */  sw        $s0, 0x10($sp)
/* AEDB14 80240704 F7B80048 */  sdc1      $f24, 0x48($sp)
/* AEDB18 80240708 F7B60040 */  sdc1      $f22, 0x40($sp)
/* AEDB1C 8024070C F7B40038 */  sdc1      $f20, 0x38($sp)
/* AEDB20 80240710 8E70000C */  lw        $s0, 0xc($s3)
/* AEDB24 80240714 8E050000 */  lw        $a1, ($s0)
/* AEDB28 80240718 0C0B1EAF */  jal       get_variable
/* AEDB2C 8024071C 26100004 */   addiu    $s0, $s0, 4
/* AEDB30 80240720 8E150000 */  lw        $s5, ($s0)
/* AEDB34 80240724 26100004 */  addiu     $s0, $s0, 4
/* AEDB38 80240728 0260202D */  daddu     $a0, $s3, $zero
/* AEDB3C 8024072C 8E160000 */  lw        $s6, ($s0)
/* AEDB40 80240730 8E170004 */  lw        $s7, 4($s0)
/* AEDB44 80240734 0C0B36B0 */  jal       resolve_npc
/* AEDB48 80240738 0040282D */   daddu    $a1, $v0, $zero
/* AEDB4C 8024073C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* AEDB50 80240740 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* AEDB54 80240744 0040802D */  daddu     $s0, $v0, $zero
/* AEDB58 80240748 1200002F */  beqz      $s0, .L80240808
/* AEDB5C 8024074C 0220902D */   daddu    $s2, $s1, $zero
/* AEDB60 80240750 C62C0028 */  lwc1      $f12, 0x28($s1)
/* AEDB64 80240754 C62E0030 */  lwc1      $f14, 0x30($s1)
/* AEDB68 80240758 8E060038 */  lw        $a2, 0x38($s0)
/* AEDB6C 8024075C 8E070040 */  lw        $a3, 0x40($s0)
/* AEDB70 80240760 3C014248 */  lui       $at, 0x4248
/* AEDB74 80240764 4481C000 */  mtc1      $at, $f24
/* AEDB78 80240768 0C00A7B5 */  jal       dist2D
/* AEDB7C 8024076C 24140001 */   addiu    $s4, $zero, 1
/* AEDB80 80240770 4618003C */  c.lt.s    $f0, $f24
/* AEDB84 80240774 00000000 */  nop
/* AEDB88 80240778 45030001 */  bc1tl     .L80240780
/* AEDB8C 8024077C 0000A02D */   daddu    $s4, $zero, $zero
.L80240780:
/* AEDB90 80240780 C64C0028 */  lwc1      $f12, 0x28($s2)
/* AEDB94 80240784 C64E0030 */  lwc1      $f14, 0x30($s2)
/* AEDB98 80240788 8E060038 */  lw        $a2, 0x38($s0)
/* AEDB9C 8024078C 0C00A720 */  jal       atan2
/* AEDBA0 80240790 8E070040 */   lw       $a3, 0x40($s0)
/* AEDBA4 80240794 0C00A6C9 */  jal       clamp_angle
/* AEDBA8 80240798 46000306 */   mov.s    $f12, $f0
/* AEDBAC 8024079C 46000506 */  mov.s     $f20, $f0
/* AEDBB0 802407A0 0C00A8BB */  jal       sin_deg
/* AEDBB4 802407A4 4600A306 */   mov.s    $f12, $f20
/* AEDBB8 802407A8 46180002 */  mul.s     $f0, $f0, $f24
/* AEDBBC 802407AC 00000000 */  nop
/* AEDBC0 802407B0 C6560028 */  lwc1      $f22, 0x28($s2)
/* AEDBC4 802407B4 4600B580 */  add.s     $f22, $f22, $f0
/* AEDBC8 802407B8 0C00A8D4 */  jal       cos_deg
/* AEDBCC 802407BC 4600A306 */   mov.s    $f12, $f20
/* AEDBD0 802407C0 46180002 */  mul.s     $f0, $f0, $f24
/* AEDBD4 802407C4 00000000 */  nop
/* AEDBD8 802407C8 0260202D */  daddu     $a0, $s3, $zero
/* AEDBDC 802407CC 02A0282D */  daddu     $a1, $s5, $zero
/* AEDBE0 802407D0 C6540030 */  lwc1      $f20, 0x30($s2)
/* AEDBE4 802407D4 0280302D */  daddu     $a2, $s4, $zero
/* AEDBE8 802407D8 0C0B2026 */  jal       evt_set_variable
/* AEDBEC 802407DC 4600A501 */   sub.s    $f20, $f20, $f0
/* AEDBF0 802407E0 0260202D */  daddu     $a0, $s3, $zero
/* AEDBF4 802407E4 4600B08D */  trunc.w.s $f2, $f22
/* AEDBF8 802407E8 44061000 */  mfc1      $a2, $f2
/* AEDBFC 802407EC 0C0B2026 */  jal       evt_set_variable
/* AEDC00 802407F0 02C0282D */   daddu    $a1, $s6, $zero
/* AEDC04 802407F4 0260202D */  daddu     $a0, $s3, $zero
/* AEDC08 802407F8 4600A08D */  trunc.w.s $f2, $f20
/* AEDC0C 802407FC 44061000 */  mfc1      $a2, $f2
/* AEDC10 80240800 0C0B2026 */  jal       evt_set_variable
/* AEDC14 80240804 02E0282D */   daddu    $a1, $s7, $zero
.L80240808:
/* AEDC18 80240808 24020002 */  addiu     $v0, $zero, 2
/* AEDC1C 8024080C 8FBF0030 */  lw        $ra, 0x30($sp)
/* AEDC20 80240810 8FB7002C */  lw        $s7, 0x2c($sp)
/* AEDC24 80240814 8FB60028 */  lw        $s6, 0x28($sp)
/* AEDC28 80240818 8FB50024 */  lw        $s5, 0x24($sp)
/* AEDC2C 8024081C 8FB40020 */  lw        $s4, 0x20($sp)
/* AEDC30 80240820 8FB3001C */  lw        $s3, 0x1c($sp)
/* AEDC34 80240824 8FB20018 */  lw        $s2, 0x18($sp)
/* AEDC38 80240828 8FB10014 */  lw        $s1, 0x14($sp)
/* AEDC3C 8024082C 8FB00010 */  lw        $s0, 0x10($sp)
/* AEDC40 80240830 D7B80048 */  ldc1      $f24, 0x48($sp)
/* AEDC44 80240834 D7B60040 */  ldc1      $f22, 0x40($sp)
/* AEDC48 80240838 D7B40038 */  ldc1      $f20, 0x38($sp)
/* AEDC4C 8024083C 03E00008 */  jr        $ra
/* AEDC50 80240840 27BD0050 */   addiu    $sp, $sp, 0x50
/* AEDC54 80240844 00000000 */  nop
/* AEDC58 80240848 00000000 */  nop
/* AEDC5C 8024084C 00000000 */  nop
