.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056144
/* 31544 80056144 3C02800A */  lui       $v0, %hi(D_8009A5C0)
/* 31548 80056148 8C42A5C0 */  lw        $v0, %lo(D_8009A5C0)($v0)
/* 3154C 8005614C 00052880 */  sll       $a1, $a1, 2
/* 31550 80056150 00451021 */  addu      $v0, $v0, $a1
/* 31554 80056154 03E00008 */  jr        $ra
/* 31558 80056158 AC4400A4 */   sw       $a0, 0xa4($v0)
