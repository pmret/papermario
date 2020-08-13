.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249290
/* 13C5D0 80249290 0C05272D */  jal   play_sound
/* 13C5D4 80249294 240400C8 */   addiu $a0, $zero, 0xc8
/* 13C5D8 80249298 8E040000 */  lw    $a0, ($s0)
/* 13C5DC 8024929C 0C092363 */  jal   func_80248D8C
/* 13C5E0 802492A0 00000000 */   nop   
/* 13C5E4 802492A4 08092543 */  j     func_8024950C
/* 13C5E8 802492A8 00000000 */   nop   

.L802492AC:
/* 13C5EC 802492AC 3C038027 */  lui   $v1, 0x8027
/* 13C5F0 802492B0 8C6300C0 */  lw    $v1, 0xc0($v1)
