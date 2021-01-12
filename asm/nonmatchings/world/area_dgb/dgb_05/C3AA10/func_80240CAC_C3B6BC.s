.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CAC_C3B6BC
/* C3B6BC 80240CAC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C3B6C0 80240CB0 AFB3002C */  sw        $s3, 0x2c($sp)
/* C3B6C4 80240CB4 0080982D */  daddu     $s3, $a0, $zero
/* C3B6C8 80240CB8 AFBF0030 */  sw        $ra, 0x30($sp)
/* C3B6CC 80240CBC AFB20028 */  sw        $s2, 0x28($sp)
/* C3B6D0 80240CC0 AFB10024 */  sw        $s1, 0x24($sp)
/* C3B6D4 80240CC4 AFB00020 */  sw        $s0, 0x20($sp)
/* C3B6D8 80240CC8 8E720148 */  lw        $s2, 0x148($s3)
/* C3B6DC 80240CCC 00A0882D */  daddu     $s1, $a1, $zero
/* C3B6E0 80240CD0 86440008 */  lh        $a0, 8($s2)
/* C3B6E4 80240CD4 0C00EABB */  jal       get_npc_unsafe
/* C3B6E8 80240CD8 00C0802D */   daddu    $s0, $a2, $zero
/* C3B6EC 80240CDC 0200202D */  daddu     $a0, $s0, $zero
/* C3B6F0 80240CE0 0240282D */  daddu     $a1, $s2, $zero
/* C3B6F4 80240CE4 AFA00010 */  sw        $zero, 0x10($sp)
/* C3B6F8 80240CE8 8E260024 */  lw        $a2, 0x24($s1)
/* C3B6FC 80240CEC 8E270028 */  lw        $a3, 0x28($s1)
/* C3B700 80240CF0 0C01242D */  jal       func_800490B4
/* C3B704 80240CF4 0040802D */   daddu    $s0, $v0, $zero
/* C3B708 80240CF8 1040000C */  beqz      $v0, .L80240D2C
/* C3B70C 80240CFC 00000000 */   nop
/* C3B710 80240D00 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3B714 80240D04 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C3B718 80240D08 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3B71C 80240D0C C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3B720 80240D10 8C460028 */  lw        $a2, 0x28($v0)
/* C3B724 80240D14 0C00A720 */  jal       atan2
/* C3B728 80240D18 8C470030 */   lw       $a3, 0x30($v0)
/* C3B72C 80240D1C 2402000C */  addiu     $v0, $zero, 0xc
/* C3B730 80240D20 E600000C */  swc1      $f0, 0xc($s0)
/* C3B734 80240D24 08090382 */  j         .L80240E08
/* C3B738 80240D28 AE620070 */   sw       $v0, 0x70($s3)
.L80240D2C:
/* C3B73C 80240D2C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3B740 80240D30 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C3B744 80240D34 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3B748 80240D38 C4440000 */  lwc1      $f4, ($v0)
/* C3B74C 80240D3C 46802120 */  cvt.s.w   $f4, $f4
/* C3B750 80240D40 44062000 */  mfc1      $a2, $f4
/* C3B754 80240D44 C4440008 */  lwc1      $f4, 8($v0)
/* C3B758 80240D48 46802120 */  cvt.s.w   $f4, $f4
/* C3B75C 80240D4C 44072000 */  mfc1      $a3, $f4
/* C3B760 80240D50 0C00A7B5 */  jal       dist2D
/* C3B764 80240D54 00000000 */   nop
/* C3B768 80240D58 C6020018 */  lwc1      $f2, 0x18($s0)
/* C3B76C 80240D5C 4602003E */  c.le.s    $f0, $f2
/* C3B770 80240D60 00000000 */  nop
/* C3B774 80240D64 4500000B */  bc1f      .L80240D94
/* C3B778 80240D68 00000000 */   nop
/* C3B77C 80240D6C 8E4200CC */  lw        $v0, 0xcc($s2)
/* C3B780 80240D70 8C430000 */  lw        $v1, ($v0)
/* C3B784 80240D74 2402000F */  addiu     $v0, $zero, 0xf
/* C3B788 80240D78 A602008E */  sh        $v0, 0x8e($s0)
/* C3B78C 80240D7C 24020032 */  addiu     $v0, $zero, 0x32
/* C3B790 80240D80 AE030028 */  sw        $v1, 0x28($s0)
/* C3B794 80240D84 AE420088 */  sw        $v0, 0x88($s2)
/* C3B798 80240D88 24020003 */  addiu     $v0, $zero, 3
/* C3B79C 80240D8C 08090382 */  j         .L80240E08
/* C3B7A0 80240D90 AE620070 */   sw       $v0, 0x70($s3)
.L80240D94:
/* C3B7A4 80240D94 8602008C */  lh        $v0, 0x8c($s0)
/* C3B7A8 80240D98 1440001B */  bnez      $v0, .L80240E08
/* C3B7AC 80240D9C 0200202D */   daddu    $a0, $s0, $zero
/* C3B7B0 80240DA0 27A60018 */  addiu     $a2, $sp, 0x18
/* C3B7B4 80240DA4 3C0540A0 */  lui       $a1, 0x40a0
/* C3B7B8 80240DA8 C600000C */  lwc1      $f0, 0xc($s0)
/* C3B7BC 80240DAC 0000382D */  daddu     $a3, $zero, $zero
/* C3B7C0 80240DB0 E7A00018 */  swc1      $f0, 0x18($sp)
/* C3B7C4 80240DB4 AFA00010 */  sw        $zero, 0x10($sp)
/* C3B7C8 80240DB8 0C0129E1 */  jal       func_8004A784
/* C3B7CC 80240DBC AFA00014 */   sw       $zero, 0x14($sp)
/* C3B7D0 80240DC0 C7A00018 */  lwc1      $f0, 0x18($sp)
/* C3B7D4 80240DC4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3B7D8 80240DC8 E600000C */  swc1      $f0, 0xc($s0)
/* C3B7DC 80240DCC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C3B7E0 80240DD0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3B7E4 80240DD4 C4440000 */  lwc1      $f4, ($v0)
/* C3B7E8 80240DD8 46802120 */  cvt.s.w   $f4, $f4
/* C3B7EC 80240DDC 44062000 */  mfc1      $a2, $f4
/* C3B7F0 80240DE0 C4440008 */  lwc1      $f4, 8($v0)
/* C3B7F4 80240DE4 46802120 */  cvt.s.w   $f4, $f4
/* C3B7F8 80240DE8 44072000 */  mfc1      $a3, $f4
/* C3B7FC 80240DEC 0C00A720 */  jal       atan2
/* C3B800 80240DF0 00000000 */   nop
/* C3B804 80240DF4 8E050018 */  lw        $a1, 0x18($s0)
/* C3B808 80240DF8 44060000 */  mfc1      $a2, $f0
/* C3B80C 80240DFC 0200202D */  daddu     $a0, $s0, $zero
/* C3B810 80240E00 0C00EA95 */  jal       npc_move_heading
/* C3B814 80240E04 AC86000C */   sw       $a2, 0xc($a0)
.L80240E08:
/* C3B818 80240E08 8FBF0030 */  lw        $ra, 0x30($sp)
/* C3B81C 80240E0C 8FB3002C */  lw        $s3, 0x2c($sp)
/* C3B820 80240E10 8FB20028 */  lw        $s2, 0x28($sp)
/* C3B824 80240E14 8FB10024 */  lw        $s1, 0x24($sp)
/* C3B828 80240E18 8FB00020 */  lw        $s0, 0x20($sp)
/* C3B82C 80240E1C 03E00008 */  jr        $ra
/* C3B830 80240E20 27BD0038 */   addiu    $sp, $sp, 0x38
