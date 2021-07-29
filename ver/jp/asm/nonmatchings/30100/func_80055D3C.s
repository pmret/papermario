.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055D3C
/* 3113C 80055D3C 3C02800A */  lui       $v0, %hi(D_8009A5A0)
/* 31140 80055D40 8C42A5A0 */  lw        $v0, %lo(D_8009A5A0)($v0)
/* 31144 80055D44 8C430094 */  lw        $v1, 0x94($v0)
/* 31148 80055D48 AC830000 */  sw        $v1, ($a0)
/* 3114C 80055D4C 8C420098 */  lw        $v0, 0x98($v0)
/* 31150 80055D50 03E00008 */  jr        $ra
/* 31154 80055D54 ACA20000 */   sw       $v0, ($a1)
