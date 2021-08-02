.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024098C_EB97DC
/* EB97DC 8024098C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EB97E0 80240990 AFB3003C */  sw        $s3, 0x3c($sp)
/* EB97E4 80240994 0080982D */  daddu     $s3, $a0, $zero
/* EB97E8 80240998 AFBF0040 */  sw        $ra, 0x40($sp)
/* EB97EC 8024099C AFB20038 */  sw        $s2, 0x38($sp)
/* EB97F0 802409A0 AFB10034 */  sw        $s1, 0x34($sp)
/* EB97F4 802409A4 AFB00030 */  sw        $s0, 0x30($sp)
/* EB97F8 802409A8 8E720148 */  lw        $s2, 0x148($s3)
/* EB97FC 802409AC 00A0882D */  daddu     $s1, $a1, $zero
/* EB9800 802409B0 86440008 */  lh        $a0, 8($s2)
/* EB9804 802409B4 0C00F92F */  jal       dead_get_npc_unsafe
/* EB9808 802409B8 00C0802D */   daddu    $s0, $a2, $zero
/* EB980C 802409BC 0200202D */  daddu     $a0, $s0, $zero
/* EB9810 802409C0 0240282D */  daddu     $a1, $s2, $zero
/* EB9814 802409C4 24030001 */  addiu     $v1, $zero, 1
/* EB9818 802409C8 AFA30010 */  sw        $v1, 0x10($sp)
/* EB981C 802409CC 8E260024 */  lw        $a2, 0x24($s1)
/* EB9820 802409D0 8E270028 */  lw        $a3, 0x28($s1)
/* EB9824 802409D4 0C013469 */  jal       func_8004D1A4
/* EB9828 802409D8 0040802D */   daddu    $s0, $v0, $zero
/* EB982C 802409DC 1440001E */  bnez      $v0, .L80240A58
/* EB9830 802409E0 0200202D */   daddu    $a0, $s0, $zero
/* EB9834 802409E4 24040002 */  addiu     $a0, $zero, 2
/* EB9838 802409E8 0200282D */  daddu     $a1, $s0, $zero
/* EB983C 802409EC 0000302D */  daddu     $a2, $zero, $zero
/* EB9840 802409F0 860300A8 */  lh        $v1, 0xa8($s0)
/* EB9844 802409F4 3C013F80 */  lui       $at, 0x3f80
/* EB9848 802409F8 44810000 */  mtc1      $at, $f0
/* EB984C 802409FC 3C014000 */  lui       $at, 0x4000
/* EB9850 80240A00 44811000 */  mtc1      $at, $f2
/* EB9854 80240A04 3C01C1A0 */  lui       $at, 0xc1a0
/* EB9858 80240A08 44812000 */  mtc1      $at, $f4
/* EB985C 80240A0C 2402000F */  addiu     $v0, $zero, 0xf
/* EB9860 80240A10 AFA2001C */  sw        $v0, 0x1c($sp)
/* EB9864 80240A14 44833000 */  mtc1      $v1, $f6
/* EB9868 80240A18 00000000 */  nop
/* EB986C 80240A1C 468031A0 */  cvt.s.w   $f6, $f6
/* EB9870 80240A20 44073000 */  mfc1      $a3, $f6
/* EB9874 80240A24 27A20028 */  addiu     $v0, $sp, 0x28
/* EB9878 80240A28 AFA20020 */  sw        $v0, 0x20($sp)
/* EB987C 80240A2C E7A00010 */  swc1      $f0, 0x10($sp)
/* EB9880 80240A30 E7A20014 */  swc1      $f2, 0x14($sp)
/* EB9884 80240A34 0C01D444 */  jal       func_80075110
/* EB9888 80240A38 E7A40018 */   swc1     $f4, 0x18($sp)
/* EB988C 80240A3C 8E4200CC */  lw        $v0, 0xcc($s2)
/* EB9890 80240A40 8C430000 */  lw        $v1, ($v0)
/* EB9894 80240A44 24020019 */  addiu     $v0, $zero, 0x19
/* EB9898 80240A48 A602008E */  sh        $v0, 0x8e($s0)
/* EB989C 80240A4C 2402000E */  addiu     $v0, $zero, 0xe
/* EB98A0 80240A50 080902A3 */  j         .L80240A8C
/* EB98A4 80240A54 AE030028 */   sw       $v1, 0x28($s0)
.L80240A58:
/* EB98A8 80240A58 0C010420 */  jal       func_80041080
/* EB98AC 80240A5C 24050001 */   addiu    $a1, $zero, 1
/* EB98B0 80240A60 8E050018 */  lw        $a1, 0x18($s0)
/* EB98B4 80240A64 8E06000C */  lw        $a2, 0xc($s0)
/* EB98B8 80240A68 0C00F909 */  jal       func_8003E424
/* EB98BC 80240A6C 0200202D */   daddu    $a0, $s0, $zero
/* EB98C0 80240A70 8602008E */  lh        $v0, 0x8e($s0)
/* EB98C4 80240A74 9603008E */  lhu       $v1, 0x8e($s0)
/* EB98C8 80240A78 18400003 */  blez      $v0, .L80240A88
/* EB98CC 80240A7C 2462FFFF */   addiu    $v0, $v1, -1
/* EB98D0 80240A80 080902A4 */  j         .L80240A90
/* EB98D4 80240A84 A602008E */   sh       $v0, 0x8e($s0)
.L80240A88:
/* EB98D8 80240A88 2402000C */  addiu     $v0, $zero, 0xc
.L80240A8C:
/* EB98DC 80240A8C AE620070 */  sw        $v0, 0x70($s3)
.L80240A90:
/* EB98E0 80240A90 8FBF0040 */  lw        $ra, 0x40($sp)
/* EB98E4 80240A94 8FB3003C */  lw        $s3, 0x3c($sp)
/* EB98E8 80240A98 8FB20038 */  lw        $s2, 0x38($sp)
/* EB98EC 80240A9C 8FB10034 */  lw        $s1, 0x34($sp)
/* EB98F0 80240AA0 8FB00030 */  lw        $s0, 0x30($sp)
/* EB98F4 80240AA4 03E00008 */  jr        $ra
/* EB98F8 80240AA8 27BD0048 */   addiu    $sp, $sp, 0x48
