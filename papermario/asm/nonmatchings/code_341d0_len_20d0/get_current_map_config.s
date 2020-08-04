.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_current_map_config
/* 035FD8 8005ABD8 3C02800A */  lui   $v0, 0x800a
/* 035FDC 8005ABDC 8C4241E0 */  lw    $v0, 0x41e0($v0)
/* 035FE0 8005ABE0 03E00008 */  jr    $ra
/* 035FE4 8005ABE4 00000000 */   nop   

