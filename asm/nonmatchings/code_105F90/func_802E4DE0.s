.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4DE0
/* 106660 802E4DE0 8C820040 */  lw        $v0, 0x40($a0)
/* 106664 802E4DE4 3C013F80 */  lui       $at, 0x3f80
/* 106668 802E4DE8 44810000 */  mtc1      $at, $f0
/* 10666C 802E4DEC A0400001 */  sb        $zero, 1($v0)
/* 106670 802E4DF0 E4800054 */  swc1      $f0, 0x54($a0)
/* 106674 802E4DF4 E4800058 */  swc1      $f0, 0x58($a0)
/* 106678 802E4DF8 E480005C */  swc1      $f0, 0x5c($a0)
/* 10667C 802E4DFC 03E00008 */  jr        $ra
/* 106680 802E4E00 AC800068 */   sw       $zero, 0x68($a0)
