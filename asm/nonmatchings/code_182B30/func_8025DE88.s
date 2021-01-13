.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025DE88
/* 18C768 8025DE88 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 18C76C 8025DE8C 00052880 */  sll       $a1, $a1, 2
/* 18C770 8025DE90 00451021 */  addu      $v0, $v0, $a1
/* 18C774 8025DE94 8C4308B0 */  lw        $v1, 0x8b0($v0)
/* 18C778 8025DE98 8C620000 */  lw        $v0, ($v1)
/* 18C77C 8025DE9C 34420010 */  ori       $v0, $v0, 0x10
/* 18C780 8025DEA0 03E00008 */  jr        $ra
/* 18C784 8025DEA4 AC620000 */   sw       $v0, ($v1)
/* 18C788 8025DEA8 00000000 */  nop
/* 18C78C 8025DEAC 00000000 */  nop
