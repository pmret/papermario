.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BA00
/* 6E00 8002BA00 3C014000 */  lui       $at, 0x4000
/* 6E04 8002BA04 44810000 */  mtc1      $at, $f0
/* 6E08 8002BA08 3C01800A */  lui       $at, %hi(D_8009BA80)
/* 6E0C 8002BA0C AC20BA80 */  sw        $zero, %lo(D_8009BA80)($at)
/* 6E10 8002BA10 3C01800A */  lui       $at, %hi(D_8009BA78)
/* 6E14 8002BA14 AC20BA78 */  sw        $zero, %lo(D_8009BA78)($at)
/* 6E18 8002BA18 3C01800A */  lui       $at, %hi(D_8009BA7C)
/* 6E1C 8002BA1C AC20BA7C */  sw        $zero, %lo(D_8009BA7C)($at)
/* 6E20 8002BA20 3C01800A */  lui       $at, %hi(D_8009BA70)
/* 6E24 8002BA24 E420BA70 */  swc1      $f0, %lo(D_8009BA70)($at)
/* 6E28 8002BA28 3C01800A */  lui       $at, %hi(D_8009BA74)
/* 6E2C 8002BA2C E420BA74 */  swc1      $f0, %lo(D_8009BA74)($at)
/* 6E30 8002BA30 03E00008 */  jr        $ra
/* 6E34 8002BA34 00000000 */   nop
