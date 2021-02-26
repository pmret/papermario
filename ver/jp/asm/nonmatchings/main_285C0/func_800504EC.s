.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800504EC
/* 2B8EC 800504EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2B8F0 800504F0 00051040 */  sll       $v0, $a1, 1
/* 2B8F4 800504F4 00451021 */  addu      $v0, $v0, $a1
/* 2B8F8 800504F8 00021140 */  sll       $v0, $v0, 5
/* 2B8FC 800504FC 2442025C */  addiu     $v0, $v0, 0x25c
/* 2B900 80050500 00822821 */  addu      $a1, $a0, $v0
/* 2B904 80050504 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2B908 80050508 8CA20000 */  lw        $v0, ($a1)
/* 2B90C 8005050C 10400004 */  beqz      $v0, .L80050520
/* 2B910 80050510 00000000 */   nop
/* 2B914 80050514 A48600D4 */  sh        $a2, 0xd4($a0)
/* 2B918 80050518 0C013EE0 */  jal       func_8004FB80
/* 2B91C 8005051C A08700D6 */   sb       $a3, 0xd6($a0)
.L80050520:
/* 2B920 80050520 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2B924 80050524 03E00008 */  jr        $ra
/* 2B928 80050528 27BD0018 */   addiu    $sp, $sp, 0x18
