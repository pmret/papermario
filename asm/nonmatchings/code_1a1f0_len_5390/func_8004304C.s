.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004304C
/* 01E44C 8004304C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01E450 80043050 3C03800B */  lui   $v1, 0x800b
/* 01E454 80043054 24630F10 */  addiu $v1, $v1, 0xf10
/* 01E458 80043058 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01E45C 8004305C 8C620098 */  lw    $v0, 0x98($v1)
/* 01E460 80043060 1040000B */  beqz  $v0, .L80043090
/* 01E464 80043064 00000000 */   nop   
/* 01E468 80043068 C4600090 */  lwc1  $f0, 0x90($v1)
/* 01E46C 8004306C 46800020 */  cvt.s.w $f0, $f0
/* 01E470 80043070 44050000 */  mfc1  $a1, $f0
/* 01E474 80043074 0C04DF62 */  jal   func_80137D88
/* 01E478 80043078 0000202D */   daddu $a0, $zero, $zero
/* 01E47C 8004307C 0000202D */  daddu $a0, $zero, $zero
/* 01E480 80043080 0080282D */  daddu $a1, $a0, $zero
/* 01E484 80043084 0080302D */  daddu $a2, $a0, $zero
/* 01E488 80043088 0C04DF84 */  jal   func_80137E10
/* 01E48C 8004308C 0080382D */   daddu $a3, $a0, $zero
.L80043090:
/* 01E490 80043090 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01E494 80043094 03E00008 */  jr    $ra
/* 01E498 80043098 27BD0018 */   addiu $sp, $sp, 0x18

