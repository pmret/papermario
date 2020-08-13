.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPartGoalToTarget
/* 198CE4 8026A404 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 198CE8 8026A408 AFB20018 */  sw    $s2, 0x18($sp)
/* 198CEC 8026A40C 0080902D */  daddu $s2, $a0, $zero
/* 198CF0 8026A410 AFBF0020 */  sw    $ra, 0x20($sp)
/* 198CF4 8026A414 AFB3001C */  sw    $s3, 0x1c($sp)
/* 198CF8 8026A418 AFB10014 */  sw    $s1, 0x14($sp)
/* 198CFC 8026A41C AFB00010 */  sw    $s0, 0x10($sp)
/* 198D00 8026A420 8E50000C */  lw    $s0, 0xc($s2)
/* 198D04 8026A424 8E050000 */  lw    $a1, ($s0)
/* 198D08 8026A428 0C0B1EAF */  jal   get_variable
/* 198D0C 8026A42C 26100004 */   addiu $s0, $s0, 4
/* 198D10 8026A430 0040882D */  daddu $s1, $v0, $zero
/* 198D14 8026A434 8E050000 */  lw    $a1, ($s0)
/* 198D18 8026A438 0C0B1EAF */  jal   get_variable
/* 198D1C 8026A43C 0240202D */   daddu $a0, $s2, $zero
/* 198D20 8026A440 0040982D */  daddu $s3, $v0, $zero
/* 198D24 8026A444 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198D28 8026A448 16220002 */  bne   $s1, $v0, .L8026A454
/* 198D2C 8026A44C 00000000 */   nop   
/* 198D30 8026A450 8E510148 */  lw    $s1, 0x148($s2)
.L8026A454:
/* 198D34 8026A454 0C09A75B */  jal   get_actor
/* 198D38 8026A458 0220202D */   daddu $a0, $s1, $zero
/* 198D3C 8026A45C 0040802D */  daddu $s0, $v0, $zero
/* 198D40 8026A460 0200202D */  daddu $a0, $s0, $zero
/* 198D44 8026A464 0C099117 */  jal   get_actor_part
/* 198D48 8026A468 0260282D */   daddu $a1, $s3, $zero
/* 198D4C 8026A46C 8C440010 */  lw    $a0, 0x10($v0)
/* 198D50 8026A470 86050428 */  lh    $a1, 0x428($s0)
/* 198D54 8026A474 0C09A676 */  jal   set_part_goal_to_actor_part
/* 198D58 8026A478 82060426 */   lb    $a2, 0x426($s0)
/* 198D5C 8026A47C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 198D60 8026A480 8FB3001C */  lw    $s3, 0x1c($sp)
/* 198D64 8026A484 8FB20018 */  lw    $s2, 0x18($sp)
/* 198D68 8026A488 8FB10014 */  lw    $s1, 0x14($sp)
/* 198D6C 8026A48C 8FB00010 */  lw    $s0, 0x10($sp)
/* 198D70 8026A490 24020002 */  addiu $v0, $zero, 2
/* 198D74 8026A494 03E00008 */  jr    $ra
/* 198D78 8026A498 27BD0028 */   addiu $sp, $sp, 0x28

