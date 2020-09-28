.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CCCB0
/* F1660 802CCCB0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* F1664 802CCCB4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* F1668 802CCCB8 80420070 */  lb        $v0, 0x70($v0)
/* F166C 802CCCBC 14400005 */  bnez      $v0, .L802CCCD4
/* F1670 802CCCC0 00000000 */   nop      
/* F1674 802CCCC4 3C02802E */  lui       $v0, 0x802e
/* F1678 802CCCC8 2442ADF0 */  addiu     $v0, $v0, -0x5210
/* F167C 802CCCCC 080B3337 */  j         .L802CCCDC
/* F1680 802CCCD0 00000000 */   nop      
.L802CCCD4:
/* F1684 802CCCD4 3C02802E */  lui       $v0, 0x802e
/* F1688 802CCCD8 2442ADB0 */  addiu     $v0, $v0, -0x5250
.L802CCCDC:
/* F168C 802CCCDC 3C01802E */  lui       $at, 0x802e
/* F1690 802CCCE0 AC22AE30 */  sw        $v0, -0x51d0($at)
/* F1694 802CCCE4 03E00008 */  jr        $ra
/* F1698 802CCCE8 24020002 */   addiu    $v0, $zero, 2
