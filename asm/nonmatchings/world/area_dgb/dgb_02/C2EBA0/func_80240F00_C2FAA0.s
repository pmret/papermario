.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F00_C2FAA0
/* C2FAA0 80240F00 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C2FAA4 80240F04 AFB3002C */  sw        $s3, 0x2c($sp)
/* C2FAA8 80240F08 0080982D */  daddu     $s3, $a0, $zero
/* C2FAAC 80240F0C AFBF0030 */  sw        $ra, 0x30($sp)
/* C2FAB0 80240F10 AFB20028 */  sw        $s2, 0x28($sp)
/* C2FAB4 80240F14 AFB10024 */  sw        $s1, 0x24($sp)
/* C2FAB8 80240F18 AFB00020 */  sw        $s0, 0x20($sp)
/* C2FABC 80240F1C 8E720148 */  lw        $s2, 0x148($s3)
/* C2FAC0 80240F20 00A0882D */  daddu     $s1, $a1, $zero
/* C2FAC4 80240F24 86440008 */  lh        $a0, 8($s2)
/* C2FAC8 80240F28 0C00EABB */  jal       get_npc_unsafe
/* C2FACC 80240F2C 00C0802D */   daddu    $s0, $a2, $zero
/* C2FAD0 80240F30 0200202D */  daddu     $a0, $s0, $zero
/* C2FAD4 80240F34 0240282D */  daddu     $a1, $s2, $zero
/* C2FAD8 80240F38 AFA00010 */  sw        $zero, 0x10($sp)
/* C2FADC 80240F3C 8E260024 */  lw        $a2, 0x24($s1)
/* C2FAE0 80240F40 8E270028 */  lw        $a3, 0x28($s1)
/* C2FAE4 80240F44 0C01242D */  jal       func_800490B4
/* C2FAE8 80240F48 0040802D */   daddu    $s0, $v0, $zero
/* C2FAEC 80240F4C 1040000C */  beqz      $v0, .L80240F80
/* C2FAF0 80240F50 00000000 */   nop
/* C2FAF4 80240F54 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C2FAF8 80240F58 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C2FAFC 80240F5C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C2FB00 80240F60 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C2FB04 80240F64 8C460028 */  lw        $a2, 0x28($v0)
/* C2FB08 80240F68 0C00A720 */  jal       atan2
/* C2FB0C 80240F6C 8C470030 */   lw       $a3, 0x30($v0)
/* C2FB10 80240F70 2402000C */  addiu     $v0, $zero, 0xc
/* C2FB14 80240F74 E600000C */  swc1      $f0, 0xc($s0)
/* C2FB18 80240F78 08090417 */  j         .L8024105C
/* C2FB1C 80240F7C AE620070 */   sw       $v0, 0x70($s3)
.L80240F80:
/* C2FB20 80240F80 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C2FB24 80240F84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C2FB28 80240F88 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C2FB2C 80240F8C C4440000 */  lwc1      $f4, ($v0)
/* C2FB30 80240F90 46802120 */  cvt.s.w   $f4, $f4
/* C2FB34 80240F94 44062000 */  mfc1      $a2, $f4
/* C2FB38 80240F98 C4440008 */  lwc1      $f4, 8($v0)
/* C2FB3C 80240F9C 46802120 */  cvt.s.w   $f4, $f4
/* C2FB40 80240FA0 44072000 */  mfc1      $a3, $f4
/* C2FB44 80240FA4 0C00A7B5 */  jal       dist2D
/* C2FB48 80240FA8 00000000 */   nop
/* C2FB4C 80240FAC C6020018 */  lwc1      $f2, 0x18($s0)
/* C2FB50 80240FB0 4602003E */  c.le.s    $f0, $f2
/* C2FB54 80240FB4 00000000 */  nop
/* C2FB58 80240FB8 4500000B */  bc1f      .L80240FE8
/* C2FB5C 80240FBC 00000000 */   nop
/* C2FB60 80240FC0 8E4200CC */  lw        $v0, 0xcc($s2)
/* C2FB64 80240FC4 8C430000 */  lw        $v1, ($v0)
/* C2FB68 80240FC8 2402000F */  addiu     $v0, $zero, 0xf
/* C2FB6C 80240FCC A602008E */  sh        $v0, 0x8e($s0)
/* C2FB70 80240FD0 24020032 */  addiu     $v0, $zero, 0x32
/* C2FB74 80240FD4 AE030028 */  sw        $v1, 0x28($s0)
/* C2FB78 80240FD8 AE420088 */  sw        $v0, 0x88($s2)
/* C2FB7C 80240FDC 24020003 */  addiu     $v0, $zero, 3
/* C2FB80 80240FE0 08090417 */  j         .L8024105C
/* C2FB84 80240FE4 AE620070 */   sw       $v0, 0x70($s3)
.L80240FE8:
/* C2FB88 80240FE8 8602008C */  lh        $v0, 0x8c($s0)
/* C2FB8C 80240FEC 1440001B */  bnez      $v0, .L8024105C
/* C2FB90 80240FF0 0200202D */   daddu    $a0, $s0, $zero
/* C2FB94 80240FF4 27A60018 */  addiu     $a2, $sp, 0x18
/* C2FB98 80240FF8 3C0540A0 */  lui       $a1, 0x40a0
/* C2FB9C 80240FFC C600000C */  lwc1      $f0, 0xc($s0)
/* C2FBA0 80241000 0000382D */  daddu     $a3, $zero, $zero
/* C2FBA4 80241004 E7A00018 */  swc1      $f0, 0x18($sp)
/* C2FBA8 80241008 AFA00010 */  sw        $zero, 0x10($sp)
/* C2FBAC 8024100C 0C0129E1 */  jal       func_8004A784
/* C2FBB0 80241010 AFA00014 */   sw       $zero, 0x14($sp)
/* C2FBB4 80241014 C7A00018 */  lwc1      $f0, 0x18($sp)
/* C2FBB8 80241018 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C2FBBC 8024101C E600000C */  swc1      $f0, 0xc($s0)
/* C2FBC0 80241020 8E4200D0 */  lw        $v0, 0xd0($s2)
/* C2FBC4 80241024 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C2FBC8 80241028 C4440000 */  lwc1      $f4, ($v0)
/* C2FBCC 8024102C 46802120 */  cvt.s.w   $f4, $f4
/* C2FBD0 80241030 44062000 */  mfc1      $a2, $f4
/* C2FBD4 80241034 C4440008 */  lwc1      $f4, 8($v0)
/* C2FBD8 80241038 46802120 */  cvt.s.w   $f4, $f4
/* C2FBDC 8024103C 44072000 */  mfc1      $a3, $f4
/* C2FBE0 80241040 0C00A720 */  jal       atan2
/* C2FBE4 80241044 00000000 */   nop
/* C2FBE8 80241048 8E050018 */  lw        $a1, 0x18($s0)
/* C2FBEC 8024104C 44060000 */  mfc1      $a2, $f0
/* C2FBF0 80241050 0200202D */  daddu     $a0, $s0, $zero
/* C2FBF4 80241054 0C00EA95 */  jal       npc_move_heading
/* C2FBF8 80241058 AC86000C */   sw       $a2, 0xc($a0)
.L8024105C:
/* C2FBFC 8024105C 8FBF0030 */  lw        $ra, 0x30($sp)
/* C2FC00 80241060 8FB3002C */  lw        $s3, 0x2c($sp)
/* C2FC04 80241064 8FB20028 */  lw        $s2, 0x28($sp)
/* C2FC08 80241068 8FB10024 */  lw        $s1, 0x24($sp)
/* C2FC0C 8024106C 8FB00020 */  lw        $s0, 0x20($sp)
/* C2FC10 80241070 03E00008 */  jr        $ra
/* C2FC14 80241074 27BD0038 */   addiu    $sp, $sp, 0x38
