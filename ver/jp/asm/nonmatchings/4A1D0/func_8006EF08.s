.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006EF08
/* 4A308 8006EF08 00047440 */  sll       $t6, $a0, 0x11
/* 4A30C 8006EF0C 3C010800 */  lui       $at, 0x800
/* 4A310 8006EF10 01C17821 */  addu      $t7, $t6, $at
/* 4A314 8006EF14 3C01A000 */  lui       $at, 0xa000
/* 4A318 8006EF18 01E1C025 */  or        $t8, $t7, $at
/* 4A31C 8006EF1C 3C01800B */  lui       $at, %hi(D_800B0C5C)
/* 4A320 8006EF20 AC380C5C */  sw        $t8, %lo(D_800B0C5C)($at)
/* 4A324 8006EF24 24990008 */  addiu     $t9, $a0, 8
/* 4A328 8006EF28 3C01800B */  lui       $at, %hi(D_800B0C54)
/* 4A32C 8006EF2C A0390C54 */  sb        $t9, %lo(D_800B0C54)($at)
/* 4A330 8006EF30 03E00008 */  jr        $ra
/* 4A334 8006EF34 00000000 */   nop
