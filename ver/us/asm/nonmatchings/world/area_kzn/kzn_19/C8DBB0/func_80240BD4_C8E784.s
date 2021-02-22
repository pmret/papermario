.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD4_C8E784
/* C8E784 80240BD4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C8E788 80240BD8 AFB10014 */  sw        $s1, 0x14($sp)
/* C8E78C 80240BDC 0080882D */  daddu     $s1, $a0, $zero
/* C8E790 80240BE0 AFBF0024 */  sw        $ra, 0x24($sp)
/* C8E794 80240BE4 AFB40020 */  sw        $s4, 0x20($sp)
/* C8E798 80240BE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* C8E79C 80240BEC AFB20018 */  sw        $s2, 0x18($sp)
/* C8E7A0 80240BF0 AFB00010 */  sw        $s0, 0x10($sp)
/* C8E7A4 80240BF4 8E30000C */  lw        $s0, 0xc($s1)
/* C8E7A8 80240BF8 8E050000 */  lw        $a1, ($s0)
/* C8E7AC 80240BFC 0C0B1EAF */  jal       get_variable
/* C8E7B0 80240C00 26100004 */   addiu    $s0, $s0, 4
/* C8E7B4 80240C04 8E050000 */  lw        $a1, ($s0)
/* C8E7B8 80240C08 26100004 */  addiu     $s0, $s0, 4
/* C8E7BC 80240C0C 0220202D */  daddu     $a0, $s1, $zero
/* C8E7C0 80240C10 0C0B1EAF */  jal       get_variable
/* C8E7C4 80240C14 0040982D */   daddu    $s3, $v0, $zero
/* C8E7C8 80240C18 8E050000 */  lw        $a1, ($s0)
/* C8E7CC 80240C1C 26100004 */  addiu     $s0, $s0, 4
/* C8E7D0 80240C20 0220202D */  daddu     $a0, $s1, $zero
/* C8E7D4 80240C24 0C0B1EAF */  jal       get_variable
/* C8E7D8 80240C28 0040902D */   daddu    $s2, $v0, $zero
/* C8E7DC 80240C2C 8E050000 */  lw        $a1, ($s0)
/* C8E7E0 80240C30 26100004 */  addiu     $s0, $s0, 4
/* C8E7E4 80240C34 0220202D */  daddu     $a0, $s1, $zero
/* C8E7E8 80240C38 0C0B1EAF */  jal       get_variable
/* C8E7EC 80240C3C 0040A02D */   daddu    $s4, $v0, $zero
/* C8E7F0 80240C40 0220202D */  daddu     $a0, $s1, $zero
/* C8E7F4 80240C44 8E050000 */  lw        $a1, ($s0)
/* C8E7F8 80240C48 0C0B1EAF */  jal       get_variable
/* C8E7FC 80240C4C 0040882D */   daddu    $s1, $v0, $zero
/* C8E800 80240C50 0000202D */  daddu     $a0, $zero, $zero
/* C8E804 80240C54 3C05FD05 */  lui       $a1, 0xfd05
/* C8E808 80240C58 34A50F80 */  ori       $a1, $a1, 0xf80
/* C8E80C 80240C5C 0C0B1EAF */  jal       get_variable
/* C8E810 80240C60 0040802D */   daddu    $s0, $v0, $zero
/* C8E814 80240C64 00131900 */  sll       $v1, $s3, 4
/* C8E818 80240C68 00731823 */  subu      $v1, $v1, $s3
/* C8E81C 80240C6C 00031940 */  sll       $v1, $v1, 5
/* C8E820 80240C70 00432021 */  addu      $a0, $v0, $v1
/* C8E824 80240C74 24020002 */  addiu     $v0, $zero, 2
/* C8E828 80240C78 00121840 */  sll       $v1, $s2, 1
/* C8E82C 80240C7C 00721821 */  addu      $v1, $v1, $s2
/* C8E830 80240C80 00431804 */  sllv      $v1, $v1, $v0
/* C8E834 80240C84 00832021 */  addu      $a0, $a0, $v1
/* C8E838 80240C88 44940000 */  mtc1      $s4, $f0
/* C8E83C 80240C8C 00000000 */  nop
/* C8E840 80240C90 46800020 */  cvt.s.w   $f0, $f0
/* C8E844 80240C94 E4800000 */  swc1      $f0, ($a0)
/* C8E848 80240C98 44910000 */  mtc1      $s1, $f0
/* C8E84C 80240C9C 00000000 */  nop
/* C8E850 80240CA0 46800020 */  cvt.s.w   $f0, $f0
/* C8E854 80240CA4 E4800004 */  swc1      $f0, 4($a0)
/* C8E858 80240CA8 44900000 */  mtc1      $s0, $f0
/* C8E85C 80240CAC 00000000 */  nop
/* C8E860 80240CB0 46800020 */  cvt.s.w   $f0, $f0
/* C8E864 80240CB4 E4800008 */  swc1      $f0, 8($a0)
/* C8E868 80240CB8 8FBF0024 */  lw        $ra, 0x24($sp)
/* C8E86C 80240CBC 8FB40020 */  lw        $s4, 0x20($sp)
/* C8E870 80240CC0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C8E874 80240CC4 8FB20018 */  lw        $s2, 0x18($sp)
/* C8E878 80240CC8 8FB10014 */  lw        $s1, 0x14($sp)
/* C8E87C 80240CCC 8FB00010 */  lw        $s0, 0x10($sp)
/* C8E880 80240CD0 03E00008 */  jr        $ra
/* C8E884 80240CD4 27BD0028 */   addiu    $sp, $sp, 0x28
