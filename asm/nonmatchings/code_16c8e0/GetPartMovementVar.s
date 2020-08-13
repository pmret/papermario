.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPartMovementVar
/* 19AA50 8026C170 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19AA54 8026C174 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19AA58 8026C178 0080982D */  daddu $s3, $a0, $zero
/* 19AA5C 8026C17C AFBF0020 */  sw    $ra, 0x20($sp)
/* 19AA60 8026C180 AFB20018 */  sw    $s2, 0x18($sp)
/* 19AA64 8026C184 AFB10014 */  sw    $s1, 0x14($sp)
/* 19AA68 8026C188 AFB00010 */  sw    $s0, 0x10($sp)
/* 19AA6C 8026C18C 8E72000C */  lw    $s2, 0xc($s3)
/* 19AA70 8026C190 8E450000 */  lw    $a1, ($s2)
/* 19AA74 8026C194 0C0B1EAF */  jal   get_variable
/* 19AA78 8026C198 26520004 */   addiu $s2, $s2, 4
/* 19AA7C 8026C19C 0040802D */  daddu $s0, $v0, $zero
/* 19AA80 8026C1A0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19AA84 8026C1A4 16020002 */  bne   $s0, $v0, .L8026C1B0
/* 19AA88 8026C1A8 00000000 */   nop   
/* 19AA8C 8026C1AC 8E700148 */  lw    $s0, 0x148($s3)
.L8026C1B0:
/* 19AA90 8026C1B0 8E450000 */  lw    $a1, ($s2)
/* 19AA94 8026C1B4 26520004 */  addiu $s2, $s2, 4
/* 19AA98 8026C1B8 0C0B1EAF */  jal   get_variable
/* 19AA9C 8026C1BC 0260202D */   daddu $a0, $s3, $zero
/* 19AAA0 8026C1C0 8E450000 */  lw    $a1, ($s2)
/* 19AAA4 8026C1C4 26520004 */  addiu $s2, $s2, 4
/* 19AAA8 8026C1C8 0260202D */  daddu $a0, $s3, $zero
/* 19AAAC 8026C1CC 0C0B1EAF */  jal   get_variable
/* 19AAB0 8026C1D0 0040882D */   daddu $s1, $v0, $zero
/* 19AAB4 8026C1D4 0200202D */  daddu $a0, $s0, $zero
/* 19AAB8 8026C1D8 8E520000 */  lw    $s2, ($s2)
/* 19AABC 8026C1DC 0C09A75B */  jal   get_actor
/* 19AAC0 8026C1E0 0040802D */   daddu $s0, $v0, $zero
/* 19AAC4 8026C1E4 0040202D */  daddu $a0, $v0, $zero
/* 19AAC8 8026C1E8 0C099117 */  jal   get_actor_part
/* 19AACC 8026C1EC 0220282D */   daddu $a1, $s1, $zero
/* 19AAD0 8026C1F0 0260202D */  daddu $a0, $s3, $zero
/* 19AAD4 8026C1F4 8C420010 */  lw    $v0, 0x10($v0)
/* 19AAD8 8026C1F8 00108080 */  sll   $s0, $s0, 2
/* 19AADC 8026C1FC 00501021 */  addu  $v0, $v0, $s0
/* 19AAE0 8026C200 8C46004C */  lw    $a2, 0x4c($v0)
/* 19AAE4 8026C204 0C0B2026 */  jal   set_variable
/* 19AAE8 8026C208 0240282D */   daddu $a1, $s2, $zero
/* 19AAEC 8026C20C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19AAF0 8026C210 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19AAF4 8026C214 8FB20018 */  lw    $s2, 0x18($sp)
/* 19AAF8 8026C218 8FB10014 */  lw    $s1, 0x14($sp)
/* 19AAFC 8026C21C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19AB00 8026C220 24020002 */  addiu $v0, $zero, 2
/* 19AB04 8026C224 03E00008 */  jr    $ra
/* 19AB08 8026C228 27BD0028 */   addiu $sp, $sp, 0x28

