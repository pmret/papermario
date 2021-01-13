.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024098C_C9E8AC
/* C9E8AC 8024098C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C9E8B0 80240990 AFB3003C */  sw        $s3, 0x3c($sp)
/* C9E8B4 80240994 0080982D */  daddu     $s3, $a0, $zero
/* C9E8B8 80240998 AFBF0040 */  sw        $ra, 0x40($sp)
/* C9E8BC 8024099C AFB20038 */  sw        $s2, 0x38($sp)
/* C9E8C0 802409A0 AFB10034 */  sw        $s1, 0x34($sp)
/* C9E8C4 802409A4 AFB00030 */  sw        $s0, 0x30($sp)
/* C9E8C8 802409A8 8E720148 */  lw        $s2, 0x148($s3)
/* C9E8CC 802409AC 00A0882D */  daddu     $s1, $a1, $zero
/* C9E8D0 802409B0 86440008 */  lh        $a0, 8($s2)
/* C9E8D4 802409B4 0C00EABB */  jal       get_npc_unsafe
/* C9E8D8 802409B8 00C0802D */   daddu    $s0, $a2, $zero
/* C9E8DC 802409BC 0200202D */  daddu     $a0, $s0, $zero
/* C9E8E0 802409C0 0240282D */  daddu     $a1, $s2, $zero
/* C9E8E4 802409C4 24030001 */  addiu     $v1, $zero, 1
/* C9E8E8 802409C8 AFA30010 */  sw        $v1, 0x10($sp)
/* C9E8EC 802409CC 8E260024 */  lw        $a2, 0x24($s1)
/* C9E8F0 802409D0 8E270028 */  lw        $a3, 0x28($s1)
/* C9E8F4 802409D4 0C01242D */  jal       func_800490B4
/* C9E8F8 802409D8 0040802D */   daddu    $s0, $v0, $zero
/* C9E8FC 802409DC 1440001E */  bnez      $v0, .L80240A58
/* C9E900 802409E0 0200202D */   daddu    $a0, $s0, $zero
/* C9E904 802409E4 24040002 */  addiu     $a0, $zero, 2
/* C9E908 802409E8 0200282D */  daddu     $a1, $s0, $zero
/* C9E90C 802409EC 0000302D */  daddu     $a2, $zero, $zero
/* C9E910 802409F0 860300A8 */  lh        $v1, 0xa8($s0)
/* C9E914 802409F4 3C013F80 */  lui       $at, 0x3f80
/* C9E918 802409F8 44810000 */  mtc1      $at, $f0
/* C9E91C 802409FC 3C014000 */  lui       $at, 0x4000
/* C9E920 80240A00 44811000 */  mtc1      $at, $f2
/* C9E924 80240A04 3C01C1A0 */  lui       $at, 0xc1a0
/* C9E928 80240A08 44812000 */  mtc1      $at, $f4
/* C9E92C 80240A0C 2402000F */  addiu     $v0, $zero, 0xf
/* C9E930 80240A10 AFA2001C */  sw        $v0, 0x1c($sp)
/* C9E934 80240A14 44833000 */  mtc1      $v1, $f6
/* C9E938 80240A18 00000000 */  nop
/* C9E93C 80240A1C 468031A0 */  cvt.s.w   $f6, $f6
/* C9E940 80240A20 44073000 */  mfc1      $a3, $f6
/* C9E944 80240A24 27A20028 */  addiu     $v0, $sp, 0x28
/* C9E948 80240A28 AFA20020 */  sw        $v0, 0x20($sp)
/* C9E94C 80240A2C E7A00010 */  swc1      $f0, 0x10($sp)
/* C9E950 80240A30 E7A20014 */  swc1      $f2, 0x14($sp)
/* C9E954 80240A34 0C01BFA4 */  jal       fx_emote
/* C9E958 80240A38 E7A40018 */   swc1     $f4, 0x18($sp)
/* C9E95C 80240A3C 8E4200CC */  lw        $v0, 0xcc($s2)
/* C9E960 80240A40 8C430000 */  lw        $v1, ($v0)
/* C9E964 80240A44 24020019 */  addiu     $v0, $zero, 0x19
/* C9E968 80240A48 A602008E */  sh        $v0, 0x8e($s0)
/* C9E96C 80240A4C 2402000E */  addiu     $v0, $zero, 0xe
/* C9E970 80240A50 080902A3 */  j         .L80240A8C
/* C9E974 80240A54 AE030028 */   sw       $v1, 0x28($s0)
.L80240A58:
/* C9E978 80240A58 0C00F598 */  jal       func_8003D660
/* C9E97C 80240A5C 24050001 */   addiu    $a1, $zero, 1
/* C9E980 80240A60 8E050018 */  lw        $a1, 0x18($s0)
/* C9E984 80240A64 8E06000C */  lw        $a2, 0xc($s0)
/* C9E988 80240A68 0C00EA95 */  jal       npc_move_heading
/* C9E98C 80240A6C 0200202D */   daddu    $a0, $s0, $zero
/* C9E990 80240A70 8602008E */  lh        $v0, 0x8e($s0)
/* C9E994 80240A74 9603008E */  lhu       $v1, 0x8e($s0)
/* C9E998 80240A78 18400003 */  blez      $v0, .L80240A88
/* C9E99C 80240A7C 2462FFFF */   addiu    $v0, $v1, -1
/* C9E9A0 80240A80 080902A4 */  j         .L80240A90
/* C9E9A4 80240A84 A602008E */   sh       $v0, 0x8e($s0)
.L80240A88:
/* C9E9A8 80240A88 2402000C */  addiu     $v0, $zero, 0xc
.L80240A8C:
/* C9E9AC 80240A8C AE620070 */  sw        $v0, 0x70($s3)
.L80240A90:
/* C9E9B0 80240A90 8FBF0040 */  lw        $ra, 0x40($sp)
/* C9E9B4 80240A94 8FB3003C */  lw        $s3, 0x3c($sp)
/* C9E9B8 80240A98 8FB20038 */  lw        $s2, 0x38($sp)
/* C9E9BC 80240A9C 8FB10034 */  lw        $s1, 0x34($sp)
/* C9E9C0 80240AA0 8FB00030 */  lw        $s0, 0x30($sp)
/* C9E9C4 80240AA4 03E00008 */  jr        $ra
/* C9E9C8 80240AA8 27BD0048 */   addiu    $sp, $sp, 0x48
