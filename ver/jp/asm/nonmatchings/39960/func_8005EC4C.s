.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EC4C
/* 3A04C 8005EC4C 3C02800E */  lui       $v0, %hi(D_800DAA9C)
/* 3A050 8005EC50 03E00008 */  jr        $ra
/* 3A054 8005EC54 9042AA9C */   lbu      $v0, %lo(D_800DAA9C)($v0)
