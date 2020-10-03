.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005083C
/* 2BC3C 8005083C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2BC40 80050840 00051040 */  sll       $v0, $a1, 1
/* 2BC44 80050844 00451021 */  addu      $v0, $v0, $a1
/* 2BC48 80050848 00021140 */  sll       $v0, $v0, 5
/* 2BC4C 8005084C 2442025C */  addiu     $v0, $v0, 0x25c
/* 2BC50 80050850 00822821 */  addu      $a1, $a0, $v0
/* 2BC54 80050854 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2BC58 80050858 8CA20000 */  lw        $v0, ($a1)
/* 2BC5C 8005085C 10400004 */  beqz      $v0, .L80050870
/* 2BC60 80050860 00000000 */   nop      
/* 2BC64 80050864 A48600D4 */  sh        $a2, 0xd4($a0)
/* 2BC68 80050868 0C013FB4 */  jal       func_8004FED0
/* 2BC6C 8005086C A08700D6 */   sb       $a3, 0xd6($a0)
.L80050870:
/* 2BC70 80050870 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2BC74 80050874 03E00008 */  jr        $ra
/* 2BC78 80050878 27BD0018 */   addiu    $sp, $sp, 0x18
