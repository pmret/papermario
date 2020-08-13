.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorRotationOffset
/* 19AD8C 8026C4AC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19AD90 8026C4B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 19AD94 8026C4B4 0080882D */  daddu $s1, $a0, $zero
/* 19AD98 8026C4B8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19AD9C 8026C4BC AFB3001C */  sw    $s3, 0x1c($sp)
/* 19ADA0 8026C4C0 AFB20018 */  sw    $s2, 0x18($sp)
/* 19ADA4 8026C4C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 19ADA8 8026C4C8 8E30000C */  lw    $s0, 0xc($s1)
/* 19ADAC 8026C4CC 8E050000 */  lw    $a1, ($s0)
/* 19ADB0 8026C4D0 0C0B1EAF */  jal   get_variable
/* 19ADB4 8026C4D4 26100004 */   addiu $s0, $s0, 4
/* 19ADB8 8026C4D8 0040982D */  daddu $s3, $v0, $zero
/* 19ADBC 8026C4DC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19ADC0 8026C4E0 16620002 */  bne   $s3, $v0, .L8026C4EC
/* 19ADC4 8026C4E4 00000000 */   nop   
/* 19ADC8 8026C4E8 8E330148 */  lw    $s3, 0x148($s1)
.L8026C4EC:
/* 19ADCC 8026C4EC 8E050000 */  lw    $a1, ($s0)
/* 19ADD0 8026C4F0 26100004 */  addiu $s0, $s0, 4
/* 19ADD4 8026C4F4 0C0B210B */  jal   get_float_variable
/* 19ADD8 8026C4F8 0220202D */   daddu $a0, $s1, $zero
/* 19ADDC 8026C4FC 8E050000 */  lw    $a1, ($s0)
/* 19ADE0 8026C500 26100004 */  addiu $s0, $s0, 4
/* 19ADE4 8026C504 4600008D */  trunc.w.s $f2, $f0
/* 19ADE8 8026C508 44121000 */  mfc1  $s2, $f2
/* 19ADEC 8026C50C 0C0B210B */  jal   get_float_variable
/* 19ADF0 8026C510 0220202D */   daddu $a0, $s1, $zero
/* 19ADF4 8026C514 0220202D */  daddu $a0, $s1, $zero
/* 19ADF8 8026C518 8E050000 */  lw    $a1, ($s0)
/* 19ADFC 8026C51C 4600008D */  trunc.w.s $f2, $f0
/* 19AE00 8026C520 44111000 */  mfc1  $s1, $f2
/* 19AE04 8026C524 0C0B210B */  jal   get_float_variable
/* 19AE08 8026C528 00000000 */   nop   
/* 19AE0C 8026C52C 4600008D */  trunc.w.s $f2, $f0
/* 19AE10 8026C530 44101000 */  mfc1  $s0, $f2
/* 19AE14 8026C534 0C09A75B */  jal   get_actor
/* 19AE18 8026C538 0260202D */   daddu $a0, $s3, $zero
/* 19AE1C 8026C53C 0040182D */  daddu $v1, $v0, $zero
/* 19AE20 8026C540 A4720168 */  sh    $s2, 0x168($v1)
/* 19AE24 8026C544 A471016A */  sh    $s1, 0x16a($v1)
/* 19AE28 8026C548 A470016C */  sh    $s0, 0x16c($v1)
/* 19AE2C 8026C54C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19AE30 8026C550 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19AE34 8026C554 8FB20018 */  lw    $s2, 0x18($sp)
/* 19AE38 8026C558 8FB10014 */  lw    $s1, 0x14($sp)
/* 19AE3C 8026C55C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19AE40 8026C560 24020002 */  addiu $v0, $zero, 2
/* 19AE44 8026C564 03E00008 */  jr    $ra
/* 19AE48 8026C568 27BD0028 */   addiu $sp, $sp, 0x28

