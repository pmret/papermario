.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB69C_E2BDCC
/* E2BDCC 802BB69C 3C02802C */  lui       $v0, %hi(func_802BAE00_E2B530)
/* E2BDD0 802BB6A0 2442AE00 */  addiu     $v0, $v0, %lo(func_802BAE00_E2B530)
/* E2BDD4 802BB6A4 3C030A00 */  lui       $v1, 0xa00
/* E2BDD8 802BB6A8 24631AC8 */  addiu     $v1, $v1, 0x1ac8
/* E2BDDC 802BB6AC 3063FFFF */  andi      $v1, $v1, 0xffff
/* E2BDE0 802BB6B0 AC82003C */  sw        $v0, 0x3c($a0)
/* E2BDE4 802BB6B4 8C820044 */  lw        $v0, 0x44($a0)
/* E2BDE8 802BB6B8 8C840040 */  lw        $a0, 0x40($a0)
/* E2BDEC 802BB6BC 00431021 */  addu      $v0, $v0, $v1
/* E2BDF0 802BB6C0 AC820014 */  sw        $v0, 0x14($a0)
/* E2BDF4 802BB6C4 3C020A00 */  lui       $v0, 0xa00
/* E2BDF8 802BB6C8 24421B70 */  addiu     $v0, $v0, 0x1b70
/* E2BDFC 802BB6CC 03E00008 */  jr        $ra
/* E2BE00 802BB6D0 AC820018 */   sw       $v0, 0x18($a0)
