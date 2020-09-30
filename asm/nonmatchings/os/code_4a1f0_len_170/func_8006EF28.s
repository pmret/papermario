.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006EF28
/* 4A328 8006EF28 00047440 */  sll       $t6, $a0, 0x11
/* 4A32C 8006EF2C 3C010800 */  lui       $at, 0x800
/* 4A330 8006EF30 01C17821 */  addu      $t7, $t6, $at
/* 4A334 8006EF34 3C01A000 */  lui       $at, 0xa000
/* 4A338 8006EF38 01E1C025 */  or        $t8, $t7, $at
/* 4A33C 8006EF3C 3C01800B */  lui       $at, 0x800b
/* 4A340 8006EF40 AC380C7C */  sw        $t8, 0xc7c($at)
/* 4A344 8006EF44 24990008 */  addiu     $t9, $a0, 8
/* 4A348 8006EF48 3C01800B */  lui       $at, 0x800b
/* 4A34C 8006EF4C A0390C74 */  sb        $t9, 0xc74($at)
/* 4A350 8006EF50 03E00008 */  jr        $ra
/* 4A354 8006EF54 00000000 */   nop      
