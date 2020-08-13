.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel LandJumpPart
/* 1A943C 8027AB5C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1A9440 8027AB60 AFB20020 */  sw    $s2, 0x20($sp)
/* 1A9444 8027AB64 0080902D */  daddu $s2, $a0, $zero
/* 1A9448 8027AB68 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1A944C 8027AB6C AFB1001C */  sw    $s1, 0x1c($sp)
/* 1A9450 8027AB70 AFB00018 */  sw    $s0, 0x18($sp)
/* 1A9454 8027AB74 8E51000C */  lw    $s1, 0xc($s2)
/* 1A9458 8027AB78 54A00001 */  bnezl $a1, .L8027AB80
/* 1A945C 8027AB7C AE400070 */   sw    $zero, 0x70($s2)
.L8027AB80:
/* 1A9460 8027AB80 8E420070 */  lw    $v0, 0x70($s2)
/* 1A9464 8027AB84 14400020 */  bnez  $v0, .L8027AC08
/* 1A9468 8027AB88 00000000 */   nop   
/* 1A946C 8027AB8C 8E250000 */  lw    $a1, ($s1)
/* 1A9470 8027AB90 26310004 */  addiu $s1, $s1, 4
/* 1A9474 8027AB94 0C0B1EAF */  jal   get_variable
/* 1A9478 8027AB98 0240202D */   daddu $a0, $s2, $zero
/* 1A947C 8027AB9C 0040802D */  daddu $s0, $v0, $zero
/* 1A9480 8027ABA0 8E250000 */  lw    $a1, ($s1)
/* 1A9484 8027ABA4 0C0B1EAF */  jal   get_variable
/* 1A9488 8027ABA8 0240202D */   daddu $a0, $s2, $zero
/* 1A948C 8027ABAC 0040882D */  daddu $s1, $v0, $zero
/* 1A9490 8027ABB0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A9494 8027ABB4 16020002 */  bne   $s0, $v0, .L8027ABC0
/* 1A9498 8027ABB8 00000000 */   nop   
/* 1A949C 8027ABBC 8E500148 */  lw    $s0, 0x148($s2)
.L8027ABC0:
/* 1A94A0 8027ABC0 0C09A75B */  jal   get_actor
/* 1A94A4 8027ABC4 0200202D */   daddu $a0, $s0, $zero
/* 1A94A8 8027ABC8 0040802D */  daddu $s0, $v0, $zero
/* 1A94AC 8027ABCC 0200202D */  daddu $a0, $s0, $zero
/* 1A94B0 8027ABD0 0C099117 */  jal   get_actor_part
/* 1A94B4 8027ABD4 0220282D */   daddu $a1, $s1, $zero
/* 1A94B8 8027ABD8 0040882D */  daddu $s1, $v0, $zero
/* 1A94BC 8027ABDC AE500074 */  sw    $s0, 0x74($s2)
/* 1A94C0 8027ABE0 AE510078 */  sw    $s1, 0x78($s2)
/* 1A94C4 8027ABE4 8E300010 */  lw    $s0, 0x10($s1)
/* 1A94C8 8027ABE8 C620002C */  lwc1  $f0, 0x2c($s1)
/* 1A94CC 8027ABEC E6000000 */  swc1  $f0, ($s0)
/* 1A94D0 8027ABF0 C6200030 */  lwc1  $f0, 0x30($s1)
/* 1A94D4 8027ABF4 E6000004 */  swc1  $f0, 4($s0)
/* 1A94D8 8027ABF8 C6200034 */  lwc1  $f0, 0x34($s1)
/* 1A94DC 8027ABFC 24020001 */  addiu $v0, $zero, 1
/* 1A94E0 8027AC00 E6000008 */  swc1  $f0, 8($s0)
/* 1A94E4 8027AC04 AE420070 */  sw    $v0, 0x70($s2)
.L8027AC08:
/* 1A94E8 8027AC08 8E510078 */  lw    $s1, 0x78($s2)
/* 1A94EC 8027AC0C 8E300010 */  lw    $s0, 0x10($s1)
/* 1A94F0 8027AC10 C6040004 */  lwc1  $f4, 4($s0)
/* 1A94F4 8027AC14 C600002C */  lwc1  $f0, 0x2c($s0)
/* 1A94F8 8027AC18 8E050028 */  lw    $a1, 0x28($s0)
/* 1A94FC 8027AC1C 46002100 */  add.s $f4, $f4, $f0
/* 1A9500 8027AC20 C6020024 */  lwc1  $f2, 0x24($s0)
/* 1A9504 8027AC24 8E060030 */  lw    $a2, 0x30($s0)
/* 1A9508 8027AC28 46020001 */  sub.s $f0, $f0, $f2
/* 1A950C 8027AC2C 0200202D */  daddu $a0, $s0, $zero
/* 1A9510 8027AC30 E6040004 */  swc1  $f4, 4($s0)
/* 1A9514 8027AC34 0C099070 */  jal   add_xz_vec3f_copy1
/* 1A9518 8027AC38 E600002C */   swc1  $f0, 0x2c($s0)
/* 1A951C 8027AC3C C6000000 */  lwc1  $f0, ($s0)
/* 1A9520 8027AC40 44802000 */  mtc1  $zero, $f4
/* 1A9524 8027AC44 E620002C */  swc1  $f0, 0x2c($s1)
/* 1A9528 8027AC48 C6000004 */  lwc1  $f0, 4($s0)
/* 1A952C 8027AC4C E6200030 */  swc1  $f0, 0x30($s1)
/* 1A9530 8027AC50 C6220030 */  lwc1  $f2, 0x30($s1)
/* 1A9534 8027AC54 C6000008 */  lwc1  $f0, 8($s0)
/* 1A9538 8027AC58 4604103C */  c.lt.s $f2, $f4
/* 1A953C 8027AC5C 00000000 */  nop   
/* 1A9540 8027AC60 45010003 */  bc1t  .L8027AC70
/* 1A9544 8027AC64 E6200034 */   swc1  $f0, 0x34($s1)
/* 1A9548 8027AC68 0809EB25 */  j     .L8027AC94
/* 1A954C 8027AC6C 0000102D */   daddu $v0, $zero, $zero

.L8027AC70:
/* 1A9550 8027AC70 C6200064 */  lwc1  $f0, 0x64($s1)
/* 1A9554 8027AC74 E6240030 */  swc1  $f4, 0x30($s1)
/* 1A9558 8027AC78 E7A00010 */  swc1  $f0, 0x10($sp)
/* 1A955C 8027AC7C 8E25002C */  lw    $a1, 0x2c($s1)
/* 1A9560 8027AC80 8E260030 */  lw    $a2, 0x30($s1)
/* 1A9564 8027AC84 8E270034 */  lw    $a3, 0x34($s1)
/* 1A9568 8027AC88 0C0990BC */  jal   play_movement_dust_effects
/* 1A956C 8027AC8C 24040002 */   addiu $a0, $zero, 2
/* 1A9570 8027AC90 24020001 */  addiu $v0, $zero, 1
.L8027AC94:
/* 1A9574 8027AC94 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1A9578 8027AC98 8FB20020 */  lw    $s2, 0x20($sp)
/* 1A957C 8027AC9C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1A9580 8027ACA0 8FB00018 */  lw    $s0, 0x18($sp)
/* 1A9584 8027ACA4 03E00008 */  jr    $ra
/* 1A9588 8027ACA8 27BD0028 */   addiu $sp, $sp, 0x28

