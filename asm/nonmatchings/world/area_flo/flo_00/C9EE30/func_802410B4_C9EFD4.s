.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410B4_C9EFD4
/* C9EFD4 802410B4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C9EFD8 802410B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C9EFDC 802410BC 0080802D */  daddu     $s0, $a0, $zero
/* C9EFE0 802410C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C9EFE4 802410C4 AFB10014 */  sw        $s1, 0x14($sp)
/* C9EFE8 802410C8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* C9EFEC 802410CC F7B80030 */  sdc1      $f24, 0x30($sp)
/* C9EFF0 802410D0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* C9EFF4 802410D4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* C9EFF8 802410D8 0C00E2B7 */  jal       get_npc_by_index
/* C9EFFC 802410DC 0000202D */   daddu    $a0, $zero, $zero
/* C9F000 802410E0 0000202D */  daddu     $a0, $zero, $zero
/* C9F004 802410E4 8E05008C */  lw        $a1, 0x8c($s0)
/* C9F008 802410E8 0C0B1EAF */  jal       get_variable
/* C9F00C 802410EC 0040882D */   daddu    $s1, $v0, $zero
/* C9F010 802410F0 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* C9F014 802410F4 468010A0 */  cvt.s.w   $f2, $f2
/* C9F018 802410F8 44061000 */  mfc1      $a2, $f2
/* C9F01C 802410FC C60200BC */  lwc1      $f2, 0xbc($s0)
/* C9F020 80241100 468010A0 */  cvt.s.w   $f2, $f2
/* C9F024 80241104 4482A000 */  mtc1      $v0, $f20
/* C9F028 80241108 00000000 */  nop
/* C9F02C 8024110C 4680A520 */  cvt.s.w   $f20, $f20
/* C9F030 80241110 3C01C2A6 */  lui       $at, 0xc2a6
/* C9F034 80241114 4481C000 */  mtc1      $at, $f24
/* C9F038 80241118 3C0142AE */  lui       $at, 0x42ae
/* C9F03C 8024111C 4481D000 */  mtc1      $at, $f26
/* C9F040 80241120 44071000 */  mfc1      $a3, $f2
/* C9F044 80241124 4600C306 */  mov.s     $f12, $f24
/* C9F048 80241128 0C00A7B5 */  jal       dist2D
/* C9F04C 8024112C 4600D386 */   mov.s    $f14, $f26
/* C9F050 80241130 4600C306 */  mov.s     $f12, $f24
/* C9F054 80241134 4600D386 */  mov.s     $f14, $f26
/* C9F058 80241138 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* C9F05C 8024113C 468010A0 */  cvt.s.w   $f2, $f2
/* C9F060 80241140 44061000 */  mfc1      $a2, $f2
/* C9F064 80241144 C60200BC */  lwc1      $f2, 0xbc($s0)
/* C9F068 80241148 468010A0 */  cvt.s.w   $f2, $f2
/* C9F06C 8024114C 44071000 */  mfc1      $a3, $f2
/* C9F070 80241150 0C00A720 */  jal       atan2
/* C9F074 80241154 46000586 */   mov.s    $f22, $f0
/* C9F078 80241158 0C00A6C9 */  jal       clamp_angle
/* C9F07C 8024115C 46140301 */   sub.s    $f12, $f0, $f20
/* C9F080 80241160 46000506 */  mov.s     $f20, $f0
/* C9F084 80241164 0C00A8BB */  jal       sin_deg
/* C9F088 80241168 4600A306 */   mov.s    $f12, $f20
/* C9F08C 8024116C 4600B002 */  mul.s     $f0, $f22, $f0
/* C9F090 80241170 00000000 */  nop
/* C9F094 80241174 46180000 */  add.s     $f0, $f0, $f24
/* C9F098 80241178 E6200038 */  swc1      $f0, 0x38($s1)
/* C9F09C 8024117C 8E0500B8 */  lw        $a1, 0xb8($s0)
/* C9F0A0 80241180 0C0B1EAF */  jal       get_variable
/* C9F0A4 80241184 0000202D */   daddu    $a0, $zero, $zero
/* C9F0A8 80241188 0000202D */  daddu     $a0, $zero, $zero
/* C9F0AC 8024118C 8E050090 */  lw        $a1, 0x90($s0)
/* C9F0B0 80241190 0C0B1EAF */  jal       get_variable
/* C9F0B4 80241194 0040802D */   daddu    $s0, $v0, $zero
/* C9F0B8 80241198 4600A306 */  mov.s     $f12, $f20
/* C9F0BC 8024119C 02028021 */  addu      $s0, $s0, $v0
/* C9F0C0 802411A0 44900000 */  mtc1      $s0, $f0
/* C9F0C4 802411A4 00000000 */  nop
/* C9F0C8 802411A8 46800020 */  cvt.s.w   $f0, $f0
/* C9F0CC 802411AC 0C00A8D4 */  jal       cos_deg
/* C9F0D0 802411B0 E620003C */   swc1     $f0, 0x3c($s1)
/* C9F0D4 802411B4 4600B582 */  mul.s     $f22, $f22, $f0
/* C9F0D8 802411B8 00000000 */  nop
/* C9F0DC 802411BC 4616D681 */  sub.s     $f26, $f26, $f22
/* C9F0E0 802411C0 E63A0040 */  swc1      $f26, 0x40($s1)
/* C9F0E4 802411C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9F0E8 802411C8 8FB10014 */  lw        $s1, 0x14($sp)
/* C9F0EC 802411CC 8FB00010 */  lw        $s0, 0x10($sp)
/* C9F0F0 802411D0 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* C9F0F4 802411D4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* C9F0F8 802411D8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* C9F0FC 802411DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* C9F100 802411E0 24020002 */  addiu     $v0, $zero, 2
/* C9F104 802411E4 03E00008 */  jr        $ra
/* C9F108 802411E8 27BD0040 */   addiu    $sp, $sp, 0x40
