.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240604_AD4694
/* AD4694 80240604 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AD4698 80240608 AFB10014 */  sw        $s1, 0x14($sp)
/* AD469C 8024060C 0080882D */  daddu     $s1, $a0, $zero
/* AD46A0 80240610 AFBF0024 */  sw        $ra, 0x24($sp)
/* AD46A4 80240614 AFB40020 */  sw        $s4, 0x20($sp)
/* AD46A8 80240618 AFB3001C */  sw        $s3, 0x1c($sp)
/* AD46AC 8024061C AFB20018 */  sw        $s2, 0x18($sp)
/* AD46B0 80240620 AFB00010 */  sw        $s0, 0x10($sp)
/* AD46B4 80240624 8E30000C */  lw        $s0, 0xc($s1)
/* AD46B8 80240628 8E140000 */  lw        $s4, ($s0)
/* AD46BC 8024062C 26100004 */  addiu     $s0, $s0, 4
/* AD46C0 80240630 8E050000 */  lw        $a1, ($s0)
/* AD46C4 80240634 0C0B1EAF */  jal       get_variable
/* AD46C8 80240638 26100004 */   addiu    $s0, $s0, 4
/* AD46CC 8024063C 8E050000 */  lw        $a1, ($s0)
/* AD46D0 80240640 26100004 */  addiu     $s0, $s0, 4
/* AD46D4 80240644 0220202D */  daddu     $a0, $s1, $zero
/* AD46D8 80240648 0C0B1EAF */  jal       get_variable
/* AD46DC 8024064C 0040982D */   daddu    $s3, $v0, $zero
/* AD46E0 80240650 8E050000 */  lw        $a1, ($s0)
/* AD46E4 80240654 26100004 */  addiu     $s0, $s0, 4
/* AD46E8 80240658 0220202D */  daddu     $a0, $s1, $zero
/* AD46EC 8024065C 0C0B1EAF */  jal       get_variable
/* AD46F0 80240660 0040902D */   daddu    $s2, $v0, $zero
/* AD46F4 80240664 0220202D */  daddu     $a0, $s1, $zero
/* AD46F8 80240668 8E050000 */  lw        $a1, ($s0)
/* AD46FC 8024066C 0C0B1EAF */  jal       get_variable
/* AD4700 80240670 0040802D */   daddu    $s0, $v0, $zero
/* AD4704 80240674 44901000 */  mtc1      $s0, $f2
/* AD4708 80240678 00000000 */  nop
/* AD470C 8024067C 468010A0 */  cvt.s.w   $f2, $f2
/* AD4710 80240680 44936000 */  mtc1      $s3, $f12
/* AD4714 80240684 00000000 */  nop
/* AD4718 80240688 46806320 */  cvt.s.w   $f12, $f12
/* AD471C 8024068C 44061000 */  mfc1      $a2, $f2
/* AD4720 80240690 44821000 */  mtc1      $v0, $f2
/* AD4724 80240694 00000000 */  nop
/* AD4728 80240698 468010A0 */  cvt.s.w   $f2, $f2
/* AD472C 8024069C 44071000 */  mfc1      $a3, $f2
/* AD4730 802406A0 44927000 */  mtc1      $s2, $f14
/* AD4734 802406A4 00000000 */  nop
/* AD4738 802406A8 0C00A720 */  jal       atan2
/* AD473C 802406AC 468073A0 */   cvt.s.w  $f14, $f14
/* AD4740 802406B0 0220202D */  daddu     $a0, $s1, $zero
/* AD4744 802406B4 4600008D */  trunc.w.s $f2, $f0
/* AD4748 802406B8 44061000 */  mfc1      $a2, $f2
/* AD474C 802406BC 0C0B2026 */  jal       set_variable
/* AD4750 802406C0 0280282D */   daddu    $a1, $s4, $zero
/* AD4754 802406C4 8FBF0024 */  lw        $ra, 0x24($sp)
/* AD4758 802406C8 8FB40020 */  lw        $s4, 0x20($sp)
/* AD475C 802406CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* AD4760 802406D0 8FB20018 */  lw        $s2, 0x18($sp)
/* AD4764 802406D4 8FB10014 */  lw        $s1, 0x14($sp)
/* AD4768 802406D8 8FB00010 */  lw        $s0, 0x10($sp)
/* AD476C 802406DC 24020002 */  addiu     $v0, $zero, 2
/* AD4770 802406E0 03E00008 */  jr        $ra
/* AD4774 802406E4 27BD0028 */   addiu    $sp, $sp, 0x28
