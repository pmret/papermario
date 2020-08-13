.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_case_default
/* 0E9DF4 802C5444 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E9DF8 802C5448 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9DFC 802C544C 0080802D */  daddu $s0, $a0, $zero
/* 0E9E00 802C5450 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9E04 802C5454 82020007 */  lb    $v0, 7($s0)
/* 0E9E08 802C5458 04410003 */  bgez  $v0, .L802C5468
/* 0E9E0C 802C545C 02021821 */   addu  $v1, $s0, $v0
.L802C5460:
/* 0E9E10 802C5460 080B1518 */  j     .L802C5460
/* 0E9E14 802C5464 00000000 */   nop   

.L802C5468:
/* 0E9E18 802C5468 80620110 */  lb    $v0, 0x110($v1)
/* 0E9E1C 802C546C 18400003 */  blez  $v0, .L802C547C
/* 0E9E20 802C5470 00000000 */   nop   
/* 0E9E24 802C5474 080B1522 */  j     .L802C5488
/* 0E9E28 802C5478 A0600110 */   sb    $zero, 0x110($v1)

.L802C547C:
/* 0E9E2C 802C547C 0C0B2279 */  jal   si_goto_end_case
/* 0E9E30 802C5480 0200202D */   daddu $a0, $s0, $zero
/* 0E9E34 802C5484 AE020008 */  sw    $v0, 8($s0)
.L802C5488:
/* 0E9E38 802C5488 24020002 */  addiu $v0, $zero, 2
/* 0E9E3C 802C548C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E9E40 802C5490 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9E44 802C5494 03E00008 */  jr    $ra
/* 0E9E48 802C5498 27BD0018 */   addiu $sp, $sp, 0x18

