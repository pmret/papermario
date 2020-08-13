.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetActorRotation
/* 19AC8C 8026C3AC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19AC90 8026C3B0 AFB20018 */  sw    $s2, 0x18($sp)
/* 19AC94 8026C3B4 0080902D */  daddu $s2, $a0, $zero
/* 19AC98 8026C3B8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19AC9C 8026C3BC AFB3001C */  sw    $s3, 0x1c($sp)
/* 19ACA0 8026C3C0 AFB10014 */  sw    $s1, 0x14($sp)
/* 19ACA4 8026C3C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 19ACA8 8026C3C8 8E50000C */  lw    $s0, 0xc($s2)
/* 19ACAC 8026C3CC 8E050000 */  lw    $a1, ($s0)
/* 19ACB0 8026C3D0 0C0B1EAF */  jal   get_variable
/* 19ACB4 8026C3D4 26100004 */   addiu $s0, $s0, 4
/* 19ACB8 8026C3D8 0040882D */  daddu $s1, $v0, $zero
/* 19ACBC 8026C3DC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19ACC0 8026C3E0 16220002 */  bne   $s1, $v0, .L8026C3EC
/* 19ACC4 8026C3E4 00000000 */   nop   
/* 19ACC8 8026C3E8 8E510148 */  lw    $s1, 0x148($s2)
.L8026C3EC:
/* 19ACCC 8026C3EC 8E050000 */  lw    $a1, ($s0)
/* 19ACD0 8026C3F0 26100004 */  addiu $s0, $s0, 4
/* 19ACD4 8026C3F4 0C0B210B */  jal   get_float_variable
/* 19ACD8 8026C3F8 0240202D */   daddu $a0, $s2, $zero
/* 19ACDC 8026C3FC 8E050000 */  lw    $a1, ($s0)
/* 19ACE0 8026C400 26100004 */  addiu $s0, $s0, 4
/* 19ACE4 8026C404 4600008D */  trunc.w.s $f2, $f0
/* 19ACE8 8026C408 44131000 */  mfc1  $s3, $f2
/* 19ACEC 8026C40C 0C0B210B */  jal   get_float_variable
/* 19ACF0 8026C410 0240202D */   daddu $a0, $s2, $zero
/* 19ACF4 8026C414 8E050000 */  lw    $a1, ($s0)
/* 19ACF8 8026C418 4600008D */  trunc.w.s $f2, $f0
/* 19ACFC 8026C41C 44101000 */  mfc1  $s0, $f2
/* 19AD00 8026C420 0C0B210B */  jal   get_float_variable
/* 19AD04 8026C424 0240202D */   daddu $a0, $s2, $zero
/* 19AD08 8026C428 0220202D */  daddu $a0, $s1, $zero
/* 19AD0C 8026C42C 4600008D */  trunc.w.s $f2, $f0
/* 19AD10 8026C430 44111000 */  mfc1  $s1, $f2
/* 19AD14 8026C434 0C09A75B */  jal   get_actor
/* 19AD18 8026C438 00000000 */   nop   
/* 19AD1C 8026C43C 3C03F119 */  lui   $v1, 0xf119
/* 19AD20 8026C440 34634D80 */  ori   $v1, $v1, 0x4d80
/* 19AD24 8026C444 12630005 */  beq   $s3, $v1, .L8026C45C
/* 19AD28 8026C448 00000000 */   nop   
/* 19AD2C 8026C44C 44930000 */  mtc1  $s3, $f0
/* 19AD30 8026C450 00000000 */  nop   
/* 19AD34 8026C454 46800020 */  cvt.s.w $f0, $f0
/* 19AD38 8026C458 E440015C */  swc1  $f0, 0x15c($v0)
.L8026C45C:
/* 19AD3C 8026C45C 12030005 */  beq   $s0, $v1, .L8026C474
/* 19AD40 8026C460 00000000 */   nop   
/* 19AD44 8026C464 44900000 */  mtc1  $s0, $f0
/* 19AD48 8026C468 00000000 */  nop   
/* 19AD4C 8026C46C 46800020 */  cvt.s.w $f0, $f0
/* 19AD50 8026C470 E4400160 */  swc1  $f0, 0x160($v0)
.L8026C474:
/* 19AD54 8026C474 12230005 */  beq   $s1, $v1, .L8026C48C
/* 19AD58 8026C478 00000000 */   nop   
/* 19AD5C 8026C47C 44910000 */  mtc1  $s1, $f0
/* 19AD60 8026C480 00000000 */  nop   
/* 19AD64 8026C484 46800020 */  cvt.s.w $f0, $f0
/* 19AD68 8026C488 E4400164 */  swc1  $f0, 0x164($v0)
.L8026C48C:
/* 19AD6C 8026C48C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19AD70 8026C490 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19AD74 8026C494 8FB20018 */  lw    $s2, 0x18($sp)
/* 19AD78 8026C498 8FB10014 */  lw    $s1, 0x14($sp)
/* 19AD7C 8026C49C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19AD80 8026C4A0 24020002 */  addiu $v0, $zero, 2
/* 19AD84 8026C4A4 03E00008 */  jr    $ra
/* 19AD88 8026C4A8 27BD0028 */   addiu $sp, $sp, 0x28

