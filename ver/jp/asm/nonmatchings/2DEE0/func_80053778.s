.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053778
/* 2EB78 80053778 8482000A */  lh        $v0, 0xa($a0)
/* 2EB7C 8005377C 14400005 */  bnez      $v0, .L80053794
/* 2EB80 80053780 24020001 */   addiu    $v0, $zero, 1
/* 2EB84 80053784 94830000 */  lhu       $v1, ($a0)
/* 2EB88 80053788 A482000A */  sh        $v0, 0xa($a0)
/* 2EB8C 8005378C AC800004 */  sw        $zero, 4($a0)
/* 2EB90 80053790 A4830008 */  sh        $v1, 8($a0)
.L80053794:
/* 2EB94 80053794 03E00008 */  jr        $ra
/* 2EB98 80053798 00000000 */   nop
