.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4B10
/* 106390 802E4B10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106394 802E4B14 AFB00010 */  sw        $s0, 0x10($sp)
/* 106398 802E4B18 0080802D */  daddu     $s0, $a0, $zero
/* 10639C 802E4B1C AFBF0014 */  sw        $ra, 0x14($sp)
/* 1063A0 802E4B20 8E020040 */  lw        $v0, 0x40($s0)
/* 1063A4 802E4B24 0C04417A */  jal       get_entity_by_index
/* 1063A8 802E4B28 90440000 */   lbu      $a0, ($v0)
/* 1063AC 802E4B2C C4400048 */  lwc1      $f0, 0x48($v0)
/* 1063B0 802E4B30 3C014160 */  lui       $at, 0x4160
/* 1063B4 802E4B34 44811000 */  mtc1      $at, $f2
/* 1063B8 802E4B38 E6000048 */  swc1      $f0, 0x48($s0)
/* 1063BC 802E4B3C C440004C */  lwc1      $f0, 0x4c($v0)
/* 1063C0 802E4B40 46020000 */  add.s     $f0, $f0, $f2
/* 1063C4 802E4B44 E600004C */  swc1      $f0, 0x4c($s0)
/* 1063C8 802E4B48 C4400050 */  lwc1      $f0, 0x50($v0)
/* 1063CC 802E4B4C E6000050 */  swc1      $f0, 0x50($s0)
/* 1063D0 802E4B50 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1063D4 802E4B54 8FB00010 */  lw        $s0, 0x10($sp)
/* 1063D8 802E4B58 03E00008 */  jr        $ra
/* 1063DC 802E4B5C 27BD0018 */   addiu    $sp, $sp, 0x18
