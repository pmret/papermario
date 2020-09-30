.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005608C
/* 3148C 8005608C 3C02800A */  lui       $v0, 0x800a
/* 31490 80056090 8C42A5C0 */  lw        $v0, -0x5a40($v0)
/* 31494 80056094 8C430094 */  lw        $v1, 0x94($v0)
/* 31498 80056098 AC830000 */  sw        $v1, ($a0)
/* 3149C 8005609C 8C420098 */  lw        $v0, 0x98($v0)
/* 314A0 800560A0 03E00008 */  jr        $ra
/* 314A4 800560A4 ACA20000 */   sw       $v0, ($a1)
