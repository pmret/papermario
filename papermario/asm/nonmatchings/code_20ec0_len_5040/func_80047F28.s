.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80047F28
/* 023328 80047F28 00041040 */  sll   $v0, $a0, 1
/* 02332C 80047F2C 00441021 */  addu  $v0, $v0, $a0
/* 023330 80047F30 00021080 */  sll   $v0, $v0, 2
/* 023334 80047F34 00441023 */  subu  $v0, $v0, $a0
/* 023338 80047F38 3C03800A */  lui   $v1, 0x800a
/* 02333C 80047F3C 8C630F44 */  lw    $v1, 0xf44($v1)
/* 023340 80047F40 00021100 */  sll   $v0, $v0, 4
/* 023344 80047F44 00621821 */  addu  $v1, $v1, $v0
/* 023348 80047F48 8C620000 */  lw    $v0, ($v1)
/* 02334C 80047F4C 34420100 */  ori   $v0, $v0, 0x100
/* 023350 80047F50 03E00008 */  jr    $ra
/* 023354 80047F54 AC620000 */   sw    $v0, ($v1)

