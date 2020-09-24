.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E176C
/* 102FEC 802E176C 8C820040 */  lw        $v0, 0x40($a0)
/* 102FF0 802E1770 3C013F80 */  lui       $at, 0x3f80
/* 102FF4 802E1774 44810000 */  mtc1      $at, $f0
/* 102FF8 802E1778 3C013DCC */  lui       $at, 0x3dcc
/* 102FFC 802E177C 3421CCCD */  ori       $at, $at, 0xcccd
/* 103000 802E1780 44811000 */  mtc1      $at, $f2
/* 103004 802E1784 3C01BDCC */  lui       $at, 0xbdcc
/* 103008 802E1788 3421CCCD */  ori       $at, $at, 0xcccd
/* 10300C 802E178C 44812000 */  mtc1      $at, $f4
/* 103010 802E1790 E4400000 */  swc1      $f0, ($v0)
/* 103014 802E1794 E4420004 */  swc1      $f2, 4($v0)
/* 103018 802E1798 E4440008 */  swc1      $f4, 8($v0)
/* 10301C 802E179C A0400010 */  sb        $zero, 0x10($v0)
/* 103020 802E17A0 03E00008 */  jr        $ra
/* 103024 802E17A4 A0400011 */   sb       $zero, 0x11($v0)
