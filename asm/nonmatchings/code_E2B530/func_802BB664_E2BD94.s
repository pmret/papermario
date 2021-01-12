.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB664_E2BD94
/* E2BD94 802BB664 3C02802C */  lui       $v0, %hi(func_802BAE00_E2B530)
/* E2BD98 802BB668 2442AE00 */  addiu     $v0, $v0, %lo(func_802BAE00_E2B530)
/* E2BD9C 802BB66C 3C030A00 */  lui       $v1, 0xa00
/* E2BDA0 802BB670 24631690 */  addiu     $v1, $v1, 0x1690
/* E2BDA4 802BB674 3063FFFF */  andi      $v1, $v1, 0xffff
/* E2BDA8 802BB678 AC82003C */  sw        $v0, 0x3c($a0)
/* E2BDAC 802BB67C 8C820044 */  lw        $v0, 0x44($a0)
/* E2BDB0 802BB680 8C840040 */  lw        $a0, 0x40($a0)
/* E2BDB4 802BB684 00431021 */  addu      $v0, $v0, $v1
/* E2BDB8 802BB688 AC820014 */  sw        $v0, 0x14($a0)
/* E2BDBC 802BB68C 3C020A00 */  lui       $v0, 0xa00
/* E2BDC0 802BB690 24421840 */  addiu     $v0, $v0, 0x1840
/* E2BDC4 802BB694 03E00008 */  jr        $ra
/* E2BDC8 802BB698 AC820018 */   sw       $v0, 0x18($a0)
