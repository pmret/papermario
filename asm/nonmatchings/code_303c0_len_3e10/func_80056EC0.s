.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80056EC0
/* 0322C0 80056EC0 308400FF */  andi  $a0, $a0, 0xff
/* 0322C4 80056EC4 00041940 */  sll   $v1, $a0, 5
/* 0322C8 80056EC8 3C028008 */  lui   $v0, 0x8008
/* 0322CC 80056ECC 8C428E54 */  lw    $v0, -0x71ac($v0)
/* 0322D0 80056ED0 00641823 */  subu  $v1, $v1, $a0
/* 0322D4 80056ED4 8C42001C */  lw    $v0, 0x1c($v0)
/* 0322D8 80056ED8 00031880 */  sll   $v1, $v1, 2
/* 0322DC 80056EDC 00431021 */  addu  $v0, $v0, $v1
/* 0322E0 80056EE0 03E00008 */  jr    $ra
/* 0322E4 80056EE4 A0450078 */   sb    $a1, 0x78($v0)

