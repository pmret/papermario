.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC3A8_E2CAD8
/* E2CAD8 802BC3A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2CADC 802BC3AC 3C050A00 */  lui       $a1, 0xa00
/* E2CAE0 802BC3B0 24A51660 */  addiu     $a1, $a1, 0x1660
/* E2CAE4 802BC3B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2CAE8 802BC3B8 8C820040 */  lw        $v0, 0x40($a0)
/* E2CAEC 802BC3BC C480004C */  lwc1      $f0, 0x4c($a0)
/* E2CAF0 802BC3C0 3C060A00 */  lui       $a2, 0xa00
/* E2CAF4 802BC3C4 24C61118 */  addiu     $a2, $a2, 0x1118
/* E2CAF8 802BC3C8 0C0AF080 */  jal       func_802BC200_E2C930
/* E2CAFC 802BC3CC E4400004 */   swc1     $f0, 4($v0)
/* E2CB00 802BC3D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2CB04 802BC3D4 03E00008 */  jr        $ra
/* E2CB08 802BC3D8 27BD0018 */   addiu    $sp, $sp, 0x18
