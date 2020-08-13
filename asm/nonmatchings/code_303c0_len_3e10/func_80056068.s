.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80056068
/* 031468 80056068 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03146C 8005606C 30A200FF */  andi  $v0, $a1, 0xff
/* 031470 80056070 3C057F00 */  lui   $a1, 0x7f00
/* 031474 80056074 AFBF0010 */  sw    $ra, 0x10($sp)
/* 031478 80056078 0C0141B2 */  jal   func_800506C8
/* 03147C 8005607C 00452825 */   or    $a1, $v0, $a1
/* 031480 80056080 8FBF0010 */  lw    $ra, 0x10($sp)
/* 031484 80056084 03E00008 */  jr    $ra
/* 031488 80056088 27BD0018 */   addiu $sp, $sp, 0x18

