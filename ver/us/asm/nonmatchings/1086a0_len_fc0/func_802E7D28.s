.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7D28
/* 1095A8 802E7D28 8C830040 */  lw        $v1, 0x40($a0)
/* 1095AC 802E7D2C 2402FFFF */  addiu     $v0, $zero, -1
/* 1095B0 802E7D30 03E00008 */  jr        $ra
/* 1095B4 802E7D34 AC620010 */   sw       $v0, 0x10($v1)
