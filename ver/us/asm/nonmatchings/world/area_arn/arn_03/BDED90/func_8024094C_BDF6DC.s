.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024094C_BDF6DC
/* BDF6DC 8024094C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BDF6E0 80240950 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDF6E4 80240954 0080982D */  daddu     $s3, $a0, $zero
/* BDF6E8 80240958 AFBF0040 */  sw        $ra, 0x40($sp)
/* BDF6EC 8024095C AFB20038 */  sw        $s2, 0x38($sp)
/* BDF6F0 80240960 AFB10034 */  sw        $s1, 0x34($sp)
/* BDF6F4 80240964 AFB00030 */  sw        $s0, 0x30($sp)
/* BDF6F8 80240968 8E720148 */  lw        $s2, 0x148($s3)
/* BDF6FC 8024096C 00A0882D */  daddu     $s1, $a1, $zero
/* BDF700 80240970 86440008 */  lh        $a0, 8($s2)
/* BDF704 80240974 0C00EABB */  jal       get_npc_unsafe
/* BDF708 80240978 00C0802D */   daddu    $s0, $a2, $zero
/* BDF70C 8024097C 0200202D */  daddu     $a0, $s0, $zero
/* BDF710 80240980 0240282D */  daddu     $a1, $s2, $zero
/* BDF714 80240984 24030001 */  addiu     $v1, $zero, 1
/* BDF718 80240988 AFA30010 */  sw        $v1, 0x10($sp)
/* BDF71C 8024098C 8E260024 */  lw        $a2, 0x24($s1)
/* BDF720 80240990 8E270028 */  lw        $a3, 0x28($s1)
/* BDF724 80240994 0C01242D */  jal       func_800490B4
/* BDF728 80240998 0040802D */   daddu    $s0, $v0, $zero
/* BDF72C 8024099C 1440001E */  bnez      $v0, .L80240A18
/* BDF730 802409A0 0200202D */   daddu    $a0, $s0, $zero
/* BDF734 802409A4 24040002 */  addiu     $a0, $zero, 2
/* BDF738 802409A8 0200282D */  daddu     $a1, $s0, $zero
/* BDF73C 802409AC 0000302D */  daddu     $a2, $zero, $zero
/* BDF740 802409B0 860300A8 */  lh        $v1, 0xa8($s0)
/* BDF744 802409B4 3C013F80 */  lui       $at, 0x3f80
/* BDF748 802409B8 44810000 */  mtc1      $at, $f0
/* BDF74C 802409BC 3C014000 */  lui       $at, 0x4000
/* BDF750 802409C0 44811000 */  mtc1      $at, $f2
/* BDF754 802409C4 3C01C1A0 */  lui       $at, 0xc1a0
/* BDF758 802409C8 44812000 */  mtc1      $at, $f4
/* BDF75C 802409CC 2402000F */  addiu     $v0, $zero, 0xf
/* BDF760 802409D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* BDF764 802409D4 44833000 */  mtc1      $v1, $f6
/* BDF768 802409D8 00000000 */  nop
/* BDF76C 802409DC 468031A0 */  cvt.s.w   $f6, $f6
/* BDF770 802409E0 44073000 */  mfc1      $a3, $f6
/* BDF774 802409E4 27A20028 */  addiu     $v0, $sp, 0x28
/* BDF778 802409E8 AFA20020 */  sw        $v0, 0x20($sp)
/* BDF77C 802409EC E7A00010 */  swc1      $f0, 0x10($sp)
/* BDF780 802409F0 E7A20014 */  swc1      $f2, 0x14($sp)
/* BDF784 802409F4 0C01BFA4 */  jal       fx_emote
/* BDF788 802409F8 E7A40018 */   swc1     $f4, 0x18($sp)
/* BDF78C 802409FC 8E4200CC */  lw        $v0, 0xcc($s2)
/* BDF790 80240A00 8C430000 */  lw        $v1, ($v0)
/* BDF794 80240A04 24020019 */  addiu     $v0, $zero, 0x19
/* BDF798 80240A08 A602008E */  sh        $v0, 0x8e($s0)
/* BDF79C 80240A0C 2402000E */  addiu     $v0, $zero, 0xe
/* BDF7A0 80240A10 08090293 */  j         .L80240A4C
/* BDF7A4 80240A14 AE030028 */   sw       $v1, 0x28($s0)
.L80240A18:
/* BDF7A8 80240A18 0C00F598 */  jal       func_8003D660
/* BDF7AC 80240A1C 24050001 */   addiu    $a1, $zero, 1
/* BDF7B0 80240A20 8E050018 */  lw        $a1, 0x18($s0)
/* BDF7B4 80240A24 8E06000C */  lw        $a2, 0xc($s0)
/* BDF7B8 80240A28 0C00EA95 */  jal       npc_move_heading
/* BDF7BC 80240A2C 0200202D */   daddu    $a0, $s0, $zero
/* BDF7C0 80240A30 8602008E */  lh        $v0, 0x8e($s0)
/* BDF7C4 80240A34 9603008E */  lhu       $v1, 0x8e($s0)
/* BDF7C8 80240A38 18400003 */  blez      $v0, .L80240A48
/* BDF7CC 80240A3C 2462FFFF */   addiu    $v0, $v1, -1
/* BDF7D0 80240A40 08090294 */  j         .L80240A50
/* BDF7D4 80240A44 A602008E */   sh       $v0, 0x8e($s0)
.L80240A48:
/* BDF7D8 80240A48 2402000C */  addiu     $v0, $zero, 0xc
.L80240A4C:
/* BDF7DC 80240A4C AE620070 */  sw        $v0, 0x70($s3)
.L80240A50:
/* BDF7E0 80240A50 8FBF0040 */  lw        $ra, 0x40($sp)
/* BDF7E4 80240A54 8FB3003C */  lw        $s3, 0x3c($sp)
/* BDF7E8 80240A58 8FB20038 */  lw        $s2, 0x38($sp)
/* BDF7EC 80240A5C 8FB10034 */  lw        $s1, 0x34($sp)
/* BDF7F0 80240A60 8FB00030 */  lw        $s0, 0x30($sp)
/* BDF7F4 80240A64 03E00008 */  jr        $ra
/* BDF7F8 80240A68 27BD0048 */   addiu    $sp, $sp, 0x48
