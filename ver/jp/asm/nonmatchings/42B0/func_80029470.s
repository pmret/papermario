.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029470
/* 4870 80029470 04800002 */  bltz      $a0, .L8002947C
/* 4874 80029474 2402FFFF */   addiu    $v0, $zero, -1
/* 4878 80029478 0004102A */  slt       $v0, $zero, $a0
.L8002947C:
/* 487C 8002947C 03E00008 */  jr        $ra
/* 4880 80029480 00000000 */   nop
