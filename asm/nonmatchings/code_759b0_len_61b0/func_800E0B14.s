.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E0B14
/* 079FC4 800E0B14 3C02800F */  lui   $v0, 0x800f
/* 079FC8 800E0B18 8C427B30 */  lw    $v0, 0x7b30($v0)
/* 079FCC 800E0B1C 8C430004 */  lw    $v1, 4($v0)
/* 079FD0 800E0B20 2404FFEF */  addiu $a0, $zero, -0x11
/* 079FD4 800E0B24 3C018011 */  lui   $at, 0x8011
/* 079FD8 800E0B28 AC20C958 */  sw    $zero, -0x36a8($at)
/* 079FDC 800E0B2C 00641824 */  and   $v1, $v1, $a0
/* 079FE0 800E0B30 03E00008 */  jr    $ra
/* 079FE4 800E0B34 AC430004 */   sw    $v1, 4($v0)

