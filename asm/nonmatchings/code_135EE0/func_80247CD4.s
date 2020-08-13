.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247CD4
/* 13B014 80247CD4 000212C3 */   sra   $v0, $v0, 0xb
/* 13B018 80247CD8 3C0B8008 */  lui   $t3, 0x8008
/* 13B01C 80247CDC 256B78E0 */  addiu $t3, $t3, 0x78e0
