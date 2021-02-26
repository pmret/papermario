.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C6E0
/* 47AE0 8006C6E0 3C02A404 */  lui       $v0, 0xa404
/* 47AE4 8006C6E4 34420010 */  ori       $v0, $v0, 0x10
/* 47AE8 8006C6E8 8C420000 */  lw        $v0, ($v0)
/* 47AEC 8006C6EC 30420001 */  andi      $v0, $v0, 1
/* 47AF0 8006C6F0 10400004 */  beqz      $v0, .L8006C704
/* 47AF4 8006C6F4 3C02A408 */   lui      $v0, 0xa408
/* 47AF8 8006C6F8 AC440000 */  sw        $a0, ($v0)
/* 47AFC 8006C6FC 0801B1C2 */  j         .L8006C708
/* 47B00 8006C700 00001021 */   addu     $v0, $zero, $zero
.L8006C704:
/* 47B04 8006C704 2402FFFF */  addiu     $v0, $zero, -1
.L8006C708:
/* 47B08 8006C708 03E00008 */  jr        $ra
/* 47B0C 8006C70C 00000000 */   nop
