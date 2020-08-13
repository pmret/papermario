.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CamPreset_J
/* 7E1C80 80280E00 00000000 */   nop   
/* 7E1C84 80280E04 0C0A005F */  jal   func_8028017C
/* 7E1C88 80280E08 24040006 */   addiu $a0, $zero, 6
/* 7E1C8C 80280E0C 080A04EE */  j     .L802813B8
/* 7E1C90 80280E10 AE220074 */   sw    $v0, 0x74($s1)

.L80280E14:
/* 7E1C94 80280E14 0C0A005F */  jal   func_8028017C
/* 7E1C98 80280E18 24040007 */   addiu $a0, $zero, 7
