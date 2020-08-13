.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8014A964
/* 0E1064 8014A964 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E1068 8014A968 AFB40020 */  sw    $s4, 0x20($sp)
/* 0E106C 8014A96C 00A0A02D */  daddu $s4, $a1, $zero
/* 0E1070 8014A970 3C058007 */  lui   $a1, 0x8007
/* 0E1074 8014A974 8CA5419C */  lw    $a1, 0x419c($a1)
/* 0E1078 8014A978 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0E107C 8014A97C 8FB30040 */  lw    $s3, 0x40($sp)
/* 0E1080 8014A980 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E1084 8014A984 00C0882D */  daddu $s1, $a2, $zero
/* 0E1088 8014A988 AFB50024 */  sw    $s5, 0x24($sp)
/* 0E108C 8014A98C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0E1090 8014A990 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E1094 8014A994 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E1098 8014A998 80A20071 */  lb    $v0, 0x71($a1)
/* 0E109C 8014A99C 8FB20044 */  lw    $s2, 0x44($sp)
/* 0E10A0 8014A9A0 10400003 */  beqz  $v0, .L8014A9B0
/* 0E10A4 8014A9A4 00E0A82D */   daddu $s5, $a3, $zero
/* 0E10A8 8014A9A8 08052A8C */  j     .L8014AA30
/* 0E10AC 8014A9AC 24020001 */   addiu $v0, $zero, 1

.L8014A9B0:
/* 0E10B0 8014A9B0 3C028016 */  lui   $v0, 0x8016
/* 0E10B4 8014A9B4 24429AF0 */  addiu $v0, $v0, -0x6510
/* 0E10B8 8014A9B8 00041840 */  sll   $v1, $a0, 1
/* 0E10BC 8014A9BC 00641821 */  addu  $v1, $v1, $a0
/* 0E10C0 8014A9C0 00031900 */  sll   $v1, $v1, 4
/* 0E10C4 8014A9C4 80A4007A */  lb    $a0, 0x7a($a1)
/* 0E10C8 8014A9C8 14800008 */  bnez  $a0, .L8014A9EC
/* 0E10CC 8014A9CC 00628021 */   addu  $s0, $v1, $v0
/* 0E10D0 8014A9D0 8E040018 */  lw    $a0, 0x18($s0)
/* 0E10D4 8014A9D4 0C015671 */  jal   func_800559C4
/* 0E10D8 8014A9D8 00000000 */   nop   
/* 0E10DC 8014A9DC 96030000 */  lhu   $v1, ($s0)
/* 0E10E0 8014A9E0 24020001 */  addiu $v0, $zero, 1
/* 0E10E4 8014A9E4 08052A8B */  j     .L8014AA2C
/* 0E10E8 8014A9E8 3063FFFE */   andi  $v1, $v1, 0xfffe

.L8014A9EC:
/* 0E10EC 8014A9EC 0C05290C */  jal   get_default_variation_for_song
/* 0E10F0 8014A9F0 0280202D */   daddu $a0, $s4, $zero
/* 0E10F4 8014A9F4 04430001 */  bgezl $v0, .L8014A9FC
/* 0E10F8 8014A9F8 0040882D */   daddu $s1, $v0, $zero
.L8014A9FC:
/* 0E10FC 8014A9FC 24020001 */  addiu $v0, $zero, 1
/* 0E1100 8014AA00 96030000 */  lhu   $v1, ($s0)
/* 0E1104 8014AA04 0040202D */  daddu $a0, $v0, $zero
/* 0E1108 8014AA08 AE150008 */  sw    $s5, 8($s0)
/* 0E110C 8014AA0C A613000C */  sh    $s3, 0xc($s0)
/* 0E1110 8014AA10 A612000E */  sh    $s2, 0xe($s0)
/* 0E1114 8014AA14 AE140010 */  sw    $s4, 0x10($s0)
/* 0E1118 8014AA18 AE110014 */  sw    $s1, 0x14($s0)
/* 0E111C 8014AA1C A6040002 */  sh    $a0, 2($s0)
/* 0E1120 8014AA20 34630020 */  ori   $v1, $v1, 0x20
/* 0E1124 8014AA24 A6030000 */  sh    $v1, ($s0)
/* 0E1128 8014AA28 3063FFFD */  andi  $v1, $v1, 0xfffd
.L8014AA2C:
/* 0E112C 8014AA2C A6030000 */  sh    $v1, ($s0)
.L8014AA30:
/* 0E1130 8014AA30 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0E1134 8014AA34 8FB50024 */  lw    $s5, 0x24($sp)
/* 0E1138 8014AA38 8FB40020 */  lw    $s4, 0x20($sp)
/* 0E113C 8014AA3C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0E1140 8014AA40 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E1144 8014AA44 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E1148 8014AA48 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E114C 8014AA4C 03E00008 */  jr    $ra
/* 0E1150 8014AA50 27BD0030 */   addiu $sp, $sp, 0x30

