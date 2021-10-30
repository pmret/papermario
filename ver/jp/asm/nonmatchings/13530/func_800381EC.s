.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800381EC
/* 135EC 800381EC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 135F0 800381F0 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 135F4 800381F4 80420070 */  lb        $v0, 0x70($v0)
/* 135F8 800381F8 14400005 */  bnez      $v0, .L80038210
/* 135FC 800381FC 00000000 */   nop
/* 13600 80038200 3C02800A */  lui       $v0, %hi(D_8009E7A0)
/* 13604 80038204 2442E7A0 */  addiu     $v0, $v0, %lo(D_8009E7A0)
/* 13608 80038208 0800E086 */  j         .L80038218
/* 1360C 8003820C 00000000 */   nop
.L80038210:
/* 13610 80038210 3C02800A */  lui       $v0, %hi(D_8009E8A0)
/* 13614 80038214 2442E8A0 */  addiu     $v0, $v0, %lo(D_8009E8A0)
.L80038218:
/* 13618 80038218 3C01800A */  lui       $at, %hi(D_8009E9A0)
/* 1361C 8003821C AC22E9A0 */  sw        $v0, %lo(D_8009E9A0)($at)
/* 13620 80038220 24020001 */  addiu     $v0, $zero, 1
/* 13624 80038224 3C01800A */  lui       $at, %hi(D_8009A5E4)
/* 13628 80038228 A420A5E4 */  sh        $zero, %lo(D_8009A5E4)($at)
/* 1362C 8003822C 3C01800A */  lui       $at, %hi(D_8009E9A4)
/* 13630 80038230 A022E9A4 */  sb        $v0, %lo(D_8009E9A4)($at)
/* 13634 80038234 03E00008 */  jr        $ra
/* 13638 80038238 00000000 */   nop
