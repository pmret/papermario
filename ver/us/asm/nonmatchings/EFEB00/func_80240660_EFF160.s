.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240660_EFF160
/* EFF160 80240660 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EFF164 80240664 AFB00010 */  sw        $s0, 0x10($sp)
/* EFF168 80240668 0080802D */  daddu     $s0, $a0, $zero
/* EFF16C 8024066C AFBF0018 */  sw        $ra, 0x18($sp)
/* EFF170 80240670 AFB10014 */  sw        $s1, 0x14($sp)
/* EFF174 80240674 F7B80030 */  sdc1      $f24, 0x30($sp)
/* EFF178 80240678 F7B60028 */  sdc1      $f22, 0x28($sp)
/* EFF17C 8024067C F7B40020 */  sdc1      $f20, 0x20($sp)
/* EFF180 80240680 0C00F10F */  jal       func_8003C43C
/* EFF184 80240684 0000202D */   daddu    $a0, $zero, $zero
/* EFF188 80240688 0000202D */  daddu     $a0, $zero, $zero
/* EFF18C 8024068C 8E05008C */  lw        $a1, 0x8c($s0)
/* EFF190 80240690 4480B000 */  mtc1      $zero, $f22
/* EFF194 80240694 0C0B53A3 */  jal       dead_get_variable
/* EFF198 80240698 0040882D */   daddu    $s1, $v0, $zero
/* EFF19C 8024069C 4600B306 */  mov.s     $f12, $f22
/* EFF1A0 802406A0 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* EFF1A4 802406A4 468010A0 */  cvt.s.w   $f2, $f2
/* EFF1A8 802406A8 44061000 */  mfc1      $a2, $f2
/* EFF1AC 802406AC C60200BC */  lwc1      $f2, 0xbc($s0)
/* EFF1B0 802406B0 468010A0 */  cvt.s.w   $f2, $f2
/* EFF1B4 802406B4 44071000 */  mfc1      $a3, $f2
/* EFF1B8 802406B8 4482A000 */  mtc1      $v0, $f20
/* EFF1BC 802406BC 00000000 */  nop
/* EFF1C0 802406C0 4680A520 */  cvt.s.w   $f20, $f20
/* EFF1C4 802406C4 0C00AC71 */  jal       func_8002B1C4
/* EFF1C8 802406C8 4600B386 */   mov.s    $f14, $f22
/* EFF1CC 802406CC 4600B306 */  mov.s     $f12, $f22
/* EFF1D0 802406D0 4600B386 */  mov.s     $f14, $f22
/* EFF1D4 802406D4 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* EFF1D8 802406D8 468010A0 */  cvt.s.w   $f2, $f2
/* EFF1DC 802406DC 44061000 */  mfc1      $a2, $f2
/* EFF1E0 802406E0 C60200BC */  lwc1      $f2, 0xbc($s0)
/* EFF1E4 802406E4 468010A0 */  cvt.s.w   $f2, $f2
/* EFF1E8 802406E8 44071000 */  mfc1      $a3, $f2
/* EFF1EC 802406EC 0C00ABDC */  jal       fio_validate_header_checksums
/* EFF1F0 802406F0 46000606 */   mov.s    $f24, $f0
/* EFF1F4 802406F4 0C00AB85 */  jal       func_8002AE14
/* EFF1F8 802406F8 46140301 */   sub.s    $f12, $f0, $f20
/* EFF1FC 802406FC 46000506 */  mov.s     $f20, $f0
/* EFF200 80240700 0C00AD77 */  jal       func_8002B5DC
/* EFF204 80240704 4600A306 */   mov.s    $f12, $f20
/* EFF208 80240708 4600C002 */  mul.s     $f0, $f24, $f0
/* EFF20C 8024070C 00000000 */  nop
/* EFF210 80240710 46160000 */  add.s     $f0, $f0, $f22
/* EFF214 80240714 E6200038 */  swc1      $f0, 0x38($s1)
/* EFF218 80240718 8E0500B8 */  lw        $a1, 0xb8($s0)
/* EFF21C 8024071C 0C0B53A3 */  jal       dead_get_variable
/* EFF220 80240720 0000202D */   daddu    $a0, $zero, $zero
/* EFF224 80240724 0000202D */  daddu     $a0, $zero, $zero
/* EFF228 80240728 8E050090 */  lw        $a1, 0x90($s0)
/* EFF22C 8024072C 0C0B53A3 */  jal       dead_get_variable
/* EFF230 80240730 0040802D */   daddu    $s0, $v0, $zero
/* EFF234 80240734 4600A306 */  mov.s     $f12, $f20
/* EFF238 80240738 02028021 */  addu      $s0, $s0, $v0
/* EFF23C 8024073C 44900000 */  mtc1      $s0, $f0
/* EFF240 80240740 00000000 */  nop
/* EFF244 80240744 46800020 */  cvt.s.w   $f0, $f0
/* EFF248 80240748 0C00AD90 */  jal       func_8002B640
/* EFF24C 8024074C E620003C */   swc1     $f0, 0x3c($s1)
/* EFF250 80240750 4600C602 */  mul.s     $f24, $f24, $f0
/* EFF254 80240754 00000000 */  nop
/* EFF258 80240758 4618B581 */  sub.s     $f22, $f22, $f24
/* EFF25C 8024075C E6360040 */  swc1      $f22, 0x40($s1)
/* EFF260 80240760 8FBF0018 */  lw        $ra, 0x18($sp)
/* EFF264 80240764 8FB10014 */  lw        $s1, 0x14($sp)
/* EFF268 80240768 8FB00010 */  lw        $s0, 0x10($sp)
/* EFF26C 8024076C D7B80030 */  ldc1      $f24, 0x30($sp)
/* EFF270 80240770 D7B60028 */  ldc1      $f22, 0x28($sp)
/* EFF274 80240774 D7B40020 */  ldc1      $f20, 0x20($sp)
/* EFF278 80240778 24020002 */  addiu     $v0, $zero, 2
/* EFF27C 8024077C 03E00008 */  jr        $ra
/* EFF280 80240780 27BD0038 */   addiu    $sp, $sp, 0x38
