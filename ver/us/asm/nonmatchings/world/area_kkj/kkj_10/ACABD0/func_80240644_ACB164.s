.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240644_ACB164
/* ACB164 80240644 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ACB168 80240648 AFB10014 */  sw        $s1, 0x14($sp)
/* ACB16C 8024064C 0080882D */  daddu     $s1, $a0, $zero
/* ACB170 80240650 AFBF0024 */  sw        $ra, 0x24($sp)
/* ACB174 80240654 AFB40020 */  sw        $s4, 0x20($sp)
/* ACB178 80240658 AFB3001C */  sw        $s3, 0x1c($sp)
/* ACB17C 8024065C AFB20018 */  sw        $s2, 0x18($sp)
/* ACB180 80240660 AFB00010 */  sw        $s0, 0x10($sp)
/* ACB184 80240664 8E30000C */  lw        $s0, 0xc($s1)
/* ACB188 80240668 8E140000 */  lw        $s4, ($s0)
/* ACB18C 8024066C 26100004 */  addiu     $s0, $s0, 4
/* ACB190 80240670 8E050000 */  lw        $a1, ($s0)
/* ACB194 80240674 0C0B1EAF */  jal       evt_get_variable
/* ACB198 80240678 26100004 */   addiu    $s0, $s0, 4
/* ACB19C 8024067C 8E050000 */  lw        $a1, ($s0)
/* ACB1A0 80240680 26100004 */  addiu     $s0, $s0, 4
/* ACB1A4 80240684 0220202D */  daddu     $a0, $s1, $zero
/* ACB1A8 80240688 0C0B1EAF */  jal       evt_get_variable
/* ACB1AC 8024068C 0040982D */   daddu    $s3, $v0, $zero
/* ACB1B0 80240690 8E050000 */  lw        $a1, ($s0)
/* ACB1B4 80240694 26100004 */  addiu     $s0, $s0, 4
/* ACB1B8 80240698 0220202D */  daddu     $a0, $s1, $zero
/* ACB1BC 8024069C 0C0B1EAF */  jal       evt_get_variable
/* ACB1C0 802406A0 0040902D */   daddu    $s2, $v0, $zero
/* ACB1C4 802406A4 0220202D */  daddu     $a0, $s1, $zero
/* ACB1C8 802406A8 8E050000 */  lw        $a1, ($s0)
/* ACB1CC 802406AC 0C0B1EAF */  jal       evt_get_variable
/* ACB1D0 802406B0 0040802D */   daddu    $s0, $v0, $zero
/* ACB1D4 802406B4 44901000 */  mtc1      $s0, $f2
/* ACB1D8 802406B8 00000000 */  nop
/* ACB1DC 802406BC 468010A0 */  cvt.s.w   $f2, $f2
/* ACB1E0 802406C0 44936000 */  mtc1      $s3, $f12
/* ACB1E4 802406C4 00000000 */  nop
/* ACB1E8 802406C8 46806320 */  cvt.s.w   $f12, $f12
/* ACB1EC 802406CC 44061000 */  mfc1      $a2, $f2
/* ACB1F0 802406D0 44821000 */  mtc1      $v0, $f2
/* ACB1F4 802406D4 00000000 */  nop
/* ACB1F8 802406D8 468010A0 */  cvt.s.w   $f2, $f2
/* ACB1FC 802406DC 44071000 */  mfc1      $a3, $f2
/* ACB200 802406E0 44927000 */  mtc1      $s2, $f14
/* ACB204 802406E4 00000000 */  nop
/* ACB208 802406E8 0C00A720 */  jal       atan2
/* ACB20C 802406EC 468073A0 */   cvt.s.w  $f14, $f14
/* ACB210 802406F0 0220202D */  daddu     $a0, $s1, $zero
/* ACB214 802406F4 4600008D */  trunc.w.s $f2, $f0
/* ACB218 802406F8 44061000 */  mfc1      $a2, $f2
/* ACB21C 802406FC 0C0B2026 */  jal       evt_set_variable
/* ACB220 80240700 0280282D */   daddu    $a1, $s4, $zero
/* ACB224 80240704 8FBF0024 */  lw        $ra, 0x24($sp)
/* ACB228 80240708 8FB40020 */  lw        $s4, 0x20($sp)
/* ACB22C 8024070C 8FB3001C */  lw        $s3, 0x1c($sp)
/* ACB230 80240710 8FB20018 */  lw        $s2, 0x18($sp)
/* ACB234 80240714 8FB10014 */  lw        $s1, 0x14($sp)
/* ACB238 80240718 8FB00010 */  lw        $s0, 0x10($sp)
/* ACB23C 8024071C 24020002 */  addiu     $v0, $zero, 2
/* ACB240 80240720 03E00008 */  jr        $ra
/* ACB244 80240724 27BD0028 */   addiu    $sp, $sp, 0x28
