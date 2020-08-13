.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800478F8
/* 022CF8 800478F8 00041040 */  sll   $v0, $a0, 1
/* 022CFC 800478FC 00441021 */  addu  $v0, $v0, $a0
/* 022D00 80047900 00021080 */  sll   $v0, $v0, 2
/* 022D04 80047904 00441023 */  subu  $v0, $v0, $a0
/* 022D08 80047908 3C03800A */  lui   $v1, 0x800a
/* 022D0C 8004790C 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022D10 80047910 00021100 */  sll   $v0, $v0, 4
/* 022D14 80047914 00621821 */  addu  $v1, $v1, $v0
/* 022D18 80047918 8C620000 */  lw    $v0, ($v1)
/* 022D1C 8004791C 34420004 */  ori   $v0, $v0, 4
/* 022D20 80047920 03E00008 */  jr    $ra
/* 022D24 80047924 AC620000 */   sw    $v0, ($v1)

