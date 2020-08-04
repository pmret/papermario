.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddActorPos
/* 19A20C 8026B92C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 19A210 8026B930 AFB20018 */  sw    $s2, 0x18($sp)
/* 19A214 8026B934 0080902D */  daddu $s2, $a0, $zero
/* 19A218 8026B938 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19A21C 8026B93C AFB10014 */  sw    $s1, 0x14($sp)
/* 19A220 8026B940 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A224 8026B944 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 19A228 8026B948 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 19A22C 8026B94C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 19A230 8026B950 8E50000C */  lw    $s0, 0xc($s2)
/* 19A234 8026B954 8E050000 */  lw    $a1, ($s0)
/* 19A238 8026B958 0C0B1EAF */  jal   get_variable
/* 19A23C 8026B95C 26100004 */   addiu $s0, $s0, 4
/* 19A240 8026B960 0040882D */  daddu $s1, $v0, $zero
/* 19A244 8026B964 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19A248 8026B968 16220002 */  bne   $s1, $v0, .L8026B974
/* 19A24C 8026B96C 00000000 */   nop   
/* 19A250 8026B970 8E510148 */  lw    $s1, 0x148($s2)
.L8026B974:
/* 19A254 8026B974 8E050000 */  lw    $a1, ($s0)
/* 19A258 8026B978 26100004 */  addiu $s0, $s0, 4
/* 19A25C 8026B97C 0C0B210B */  jal   get_float_variable
/* 19A260 8026B980 0240202D */   daddu $a0, $s2, $zero
/* 19A264 8026B984 8E050000 */  lw    $a1, ($s0)
/* 19A268 8026B988 26100004 */  addiu $s0, $s0, 4
/* 19A26C 8026B98C 0240202D */  daddu $a0, $s2, $zero
/* 19A270 8026B990 0C0B210B */  jal   get_float_variable
/* 19A274 8026B994 46000606 */   mov.s $f24, $f0
/* 19A278 8026B998 0240202D */  daddu $a0, $s2, $zero
/* 19A27C 8026B99C 8E050000 */  lw    $a1, ($s0)
/* 19A280 8026B9A0 0C0B210B */  jal   get_float_variable
/* 19A284 8026B9A4 46000506 */   mov.s $f20, $f0
/* 19A288 8026B9A8 0220202D */  daddu $a0, $s1, $zero
/* 19A28C 8026B9AC 0C09A75B */  jal   get_actor
/* 19A290 8026B9B0 46000586 */   mov.s $f22, $f0
/* 19A294 8026B9B4 0040182D */  daddu $v1, $v0, $zero
/* 19A298 8026B9B8 C4640144 */  lwc1  $f4, 0x144($v1)
/* 19A29C 8026B9BC 46182100 */  add.s $f4, $f4, $f24
/* 19A2A0 8026B9C0 C4620148 */  lwc1  $f2, 0x148($v1)
/* 19A2A4 8026B9C4 46141080 */  add.s $f2, $f2, $f20
/* 19A2A8 8026B9C8 C460014C */  lwc1  $f0, 0x14c($v1)
/* 19A2AC 8026B9CC 46160000 */  add.s $f0, $f0, $f22
/* 19A2B0 8026B9D0 E4640144 */  swc1  $f4, 0x144($v1)
/* 19A2B4 8026B9D4 E4620148 */  swc1  $f2, 0x148($v1)
/* 19A2B8 8026B9D8 E460014C */  swc1  $f0, 0x14c($v1)
/* 19A2BC 8026B9DC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19A2C0 8026B9E0 8FB20018 */  lw    $s2, 0x18($sp)
/* 19A2C4 8026B9E4 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A2C8 8026B9E8 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A2CC 8026B9EC D7B80030 */  ldc1  $f24, 0x30($sp)
/* 19A2D0 8026B9F0 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 19A2D4 8026B9F4 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 19A2D8 8026B9F8 24020002 */  addiu $v0, $zero, 2
/* 19A2DC 8026B9FC 03E00008 */  jr    $ra
/* 19A2E0 8026BA00 27BD0038 */   addiu $sp, $sp, 0x38

