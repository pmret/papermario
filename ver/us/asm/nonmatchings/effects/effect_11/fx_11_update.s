.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E0016730
.double 0.1

dlabel D_E0016738
.double 0.94

dlabel D_E0016740
.double 0.14, 0.0

.section .text

glabel fx_11_update
/* 32F058 E0016228 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 32F05C E001622C AFB40020 */  sw        $s4, 0x20($sp)
/* 32F060 E0016230 0080A02D */  daddu     $s4, $a0, $zero
/* 32F064 E0016234 AFB20018 */  sw        $s2, 0x18($sp)
/* 32F068 E0016238 0000902D */  daddu     $s2, $zero, $zero
/* 32F06C E001623C AFB3001C */  sw        $s3, 0x1c($sp)
/* 32F070 E0016240 AFBF0024 */  sw        $ra, 0x24($sp)
/* 32F074 E0016244 AFB10014 */  sw        $s1, 0x14($sp)
/* 32F078 E0016248 AFB00010 */  sw        $s0, 0x10($sp)
/* 32F07C E001624C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 32F080 E0016250 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 32F084 E0016254 8E820008 */  lw        $v0, 8($s4)
/* 32F088 E0016258 8E91000C */  lw        $s1, 0xc($s4)
/* 32F08C E001625C 1840005E */  blez      $v0, .LE00163D8
/* 32F090 E0016260 0240982D */   daddu    $s3, $s2, $zero
/* 32F094 E0016264 26300038 */  addiu     $s0, $s1, 0x38
/* 32F098 E0016268 3C01E001 */  lui       $at, %hi(D_E0016730)
/* 32F09C E001626C D4346730 */  ldc1      $f20, %lo(D_E0016730)($at)
/* 32F0A0 E0016270 4480B000 */  mtc1      $zero, $f22
.LE0016274:
/* 32F0A4 E0016274 8E220000 */  lw        $v0, ($s1)
/* 32F0A8 E0016278 50400052 */  beql      $v0, $zero, .LE00163C4
/* 32F0AC E001627C 26520001 */   addiu    $s2, $s2, 1
/* 32F0B0 E0016280 9602FFCE */  lhu       $v0, -0x32($s0)
/* 32F0B4 E0016284 2442FFFF */  addiu     $v0, $v0, -1
/* 32F0B8 E0016288 A602FFCE */  sh        $v0, -0x32($s0)
/* 32F0BC E001628C 00021400 */  sll       $v0, $v0, 0x10
/* 32F0C0 E0016290 1C400003 */  bgtz      $v0, .LE00162A0
/* 32F0C4 E0016294 00000000 */   nop
/* 32F0C8 E0016298 080058F0 */  j         .LE00163C0
/* 32F0CC E001629C AE200000 */   sw       $zero, ($s1)
.LE00162A0:
/* 32F0D0 E00162A0 C600FFF8 */  lwc1      $f0, -8($s0)
/* 32F0D4 E00162A4 3C014140 */  lui       $at, 0x4140
/* 32F0D8 E00162A8 44816000 */  mtc1      $at, $f12
/* 32F0DC E00162AC 0C08013C */  jal       shim_clamp_angle
/* 32F0E0 E00162B0 460C0300 */   add.s    $f12, $f0, $f12
/* 32F0E4 E00162B4 46000306 */  mov.s     $f12, $f0
/* 32F0E8 E00162B8 0C080140 */  jal       shim_sin_deg
/* 32F0EC E00162BC E60CFFF8 */   swc1     $f12, -8($s0)
/* 32F0F0 E00162C0 46000021 */  cvt.d.s   $f0, $f0
/* 32F0F4 E00162C4 46340002 */  mul.d     $f0, $f0, $f20
/* 32F0F8 E00162C8 00000000 */  nop
/* 32F0FC E00162CC C602FFF0 */  lwc1      $f2, -0x10($s0)
/* 32F100 E00162D0 460010A1 */  cvt.d.s   $f2, $f2
/* 32F104 E00162D4 46201080 */  add.d     $f2, $f2, $f0
/* 32F108 E00162D8 C60CFFF8 */  lwc1      $f12, -8($s0)
/* 32F10C E00162DC 462010A0 */  cvt.s.d   $f2, $f2
/* 32F110 E00162E0 0C080144 */  jal       shim_cos_deg
/* 32F114 E00162E4 E602FFE4 */   swc1     $f2, -0x1c($s0)
/* 32F118 E00162E8 46000021 */  cvt.d.s   $f0, $f0
/* 32F11C E00162EC 46340002 */  mul.d     $f0, $f0, $f20
/* 32F120 E00162F0 00000000 */  nop
/* 32F124 E00162F4 C602FFF4 */  lwc1      $f2, -0xc($s0)
/* 32F128 E00162F8 460010A1 */  cvt.d.s   $f2, $f2
/* 32F12C E00162FC 46201080 */  add.d     $f2, $f2, $f0
/* 32F130 E0016300 24130001 */  addiu     $s3, $zero, 1
/* 32F134 E0016304 9602FFCC */  lhu       $v0, -0x34($s0)
/* 32F138 E0016308 462010A0 */  cvt.s.d   $f2, $f2
/* 32F13C E001630C 1440000B */  bnez      $v0, .LE001633C
/* 32F140 E0016310 E602FFE8 */   swc1     $f2, -0x18($s0)
/* 32F144 E0016314 24030005 */  addiu     $v1, $zero, 5
/* 32F148 E0016318 8602FFCE */  lh        $v0, -0x32($s0)
/* 32F14C E001631C 14430007 */  bne       $v0, $v1, .LE001633C
/* 32F150 E0016320 9604FFCE */   lhu      $a0, -0x32($s0)
/* 32F154 E0016324 3C028011 */  lui       $v0, %hi(gPlayerActionState)
/* 32F158 E0016328 8042F07C */  lb        $v0, %lo(gPlayerActionState)($v0)
/* 32F15C E001632C 14400003 */  bnez      $v0, .LE001633C
/* 32F160 E0016330 00931021 */   addu     $v0, $a0, $s3
/* 32F164 E0016334 080058FA */  j         .LE00163E8
/* 32F168 E0016338 A602FFCE */   sh       $v0, -0x32($s0)
.LE001633C:
/* 32F16C E001633C C604FFF4 */  lwc1      $f4, -0xc($s0)
/* 32F170 E0016340 3C01E001 */  lui       $at, %hi(D_E0016738)
/* 32F174 E0016344 D4206738 */  ldc1      $f0, %lo(D_E0016738)($at)
/* 32F178 E0016348 46002121 */  cvt.d.s   $f4, $f4
/* 32F17C E001634C 46202102 */  mul.d     $f4, $f4, $f0
/* 32F180 E0016350 00000000 */  nop
/* 32F184 E0016354 9202FFD0 */  lbu       $v0, -0x30($s0)
/* 32F188 E0016358 C6080004 */  lwc1      $f8, 4($s0)
/* 32F18C E001635C C6020008 */  lwc1      $f2, 8($s0)
/* 32F190 E0016360 C6060000 */  lwc1      $f6, ($s0)
/* 32F194 E0016364 2442FFF1 */  addiu     $v0, $v0, -0xf
/* 32F198 E0016368 46024200 */  add.s     $f8, $f8, $f2
/* 32F19C E001636C C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 32F1A0 E0016370 3C01E001 */  lui       $at, %hi(D_E0016740)
/* 32F1A4 E0016374 D4226740 */  ldc1      $f2, %lo(D_E0016740)($at)
/* 32F1A8 E0016378 46000021 */  cvt.d.s   $f0, $f0
/* 32F1AC E001637C 46220000 */  add.d     $f0, $f0, $f2
/* 32F1B0 E0016380 A202FFD0 */  sb        $v0, -0x30($s0)
/* 32F1B4 E0016384 C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 32F1B8 E0016388 46083180 */  add.s     $f6, $f6, $f8
/* 32F1BC E001638C E6080004 */  swc1      $f8, 4($s0)
/* 32F1C0 E0016390 46200020 */  cvt.s.d   $f0, $f0
/* 32F1C4 E0016394 E600FFF0 */  swc1      $f0, -0x10($s0)
/* 32F1C8 E0016398 46061080 */  add.s     $f2, $f2, $f6
/* 32F1CC E001639C E6060000 */  swc1      $f6, ($s0)
/* 32F1D0 E00163A0 46003006 */  mov.s     $f0, $f6
/* 32F1D4 E00163A4 4616003C */  c.lt.s    $f0, $f22
/* 32F1D8 E00163A8 E602FFD8 */  swc1      $f2, -0x28($s0)
/* 32F1DC E00163AC 46202120 */  cvt.s.d   $f4, $f4
/* 32F1E0 E00163B0 45000003 */  bc1f      .LE00163C0
/* 32F1E4 E00163B4 E604FFF4 */   swc1     $f4, -0xc($s0)
/* 32F1E8 E00163B8 E6160004 */  swc1      $f22, 4($s0)
/* 32F1EC E00163BC E6160000 */  swc1      $f22, ($s0)
.LE00163C0:
/* 32F1F0 E00163C0 26520001 */  addiu     $s2, $s2, 1
.LE00163C4:
/* 32F1F4 E00163C4 26100050 */  addiu     $s0, $s0, 0x50
/* 32F1F8 E00163C8 8E820008 */  lw        $v0, 8($s4)
/* 32F1FC E00163CC 0242102A */  slt       $v0, $s2, $v0
/* 32F200 E00163D0 1440FFA8 */  bnez      $v0, .LE0016274
/* 32F204 E00163D4 26310050 */   addiu    $s1, $s1, 0x50
.LE00163D8:
/* 32F208 E00163D8 16600003 */  bnez      $s3, .LE00163E8
/* 32F20C E00163DC 00000000 */   nop
/* 32F210 E00163E0 0C080128 */  jal       shim_remove_effect
/* 32F214 E00163E4 0280202D */   daddu    $a0, $s4, $zero
.LE00163E8:
/* 32F218 E00163E8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 32F21C E00163EC 8FB40020 */  lw        $s4, 0x20($sp)
/* 32F220 E00163F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 32F224 E00163F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 32F228 E00163F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 32F22C E00163FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 32F230 E0016400 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 32F234 E0016404 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 32F238 E0016408 03E00008 */  jr        $ra
/* 32F23C E001640C 27BD0038 */   addiu    $sp, $sp, 0x38
