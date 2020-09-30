.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_init_HammerBlock_small
/* 1056B0 802E3E30 2403FFFF */  addiu     $v1, $zero, -1
/* 1056B4 802E3E34 8C820040 */  lw        $v0, 0x40($a0)
/* 1056B8 802E3E38 3C05FFDF */  lui       $a1, 0xffdf
/* 1056BC 802E3E3C A4430010 */  sh        $v1, 0x10($v0)
/* 1056C0 802E3E40 C480004C */  lwc1      $f0, 0x4c($a0)
/* 1056C4 802E3E44 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 1056C8 802E3E48 A443000E */  sh        $v1, 0xe($v0)
/* 1056CC 802E3E4C E4400014 */  swc1      $f0, 0x14($v0)
/* 1056D0 802E3E50 8C820000 */  lw        $v0, ($a0)
/* 1056D4 802E3E54 3C013F00 */  lui       $at, 0x3f00
/* 1056D8 802E3E58 44810000 */  mtc1      $at, $f0
/* 1056DC 802E3E5C 00451024 */  and       $v0, $v0, $a1
/* 1056E0 802E3E60 E4800054 */  swc1      $f0, 0x54($a0)
/* 1056E4 802E3E64 E4800058 */  swc1      $f0, 0x58($a0)
/* 1056E8 802E3E68 E480005C */  swc1      $f0, 0x5c($a0)
/* 1056EC 802E3E6C 03E00008 */  jr        $ra
/* 1056F0 802E3E70 AC820000 */   sw       $v0, ($a0)
/* 1056F4 802E3E74 00000000 */  nop       
/* 1056F8 802E3E78 00000000 */  nop       
/* 1056FC 802E3E7C 00000000 */  nop       
