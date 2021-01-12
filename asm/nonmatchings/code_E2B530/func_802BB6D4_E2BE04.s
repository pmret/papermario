.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB6D4_E2BE04
/* E2BE04 802BB6D4 3C02802C */  lui       $v0, %hi(func_802BAE00_E2B530)
/* E2BE08 802BB6D8 2442AE00 */  addiu     $v0, $v0, %lo(func_802BAE00_E2B530)
/* E2BE0C 802BB6DC 3C030A00 */  lui       $v1, 0xa00
/* E2BE10 802BB6E0 24631AC8 */  addiu     $v1, $v1, 0x1ac8
/* E2BE14 802BB6E4 3063FFFF */  andi      $v1, $v1, 0xffff
/* E2BE18 802BB6E8 AC82003C */  sw        $v0, 0x3c($a0)
/* E2BE1C 802BB6EC 8C820044 */  lw        $v0, 0x44($a0)
/* E2BE20 802BB6F0 8C840040 */  lw        $a0, 0x40($a0)
/* E2BE24 802BB6F4 00431021 */  addu      $v0, $v0, $v1
/* E2BE28 802BB6F8 AC820014 */  sw        $v0, 0x14($a0)
/* E2BE2C 802BB6FC 3C020A00 */  lui       $v0, 0xa00
/* E2BE30 802BB700 24421B70 */  addiu     $v0, $v0, 0x1b70
/* E2BE34 802BB704 03E00008 */  jr        $ra
/* E2BE38 802BB708 AC820018 */   sw       $v0, 0x18($a0)
/* E2BE3C 802BB70C 00000000 */  nop       
