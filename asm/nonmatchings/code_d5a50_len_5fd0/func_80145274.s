.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80145274
/* 0DB974 80145274 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB978 80145278 00822024 */  and   $a0, $a0, $v0
/* 0DB97C 8014527C 3C028015 */  lui   $v0, 0x8015
/* 0DB980 80145280 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DB984 80145284 00042080 */  sll   $a0, $a0, 2
/* 0DB988 80145288 00822021 */  addu  $a0, $a0, $v0
/* 0DB98C 8014528C 8C840000 */  lw    $a0, ($a0)
/* 0DB990 80145290 8C820000 */  lw    $v0, ($a0)
/* 0DB994 80145294 3C030001 */  lui   $v1, 1
/* 0DB998 80145298 00431024 */  and   $v0, $v0, $v1
/* 0DB99C 8014529C 10400003 */  beqz  $v0, .L801452AC
/* 0DB9A0 801452A0 8C83001C */   lw    $v1, 0x1c($a0)
/* 0DB9A4 801452A4 A4650028 */  sh    $a1, 0x28($v1)
/* 0DB9A8 801452A8 A466002A */  sh    $a2, 0x2a($v1)
.L801452AC:
/* 0DB9AC 801452AC 03E00008 */  jr    $ra
/* 0DB9B0 801452B0 00000000 */   nop   

