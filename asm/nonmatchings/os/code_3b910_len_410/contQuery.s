.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel contQuery
/* 03BC70 80060870 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03BC74 80060874 AFB00010 */  sw    $s0, 0x10($sp)
/* 03BC78 80060878 3C10800E */  lui   $s0, 0x800e
/* 03BC7C 8006087C 2610AC78 */  addiu $s0, $s0, -0x5388
/* 03BC80 80060880 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03BC84 80060884 0C018640 */  jal   osContStartQuery
/* 03BC88 80060888 0200202D */   daddu $a0, $s0, $zero
/* 03BC8C 8006088C 14400008 */  bnez  $v0, .L800608B0
/* 03BC90 80060890 0200202D */   daddu $a0, $s0, $zero
/* 03BC94 80060894 0000282D */  daddu $a1, $zero, $zero
/* 03BC98 80060898 0C0195BC */  jal   osRecvMesg
/* 03BC9C 8006089C 24060001 */   addiu $a2, $zero, 1
/* 03BCA0 800608A0 3C04800B */  lui   $a0, 0x800b
/* 03BCA4 800608A4 0C018660 */  jal   osContGetQuery
/* 03BCA8 800608A8 24841B7C */   addiu $a0, $a0, 0x1b7c
/* 03BCAC 800608AC 0000102D */  daddu $v0, $zero, $zero
.L800608B0:
/* 03BCB0 800608B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BCB4 800608B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 03BCB8 800608B8 03E00008 */  jr    $ra
/* 03BCBC 800608BC 27BD0018 */   addiu $sp, $sp, 0x18

