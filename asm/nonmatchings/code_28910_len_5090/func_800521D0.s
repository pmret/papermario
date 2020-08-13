.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800521D0
/* 02D5D0 800521D0 8C830008 */  lw    $v1, 8($a0)
/* 02D5D4 800521D4 90620000 */  lbu   $v0, ($v1)
/* 02D5D8 800521D8 24630001 */  addiu $v1, $v1, 1
/* 02D5DC 800521DC AC830008 */  sw    $v1, 8($a0)
/* 02D5E0 800521E0 03E00008 */  jr    $ra
/* 02D5E4 800521E4 304200FF */   andi  $v0, $v0, 0xff

