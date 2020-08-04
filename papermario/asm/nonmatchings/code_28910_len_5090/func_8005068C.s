.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8005068C
/* 02BA8C 8005068C 000411C3 */  sra   $v0, $a0, 7
/* 02BA90 80050690 30420007 */  andi  $v0, $v0, 7
/* 02BA94 80050694 000420C0 */  sll   $a0, $a0, 3
/* 02BA98 80050698 308400F8 */  andi  $a0, $a0, 0xf8
/* 02BA9C 8005069C 00441021 */  addu  $v0, $v0, $a0
/* 02BAA0 800506A0 30C600FF */  andi  $a2, $a2, 0xff
/* 02BAA4 800506A4 00C20018 */  mult  $a2, $v0
/* 02BAA8 800506A8 30A500FF */  andi  $a1, $a1, 0xff
/* 02BAAC 800506AC 00001812 */  mflo  $v1
/* 02BAB0 800506B0 34028000 */  ori   $v0, $zero, 0x8000
/* 02BAB4 800506B4 00431023 */  subu  $v0, $v0, $v1
/* 02BAB8 800506B8 00A20018 */  mult  $a1, $v0
/* 02BABC 800506BC 00001812 */  mflo  $v1
/* 02BAC0 800506C0 03E00008 */  jr    $ra
/* 02BAC4 800506C4 306200FF */   andi  $v0, $v1, 0xff

