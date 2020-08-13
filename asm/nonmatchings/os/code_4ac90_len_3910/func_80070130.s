.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80070130
/* 04B530 80070130 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B534 80070134 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B538 80070138 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B53C 8007013C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B540 80070140 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B544 80070144 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B548 80070148 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B54C 8007014C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B550 80070150 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B554 80070154 0C016959 */  jal   play_effect
/* 04B558 80070158 24040017 */   addiu $a0, $zero, 0x17
/* 04B55C 8007015C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B560 80070160 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B564 80070164 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B568 80070168 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B56C 8007016C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B570 80070170 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B574 80070174 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B578 80070178 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B57C 8007017C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B580 80070180 3C018008 */  lui   $at, 0x8008
/* 04B584 80070184 8C21F438 */  lw    $at, -0xbc8($at)
/* 04B588 80070188 00200008 */  jr    $at
/* 04B58C 8007018C 00000000 */   nop   
