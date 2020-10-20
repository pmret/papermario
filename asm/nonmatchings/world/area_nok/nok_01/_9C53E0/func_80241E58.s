.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E58
/* 9C7238 80241E58 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9C723C 80241E5C AFB10014 */  sw        $s1, 0x14($sp)
/* 9C7240 80241E60 0080882D */  daddu     $s1, $a0, $zero
/* 9C7244 80241E64 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9C7248 80241E68 AFB40020 */  sw        $s4, 0x20($sp)
/* 9C724C 80241E6C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9C7250 80241E70 AFB20018 */  sw        $s2, 0x18($sp)
/* 9C7254 80241E74 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7258 80241E78 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 9C725C 80241E7C F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 9C7260 80241E80 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 9C7264 80241E84 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 9C7268 80241E88 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 9C726C 80241E8C 8E30000C */  lw        $s0, 0xc($s1)
/* 9C7270 80241E90 8E130000 */  lw        $s3, ($s0)
/* 9C7274 80241E94 26100004 */  addiu     $s0, $s0, 4
/* 9C7278 80241E98 0C0B1EAF */  jal       get_variable
/* 9C727C 80241E9C 0260282D */   daddu    $a1, $s3, $zero
/* 9C7280 80241EA0 4482E000 */  mtc1      $v0, $f28
/* 9C7284 80241EA4 00000000 */  nop       
/* 9C7288 80241EA8 4680E720 */  cvt.s.w   $f28, $f28
/* 9C728C 80241EAC 8E140000 */  lw        $s4, ($s0)
/* 9C7290 80241EB0 26100004 */  addiu     $s0, $s0, 4
/* 9C7294 80241EB4 0220202D */  daddu     $a0, $s1, $zero
/* 9C7298 80241EB8 0C0B1EAF */  jal       get_variable
/* 9C729C 80241EBC 0280282D */   daddu    $a1, $s4, $zero
/* 9C72A0 80241EC0 4482D000 */  mtc1      $v0, $f26
/* 9C72A4 80241EC4 00000000 */  nop       
/* 9C72A8 80241EC8 4680D6A0 */  cvt.s.w   $f26, $f26
/* 9C72AC 80241ECC 8E100000 */  lw        $s0, ($s0)
/* 9C72B0 80241ED0 0220202D */  daddu     $a0, $s1, $zero
/* 9C72B4 80241ED4 0C0B1EAF */  jal       get_variable
/* 9C72B8 80241ED8 0200282D */   daddu    $a1, $s0, $zero
/* 9C72BC 80241EDC 4482C000 */  mtc1      $v0, $f24
/* 9C72C0 80241EE0 00000000 */  nop       
/* 9C72C4 80241EE4 4680C620 */  cvt.s.w   $f24, $f24
/* 9C72C8 80241EE8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 9C72CC 80241EEC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 9C72D0 80241EF0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 9C72D4 80241EF4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 9C72D8 80241EF8 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 9C72DC 80241EFC 44800000 */  mtc1      $zero, $f0
/* 9C72E0 80241F00 00031080 */  sll       $v0, $v1, 2
/* 9C72E4 80241F04 00431021 */  addu      $v0, $v0, $v1
/* 9C72E8 80241F08 00021080 */  sll       $v0, $v0, 2
/* 9C72EC 80241F0C 00431023 */  subu      $v0, $v0, $v1
/* 9C72F0 80241F10 000218C0 */  sll       $v1, $v0, 3
/* 9C72F4 80241F14 00431021 */  addu      $v0, $v0, $v1
/* 9C72F8 80241F18 000210C0 */  sll       $v0, $v0, 3
/* 9C72FC 80241F1C 46001032 */  c.eq.s    $f2, $f0
/* 9C7300 80241F20 3C01800B */  lui       $at, 0x800b
/* 9C7304 80241F24 00220821 */  addu      $at, $at, $v0
/* 9C7308 80241F28 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* 9C730C 80241F2C 45000005 */  bc1f      .L80241F44
/* 9C7310 80241F30 00000000 */   nop      
/* 9C7314 80241F34 3C0142C8 */  lui       $at, 0x42c8
/* 9C7318 80241F38 44810000 */  mtc1      $at, $f0
/* 9C731C 80241F3C 080907D5 */  j         .L80241F54
/* 9C7320 80241F40 4600B581 */   sub.s    $f22, $f22, $f0
.L80241F44:
/* 9C7324 80241F44 3C0142C8 */  lui       $at, 0x42c8
/* 9C7328 80241F48 44810000 */  mtc1      $at, $f0
/* 9C732C 80241F4C 00000000 */  nop       
/* 9C7330 80241F50 4600B580 */  add.s     $f22, $f22, $f0
.L80241F54:
/* 9C7334 80241F54 0C00A6C9 */  jal       clamp_angle
/* 9C7338 80241F58 4600B306 */   mov.s    $f12, $f22
/* 9C733C 80241F5C 46000586 */  mov.s     $f22, $f0
/* 9C7340 80241F60 3C014170 */  lui       $at, 0x4170
/* 9C7344 80241F64 4481A000 */  mtc1      $at, $f20
/* 9C7348 80241F68 0C00A8BB */  jal       sin_deg
/* 9C734C 80241F6C 4600B306 */   mov.s    $f12, $f22
/* 9C7350 80241F70 46140002 */  mul.s     $f0, $f0, $f20
/* 9C7354 80241F74 00000000 */  nop       
/* 9C7358 80241F78 864200B0 */  lh        $v0, 0xb0($s2)
/* 9C735C 80241F7C 3C013F00 */  lui       $at, 0x3f00
/* 9C7360 80241F80 44812000 */  mtc1      $at, $f4
/* 9C7364 80241F84 44821000 */  mtc1      $v0, $f2
/* 9C7368 80241F88 00000000 */  nop       
/* 9C736C 80241F8C 468010A0 */  cvt.s.w   $f2, $f2
/* 9C7370 80241F90 46041082 */  mul.s     $f2, $f2, $f4
/* 9C7374 80241F94 00000000 */  nop       
/* 9C7378 80241F98 4600E700 */  add.s     $f28, $f28, $f0
/* 9C737C 80241F9C 4602D680 */  add.s     $f26, $f26, $f2
/* 9C7380 80241FA0 0C00A8D4 */  jal       cos_deg
/* 9C7384 80241FA4 4600B306 */   mov.s    $f12, $f22
/* 9C7388 80241FA8 46140002 */  mul.s     $f0, $f0, $f20
/* 9C738C 80241FAC 00000000 */  nop       
/* 9C7390 80241FB0 0220202D */  daddu     $a0, $s1, $zero
/* 9C7394 80241FB4 0260282D */  daddu     $a1, $s3, $zero
/* 9C7398 80241FB8 4600E18D */  trunc.w.s $f6, $f28
/* 9C739C 80241FBC 44063000 */  mfc1      $a2, $f6
/* 9C73A0 80241FC0 0C0B2026 */  jal       set_variable
/* 9C73A4 80241FC4 4600C601 */   sub.s    $f24, $f24, $f0
/* 9C73A8 80241FC8 0220202D */  daddu     $a0, $s1, $zero
/* 9C73AC 80241FCC 4600D18D */  trunc.w.s $f6, $f26
/* 9C73B0 80241FD0 44063000 */  mfc1      $a2, $f6
/* 9C73B4 80241FD4 0C0B2026 */  jal       set_variable
/* 9C73B8 80241FD8 0280282D */   daddu    $a1, $s4, $zero
/* 9C73BC 80241FDC 0220202D */  daddu     $a0, $s1, $zero
/* 9C73C0 80241FE0 4600C18D */  trunc.w.s $f6, $f24
/* 9C73C4 80241FE4 44063000 */  mfc1      $a2, $f6
/* 9C73C8 80241FE8 0C0B2026 */  jal       set_variable
/* 9C73CC 80241FEC 0200282D */   daddu    $a1, $s0, $zero
/* 9C73D0 80241FF0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9C73D4 80241FF4 8FB40020 */  lw        $s4, 0x20($sp)
/* 9C73D8 80241FF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9C73DC 80241FFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9C73E0 80242000 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C73E4 80242004 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C73E8 80242008 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 9C73EC 8024200C D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 9C73F0 80242010 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 9C73F4 80242014 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 9C73F8 80242018 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 9C73FC 8024201C 24020002 */  addiu     $v0, $zero, 2
/* 9C7400 80242020 03E00008 */  jr        $ra
/* 9C7404 80242024 27BD0050 */   addiu    $sp, $sp, 0x50
