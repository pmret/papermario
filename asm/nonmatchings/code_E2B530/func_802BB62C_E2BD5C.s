.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB62C_E2BD5C
/* E2BD5C 802BB62C 3C02802C */  lui       $v0, %hi(func_802BAE00_E2B530)
/* E2BD60 802BB630 2442AE00 */  addiu     $v0, $v0, %lo(func_802BAE00_E2B530)
/* E2BD64 802BB634 3C030A00 */  lui       $v1, 0xa00
/* E2BD68 802BB638 24631EF8 */  addiu     $v1, $v1, 0x1ef8
/* E2BD6C 802BB63C 3063FFFF */  andi      $v1, $v1, 0xffff
/* E2BD70 802BB640 AC82003C */  sw        $v0, 0x3c($a0)
/* E2BD74 802BB644 8C820044 */  lw        $v0, 0x44($a0)
/* E2BD78 802BB648 8C840040 */  lw        $a0, 0x40($a0)
/* E2BD7C 802BB64C 00431021 */  addu      $v0, $v0, $v1
/* E2BD80 802BB650 AC820014 */  sw        $v0, 0x14($a0)
/* E2BD84 802BB654 3C020A00 */  lui       $v0, 0xa00
/* E2BD88 802BB658 24421FA0 */  addiu     $v0, $v0, 0x1fa0
/* E2BD8C 802BB65C 03E00008 */  jr        $ra
/* E2BD90 802BB660 AC820018 */   sw       $v0, 0x18($a0)
