.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel _set_music_track
/* 0E0EE0 8014A7E0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E0EE4 8014A7E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E0EE8 8014A7E8 00A0902D */  daddu $s2, $a1, $zero
/* 0E0EEC 8014A7EC 3C058007 */  lui   $a1, 0x8007
/* 0E0EF0 8014A7F0 8CA5419C */  lw    $a1, 0x419c($a1)
/* 0E0EF4 8014A7F4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0E0EF8 8014A7F8 8FB30040 */  lw    $s3, 0x40($sp)
/* 0E0EFC 8014A7FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E0F00 8014A800 00C0882D */  daddu $s1, $a2, $zero
/* 0E0F04 8014A804 AFB50024 */  sw    $s5, 0x24($sp)
/* 0E0F08 8014A808 00E0A82D */  daddu $s5, $a3, $zero
/* 0E0F0C 8014A80C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0E0F10 8014A810 AFB40020 */  sw    $s4, 0x20($sp)
/* 0E0F14 8014A814 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E0F18 8014A818 80A20071 */  lb    $v0, 0x71($a1)
/* 0E0F1C 8014A81C 10400003 */  beqz  $v0, .L8014A82C
/* 0E0F20 8014A820 0260A02D */   daddu $s4, $s3, $zero
/* 0E0F24 8014A824 08052A3D */  j     .L8014A8F4
/* 0E0F28 8014A828 24020001 */   addiu $v0, $zero, 1

.L8014A82C:
/* 0E0F2C 8014A82C 3C028016 */  lui   $v0, 0x8016
/* 0E0F30 8014A830 24429AF0 */  addiu $v0, $v0, -0x6510
/* 0E0F34 8014A834 00041840 */  sll   $v1, $a0, 1
/* 0E0F38 8014A838 00641821 */  addu  $v1, $v1, $a0
/* 0E0F3C 8014A83C 00031900 */  sll   $v1, $v1, 4
/* 0E0F40 8014A840 80A4007A */  lb    $a0, 0x7a($a1)
/* 0E0F44 8014A844 14800008 */  bnez  $a0, .L8014A868
/* 0E0F48 8014A848 00628021 */   addu  $s0, $v1, $v0
/* 0E0F4C 8014A84C 8E040018 */  lw    $a0, 0x18($s0)
/* 0E0F50 8014A850 0C015671 */  jal   func_800559C4
/* 0E0F54 8014A854 00000000 */   nop   
/* 0E0F58 8014A858 96030000 */  lhu   $v1, ($s0)
/* 0E0F5C 8014A85C 24020001 */  addiu $v0, $zero, 1
/* 0E0F60 8014A860 08052A3C */  j     .L8014A8F0
/* 0E0F64 8014A864 3063FFFE */   andi  $v1, $v1, 0xfffe

.L8014A868:
/* 0E0F68 8014A868 0C05290C */  jal   get_default_variation_for_song
/* 0E0F6C 8014A86C 0240202D */   daddu $a0, $s2, $zero
/* 0E0F70 8014A870 04430001 */  bgezl $v0, .L8014A878
/* 0E0F74 8014A874 0040882D */   daddu $s1, $v0, $zero
.L8014A878:
/* 0E0F78 8014A878 8E020010 */  lw    $v0, 0x10($s0)
/* 0E0F7C 8014A87C 14520013 */  bne   $v0, $s2, .L8014A8CC
/* 0E0F80 8014A880 24020001 */   addiu $v0, $zero, 1
/* 0E0F84 8014A884 8E020014 */  lw    $v0, 0x14($s0)
/* 0E0F88 8014A888 14510010 */  bne   $v0, $s1, .L8014A8CC
/* 0E0F8C 8014A88C 24020001 */   addiu $v0, $zero, 1
/* 0E0F90 8014A890 00132400 */  sll   $a0, $s3, 0x10
/* 0E0F94 8014A894 0C052B21 */  jal   func_8014AC84
/* 0E0F98 8014A898 00042403 */   sra   $a0, $a0, 0x10
/* 0E0F9C 8014A89C 96020000 */  lhu   $v0, ($s0)
/* 0E0FA0 8014A8A0 30420004 */  andi  $v0, $v0, 4
/* 0E0FA4 8014A8A4 50400013 */  beql  $v0, $zero, .L8014A8F4
/* 0E0FA8 8014A8A8 24020002 */   addiu $v0, $zero, 2
/* 0E0FAC 8014A8AC 8E040018 */  lw    $a0, 0x18($s0)
/* 0E0FB0 8014A8B0 0C0156E0 */  jal   func_80055B80
/* 0E0FB4 8014A8B4 00000000 */   nop   
/* 0E0FB8 8014A8B8 96020000 */  lhu   $v0, ($s0)
/* 0E0FBC 8014A8BC 3042FFFB */  andi  $v0, $v0, 0xfffb
/* 0E0FC0 8014A8C0 A6020000 */  sh    $v0, ($s0)
/* 0E0FC4 8014A8C4 08052A3D */  j     .L8014A8F4
/* 0E0FC8 8014A8C8 24020002 */   addiu $v0, $zero, 2

.L8014A8CC:
/* 0E0FCC 8014A8CC 96030000 */  lhu   $v1, ($s0)
/* 0E0FD0 8014A8D0 0040202D */  daddu $a0, $v0, $zero
/* 0E0FD4 8014A8D4 3C018016 */  lui   $at, 0x8016
/* 0E0FD8 8014A8D8 A4349AE0 */  sh    $s4, -0x6520($at)
/* 0E0FDC 8014A8DC AE120010 */  sw    $s2, 0x10($s0)
/* 0E0FE0 8014A8E0 AE110014 */  sw    $s1, 0x14($s0)
/* 0E0FE4 8014A8E4 AE150004 */  sw    $s5, 4($s0)
/* 0E0FE8 8014A8E8 A6040002 */  sh    $a0, 2($s0)
/* 0E0FEC 8014A8EC 3063FFFD */  andi  $v1, $v1, 0xfffd
.L8014A8F0:
/* 0E0FF0 8014A8F0 A6030000 */  sh    $v1, ($s0)
.L8014A8F4:
/* 0E0FF4 8014A8F4 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0E0FF8 8014A8F8 8FB50024 */  lw    $s5, 0x24($sp)
/* 0E0FFC 8014A8FC 8FB40020 */  lw    $s4, 0x20($sp)
/* 0E1000 8014A900 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0E1004 8014A904 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E1008 8014A908 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E100C 8014A90C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E1010 8014A910 03E00008 */  jr    $ra
/* 0E1014 8014A914 27BD0030 */   addiu $sp, $sp, 0x30

