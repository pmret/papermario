.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_317E50
/* 317E50 802BD100 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 317E54 802BD104 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 317E58 802BD108 4480A000 */  mtc1      $zero, $f20
/* 317E5C 802BD10C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 317E60 802BD110 3C0141F0 */  lui       $at, 0x41f0
/* 317E64 802BD114 4481D000 */  mtc1      $at, $f26
/* 317E68 802BD118 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 317E6C 802BD11C 3C014234 */  lui       $at, 0x4234
/* 317E70 802BD120 4481C000 */  mtc1      $at, $f24
/* 317E74 802BD124 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 317E78 802BD128 3C0143B4 */  lui       $at, 0x43b4
/* 317E7C 802BD12C 4481B000 */  mtc1      $at, $f22
/* 317E80 802BD130 AFB00030 */  sw        $s0, 0x30($sp)
/* 317E84 802BD134 0080802D */  daddu     $s0, $a0, $zero
/* 317E88 802BD138 AFBF0034 */  sw        $ra, 0x34($sp)
.L802BD13C:
/* 317E8C 802BD13C C6020038 */  lwc1      $f2, 0x38($s0)
/* 317E90 802BD140 C604003C */  lwc1      $f4, 0x3c($s0)
/* 317E94 802BD144 C60C000C */  lwc1      $f12, 0xc($s0)
/* 317E98 802BD148 C6000040 */  lwc1      $f0, 0x40($s0)
/* 317E9C 802BD14C 46146300 */  add.s     $f12, $f12, $f20
/* 317EA0 802BD150 E7A20020 */  swc1      $f2, 0x20($sp)
/* 317EA4 802BD154 E7A40024 */  swc1      $f4, 0x24($sp)
/* 317EA8 802BD158 0C00A6C9 */  jal       clamp_angle
/* 317EAC 802BD15C E7A00028 */   swc1     $f0, 0x28($sp)
/* 317EB0 802BD160 3C040010 */  lui       $a0, 0x10
/* 317EB4 802BD164 27A50020 */  addiu     $a1, $sp, 0x20
/* 317EB8 802BD168 E7BA0010 */  swc1      $f26, 0x10($sp)
/* 317EBC 802BD16C E7A00014 */  swc1      $f0, 0x14($sp)
/* 317EC0 802BD170 860200A8 */  lh        $v0, 0xa8($s0)
/* 317EC4 802BD174 27A60024 */  addiu     $a2, $sp, 0x24
/* 317EC8 802BD178 44820000 */  mtc1      $v0, $f0
/* 317ECC 802BD17C 00000000 */  nop
/* 317ED0 802BD180 46800020 */  cvt.s.w   $f0, $f0
/* 317ED4 802BD184 E7A00018 */  swc1      $f0, 0x18($sp)
/* 317ED8 802BD188 860200A6 */  lh        $v0, 0xa6($s0)
/* 317EDC 802BD18C 27A70028 */  addiu     $a3, $sp, 0x28
/* 317EE0 802BD190 44820000 */  mtc1      $v0, $f0
/* 317EE4 802BD194 00000000 */  nop
/* 317EE8 802BD198 46800020 */  cvt.s.w   $f0, $f0
/* 317EEC 802BD19C 0C0376B9 */  jal       func_800DDAE4
/* 317EF0 802BD1A0 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 317EF4 802BD1A4 14400006 */  bnez      $v0, .L802BD1C0
/* 317EF8 802BD1A8 00000000 */   nop
/* 317EFC 802BD1AC 4618A500 */  add.s     $f20, $f20, $f24
/* 317F00 802BD1B0 4616A03C */  c.lt.s    $f20, $f22
/* 317F04 802BD1B4 00000000 */  nop
/* 317F08 802BD1B8 4501FFE0 */  bc1t      .L802BD13C
/* 317F0C 802BD1BC 00000000 */   nop
.L802BD1C0:
/* 317F10 802BD1C0 3C0143B4 */  lui       $at, 0x43b4
/* 317F14 802BD1C4 44810000 */  mtc1      $at, $f0
/* 317F18 802BD1C8 00000000 */  nop
/* 317F1C 802BD1CC 4614003E */  c.le.s    $f0, $f20
/* 317F20 802BD1D0 00000000 */  nop
/* 317F24 802BD1D4 4500002F */  bc1f      .L802BD294
/* 317F28 802BD1D8 00000000 */   nop
/* 317F2C 802BD1DC 46000686 */  mov.s     $f26, $f0
/* 317F30 802BD1E0 4480A000 */  mtc1      $zero, $f20
/* 317F34 802BD1E4 3C0141F0 */  lui       $at, 0x41f0
/* 317F38 802BD1E8 4481C000 */  mtc1      $at, $f24
/* 317F3C 802BD1EC 3C014234 */  lui       $at, 0x4234
/* 317F40 802BD1F0 4481B000 */  mtc1      $at, $f22
.L802BD1F4:
/* 317F44 802BD1F4 C6020038 */  lwc1      $f2, 0x38($s0)
/* 317F48 802BD1F8 C604003C */  lwc1      $f4, 0x3c($s0)
/* 317F4C 802BD1FC C60C000C */  lwc1      $f12, 0xc($s0)
/* 317F50 802BD200 C6000040 */  lwc1      $f0, 0x40($s0)
/* 317F54 802BD204 46146300 */  add.s     $f12, $f12, $f20
/* 317F58 802BD208 E7A20020 */  swc1      $f2, 0x20($sp)
/* 317F5C 802BD20C E7A40024 */  swc1      $f4, 0x24($sp)
/* 317F60 802BD210 0C00A6C9 */  jal       clamp_angle
/* 317F64 802BD214 E7A00028 */   swc1     $f0, 0x28($sp)
/* 317F68 802BD218 3C040004 */  lui       $a0, 4
/* 317F6C 802BD21C 27A50020 */  addiu     $a1, $sp, 0x20
/* 317F70 802BD220 E7B80010 */  swc1      $f24, 0x10($sp)
/* 317F74 802BD224 E7A00014 */  swc1      $f0, 0x14($sp)
/* 317F78 802BD228 860200A8 */  lh        $v0, 0xa8($s0)
/* 317F7C 802BD22C 27A60024 */  addiu     $a2, $sp, 0x24
/* 317F80 802BD230 44820000 */  mtc1      $v0, $f0
/* 317F84 802BD234 00000000 */  nop
/* 317F88 802BD238 46800020 */  cvt.s.w   $f0, $f0
/* 317F8C 802BD23C E7A00018 */  swc1      $f0, 0x18($sp)
/* 317F90 802BD240 860200A6 */  lh        $v0, 0xa6($s0)
/* 317F94 802BD244 27A70028 */  addiu     $a3, $sp, 0x28
/* 317F98 802BD248 44820000 */  mtc1      $v0, $f0
/* 317F9C 802BD24C 00000000 */  nop
/* 317FA0 802BD250 46800020 */  cvt.s.w   $f0, $f0
/* 317FA4 802BD254 0C0376B9 */  jal       func_800DDAE4
/* 317FA8 802BD258 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 317FAC 802BD25C 14400006 */  bnez      $v0, .L802BD278
/* 317FB0 802BD260 00000000 */   nop
/* 317FB4 802BD264 4616A500 */  add.s     $f20, $f20, $f22
/* 317FB8 802BD268 461AA03C */  c.lt.s    $f20, $f26
/* 317FBC 802BD26C 00000000 */  nop
/* 317FC0 802BD270 4501FFE0 */  bc1t      .L802BD1F4
/* 317FC4 802BD274 00000000 */   nop
.L802BD278:
/* 317FC8 802BD278 3C0143B4 */  lui       $at, 0x43b4
/* 317FCC 802BD27C 44810000 */  mtc1      $at, $f0
/* 317FD0 802BD280 00000000 */  nop
/* 317FD4 802BD284 4614003E */  c.le.s    $f0, $f20
/* 317FD8 802BD288 00000000 */  nop
/* 317FDC 802BD28C 4501000A */  bc1t      .L802BD2B8
/* 317FE0 802BD290 00000000 */   nop
.L802BD294:
/* 317FE4 802BD294 3C038011 */  lui       $v1, %hi(D_8010C978)
/* 317FE8 802BD298 8C63C978 */  lw        $v1, %lo(D_8010C978)($v1)
/* 317FEC 802BD29C 04600006 */  bltz      $v1, .L802BD2B8
/* 317FF0 802BD2A0 30624000 */   andi     $v0, $v1, 0x4000
/* 317FF4 802BD2A4 10400004 */  beqz      $v0, .L802BD2B8
/* 317FF8 802BD2A8 00000000 */   nop
/* 317FFC 802BD2AC 2404BFFF */  addiu     $a0, $zero, -0x4001
/* 318000 802BD2B0 0C044277 */  jal       func_801109DC
/* 318004 802BD2B4 00642024 */   and      $a0, $v1, $a0
.L802BD2B8:
/* 318008 802BD2B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 31800C 802BD2BC 8FB00030 */  lw        $s0, 0x30($sp)
/* 318010 802BD2C0 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 318014 802BD2C4 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 318018 802BD2C8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 31801C 802BD2CC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 318020 802BD2D0 03E00008 */  jr        $ra
/* 318024 802BD2D4 27BD0058 */   addiu    $sp, $sp, 0x58
