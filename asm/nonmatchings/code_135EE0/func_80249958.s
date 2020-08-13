.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80249958
/* 13CC98 80249958 3C028027 */  lui   $v0, 0x8027
/* 13CC9C 8024995C 8C4205D4 */  lw    $v0, 0x5d4($v0)
/* 13CCA0 80249960 03E00008 */  jr    $ra
/* 13CCA4 80249964 00821023 */   subu  $v0, $a0, $v0

