.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_shadow_callback
/* 102610 802E0D90 3C013DCC */  lui       $at, 0x3dcc
/* 102614 802E0D94 3421CCCD */  ori       $at, $at, 0xcccd
/* 102618 802E0D98 44810000 */  mtc1      $at, $f0
/* 10261C 802E0D9C 00000000 */  nop
/* 102620 802E0DA0 E480001C */  swc1      $f0, 0x1c($a0)
/* 102624 802E0DA4 E4800020 */  swc1      $f0, 0x20($a0)
/* 102628 802E0DA8 03E00008 */  jr        $ra
/* 10262C 802E0DAC E4800024 */   swc1     $f0, 0x24($a0)
