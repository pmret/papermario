.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240844_D9B734
/* D9B734 80240844 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D9B738 80240848 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9B73C 8024084C 0080982D */  daddu     $s3, $a0, $zero
/* D9B740 80240850 AFBF0040 */  sw        $ra, 0x40($sp)
/* D9B744 80240854 AFB20038 */  sw        $s2, 0x38($sp)
/* D9B748 80240858 AFB10034 */  sw        $s1, 0x34($sp)
/* D9B74C 8024085C AFB00030 */  sw        $s0, 0x30($sp)
/* D9B750 80240860 8E720148 */  lw        $s2, 0x148($s3)
/* D9B754 80240864 00A0882D */  daddu     $s1, $a1, $zero
/* D9B758 80240868 86440008 */  lh        $a0, 8($s2)
/* D9B75C 8024086C 0C00EABB */  jal       get_npc_unsafe
/* D9B760 80240870 00C0802D */   daddu    $s0, $a2, $zero
/* D9B764 80240874 0200202D */  daddu     $a0, $s0, $zero
/* D9B768 80240878 0240282D */  daddu     $a1, $s2, $zero
/* D9B76C 8024087C 24030001 */  addiu     $v1, $zero, 1
/* D9B770 80240880 AFA30010 */  sw        $v1, 0x10($sp)
/* D9B774 80240884 8E260024 */  lw        $a2, 0x24($s1)
/* D9B778 80240888 8E270028 */  lw        $a3, 0x28($s1)
/* D9B77C 8024088C 0C01242D */  jal       func_800490B4
/* D9B780 80240890 0040802D */   daddu    $s0, $v0, $zero
/* D9B784 80240894 1440001D */  bnez      $v0, .L8024090C
/* D9B788 80240898 24040002 */   addiu    $a0, $zero, 2
/* D9B78C 8024089C 0200282D */  daddu     $a1, $s0, $zero
/* D9B790 802408A0 0000302D */  daddu     $a2, $zero, $zero
/* D9B794 802408A4 860300A8 */  lh        $v1, 0xa8($s0)
/* D9B798 802408A8 3C013F80 */  lui       $at, 0x3f80
/* D9B79C 802408AC 44810000 */  mtc1      $at, $f0
/* D9B7A0 802408B0 3C014000 */  lui       $at, 0x4000
/* D9B7A4 802408B4 44811000 */  mtc1      $at, $f2
/* D9B7A8 802408B8 3C01C1A0 */  lui       $at, 0xc1a0
/* D9B7AC 802408BC 44812000 */  mtc1      $at, $f4
/* D9B7B0 802408C0 2402000F */  addiu     $v0, $zero, 0xf
/* D9B7B4 802408C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* D9B7B8 802408C8 44833000 */  mtc1      $v1, $f6
/* D9B7BC 802408CC 00000000 */  nop
/* D9B7C0 802408D0 468031A0 */  cvt.s.w   $f6, $f6
/* D9B7C4 802408D4 44073000 */  mfc1      $a3, $f6
/* D9B7C8 802408D8 27A20028 */  addiu     $v0, $sp, 0x28
/* D9B7CC 802408DC AFA20020 */  sw        $v0, 0x20($sp)
/* D9B7D0 802408E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* D9B7D4 802408E4 E7A20014 */  swc1      $f2, 0x14($sp)
/* D9B7D8 802408E8 0C01BFA4 */  jal       fx_emote
/* D9B7DC 802408EC E7A40018 */   swc1     $f4, 0x18($sp)
/* D9B7E0 802408F0 8E4200CC */  lw        $v0, 0xcc($s2)
/* D9B7E4 802408F4 8C430000 */  lw        $v1, ($v0)
/* D9B7E8 802408F8 24020019 */  addiu     $v0, $zero, 0x19
/* D9B7EC 802408FC A602008E */  sh        $v0, 0x8e($s0)
/* D9B7F0 80240900 2402000E */  addiu     $v0, $zero, 0xe
/* D9B7F4 80240904 08090262 */  j         .L80240988
/* D9B7F8 80240908 AE030028 */   sw       $v1, 0x28($s0)
.L8024090C:
/* D9B7FC 8024090C 8E4200CC */  lw        $v0, 0xcc($s2)
/* D9B800 80240910 8E030028 */  lw        $v1, 0x28($s0)
/* D9B804 80240914 8C420020 */  lw        $v0, 0x20($v0)
/* D9B808 80240918 10620014 */  beq       $v1, $v0, .L8024096C
/* D9B80C 8024091C 00000000 */   nop
/* D9B810 80240920 C6000018 */  lwc1      $f0, 0x18($s0)
/* D9B814 80240924 3C014010 */  lui       $at, 0x4010
/* D9B818 80240928 44811800 */  mtc1      $at, $f3
/* D9B81C 8024092C 44801000 */  mtc1      $zero, $f2
/* D9B820 80240930 46000021 */  cvt.d.s   $f0, $f0
/* D9B824 80240934 4622003C */  c.lt.d    $f0, $f2
/* D9B828 80240938 00000000 */  nop
/* D9B82C 8024093C 45000003 */  bc1f      .L8024094C
/* D9B830 80240940 0000282D */   daddu    $a1, $zero, $zero
/* D9B834 80240944 08090255 */  j         .L80240954
/* D9B838 80240948 0200202D */   daddu    $a0, $s0, $zero
.L8024094C:
/* D9B83C 8024094C 0200202D */  daddu     $a0, $s0, $zero
/* D9B840 80240950 24050001 */  addiu     $a1, $zero, 1
.L80240954:
/* D9B844 80240954 0C00F598 */  jal       func_8003D660
/* D9B848 80240958 00000000 */   nop
/* D9B84C 8024095C 8E050018 */  lw        $a1, 0x18($s0)
/* D9B850 80240960 8E06000C */  lw        $a2, 0xc($s0)
/* D9B854 80240964 0C00EA95 */  jal       npc_move_heading
/* D9B858 80240968 0200202D */   daddu    $a0, $s0, $zero
.L8024096C:
/* D9B85C 8024096C 8602008E */  lh        $v0, 0x8e($s0)
/* D9B860 80240970 9603008E */  lhu       $v1, 0x8e($s0)
/* D9B864 80240974 18400003 */  blez      $v0, .L80240984
/* D9B868 80240978 2462FFFF */   addiu    $v0, $v1, -1
/* D9B86C 8024097C 08090263 */  j         .L8024098C
/* D9B870 80240980 A602008E */   sh       $v0, 0x8e($s0)
.L80240984:
/* D9B874 80240984 2402000C */  addiu     $v0, $zero, 0xc
.L80240988:
/* D9B878 80240988 AE620070 */  sw        $v0, 0x70($s3)
.L8024098C:
/* D9B87C 8024098C 8FBF0040 */  lw        $ra, 0x40($sp)
/* D9B880 80240990 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9B884 80240994 8FB20038 */  lw        $s2, 0x38($sp)
/* D9B888 80240998 8FB10034 */  lw        $s1, 0x34($sp)
/* D9B88C 8024099C 8FB00030 */  lw        $s0, 0x30($sp)
/* D9B890 802409A0 03E00008 */  jr        $ra
/* D9B894 802409A4 27BD0048 */   addiu    $sp, $sp, 0x48
