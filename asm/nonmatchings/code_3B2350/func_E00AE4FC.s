.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AE4FC
/* 3B284C E00AE4FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B2850 E00AE500 3C02E00B */  lui       $v0, %hi(D_E00AE54C)
/* 3B2854 E00AE504 2442E54C */  addiu     $v0, $v0, %lo(D_E00AE54C)
/* 3B2858 E00AE508 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B285C E00AE50C 2402000A */  addiu     $v0, $zero, 0xa
/* 3B2860 E00AE510 AFA20014 */  sw        $v0, 0x14($sp)
/* 3B2864 E00AE514 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B2868 E00AE518 AFA40018 */  sw        $a0, 0x18($sp)
/* 3B286C E00AE51C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B2870 E00AE520 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B2874 E00AE524 0C080120 */  jal       func_E0200480
/* 3B2878 E00AE528 AFA20010 */   sw       $v0, 0x10($sp)
/* 3B287C E00AE52C 8C430000 */  lw        $v1, ($v0)
/* 3B2880 E00AE530 34630002 */  ori       $v1, $v1, 2
/* 3B2884 E00AE534 AC430000 */  sw        $v1, ($v0)
/* 3B2888 E00AE538 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B288C E00AE53C 03E00008 */  jr        $ra
/* 3B2890 E00AE540 27BD0028 */   addiu    $sp, $sp, 0x28
