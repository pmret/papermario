.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8012363C
/* 0B9D3C 8012363C 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B9D40 80123640 00822024 */  and   $a0, $a0, $v0
/* 0B9D44 80123644 3C028015 */  lui   $v0, 0x8015
/* 0B9D48 80123648 8C424420 */  lw    $v0, 0x4420($v0)
/* 0B9D4C 8012364C 00042080 */  sll   $a0, $a0, 2
/* 0B9D50 80123650 00822021 */  addu  $a0, $a0, $v0
/* 0B9D54 80123654 03E00008 */  jr    $ra
/* 0B9D58 80123658 8C820000 */   lw    $v0, ($a0)

/* 0B9D5C 8012365C 00000000 */  nop   
