.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_init_Hammer23Block_normal
/* 104F64 802E36E4 8C820040 */  lw        $v0, 0x40($a0)
/* 104F68 802E36E8 2403FFFF */  addiu     $v1, $zero, -1
/* 104F6C 802E36EC A4430010 */  sh        $v1, 0x10($v0)
/* 104F70 802E36F0 C480004C */  lwc1      $f0, 0x4c($a0)
/* 104F74 802E36F4 3C05FFDF */  lui       $a1, 0xffdf
/* 104F78 802E36F8 A443000E */  sh        $v1, 0xe($v0)
/* 104F7C 802E36FC E4400014 */  swc1      $f0, 0x14($v0)
/* 104F80 802E3700 8C820000 */  lw        $v0, ($a0)
/* 104F84 802E3704 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 104F88 802E3708 00451024 */  and       $v0, $v0, $a1
/* 104F8C 802E370C 03E00008 */  jr        $ra
/* 104F90 802E3710 AC820000 */   sw       $v0, ($a0)
