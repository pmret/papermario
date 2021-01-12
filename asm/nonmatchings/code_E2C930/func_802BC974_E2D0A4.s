.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC974_E2D0A4
/* E2D0A4 802BC974 27BDFE80 */  addiu     $sp, $sp, -0x180
/* E2D0A8 802BC978 AFBE0148 */  sw        $fp, 0x148($sp)
/* E2D0AC 802BC97C 0000F02D */  daddu     $fp, $zero, $zero
/* E2D0B0 802BC980 27A80098 */  addiu     $t0, $sp, 0x98
/* E2D0B4 802BC984 AFB5013C */  sw        $s5, 0x13c($sp)
/* E2D0B8 802BC988 27B500D8 */  addiu     $s5, $sp, 0xd8
/* E2D0BC 802BC98C AFB40138 */  sw        $s4, 0x138($sp)
/* E2D0C0 802BC990 27B40058 */  addiu     $s4, $sp, 0x58
/* E2D0C4 802BC994 AFA8011C */  sw        $t0, 0x11c($sp)
/* E2D0C8 802BC998 3C080001 */  lui       $t0, 1
/* E2D0CC 802BC99C AFB1012C */  sw        $s1, 0x12c($sp)
/* E2D0D0 802BC9A0 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* E2D0D4 802BC9A4 8E31A66C */  lw        $s1, %lo(gMasterGfxPos)($s1)
/* E2D0D8 802BC9A8 35081630 */  ori       $t0, $t0, 0x1630
/* E2D0DC 802BC9AC AFBF014C */  sw        $ra, 0x14c($sp)
/* E2D0E0 802BC9B0 AFB70144 */  sw        $s7, 0x144($sp)
/* E2D0E4 802BC9B4 AFB60140 */  sw        $s6, 0x140($sp)
/* E2D0E8 802BC9B8 AFB30134 */  sw        $s3, 0x134($sp)
/* E2D0EC 802BC9BC AFB20130 */  sw        $s2, 0x130($sp)
/* E2D0F0 802BC9C0 AFB00128 */  sw        $s0, 0x128($sp)
/* E2D0F4 802BC9C4 F7BE0178 */  sdc1      $f30, 0x178($sp)
/* E2D0F8 802BC9C8 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* E2D0FC 802BC9CC F7BA0168 */  sdc1      $f26, 0x168($sp)
/* E2D100 802BC9D0 F7B80160 */  sdc1      $f24, 0x160($sp)
/* E2D104 802BC9D4 F7B60158 */  sdc1      $f22, 0x158($sp)
/* E2D108 802BC9D8 F7B40150 */  sdc1      $f20, 0x150($sp)
/* E2D10C 802BC9DC 0C04417A */  jal       get_entity_by_index
/* E2D110 802BC9E0 AFA80120 */   sw       $t0, 0x120($sp)
/* E2D114 802BC9E4 0040B82D */  daddu     $s7, $v0, $zero
/* E2D118 802BC9E8 3C0143B4 */  lui       $at, 0x43b4
/* E2D11C 802BC9EC 4481D000 */  mtc1      $at, $f26
/* E2D120 802BC9F0 3C013B80 */  lui       $at, 0x3b80
/* E2D124 802BC9F4 4481C000 */  mtc1      $at, $f24
/* E2D128 802BC9F8 3C013F80 */  lui       $at, 0x3f80
/* E2D12C 802BC9FC 4481B000 */  mtc1      $at, $f22
/* E2D130 802BCA00 8EE20040 */  lw        $v0, 0x40($s7)
/* E2D134 802BCA04 4480A000 */  mtc1      $zero, $f20
/* E2D138 802BCA08 C6E00048 */  lwc1      $f0, 0x48($s7)
/* E2D13C 802BCA0C 0040902D */  daddu     $s2, $v0, $zero
/* E2D140 802BCA10 0240982D */  daddu     $s3, $s2, $zero
/* E2D144 802BCA14 2630FFFC */  addiu     $s0, $s1, -4
/* E2D148 802BCA18 46000007 */  neg.s     $f0, $f0
/* E2D14C 802BCA1C E7A00118 */  swc1      $f0, 0x118($sp)
/* E2D150 802BCA20 C6E0004C */  lwc1      $f0, 0x4c($s7)
/* E2D154 802BCA24 C6E20050 */  lwc1      $f2, 0x50($s7)
/* E2D158 802BCA28 8E560000 */  lw        $s6, ($s2)
/* E2D15C 802BCA2C 46000787 */  neg.s     $f30, $f0
/* E2D160 802BCA30 46001707 */  neg.s     $f28, $f2
.L802BCA34:
/* E2D164 802BCA34 82420008 */  lb        $v0, 8($s2)
/* E2D168 802BCA38 28420002 */  slti      $v0, $v0, 2
/* E2D16C 802BCA3C 1040000F */  beqz      $v0, .L802BCA7C
/* E2D170 802BCA40 3C03E200 */   lui      $v1, 0xe200
/* E2D174 802BCA44 26100008 */  addiu     $s0, $s0, 8
/* E2D178 802BCA48 3463001C */  ori       $v1, $v1, 0x1c
/* E2D17C 802BCA4C 3C020055 */  lui       $v0, 0x55
/* E2D180 802BCA50 34422078 */  ori       $v0, $v0, 0x2078
/* E2D184 802BCA54 AE03FFFC */  sw        $v1, -4($s0)
/* E2D188 802BCA58 AE020000 */  sw        $v0, ($s0)
/* E2D18C 802BCA5C 26100008 */  addiu     $s0, $s0, 8
/* E2D190 802BCA60 26310010 */  addiu     $s1, $s1, 0x10
/* E2D194 802BCA64 3C03FC12 */  lui       $v1, 0xfc12
/* E2D198 802BCA68 34631824 */  ori       $v1, $v1, 0x1824
/* E2D19C 802BCA6C 3C02FF33 */  lui       $v0, 0xff33
/* E2D1A0 802BCA70 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2D1A4 802BCA74 080AF2AB */  j         .L802BCAAC
/* E2D1A8 802BCA78 AE03FFFC */   sw       $v1, -4($s0)
.L802BCA7C:
/* E2D1AC 802BCA7C 26100008 */  addiu     $s0, $s0, 8
/* E2D1B0 802BCA80 3C03FCFF */  lui       $v1, 0xfcff
/* E2D1B4 802BCA84 3463C3FF */  ori       $v1, $v1, 0xc3ff
/* E2D1B8 802BCA88 3C02FF30 */  lui       $v0, 0xff30
/* E2D1BC 802BCA8C 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* E2D1C0 802BCA90 AE03FFFC */  sw        $v1, -4($s0)
/* E2D1C4 802BCA94 AE020000 */  sw        $v0, ($s0)
/* E2D1C8 802BCA98 26100008 */  addiu     $s0, $s0, 8
/* E2D1CC 802BCA9C 3C02FA00 */  lui       $v0, 0xfa00
/* E2D1D0 802BCAA0 AE02FFFC */  sw        $v0, -4($s0)
/* E2D1D4 802BCAA4 9242000E */  lbu       $v0, 0xe($s2)
/* E2D1D8 802BCAA8 26310010 */  addiu     $s1, $s1, 0x10
.L802BCAAC:
/* E2D1DC 802BCAAC AE020000 */  sw        $v0, ($s0)
/* E2D1E0 802BCAB0 8FA50118 */  lw        $a1, 0x118($sp)
/* E2D1E4 802BCAB4 4406F000 */  mfc1      $a2, $f30
/* E2D1E8 802BCAB8 4407E000 */  mfc1      $a3, $f28
/* E2D1EC 802BCABC 0C019E40 */  jal       guTranslateF
/* E2D1F0 802BCAC0 27A40018 */   addiu    $a0, $sp, 0x18
/* E2D1F4 802BCAC4 92420014 */  lbu       $v0, 0x14($s2)
/* E2D1F8 802BCAC8 44820000 */  mtc1      $v0, $f0
/* E2D1FC 802BCACC 00000000 */  nop       
/* E2D200 802BCAD0 46800020 */  cvt.s.w   $f0, $f0
/* E2D204 802BCAD4 461A0002 */  mul.s     $f0, $f0, $f26
/* E2D208 802BCAD8 00000000 */  nop       
/* E2D20C 802BCADC 46180002 */  mul.s     $f0, $f0, $f24
/* E2D210 802BCAE0 00000000 */  nop       
/* E2D214 802BCAE4 4406B000 */  mfc1      $a2, $f22
/* E2D218 802BCAE8 4407A000 */  mfc1      $a3, $f20
/* E2D21C 802BCAEC 8FA4011C */  lw        $a0, 0x11c($sp)
/* E2D220 802BCAF0 44050000 */  mfc1      $a1, $f0
/* E2D224 802BCAF4 0C019EC8 */  jal       guRotateF
/* E2D228 802BCAF8 E7B40010 */   swc1     $f20, 0x10($sp)
/* E2D22C 802BCAFC 9242001A */  lbu       $v0, 0x1a($s2)
/* E2D230 802BCB00 44820000 */  mtc1      $v0, $f0
/* E2D234 802BCB04 00000000 */  nop       
/* E2D238 802BCB08 46800020 */  cvt.s.w   $f0, $f0
/* E2D23C 802BCB0C 461A0002 */  mul.s     $f0, $f0, $f26
/* E2D240 802BCB10 00000000 */  nop       
/* E2D244 802BCB14 26100008 */  addiu     $s0, $s0, 8
/* E2D248 802BCB18 26310018 */  addiu     $s1, $s1, 0x18
/* E2D24C 802BCB1C 46180002 */  mul.s     $f0, $f0, $f24
/* E2D250 802BCB20 00000000 */  nop       
/* E2D254 802BCB24 27DE0001 */  addiu     $fp, $fp, 1
/* E2D258 802BCB28 02A0202D */  daddu     $a0, $s5, $zero
/* E2D25C 802BCB2C 4406A000 */  mfc1      $a2, $f20
/* E2D260 802BCB30 4407B000 */  mfc1      $a3, $f22
/* E2D264 802BCB34 44050000 */  mfc1      $a1, $f0
/* E2D268 802BCB38 26520001 */  addiu     $s2, $s2, 1
/* E2D26C 802BCB3C 0C019EC8 */  jal       guRotateF
/* E2D270 802BCB40 E7B40010 */   swc1     $f20, 0x10($sp)
/* E2D274 802BCB44 02A0282D */  daddu     $a1, $s5, $zero
/* E2D278 802BCB48 8FA4011C */  lw        $a0, 0x11c($sp)
/* E2D27C 802BCB4C 0C019D80 */  jal       guMtxCatF
/* E2D280 802BCB50 02A0302D */   daddu    $a2, $s5, $zero
/* E2D284 802BCB54 02A0202D */  daddu     $a0, $s5, $zero
/* E2D288 802BCB58 27A50018 */  addiu     $a1, $sp, 0x18
/* E2D28C 802BCB5C 0C019D80 */  jal       guMtxCatF
/* E2D290 802BCB60 00A0302D */   daddu    $a2, $a1, $zero
/* E2D294 802BCB64 0280202D */  daddu     $a0, $s4, $zero
/* E2D298 802BCB68 8E650040 */  lw        $a1, 0x40($s3)
/* E2D29C 802BCB6C 8E660058 */  lw        $a2, 0x58($s3)
/* E2D2A0 802BCB70 8E670070 */  lw        $a3, 0x70($s3)
/* E2D2A4 802BCB74 0C019E40 */  jal       guTranslateF
/* E2D2A8 802BCB78 26730004 */   addiu    $s3, $s3, 4
/* E2D2AC 802BCB7C 27A40018 */  addiu     $a0, $sp, 0x18
/* E2D2B0 802BCB80 0280282D */  daddu     $a1, $s4, $zero
/* E2D2B4 802BCB84 0C019D80 */  jal       guMtxCatF
/* E2D2B8 802BCB88 0280302D */   daddu    $a2, $s4, $zero
/* E2D2BC 802BCB8C 0280202D */  daddu     $a0, $s4, $zero
/* E2D2C0 802BCB90 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* E2D2C4 802BCB94 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* E2D2C8 802BCB98 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* E2D2CC 802BCB9C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* E2D2D0 802BCBA0 8FA80120 */  lw        $t0, 0x120($sp)
/* E2D2D4 802BCBA4 00052980 */  sll       $a1, $a1, 6
/* E2D2D8 802BCBA8 00A82821 */  addu      $a1, $a1, $t0
/* E2D2DC 802BCBAC 0C019D40 */  jal       guMtxF2L
/* E2D2E0 802BCBB0 00452821 */   addu     $a1, $v0, $a1
/* E2D2E4 802BCBB4 3C05D838 */  lui       $a1, 0xd838
/* E2D2E8 802BCBB8 34A50002 */  ori       $a1, $a1, 2
/* E2D2EC 802BCBBC 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* E2D2F0 802BCBC0 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* E2D2F4 802BCBC4 3C03DA38 */  lui       $v1, 0xda38
/* E2D2F8 802BCBC8 AE03FFFC */  sw        $v1, -4($s0)
/* E2D2FC 802BCBCC 8FA80120 */  lw        $t0, 0x120($sp)
/* E2D300 802BCBD0 24430001 */  addiu     $v1, $v0, 1
/* E2D304 802BCBD4 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2D308 802BCBD8 00021180 */  sll       $v0, $v0, 6
/* E2D30C 802BCBDC 3C018007 */  lui       $at, %hi(gMatrixListPos)
/* E2D310 802BCBE0 A42341F0 */  sh        $v1, %lo(gMatrixListPos)($at)
/* E2D314 802BCBE4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2D318 802BCBE8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2D31C 802BCBEC 00481021 */  addu      $v0, $v0, $t0
/* E2D320 802BCBF0 00621821 */  addu      $v1, $v1, $v0
/* E2D324 802BCBF4 AE030000 */  sw        $v1, ($s0)
/* E2D328 802BCBF8 96C40002 */  lhu       $a0, 2($s6)
/* E2D32C 802BCBFC 26D60004 */  addiu     $s6, $s6, 4
/* E2D330 802BCC00 26100008 */  addiu     $s0, $s0, 8
/* E2D334 802BCC04 8EE30044 */  lw        $v1, 0x44($s7)
/* E2D338 802BCC08 3C02DE00 */  lui       $v0, 0xde00
/* E2D33C 802BCC0C AE02FFFC */  sw        $v0, -4($s0)
/* E2D340 802BCC10 24020040 */  addiu     $v0, $zero, 0x40
/* E2D344 802BCC14 00641821 */  addu      $v1, $v1, $a0
/* E2D348 802BCC18 AE030000 */  sw        $v1, ($s0)
/* E2D34C 802BCC1C 26100008 */  addiu     $s0, $s0, 8
/* E2D350 802BCC20 AE020000 */  sw        $v0, ($s0)
/* E2D354 802BCC24 2BC20005 */  slti      $v0, $fp, 5
/* E2D358 802BCC28 1440FF82 */  bnez      $v0, .L802BCA34
/* E2D35C 802BCC2C AE05FFFC */   sw       $a1, -4($s0)
/* E2D360 802BCC30 8FBF014C */  lw        $ra, 0x14c($sp)
/* E2D364 802BCC34 8FBE0148 */  lw        $fp, 0x148($sp)
/* E2D368 802BCC38 8FB70144 */  lw        $s7, 0x144($sp)
/* E2D36C 802BCC3C 8FB60140 */  lw        $s6, 0x140($sp)
/* E2D370 802BCC40 8FB5013C */  lw        $s5, 0x13c($sp)
/* E2D374 802BCC44 8FB40138 */  lw        $s4, 0x138($sp)
/* E2D378 802BCC48 8FB30134 */  lw        $s3, 0x134($sp)
/* E2D37C 802BCC4C 8FB20130 */  lw        $s2, 0x130($sp)
/* E2D380 802BCC50 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* E2D384 802BCC54 AC31A66C */  sw        $s1, %lo(gMasterGfxPos)($at)
/* E2D388 802BCC58 8FB1012C */  lw        $s1, 0x12c($sp)
/* E2D38C 802BCC5C 8FB00128 */  lw        $s0, 0x128($sp)
/* E2D390 802BCC60 D7BE0178 */  ldc1      $f30, 0x178($sp)
/* E2D394 802BCC64 D7BC0170 */  ldc1      $f28, 0x170($sp)
/* E2D398 802BCC68 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* E2D39C 802BCC6C D7B80160 */  ldc1      $f24, 0x160($sp)
/* E2D3A0 802BCC70 D7B60158 */  ldc1      $f22, 0x158($sp)
/* E2D3A4 802BCC74 D7B40150 */  ldc1      $f20, 0x150($sp)
/* E2D3A8 802BCC78 03E00008 */  jr        $ra
/* E2D3AC 802BCC7C 27BD0180 */   addiu    $sp, $sp, 0x180
