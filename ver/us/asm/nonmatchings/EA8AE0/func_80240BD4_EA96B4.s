.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD4_EA96B4
/* EA96B4 80240BD4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA96B8 80240BD8 AFB10014 */  sw        $s1, 0x14($sp)
/* EA96BC 80240BDC 0080882D */  daddu     $s1, $a0, $zero
/* EA96C0 80240BE0 AFBF0024 */  sw        $ra, 0x24($sp)
/* EA96C4 80240BE4 AFB40020 */  sw        $s4, 0x20($sp)
/* EA96C8 80240BE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* EA96CC 80240BEC AFB20018 */  sw        $s2, 0x18($sp)
/* EA96D0 80240BF0 AFB00010 */  sw        $s0, 0x10($sp)
/* EA96D4 80240BF4 8E30000C */  lw        $s0, 0xc($s1)
/* EA96D8 80240BF8 8E050000 */  lw        $a1, ($s0)
/* EA96DC 80240BFC 0C0B53A3 */  jal       dead_get_variable
/* EA96E0 80240C00 26100004 */   addiu    $s0, $s0, 4
/* EA96E4 80240C04 8E050000 */  lw        $a1, ($s0)
/* EA96E8 80240C08 26100004 */  addiu     $s0, $s0, 4
/* EA96EC 80240C0C 0220202D */  daddu     $a0, $s1, $zero
/* EA96F0 80240C10 0C0B53A3 */  jal       dead_get_variable
/* EA96F4 80240C14 0040982D */   daddu    $s3, $v0, $zero
/* EA96F8 80240C18 8E050000 */  lw        $a1, ($s0)
/* EA96FC 80240C1C 26100004 */  addiu     $s0, $s0, 4
/* EA9700 80240C20 0220202D */  daddu     $a0, $s1, $zero
/* EA9704 80240C24 0C0B53A3 */  jal       dead_get_variable
/* EA9708 80240C28 0040902D */   daddu    $s2, $v0, $zero
/* EA970C 80240C2C 8E050000 */  lw        $a1, ($s0)
/* EA9710 80240C30 26100004 */  addiu     $s0, $s0, 4
/* EA9714 80240C34 0220202D */  daddu     $a0, $s1, $zero
/* EA9718 80240C38 0C0B53A3 */  jal       dead_get_variable
/* EA971C 80240C3C 0040A02D */   daddu    $s4, $v0, $zero
/* EA9720 80240C40 0220202D */  daddu     $a0, $s1, $zero
/* EA9724 80240C44 8E050000 */  lw        $a1, ($s0)
/* EA9728 80240C48 0C0B53A3 */  jal       dead_get_variable
/* EA972C 80240C4C 0040882D */   daddu    $s1, $v0, $zero
/* EA9730 80240C50 0000202D */  daddu     $a0, $zero, $zero
/* EA9734 80240C54 3C05FD05 */  lui       $a1, 0xfd05
/* EA9738 80240C58 34A50F80 */  ori       $a1, $a1, 0xf80
/* EA973C 80240C5C 0C0B53A3 */  jal       dead_get_variable
/* EA9740 80240C60 0040802D */   daddu    $s0, $v0, $zero
/* EA9744 80240C64 00131900 */  sll       $v1, $s3, 4
/* EA9748 80240C68 00731823 */  subu      $v1, $v1, $s3
/* EA974C 80240C6C 00031940 */  sll       $v1, $v1, 5
/* EA9750 80240C70 00432021 */  addu      $a0, $v0, $v1
/* EA9754 80240C74 24020002 */  addiu     $v0, $zero, 2
/* EA9758 80240C78 00121840 */  sll       $v1, $s2, 1
/* EA975C 80240C7C 00721821 */  addu      $v1, $v1, $s2
/* EA9760 80240C80 00431804 */  sllv      $v1, $v1, $v0
/* EA9764 80240C84 00832021 */  addu      $a0, $a0, $v1
/* EA9768 80240C88 44940000 */  mtc1      $s4, $f0
/* EA976C 80240C8C 00000000 */  nop
/* EA9770 80240C90 46800020 */  cvt.s.w   $f0, $f0
/* EA9774 80240C94 E4800000 */  swc1      $f0, ($a0)
/* EA9778 80240C98 44910000 */  mtc1      $s1, $f0
/* EA977C 80240C9C 00000000 */  nop
/* EA9780 80240CA0 46800020 */  cvt.s.w   $f0, $f0
/* EA9784 80240CA4 E4800004 */  swc1      $f0, 4($a0)
/* EA9788 80240CA8 44900000 */  mtc1      $s0, $f0
/* EA978C 80240CAC 00000000 */  nop
/* EA9790 80240CB0 46800020 */  cvt.s.w   $f0, $f0
/* EA9794 80240CB4 E4800008 */  swc1      $f0, 8($a0)
/* EA9798 80240CB8 8FBF0024 */  lw        $ra, 0x24($sp)
/* EA979C 80240CBC 8FB40020 */  lw        $s4, 0x20($sp)
/* EA97A0 80240CC0 8FB3001C */  lw        $s3, 0x1c($sp)
/* EA97A4 80240CC4 8FB20018 */  lw        $s2, 0x18($sp)
/* EA97A8 80240CC8 8FB10014 */  lw        $s1, 0x14($sp)
/* EA97AC 80240CCC 8FB00010 */  lw        $s0, 0x10($sp)
/* EA97B0 80240CD0 03E00008 */  jr        $ra
/* EA97B4 80240CD4 27BD0028 */   addiu    $sp, $sp, 0x28
