.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240660_CE3D50
/* CE3D50 80240660 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CE3D54 80240664 AFB00010 */  sw        $s0, 0x10($sp)
/* CE3D58 80240668 0080802D */  daddu     $s0, $a0, $zero
/* CE3D5C 8024066C AFBF0018 */  sw        $ra, 0x18($sp)
/* CE3D60 80240670 AFB10014 */  sw        $s1, 0x14($sp)
/* CE3D64 80240674 F7B80030 */  sdc1      $f24, 0x30($sp)
/* CE3D68 80240678 F7B60028 */  sdc1      $f22, 0x28($sp)
/* CE3D6C 8024067C F7B40020 */  sdc1      $f20, 0x20($sp)
/* CE3D70 80240680 0C00E2B7 */  jal       get_npc_by_index
/* CE3D74 80240684 0000202D */   daddu    $a0, $zero, $zero
/* CE3D78 80240688 0000202D */  daddu     $a0, $zero, $zero
/* CE3D7C 8024068C 8E05008C */  lw        $a1, 0x8c($s0)
/* CE3D80 80240690 4480B000 */  mtc1      $zero, $f22
/* CE3D84 80240694 0C0B1EAF */  jal       get_variable
/* CE3D88 80240698 0040882D */   daddu    $s1, $v0, $zero
/* CE3D8C 8024069C 4600B306 */  mov.s     $f12, $f22
/* CE3D90 802406A0 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* CE3D94 802406A4 468010A0 */  cvt.s.w   $f2, $f2
/* CE3D98 802406A8 44061000 */  mfc1      $a2, $f2
/* CE3D9C 802406AC C60200BC */  lwc1      $f2, 0xbc($s0)
/* CE3DA0 802406B0 468010A0 */  cvt.s.w   $f2, $f2
/* CE3DA4 802406B4 44071000 */  mfc1      $a3, $f2
/* CE3DA8 802406B8 4482A000 */  mtc1      $v0, $f20
/* CE3DAC 802406BC 00000000 */  nop       
/* CE3DB0 802406C0 4680A520 */  cvt.s.w   $f20, $f20
/* CE3DB4 802406C4 0C00A7B5 */  jal       dist2D
/* CE3DB8 802406C8 4600B386 */   mov.s    $f14, $f22
/* CE3DBC 802406CC 4600B306 */  mov.s     $f12, $f22
/* CE3DC0 802406D0 4600B386 */  mov.s     $f14, $f22
/* CE3DC4 802406D4 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* CE3DC8 802406D8 468010A0 */  cvt.s.w   $f2, $f2
/* CE3DCC 802406DC 44061000 */  mfc1      $a2, $f2
/* CE3DD0 802406E0 C60200BC */  lwc1      $f2, 0xbc($s0)
/* CE3DD4 802406E4 468010A0 */  cvt.s.w   $f2, $f2
/* CE3DD8 802406E8 44071000 */  mfc1      $a3, $f2
/* CE3DDC 802406EC 0C00A720 */  jal       atan2
/* CE3DE0 802406F0 46000606 */   mov.s    $f24, $f0
/* CE3DE4 802406F4 0C00A6C9 */  jal       clamp_angle
/* CE3DE8 802406F8 46140301 */   sub.s    $f12, $f0, $f20
/* CE3DEC 802406FC 46000506 */  mov.s     $f20, $f0
/* CE3DF0 80240700 0C00A8BB */  jal       sin_deg
/* CE3DF4 80240704 4600A306 */   mov.s    $f12, $f20
/* CE3DF8 80240708 4600C002 */  mul.s     $f0, $f24, $f0
/* CE3DFC 8024070C 00000000 */  nop       
/* CE3E00 80240710 46160000 */  add.s     $f0, $f0, $f22
/* CE3E04 80240714 E6200038 */  swc1      $f0, 0x38($s1)
/* CE3E08 80240718 8E0500B8 */  lw        $a1, 0xb8($s0)
/* CE3E0C 8024071C 0C0B1EAF */  jal       get_variable
/* CE3E10 80240720 0000202D */   daddu    $a0, $zero, $zero
/* CE3E14 80240724 0000202D */  daddu     $a0, $zero, $zero
/* CE3E18 80240728 8E050090 */  lw        $a1, 0x90($s0)
/* CE3E1C 8024072C 0C0B1EAF */  jal       get_variable
/* CE3E20 80240730 0040802D */   daddu    $s0, $v0, $zero
/* CE3E24 80240734 4600A306 */  mov.s     $f12, $f20
/* CE3E28 80240738 02028021 */  addu      $s0, $s0, $v0
/* CE3E2C 8024073C 44900000 */  mtc1      $s0, $f0
/* CE3E30 80240740 00000000 */  nop       
/* CE3E34 80240744 46800020 */  cvt.s.w   $f0, $f0
/* CE3E38 80240748 0C00A8D4 */  jal       cos_deg
/* CE3E3C 8024074C E620003C */   swc1     $f0, 0x3c($s1)
/* CE3E40 80240750 4600C602 */  mul.s     $f24, $f24, $f0
/* CE3E44 80240754 00000000 */  nop       
/* CE3E48 80240758 4618B581 */  sub.s     $f22, $f22, $f24
/* CE3E4C 8024075C E6360040 */  swc1      $f22, 0x40($s1)
/* CE3E50 80240760 8FBF0018 */  lw        $ra, 0x18($sp)
/* CE3E54 80240764 8FB10014 */  lw        $s1, 0x14($sp)
/* CE3E58 80240768 8FB00010 */  lw        $s0, 0x10($sp)
/* CE3E5C 8024076C D7B80030 */  ldc1      $f24, 0x30($sp)
/* CE3E60 80240770 D7B60028 */  ldc1      $f22, 0x28($sp)
/* CE3E64 80240774 D7B40020 */  ldc1      $f20, 0x20($sp)
/* CE3E68 80240778 24020002 */  addiu     $v0, $zero, 2
/* CE3E6C 8024077C 03E00008 */  jr        $ra
/* CE3E70 80240780 27BD0038 */   addiu    $sp, $sp, 0x38
