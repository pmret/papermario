.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F4_AEDA04
/* AEDA04 802405F4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AEDA08 802405F8 AFB10014 */  sw        $s1, 0x14($sp)
/* AEDA0C 802405FC 0080882D */  daddu     $s1, $a0, $zero
/* AEDA10 80240600 AFBF0024 */  sw        $ra, 0x24($sp)
/* AEDA14 80240604 AFB40020 */  sw        $s4, 0x20($sp)
/* AEDA18 80240608 AFB3001C */  sw        $s3, 0x1c($sp)
/* AEDA1C 8024060C AFB20018 */  sw        $s2, 0x18($sp)
/* AEDA20 80240610 AFB00010 */  sw        $s0, 0x10($sp)
/* AEDA24 80240614 8E30000C */  lw        $s0, 0xc($s1)
/* AEDA28 80240618 8E140000 */  lw        $s4, ($s0)
/* AEDA2C 8024061C 26100004 */  addiu     $s0, $s0, 4
/* AEDA30 80240620 8E050000 */  lw        $a1, ($s0)
/* AEDA34 80240624 0C0B1EAF */  jal       get_variable
/* AEDA38 80240628 26100004 */   addiu    $s0, $s0, 4
/* AEDA3C 8024062C 8E050000 */  lw        $a1, ($s0)
/* AEDA40 80240630 26100004 */  addiu     $s0, $s0, 4
/* AEDA44 80240634 0220202D */  daddu     $a0, $s1, $zero
/* AEDA48 80240638 0C0B1EAF */  jal       get_variable
/* AEDA4C 8024063C 0040982D */   daddu    $s3, $v0, $zero
/* AEDA50 80240640 8E050000 */  lw        $a1, ($s0)
/* AEDA54 80240644 26100004 */  addiu     $s0, $s0, 4
/* AEDA58 80240648 0220202D */  daddu     $a0, $s1, $zero
/* AEDA5C 8024064C 0C0B1EAF */  jal       get_variable
/* AEDA60 80240650 0040902D */   daddu    $s2, $v0, $zero
/* AEDA64 80240654 0220202D */  daddu     $a0, $s1, $zero
/* AEDA68 80240658 8E050000 */  lw        $a1, ($s0)
/* AEDA6C 8024065C 0C0B1EAF */  jal       get_variable
/* AEDA70 80240660 0040802D */   daddu    $s0, $v0, $zero
/* AEDA74 80240664 44901000 */  mtc1      $s0, $f2
/* AEDA78 80240668 00000000 */  nop       
/* AEDA7C 8024066C 468010A0 */  cvt.s.w   $f2, $f2
/* AEDA80 80240670 44936000 */  mtc1      $s3, $f12
/* AEDA84 80240674 00000000 */  nop       
/* AEDA88 80240678 46806320 */  cvt.s.w   $f12, $f12
/* AEDA8C 8024067C 44061000 */  mfc1      $a2, $f2
/* AEDA90 80240680 44821000 */  mtc1      $v0, $f2
/* AEDA94 80240684 00000000 */  nop       
/* AEDA98 80240688 468010A0 */  cvt.s.w   $f2, $f2
/* AEDA9C 8024068C 44071000 */  mfc1      $a3, $f2
/* AEDAA0 80240690 44927000 */  mtc1      $s2, $f14
/* AEDAA4 80240694 00000000 */  nop       
/* AEDAA8 80240698 0C00A720 */  jal       atan2
/* AEDAAC 8024069C 468073A0 */   cvt.s.w  $f14, $f14
/* AEDAB0 802406A0 0220202D */  daddu     $a0, $s1, $zero
/* AEDAB4 802406A4 4600008D */  trunc.w.s $f2, $f0
/* AEDAB8 802406A8 44061000 */  mfc1      $a2, $f2
/* AEDABC 802406AC 0C0B2026 */  jal       set_variable
/* AEDAC0 802406B0 0280282D */   daddu    $a1, $s4, $zero
/* AEDAC4 802406B4 8FBF0024 */  lw        $ra, 0x24($sp)
/* AEDAC8 802406B8 8FB40020 */  lw        $s4, 0x20($sp)
/* AEDACC 802406BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* AEDAD0 802406C0 8FB20018 */  lw        $s2, 0x18($sp)
/* AEDAD4 802406C4 8FB10014 */  lw        $s1, 0x14($sp)
/* AEDAD8 802406C8 8FB00010 */  lw        $s0, 0x10($sp)
/* AEDADC 802406CC 24020002 */  addiu     $v0, $zero, 2
/* AEDAE0 802406D0 03E00008 */  jr        $ra
/* AEDAE4 802406D4 27BD0028 */   addiu    $sp, $sp, 0x28
