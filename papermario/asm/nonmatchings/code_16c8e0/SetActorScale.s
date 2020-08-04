.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetActorScale
/* 19B1E4 8026C904 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 19B1E8 8026C908 AFB20018 */  sw    $s2, 0x18($sp)
/* 19B1EC 8026C90C 0080902D */  daddu $s2, $a0, $zero
/* 19B1F0 8026C910 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19B1F4 8026C914 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B1F8 8026C918 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B1FC 8026C91C F7B80030 */  sdc1  $f24, 0x30($sp)
/* 19B200 8026C920 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 19B204 8026C924 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 19B208 8026C928 8E50000C */  lw    $s0, 0xc($s2)
/* 19B20C 8026C92C 8E050000 */  lw    $a1, ($s0)
/* 19B210 8026C930 0C0B1EAF */  jal   get_variable
/* 19B214 8026C934 26100004 */   addiu $s0, $s0, 4
/* 19B218 8026C938 0040882D */  daddu $s1, $v0, $zero
/* 19B21C 8026C93C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B220 8026C940 16220002 */  bne   $s1, $v0, .L8026C94C
/* 19B224 8026C944 00000000 */   nop   
/* 19B228 8026C948 8E510148 */  lw    $s1, 0x148($s2)
.L8026C94C:
/* 19B22C 8026C94C 8E050000 */  lw    $a1, ($s0)
/* 19B230 8026C950 26100004 */  addiu $s0, $s0, 4
/* 19B234 8026C954 0C0B210B */  jal   get_float_variable
/* 19B238 8026C958 0240202D */   daddu $a0, $s2, $zero
/* 19B23C 8026C95C 8E050000 */  lw    $a1, ($s0)
/* 19B240 8026C960 26100004 */  addiu $s0, $s0, 4
/* 19B244 8026C964 0240202D */  daddu $a0, $s2, $zero
/* 19B248 8026C968 0C0B210B */  jal   get_float_variable
/* 19B24C 8026C96C 46000606 */   mov.s $f24, $f0
/* 19B250 8026C970 0240202D */  daddu $a0, $s2, $zero
/* 19B254 8026C974 8E050000 */  lw    $a1, ($s0)
/* 19B258 8026C978 0C0B210B */  jal   get_float_variable
/* 19B25C 8026C97C 46000586 */   mov.s $f22, $f0
/* 19B260 8026C980 0220202D */  daddu $a0, $s1, $zero
/* 19B264 8026C984 0C09A75B */  jal   get_actor
/* 19B268 8026C988 46000506 */   mov.s $f20, $f0
/* 19B26C 8026C98C 0040182D */  daddu $v1, $v0, $zero
/* 19B270 8026C990 E4780170 */  swc1  $f24, 0x170($v1)
/* 19B274 8026C994 E4760174 */  swc1  $f22, 0x174($v1)
/* 19B278 8026C998 E4740178 */  swc1  $f20, 0x178($v1)
/* 19B27C 8026C99C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19B280 8026C9A0 8FB20018 */  lw    $s2, 0x18($sp)
/* 19B284 8026C9A4 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B288 8026C9A8 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B28C 8026C9AC D7B80030 */  ldc1  $f24, 0x30($sp)
/* 19B290 8026C9B0 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 19B294 8026C9B4 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 19B298 8026C9B8 24020002 */  addiu $v0, $zero, 2
/* 19B29C 8026C9BC 03E00008 */  jr    $ra
/* 19B2A0 8026C9C0 27BD0038 */   addiu $sp, $sp, 0x38

