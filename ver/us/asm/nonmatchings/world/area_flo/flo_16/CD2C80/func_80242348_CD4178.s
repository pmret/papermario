.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242348_CD4178
/* CD4178 80242348 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CD417C 8024234C AFB3001C */  sw        $s3, 0x1c($sp)
/* CD4180 80242350 0080982D */  daddu     $s3, $a0, $zero
/* CD4184 80242354 AFBF0020 */  sw        $ra, 0x20($sp)
/* CD4188 80242358 AFB20018 */  sw        $s2, 0x18($sp)
/* CD418C 8024235C AFB10014 */  sw        $s1, 0x14($sp)
/* CD4190 80242360 AFB00010 */  sw        $s0, 0x10($sp)
/* CD4194 80242364 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CD4198 80242368 8E710148 */  lw        $s1, 0x148($s3)
/* CD419C 8024236C 86240008 */  lh        $a0, 8($s1)
/* CD41A0 80242370 0C00EABB */  jal       get_npc_unsafe
/* CD41A4 80242374 00A0802D */   daddu    $s0, $a1, $zero
/* CD41A8 80242378 8E040020 */  lw        $a0, 0x20($s0)
/* CD41AC 8024237C 0040902D */  daddu     $s2, $v0, $zero
/* CD41B0 80242380 00041FC2 */  srl       $v1, $a0, 0x1f
/* CD41B4 80242384 00832021 */  addu      $a0, $a0, $v1
/* CD41B8 80242388 00042043 */  sra       $a0, $a0, 1
/* CD41BC 8024238C 0C00A67F */  jal       rand_int
/* CD41C0 80242390 24840001 */   addiu    $a0, $a0, 1
/* CD41C4 80242394 8E030020 */  lw        $v1, 0x20($s0)
/* CD41C8 80242398 C64C0038 */  lwc1      $f12, 0x38($s2)
/* CD41CC 8024239C 000327C2 */  srl       $a0, $v1, 0x1f
/* CD41D0 802423A0 00641821 */  addu      $v1, $v1, $a0
/* CD41D4 802423A4 00031843 */  sra       $v1, $v1, 1
/* CD41D8 802423A8 00621821 */  addu      $v1, $v1, $v0
/* CD41DC 802423AC A643008E */  sh        $v1, 0x8e($s2)
/* CD41E0 802423B0 8E2200CC */  lw        $v0, 0xcc($s1)
/* CD41E4 802423B4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* CD41E8 802423B8 8C42000C */  lw        $v0, 0xc($v0)
/* CD41EC 802423BC AE420028 */  sw        $v0, 0x28($s2)
/* CD41F0 802423C0 C6000018 */  lwc1      $f0, 0x18($s0)
/* CD41F4 802423C4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD41F8 802423C8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD41FC 802423CC E6400018 */  swc1      $f0, 0x18($s2)
/* CD4200 802423D0 8C460028 */  lw        $a2, 0x28($v0)
/* CD4204 802423D4 0C00A720 */  jal       atan2
/* CD4208 802423D8 8C470030 */   lw       $a3, 0x30($v0)
/* CD420C 802423DC 46000506 */  mov.s     $f20, $f0
/* CD4210 802423E0 C64C000C */  lwc1      $f12, 0xc($s2)
/* CD4214 802423E4 0C00A70A */  jal       get_clamped_angle_diff
/* CD4218 802423E8 4600A386 */   mov.s    $f14, $f20
/* CD421C 802423EC 46000086 */  mov.s     $f2, $f0
/* CD4220 802423F0 8E02001C */  lw        $v0, 0x1c($s0)
/* CD4224 802423F4 46001005 */  abs.s     $f0, $f2
/* CD4228 802423F8 44822000 */  mtc1      $v0, $f4
/* CD422C 802423FC 00000000 */  nop
/* CD4230 80242400 46802120 */  cvt.s.w   $f4, $f4
/* CD4234 80242404 4600203C */  c.lt.s    $f4, $f0
/* CD4238 80242408 00000000 */  nop
/* CD423C 8024240C 4500000D */  bc1f      .L80242444
/* CD4240 80242410 00000000 */   nop
/* CD4244 80242414 44800000 */  mtc1      $zero, $f0
/* CD4248 80242418 C654000C */  lwc1      $f20, 0xc($s2)
/* CD424C 8024241C 4600103C */  c.lt.s    $f2, $f0
/* CD4250 80242420 00000000 */  nop
/* CD4254 80242424 45000006 */  bc1f      .L80242440
/* CD4258 80242428 00021023 */   negu     $v0, $v0
/* CD425C 8024242C 44820000 */  mtc1      $v0, $f0
/* CD4260 80242430 00000000 */  nop
/* CD4264 80242434 46800020 */  cvt.s.w   $f0, $f0
/* CD4268 80242438 08090911 */  j         .L80242444
/* CD426C 8024243C 4600A500 */   add.s    $f20, $f20, $f0
.L80242440:
/* CD4270 80242440 4604A500 */  add.s     $f20, $f20, $f4
.L80242444:
/* CD4274 80242444 0C00A6C9 */  jal       clamp_angle
/* CD4278 80242448 4600A306 */   mov.s    $f12, $f20
/* CD427C 8024244C 2402000D */  addiu     $v0, $zero, 0xd
/* CD4280 80242450 E640000C */  swc1      $f0, 0xc($s2)
/* CD4284 80242454 AE620070 */  sw        $v0, 0x70($s3)
/* CD4288 80242458 8FBF0020 */  lw        $ra, 0x20($sp)
/* CD428C 8024245C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CD4290 80242460 8FB20018 */  lw        $s2, 0x18($sp)
/* CD4294 80242464 8FB10014 */  lw        $s1, 0x14($sp)
/* CD4298 80242468 8FB00010 */  lw        $s0, 0x10($sp)
/* CD429C 8024246C D7B40028 */  ldc1      $f20, 0x28($sp)
/* CD42A0 80242470 03E00008 */  jr        $ra
/* CD42A4 80242474 27BD0030 */   addiu    $sp, $sp, 0x30
