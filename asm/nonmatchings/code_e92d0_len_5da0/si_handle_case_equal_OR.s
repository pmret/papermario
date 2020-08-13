.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_case_equal_OR
/* 0E9EC8 802C5518 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9ECC 802C551C AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9ED0 802C5520 0080882D */  daddu $s1, $a0, $zero
/* 0E9ED4 802C5524 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9ED8 802C5528 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9EDC 802C552C 82300007 */  lb    $s0, 7($s1)
/* 0E9EE0 802C5530 06010003 */  bgez  $s0, .L802C5540
/* 0E9EE4 802C5534 8E25000C */   lw    $a1, 0xc($s1)
.L802C5538:
/* 0E9EE8 802C5538 080B154E */  j     .L802C5538
/* 0E9EEC 802C553C 00000000 */   nop   

.L802C5540:
/* 0E9EF0 802C5540 8CA50000 */  lw    $a1, ($a1)
/* 0E9EF4 802C5544 0C0B1EAF */  jal   get_variable
/* 0E9EF8 802C5548 0220202D */   daddu $a0, $s1, $zero
/* 0E9EFC 802C554C 0040282D */  daddu $a1, $v0, $zero
/* 0E9F00 802C5550 00101080 */  sll   $v0, $s0, 2
/* 0E9F04 802C5554 02221021 */  addu  $v0, $s1, $v0
/* 0E9F08 802C5558 02302021 */  addu  $a0, $s1, $s0
/* 0E9F0C 802C555C 80830110 */  lb    $v1, 0x110($a0)
/* 0E9F10 802C5560 14600005 */  bnez  $v1, .L802C5578
/* 0E9F14 802C5564 8C420118 */   lw    $v0, 0x118($v0)
/* 0E9F18 802C5568 0C0B2279 */  jal   si_goto_end_case
/* 0E9F1C 802C556C 0220202D */   daddu $a0, $s1, $zero
/* 0E9F20 802C5570 080B1568 */  j     .L802C55A0
/* 0E9F24 802C5574 AE220008 */   sw    $v0, 8($s1)

.L802C5578:
/* 0E9F28 802C5578 14A20004 */  bne   $a1, $v0, .L802C558C
/* 0E9F2C 802C557C 2402FFFF */   addiu $v0, $zero, -1
/* 0E9F30 802C5580 2402FFFF */  addiu $v0, $zero, -1
/* 0E9F34 802C5584 080B1568 */  j     .L802C55A0
/* 0E9F38 802C5588 A0820110 */   sb    $v0, 0x110($a0)

.L802C558C:
/* 0E9F3C 802C558C 10620005 */  beq   $v1, $v0, .L802C55A4
/* 0E9F40 802C5590 24020002 */   addiu $v0, $zero, 2
/* 0E9F44 802C5594 0C0B2298 */  jal   si_goto_next_case
/* 0E9F48 802C5598 0220202D */   daddu $a0, $s1, $zero
/* 0E9F4C 802C559C AE220008 */  sw    $v0, 8($s1)
.L802C55A0:
/* 0E9F50 802C55A0 24020002 */  addiu $v0, $zero, 2
.L802C55A4:
/* 0E9F54 802C55A4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9F58 802C55A8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9F5C 802C55AC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9F60 802C55B0 03E00008 */  jr    $ra
/* 0E9F64 802C55B4 27BD0020 */   addiu $sp, $sp, 0x20

