.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddGoalPos
/* 199028 8026A748 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 19902C 8026A74C AFB20018 */  sw    $s2, 0x18($sp)
/* 199030 8026A750 0080902D */  daddu $s2, $a0, $zero
/* 199034 8026A754 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199038 8026A758 AFB10014 */  sw    $s1, 0x14($sp)
/* 19903C 8026A75C AFB00010 */  sw    $s0, 0x10($sp)
/* 199040 8026A760 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 199044 8026A764 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 199048 8026A768 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 19904C 8026A76C 8E50000C */  lw    $s0, 0xc($s2)
/* 199050 8026A770 8E050000 */  lw    $a1, ($s0)
/* 199054 8026A774 0C0B1EAF */  jal   get_variable
/* 199058 8026A778 26100004 */   addiu $s0, $s0, 4
/* 19905C 8026A77C 0040882D */  daddu $s1, $v0, $zero
/* 199060 8026A780 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199064 8026A784 16220002 */  bne   $s1, $v0, .L8026A790
/* 199068 8026A788 00000000 */   nop   
/* 19906C 8026A78C 8E510148 */  lw    $s1, 0x148($s2)
.L8026A790:
/* 199070 8026A790 8E050000 */  lw    $a1, ($s0)
/* 199074 8026A794 26100004 */  addiu $s0, $s0, 4
/* 199078 8026A798 0C0B210B */  jal   get_float_variable
/* 19907C 8026A79C 0240202D */   daddu $a0, $s2, $zero
/* 199080 8026A7A0 8E050000 */  lw    $a1, ($s0)
/* 199084 8026A7A4 26100004 */  addiu $s0, $s0, 4
/* 199088 8026A7A8 0240202D */  daddu $a0, $s2, $zero
/* 19908C 8026A7AC 0C0B210B */  jal   get_float_variable
/* 199090 8026A7B0 46000606 */   mov.s $f24, $f0
/* 199094 8026A7B4 0240202D */  daddu $a0, $s2, $zero
/* 199098 8026A7B8 8E050000 */  lw    $a1, ($s0)
/* 19909C 8026A7BC 0C0B210B */  jal   get_float_variable
/* 1990A0 8026A7C0 46000506 */   mov.s $f20, $f0
/* 1990A4 8026A7C4 0220202D */  daddu $a0, $s1, $zero
/* 1990A8 8026A7C8 0C09A75B */  jal   get_actor
/* 1990AC 8026A7CC 46000586 */   mov.s $f22, $f0
/* 1990B0 8026A7D0 0040182D */  daddu $v1, $v0, $zero
/* 1990B4 8026A7D4 C4640018 */  lwc1  $f4, 0x18($v1)
/* 1990B8 8026A7D8 46182100 */  add.s $f4, $f4, $f24
/* 1990BC 8026A7DC C462001C */  lwc1  $f2, 0x1c($v1)
/* 1990C0 8026A7E0 46141080 */  add.s $f2, $f2, $f20
/* 1990C4 8026A7E4 C4600020 */  lwc1  $f0, 0x20($v1)
/* 1990C8 8026A7E8 46160000 */  add.s $f0, $f0, $f22
/* 1990CC 8026A7EC E4640018 */  swc1  $f4, 0x18($v1)
/* 1990D0 8026A7F0 E462001C */  swc1  $f2, 0x1c($v1)
/* 1990D4 8026A7F4 E4600020 */  swc1  $f0, 0x20($v1)
/* 1990D8 8026A7F8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1990DC 8026A7FC 8FB20018 */  lw    $s2, 0x18($sp)
/* 1990E0 8026A800 8FB10014 */  lw    $s1, 0x14($sp)
/* 1990E4 8026A804 8FB00010 */  lw    $s0, 0x10($sp)
/* 1990E8 8026A808 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 1990EC 8026A80C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 1990F0 8026A810 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 1990F4 8026A814 24020002 */  addiu $v0, $zero, 2
/* 1990F8 8026A818 03E00008 */  jr    $ra
/* 1990FC 8026A81C 27BD0038 */   addiu $sp, $sp, 0x38

