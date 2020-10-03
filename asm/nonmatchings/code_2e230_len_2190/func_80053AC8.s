.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053AC8
/* 2EEC8 80053AC8 8482000A */  lh        $v0, 0xa($a0)
/* 2EECC 80053ACC 14400005 */  bnez      $v0, .L80053AE4
/* 2EED0 80053AD0 24020001 */   addiu    $v0, $zero, 1
/* 2EED4 80053AD4 94830000 */  lhu       $v1, ($a0)
/* 2EED8 80053AD8 A482000A */  sh        $v0, 0xa($a0)
/* 2EEDC 80053ADC AC800004 */  sw        $zero, 4($a0)
/* 2EEE0 80053AE0 A4830008 */  sh        $v1, 8($a0)
.L80053AE4:
/* 2EEE4 80053AE4 03E00008 */  jr        $ra
/* 2EEE8 80053AE8 00000000 */   nop      
