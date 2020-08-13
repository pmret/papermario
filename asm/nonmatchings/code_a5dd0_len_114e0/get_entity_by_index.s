.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_entity_by_index
/* 0A6CE8 801105E8 30840FFF */  andi  $a0, $a0, 0xfff
/* 0A6CEC 801105EC 3C028015 */  lui   $v0, 0x8015
/* 0A6CF0 801105F0 8C421470 */  lw    $v0, 0x1470($v0)
/* 0A6CF4 801105F4 00042080 */  sll   $a0, $a0, 2
/* 0A6CF8 801105F8 00822021 */  addu  $a0, $a0, $v0
/* 0A6CFC 801105FC 03E00008 */  jr    $ra
/* 0A6D00 80110600 8C820000 */   lw    $v0, ($a0)

