.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuContInit
/* 03AA10 8005F610 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03AA14 8005F614 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03AA18 8005F618 0C00B38C */  jal   nuSiMgrInit
/* 03AA1C 8005F61C AFB00010 */   sw    $s0, 0x10($sp)
/* 03AA20 8005F620 0C018144 */  jal   nuContMgrInit
/* 03AA24 8005F624 0040802D */   daddu $s0, $v0, $zero
/* 03AA28 8005F628 0C017DAC */  jal   nuContPakMgrInit
/* 03AA2C 8005F62C 00000000 */   nop   
/* 03AA30 8005F630 0C017F23 */  jal   nuContRmbMgrInit
/* 03AA34 8005F634 00000000 */   nop   
/* 03AA38 8005F638 320200FF */  andi  $v0, $s0, 0xff
/* 03AA3C 8005F63C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03AA40 8005F640 8FB00010 */  lw    $s0, 0x10($sp)
/* 03AA44 8005F644 03E00008 */  jr    $ra
/* 03AA48 8005F648 27BD0018 */   addiu $sp, $sp, 0x18

/* 03AA4C 8005F64C 00000000 */  nop   
