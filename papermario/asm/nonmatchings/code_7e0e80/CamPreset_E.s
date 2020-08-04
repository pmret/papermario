.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_E
/* 7E1C64 80280DE4 24040005 */   addiu $a0, $zero, 5
/* 7E1C68 80280DE8 AE220074 */  sw    $v0, 0x74($s1)
/* 7E1C6C 80280DEC 080A0505 */  j     .L80281414
/* 7E1C70 80280DF0 AE200070 */   sw    $zero, 0x70($s1)

.L80280DF4:
/* 7E1C74 80280DF4 0C039D7B */  jal   get_item_count
/* 7E1C78 80280DF8 00000000 */   nop   
/* 7E1C7C 80280DFC 14400005 */  bnez  $v0, .L80280E14
