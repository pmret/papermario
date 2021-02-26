.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F514
/* 3A914 8005F514 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A918 8005F518 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A91C 8005F51C 8C82000C */  lw        $v0, 0xc($a0)
/* 3A920 8005F520 3C058009 */  lui       $a1, %hi(D_80093C70)
/* 3A924 8005F524 94A53C70 */  lhu       $a1, %lo(D_80093C70)($a1)
/* 3A928 8005F528 3C068009 */  lui       $a2, %hi(D_80093C74)
/* 3A92C 8005F52C 8CC63C74 */  lw        $a2, %lo(D_80093C74)($a2)
/* 3A930 8005F530 8C430008 */  lw        $v1, 8($v0)
/* 3A934 8005F534 8C440000 */  lw        $a0, ($v0)
/* 3A938 8005F538 AFA30010 */  sw        $v1, 0x10($sp)
/* 3A93C 8005F53C 8C840000 */  lw        $a0, ($a0)
/* 3A940 8005F540 0C01A168 */  jal       func_800685A0
/* 3A944 8005F544 8C470004 */   lw       $a3, 4($v0)
/* 3A948 8005F548 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A94C 8005F54C 03E00008 */  jr        $ra
/* 3A950 8005F550 27BD0020 */   addiu    $sp, $sp, 0x20
