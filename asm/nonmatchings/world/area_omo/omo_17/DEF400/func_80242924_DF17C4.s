.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242924_DF17C4
/* DF17C4 80242924 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DF17C8 80242928 AFB3001C */  sw        $s3, 0x1c($sp)
/* DF17CC 8024292C 0080982D */  daddu     $s3, $a0, $zero
/* DF17D0 80242930 AFBF0020 */  sw        $ra, 0x20($sp)
/* DF17D4 80242934 AFB20018 */  sw        $s2, 0x18($sp)
/* DF17D8 80242938 AFB10014 */  sw        $s1, 0x14($sp)
/* DF17DC 8024293C AFB00010 */  sw        $s0, 0x10($sp)
/* DF17E0 80242940 8E720148 */  lw        $s2, 0x148($s3)
/* DF17E4 80242944 0C00EABB */  jal       get_npc_unsafe
/* DF17E8 80242948 86440008 */   lh       $a0, 8($s2)
/* DF17EC 8024294C 86440008 */  lh        $a0, 8($s2)
/* DF17F0 80242950 0040882D */  daddu     $s1, $v0, $zero
/* DF17F4 80242954 0C00FB3A */  jal       get_enemy
/* DF17F8 80242958 24840001 */   addiu    $a0, $a0, 1
/* DF17FC 8024295C 0040802D */  daddu     $s0, $v0, $zero
/* DF1800 80242960 0C00EABB */  jal       get_npc_unsafe
/* DF1804 80242964 86040008 */   lh       $a0, 8($s0)
/* DF1808 80242968 C62C0038 */  lwc1      $f12, 0x38($s1)
/* DF180C 8024296C C62E0040 */  lwc1      $f14, 0x40($s1)
/* DF1810 80242970 8C460038 */  lw        $a2, 0x38($v0)
/* DF1814 80242974 0C00A720 */  jal       atan2
/* DF1818 80242978 8C470040 */   lw       $a3, 0x40($v0)
/* DF181C 8024297C E620000C */  swc1      $f0, 0xc($s1)
/* DF1820 80242980 8E02006C */  lw        $v0, 0x6c($s0)
/* DF1824 80242984 14400008 */  bnez      $v0, .L802429A8
/* DF1828 80242988 00000000 */   nop      
/* DF182C 8024298C 8E4200CC */  lw        $v0, 0xcc($s2)
/* DF1830 80242990 8C420000 */  lw        $v0, ($v0)
/* DF1834 80242994 AE220028 */  sw        $v0, 0x28($s1)
/* DF1838 80242998 96420076 */  lhu       $v0, 0x76($s2)
/* DF183C 8024299C A622008E */  sh        $v0, 0x8e($s1)
/* DF1840 802429A0 24020021 */  addiu     $v0, $zero, 0x21
/* DF1844 802429A4 AE620070 */  sw        $v0, 0x70($s3)
.L802429A8:
/* DF1848 802429A8 8FBF0020 */  lw        $ra, 0x20($sp)
/* DF184C 802429AC 8FB3001C */  lw        $s3, 0x1c($sp)
/* DF1850 802429B0 8FB20018 */  lw        $s2, 0x18($sp)
/* DF1854 802429B4 8FB10014 */  lw        $s1, 0x14($sp)
/* DF1858 802429B8 8FB00010 */  lw        $s0, 0x10($sp)
/* DF185C 802429BC 03E00008 */  jr        $ra
/* DF1860 802429C0 27BD0028 */   addiu    $sp, $sp, 0x28
