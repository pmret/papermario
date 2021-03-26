.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240638_C7E7B8
/* C7E7B8 80240638 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C7E7BC 8024063C AFB1001C */  sw        $s1, 0x1c($sp)
/* C7E7C0 80240640 0080882D */  daddu     $s1, $a0, $zero
/* C7E7C4 80240644 AFBF0020 */  sw        $ra, 0x20($sp)
/* C7E7C8 80240648 AFB00018 */  sw        $s0, 0x18($sp)
/* C7E7CC 8024064C 8E30000C */  lw        $s0, 0xc($s1)
/* C7E7D0 80240650 8E050000 */  lw        $a1, ($s0)
/* C7E7D4 80240654 0C0B1EAF */  jal       get_variable
/* C7E7D8 80240658 26100004 */   addiu    $s0, $s0, 4
/* C7E7DC 8024065C AE220070 */  sw        $v0, 0x70($s1)
/* C7E7E0 80240660 8E050000 */  lw        $a1, ($s0)
/* C7E7E4 80240664 26100004 */  addiu     $s0, $s0, 4
/* C7E7E8 80240668 0C0B1EAF */  jal       get_variable
/* C7E7EC 8024066C 0220202D */   daddu    $a0, $s1, $zero
/* C7E7F0 80240670 AE220074 */  sw        $v0, 0x74($s1)
/* C7E7F4 80240674 8E050000 */  lw        $a1, ($s0)
/* C7E7F8 80240678 0C0B1EAF */  jal       get_variable
/* C7E7FC 8024067C 0220202D */   daddu    $a0, $s1, $zero
/* C7E800 80240680 24040052 */  addiu     $a0, $zero, 0x52
/* C7E804 80240684 0000282D */  daddu     $a1, $zero, $zero
/* C7E808 80240688 C6200070 */  lwc1      $f0, 0x70($s1)
/* C7E80C 8024068C 46800020 */  cvt.s.w   $f0, $f0
/* C7E810 80240690 C6220074 */  lwc1      $f2, 0x74($s1)
/* C7E814 80240694 468010A0 */  cvt.s.w   $f2, $f2
/* C7E818 80240698 44060000 */  mfc1      $a2, $f0
/* C7E81C 8024069C 44071000 */  mfc1      $a3, $f2
/* C7E820 802406A0 44820000 */  mtc1      $v0, $f0
/* C7E824 802406A4 00000000 */  nop
/* C7E828 802406A8 46800020 */  cvt.s.w   $f0, $f0
/* C7E82C 802406AC AE220078 */  sw        $v0, 0x78($s1)
/* C7E830 802406B0 0C05267B */  jal       sfx_adjust_env_sound_pos
/* C7E834 802406B4 E7A00010 */   swc1     $f0, 0x10($sp)
/* C7E838 802406B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* C7E83C 802406BC 8FB1001C */  lw        $s1, 0x1c($sp)
/* C7E840 802406C0 8FB00018 */  lw        $s0, 0x18($sp)
/* C7E844 802406C4 24020002 */  addiu     $v0, $zero, 2
/* C7E848 802406C8 03E00008 */  jr        $ra
/* C7E84C 802406CC 27BD0028 */   addiu    $sp, $sp, 0x28
