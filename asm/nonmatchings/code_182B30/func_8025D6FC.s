.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025D6FC
/* 18BFDC 8025D6FC 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 18BFE0 8025D700 00052880 */  sll       $a1, $a1, 2
/* 18BFE4 8025D704 00451021 */  addu      $v0, $v0, $a1
/* 18BFE8 8025D708 8C4308B0 */  lw        $v1, 0x8b0($v0)
/* 18BFEC 8025D70C 8C620000 */  lw        $v0, ($v1)
/* 18BFF0 8025D710 34420010 */  ori       $v0, $v0, 0x10
/* 18BFF4 8025D714 03E00008 */  jr        $ra
/* 18BFF8 8025D718 AC620000 */   sw       $v0, ($v1)
