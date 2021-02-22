.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FE0C
/* 2B20C 8004FE0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2B210 8004FE10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2B214 8004FE14 8C8600D4 */  lw        $a2, 0xd4($a0)
/* 2B218 8004FE18 90840234 */  lbu       $a0, 0x234($a0)
/* 2B21C 8004FE1C 90A5005C */  lbu       $a1, 0x5c($a1)
/* 2B220 8004FE20 0C01575B */  jal       func_80055D6C
/* 2B224 8004FE24 00063202 */   srl      $a2, $a2, 8
/* 2B228 8004FE28 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2B22C 8004FE2C 03E00008 */  jr        $ra
/* 2B230 8004FE30 27BD0018 */   addiu    $sp, $sp, 0x18
