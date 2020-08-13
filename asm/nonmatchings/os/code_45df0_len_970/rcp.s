.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel rcp
/* 0460C8 8006ACC8 3C11A430 */  lui   $s1, 0xa430
/* 0460CC 8006ACCC 8E310008 */  lw    $s1, 8($s1)
/* 0460D0 8006ACD0 3C088009 */  lui   $t0, 0x8009
/* 0460D4 8006ACD4 25085900 */  addiu $t0, $t0, 0x5900
/* 0460D8 8006ACD8 8D080000 */  lw    $t0, ($t0)
/* 0460DC 8006ACDC 00084402 */  srl   $t0, $t0, 0x10
/* 0460E0 8006ACE0 02288824 */  and   $s1, $s1, $t0
/* 0460E4 8006ACE4 32290001 */  andi  $t1, $s1, 1
/* 0460E8 8006ACE8 11200014 */  beqz  $t1, .L8006AD3C
/* 0460EC 8006ACEC 00000000 */   nop   
/* 0460F0 8006ACF0 3231003E */  andi  $s1, $s1, 0x3e
/* 0460F4 8006ACF4 3C0CA404 */  lui   $t4, 0xa404
/* 0460F8 8006ACF8 8D8C0010 */  lw    $t4, 0x10($t4)
/* 0460FC 8006ACFC 34098008 */  ori   $t1, $zero, 0x8008
/* 046100 8006AD00 3C01A404 */  lui   $at, 0xa404
/* 046104 8006AD04 AC290010 */  sw    $t1, 0x10($at)
/* 046108 8006AD08 318C0300 */  andi  $t4, $t4, 0x300
/* 04610C 8006AD0C 11800007 */  beqz  $t4, .L8006AD2C
/* 046110 8006AD10 00000000 */   nop   
/* 046114 8006AD14 0C01ABDF */  jal   send_mesg
/* 046118 8006AD18 24040020 */   addiu $a0, $zero, 0x20
/* 04611C 8006AD1C 12200044 */  beqz  $s1, .L8006AE30
/* 046120 8006AD20 00000000 */   nop   
/* 046124 8006AD24 10000005 */  b     .L8006AD3C
/* 046128 8006AD28 00000000 */   nop   
