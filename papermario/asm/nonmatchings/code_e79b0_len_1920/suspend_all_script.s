.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel suspend_all_script
/* 0E8DD0 802C4420 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8DD4 802C4424 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8DD8 802C4428 0080882D */  daddu $s1, $a0, $zero
/* 0E8DDC 802C442C AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8DE0 802C4430 0000802D */  daddu $s0, $zero, $zero
/* 0E8DE4 802C4434 AFBF0018 */  sw    $ra, 0x18($sp)
.L802C4438:
/* 0E8DE8 802C4438 3C03802E */  lui   $v1, 0x802e
/* 0E8DEC 802C443C 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8DF0 802C4440 00101080 */  sll   $v0, $s0, 2
/* 0E8DF4 802C4444 00431021 */  addu  $v0, $v0, $v1
/* 0E8DF8 802C4448 8C440000 */  lw    $a0, ($v0)
/* 0E8DFC 802C444C 50800007 */  beql  $a0, $zero, .L802C446C
/* 0E8E00 802C4450 26100001 */   addiu $s0, $s0, 1
/* 0E8E04 802C4454 8C820144 */  lw    $v0, 0x144($a0)
/* 0E8E08 802C4458 54510004 */  bnel  $v0, $s1, .L802C446C
/* 0E8E0C 802C445C 26100001 */   addiu $s0, $s0, 1
/* 0E8E10 802C4460 0C0B10B6 */  jal   suspend_group_script
/* 0E8E14 802C4464 240500EF */   addiu $a1, $zero, 0xef
/* 0E8E18 802C4468 26100001 */  addiu $s0, $s0, 1
.L802C446C:
/* 0E8E1C 802C446C 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8E20 802C4470 1440FFF1 */  bnez  $v0, .L802C4438
/* 0E8E24 802C4474 00000000 */   nop   
/* 0E8E28 802C4478 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E8E2C 802C447C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8E30 802C4480 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8E34 802C4484 03E00008 */  jr    $ra
/* 0E8E38 802C4488 27BD0020 */   addiu $sp, $sp, 0x20

