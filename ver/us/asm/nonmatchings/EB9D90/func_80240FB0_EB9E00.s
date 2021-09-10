.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB0_EB9E00
/* EB9E00 80240FB0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EB9E04 80240FB4 AFB00010 */  sw        $s0, 0x10($sp)
/* EB9E08 80240FB8 0080802D */  daddu     $s0, $a0, $zero
/* EB9E0C 80240FBC AFBF0018 */  sw        $ra, 0x18($sp)
/* EB9E10 80240FC0 AFB10014 */  sw        $s1, 0x14($sp)
/* EB9E14 80240FC4 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* EB9E18 80240FC8 F7B80030 */  sdc1      $f24, 0x30($sp)
/* EB9E1C 80240FCC F7B60028 */  sdc1      $f22, 0x28($sp)
/* EB9E20 80240FD0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* EB9E24 80240FD4 8E05008C */  lw        $a1, 0x8c($s0)
/* EB9E28 80240FD8 0C0B53A3 */  jal       dead_evt_get_variable
/* EB9E2C 80240FDC 0000202D */   daddu    $a0, $zero, $zero
/* EB9E30 80240FE0 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* EB9E34 80240FE4 468010A0 */  cvt.s.w   $f2, $f2
/* EB9E38 80240FE8 44061000 */  mfc1      $a2, $f2
/* EB9E3C 80240FEC C60200B0 */  lwc1      $f2, 0xb0($s0)
/* EB9E40 80240FF0 468010A0 */  cvt.s.w   $f2, $f2
/* EB9E44 80240FF4 4482A000 */  mtc1      $v0, $f20
/* EB9E48 80240FF8 00000000 */  nop
/* EB9E4C 80240FFC 4680A520 */  cvt.s.w   $f20, $f20
/* EB9E50 80241000 3C01C2A6 */  lui       $at, 0xc2a6
/* EB9E54 80241004 4481C000 */  mtc1      $at, $f24
/* EB9E58 80241008 3C0142AE */  lui       $at, 0x42ae
/* EB9E5C 8024100C 4481D000 */  mtc1      $at, $f26
/* EB9E60 80241010 44071000 */  mfc1      $a3, $f2
/* EB9E64 80241014 4600C306 */  mov.s     $f12, $f24
/* EB9E68 80241018 0C00AC71 */  jal       func_8002B1C4
/* EB9E6C 8024101C 4600D386 */   mov.s    $f14, $f26
/* EB9E70 80241020 4600C306 */  mov.s     $f12, $f24
/* EB9E74 80241024 4600D386 */  mov.s     $f14, $f26
/* EB9E78 80241028 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* EB9E7C 8024102C 468010A0 */  cvt.s.w   $f2, $f2
/* EB9E80 80241030 44061000 */  mfc1      $a2, $f2
/* EB9E84 80241034 C60200B0 */  lwc1      $f2, 0xb0($s0)
/* EB9E88 80241038 468010A0 */  cvt.s.w   $f2, $f2
/* EB9E8C 8024103C 44071000 */  mfc1      $a3, $f2
/* EB9E90 80241040 0C00ABDC */  jal       fio_validate_header_checksums
/* EB9E94 80241044 46000586 */   mov.s    $f22, $f0
/* EB9E98 80241048 0C00AB85 */  jal       dead_clamp_angle
/* EB9E9C 8024104C 46140301 */   sub.s    $f12, $f0, $f20
/* EB9EA0 80241050 46000506 */  mov.s     $f20, $f0
/* EB9EA4 80241054 0C00AD77 */  jal       func_8002B5DC
/* EB9EA8 80241058 4600A306 */   mov.s    $f12, $f20
/* EB9EAC 8024105C 4600B002 */  mul.s     $f0, $f22, $f0
/* EB9EB0 80241060 00000000 */  nop
/* EB9EB4 80241064 46180000 */  add.s     $f0, $f0, $f24
/* EB9EB8 80241068 3C118011 */  lui       $s1, %hi(D_80117578)
/* EB9EBC 8024106C 26317578 */  addiu     $s1, $s1, %lo(D_80117578)
/* EB9EC0 80241070 E6200028 */  swc1      $f0, 0x28($s1)
/* EB9EC4 80241074 8E0500AC */  lw        $a1, 0xac($s0)
/* EB9EC8 80241078 0C0B53A3 */  jal       dead_evt_get_variable
/* EB9ECC 8024107C 0000202D */   daddu    $a0, $zero, $zero
/* EB9ED0 80241080 0000202D */  daddu     $a0, $zero, $zero
/* EB9ED4 80241084 8E050090 */  lw        $a1, 0x90($s0)
/* EB9ED8 80241088 0C0B53A3 */  jal       dead_evt_get_variable
/* EB9EDC 8024108C 0040802D */   daddu    $s0, $v0, $zero
/* EB9EE0 80241090 4600A306 */  mov.s     $f12, $f20
/* EB9EE4 80241094 02028021 */  addu      $s0, $s0, $v0
/* EB9EE8 80241098 44900000 */  mtc1      $s0, $f0
/* EB9EEC 8024109C 00000000 */  nop
/* EB9EF0 802410A0 46800020 */  cvt.s.w   $f0, $f0
/* EB9EF4 802410A4 0C00AD90 */  jal       func_8002B640
/* EB9EF8 802410A8 E620002C */   swc1     $f0, 0x2c($s1)
/* EB9EFC 802410AC 4600B582 */  mul.s     $f22, $f22, $f0
/* EB9F00 802410B0 00000000 */  nop
/* EB9F04 802410B4 4616D681 */  sub.s     $f26, $f26, $f22
/* EB9F08 802410B8 E63A0030 */  swc1      $f26, 0x30($s1)
/* EB9F0C 802410BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB9F10 802410C0 8FB10014 */  lw        $s1, 0x14($sp)
/* EB9F14 802410C4 8FB00010 */  lw        $s0, 0x10($sp)
/* EB9F18 802410C8 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* EB9F1C 802410CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* EB9F20 802410D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* EB9F24 802410D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* EB9F28 802410D8 24020002 */  addiu     $v0, $zero, 2
/* EB9F2C 802410DC 03E00008 */  jr        $ra
/* EB9F30 802410E0 27BD0040 */   addiu    $sp, $sp, 0x40
