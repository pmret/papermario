.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E234C
/* 103BCC 802E234C 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 103BD0 802E2350 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 103BD4 802E2354 3C060100 */  lui       $a2, 0x100
/* 103BD8 802E2358 8C830040 */  lw        $v1, 0x40($a0)
/* 103BDC 802E235C 8CA20004 */  lw        $v0, 4($a1)
/* 103BE0 802E2360 3C013F80 */  lui       $at, 0x3f80
/* 103BE4 802E2364 44810000 */  mtc1      $at, $f0
/* 103BE8 802E2368 00461025 */  or        $v0, $v0, $a2
/* 103BEC 802E236C ACA20004 */  sw        $v0, 4($a1)
/* 103BF0 802E2370 E4600014 */  swc1      $f0, 0x14($v1)
/* 103BF4 802E2374 E4600018 */  swc1      $f0, 0x18($v1)
/* 103BF8 802E2378 03E00008 */  jr        $ra
/* 103BFC 802E237C E460001C */   swc1     $f0, 0x1c($v1)
