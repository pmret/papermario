.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242858_9C7C38
/* 9C7C38 80242858 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7C3C 8024285C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7C40 80242860 8C82000C */  lw        $v0, 0xc($a0)
/* 9C7C44 80242864 0C0B1EAF */  jal       get_variable
/* 9C7C48 80242868 8C450000 */   lw       $a1, ($v0)
/* 9C7C4C 8024286C 240505DC */  addiu     $a1, $zero, 0x5dc
/* 9C7C50 80242870 00021040 */  sll       $v0, $v0, 1
/* 9C7C54 80242874 3C048025 */  lui       $a0, 0x8025
/* 9C7C58 80242878 00822021 */  addu      $a0, $a0, $v0
/* 9C7C5C 8024287C 84840810 */  lh        $a0, 0x810($a0)
/* 9C7C60 80242880 0C01559B */  jal       func_8005566C
/* 9C7C64 80242884 24060001 */   addiu    $a2, $zero, 1
/* 9C7C68 80242888 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7C6C 8024288C 24020002 */  addiu     $v0, $zero, 2
/* 9C7C70 80242890 03E00008 */  jr        $ra
/* 9C7C74 80242894 27BD0018 */   addiu    $sp, $sp, 0x18
