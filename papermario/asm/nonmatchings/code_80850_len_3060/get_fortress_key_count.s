.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_fortress_key_count
/* 083894 800EA3E4 3C028011 */  lui   $v0, 0x8011
/* 083898 800EA3E8 8042F29E */  lb    $v0, -0xd62($v0)
/* 08389C 800EA3EC 03E00008 */  jr    $ra
/* 0838A0 800EA3F0 00000000 */   nop   

/* 0838A4 800EA3F4 00000000 */  nop   
/* 0838A8 800EA3F8 00000000 */  nop   
/* 0838AC 800EA3FC 00000000 */  nop   
