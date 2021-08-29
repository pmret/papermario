.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240644_ACE784
/* ACE784 80240644 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ACE788 80240648 AFB10014 */  sw        $s1, 0x14($sp)
/* ACE78C 8024064C 0080882D */  daddu     $s1, $a0, $zero
/* ACE790 80240650 AFBF0024 */  sw        $ra, 0x24($sp)
/* ACE794 80240654 AFB40020 */  sw        $s4, 0x20($sp)
/* ACE798 80240658 AFB3001C */  sw        $s3, 0x1c($sp)
/* ACE79C 8024065C AFB20018 */  sw        $s2, 0x18($sp)
/* ACE7A0 80240660 AFB00010 */  sw        $s0, 0x10($sp)
/* ACE7A4 80240664 8E30000C */  lw        $s0, 0xc($s1)
/* ACE7A8 80240668 8E140000 */  lw        $s4, ($s0)
/* ACE7AC 8024066C 26100004 */  addiu     $s0, $s0, 4
/* ACE7B0 80240670 8E050000 */  lw        $a1, ($s0)
/* ACE7B4 80240674 0C0B1EAF */  jal       get_variable
/* ACE7B8 80240678 26100004 */   addiu    $s0, $s0, 4
/* ACE7BC 8024067C 8E050000 */  lw        $a1, ($s0)
/* ACE7C0 80240680 26100004 */  addiu     $s0, $s0, 4
/* ACE7C4 80240684 0220202D */  daddu     $a0, $s1, $zero
/* ACE7C8 80240688 0C0B1EAF */  jal       get_variable
/* ACE7CC 8024068C 0040982D */   daddu    $s3, $v0, $zero
/* ACE7D0 80240690 8E050000 */  lw        $a1, ($s0)
/* ACE7D4 80240694 26100004 */  addiu     $s0, $s0, 4
/* ACE7D8 80240698 0220202D */  daddu     $a0, $s1, $zero
/* ACE7DC 8024069C 0C0B1EAF */  jal       get_variable
/* ACE7E0 802406A0 0040902D */   daddu    $s2, $v0, $zero
/* ACE7E4 802406A4 0220202D */  daddu     $a0, $s1, $zero
/* ACE7E8 802406A8 8E050000 */  lw        $a1, ($s0)
/* ACE7EC 802406AC 0C0B1EAF */  jal       get_variable
/* ACE7F0 802406B0 0040802D */   daddu    $s0, $v0, $zero
/* ACE7F4 802406B4 44901000 */  mtc1      $s0, $f2
/* ACE7F8 802406B8 00000000 */  nop
/* ACE7FC 802406BC 468010A0 */  cvt.s.w   $f2, $f2
/* ACE800 802406C0 44936000 */  mtc1      $s3, $f12
/* ACE804 802406C4 00000000 */  nop
/* ACE808 802406C8 46806320 */  cvt.s.w   $f12, $f12
/* ACE80C 802406CC 44061000 */  mfc1      $a2, $f2
/* ACE810 802406D0 44821000 */  mtc1      $v0, $f2
/* ACE814 802406D4 00000000 */  nop
/* ACE818 802406D8 468010A0 */  cvt.s.w   $f2, $f2
/* ACE81C 802406DC 44071000 */  mfc1      $a3, $f2
/* ACE820 802406E0 44927000 */  mtc1      $s2, $f14
/* ACE824 802406E4 00000000 */  nop
/* ACE828 802406E8 0C00A720 */  jal       atan2
/* ACE82C 802406EC 468073A0 */   cvt.s.w  $f14, $f14
/* ACE830 802406F0 0220202D */  daddu     $a0, $s1, $zero
/* ACE834 802406F4 4600008D */  trunc.w.s $f2, $f0
/* ACE838 802406F8 44061000 */  mfc1      $a2, $f2
/* ACE83C 802406FC 0C0B2026 */  jal       evt_set_variable
/* ACE840 80240700 0280282D */   daddu    $a1, $s4, $zero
/* ACE844 80240704 8FBF0024 */  lw        $ra, 0x24($sp)
/* ACE848 80240708 8FB40020 */  lw        $s4, 0x20($sp)
/* ACE84C 8024070C 8FB3001C */  lw        $s3, 0x1c($sp)
/* ACE850 80240710 8FB20018 */  lw        $s2, 0x18($sp)
/* ACE854 80240714 8FB10014 */  lw        $s1, 0x14($sp)
/* ACE858 80240718 8FB00010 */  lw        $s0, 0x10($sp)
/* ACE85C 8024071C 24020002 */  addiu     $v0, $zero, 2
/* ACE860 80240720 03E00008 */  jr        $ra
/* ACE864 80240724 27BD0028 */   addiu    $sp, $sp, 0x28
