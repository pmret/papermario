.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800476F4
/* 022AF4 800476F4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 022AF8 800476F8 AFB00010 */  sw    $s0, 0x10($sp)
/* 022AFC 800476FC 0080802D */  daddu $s0, $a0, $zero
/* 022B00 80047700 00101040 */  sll   $v0, $s0, 1
/* 022B04 80047704 00501021 */  addu  $v0, $v0, $s0
/* 022B08 80047708 00021080 */  sll   $v0, $v0, 2
/* 022B0C 8004770C 00501023 */  subu  $v0, $v0, $s0
/* 022B10 80047710 AFB10014 */  sw    $s1, 0x14($sp)
/* 022B14 80047714 3C11800A */  lui   $s1, 0x800a
/* 022B18 80047718 8E310F44 */  lw    $s1, 0xf44($s1)
/* 022B1C 8004771C 00021100 */  sll   $v0, $v0, 4
/* 022B20 80047720 AFBF0018 */  sw    $ra, 0x18($sp)
/* 022B24 80047724 0C011E26 */  jal   func_80047898
/* 022B28 80047728 02228821 */   addu  $s1, $s1, $v0
/* 022B2C 8004772C 0C011E68 */  jal   func_800479A0
/* 022B30 80047730 0200202D */   daddu $a0, $s0, $zero
/* 022B34 80047734 0C011EAA */  jal   func_80047AA8
/* 022B38 80047738 0200202D */   daddu $a0, $s0, $zero
/* 022B3C 8004773C 0C011EE1 */  jal   func_80047B84
/* 022B40 80047740 0200202D */   daddu $a0, $s0, $zero
/* 022B44 80047744 0C011F29 */  jal   func_80047CA4
/* 022B48 80047748 0200202D */   daddu $a0, $s0, $zero
/* 022B4C 8004774C 0C011F70 */  jal   func_80047DC0
/* 022B50 80047750 0200202D */   daddu $a0, $s0, $zero
/* 022B54 80047754 0C011FB7 */  jal   func_80047EDC
/* 022B58 80047758 0200202D */   daddu $a0, $s0, $zero
/* 022B5C 8004775C 0C011FFA */  jal   func_80047FE8
/* 022B60 80047760 0200202D */   daddu $a0, $s0, $zero
/* 022B64 80047764 0C01203D */  jal   func_800480F4
/* 022B68 80047768 0200202D */   daddu $a0, $s0, $zero
/* 022B6C 8004776C 0C012080 */  jal   func_80048200
/* 022B70 80047770 0200202D */   daddu $a0, $s0, $zero
/* 022B74 80047774 AE200000 */  sw    $zero, ($s1)
/* 022B78 80047778 8FBF0018 */  lw    $ra, 0x18($sp)
/* 022B7C 8004777C 8FB10014 */  lw    $s1, 0x14($sp)
/* 022B80 80047780 8FB00010 */  lw    $s0, 0x10($sp)
/* 022B84 80047784 03E00008 */  jr    $ra
/* 022B88 80047788 27BD0020 */   addiu $sp, $sp, 0x20

