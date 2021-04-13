.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053748
/* 2EB48 80053748 30A5FFFF */  andi      $a1, $a1, 0xffff
/* 2EB4C 8005374C 00A60018 */  mult      $a1, $a2
/* 2EB50 80053750 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2EB54 80053754 308400FF */  andi      $a0, $a0, 0xff
/* 2EB58 80053758 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2EB5C 8005375C 00001012 */  mflo      $v0
/* 2EB60 80053760 00022BC2 */  srl       $a1, $v0, 0xf
/* 2EB64 80053764 0C015A8A */  jal       func_80056A28
/* 2EB68 80053768 30A5FFFF */   andi     $a1, $a1, 0xffff
/* 2EB6C 8005376C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2EB70 80053770 03E00008 */  jr        $ra
/* 2EB74 80053774 27BD0018 */   addiu    $sp, $sp, 0x18
