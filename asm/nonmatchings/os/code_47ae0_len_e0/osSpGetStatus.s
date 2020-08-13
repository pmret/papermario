.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSpGetStatus
/* 047AE0 8006C6E0 3C02A404 */  lui   $v0, 0xa404
/* 047AE4 8006C6E4 34420010 */  ori   $v0, $v0, 0x10
/* 047AE8 8006C6E8 03E00008 */  jr    $ra
/* 047AEC 8006C6EC 8C420000 */   lw    $v0, ($v0)

