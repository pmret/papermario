.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240674_B02EF4
/* B02EF4 80240674 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B02EF8 80240678 AFB10014 */  sw        $s1, 0x14($sp)
/* B02EFC 8024067C 0080882D */  daddu     $s1, $a0, $zero
/* B02F00 80240680 AFBF0024 */  sw        $ra, 0x24($sp)
/* B02F04 80240684 AFB40020 */  sw        $s4, 0x20($sp)
/* B02F08 80240688 AFB3001C */  sw        $s3, 0x1c($sp)
/* B02F0C 8024068C AFB20018 */  sw        $s2, 0x18($sp)
/* B02F10 80240690 AFB00010 */  sw        $s0, 0x10($sp)
/* B02F14 80240694 8E30000C */  lw        $s0, 0xc($s1)
/* B02F18 80240698 8E140000 */  lw        $s4, ($s0)
/* B02F1C 8024069C 26100004 */  addiu     $s0, $s0, 4
/* B02F20 802406A0 8E050000 */  lw        $a1, ($s0)
/* B02F24 802406A4 0C0B1EAF */  jal       evt_get_variable
/* B02F28 802406A8 26100004 */   addiu    $s0, $s0, 4
/* B02F2C 802406AC 8E050000 */  lw        $a1, ($s0)
/* B02F30 802406B0 26100004 */  addiu     $s0, $s0, 4
/* B02F34 802406B4 0220202D */  daddu     $a0, $s1, $zero
/* B02F38 802406B8 0C0B1EAF */  jal       evt_get_variable
/* B02F3C 802406BC 0040982D */   daddu    $s3, $v0, $zero
/* B02F40 802406C0 8E050000 */  lw        $a1, ($s0)
/* B02F44 802406C4 26100004 */  addiu     $s0, $s0, 4
/* B02F48 802406C8 0220202D */  daddu     $a0, $s1, $zero
/* B02F4C 802406CC 0C0B1EAF */  jal       evt_get_variable
/* B02F50 802406D0 0040902D */   daddu    $s2, $v0, $zero
/* B02F54 802406D4 0220202D */  daddu     $a0, $s1, $zero
/* B02F58 802406D8 8E050000 */  lw        $a1, ($s0)
/* B02F5C 802406DC 0C0B1EAF */  jal       evt_get_variable
/* B02F60 802406E0 0040802D */   daddu    $s0, $v0, $zero
/* B02F64 802406E4 44901000 */  mtc1      $s0, $f2
/* B02F68 802406E8 00000000 */  nop
/* B02F6C 802406EC 468010A0 */  cvt.s.w   $f2, $f2
/* B02F70 802406F0 44936000 */  mtc1      $s3, $f12
/* B02F74 802406F4 00000000 */  nop
/* B02F78 802406F8 46806320 */  cvt.s.w   $f12, $f12
/* B02F7C 802406FC 44061000 */  mfc1      $a2, $f2
/* B02F80 80240700 44821000 */  mtc1      $v0, $f2
/* B02F84 80240704 00000000 */  nop
/* B02F88 80240708 468010A0 */  cvt.s.w   $f2, $f2
/* B02F8C 8024070C 44071000 */  mfc1      $a3, $f2
/* B02F90 80240710 44927000 */  mtc1      $s2, $f14
/* B02F94 80240714 00000000 */  nop
/* B02F98 80240718 0C00A720 */  jal       atan2
/* B02F9C 8024071C 468073A0 */   cvt.s.w  $f14, $f14
/* B02FA0 80240720 0220202D */  daddu     $a0, $s1, $zero
/* B02FA4 80240724 4600008D */  trunc.w.s $f2, $f0
/* B02FA8 80240728 44061000 */  mfc1      $a2, $f2
/* B02FAC 8024072C 0C0B2026 */  jal       evt_set_variable
/* B02FB0 80240730 0280282D */   daddu    $a1, $s4, $zero
/* B02FB4 80240734 8FBF0024 */  lw        $ra, 0x24($sp)
/* B02FB8 80240738 8FB40020 */  lw        $s4, 0x20($sp)
/* B02FBC 8024073C 8FB3001C */  lw        $s3, 0x1c($sp)
/* B02FC0 80240740 8FB20018 */  lw        $s2, 0x18($sp)
/* B02FC4 80240744 8FB10014 */  lw        $s1, 0x14($sp)
/* B02FC8 80240748 8FB00010 */  lw        $s0, 0x10($sp)
/* B02FCC 8024074C 24020002 */  addiu     $v0, $zero, 2
/* B02FD0 80240750 03E00008 */  jr        $ra
/* B02FD4 80240754 27BD0028 */   addiu    $sp, $sp, 0x28
