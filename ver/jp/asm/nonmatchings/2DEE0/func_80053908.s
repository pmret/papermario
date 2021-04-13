.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053908
/* 2ED08 80053908 3C03800A */  lui       $v1, %hi(D_8009A5A0)
/* 2ED0C 8005390C 8C63A5A0 */  lw        $v1, %lo(D_8009A5A0)($v1)
/* 2ED10 80053910 24020001 */  addiu     $v0, $zero, 1
/* 2ED14 80053914 1082000B */  beq       $a0, $v0, .L80053944
/* 2ED18 80053918 00000000 */   nop
/* 2ED1C 8005391C 10800003 */  beqz      $a0, .L8005392C
/* 2ED20 80053920 24020002 */   addiu    $v0, $zero, 2
/* 2ED24 80053924 5482000D */  bnel      $a0, $v0, .L8005395C
/* 2ED28 80053928 ACA00000 */   sw       $zero, ($a1)
.L8005392C:
/* 2ED2C 8005392C 8C62005C */  lw        $v0, 0x5c($v1)
/* 2ED30 80053930 ACA20000 */  sw        $v0, ($a1)
/* 2ED34 80053934 3C02800A */  lui       $v0, %hi(D_8009A644)
/* 2ED38 80053938 8C42A644 */  lw        $v0, %lo(D_8009A644)($v0)
/* 2ED3C 8005393C 03E00008 */  jr        $ra
/* 2ED40 80053940 ACC20000 */   sw       $v0, ($a2)
.L80053944:
/* 2ED44 80053944 8C620060 */  lw        $v0, 0x60($v1)
/* 2ED48 80053948 ACA20000 */  sw        $v0, ($a1)
/* 2ED4C 8005394C 3C02800A */  lui       $v0, %hi(D_8009A5DC)
/* 2ED50 80053950 8C42A5DC */  lw        $v0, %lo(D_8009A5DC)($v0)
/* 2ED54 80053954 03E00008 */  jr        $ra
/* 2ED58 80053958 ACC20000 */   sw       $v0, ($a2)
.L8005395C:
/* 2ED5C 8005395C 03E00008 */  jr        $ra
/* 2ED60 80053960 ACC00000 */   sw       $zero, ($a2)
