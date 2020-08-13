.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dp
.L8006AE0C:
/* 04620C 8006AE0C 32290020 */  andi  $t1, $s1, 0x20
/* 046210 8006AE10 11200007 */  beqz  $t1, .L8006AE30
/* 046214 8006AE14 00000000 */   nop   
/* 046218 8006AE18 3231001F */  andi  $s1, $s1, 0x1f
/* 04621C 8006AE1C 24090800 */  addiu $t1, $zero, 0x800
/* 046220 8006AE20 3C01A430 */  lui   $at, 0xa430
/* 046224 8006AE24 AC290000 */  sw    $t1, ($at)
/* 046228 8006AE28 0C01ABDF */  jal   send_mesg
/* 04622C 8006AE2C 24040048 */   addiu $a0, $zero, 0x48
