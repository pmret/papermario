.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kkj_00_UnkFunc15
/* ABBC8C 802409FC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* ABBC90 80240A00 AFB3003C */  sw        $s3, 0x3c($sp)
/* ABBC94 80240A04 0080982D */  daddu     $s3, $a0, $zero
/* ABBC98 80240A08 AFBF0040 */  sw        $ra, 0x40($sp)
/* ABBC9C 80240A0C AFB20038 */  sw        $s2, 0x38($sp)
/* ABBCA0 80240A10 AFB10034 */  sw        $s1, 0x34($sp)
/* ABBCA4 80240A14 AFB00030 */  sw        $s0, 0x30($sp)
/* ABBCA8 80240A18 8E720148 */  lw        $s2, 0x148($s3)
/* ABBCAC 80240A1C 00A0882D */  daddu     $s1, $a1, $zero
/* ABBCB0 80240A20 86440008 */  lh        $a0, 8($s2)
/* ABBCB4 80240A24 0C00EABB */  jal       get_npc_unsafe
/* ABBCB8 80240A28 00C0802D */   daddu    $s0, $a2, $zero
/* ABBCBC 80240A2C 0200202D */  daddu     $a0, $s0, $zero
/* ABBCC0 80240A30 0240282D */  daddu     $a1, $s2, $zero
/* ABBCC4 80240A34 24030001 */  addiu     $v1, $zero, 1
/* ABBCC8 80240A38 AFA30010 */  sw        $v1, 0x10($sp)
/* ABBCCC 80240A3C 8E260024 */  lw        $a2, 0x24($s1)
/* ABBCD0 80240A40 8E270028 */  lw        $a3, 0x28($s1)
/* ABBCD4 80240A44 0C01242D */  jal       func_800490B4
/* ABBCD8 80240A48 0040802D */   daddu    $s0, $v0, $zero
/* ABBCDC 80240A4C 1440001E */  bnez      $v0, .L80240AC8
/* ABBCE0 80240A50 0200202D */   daddu    $a0, $s0, $zero
/* ABBCE4 80240A54 24040002 */  addiu     $a0, $zero, 2
/* ABBCE8 80240A58 0200282D */  daddu     $a1, $s0, $zero
/* ABBCEC 80240A5C 0000302D */  daddu     $a2, $zero, $zero
/* ABBCF0 80240A60 860300A8 */  lh        $v1, 0xa8($s0)
/* ABBCF4 80240A64 3C013F80 */  lui       $at, 0x3f80
/* ABBCF8 80240A68 44810000 */  mtc1      $at, $f0
/* ABBCFC 80240A6C 3C014000 */  lui       $at, 0x4000
/* ABBD00 80240A70 44811000 */  mtc1      $at, $f2
/* ABBD04 80240A74 3C01C1A0 */  lui       $at, 0xc1a0
/* ABBD08 80240A78 44812000 */  mtc1      $at, $f4
/* ABBD0C 80240A7C 2402000F */  addiu     $v0, $zero, 0xf
/* ABBD10 80240A80 AFA2001C */  sw        $v0, 0x1c($sp)
/* ABBD14 80240A84 44833000 */  mtc1      $v1, $f6
/* ABBD18 80240A88 00000000 */  nop
/* ABBD1C 80240A8C 468031A0 */  cvt.s.w   $f6, $f6
/* ABBD20 80240A90 44073000 */  mfc1      $a3, $f6
/* ABBD24 80240A94 27A20028 */  addiu     $v0, $sp, 0x28
/* ABBD28 80240A98 AFA20020 */  sw        $v0, 0x20($sp)
/* ABBD2C 80240A9C E7A00010 */  swc1      $f0, 0x10($sp)
/* ABBD30 80240AA0 E7A20014 */  swc1      $f2, 0x14($sp)
/* ABBD34 80240AA4 0C01BFA4 */  jal       fx_emote
/* ABBD38 80240AA8 E7A40018 */   swc1     $f4, 0x18($sp)
/* ABBD3C 80240AAC 8E4200CC */  lw        $v0, 0xcc($s2)
/* ABBD40 80240AB0 8C430000 */  lw        $v1, ($v0)
/* ABBD44 80240AB4 24020019 */  addiu     $v0, $zero, 0x19
/* ABBD48 80240AB8 A602008E */  sh        $v0, 0x8e($s0)
/* ABBD4C 80240ABC 2402000E */  addiu     $v0, $zero, 0xe
/* ABBD50 80240AC0 080902BF */  j         .L80240AFC
/* ABBD54 80240AC4 AE030028 */   sw       $v1, 0x28($s0)
.L80240AC8:
/* ABBD58 80240AC8 0C00F598 */  jal       func_8003D660
/* ABBD5C 80240ACC 24050001 */   addiu    $a1, $zero, 1
/* ABBD60 80240AD0 8E050018 */  lw        $a1, 0x18($s0)
/* ABBD64 80240AD4 8E06000C */  lw        $a2, 0xc($s0)
/* ABBD68 80240AD8 0C00EA95 */  jal       npc_move_heading
/* ABBD6C 80240ADC 0200202D */   daddu    $a0, $s0, $zero
/* ABBD70 80240AE0 8602008E */  lh        $v0, 0x8e($s0)
/* ABBD74 80240AE4 9603008E */  lhu       $v1, 0x8e($s0)
/* ABBD78 80240AE8 18400003 */  blez      $v0, .L80240AF8
/* ABBD7C 80240AEC 2462FFFF */   addiu    $v0, $v1, -1
/* ABBD80 80240AF0 080902C0 */  j         .L80240B00
/* ABBD84 80240AF4 A602008E */   sh       $v0, 0x8e($s0)
.L80240AF8:
/* ABBD88 80240AF8 2402000C */  addiu     $v0, $zero, 0xc
.L80240AFC:
/* ABBD8C 80240AFC AE620070 */  sw        $v0, 0x70($s3)
.L80240B00:
/* ABBD90 80240B00 8FBF0040 */  lw        $ra, 0x40($sp)
/* ABBD94 80240B04 8FB3003C */  lw        $s3, 0x3c($sp)
/* ABBD98 80240B08 8FB20038 */  lw        $s2, 0x38($sp)
/* ABBD9C 80240B0C 8FB10034 */  lw        $s1, 0x34($sp)
/* ABBDA0 80240B10 8FB00030 */  lw        $s0, 0x30($sp)
/* ABBDA4 80240B14 03E00008 */  jr        $ra
/* ABBDA8 80240B18 27BD0048 */   addiu    $sp, $sp, 0x48
