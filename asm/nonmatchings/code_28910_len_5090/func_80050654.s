.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80050654
/* 02BA54 80050654 00041203 */  sra   $v0, $a0, 8
/* 02BA58 80050658 3042001F */  andi  $v0, $v0, 0x1f
/* 02BA5C 8005065C 308400E0 */  andi  $a0, $a0, 0xe0
/* 02BA60 80050660 00441021 */  addu  $v0, $v0, $a0
/* 02BA64 80050664 30C600FF */  andi  $a2, $a2, 0xff
/* 02BA68 80050668 00C20018 */  mult  $a2, $v0
/* 02BA6C 8005066C 30A500FF */  andi  $a1, $a1, 0xff
/* 02BA70 80050670 00001812 */  mflo  $v1
/* 02BA74 80050674 34028000 */  ori   $v0, $zero, 0x8000
/* 02BA78 80050678 00431023 */  subu  $v0, $v0, $v1
/* 02BA7C 8005067C 00A20018 */  mult  $a1, $v0
/* 02BA80 80050680 00001812 */  mflo  $v1
/* 02BA84 80050684 03E00008 */  jr    $ra
/* 02BA88 80050688 306200FF */   andi  $v0, $v1, 0xff

