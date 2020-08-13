.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_item_entity
/* 0C7658 80130F58 3C028015 */  lui   $v0, 0x8015
/* 0C765C 80130F5C 8C4265A0 */  lw    $v0, 0x65a0($v0)
/* 0C7660 80130F60 00042080 */  sll   $a0, $a0, 2
/* 0C7664 80130F64 00822021 */  addu  $a0, $a0, $v0
/* 0C7668 80130F68 03E00008 */  jr    $ra
/* 0C766C 80130F6C 8C820000 */   lw    $v0, ($a0)

