.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800477F4
/* 022BF4 800477F4 00041040 */  sll   $v0, $a0, 1
/* 022BF8 800477F8 00441021 */  addu  $v0, $v0, $a0
/* 022BFC 800477FC 00021080 */  sll   $v0, $v0, 2
/* 022C00 80047800 00441023 */  subu  $v0, $v0, $a0
/* 022C04 80047804 3C03800A */  lui   $v1, 0x800a
/* 022C08 80047808 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022C0C 8004780C 00021100 */  sll   $v0, $v0, 4
/* 022C10 80047810 00621821 */  addu  $v1, $v1, $v0
/* 022C14 80047814 AC650030 */  sw    $a1, 0x30($v1)
/* 022C18 80047818 03E00008 */  jr    $ra
/* 022C1C 8004781C AC660034 */   sw    $a2, 0x34($v1)

