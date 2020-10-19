.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427D0_DCF4A0
/* DCF4A0 802427D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DCF4A4 802427D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* DCF4A8 802427D8 0080982D */  daddu     $s3, $a0, $zero
/* DCF4AC 802427DC AFBF0020 */  sw        $ra, 0x20($sp)
/* DCF4B0 802427E0 AFB20018 */  sw        $s2, 0x18($sp)
/* DCF4B4 802427E4 AFB10014 */  sw        $s1, 0x14($sp)
/* DCF4B8 802427E8 AFB00010 */  sw        $s0, 0x10($sp)
/* DCF4BC 802427EC 8E720148 */  lw        $s2, 0x148($s3)
/* DCF4C0 802427F0 0C00EABB */  jal       get_npc_unsafe
/* DCF4C4 802427F4 86440008 */   lh       $a0, 8($s2)
/* DCF4C8 802427F8 86440008 */  lh        $a0, 8($s2)
/* DCF4CC 802427FC 0040882D */  daddu     $s1, $v0, $zero
/* DCF4D0 80242800 0C00FB3A */  jal       get_enemy
/* DCF4D4 80242804 24840001 */   addiu    $a0, $a0, 1
/* DCF4D8 80242808 0040802D */  daddu     $s0, $v0, $zero
/* DCF4DC 8024280C 0C00EABB */  jal       get_npc_unsafe
/* DCF4E0 80242810 86040008 */   lh       $a0, 8($s0)
/* DCF4E4 80242814 C62C0038 */  lwc1      $f12, 0x38($s1)
/* DCF4E8 80242818 C62E0040 */  lwc1      $f14, 0x40($s1)
/* DCF4EC 8024281C 8C460038 */  lw        $a2, 0x38($v0)
/* DCF4F0 80242820 0C00A720 */  jal       atan2
/* DCF4F4 80242824 8C470040 */   lw       $a3, 0x40($v0)
/* DCF4F8 80242828 E620000C */  swc1      $f0, 0xc($s1)
/* DCF4FC 8024282C 8E02006C */  lw        $v0, 0x6c($s0)
/* DCF500 80242830 14400008 */  bnez      $v0, .L80242854
/* DCF504 80242834 00000000 */   nop      
/* DCF508 80242838 8E4200CC */  lw        $v0, 0xcc($s2)
/* DCF50C 8024283C 8C420000 */  lw        $v0, ($v0)
/* DCF510 80242840 AE220028 */  sw        $v0, 0x28($s1)
/* DCF514 80242844 96420076 */  lhu       $v0, 0x76($s2)
/* DCF518 80242848 A622008E */  sh        $v0, 0x8e($s1)
/* DCF51C 8024284C 24020021 */  addiu     $v0, $zero, 0x21
/* DCF520 80242850 AE620070 */  sw        $v0, 0x70($s3)
.L80242854:
/* DCF524 80242854 8FBF0020 */  lw        $ra, 0x20($sp)
/* DCF528 80242858 8FB3001C */  lw        $s3, 0x1c($sp)
/* DCF52C 8024285C 8FB20018 */  lw        $s2, 0x18($sp)
/* DCF530 80242860 8FB10014 */  lw        $s1, 0x14($sp)
/* DCF534 80242864 8FB00010 */  lw        $s0, 0x10($sp)
/* DCF538 80242868 03E00008 */  jr        $ra
/* DCF53C 8024286C 27BD0028 */   addiu    $sp, $sp, 0x28
