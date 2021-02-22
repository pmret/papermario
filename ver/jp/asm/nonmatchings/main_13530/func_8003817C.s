.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003817C
/* 1357C 8003817C 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 13580 80038180 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 13584 80038184 80420070 */  lb        $v0, 0x70($v0)
/* 13588 80038188 14400005 */  bnez      $v0, .L800381A0
/* 1358C 8003818C 00000000 */   nop
/* 13590 80038190 3C02800A */  lui       $v0, %hi(D_8009E7A0)
/* 13594 80038194 2442E7A0 */  addiu     $v0, $v0, %lo(D_8009E7A0)
/* 13598 80038198 0800E06A */  j         .L800381A8
/* 1359C 8003819C 00000000 */   nop
.L800381A0:
/* 135A0 800381A0 3C02800A */  lui       $v0, %hi(D_8009E8A0)
/* 135A4 800381A4 2442E8A0 */  addiu     $v0, $v0, %lo(D_8009E8A0)
.L800381A8:
/* 135A8 800381A8 3C01800A */  lui       $at, %hi(D_8009E9A0)
/* 135AC 800381AC AC22E9A0 */  sw        $v0, %lo(D_8009E9A0)($at)
/* 135B0 800381B0 3C02800A */  lui       $v0, %hi(D_8009E9A0)
/* 135B4 800381B4 8C42E9A0 */  lw        $v0, %lo(D_8009E9A0)($v0)
/* 135B8 800381B8 2403003F */  addiu     $v1, $zero, 0x3f
/* 135BC 800381BC 244200FC */  addiu     $v0, $v0, 0xfc
.L800381C0:
/* 135C0 800381C0 AC400000 */  sw        $zero, ($v0)
/* 135C4 800381C4 2463FFFF */  addiu     $v1, $v1, -1
/* 135C8 800381C8 0461FFFD */  bgez      $v1, .L800381C0
/* 135CC 800381CC 2442FFFC */   addiu    $v0, $v0, -4
/* 135D0 800381D0 24020001 */  addiu     $v0, $zero, 1
/* 135D4 800381D4 3C01800A */  lui       $at, %hi(D_8009A5E4)
/* 135D8 800381D8 A420A5E4 */  sh        $zero, %lo(D_8009A5E4)($at)
/* 135DC 800381DC 3C01800A */  lui       $at, %hi(D_8009E9A4)
/* 135E0 800381E0 A022E9A4 */  sb        $v0, %lo(D_8009E9A4)($at)
/* 135E4 800381E4 03E00008 */  jr        $ra
/* 135E8 800381E8 00000000 */   nop
