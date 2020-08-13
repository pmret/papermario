.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_L
/* 7E1CB8 80280E38 00000000 */   nop   
/* 7E1CBC 80280E3C 0C0A005F */  jal   func_8028017C
/* 7E1CC0 80280E40 2404000C */   addiu $a0, $zero, 0xc
/* 7E1CC4 80280E44 080A04EE */  j     .L802813B8
/* 7E1CC8 80280E48 AE220074 */   sw    $v0, 0x74($s1)

.L80280E4C:
/* 7E1CCC 80280E4C 0C039E12 */  jal   get_stored_empty_count
/* 7E1CD0 80280E50 00000000 */   nop   
