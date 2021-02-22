.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053964
/* 2ED64 80053964 24020001 */  addiu     $v0, $zero, 1
/* 2ED68 80053968 10820009 */  beq       $a0, $v0, .L80053990
/* 2ED6C 8005396C 00000000 */   nop
/* 2ED70 80053970 10800003 */  beqz      $a0, .L80053980
/* 2ED74 80053974 24020002 */   addiu    $v0, $zero, 2
/* 2ED78 80053978 14820009 */  bne       $a0, $v0, .L800539A0
/* 2ED7C 8005397C 00000000 */   nop
.L80053980:
/* 2ED80 80053980 3C02800A */  lui       $v0, %hi(D_8009A644)
/* 2ED84 80053984 8C42A644 */  lw        $v0, %lo(D_8009A644)($v0)
/* 2ED88 80053988 03E00008 */  jr        $ra
/* 2ED8C 8005398C ACA20000 */   sw       $v0, ($a1)
.L80053990:
/* 2ED90 80053990 3C02800A */  lui       $v0, %hi(D_8009A5DC)
/* 2ED94 80053994 8C42A5DC */  lw        $v0, %lo(D_8009A5DC)($v0)
/* 2ED98 80053998 03E00008 */  jr        $ra
/* 2ED9C 8005399C ACA20000 */   sw       $v0, ($a1)
.L800539A0:
/* 2EDA0 800539A0 03E00008 */  jr        $ra
/* 2EDA4 800539A4 ACA00000 */   sw       $zero, ($a1)
