.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B3F8
/* 167F8 8003B3F8 808200B4 */  lb        $v0, 0xb4($a0)
/* 167FC 8003B3FC 908300B4 */  lbu       $v1, 0xb4($a0)
/* 16800 8003B400 10450005 */  beq       $v0, $a1, .L8003B418
/* 16804 8003B404 2402FFFF */   addiu    $v0, $zero, -1
/* 16808 8003B408 A08300B5 */  sb        $v1, 0xb5($a0)
/* 1680C 8003B40C A08500B4 */  sb        $a1, 0xb4($a0)
/* 16810 8003B410 A08000B7 */  sb        $zero, 0xb7($a0)
/* 16814 8003B414 A08200B6 */  sb        $v0, 0xb6($a0)
.L8003B418:
/* 16818 8003B418 03E00008 */  jr        $ra
/* 1681C 8003B41C 00000000 */   nop      
