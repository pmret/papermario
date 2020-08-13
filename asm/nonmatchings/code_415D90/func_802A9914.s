.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A9914
/* 41E6A4 802A9914 0C0AA072 */  jal   update_partner_menu
/* 41E6A8 802A9918 00000000 */   nop   
/* 41E6AC 802A991C 080AA6AB */  j     .L802A9AAC
/* 41E6B0 802A9920 00000000 */   nop   

.L802A9924:
/* 41E6B4 802A9924 A682006C */  sh    $v0, 0x6c($s4)
/* 41E6B8 802A9928 8642032C */  lh    $v0, 0x32c($s2)
