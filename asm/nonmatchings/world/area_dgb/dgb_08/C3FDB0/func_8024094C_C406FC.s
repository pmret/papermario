.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024094C_C406FC
/* C406FC 8024094C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C40700 80240950 AFB3003C */  sw        $s3, 0x3c($sp)
/* C40704 80240954 0080982D */  daddu     $s3, $a0, $zero
/* C40708 80240958 AFBF0040 */  sw        $ra, 0x40($sp)
/* C4070C 8024095C AFB20038 */  sw        $s2, 0x38($sp)
/* C40710 80240960 AFB10034 */  sw        $s1, 0x34($sp)
/* C40714 80240964 AFB00030 */  sw        $s0, 0x30($sp)
/* C40718 80240968 8E720148 */  lw        $s2, 0x148($s3)
/* C4071C 8024096C 00A0882D */  daddu     $s1, $a1, $zero
/* C40720 80240970 86440008 */  lh        $a0, 8($s2)
/* C40724 80240974 0C00EABB */  jal       get_npc_unsafe
/* C40728 80240978 00C0802D */   daddu    $s0, $a2, $zero
/* C4072C 8024097C 0200202D */  daddu     $a0, $s0, $zero
/* C40730 80240980 0240282D */  daddu     $a1, $s2, $zero
/* C40734 80240984 24030001 */  addiu     $v1, $zero, 1
/* C40738 80240988 AFA30010 */  sw        $v1, 0x10($sp)
/* C4073C 8024098C 8E260024 */  lw        $a2, 0x24($s1)
/* C40740 80240990 8E270028 */  lw        $a3, 0x28($s1)
/* C40744 80240994 0C01242D */  jal       func_800490B4
/* C40748 80240998 0040802D */   daddu    $s0, $v0, $zero
/* C4074C 8024099C 1440001E */  bnez      $v0, .L80240A18
/* C40750 802409A0 0200202D */   daddu    $a0, $s0, $zero
/* C40754 802409A4 24040002 */  addiu     $a0, $zero, 2
/* C40758 802409A8 0200282D */  daddu     $a1, $s0, $zero
/* C4075C 802409AC 0000302D */  daddu     $a2, $zero, $zero
/* C40760 802409B0 860300A8 */  lh        $v1, 0xa8($s0)
/* C40764 802409B4 3C013F80 */  lui       $at, 0x3f80
/* C40768 802409B8 44810000 */  mtc1      $at, $f0
/* C4076C 802409BC 3C014000 */  lui       $at, 0x4000
/* C40770 802409C0 44811000 */  mtc1      $at, $f2
/* C40774 802409C4 3C01C1A0 */  lui       $at, 0xc1a0
/* C40778 802409C8 44812000 */  mtc1      $at, $f4
/* C4077C 802409CC 2402000F */  addiu     $v0, $zero, 0xf
/* C40780 802409D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* C40784 802409D4 44833000 */  mtc1      $v1, $f6
/* C40788 802409D8 00000000 */  nop
/* C4078C 802409DC 468031A0 */  cvt.s.w   $f6, $f6
/* C40790 802409E0 44073000 */  mfc1      $a3, $f6
/* C40794 802409E4 27A20028 */  addiu     $v0, $sp, 0x28
/* C40798 802409E8 AFA20020 */  sw        $v0, 0x20($sp)
/* C4079C 802409EC E7A00010 */  swc1      $f0, 0x10($sp)
/* C407A0 802409F0 E7A20014 */  swc1      $f2, 0x14($sp)
/* C407A4 802409F4 0C01BFA4 */  jal       fx_emote
/* C407A8 802409F8 E7A40018 */   swc1     $f4, 0x18($sp)
/* C407AC 802409FC 8E4200CC */  lw        $v0, 0xcc($s2)
/* C407B0 80240A00 8C430000 */  lw        $v1, ($v0)
/* C407B4 80240A04 24020019 */  addiu     $v0, $zero, 0x19
/* C407B8 80240A08 A602008E */  sh        $v0, 0x8e($s0)
/* C407BC 80240A0C 2402000E */  addiu     $v0, $zero, 0xe
/* C407C0 80240A10 08090293 */  j         .L80240A4C
/* C407C4 80240A14 AE030028 */   sw       $v1, 0x28($s0)
.L80240A18:
/* C407C8 80240A18 0C00F598 */  jal       func_8003D660
/* C407CC 80240A1C 24050001 */   addiu    $a1, $zero, 1
/* C407D0 80240A20 8E050018 */  lw        $a1, 0x18($s0)
/* C407D4 80240A24 8E06000C */  lw        $a2, 0xc($s0)
/* C407D8 80240A28 0C00EA95 */  jal       npc_move_heading
/* C407DC 80240A2C 0200202D */   daddu    $a0, $s0, $zero
/* C407E0 80240A30 8602008E */  lh        $v0, 0x8e($s0)
/* C407E4 80240A34 9603008E */  lhu       $v1, 0x8e($s0)
/* C407E8 80240A38 18400003 */  blez      $v0, .L80240A48
/* C407EC 80240A3C 2462FFFF */   addiu    $v0, $v1, -1
/* C407F0 80240A40 08090294 */  j         .L80240A50
/* C407F4 80240A44 A602008E */   sh       $v0, 0x8e($s0)
.L80240A48:
/* C407F8 80240A48 2402000C */  addiu     $v0, $zero, 0xc
.L80240A4C:
/* C407FC 80240A4C AE620070 */  sw        $v0, 0x70($s3)
.L80240A50:
/* C40800 80240A50 8FBF0040 */  lw        $ra, 0x40($sp)
/* C40804 80240A54 8FB3003C */  lw        $s3, 0x3c($sp)
/* C40808 80240A58 8FB20038 */  lw        $s2, 0x38($sp)
/* C4080C 80240A5C 8FB10034 */  lw        $s1, 0x34($sp)
/* C40810 80240A60 8FB00030 */  lw        $s0, 0x30($sp)
/* C40814 80240A64 03E00008 */  jr        $ra
/* C40818 80240A68 27BD0048 */   addiu    $sp, $sp, 0x48
