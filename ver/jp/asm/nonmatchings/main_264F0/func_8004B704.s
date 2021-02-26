.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B704
/* 26B04 8004B704 14A00003 */  bnez      $a1, .L8004B714
/* 26B08 8004B708 24020001 */   addiu    $v0, $zero, 1
/* 26B0C 8004B70C 03E00008 */  jr        $ra
/* 26B10 8004B710 A08000C0 */   sb       $zero, 0xc0($a0)
.L8004B714:
/* 26B14 8004B714 50A20001 */  beql      $a1, $v0, .L8004B71C
/* 26B18 8004B718 A08500C0 */   sb       $a1, 0xc0($a0)
.L8004B71C:
/* 26B1C 8004B71C 03E00008 */  jr        $ra
/* 26B20 8004B720 00000000 */   nop
