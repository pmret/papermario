.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414C8_D9E998
/* D9E998 802414C8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D9E99C 802414CC AFB3003C */  sw        $s3, 0x3c($sp)
/* D9E9A0 802414D0 0080982D */  daddu     $s3, $a0, $zero
/* D9E9A4 802414D4 AFBF0044 */  sw        $ra, 0x44($sp)
/* D9E9A8 802414D8 AFB40040 */  sw        $s4, 0x40($sp)
/* D9E9AC 802414DC AFB20038 */  sw        $s2, 0x38($sp)
/* D9E9B0 802414E0 AFB10034 */  sw        $s1, 0x34($sp)
/* D9E9B4 802414E4 AFB00030 */  sw        $s0, 0x30($sp)
/* D9E9B8 802414E8 8E710148 */  lw        $s1, 0x148($s3)
/* D9E9BC 802414EC 00A0902D */  daddu     $s2, $a1, $zero
/* D9E9C0 802414F0 86240008 */  lh        $a0, 8($s1)
/* D9E9C4 802414F4 0C00EABB */  jal       get_npc_unsafe
/* D9E9C8 802414F8 00C0A02D */   daddu    $s4, $a2, $zero
/* D9E9CC 802414FC 8E430008 */  lw        $v1, 8($s2)
/* D9E9D0 80241500 0460003B */  bltz      $v1, .L802415F0
/* D9E9D4 80241504 0040802D */   daddu    $s0, $v0, $zero
/* D9E9D8 80241508 8E620074 */  lw        $v0, 0x74($s3)
/* D9E9DC 8024150C 1C400037 */  bgtz      $v0, .L802415EC
/* D9E9E0 80241510 2442FFFF */   addiu    $v0, $v0, -1
/* D9E9E4 80241514 0280202D */  daddu     $a0, $s4, $zero
/* D9E9E8 80241518 AE630074 */  sw        $v1, 0x74($s3)
/* D9E9EC 8024151C AFA00010 */  sw        $zero, 0x10($sp)
/* D9E9F0 80241520 8E460018 */  lw        $a2, 0x18($s2)
/* D9E9F4 80241524 8E47001C */  lw        $a3, 0x1c($s2)
/* D9E9F8 80241528 0C01242D */  jal       func_800490B4
/* D9E9FC 8024152C 0220282D */   daddu    $a1, $s1, $zero
/* D9EA00 80241530 1040002C */  beqz      $v0, .L802415E4
/* D9EA04 80241534 0000202D */   daddu    $a0, $zero, $zero
/* D9EA08 80241538 0200282D */  daddu     $a1, $s0, $zero
/* D9EA0C 8024153C 0000302D */  daddu     $a2, $zero, $zero
/* D9EA10 80241540 860300A8 */  lh        $v1, 0xa8($s0)
/* D9EA14 80241544 3C013F80 */  lui       $at, 0x3f80
/* D9EA18 80241548 44810000 */  mtc1      $at, $f0
/* D9EA1C 8024154C 3C014000 */  lui       $at, 0x4000
/* D9EA20 80241550 44811000 */  mtc1      $at, $f2
/* D9EA24 80241554 3C01C1A0 */  lui       $at, 0xc1a0
/* D9EA28 80241558 44812000 */  mtc1      $at, $f4
/* D9EA2C 8024155C 2402000F */  addiu     $v0, $zero, 0xf
/* D9EA30 80241560 AFA2001C */  sw        $v0, 0x1c($sp)
/* D9EA34 80241564 44833000 */  mtc1      $v1, $f6
/* D9EA38 80241568 00000000 */  nop       
/* D9EA3C 8024156C 468031A0 */  cvt.s.w   $f6, $f6
/* D9EA40 80241570 44073000 */  mfc1      $a3, $f6
/* D9EA44 80241574 27A20028 */  addiu     $v0, $sp, 0x28
/* D9EA48 80241578 AFA20020 */  sw        $v0, 0x20($sp)
/* D9EA4C 8024157C E7A00010 */  swc1      $f0, 0x10($sp)
/* D9EA50 80241580 E7A20014 */  swc1      $f2, 0x14($sp)
/* D9EA54 80241584 0C01BFA4 */  jal       fx_emote
/* D9EA58 80241588 E7A40018 */   swc1     $f4, 0x18($sp)
/* D9EA5C 8024158C 0200202D */  daddu     $a0, $s0, $zero
/* D9EA60 80241590 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D9EA64 80241594 0C012530 */  jal       func_800494C0
/* D9EA68 80241598 3C060020 */   lui      $a2, 0x20
/* D9EA6C 8024159C C60C0038 */  lwc1      $f12, 0x38($s0)
/* D9EA70 802415A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D9EA74 802415A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D9EA78 802415A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D9EA7C 802415AC 8C460028 */  lw        $a2, 0x28($v0)
/* D9EA80 802415B0 0C00A720 */  jal       atan2
/* D9EA84 802415B4 8C470030 */   lw       $a3, 0x30($v0)
/* D9EA88 802415B8 E600000C */  swc1      $f0, 0xc($s0)
/* D9EA8C 802415BC 8E220018 */  lw        $v0, 0x18($s1)
/* D9EA90 802415C0 9442002A */  lhu       $v0, 0x2a($v0)
/* D9EA94 802415C4 30420001 */  andi      $v0, $v0, 1
/* D9EA98 802415C8 10400003 */  beqz      $v0, .L802415D8
/* D9EA9C 802415CC 2402000A */   addiu    $v0, $zero, 0xa
/* D9EAA0 802415D0 080905AC */  j         .L802416B0
/* D9EAA4 802415D4 AE620070 */   sw       $v0, 0x70($s3)
.L802415D8:
/* D9EAA8 802415D8 2402000C */  addiu     $v0, $zero, 0xc
/* D9EAAC 802415DC 080905AC */  j         .L802416B0
/* D9EAB0 802415E0 AE620070 */   sw       $v0, 0x70($s3)
.L802415E4:
/* D9EAB4 802415E4 8E620074 */  lw        $v0, 0x74($s3)
/* D9EAB8 802415E8 2442FFFF */  addiu     $v0, $v0, -1
.L802415EC:
/* D9EABC 802415EC AE620074 */  sw        $v0, 0x74($s3)
.L802415F0:
/* D9EAC0 802415F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D9EAC4 802415F4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9EAC8 802415F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D9EACC 802415FC C4460000 */  lwc1      $f6, ($v0)
/* D9EAD0 80241600 468031A0 */  cvt.s.w   $f6, $f6
/* D9EAD4 80241604 44063000 */  mfc1      $a2, $f6
/* D9EAD8 80241608 C4460008 */  lwc1      $f6, 8($v0)
/* D9EADC 8024160C 468031A0 */  cvt.s.w   $f6, $f6
/* D9EAE0 80241610 44073000 */  mfc1      $a3, $f6
/* D9EAE4 80241614 0C00A7B5 */  jal       dist2D
/* D9EAE8 80241618 00000000 */   nop      
/* D9EAEC 8024161C C6020018 */  lwc1      $f2, 0x18($s0)
/* D9EAF0 80241620 4602003C */  c.lt.s    $f0, $f2
/* D9EAF4 80241624 00000000 */  nop       
/* D9EAF8 80241628 4500000E */  bc1f      .L80241664
/* D9EAFC 8024162C 00000000 */   nop      
/* D9EB00 80241630 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9EB04 80241634 C4400000 */  lwc1      $f0, ($v0)
/* D9EB08 80241638 46800020 */  cvt.s.w   $f0, $f0
/* D9EB0C 8024163C E6000038 */  swc1      $f0, 0x38($s0)
/* D9EB10 80241640 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9EB14 80241644 C4400008 */  lwc1      $f0, 8($v0)
/* D9EB18 80241648 46800020 */  cvt.s.w   $f0, $f0
/* D9EB1C 8024164C E6000040 */  swc1      $f0, 0x40($s0)
/* D9EB20 80241650 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9EB24 80241654 C440000C */  lwc1      $f0, 0xc($v0)
/* D9EB28 80241658 46800020 */  cvt.s.w   $f0, $f0
/* D9EB2C 8024165C E600000C */  swc1      $f0, 0xc($s0)
/* D9EB30 80241660 AE600070 */  sw        $zero, 0x70($s3)
.L80241664:
/* D9EB34 80241664 8602008C */  lh        $v0, 0x8c($s0)
/* D9EB38 80241668 14400011 */  bnez      $v0, .L802416B0
/* D9EB3C 8024166C 00000000 */   nop      
/* D9EB40 80241670 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D9EB44 80241674 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D9EB48 80241678 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D9EB4C 8024167C C4460000 */  lwc1      $f6, ($v0)
/* D9EB50 80241680 468031A0 */  cvt.s.w   $f6, $f6
/* D9EB54 80241684 44063000 */  mfc1      $a2, $f6
/* D9EB58 80241688 C4460008 */  lwc1      $f6, 8($v0)
/* D9EB5C 8024168C 468031A0 */  cvt.s.w   $f6, $f6
/* D9EB60 80241690 44073000 */  mfc1      $a3, $f6
/* D9EB64 80241694 0C00A720 */  jal       atan2
/* D9EB68 80241698 00000000 */   nop      
/* D9EB6C 8024169C 8E050018 */  lw        $a1, 0x18($s0)
/* D9EB70 802416A0 44060000 */  mfc1      $a2, $f0
/* D9EB74 802416A4 0200202D */  daddu     $a0, $s0, $zero
/* D9EB78 802416A8 0C00EA95 */  jal       npc_move_heading
/* D9EB7C 802416AC AC86000C */   sw       $a2, 0xc($a0)
.L802416B0:
/* D9EB80 802416B0 8FBF0044 */  lw        $ra, 0x44($sp)
/* D9EB84 802416B4 8FB40040 */  lw        $s4, 0x40($sp)
/* D9EB88 802416B8 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9EB8C 802416BC 8FB20038 */  lw        $s2, 0x38($sp)
/* D9EB90 802416C0 8FB10034 */  lw        $s1, 0x34($sp)
/* D9EB94 802416C4 8FB00030 */  lw        $s0, 0x30($sp)
/* D9EB98 802416C8 03E00008 */  jr        $ra
/* D9EB9C 802416CC 27BD0048 */   addiu    $sp, $sp, 0x48
