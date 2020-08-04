.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartRotation
/* 19B108 8026C828 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 19B10C 8026C82C AFB40020 */  sw    $s4, 0x20($sp)
/* 19B110 8026C830 0080A02D */  daddu $s4, $a0, $zero
/* 19B114 8026C834 AFBF0028 */  sw    $ra, 0x28($sp)
/* 19B118 8026C838 AFB50024 */  sw    $s5, 0x24($sp)
/* 19B11C 8026C83C AFB3001C */  sw    $s3, 0x1c($sp)
/* 19B120 8026C840 AFB20018 */  sw    $s2, 0x18($sp)
/* 19B124 8026C844 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B128 8026C848 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B12C 8026C84C 8E90000C */  lw    $s0, 0xc($s4)
/* 19B130 8026C850 8E050000 */  lw    $a1, ($s0)
/* 19B134 8026C854 0C0B1EAF */  jal   get_variable
/* 19B138 8026C858 26100004 */   addiu $s0, $s0, 4
/* 19B13C 8026C85C 0040902D */  daddu $s2, $v0, $zero
/* 19B140 8026C860 8E050000 */  lw    $a1, ($s0)
/* 19B144 8026C864 26100004 */  addiu $s0, $s0, 4
/* 19B148 8026C868 0C0B1EAF */  jal   get_variable
/* 19B14C 8026C86C 0280202D */   daddu $a0, $s4, $zero
/* 19B150 8026C870 0040A82D */  daddu $s5, $v0, $zero
/* 19B154 8026C874 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B158 8026C878 16420002 */  bne   $s2, $v0, .L8026C884
/* 19B15C 8026C87C 00000000 */   nop   
/* 19B160 8026C880 8E920148 */  lw    $s2, 0x148($s4)
.L8026C884:
/* 19B164 8026C884 8E110000 */  lw    $s1, ($s0)
/* 19B168 8026C888 26100004 */  addiu $s0, $s0, 4
/* 19B16C 8026C88C 0240202D */  daddu $a0, $s2, $zero
/* 19B170 8026C890 8E120000 */  lw    $s2, ($s0)
/* 19B174 8026C894 0C09A75B */  jal   get_actor
/* 19B178 8026C898 8E130004 */   lw    $s3, 4($s0)
/* 19B17C 8026C89C 0040202D */  daddu $a0, $v0, $zero
/* 19B180 8026C8A0 0C099117 */  jal   get_actor_part
/* 19B184 8026C8A4 02A0282D */   daddu $a1, $s5, $zero
/* 19B188 8026C8A8 0280202D */  daddu $a0, $s4, $zero
/* 19B18C 8026C8AC 0040802D */  daddu $s0, $v0, $zero
/* 19B190 8026C8B0 8E060038 */  lw    $a2, 0x38($s0)
/* 19B194 8026C8B4 0C0B2190 */  jal   set_float_variable
/* 19B198 8026C8B8 0220282D */   daddu $a1, $s1, $zero
/* 19B19C 8026C8BC 0280202D */  daddu $a0, $s4, $zero
/* 19B1A0 8026C8C0 8E06003C */  lw    $a2, 0x3c($s0)
/* 19B1A4 8026C8C4 0C0B2190 */  jal   set_float_variable
/* 19B1A8 8026C8C8 0240282D */   daddu $a1, $s2, $zero
/* 19B1AC 8026C8CC 0280202D */  daddu $a0, $s4, $zero
/* 19B1B0 8026C8D0 8E060040 */  lw    $a2, 0x40($s0)
/* 19B1B4 8026C8D4 0C0B2190 */  jal   set_float_variable
/* 19B1B8 8026C8D8 0260282D */   daddu $a1, $s3, $zero
/* 19B1BC 8026C8DC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 19B1C0 8026C8E0 8FB50024 */  lw    $s5, 0x24($sp)
/* 19B1C4 8026C8E4 8FB40020 */  lw    $s4, 0x20($sp)
/* 19B1C8 8026C8E8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19B1CC 8026C8EC 8FB20018 */  lw    $s2, 0x18($sp)
/* 19B1D0 8026C8F0 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B1D4 8026C8F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B1D8 8026C8F8 24020002 */  addiu $v0, $zero, 2
/* 19B1DC 8026C8FC 03E00008 */  jr    $ra
/* 19B1E0 8026C900 27BD0030 */   addiu $sp, $sp, 0x30

