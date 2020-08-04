.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802494AC
.L802494AC:
/* 13C7EC 802494AC 3C038027 */  lui   $v1, 0x8027
/* 13C7F0 802494B0 8C630280 */  lw    $v1, 0x280($v1)
/* 13C7F4 802494B4 00031040 */  sll   $v0, $v1, 1
/* 13C7F8 802494B8 00431021 */  addu  $v0, $v0, $v1
/* 13C7FC 802494BC 00021080 */  sll   $v0, $v0, 2
/* 13C800 802494C0 3C018027 */  lui   $at, 0x8027
/* 13C804 802494C4 00220821 */  addu  $at, $at, $v0
/* 13C808 802494C8 9022028A */  lbu   $v0, 0x28a($at)
/* 13C80C 802494CC 00A20018 */  mult  $a1, $v0
/* 13C810 802494D0 3C108027 */  lui   $s0, 0x8027
/* 13C814 802494D4 26100378 */  addiu $s0, $s0, 0x378
/* 13C818 802494D8 00005012 */  mflo  $t2
/* 13C81C 802494DC 010A1021 */  addu  $v0, $t0, $t2
/* 13C820 802494E0 10490003 */  beq   $v0, $t1, .L802494F0
/* 13C824 802494E4 AE020000 */   sw    $v0, ($s0)
/* 13C828 802494E8 0C05272D */  jal   play_sound
/* 13C82C 802494EC 240400C7 */   addiu $a0, $zero, 0xc7
.L802494F0:
/* 13C830 802494F0 8E020000 */  lw    $v0, ($s0)
/* 13C834 802494F4 00021040 */  sll   $v0, $v0, 1
/* 13C838 802494F8 3C018027 */  lui   $at, 0x8027
/* 13C83C 802494FC 00220821 */  addu  $at, $at, $v0
/* 13C840 80249500 84220180 */  lh    $v0, 0x180($at)
/* 13C844 80249504 3C018027 */  lui   $at, 0x8027
/* 13C848 80249508 AC220380 */  sw    $v0, 0x380($at)
