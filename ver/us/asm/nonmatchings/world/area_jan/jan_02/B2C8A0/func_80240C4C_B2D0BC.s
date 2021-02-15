.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_B2D0BC
/* B2D0BC 80240C4C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B2D0C0 80240C50 AFB3001C */  sw        $s3, 0x1c($sp)
/* B2D0C4 80240C54 0080982D */  daddu     $s3, $a0, $zero
/* B2D0C8 80240C58 AFBF0020 */  sw        $ra, 0x20($sp)
/* B2D0CC 80240C5C AFB20018 */  sw        $s2, 0x18($sp)
/* B2D0D0 80240C60 AFB10014 */  sw        $s1, 0x14($sp)
/* B2D0D4 80240C64 AFB00010 */  sw        $s0, 0x10($sp)
/* B2D0D8 80240C68 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B2D0DC 80240C6C 8E710148 */  lw        $s1, 0x148($s3)
/* B2D0E0 80240C70 86240008 */  lh        $a0, 8($s1)
/* B2D0E4 80240C74 0C00EABB */  jal       get_npc_unsafe
/* B2D0E8 80240C78 00A0802D */   daddu    $s0, $a1, $zero
/* B2D0EC 80240C7C 8E040020 */  lw        $a0, 0x20($s0)
/* B2D0F0 80240C80 0040902D */  daddu     $s2, $v0, $zero
/* B2D0F4 80240C84 00041FC2 */  srl       $v1, $a0, 0x1f
/* B2D0F8 80240C88 00832021 */  addu      $a0, $a0, $v1
/* B2D0FC 80240C8C 00042043 */  sra       $a0, $a0, 1
/* B2D100 80240C90 0C00A67F */  jal       rand_int
/* B2D104 80240C94 24840001 */   addiu    $a0, $a0, 1
/* B2D108 80240C98 8E030020 */  lw        $v1, 0x20($s0)
/* B2D10C 80240C9C C64C0038 */  lwc1      $f12, 0x38($s2)
/* B2D110 80240CA0 000327C2 */  srl       $a0, $v1, 0x1f
/* B2D114 80240CA4 00641821 */  addu      $v1, $v1, $a0
/* B2D118 80240CA8 00031843 */  sra       $v1, $v1, 1
/* B2D11C 80240CAC 00621821 */  addu      $v1, $v1, $v0
/* B2D120 80240CB0 A643008E */  sh        $v1, 0x8e($s2)
/* B2D124 80240CB4 8E2200CC */  lw        $v0, 0xcc($s1)
/* B2D128 80240CB8 C64E0040 */  lwc1      $f14, 0x40($s2)
/* B2D12C 80240CBC 8C42000C */  lw        $v0, 0xc($v0)
/* B2D130 80240CC0 AE420028 */  sw        $v0, 0x28($s2)
/* B2D134 80240CC4 C6000018 */  lwc1      $f0, 0x18($s0)
/* B2D138 80240CC8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B2D13C 80240CCC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B2D140 80240CD0 E6400018 */  swc1      $f0, 0x18($s2)
/* B2D144 80240CD4 8C460028 */  lw        $a2, 0x28($v0)
/* B2D148 80240CD8 0C00A720 */  jal       atan2
/* B2D14C 80240CDC 8C470030 */   lw       $a3, 0x30($v0)
/* B2D150 80240CE0 46000506 */  mov.s     $f20, $f0
/* B2D154 80240CE4 C64C000C */  lwc1      $f12, 0xc($s2)
/* B2D158 80240CE8 0C00A70A */  jal       get_clamped_angle_diff
/* B2D15C 80240CEC 4600A386 */   mov.s    $f14, $f20
/* B2D160 80240CF0 46000086 */  mov.s     $f2, $f0
/* B2D164 80240CF4 8E02001C */  lw        $v0, 0x1c($s0)
/* B2D168 80240CF8 46001005 */  abs.s     $f0, $f2
/* B2D16C 80240CFC 44822000 */  mtc1      $v0, $f4
/* B2D170 80240D00 00000000 */  nop
/* B2D174 80240D04 46802120 */  cvt.s.w   $f4, $f4
/* B2D178 80240D08 4600203C */  c.lt.s    $f4, $f0
/* B2D17C 80240D0C 00000000 */  nop
/* B2D180 80240D10 4500000D */  bc1f      .L80240D48
/* B2D184 80240D14 00000000 */   nop
/* B2D188 80240D18 44800000 */  mtc1      $zero, $f0
/* B2D18C 80240D1C C654000C */  lwc1      $f20, 0xc($s2)
/* B2D190 80240D20 4600103C */  c.lt.s    $f2, $f0
/* B2D194 80240D24 00000000 */  nop
/* B2D198 80240D28 45000006 */  bc1f      .L80240D44
/* B2D19C 80240D2C 00021023 */   negu     $v0, $v0
/* B2D1A0 80240D30 44820000 */  mtc1      $v0, $f0
/* B2D1A4 80240D34 00000000 */  nop
/* B2D1A8 80240D38 46800020 */  cvt.s.w   $f0, $f0
/* B2D1AC 80240D3C 08090352 */  j         .L80240D48
/* B2D1B0 80240D40 4600A500 */   add.s    $f20, $f20, $f0
.L80240D44:
/* B2D1B4 80240D44 4604A500 */  add.s     $f20, $f20, $f4
.L80240D48:
/* B2D1B8 80240D48 0C00A6C9 */  jal       clamp_angle
/* B2D1BC 80240D4C 4600A306 */   mov.s    $f12, $f20
/* B2D1C0 80240D50 2402000D */  addiu     $v0, $zero, 0xd
/* B2D1C4 80240D54 E640000C */  swc1      $f0, 0xc($s2)
/* B2D1C8 80240D58 AE620070 */  sw        $v0, 0x70($s3)
/* B2D1CC 80240D5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B2D1D0 80240D60 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2D1D4 80240D64 8FB20018 */  lw        $s2, 0x18($sp)
/* B2D1D8 80240D68 8FB10014 */  lw        $s1, 0x14($sp)
/* B2D1DC 80240D6C 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D1E0 80240D70 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B2D1E4 80240D74 03E00008 */  jr        $ra
/* B2D1E8 80240D78 27BD0030 */   addiu    $sp, $sp, 0x30
