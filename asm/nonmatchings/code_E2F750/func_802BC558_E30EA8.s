.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC558_E30EA8
/* E30EA8 802BC558 8C820040 */  lw        $v0, 0x40($a0)
/* E30EAC 802BC55C C4400008 */  lwc1      $f0, 8($v0)
/* E30EB0 802BC560 E4800048 */  swc1      $f0, 0x48($a0)
/* E30EB4 802BC564 C440000C */  lwc1      $f0, 0xc($v0)
/* E30EB8 802BC568 03E00008 */  jr        $ra
/* E30EBC 802BC56C E4800050 */   swc1     $f0, 0x50($a0)
