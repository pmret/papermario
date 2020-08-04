.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CloseMessage
/* 0F5448 802D0A98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F544C 802D0A9C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F5450 802D0AA0 0080802D */  daddu $s0, $a0, $zero
/* 0F5454 802D0AA4 10A00005 */  beqz  $a1, .L802D0ABC
/* 0F5458 802D0AA8 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0F545C 802D0AAC 3C04802E */  lui   $a0, 0x802e
/* 0F5460 802D0AB0 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F5464 802D0AB4 0C04971C */  jal   close_message
/* 0F5468 802D0AB8 00000000 */   nop   
.L802D0ABC:
/* 0F546C 802D0ABC 3C04802E */  lui   $a0, 0x802e
/* 0F5470 802D0AC0 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F5474 802D0AC4 8C8204FC */  lw    $v0, 0x4fc($a0)
/* 0F5478 802D0AC8 30420040 */  andi  $v0, $v0, 0x40
/* 0F547C 802D0ACC 14400007 */  bnez  $v0, .L802D0AEC
/* 0F5480 802D0AD0 24020001 */   addiu $v0, $zero, 1
/* 0F5484 802D0AD4 3C03802E */  lui   $v1, 0x802e
/* 0F5488 802D0AD8 8C63B264 */  lw    $v1, -0x4d9c($v1)
/* 0F548C 802D0ADC 54620003 */  bnel  $v1, $v0, .L802D0AEC
/* 0F5490 802D0AE0 0000102D */   daddu $v0, $zero, $zero
/* 0F5494 802D0AE4 908304E8 */  lbu   $v1, 0x4e8($a0)
/* 0F5498 802D0AE8 AE030084 */  sw    $v1, 0x84($s0)
.L802D0AEC:
/* 0F549C 802D0AEC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F54A0 802D0AF0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F54A4 802D0AF4 03E00008 */  jr    $ra
/* 0F54A8 802D0AF8 27BD0018 */   addiu $sp, $sp, 0x18

