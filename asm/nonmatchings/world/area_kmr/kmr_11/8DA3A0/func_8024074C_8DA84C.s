.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024074C_8DA84C
/* 8DA84C 8024074C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8DA850 80240750 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8DA854 80240754 0080982D */  daddu     $s3, $a0, $zero
/* 8DA858 80240758 AFBF0040 */  sw        $ra, 0x40($sp)
/* 8DA85C 8024075C AFB20038 */  sw        $s2, 0x38($sp)
/* 8DA860 80240760 AFB10034 */  sw        $s1, 0x34($sp)
/* 8DA864 80240764 AFB00030 */  sw        $s0, 0x30($sp)
/* 8DA868 80240768 8E720148 */  lw        $s2, 0x148($s3)
/* 8DA86C 8024076C 00A0882D */  daddu     $s1, $a1, $zero
/* 8DA870 80240770 86440008 */  lh        $a0, 8($s2)
/* 8DA874 80240774 0C00EABB */  jal       get_npc_unsafe
/* 8DA878 80240778 00C0802D */   daddu    $s0, $a2, $zero
/* 8DA87C 8024077C 0200202D */  daddu     $a0, $s0, $zero
/* 8DA880 80240780 0240282D */  daddu     $a1, $s2, $zero
/* 8DA884 80240784 24030001 */  addiu     $v1, $zero, 1
/* 8DA888 80240788 AFA30010 */  sw        $v1, 0x10($sp)
/* 8DA88C 8024078C 8E260018 */  lw        $a2, 0x18($s1)
/* 8DA890 80240790 8E27001C */  lw        $a3, 0x1c($s1)
/* 8DA894 80240794 0C01242D */  jal       func_800490B4
/* 8DA898 80240798 0040802D */   daddu    $s0, $v0, $zero
/* 8DA89C 8024079C 1440001D */  bnez      $v0, .L80240814
/* 8DA8A0 802407A0 24040002 */   addiu    $a0, $zero, 2
/* 8DA8A4 802407A4 0200282D */  daddu     $a1, $s0, $zero
/* 8DA8A8 802407A8 0000302D */  daddu     $a2, $zero, $zero
/* 8DA8AC 802407AC 860300A8 */  lh        $v1, 0xa8($s0)
/* 8DA8B0 802407B0 3C013F80 */  lui       $at, 0x3f80
/* 8DA8B4 802407B4 44810000 */  mtc1      $at, $f0
/* 8DA8B8 802407B8 3C014000 */  lui       $at, 0x4000
/* 8DA8BC 802407BC 44811000 */  mtc1      $at, $f2
/* 8DA8C0 802407C0 3C01C1A0 */  lui       $at, 0xc1a0
/* 8DA8C4 802407C4 44812000 */  mtc1      $at, $f4
/* 8DA8C8 802407C8 2402000F */  addiu     $v0, $zero, 0xf
/* 8DA8CC 802407CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 8DA8D0 802407D0 44833000 */  mtc1      $v1, $f6
/* 8DA8D4 802407D4 00000000 */  nop       
/* 8DA8D8 802407D8 468031A0 */  cvt.s.w   $f6, $f6
/* 8DA8DC 802407DC 44073000 */  mfc1      $a3, $f6
/* 8DA8E0 802407E0 27A20028 */  addiu     $v0, $sp, 0x28
/* 8DA8E4 802407E4 AFA20020 */  sw        $v0, 0x20($sp)
/* 8DA8E8 802407E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8DA8EC 802407EC E7A20014 */  swc1      $f2, 0x14($sp)
/* 8DA8F0 802407F0 0C01BFA4 */  jal       fx_emote
/* 8DA8F4 802407F4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 8DA8F8 802407F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8DA8FC 802407FC 8C430000 */  lw        $v1, ($v0)
/* 8DA900 80240800 24020019 */  addiu     $v0, $zero, 0x19
/* 8DA904 80240804 A602008E */  sh        $v0, 0x8e($s0)
/* 8DA908 80240808 2402000E */  addiu     $v0, $zero, 0xe
/* 8DA90C 8024080C 08090212 */  j         .L80240848
/* 8DA910 80240810 AE030028 */   sw       $v1, 0x28($s0)
.L80240814:
/* 8DA914 80240814 8E050018 */  lw        $a1, 0x18($s0)
/* 8DA918 80240818 8E06000C */  lw        $a2, 0xc($s0)
/* 8DA91C 8024081C 0C00EA95 */  jal       npc_move_heading
/* 8DA920 80240820 0200202D */   daddu    $a0, $s0, $zero
/* 8DA924 80240824 0200202D */  daddu     $a0, $s0, $zero
/* 8DA928 80240828 0C00F598 */  jal       func_8003D660
/* 8DA92C 8024082C 24050001 */   addiu    $a1, $zero, 1
/* 8DA930 80240830 9602008E */  lhu       $v0, 0x8e($s0)
/* 8DA934 80240834 2442FFFF */  addiu     $v0, $v0, -1
/* 8DA938 80240838 A602008E */  sh        $v0, 0x8e($s0)
/* 8DA93C 8024083C 00021400 */  sll       $v0, $v0, 0x10
/* 8DA940 80240840 14400002 */  bnez      $v0, .L8024084C
/* 8DA944 80240844 2402000C */   addiu    $v0, $zero, 0xc
.L80240848:
/* 8DA948 80240848 AE620070 */  sw        $v0, 0x70($s3)
.L8024084C:
/* 8DA94C 8024084C 8FBF0040 */  lw        $ra, 0x40($sp)
/* 8DA950 80240850 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8DA954 80240854 8FB20038 */  lw        $s2, 0x38($sp)
/* 8DA958 80240858 8FB10034 */  lw        $s1, 0x34($sp)
/* 8DA95C 8024085C 8FB00030 */  lw        $s0, 0x30($sp)
/* 8DA960 80240860 03E00008 */  jr        $ra
/* 8DA964 80240864 27BD0048 */   addiu    $sp, $sp, 0x48
