.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025D8EC
/* 18C1CC 8025D8EC 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 18C1D0 8025D8F0 00052880 */  sll       $a1, $a1, 2
/* 18C1D4 8025D8F4 00451021 */  addu      $v0, $v0, $a1
/* 18C1D8 8025D8F8 8C4308B0 */  lw        $v1, 0x8b0($v0)
/* 18C1DC 8025D8FC 8C620000 */  lw        $v0, ($v1)
/* 18C1E0 8025D900 34420010 */  ori       $v0, $v0, 0x10
/* 18C1E4 8025D904 03E00008 */  jr        $ra
/* 18C1E8 8025D908 AC620000 */   sw       $v0, ($v1)
