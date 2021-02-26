.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055DF4
/* 311F4 80055DF4 3C02800A */  lui       $v0, %hi(D_8009A5A0)
/* 311F8 80055DF8 8C42A5A0 */  lw        $v0, %lo(D_8009A5A0)($v0)
/* 311FC 80055DFC 00052880 */  sll       $a1, $a1, 2
/* 31200 80055E00 00451021 */  addu      $v0, $v0, $a1
/* 31204 80055E04 03E00008 */  jr        $ra
/* 31208 80055E08 AC4400A4 */   sw       $a0, 0xa4($v0)
