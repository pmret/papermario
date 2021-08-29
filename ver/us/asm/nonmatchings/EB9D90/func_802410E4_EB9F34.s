.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410E4_EB9F34
/* EB9F34 802410E4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EB9F38 802410E8 AFB00010 */  sw        $s0, 0x10($sp)
/* EB9F3C 802410EC 0080802D */  daddu     $s0, $a0, $zero
/* EB9F40 802410F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB9F44 802410F4 AFB10014 */  sw        $s1, 0x14($sp)
/* EB9F48 802410F8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* EB9F4C 802410FC F7B80030 */  sdc1      $f24, 0x30($sp)
/* EB9F50 80241100 F7B60028 */  sdc1      $f22, 0x28($sp)
/* EB9F54 80241104 F7B40020 */  sdc1      $f20, 0x20($sp)
/* EB9F58 80241108 0C00F10F */  jal       func_8003C43C
/* EB9F5C 8024110C 0000202D */   daddu    $a0, $zero, $zero
/* EB9F60 80241110 0000202D */  daddu     $a0, $zero, $zero
/* EB9F64 80241114 8E05008C */  lw        $a1, 0x8c($s0)
/* EB9F68 80241118 0C0B53A3 */  jal       dead_evt_get_variable
/* EB9F6C 8024111C 0040882D */   daddu    $s1, $v0, $zero
/* EB9F70 80241120 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* EB9F74 80241124 468010A0 */  cvt.s.w   $f2, $f2
/* EB9F78 80241128 44061000 */  mfc1      $a2, $f2
/* EB9F7C 8024112C C60200BC */  lwc1      $f2, 0xbc($s0)
/* EB9F80 80241130 468010A0 */  cvt.s.w   $f2, $f2
/* EB9F84 80241134 4482A000 */  mtc1      $v0, $f20
/* EB9F88 80241138 00000000 */  nop
/* EB9F8C 8024113C 4680A520 */  cvt.s.w   $f20, $f20
/* EB9F90 80241140 3C01C2A6 */  lui       $at, 0xc2a6
/* EB9F94 80241144 4481C000 */  mtc1      $at, $f24
/* EB9F98 80241148 3C0142AE */  lui       $at, 0x42ae
/* EB9F9C 8024114C 4481D000 */  mtc1      $at, $f26
/* EB9FA0 80241150 44071000 */  mfc1      $a3, $f2
/* EB9FA4 80241154 4600C306 */  mov.s     $f12, $f24
/* EB9FA8 80241158 0C00AC71 */  jal       func_8002B1C4
/* EB9FAC 8024115C 4600D386 */   mov.s    $f14, $f26
/* EB9FB0 80241160 4600C306 */  mov.s     $f12, $f24
/* EB9FB4 80241164 4600D386 */  mov.s     $f14, $f26
/* EB9FB8 80241168 C60200B4 */  lwc1      $f2, 0xb4($s0)
/* EB9FBC 8024116C 468010A0 */  cvt.s.w   $f2, $f2
/* EB9FC0 80241170 44061000 */  mfc1      $a2, $f2
/* EB9FC4 80241174 C60200BC */  lwc1      $f2, 0xbc($s0)
/* EB9FC8 80241178 468010A0 */  cvt.s.w   $f2, $f2
/* EB9FCC 8024117C 44071000 */  mfc1      $a3, $f2
/* EB9FD0 80241180 0C00ABDC */  jal       fio_validate_header_checksums
/* EB9FD4 80241184 46000586 */   mov.s    $f22, $f0
/* EB9FD8 80241188 0C00AB85 */  jal       dead_clamp_angle
/* EB9FDC 8024118C 46140301 */   sub.s    $f12, $f0, $f20
/* EB9FE0 80241190 46000506 */  mov.s     $f20, $f0
/* EB9FE4 80241194 0C00AD77 */  jal       func_8002B5DC
/* EB9FE8 80241198 4600A306 */   mov.s    $f12, $f20
/* EB9FEC 8024119C 4600B002 */  mul.s     $f0, $f22, $f0
/* EB9FF0 802411A0 00000000 */  nop
/* EB9FF4 802411A4 46180000 */  add.s     $f0, $f0, $f24
/* EB9FF8 802411A8 E6200038 */  swc1      $f0, 0x38($s1)
/* EB9FFC 802411AC 8E0500B8 */  lw        $a1, 0xb8($s0)
/* EBA000 802411B0 0C0B53A3 */  jal       dead_evt_get_variable
/* EBA004 802411B4 0000202D */   daddu    $a0, $zero, $zero
/* EBA008 802411B8 0000202D */  daddu     $a0, $zero, $zero
/* EBA00C 802411BC 8E050090 */  lw        $a1, 0x90($s0)
/* EBA010 802411C0 0C0B53A3 */  jal       dead_evt_get_variable
/* EBA014 802411C4 0040802D */   daddu    $s0, $v0, $zero
/* EBA018 802411C8 4600A306 */  mov.s     $f12, $f20
/* EBA01C 802411CC 02028021 */  addu      $s0, $s0, $v0
/* EBA020 802411D0 44900000 */  mtc1      $s0, $f0
/* EBA024 802411D4 00000000 */  nop
/* EBA028 802411D8 46800020 */  cvt.s.w   $f0, $f0
/* EBA02C 802411DC 0C00AD90 */  jal       func_8002B640
/* EBA030 802411E0 E620003C */   swc1     $f0, 0x3c($s1)
/* EBA034 802411E4 4600B582 */  mul.s     $f22, $f22, $f0
/* EBA038 802411E8 00000000 */  nop
/* EBA03C 802411EC 4616D681 */  sub.s     $f26, $f26, $f22
/* EBA040 802411F0 E63A0040 */  swc1      $f26, 0x40($s1)
/* EBA044 802411F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* EBA048 802411F8 8FB10014 */  lw        $s1, 0x14($sp)
/* EBA04C 802411FC 8FB00010 */  lw        $s0, 0x10($sp)
/* EBA050 80241200 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* EBA054 80241204 D7B80030 */  ldc1      $f24, 0x30($sp)
/* EBA058 80241208 D7B60028 */  ldc1      $f22, 0x28($sp)
/* EBA05C 8024120C D7B40020 */  ldc1      $f20, 0x20($sp)
/* EBA060 80241210 24020002 */  addiu     $v0, $zero, 2
/* EBA064 80241214 03E00008 */  jr        $ra
/* EBA068 80241218 27BD0040 */   addiu    $sp, $sp, 0x40
