.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osSpSetStatus
/* 047AF0 8006C6F0 3C02A404 */  lui   $v0, 0xa404
/* 047AF4 8006C6F4 34420010 */  ori   $v0, $v0, 0x10
/* 047AF8 8006C6F8 03E00008 */  jr    $ra
/* 047AFC 8006C6FC AC440000 */   sw    $a0, ($v0)

