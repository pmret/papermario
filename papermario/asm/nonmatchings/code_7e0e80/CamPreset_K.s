.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_K
/* 7E1C9C 80280E1C AE220074 */  sw    $v0, 0x74($s1)
/* 7E1CA0 80280E20 240200C9 */  addiu $v0, $zero, 0xc9
/* 7E1CA4 80280E24 080A0505 */  j     .L80281414
/* 7E1CA8 80280E28 AE220070 */   sw    $v0, 0x70($s1)

.L80280E2C:
/* 7E1CAC 80280E2C 0C039D7B */  jal   get_item_count
/* 7E1CB0 80280E30 00000000 */   nop   
/* 7E1CB4 80280E34 14400005 */  bnez  $v0, .L80280E4C
