.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel play_model_animation
/* 0B6848 80120148 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B684C 8012014C 00822024 */  and   $a0, $a0, $v0
/* 0B6850 80120150 3C028015 */  lui   $v0, 0x8015
/* 0B6854 80120154 8C423A40 */  lw    $v0, 0x3a40($v0)
/* 0B6858 80120158 00042080 */  sll   $a0, $a0, 2
/* 0B685C 8012015C 00822021 */  addu  $a0, $a0, $v0
/* 0B6860 80120160 8C840000 */  lw    $a0, ($a0)
/* 0B6864 80120164 8C8300DC */  lw    $v1, 0xdc($a0)
/* 0B6868 80120168 10600004 */  beqz  $v1, .L8012017C
/* 0B686C 8012016C 3C0200FF */   lui   $v0, 0xff
/* 0B6870 80120170 3442FFFF */  ori   $v0, $v0, 0xffff
/* 0B6874 80120174 00A21024 */  and   $v0, $a1, $v0
/* 0B6878 80120178 00432821 */  addu  $a1, $v0, $v1
.L8012017C:
/* 0B687C 8012017C 3C013F80 */  lui   $at, 0x3f80
/* 0B6880 80120180 44810000 */  mtc1  $at, $f0
/* 0B6884 80120184 AC850008 */  sw    $a1, 8($a0)
/* 0B6888 80120188 AC85000C */  sw    $a1, 0xc($a0)
/* 0B688C 8012018C AC8002CC */  sw    $zero, 0x2cc($a0)
/* 0B6890 80120190 03E00008 */  jr    $ra
/* 0B6894 80120194 E4800090 */   swc1  $f0, 0x90($a0)

