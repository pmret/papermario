.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B420
/* 16820 8003B420 808200B5 */  lb        $v0, 0xb5($a0)
/* 16824 8003B424 908300B5 */  lbu       $v1, 0xb5($a0)
/* 16828 8003B428 14400003 */  bnez      $v0, .L8003B438
/* 1682C 8003B42C 24020001 */   addiu    $v0, $zero, 1
/* 16830 8003B430 03E00008 */  jr        $ra
/* 16834 8003B434 A08000B4 */   sb       $zero, 0xb4($a0)
.L8003B438:
/* 16838 8003B438 A08300B4 */  sb        $v1, 0xb4($a0)
/* 1683C 8003B43C A08000B5 */  sb        $zero, 0xb5($a0)
/* 16840 8003B440 A08000B7 */  sb        $zero, 0xb7($a0)
/* 16844 8003B444 03E00008 */  jr        $ra
/* 16848 8003B448 A08200B6 */   sb       $v0, 0xb6($a0)
