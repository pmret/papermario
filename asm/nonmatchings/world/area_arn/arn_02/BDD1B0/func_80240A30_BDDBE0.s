.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A30_BDDBE0
/* BDDBE0 80240A30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BDDBE4 80240A34 AFB30024 */  sw        $s3, 0x24($sp)
/* BDDBE8 80240A38 0080982D */  daddu     $s3, $a0, $zero
/* BDDBEC 80240A3C AFBF0028 */  sw        $ra, 0x28($sp)
/* BDDBF0 80240A40 AFB20020 */  sw        $s2, 0x20($sp)
/* BDDBF4 80240A44 AFB1001C */  sw        $s1, 0x1c($sp)
/* BDDBF8 80240A48 AFB00018 */  sw        $s0, 0x18($sp)
/* BDDBFC 80240A4C 8E720148 */  lw        $s2, 0x148($s3)
/* BDDC00 80240A50 00A0882D */  daddu     $s1, $a1, $zero
/* BDDC04 80240A54 86440008 */  lh        $a0, 8($s2)
/* BDDC08 80240A58 0C00EABB */  jal       get_npc_unsafe
/* BDDC0C 80240A5C 00C0802D */   daddu    $s0, $a2, $zero
/* BDDC10 80240A60 0200202D */  daddu     $a0, $s0, $zero
/* BDDC14 80240A64 0240282D */  daddu     $a1, $s2, $zero
/* BDDC18 80240A68 AFA00010 */  sw        $zero, 0x10($sp)
/* BDDC1C 80240A6C 8E260024 */  lw        $a2, 0x24($s1)
/* BDDC20 80240A70 8E270028 */  lw        $a3, 0x28($s1)
/* BDDC24 80240A74 0C01242D */  jal       func_800490B4
/* BDDC28 80240A78 0040802D */   daddu    $s0, $v0, $zero
/* BDDC2C 80240A7C 1040000C */  beqz      $v0, .L80240AB0
/* BDDC30 80240A80 00000000 */   nop
/* BDDC34 80240A84 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDDC38 80240A88 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BDDC3C 80240A8C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BDDC40 80240A90 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDDC44 80240A94 8C460028 */  lw        $a2, 0x28($v0)
/* BDDC48 80240A98 0C00A720 */  jal       atan2
/* BDDC4C 80240A9C 8C470030 */   lw       $a3, 0x30($v0)
/* BDDC50 80240AA0 2402000C */  addiu     $v0, $zero, 0xc
/* BDDC54 80240AA4 E600000C */  swc1      $f0, 0xc($s0)
/* BDDC58 80240AA8 080902D3 */  j         .L80240B4C
/* BDDC5C 80240AAC AE620070 */   sw       $v0, 0x70($s3)
.L80240AB0:
/* BDDC60 80240AB0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDDC64 80240AB4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDC68 80240AB8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDDC6C 80240ABC C4440000 */  lwc1      $f4, ($v0)
/* BDDC70 80240AC0 46802120 */  cvt.s.w   $f4, $f4
/* BDDC74 80240AC4 44062000 */  mfc1      $a2, $f4
/* BDDC78 80240AC8 C4440008 */  lwc1      $f4, 8($v0)
/* BDDC7C 80240ACC 46802120 */  cvt.s.w   $f4, $f4
/* BDDC80 80240AD0 44072000 */  mfc1      $a3, $f4
/* BDDC84 80240AD4 0C00A7B5 */  jal       dist2D
/* BDDC88 80240AD8 00000000 */   nop
/* BDDC8C 80240ADC C6020018 */  lwc1      $f2, 0x18($s0)
/* BDDC90 80240AE0 4602003E */  c.le.s    $f0, $f2
/* BDDC94 80240AE4 00000000 */  nop
/* BDDC98 80240AE8 45000005 */  bc1f      .L80240B00
/* BDDC9C 80240AEC 2402000A */   addiu    $v0, $zero, 0xa
/* BDDCA0 80240AF0 A602008E */  sh        $v0, 0x8e($s0)
/* BDDCA4 80240AF4 24020032 */  addiu     $v0, $zero, 0x32
/* BDDCA8 80240AF8 080902D3 */  j         .L80240B4C
/* BDDCAC 80240AFC AE620070 */   sw       $v0, 0x70($s3)
.L80240B00:
/* BDDCB0 80240B00 8602008C */  lh        $v0, 0x8c($s0)
/* BDDCB4 80240B04 14400011 */  bnez      $v0, .L80240B4C
/* BDDCB8 80240B08 00000000 */   nop
/* BDDCBC 80240B0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDDCC0 80240B10 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BDDCC4 80240B14 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDDCC8 80240B18 C4440000 */  lwc1      $f4, ($v0)
/* BDDCCC 80240B1C 46802120 */  cvt.s.w   $f4, $f4
/* BDDCD0 80240B20 44062000 */  mfc1      $a2, $f4
/* BDDCD4 80240B24 C4440008 */  lwc1      $f4, 8($v0)
/* BDDCD8 80240B28 46802120 */  cvt.s.w   $f4, $f4
/* BDDCDC 80240B2C 44072000 */  mfc1      $a3, $f4
/* BDDCE0 80240B30 0C00A720 */  jal       atan2
/* BDDCE4 80240B34 00000000 */   nop
/* BDDCE8 80240B38 8E050018 */  lw        $a1, 0x18($s0)
/* BDDCEC 80240B3C 44060000 */  mfc1      $a2, $f0
/* BDDCF0 80240B40 0200202D */  daddu     $a0, $s0, $zero
/* BDDCF4 80240B44 0C00EA95 */  jal       npc_move_heading
/* BDDCF8 80240B48 AC86000C */   sw       $a2, 0xc($a0)
.L80240B4C:
/* BDDCFC 80240B4C 8FBF0028 */  lw        $ra, 0x28($sp)
/* BDDD00 80240B50 8FB30024 */  lw        $s3, 0x24($sp)
/* BDDD04 80240B54 8FB20020 */  lw        $s2, 0x20($sp)
/* BDDD08 80240B58 8FB1001C */  lw        $s1, 0x1c($sp)
/* BDDD0C 80240B5C 8FB00018 */  lw        $s0, 0x18($sp)
/* BDDD10 80240B60 03E00008 */  jr        $ra
/* BDDD14 80240B64 27BD0030 */   addiu    $sp, $sp, 0x30
