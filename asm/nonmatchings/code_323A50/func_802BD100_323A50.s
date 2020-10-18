.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_323A50
/* 323A50 802BD100 2402001A */  addiu     $v0, $zero, 0x1a
/* 323A54 802BD104 A48200A8 */  sh        $v0, 0xa8($a0)
/* 323A58 802BD108 24020018 */  addiu     $v0, $zero, 0x18
/* 323A5C 802BD10C A48200A6 */  sh        $v0, 0xa6($a0)
/* 323A60 802BD110 24020011 */  addiu     $v0, $zero, 0x11
/* 323A64 802BD114 A08200AA */  sb        $v0, 0xaa($a0)
/* 323A68 802BD118 3C01802C */  lui       $at, 0x802c
/* 323A6C 802BD11C AC20E0C4 */  sw        $zero, -0x1f3c($at)
/* 323A70 802BD120 3C01802C */  lui       $at, 0x802c
/* 323A74 802BD124 AC20E0C0 */  sw        $zero, -0x1f40($at)
/* 323A78 802BD128 03E00008 */  jr        $ra
/* 323A7C 802BD12C 00000000 */   nop      
