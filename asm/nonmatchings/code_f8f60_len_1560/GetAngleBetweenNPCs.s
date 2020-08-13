.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetAngleBetweenNPCs
/* 0F90B8 802D4708 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F90BC 802D470C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F90C0 802D4710 0080902D */  daddu $s2, $a0, $zero
/* 0F90C4 802D4714 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F90C8 802D4718 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F90CC 802D471C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F90D0 802D4720 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F90D4 802D4724 8E50000C */  lw    $s0, 0xc($s2)
/* 0F90D8 802D4728 8E050000 */  lw    $a1, ($s0)
/* 0F90DC 802D472C 0C0B1EAF */  jal   get_variable
/* 0F90E0 802D4730 26100004 */   addiu $s0, $s0, 4
/* 0F90E4 802D4734 8E050000 */  lw    $a1, ($s0)
/* 0F90E8 802D4738 26100004 */  addiu $s0, $s0, 4
/* 0F90EC 802D473C 0240202D */  daddu $a0, $s2, $zero
/* 0F90F0 802D4740 0C0B1EAF */  jal   get_variable
/* 0F90F4 802D4744 0040882D */   daddu $s1, $v0, $zero
/* 0F90F8 802D4748 0240202D */  daddu $a0, $s2, $zero
/* 0F90FC 802D474C 0220282D */  daddu $a1, $s1, $zero
/* 0F9100 802D4750 8E130000 */  lw    $s3, ($s0)
/* 0F9104 802D4754 0C0B36B0 */  jal   func_802CDAC0
/* 0F9108 802D4758 0040882D */   daddu $s1, $v0, $zero
/* 0F910C 802D475C 0240202D */  daddu $a0, $s2, $zero
/* 0F9110 802D4760 0220282D */  daddu $a1, $s1, $zero
/* 0F9114 802D4764 0C0B36B0 */  jal   func_802CDAC0
/* 0F9118 802D4768 0040802D */   daddu $s0, $v0, $zero
/* 0F911C 802D476C 8C460038 */  lw    $a2, 0x38($v0)
/* 0F9120 802D4770 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F9124 802D4774 C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F9128 802D4778 0C00A720 */  jal   atan2
/* 0F912C 802D477C 8C470040 */   lw    $a3, 0x40($v0)
/* 0F9130 802D4780 0240202D */  daddu $a0, $s2, $zero
/* 0F9134 802D4784 4600008D */  trunc.w.s $f2, $f0
/* 0F9138 802D4788 44061000 */  mfc1  $a2, $f2
/* 0F913C 802D478C 0C0B2026 */  jal   set_variable
/* 0F9140 802D4790 0260282D */   daddu $a1, $s3, $zero
/* 0F9144 802D4794 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F9148 802D4798 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F914C 802D479C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9150 802D47A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9154 802D47A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F9158 802D47A8 24020002 */  addiu $v0, $zero, 2
/* 0F915C 802D47AC 03E00008 */  jr    $ra
/* 0F9160 802D47B0 27BD0028 */   addiu $sp, $sp, 0x28

