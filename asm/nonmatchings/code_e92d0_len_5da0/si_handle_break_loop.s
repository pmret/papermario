.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_break_loop
/* 0E94BC 802C4B0C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E94C0 802C4B10 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E94C4 802C4B14 0080802D */  daddu $s0, $a0, $zero
/* 0E94C8 802C4B18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E94CC 802C4B1C 82020006 */  lb    $v0, 6($s0)
/* 0E94D0 802C4B20 04410003 */  bgez  $v0, .L802C4B30
/* 0E94D4 802C4B24 00000000 */   nop   
.L802C4B28:
/* 0E94D8 802C4B28 080B12CA */  j     .L802C4B28
/* 0E94DC 802C4B2C 00000000 */   nop   

.L802C4B30:
/* 0E94E0 802C4B30 0C0B22B9 */  jal   si_goto_end_loop
/* 0E94E4 802C4B34 0200202D */   daddu $a0, $s0, $zero
/* 0E94E8 802C4B38 92030006 */  lbu   $v1, 6($s0)
/* 0E94EC 802C4B3C AE020008 */  sw    $v0, 8($s0)
/* 0E94F0 802C4B40 2463FFFF */  addiu $v1, $v1, -1
/* 0E94F4 802C4B44 A2030006 */  sb    $v1, 6($s0)
/* 0E94F8 802C4B48 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E94FC 802C4B4C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9500 802C4B50 24020002 */  addiu $v0, $zero, 2
/* 0E9504 802C4B54 03E00008 */  jr    $ra
/* 0E9508 802C4B58 27BD0018 */   addiu $sp, $sp, 0x18

