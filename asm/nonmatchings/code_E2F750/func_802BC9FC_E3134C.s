.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC9FC_E3134C
/* E3134C 802BC9FC 8C830040 */  lw        $v1, 0x40($a0)
/* E31350 802BCA00 C4800048 */  lwc1      $f0, 0x48($a0)
/* E31354 802BCA04 3C02802C */  lui       $v0, %hi(func_802BBE70_E307C0)
/* E31358 802BCA08 2442BE70 */  addiu     $v0, $v0, %lo(func_802BBE70_E307C0)
/* E3135C 802BCA0C AC82003C */  sw        $v0, 0x3c($a0)
/* E31360 802BCA10 E4600008 */  swc1      $f0, 8($v1)
/* E31364 802BCA14 C480004C */  lwc1      $f0, 0x4c($a0)
/* E31368 802BCA18 E4600010 */  swc1      $f0, 0x10($v1)
/* E3136C 802BCA1C C4800050 */  lwc1      $f0, 0x50($a0)
/* E31370 802BCA20 03E00008 */  jr        $ra
/* E31374 802BCA24 E460000C */   swc1     $f0, 0xc($v1)
/* E31378 802BCA28 00000000 */  nop
/* E3137C 802BCA2C 00000000 */  nop
